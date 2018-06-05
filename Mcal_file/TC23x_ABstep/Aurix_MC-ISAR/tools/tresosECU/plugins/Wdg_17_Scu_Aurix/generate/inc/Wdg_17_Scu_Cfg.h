[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Wdg_17_Scu_Cfg.h $                                         **
**                                                                           **
**  $CC VERSION : \main\43 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-11 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Wdg_17_Scu_Cfg.h file                   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=SAS_NAS_WDG_PR913,SAS_NAS_WDG_PR483
                       ,DS_AS4XX_WDG_PR2849,SAS_NAS_WDG_PR914,SAS_NAS_WDG_PR915,
         SAS_NAS_WDG_PR916,SAS_AS4XX_WDG_PR678, DS_NAS_WDG_PR919,
         SAS_NAS_WDG_PR64,SAS_NAS_WDG_PR82,DS_NAS_HE2_WDG_PR3054_1,
    DS_NAS_EP_WDG_PR3054_1,DS_NAS_HE2_WDG_PR3054_2,DS_NAS_EP_WDG_PR3054_2,
    DS_NAS_HE2_WDG_PR3054_3,DS_NAS_EP_WDG_PR3054_3]
    [/cover]                                                            */!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Wdg_17_Scu_Cfg.h                                              **
**                                                                            **
**  $CC VERSION : \main\43 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : WDG configuration generated out of ECU configuration       **
**                 file  (Wdg_17_Scu.bmd )  4.0.3                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/******************************************************************************/
#ifndef WDG_17_SCU_CFG_H
#define WDG_17_SCU_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]
#define WDG_17_SCU_AS_VERSION ([!"$NewString"!])

/* AUTOSAR specification version numbers */
[!IF "$MajorVersion = num:i(4)"!][!//
#define WDG_17_SCU_AR_RELEASE_MAJOR_VERSION     ([!"$MajorVersion"!]U)
#define WDG_17_SCU_AR_RELEASE_MINOR_VERSION     ([!"$MinorVersion"!]U)
#define WDG_17_SCU_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
#define WDG_17_SCU_MAJOR_VERSION           (WDG_17_SCU_AR_RELEASE_MAJOR_VERSION)
[!ENDIF!][!//

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define WDG_17_SCU_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define WDG_17_SCU_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define WDG_17_SCU_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)

/*
Configuration: WDG_DEV_ERROR_DETECT  WDG069: WDG045: WDG064:
- if ON, DET is Enabled
- if OFF,DET is Disabled
WDG069: Compile switch to enable/disable development error detection
for this module.
- ON if WdgDevErrorDetect is true
*/
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Wdg')[1]"!][!//
[!VAR "Wdg_MaxTimers" = "ecu:get('Wdg.MaxTimers')"!][!//
#define WDG_DEV_ERROR_DETECT      ([!//
[!IF "WdgGeneral/WdgDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* 
This parameter is defined by IFX.
UTP : AI00253342 
*/
#define WDG_UNLOCK_RESTRICTION    ([!//
[!IF "WdgGeneral/WdgUnlockRestriction = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: WDG_DISABLE_ALLOWED WDG070:
WDG070: Compile switch to allow/forbid disabling the watchdog
driver during runtime.
- ON if WdgDisableAllowed is true
*/
#define WDG_DISABLE_ALLOWED       ([!//
[!IF "WdgGeneral/WdgDisableAllowed = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: WDG_VERSION_INFO_API WDG081:
WDG081:Compile switch to enable/disable the version information API
- ON if WdgVersionInfoApi is true
*/
#define WDG_VERSION_INFO_API      ([!//
[!IF "WdgGeneral/WdgVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!IF "(WdgGeneral/WdgRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "WdgGeneral/WdgUserModeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "WdgGeneral/WdgUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: WdgRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
WdgUserModeRuntimeApiEnable or WdgUserModeInitApiEnable
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: WDG_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "WdgGeneral/WdgRunningInUser0Mode = 'true'"!][!//
#define WDG_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define WDG_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: WDG_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "WdgGeneral/WdgUserModeInitApiEnable = 'true'"!][!//
#define WDG_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  WDG_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//


/*Configuration: WDG_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init APIs
- if STD_OFF, Disable Protected mode in APIs other than Init APIs
*/
[!IF "WdgGeneral/WdgUserModeRuntimeApiEnable = 'true'"!][!//
#define WDG_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  WDG_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
The Max timeout entered by the user is converted to milliseconds
This is used in STC to check for limits.
*/
#define WDG_MAX_TIMEOUT           ([!"num:i((WdgGeneral/WdgMaxTimeout)*(1000))"!]U)

/*
The Initial timeout entered by the user is converted to milliseconds
This is used in Wdg_17_Init to set the STC window post Wdg_17_Init()
*/
#define WDG_INITIAL_TIMEOUT       ((uint16)[!"num:i((WdgGeneral/WdgInitialTimeout)*(1000))"!]U)

/* WDG_MAX_TIMERS : holds maximum number of WDG timers  */
#define WDG_MAX_TIMERS            ([!"ecu:get('Wdg.MaxTimers')"!]U) 

[!NOCODE!][!//
[!VAR "WDGSAFECOUNT" = "num:i(0)"!][!//
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!][!//
[!VAR "WDGSAFECOUNT" = "($WDGSAFECOUNT) + num:i(1)"!][!//
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
[!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
[!VAR "WDGSAFECOUNT" = " ($WDGSAFECOUNT) + num:i(1)"!][!//
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//  
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
[!VAR "WDGSAFECOUNT" = " ($WDGSAFECOUNT) + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/* WDG_MAXSAFE_TIMERS holds maximum number of WDG with safety used */
#define WDG_MAXSAFE_TIMERS        ([!"num:i($WDGSAFECOUNT)"!]U)


/* WDG_MAXQM_TIMERS holds maximum number of WDG without safety used */
#define WDG_MAXQM_TIMERS          ([!"num:i(ecu:get('Wdg.MaxTimers') - $WDGSAFECOUNT)"!]U)

/* WDG0 safety enabled */
/*WDG0_SAFETY_ENABLE: STD_ON - WDG0 enabled with safety
                      STD_OFF- WDG0 enabled without safety  */
#define WDG0_SAFETY_ENABLE        ([!//
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
/*WDG1_SAFETY_ENABLE: STD_ON - WDG1 enabled with safety
                      STD_OFF- WDG1 enabled without safety  */
#define WDG1_SAFETY_ENABLE        ([!//
[!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ENDIF!][!//

[!IF "($Wdg_MaxTimers > num:i(2))"!][!// 
/*WDG2_SAFETY_ENABLE: STD_ON - WDG2 enabled with safety
                      STD_OFF- WDG2 enabled without safety  */
#define WDG2_SAFETY_ENABLE        ([!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ENDIF!][!//

/* WDG_SET_OFF_MODE_API: STD_ON - SetOffMode API enabled
                         STD_OFF- SetOffMode API disabled */
[!IF "($WDGSAFECOUNT > num:i(0))"!][!//
#define WDG_SET_OFF_MODE_API      ([!//
[!IF "WdgSafety/WdgSetOffModeApi  = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ELSE!][!//
#define WDG_SET_OFF_MODE_API      (STD_OFF)
[!ENDIF!][!//

/* WDG_ENABLE_TIME_CHECK: STD_ON - execution time check enabled
                          STD_OFF - execution time check disabled  */
[!IF "($WDGSAFECOUNT > num:i(0))"!][!//
#define WDG_ENABLE_TIME_CHECK     ([!//
[!IF "WdgSafety/WdgEnableTimecheck   = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ELSE!][!//
#define WDG_ENABLE_TIME_CHECK     (STD_OFF)
[!ENDIF!][!//

/*
Configuration: WdgDebugSupport -> WDG_DEBUG_SUPPORT
Switches ON, debug support.
*/
#define WDG_DEBUG_SUPPORT         ([!//
[!IF "WdgGeneral/WdgDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//

[!NOCODE!][!//
[!//
[!VAR "TotalWdgConfig" = "num:i(count(WdgSettingsConfig/*))"!][!//
[!/* Determine only one WdgSettingsConfig is configured 
                                        when WdgPBFixedAddress = true.*/!]
[!IF "WdgGeneral/WdgPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalWdgConfig != 1)"!][!//
Config Error: when WdgGeneral/WdgPBFixedAddress is set as true, [!//
Only one WdgSettingsConfig configuration is allowed. [!//
But WdgSettingsConfig has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//

[!VAR "WdgPBFixAddr" = "'OFF'"!]
[!IF "node:exists(WdgGeneral/WdgPBFixedAddress)"!]
[!IF "WdgGeneral/WdgPBFixedAddress = 'true'"!]
[!VAR "WdgPBFixAddr" = "'STD_ON'"!]
[!ELSE!]
[!VAR "WdgPBFixAddr" = "'STD_OFF'"!]
[!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!]
/* Wdg Fixed Address usage */
#define WDG_PB_FIXEDADDR          ([!"$WdgPBFixAddr"!])

/* DEM related pre-compile switches */
[!IF "(node:exists(WdgDemEventParameterRefs/*[1]) = 'true')"!][!//
[!SELECT "WdgDemEventParameterRefs/*[1]"!][!//
[!IF "(node:exists(./WDG_E_DISABLE_REJECTED/*[1]) = 'true') and (node:value(./WDG_E_DISABLE_REJECTED /*[1]) != ' ' )"!][!//
#define WDG_DISABLE_REJECT_DEM_REPORT   (ENABLE_DEM_REPORT)
 #define WDG_E_DISABLE_REJECTED         (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./WDG_E_DISABLE_REJECTED/*[1])))"!]) 
[!ELSE!][!//
#define WDG_DISABLE_REJECT_DEM_REPORT   (DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!IF "(node:exists(./WDG_E_MODE_FAILED/*[1]) = 'true') and (node:value(./WDG_E_MODE_FAILED/*[1]) != '')"!][!//
#define WDG_MODE_FAIL_DEM_REPORT        (ENABLE_DEM_REPORT)
#define WDG_E_MODE_FAILED               (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./WDG_E_MODE_FAILED/*[1])))"!]) 
[!ELSE!][!//
#define WDG_MODE_FAIL_DEM_REPORT        (DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!IF "(node:exists(./WDG_E_INIT_FAILED/*[1]) = 'true') and (node:value(./WDG_E_INIT_FAILED/*[1]) != '')"!][!//
#define WDG_INIT_FAILED_DEM_REPORT      (ENABLE_DEM_REPORT)
#define WDG_E_INIT_FAILED               (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./WDG_E_INIT_FAILED/*[1])))"!]) 
[!ELSE!][!//
#define WDG_INIT_FAILED_DEM_REPORT      (DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
#define WDG_DISABLE_REJECT_DEM_REPORT   (DISABLE_DEM_REPORT)
#define WDG_MODE_FAIL_DEM_REPORT        (DISABLE_DEM_REPORT)
#define WDG_INIT_FAILED_DEM_REPORT      (DISABLE_DEM_REPORT)
[!ENDIF!]
[!//
[!//

/* MAcro Definition for Timer unit used for servicing of the WDG*/
#define WDG_GTM_ATOM_CHANNEL  0x00U
#define WDG_GTM_TOM_CHANNEL   0x01U
/* Instance ID for WDG_17 module */
#define WDG_17_SCU_INSTANCE_ID   ((uint8)[!"num:i(WdgGeneral/WdgIndex)"!]U)
#define Wdg_17_ScuConf_WdgGeneral_WdgIndex (WDG_17_SCU_INSTANCE_ID)

/* Total no. of config sets */
#define WDG_17_CONFIG_COUNT   ([!"num:i(count(WdgSettingsConfig/*))"!]U)

[!ENDSELECT!][!//
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


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* WDG_17_SCU_CFG_H */

