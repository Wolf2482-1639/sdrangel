///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QDebug>

#include "dsp/dspengine.h"
#include "dsp/dspcommands.h"
#include "dsp/downchannelizer.h"

#include "chanalyzerbaseband.h"

MESSAGE_CLASS_DEFINITION(ChannelAnalyzerBaseband::MsgConfigureChannelAnalyzerBaseband, Message)

ChannelAnalyzerBaseband::ChannelAnalyzerBaseband() :
    m_running(false),
    m_mutex(QMutex::Recursive)
{
    qDebug("ChannelAnalyzerBaseband::ChannelAnalyzerBaseband");
    m_sampleFifo.setSize(SampleSinkFifo::getSizePolicy(48000));
    m_channelizer = new DownChannelizer(&m_sink);
}

ChannelAnalyzerBaseband::~ChannelAnalyzerBaseband()
{
    m_inputMessageQueue.clear();
    delete m_channelizer;
}

void ChannelAnalyzerBaseband::reset()
{
    QMutexLocker mutexLocker(&m_mutex);
    m_inputMessageQueue.clear();
    m_sampleFifo.reset();
}

void ChannelAnalyzerBaseband::startWork()
{
    QMutexLocker mutexLocker(&m_mutex);
    QObject::connect(
        &m_sampleFifo,
        &SampleSinkFifo::dataReady,
        this,
        &ChannelAnalyzerBaseband::handleData,
        Qt::QueuedConnection
    );
    connect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));
    m_running = true;
}

void ChannelAnalyzerBaseband::stopWork()
{
    QMutexLocker mutexLocker(&m_mutex);
    disconnect(&m_inputMessageQueue, SIGNAL(messageEnqueued()), this, SLOT(handleInputMessages()));
    QObject::disconnect(
        &m_sampleFifo,
        &SampleSinkFifo::dataReady,
        this,
        &ChannelAnalyzerBaseband::handleData
    );
    m_running = false;
}

void ChannelAnalyzerBaseband::feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end)
{
    m_sampleFifo.write(begin, end);
}

void ChannelAnalyzerBaseband::handleData()
{
    QMutexLocker mutexLocker(&m_mutex);

    while ((m_sampleFifo.fill() > 0) && (m_inputMessageQueue.size() == 0))
    {
		SampleVector::iterator part1begin;
		SampleVector::iterator part1end;
		SampleVector::iterator part2begin;
		SampleVector::iterator part2end;

        std::size_t count = m_sampleFifo.readBegin(m_sampleFifo.fill(), &part1begin, &part1end, &part2begin, &part2end);

		// first part of FIFO data
        if (part1begin != part1end) {
            m_channelizer->feed(part1begin, part1end);
        }

		// second part of FIFO data (used when block wraps around)
		if(part2begin != part2end) {
            m_channelizer->feed(part2begin, part2end);
        }

		m_sampleFifo.readCommit((unsigned int) count);
    }
}

void ChannelAnalyzerBaseband::handleInputMessages()
{
	Message* message;

	while ((message = m_inputMessageQueue.pop()) != nullptr)
	{
		if (handleMessage(*message)) {
			delete message;
		}
	}
}

bool ChannelAnalyzerBaseband::handleMessage(const Message& cmd)
{
    if (MsgConfigureChannelAnalyzerBaseband::match(cmd))
    {
        QMutexLocker mutexLocker(&m_mutex);
        MsgConfigureChannelAnalyzerBaseband& cfg = (MsgConfigureChannelAnalyzerBaseband&) cmd;
        qDebug() << "ChannelAnalyzerBaseband::handleMessage: MsgConfigureChannelAnalyzerBaseband";

        applySettings(cfg.getSettings(), cfg.getForce());

        return true;
    }
    else if (DSPSignalNotification::match(cmd))
    {
        QMutexLocker mutexLocker(&m_mutex);
        DSPSignalNotification& notif = (DSPSignalNotification&) cmd;
        qDebug() << "ChannelAnalyzerBaseband::handleMessage: DSPSignalNotification: basebandSampleRate: " << notif.getSampleRate();
        m_sampleFifo.setSize(SampleSinkFifo::getSizePolicy(notif.getSampleRate()));
        m_channelizer->setBasebandSampleRate(notif.getSampleRate());
        int desiredSampleRate = getSinkSampleRate(m_settings);
        m_channelizer->setChannelization(desiredSampleRate, m_settings.m_inputFrequencyOffset);
        m_sink.applyChannelSettings(m_channelizer->getChannelSampleRate(), desiredSampleRate, m_channelizer->getChannelFrequencyOffset());

		return true;
    }
    else
    {
        return false;
    }
}

void ChannelAnalyzerBaseband::applySettings(const ChannelAnalyzerSettings& settings, bool force)
{
    if ((settings.m_log2Decim != m_settings.m_log2Decim)
     || (settings.m_inputFrequencyOffset != m_settings.m_inputFrequencyOffset)
     || (settings.m_rationalDownSamplerRate != m_settings.m_rationalDownSamplerRate)
     || (settings.m_rationalDownSample != m_settings.m_rationalDownSample) || force)
    {
        int desiredSampleRate = getSinkSampleRate(settings);
        m_channelizer->setChannelization(desiredSampleRate, settings.m_inputFrequencyOffset);
        m_sink.applyChannelSettings(m_channelizer->getChannelSampleRate(), desiredSampleRate, m_channelizer->getChannelFrequencyOffset());
    }

    m_sink.applySettings(settings, force);
    m_settings = settings;
}

int ChannelAnalyzerBaseband::getSinkSampleRate(ChannelAnalyzerSettings settings)
{
    int normalSinkSampleRate = m_channelizer->getBasebandSampleRate() / (1<<settings.m_log2Decim);
    return settings.m_rationalDownSample ? settings.m_rationalDownSamplerRate : normalSinkSampleRate;
}

int ChannelAnalyzerBaseband::getChannelSampleRate() const
{
    return m_channelizer->getChannelSampleRate();
}
