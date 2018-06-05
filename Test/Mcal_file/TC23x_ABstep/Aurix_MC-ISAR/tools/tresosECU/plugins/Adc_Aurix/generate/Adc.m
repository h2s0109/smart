[!/*
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
**   $FILENAME   : Adc.m $                                                    **
**                                                                            **
**   $CC VERSION : \main\16 $                                                 **
**                                                                            **
**   $DATE       : 2014-07-31 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Configuration Generator Macros                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/

*/!]
/******************************************************************************/
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('ADC_M'))"!][!//
[!VAR "ADC_M"="'true'"!][!//
/*******************************************************************************
** Name             : CG_ConfigSwitch                                         **
**                                                                            **
** Description      : Macro to generate configuration switch Values ON/OFF    **
**                    based on configuration true/false                       **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]

/*******************************************************************************
** Name             : CG_ResHandlingConfigSwitch                              **
**                                                                            **
** Description      : Macro to generate configuration switch Values           **
**                    ADC_AUTOSAR / ADC_NON_AUTOSAR                           **
**                    based on configuration true/false                       **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_ResHandlingConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(ADC_NON_AUTOSAR)[!//
[!ELSE!][!//
(ADC_AUTOSAR)[!//
[!ENDIF!]
[!ENDMACRO!]

/*******************************************************************************
** Name             : CG_ConfigChannelNum                                     **
**                                                                            **
** Description      : Macro to get the internal channel number                **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_ConfigChannelNum"!][!//

[!IF "ecu:get('Adc.NumOfChInGrp') = num:i(8)"!][!// 
[!VAR "InternalChannelMaskNumber" = "num:i(num:mod($AnalogInputChannelNumber,8))"!]
[!ELSE!][!//
[!VAR "InternalChannelMaskNumber" = "num:i(num:mod($AnalogInputChannelNumber,16))"!]
[!ENDIF!][!//

[!ENDMACRO!]

/*******************************************************************************
** Name             : CG_ErrorMacro                                           **
**                                                                            **
** Description      : Macro to check whether Channels added to the group is   **
**                    within the limit of Request source                      **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_GroupErrorMacro"!]
[!NOCODE!][!//
[!IF "ecu:get('Adc.NumOfChInGrp') = num:i(8)"!][!// 
[!IF "$ReqSrcId = num:i(0) or $ReqSrcId = num:i(1) or $ReqSrcId = num:i(2)"!][!// 
[!ASSERT "$TotalAdcGroupDef <= 8"!][!//
Cfg Error: More than 8 channels can not be configured for [!"$SymbolicName"!] with request source [!"$ReqSrcName"!]
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "$ReqSrcId = num:i(0)"!][!// 
[!ASSERT "$TotalAdcGroupDef <= 8"!][!//
Cfg Error: More than 8 channels can not be configured for [!"$SymbolicName"!] with request source [!"$ReqSrcName"!]
[!ENDASSERT!][!//
[!ELSEIF "$ReqSrcId = num:i(1) or $ReqSrcId = num:i(2)"!][!// 
[!ASSERT "$TotalAdcGroupDef <= 16"!][!//
Cfg Error: More than 16 channels can not be configured for [!"$SymbolicName"!] with request source [!"$ReqSrcName"!]
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

/*******************************************************************************
** Name             : CG_GtmGetTicksPerMs                                     **
**                                                                            **
** Description      : Macro to get the Ticks per Millisecond for Timer        **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_GtmGetTicksPerMs", "TriggerString"="", "McuModuleId"="", "GtmModuleId"="", "MCU_GTMClock"="", "ClockTicks"=""!]
[!NOCODE!]
[!VAR "TimerUnit" = "contains($TriggerString,"ATOM")"!]
[!//
[!IF "$TimerUnit = "true" "!]
[!//
[!VAR "ModuleIdFind" = "substring($TriggerString,7,1)"!][!//
[!IF "$ModuleIdFind = '_' "!]
[!//
[!VAR "ModuleId" = "substring($TriggerString,12,1)"!][!//
[!VAR "ChannelId" = "substring($TriggerString,16,2)"!][!//
[!//
[!ELSE!]
[!//
[!VAR "ModuleId" = "substring($TriggerString,13,1)"!][!//
[!VAR "ChannelId" = "substring($TriggerString,17,2)"!][!//
[!//
[!ENDIF!]
[!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "ClockUsed" = "(McuModuleConfiguration/*[@index=$McuModuleId]/GtmConfiguration/*[@index=$GtmModuleId]/Atom/*[@index=$ModuleId]/AtomChannel/*[@index=$ChannelId]/AtomChannelTimerParameters/AtomChannelClockSelect)"!]
[!VAR "GTMChannelConfiguration" = "node:path(McuModuleConfiguration/*[@index=$McuModuleId]/GtmConfiguration/*[@index=$GtmModuleId])"!]
[!ENDSELECT!][!//
[!//
[!ELSE!]
[!//
[!VAR "ModuleIdFind" = "substring($TriggerString,7,1)"!][!//
[!IF "$ModuleIdFind = '_' "!]
[!//
[!VAR "ModuleId" = "substring($TriggerString,11,1)"!][!//
[!VAR "ChannelId" = "substring($TriggerString,15,2)"!][!//
[!//
[!ELSE!]
[!//
[!VAR "ModuleId" = "substring($TriggerString,12,1)"!][!//
[!VAR "ChannelId" = "substring($TriggerString,16,2)"!][!//
[!//
[!ENDIF!]
[!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "ClockUsed" = "(McuModuleConfiguration/*[@index=$McuModuleId]/GtmConfiguration/*[@index=$GtmModuleId]/Tom/*[@index=$ModuleId]/TomChannel/*[@name=concat('TomChannel_',$ChannelId)]/TomChannelTimerParameters/TomChannelClockSelect)"!]
[!VAR "GTMChannelConfiguration" = "node:path(McuModuleConfiguration/*[@index=$McuModuleId]/GtmConfiguration/*[@index=$GtmModuleId])"!]
[!ENDSELECT!][!//
[!//
[!ENDIF!]

[!/*" Calculate GTM Frequency after GTM internal divider "*/!]	
[!VAR "GTM_Global_Numerator" = "(node:ref($GTMChannelConfiguration)/GtmGeneral/GtmGlobalClkDivNumerator)"!]
[!VAR "GTM_Global_Denominator" ="(node:ref($GTMChannelConfiguration)/GtmGeneral/GtmGlobalClkDivDenominator)"!]
[!VAR "GTM_Clock" = "($MCU_GTMClock) * num:i($GTM_Global_Numerator)"!]
[!VAR "GTM_Clock" = "($GTM_Clock) div num:i($GTM_Global_Denominator)"!]

[!VAR "TimePeriod" = "./AdcGtmTimerPeriod"!][!//

[!VAR "TypeOfClock" = "contains($ClockUsed,"CONFIGURABLE")"!]
[!IF "$TypeOfClock = "true""!]
[!VAR "ClockModuleUsed" = "text:split($ClockUsed,'GTM_CONFIGURABLE_CLOCK_')[position()-1 = 0]"!]
[!VAR "CmuConfigurableClock" = "num:i(0)"!]
[!IF "$ClockModuleUsed = num:i(0)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk0 = "true""!]	
  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk0Div)"!]
  [!ELSE!]
  [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk0 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(1)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk1 = "true""!]	
  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk1Div)"!]
  [!ELSE!]
  [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk1 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(2)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk2 = "true""!]	
  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk2Div)"!]
  [!ELSE!]
  [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk2 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(3)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk3 = "true""!]	
  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk3Div)"!]
  [!ELSE!]
  [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk3 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(4)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk4 = "true""!]	
  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk4Div)"!]
  [!ELSE!]
  [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk4 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(5)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk5 = "true""!]	
  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk5Div)"!]
  [!ELSE!]
  [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk5 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(6)"!]
  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk6 = "true""!]	
	  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuClk6SourceSelect= 'CMU_CLK_6_DIVIDER'"!]
	  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk6Div)"!]
	  [!ELSE!]
	  [!ERROR"Config Error : /CmuConfigurableClock/CmuClk6SourceSelect is not configured to CMU_CLK_6_DIVIDER."!]
	  [!ENDIF!]	
  [!ELSE!]
    [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk6 is not set to true."!]
  [!ENDIF!]	
[!ELSEIF "$ClockModuleUsed = num:i(7)"!]
	[!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk7 = "true""!]	
	  [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuClk7SourceSelect= 'CMU_CLK_7_DIVIDER'"!]
	  [!VAR "CmuConfigurableClock" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk7Div)"!]
	  [!ELSE!]
	  [!ERROR"Config Error : /CmuConfigurableClock/CmuClk7SourceSelect is not configured to CMU_CLK_7_DIVIDER."!]
	  [!ENDIF!]	
  [!ELSE!]
    [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk7 is not set to true."!]	
  [!ENDIF!]	
[!ENDIF!]
[!VAR "GTM_Conf_Clock" = "($GTM_Clock) div num:i($CmuConfigurableClock+1)"!]
[!VAR "TicksPerMs" = " num:i($GTM_Conf_Clock) div num:i(1000)"!]
[!//
[!VAR "ClockTicks" = "num:i($TicksPerMs) * $TimePeriod"!][!//
[!ASSERT "$ClockTicks < 16777215"!]
The given input period in AdcGtmTimerPeriod for [!"node:name(.)"!] is not possible with the selected clock line.Provide lesser AdcGtmTimerPeriod value or change the selected clock. 
[!ENDASSERT!][!//
[!ASSERT "num:i($ClockTicks) != num:i(0)"!]
The given input period in AdcGtmTimerPeriod for [!"node:name(.)"!] is too less for triggering. 
[!ENDASSERT!][!//
[!//
[!ELSE!]
[!//
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuEnableAllFixedClocks) = "true""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "GTM_GLOBAL_CLOCK""!]
[!VAR "GTM_Fixed_Clock" = "$GTM_Clock"!]
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_0_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk0) = "true""!]
[!VAR "GTM_Clock0_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk0Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock0_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk0 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_1_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk1) = "true""!]
[!VAR "GTM_Clock1_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk1Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock1_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk1 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_2_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk2) = "true""!]
[!VAR "GTM_Clock2_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk2Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock2_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk2 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_3_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk3) = "true""!]
[!VAR "GTM_Clock3_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk3Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock3_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk3 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_4_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk4) = "true""!]
[!VAR "GTM_Clock4_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk4Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock4_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk4 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_5_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk5) = "true""!]
[!VAR "GTM_Clock5_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk5Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock5_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk5 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_6_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk6) = "true""!]
[!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuClk6SourceSelect= 'CMU_CLK_6_DIVIDER'"!]
[!VAR "GTM_Clock6_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk6Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock6_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error : CmuConfigurableClock/CmuClk6SourceSelect is not configured to CMU_CLK_6_DIVIDER."!]
[!ENDIF!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk6 is not set to TRUE."!]		
[!ENDIF!]	
[!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_7_DIVIDER""!]
[!IF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk7) = "true""!]
[!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuClk7SourceSelect= 'CMU_CLK_7_DIVIDER'"!]
[!VAR "GTM_Clock7_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk7Div)"!]		
[!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock7_Divider + 1)"!]	
[!ELSE!]
[!ERROR"Config Error : CmuConfigurableClock/CmuClk7SourceSelect is not configured to CMU_CLK_7_DIVIDER."!]
[!ENDIF!]	
[!ELSE!]
[!ERROR"Config Error: CmuConfigurableClock/CmuEnableConfigurableClk7 is not set to TRUE."!]		
[!ENDIF!]	
[!ENDIF!]	
[!VAR "ClockModuleUsed" = "text:split($ClockUsed,'GTM_FIXED_CLOCK_')[position()-1 = 0]"!]
[!VAR "Exponent" = "num:i(4)*num:i($ClockModuleUsed)"!]
[!VAR "denominator" = "num:i(1)"!]
[!FOR "LoopCtr" = "num:i(0)" TO "num:i(($Exponent)- num:i(1))"!]
[!VAR "denominator" = "num:i($denominator) * num:i(2)"!]
[!ENDFOR!]
[!VAR "Numerator" = "num:i($GTM_Fixed_Clock) div num:i($denominator)"!]
[!VAR "TicksPerMs" = "num:i($Numerator) div num:i(1000)"!]
[!ELSE!]
[!ERROR"Config Error: CmuFixedClock/CmuEnableAllFixedClocks is not set true."!]	
[!ENDIF!]
[!//
[!VAR "ClockTicks" = "num:i($TicksPerMs) * $TimePeriod"!][!//
[!ASSERT "$ClockTicks < 65535"!]
The given input period in AdcGtmTimerPeriod for [!"node:name(.)"!] is not possible with the selected clock line.Provide lesser AdcGtmTimerPeriod value or change the selected clock. 
[!ENDASSERT!][!//
[!ASSERT "num:i($ClockTicks) != num:i(0)"!]
The given input period in AdcGtmTimerPeriod for [!"node:name(.)"!] is too less for triggering. 
[!ENDASSERT!][!//
[!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!]


[!ENDIF!][!// IF "not(var:defined('ADC_M'))

