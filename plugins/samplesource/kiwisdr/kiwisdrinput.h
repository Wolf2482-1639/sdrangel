///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Vort                                                       //
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

#ifndef _KIWISDR_KIWISDRINPUT_H_
#define _KIWISDR_KIWISDRINPUT_H_

#include <QString>
#include <QByteArray>
#include <QTimer>
#include <QNetworkRequest>

#include <dsp/devicesamplesource.h>
#include "kiwisdrsettings.h"

class DeviceAPI;
class KiwiSDRWorker;
class QNetworkAccessManager;
class QNetworkReply;
class QThread;

class KiwiSDRInput : public DeviceSampleSource {
    Q_OBJECT
public:
	class MsgConfigureKiwiSDR : public Message {
		MESSAGE_CLASS_DECLARATION

	public:
		const KiwiSDRSettings& getSettings() const { return m_settings; }
        const QList<QString>& getSettingsKeys() const { return m_settingsKeys; }
		bool getForce() const { return m_force; }

		static MsgConfigureKiwiSDR* create(const KiwiSDRSettings& settings, const QList<QString>& settingsKeys, bool force)
		{
			return new MsgConfigureKiwiSDR(settings, settingsKeys, force);
		}

	private:
		KiwiSDRSettings m_settings;
        QList<QString> m_settingsKeys;
		bool m_force;

		MsgConfigureKiwiSDR(const KiwiSDRSettings& settings, const QList<QString>& settingsKeys, bool force) :
			Message(),
			m_settings(settings),
            m_settingsKeys(settingsKeys),
			m_force(force)
		{ }
	};

    class MsgStartStop : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        bool getStartStop() const { return m_startStop; }

        static MsgStartStop* create(bool startStop) {
            return new MsgStartStop(startStop);
        }

    protected:
        bool m_startStop;

        MsgStartStop(bool startStop) :
            Message(),
            m_startStop(startStop)
        { }
    };

	class MsgSetStatus : public Message {
		MESSAGE_CLASS_DECLARATION

	public:
		int getStatus() const { return m_status; }

		static MsgSetStatus* create(int status) {
			return new MsgSetStatus(status);
		}

	protected:
		int m_status;

		MsgSetStatus(int status) :
			Message(),
			m_status(status)
		{ }
	};

	KiwiSDRInput(DeviceAPI *deviceAPI);
	virtual ~KiwiSDRInput();
	virtual void destroy();

	virtual void init();
	virtual bool start();
	virtual void stop();

    virtual QByteArray serialize() const;
    virtual bool deserialize(const QByteArray& data);

    virtual void setMessageQueueToGUI(MessageQueue *queue) { m_guiMessageQueue = queue; }
	virtual const QString& getDeviceDescription() const;
	virtual int getSampleRate() const;
    virtual void setSampleRate(int sampleRate) { (void) sampleRate; }
	virtual quint64 getCenterFrequency() const;
    virtual void setCenterFrequency(qint64 centerFrequency);

	virtual bool handleMessage(const Message& message);

    virtual int webapiSettingsGet(
                SWGSDRangel::SWGDeviceSettings& response,
                QString& errorMessage);

    virtual int webapiSettingsPutPatch(
                bool force,
                const QStringList& deviceSettingsKeys,
                SWGSDRangel::SWGDeviceSettings& response, // query + response
                QString& errorMessage);

    virtual int webapiRunGet(
            SWGSDRangel::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiRun(
            bool run,
            SWGSDRangel::SWGDeviceState& response,
            QString& errorMessage);

    virtual int webapiReportGet(
            SWGSDRangel::SWGDeviceReport& response,
            QString& errorMessage);

    static void webapiFormatDeviceSettings(
            SWGSDRangel::SWGDeviceSettings& response,
            const KiwiSDRSettings& settings);

    static void webapiUpdateDeviceSettings(
            KiwiSDRSettings& settings,
            const QStringList& deviceSettingsKeys,
            SWGSDRangel::SWGDeviceSettings& response);

private:
	DeviceAPI *m_deviceAPI;
	QMutex m_mutex;
	KiwiSDRSettings m_settings;
	KiwiSDRWorker* m_kiwiSDRWorker;
	QThread *m_kiwiSDRWorkerThread;
	QString m_deviceDescription;
	bool m_running;
    const QTimer& m_masterTimer;
    QNetworkAccessManager *m_networkManager;
    QNetworkRequest m_networkRequest;

    int getStatus() const;
	bool applySettings(const KiwiSDRSettings& settings, const QList<QString>& settingsKeys, bool force);
    void webapiFormatDeviceReport(SWGSDRangel::SWGDeviceReport& response);
    void webapiReverseSendSettings(const QList<QString>& deviceSettingsKeys, const KiwiSDRSettings& settings, bool force);
    void webapiReverseSendStartStop(bool start);

signals:
	void startWorker();
	void stopWorker();
	void setWorkerCenterFrequency(quint64 centerFrequency);
	void setWorkerServerAddress(QString serverAddress);
	void setWorkerGain(quint32 gain, bool useAGC);

private slots:
	void setWorkerStatus(int status);
    void networkManagerFinished(QNetworkReply *reply);
};

#endif // _KIWISDR_KIWISDRINPUT_H_
