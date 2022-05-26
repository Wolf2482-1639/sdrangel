/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 7.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGAMBEReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGAMBEReport::SWGAMBEReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGAMBEReport::SWGAMBEReport() {
    serial = nullptr;
    m_serial_isSet = false;
    devices = nullptr;
    m_devices_isSet = false;
}

SWGAMBEReport::~SWGAMBEReport() {
    this->cleanup();
}

void
SWGAMBEReport::init() {
    serial = new SWGDVSerialDevices();
    m_serial_isSet = false;
    devices = new QList<SWGAMBEDeviceReport*>();
    m_devices_isSet = false;
}

void
SWGAMBEReport::cleanup() {
    if(serial != nullptr) { 
        delete serial;
    }
    if(devices != nullptr) { 
        auto arr = devices;
        for(auto o: *arr) { 
            delete o;
        }
        delete devices;
    }
}

SWGAMBEReport*
SWGAMBEReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGAMBEReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&serial, pJson["serial"], "SWGDVSerialDevices", "SWGDVSerialDevices");
    
    
    ::SWGSDRangel::setValue(&devices, pJson["devices"], "QList", "SWGAMBEDeviceReport");
}

QString
SWGAMBEReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGAMBEReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if((serial != nullptr) && (serial->isSet())){
        toJsonValue(QString("serial"), serial, obj, QString("SWGDVSerialDevices"));
    }
    if(devices && devices->size() > 0){
        toJsonArray((QList<void*>*)devices, obj, "devices", "SWGAMBEDeviceReport");
    }

    return obj;
}

SWGDVSerialDevices*
SWGAMBEReport::getSerial() {
    return serial;
}
void
SWGAMBEReport::setSerial(SWGDVSerialDevices* serial) {
    this->serial = serial;
    this->m_serial_isSet = true;
}

QList<SWGAMBEDeviceReport*>*
SWGAMBEReport::getDevices() {
    return devices;
}
void
SWGAMBEReport::setDevices(QList<SWGAMBEDeviceReport*>* devices) {
    this->devices = devices;
    this->m_devices_isSet = true;
}


bool
SWGAMBEReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(serial && serial->isSet()){
            isObjectUpdated = true; break;
        }
        if(devices && (devices->size() > 0)){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

