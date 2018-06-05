[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Sent_Cfg.h $                                               **
**                                                                           **
**  $CC VERSION : \main\15 $                                                 **
**                                                                           **
**  $DATE       : 2016-02-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Sent_Cfg.h file                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/* [cover parentID=DS_NAS_SENT_PR1693_2_0,
DS_NAS_SENT_PR1693_2_1,DS_NAS_SENT_PR1693_2_2,DS_NAS_SENT_PR1693_2_3,
DS_NAS_SENT_PR1693_2_4,DS_NAS_SENT_PR1693_2_5,DS_NAS_SENT_PR1693_2_6]
[/cover]                                                                */!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Sent_Cfg.h                                                    **
**                                                                            **
**  $CC VERSION : \main\15 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SENT configuration generated out of ECU configuration      **
**                 file (Sent.bmd)                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SENT_CFG_H
#define SENT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* SENT Type definitions */
#include "Sent_Types.h"
[!NOCODE!]
[!INCLUDE "Sent.m"!][!//
[!/* For loadable build PBfixedAddress should be False */!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$PostBuildType = 'LOADABLE'"!][!//
[!ASSERT "not(SentGeneral/SentPBFixedAddress = 'true')"!][!//
For EcuMPostBuildConfigType = Loadable, SentPBFixedAddress should be False[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define SENT_SW_MAJOR_VERSION              ([!"$SwMajorVersion"!]U)
#define SENT_SW_MINOR_VERSION              ([!"$SwMinorVersion"!]U)
#define SENT_SW_PATCH_VERSION              ([!"$SwPatchVersion"!]U)

[!SELECT "as:modconf('Sent')[1]"!][!//

/*
                     Container : SentDriverGeneralConfiguration
*/
/*
  The following macros will enable or disable a particular feature 
  in SENT module.
  Set the macro to ON to enable the feature and OFF to disable the same.
*/
/*
Configuration: SENT_DEV_ERROR_DETECT
Preprocessor switch for enabling the development error detection and 
reporting. 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define SENT_DEV_ERROR_DETECT  [!//
[!CALL "CG_ConfigSwitch","MacInputVal" = "SentGeneral/SentDevErrorDetect"!][!//

/* Configuration: SENT_DEINIT_API
Sent_DeInit API configuration 
- if STD_ON, DeInit API is Enabled 
- if STD_OFF, DeInit API is Disabled 
*/
#define SENT_DEINIT_API        [!//
[!CALL "CG_ConfigSwitch","MacInputVal" = "SentGeneral/SentDeInitApi"!][!//

/* Configuration: SENT_VERSION_INFO_API
Version Information API configuration 
- if STD_ON, VersionInfo API is Enabled 
- if STD_OFF, VersionInfo API is Disabled 
*/
#define SENT_VERSION_INFO_API  [!//
[!CALL "CG_ConfigSwitch","MacInputVal" = "SentGeneral/SentVersionInfoApi"!][!//

/* Configuration: SENT_SPC_USED
SENT SPC Feature configuration 
- if STD_ON, SPC feature is Enabled 
- if STD_OFF, SPC feature is Disabled 
*/
#define SENT_SPC_USED         [!//
[!CALL "CG_ConfigSwitch","MacInputVal" = "SentGeneral/SentSpcFeatureSupport"!][!//

[!NOCODE!][!//
[!//
[!VAR "TotalSentConfig" = "num:i(count(SentConfigSet/*))"!][!//
[!/* Determine only one SentConfigSet is configured 
                                            when SentPBFixedAddress = true.*/!]
[!IF "SentGeneral/SentPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalSentConfig != 1)"!][!//
Config Error: when SentGeneral/SentPBFixedAddress is set as true, [!//
Only one SentConfigSet configuration is allowed. [!//
But SentConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* Configuration: SENT_PB_FIXED_ADDRESS (Vendor specific)
Fixed address confiuration as per HIS recommendatons
- if STD_ON, ConfigRoot[0] is used by default as the fixed configuration
- if STD_OFF, Dynamic usage of the selected configurations according to AUTOSAR 
*/
#define SENT_PB_FIXED_ADDRESS [!//
[!CALL "CG_ConfigSwitch","MacInputVal" = "SentGeneral/SentPBFixedAddress"!]

/* Configuration: SENT_RESET_SFR_AT_INIT 
SENT Enable/Disable Reset of SFR's during Init 
- if STD_ON, Enables Reset of SFR's during Init 
- if STD_OFF, Disables Reset of SFR's during Init 
*/
#define SENT_RESET_SFR_AT_INIT [!//
[!CALL "CG_ConfigSwitch","MacInputVal" = "SentGeneral/SentResetSfrAtInit"!]

/* Configuration: SENT_ACCEN_MODE
SENT_ACCEN_DEFAULT - No ACCEN register access; default HW value
SENT_ACCEN_INIT - ACCEN register access only at initialization
SENT_ACCEN_API - ACCEN register access only through API  
*/
#define SENT_ACCEN_MODE       ([!"SentGeneral/SentAccessEnable"!])

/* Configuration: SENT_HW_MAX_CHANNELS
Maximum number of SENT physical channels supported
*/
#define SENT_HW_MAX_CHANNELS   ([!"ecu:get('Sent.MaxChannelsSupported')"!]U)

/* Configuration: SENT MODULE INSTANCE ID */
#define SENT_INSTANCE_ID       ((uint8)[!"SentGeneral/SentIndex"!])

/* Total no. of config sets */
#define SENT_CONFIG_COUNT    ([!"num:i(count(SentConfigSet/*))"!]U)

[!IF "(SentGeneral/SentRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "SentGeneral/SentUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "SentGeneral/SentUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "SentGeneral/SentUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: SentRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
SentUserModeRuntimeApiEnable, SentUserModeInitApiEnable or SentUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: SENT_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "SentGeneral/SentRunningInUser0Mode = 'true'"!][!//
#define SENT_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define SENT_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: SENT_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "SentGeneral/SentUserModeInitApiEnable = 'true'"!][!//
#define SENT_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  SENT_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: SENT_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "SentGeneral/SentUserModeDeInitApiEnable = 'true'"!][!//
#define SENT_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  SENT_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: SENT_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "SentGeneral/SentUserModeRuntimeApiEnable = 'true'"!][!//
#define SENT_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  SENT_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
[!VAR "TotalConfig" = "num:i(count(SentConfigSet/*))"!][!//
[!FOR "SentId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SentConfigSet/*[num:i($SentId)]"!][!//
[!NOCODE!][!//
[!VAR "MaxSentChannels" = "num:i(0)"!][!//
[!VAR "MaxSentChannels" = "num:i(count(SentChannelConfigSet/*))"!][!//
[!ENDNOCODE!][!//

/*IFX_MISRA_RULE_08_07_STATUS=SentNotifFnPtrArray variable 
is used across multiple files it is defined in generated Sent_LCfg.c file and   
accessed in Sent.c,hence it cannot be declared as a local variable*/
extern const Sent_NotifFnPtrType SentNotifFnPtrArray[[!"num:i($MaxSentChannels)"!]];

/* ConfigSet [!"num:i($SentId - 1)"!] */
[!FOR "Channel" = "0" TO "num:i($MaxSentChannels)"!][!//
[!SELECT "SentChannelConfigSet/*[num:i($Channel)]"!][!//
/* Application callout function for SENT Channel[!"SentChanIndex"!] */
extern void [!"SentChanCalloutFn"!] (Sent_ChannelIdxType ChannelId, 
                                                Sent_NotifType Stat);
[!ENDSELECT!][!//
[!ENDFOR!][!//  
[!ENDSELECT!][!//
[!ENDFOR!][!//  
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /* SENT_CFG_H */
[!AUTOSPACING!]
