[!/*****************************************************************************
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
**   $FILENAME   : Adc_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\dev_tc23x_as4.0.3\19 $                               **
**                                                                            **
**   $DATE       : 2016-07-23 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for Adc_Cfg.h file                           **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  TRACEABILITY: [cover parentID=DS_NAS_ADC_PR716,DS_NAS_ADC_PR699,
DS_NAS_ADC_PR700,DS_NAS_ADC_PR701,DS_NAS_ADC_PR704,DS_NAS_ADC_PR707,
DS_NAS_ADC_PR708,DS_NAS_ADC_PR709,DS_NAS_ADC_PR712,DS_NAS_ADC_PR717,
DS_NAS_ADC_PR724,DS_NAS_ADC_PR728,DS_NAS_ADC_PR446,DS_NAS_ADC_PR1785,
DS_AS4XX_ADC_PR2849_1,DS_AS4XX_ADC_PR2849_2,DS_NAS_HE2_ADC_PR3054_1,
DS_NAS_EP_ADC_PR3054_1,DS_NAS_HE2_ADC_PR3054_2,DS_NAS_EP_ADC_PR3054_2,
DS_NAS_HE2_ADC_PR3054_3,DS_NAS_EP_ADC_PR3054_3,DS_NAS_HE2_ADC_PR3054_4,
DS_NAS_EP_ADC_PR3054_4]                                                       **
**                                                                            **
**  Code template for Adc_Cfg.h file                                          **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
*************************************************************************/!][!//
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
**   $FILENAME   : Adc_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\dev_tc23x_as4.0.3\19 $                               **
**                                                                            **
**   DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                            **
**   GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : Adc configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
#ifndef ADC_CFG_H
#define ADC_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
[!NOCODE!]
[!INCLUDE "Adc.m"!][!//
[!ENDNOCODE!]
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
#define ADC_AR_RELEASE_MAJOR_VERSION      ([!"$MajorVersion"!]U)
#define ADC_AR_RELEASE_MINOR_VERSION      ([!"$MinorVersion"!]U)
#define ADC_AR_RELEASE_REVISION_VERSION   ([!"$RevisionVersion"!]U)

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define ADC_SW_MAJOR_VERSION              ([!"$SwMajorVersion"!]U)
#define ADC_SW_MINOR_VERSION              ([!"$SwMinorVersion"!]U)
#define ADC_SW_PATCH_VERSION              ([!"$SwPatchVersion"!]U)

[!SELECT "as:modconf('Adc')[1]"!][!//
/* Maximum resolution possible */
#define ADC_MAX_CHANNEL_RESOLUTION        ((uint8)[!"AdcPublishedInformation/AdcMaxChannelResolution"!])

/* ADC_CHANNEL_VALUESIGNED:  unsigned */
#define ADC_CHANNEL_VALUESIGNED           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcPublishedInformation/AdcChannelValueSigned"!][!//

/*
  Information whether the first channel of an ADC Channel group can be
  configured (FALSE) or is fixed (TRUE) to a value determined by 
  the ADC HW Unit 
*/
#define ADC_GROUP_FIRST_CHANNEL_FIXED     [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcPublishedInformation/AdcGroupFirstChannelFixed"!][!// 

/*
  Macros are defined to enable/disable the usage of debug variables
  Debug variables are added in the code for code coverage
*/
#define IFX_ADC_DEBUG_RESET               (STD_OFF)
#define IFX_ADC_DEBUG_CLC                 (STD_OFF)
#define IFX_ADC_DEBUG_CCU60_CLC           (STD_OFF)
#define IFX_ADC_DEBUG_CCU6_CLC            (STD_OFF)
#define IFX_ADC_DEBUG_CLC_DISABLE         (STD_OFF)

/*Configuration Options: ADC_RESULT_HANDLING_MODE
  Result handling as per AUTOSAR specification or 
  NonAUTOSAR specific DMA handling
*/
#define ADC_AUTOSAR                       (0U)
#define ADC_NON_AUTOSAR                   (1U)

/*
  Configuration Options: ADC_PRIORITY_IMPLEMENTATION
  Options for the Priority Mechanism supported in ADC Driver
*/
#define ADC_PRIORITY_NONE                 (0U)
#define ADC_PRIORITY_HW                   (1U)
#define ADC_PRIORITY_HW_SW                (2U) 

/*
  Configuration Options: ADC_RESULT_ALIGNMENT
  Options for the Alignment of raw results in ADC Driver
*/
#define ADC_ALIGN_LEFT                    (0U)
#define ADC_ALIGN_RIGHT                   (1U)

/* Configuration Options: ADC_VALUE_GROUP_TYPE 
ADC320: Only if all ADC channels of all ADC groups have 8 bit resolution, 
Adc_ValueGroupType can be configured as 8 bit data type.
Else, 16-bit is selected
*/

#define ADC_VALUE_EIGHT_BIT               (0U)
#define ADC_VALUE_SIXTEEN_BIT             (1U)

/* Configuration of channel & kernel mask to identify the 
channel & kernel number */ 
[!IF "ecu:get('Adc.NumOfChInGrp') = num:i(16)"!][!//
#define ADC_AN_CH_MASK                    (0xFU)
#define ADC_KERNEL_MASK                   (0x70U)
#define ADC_KERNEL_NUM_SHIFT_POS          (0x4U)
[!ELSE!][!//
#define ADC_AN_CH_MASK                    (0x7U)
#define ADC_KERNEL_MASK                   (0x78U)
#define ADC_KERNEL_NUM_SHIFT_POS          (0x3U)
[!ENDIF!][!//

/* Configuration of wait count of checking reset status */
#define ADC_KERNEL_RESET_WAIT_COUNTS      (0x100U)

/* Configuration of ARM bitfield of CALCTR register */ 
#define ADC_REF_LOCAL_MODE                (0U)
#define ADC_REF_GLOBAL_MODE               (1U)

/* Total number of Configuration set */
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
#define ADC_CONFIG_COUNT                  ([!"$TotalAdcConfig"!]U)
/*
                     Container : AdcDriverGeneralConfiguration
*/
/*
  The following macros will enable or disable a particular feature 
  in ADC module.
  Set the macro to ON to enable the feature and OFF to disable the same.
*/
/*
Configuration: ADC_DEV_ERROR_DETECT
Preprocessor switch for enabling the development error detection and 
reporting. 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define ADC_DEV_ERROR_DETECT  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcDevErrorDetect"!][!//

/*
Configuration: ADC_SAFETY_ENABLE
Preprocessor switch for enabling the Safety signals. 
- if STD_ON, Safety is Enabled 
- if STD_OFF,Safety is Disabled 
*/
#define ADC_SAFETY_ENABLE    [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcSafety/AdcSafetyEnable"!][!//

/*
Configuration: ADC_INITCHECK_API
Preprocessor switch for enabling the Adc_InitCheck Api. 
- if STD_ON, Adc_InitCheck Api is Enabled 
- if STD_OFF,Adc_InitCheck Api is Disabled 
*/
[!IF "(AdcSafety/AdcSafetyEnable = 'true')"!][!//
#define ADC_INITCHECK_API    [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcSafety/AdcInitCheckApi"!][!//
[!ELSE!][!//
#define ADC_INITCHECK_API    (STD_OFF)
[!ENDIF!][!//

/* Mask value for the GLOBCFG sfr */
[!IF "ecu:get('Adc.MaxControllers') = num:i(11)"!][!//
#define ADC_GLOBCFG_SFR_MSK               (0x07FFD39FU)
[!ELSEIF "ecu:get('Adc.MaxControllers') = num:i(8)"!][!//
#define ADC_GLOBCFG_SFR_MSK               (0x00FFD39FU)
[!ELSE!][!//
#define ADC_GLOBCFG_SFR_MSK               (0x000FD39FU)
[!ENDIF!][!//


/* Mask value for the SRC Register */
[!IF "ecu:get('Adc.ReqSrcCount') = num:i(4)"!][!//
#define ADC_SRC_SRCR_MSK                  (0x7F1F08FFU)
[!ELSE!][!//
#define ADC_SRC_SRCR_MSK                  (0x7F3F18FFU)
[!ENDIF!][!//

/*
Configuration: ADC_CCU6_SYNCHRONIZATION
Preprocessor switch for enabling the development CCU6x T13 to generate 20MHz  
Synchronization signal to all VADCs. 
- if STD_ON, Enables the CCU6x T13 to generate 20MHz Synchronization signal 
- if STD_OFF, Disables the CCU6x T13 to generate 20MHz Synchronization signal 
*/
[!IF "node:exists(AdcGeneral/AdcCcu6Synchronization)"!][!//
[!IF "AdcGeneral/AdcCcu6Synchronization = 'true'"!][!//
  [!WARNING "Configuration parameter AdcCcu6Synchronization should be set to true, only for devices (e.g., TC26xBB, TC27xDB, TC29xBB) with metal fix for cross coupling effect to initalize the CCU6 module to generate 20MHz synchronization signal.!"!][!//
[!ENDIF!][!//
#define ADC_CCU6_SYNCHRONIZATION      [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcCcu6Synchronization"!][!//
[!ELSE!][!//
#define ADC_CCU6_SYNCHRONIZATION      (STD_OFF)
[!ENDIF!][!//

/*
Configuration: ADC_ENABLE_LIMIT_CHECK
Preprocessor switch for enabling the limit checking feature of ADC. 
- if STD_ON, Limit checking feature of ADC is Enabled 
- if STD_OFF,Limit checking feature of ADC is Disabled 
*/
[!IF "node:exists(AdcGeneral/AdcEnableLimitCheck)"!][!//
#define ADC_ENABLE_LIMIT_CHECK        [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcEnableLimitCheck"!][!//
[!ELSE!][!//
#define ADC_ENABLE_LIMIT_CHECK        (STD_OFF)
[!ENDIF!][!//

/* Preprocessor switch for enabling the code to access VADC_GxCEVNP1 SFR */
[!IF "contains( ecu:get('Adc.ChEvntNodePtr1Available'), 'YES' )"!][!//
#define ADC_CH_EVNT_NPTR1_AVAILABLE   (STD_ON)
[!ELSE!][!//
#define ADC_CH_EVNT_NPTR1_AVAILABLE   (STD_OFF)
[!ENDIF!][!//

/* Preprocessor switch for enabling the code to access VADC_GxREVNP1 SFR */
[!IF "contains( ecu:get('Adc.ResEvntNodePtr1Available'), 'YES' )"!][!//
#define ADC_RES_EVNT_NPTR1_AVAILABLE  (STD_ON)
[!ELSE!][!//
#define ADC_RES_EVNT_NPTR1_AVAILABLE  (STD_OFF)
[!ENDIF!][!//

/* Configuration: ADC_VERSION_INFO_API
Version Information API configuration 
- if STD_ON, VersionInfo API is Enabled 
- if STD_OFF, VersionInfo API is Disabled 
*/
#define ADC_VERSION_INFO_API  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcVersionInfoApi"!][!//

/*
Configuration: ADC_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, Enable User0 mode 
- if STD_OFF, Disable User0 mode 
*/
[!IF "node:exists(./AdcGeneral/AdcRunningInUser0Mode)"!][!//
[!IF "AdcGeneral/AdcRunningInUser0Mode = 'true'"!][!//
[!ASSERT "not((./AdcGeneral/AdcUserModeInitApiEnable != 'true') and (./AdcGeneral/AdcUserModeDeInitApiEnable != 'true') and (./AdcGeneral/AdcUserModeRuntimeApiEnable != 'true'))"!][!//
Config Error: when AdcGeneral/AdcRunningInUser0Mode is set as true, [!//
Then atleast any one of the switches: AdcUserModeInitApiEnable or [!//
AdcUserModeDeInitApiEnable or AdcUserModeRuntimeApiEnable should be selected.[!//
But in configuration none are selected.[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
#define ADC_RUNNING_IN_USER_0_MODE_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./AdcGeneral/AdcRunningInUser0Mode"!]
[!ELSE!][!//
#define ADC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: ADC_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Disable Protected Mode(user mode) mode in Init API  
*/
[!IF "node:exists(./AdcGeneral/AdcUserModeInitApiEnable)"!][!//
#define ADC_USER_MODE_INIT_API_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./AdcGeneral/AdcUserModeInitApiEnable"!]
[!ELSE!][!//
#define ADC_USER_MODE_INIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: ADC_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Disable Protected Mode(user mode) mode in DeInit API 
*/
[!IF "node:exists(./AdcGeneral/AdcUserModeDeInitApiEnable)"!][!//
#define ADC_USER_MODE_DEINIT_API_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./AdcGeneral/AdcUserModeDeInitApiEnable"!]
[!ELSE!][!//
#define ADC_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: ADC_USER_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Protected Mode(user mode) mode in APIs other than Init/Deinit APIs
*/
[!IF "node:exists(./AdcGeneral/AdcUserModeRuntimeApiEnable)"!][!//
#define ADC_USER_MODE_RUNTIME_API_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./AdcGeneral/AdcUserModeRuntimeApiEnable"!]
[!ELSE!][!//
#define ADC_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/* Configuration: ADC_DEINIT_API
Adc_DeInit API configuration 
- if STD_ON, DeInit API is Enabled 
- if STD_OFF, DeInit API is Disabled 
*/
#define ADC_DEINIT_API  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcDeInitApi"!][!//

/* Configuration: ADC_ENABLE_START_STOP_GROUP_API
Start/Stop Group conversion API configuration 
- if STD_ON, Start/Stop Group conversion API is Enabled 
- if STD_OFF, Start/Stop Group conversion API is Disabled 
*/
#define ADC_ENABLE_START_STOP_GROUP_API  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcEnableStartStopGroupApi"!][!//

/* Configuration: ADC_HW_TRIGGER_API
Adc HW Trigger API configuration 
- if STD_ON, Adc HW Trigger API is Enabled 
- if STD_OFF, Adc HW Trigger API is Disabled 
*/
#define ADC_HW_TRIGGER_API  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcHwTriggerApi"!][!//

[!NOCODE!][!//
/* Checking is done for UTP AI00132371 */
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "TotalGroups"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "AdcGatePin" = "'GATE_PIN_RESET'"!][!//
[!VAR "AdcExtTrig" = "'TRIG_RESET'"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcRSType" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!VAR "AdcSWType" = "AdcGroup/*[@index = $GroupId]/AdcGroupTriggSrc"!][!//
[!VAR "HWTrigType" = "AdcGroup/*[@index = $GroupId]/AdcHwTrigType"!][!//
[!IF "($AdcRSType = 'REQSRC2_BGND_SCAN') and ($AdcSWType = 'ADC_TRIGG_SRC_HW') and ($HWTrigType = 'HW_TRIGG_TIMER')"!][!//
[!IF "($AdcGatePin = 'GATE_PIN_RESET')"!][!//
[!VAR "AdcGatePin" = "AdcGroup/*[@index = $GroupId]/AdcHwGatePin"!][!//
[!VAR "AdcAccessMode" = "AdcGroup/*[@index = $GroupId]/AdcGroupAccessMode"!][!//
[!VAR "AdcTimerPeriod" = "AdcGroup/*[@index = $GroupId]/AdcGtmTimerPeriod"!][!//
[!VAR "AdcBufferMode" = "AdcGroup/*[@index = $GroupId]/AdcStreamingBufferMode"!][!//
[!VAR "AdcNumSamples" = "AdcGroup/*[@index = $GroupId]/AdcStreamingNumSamples"!][!//
[!VAR "HwUnitName" = "@name"!][!//
[!VAR "GroupName" = "AdcGroup/*[@index = $GroupId]/@name"!][!//
[!ELSE!][!//
[!VAR "CurGroupName" = "AdcGroup/*[@index = $GroupId]/@name"!][!//
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcGroupAccessMode = $AdcAccessMode"!][!//
Config Error: AdcGroupAccessMode in [!"$CurGroupName"!] of [!"node:name(.)"!] should be same as [!"$GroupName"!] of [!"$HwUnitName"!]. AdcGroupAccessMode must be same for all the Timer triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcGtmTimerPeriod = $AdcTimerPeriod"!][!//
Config Error: AdcGtmTimerPeriod in [!"$CurGroupName"!] of [!"node:name(.)"!] should be same as [!"$GroupName"!] of [!"$HwUnitName"!]. AdcGtmTimerPeriod must be same for all the Timer triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcStreamingBufferMode = $AdcBufferMode"!][!//
Config Error: AdcStreamingBufferMode in [!"$CurGroupName"!] of [!"node:name(.)"!] should be same as [!"$GroupName"!] of [!"$HwUnitName"!]. AdcStreamingBufferMode must be same for all the Timer triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcStreamingNumSamples = $AdcNumSamples"!][!//
Config Error: AdcStreamingNumSamples in [!"$CurGroupName"!] of [!"node:name(.)"!] should be same as [!"$GroupName"!] of [!"$HwUnitName"!]. AdcStreamingNumSamples must be same for all the Timer triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcHwGatePin = $AdcGatePin"!][!//
Config Error: AdcHwGatePin in [!"$CurGroupName"!] of [!"node:name(.)"!] should be same as [!"$GroupName"!] of [!"$HwUnitName"!]. AdcHwGatePin must be same for all the Timer triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ENDIF!][!//
[!ELSEIF "($AdcRSType = 'REQSRC2_BGND_SCAN') and ($AdcSWType = 'ADC_TRIGG_SRC_HW') and ($HWTrigType = 'HW_TRIGG_EXT_REQ')"!][!//
[!IF "($AdcExtTrig = 'TRIG_RESET')"!][!//
[!VAR "AdcExtTrig" = "AdcGroup/*[@index = $GroupId]/AdcHwExtTrigSelect"!][!//
[!VAR "AdcAccessModeExt" = "AdcGroup/*[@index = $GroupId]/AdcGroupAccessMode"!][!//
[!VAR "AdcGateSignal" = "AdcGroup/*[@index = $GroupId]/AdcHwGateSignal"!][!//
[!VAR "AdcBufferModeExt" = "AdcGroup/*[@index = $GroupId]/AdcStreamingBufferMode"!][!//
[!VAR "AdcNumSamplesExt" = "AdcGroup/*[@index = $GroupId]/AdcStreamingNumSamples"!][!//
[!IF "($AdcGateSignal != 'ADC_GATE_SIGNAL_NONE')"!][!//
[!VAR "AdcGatePinExt" = "AdcGroup/*[@index = $GroupId]/AdcHwGatePin"!][!//
[!ENDIF!][!//
[!VAR "HwUnitNameExt" = "@name"!][!//
[!VAR "GroupNameExt" = "AdcGroup/*[@index = $GroupId]/@name"!][!//
[!ELSE!][!//
[!VAR "CurGroupNameExt" = "AdcGroup/*[@index = $GroupId]/@name"!][!//
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcGroupAccessMode = $AdcAccessModeExt"!][!//
Config Error: AdcGroupAccessMode in [!"$CurGroupNameExt"!] of [!"node:name(.)"!] should be same as [!"$GroupNameExt"!] of [!"$HwUnitNameExt"!]. AdcGroupAccessMode must be same for all the External triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcHwExtTrigSelect = $AdcExtTrig"!][!//
Config Error: AdcHwExtTrigSelect in [!"$CurGroupNameExt"!] of [!"node:name(.)"!] should be same as [!"$GroupNameExt"!] of [!"$HwUnitNameExt"!]. AdcHwExtTrigSelect must be same for all the External triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcHwGateSignal = $AdcGateSignal"!][!//
Config Error: AdcHwGateSignal in [!"$CurGroupNameExt"!] of [!"node:name(.)"!] should be same as [!"$GroupNameExt"!] of [!"$HwUnitNameExt"!]. AdcHwGateSignal must be same for all the External triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!IF "(AdcGroup/*[@index = $GroupId]/AdcHwGateSignal != 'ADC_GATE_SIGNAL_NONE')"!][!//
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcHwGatePin = $AdcGatePinExt"!][!//
Config Error: AdcHwGatePin in [!"$CurGroupNameExt"!] of [!"node:name(.)"!] should be same as [!"$GroupNameExt"!] of [!"$HwUnitNameExt"!]. AdcHwGatePin must be same for all the External triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ENDIF!][!//
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcStreamingBufferMode = $AdcBufferModeExt"!][!//
Config Error: AdcStreamingBufferMode in [!"$CurGroupNameExt"!] of [!"node:name(.)"!] should be same as [!"$GroupNameExt"!] of [!"$HwUnitNameExt"!]. AdcStreamingBufferMode must be same for all the External triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ASSERT "AdcGroup/*[@index = $GroupId]/AdcStreamingNumSamples = $AdcNumSamplesExt"!][!//
Config Error: AdcStreamingNumSamples in [!"$CurGroupNameExt"!] of [!"node:name(.)"!] should be same as [!"$GroupNameExt"!] of [!"$HwUnitNameExt"!]. AdcStreamingNumSamples must be same for all the External triggered Background Resquest Source (RS2) Adc_Groups. 
[!ENDASSERT!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!VAR "TimerTrig" = "num:i(0)"!][!//
[!VAR "EruReqTrig" = "num:i(0)"!][!//
[!VAR "EruGateSel" = "num:i(0)"!][!// 
[!ENDNOCODE!][!//
[!IF "AdcGeneral/AdcHwTriggerApi = 'true'"!][!//
#if (ADC_HW_TRIGGER_API == STD_ON)
/* Configuration: ADC_TIMER_TRIGG , ADC_ERU_TRIGG, ADC_ERU_GATING 
   Determines if the HW trigger is through Timer or ERU trigger, or both 
- if ON, The Trigger Type is Enabled 
- if OFF, The Trigger Type is Disabled
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "TotalGroups"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcSWType" = "AdcGroup/*[@index = $GroupId]/AdcGroupTriggSrc"!][!//
[!IF "($AdcSWType = 'ADC_TRIGG_SRC_HW')"!][!//
[!VAR "HWTrigType" = "AdcGroup/*[@index = $GroupId]/AdcHwTrigType"!][!//
[!IF "($HWTrigType = 'HW_TRIGG_TIMER')"!][!//
[!VAR "TimerTrig" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "AdcTrigSelect" = "AdcGroup/*[@index = $GroupId]/AdcHwExtTrigSelect"!][!//  
[!IF "contains($AdcTrigSelect,'IOUT')"!][!//
[!VAR "EruReqTrig" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "AdcGateSelect" = "AdcGroup/*[@index = $GroupId]/AdcHwGatePin"!][!//  
[!IF "contains($AdcGateSelect,'PDOUT')"!][!//
[!VAR "EruGateSel" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!IF "$TimerTrig = num:i(1)"!]
#define ADC_TIMER_TRIGG             (STD_ON)
[!ELSE!][!//
#define ADC_TIMER_TRIGG             (STD_OFF)
[!ENDIF!][!//
[!IF "$EruReqTrig = num:i(1)"!]
#define ADC_ERU_TRIGG               (STD_ON)
[!ELSE!][!//
#define ADC_ERU_TRIGG               (STD_OFF)
[!ENDIF!][!//
[!IF "$EruGateSel = num:i(1)"!]
#define ADC_ERU_GATING              (STD_ON)
[!ELSE!][!//
#define ADC_ERU_GATING              (STD_OFF)
[!ENDIF!][!//
#endif
[!ELSE!][!//
#define ADC_TIMER_TRIGG             (STD_OFF)
#define ADC_ERU_TRIGG               (STD_OFF)
#define ADC_ERU_GATING              (STD_OFF)
[!ENDIF!][!//

[!NOCODE!][!//
[!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!/* Determine only one AdcConfigSet is configured 
                                        when AdcPBFixedAddress = true.*/!]
[!IF "AdcGeneral/AdcPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalAdcConfig != 1)"!][!//
Config Error: when AdcGeneral/AdcPBFixedAddress is set as true, [!//
Only one AdcConfigSet configuration is allowed. [!//
But AdcConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* Configuration: ADC_PB_FIXED_ADDRESS (Vendor specific)
Fixed address confiuration as per HIS recommendatons
- if STD_ON, ConfigRoot[0] is used by default as the fixed configuration
- if STD_OFF, Dynamic usage of the selected configurations according to AUTOSAR 
*/
#define ADC_PB_FIXED_ADDRESS               [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcPBFixedAddress"!]

/* Configuration: ADC_MASTER_SLAVE_SYNC
Enables/Disables the Synchronization of conversion (Parallel sampling) feature 
- if STD_ON, Enables Parallel sampling 
- if STD_OFF, Disables Parallel sampling 
*/
#define ADC_MASTER_SLAVE_SYNC              [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcMasterSlaveSync"!][!//

#if( ADC_MASTER_SLAVE_SYNC == STD_ON )
/* Configuration: ADC_KERNELS_PER_SYNGRP
Provides the number of kernels per synchronization group
*/
[!IF "num:i(ecu:get('Adc.MaxControllers')) >= num:i(4)"!][!//
#define ADC_KERNELS_PER_SYNGRP             (4U)
[!ELSE!][!//
#define ADC_KERNELS_PER_SYNGRP             ([!"num:i(ecu:get('Adc.MaxControllers'))"!]U)
[!ENDIF!][!//
#endif /* ( ADC_MASTER_SLAVE_SYNC == STD_ON ) */

/* Configuration: ADC_SAMPLE_HOLD_UNIT
- if STD_ON: Sample and Hold unit is available in the used ADC
- if STD_OFF: Sample and Hold unit is not available in the used ADC 
*/
[!IF "node:exists(AdcGeneral/AdcSampleAndHoldUnitAvailable)"!][!//
#define ADC_SAMPLE_HOLD_UNIT               [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcSampleAndHoldUnitAvailable"!]
[!ELSE!][!//
#define ADC_SAMPLE_HOLD_UNIT               (STD_OFF)
[!ENDIF!][!//

/* Preprocessor switch for enabling the Adc_17_GetStartupCalStatus() API */
[!IF "contains( ecu:get('Adc.StartUpCal'), 'HW_CAL' )"!][!//
#define ADC_HW_STARTUP_CALIBRATION         (STD_ON)
[!ELSE!][!//
#define ADC_HW_STARTUP_CALIBRATION         (STD_OFF)
[!ENDIF!][!//

[!NOCODE!][!//
[!IF "node:exists(AdcGeneral/AdcSampleAndHoldUnitAvailable)"!][!//
[!IF "AdcGeneral/AdcSampleAndHoldUnitAvailable = 'false'"!][!//
  [!WARNING "Configuration parameter AdcSampleAndHoldUnitAvailable must be set to true, if the Sample and Hold unit is available in VADC Hardware. e.g, TC27xBA & TC27xBC step device.!"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* Configuration: ADC_ALTERNATE_REF_MODE
- if ADC_REF_LOCAL_MODE: Channel 0 (CH0) of a Kernel is used as reference
- if ADC_REF_GLOBAL_MODE: Channel 0 (CH0) of a selected kernel of a 
  cluster is used as reference 
*/
[!IF "node:exists(AdcGeneral/AdcSampleAndHoldUnitAvailable)"!][!//
[!IF "AdcGeneral/AdcSampleAndHoldUnitAvailable = 'true'"!][!//
#define ADC_ALTERNATE_REF_MODE       ([!"AdcGeneral/AdcAlternateRefMode"!])
[!ELSE!][!//
#define ADC_ALTERNATE_REF_MODE       (ADC_REF_LOCAL_MODE)
[!ENDIF!][!//
[!ELSE!][!//
#define ADC_ALTERNATE_REF_MODE       (ADC_REF_LOCAL_MODE)
[!ENDIF!][!//

[!NOCODE!][!//
[!VAR "AltRefSelected" = "num:i(0)"!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "TotalAdcChannels"= "num:i(count(AdcChannel/*))"!][!//
[!FOR "ChannelId" ="num:i(0)" TO "num:i($TotalAdcChannels)-1"!][!//
[!VAR "RefVolt" = "AdcChannel/*[@index=$ChannelId]/AdcChannelRefVoltsrcHigh"!][!//
[!IF "$RefVolt = 'REF_VOLTAGE_CH0'"!][!//
[!VAR "AltRefSelected" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
/* Configuration: ADC_ALTERNATE_REF_CH_USED
- if STD_ON: Channel 0 (CH0) is used as reference
- if STD_OFF: Standard reference is used
*/
[!IF "$AltRefSelected = num:i(1)"!][!//
#define ADC_ALTERNATE_REF_CH_USED    (STD_ON)
[!ELSE!][!//
#define ADC_ALTERNATE_REF_CH_USED    (STD_OFF)
[!ENDIF!][!//

/* Configuration: ADC_RESULT_POLLING_MODE
Switches the ADC Group result handing between AUTOSAR specific and Non AUTOSAR polling mode 
- if STD_ON, enables the services Adc_17_GetGroupResult() and Adc_17_GetChannelStatus() from code 
- if STD_OFF, disables the services Adc_17_GetGroupResult() and Adc_17_GetChannelStatus() from code 
*/
#define ADC_RESULT_POLLING_MODE  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcNonAutosarResultPolling"!][!//

/* Configuration: ADC_SAME_CHANNEL_QUEUING
Adc same channel queing in request source que capability configuration 
- if STD_ON, Same channel queing is Enabled 
- if STD_OFF, Same channel queing is Disabled 
*/
[!IF "(AdcGeneral/AdcNonAutosarDmaResultHandling = 'false') and (AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
#define ADC_SAME_CHANNEL_QUEUING   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcSameChannelQueuing"!][!//
[!ELSE!][!//
#define ADC_SAME_CHANNEL_QUEUING   (STD_OFF)
[!ENDIF!][!//

/* Configuration: ADC_RESULT_HANDLING_MODE 
   ADC Group result handling selection
- if AdcNonAutosarDmaResultHandling = true, Result handling is ADC_NON_AUTOSAR
- if AdcNonAutosarDmaResultHandling = false, Result handling is ADC_AUTOSAR
*/
[!IF "(AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
#define ADC_RESULT_HANDLING_MODE  [!//
[!CALL "CG_ResHandlingConfigSwitch","nodeval" = "AdcGeneral/AdcNonAutosarDmaResultHandling"!][!//
[!ELSE!][!//
#define ADC_RESULT_HANDLING_MODE  (ADC_NON_AUTOSAR)
[!ENDIF!][!//

[!IF "(AdcGeneral/AdcNonAutosarResultPolling = 'true')"!][!//
/*
  Configuration Options: ADC_RESULT_ACCUMULATION
  ADC_RES_ACCUMULATION_NONE: No accumulation of the result. 
  ADC_RES_ACCUMULATION_TWO: Accumulation of the results upto 2 conversions.
  ADC_RES_ACCUMULATION_THREE: Accumulation of the results upto 3 conversions.
  ADC_RES_ACCUMULATION_FOUR: Accumulation of the results upto 4 conversions.
  WFR mode disabled
*/
#define ADC_RES_ACCUMULATION_NONE     (0x00000000U)
#define ADC_RES_ACCUMULATION_TWO      (0x00010000U)
#define ADC_RES_ACCUMULATION_THREE    (0x00020000U)
#define ADC_RES_ACCUMULATION_FOUR     (0x00030000U)
[!ELSE!][!//
/* ADC_RES_ACCUMULATION_NONE: No accumulation of the result. Result register 
                        will have only one conversion value/WFR mode enabled
*/
#define ADC_RES_ACCUMULATION_NONE     (0x01000000U)
#if ( (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) ||\
                                        (ADC_SAME_CHANNEL_QUEUING ==  STD_ON) )
/*
  Configuration Options: ADC_RESULT_ACCUMULATION
  ADC_RES_ACCUMULATION_TWO: Accumulation of the results upto 2 conversions.
  ADC_RES_ACCUMULATION_THREE: Accumulation of the results upto 3 conversions.
  ADC_RES_ACCUMULATION_FOUR: Accumulation of the results upto 4 conversions.
  WFR mode enabled
*/
#define ADC_RES_ACCUMULATION_TWO      (0x01010000U)
#define ADC_RES_ACCUMULATION_THREE    (0x01020000U)
#define ADC_RES_ACCUMULATION_FOUR     (0x01030000U)

#endif 
/* (ADC_RESULT_HANDLING_MODE == ADC_NON_AUTOSAR) || 
                                         (ADC_SAME_CHANNEL_QUEUING ==  STD_ON)*/
[!ENDIF!][!//

[!IF "(AdcGeneral/AdcNonAutosarDmaResultHandling = 'true') or (AdcGeneral/AdcNonAutosarResultPolling = 'true')"!][!//
/* Configuration: ADC_RESULT_ACCUMULATION 
   Selection of AtoD result data reduction
*/
#define ADC_RESULT_ACCUMULATION  ([!"AdcGeneral/AdcResultAccumulation"!])[!//
[!ENDIF!][!//

[!IF "(AdcGeneral/AdcNonAutosarDmaResultHandling = 'false') and (AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
/* Configuration: ADC_READ_GROUP_API
Adc_ReadGroup API switch 
- if STD_ON, Adc_ReadGroup API is Enabled 
- if STD_OFF, Adc_ReadGroup API is Disabled 
*/
#define ADC_READ_GROUP_API  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcReadGroupApi"!][!//
[!ENDIF!][!//

/* Configuration: ADC_RESET_SFR_INIT
Resetting SFR to its reset value 
- if STD_ON, resetting of SFRs to its reset value in the Adc_Init() is Enabled 
- if STD_OFF, resetting of SFRs to its reset value in the Adc_Init() is Disabled 
*/
#define ADC_RESET_SFR_INIT  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcResetSfrAtInit"!][!//

/* Configuration: ADC_GRP_NOTIF_CAPABILITY
Adc Notification capability configuration 
- if STD_ON, Adc Notification capability is Enabled 
- if STD_OFF, Adc Notification capability is Disabled 
*/
[!IF "(AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
#define ADC_GRP_NOTIF_CAPABILITY  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcGrpNotifCapability"!][!//
[!ELSE!][!//
#define ADC_GRP_NOTIF_CAPABILITY  (STD_OFF)
[!ENDIF!][!//

/* Configuration: ADC_DEBUG_SUPPORT
Adc Debug capability configuration 
- if STD_ON, Debug support is Enabled 
- if STD_OFF, Debug support is Disabled 
*/
#define ADC_DEBUG_SUPPORT         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcDebugSupport"!][!//

/* Configuration: ADC_RESULT_ALIGNMENT
Determines the ADC result alignment
*/
#define ADC_RESULT_ALIGNMENT      ([!"AdcGeneral/AdcResultAlignment"!])

/* Configuration: ADC_PRIORITY_IMPLEMENTATION
Determines the type of prioritization mechanism
*/
[!IF "(AdcGeneral/AdcNonAutosarDmaResultHandling = 'false') and (AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
#define ADC_PRIORITY_IMPLEMENTATION  ([!"AdcGeneral/AdcPriorityImplementation"!])
[!ELSE!][!//
#define ADC_PRIORITY_IMPLEMENTATION  (ADC_PRIORITY_NONE)
[!ENDIF!][!//

/* Since ADC_PRIORITY_HW_SW has no meaning in case of AdcEnableStartStopGroupApi
   disabled, throw error */
[!IF "AdcGeneral/AdcEnableStartStopGroupApi = 'false'"!][!//
[!ASSERT "(AdcGeneral/AdcPriorityImplementation != 'ADC_PRIORITY_HW_SW')"!]
Cfg ERROR: The priority can not be ADC_PRIORITY_HW_SW when 'AdcEnableStartStopGroupApi' is false.
[!ENDASSERT!]
[!ASSERT "(AdcGeneral/AdcEnableQueuing = 'false' or AdcGeneral/AdcPriorityImplementation != 'ADC_PRIORITY_NONE')"!]
Cfg ERROR: AdcEnableQueuing can not be set to true when 'AdcEnableStartStopGroupApi' is false.
[!ENDASSERT!]
[!ENDIF!][!//

/* Configuration: ADC_USE_EMUX (Vendor specific)
Micro controller specific static configuration
- if STD_ON, Adc External multiplexer is used by the user
- if STD_OFF, Adc External multiplexer is not used by the user 
*/
#define ADC_USE_EMUX               [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcUseEmux"!]

[!IF "(AdcGeneral/AdcNonAutosarDmaResultHandling = 'false') and (AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
[!IF "AdcGeneral/AdcEnableStartStopGroupApi = 'true' and AdcGeneral/AdcPriorityImplementation = 'ADC_PRIORITY_NONE'"!][!//
#if ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&\
      (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)\
    )
/* Configuration: ADC_ENABLE_QUEUING
Determines, if the queuing mechanism is active in case of priority mechanism 
disabled.
Note: If priority mechanism is enabled, queuing mechanism is always active 
and the parameter ADC_ENABLE_QUEUING is not evaluated.
- if STD_ON, Queuing mechanism in no priority is Enabled 
- if STD_OFF, Queuing mechanism in no priority is Disabled 
*/
#define ADC_ENABLE_QUEUING  [!//
[!CALL "CG_ConfigSwitch","nodeval" = "AdcGeneral/AdcEnableQueuing"!]

#endif/* ( (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) &&\
            (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_NONE)\
          )*/

[!ELSE!][!// If Priority is other than PRIORITY_NONE
/* Configuration: ADC_ENABLE_QUEUING
Determines, if the queuing mechanism is active in case of priority mechanism 
is disabled (PRIORITY_NONE).
Note: If priority mechanism is enabled, queuing mechanism is always active 
and the parameter ADC_ENABLE_QUEUING is not evaluated.
- if STD_ON, Queuing mechanism in no priority is Enabled 
- if STD_OFF, Queuing mechanism in no priority is Disabled 
*/
#define ADC_ENABLE_QUEUING  (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!// AdcNonAutosarDmaResultHandling = 'true' 
/* Note: For Non AUTOSAR result handling, No Priority Queue is STD_OFF */
/* Configuration: ADC_ENABLE_QUEUING
Determines, if the queuing mechanism is active in case of priority mechanism 
is disabled (PRIORITY_NONE).
Note: If priority mechanism is enabled, queuing mechanism is always active 
and the parameter ADC_ENABLE_QUEUING is not evaluated.
- if STD_ON, Queuing mechanism in no priority is Enabled 
- if STD_OFF, Queuing mechanism in no priority is Disabled 
*/
#define ADC_ENABLE_QUEUING  (STD_OFF)
[!ENDIF!][!//


#if((ADC_ENABLE_QUEUING == STD_ON) || (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR))
/* Configuration: ADC_MAX_GROUPS (Vendor Specific)
It is the maximum among the total number of groups configured in each 
Adc configuration.
This parameter is required for Queue mechanism in No Priority.
This parameter is automatically generated by the tool. 
For example if there are two post build configurations and 2 HW Units 
configured among each, with maximum 2, 3, 4 and 5 groups repectively in each 
HW Units, then ADC_MAX_GROUPS must be configured as 5. 
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "TotalGroups"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$TotalAdcGroups > $TotalGroups"!][!//
[!VAR "TotalGroups" = "num:i($TotalAdcGroups)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
#define ADC_MAX_GROUPS   ([!"$TotalGroups"!]U)
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

[!NOCODE!][!//
[!VAR "Safety"= "AdcSafety/AdcSafetyEnable"!][!//
[!ASSERT "($Safety != 'true') or (AdcGeneral/AdcNonAutosarDmaResultHandling != 'true')"!][!//
Config Error: AdcNonAutosarDmaResultHandling can not be set to true, if AdcSafetyEnable is set to true. Non Autosar Dma handling feature is not available for the Safety driver.
[!ENDASSERT!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "TotalAdc0Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc1Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc2Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc3Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc4Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc5Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc6Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc7Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc8Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc9Groups"= "num:i(0)"!][!//
[!VAR "TotalAdc10Groups"= "num:i(0)"!][!//
[!VAR "Adc0Count"= "num:i(0)"!][!//
[!VAR "Adc1Count"= "num:i(0)"!][!//
[!VAR "Adc2Count"= "num:i(0)"!][!//
[!VAR "Adc3Count"= "num:i(0)"!][!//
[!VAR "Adc4Count"= "num:i(0)"!][!//
[!VAR "Adc5Count"= "num:i(0)"!][!//
[!VAR "Adc6Count"= "num:i(0)"!][!//
[!VAR "Adc7Count"= "num:i(0)"!][!//
[!VAR "Adc8Count"= "num:i(0)"!][!//
[!VAR "Adc96Count"= "num:i(0)"!][!//
[!VAR "Adc10Count"= "num:i(0)"!][!//
[!VAR "Adc0Index"= "num:i(0)"!][!//
[!VAR "Adc1Index"= "num:i(0)"!][!//
[!VAR "Adc2Index"= "num:i(0)"!][!//
[!VAR "Adc3Index"= "num:i(0)"!][!//
[!VAR "Adc4Index"= "num:i(0)"!][!//
[!VAR "Adc5Index"= "num:i(0)"!][!//
[!VAR "Adc6Index"= "num:i(0)"!][!//
[!VAR "Adc7Index"= "num:i(0)"!][!//
[!VAR "Adc8Index"= "num:i(0)"!][!//
[!VAR "Adc9Index"= "num:i(0)"!][!//
[!VAR "Adc10Index"= "num:i(0)"!][!//
[!VAR "AdcIndex"= "num:i(0)"!][!//
[!VAR "Adc0QmIndex"= "num:i(0)"!][!//
[!VAR "Adc1QmIndex"= "num:i(0)"!][!//
[!VAR "Adc2QmIndex"= "num:i(0)"!][!//
[!VAR "Adc3QmIndex"= "num:i(0)"!][!//
[!VAR "Adc4QmIndex"= "num:i(0)"!][!//
[!VAR "Adc5QmIndex"= "num:i(0)"!][!//
[!VAR "Adc6QmIndex"= "num:i(0)"!][!//
[!VAR "Adc7QmIndex"= "num:i(0)"!][!//
[!VAR "Adc8QmIndex"= "num:i(0)"!][!//
[!VAR "Adc9QmIndex"= "num:i(0)"!][!//
[!VAR "Adc10QmIndex"= "num:i(0)"!][!//
[!VAR "AdcQmIndex"= "num:i(0)"!][!//
[!VAR "AdcAsil0Index"= "num:i(0)"!][!//
[!VAR "Adc0Asil0Index"= "num:i(0)"!][!//
[!VAR "Adc1Asil0Index"= "num:i(0)"!][!//
[!VAR "Adc2Asil0Index"= "num:i(0)"!][!//
[!VAR "Adc3Asil0Index"= "num:i(0)"!][!//
[!VAR "AdcAsil1Index"= "num:i(0)"!][!//
[!VAR "Adc1Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc2Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc3Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc4Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc5Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc6Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc7Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc8Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc9Asil1Index"= "num:i(0)"!][!//
[!VAR "Adc10Asil1Index"= "num:i(0)"!][!//
[!VAR "AdcKernelUsed"= "num:i(0)"!][!//
[!VAR "Adc0Signal"= "'SIGNAL'"!][!//
[!VAR "Adc1Signal"= "'SIGNAL'"!][!//
[!VAR "Adc2Signal"= "'SIGNAL'"!][!//
[!VAR "Adc3Signal"= "'SIGNAL'"!][!//
[!VAR "Adc4Signal"= "'SIGNAL'"!][!//
[!VAR "Adc5Signal"= "'SIGNAL'"!][!//
[!VAR "Adc6Signal"= "'SIGNAL'"!][!//
[!VAR "Adc7Signal"= "'SIGNAL'"!][!//
[!VAR "Adc8Signal"= "'SIGNAL'"!][!//
[!VAR "Adc9Signal"= "'SIGNAL'"!][!//
[!VAR "Adc10Signal"= "'SIGNAL'"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC0')"!][!//
[!//
[!VAR "Adc0Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc0Count > $TotalAdc0Groups"!][!//
[!VAR "TotalAdc0Groups" = "num:i($Adc0Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc0Signal = 'SIGNAL'"!][!//
[!VAR "Adc0Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc0Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 0 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 0, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC1')"!][!//
[!//
[!VAR "Adc1Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc1Count > $TotalAdc1Groups"!][!//
[!VAR "TotalAdc1Groups" = "num:i($Adc1Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc1Signal = 'SIGNAL'"!][!//
[!VAR "Adc1Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc1Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 1 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 1, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC2')"!][!//
[!//
[!VAR "Adc2Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc2Count > $TotalAdc2Groups"!][!//
[!VAR "TotalAdc2Groups" = "num:i($Adc2Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc2Signal = 'SIGNAL'"!][!//
[!VAR "Adc2Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc2Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 2 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 2, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC3')"!][!//
[!//
[!VAR "Adc3Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc3Count > $TotalAdc3Groups"!][!//
[!VAR "TotalAdc3Groups" = "num:i($Adc3Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc3Signal = 'SIGNAL'"!][!//
[!VAR "Adc3Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc3Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 3 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 3, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC4')"!][!//
[!//
[!VAR "Adc4Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc4Count > $TotalAdc4Groups"!][!//
[!VAR "TotalAdc4Groups" = "num:i($Adc4Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc4Signal = 'SIGNAL'"!][!//
[!VAR "Adc4Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc4Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 4 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 4, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC5')"!][!//
[!//
[!VAR "Adc5Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc5Count > $TotalAdc5Groups"!][!//
[!VAR "TotalAdc5Groups" = "num:i($Adc5Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc5Signal = 'SIGNAL'"!][!//
[!VAR "Adc5Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc5Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 5 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 5, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC6')"!][!//
[!//
[!VAR "Adc6Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc6Count > $TotalAdc6Groups"!][!//
[!VAR "TotalAdc6Groups" = "num:i($Adc6Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc6Signal = 'SIGNAL'"!][!//
[!VAR "Adc6Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc6Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 6 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 6, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC7')"!][!//
[!//
[!VAR "Adc7Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc7Count > $TotalAdc7Groups"!][!//
[!VAR "TotalAdc7Groups" = "num:i($Adc7Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc7Signal = 'SIGNAL'"!][!//
[!VAR "Adc7Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc7Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 7 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 7, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC8')"!][!//
[!//
[!VAR "Adc8Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc8Count > $TotalAdc8Groups"!][!//
[!VAR "TotalAdc8Groups" = "num:i($Adc8Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc8Signal = 'SIGNAL'"!][!//
[!VAR "Adc8Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc8Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 8 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 8, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC9')"!][!//
[!//
[!VAR "Adc9Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc9Count > $TotalAdc9Groups"!][!//
[!VAR "TotalAdc9Groups" = "num:i($Adc9Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc9Signal = 'SIGNAL'"!][!//
[!VAR "Adc9Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc9Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 9 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 9, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC10')"!][!//
[!//
[!VAR "Adc10Count"= "num:i(count(AdcGroup/*))"!][!//
[!IF "$Adc10Count > $TotalAdc10Groups"!][!//
[!VAR "TotalAdc10Groups" = "num:i($Adc10Count)"!][!//
[!ENDIF!][!//
[!IF "$Safety = 'true'"!][!//
[!IF "$Adc10Signal = 'SIGNAL'"!][!//
[!VAR "Adc10Signal" = "./AdcSafetySignal"!][!//
[!ENDIF!][!//
[!VAR "AdcSignal" = "./AdcSafetySignal"!][!//
[!ASSERT "($Adc10Signal = $AdcSignal)", "AdcSafetySignal of Adc HW unit 10 should be configured as same across all configset"!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = 'REQSRC2_BGND_SCAN']"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC2_BGND_SCAN')", "AdcGroupRequestSource should not be configured as REQSRC2_BGND_SCAN for Group in Adc HW unit 10, if AdcSafetyEnable is set to true."!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
[!IF "$TotalAdc0Groups > num:i(0)"!][!//
[!IF "$Adc0Signal = 'true'"!][!//
[!VAR "Adc0Asil0Index" = "num:i($AdcAsil0Index)"!][!//
[!VAR "AdcAsil0Index" = "$AdcAsil0Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc0QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc0Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(0))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
[!IF "$TotalAdc1Groups > num:i(0)"!][!//
[!IF "$Adc1Signal = 'true'"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') >= num:i(2))"!][!//
[!VAR "Adc1Asil0Index" = "num:i($AdcAsil0Index)"!][!//
[!VAR "AdcAsil0Index" = "$AdcAsil0Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc1Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "Adc1QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc1Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(1))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
[!IF "$TotalAdc2Groups > num:i(0)"!][!//
[!IF "$Adc2Signal = 'true'"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
[!VAR "Adc2Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc2Asil0Index" = "num:i($AdcAsil0Index)"!][!//
[!VAR "AdcAsil0Index" = "$AdcAsil0Index + num:i(1)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "Adc2QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc2Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(2))))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
[!IF "$TotalAdc3Groups > num:i(0)"!][!//
[!IF "$Adc3Signal = 'true'"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
[!VAR "Adc3Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc3Asil0Index" = "num:i($AdcAsil0Index)"!][!//
[!VAR "AdcAsil0Index" = "$AdcAsil0Index + num:i(1)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "Adc3QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc3Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(3))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
[!IF "$TotalAdc4Groups > num:i(0)"!][!//
[!IF "$Adc4Signal = 'true'"!][!//
[!VAR "Adc4Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc4QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc4Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(4))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
[!IF "$TotalAdc5Groups > num:i(0)"!][!//
[!IF "$Adc5Signal = 'true'"!][!//
[!VAR "Adc5Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc5QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc5Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(5))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
[!IF "$TotalAdc6Groups > num:i(0)"!][!//
[!IF "$Adc6Signal = 'true'"!][!//
[!VAR "Adc6Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc6QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc6Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(6))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
[!IF "$TotalAdc7Groups > num:i(0)"!][!//
[!IF "$Adc7Signal = 'true'"!][!//
[!VAR "Adc7Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc7QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc7Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(7))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
[!IF "$TotalAdc8Groups > num:i(0)"!][!//
[!IF "$Adc8Signal = 'true'"!][!//
[!VAR "Adc8Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc8QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc8Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(8))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
[!IF "$TotalAdc9Groups > num:i(0)"!][!//
[!IF "$Adc9Signal = 'true'"!][!//
[!VAR "Adc9Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc9QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc9Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(9))))"!][!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
[!IF "$TotalAdc10Groups > num:i(0)"!][!//
[!IF "$Adc10Signal = 'true'"!][!//
[!VAR "Adc10Asil1Index" = "num:i($AdcAsil1Index)"!][!//
[!VAR "AdcAsil1Index" = "$AdcAsil1Index + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Adc10QmIndex" = "num:i($AdcQmIndex)"!][!//
[!VAR "AdcQmIndex" = "$AdcQmIndex + num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "Adc10Index" = "num:i($AdcIndex)"!][!//
[!VAR "AdcIndex" = "$AdcIndex + num:i(1)"!][!//
[!VAR "AdcKernelUsed" = "bit:or($AdcKernelUsed,(bit:shl(1,num:i(10))))"!][!// 
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/* Configuration: ADCx_KERNEL_INDEX (Vendor Specific)
It is the variable array index of each Adc Hw Unit.
This parameter is automatically generated by the tool. 
For example if there are two ADC Hw units used, say ADC0 and ADC2,
ADC0_KERNEL_INDEX = 0, ADC2_KERNEL_INDEX = 1, ADC1_KERNEL_INDEX = Invalid
*/
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
#define ADC0_KERNEL_INDEX  ([!"num:i($Adc0Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
#define ADC1_KERNEL_INDEX  ([!"num:i($Adc1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
#define ADC2_KERNEL_INDEX  ([!"num:i($Adc2Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
#define ADC3_KERNEL_INDEX  ([!"num:i($Adc3Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
#define ADC4_KERNEL_INDEX  ([!"num:i($Adc4Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
#define ADC5_KERNEL_INDEX  ([!"num:i($Adc5Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
#define ADC6_KERNEL_INDEX  ([!"num:i($Adc6Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
#define ADC7_KERNEL_INDEX  ([!"num:i($Adc7Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
#define ADC8_KERNEL_INDEX  ([!"num:i($Adc8Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
#define ADC9_KERNEL_INDEX  ([!"num:i($Adc9Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
#define ADC10_KERNEL_INDEX ([!"num:i($Adc10Index)"!]U)
[!ENDIF!][!//

/* Configuration: ADCx_QM_KERNEL_INDEX (Vendor Specific)
It is the variable array index of each Adc Hw Unit.
This parameter is automatically generated by the tool. 
For example if there are two ADC Hw units used, say ADC0 and ADC2,
ADC0_QM_KERNEL_INDEX = 0, ADC2_QM_KERNEL_INDEX = 1, 
ADC1_QM_KERNEL_INDEX = Invalid
*/
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
#define ADC0_QM_KERNEL_INDEX  ([!"num:i($Adc0QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
#define ADC1_QM_KERNEL_INDEX  ([!"num:i($Adc1QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
#define ADC2_QM_KERNEL_INDEX  ([!"num:i($Adc2QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
#define ADC3_QM_KERNEL_INDEX  ([!"num:i($Adc3QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
#define ADC4_QM_KERNEL_INDEX  ([!"num:i($Adc4QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
#define ADC5_QM_KERNEL_INDEX  ([!"num:i($Adc5QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
#define ADC6_QM_KERNEL_INDEX  ([!"num:i($Adc6QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
#define ADC7_QM_KERNEL_INDEX  ([!"num:i($Adc7QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
#define ADC8_QM_KERNEL_INDEX  ([!"num:i($Adc8QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
#define ADC9_QM_KERNEL_INDEX  ([!"num:i($Adc9QmIndex)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
#define ADC10_QM_KERNEL_INDEX ([!"num:i($Adc10QmIndex)"!]U)
[!ENDIF!][!//


[!IF "$Safety = 'true'"!][!//
/* Configuration: ADCx_ASIL_KERNEL_INDEX (Vendor Specific)
It is the variable array index of each Adc Hw Unit.
This parameter is automatically generated by the tool. 
For example if there are two ADC Hw units used, say ADC0 and ADC2,
ADC0_ASIL_KERNEL_INDEX = 0, ADC2_ASIL_KERNEL_INDEX = 1, 
ADC1_ASIL_KERNEL_INDEX = Invalid
*/
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
#define ADC0_ASIL_KERNEL_INDEX  ([!"num:i($Adc0Asil0Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') >= num:i(2))"!][!//
#define ADC1_ASIL_KERNEL_INDEX  ([!"num:i($Adc1Asil0Index)"!]U)
[!ELSE!][!//
#define ADC1_ASIL_KERNEL_INDEX  ([!"num:i($Adc1Asil1Index)"!]U)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
#define ADC2_ASIL_KERNEL_INDEX  ([!"num:i($Adc2Asil1Index)"!]U)
[!ELSE!][!//
#define ADC2_ASIL_KERNEL_INDEX  ([!"num:i($Adc2Asil0Index)"!]U)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
#define ADC3_ASIL_KERNEL_INDEX  ([!"num:i($Adc3Asil1Index)"!]U)
[!ELSE!][!//
#define ADC3_ASIL_KERNEL_INDEX  ([!"num:i($Adc3Asil0Index)"!]U)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
#define ADC4_ASIL_KERNEL_INDEX  ([!"num:i($Adc4Asil1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
#define ADC5_ASIL_KERNEL_INDEX  ([!"num:i($Adc5Asil1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
#define ADC6_ASIL_KERNEL_INDEX  ([!"num:i($Adc6Asil1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
#define ADC7_ASIL_KERNEL_INDEX  ([!"num:i($Adc7Asil1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
#define ADC8_ASIL_KERNEL_INDEX  ([!"num:i($Adc8Asil1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
#define ADC9_ASIL_KERNEL_INDEX  ([!"num:i($Adc9Asil1Index)"!]U)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
#define ADC10_ASIL_KERNEL_INDEX ([!"num:i($Adc10Asil1Index)"!]U)
[!ENDIF!][!//
[!ENDIF!][!//

/* Number of ADC Kernels in the selected microcontroller */
#define ADC_MAX_KERNELS    ([!"num:i(ecu:get('Adc.MaxControllers'))"!]U)
/* ADC Kernels Configured to use */
#define ADC_USED_KERNELS   ([!"num:inttohex($AdcKernelUsed, 4)"!]U)
/* Number of SHS Clusters in the selected microcontroller */
#define ADC_MAX_SHS_CLUSTERS  ([!"num:i(ecu:get('Adc.MaxSHClusters'))"!]U)
/* Number of Kernels per Clusters in the selected microcontroller */
#define ADC_KERNELS_PER_CLUSTER  ([!"num:i(ecu:get('Adc.HwUnitPerCluster'))"!]U)

/*
  Constant for getting  the variable array index for particular ADC Kernel
  If any of the ADCs are not used, its index will be 0.
  If Kernel is not used, the corresponding Index will be invalid value
  Eg: If ADC0 and ADC2 are used, then 
  ADC0_QM_KERNEL_INDEX = 0
  ADC2_QM_KERNEL_INDEX = 1
  and ADC_QM_KERNEL_USED_COUNT = 2
*/
/*IFX_MISRA_RULE_19_04_STATUS=ADC_QM_KERNEL_INDEX cannot be expand to a braced 
 initialiser*/
#define ADC_QM_KERNEL_INDEX   [!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
ADC0_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
, \
                              ADC1_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
, \
                              ADC2_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
, \
                              ADC3_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
, \
                              ADC4_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
, \
                              ADC5_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
, \
                              ADC6_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
, \
                              ADC7_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
, \
                              ADC8_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
, \
                              ADC9_QM_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
, \
                              ADC10_QM_KERNEL_INDEX[!//
[!ENDIF!][!//


[!IF "$Safety = 'true'"!][!//
/*
  Constant for getting  the variable array index for particular ADC Kernel
  If any of the ADCs are not used, its index will be 0.
  If Kernel is not used, the corresponding Index will be invalid value
  Eg: If ADC0 and ADC2 are used, then 
  ADC0_ASIL_KERNEL_INDEX = 0
  ADC2_ASIL_KERNEL_INDEX = 1
  and ADC_ASIL0_KERNEL_USED_COUNT = 2
*/
/*IFX_MISRA_RULE_19_04_STATUS=ADC_ASIL0_KERNEL_INDEX cannot be expand to a 
braced initialiser*/
#define ADC_ASIL0_KERNEL_INDEX   [!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
ADC0_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' ) and (ecu:get('Adc.HwUnitPerCluster') >= num:i(2))"!][!//
, \
                                 ADC1_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' ) and (ecu:get('Adc.HwUnitPerCluster') = num:i(4))"!][!//
, \
                                 ADC2_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' ) and (ecu:get('Adc.HwUnitPerCluster') = num:i(4))"!][!//
, \
                                 ADC3_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//

/*
  Constant for getting  the variable array index for particular ADC Kernel
  If any of the ADCs are not used, its index will be 0.
  If Kernel is not used, the corresponding Index will be invalid value
  Eg: If ADC4 and ADC6 are used, then 
  ADC4_ASIL_KERNEL_INDEX = 0
  ADC6_ASIL_KERNEL_INDEX = 1
  and ADC_ASIL1_KERNEL_USED_COUNT = 2
*/
/*IFX_MISRA_RULE_19_04_STATUS=ADC_ASIL1_KERNEL_INDEX cannot be expand to a 
braced initialiser*/
#define ADC_ASIL1_KERNEL_INDEX   [!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' ) and (ecu:get('Adc.HwUnitPerCluster') = num:i(1))"!][!//
ADC1_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' ) and (ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
ADC2_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' ) and (ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
, \
                                 ADC3_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
ADC4_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
, \
                                 ADC5_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
, \
                                 ADC6_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
, \
                                 ADC7_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
, \
                                 ADC8_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
, \
                                 ADC9_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
, \
                                 ADC10_ASIL_KERNEL_INDEX[!//
[!ENDIF!][!//
[!ENDIF!][!//

/* Configuration: ADCx_KERNEL_USED (Vendor Specific)
Define a macro for each Adc Hw Unit when Used in any of the configuration set
For example if there are two ADC Hw units used, say ADC0 and ADC2,
define ADC0_KERNEL_USED and ADC2_KERNEL_USED
ADC1_KERNEL_USED is not defined
*/
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
[!IF "$TotalAdc0Groups > num:i(0)"!][!//
#define ADC0_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC0_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
[!IF "$TotalAdc1Groups > num:i(0)"!][!//
#define ADC1_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC1_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
[!IF "$TotalAdc2Groups > num:i(0)"!][!//
#define ADC2_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC2_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
[!IF "$TotalAdc3Groups > num:i(0)"!][!//
#define ADC3_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC3_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
[!IF "$TotalAdc4Groups > num:i(0)"!][!//
#define ADC4_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC4_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
[!IF "$TotalAdc5Groups > num:i(0)"!][!//
#define ADC5_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC5_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
[!IF "$TotalAdc6Groups > num:i(0)"!][!//
#define ADC6_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC6_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
[!ENDIF!][!//
[!IF "$TotalAdc7Groups > num:i(0)"!][!//
#define ADC7_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC7_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
[!IF "$TotalAdc8Groups > num:i(0)"!][!//
#define ADC8_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC8_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
[!IF "$TotalAdc9Groups > num:i(0)"!][!//
#define ADC9_KERNEL_USED         (STD_ON)
[!ELSE!][!//
#define ADC9_KERNEL_USED         (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
[!IF "$TotalAdc10Groups > num:i(0)"!][!//
#define ADC10_KERNEL_USED        (STD_ON)
[!ELSE!][!//
#define ADC10_KERNEL_USED        (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//
/* Configuration: ADC_KERNEL_USED_COUNT (Vendor Specific)
Define a macro for total number of Adc Hw Unit in use
For example if there are two ADC Hw units used across post build 
configurations , say ADC0 and ADC1,
ADC_KERNEL_USED_COUNT = 2
*/
#define ADC_KERNEL_USED_COUNT  ([!"num:i($AdcIndex)"!]U)[!//

/* Configuration: ADC_QM_KERNEL_USED_COUNT (Vendor Specific)
Define a macro for total number of Adc Hw Unit in use
For example if there are two ADC Hw units used across post build 
configurations , say ADC0 and ADC1,
ADC_QM_KERNEL_USED_COUNT = 2
*/
#define ADC_QM_KERNEL_USED_COUNT  ([!"num:i($AdcQmIndex)"!]U)[!//
 
[!IF "$Safety = 'true'"!][!//
/* Configuration: ADC_ASIL0_KERNEL_USED_COUNT (Vendor Specific)
Define a macro for total number of Adc Hw Unit in use
For example if there are two ADC Hw units used across post build 
configurations , say ADC0 and ADC1,
ADC_ASIL0_KERNEL_USED_COUNT = 2
*/
#define ADC_ASIL0_KERNEL_USED_COUNT  ([!"num:i($AdcAsil0Index)"!]U)[!//
 
/* Configuration: ADC_ASIL1_KERNEL_USED_COUNT (Vendor Specific)
Define a macro for total number of Adc Hw Unit in use
For example if there are two ADC Hw units used across post build 
configurations , say ADC4 and ADC5,
ADC_ASIL1_KERNEL_USED_COUNT = 2
*/
#define ADC_ASIL1_KERNEL_USED_COUNT  ([!"num:i($AdcAsil1Index)"!]U)[!//
[!ENDIF!][!//

/* Configuration: ADC_VALUE_GROUP_TYPE (Vendor specific)
Macro to decide the Adc_ValueGroupType to be 8-bit or 16-bit
If all the Adc configured channels are of 8 bit resolution, 
8-bit is selected for Adc_ValueGroupType. Else, 16-bit is selected
This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!IF "AdcGeneral/AdcSameChannelQueuing = 'false'"!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "Flag" = "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "TotalAdcChannels"= "num:i(count(AdcChannel/*))"!][!//
[!FOR "ChannelId" ="num:i(0)" TO "num:i($TotalAdcChannels)-1"!][!//
[!VAR "classname" = "node:name(node:ref(AdcChannel/*[@index=$ChannelId]/AdcInputClassSelection))"!][!//
[!VAR "ParentClass" = "node:name(node:ref(AdcChannel/*[@index=$ChannelId]/AdcInputClassSelection)/..)"!][!//
[!//
[!IF "contains($ParentClass,'Kernel')"!][!//
[!//
[!LOOP "AdcKernelInputClass/*"!][!//
[!//
[!IF "$classname = @name"!][!//
[!//
[!VAR "AdcChannelRes" ="AdcKernelChResolution"!]
[!IF "($AdcChannelRes = 'CH_RES_10BIT') or ($AdcChannelRes = 'CH_RES_12BIT')"!][!//
[!VAR "Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!ELSE!][!//
[!//
[!LOOP "../../AdcGlobInputClass/*"!][!//
[!IF "$classname = @name"!][!//
[!//
[!VAR "AdcChannelRes" ="AdcGlobChResolution"!]
[!IF "($AdcChannelRes = 'CH_RES_10BIT') or ($AdcChannelRes = 'CH_RES_12BIT')"!][!//
[!VAR "Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ELSE!][!//
[!VAR "Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "$Flag = num:i(1)"!][!//
#define ADC_VALUE_GROUP_TYPE     (ADC_VALUE_SIXTEEN_BIT)
[!ELSE!][!//
#define ADC_VALUE_GROUP_TYPE     (ADC_VALUE_EIGHT_BIT)
[!ENDIF!][!//

[!VAR "Flag" = "num:i(0)"!][!//
[!IF "AdcGeneral/AdcNonAutosarDmaResultHandling = 'true'"!][!//
/* Configuration: ADC_SWOSM_INTERRUPT_HANDLER (Vendor specific)
Macro to switch ON or OFF the SW trigger Oneshot groups interrupt handler
If any of the Group type is SW trigger Oneshot mode, the switch is set ON 
else OFF
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "GroupConvMode" ="AdcGroup/*[@index = $GroupId]/AdcGroupConversionMode"!]
[!IF "($GroupConvMode = 'ADC_CONV_MODE_ONESHOT')"!][!//
[!VAR "Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!//
[!ENDIF!][!//
[!IF "$Flag = num:i(1)"!][!//
#define ADC_SWOSM_INTERRUPT_HANDLER     (STD_ON)
[!ELSE!][!//
#define ADC_SWOSM_INTERRUPT_HANDLER     (STD_OFF)
[!ENDIF!][!//

/*
  Macro indicating the total number of request sources used by the driver
*/
#define ADC_REQSRC_COUNT       ([!"num:i(ecu:get('Adc.ReqSrcCount'))"!]U)

/*
  Macro indicating the availability of Request Source 3
*/
[!IF "(num:i(ecu:get('Adc.ReqSrcCount')) = num:i(4))"!][!//
#define ADC_REQSRC3_AVAILABLE   (STD_ON)
[!ELSE!][!//
#define ADC_REQSRC3_AVAILABLE   (STD_OFF)
[!ENDIF!][!//

/* Configuration Options: ADCx_REQSRCy
   Options for request source of perticular ADC Hw Unit used or not
*/
#define ADC_REQSRC_USED        (1U)
#define ADC_REQSRC_UNUSED      (0U)

[!VAR "AdcReqSrc0Used"= "num:i(0)"!][!//
[!VAR "AdcReqSrc1Used"= "num:i(0)"!][!//
[!VAR "AdcReqSrc2Used"= "num:i(0)"!][!//
[!VAR "AdcReqSrc3Used"= "num:i(0)"!][!//
[!VAR "Adc0ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc0ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc0ReqSrc2Flag"= "num:i(0)"!][!//
[!VAR "Adc0ReqSrc3Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0' )"!][!//
/* Configuration: ADC0_REQSRCy (Vendor specific)
   Request source (RS0 .. RS3) of perticular ADC0 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC0')"!][!//
[!VAR "ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc0ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc0ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc0ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC3_8STG_QUE')"!][!//
[!ASSERT "$ArbRoundLen != 'ARBITRATION_SLOTS_4'"!]
 ERROR: Invalid configuration. AdcArbitrationRoundLength cannot be configured as ARBITRATION_SLOTS_4, if REQSRC3_8STG_QUE is used.
[!ENDASSERT!][!//
[!VAR "Adc0ReqSrc3Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc0ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(0))))"!][!//  
#define ADC0_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC0_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc0ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(0))))"!][!//  
#define ADC0_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC0_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc0ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(0))))"!][!// 
#define ADC0_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC0_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc0ReqSrc3Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc3Used" = "bit:or($AdcReqSrc3Used,(bit:shl(1,num:i(0))))"!][!//  
#define ADC0_REQSRC3  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC0_REQSRC3  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc1ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc1ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc1ReqSrc2Flag"= "num:i(0)"!][!//
[!VAR "Adc1ReqSrc3Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1' )"!][!//
/* Configuration: ADC1_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC1 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC1')"!][!//
[!VAR "ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc1ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc1ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc1ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC3_8STG_QUE')"!][!//
[!ASSERT "$ArbRoundLen != 'ARBITRATION_SLOTS_4'"!]
 ERROR: Invalid configuration. AdcArbitrationRoundLength cannot be configured as ARBITRATION_SLOTS_4, if REQSRC3_8STG_QUE is used.
[!ENDASSERT!][!//
[!VAR "Adc1ReqSrc3Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc1ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(1))))"!][!//  
#define ADC1_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC1_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc1ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(1))))"!][!//  
#define ADC1_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC1_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc1ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(1))))"!][!// 
#define ADC1_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC1_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc1ReqSrc3Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc3Used" = "bit:or($AdcReqSrc3Used,(bit:shl(1,num:i(1))))"!][!// 
#define ADC1_REQSRC3  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC1_REQSRC3  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc2ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc2ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc2ReqSrc2Flag"= "num:i(0)"!][!//
[!VAR "Adc2ReqSrc3Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2' )"!][!//
/* Configuration: ADC2_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC2 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC2')"!][!//
[!VAR "ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc2ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc2ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc2ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC3_8STG_QUE')"!][!//
[!ASSERT "$ArbRoundLen != 'ARBITRATION_SLOTS_4'"!]
 ERROR: Invalid configuration. AdcArbitrationRoundLength cannot be configured as ARBITRATION_SLOTS_4, if REQSRC3_8STG_QUE is used.
[!ENDASSERT!][!//
[!VAR "Adc2ReqSrc3Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc2ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(2))))"!][!//  
#define ADC2_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC2_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc2ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(2))))"!][!//  
#define ADC2_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC2_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc2ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(2))))"!][!// 
#define ADC2_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC2_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc2ReqSrc3Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc3Used" = "bit:or($AdcReqSrc3Used,(bit:shl(1,num:i(2))))"!][!// 
#define ADC2_REQSRC3  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC2_REQSRC3  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc3ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc3ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc3ReqSrc2Flag"= "num:i(0)"!][!//
[!VAR "Adc3ReqSrc3Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3' )"!][!//
/* Configuration: ADC3_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC3 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC3')"!][!//
[!VAR "ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc3ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc3ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc3ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC3_8STG_QUE')"!][!//
[!ASSERT "$ArbRoundLen != 'ARBITRATION_SLOTS_4'"!]
 ERROR: Invalid configuration. AdcArbitrationRoundLength cannot be configured as ARBITRATION_SLOTS_4, if REQSRC3_8STG_QUE is used.
[!ENDASSERT!][!//
[!VAR "Adc3ReqSrc3Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc3ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(3))))"!][!//  
#define ADC3_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC3_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc3ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(3))))"!][!//  
#define ADC3_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC3_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc3ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(3))))"!][!// 
#define ADC3_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC3_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc3ReqSrc3Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc3Used" = "bit:or($AdcReqSrc3Used,(bit:shl(1,num:i(3))))"!][!// 
#define ADC3_REQSRC3  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC3_REQSRC3  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc4ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc4ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc4ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4' )"!][!//
/* Configuration: ADC4_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC4 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC4')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc4ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc4ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc4ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc4ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(4))))"!][!//  
#define ADC4_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC4_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc4ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(4))))"!][!//  
#define ADC4_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC4_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc4ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(4))))"!][!// 
#define ADC4_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC4_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc5ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc5ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc5ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5' )"!][!//
/* Configuration: ADC5_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC5 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC5')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc5ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc5ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc5ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc5ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(5))))"!][!//  
#define ADC5_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC5_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc5ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(5))))"!][!//  
#define ADC5_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC5_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc5ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(5))))"!][!// 
#define ADC5_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC5_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc6ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc6ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc6ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6' )"!][!//
/* Configuration: ADC6_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC6 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC6')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc6ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc6ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc6ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc6ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(6))))"!][!//  
#define ADC6_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC6_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc6ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(6))))"!][!//  
#define ADC6_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC6_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc6ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(6))))"!][!// 
#define ADC6_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC6_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc7ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc7ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc7ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7' )"!][!//
/* Configuration: ADC7_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC7 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC7')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc7ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc7ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc7ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc7ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(7))))"!][!//  
#define ADC7_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC7_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc7ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(7))))"!][!//  
#define ADC7_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC7_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc7ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(7))))"!][!// 
#define ADC7_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC7_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc8ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc8ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc8ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8' )"!][!//
/* Configuration: ADC8_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC8 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC8')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc8ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc8ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc8ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc8ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(8))))"!][!//  
#define ADC8_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC8_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc8ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(8))))"!][!//  
#define ADC8_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC8_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc8ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(8))))"!][!// 
#define ADC8_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC8_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "Adc9ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc9ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc9ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9' )"!][!//
/* Configuration: ADC9_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC9 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC9')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc9ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc9ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc9ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc9ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(9))))"!][!//  
#define ADC9_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC9_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc9ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(9))))"!][!//  
#define ADC9_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC9_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//
  
[!IF "$Adc9ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(9))))"!][!// 
#define ADC9_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC9_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//
  
[!VAR "Adc10ReqSrc0Flag"= "num:i(0)"!][!//
[!VAR "Adc10ReqSrc1Flag"= "num:i(0)"!][!//
[!VAR "Adc10ReqSrc2Flag"= "num:i(0)"!][!//
[!IF "contains( ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10' )"!][!//
/* Configuration: ADC10_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of perticular ADC10 Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "AdcReqSrc"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "AdcHwUnit" = "./AdcHwUnitId"!][!//
[!IF "($AdcHwUnit = 'HWUNIT_ADC10')"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcReqSrc" = "AdcGroup/*[@index = $GroupId]/AdcGroupRequestSource"!][!//
[!IF "($AdcReqSrc = 'REQSRC0_8STG_QUE')"!][!//
[!VAR "Adc10ReqSrc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC1_NCH_SCAN')"!][!//
[!VAR "Adc10ReqSrc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!IF "($AdcReqSrc = 'REQSRC2_BGND_SCAN')"!][!//
[!VAR "Adc10ReqSrc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//

[!IF "$Adc10ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Used" = "bit:or($AdcReqSrc0Used,(bit:shl(1,num:i(10))))"!][!// 
#define ADC10_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC10_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!IF "$Adc10ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Used" = "bit:or($AdcReqSrc1Used,(bit:shl(1,num:i(10))))"!][!// 
#define ADC10_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC10_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//
  
[!IF "$Adc10ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Used" = "bit:or($AdcReqSrc2Used,(bit:shl(1,num:i(10))))"!][!// 
#define ADC10_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC10_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

/* macros used to identify the Request sources configured */  
#define ADC_KERNEL_REQSRC0_USED  ([!"num:inttohex($AdcReqSrc0Used, 4)"!]U)
#define ADC_KERNEL_REQSRC1_USED  ([!"num:inttohex($AdcReqSrc1Used, 4)"!]U)
#define ADC_KERNEL_REQSRC2_USED  ([!"num:inttohex($AdcReqSrc2Used, 4)"!]U)
#define ADC_KERNEL_REQSRC3_USED  ([!"num:inttohex($AdcReqSrc3Used, 4)"!]U)


/* Configuration: ADC_REQSRCy (Vendor specific)
   Request source (RS0 .. RS2) of any ADC Hw Unit used or not
   This parameter is automatically ganerated by the tool
*/
[!VAR "AdcReqSrc0Flag"= "num:i(0)"!][!//
[!IF "$Adc0ReqSrc0Flag = num:i(1) or $Adc1ReqSrc0Flag = num:i(1) or $Adc2ReqSrc0Flag = num:i(1) or [!//
  $Adc3ReqSrc0Flag = num:i(1) or $Adc4ReqSrc0Flag = num:i(1) or $Adc5ReqSrc0Flag = num:i(1) or [!//
  $Adc6ReqSrc0Flag = num:i(1) or $Adc7ReqSrc0Flag = num:i(1) or $Adc8ReqSrc0Flag = num:i(1) or [!//
  $Adc9ReqSrc0Flag = num:i(1) or $Adc10ReqSrc0Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc0Flag"= "num:i(1)"!][!//
#define ADC_REQSRC0  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC_REQSRC0  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "AdcReqSrc1Flag"= "num:i(0)"!][!//
[!IF "$Adc0ReqSrc1Flag = num:i(1) or $Adc1ReqSrc1Flag = num:i(1) or $Adc2ReqSrc1Flag = num:i(1) or [!//
  $Adc3ReqSrc1Flag = num:i(1) or $Adc4ReqSrc1Flag = num:i(1) or $Adc5ReqSrc1Flag = num:i(1) or [!//
  $Adc6ReqSrc1Flag = num:i(1) or $Adc7ReqSrc1Flag = num:i(1) or $Adc8ReqSrc1Flag = num:i(1) or [!//
  $Adc9ReqSrc1Flag = num:i(1) or $Adc10ReqSrc1Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc1Flag"= "num:i(2)"!][!//
#define ADC_REQSRC1  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC_REQSRC1  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "AdcReqSrc2Flag"= "num:i(0)"!][!//
[!IF "$Adc0ReqSrc2Flag = num:i(1) or $Adc1ReqSrc2Flag = num:i(1) or $Adc2ReqSrc2Flag = num:i(1) or [!//
  $Adc3ReqSrc2Flag = num:i(1) or $Adc4ReqSrc2Flag = num:i(1) or $Adc5ReqSrc2Flag = num:i(1) or [!//
  $Adc6ReqSrc2Flag = num:i(1) or $Adc7ReqSrc2Flag = num:i(1) or $Adc8ReqSrc2Flag = num:i(1) or [!//
  $Adc9ReqSrc2Flag = num:i(1) or $Adc10ReqSrc2Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc2Flag"= "num:i(4)"!][!//
#define ADC_REQSRC2  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC_REQSRC2  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!VAR "AdcReqSrc3Flag"= "num:i(0)"!][!//
[!IF "$Adc0ReqSrc3Flag = num:i(1) or $Adc1ReqSrc3Flag = num:i(1) or $Adc2ReqSrc3Flag = num:i(1) or [!//
  $Adc3ReqSrc3Flag = num:i(1)"!][!//
[!VAR "AdcReqSrc3Flag"= "num:i(8)"!][!//
#define ADC_REQSRC3  (ADC_REQSRC_USED)
[!ELSE!][!//
#define ADC_REQSRC3  (ADC_REQSRC_UNUSED)
[!ENDIF!][!//

[!NOCODE!][!//
[!VAR "AdcReqSrcCount"= "num:i(ecu:get('Adc.ReqSrcCount')) - num:i(1)"!][!//
[!VAR "AdcReqSrc" = "num:i(0)"!][!//
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!]
[!VAR "ReqSrcFlag" = "num:i($AdcReqSrc0Flag)"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcFlag" = "num:i($AdcReqSrc1Flag)"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcFlag" = "num:i($AdcReqSrc2Flag)"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcFlag" = "num:i($AdcReqSrc3Flag)"!][!//
[!ENDIF!][!//
[!VAR "AdcReqSrc" = "bit:or(num:i($AdcReqSrc),num:i($ReqSrcFlag))"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
/* Enable request sources for arbitration */
#define ADC_REQSRC_ARB_ENABLE          ((uint32)[!"num:inttohex($AdcReqSrc)"!])

/* Configuration: ADC_MAX_CH_CON_TIME_COUNT (Vendor specific)
  On stop of conversion request, the ongoing channel conversion in the 
  A/D converter can't be stopped. Insted the API / software needs to wait 
  for atleast the converter to become idle. 
  Only when the converter is idle, the stop request is completely serviced. 
  Inorder to ensure the converter is idle, a wait on coverter status polling 
  is required and its maximum wait time is defined by the value entered in 
  the AdcMaxChConvTimeCount.

  Conversion time = 2 * tADC + (4 + STC + n) * tADCI + sample phase length
  where: 
  n = 8, 10, 12 for n bit resolution
  tADC = ADC module clock = system clock
  tADCI = Analog clock
  STC = Sample time control (Value - 0, 1, 2 ... 16, 32, 48, 64, 80, 96, 112, 128,
        144, 160, 176, 192, 208, 224, 240, 256)

  sample phase length = (2 + STC) / fADCI
  STC = Sample time control (Value - 0, 1, 2 ... 16, 32, 48, 64, 80, 96, 112, 128,
        144, 160, 176, 192, 208, 224, 240, 256)
             fADCI : Analog clock frequency
             1/fADCI = tADCI

  Maximum sample phase length value:
  STC = 256
  tADCI = 32*tADC
  tADC = tSYS (System clock time)
  No. of sampling time count = 32*tSYS (2+256) / tSYS = 8256
  
  Minimum sample phase length value:
  STC = 0
  tADCI = 1*tADC
  tADC = tSYS (System clock time)
  No. of sampling time count = 1*tSYS (2+0) / tSYS = 2

  Maximum Conversion time value:
  tADC = tSYS (System clock time)
  tADCI = 32 * tADC
  STC = 256
  n =  12 bit resolution
  No. of conversion time count = tSYS (2+(4+256+12)32) / tSYS + 
                                 Maximum sample phase length value 
                               = 8706 + 8256 = 16962
  Minimum Conversion time value:
  tADC = tSYS (System clock time)
  tADCI = 1* tADC
  STC = 0
  n =  8 bit resolution
  No. of conversion time count = tSYS (2+(4+0+8)1) / tSYS + 
                                 Minimum sample phase length value 
                               = 14 + 2 = 16
*/
[!ASSERT "AdcGeneral/AdcMaxChConvTimeCount <= num:i(16962)", "AdcMaxChConvTimeCount should be configured less than or equal to 16962"!][!//
#define ADC_MAX_CH_CON_TIME_COUNT                 ([!"AdcGeneral/AdcMaxChConvTimeCount"!]U)

/* Configuration: ADC_WAIT_ON_STOP (Vendor specific)
   Macro to switch ON/OFF the wait for HW unit Idle state in the driver on 
   Stop / Disable request
   If the configured ADC_MAX_CH_CON_TIME_COUNT is less than the minimum value,
   ADC_WAIT_ON_STOP is set OFF. In this case,  user has to ensure that 
   new start of a Group is called only when ADC HW Unit is Idle. 
   Switching off of driver to wait on stop is applicable in 
   PRIORITY_NONE (Queue is OFF) and PRIORITY_HW_SW.
   This parameter is automatically ganerated by the tool
*/
[!IF "AdcGeneral/AdcMaxChConvTimeCount < num:i(16)"!][!//
#define ADC_WAIT_ON_STOP             (STD_OFF)
[!ELSE!][!//
#define ADC_WAIT_ON_STOP             (STD_ON)
[!ENDIF!][!//

[!IF "AdcGeneral/AdcEnableLimitCheck = 'true'"!][!//
/* Limit check configured ADC kernels */
[!NOCODE!][!//
[!VAR "LimitChkUsed"= "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!LOOP "node:order(./AdcChannel/*, './AdcChannelId')"!]
[!IF "./AdcChannelLimitCheck  = 'true'"!][!//
[!VAR "LimitChkUsed" = "bit:or($LimitChkUsed,(bit:shl(1,num:i($UnitId))))"!][!// 
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!//
[!ASSERT "$LimitChkUsed != num:i(0)", "Global switch AdcEnableLimitCheck is enabled, but none of the Adc channel's parameter AdcChannelLimitCheck is enabled."!][!//
[!//
[!ENDNOCODE!][!//
#define ADC_LIMIT_CHECK_USED  ([!"num:inttohex($LimitChkUsed, 4)"!]U)
[!ENDIF!][!//


/* Configuration: ADC_GROUP_EMUX_SCAN (Vendor specific)
Macro which tells if any of the Group uses EMUX scan feature or not. 
This parameter is automatically ganerated by the tool
*/
[!IF "(AdcGeneral/AdcNonAutosarDmaResultHandling = 'false') and (AdcGeneral/AdcNonAutosarResultPolling = 'false')"!][!//
[!//
[!IF "AdcGeneral/AdcUseEmux = 'true'"!][!//
[!//
[!NOCODE!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!VAR "Flag"= "num:i(0)"!][!//
[!VAR "TotalDmaTransfer"= "num:i(0)"!][!//
[!VAR "DmaTransferCount"= "num:i(0)"!][!//
[!VAR "GroupStreaming"= "num:i(0)"!][!//
[!VAR "EmuxSelect"= "num:i(0)"!][!//
[!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcEmuxScan" = "AdcGroup/*[@index = $GroupId]/AdcEmuxScanEnable"!][!//
[!IF "($AdcEmuxScan = 'true')"!][!//
[!ASSERT "($Safety != 'true')"!][!//
Config Error: AdcEmuxScanEnable can not be set to true in a group, if AdcSafetyEnable is set to true. Emux Scan feature is not available for the Safety driver.
[!ENDASSERT!]
[!VAR "Flag" = "num:i(1)"!][!//
[!VAR "EmuxSelect"= "AdcGroup/*[@index = $GroupId]/AdcChannelEmuxSelect"!]
[!VAR "EmuxSelect"= "num:i($EmuxSelect + num:i(1))"!]

[!VAR "GroupStreaming" = "num:i(AdcGroup/*[@index = $GroupId]/AdcStreamingNumSamples)"!][!//
[!VAR "DmaTransferCount" = "num:i(($EmuxSelect) * ($GroupStreaming))"!][!//
[!IF "($DmaTransferCount > $TotalDmaTransfer)"!]
[!VAR "TotalDmaTransfer" = "num:i($DmaTransferCount)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!IF "$Flag = num:i(1)"!][!//
#define ADC_GROUP_EMUX_SCAN  (STD_ON)

/* Configuration: ADC_DMA_MAX_TRANSFER (Vendor specific)
Macro which tells the maximum DMA transfer size from EMUX Scan Groups.
value = 
 MAX((Group channel Emux selcect value + 1) * Group streaming number of samples)
This parameter is automatically ganerated by the tool. The value is generated 
only when ADC_GROUP_EMUX_SCAN == STD_ON 
*/
#define ADC_DMA_MAX_TRANSFER  ([!"$TotalDmaTransfer"!]U)
[!ELSE!][!//
#define ADC_GROUP_EMUX_SCAN   (STD_OFF)
[!ENDIF!][!//
[!//
[!ELSE!][!//AdcUseEmux = 'false'
#define ADC_GROUP_EMUX_SCAN   (STD_OFF)
[!ENDIF!][!//
[!//
[!ELSE!][!//AdcNonAutosarDmaResultHandling = 'true'
#define ADC_GROUP_EMUX_SCAN   (STD_OFF)
[!ENDIF!][!//

[!IF "(AdcGeneral/AdcHwTriggerApi = 'true') and ($TimerTrig = num:i(1))"!][!//
#if ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_TIMER_TRIGG == STD_ON))

#define ADC_GTM_NO_OF_TIM_MODULES          ([!"ecu:get('Gtm.NumberOfTimModules')"!]U)
#define ADC_GTM_CHANNELS_PER_TIM_MODULE    ([!"ecu:get('Gtm.NumberOfTimChannels')"!]U)
#define ADC_GTM_MAX_TIM_CHANNELS    \
                 (ADC_GTM_NO_OF_TIM_MODULES *  ADC_GTM_CHANNELS_PER_TIM_MODULE)

#define ADC_GTM_NO_OF_TOM_MODULES          ([!"ecu:get('Gtm.NumberOfTomModules')"!]U)
#define ADC_GTM_NO_OF_TGC_PER_MODULE       ([!"ecu:get('Gtm.NumberOfTGCPerTom')"!]U)
#define ADC_GTM_CHANNELS_PER_TOM_MODULE    ([!"ecu:get('Gtm.NumberOfTomChannels')"!]U)
#define ADC_GTM_TOM_CHANNELS_PER_TGC       ([!"ecu:get('Gtm.NumberOfChannelsPerTgc')"!]U)
#define ADC_GTM_MAX_TOM_CHANNELS     \
                  (ADC_GTM_NO_OF_TOM_MODULES *  ADC_GTM_CHANNELS_PER_TOM_MODULE)

[!IF "(num:i( ecu:get('Gtm.NumberOfAtomModules')) != num:i(0))"!][!//
#define ADC_GTM_NO_OF_ATOM_MODULES          ([!"ecu:get('Gtm.NumberOfAtomModules')"!]U)
#define ADC_GTM_NO_OF_AGC_PER_MODULE        ([!"ecu:get('Gtm.NumberOfAgcPerAtom')"!]U)
#define ADC_GTM_CHANNELS_PER_ATOM_MODULE    ([!"ecu:get('Gtm.NumberOfAtomChannels')"!]U)
#define ADC_GTM_ATOM_CHANNELS_PER_AGC       ([!"ecu:get('Gtm.NumberOfChannelsPerAgc')"!]U)
#define ADC_GTM_MAX_ATOM_CHANNELS    \
                (ADC_GTM_NO_OF_ATOM_MODULES *  ADC_GTM_CHANNELS_PER_ATOM_MODULE)
[!ENDIF!][!//


/* Generating defines for GTM Global Channel Numbers */ 
[!VAR "TotalCount" = "num:i(ecu:get('Gtm.NumberOfTimChannels') * ecu:get('Gtm.NumberOfTimModules'))"!][!//
[!//
[!FOR "GcnModuleCount" = "0" TO "ecu:get('Gtm.NumberOfTomModules') - 1"!][!//
[!FOR "GcnCount" = "0" TO "ecu:get('Gtm.NumberOfTomChannels') - 1 "!][!//
#define ADC_GTM_TOM[!"num:i($GcnModuleCount)"!]_CHANNEL[!"num:i($GcnCount)"!]   ([!"num:dectoint(num:i($GcnCount) + ($TotalCount))"!]U)
[!ENDFOR!][!//
[!VAR "TotalCount" = "$TotalCount + ecu:get('Gtm.NumberOfTomChannels')"!][!//
[!ENDFOR!][!//
[!//
[!IF "(num:i( ecu:get('Gtm.NumberOfAtomModules')) != num:i(0))"!][!//
[!FOR "GcnModuleCount" = "0" TO "ecu:get('Gtm.NumberOfAtomModules') - 1"!][!//
[!FOR "GcnCount" = "0" TO "ecu:get('Gtm.NumberOfAtomChannels') - 1 "!][!//
#define ADC_GTM_ATOM[!"num:i($GcnModuleCount)"!]_CHANNEL[!"num:i($GcnCount)"!]   ([!"num:dectoint(num:i($GcnCount) + ($TotalCount))"!]U)
[!ENDFOR!][!//
[!VAR "TotalCount" = "$TotalCount + ecu:get('Gtm.NumberOfAtomChannels')"!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

#endif /*(ADC_HW_TRIGGER_API == STD_ON && ADC_TIMER_TRIGG == STD_ON)*/
[!ENDIF!][!//

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
[!IF "(AdcGeneral/AdcNonAutosarResultPolling = 'true')"!][!//
/*ANALOG CHANNEL NUMBER Definition */
/*Macros can be used for Adc_17_GetChannelStatus() api parameter */

[!VAR "AdcAnChNum" = "num:i(0)"!][!//
[!FOR "AdcId" ="num:i(0)" TO "(num:i(ecu:get('Adc.MaxControllers')) - num:i(1))"!][!//
[!FOR "ChannelId" ="num:i(0)" TO "(num:i(ecu:get('Adc.NumOfChInGrp')) - num:i(1))"!][!//
[!IF "contains(ecu:get(concat('Adc.AdcChannels_Adc',$AdcId)), concat('_', num:i($AdcAnChNum), '_'))"!][!//
#define ADC_[!"$AdcId"!]_CH_[!"$ChannelId"!] ([!"num:i($AdcAnChNum)"!]U)
[!ENDIF!][!//
[!VAR "AdcAnChNum"= "num:i($AdcAnChNum) + num:i(1)"!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

/*CHANNEL SYMBOLIC NAME */
[!SELECT "AdcConfigSet/*[1]"!][!//

[!VAR "ChannelId" = "num:i(0)"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
/* ADC[!"num:i($AdcId - num:i(1))"!] HW Unit */
[!LOOP "node:order(./AdcChannel/*, './AdcChannelId')"!]
#ifndef AdcConf_AdcChannel_[!"node:name(.)"!] /* to prevent double declaration */
#define AdcConf_AdcChannel_[!"node:name(.)"!]  ((Adc_ChannelType)[!"AdcChannelId"!])
#endif /* AdcConf_AdcChannel_[!"node:name(.)"!] */
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

/*GROUP SYMBOLIC NAME */
[!VAR "AdcHwTrigApi" = "AdcGeneral/AdcHwTriggerApi"!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//

/* Configuration set [!"$CfgCount"!] */

[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
/* [!"node:name(.)"!] */
[!NOCODE!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC0'"!][!//
[!VAR "GrpID" = "num:i(0)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC1'"!][!//
[!VAR "GrpID" = "num:i(32)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC2'"!][!//
[!VAR "GrpID" = "num:i(64)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC3'"!][!//
[!VAR "GrpID" = "num:i(96)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC4'"!][!//
[!VAR "GrpID" = "num:i(128)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC5'"!][!//
[!VAR "GrpID" = "num:i(160)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC6'"!][!//
[!VAR "GrpID" = "num:i(192)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC7'"!][!//
[!VAR "GrpID" = "num:i(224)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC8'"!][!//
[!VAR "GrpID" = "num:i(256)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC9'"!][!//
[!VAR "GrpID" = "num:i(288)"!][!//
[!ELSEIF "./AdcHwUnitId = 'HWUNIT_ADC10'"!][!//
[!VAR "GrpID" = "num:i(320)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!VAR "AdcReqSrcCount"= "num:i(ecu:get('Adc.ReqSrcCount')) - num:i(1)"!][!//
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!]
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_SW'"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "node:name(.)"!]
[!ENDNOCODE!][!//
 #ifndef AdcConf_AdcGroup_[!"$SymbolicName"!] /* to prevent double declaration */
 #define AdcConf_AdcGroup_[!"$SymbolicName"!]   ((Adc_GroupType)[!"num:i($GrpID)"!])
 #endif /* AdcConf_AdcGroup_[!"$SymbolicName"!] */
[!VAR "GrpID" = "$GrpID + 1"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!//
[!IF "$AdcHwTrigApi = 'true'"!][!//
[!//
[!VAR "AdcReqSrcCount"= "num:i(ecu:get('Adc.ReqSrcCount')) - num:i(1)"!][!//
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!]
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW'"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "node:name(.)"!]
[!ENDNOCODE!][!//
 #ifndef AdcConf_AdcGroup_[!"$SymbolicName"!] /* to prevent double declaration */
 #define AdcConf_AdcGroup_[!"$SymbolicName"!]   ((Adc_GroupType)[!"num:i($GrpID)"!])
 #endif /* AdcConf_AdcGroup_[!"$SymbolicName"!] */
[!VAR "GrpID" = "$GrpID + 1"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!]

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

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /* ADC_CFG_H */
