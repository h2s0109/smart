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
**   $FILENAME   : Wdg_17_Scu.m $                                             **
**                                                                            **
**   $CC VERSION : \main\16 $                                                 **
**                                                                            **
**   $DATE       : 2015-02-20 $                                               **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : NA                                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Configuration Generator Macros                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/**************************************************************************/!]

[!/*  TRACEABILITY : [cover parentID= DS_NAS_WDG_PR709,DS_NAS_WDG_PR912]
    [/cover]                            */!][!//


[!//
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('WDG_17_M'))"!][!//
[!VAR "WDG_17_M"="'true'"!][!//


[!/*****************************************************************************
** Name             : Wdg_GtmTimingValidation                                 **
**                                                                            **
** Description      : Macro to validate GTM Ticks                             **
**                                                                            **
*****************************************************************************/!]
[!MACRO "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "", "SlowCbkTimeInTicks"="","WdgTimeNodeName"="", "MaxTicks"="", "MinTicks"=""!]
[!NOCODE!]
[!VAR "MaxAllowedCbkTime" = "num:i($MaxTicks) div ($TicksPerMs)"!]
[!IF "$FastCbkTimeInTicks > num:i($MaxTicks)"!] [!//
  [!ASSERT "num:i($FastCbkTimeInTicks) <= num:i($MaxTicks)"!][!//
   Error: The parameter "Wdg[!"$WdgTimeNodeName"!]FastServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] can be set to maximum of [!"$MaxAllowedCbkTime"!] ms for the selected GTM Clock configuration.
  [!ENDASSERT!]
[!ENDIF!]
[!IF "$FastCbkTimeInTicks < num:i($MinTicks)"!] [!//
  [!ASSERT "num:i($FastCbkTimeInTicks) >= num:i($MinTicks)"!][!//
  Error: The value configured for the parameter "Wdg[!"$WdgTimeNodeName"!]FastServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is lower than minimum possible value.Configure a higher value for "Wdg[!"$WdgTimeNodeName"!]FastServiceGtmCbkTime" .
  [!ENDASSERT!]
[!ENDIF!]
[!IF "$SlowCbkTimeInTicks > num:i($MaxTicks)"!] [!//
  [!ASSERT "num:i($SlowCbkTimeInTicks) <= num:i($MaxTicks)"!][!//
  Error: The parameter "Wdg[!"$WdgTimeNodeName"!]SlowServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] can be set to maximum of [!"$MaxAllowedCbkTime"!] ms for the selected GTM Clock configuration.
  [!ENDASSERT!]
[!ENDIF!]
[!IF "$SlowCbkTimeInTicks < num:i($MinTicks)"!] [!//
  [!ASSERT "num:i($SlowCbkTimeInTicks) >= num:i($MinTicks)"!][!//
  Error: The value configured for the parameter "Wdg[!"$WdgTimeNodeName"!]SlowServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is lower than minimum possible value.Configure a higher value for "Wdg[!"$WdgTimeNodeName"!]SlowServiceGtmCbkTime" .
  [!ENDASSERT!]
[!ENDIF!]
[!IF "$SlowCbkTimeInTicks < num:i($FastCbkTimeInTicks)"!] [!//
  [!ASSERT "num:i($SlowCbkTimeInTicks) >= num:i($FastCbkTimeInTicks)"!][!//
  Error: The value Wdg[!"$WdgTimeNodeName"!]SlowModeTimeoutValue should be more than Wdg[!"$WdgTimeNodeName"!]FastModeTimeoutValue in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is lower than minimum possible value.Configure a higher value for "Wdg[!"$WdgTimeNodeName"!]SlowServiceGtmCbkTime" .
  [!ENDASSERT!]
[!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!]
[!/*****************************************************************************
** Name             : Wdg_TimingValidation                                    **
**                                                                            **
** Description      : Macro to validate WDG Ticks                             **
**                                                                            **
*****************************************************************************/!]
[!MACRO "Wdg_TimingValidation", "ReloadValue"="", "WdgTimeNodeName"="","MaxReloadTime"="","Resolution"=""!][!//
[!NOCODE!]
[!IF "$ReloadValue > num:i(65536)"!][!//
  [!ASSERT "$ReloadValue <= num:i(65536)"!][!//
  Error: The value configured for the parameter [!"$WdgTimeNodeName"!] in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] exceeds the 16 bit timer value of watchdog for the configured system clock.
  Maximum time which could be configured for the configured system frequency is [!"num:i($MaxReloadTime)"!] ms.
  [!ENDASSERT!][!//
[!ELSEIF "$ReloadValue < num:i(1)"!][!//
  [!ASSERT "$ReloadValue >= num:i(1)"!][!//
  Error: The value configured for the parameter [!"$WdgTimeNodeName"!] in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is less than minimum resolution of timer value of watchdog for the configured system clock.
  The minimum value which could be configured for the configured system frequency is [!"num:i($Resolution)"!] ms.
  [!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Wdg_ValidateGtmChannel                                  **
**                                                                            **
** Description      : Macro to validate GTM SRV                               **
**                                                                            **
*****************************************************************************/!]
[!MACRO "Wdg_ValidateGtmChannel", "Wdg0GtmChannel"="", "Wdg1GtmChannel"="", "Wdg2GtmChannel"=""!][!//
[!NOCODE!]

[!IF "$Wdg0GtmChannel != 'NotAvailable'"!][!//
[!VAR "Wdg0TimerUnit" = "contains($Wdg0GtmChannel,"Atom")"!]
[!IF "$Wdg0TimerUnit = "true" "!]
[!/*" ATOM channel Used "*/!]
[!VAR "Wdg0ModuleNumber" = "substring-before ( substring-after($Wdg0GtmChannel,'/Atom_'),'/AtomChannel_')"!]
[!VAR "Wdg0ChannelNumber" = "substring-after($Wdg0GtmChannel,'/AtomChannel_')"!]
[!ELSE!]
[!/*" TOM channel Used "*/!]
[!VAR "Wdg0ModuleNumber" = "substring-before ( substring-after($Wdg0GtmChannel,'/Tom_'),'/TomChannel_')"!]
[!VAR "Wdg0ChannelNumber" = "substring-after($Wdg0GtmChannel,'/TomChannel_')"!]
[!ENDIF!]
[!ENDIF!]

[!IF "$Wdg1GtmChannel != 'NotAvailable'"!][!//
[!VAR "Wdg1TimerUnit" = "contains($Wdg1GtmChannel,"Atom")"!]
[!IF "$Wdg1TimerUnit = "true" "!]
[!/*" ATOM channel Used "*/!]
[!VAR "Wdg1ModuleNumber" = "substring-before ( substring-after($Wdg1GtmChannel,'/Atom_'),'/AtomChannel_')"!]
[!VAR "Wdg1ChannelNumber" = "substring-after($Wdg1GtmChannel,'/AtomChannel_')"!]
[!ELSE!]
[!/*" TOM channel Used "*/!]
[!VAR "Wdg1ModuleNumber" = "substring-before ( substring-after($Wdg1GtmChannel,'/Tom_'),'/TomChannel_')"!]
[!VAR "Wdg1ChannelNumber" = "substring-after($Wdg1GtmChannel,'/TomChannel_')"!]
[!ENDIF!]
[!ENDIF!]

[!IF "$Wdg2GtmChannel != 'NotAvailable'"!][!//
[!VAR "Wdg2TimerUnit" = "contains($Wdg2GtmChannel,"Atom")"!]
[!IF "$Wdg2TimerUnit = "true" "!]
[!/*" ATOM channel Used "*/!]
[!VAR "Wdg2ModuleNumber" = "substring-before ( substring-after($Wdg2GtmChannel,'/Atom_'),'/AtomChannel_')"!]
[!VAR "Wdg2ChannelNumber" = "substring-after($Wdg2GtmChannel,'/AtomChannel_')"!]
[!ELSE!]
[!/*" TOM channel Used "*/!]
[!VAR "Wdg2ModuleNumber" = "substring-before ( substring-after($Wdg2GtmChannel,'/Tom_'),'/TomChannel_')"!]
[!VAR "Wdg2ChannelNumber" = "substring-after($Wdg2GtmChannel,'/TomChannel_')"!]
[!ENDIF!]
[!ENDIF!][!//

[!IF "($Wdg0GtmChannel != 'NotAvailable') and ($Wdg1GtmChannel != 'NotAvailable')"!]
[!IF "($Wdg0TimerUnit = $Wdg1TimerUnit)"!][!//
  [!IF "($Wdg0ModuleNumber = $Wdg1ModuleNumber)"!][!//
    [!VAR "Wdg0ChannelNumber" = "bit:shr($Wdg0ChannelNumber,num:i(1))"!][!//
    [!VAR "Wdg1ChannelNumber" = "bit:shr($Wdg1ChannelNumber,num:i(1))"!][!//
    [!IF "($Wdg0ChannelNumber = $Wdg1ChannelNumber)"!][!//
      [!ASSERT "($Wdg0ChannelNumber != $Wdg1ChannelNumber)"!][!//
        Config error: In Container Wdg/[!"node:name(WdgSettingsConfig/*[@index = $Index])"!]/WdgGtmSettings for WDG0 and WDG1 same Interrupt SRV is selected .
      [!ENDASSERT!][!//
    [!ENDIF!][//
  [!ENDIF!][//
[!ENDIF!][//
[!ENDIF!][!//


[!IF "($Wdg0GtmChannel != 'NotAvailable') and ($Wdg2GtmChannel != 'NotAvailable')"!]
[!IF "($Wdg0TimerUnit = $Wdg2TimerUnit)"!][!//
  [!IF "($Wdg0ModuleNumber = $Wdg2ModuleNumber)"!][!//
    [!VAR "Wdg0ChannelNumber" = "bit:shr($Wdg0ChannelNumber,num:i(1))"!][!//
    [!VAR "Wdg2ChannelNumber" = "bit:shr($Wdg2ChannelNumber,num:i(1))"!][!//
    [!IF "($Wdg0ChannelNumber = $Wdg2ChannelNumber)"!][!//
      [!ASSERT "($Wdg0ChannelNumber != $Wdg2ChannelNumber)"!][!//
        Config error: In Conrainer Wdg/[!"node:name(WdgSettingsConfig/*[@index = $Index])"!]/WdgGtmSettings for WDG0 and WDG2 same Interrupt SRV is selected .
      [!ENDASSERT!][!//
    [!ENDIF!][//
  [!ENDIF!][//
[!ENDIF!][//
[!ENDIF!][//

[!IF "($Wdg1GtmChannel != 'NotAvailable') and ($Wdg2GtmChannel != 'NotAvailable')"!]
[!IF "($Wdg1TimerUnit = $Wdg2TimerUnit)"!][!//
  [!IF "($Wdg1ModuleNumber = $Wdg2ModuleNumber)"!][!//
    [!VAR "Wdg1ChannelNumber" = "bit:shr($Wdg1ChannelNumber,num:i(1))"!][!//
    [!VAR "Wdg2ChannelNumber" = "bit:shr($Wdg2ChannelNumber,num:i(1))"!][!//
    [!IF "($Wdg1ChannelNumber = $Wdg2ChannelNumber)"!][!//
      [!ASSERT "($Wdg1ChannelNumber != $Wdg2ChannelNumber)"!][!//
        Config error: In Conrainer Wdg/[!"node:name(WdgSettingsConfig/*[@index = $Index])"!]/WdgGtmSettings for WDG1 and WDG2 same Interrupt SRV is selected .
      [!ENDASSERT!][!//
    [!ENDIF!][//
  [!ENDIF!][//
[!ENDIF!][//   
[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Wdg_GetTicksPerMs                                       **
**                                                                            **
** Description      : Macro to calculate Ticks per millisecond of GTM         **
**                                                                            **
*****************************************************************************/!]
[!MACRO "Wdg_GetTicksPerMs", "ChannelRef" = "","TicksPerMs"=""!]
[!NOCODE!]

[!VAR "TimerUnit" = "contains($ChannelRef,"Atom")"!]
[!IF "$TimerUnit = "true" "!]
[!/*" ATOM channel Used "*/!] 
[!VAR "GTMChannelConfiguration" = "substring-before($ChannelRef,'/Atom_')"!]
[!ELSE!]
[!/*" TOM channel Used "*/!]    
[!VAR "GTMChannelConfiguration" = "substring-before($ChannelRef,'/Tom_')"!]
[!ENDIF!]

[!/*" Calculate GTM Frequency after GTM internal divider "*/!]  
[!VAR "GTM_Global_Numerator" = "(node:ref($GTMChannelConfiguration)/GtmGeneral/GtmGlobalClkDivNumerator)"!]
[!VAR "GTM_Global_Denominator" ="(node:ref($GTMChannelConfiguration)/GtmGeneral/GtmGlobalClkDivDenominator)"!]
[!VAR "GTM_Clock" = "($MCU_GTMClock) * num:i($GTM_Global_Denominator)"!]
[!VAR "GTM_Clock" = "($GTM_Clock) div num:i($GTM_Global_Numerator)"!]

[!IF "$TimerUnit = "true" "!]
[!/*" ATOM channel Used "*/!]   
  [!VAR "ClockUsed" = "(node:ref($ChannelRef)/AtomChannelTimerParameters/AtomChannelClockSelect)"!]
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
[!ELSE!]
[!/*" TOM channel Used "*/!]  
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
    [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk6 = "true""!]  
      [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuClk6SourceSelect= 'CMU_CLK_6_DIVIDER'"!]
        [!VAR "GTM_Clock6_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk6Div)"!]
        [!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock6_Divider + 1)"!] 
      [!ELSE!]
        [!ERROR"Config Error : /CmuConfigurableClock/CmuClk6SourceSelect is not configured to CMU_CLK_6_DIVIDER."!]
      [!ENDIF!] 
    [!ELSE!]
      [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk6 is not set to true."!]
    [!ENDIF!] 
  [!ELSEIF "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuFixedClock/CmuFxdClkSourceSelect) = "CMU_CLOCK_7_DIVIDER""!]
    [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuEnableConfigurableClk7 = "true""!]  
      [!IF "node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuClk7SourceSelect= 'CMU_CLK_7_DIVIDER'"!]
        [!VAR "GTM_Clock7_Divider" = "(node:ref($GTMChannelConfiguration)/Cmu/*[1]/CmuConfigurableClock/CmuConfigurableClk7Div)"!]
        [!VAR "GTM_Fixed_Clock" = "($GTM_Clock) div num:i($GTM_Clock7_Divider + 1)"!] 
      [!ELSE!]
      [!ERROR"Config Error : /CmuConfigurableClock/CmuClk7SourceSelect is not configured to CMU_CLK_7_DIVIDER."!]
      [!ENDIF!] 
    [!ELSE!]
      [!ERROR"Config Error: /CmuConfigurableClock/CmuEnableConfigurableClk7 is not set to true."!]  
    [!ENDIF!] 
  [!ENDIF!] 
  [!VAR "ClockUsed" = "(node:ref($ChannelRef)/TomChannelTimerParameters/TomChannelClockSelect)"!]
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
[!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!]
[!/*******************************************************************************
** Name             : Wdg_ReloadValue                                         **
**                                                                            **
** Description      : Macro to calculate WDG reload value                     **
**                                                                            **
*******************************************************************************/!]
[!MACRO "Wdg_ReloadValue", "SystemClockVal" = "", "TimeoutVal"="", "ClockDivider"="", "ReloadValue"=""!]
[!NOCODE!]
[!VAR "Numerator_ReloadValue" = "(num:i($SystemClockVal)*$TimeoutVal) div 1000.0"!]
[!VAR "ReloadValue" = "num:i(ceiling($Numerator_ReloadValue div $ClockDivider))"!]
[!ENDNOCODE!]
[!ENDMACRO!]
/*******************************************************************************
** Name             : Wdg_MaxReloadTime                                       **
**                                                                            **
** Description      : Macro to calculate max reload time for WDG              **
**                                                                            **
*******************************************************************************/
[!//
[!MACRO "Wdg_MaxReloadTime", "SystemClockVal" = "", "ClockDivider"="", "MaxReloadTime"=""!]
[!NOCODE!]
[!VAR "Numerator_MaxReloadTime" = "num:i(65536)* num:i($ClockDivider)"!]
[!VAR "Denominator_MaxReloadTime" = "num:i($SystemClockVal) div 1000.0"!]
[!VAR "MaxReloadTime" = "$Numerator_MaxReloadTime div $Denominator_MaxReloadTime"!]
[!ENDNOCODE!]
[!ENDMACRO!]
[!//
[!/*******************************************************************************
** Name             : Wdg_Resolution                                          **
**                                                                            **
** Description      : Macro to calculate WDG reolution                        **
**                                                                            **
*******************************************************************************/!]
[!MACRO "Wdg_Resolution", "SystemClockVal" = "", "ClockDivider"="", "Resolution"=""!]
[!NOCODE!]
[!VAR "Denominator_Resolution" = "num:i($SystemClockVal) div 1000.0"!]
[!VAR "Resolution" = "num:i($ClockDivider) div $Denominator_Resolution"!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!ENDIF!][!// IF "not(var:defined('WDG_17_M'))