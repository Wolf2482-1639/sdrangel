/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.15.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGFileSourceActions.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGFileSourceActions::SWGFileSourceActions(QString* json) {
    init();
    this->fromJson(*json);
}

SWGFileSourceActions::SWGFileSourceActions() {
    play = 0;
    m_play_isSet = false;
    seek_millis = 0;
    m_seek_millis_isSet = false;
}

SWGFileSourceActions::~SWGFileSourceActions() {
    this->cleanup();
}

void
SWGFileSourceActions::init() {
    play = 0;
    m_play_isSet = false;
    seek_millis = 0;
    m_seek_millis_isSet = false;
}

void
SWGFileSourceActions::cleanup() {


}

SWGFileSourceActions*
SWGFileSourceActions::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGFileSourceActions::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&play, pJson["play"], "qint32", "");
    
    ::SWGSDRangel::setValue(&seek_millis, pJson["seekMillis"], "qint32", "");
    
}

QString
SWGFileSourceActions::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGFileSourceActions::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_play_isSet){
        obj->insert("play", QJsonValue(play));
    }
    if(m_seek_millis_isSet){
        obj->insert("seekMillis", QJsonValue(seek_millis));
    }

    return obj;
}

qint32
SWGFileSourceActions::getPlay() {
    return play;
}
void
SWGFileSourceActions::setPlay(qint32 play) {
    this->play = play;
    this->m_play_isSet = true;
}

qint32
SWGFileSourceActions::getSeekMillis() {
    return seek_millis;
}
void
SWGFileSourceActions::setSeekMillis(qint32 seek_millis) {
    this->seek_millis = seek_millis;
    this->m_seek_millis_isSet = true;
}


bool
SWGFileSourceActions::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_play_isSet){
            isObjectUpdated = true; break;
        }
        if(m_seek_millis_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

