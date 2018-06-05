[!/*****************************************************************************
/******************************************************************************
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
**  $FILENAME   : Icu_17_GtmCcu6_Cfg.h $                                     **
**                                                                           **
**  $CC VERSION : \main\40 $                                                 **
**                                                                           **
**  $DATE       : 2016-04-26 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :  Code template for Icu_17_GtmCcu6_PBCfg.h file             **
**                                                                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=DS_AS40X_ICU350,DS_AS_ICU002, 
    DS_AS_ICU118,DS_AS_ICU189,DS_NAS_ICU_PR69_PR469,DS_NAS_ICU_PR446,DS_AS403_PR2849,
    SAS_NAS_ICU_PR914,SAS_NAS_ICU_PR915,SAS_NAS_ICU_PR916,SAS_AS4XX_ICU_PR678,
    SAS_AS4XX_ICU_PR680,DS_NAS_HE2_ICU_PR3017,DS_NAS_EP_ICU_PR3017,
    DS_NAS_HE2_ICU_PR3054_5,DS_NAS_HE2_ICU_PR3054_6,DS_NAS_HE2_ICU_PR3054_7,
    DS_NAS_HE2_ICU_PR3054_8,DS_NAS_EP_ICU_PR3054_5,DS_NAS_EP_ICU_PR3054_6,
    DS_NAS_EP_ICU_PR3054_7,DS_NAS_EP_ICU_PR3054_8]
        [/cover] */!][!//
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
**  FILENAME  : Icu_17_GtmCcu6_PBCfg.h                                        **
**                                                                            **
**  $CC VERSION : \main\40 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Icu configuration generated out of ECU configuration       **
**                 file  (Icu_17_GtmCcu6.bmd)                                 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


#ifndef ICU_17_GTMCCU6_CFG_H
#define ICU_17_GTMCCU6_CFG_H

[!NOCODE!][!//
[!INCLUDE "Icu_17_GtmCcu6.m"!][!//
[!ENDNOCODE!][!//

[!SELECT "as:modconf('Icu')[1]"!][!// 

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
#define ICU_17_GTMCCU6_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define ICU_17_GTMCCU6_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define ICU_17_GTMCCU6_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/*Section to Generate Vendor Specific Version Information*/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define ICU_17_GTMCCU6_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define ICU_17_GTMCCU6_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define ICU_17_GTMCCU6_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)




[!IF "./IcuGeneral/IcuDebugSupport = 'true'"!][!//
#define ICU_DEBUG_SUPPORT (STD_ON)
[!ELSE!][!//
#define ICU_DEBUG_SUPPORT (STD_OFF)
[!ENDIF!][!//


/*
    Configuration : ICU_SAFETY_ENABLE
    Pre-processor switch to enable/disable the ICU driver safety features.
*/
[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_SAFETY_ENABLE (STD_ON)
[!ELSE!][!//
#define ICU_SAFETY_ENABLE (STD_OFF)
[!ENDIF!][!//

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
/*
    Configuration : ICU_INITCHECK_API (IcuInitCheckApi)
    Pre-processor switch to enable/disable the API Icu_InitCheck.
*/
[!IF "IcuSafety/IcuInitCheckApi = 'true'"!][!//
#define ICU_INITCHECK_API (STD_ON)
[!ELSE!][!//
#define ICU_INITCHECK_API (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
#define ICU_INITCHECK_API (STD_OFF)
[!ENDIF!][!//

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
/*
    Configuration : ICU_GETMODE_API (IcuGetModeApi)
    Pre-processor switch to enable/disable the API IcuGetMode.
*/
[!IF "IcuSafety/IcuGetModeApi = 'true'"!][!//
#define ICU_GETMODE_API (STD_ON)
[!ELSE!][!//
#define ICU_GETMODE_API (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
#define ICU_GETMODE_API (STD_OFF)
[!ENDIF!][!//



[!NOCODE!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "McuSelect" = "'McuModuleConfiguration'"!][!//
[!VAR "TotalMcuConfig" = "num:i(count(node:ref($McuSelect)/*))"!][!//
[!VAR "TotalGtmConfig" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!//
[!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleIndex + 1,']')"!][!//
[!VAR "Count" = "num:i(count(node:ref($McuSelectIndex)/GtmConfiguration/*))"!]
[!IF "$Count > num:i(0)"!][!//    
[!VAR "TotalGtmConfig" = "$TotalGtmConfig + $Count"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!VAR "TotalIcuConfig" = "num:i(count(IcuConfigSet/*))"!][!// 
[!ENDNOCODE!][!//


[!NOCODE!][!//
[!VAR "GetTimeElapsedApi" = "IcuOptionalApis/IcuGetTimeElapsedApi"!][!//
[!VAR "GetDutyCyclesApi" = "IcuOptionalApis/IcuGetDutyCycleValuesApi"!][!//
[!VAR "EdgeCountApi" = "IcuOptionalApis/IcuEdgeCountApi"!]
[!VAR "TimestampApi" = "IcuOptionalApis/IcuTimestampApi"!]
[!VAR "EnableWakeupApi" = "IcuOptionalApis/IcuEnableWakeupApi"!] 
[!VAR "SignalMeasurementApi" = "IcuOptionalApis/IcuSignalMeasurementApi"!] 
[!VAR "EdgeDetectionApi" = "IcuOptionalApis/IcuEdgeDetectApi"!] 
[!ENDNOCODE!][!//

/*
Configuration: ICU_17_GTMCCU6_RESET_SFR_AT_INIT 
- if STD_ON, During Icu_17_GtmCcu6_Init, CCU6 and ERU SFRs will be reset before 
              getting updated.
- if STD_OFF, During Icu_17_GtmCcu6_Init, CCU6 and ERU SFRs will not be reset before 
              getting updated.
*/
#define ICU_17_GTMCCU6_RESET_SFR_AT_INIT  ([!//
[!IF "IcuGeneral/IcuResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ICU_USER_MODE_RUNTIME_API_ENABLE
- if STD_ON, all APIs except Init and DeInit APIs are running in user mode and 
             protected register access is enabled for those APIs.
- if STD_OFF, all APIs except Init and DeInit APIs are running in supervisor mode and 
             protected register access is disabled for those APIs.
*/
#define ICU_USER_MODE_RUNTIME_API_ENABLE  [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuUserModeRuntimeApiEnable"!]

/*
Configuration: ICU_USER_MODE_INIT_API_ENABLE
- if STD_ON, Init API is running in user mode and 
             protected register access is enabled for Init API.
- if STD_OFF, Init API is running in running in supervisor mode and 
             protected register access is disabled for Init API.
*/
#define ICU_USER_MODE_INIT_API_ENABLE  [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuUserModeInitApiEnable"!]

/*
Configuration: ICU_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, DeInit API is running in user mode and 
             protected register access is enabled for DeInit API.
- if STD_OFF, DeInit API is running in running in supervisor mode and 
             protected register access is disabled for DeInit API.
*/
#define ICU_USER_MODE_DEINIT_API_ENABLE  [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuUserModeDeInitApiEnable"!]

/*
Configuration: ICU_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, user0 mode is enabled.
- if STD_OFF, user1 mode is enbled.
*/
#define ICU_RUNNING_IN_USER_0_MODE_ENABLE  [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuRunningInUser0Mode"!]
[!IF "IcuGeneral/IcuRunningInUser0Mode = 'true'"!]
[!ASSERT "IcuGeneral/IcuUserModeRuntimeApiEnable = 'true' or IcuGeneral/IcuUserModeInitApiEnable = 'true' or 
 IcuGeneral/IcuUserModeDeInitApiEnable = 'true'"!]
 Config Errror: Inorder to configure IcuRunningInUser0Mode as true, atleaset one of the parameters  IcuUserModeRuntimeApiEnable,
 IcuUserModeInitApiEnable, IcuUserModeDeInitApiEnable should be configured as true.
[!ENDASSERT!]
[!ENDIF!]
 
/* Total nubber of ICU config sets */
#define ICU_CONFIG_COUNT  ([!"num:i($TotalIcuConfig)"!]U)

/* ICU026: General Configuration */
/*
Configuration: ICU_DEV_ERROR_DETECT
Adds/removes the Development Error Detection 
from the code 
- if STD_ON, Development error detection is enabled
- if STD_OFF, Development error detection is disabled
*/
/* ICU111: Development error detection  */
#define ICU_DEV_ERROR_DETECT           [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuDevErrorDetect"!]
/*
Configuration: ICU_REPORT_WAKEUP_SOURCE
Preprocessor switch to enable/disable the wakeup source reporting
- if STD_ON, Reports wakeup to higher layer
- if STD_OFF, Reporting is switched off
*/
/* ICU055: Report Wakeup source to the higher layer */
#define ICU_REPORT_WAKEUP_SOURCE       [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuReportWakeupSource"!]
/*
Configuration: ICU_PB_FIXEDADDR
This parameter enables the user to switch STD_ON/STD_OFF 
the PostBuild Fixed Address Feature
- if STD_ON, PostBuild Fixed Address Feature is enabled
- if STD_OFF,PostBuild Fixed Address Feature is disabled
*/
[!NOCODE!][!//
[!//
[!VAR "TotalIcuConfig" = "num:i(count(IcuConfigSet/*))"!][!//
[!/* Determine only one IcuConfigSet is configured 
                                        when IcuPBFixedAddress = true.*/!]
[!IF "IcuGeneral/IcuPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalIcuConfig != 1)"!][!//
Config Error: when IcuGeneral/IcuPBFixedAddress is set as true, [!//
Only one IcuConfigSet configuration is allowed. [!//
But IcuConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "node:exists(IcuGeneral/IcuPBFixedAddress)"!][!//
#define ICU_PB_FIXEDADDR               [!CALL "CG_ConfigSwitch", "nodeval" = "IcuGeneral/IcuPBFixedAddress"!]
[!ELSE!][!//
#define ICU_PB_FIXEDADDR               (STD_OFF)
[!ENDIF!][!//
/*
Configuration: ICU_DE_INIT_API
Adds/removes Icu_DeInit API 
from the code 
- if STD_ON, Icu_DeInit is enabled
- if STD_OFF, Icu_DeInit is disabled
*/
/* ICU114: Configuration Icu_DeInit API*/
#define ICU_DE_INIT_API                [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuDeInitApi"!]
/*
Configuration: ICU_DISABLE_WAKEUP_API
Adds/removes Icu_DisableWakeup API 
from the code 
- if STD_ON, Icu_DisableWakeup is enabled
- if STD_OFF, Icu_DisableWakeup is disabled
*/
/* ICU114:Configuration Icu_DisableWakeup API */
#define ICU_DISABLE_WAKEUP_API         [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuDisableWakeupApi"!]
/*
Configuration: ICU_ENABLE_WAKEUP_API
Adds/removes Icu_EnableWakeup API 
from the code 
- if STD_ON, Icu_EnableWakeup is enabled
- if STD_OFF, Icu_EnableWakeup is disabled
*/
/* ICU114:Configuration Icu_EnableWakeup API */
#define ICU_ENABLE_WAKEUP_API          [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuEnableWakeupApi"!]
/*
Configuration: ICU_EDGE_COUNT_API
Adds/removes Edge Count Measurement APIs 
from the code 
- if STD_ON, Icu_EnableEdgeCount, Icu_DisableEdgeCount
         Icu_ResetEdgeCount, Icu_GetEdgeNumbers is enabled
- if STD_OFF, Icu_EnableEdgeCount, Icu_DisableEdgeCount
         Icu_ResetEdgeCount, Icu_GetEdgeNumbers is disabled
*/
/* ICU124:Configuration Icu_EdgeCount API */
#define ICU_EDGE_COUNT_API             [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuEdgeCountApi"!]
/*
Configuration: ICU_GET_DUTY_CYCLE_VALUES_API
Adds/removes Icu_GetDutyCycleValues API 
from the code 
- if STD_ON, Icu_GetDutyCycleValues is enabled
- if STD_OFF, Icu_GetDutyCycleValues is disabled
*/
/* ICU114:Configuration Icu_GetDutyCycleValues API */
#define ICU_GET_DUTY_CYCLE_VALUES_API  [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuGetDutyCycleValuesApi"!]
/*
Configuration: ICU_GET_INPUT_STATE_API
Adds/removes Icu_GetInputState API 
from the code 
- if STD_ON, Icu_GetInputState is enabled
- if STD_OFF, Icu_GetInputState is disabled
*/
/* ICU114:Configuration Icu_GetInputState API */
#define ICU_GET_INPUT_STATE_API        [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuGetInputStateApi"!]
/*
Configuration: ICU_GET_TIME_ELAPSED_API
Adds/removes Icu_GetTimeElapsed API 
from the code 
- if STD_ON, Icu_GetTimeElapsed is enabled
- if STD_OFF, Icu_GetTimeElapsed is disabled
*/
/* ICU114:Configuration Icu_GetTimeElapsed API */
#define ICU_GET_TIME_ELAPSED_API       [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuGetTimeElapsedApi"!]
/*
Configuration: ICU_GET_VERSION_INFO_API
Adds/removes Icu_GetVersionInfo API 
from the code 
- if STD_ON, Icu_GetVersionInfo is enabled
- if STD_OFF, Icu_GetVersionInfo is disabled
*/
/* ICU114:Configuration Icu_GetVersionInfo API */
#define ICU_GET_VERSION_INFO_API       [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuGetVersionInfoApi"!]
/*
Configuration: ICU_SET_MODE_API
Adds/removes Icu_SetMode API 
from the code 
- if STD_ON, Icu_SetMode is enabled
- if STD_OFF, Icu_SetMode is disabled
*/
/* ICU114:Configuration Icu_SetMode API */
#define ICU_SET_MODE_API               [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuSetModeApi"!]
/*
Configuration: ICU_TIMESTAMP_API
Adds/removes Edge Count Measurement APIs 
from the code 
- if STD_ON, Icu_StartTimestamp, Icu_StopTimestamp
         Icu_GetTimestampIndex is enabled
- if STD_OFF, Icu_StartTimestamp, Icu_StopTimestamp
         Icu_GetTimestampIndex is disabled
*/
/* ICU123: configuration of timestamp API */
#define ICU_TIMESTAMP_API              [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuTimestampApi"!]

/*
Configuration: ICU_SIGNAL_MEASUREMENT_API
Adds/removes Signal Measurement APIs 
from the code 
- if STD_ON, Icu_StartSignalMeasurement, Icu_StopSignalMeasurement
         Icu_GetTimeElapsed, Icu_GetDutyCycleValues is enabled
- if STD_OFF, Icu_StartSignalMeasurement, Icu_StopSignalMeasurement
         Icu_GetTimeElapsed, Icu_GetDutyCycleValues is disabled
*/
/* ICU123: configuration of timestamp API */
#define ICU_SIGNAL_MEASUREMENT_API              [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuSignalMeasurementApi"!]


/*
Configuration: ICU_EDGE_DETECT_API
Adds/removes Signal Measurement APIs 
from the code 
- if STD_ON, Edge Detection functionality is enabled
- if STD_OFF, Edge Detection functionality is disabled
*/
/* ICU123: configuration of timestamp API */
#define ICU_EDGE_DETECT_API                     [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuEdgeDetectApi"!]

/*
Configuration: ICU_NO_OF_CCU6_MODULES
Number of CCU6 modules present in the device
*/
#define ICU_NO_OF_CCU6_MODULES       [!"ecu:get('Ccu6.MaxKernals')"!]

/*
Configuration: ICU_NO_OF_CCU6_CHANNELS
Number of CCU6 channels present in 1 CCU6 Kernal
*/
#define ICU_NO_OF_CCU6_CHANNELS       [!"ecu:get('Ccu6.MaxT12Channels')"!]


/*
Configuration: ICU_WAKEUP_FUNCTIONALITY_API
Adds/removes the service Icu_CheckWakeup() 
from the code 
- if ON, the service Icu_CheckWakeup() is enabled
- if OFF, the service Icu_CheckWakeup() is disabled
*/
/* ICU355_Conf: Adds / removes the service Icu_CheckWakeup() from the code */
#define ICU_WAKEUP_FUNCTIONALITY_API        [!CALL "CG_ConfigSwitch", "nodeval" = "IcuOptionalApis/IcuWakeupFunctionalityApi"!] 

/*
Configuration: ICU_17_GTMCCU6_INSTANCE_ID
InstanceId of ICU module
*/
/* InstanceId of ICU module  */
#define ICU_17_GTMCCU6_INSTANCE_ID       ((uint8)[!"num:i(node:value(IcuGeneral/IcuIndex))"!])


[!VAR "TotalIcuConfig" = "num:i(count(IcuConfigSet/*))"!][!//
[!VAR "MaxTimestampAsilChannels" = "num:i(0)"!][!//
[!VAR "MaxTimestampQmChannels" = "num:i(0)"!][!//

[!VAR "MaxEdgecountAsilChannels" = "num:i(0)"!][!//
[!VAR "MaxEdgecountQmChannels" = "num:i(0)"!][!//

[!VAR "MaxSigmeasQmChannels" = "num:i(0)"!][!//
[!VAR "MaxEdgeDetectionAsilGtmChannels" = "num:i(0)"!][!//
[!VAR "MaxEdgeDetectionQmGtmChannels" = "num:i(0)"!][!//
[!VAR "MaxEdgeDetectionAsilCcu6Channels" = "num:i(0)"!][!//
[!VAR "MaxEdgeDetectionQmCcu6Channels" = "num:i(0)"!][!//
[!VAR "MaxEdgeDetectionQmEruChannels" = "num:i(0)"!][!//

[!VAR "MaxSigMeasurementQmGtmChannels" = "num:i(0)"!][!//
[!VAR "MaxSigMeasurementAsilGtmChannels" = "num:i(0)"!][!//
[!VAR "MaxSigMeasurementQmCcu6Channels" = "num:i(0)"!][!//
[!VAR "MaxSigMeasurementAsilCcu6Channels" = "num:i(0)"!][!//

[!VAR "MaxSignalEdgeChannels" = "num:i(0)"!][!//
[!VAR "MaxSignalEdgeAsilChannels" = "num:i(0)"!][!//
[!VAR "MaxDutyCycleChannels" = "num:i(0)"!][!//
[!VAR "MaxTimeElapsedChannels" = "num:i(0)"!][!//
[!VAR "MaxChannelCount" = "num:i(0)"!][!//

[!VAR "MaxQmGtmChannels" = "num:i(0)"!][!//

[!VAR "MaxAsilGtmChannels" = "num:i(0)"!][!//

[!VAR "MaxAsilCcu6Channels" = "num:i(0)"!][!//

[!VAR "MaxQmCcu6Channels" = "num:i(0)"!][!//

[!VAR "MaxQmChannels" = "num:i(0)"!][!//

[!VAR "MaxAsilChannels" = "num:i(0)"!][!//


[!VAR "IcuSafetyEnabled" = "IcuSafety/IcuSafetyEnable"!][!//
[!FOR "ModuleId" = "num:i(1)" TO "num:i($TotalIcuConfig)"!][!//  
[!NOCODE!][!//

[!SELECT "IcuConfigSet/*[num:i($ModuleId)]"!][!//
[!VAR "TimestampAsilChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_TIMESTAMP'and IcuSignalType='ICU_ASIL_SIGNAL' ]))"!][!//
[!VAR "EdgecountAsilChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_EDGE_COUNTER' and IcuSignalType='ICU_ASIL_SIGNAL']))"!][!//
[!VAR "EdgeDetectionAsilGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "EdgeDetectionAsilCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//
[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!VAR "TimestampQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_TIMESTAMP'and IcuSignalType='ICU_QM_SIGNAL' ]))"!][!//
[!VAR "EdgecountQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_EDGE_COUNTER' and IcuSignalType='ICU_QM_SIGNAL']))"!][!//
[!VAR "EdgeDetectionQmGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "EdgeDetectionQmCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//
[!VAR "EdgeDetectionQmEruChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "EruConfiguration") = 'true']))"!][!//
[!ELSE!][!//
[!VAR "TimestampQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_TIMESTAMP']))"!][!//
[!VAR "EdgecountQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_EDGE_COUNTER']))"!][!//
[!VAR "EdgeDetectionQmGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "EdgeDetectionQmCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//
[!VAR "EdgeDetectionQmEruChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "EruConfiguration") = 'true']))"!][!//
[!ENDIF!][!//

[!VAR "SigMeasurementAsilGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "SigMeasurementAsilCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//
[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!VAR "SigMeasurementQmGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "SigMeasurementQmCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//
[!ELSE!][!//
[!VAR "SigMeasurementQmGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "SigMeasurementQmCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//
[!ENDIF!][!//

[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!VAR "SigmeasQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and IcuSignalType='ICU_QM_SIGNAL']))"!][!//
[!VAR "SigmeasAsilChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT' and IcuSignalType='ICU_ASIL_SIGNAL']))"!][!//

[!VAR "SignalEdgeQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT']) and IcuSignalType='ICU_QM_SIGNAL')"!][!//
[!VAR "SignalEdgeAsilChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT']) and IcuSignalType='ICU_ASIL_SIGNAL')"!][!//

[!VAR "DutyCycleChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty='ICU_ACTIVE_TIME'])and IcuSignalType='ICU_QM_SIGNAL')"!][!//

[!VAR "DutyCycleAsilChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty='ICU_ACTIVE_TIME'])and IcuSignalType='ICU_ASIL_SIGNAL')"!][!//

[!VAR "TimeElapsedChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty != 'ICU_ACTIVE_TIME'])and IcuSignalType='ICU_QM_SIGNAL')"!][!//

[!VAR "TimeElapsedAsilChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty != 'ICU_ACTIVE_TIME'])and IcuSignalType='ICU_ASIL_SIGNAL')"!][!//

[!VAR "QmGtmChannels" = "num:i(count(IcuChannel/*[IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//

[!VAR "AsilGtmChannels" = "num:i(count(IcuChannel/*[IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//

[!VAR "QmCcu6Channels" = "num:i(count(IcuChannel/*[IcuSignalType='ICU_QM_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//

[!VAR "AsilCcu6Channels" = "num:i(count(IcuChannel/*[IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//

[!VAR "AsilChannels" = "num:i(count(IcuChannel/*[IcuSignalType='ICU_ASIL_SIGNAL']))"!][!//
[!VAR "QmChannels" = "num:i(count(IcuChannel/*[IcuSignalType='ICU_QM_SIGNAL']))"!][!//

[!ELSE!][!//
[!VAR "SigmeasQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT']))"!][!//
[!VAR "SigmeasAsilChannels" = "num:i(0)"!][!//
[!VAR "SignalEdgeQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT']))"!][!//
[!VAR "SignalEdgeAsilChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT']))"!][!//

[!VAR "DutyCycleChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty='ICU_ACTIVE_TIME']))"!][!//

[!VAR "DutyCycleAsilChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty='ICU_ACTIVE_TIME']))"!][!//

[!VAR "TimeElapsedChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty != 'ICU_ACTIVE_TIME']))"!][!//

[!VAR "TimeElapsedAsilChannels" = "num:i(count(IcuChannel/*[IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty != 'ICU_ACTIVE_TIME']))"!][!//

[!VAR "QmGtmChannels" = "num:i(count(IcuChannel/*[contains(node:path(node:ref(./IcuAssignedHwUnit)),"GtmConfiguration") = 'true']))"!][!//

[!VAR "AsilGtmChannels" = "num:i(0)"!][!//

[!VAR "QmCcu6Channels" = "num:i(count(IcuChannel/*[contains(node:path(node:ref(./IcuAssignedHwUnit)),"CcuConfiguration") = 'true']))"!][!//

[!VAR "AsilCcu6Channels" =  "num:i(0)"!][!//

[!VAR "AsilChannels" =  "num:i(0)"!][!//
[!VAR "QmChannels" = "num:i(count(IcuChannel/*))"!][!//
[!ENDIF!][!//


[!IF "$QmGtmChannels > $MaxQmGtmChannels"!]
[!VAR "MaxQmGtmChannels" = "$QmGtmChannels"!][!//
[!ENDIF!][!//

[!IF "$AsilGtmChannels > $MaxAsilGtmChannels"!]
[!VAR "MaxAsilGtmChannels" = "$AsilGtmChannels"!][!//
[!ENDIF!][!//

[!IF "$AsilCcu6Channels > $MaxAsilCcu6Channels"!]
[!VAR "MaxAsilCcu6Channels" = "$AsilCcu6Channels"!][!//
[!ENDIF!][!//

[!IF "$QmCcu6Channels > $MaxQmCcu6Channels"!]
[!VAR "MaxQmCcu6Channels" = "$QmCcu6Channels"!][!//
[!ENDIF!][!//


[!IF "$QmChannels > $MaxQmChannels"!]
[!VAR "MaxQmChannels" = "$QmChannels"!][!//
[!ENDIF!][!//

[!IF "$AsilChannels > $MaxAsilChannels"!]
[!VAR "MaxAsilChannels" = "$AsilChannels"!][!//
[!ENDIF!][!//

[!// check for the maximum of Asil based channels
[!IF "$TimestampAsilChannels > $MaxTimestampAsilChannels"!]
[!VAR "MaxTimestampAsilChannels" = "$TimestampAsilChannels"!][!//
[!ENDIF!][!//
[!IF "$EdgecountAsilChannels > $MaxEdgecountAsilChannels"!]
[!VAR "MaxEdgecountAsilChannels" = "$EdgecountAsilChannels"!][!//
[!ENDIF!][!//

[!IF "$EdgeDetectionAsilGtmChannels > $MaxEdgeDetectionAsilGtmChannels"!]
[!VAR "MaxEdgeDetectionAsilGtmChannels" = "$EdgeDetectionAsilGtmChannels"!][!//
[!ENDIF!][!//
[!IF "$EdgeDetectionQmGtmChannels > $MaxEdgeDetectionQmGtmChannels"!]
[!VAR "MaxEdgeDetectionQmGtmChannels" = "$EdgeDetectionQmGtmChannels"!][!//
[!ENDIF!][!//


[!IF "$EdgeDetectionAsilCcu6Channels > $MaxEdgeDetectionAsilCcu6Channels"!]
[!VAR "MaxEdgeDetectionAsilCcu6Channels" = "$EdgeDetectionAsilCcu6Channels"!][!//
[!ENDIF!][!//
[!IF "$EdgeDetectionQmCcu6Channels > $MaxEdgeDetectionQmCcu6Channels"!]
[!VAR "MaxEdgeDetectionQmCcu6Channels" = "$EdgeDetectionQmCcu6Channels"!][!//
[!ENDIF!][!//

[!IF "$EdgeDetectionQmEruChannels > $MaxEdgeDetectionQmEruChannels"!]
[!VAR "MaxEdgeDetectionQmEruChannels" = "$EdgeDetectionQmEruChannels"!][!//
[!ENDIF!][!//

[!IF "$SigMeasurementQmGtmChannels > $MaxSigMeasurementQmGtmChannels"!]
[!VAR "MaxSigMeasurementQmGtmChannels" = "$SigMeasurementQmGtmChannels"!][!//
[!ENDIF!][!//

[!IF "$SigMeasurementAsilGtmChannels > $MaxSigMeasurementAsilGtmChannels"!]
[!VAR "MaxSigMeasurementAsilGtmChannels" = "$SigMeasurementAsilGtmChannels"!][!//
[!ENDIF!][!//
[!IF "$SigMeasurementQmCcu6Channels > $MaxSigMeasurementQmCcu6Channels"!]
[!VAR "MaxSigMeasurementQmCcu6Channels" = "$SigMeasurementQmCcu6Channels"!][!//
[!ENDIF!][!//

[!IF "$SigMeasurementAsilCcu6Channels > $MaxSigMeasurementAsilCcu6Channels"!]
[!VAR "MaxSigMeasurementAsilCcu6Channels" = "$SigMeasurementAsilCcu6Channels"!][!//
[!ENDIF!][!//

[!// check for the maximum of QM based channels
[!IF "$TimestampQmChannels > $MaxTimestampQmChannels"!]
[!VAR "MaxTimestampQmChannels" = "$TimestampQmChannels"!][!//
[!ENDIF!][!//
[!IF "$EdgecountQmChannels > $MaxEdgecountQmChannels"!]
[!VAR "MaxEdgecountQmChannels" = "$EdgecountQmChannels"!][!//
[!ENDIF!][!//

[!IF "$SigmeasQmChannels > $MaxSigmeasQmChannels"!]
[!VAR "MaxSigmeasQmChannels" = "$SigmeasQmChannels"!][!//
[!ENDIF!][!//

[!IF "$SignalEdgeQmChannels > $MaxSignalEdgeChannels"!]
[!VAR "MaxSignalEdgeChannels" = "$SignalEdgeQmChannels"!][!//
[!ENDIF!][!//
[!IF "$SignalEdgeAsilChannels > $MaxSignalEdgeAsilChannels"!]
[!VAR "MaxSignalEdgeAsilChannels" = "$SignalEdgeAsilChannels"!][!//
[!ENDIF!][!//

[!IF "$DutyCycleChannels > $MaxDutyCycleChannels"!]
[!VAR "MaxDutyCycleChannels" = "$DutyCycleChannels"!][!//
[!ENDIF!][!//
[!IF "$TimeElapsedChannels > $MaxTimeElapsedChannels"!]
[!VAR "MaxTimeElapsedChannels" = "$TimeElapsedChannels"!][!//
[!ENDIF!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!VAR "NumberofChannels" = "num:i(count(IcuConfigSet/*[num:i($ModuleId)]/IcuChannel/*))"!][!//
[!IF "$NumberofChannels > $MaxChannelCount"!]
[!VAR "MaxChannelCount" = "$NumberofChannels"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
/********************************************************************
LIST OF ALL CONFIGURED ASIL CHANNELS :Since Safety feature is enabled 
*********************************************************************/
#define ICU_MAX_EDGE_DETECT_ASIL_GTM_CHANNELS  ([!"$MaxEdgeDetectionAsilGtmChannels"!]U)
#define ICU_MAX_EDGE_DETECT_ASIL_CCU6_CHANNELS  ([!"$MaxEdgeDetectionAsilCcu6Channels"!]U)
 
#define ICU_MAX_SIGNAL_MEASURE_ASIL_GTM_CHANNELS  ([!"$MaxSigMeasurementAsilGtmChannels"!]U)
#define ICU_MAX_SIGNAL_MEASURE_ASIL_CCU6_CHANNELS  ([!"$MaxSigMeasurementAsilCcu6Channels"!]U)

#define ICU_MAX_EDGE_COUNT_ASIL_CHANNELS ([!"$MaxEdgecountAsilChannels"!]U)

#define ICU_MAX_TIMESTAMP_ASIL_CHANNELS ([!"$MaxTimestampAsilChannels"!]U)

#define ICU_MAX_ASIL_GTM_CHANNELS      ([!"num:i($MaxAsilGtmChannels)"!]U)   
                                                               
#define ICU_MAX_ASIL_CCU6_CHANNELS          ([!"num:i($MaxAsilCcu6Channels)"!]U)   
                         
#define ICU_MAX_ASIL_CHANNELS        ([!"num:i($MaxAsilChannels)"!]U)   
[!ENDIF!][!// 


/********************************************************************
LIST OF ALL CONFIGURED QM CHANNELS  
*********************************************************************/
#define ICU_MAX_EDGE_DETECT_QM_GTM_CHANNELS  ([!"$MaxEdgeDetectionQmGtmChannels"!]U)
#define ICU_MAX_EDGE_DETECT_QM_CCU6_CHANNELS  ([!"$MaxEdgeDetectionQmCcu6Channels"!]U)
#define ICU_MAX_EDGE_DETECT_QM_ERU_CHANNELS  ([!"$MaxEdgeDetectionQmEruChannels"!]U)
 
#define ICU_MAX_SIGNAL_MEASURE_QM_GTM_CHANNELS  ([!"$MaxSigMeasurementQmGtmChannels"!]U)
#define ICU_MAX_SIGNAL_MEASURE_QM_CCU6_CHANNELS  ([!"$MaxSigMeasurementQmCcu6Channels"!]U)

#define ICU_MAX_SIGNAL_MEASURE_QM_CHANNELS   ([!"num:i($MaxSigmeasQmChannels)"!]U)   

#define ICU_MAX_EDGE_COUNT_QM_CHANNELS ([!"$MaxEdgecountQmChannels"!]U)
#define ICU_MAX_TIMESTAMP_QM_CHANNELS ([!"$MaxTimestampQmChannels"!]U)
            
#define ICU_MAX_QM_GTM_CHANNELS   ([!"num:i($MaxQmGtmChannels)"!]U)
 
#define ICU_MAX_QM_CCU6_CHANNELS          ([!"num:i($MaxQmCcu6Channels)"!]U)

#define ICU_MAX_QM_ERU_CHANNELS          ([!"num:i($MaxEdgeDetectionQmEruChannels)"!]U)
    
#define ICU_MAX_QM_CHANNELS          ([!"num:i($MaxQmChannels)"!]U)

[!IF "IcuSafety/IcuSafetyEnable = 'false'"!][!//
#define ICU_MAX_ASIL_GTM_CHANNELS      (0U)   
                      
#define ICU_MAX_ASIL_CCU6_CHANNELS     (0U)   
[!ENDIF!][!// 

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
/***************************************************************************
TOTAL NUMBER OF CONFIGURED CHANNELS  : ASIL + QM
****************************************************************************/
#define ICU_MAX_CHANNELS  ([!"num:i($MaxChannelCount)"!]U)
[!ELSE!][!//
/***************************************************************************
TOTAL NUMBER OF CONFIGURED CHANNELS  : All channels are QM as safety is OFF
****************************************************************************/
#define ICU_MAX_CHANNELS    ([!"num:i($MaxChannelCount)"!]U)

[!ENDIF!][!// 
[!NOCODE!][!//
[!VAR "EcumWakeupUsed" = "'STD_OFF'"!][!//
[!IF "num:i(count(IcuConfigSet/*/IcuChannel/*[IcuWakeupCapability='true'])) > 0"!][!// 
[!LOOP "IcuConfigSet/*"!][!//
[!LOOP "IcuChannel/*"!][!//
[!VAR "Wakeup" = "'false'"!][!//
[!IF "node:exists(./IcuWakeupCapability) ='true'"!][!// 
[!VAR "Wakeup" = "./IcuWakeupCapability"!][!//
[!ENDIF!][!//
[!VAR "MeasMode" = "./IcuMeasurementMode"!][!//
[!VAR "Wakeupreference" = "''"!][!//
[!// Wakeup capability is true and Signal Measurment is Signal Edge Detection
[!IF "$Wakeup = 'true'"!][!//
[!IF "$MeasMode = 'ICU_MODE_SIGNAL_EDGE_DETECT'"!][!//
[!IF "node:exists(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]) = 'true'"!][!// 
[!IF "string-length(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]) > 0"!][!//
[!VAR "Wakeupreference" = "node:name(node:ref(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!// Ecum wakeup cannot be null.
[!//Wakeup will be configured only if Report Wakeup is enabled
[!IF "node:value(../../../../IcuGeneral/IcuReportWakeupSource) = 'true'"!][!//
[!ASSERT "not(string-length($Wakeupreference) = 0)" ,"Wrong Configuration: Wakeup reference not provided for a wakeup capable channel"!]
[!ENDIF!][!// 
[!IF "string-length($Wakeupreference) > 0"!][!//
[!// Ecum is used.
[!VAR "EcumWakeupUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDIF!][!// end of if wakeup capable channels greater than 0
[!ENDNOCODE!][!//
/*
Configuration: ICU_ECUM_WAKEUP_USED (Vendor Specific)
Indication of using wakeup concept to higher layer 
- if STD_ON, atleast one wakeup capable channel is
         configured to call Ecum layer.
- if STD_OFF, Ecum wakeup is not used.
*/
#define ICU_ECUM_WAKEUP_USED                        ([!"$EcumWakeupUsed"!])
[!NOCODE!]
[!VAR "EdgeCntMode" = "'0'"!][!//
[!VAR "SigMeasMode" = "'0'"!][!//
[!VAR "TimstmpMode" = "'0'"!][!//
[!VAR "SigEdgeMode" = "'0'"!][!//
[!VAR "EruSigEdge"  = "'STD_OFF'"!][!//
[!VAR "EruSigMeas"  = "'STD_OFF'"!][!//
[!VAR "EruEdgeCnt"  = "'STD_OFF'"!][!//
[!VAR "EruTimStmp"  = "'STD_OFF'"!][!//
[!VAR "TimSigEdge"  = "'STD_OFF'"!][!//
[!VAR "TimSigMeas"  = "'STD_OFF'"!][!//
[!VAR "TimEdgeCnt"  = "'STD_OFF'"!][!//
[!VAR "TimTimStmp"  = "'STD_OFF'"!][!//
[!VAR "WrongEdge"    = "'STD_OFF'"!][!//
[!VAR "Eru0Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru1Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru2Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru3Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru4Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru5Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru6Defined" =  "'STD_OFF'"!][!//
[!VAR "Eru7Defined" =  "'STD_OFF'"!][!//
[!VAR "CcuSigEdge"  = "'STD_OFF'"!][!//
[!VAR "CcuSigMeas"  = "'STD_OFF'"!][!//
[!VAR "CcuEdgeCnt"  = "'STD_OFF'"!][!//
[!VAR "CcuTimStmp"  = "'STD_OFF'"!][!//
[!ENDNOCODE!]

[!//[!FOR "ModuleId" = "num:i(1)" TO "num:i($TotalIcuConfig)"!][!//  
[!//[!SELECT "as:modconf('Icu')[position()=$ModuleId]"!][!//
[!LOOP "IcuConfigSet/*"!][!//
[!LOOP "IcuChannel/*"!][!//
[!NOCODE!][!//
[!VAR "MeasMode" = "./IcuMeasurementMode"!][!//
[!IF "$MeasMode = 'ICU_MODE_EDGE_COUNTER'"!][!//
[!VAR "EdgeCntMode" = "'1'"!][!//
[!ELSEIF "$MeasMode = 'ICU_MODE_SIGNAL_MEASUREMENT'"!][!//
[!VAR "SigMeasMode" = "'1'"!][!//
[!ELSEIF "$MeasMode = 'ICU_MODE_TIMESTAMP'"!][!//
[!VAR "TimstmpMode" = "'1'"!][!//
[!ELSE!][!//
[!VAR "SigEdgeMode" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$MeasMode = 'ICU_MODE_SIGNAL_MEASUREMENT'"!][!//
[!VAR "MeasKindConfigured" = "./IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty"!][!//
[!VAR "MeasKind" = "'ICU_ACTIVE_TIME'"!][!//
[!IF "$MeasKindConfigured = $MeasKind or $MeasKindConfigured = 'ICU_PERIOD_TIME'"!][!//
[!IF "./IcuDefaultStartEdge = 'ICU_BOTH_EDGES'"!][!//
[!VAR "WrongEdge"    = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDIF!][!// 
[!ENDIF!][!//
[!VAR "Cell" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!//
[!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!//
[!IF "contains($Cell,'ERU') = 'true'"!][!//
    [!IF "$SigEdgeMode = '1'"!][!//
    [!VAR "EruSigEdge" = "'STD_ON'"!][!//
    [!VAR "SigEdgeMode" = "'0'"!][!//
    [!VAR "EruChannelNumber" = "text:split($Cell, 'RU')[position()-1 = 1]"!]
    [!IF "$EruChannelNumber = num:i(0)"!]
    [!VAR "Eru0Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(1)"!]
    [!VAR "Eru1Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(2)"!]
    [!VAR "Eru2Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(3)"!]
    [!VAR "Eru3Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(4)"!]
    [!VAR "Eru4Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(5)"!]
    [!VAR "Eru5Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(6)"!]
    [!VAR "Eru6Defined" = "'STD_ON'"!]
    [!ENDIF!]
    [!IF "$EruChannelNumber = num:i(7)"!]
    [!VAR "Eru7Defined" = "'STD_ON'"!]
    [!ENDIF!]
            
    [!ELSEIF "$EdgeCntMode = '1'"!][!//
    [!VAR "EruEdgeCnt" = "'STD_ON'"!][!//
    [!VAR "EdgeCntMode" = "'0'"!][!//
    [!ELSEIF "$TimstmpMode = '1'"!][!//
    [!VAR "EruTimStmp" = "'STD_ON'"!][!//
    [!VAR "TimstmpMode" = "'0'"!][!//
    [!ELSE!][!//
    [!VAR "EruSigMeas" = "'STD_ON'"!][!//
    [!VAR "SigMeasMode" = "'0'"!][!//
    [!ENDIF!][!// End of if SigEdge for Eru
[!ELSEIF "contains($Cell,'Tim') = 'true'"!][!//
    [!IF "$SigEdgeMode = '1'"!][!//
    [!VAR "TimSigEdge" = "'STD_ON'"!][!//
    [!VAR "SigEdgeMode" = "'0'"!][!//
    [!ELSEIF "$EdgeCntMode = '1'"!][!//
    [!VAR "TimEdgeCnt" = "'STD_ON'"!][!//
    [!VAR "EdgeCntMode" = "'0'"!][!//
    [!ELSEIF "$TimstmpMode = '1'"!][!//
    [!VAR "TimTimStmp" = "'STD_ON'"!][!//
    [!VAR "TimstmpMode" = "'0'"!][!//
    [!ELSE!][!//
    [!VAR "TimSigMeas" = "'STD_ON'"!][!// 
    [!VAR "SigMeasMode" = "'0'"!][!//
    [!ENDIF!][!// End of if SigEdge for Tim
[!ELSEIF "contains($Cell,'Cc6') = 'true'"!][!//
    [!IF "$SigEdgeMode = '1'"!][!//
    [!VAR "CcuSigEdge" = "'STD_ON'"!][!//
    [!VAR "SigEdgeMode" = "'0'"!][!//
    [!ELSEIF "$EdgeCntMode = '1'"!][!//
    [!VAR "CcuEdgeCnt" = "'STD_ON'"!][!//
    [!VAR "EdgeCntMode" = "'0'"!][!//
    [!ELSEIF "$TimstmpMode = '1'"!][!//
    [!VAR "CcuTimStmp" = "'STD_ON'"!][!//
    [!VAR "TimstmpMode" = "'0'"!][!//
    [!ELSE!][!//
    [!VAR "CcuSigMeas" = "'STD_ON'"!][!//
    [!VAR "SigMeasMode" = "'0'"!][!//
    [!ENDIF!][!// End of if SigEdge for Tim    
[!ENDIF!][!// if contains cell
[!//
[!ENDNOCODE!][!//

#ifndef IcuConf_IcuChannel_[!"node:name(.)"!]
#define IcuConf_IcuChannel_[!"node:name(.)"!]          ((Icu_17_GtmCcu6_ChannelType)[!"IcuChannelId"!])
#endif
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!//[!ENDSELECT!][!//
[!//[!ENDFOR!][!//
[!ASSERT "not($EruTimStmp = 'STD_ON')","Wrong Configuration:ERU Cell cannot be used for Timestamp measurement"!]
[!ASSERT "not($EruSigMeas = 'STD_ON')","Wrong Configuration:ERU Cell cannot be used for Signal measurement"!]
[!ASSERT "not($EruEdgeCnt = 'STD_ON')","Wrong Configuration:ERU Cell cannot be used for Edge Counting"!]
[!ASSERT "not($WrongEdge  = 'STD_ON')","Wrong Configuration:IcuBothEdges cannot be given as Default start edge for measuring Period Time or DutyCycle"!][!//
[!ASSERT "not($CcuEdgeCnt = 'STD_ON')","Wrong Configuration:CCU Cell cannot be used for Edge Counting"!]
[!ASSERT "not($CcuTimStmp = 'STD_ON')","Wrong Configuration:CCU Cell cannot be used for Timestamp measurement"!]
/*
Derived parameters
Vendor specific configuration switches
Format
ICU_RES_MODE_USED
RES : TIM, ERU
MODE: SIGMEAS, SIGEDGE, EDGECNT, TIMSTMP
*/
/*
Configuration:ICU_TIM_SIGMEAS_USED (Vendor Specific)
DCM resource used in Signal measurement:
STD_ON: TIM cells are used in Signal measurement mode.
STD_OFF: TIM cells are not used in Signal measurement mode.
*/
[!NOCODE!][!//
[!IF "$MaxEdgeDetectionAsilGtmChannels > 0"!]
[!VAR "TimSigEdgeAsil" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigEdgeAsil" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxEdgeDetectionQmGtmChannels > 0"!]
[!VAR "TimSigEdgeQm" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigEdgeQm" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxSigMeasurementAsilGtmChannels > 0"!]
[!VAR "TimSigMeasAsil" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigMeasAsil" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxSigMeasurementQmGtmChannels > 0"!]
[!VAR "TimSigMeasQm" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigMeasQm" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxEdgecountAsilChannels > 0"!]
[!VAR "TimEdgeCountAsil" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimEdgeCountAsil" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxEdgecountQmChannels > 0"!]
[!VAR "TimEdgeCountQm" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimEdgeCountQm" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxTimestampAsilChannels > 0"!]
[!VAR "TimStampAsil" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimStampAsil" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxTimestampQmChannels > 0"!]
[!VAR "TimStampQm" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimStampQm" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxSigMeasurementAsilCcu6Channels > 0"!]
[!VAR "TimSigMeasAsil_ccu6" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigMeasAsil_ccu6" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxSigMeasurementQmCcu6Channels > 0"!]
[!VAR "TimSigMeasQm_ccu6" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigMeasQm_ccu6" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxEdgeDetectionAsilCcu6Channels > 0"!]
[!VAR "TimSigEdgeAsil_ccu6" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigEdgeAsil_ccu6" = "'STD_OFF'"!][!//
[!ENDIF!][!//

[!IF "$MaxEdgeDetectionQmCcu6Channels > 0"!]
[!VAR "TimSigEdgeQm_ccu6" = "'STD_ON'"!][!//
[!ELSE!][!//  
[!VAR "TimSigEdgeQm_ccu6" = "'STD_OFF'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!// 

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_ASIL_TIM_SIGMEAS_USED     ([!"$TimSigMeasAsil"!])
[!ELSE!][!//
#define ICU_ASIL_TIM_SIGMEAS_USED     (STD_OFF)
[!ENDIF!][!//
#define ICU_QM_TIM_SIGMEAS_USED     ([!"$TimSigMeasQm"!])
#if (ICU_ASIL_TIM_SIGMEAS_USED == STD_ON) || (ICU_QM_TIM_SIGMEAS_USED == STD_ON)
#define ICU_TIM_SIGMEAS_USED    (STD_ON)
#else
#define ICU_TIM_SIGMEAS_USED    (STD_OFF)
#endif

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_ASIL_TIM_SIGEDGE_USED     ([!"$TimSigEdgeAsil"!]) 
[!ELSE!][!//
#define ICU_ASIL_TIM_SIGEDGE_USED     (STD_OFF) 
[!ENDIF!][!//
#define ICU_QM_TIM_SIGEDGE_USED     ([!"$TimSigEdgeQm"!])
#if (ICU_ASIL_TIM_SIGEDGE_USED == STD_ON) || (ICU_QM_TIM_SIGEDGE_USED == STD_ON)
#define ICU_TIM_SIGEDGE_USED     (STD_ON)
#else
#define ICU_TIM_SIGEDGE_USED    (STD_OFF)
#endif

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_ASIL_TIM_EDGECNT_USED     ([!"$TimEdgeCountAsil"!])  
[!ELSE!][!//
#define ICU_ASIL_TIM_EDGECNT_USED     (STD_OFF)  
[!ENDIF!][!//
#define ICU_QM_TIM_EDGECNT_USED     ([!"$TimEdgeCountQm"!])   
#if (ICU_ASIL_TIM_EDGECNT_USED == STD_ON) || (ICU_QM_TIM_EDGECNT_USED == STD_ON)
#define ICU_TIM_EDGECNT_USED     (STD_ON) 
#else
#define ICU_TIM_EDGECNT_USED     (STD_OFF) 
#endif

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_ASIL_TIM_TIMESTAMP_USED     ([!"$TimStampAsil"!])
[!ELSE!][!//
#define ICU_ASIL_TIM_TIMESTAMP_USED     (STD_OFF)
[!ENDIF!][!//
#define ICU_QM_TIM_TIMESTAMP_USED    ([!"$TimStampQm"!])
#if (ICU_ASIL_TIM_TIMESTAMP_USED == STD_ON) || (ICU_QM_TIM_TIMESTAMP_USED == STD_ON)
#define ICU_TIM_TIMSTMP_USED     (STD_ON)
#else
#define ICU_TIM_TIMSTMP_USED     (STD_OFF)
#endif
 
[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_ASIL_CCU6_SIGMEAS_USED     ([!"$TimSigMeasAsil_ccu6"!])
[!ELSE!][!//
#define ICU_ASIL_CCU6_SIGMEAS_USED     (STD_OFF)
[!ENDIF!][!//
#define ICU_QM_CCU6_SIGMEAS_USED     ([!"$TimSigMeasQm_ccu6"!])
#if (ICU_ASIL_CCU6_SIGMEAS_USED == STD_ON) || (ICU_QM_CCU6_SIGMEAS_USED == STD_ON)
#define ICU_CCU6_SIGMEAS_USED     (STD_ON)
#else
#define ICU_CCU6_SIGMEAS_USED     (STD_OFF)
#endif

[!IF "IcuSafety/IcuSafetyEnable = 'true'"!][!//
#define ICU_ASIL_CCU6_SIGEDGE_USED     ([!"$TimSigEdgeAsil_ccu6"!])
[!ELSE!][!//
#define ICU_ASIL_CCU6_SIGEDGE_USED     (STD_OFF)
[!ENDIF!][!//
#define ICU_QM_CCU6_SIGEDGE_USED     ([!"$TimSigEdgeQm_ccu6"!])
#if (ICU_ASIL_CCU6_SIGEDGE_USED == STD_ON) || (ICU_QM_CCU6_SIGEDGE_USED == STD_ON)
#define ICU_CCU6_SIGEDGE_USED     (STD_ON)
#else
#define ICU_CCU6_SIGEDGE_USED     (STD_OFF)
#endif


/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU resource used in Signal edge detection or not.
STD_ON: ERUs are used in Signal edge detection mode.
STD_OFF: ERUs are not used in Signal edge detection mode.
*/
#define ICU_ERU_SIGEDGE_USED     ([!"$EruSigEdge"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU0 resource used in Signal edge detection or not.
STD_ON: ERU0 is used in Signal edge detection mode.
STD_OFF: ERU0 is not used in Signal edge detection mode.
*/
#define ICU_ERU0_USED ([!"$Eru0Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU1 resource used in Signal edge detection or not.
STD_ON: ERU1 is used in Signal edge detection mode.
STD_OFF: ERU1 is not used in Signal edge detection mode.
*/
#define ICU_ERU1_USED ([!"$Eru1Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU2 resource used in Signal edge detection or not.
STD_ON: ERU2 is used in Signal edge detection mode.
STD_OFF: ERU2 is not used in Signal edge detection mode.
*/
#define ICU_ERU2_USED ([!"$Eru2Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU3 resource used in Signal edge detection or not.
STD_ON: ERU3 is used in Signal edge detection mode.
STD_OFF: ERU3 is not used in Signal edge detection mode.
*/
#define ICU_ERU3_USED ([!"$Eru3Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU4 resource used in Signal edge detection or not.
STD_ON: ERU4 is used in Signal edge detection mode.
STD_OFF: ERU4 is not used in Signal edge detection mode.
*/
#define ICU_ERU4_USED ([!"$Eru4Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU5 resource used in Signal edge detection or not.
STD_ON: ERU5 is used in Signal edge detection mode.
STD_OFF: ERU5 is not used in Signal edge detection mode.
*/
#define ICU_ERU5_USED ([!"$Eru5Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU6 resource used in Signal edge detection or not.
STD_ON: ERU6 is used in Signal edge detection mode.
STD_OFF: ERU6 is not used in Signal edge detection mode.
*/
#define ICU_ERU6_USED ([!"$Eru6Defined"!])
/*
Configuration:ICU_ERU_SIGEDGE_USED (Vendor Specific)
Indicates whether ERU7 resource used in Signal edge detection or not.
STD_ON: ERU7 is used in Signal edge detection mode.
STD_OFF: ERU7 is not used in Signal edge detection mode.
*/
#define ICU_ERU7_USED ([!"$Eru7Defined"!])

[!ENDSELECT!][!//

/*******************************************************************************
**                      Global constant declarations                          **
*******************************************************************************/


#endif  /* ICU_17_GTMCCU6_CFG_H */


