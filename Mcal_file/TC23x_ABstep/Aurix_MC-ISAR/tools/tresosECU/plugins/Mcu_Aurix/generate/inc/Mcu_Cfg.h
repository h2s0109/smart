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
**  $FILENAME   : Mcu_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\25 $                               **
**                                                                           **
**  $DATE       : 2016-08-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Mcu_Cfg.h file                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=DS_NAS_MCU_PR446,SAS_AS_MCU102,DS_NAS_MCU_PR915,
    DS_AS_MCU016,DS_AS_MCU054,DS_AS_MCU101,DS_AS40X_MCU_PR2849,SAS_AS_MCU168_Conf,
    SAS_AS4XX_MCU_PR678,SAS_NAS_MCU_PR914,SAS_NAS_MCU_PR915,SAS_NAS_MCU_PR916,
  SAS_MCAL_MCU_0442,DS_NAS_MCU_PR115,SAS_AS_MCU013_MCU166_Conf,SAS_AS_MCU167_Conf
  ,DS_NAS_EP_MCU_PR3054_1,DS_NAS_HE2_MCU_PR3054_1,DS_NAS_EP_MCU_PR3054_2,
   DS_NAS_HE2_MCU_PR3054_2,,DS_NAS_EP_MCU_PR3054_3,
   ,DS_NAS_EP_MCU_PR3054_4,DS_NAS_HE2_MCU_PR3054_4]
    [/cover]                                                            */!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Mcu_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\25 $                               **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : MCU configuration generated out of ECU configuration       **
**                 file (Mcu.bmd)                                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

#ifndef MCU_CFG_H
#define MCU_CFG_H

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
/* Autosar version of the module */
#define MCU_AS_VERSION ([!"$NewString"!])



/* AUTOSAR specification version numbers */
[!IF "$MajorVersion = num:i(4)"!][!//
#define MCU_AR_RELEASE_MAJOR_VERSION      ([!"$MajorVersion"!]U)
#define MCU_AR_RELEASE_MINOR_VERSION      ([!"$MinorVersion"!]U)
#define MCU_AR_RELEASE_REVISION_VERSION   ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define MCU_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define MCU_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define MCU_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)

/* CCUCON0 - CLKSEL & UP Bit Mask Valeus */
#define MCU_CCUCON0_CLKSEL_SETMASK            0x10000008U
#define MCU_CCUCON0_UP_SETMASK                0x40000008U
#define MCU_CCUCON0_CLKSEL_SETMASK2           0x00000008U
#define MCU_CCUCON0_UP_SETMASK2               0x00000008U

[!VAR "CrcInstructionModeUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Crc')[1]"!][!//
[!IF "CrcGeneral/Crc32Mode/__1 = 'CRC_32_INSTRUCTION'"!][!//
[!VAR "CrcInstructionModeUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!//

/*
  Requirement key - MCU 121, MCU 037 :
  Module Identification, Vendor Identification
*/


/* MCU module instance ID*/
#define MCU_MODULE_INSTANCE             ((uint8)0)

/* MCU module CCUCON6 Register  ID*/
#define MCU_CCUCONREG_AVAILABILITY_RANGE        ((uint8)0x06U)

/*
              Container : McuGeneralConfiguration
              Multiplicity: 1 -1
*/
                    /* Total no. of config sets */
                    
#define MCU_CONFIG_COUNT   ([!"num:i(count(McuModuleConfiguration/*))"!]U)

/*
   Configuration: MCU_DEV_ERROR_DETECT  MCU118, MCU013, MCU100
   Preprocessor switch for enabling the development error detection and
   reporting.
   ON  : DET is Enabled
   OFF : DET is Disabled
*/
#define MCU_DEV_ERROR_DETECT  ([!//
[!IF "McuGeneralConfiguration/McuDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!//

/*
   Configuration: MCU_VERSION_INFO_API MCU118_Conf , MCU168_Conf
   Preprocessor switch to enable / disable the API to read out the modules
   version information.
   ON  : version info API is enabled
   OFF : version info API is disabled
*/
[!IF "McuGeneralConfiguration/McuVersionInfoApi = 'true'"!][!//

#define MCU_VERSION_INFO_API (STD_ON)
[!ELSE!][!//
#define MCU_VERSION_INFO_API (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_PERFORM_RESET_API  MCU118, MCU055, MCU167
    Preprocessor switch to enable / disable the use of the
    function Mcu_PerformReset()
    ENABLED  : Mcu_PerformReset function is available
    DISABLED : Mcu_PerformReset function is not available
*/
#define  MCU_PERFORM_RESET_API   ([!//
[!IF "McuGeneralConfiguration/McuPerformResetApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
    MCU181_Conf:
    Configuration : MCU_GET_RAM_STATE_API (McuGetRamStateApi)
    Pre-processor switch to enable/disable the API Mcu_GetRamState.
    (If the H/W does not support the functionality, this parameter
    can be used to disable the Api).
    Since this feature is not present in the hardware, it is permanently
    stuck at STD_OFF.
*/
[!IF "McuGeneralConfiguration/McuGetRamStateApi = 'true'"!][!//
#define MCU_GET_RAM_STATE_API (STD_ON)
[!ELSE!][!//
#define  MCU_GET_RAM_STATE_API (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_CLR_COLD_RESET_STAT_API (McuClearColdResetApi)
    Pre-processor switch to enable/disable the API Mcu_ClearColdResetStatus.
*/
[!IF "McuGeneralConfiguration/McuClearColdResetApi = 'true'"!][!//
#define MCU_CLR_COLD_RESET_STAT_API (STD_ON)
[!ELSE!][!//
#define  MCU_CLR_COLD_RESET_STAT_API (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_DEINIT_API (McuDeInitApi)
    Pre-processor switch to enable/disable the API Mcu_DeInit.
*/
[!IF "McuGeneralConfiguration/McuDeInitApi = 'true'"!][!//
#define MCU_DEINIT_API (STD_ON)
[!ELSE!][!//
#define  MCU_DEINIT_API (STD_OFF)
[!ENDIF!][!//

[!IF "(McuGeneralConfiguration/McuRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "McuGeneralConfiguration/McuUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "McuGeneralConfiguration/McuUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "McuGeneralConfiguration/McuUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: McuRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
McuUserModeRuntimeApiEnable, McuUserModeInitApiEnable or McuUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: MCU_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "McuGeneralConfiguration/McuRunningInUser0Mode = 'true'"!][!//
#define MCU_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define MCU_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: MCU_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "McuGeneralConfiguration/McuUserModeInitApiEnable = 'true'"!][!//
#define MCU_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  MCU_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: MCU_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "McuGeneralConfiguration/McuUserModeDeInitApiEnable = 'true'"!][!//
#define MCU_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  MCU_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: MCU_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "McuGeneralConfiguration/McuUserModeRuntimeApiEnable = 'true'"!][!//
#define MCU_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  MCU_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_SAFETY_ENABLE
    Pre-processor switch to enable/disable the MCU driver safety features.
*/
[!IF "McuSafety/McuSafetyEnable = 'true'"!][!//
#define MCU_SAFETY_ENABLE (STD_ON)
[!ELSE!][!//
#define MCU_SAFETY_ENABLE (STD_OFF)
[!ENDIF!][!//

[!IF "McuSafety/McuSafetyEnable = 'true'"!][!//
/*
    Configuration : MCU_INITCHECK_API (McuInitCheckApi)
    Pre-processor switch to enable/disable the API Mcu_InitCheck.
*/
[!IF "McuSafety/McuInitCheckApi = 'true'"!][!//
#define MCU_INITCHECK_API (STD_ON)
[!ELSE!][!//
#define MCU_INITCHECK_API (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_GETMODE_API (McuGetModeApi)
    Pre-processor switch to enable/disable the API Mcu_GetMode.
*/
[!IF "McuSafety/McuGetModeApi = 'true'"!][!//
#define MCU_GETMODE_API (STD_ON)
[!ELSE!][!//
#define MCU_GETMODE_API (STD_OFF)
[!ENDIF!][!//
[!ENDIF!][!//

/*
    Configuration : MCU_FMPLL_ENABLE (McuFmPllEnable)
    Pre-processor switch to enable/disable the PLL frequency modulation.
*/
#define MCU_FMPLL_ENABLE ([!//
[!IF "McuGeneralConfiguration/McuFmPllEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Reset value of PMSWCR0 */
#define MCU_PMSWCR0_DEINIT_VALUE             ((uint32)0x000002D0U)

/*
    Configuration : MCU_ENABLE_CLOCK_MONITORING (McuClockMonitoringEnable)
    Pre-processor switch to enable/disable clock monitoring safety measure.
*/
[!IF "McuSafety/McuSafetyEnable = 'true' and McuSafety/McuClockMonitoringEnable = 'true'"!][!//
#define MCU_ENABLE_CLOCK_MONITORING (STD_ON)
[!ELSE!][!//
#define MCU_ENABLE_CLOCK_MONITORING (STD_OFF)
[!ENDIF!][!//
[!//
[!VAR "ModulePath" = "'McuModuleConfiguration'"!][!//
[!VAR "McuStandbyCtrlApiEnable" = "num:i(0)"!][!//
[!VAR "McuStandbyRampApiEnable" = "num:i(0)"!][!//
[!VAR "McuIRADISDisable" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!VAR "ModeSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuModeSettingConf/*))"!][!//
[!FOR "ModeIndex" = "0" TO "($ModeSettingConfig - 1)"!][!//
[!VAR "McuModeConfig" = "node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuMode"!][!//
[!IF "$McuModeConfig = num:i(2) and (node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuStandbySettingConf/McuRampToBackupFreqApi = 'true')"!][!//
[!VAR "McuStandbyRampApiEnable" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$McuModeConfig = num:i(2) and (node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuStandbySettingConf/McuSetStandbyWakeupControlApi = 'true')"!][!//
[!VAR "McuStandbyCtrlApiEnable" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$McuModeConfig != num:i(2) and (node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuIdleReqAckSeqDisable = 'true')"!][!//
[!VAR "McuIRADISDisable" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
/*
    Configuration : MCU_DISABLE_IRADIS (McuIdleReqAckSeqDisable)
    Pre-processor switch to enable/disable IRADIS bit in PMSWCR1.
*/
[!IF "$McuIRADISDisable = num:i(1)"!][!//
#define MCU_DISABLE_IRADIS (STD_ON)
[!ELSE!][!//
#define MCU_DISABLE_IRADIS (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_RAMP_TO_BACKUP_FREQ_API (McuRampToBackupFreqApi)
    Pre-processor switch to enable/disable the API Mcu_RampToBackUpClockFreq.
*/
[!IF "$McuStandbyRampApiEnable = num:i(1)"!][!//
#define MCU_RAMP_TO_BACKUP_FREQ_API (STD_ON)
[!ELSE!][!//
#define MCU_RAMP_TO_BACKUP_FREQ_API (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : MCU_SET_STANDBY_CONTROL_API (McuSetStandbyWakeupControlApi)
    Pre-processor switch to enable/disable the API Mcu_SetStandbyCtrlReg.
*/
[!IF "$McuStandbyCtrlApiEnable = num:i(1)"!][!//
#define MCU_SET_STANDBY_CONTROL_API (STD_ON)
[!ELSE!][!//
#define MCU_SET_STANDBY_CONTROL_API (STD_OFF)
[!ENDIF!][!//

[!IF "McuGeneralConfiguration/McuInitClock = 'true'"!][!//
/*
    Configuration : MCU_INIT_CLOCK
    Preprocessor switch to enable / disable the use of the
    function Mcu_InitClock()
    ENABLED  : Mcu_InitClock function is available
    DISABLED : Mcu_InitClock function is not available
*/
#define  MCU_INIT_CLOCK (STD_ON)
[!ELSE!][!//
[!ASSERT "McuGeneralConfiguration/McuInitClock = 'true'"!][!//
Config Error : In McuGeneralConfiguration, McuInitClock is set to FALSE. It has to be TRUE.
[!ENDASSERT!]
[!ENDIF!][!//

[!NOCODE!][!//
[!//
[!VAR "TotalMcuConfig" = "num:i(count(McuModuleConfiguration/*))"!][!//
[!/* Determine only one McuModuleConfiguration is configured 
                                        when McuPBFixedAddress = true.*/!]
[!IF "McuGeneral/McuPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalMcuConfig != 1)"!][!//
Config Error: when McuGeneral/McuPBFixedAddress is set as true, [!//
Only one McuModuleConfiguration configuration is allowed. [!//
But McuModuleConfiguration has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "node:exists(McuGeneralConfiguration/McuPBFixedAddress)"!]
/* Configuration : McuPBFixedAddress
   This parameter enables the user to switch ON/OFF the
   PostBuild Fixed Address Feature
*/
#define MCU_PB_FIXEDADDR                ([!//
[!IF "McuGeneralConfiguration/McuPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ELSE!][!//
/* Configuration : McuPBFixedAddress
   This parameter enables the user to switch ON/OFF the
   PostBuild Fixed Address Feature
*/
#define MCU_PB_FIXEDADDR                (STD_OFF)
[!ENDIF!][!//

/*
    Configuration: MCU_MAIN_OSC_FREQ  (MHz)
    This parameter defines external Oscillator frequency in MHz
    This parameter should be configured to the external Oscillator frequency
    value
*/
#define MCU_MAIN_OSC_FREQ  ([!"McuGeneralConfiguration/McuMainOscillatorFrequency"!]U)


[!VAR "FreqToTickConvRatio" = "num:i(2)"!][!//
#define MCU_DELAY_COUNT_DIVIDER   ([!"num:i($FreqToTickConvRatio)"!]U)

/*
    Configuration: MCU_DISABLE_ERAY_PLL
    This parameter defines if ERAY PLL should be enabled/disabled
    ERAY PLL shall be disabled if Oscillator frequency < 16 MHz
*/

#define MCU_DISABLE_ERAY_PLL ([!//
[!IF "(ecu:get('Mcu.fErayPllExists') = 'true') and (McuGeneralConfiguration/McuMainOscillatorFrequency >= 16)"!][!//
STD_OFF[!//
[!ELSE!][!//
STD_ON[!//
[!ENDIF!][!//
)

/*
    Configuration: MCU_BACKUP_FREQ  (MHz)
    This parameter defines back up frequency in MHz
*/
#define MCU_BACKUP_FREQ    ([!"num:i(ecu:get('Mcu.BackUpFrequency') div num:i(1000000))"!]U)

[!NOCODE!][!//
[!VAR "McuOscValReg" = "10*num:i(McuGeneralConfiguration/McuMainOscillatorFrequency) div num:i(25)"!][!//
[!VAR "McuOscValReg" = "num:inttohex(num:i($McuOscValReg) - 1)"!][!//
[!ENDNOCODE!][!//
/* OSC Frequency Value
    This bit field defines the divider value that generates
    the reference clock that is supervised by the
    oscillator watchdog. fOSC is divided by OSCVAL + 1
    in order to generate fOSCREF.
    Equation is OSCVAL = (Fosc/2.5 - 1). Xpath eq. becomes (10*Fosc/25 - 1)*/
#define MCU_OSCVAL_REG_VALUE  ([!"$McuOscValReg"!]U)

/* Master Core for triggering System Modes for controller
 * NA for EP platforms (to avoid compilation error on common source code)
*/
#define MCU_SYSTEM_MODE_CORE            ((uint8)0U)

/* Master Core for triggering Idle Mode for controller
* NA for EP platforms (to avoid compilation error on common source code)
*/
#define MCU_IDLE_MODE_CORE              ((uint8)0U)

/*
              Container: GtmConfiguration
              Multilplicity: 0 -1
*/
    /* Check if GTM is configured */
[!NOCODE!][!//
[!VAR "McuGtmUsed" = "num:i(0)"!][!//
[!VAR "TotalGtmConfig" = "num:i(0)"!][!//
[!VAR "GtmIndex" = "num:i(0)"!][!//
[!VAR "ModulePath" = "'McuModuleConfiguration'"!][!//
[!VAR "TotalMcuModuleConfig" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!FOR "ModuleIndex" = "0" TO " ($TotalMcuModuleConfig - 1)"!][!//
[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/GtmConfiguration/*))"!]
[!VAR "TotalGtmConfig" = "$TotalGtmConfig + $Count"!][!//
[!IF "$Count = num:i(0)"!][!//
[!VAR "GtmIndex" = "$ModuleIndex"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$TotalGtmConfig != num:i(0)"!][!//
[!ASSERT "not(num:i($TotalMcuModuleConfig) != num:i($TotalGtmConfig))"!][!//
Config Error : In McuModuleConfiguration [!"$GtmIndex"!] Gtm is not configured
[!ENDASSERT!]
[!ENDIF!][!//
[!ENDNOCODE!]
#define MCU_GTM_USED ([!//
[!IF "$TotalGtmConfig = num:i(0)"!][!//
STD_OFF[!//
[!ELSE!][!//
STD_ON[!//
[!ENDIF!][!//
)

/* CRC Initialization
   Will be ON if CRC_32_INSTRUCTION is ON in CRC
*/
#define MCU_CRC_HW_USED                 ([!"$CrcInstructionModeUsed"!])
/* 
   Always OFF since FCE Kernel does not exist in EP
*/
/* 8-bit FCE Kernel used */
#define MCU_CRC8_HW_MODE                STD_OFF
/* 16-bit FCE Kernel used */
#define MCU_CRC16_HW_MODE               STD_OFF
/* 32-bit FCE Kernel used */
#define MCU_CRC32_HW_MODE               STD_OFF

[!NOCODE!][!//
[!VAR "DmaHardwareUsed" = "'STD_OFF'"!][!//
[!VAR "ModulePath" = "'McuModuleConfiguration'"!][!//
[!VAR "TotalMcuModuleConfig" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!FOR "ModuleIndex" = "0" TO " ($TotalMcuModuleConfig - 1)"!][!//
[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/DmaConfiguration/*))"!]
[!IF "$Count = num:i(1)"!][!//
[!VAR "DmaHardwareUsed" = "'STD_ON'"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
/* DMA Initialization */
#define MCU_DMA_USED                    ([!"$DmaHardwareUsed"!])

/*
              Container: McuRamSectorSettingConf
              Multiplicity: 1 -*
*/
/*    Configuration  MCU_RAM_SECTORS MCU120_Conf
      This parameter shall represent the number
      of RAM sectors available for the MCU
*/
[!VAR "RamSectors"= "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuRamSectorSettingConf/*))"!]
[!VAR "Total" = "$Count"!][!//
[!IF "$Count > $RamSectors"!][!//
[!VAR "RamSectors" = "$Count"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
#define MCU_RAM_SECTORS     ([!"num:i($RamSectors)"!]U)

/*
              Container: McuModeSettingConf
              Multiplicity: 1 -*
*/
/*
    Configuration Options:
    For MCU power down modes Mcu_ModeType MCU035:
    IDLE Mode: CPU clock is disabled and peripheral clock is running
    as configured
*/
#define MCU_IDLE  ((Mcu_ModeType)(0U))
/*
    Configuration Options:
    For MCU power down modes Mcu_ModeType MCU035:
    SLEEP Mode: CPU clock is disabled and Peripherals go to sleep if
    configured for sleep mode
*/
#define MCU_SLEEP ((Mcu_ModeType)(1U))
/*
    Configuration Options:
    For MCU power down modes Mcu_ModeType MCU035:
    STANDBY Mode: PLL and ERAY_PLL are disabled
*/
#define MCU_STANDBY ((Mcu_ModeType)(2U))
/*
    Maximum number of modes which are configurable is 3
*/
#define MCU_MAX_NO_MODES ((Mcu_ModeType)(3U))

/*
    Configuration: Mode Id
    This id corresponds to the container name of the McuModeSettingConfiguration
    Use this as the parameter for API: Mcu_SetMode
*/
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!VAR "ModeSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuModeSettingConf/*))"!]
[!FOR "ModeIndex" = "0" TO "($ModeSettingConfig - 1)"!][!//
[!VAR "SymbolicName" = "concat('McuConf_McuModeSettingConf_',node:name(node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]))"!]
/* To prevent double declaration */
#ifndef [!"$SymbolicName"!]
#define [!"$SymbolicName"!]  ((Mcu_ModeType)([!"node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuMode"!]U))
#endif
[!ENDFOR!][!//
[!ENDFOR!][!//

/*
    Configuration : MCU_MODE  MCU123_Conf
    This parameter shall represent the different MCU Modes
    available to a MCU .For AURIX the maximum number of modes available are 3
    The parameter is bitwise representation.
    Value = 0(Bit 0)- Used for Idle Mode.If 1 - idle mode can be requested.
    Value = 2(Bit 1)- Used for Sleep Mode.If 1 - sleep mode can be requested.
    Value = 4(Bit 2)- Used for Standby Mode.If 1 -standby mode can be requested.
*/
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!VAR "McuNumberOfModes" = "num:i(0)"!][!//
[!VAR "ModeSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuModeSettingConf/*))"!]
[!FOR "ModeIndex" = "0" TO "($ModeSettingConfig - 1)"!][!//
[!VAR "McuModeConfig" = "node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuMode"!][!//
[!VAR "McuNumberOfModes" = "bit:or($McuNumberOfModes, bit:shl(1,$McuModeConfig))"!][!//
[!ENDFOR!][!//
#define MCU_MODE_MAX[!"$ModuleIndex"!]     ((Mcu_ModeType)([!"num:i($McuNumberOfModes)"!]U))
[!ENDFOR!][!//

/*
              Container: McuClockSettingConfig
              Multiplicity: 1 -*
*/

[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!NOCODE!][!//
[!VAR "ClockSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuClockSettingConfig/*))"!][!//
[!ENDNOCODE!][!//
[!FOR "ClockIndex" = "0" TO "($ClockSettingConfig - 1)"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "concat('McuConf_McuClockSettingConfig_',node:name(node:ref($ModulePath)/*[@index =$ModuleIndex]/McuClockSettingConfig/*[$ClockIndex+1]))"!]
[!ENDNOCODE!][!//
/*To prevent double declaration*/
#ifndef [!"$SymbolicName"!]
#define [!"$SymbolicName"!]  ((Mcu_ClockType)([!"num:i(node:ref($ModulePath)/*[@index =$ModuleIndex]/McuClockSettingConfig/*[$ClockIndex+1]/McuClockSettingId)"!]U))
#endif
[!ENDFOR!][!//
[!ENDFOR!][!//



[!VAR "McuBackupFreq" = "num:i(100)"!][!/*
Fback-up is always 100 MHz
*/!][!VAR "McuPllDelay" = "num:i(McuGeneralConfiguration/McuPllInitDelay)"!][!//
[!VAR "McuPllDelay" = "num:i($McuBackupFreq) * num:i($McuPllDelay) "!][!//
[!VAR "McuPllDelay" = "num:i($McuPllDelay) div num:i($FreqToTickConvRatio)"!][!//

/*  PLL delay ticks calculated as per back up clock Freqeuency (100MHz) */
#define MCU_CONF_DELAY_PLL  ([!"num:i($McuPllDelay)"!]U)

[!VAR "McuErayPllDelay" = "num:i(McuGeneralConfiguration/McuErayPllInitDelay)"!][!//
[!VAR "McuErayPllDelay" = "num:i($McuBackupFreq) * num:i($McuErayPllDelay) "!][!//
[!VAR "McuErayPllDelay" = "num:i($McuErayPllDelay) div num:i($FreqToTickConvRatio)"!][!//

/* ERAY PLL delay ticks calculated as per back up clock Freqeuency (100MHz) */
#define MCU_CONF_DELAY_ERAY_PLL  ([!"num:i($McuErayPllDelay)"!]U)

/*
    Configuration : MCU_NUMBER_OF_CLOCK_SETTINGS MCU124
    This parameter shall represent the number of clock settings
    available for the MCU
*/
[!VAR "ClockSettingConfig"= "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!NOCODE!][!//
[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuClockSettingConfig/*))"!]
[!ENDNOCODE!][!//
[!VAR "Total" = "$Count"!][!//
[!IF "$Count > $ClockSettingConfig"!][!//
[!VAR "ClockSettingConfig" = "$Count"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
#define MCU_NUMBER_OF_CLOCK_SETTINGS ((Mcu_ClockType)([!"num:i($ClockSettingConfig)"!]U))

/*
              Container: McuRamSectorSettingConf
              Multiplicity: 0 -*
*/

[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!NOCODE!][!//
[!VAR "RAMSECTIONID" = "num:i(0)"!][!//
[!VAR "RamSectorSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuRamSectorSettingConf/*))"!][!//
[!ENDNOCODE!][!//
[!IF "$RamSectorSettingConfig>0"!][!//
[!FOR "RAMSectionIndex" = "0" TO "($RamSectorSettingConfig - 1)"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "concat('McuConf_McuRamSectorSettingConf_',node:name(node:ref($ModulePath)/*[@index =$ModuleIndex]/McuRamSectorSettingConf/*[$RAMSectionIndex+1]))"!]
[!ENDNOCODE!][!//
#ifndef [!"$SymbolicName"!]
#define [!"$SymbolicName"!]  ([!"num:i($RAMSECTIONID)"!])
#endif

[!VAR "RAMSECTIONID" = "$RAMSECTIONID + 1"!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

/*
              Container: McuResetReasonConf
              Multiplicity: 1-1
*/
[!VAR "LoopCounter" = "'McuPublishedInformation/McuResetReasonConf'"!][!//
[!LOOP "node:ref($LoopCounter)/*"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "concat('McuConf_McuResetReasonConf_',node:name(.))"!]
[!ENDNOCODE!][!//
#ifndef [!"$SymbolicName"!]
#define [!"$SymbolicName"!]  ([!"num:i(./McuResetReason)"!])
#endif
[!ENDLOOP!][!//

/* Dem reporting enable/disabled macro */
#define MCU_ENABLE_DEM_REPORT  (1U)
#define MCU_DISABLE_DEM_REPORT (0U)

/* DEM enable/disable for Clock Failure */
[!VAR "McuDemReportStatus" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!IF "node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuClockSrcFailureNotification) = 'ENABLED'"!][!//
[!IF "(node:exists(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]) = 'true')"!][!//
[!IF "(node:refexists(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_CLOCK_FAILURE/*[1]) = 'true') and (node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_CLOCK_FAILURE/*[1]) != ' ' )"!][!//
#define MCU_E_CLOCK_FAILURE_DEM_REPORT   (MCU_ENABLE_DEM_REPORT)
#define MCU_E_CLOCK_FAILURE              \
  ((Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_CLOCK_FAILURE/*[1])))"!])[!//
[!ELSE!][!//
[!ERROR "The parameter McuClockSrcFailureNotification is configured as ENABLED but there is no DEM configured inside the container McuDemEventParameterRefs. Configure the DEM"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR "The parameter McuClockSrcFailureNotification is configured as ENABLED but there is no container for McuDemEventParameterRefs"!][!//
[!ENDIF!][!//
[!VAR "McuDemReportStatus" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$McuDemReportStatus = num:i(0)"!][!//
#define MCU_E_CLOCK_FAILURE_DEM_REPORT   (MCU_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!//

[!IF "ecu:get('Mcu.fErayPllExists')='true'"!][!//
/* DEM enable/disable for Eray PLL Timeout */
[!VAR "McuDemReportStatus" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!IF "(node:exists(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]) = 'true')"!][!//
[!IF "(node:refexists(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_ERAY_TIMEOUT/*[1]) = 'true') and (node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_ERAY_TIMEOUT/*[1]) != ' ' )"!][!//
#define MCU_E_ERAY_TIMEOUT_DEM_REPORT    (MCU_ENABLE_DEM_REPORT)
#define MCU_E_ERAY_TIMEOUT                \
  ((Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_ERAY_TIMEOUT/*[1])))"!])[!//
[!VAR "McuDemReportStatus" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$McuDemReportStatus = num:i(0)"!][!//
#define MCU_E_ERAY_TIMEOUT_DEM_REPORT    (MCU_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!ELSE!][!//
#define MCU_E_ERAY_TIMEOUT_DEM_REPORT    (MCU_DISABLE_DEM_REPORT)
[!ENDIF!][!//"ecu:get('Mcu.fErayPllExists')='true'"

/* DEM enable/disable for Oscillator Failure */
[!VAR "McuDemReportStatus" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
[!IF "(node:exists(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]) = 'true')"!][!//
[!IF "(node:refexists(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_OSC_FAILURE/*[1]) = 'true') and (node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_OSC_FAILURE/*[1]) != ' ' )"!][!//
#define MCU_E_OSC_FAILURE_DEM_REPORT    (MCU_ENABLE_DEM_REPORT)
#define MCU_E_OSC_FAILURE               \
  ((Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuDemEventParameterRefs/*[1]/MCU_E_OSC_FAILURE/*[1])))"!])[!//
[!VAR "McuDemReportStatus" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$McuDemReportStatus = num:i(0)"!][!//
#define MCU_E_OSC_FAILURE_DEM_REPORT     (MCU_DISABLE_DEM_REPORT)
[!ENDIF!][!//

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

#endif /* end of MCU_CFG_H */

  /* General Notes
   MCU105:The code file structure shall not be defined within this specification
   completely.At this point it shall be pointed out that the code-file structure
   shall include the following file named:
   Mcu_PBcfg.c – for post build time configurable parameters.
   This file shall contain all  post-build time configurable parameters.

  */
[!ENDSELECT!][!//