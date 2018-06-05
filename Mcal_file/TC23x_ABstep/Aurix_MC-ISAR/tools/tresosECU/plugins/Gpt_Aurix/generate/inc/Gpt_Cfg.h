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
**  $FILENAME   : Gpt_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\37 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-13 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**                                                                           **
**  DESCRIPTION  : Code template for Gpt_Cfg.h file                          **
**                                                                           **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release 4.0.3                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY: [cover parentID=DS_AS40X_GPT333,
    DS_NAS_PR69_PR469,SAS_NAS_GPT_PR483,DS_NAS_PR446,DS_AS40X_GPT_PR2849,
    SAS_NAS_GPT_PR914,SAS_NAS_GPT_PR915,SAS_NAS_GPT_PR916,SAS_AS4XX_GPT_PR678,
    DS_NAS_EP_GPT_PR3054_1,DS_NAS_EP_GPT_PR3054_2,DS_NAS_EP_GPT_PR3054_3,
    DS_NAS_EP_GPT_PR3054_4,DS_NAS_HE2_GPT_PR3054_1,DS_NAS_HE2_GPT_PR3054_2,
    DS_NAS_HE2_GPT_PR3054_3,DS_NAS_HE2_GPT_PR3054_4]
**  [/cover]                                                                  **
*/!][!//
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
**  FILENAME  : Gpt_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\37 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : Gpt.xdm                                          **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GPT configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release-4.0                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/******************************************************************************/
#ifndef  GPT_CFG_H
#define  GPT_CFG_H

[!NOCODE!]
[!INCLUDE "Gpt.m"!]
[!ENDNOCODE!]

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*Section to Generate Autosar Specific Version Information*/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//


[!IF "$MajorVersion = num:i(4)"!][!//
#define GPT_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define GPT_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define GPT_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/*Section to Generate Vendor Specific Version Information*/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define GPT_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define GPT_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define GPT_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)





[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//. 
[!//
/*
Container : GptDriverConfiguration - GPT183:
This container contains the channel-wide configuration (parameters) of
the GPT Driver.
*/

/*
Configuration: GPT_DEV_ERROR_DETECT
Preprocessor switch to enable/disable the development error detection and 
reporting. ( GPT183:,GPT175:,GPT176:,GPT177:,GPT178: )
- if STD_ON, Enable development error detection 
- if STD_OFF, Disable development error detection
*/
#define GPT_DEV_ERROR_DETECT                  ([!//
[!IF "GptDriverConfiguration/GptDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: GPT_REPORT_WAKEUP_SOURCE
Preprocessor switch to enable/disable the wakeup source reporting - GPT183:
- if STD_ON, Report wakeup source 
- if STD_OFF, Dont report wakeup source
*/
#define GPT_REPORT_WAKEUP_SOURCE              ([!//
[!IF "GptDriverConfiguration/GptReportWakeupSource = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: GPT_DEBUG_SUPPORT
Preprocessor switch to enable/disable the Debug Support
which is applicable to AS402	 - GPT333,GPT334,GPT337:
- if STD_ON, Debug Support Enabled 
- if STD_OFF, Debug Support Disabled 
(Always STD_OFF for versions other than AS402)
*/



#define GPT_DEBUG_SUPPORT              ([!//
[!IF "GptDriverConfiguration/GptDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)




[!NOCODE!][!//
[!VAR "ChannelMax" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
  [!VAR "ConfChannelMax" = "num:i(count(GptChannelConfiguration/*))"!][!//
  [!IF "$ConfChannelMax > $ChannelMax"!][!//
    [!VAR "ChannelMax" =  "$ConfChannelMax"!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!// 
[!ENDNOCODE!][!//
#define GPT_MAX_CHANNELS  ([!"num:i($ChannelMax)"!]U)
[!ENDSELECT!][!//


[!NOCODE!]
[!VAR "AsilMax1" = "num:i(0)"!][!//
[!VAR "AsilMax" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!VAR "AsilMax" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfiguration/*"!][!//
[!VAR "SignalType" = "GptSignalType"!][!//
[!IF "$SignalType = 'GPT_ASIL_SIGNAL'"!][!//
[!VAR "AsilMax" = "$AsilMax + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$AsilMax > $AsilMax1"!][!//
[!VAR "AsilMax1" = "$AsilMax"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "GptSafety/GptSafetyEnable = 'false'"!][!//
[!VAR "AsilMax1" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define GPT_MAX_ASIL_CHANNELS  ([!"num:i($AsilMax1)"!]U)



[!NOCODE!]
[!VAR "QMMax1" = "num:i(0)"!][!//
[!VAR "QMMax" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!VAR "QMMax" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfiguration/*"!][!//
[!VAR "SignalType" = "GptSignalType"!][!//
[!IF "$SignalType = 'GPT_QM_SIGNAL'"!][!//
[!VAR "QMMax" = "$QMMax + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$QMMax > $QMMax1"!][!//
[!VAR "QMMax1" = "$QMMax"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "GptSafety/GptSafetyEnable = 'false'"!][!//
[!VAR "QMMax1" = "num:i($ChannelMax)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#define GPT_MAX_QM_CHANNELS  ([!"num:i($QMMax1)"!]U)

[!NOCODE!]
[!VAR "TomNo" = "num:i(0)"!][!//
[!VAR "AtomNo" = "num:i(0)"!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!VAR "MaxChannels"= "num:i(count(GptChannelConfiguration/*))"!][!//
[!FOR "ChannelId" = "num:i(1)" TO "num:i($MaxChannels)"!][!//
[!SELECT "GptChannelConfiguration/*[GptChannelId = num:i($ChannelId) - num:i(1)]"!][!//
[!VAR "GtmRef" = "node:path(node:ref(./GptAssignedHwUnit))"!][!//
[!IF "contains($GtmRef, '/Tom/') = 'true'"!][!//
[!VAR "TomNo" = "num:i($TomNo) + num:i(1)"!][!//
[!ELSEIF "contains($GtmRef, '/Atom/') = 'true'"!][!//
[!VAR "GtmMod" ="'ATOM'"!][!//
[!VAR "AtomNo" = "num:i($AtomNo) + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDLOOP!][!// 
[!ENDSELECT!][!//
[!ENDNOCODE!][!//

#define GPT_TOM_USED              ([!//
[!IF "$TomNo > num:i(0)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

#define GPT_ATOM_USED              ([!//
[!IF "$AtomNo > num:i(0)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Container : Configuration of optional API services - GPT193:
This container contains all configuration switches for configuring
optional API services of the GPT driver.
*/
[!SELECT "as:modconf('Gpt')[1]/GptConfigurationOfOptApiServices"!][!//. 

/*
Configuration: GPT_VERSION_INFO_API
Adds/removes the service Gpt_GetVersionInfo() from the code 
- if STD_ON, Gpt_GetVersionInfo() can be used
- if STD_OFF, Gpt_GetVersionInfo() can not be used
*/
#define GPT_VERSION_INFO_API                  [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptVersionInfoApi"!][!//

/*
Configuration: GPT_DEINIT_API
Adds/removes the service Gpt_DeInit() from the code 
- if STD_ON, Gpt_DeInit() can be used
- if STD_OFF, Gpt_DeInit() can not be used
*/
#define GPT_DEINIT_API                        [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptDeinitApi"!][!//

/*
Configuration: GPT_TIME_ELAPSED_API
Adds/removes the service Gpt_GetTimeElapsed() from the code 
- if STD_ON, Gpt_GetTimeElapsed() can be used
- if STD_OFF, Gpt_GetTimeElapsed() can not be used
*/
#define GPT_TIME_ELAPSED_API                  [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptTimeElapsedApi"!][!//

/*
Configuration: GPT_TIME_REMAINING_API
Adds/removes the service Gpt_GetTimeRemaining() from the code 
- if STD_ON, Gpt_GetTimeRemaining() can be used
- if STD_OFF, Gpt_GetTimeRemaining() can not be used
*/
#define GPT_TIME_REMAINING_API                [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptTimeRemainingApi"!][!//

/*
Configuration: GPT_ENABLE_DISABLE_NOTIFICATION_API
Adds/removes the service Gpt_EnableNotification() and Gpt_DisableNotification 
from the code 
- if STD_ON, Gpt_EnableNotification() and Gpt_DisableNotification  can be used
- if STD_OFF, Gpt_EnableNotification() and Gpt_DisableNotification  can not be
  used
*/
#define GPT_ENABLE_DISABLE_NOTIFICATION_API   [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptEnableDisableNotificationApi"!][!//

/*
Configuration: GPT_WAKEUP_FUNCTIONALITY_API
Adds/removes the service Gpt_SetMode(), Gpt_EnableWakeup(),
Gpt_DisableWakeup() and Gpt_CheckWakeup() from the code 
- if STD_ON, Gpt_SetMode(), Gpt_EnableWakeup(), Gpt_DisableWakeup() and 
  Gpt_CheckWakeup() can be used
- if STD_OFF, Gpt_SetMode(), Gpt_EnableWakeup(), Gpt_DisableWakeup() and 
  Gpt_CheckWakeup() can not be used
*/
#define GPT_WAKEUP_FUNCTIONALITY_API          [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptWakeupFunctionalityApi"!][!//
[!//

/*
Configuration: GPT_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define GPT_RUNNING_IN_USER_0_MODE_ENABLE   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "GptRunningInUser0Mode"!][!//
[!IF "(GptRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "GptUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "GptUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "GptUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: GptRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
GptUserModeRuntimeApiEnable, GptUserModeInitApiEnable or GptUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//
/*
Configuration: GPT_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Disable Supervisor mode in Init API  
*/
#define GPT_USER_MODE_INIT_API_ENABLE         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "GptUserModeInitApiEnable"!][!//

/*
Configuration: GPT_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Disable Supervisor mode in Init API  
*/
#define GPT_USER_MODE_DEINIT_API_ENABLE       [!//
[!CALL "CG_ConfigSwitch","nodeval" = "GptUserModeDeInitApiEnable"!][!//

/*
Configuration: GPT_USER_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Disable Supervisor mode in Init API  
*/
#define GPT_USER_MODE_RUNTIME_API_ENABLE           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "GptUserModeRuntimeApiEnable"!][!//
[!ENDSELECT!][!//
[!//


[!SELECT "as:modconf('Gpt')[1]/GptSafety"!][!//.
/*
Configuration: GPT_SAFETY_ENABLE
Preprocessor switch to enable/disable the GPT Safety features.
- if STD_ON, GPT Safety Enabled 
- if STD_OFF, GPT Safety Disabled
*/
#define GPT_SAFETY_ENABLE          [!//
[!CALL "CG_ConfigSwitch", "nodeval" = "GptSafetyEnable"!][!//
[!//
[!ENDSELECT!][!//
[!//


/*
Configuration: GPT_INITCHECK_API
Preprocessor switch to enable/disable the GPT InitCheck API.
- if STD_ON, GPT InitCheck API Enabled 
- if STD_OFF, GPT InitCheck API Disabled
*/
#define GPT_INITCHECK_API              ([!//
[!IF "GptSafety/GptSafetyEnable = 'true'"!][!//
[!IF "GptSafety/GptInitCheckApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: GPT_GETMODE_API
Preprocessor switch to enable/disable the GPT GetMode API.
- if STD_ON, GPT GetMode API Enabled 
- if STD_OFF, GPT GetMode API Disabled
*/
#define GPT_GETMODE_API              ([!//
[!IF "GptSafety/GptSafetyEnable = 'true'"!][!//
[!IF "GptSafety/GptGetModeApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


[!SELECT "as:modconf('Gpt')[1]"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
/* 
   Gpt Channel ID Enumerations for Channel Configuration Instance 
   [!"node:name(.)"!]
*/
[!VAR "ChannelCounter" = "'0'"!][!//
[!LOOP "./GptChannelConfiguration/*"!][!//
[!VAR "TimerType" = "GptAssignedHwUnit"!][!//
#ifndef GptConf_GptChannel_[!"node:name(.)"!]
#define GptConf_GptChannel_[!"node:name(.)"!]  ((Gpt_ChannelType)[!"GptChannelId"!]U)
#endif
[!VAR "ChannelCounter" = "$ChannelCounter + 1"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//





/*******************************************************************************
**                      Derived Configuration Parameters                      **
*******************************************************************************/
[!NOCODE!]
[!VAR "OsmUsed" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!LOOP "./GptChannelConfiguration/*"!][!//
[!VAR "Mode" = "GptChannelMode"!][!//
[!IF "$Mode = 'GPT_CH_MODE_ONESHOT'"!][!//
[!VAR "OsmUsed" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$OsmUsed = num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

/*
Configuration: GPT_ONESHOT_USED
The configuration contains oneshot mode channels
*/
[!IF "$OsmUsed = num:i(1)"!][!//
#define GPT_ONESHOT_USED                      (STD_ON)
[!ELSE!][!//
#define GPT_ONESHOT_USED                      (STD_OFF)
[!ENDIF!][!//


/*
Configuration: GPT_PB_FIXEDADDR
   This parameter enables the user to fix the PB config pointer to first 
   instance of configuration
*/
[!NOCODE!][!//
[!//
[!VAR "TotalGptConfig" = "num:i(count(GptChannelConfigSet/*))"!][!//
[!/* Determine only one GptChannelConfigSet is configured 
                                        when GptPBFixedAddress = true.*/!]
[!IF "GptDriverConfiguration/GptPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalGptConfig != 1)"!][!//
Config Error: when GptDriverConfiguration/GptPBFixedAddress is set as true, [!//
Only one GptChannelConfigSet configuration is allowed. [!//
But GptChannelConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "node:exists(GptDriverConfiguration/GptPBFixedAddress)"!][!//
#define GPT_PB_FIXEDADDR                      ([!//
[!IF "GptDriverConfiguration/GptPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ELSE!][!//
#define GPT_PB_FIXEDADDR                      (STD_OFF)
[!ENDIF!][!//

/* Total no. of config sets */
#define GPT_CONFIG_COUNT  ([!"num:i(count(GptChannelConfigSet/*))"!]U)
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

[!ENDSELECT!][!//
#endif /* GPT_CFG_H */
