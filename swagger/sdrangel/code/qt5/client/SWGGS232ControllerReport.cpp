/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 6.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGGS232ControllerReport.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGGS232ControllerReport::SWGGS232ControllerReport(QString* json) {
    init();
    this->fromJson(*json);
}

SWGGS232ControllerReport::SWGGS232ControllerReport() {
    running_state = 0;
    m_running_state_isSet = false;
    sources = nullptr;
    m_sources_isSet = false;
    serial_ports = nullptr;
    m_serial_ports_isSet = false;
    target_azimuth = 0.0f;
    m_target_azimuth_isSet = false;
    target_elevation = 0.0f;
    m_target_elevation_isSet = false;
    current_azimuth = 0.0f;
    m_current_azimuth_isSet = false;
    current_elevation = 0.0f;
    m_current_elevation_isSet = false;
    on_target = 0;
    m_on_target_isSet = false;
}

SWGGS232ControllerReport::~SWGGS232ControllerReport() {
    this->cleanup();
}

void
SWGGS232ControllerReport::init() {
    running_state = 0;
    m_running_state_isSet = false;
    sources = new QList<QString*>();
    m_sources_isSet = false;
    serial_ports = new QList<QString*>();
    m_serial_ports_isSet = false;
    target_azimuth = 0.0f;
    m_target_azimuth_isSet = false;
    target_elevation = 0.0f;
    m_target_elevation_isSet = false;
    current_azimuth = 0.0f;
    m_current_azimuth_isSet = false;
    current_elevation = 0.0f;
    m_current_elevation_isSet = false;
    on_target = 0;
    m_on_target_isSet = false;
}

void
SWGGS232ControllerReport::cleanup() {

    if(sources != nullptr) { 
        auto arr = sources;
        for(auto o: *arr) { 
            delete o;
        }
        delete sources;
    }
    if(serial_ports != nullptr) { 
        auto arr = serial_ports;
        for(auto o: *arr) { 
            delete o;
        }
        delete serial_ports;
    }





}

SWGGS232ControllerReport*
SWGGS232ControllerReport::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGGS232ControllerReport::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&running_state, pJson["runningState"], "qint32", "");
    
    
    ::SWGSDRangel::setValue(&sources, pJson["sources"], "QList", "QString");
    
    ::SWGSDRangel::setValue(&serial_ports, pJson["serialPorts"], "QList", "QString");
    ::SWGSDRangel::setValue(&target_azimuth, pJson["targetAzimuth"], "float", "");
    
    ::SWGSDRangel::setValue(&target_elevation, pJson["targetElevation"], "float", "");
    
    ::SWGSDRangel::setValue(&current_azimuth, pJson["currentAzimuth"], "float", "");
    
    ::SWGSDRangel::setValue(&current_elevation, pJson["currentElevation"], "float", "");
    
    ::SWGSDRangel::setValue(&on_target, pJson["onTarget"], "qint32", "");
    
}

QString
SWGGS232ControllerReport::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGGS232ControllerReport::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_running_state_isSet){
        obj->insert("runningState", QJsonValue(running_state));
    }
    if(sources && sources->size() > 0){
        toJsonArray((QList<void*>*)sources, obj, "sources", "QString");
    }
    if(serial_ports && serial_ports->size() > 0){
        toJsonArray((QList<void*>*)serial_ports, obj, "serialPorts", "QString");
    }
    if(m_target_azimuth_isSet){
        obj->insert("targetAzimuth", QJsonValue(target_azimuth));
    }
    if(m_target_elevation_isSet){
        obj->insert("targetElevation", QJsonValue(target_elevation));
    }
    if(m_current_azimuth_isSet){
        obj->insert("currentAzimuth", QJsonValue(current_azimuth));
    }
    if(m_current_elevation_isSet){
        obj->insert("currentElevation", QJsonValue(current_elevation));
    }
    if(m_on_target_isSet){
        obj->insert("onTarget", QJsonValue(on_target));
    }

    return obj;
}

qint32
SWGGS232ControllerReport::getRunningState() {
    return running_state;
}
void
SWGGS232ControllerReport::setRunningState(qint32 running_state) {
    this->running_state = running_state;
    this->m_running_state_isSet = true;
}

QList<QString*>*
SWGGS232ControllerReport::getSources() {
    return sources;
}
void
SWGGS232ControllerReport::setSources(QList<QString*>* sources) {
    this->sources = sources;
    this->m_sources_isSet = true;
}

QList<QString*>*
SWGGS232ControllerReport::getSerialPorts() {
    return serial_ports;
}
void
SWGGS232ControllerReport::setSerialPorts(QList<QString*>* serial_ports) {
    this->serial_ports = serial_ports;
    this->m_serial_ports_isSet = true;
}

float
SWGGS232ControllerReport::getTargetAzimuth() {
    return target_azimuth;
}
void
SWGGS232ControllerReport::setTargetAzimuth(float target_azimuth) {
    this->target_azimuth = target_azimuth;
    this->m_target_azimuth_isSet = true;
}

float
SWGGS232ControllerReport::getTargetElevation() {
    return target_elevation;
}
void
SWGGS232ControllerReport::setTargetElevation(float target_elevation) {
    this->target_elevation = target_elevation;
    this->m_target_elevation_isSet = true;
}

float
SWGGS232ControllerReport::getCurrentAzimuth() {
    return current_azimuth;
}
void
SWGGS232ControllerReport::setCurrentAzimuth(float current_azimuth) {
    this->current_azimuth = current_azimuth;
    this->m_current_azimuth_isSet = true;
}

float
SWGGS232ControllerReport::getCurrentElevation() {
    return current_elevation;
}
void
SWGGS232ControllerReport::setCurrentElevation(float current_elevation) {
    this->current_elevation = current_elevation;
    this->m_current_elevation_isSet = true;
}

qint32
SWGGS232ControllerReport::getOnTarget() {
    return on_target;
}
void
SWGGS232ControllerReport::setOnTarget(qint32 on_target) {
    this->on_target = on_target;
    this->m_on_target_isSet = true;
}


bool
SWGGS232ControllerReport::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_running_state_isSet){
            isObjectUpdated = true; break;
        }
        if(sources && (sources->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(serial_ports && (serial_ports->size() > 0)){
            isObjectUpdated = true; break;
        }
        if(m_target_azimuth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_target_elevation_isSet){
            isObjectUpdated = true; break;
        }
        if(m_current_azimuth_isSet){
            isObjectUpdated = true; break;
        }
        if(m_current_elevation_isSet){
            isObjectUpdated = true; break;
        }
        if(m_on_target_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

