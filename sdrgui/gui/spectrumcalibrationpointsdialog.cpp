///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2022 F4EXB                                                      //
// written by Edouard Griffiths                                                  //
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

#include <QFileDialog>
#include <QFile>
#include <QStandardPaths>

#include "util/db.h"
#include "util/csv.h"
#include "dsp/spectrummarkers.h"

#include "spectrumcalibrationpointsdialog.h"

#include "ui_spectrumcalibrationpointsdialog.h"

SpectrumCalibrationPointsDialog::SpectrumCalibrationPointsDialog(
    QList<SpectrumCalibrationPoint>& calibrationPoints,
    const SpectrumHistogramMarker *markerZero,
    QWidget* parent) :
    QDialog(parent),
    ui(new Ui::SpectrumCalibrationPointsDialog),
    m_calibrationPoints(calibrationPoints),
    m_markerZero(markerZero),
    m_calibrationPointIndex(0),
    m_centerFrequency(0)
{
    ui->setupUi(this);
    ui->calibPointFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->calibPointFrequency->setValueRange(false, 10, -9999999999L, 9999999999L);
    ui->calibPoint->setMaximum(m_calibrationPoints.size() - 1);
    displayCalibrationPoint();
}

SpectrumCalibrationPointsDialog::~SpectrumCalibrationPointsDialog()
{}

void SpectrumCalibrationPointsDialog::displayCalibrationPoint()
{
    ui->calibPointFrequency->blockSignals(true);
    ui->calibPoint->blockSignals(true);
    ui->relativePower->blockSignals(true);
    ui->absolutePower->blockSignals(true);

    if (m_calibrationPoints.size() == 0)
    {
        ui->calibPoint->setEnabled(false);
        ui->calibPointDel->setEnabled(false);
        ui->relativePower->setEnabled(false);
        ui->absolutePower->setEnabled(false);
        ui->calibPointFrequency->setEnabled(false);
        ui->importMarkerZero->setEnabled(false);
        ui->centerFrequency->setEnabled(false);
    }
    else
    {
        ui->calibPoint->setEnabled(true);
        ui->calibPointDel->setEnabled(true);
        ui->relativePower->setEnabled(true);
        ui->absolutePower->setEnabled(true);
        ui->calibPointFrequency->setEnabled(true);
        ui->importMarkerZero->setEnabled(true);
        ui->centerFrequency->setEnabled(true);
        ui->calibPoint->setValue(m_calibrationPointIndex);
        ui->calibPointText->setText(tr("%1").arg(m_calibrationPointIndex));
        float powerDB = CalcDb::dbPower(m_calibrationPoints[m_calibrationPointIndex].m_powerRelativeReference);
        ui->relativePower->setValue(powerDB*10);
        ui->relativePowerText->setText(QString::number(powerDB, 'f', 1));
        powerDB = CalcDb::dbPower(m_calibrationPoints[m_calibrationPointIndex].m_powerAbsoluteReference);
        ui->absolutePower->setValue(powerDB*10);
        ui->absolutePowerText->setText(QString::number(powerDB, 'f', 1));
        ui->calibPointFrequency->setValue(m_calibrationPoints[m_calibrationPointIndex].m_frequency);
    }

    ui->calibPointFrequency->blockSignals(false);
    ui->calibPoint->blockSignals(false);
    ui->relativePower->blockSignals(false);
    ui->absolutePower->blockSignals(false);
}

void SpectrumCalibrationPointsDialog::on_calibPoint_valueChanged(int value)
{
    if (m_calibrationPoints.size() == 0) {
        return;
    }

    m_calibrationPointIndex = value;
    displayCalibrationPoint();
}

void SpectrumCalibrationPointsDialog::on_calibPointAdd_clicked()
{
    m_calibrationPoints.append(SpectrumCalibrationPoint());
    m_calibrationPoints.back().m_frequency = m_centerFrequency;
    m_calibrationPointIndex = m_calibrationPoints.size() - 1;
    ui->calibPoint->setMaximum(m_calibrationPoints.size() - 1);
    ui->calibPoint->setMinimum(0);
    displayCalibrationPoint();
}

void SpectrumCalibrationPointsDialog::on_calibPointDel_clicked()
{
    if (m_calibrationPoints.size() == 0) {
        return;
    }

    m_calibrationPoints.removeAt(m_calibrationPointIndex);
    m_calibrationPointIndex = m_calibrationPointIndex < m_calibrationPoints.size() ?
        m_calibrationPointIndex : m_calibrationPointIndex - 1;
    ui->calibPoint->setMaximum(m_calibrationPoints.size() - 1);
    ui->calibPoint->setMinimum(0);
    displayCalibrationPoint();
}

void SpectrumCalibrationPointsDialog::on_relativePower_valueChanged(int value)
{
    if (m_calibrationPoints.size() == 0) {
        return;
    }

    float powerDB = value / 10.0f;
    ui->relativePowerText->setText(QString::number(powerDB, 'f', 1));
    m_calibrationPoints[m_calibrationPointIndex].m_powerRelativeReference = CalcDb::powerFromdB(powerDB);
    emit updateCalibrationPoints();
}

void SpectrumCalibrationPointsDialog::on_absolutePower_valueChanged(int value)
{
    if (m_calibrationPoints.size() == 0) {
        return;
    }

    float powerDB = value / 10.0f;
    ui->absolutePowerText->setText(QString::number(powerDB, 'f', 1));
    m_calibrationPoints[m_calibrationPointIndex].m_powerAbsoluteReference = CalcDb::powerFromdB(powerDB);
    emit updateCalibrationPoints();
}

void SpectrumCalibrationPointsDialog::on_calibPointFrequency_changed(qint64 value)
{
    if (m_calibrationPoints.size() == 0) {
        return;
    }

    m_calibrationPoints[m_calibrationPointIndex].m_frequency = value;
    emit updateCalibrationPoints();
}

void SpectrumCalibrationPointsDialog::on_importMarkerZero_clicked()
{
    if ((m_calibrationPoints.size() == 0) || (m_markerZero == nullptr)) {
        return;
    }

    m_calibrationPoints[m_calibrationPointIndex].m_frequency = m_markerZero->m_frequency;
    m_calibrationPoints[m_calibrationPointIndex].m_powerRelativeReference = CalcDb::powerFromdB(m_markerZero->m_powerMax);
    displayCalibrationPoint();
    emit updateCalibrationPoints();
}

void SpectrumCalibrationPointsDialog::on_centerFrequency_clicked()
{
    if (m_calibrationPoints.size() == 0) {
        return;
    }

    m_calibrationPoints[m_calibrationPointIndex].m_frequency = m_centerFrequency;
    displayCalibrationPoint();
    emit updateCalibrationPoints();
}

void SpectrumCalibrationPointsDialog::on_calibPointsExport_clicked()
{
    QFileDialog fileDialog(
        nullptr,
        "Select file to write calibration points to",
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation),
        "*.csv"
    );
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);

    if (fileDialog.exec())
    {
        QStringList fileNames = fileDialog.selectedFiles();

        if (fileNames.size() > 0)
        {
            QFile file(fileNames[0]);

            if (file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream stream;
                stream.setDevice(&file);
                stream << "Frequency,Reference,Absolute\n";

                for (const auto &calibrationPint : m_calibrationPoints)
                {
                    stream << calibrationPint.m_frequency << ","
                        << calibrationPint.m_powerRelativeReference << ","
                        << calibrationPint.m_powerAbsoluteReference << "\n";
                }

                stream.flush();
                file.close();
            }
        }
    }
}

void SpectrumCalibrationPointsDialog::on_calibPointsImport_clicked()
{
    QFileDialog fileDialog(
        nullptr,
        "Select .csv calibration points file to read",
        QStandardPaths::writableLocation(QStandardPaths::AppDataLocation),
        "*.csv"
    );

    if (fileDialog.exec())
    {
        QStringList fileNames = fileDialog.selectedFiles();

        if (fileNames.size() > 0)
        {
            QFile file(fileNames[0]);

            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {

                QTextStream in(&file);
                QString error;
                QHash<QString, int> colIndexes = CSV::readHeader(
                    in,
                    {"Frequency", "Reference", "Absolute"},
                    error
                );

                if (error.isEmpty())
                {
                    QStringList cols;
                    int frequencyCol = colIndexes.value("Frequency");
                    int referenceCol = colIndexes.value("Reference");
                    int absoluteCol = colIndexes.value("Absolute");

                    m_calibrationPoints.clear();

                    while (CSV::readRow(in, &cols))
                    {
                        m_calibrationPoints.push_back(SpectrumCalibrationPoint());
                        m_calibrationPoints.back().m_frequency = cols[frequencyCol].toLongLong();
                        m_calibrationPoints.back().m_powerRelativeReference = cols[referenceCol].toFloat();
                        m_calibrationPoints.back().m_powerAbsoluteReference = cols[absoluteCol].toFloat();
                    }

                    m_calibrationPointIndex = 0;
                    ui->calibPoint->setMaximum(m_calibrationPoints.size() - 1);
                    ui->calibPoint->setMinimum(0);
                    displayCalibrationPoint();
                    emit updateCalibrationPoints();
                }
            }
        }
    }
}