[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : CanTrcv_17_6251G_Cfg.h $                                   **
**                                                                           **
**  $CC VERSION : \main\28 $                                                 **
**                                                                           **
**  $DATE       : 2016-02-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : CanTrcv configuration generated out of ECU configuration   **
**                 file                                                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : CanTrcv_17_6251G_Cfg.h                                        **
**                                                                            **
**  $CC VERSION : \main\28 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  MODULE DECRIPTION : CanTrcv_17_6251G.bmd/.xdm                             **
**                                                                            **
**  VARIANT   : VariantPC                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION : CanTrcv configuration generated out of ECU configuration    **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CAN_TransceiverDriver.pdf,Release AS4.0.3  **
// // **                                                                      **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY : [cover parentID= ASW:1500,ASW:1501,ASW:1504, 
                   ASW:1507, ASW:1507, ASW:1509, ASW:1512,ASW:1513,ASW:1514,
                   ASW:1516,,ASW:1517,ASW:1523,ASW:1524,ASW:1528, ASW:1508,
                   DS_NAS_CANTRCV_PR127,DS_NAS_CANTRCV_PR446, DS_AS403_CANTRCV050,
				   SAS_NAS_CANTRCV_PR916,SAS_AS4XX_CANTRCV_PR678,DS_NAS_CANTRCV_PR700
				    DS_NAS_CANTRCV_PR701, DS_NAS_CANTRCV_PR704, DS_NAS_CANTRCV_PR712,
DS_NAS_CANTRCV_PR707, DS_NAS_CANTRCV_PR713,DS_NAS_CANTRCV_PR728,
DS_NAS_CANTRCV_PR714, DS_NAS_CANTRCV_PR716, DS_NAS_CANTRCV_PR717,DS_NAS_CANTRCV_PR709,
DS_NAS_CANTRCV_PR724,
DS_NAS_CANTRCV_PR708]
**                                                                            **
*******************************************************************************/

#ifndef CANTRCV_17_6251G_CFG_H
#define CANTRCV_17_6251G_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include Dio header file */
#include "Dio.h"

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('CanTrcv_17_6251G')[1]"!][!//

[!VAR "MaxChannels" = "ecu:get('CanTrcv.MaxChannelnumber')"!][!//
[!VAR "CanTrcvConfigSetName" = "'CanTrcvConfigSet'"!][!//
[!//
/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
/*
  CAN085: Published Information
  Module ID is used in reporting development errors.
*/


/* CANTRCV MODULE INSTANCE ID */
#define CANTRCV_17_6251G_INSTANCE_ID             ((uint8)[!"CanTrcvGeneral/CanTrcvIndex"!])

/*Section to Generate Autosar Specific Version Information*/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]

[!IF "$MajorVersion = num:i(4)"!][!//
#define CANTRCV_17_6251G_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define CANTRCV_17_6251G_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define CANTRCV_17_6251G_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/*Section to Generate Vendor Specific Version Information*/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define CANTRCV_17_6251G_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define CANTRCV_17_6251G_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define CANTRCV_17_6251G_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)

/*
Configuration: CANTRCV_DEV_ERROR_DETECT 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define CANTRCV_17_6251G_DEV_ERROR_DETECT                    ([!//
[!IF "CanTrcvGeneral/CanTrcvDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: CANTRCV_GENERAL_WAKE_UP_SUPPORT 
- POLLING: Wake up supported by POLLING.
- NO :Wake up not supported.
*/

[!IF "CanTrcvGeneral/CanTrcvWakeUpSupport = 'CANTRCV_WAKEUP_BY_ISR'"!][!//
#define CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT  (CANTRCV_WAKE_UP_BY_ISR)[!//
[!ELSEIF "CanTrcvGeneral/CanTrcvWakeUpSupport = 'CAVTRCV_WAKEUP_BY_POLLING'"!][!//
#define CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT  (CANTRCV_WAKE_UP_BY_POLLING)[!//
[!ELSEIF "CanTrcvGeneral/CanTrcvWakeUpSupport = 'CANTRCV_WAKEUP_NOT_SUPPORTED'"!][!//
#define CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT  (CANTRCV_WAKE_UP_NOT_SUPPORTED)[!//
[!ENDIF!][!//


/*
Configuration: CANTRCV_VERSION_INFO_API 
- if STD_ON, Function CANTRCV_GetVersionInfo is available
- if STD_OFF,Function CANTRCV_GetVersionInfo is not available
*/

#define CANTRCV_17_6251G_GET_VERSION_INFO                    ([!//
[!IF "CanTrcvGeneral/CanTrcvGetVersionInfo = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: CANTRCV_DEBUG_SUPPORT 
- if STD_ON, CANTRCV_DEBUG_SUPPORT is available
- if STD_OFF,CANTRCV_DEBUG_SUPPORT is not available
*/

#define CANTRCV_17_6251G_DEBUG_SUPPORT                    ([!//
[!IF "CanTrcvGeneral/CanTrcvDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!//[!IF "$ModuleReleaseVersion = '3.1'"!][!//
/* Marco Used to allow the Current Mode Transition CanTrcv120 and CanTrcv121*/  
#define CANTRCV_SWITCH_REQ_CUR_MOD                    (STD_ON)
[!//[!ENDIF!][!//



/*
Configuration: CANTRCV_WAIT_COUNT 
- Range is 0 .. 4294967295
*/

#define CANTRCV_17_6251G_WAIT_COUNT                    ([!"CanTrcvGeneral/CanTrcvWaitCount"!]U)


[!NOCODE!]
[!VAR "TotalCanTrcvChannels" = "num:i(0)"!][!//
[!VAR "ErrorFlag" = "num:i(0)"!][!//
[!VAR "ChannelId" ="num:i(0)"!][!//
[!SELECT "node:ref($CanTrcvConfigSetName)/*[1]"!][!//
[!LOOP "CanTrcvChannel/*"!][!//
[!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
[!IF "$CanTrcvChUsed = 'true'"!][!//
[!VAR "TotalCanTrcvChannels" = "num:i($TotalCanTrcvChannels + num:i(1))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!// 
[!IF "$TotalCanTrcvChannels =  num:i(0)"!][!//
[!ERROR!]
ERROR: Atleast one of the CanTrcv Channel should be activated in the configuration set.
[!ENDERROR!]
[!ENDIF!][!//
[!IF "$TotalCanTrcvChannels > 0"!][!//
[!LOOP "CanTrcvChannel/*"!][!//
[!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
[!IF "$CanTrcvChUsed = 'true'"!][!//
[!VAR "CanTrcv_ChannelId" = "./CanTrcvChannelId"!]
RRR: [!"$CanTrcv_ChannelId"!][!//
[!IF "$CanTrcv_ChannelId != $ChannelId"!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "ChannelId" = "num:i($ChannelId + num:i(1))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ASSERT "not($ErrorFlag = num:i(1))"!][!//
Config Error : CanTrcvChannelId's should start with zero & should be continuous.
[!ENDASSERT!][!//
[!ENDNOCODE!][!//

[!VAR "ChannelCount" = "0"!][!//
[!VAR "SleepInitCount" = "0"!][!//
[!//
[!SELECT "node:ref($CanTrcvConfigSetName)/*[1]"!][!//
[!LOOP "CanTrcvChannel/*"!][!//

[!IF "./CanTrcvChannelUsed = 'true'"!][!//
[!//
/*******************************************************************************
**   CanTransceiver Channel [!"./CanTrcvChannelId "!] Specific Information                            **
*******************************************************************************/
/*
Configuration: Channel is used or not
- if STD_ON, Is used
- if STD_OFF, Is not used
*/
#define CANTRCV_17_6251G_CHANNEL_USED_[!"./CanTrcvChannelId"!]                      ([!//
[!IF "./CanTrcvChannelUsed = 'true'"!][!//
STD_ON)[!//

[!IF "./CanTrcvChannelUsed = 'true'"!][!//
[!VAR "ChannelCount" = "$ChannelCount + 1"!][!//
[!ENDIF!][!//

/*
Configuration: Channel Identififier
*/
[!VAR "SymbolicName" = "node:name(.)"!][!//
#ifdef [!"$SymbolicName"!] /* to prevent double declaration */
#error [!"$SymbolicName"!] already defined
#endif
 /* End of  #ifdef [!"$SymbolicName"!] */
#define [!"$SymbolicName"!]     ([!"(num:i(./CanTrcvChannelId))"!]U)

/*
Configuration: CAN Transceiver State after power on
- CanTrcvOpModeNormal
- CanTrcvOpModeStandby
- CanTrcvOpModeSleep
*/

[!IF "./CanTrcvInitState = 'CANTRCV_OP_MODE_NORMAL'"!][!//
#define CANTRCV_17_6251G_INIT_STATE_[!"./CanTrcvChannelId"!]    (CANTRCV_OP_MODE_NORMAL)
[!ELSEIF "./CanTrcvInitState = 'CANTRCV_OP_MODE_STANDBY'"!][!//
#define CANTRCV_17_6251G_INIT_STATE_[!"./CanTrcvChannelId"!]    (CANTRCV_OP_MODE_STANDBY)
[!ELSEIF "./CanTrcvInitState = 'CANTRCV_OP_MODE_SLEEP'"!][!//
#define CANTRCV_17_6251G_INIT_STATE_[!"./CanTrcvChannelId"!]    (CANTRCV_OP_MODE_SLEEP)
[!VAR "SleepInitCount" = "$SleepInitCount + 1"!][!//
[!ENDIF!][!//

/*
Configuration: Wake up by bus
- if STD_ON, Is used
- if STD_OFF, Is not used
*/
#define CANTRCV_17_6251G_WAKEUP_BY_BUS_USED_[!"./CanTrcvChannelId"!]                ([!//
[!IF "./CanTrcvWakeupByBusUsed/*[1] = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!])[!//


/*
Configuration: ECU Power Control Supply
- if STD_ON, Controlled by transceiver
- if STD_OFF, Not controlled by transceiver
*/
#define CANTRCV_17_6251G_CONTROLS_POWER_SUPPLY_[!"./CanTrcvChannelId"!]             ([!//
[!IF "./CanTrcvControlsPowerSupply = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!])[!//


/*
Configuration: CANTRCV_MAX_BAUDRATE
- Range: 0 to 1000KB
*/
#define CANTRCV_17_6251G_MAX_BAUDRATE_[!"./CanTrcvChannelId"!]                      ([!"./CanTrcvMaxBaudrate"!]U)

[!IF "(CanTrcvGeneral/CanTrcvWakeUpSupport != 'CANTRCV_WAKEUP_NOT_SUPPORTED') and (./CanTrcvWakeupByBusUsed/*[1] = 'true')"!][!//
[!ASSERT "node:refexists(./CanTrcvWakeupSourceRef/*[1]) ='true'"!][!//
ERROR: Provide CanTrcvWakeupSource reference for Channel[!"./CanTrcvChannelId"!]
[!ENDASSERT!][!//
[!ENDIF!][!//

[!IF "(CanTrcvGeneral/CanTrcvRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "CanTrcvGeneral/CanTrcvUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "CanTrcvGeneral/CanTrcvUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "CanTrcvGeneral/CanTrcvUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: CanTrcvRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
CanTrcvUserModeRuntimeApiEnable, CanTrcvUserModeInitApiEnable or CanTrcvUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: CANTRCV6251G_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "CanTrcvGeneral/CanTrcvRunningInUser0Mode = 'true'"!][!//
#define CANTRCV6251G_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define CANTRCV6251G_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: CANTRCV6251G_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "CanTrcvGeneral/CanTrcvUserModeInitApiEnable = 'true'"!][!//
#define CANTRCV6251G_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  CANTRCV6251G_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: CANTRCV6251G_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "CanTrcvGeneral/CanTrcvUserModeDeInitApiEnable = 'true'"!][!//
#define CANTRCV6251G_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  CANTRCV6251G_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: CANTRCV6251G_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "CanTrcvGeneral/CanTrcvUserModeRuntimeApiEnable = 'true'"!][!//
#define CANTRCV6251G_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  CANTRCV6251G_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/* CanTrcvWakeupSource reference  */
[!IF "node:refexists(./CanTrcvWakeupSourceRef/*[1]) ='true'"!][!//
#define CANTRCV_17_6251G_WAKEUP_SOURCE_REF_[!"./CanTrcvChannelId"!]                ([!"node:ref(./CanTrcvWakeupSourceRef/*[1])/EcuMWakeupSourceId"!]U)
[!ELSE!]
#define CANTRCV_17_6251G_WAKEUP_SOURCE_REF_[!"./CanTrcvChannelId"!]                (0xFFU)
[!ENDIF!][!//
/* 
Configuration : CanTransceiverDIOAccess 
*/

[!LOOP "./CanTrcvAccess/CanTrcvDioChannelAccess/*"!][!//
[!ASSERT "node:refexists(CanTrcvDioSymNameRef) = 'true'"!][!//
ERROR: Provide Dio reference for [!"node:path(.)"!]
[!ENDASSERT!][!//
[!IF "CanTrcvHardwareInterfaceName = 'EN'"!][!//
[!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef))"!][!//
#define CANTRCV_17_6251G_DIO_EN_[!"../../../CanTrcvChannelId"!]       (DioConf_DioChannel_[!"$DioChannelName"!])
[!ENDIF!][!//
[!IF "CanTrcvHardwareInterfaceName = 'NSTB'"!][!//
[!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef))"!][!//
#define CANTRCV_17_6251G_DIO_NSTB_[!"../../../CanTrcvChannelId"!]       (DioConf_DioChannel_[!"$DioChannelName"!])
[!ENDIF!][!//
[!IF "CanTrcvHardwareInterfaceName = 'NERR'"!][!//
[!VAR "DioChannelName" = "node:name(node:ref(CanTrcvDioSymNameRef))"!][!//
#define CANTRCV_17_6251G_DIO_NERR_[!"../../../CanTrcvChannelId"!]       (DioConf_DioChannel_[!"$DioChannelName"!])
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
/* 
Internal value for Initialization 
*/
[!IF "./CanTrcvInitState = 'CANTRCV_OP_MODE_NORMAL' "!][!//
#define CANTRCV_17_6251G_INIT_STATE_CTRLPIN_SETTING_[!"./CanTrcvChannelId"!]        (3U)
[!//
[!ELSEIF "./CanTrcvInitState = 'CANTRCV_OP_MODE_STANDBY'"!][!//
#define CANTRCV_17_6251G_INIT_STATE_CTRLPIN_SETTING_[!"./CanTrcvChannelId"!]        (0U)
[!//
[!ELSEIF "./CanTrcvInitState = 'CANTRCV_OP_MODE_SLEEP'"!][!//
#define CANTRCV_17_6251G_INIT_STATE_CTRLPIN_SETTING_[!"./CanTrcvChannelId"!]        (1U)
[!ENDIF!][!//

[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
/* Channel/s is configured for Sleep State */
[!IF "num:i($SleepInitCount) > '0' "!][!//
#define CANTRCV_17_6251G_INIT_SLEEP_STATE                    (STD_ON)
[!ELSE!][!//
#define CANTRCV_17_6251G_INIT_SLEEP_STATE                    (STD_OFF)
[!ENDIF!][!//
[!//
[!ENDSELECT!][!//
[!//
[!FOR "Channel" = "num:i($ChannelCount)" TO "num:i($MaxChannels)"!][!//

#define CANTRCV_17_6251G_CHANNEL_USED_[!"num:i($Channel)"!]         (STD_OFF)
[!ENDFOR!][!//

/* Number of Channels Configured */
#define CANTRCV_17_6251G_CHANNELS_CFG             [!"num:i($ChannelCount)"!]U

/* Number of Channels supported by HW */
#define CANTRCV_17_6251G_MAX_CH_SUPPORT        ([!"num:i(ecu:get('CanTrcv.MaxChannels'))"!]U)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif
  /*END OF  CANTRCV_17_6251G_CFG_H */
[!ENDSELECT!]