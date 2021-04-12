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

/*
 * SWGDeviceSettings.h
 *
 * Base device settings. Only the device settings corresponding to the device specified in the deviceHwType field is or should be present.
 */

#ifndef SWGDeviceSettings_H_
#define SWGDeviceSettings_H_

#include <QJsonObject>


#include "SWGAirspyHFSettings.h"
#include "SWGAirspySettings.h"
#include "SWGAudioInputSettings.h"
#include "SWGAudioOutputSettings.h"
#include "SWGBladeRF1InputSettings.h"
#include "SWGBladeRF1OutputSettings.h"
#include "SWGBladeRF2InputSettings.h"
#include "SWGBladeRF2MIMOSettings.h"
#include "SWGBladeRF2OutputSettings.h"
#include "SWGFCDProPlusSettings.h"
#include "SWGFCDProSettings.h"
#include "SWGFileInputSettings.h"
#include "SWGHackRFInputSettings.h"
#include "SWGHackRFOutputSettings.h"
#include "SWGKiwiSDRSettings.h"
#include "SWGLimeSdrInputSettings.h"
#include "SWGLimeSdrMIMOSettings.h"
#include "SWGLimeSdrOutputSettings.h"
#include "SWGLocalInputSettings.h"
#include "SWGLocalOutputSettings.h"
#include "SWGMetisMISOSettings.h"
#include "SWGPerseusSettings.h"
#include "SWGPlutoSdrInputSettings.h"
#include "SWGPlutoSdrOutputSettings.h"
#include "SWGRemoteInputSettings.h"
#include "SWGRemoteOutputSettings.h"
#include "SWGRtlSdrSettings.h"
#include "SWGSDRPlaySettings.h"
#include "SWGSDRPlayV3Settings.h"
#include "SWGSigMFFileInputSettings.h"
#include "SWGSoapySDRInputSettings.h"
#include "SWGSoapySDROutputSettings.h"
#include "SWGTestMISettings.h"
#include "SWGTestMOSyncSettings.h"
#include "SWGTestSourceSettings.h"
#include "SWGUSRPInputSettings.h"
#include "SWGUSRPOutputSettings.h"
#include "SWGXtrxInputSettings.h"
#include "SWGXtrxMIMOSettings.h"
#include "SWGXtrxOutputSettings.h"
#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGDeviceSettings: public SWGObject {
public:
    SWGDeviceSettings();
    SWGDeviceSettings(QString* json);
    virtual ~SWGDeviceSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGDeviceSettings* fromJson(QString &jsonString) override;

    QString* getDeviceHwType();
    void setDeviceHwType(QString* device_hw_type);

    qint32 getDirection();
    void setDirection(qint32 direction);

    qint32 getOriginatorIndex();
    void setOriginatorIndex(qint32 originator_index);

    SWGAirspySettings* getAirspySettings();
    void setAirspySettings(SWGAirspySettings* airspy_settings);

    SWGAirspyHFSettings* getAirspyHfSettings();
    void setAirspyHfSettings(SWGAirspyHFSettings* airspy_hf_settings);

    SWGAudioInputSettings* getAudioInputSettings();
    void setAudioInputSettings(SWGAudioInputSettings* audio_input_settings);

    SWGAudioOutputSettings* getAudioOutputSettings();
    void setAudioOutputSettings(SWGAudioOutputSettings* audio_output_settings);

    SWGBladeRF1InputSettings* getBladeRf1InputSettings();
    void setBladeRf1InputSettings(SWGBladeRF1InputSettings* blade_rf1_input_settings);

    SWGBladeRF2InputSettings* getBladeRf2InputSettings();
    void setBladeRf2InputSettings(SWGBladeRF2InputSettings* blade_rf2_input_settings);

    SWGBladeRF1OutputSettings* getBladeRf1OutputSettings();
    void setBladeRf1OutputSettings(SWGBladeRF1OutputSettings* blade_rf1_output_settings);

    SWGBladeRF2OutputSettings* getBladeRf2OutputSettings();
    void setBladeRf2OutputSettings(SWGBladeRF2OutputSettings* blade_rf2_output_settings);

    SWGBladeRF2MIMOSettings* getBladeRf2MimoSettings();
    void setBladeRf2MimoSettings(SWGBladeRF2MIMOSettings* blade_rf2_mimo_settings);

    SWGFCDProSettings* getFcdProSettings();
    void setFcdProSettings(SWGFCDProSettings* fcd_pro_settings);

    SWGFCDProPlusSettings* getFcdProPlusSettings();
    void setFcdProPlusSettings(SWGFCDProPlusSettings* fcd_pro_plus_settings);

    SWGFileInputSettings* getFileInputSettings();
    void setFileInputSettings(SWGFileInputSettings* file_input_settings);

    SWGHackRFInputSettings* getHackRfInputSettings();
    void setHackRfInputSettings(SWGHackRFInputSettings* hack_rf_input_settings);

    SWGHackRFOutputSettings* getHackRfOutputSettings();
    void setHackRfOutputSettings(SWGHackRFOutputSettings* hack_rf_output_settings);

    SWGKiwiSDRSettings* getKiwiSdrSettings();
    void setKiwiSdrSettings(SWGKiwiSDRSettings* kiwi_sdr_settings);

    SWGLimeSdrInputSettings* getLimeSdrInputSettings();
    void setLimeSdrInputSettings(SWGLimeSdrInputSettings* lime_sdr_input_settings);

    SWGLimeSdrOutputSettings* getLimeSdrOutputSettings();
    void setLimeSdrOutputSettings(SWGLimeSdrOutputSettings* lime_sdr_output_settings);

    SWGLimeSdrMIMOSettings* getLimeSdrMimoSettings();
    void setLimeSdrMimoSettings(SWGLimeSdrMIMOSettings* lime_sdr_mimo_settings);

    SWGLocalInputSettings* getLocalInputSettings();
    void setLocalInputSettings(SWGLocalInputSettings* local_input_settings);

    SWGLocalOutputSettings* getLocalOutputSettings();
    void setLocalOutputSettings(SWGLocalOutputSettings* local_output_settings);

    SWGMetisMISOSettings* getMetisMisoSettings();
    void setMetisMisoSettings(SWGMetisMISOSettings* metis_miso_settings);

    SWGPerseusSettings* getPerseusSettings();
    void setPerseusSettings(SWGPerseusSettings* perseus_settings);

    SWGPlutoSdrInputSettings* getPlutoSdrInputSettings();
    void setPlutoSdrInputSettings(SWGPlutoSdrInputSettings* pluto_sdr_input_settings);

    SWGPlutoSdrOutputSettings* getPlutoSdrOutputSettings();
    void setPlutoSdrOutputSettings(SWGPlutoSdrOutputSettings* pluto_sdr_output_settings);

    SWGRtlSdrSettings* getRtlSdrSettings();
    void setRtlSdrSettings(SWGRtlSdrSettings* rtl_sdr_settings);

    SWGRemoteOutputSettings* getRemoteOutputSettings();
    void setRemoteOutputSettings(SWGRemoteOutputSettings* remote_output_settings);

    SWGRemoteInputSettings* getRemoteInputSettings();
    void setRemoteInputSettings(SWGRemoteInputSettings* remote_input_settings);

    SWGSDRPlaySettings* getSdrPlaySettings();
    void setSdrPlaySettings(SWGSDRPlaySettings* sdr_play_settings);

    SWGSDRPlayV3Settings* getSdrPlayV3Settings();
    void setSdrPlayV3Settings(SWGSDRPlayV3Settings* sdr_play_v3_settings);

    SWGSigMFFileInputSettings* getSigMfFileInputSettings();
    void setSigMfFileInputSettings(SWGSigMFFileInputSettings* sig_mf_file_input_settings);

    SWGSoapySDRInputSettings* getSoapySdrInputSettings();
    void setSoapySdrInputSettings(SWGSoapySDRInputSettings* soapy_sdr_input_settings);

    SWGSoapySDROutputSettings* getSoapySdrOutputSettings();
    void setSoapySdrOutputSettings(SWGSoapySDROutputSettings* soapy_sdr_output_settings);

    SWGTestMISettings* getTestMiSettings();
    void setTestMiSettings(SWGTestMISettings* test_mi_settings);

    SWGTestMOSyncSettings* getTestMoSyncSettings();
    void setTestMoSyncSettings(SWGTestMOSyncSettings* test_mo_sync_settings);

    SWGTestSourceSettings* getTestSourceSettings();
    void setTestSourceSettings(SWGTestSourceSettings* test_source_settings);

    SWGUSRPInputSettings* getUsrpInputSettings();
    void setUsrpInputSettings(SWGUSRPInputSettings* usrp_input_settings);

    SWGUSRPOutputSettings* getUsrpOutputSettings();
    void setUsrpOutputSettings(SWGUSRPOutputSettings* usrp_output_settings);

    SWGXtrxInputSettings* getXtrxInputSettings();
    void setXtrxInputSettings(SWGXtrxInputSettings* xtrx_input_settings);

    SWGXtrxOutputSettings* getXtrxOutputSettings();
    void setXtrxOutputSettings(SWGXtrxOutputSettings* xtrx_output_settings);

    SWGXtrxMIMOSettings* getXtrxMimoSettings();
    void setXtrxMimoSettings(SWGXtrxMIMOSettings* xtrx_mimo_settings);


    virtual bool isSet() override;

private:
    QString* device_hw_type;
    bool m_device_hw_type_isSet;

    qint32 direction;
    bool m_direction_isSet;

    qint32 originator_index;
    bool m_originator_index_isSet;

    SWGAirspySettings* airspy_settings;
    bool m_airspy_settings_isSet;

    SWGAirspyHFSettings* airspy_hf_settings;
    bool m_airspy_hf_settings_isSet;

    SWGAudioInputSettings* audio_input_settings;
    bool m_audio_input_settings_isSet;

    SWGAudioOutputSettings* audio_output_settings;
    bool m_audio_output_settings_isSet;

    SWGBladeRF1InputSettings* blade_rf1_input_settings;
    bool m_blade_rf1_input_settings_isSet;

    SWGBladeRF2InputSettings* blade_rf2_input_settings;
    bool m_blade_rf2_input_settings_isSet;

    SWGBladeRF1OutputSettings* blade_rf1_output_settings;
    bool m_blade_rf1_output_settings_isSet;

    SWGBladeRF2OutputSettings* blade_rf2_output_settings;
    bool m_blade_rf2_output_settings_isSet;

    SWGBladeRF2MIMOSettings* blade_rf2_mimo_settings;
    bool m_blade_rf2_mimo_settings_isSet;

    SWGFCDProSettings* fcd_pro_settings;
    bool m_fcd_pro_settings_isSet;

    SWGFCDProPlusSettings* fcd_pro_plus_settings;
    bool m_fcd_pro_plus_settings_isSet;

    SWGFileInputSettings* file_input_settings;
    bool m_file_input_settings_isSet;

    SWGHackRFInputSettings* hack_rf_input_settings;
    bool m_hack_rf_input_settings_isSet;

    SWGHackRFOutputSettings* hack_rf_output_settings;
    bool m_hack_rf_output_settings_isSet;

    SWGKiwiSDRSettings* kiwi_sdr_settings;
    bool m_kiwi_sdr_settings_isSet;

    SWGLimeSdrInputSettings* lime_sdr_input_settings;
    bool m_lime_sdr_input_settings_isSet;

    SWGLimeSdrOutputSettings* lime_sdr_output_settings;
    bool m_lime_sdr_output_settings_isSet;

    SWGLimeSdrMIMOSettings* lime_sdr_mimo_settings;
    bool m_lime_sdr_mimo_settings_isSet;

    SWGLocalInputSettings* local_input_settings;
    bool m_local_input_settings_isSet;

    SWGLocalOutputSettings* local_output_settings;
    bool m_local_output_settings_isSet;

    SWGMetisMISOSettings* metis_miso_settings;
    bool m_metis_miso_settings_isSet;

    SWGPerseusSettings* perseus_settings;
    bool m_perseus_settings_isSet;

    SWGPlutoSdrInputSettings* pluto_sdr_input_settings;
    bool m_pluto_sdr_input_settings_isSet;

    SWGPlutoSdrOutputSettings* pluto_sdr_output_settings;
    bool m_pluto_sdr_output_settings_isSet;

    SWGRtlSdrSettings* rtl_sdr_settings;
    bool m_rtl_sdr_settings_isSet;

    SWGRemoteOutputSettings* remote_output_settings;
    bool m_remote_output_settings_isSet;

    SWGRemoteInputSettings* remote_input_settings;
    bool m_remote_input_settings_isSet;

    SWGSDRPlaySettings* sdr_play_settings;
    bool m_sdr_play_settings_isSet;

    SWGSDRPlayV3Settings* sdr_play_v3_settings;
    bool m_sdr_play_v3_settings_isSet;

    SWGSigMFFileInputSettings* sig_mf_file_input_settings;
    bool m_sig_mf_file_input_settings_isSet;

    SWGSoapySDRInputSettings* soapy_sdr_input_settings;
    bool m_soapy_sdr_input_settings_isSet;

    SWGSoapySDROutputSettings* soapy_sdr_output_settings;
    bool m_soapy_sdr_output_settings_isSet;

    SWGTestMISettings* test_mi_settings;
    bool m_test_mi_settings_isSet;

    SWGTestMOSyncSettings* test_mo_sync_settings;
    bool m_test_mo_sync_settings_isSet;

    SWGTestSourceSettings* test_source_settings;
    bool m_test_source_settings_isSet;

    SWGUSRPInputSettings* usrp_input_settings;
    bool m_usrp_input_settings_isSet;

    SWGUSRPOutputSettings* usrp_output_settings;
    bool m_usrp_output_settings_isSet;

    SWGXtrxInputSettings* xtrx_input_settings;
    bool m_xtrx_input_settings_isSet;

    SWGXtrxOutputSettings* xtrx_output_settings;
    bool m_xtrx_output_settings_isSet;

    SWGXtrxMIMOSettings* xtrx_mimo_settings;
    bool m_xtrx_mimo_settings_isSet;

};

}

#endif /* SWGDeviceSettings_H_ */
