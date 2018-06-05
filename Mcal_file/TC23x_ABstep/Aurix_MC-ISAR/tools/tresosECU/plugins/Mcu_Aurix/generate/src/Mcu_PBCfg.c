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
**  $FILENAME   : Mcu_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x\30 $                                       **
**                                                                           **
**  $DATE       : 2016-04-29 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Mcu_PBCfg.c file                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=SAS_NAS_MCU_PR69_PR469,DS_NAS_MCU_PR446,
    SAS_AS_MCU108_MCU211_MCU215_MCU109_MCU111_MCU213,DS_AS_MCU035,DS_AS_MCU031,
    DS_AS_MCU030,SAS_MCAL_MCU_0441,DS_NAS_MCU_PR709,SAS_AS4XX_MCU_PR680,
    DS_AS_MCU130_Conf] [/cover]                            */!][!//
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
**  FILENAME  : Mcu_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x\30 $                                       **
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
**                 file  (Mcu.bmd)                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/

/* Include module header file */
#include "Mcu.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
[!NOCODE!][!//
[!VAR "RelDerivate" = "ecu:get('Rel.Derivate')"!][!//
[!IF "($RelDerivate = '_TRICORE_TC212') or ($RelDerivate = '_TRICORE_TC213') or ($RelDerivate = '_TRICORE_TC214') or ($RelDerivate = '_TRICORE_TC222') or ($RelDerivate = '_TRICORE_TC223') or ($RelDerivate = '_TRICORE_TC224')"!][!//
[!VAR "RelDerivate" = "'TC22x'"!][!//
[!ENDIF!][!//

[!VAR "CpuTickValue1" = "num:i(0)"!][!//
[!VAR "CpuTickValue2" = "num:i(0)"!][!//
[!VAR "CpuTickValue3" = "num:i(0)"!][!//
[!VAR "CpuTickValue4" = "num:i(0)"!][!//
[!VAR "CpuTickValue5" = "num:i(0)"!][!//
[!VAR "CpuTickValue6" = "num:i(0)"!][!//
[!VAR "CpuTickValue7" = "num:i(0)"!][!//
[!VAR "CpuTickValue8" = "num:i(0)"!][!//

[!MACRO "Mcu_AddToCpuTickValue", "PllFreq" = "", "PllFreqArrayIndex" = "", "SRIDiv" = "", "CPU0Div" = ""!][!//
[!IF "num:i($PllFreqArrayIndex) = num:i(1)"!][!//
[!VAR "CpuTickValue1" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(2)"!][!//
[!VAR "CpuTickValue2" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(3)"!][!//
[!VAR "CpuTickValue3" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(4)"!][!//
[!VAR "CpuTickValue4" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(5)"!][!//
[!VAR "CpuTickValue5" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(6)"!][!//
[!VAR "CpuTickValue6" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(7)"!][!//
[!VAR "CpuTickValue7" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ELSEIF "num:i($PllFreqArrayIndex) = num:i(8)"!][!//
[!VAR "CpuTickValue8" = "(num:f($PllFreq) div num:i($SRIDiv))*((num:i(64)-num:i($CPU0Div)) div num:i(64))"!][!//
[!ENDIF!][!//
[!ENDMACRO!]


[!/*
MACRO: Mcu_GetMonitorDivVal 
Macro to derive the Clock Monitor divider value
*/!][!//
[!MACRO "Mcu_GetMonitorDivVal", "FreqInput" = "", "StrValInput" = ""!][!//
[!//
  [!VAR "OutDivVal" = "num:i(0)"!]
  [!IF "(num:i($FreqInput) mod num:i(5000000)) = num:i(0)"!][!//
    [!VAR "OutDivVal" = "(num:i($FreqInput) div num:i(5000000))"!]
  [!ELSEIF "(num:i($FreqInput) mod num:i(6000000)) = num:i(0)"!][!//
    [!VAR "OutDivVal" = "(num:i($FreqInput) div num:i(6000000))"!]
    [!VAR "OutDivVal" = "bit:or($OutDivVal, bit:shl(1,6))"!]
  [!ELSEIF "(num:i($FreqInput) mod num:i(7500000)) = num:i(0)"!][!//
    [!VAR "OutDivVal" = "(num:i($FreqInput) div num:i(7500000))"!]
    [!VAR "OutDivVal" = "bit:or($OutDivVal, bit:shl(3,6))"!]
  [!ELSEIF "num:i(num:i($FreqInput) mod num:i(6666666)) = num:i(0)"!][!//
    [!VAR "OutDivVal" = "(num:i($FreqInput) div num:i(6666666))"!]
    [!VAR "OutDivVal" = "bit:or($OutDivVal, bit:shl(2,6))"!]
  [!ELSE!][!//
  	[!/* get the non zero remainder */!][!//
    [!VAR "OutRemVal" = "(num:i($FreqInput) mod num:i(6666666))"!][!//
    [!/* check if remainder for 6.6MHz is in range of 0-30 */!][!//
    [!IF "num:i($OutRemVal) < num:i(30)"!][!//
      [!VAR "OutDivVal" = "(num:i($FreqInput) div num:i(6666666))"!]
      [!VAR "OutDivVal" = "bit:or($OutDivVal, bit:shl(2,6))"!]
    [!ELSE!][!//
      [!ASSERT "$OutDivVal != num:i(0)"!] ERROR: FreqInput [!"num:i($FreqInput)"!] OutDivVal [!"$OutDivVal"!]  OutDivVal1 [!"$OutDivVal1"!] [!"$StrValInput"!] Frequency monitoring cannot be configured since not a multiple of 5,6,6.6 or 7.5MHz[!//
      [!ENDASSERT!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDMACRO!]

[!/*
MACRO: Mcu_GetBooleanVal 
Macro to derive value from boolean TRUE = 1, FALSE = 0
*/!][!//
[!MACRO "Mcu_GetBooleanVal", "InpVal" = ""!][!//
[!//
[!IF "$InpVal = 'true'"!][!//
  [!VAR "OutVal" = "num:i(1)"!][!//
[!ELSE!][!//
  [!VAR "OutVal" = "num:i(0)"!][!//
[!ENDIF!]
[!ENDMACRO!]

[!/*
MACRO: Mcu_GetEDCONVal 
Macro to derive value from boolean TRUE = 1, FALSE = 0
*/!][!//
[!MACRO "Mcu_GetEDCONVal", "InpVal" = ""!][!//
[!//
[!IF "$InpVal = 'TRIGGER_NONE'"!][!//
  [!VAR "OutVal" = "num:i(0)"!][!//
[!ELSEIF "$InpVal = 'TRIGGER_RISING_EDGE'"!][!//
  [!VAR "OutVal" = "num:i(1)"!][!//
[!ELSEIF "$InpVal = 'TRIGGER_FALLING_EDGE'"!][!//
  [!VAR "OutVal" = "num:i(2)"!][!//
[!ELSEIF "$InpVal = 'TRIGGER_ANY_EDGE'"!][!//
  [!VAR "OutVal" = "num:i(3)"!][!//
[!ENDIF!]
[!ENDMACRO!]
[!ENDNOCODE!][!//

/*
   Configuration Options:
   For the clock setting configuration
   PLL status
*/

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!//
[!NOCODE!][!//
[!VAR "OSCFREQ" = "num:i(McuGeneralConfiguration/McuMainOscillatorFrequency)"!][!//
[!VAR "FBACK" = "num:i(100)"!][!//
[!VAR "McuErayPllDelay" = "num:i(McuGeneralConfiguration/McuErayPllInitDelay)"!][!//
[!VAR "OscFrequency" = "num:i($OSCFREQ * num:i(1000000))"!][!//
[!VAR "ModulePath" = "'McuModuleConfiguration'"!][!//
[!ENDNOCODE!][!//
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!VAR "ModuleIndex" = "num:i(0)"!]
[!VAR "ClockIndex" = "num:i(0)"!]
[!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuClockSettingConfig/*[$ClockIndex+1]/McuClockReferencePoint"!][!//
[!ENDSELECT!][!//
[!//
[!VAR "NormalModeExists" = "0"!][!//
[!VAR "PrescalarModeExists" = "0"!][!//
[!VAR "Counter" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!FOR "ModuleIndexCounter" = "0" TO "(num:i($Counter)- 1)"!][!//
[!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndexCounter]"!][!//
[!NOCODE!][!//
[!VAR "LoopCounter" = "'McuClockSettingConfig'"!][!//
[!ENDNOCODE!][!//
[!LOOP "node:ref($LoopCounter)/*"!][!//
[!IF "./McuClockReferencePoint/McuClockSettingMode = 'NORMAL_MODE'"!][!//
[!VAR "NormalModeExists" = "1"!][!//
[!ENDIF!][!//
[!IF "./McuClockReferencePoint/McuClockSettingMode = 'PRESCALER_MODE'"!][!//
[!VAR "PrescalarModeExists" = "1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!//

[!IF "$NormalModeExists = 1"!][!//
/* Normal Mode */
#define MCU_NORMAL_MODE        (0x01U)
[!ENDIF!][!//
[!IF "$PrescalarModeExists = 1"!][!//
/* Prescaler Mode */
#define MCU_PRESCALER_MODE     (0x00U)
[!ENDIF!][!//
[!//
[!VAR "McuResetSetting1" = "0"!][!//
[!VAR "McuResetSetting2" = "0"!][!//
[!VAR "McuResetSetting3" = "0"!][!//
[!VAR "McuResetSetting4" = "0"!][!//
[!VAR "TotalConfigCounter" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!VAR "McuSafetyEnabled" = "McuSafety/McuSafetyEnable"!][!//
[!VAR "McuClockMonitoringEnabled" = "McuSafety/McuClockMonitoringEnable"!][!//
[!VAR "McuFmPllEnabled" = "McuGeneralConfiguration/McuFmPllEnable"!][!//

/******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Memory Mapping the configuration constant */
#define MCU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*
   Configuration : Mcu_ConfigType
   For Mcu_ConfigType: MCU specific configuration ID
   This id corresponds to the container name of the McuConfiguration.
   Use this as the parameter for API: Mcu_Init
    - MCU035 : Configuration of MCU
*/
/*
                     Container: McuClockSettingConfig
                     Multilplicity : 1 - *
*/

[!NOCODE!][!//
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
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//

[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i($Count)- 1)"!][!//
static const Mcu_ClockCfgType Mcu_kClockConfiguration[!"string($ModuleIndex)"!][] =
{
[!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndex]"!][!//
[!NOCODE!][!//
  [!/* Verify McuMode */!][!//
  [!VAR "LoopVar" = "'McuModeSettingConf'"!][!//
  [!LOOP "node:ref($LoopVar)/*"!][!//
  [!ASSERT "text:uniq(../../McuModeSettingConf/*/McuMode,./McuMode)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Each mode should be unique.Enter 2 for Standby mode, 1 for Sleep Mode and 0 - for Idle Mode.
  [!ENDASSERT!][!//
  [!ENDLOOP!][!//
  [!VAR "LoopVar" = "'McuRamSectorSettingConf'"!][!//
  [!LOOP "node:ref($LoopVar)/*"!][!//
  [!/* Verify McuRamSectionBaseAddress */!][!//
  [!ASSERT "(( McuRamSectionBaseAddress >= ecu:get('Mcu.CPU0DSPRAddStart')) and (McuRamSectionBaseAddress <= ecu:get('Mcu.CPU0DSPRAddEnd'))) or (( McuRamSectionBaseAddress >= ecu:get('Mcu.CPU0PSPRAddStart')) and (McuRamSectionBaseAddress <= ecu:get('Mcu.CPU0PSPRAddEnd'))) or (( McuRamSectionBaseAddress >= ecu:get('Mcu.LMURamAddStart')) and (McuRamSectionBaseAddress <= ecu:get('Mcu.LMURamAddEnd')))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuRamSectionBaseAddress is not in the proper range.
  [!ENDASSERT!][!//
  [!IF "(ecu:get('Mcu.LMURamAddStart') = 0) and (ecu:get('Mcu.LMURamAddEnd') = 0)"!][!//
  [!ASSERT "McuRamSectionBaseAddress < 2415919104"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuRamSectionBaseAddress should not be in the range of 0x90000000 since LMU memory is not present.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuRamSectionSize */!][!//
  [!ASSERT "(((./McuRamSectionBaseAddress >= ecu:get('Mcu.CPU0DSPRAddStart')) and (./McuRamSectionBaseAddress <= ecu:get('Mcu.CPU0DSPRAddEnd'))) and ((McuRamSectionSize + ./McuRamSectionBaseAddress) <= (ecu:get('Mcu.CPU0DSPRAddEnd')+1))) or (((./McuRamSectionBaseAddress >= ecu:get('Mcu.CPU0PSPRAddStart')) and (./McuRamSectionBaseAddress <= ecu:get('Mcu.CPU0PSPRAddEnd'))) and ((McuRamSectionSize + ./McuRamSectionBaseAddress) <= (ecu:get('Mcu.CPU0PSPRAddEnd')+1))) or (((./McuRamSectionBaseAddress >= ecu:get('Mcu.LMURamAddStart')) and (./McuRamSectionBaseAddress <= ecu:get('Mcu.LMURamAddEnd'))) and ((McuRamSectionSize + ./McuRamSectionBaseAddress) <= (ecu:get('Mcu.LMURamAddEnd')+1)))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: The RAM Base Address + Size is crossing the allowed RAM region. Or the McuRamSectionSize is not in valid range of 1 to 188416.
  [!ENDASSERT!][!//
  [!ENDLOOP!][!//
[!VAR "LoopVar" = "'McuClockSettingConfig'"!][!//
[!ENDNOCODE!][!//
[!LOOP "node:ref($LoopVar)/*"!][!//
    /*[!"node:name(.)"!]*/
[!SELECT "McuClockReferencePoint"!][!//
[!NOCODE!][!//
  [!VAR "TempVar" = "num:i(0)"!][!//  
  [!/*Verify Clock parameters for proper range and plausibility check*/!][!//
  [!IF "./McuClockSettingMode = 'NORMAL_MODE'"!][!//
    [!/* Verify McuClockReferencePointFrequency */!][!//
    [!ASSERT "(./McuClockReferencePointFrequency >= ecu:get('Mcu.FpllMinFrequency')) and (./McuClockReferencePointFrequency <= ecu:get('Mcu.FpllMaxFrequency'))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: The parameter McuClockReferencePointFrequency should be in the proper valid range. See description for more details.
    [!ENDASSERT!][!//
    [!VAR "TempVar" = "round(num:i($OscFrequency div (./McuPllPDivider+1)))"!][!//  
    [!ASSERT "($TempVar >= ecu:get('Mcu.FoscByPMinFrequency')) and ($TempVar <= ecu:get('Mcu.FoscByPMaxFrequency'))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: The parameter McuClockReferencePointFrequency i.e. For the Main PLL :Reference Frequency for VCO is not in valid range.Reference Frequeny = McuMainOscillatorFrequency / (McuPllPDivider+1). Try changing the value of McuPllPDivider.
    [!ENDASSERT!][!//
    [!VAR "TempVar" = "round(num:i(($OscFrequency * (./McuPllNDivider+1)) div (./McuPllPDivider+1)))"!][!//  
    [!ASSERT "($TempVar >= ecu:get('Mcu.PllVcoBaseMinFreq')) and ($TempVar <= ecu:get('Mcu.PllVcoBaseMaxFreq'))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: The parameter McuClockReferencePointFrequency i.e. For the Main PLL : VCO input frequency is not in valid range. Vco Input Frequency = McuMainOscillatorFrequency * (McuPllNDivider+1)/(McuPllPDivider+1).Try changing McuPllNDivider and McuPllPDivider.
    [!ENDASSERT!][!//
    [!VAR "TempVar" = "round(num:i(($OscFrequency * (./McuPllNDivider+1)) div ((./McuPllPDivider+1)*(./McuPllK2Divider+1))))"!][!//  
    [!ASSERT "($TempVar = ./McuClockReferencePointFrequency)"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockReferencePointFrequency does not match with the divider values configured in the parameters McuPllPDivider, McuPllNDivider, McuPllK2Divider and McuMainOscillatorFrequency (which is under McuGeneralConfiguration). The formula for calculation is McuClockReferencePointFrequency = (((McuPllNDivider+1)*(McuMainOscillatorFrequency)) / ((McuPllPDivider+1)*(McuPllK2Divider+1))).
    [!ENDASSERT!][!//
    [!/* Verify McuClockReferencePoint2Frequency */!][!//
    [!VAR "TempVar" = "round(num:i(($OscFrequency * (./McuPllNDivider+1)) div ((./McuPllPDivider+1)*(./McuPllK3Divider+1))))"!][!//  
    [!ASSERT "($TempVar = ./McuClockReferencePoint2Frequency)"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockReferencePoint2Frequency does not match with the divider values configured in the parameters McuPllPDivider, McuPllNDivider, McuPllK3Divider and McuMainOscillatorFrequency (which is under McuGeneralConfiguration). The formula for calculation is McuClockReferencePointFrequency = (((McuPllNDivider+1)*(McuMainOscillatorFrequency)) / ((McuPllPDivider+1)*(McuPllK3Divider+1))).
    [!ENDASSERT!][!// 
  [!ENDIF!][!//
  [!IF "./McuClockSettingMode = 'PRESCALER_MODE'"!][!//
    [!/* Verify McuClockReferencePointFrequency */!][!//  
    [!VAR "TempVar" = "round(num:i(($OscFrequency div (./McuPllK1Divider+1))))"!][!//
    [!ASSERT "($TempVar = ./McuClockReferencePointFrequency)"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockReferencePointFrequency does not match with the divider values configured in the parameter McuPllK1Divider and McuMainOscillatorFrequency (which is under McuGeneralConfiguration). The formula for calculation is McuClockReferencePointFrequency = ((McuMainOscillatorFrequency) / (McuPllK1Divider+1)).
    [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuSRIDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.SRIDividerValues'),string(./McuSRIDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuSRIDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//
  [!/* Verify McuClockSRIFrequency */!][!//
  [!VAR "TempVar" = "round(./McuClockReferencePointFrequency div (./McuSRIDivider))"!][!//  
  [!ASSERT "($TempVar = ./McuClockSRIFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockSRIFrequency does not match with the divider value configured in McuSRIDivider.
  [!ENDASSERT!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockSRIFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockSRIFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!/* Verify McuClockCPU0Frequency */!][!//
  [!VAR "TempVar" = "round( ((./McuClockSRIFrequency)*(64 - ./McuCPU0Divider)) div (64))"!][!//  
  [!ASSERT "($TempVar = ./McuClockCPU0Frequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockCPU0Frequency does not match with the divider value configured in McuCPU0Divider.
  [!ENDASSERT!][!//
  [!/* Verify McuSPBDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.SPBDividerValues'),string(./McuSPBDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuSPBDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//  
  [!/* Verify McuClockSPBFrequency */!][!//
  [!ASSERT "(./McuClockSPBFrequency <= ./McuClockReferencePointFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockSPBFrequency should not be greater than McuClockReferencePointFrequency.
  [!ENDASSERT!][!//
  [!ASSERT "(./McuClockSPBFrequency <= ./McuClockBBBFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockSPBFrequency should not be greater than McuClockBBBFrequency.
  [!ENDASSERT!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockSPBFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockSPBFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!VAR "TempVar" = "round( (./McuClockReferencePointFrequency) div (./McuSPBDivider))"!][!//    
  [!ASSERT "($TempVar = ./McuClockSPBFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockSPBFrequency does not match with the divider value configured in McuSPBDivider.
  [!ENDASSERT!][!//
  [!/* Verify McuClockFSIFrequency */!][!//  
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockFSIFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockFSIFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "((./McuFSIDivider != 0) and ((./McuSRIDivider = 1) or (./McuSRIDivider = 2)))"!][!//
  [!ASSERT "./McuClockFSIFrequency = (round((./McuClockSRIFrequency) div (./McuFSIDivider)))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockFSIFrequency does not match with the divider value configured in McuFSIDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!IF "((./McuFSIDivider != 0) and ((./McuSRIDivider != 1) and (./McuSRIDivider != 2)))"!][!//
  [!ASSERT "./McuClockFSIFrequency = ./McuClockSRIFrequency"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: When McuSRIDivider is other than 1 or 2, McuClockFSIFrequency should be equal to McuClockSRIFrequency.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuClockFSI2Frequency */!][!//  
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockFSI2Frequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockFSI2Frequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "((./McuFSI2Divider != 0) and ((./McuSRIDivider = 1) or (./McuSRIDivider = 2)))"!][!//
  [!ASSERT "./McuClockFSI2Frequency = (round((./McuClockSRIFrequency) div (./McuFSI2Divider)))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockFSI2Frequency does not match with the divider value configured in McuFSI2Divider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!IF "((./McuFSI2Divider != 0) and ((./McuSRIDivider != 1) and (./McuSRIDivider != 2)))"!][!//
  [!ASSERT "./McuClockFSI2Frequency = ./McuClockSRIFrequency"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: When McuSRIDivider is other than 1 or 2, McuClockFSI2Frequency should be equal to McuClockSRIFrequency.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuMAXDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.MAXDividervalues'),string(./McuMAXDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuMAXDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockMAXFrequency */!][!//
  [!ASSERT "(./McuClockReferencePointFrequency >= ./McuClockMAXFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockReferencePointFrequency should not be less than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!ASSERT "./McuClockMAXFrequency = (round(./McuClockReferencePointFrequency div ./McuMAXDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency does not match with the divider value configured in McuMAXDivider.
  [!ENDASSERT!][!//
  [!/* Verify McuGTMDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.GTMDividerValues'),string(./McuGTMDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuGTMDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockGTMFrequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockGTMFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockGTMFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuGTMDivider != 0)"!][!//
  [!ASSERT "./McuClockGTMFrequency = (round(./McuClockReferencePointFrequency div ./McuGTMDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockGTMFrequency does not match with the divider value configured in McuGTMDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuSTMDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.STMDividerValues'),string(./McuSTMDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuSTMDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockSTMFrequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockSTMFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockSTMFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuSTMDivider != 0)"!][!//
  [!ASSERT "./McuClockSTMFrequency = (round(./McuClockReferencePointFrequency div ./McuSTMDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockSTMFrequency does not match with the divider value configured in McuSTMDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuBBBDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.BBBDividerValues'),string(./McuBBBDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuBBBDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockBBBFrequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockBBBFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockBBBFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuBBBDivider != 0)"!][!//
  [!ASSERT "./McuClockBBBFrequency = (round(./McuClockReferencePointFrequency div ./McuBBBDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockBBBFrequency does not match with the divider value configured in McuBBBDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!IF "ecu:get('Mcu.fBaud1Exists')='true'"!][!//
    [!/* Verify McuBAUD1Divider */!][!//
    [!ASSERT "text:contains(ecu:list('Mcu.BAUD1DividerValues'),string(./McuBAUD1Divider))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuBAUD1Divider input not valid divider value. Check the description for allowed values.
    [!ENDASSERT!][!//   
    [!/* Verify McuClockBAUD1Frequency */!][!//
    [!ASSERT "(./McuClockMAXFrequency >= ./McuClockBAUD1Frequency)"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockBAUD1Frequency cannot be more than McuClockMAXFrequency.
    [!ENDASSERT!][!//
    [!IF "(./McuBAUD1Divider != 0)"!][!//
    [!ASSERT "./McuClockBAUD1Frequency = (round(./McuClockReferencePointFrequency div ./McuBAUD1Divider))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockBAUD1Frequency does not match with the divider value configured in McuBAUD1Divider.
    [!ENDASSERT!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//    
  [!/* Verify McuBAUD2Divider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.BAUD2DividerValues'),string(./McuBAUD2Divider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuBAUD2Divider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockBAUD2Frequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockBAUD2Frequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockBAUD2Frequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuBAUD2Divider != 0)"!][!//
  [!ASSERT "./McuClockBAUD2Frequency = (round(./McuClockReferencePointFrequency div ./McuBAUD2Divider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockBAUD2Frequency does not match with the divider value configured in McuBAUD2Divider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuCANDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.CANDividerValues'),string(./McuCANDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuCANDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockCANFrequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockCANFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockCANFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuCANDivider != 0)"!][!//
  [!ASSERT "./McuClockCANFrequency = (round(./McuClockReferencePointFrequency div ./McuCANDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockCANFrequency does not match with the divider value configured in McuCANDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuASCLINFDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.ASCLINFDividerValues'),string(./McuASCLINFDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuASCLINFDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockASCLINFFrequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockASCLINFFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockASCLINFFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuASCLINFDivider != 0)"!][!//
  [!ASSERT "./McuClockASCLINFFrequency = (round(./McuClockReferencePointFrequency div ./McuASCLINFDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockASCLINFFrequency does not match with the divider value configured in McuASCLINFDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!/* Verify McuASCLINSDivider */!][!//
  [!ASSERT "text:contains(ecu:list('Mcu.ASCLINSDividerValues'),string(./McuASCLINSDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuASCLINSDivider input not valid divider value. Check the description for allowed values.
  [!ENDASSERT!][!//   
  [!/* Verify McuClockASCLINSFrequency */!][!//
  [!ASSERT "(./McuClockMAXFrequency >= ./McuClockASCLINSFrequency)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockMAXFrequency is the maximum clock frequency, McuClockASCLINSFrequency cannot be more than McuClockMAXFrequency.
  [!ENDASSERT!][!//
  [!IF "(./McuASCLINSDivider != 0)"!][!//
  [!ASSERT "./McuClockASCLINSFrequency = (round(./McuClockReferencePointFrequency div ./McuASCLINSDivider))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockASCLINSFrequency does not match with the divider value configured in McuASCLINSDivider.
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!IF "(ecu:get('Mcu.fErayPllExists')='true') and ($OSCFREQ >= 16 )"!][!//
    [!/* Verify McuClockErayPllFrequency */!][!//
    [!VAR "TempVar" = "round(num:i($OscFrequency div (./McuErayPllPDivider+1)))"!][!//  
    [!ASSERT "($TempVar >= ecu:get('Mcu.ErayFoscByPMinFrequency')) and ($TempVar <= ecu:get('Mcu.ErayFoscByPMaxFrequency'))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: The parameter McuClockErayPllFrequency i.e. For the Eray PLL :Reference Frequency for VCO is not in valid range.Reference Frequeny = McuMainOscillatorFrequency / (McuErayPllPDivider+1). Try changing the value of McuErayPllPDivider.
    [!ENDASSERT!][!//
    [!VAR "TempVar" = "round(num:i(($OscFrequency * (./McuErayPllNDivider+1)) div (./McuErayPllPDivider+1)))"!][!//  
    [!ASSERT "($TempVar >= ecu:get('Mcu.ErayPllVcoBaseMinFreq')) and ($TempVar <= ecu:get('Mcu.ErayPllVcoBaseMaxFreq'))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: The parameter McuClockErayPllFrequency i.e. For the Eray PLL : Eray VCO input frequency is not in valid range. Vco Input Frequency = McuMainOscillatorFrequency* (McuErayPllNDivider+1)/(McuErayPllPDivider+1). Try Changing McuErayPllNDivider and McuErayPllPDivider.
    [!ENDASSERT!][!//
    [!VAR "TempVar" = "round(num:i(($OscFrequency * (./McuErayPllNDivider+1)) div ((./McuErayPllPDivider+1)*(./McuErayPllK2Divider+1))))"!][!//  
    [!ASSERT "($TempVar = ./McuClockErayPllFrequency)"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockErayPllFrequency does not match with the divider values configured in the parameters McuErayPllPDivider, McuErayPllNDivider, McuErayPllK2Divider and McuMainOscillatorFrequency (which is under McuGeneralConfiguration). The formula for calculation is McuClockErayPllFrequency = (((McuErayPllNDivider+1)*(McuMainOscillatorFrequency)) / ((McuErayPllPDivider+1)*(McuErayPllK2Divider+1))).
    [!ENDASSERT!][!//
    [!/* Verify McuClockErayPll2Frequency */!][!//
    [!VAR "TempVar" = "round(num:i(($OscFrequency * (./McuErayPllNDivider+1)) div ((./McuErayPllPDivider+1)*(./McuErayPllK3Divider+1))))"!][!//  
    [!ASSERT "($TempVar = ./McuClockErayPll2Frequency)"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockErayPll2Frequency does not match with the divider values configured in the parameters McuErayPllPDivider, McuErayPllNDivider, McuErayPllK3Divider and McuMainOscillatorFrequency (which is under McuGeneralConfiguration). The formula for calculation is McuClockErayPll2Frequency = (((McuErayPllNDivider+1)*(McuMainOscillatorFrequency)) / ((McuErayPllPDivider+1)*(McuErayPllK3Divider+1))).
    [!ENDASSERT!][!//
    [!/* Verify McuErayDivider */!][!//
    [!ASSERT "text:contains(ecu:list('Mcu.ERAYDividerValues'),string(./McuErayDivider))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuErayDivider input not valid divider value. Check the description for allowed values.
    [!ENDASSERT!][!//    
    [!/* Verify McuClockErayFrequency */!][!//
    [!IF "(./McuErayDivider != 0)"!][!//
    [!ASSERT "./McuClockErayFrequency = (round(./McuClockErayPllFrequency div ./McuErayDivider))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuClockErayFrequency does not match with the divider value configured in McuErayDivider.
    [!ENDASSERT!][!//
    [!ENDIF!][!//
    [!IF "ecu:get('Mcu.fEthExists')='true'"!][!//
    [!/* Verify McuETHDivider */!][!//
    [!ASSERT "text:contains(ecu:list('Mcu.ETHDividerValues'),string(./McuETHDivider))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuETHDivider input not valid divider value. Check the description for allowed values.
    [!ENDASSERT!][!//   
    [!/* Verify McuETHFrequency */!][!//
    [!IF "(./McuETHDivider != 0)"!][!//
    [!ASSERT "./McuETHFrequency = (round(./McuClockErayPllFrequency div (./McuETHDivider * 4)))"!][!//
    Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: McuETHFrequency does not match with the divider value configured in McuETHDivider.
    [!ENDASSERT!][!//
    [!ENDIF!][!//    
    [!ENDIF!][!//  
  [!ENDIF!][!//
  [!/* Verify McuSPBDivider */!][!//
  [!ASSERT "text:contains(ecu:get('Mcu.SRISPBClockRatios'),string(round(McuSPBDivider div (./McuSRIDivider))))"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuSRIDivider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1, 2, 3 and 4.
  [!ENDASSERT!][!//  
  [!ASSERT "text:contains(ecu:get('Mcu.STMSPBClockRatios'),string(round(McuSPBDivider div (./McuSTMDivider)))) or text:contains(ecu:get('Mcu.SPBSTMClockRatios'),string(round((./McuSTMDivider) div McuSPBDivider))) or (./McuSTMDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuSTMDivider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15. STM clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//
  [!ASSERT "text:contains(ecu:get('Mcu.GTMSPBClockRatios'),string(round(McuSPBDivider div (./McuGTMDivider)))) or text:contains(ecu:get('Mcu.SPBGTMClockRatios'),string(round((./McuGTMDivider) div McuSPBDivider))) or (./McuGTMDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuGTMDivider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15.  GTM clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//
  [!IF "ecu:get('Mcu.fBaud1Exists')='true'"!][!//
  [!ASSERT "text:contains(ecu:get('Mcu.BAUD1SPBClockRatios'),string(round(McuSPBDivider div (./McuBAUD1Divider)))) or text:contains(ecu:get('Mcu.SPBBAUD1ClockRatios'),string(round((./McuBAUD1Divider) div McuSPBDivider))) or (./McuBAUD1Divider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuBAUD1Divider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15. BAUD1 clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//  
  [!ENDIF!][!//
  [!ASSERT "text:contains(ecu:get('Mcu.BAUD2SPBClockRatios'),string(round(McuSPBDivider div (./McuBAUD2Divider)))) or text:contains(ecu:get('Mcu.SPBBAUD2ClockRatios'),string(round((./McuBAUD2Divider) div McuSPBDivider))) or (./McuBAUD2Divider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuBAUD2Divider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15.  BAUD2 clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//  
  [!ASSERT "text:contains(ecu:get('Mcu.CANSPBClockRatios'),string(round(McuSPBDivider div (./McuCANDivider)))) or text:contains(ecu:get('Mcu.SPBCANClockRatios'),string(round((./McuCANDivider) div McuSPBDivider))) or (./McuCANDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuCANDivider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15. CAN clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//  
  [!ASSERT "text:contains(ecu:get('Mcu.ASCLINFSPBClockRatios'),string(round(McuSPBDivider div(./McuASCLINFDivider)))) or text:contains(ecu:get('Mcu.SPBASCLINFClockRatios'),string(round((./McuASCLINFDivider) div McuSPBDivider))) or (./McuASCLINFDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuASCLINFDivider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15. ASCLINF clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//  
  [!ASSERT "text:contains(ecu:get('Mcu.ASCLINSSPBClockRatios'),string(round(McuSPBDivider div(./McuASCLINSDivider)))) or text:contains(ecu:get('Mcu.SPBASCLINSClockRatios'),string(round((./McuASCLINSDivider) div McuSPBDivider))) or (./McuASCLINSDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuASCLINSDivider and McuSPBDivider is not within the allowed ratio. Allowed ratios are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15. ASCLINS clock can be faster, slower or equal to SPB clock.
  [!ENDASSERT!][!//
  [!/* Verify McuFSIDivider */!][!//
  [!ASSERT "(text:contains(ecu:get('Mcu.SRIFSIClockRatios'),string(./McuFSIDivider))) or (./McuFSIDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuSRIDivider and McuFSIDivider is not within the allowed ratio. See description for more details.
  [!ENDASSERT!][!//
  [!/* Verify McuFSI2Divider */!][!//
  [!ASSERT "(text:contains(ecu:get('Mcu.SRIFSI2ClockRatios'),string(./McuFSI2Divider))) or (./McuFSI2Divider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuSRIDivider and McuFSI2Divider is not within the allowed ratio. See description for more details.
  [!ENDASSERT!][!//
  [!/* Verify McuBBBDivider */!][!//
  [!ASSERT "text:contains(ecu:get('Mcu.SRIBBBClockRatios'),string(round(McuBBBDivider div (./McuSRIDivider)))) or (./McuBBBDivider = 0)"!][!//
  Config Error in [!"concat($ModulePath,substring-after(node:path(.),$ModulePath))"!]: Clock ratio between McuSRIDivider and McuBBBDivider is not within the allowed ratio. See description for more details.
  [!ENDASSERT!][!//
  [!VAR "ERAYNDIV" = "num:i(0)"!][!//
  [!VAR "ERAYPDIV" = "num:i(0)"!][!//
  [!VAR "ERAYK2DIV" = "num:i(0)"!][!//
  [!VAR "ERAYK3DIV" = "num:i(0)"!][!//   
  [!IF "ecu:get('Mcu.fErayPllExists')='true'"!][!//
    [!VAR "ERAYNDIV" = "num:i(./McuErayPllNDivider)"!][!//
    [!VAR "ERAYPDIV" = "num:i(./McuErayPllPDivider)"!][!//
    [!VAR "ERAYK2DIV" = "num:i(./McuErayPllK2Divider)"!][!//
    [!VAR "ERAYK3DIV" = "num:i(./McuErayPllK3Divider)"!][!//  
  [!ENDIF!][!//
[!ENDNOCODE!][!//
  {
[!/*"Clock Configuration Check"*/!][!//
[!VAR "NDIV" = "num:i(./McuPllNDivider)+1"!][!//
[!VAR "PDIV" = "num:i(./McuPllPDivider)+1"!][!//
[!VAR "K2DIV" = "num:i(./McuPllK2Divider)+1"!][!//
[!VAR "K1DIV" = "num:i(./McuPllK1Divider)+1"!][!//
[!VAR "SRIDIV" = "num:i(./McuSRIDivider)"!][!//
[!VAR "SPBDIV" = "num:i(./McuSPBDivider)"!][!//
[!//
[!VAR "VcoRange" = "num:i(($NDIV * $OSCFREQ)) div num:i($PDIV)"!][!//
[!IF "./McuClockSettingMode = 'NORMAL_MODE'"!][!//
[!VAR "PLL_Clock" = "(num:i($VcoRange)) div (num:i($K2DIV))"!][!//
[!ELSE!][!//
[!VAR "PLL_Clock" = "(num:i($OSCFREQ)) div (num:i($K1DIV))"!][!//
[!ENDIF!][!//
[!IF "./McuClockSettingMode = 'NORMAL_MODE'"!][!//
[!VAR "CPU_Clock" = "(num:i($PLL_Clock)) div (num:i(1))"!][!//
[!VAR "K2DividerSteps" = "num:i(./McuK2DivSteps)"!][!//
[!VAR "CPU_Clock0" = "num:i($FBACK)"!][!//
    {
      /*K2 divider steps*/
[!VAR "PllFreqArrayIndex" = "num:i(0)"!][!//
[!IF "num:i($PLL_Clock) > num:i($CPU_Clock0)"!][!//
[!FOR "K2" = "num:i(127)" TO "num:i($K2DIV)" STEP "num:i(-1)"!][!//
[!VAR "InterFreq1" = "(num:i($VcoRange)) div (num:i($K2)) div (num:i(1))"!][!//
[!IF "num:i($InterFreq1) >= num:i($CPU_Clock0)"!][!//
[!VAR "InterFreq1" = "(num:i($VcoRange)) div (num:i($K2)) div (num:i(1))"!][!//
      [!"num:i($K2 - 1)"!]U, /* [!"round($InterFreq1)"!] MHz */ 
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$InterFreq1"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!]
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "DIFF" = "$PLL_Clock - $InterFreq1 "!][!//
[!IF "num:i($K2DividerSteps)> num:i(0)"!][!//
[!VAR "Step" = "num:i($DIFF) div (num:i($K2DividerSteps)+ num:i(1))"!][!//
[!ENDIF!][!//
[!FOR "K2Steps" = "num:i(1)" TO "num:i($K2DividerSteps)"!][!//
[!VAR "TargetClock" = "num:i($InterFreq1) + (num:i($Step) * num:i($K2Steps))"!][!//
[!FOR "K2" = "num:i(127)" TO "num:i($K2DIV)" STEP "num:i(-1)"!][!//
[!VAR "AchievedFreq" = "(num:i($VcoRange) div num:i($K2)) div (num:i(1))"!][!//
[!IF "num:i($AchievedFreq) > num:i($TargetClock)"!][!//
[!VAR "AchFreq1" = "(num:i($VcoRange) div (num:i($K2))) div (num:i(1))"!][!//
      [!"num:i($K2 - 1)"!]U, /* [!"round($AchFreq1)"!] MHz  */
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$AchFreq1"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!][!//
[!BREAK!][!//
[!ELSEIF "num:i($AchievedFreq) = num:i($TargetClock)"!][!//
[!VAR "AchFreq1" = "(num:i($VcoRange) div num:i($K2)) div (num:i(1))"!][!//
      [!"num:i($K2 - 1)"!]U, /* [!"round($AchFreq1)"!] MHz  */
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$AchFreq1"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
      [!"num:i($K2DIV - 1)"!]U,  /* [!"($CPU_Clock) "!] MHz */ 
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$CPU_Clock"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!][!//
      [!VAR "K2StepsCounter" = "num:i(0)"!][!//      
      [!FOR "K2StepsCounter" = "num:i(1)" TO "num:i(8) - (num:i($K2DividerSteps)+num:i(2))"!][!//
      0U,
      [!ENDFOR!][!//
[!ELSE!][!//
[!FOR "K2" = "num:i(1)" TO "num:i($K2DIV)" STEP "num:i(1)"!][!//
[!VAR "InterFreq1" = "(num:i($VcoRange)) div (num:i($K2)) div (num:i(1))"!][!//
[!IF "num:i($InterFreq1) <= num:i($CPU_Clock0)"!][!//
[!VAR "InterFreq1" = "(num:i($VcoRange)) div (num:i($K2)) div (num:i(1))"!][!//
      [!"num:i($K2 - 1)"!]U, /* [!"round($InterFreq1)"!] MHz */
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$InterFreq1"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!]
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "DIFF" = "$InterFreq1 - $PLL_Clock"!][!//
[!IF "num:i($K2DividerSteps)> num:i(0)"!][!//
[!VAR "Step" = "num:i($DIFF) div (num:i($K2DividerSteps)+ num:i(1))"!][!//
[!ENDIF!][!//
[!FOR "K2Steps" = "num:i(1)" TO "num:i($K2DividerSteps)"!][!//
[!VAR "TargetClock" = "num:i($InterFreq1) - (num:i($Step) * num:i($K2Steps))"!][!//
[!FOR "K2" = "num:i(1)" TO "num:i($K2DIV)" STEP "num:i(1)"!][!//
[!VAR "AchievedFreq" = "(num:i($VcoRange) div num:i($K2)) div (num:i(1))"!][!//
[!IF "num:i($AchievedFreq) < num:i($TargetClock)"!][!//
[!VAR "AchFreq1" = "(num:i($VcoRange) div (num:i($K2))) div (num:i(1))"!][!//
      [!"num:i($K2 - 1)"!]U, /* [!"round($AchFreq1)"!] MHz */
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$AchFreq1"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!][!//
[!BREAK!][!//
[!ELSEIF "num:i($AchievedFreq) = num:i($TargetClock)"!][!//
[!VAR "AchFreq1" = "(num:i($VcoRange) div num:i($K2)) div (num:i(1))"!][!//
      [!"num:i($K2 - 1)"!]U, /* [!"round($AchFreq1)"!] MHz Step */
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$AchFreq1"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
      [!"num:i($K2DIV - 1)"!]U,  /* [!"($CPU_Clock) "!] MHz Step */
      [!VAR "PllFreqArrayIndex" = "num:i($PllFreqArrayIndex) + num:i(1)"!][!//
      [!VAR "PllFreq" = "$CPU_Clock"!][!//
      [!CALL "Mcu_AddToCpuTickValue","PllFreq" = "$PllFreq","PllFreqArrayIndex" = "$PllFreqArrayIndex","SRIDiv" = "./McuSRIDivider","CPU0Div" = "./McuCPU0Divider"!][!//
      [!VAR "K2StepsCounter" = "num:i(0)"!][!//      
      [!FOR "K2StepsCounter" = "num:i(1)" TO "num:i(8) - (num:i($K2DividerSteps)+num:i(2))"!][!//
      0U,
      [!ENDFOR!][!//
[!ENDIF!][!//      
    },
[!ELSE!][!// ./McuClockSettingMode = 'NORMAL_MODE
    {
    	/* Configured in PRESCALAR mode */
     0U,
     0U,
     0U,
     0U,
     0U,
     0U,
     0U,
     0U
    },
[!ENDIF!][!//
    {
 [!VAR "K2DivCount" = "num:i(0) "!][!//
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue1) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U,  /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue2) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue3) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue4) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue5) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue6) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue7) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue8) * num:f(./McuK2DivRampToPllConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp up delay for K2 div step [!"num:i($K2DivCount)"!]*/
    },
[!IF "$McuStandbyRampApiEnable = num:i(1)"!][!//
    {
 [!VAR "K2DivCount" = "num:i(0) "!][!//

[!VAR "TempCpuTickValue" = "num:i($CpuTickValue1) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:i($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue2) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue3) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue4) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue5) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue6) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue7) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
[!VAR "TempCpuTickValue" = "num:f($CpuTickValue8) * num:i(./McuK2DivRampToBackUpConfDelay)"!][!//
[!VAR "TempCpuTickValue" = "num:f($TempCpuTickValue) div num:i(2)"!][!//
      [!VAR "K2DivCount" = "num:i($K2DivCount) + num:i(1)"!][!//
      [!"num:i($TempCpuTickValue)"!]U, /* ramp down delay for K2 div step [!"num:i($K2DivCount)"!]*/
    },
[!ENDIF!][!//
[!/* Clearing the variables after usage */!]
[!VAR "CpuTickValue1" = "num:i(0)"!][!//
[!VAR "CpuTickValue2" = "num:i(0)"!][!//
[!VAR "CpuTickValue3" = "num:i(0)"!][!//
[!VAR "CpuTickValue4" = "num:i(0)"!][!//
[!VAR "CpuTickValue5" = "num:i(0)"!][!//
[!VAR "CpuTickValue6" = "num:i(0)"!][!//
[!VAR "CpuTickValue7" = "num:i(0)"!][!//
[!VAR "CpuTickValue8" = "num:i(0)"!][!//
    {
      [!"num:i(./McuPllK1Divider)"!]U,                              /* K1DIV */
      [!"num:i(./McuPllK3Divider)"!]U,                              /* K3DIV */
      [!"num:i(./McuPllNDivider)"!]U,                             /* NDIV */
      [!"num:i(./McuPllPDivider)"!]U,                              /* PDIV */
      [!"num:i(./McuK2DivSteps)"!]U,                              /* K2DivSteps */
      MCU_[!"./McuClockSettingMode"!],                 /* NORMAL/PRESCALER MODE */
      [!"num:i(0)"!]U                               /* reserved */
    },[!//

[!IF "(ecu:get('Mcu.fErayPllExists')='true') and ($OSCFREQ >= 16)"!][!//
  [!/* Eray_PLL configuration */!][!//
    {
      [!"num:i($ERAYNDIV)"!]U,                             /* PLL ERAY N divider */
      [!"num:i($ERAYK2DIV)"!]U,                              /* PLL ERAY K2 divider */
      [!"num:i($ERAYK3DIV)"!]U,                              /* PLL ERAY K3 divider */
      [!"num:i($ERAYPDIV)"!]U,                              /* PLL ERAY P Divider */
      [!"num:i(0)"!]U                               /* reserved */
    },
[!ENDIF!][!//ecu:get('Mcu.fErayPllExists')='true'
[!//
[!NOCODE!][!//
  [!VAR "CCUCon0Value" = "num:i(0)"!][!//
  [!IF "ecu:get('Mcu.fBaud1Exists')='true'"!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(./McuBAUD1Divider,0))"!][!//
  [!ENDIF!][!//    
  [!IF "$RelDerivate = 'TC22x'"!][!//
  [!VAR "CCUCon0Value" = "bit:bitset($CCUCon0Value, 3)"!][!//
  [!ENDIF!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(./McuBAUD2Divider,4))"!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(./McuSRIDivider,8))"!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(./McuSPBDivider,16))"!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(./McuFSI2Divider,20))"!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(./McuFSIDivider,24))"!][!//
  [!VAR "CCUCon0Value" = "bit:or($CCUCon0Value,bit:shl(1,3))"!][!//Bit 3 is reserved and should be written with 1
  
  [!VAR "CCUCon1Value" = "num:i(0)"!][!//
  [!IF "$RelDerivate = 'TC22x'"!][!//
  [!VAR "CCUCon1Value" = "bit:bitset($CCUCon1Value, 4)"!][!//
  [!ENDIF!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(./McuCANDivider,0))"!][!//
  [!IF "ecu:get('Mcu.fErayPllExists')='true'"!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(./McuErayDivider,4))"!][!//
  [!ENDIF!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(./McuSTMDivider,8))"!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(./McuGTMDivider,12))"!][!//
  [!IF "ecu:get('Mcu.fEthExists')='true'"!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(num:i(./McuETHDivider),16))"!][!//
  [!ENDIF!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(./McuASCLINFDivider,20))"!][!//
  [!VAR "CCUCon1Value" = "bit:or($CCUCon1Value,bit:shl(./McuASCLINSDivider,24))"!][!//
  
  [!VAR "CCUCon5Value" = "./McuMAXDivider"!][!//
  [!VAR "CCUCon5Value" = "bit:and($CCUCon5Value,num:hextoint('0x0000000F'))"!][!//
  [!VAR "CCUCon5Value" = "bit:or($CCUCon5Value,bit:shl(num:i(1),6))"!][!//
  [!VAR "CCUCon3Value" = "num:i(0)"!][!//
  [!VAR "CCUCon4Value" = "num:i(0)"!][!//
  [!IF "($McuSafetyEnabled = 'true') and ($McuClockMonitoringEnabled = 'true')"!][!//
  [!/* Clock Monitor configuration */!][!//
  [!/* CCUCon3 configuration */!][!//
    [!/* Get PLL monitor configuration */!]
    [!CALL "Mcu_GetMonitorDivVal","FreqInput" = "./McuClockReferencePointFrequency","StrValInput" = "'PLL'"!][!//
    [!VAR "PLLMonDiv" = "num:i($OutDivVal)"!][!//
    [!IF "ecu:get('Mcu.fErayPllExists')='true'"!][!//
    [!/* Get PLL_ERAY monitor configuration */!]
    [!CALL "Mcu_GetMonitorDivVal","FreqInput" = "./McuClockErayPllFrequency","StrValInput" = "'PLL_ERAY'"!][!//
    [!VAR "PLLErayMonDiv" = "num:i($OutDivVal)"!][!//
    [!ELSE!][!//
    [!VAR "PLLErayMonDiv" = "num:i(0)"!][!//
    [!ENDIF!][!//
    [!/* Get SRI monitor configuration */!]
    [!CALL "Mcu_GetMonitorDivVal","FreqInput" = "./McuClockSRIFrequency","StrValInput" = "'SRI'"!][!//
    [!VAR "SRIMonDiv" = "num:i($OutDivVal)"!][!//
  [!VAR "CCUCon3Value" = "bit:or($CCUCon3Value,bit:shl($PLLMonDiv,0))"!][!//
  [!VAR "CCUCon3Value" = "bit:or($CCUCon3Value,bit:shl($PLLErayMonDiv,8))"!][!//
  [!VAR "CCUCon3Value" = "bit:or($CCUCon3Value,bit:shl($SRIMonDiv,16))"!][!//
  [!/* CCUCon4 configuration */!][!//
    [!/* Get SPB configuration */!]
    [!CALL "Mcu_GetMonitorDivVal","FreqInput" = "./McuClockSPBFrequency","StrValInput" = "'SPB'"!][!//
    [!VAR "SPBMonDiv" = "num:i($OutDivVal)"!][!//
    [!/* Get GTM monitor configuration */!]
    [!CALL "Mcu_GetMonitorDivVal","FreqInput" = "./McuClockGTMFrequency","StrValInput" = "'GTM'"!][!//
    [!VAR "GTMMonDiv" = "num:i($OutDivVal)"!][!//
    [!/* Get STM monitor configuration */!]
    [!CALL "Mcu_GetMonitorDivVal","FreqInput" = "./McuClockSTMFrequency","StrValInput" = "'STM'"!][!//
    [!VAR "STMMonDiv" = "num:i($OutDivVal)"!][!//
  [!VAR "CCUCon4Value" = "bit:or($CCUCon4Value,bit:shl($SPBMonDiv,0))"!][!//
  [!VAR "CCUCon4Value" = "bit:or($CCUCon4Value,bit:shl($GTMMonDiv,8))"!][!//
  [!VAR "CCUCon4Value" = "bit:or($CCUCon4Value,bit:shl($STMMonDiv,16))"!][!// 
  [!ENDIF!][!//IF "($McuSafetyEnabled = 'true') and ($McuClockMonitoringEnabled = 'true')
[!ENDNOCODE!][!//    
    /*
  [!IF "./McuClockSettingMode = 'NORMAL_MODE'"!]
      SRI Clock     = [!"($PLL_Clock) div (num:i($SRIDIV))"!]MHz
      SPB Clock     = [!"($PLL_Clock) div (num:i($SPBDIV))"!]MHz
  [!ELSE!][!//
      SRI Clock     = [!"(num:i($OSCFREQ) div num:i($K1DIV)) div (num:i($SRIDIV))"!]MHz
      SPB Clock     = [!"(num:i($OSCFREQ) div num:i($K1DIV)) div (num:i($SPBDIV))"!]MHz
  [!ENDIF!][!//
  */
    (uint32)[!"num:inttohex(bit:and($CCUCon0Value,num:hextoint('0x0F3F0FF8')),8)"!]U,/* CCUCON0 Register Configuration*/
    (uint32)[!"num:inttohex(bit:and($CCUCon1Value,num:hextoint('0x0FFFFFFF')),8)"!]U,/* CCUCON1 Register Configuration*/
    (uint32)[!"num:inttohex(bit:and(./McuBBBDivider,num:hextoint('0x0000000F')),8)"!]U,/* CCUCON2 Register Configuration*/
    (uint32)[!"num:inttohex($CCUCon5Value,8)"!]U,/* CCUCON5 Register Configuration*/
    (uint32)[!"num:inttohex(bit:and(./McuCPU0Divider,num:hextoint('0x0000003F')),8)"!]U,/* CCUCON6 Register Configuration*/
    (uint32)0x00000000U,/* Dummy value, CCUCON7 doesn't exist in this variant*/
    (uint32)0x00000000U,[!IF "$McuSafetyEnabled = 'true' or $McuFmPllEnabled = 'true'"!][!ENDIF!] /* Dummy value, CCUCON8 register doesn't 
                                                       exist in this variant */
    [!IF "($McuSafetyEnabled = 'true') and ($McuClockMonitoringEnabled = 'true')"!][!//
    /* Clock Monitoring configuration */
    [!"num:inttohex(bit:and($CCUCon3Value,num:hextoint('0x00FFFFFF')),8)"!]U, /* CCUCON3 Register Configuration*/
    [!"num:inttohex(bit:and($CCUCon4Value,num:hextoint('0x00FFFFFF')),8)"!]U,[!IF "$McuFmPllEnabled = 'true'"!][!ENDIF!]  /* CCUCON4 Register Configuration*/
    [!ENDIF!][!//IF "($McuSafetyEnabled = 'true') and ($McuClockMonitoringEnabled = 'true')"
    [!IF "$McuFmPllEnabled = 'true'"!][!//
    [!NOCODE!][!//
    [!VAR "McuTemp" = "num:i($OSCFREQ) * num:i(64) * num:i(./McuPllNDivider + 1)"!][!//
    [!VAR "McuTemp" = "num:f($McuTemp) div (num:f(100) * num:f(3.6) * num:f(./McuPllPDivider + 1))"!][!//
    [!VAR "McuModulationAmplitude" = "num:f(./McuFMPllModAmp) * num:f($McuTemp)"!][!//        
    /* MCU PLL Modulation Configuration */   
    [!VAR "McuMODCFG_15_10" = "ecu:get('Mcu.PllModulationConfiguration')"!][!//
    [!VAR "McuMODCFG" ="num:inttohex(bit:or((bit:shl($McuMODCFG_15_10,10)),num:i($McuModulationAmplitude)),8)"!][!//  
    [!ENDNOCODE!][!//
    [!"$McuMODCFG"!]U, /* PLLCON2 register configuration for FM PLL */
    [!ENDIF!][!//
  [!"num:i(./McuK2DivRampToPllConfDelay)"!]U, /* Ramp to PLL delay configured in us */
  [!ENDSELECT!]
  }[!IF "not(node:islast())"!],[!ENDIF!]/*[!"node:name(.)"!]*/

[!ENDLOOP!][!//
[!ENDSELECT!][!//
};
[!ENDFOR!][!//

[!FOR "ModuleIndex" = "0" TO "(num:i($Count)- 1)"!][!//
[!IF "num:i(count(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuRamSectorSettingConf/*)) > 0"!][!//
/* Ptr to RAM Section in config structure */
/*
    Container: McuRamSectorSettingConf
    Multiplicity: 1 - *

*/
/*
    Configuration: RAM Section Id
    This id corresponds to the container name of the McuRAMSettingConfiguration.
    Use this as the parameter for API: Mcu_InitRamSection
    MCU030 : Definition of RAM section
*/

static const Mcu_RamCfgType Mcu_kRamConfiguration[!"string($ModuleIndex)"!][] =
{
[!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndex]"!][!//
[!NOCODE!][!//
[!VAR "LoopVar" = "'McuRamSectorSettingConf'"!][!//
[!ENDNOCODE!][!//
[!LOOP "node:ref($LoopVar)/*"!][!//
  {
    /* RAM Section Configuration: [!"node:name(.)"!] */
    /* IFX_MISRA_RULE_11_01_STATUS=Cast from unsigned int to pointer, this is
       required to assign the ram base address to local variable to access
       ram memory.*/    
    (Mcu_RamBaseAdrType)[!"num:inttohex(./McuRamSectionBaseAddress)"!]U, /* RAM section base address */

    (Mcu_RamSizeType)[!"num:inttohex(./McuRamSectionSize)"!],        /* RAM section size */
    
    (Mcu_RamPrstDatType)[!"num:inttohex(./McuRamDefaultValue)"!]        /* Default Value */
    
  }[!IF "not(node:islast())"!],[!ENDIF!]

[!ENDLOOP!][!//
[!ENDSELECT!][!//
};
[!ENDIF!][!//
[!ENDFOR!][!//

[!FOR "ModuleIndex" = "0" TO "(num:i($Count)- 1)"!][!//
[!VAR "McuModeIndex" = "num:i(0)"!][!//
[!VAR "McuStandbyModeEnable" = "num:i(0)"!][!//
[!NOCODE!][!//
[!VAR "ModeSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuModeSettingConf/*))"!]
[!FOR "ModeIndex" = "0" TO "($ModeSettingConfig - 1)"!][!//
[!VAR "McuModeConfig" = "node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuMode"!][!//
[!IF "$McuModeConfig = num:i(2)"!][!//
[!VAR "McuStandbyModeEnable" = "num:i(1)"!][!//
[!VAR "McuModeIndex" = "num:i($ModeIndex)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
  [!IF "$McuStandbyModeEnable = num:i(1)"!][!//
    [!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuModeSettingConf/*[$McuModeIndex+1]/McuStandbySettingConf"!][!//
    [!/* Calculate  PMSWCR0 register value */!][!//
    [!VAR "OutVal" = "num:i(0)"!][!//
    [!VAR "PMSWCR0Value" = "num:i(0)"!][!//
    [!IF "./McuESR1WakeUpEnable = 'true'"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl(1,1))"!][!//
    [!CALL "Mcu_GetBooleanVal","InpVal" = "./McuESR1DigitalFilterEnable"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,7))"!][!//
    [!CALL "Mcu_GetEDCONVal","InpVal" = "./McuESR1EdgeDetection"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,8))"!][!//
    [!ENDIF!][!//
    [!IF "./McuPinAWakeUpEnable = 'true'"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl(1,2))"!][!//
    [!CALL "Mcu_GetBooleanVal","InpVal" = "./McuPinADigitalFilterEnable"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,10))"!][!//
    [!CALL "Mcu_GetEDCONVal","InpVal" = "./McuPinAEdgeDetection"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,11))"!][!//
    [!ENDIF!][!//
    [!IF "./McuPinBWakeUpEnable = 'true'"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl(1,3))"!][!//
    [!CALL "Mcu_GetBooleanVal","InpVal" = "./McuPinBDigitalFilterEnable"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,13))"!][!//
    [!CALL "Mcu_GetEDCONVal","InpVal" = "./McuPinBEdgeDetection"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,14))"!][!//
    [!ENDIF!][!//
    [!CALL "Mcu_GetBooleanVal","InpVal" = "./McuPORSTDigitalFilterEnable"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,23))"!][!//
    [!CALL "Mcu_GetBooleanVal","InpVal" = "./McuESR0TristateEnable"!][!//
    [!VAR "PMSWCR0Value" = "bit:or($PMSWCR0Value,bit:shl($OutVal,29))"!][!//
    [!ENDSELECT!][!//
  [!ENDIF!][!//
[!ENDNOCODE!][!//
[!AUTOSPACING!][!//
[!IF "$McuStandbyModeEnable = num:i(1)"!][!//
[!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuModeSettingConf/*[$McuModeIndex+1]/McuStandbySettingConf"!][!//
/* Standby Mode config structure for Mode Configuration:
 * [!"substring-before((substring-after(node:path(.),concat($ModulePath,'/'))),'/McuStandbySettingConf')"!] 
 */
static const Mcu_StandbyModeType Mcu_kStandbyModeConf[!"string($ModuleIndex)"!] = 
{
  /* PMSWCR0 Register value */
  [!"num:inttohex($PMSWCR0Value)"!]U,
  /* RAR Crc Check */
  [!IF "./McuRARCrcCheckEnable = 'true'"!][!//
  (uint8)TRUE,
  [!ELSE!][!//
  (uint8)FALSE,
  [!ENDIF!][!//
};

[!ENDSELECT!][!//
[!ENDIF!][!//$McuStandbyModeEnable = num:i(1)
[!ENDFOR!][!//
[!//
/* Main MCU Configuration Structure */
[!VAR "TotalConfig" = "num:i(count(node:ref($ModulePath)/*))"!][!//
const Mcu_ConfigType Mcu_ConfigRoot[[!"string(num:i($TotalConfig))"!]] =
{
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($ModulePath)/*))- 1)"!][!//
  {
    /*[!"node:name(node:ref($ModulePath)/*[$ModuleIndex+1])"!]*/
    
    [!IF "$McuSafetyEnabled = 'true'"!][!//
    [!NOCODE!][!//
    [!VAR "Marker" = "num:i(0)"!][!//
    [!VAR "ModuleId" = "num:i(101)"!][!//
    [!VAR "Marker" = "num:inttohex(bit:or($Marker,bit:shl($ModuleId,16)))"!][!//
    [!ENDNOCODE!][!//   
    /* Safety Marker */    
    [!"$Marker"!]U,
    [!ENDIF!][!//
    /*Mcu Clock Configuration*/
[!AUTOSPACING!][!//
    Mcu_kClockConfiguration[!"string($ModuleIndex)"!],
[!AUTOSPACING!][!//
[!IF "num:i(count(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuRamSectorSettingConf/*)) > 0"!][!//
    /*Mcu Ram Configuration*/
    Mcu_kRamConfiguration[!"string($ModuleIndex)"!],
[!ELSE!][!//
    #if (MCU_RAM_SECTORS != 0U)
    /*Mcu Ram Configuration is NULL_PTR as there is nothing configured here */
    NULL_PTR,
    #endif /* #if (MCU_RAM_SECTORS != 0U) */
[!ENDIF!][!//
[!AUTOSPACING!][!//
[!IF "num:i(num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/GtmConfiguration/*))) >= num:i(1)"!][!//
    /*Ptr to Gtm_ConfigRoot*/
    &Gtm_ConfigRoot[[!"$ModuleIndex"!]],
[!ENDIF!][!//
[!AUTOSPACING!][!//
    /* Reset request configuration  */
[!NOCODE!][!//
[!VAR "McuArstdisVal" = "num:i(0)"!][!//
[!IF "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuStm0ResetDisable = 'true'"!][!//
[!VAR "McuArstdisVal" = "bit:or($McuArstdisVal,bit:shl(1,0))"!][!//
[!ENDIF!][!//
[!VAR "McuRstconVal" = "num:i(0)"!][!//
[!VAR "McuTempVal" = "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuTriggerReset/ESR0ResetTrigger"!][!//
[!VAR "McuRstconVal" = "bit:or($McuRstconVal,bit:shl($McuTempVal,0))"!][!//
[!VAR "McuTempVal" = "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuTriggerReset/ESR1ResetTrigger"!][!//
[!VAR "McuRstconVal" = "bit:or($McuRstconVal,bit:shl($McuTempVal,2))"!][!//
[!VAR "McuTempVal" = "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuTriggerReset/SMUResetTrigger"!][!//
[!VAR "McuRstconVal" = "bit:or($McuRstconVal,bit:shl($McuTempVal,6))"!][!//
[!VAR "McuTempVal" = "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuResetSetting"!][!//
[!VAR "McuRstconVal" = "bit:or($McuRstconVal,bit:shl($McuTempVal,8))"!][!//
[!VAR "McuTempVal" = "node:ref($ModulePath)/*[@index = $ModuleIndex]/McuTriggerReset/STM0ResetTrigger"!][!//
[!VAR "McuRstconVal" = "bit:or($McuRstconVal,bit:shl($McuTempVal,10))"!][!//
[!VAR "McuResetCfgVal" = "num:i($McuRstconVal)"!][!//
[!VAR "McuResetCfgVal" = "bit:or($McuResetCfgVal,bit:shl($McuArstdisVal,16))"!][!//
[!ENDNOCODE!][!//
    /* 
     * Upper 16-bits contain ARSTDIS register configuration value, 
     * lower 16-bits contain RSTCON register configuration value
     */
    [!"num:inttohex($McuResetCfgVal)"!]U,
[!AUTOSPACING!][!//
    /* Total number of Clock settings */
[!NOCODE!][!//
[!VAR "ClkSetting" = "num:i(count(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuClockSettingConfig/*))"!][!//
[!FOR "ClockSettingIndex" = "0" TO "(num:i($ClkSetting)- 1)"!][!//
  [!ASSERT "$ClockSettingIndex = num:i(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuClockSettingConfig/*[@index = $ClockSettingIndex]/McuClockSettingId)"!][!//
  Config Error: The parameter McuClockSettingId in Mcu/McuModuleConfiguration/[!"node:name(node:ref($ModulePath)/*[@index = $ModuleIndex])"!] should be unique for every instance of McuClockSettingConfig . McuClockSettingId has a range 0-255. It should be incremental starting from 0 and without any gaps in between.
  [!ENDASSERT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
    ((Mcu_ClockType)[!"num:i($ClkSetting)"!]U),
    /* Total number of RAM Sectors */
    ((Mcu_RamSectionType)[!"num:i(count(node:ref($ModulePath)/*[@index = $ModuleIndex]/McuRamSectorSettingConf/*))"!]U),
    /* The maximum mode that is supported by this module instance */
    (MCU_MODE_MAX[!"$ModuleIndex"!]),
[!NOCODE!][!//
[!VAR "McuModeIndex" = "num:i(0)"!][!//
[!VAR "McuStandbyModeEnable" = "num:i(0)"!][!//
[!VAR "ModeSettingConfig" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/McuModeSettingConf/*))"!]
[!FOR "ModeIndex" = "0" TO "($ModeSettingConfig - 1)"!][!//
[!VAR "McuModeConfig" = "node:ref($ModulePath)/*[@index =$ModuleIndex]/McuModeSettingConf/*[$ModeIndex+1]/McuMode"!][!//
[!IF "$McuModeConfig = num:i(2)"!][!//
[!VAR "McuStandbyModeEnable" = "num:i(1)"!][!//
[!VAR "McuModeIndex" = "num:i($ModeIndex)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
    /* Ptr to Standby Mode in config structure */
    [!IF "$McuStandbyModeEnable = num:i(1)"!][!//
    &Mcu_kStandbyModeConf[!"string($ModuleIndex)"!],
    [!ELSE!][!//
    NULL_PTR,
    [!ENDIF!][!//
  }[!IF "$ModuleIndex != $TotalConfig -1"!],[!ENDIF!]

[!ENDFOR!][!//
};

[!ENDSELECT!][!//
#define MCU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
