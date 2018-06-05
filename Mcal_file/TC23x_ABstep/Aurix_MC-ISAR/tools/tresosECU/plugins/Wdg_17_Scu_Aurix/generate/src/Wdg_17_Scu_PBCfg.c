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
**  $FILENAME   : Wdg_17_Scu_PBCfg.c $                                       **
**                                                                           **
**  $CC VERSION : \main\45 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-05 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Wdg_17_Scu_PBCfg.c file                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=DS_NAS_WDG_PR69_PR469_PR122,
   DS_NAS_WDG_PR446,
   DS_AS_WDG075,SAS_AS40X_WDG079_WDG080_WDG061,SAS_AS_WDG062,DS_AS_WDG092,
   DS_AS_WDG090,DS_NAS_WDG_PR655,DS_NAS_WDG_PR700,DS_NAS_WDG_PR701,
   DS_NAS_WDG_PR704,DS_NAS_WDG_PR707,DS_NAS_WDG_PR708,DS_NAS_WDG_PR712,
   DS_NAS_WDG_PR713,DS_NAS_WDG_PR714,DS_NAS_WDG_PR716,
   DS_NAS_WDG_PR717,DS_NAS_WDG_PR719,DS_NAS_WDG_PR720,DS_NAS_WDG_PR723,
   DS_NAS_WDG_PR724,DS_NAS_WDG_PR728,DS_NAS_WDG_PR699,
					   SAS_AS4XX_WDG_PR680,
SAS_AS_HE1_WDG120_Conf_1,SAS_AS_HE2_WDG120_Conf_1,SAS_AS_HE1_WDG120_Conf_2,
SAS_AS_HE2_WDG120_Conf_2,SAS_AS_HE1_WDG120_Conf_3,SAS_AS_HE2_WDG120_Conf_3,                                    
SAS_NAS_HE1_WDG_PR228_2,SAS_NAS_HE2_WDG_PR228_2,SAS_NAS_HE1_WDG_PR228_4,
SAS_NAS_HE2_WDG_PR228_4,SAS_NAS_HE1_WDG_PR228_3,SAS_NAS_HE2_WDG_PR228_3,
SAS_NAS_HE1_WDG_PR228_6,SAS_NAS_HE2_WDG_PR228_6,SAS_NAS_HE1_WDG_PR228_5,
SAS_NAS_HE2_WDG_PR228_5,SAS_NAS_HE1_WDG_PR228_7,SAS_NAS_HE2_WDG_PR228_7]
    [/cover]                            */!][!//
/* Traceability : [cover parentID=SAS_NAS_WDG_PR483][/cover]            */
/* Traceability : [cover parentID=SAS_NAS_WDG_PR913][/cover]            */
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
**  FILENAME  : Wdg_17_Scu_PBCfg.c                                            **
**                                                                            **
**  $CC VERSION : \main\45 $                                                 **
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
**                 file  (Wdg_17_Scu.bmd and Wdg_17_Scu.xdm)                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


[!NOCODE!][!//
[!INCLUDE "Wdg_17_Scu.m"!][!//
[!ENDNOCODE!][!//


/******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include module header File */

/* Module header file, which includes module configuration(Wdg_17_Cfg.h) file */
#include "Wdg_17_Scu.h"

/******************************************************************************
**                      Imported Compiler Switch Checks                      **
*******************************************************************************/

/******************************************************************************
**                      Private Macro Definitions                            **
*******************************************************************************/
/*
Configuration Options:
For fast mode, the divider is 256
*/

#define WDG_CLK_DIVIDER_FAST  (256U)

/*
Configuration Options:
For slow mode, the divider 16384
*/

#define WDG_CLK_DIVIDER_SLOW  (16384U)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define WDG_17_SCU_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Wdg')[1]"!][!//
[!VAR "WdgTotalConfig" = "num:i(count(as:modconf('Wdg')[1]/WdgSettingsConfig/*))"!][!//

[!NOCODE!][!//
[!/* For loadable build PBfixedAddress should be False */!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$PostBuildType = 'LOADABLE'"!][!//
[!ASSERT "not(WdgGeneral/WdgPBFixedAddress = 'true')"!][!//
For EcuMPostBuildConfigType = Loadable, WdgPBFixedAddress should be False[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!VAR "Wdg_MaxTimers" = "ecu:get('Wdg.MaxTimers')"!]
/*
Configuration: Wdg_17_Scu_ConfigType
Overall configuration of the WDT
*/
const Wdg_17_Scu_ConfigType Wdg_ConfigRoot[[!"string(num:i($WdgTotalConfig))"!]]=
{
[!//
[!VAR "No0fWdgModuleConfig" = "num:i(count(WdgSettingsConfig/*)- num:i(1))"!][!//
[!//
[!FOR "Index" = "num:i(0)" TO "num:i($No0fWdgModuleConfig)"!][!//

  {
    /* Traceability : [cover parentID=DS_AS_WDG090, DS_AS_WDG092] [/cover]*/
[!//
[!NOCODE!]
/*Code for calculating system clock*/

[!VAR "SystemClock" = "(node:ref(WdgSettingsConfig/*[@index = $Index]/WdgSystemClockRef)/McuClockSPBFrequency)"!][!//
[!VAR "MCU_GTMClock" = "(node:ref(WdgSettingsConfig/*[@index = $Index]/WdgSystemClockRef)/McuClockGTMFrequency)"!][!//



[!ENDNOCODE!][!//

[!NOCODE!][!//
[!VAR "WDGSAFECOUNT" = "num:i(0)"!][!//
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!] [!//
[!VAR "WDGSAFECOUNT" = "($WDGSAFECOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
[!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!] [!//
[!VAR "WDGSAFECOUNT" = " ($WDGSAFECOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//  
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!] [!//
[!VAR "WDGSAFECOUNT" = " ($WDGSAFECOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//
[!ENDIF!] [!//
[!ENDIF!] [!//
[!ENDNOCODE!][!//

[!NOCODE!][!//
[!VAR "WDGQMCOUNT" = "num:i(0)"!][!//
[!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
[!VAR "WDGQMCOUNT" = "($WDGQMCOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
[!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!//
[!VAR "WDGQMCOUNT" = " ($WDGQMCOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//  
[!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!] [!//
[!VAR "WDGQMCOUNT" = " ($WDGQMCOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//
[!ENDIF!] [!//
[!ENDIF!] [!//
[!ENDNOCODE!][!//


    [!//
     
    /* These are the Gtm settings for this configuration instance */ [!//
    [!NOCODE!][!//
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!VAR "Wdg0GtmChannel" = "(WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg0ServiceGtmChannelRef)"!][!//
    [!ELSE!][!//
    [!VAR "Wdg0GtmChannel" = "'NotAvailable'"!][!//
    [!ENDIF!][!//
     
      [!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
      [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!// 
      [!VAR "Wdg1GtmChannel" = "(WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg1ServiceGtmChannelRef)"!][!//
      [!ELSE!][!//
      [!VAR "Wdg1GtmChannel" = "'NotAvailable'"!][!//
      [!ENDIF!] 
    
      [!IF "($Wdg_MaxTimers > num:i(2))"!][!// 
        [!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!] [!//
        [!VAR "Wdg2GtmChannel" = "(WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg2ServiceGtmChannelRef)"!][!//
        [!ELSE!][!//
        [!VAR "Wdg2GtmChannel" = "'NotAvailable'"!][!//
        [!ENDIF!][!// 
      [!ELSE!][!//
      [!VAR "Wdg2GtmChannel" = "'NotAvailable'"!][!//
      [!ENDIF!][!//
      [!ELSE!][!//
    [!VAR "Wdg1GtmChannel" = "'NotAvailable'"!][!//
    [!VAR "Wdg2GtmChannel" = "'NotAvailable'"!][!//
    [!ENDIF!][!// 
    
    
    [!CALL "Wdg_ValidateGtmChannel", "Wdg0GtmChannel"="$Wdg0GtmChannel", "Wdg1GtmChannel"="$Wdg1GtmChannel", "Wdg2GtmChannel"="$Wdg2GtmChannel"!][!//
    
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!VAR "FastCbkTime0" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg0FastServiceGtmCbkTime "!]
    [!ENDIF!]
    [!IF "($Wdg_MaxTimers > num:i(1))"!][!//
     [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!// 
     [!VAR "FastCbkTime1" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg1FastServiceGtmCbkTime "!]
     [!ENDIF!] 
    [!ENDIF!][!//
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!IF "($FastCbkTime0 <= num:i(1))"!][!//
      [!ASSERT "($FastCbkTime0 > num:i(1))"!][!//
      Error: The value configured for the parameter "WdgXFastServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured less than 1ms. The min value should be > 1ms.
    [!ENDASSERT!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
   [!IF "($Wdg_MaxTimers > num:i(1))"!][!//  
    [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!//
    [!IF "($FastCbkTime1 <= num:i(1))"!][!//
      [!ASSERT "($FastCbkTime1 > num:i(1))"!][!//
      Error: The value configured for the parameter "WdgXFastServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured less than 1ms. The min value should be > 1ms.
    [!ENDASSERT!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//
    
    
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!VAR "SlowCbkTime0" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg0SlowServiceGtmCbkTime "!]
    [!ENDIF!]
   [!IF "($Wdg_MaxTimers > num:i(1))"!][!//  
    [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!// 
    [!VAR "SlowCbkTime1" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg1SlowServiceGtmCbkTime "!]
    [!ENDIF!] 
   [!ENDIF!] 
    
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!IF "($SlowCbkTime0 <= num:i(1))"!][!//
      [!ASSERT "($SlowCbkTime0 > num:i(1))"!][!//
      Error: The value configured for the parameter "WdgXSlowServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured less than 1ms. The min value should be > 1ms.
    [!ENDASSERT!][!//
    [!ENDIF!][!//
    [!ENDIF!]

    [!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
     [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!// 
     [!IF "($SlowCbkTime1 <= num:i(1))"!][!//
       [!ASSERT "($SlowCbkTime1 > num:i(1))"!][!//
         Error: The value configured for the parameter "WdgXSlowServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured less than 1ms. The min value should be > 1ms.
       [!ENDASSERT!][!//
     [!ENDIF!][!//
     [!ENDIF!]
    [!ENDIF!][!//
     
    
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!CALL "Wdg_GetTicksPerMs", "ChannelRef" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg0ServiceGtmChannelRef","TicksPerMs"="num:i(0)"!]
    [!VAR "TicksPerMsForSRV0" = "$TicksPerMs"!]
    [!ENDIF!]
[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
     [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!// 
     [!CALL "Wdg_GetTicksPerMs", "ChannelRef" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg1ServiceGtmChannelRef","TicksPerMs"="num:i(0)"!]
     [!VAR "TicksPerMsForSRV1" = "$TicksPerMs"!]
     [!ENDIF!]
    [!ENDIF!][!//

    
    [!IF "($Wdg_MaxTimers > num:i(2))"!][!//  
    

    [!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!] [!// 
      [!VAR "FastCbkTime2" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg2FastServiceGtmCbkTime "!]
      [!IF "($FastCbkTime2 <= num:i(1))"!][!//
       [!ASSERT "($FastCbkTime2 > num:i(1))"!][!//
       Error: The value configured for the parameter "WdgXFastServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured less than 1ms. The min value should be > 1ms.
       [!ENDASSERT!][!//
      [!ENDIF!][!// 
    
      [!VAR "SlowCbkTime2" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg2SlowServiceGtmCbkTime "!]
      [!IF "($SlowCbkTime2 <= num:i(1))"!][!//
      [!ASSERT "($SlowCbkTime2 > num:i(1))"!][!//
      Error: The value configured for the parameter "WdgXSlowServiceGtmCbkTime" in the configuration [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured less than 1ms. The min value should be > 1ms.
      [!ENDASSERT!][!//
      [!ENDIF!][!// 
        
      [!CALL "Wdg_GetTicksPerMs", "ChannelRef" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg2ServiceGtmChannelRef","TicksPerMs"="num:i(0)"!]
      [!VAR "TicksPerMsForSRV2" = "$TicksPerMs"!] 
       [!ENDIF!][!//
    [!ENDIF!][!//
    
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
    [!VAR "GtmChannelInfoForSRV" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg0ServiceGtmChannelRef"!]
    [!VAR "GtmModule" = "contains($GtmChannelInfoForSRV,"Atom")"!]
    [!IF "$GtmModule = "true""!]
      [!VAR "GtmChannelType0" = "'WDG_GTM_ATOM_CHANNEL'"!]
      [!VAR "GtmModuleIdNo0" = "substring-after($GtmChannelInfoForSRV, 'Atom_')"!]
      [!VAR "GtmModuleIdNo0" = "substring-before($GtmModuleIdNo0, '/')"!]
      [!VAR "GtmChannelIdNo0" = "substring-after($GtmChannelInfoForSRV, 'AtomChannel_')"!]

      [!VAR "FastCbkTimeInTicks" = "num:i($TicksPerMsForSRV0 * $FastCbkTime0)"!]
      [!VAR "SlowCbkTimeInTicks" = "num:i($TicksPerMsForSRV0 * $SlowCbkTime0)"!]
      [!CALL "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "$FastCbkTimeInTicks", "SlowCbkTimeInTicks"="$SlowCbkTimeInTicks","WdgTimeNodeName"="num:i(0)", "MaxTicks"="num:i(16777215)", "MinTicks"="num:i(2)"!]
    [!ELSE!]
      [!VAR "GtmChannelType0" = "'WDG_GTM_TOM_CHANNEL'"!]
      [!VAR "GtmModuleIdNo0" = "substring-after($GtmChannelInfoForSRV, 'Tom_')"!]
      [!VAR "GtmModuleIdNo0" = "substring-before($GtmModuleIdNo0, '/')"!]
      [!VAR "GtmChannelIdNo0" = "substring-after($GtmChannelInfoForSRV, 'TomChannel_')"!]
      [!VAR "FastCbkTimeInTicks" = "num:i($TicksPerMsForSRV0 * $FastCbkTime0)"!]
      [!VAR "SlowCbkTimeInTicks" = "num:i($TicksPerMsForSRV0 * $SlowCbkTime0)"!]
      [!CALL "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "$FastCbkTimeInTicks", "SlowCbkTimeInTicks"="$SlowCbkTimeInTicks","WdgTimeNodeName"="num:i(0)", "MaxTicks"="num:i(65535)", "MinTicks"="num:i(2)"!]
    [!ENDIF!]
    [!ENDIF!]

    
    
   [!IF "($Wdg_MaxTimers > num:i(1))"!][!//  
    [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!// 
    [!VAR "GtmChannelInfoForSRV" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg1ServiceGtmChannelRef"!]
    [!VAR "GtmModule" = "contains($GtmChannelInfoForSRV,"Atom")"!]
    [!IF "$GtmModule = "true""!]
      [!VAR "GtmChannelType1" = "'WDG_GTM_ATOM_CHANNEL'"!]
      [!VAR "GtmModuleIdNo1" = "substring-after($GtmChannelInfoForSRV, 'Atom_')"!]
      [!VAR "GtmModuleIdNo1" = "substring-before($GtmModuleIdNo1, '/')"!]
      [!VAR "GtmChannelIdNo1" = "substring-after($GtmChannelInfoForSRV, 'AtomChannel_')"!]
      [!VAR "FastCbkTimeInTicks" = "num:i($TicksPerMsForSRV1 * $FastCbkTime1)"!]
      [!VAR "SlowCbkTimeInTicks" = "num:i($TicksPerMsForSRV1 * $SlowCbkTime1)"!]
      [!CALL "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "$FastCbkTimeInTicks", "SlowCbkTimeInTicks"="$SlowCbkTimeInTicks","WdgTimeNodeName"="num:i(1)", "MaxTicks"="num:i(16777215)", "MinTicks"="num:i(2)"!]
    [!ELSE!]
      [!VAR "GtmChannelType1" = "'WDG_GTM_TOM_CHANNEL'"!]
      [!VAR "GtmModuleIdNo1" = "substring-after($GtmChannelInfoForSRV, 'Tom_')"!]
      [!VAR "GtmModuleIdNo1" = "substring-before($GtmModuleIdNo1, '/')"!]
      [!VAR "GtmChannelIdNo1" = "substring-after($GtmChannelInfoForSRV, 'TomChannel_')"!]

      [!VAR "FastCbkTimeInTicks" = "num:i($TicksPerMsForSRV1 * $FastCbkTime1)"!]
      [!VAR "SlowCbkTimeInTicks" = "num:i($TicksPerMsForSRV1 * $SlowCbkTime1)"!]
      [!CALL "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "$FastCbkTimeInTicks", "SlowCbkTimeInTicks"="$SlowCbkTimeInTicks","WdgTimeNodeName"="num:i(1)", "MaxTicks"="num:i(65535)", "MinTicks"="num:i(2)"!]
    [!ENDIF!]
    [!ENDIF!]
   [!ENDIF!][!//
    
    [!IF "($Wdg_MaxTimers > num:i(2))"!][!//
    [!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!] [!// 
    [!VAR "GtmChannelInfoForSRV" = "WdgSettingsConfig/*[@index = $Index]/WdgGtmSettings/Wdg2ServiceGtmChannelRef"!]
    [!VAR "GtmModule" = "contains($GtmChannelInfoForSRV,"Atom")"!]
    [!IF "$GtmModule = "true""!]
      [!VAR "GtmChannelType2" = "'WDG_GTM_ATOM_CHANNEL'"!]
      [!VAR "GtmModuleIdNo2" = "substring-after($GtmChannelInfoForSRV, 'Atom_')"!]
      [!VAR "GtmModuleIdNo2" = "substring-before($GtmModuleIdNo2, '/')"!]
      [!VAR "GtmChannelIdNo2" = "substring-after($GtmChannelInfoForSRV, 'AtomChannel_')"!]
      [!VAR "FastCbkTimeInTicks" = "num:i($TicksPerMsForSRV2 * $FastCbkTime2)"!]
      [!VAR "SlowCbkTimeInTicks" = "num:i($TicksPerMsForSRV2 * $SlowCbkTime2)"!]
      [!CALL "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "$FastCbkTimeInTicks", "SlowCbkTimeInTicks"="$SlowCbkTimeInTicks","WdgTimeNodeName"="num:i(2)", "MaxTicks"="num:i(16777215)", "MinTicks"="num:i(2)"!] 
    [!ELSE!]
      [!VAR "GtmChannelType2" = "'WDG_GTM_TOM_CHANNEL'"!]
      [!VAR "GtmModuleIdNo2" = "substring-after($GtmChannelInfoForSRV, 'Tom_')"!]
      [!VAR "GtmModuleIdNo2" = "substring-before($GtmModuleIdNo2, '/')"!]
      [!VAR "GtmChannelIdNo2" = "substring-after($GtmChannelInfoForSRV, 'TomChannel_')"!]
      [!VAR "FastCbkTimeInTicks" = "num:i($TicksPerMsForSRV2 * $FastCbkTime2)"!]
      [!VAR "SlowCbkTimeInTicks" = "num:i($TicksPerMsForSRV2 * $SlowCbkTime2)"!]
      [!CALL "Wdg_GtmTimingValidation", "FastCbkTimeInTicks" = "$FastCbkTimeInTicks", "SlowCbkTimeInTicks"="$SlowCbkTimeInTicks","WdgTimeNodeName"="num:i(2)", "MaxTicks"="num:i(65535)", "MinTicks"="num:i(2)"!]
    [!ENDIF!]
    [!ENDIF!]
    [!ENDIF!]
    [!ENDNOCODE!]
[!IF "num:i($WDGQMCOUNT) != num:i(0) "!][!//
    {
[!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!] [!//
      {
          /* GTM Configuration for WDG0 */
        
          [!"num:i($TicksPerMsForSRV0*$FastCbkTime0)"!]U, /* Fast callback period in ticks. */
          [!"num:i($TicksPerMsForSRV0*$SlowCbkTime0)"!]U, /* Slow callback period in ticks. */
          [!"num:i($FastCbkTime0)"!]U, /* Fast callback period in ms */
          [!"num:i($SlowCbkTime0)"!]U,/*  Slow callback period in ms */
          [!"$GtmChannelType0"!], /* GTM timer module */
          [!"$GtmModuleIdNo0"!]U, /* Gtm Module number that services H/W Wdg */
          [!"$GtmChannelIdNo0"!]U, /* Gtm channel number  that services H/W Wdg */
          (uint8)0U
        
      },
[!ENDIF!]
[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
 [!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!] [!//
      {
          /* GTM Configuration for WDG1 */
        
          [!"num:i($TicksPerMsForSRV1*$FastCbkTime1)"!]U, /* Fast callback period in ticks. */
          [!"num:i($TicksPerMsForSRV1*$SlowCbkTime1)"!]U, /* Slow callback period in ticks. */
          [!"num:i($FastCbkTime1)"!]U,/* Fast callback period in ms */
          [!"num:i($SlowCbkTime1)"!]U,/*  Slow callback period in ms */
          [!"$GtmChannelType1"!], /* GTM timer module */
          [!"$GtmModuleIdNo1"!]U, /* Gtm Module number that services H/W Wdg */
          [!"$GtmChannelIdNo1"!]U, /* Gtm channel number  that services H/W Wdg */
          (uint8)0U
        
      },
 [!ENDIF!]
[!ENDIF!][!// 
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!][!//
      {
        /* GTM Configuration for WDG2 */
        
        [!"num:i($TicksPerMsForSRV2*$FastCbkTime2)"!]U, /* Fast callback period in ticks. */
        [!"num:i($TicksPerMsForSRV2*$SlowCbkTime2)"!]U, /* Slow callback period in ticks. */
        [!"num:i($FastCbkTime2)"!]U,/* Fast callback period in ms */
        [!"num:i($SlowCbkTime2)"!]U,/*  Slow callback period in ms */
        [!"$GtmChannelType2"!], /* GTM timer module */
        [!"$GtmModuleIdNo2"!]U, /* Gtm Module number that services H/W Wdg */
        [!"$GtmChannelIdNo2"!]U, /* Gtm channel number  that services H/W Wdg */
       (uint8)0U
        
      }
[!ENDIF!]
[!ENDIF!] 
    },
[!ENDIF!] 
     [!NOCODE!]
     [!CALL "Wdg_MaxReloadTime", "SystemClockVal"="num:i($SystemClock)", "ClockDivider"="num:i(256)", "MaxReloadTime"="num:i(0)"!][!//
     [!CALL "Wdg_Resolution", "SystemClockVal"="num:i($SystemClock)", "ClockDivider"="num:i(256)", "Resolution"="num:i(0)"!][!//


     [!VAR "FastTimeout" = "WdgSettingsConfig/*[@index = $Index]/WdgSettingsFast/Wdg0FastModeTimeoutValue "!][!//
     [!CALL "Wdg_ReloadValue", "SystemClockVal"="num:i($SystemClock)", "TimeoutVal"="$FastTimeout", "ClockDivider"="num:i(256)", "ReloadValue"="num:i(0)"!][!//
     [!CALL "Wdg_TimingValidation", "ReloadValue"="num:i($ReloadValue)", "WdgTimeNodeName"="'Wdg0FastModeTimeoutValue'","MaxReloadTime"="$MaxReloadTime","Resolution"="$Resolution"!][!//
     [!VAR "FastModeReloadValue0" = "num:i(65536) - num:i($ReloadValue)"!]

[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
 [!VAR "FastTimeout" = "WdgSettingsConfig/*[@index = $Index]/WdgSettingsFast/Wdg1FastModeTimeoutValue "!][!//
 [!CALL "Wdg_ReloadValue", "SystemClockVal"="num:i($SystemClock)", "TimeoutVal"="$FastTimeout", "ClockDivider"="num:i(256)", "ReloadValue"="num:i(0)"!][!//
 [!CALL "Wdg_TimingValidation", "ReloadValue"="num:i($ReloadValue)", "WdgTimeNodeName"="'Wdg1FastModeTimeoutValue'","MaxReloadTime"="$MaxReloadTime","Resolution"="$Resolution"!][!//
 [!VAR "FastModeReloadValue1" = "num:i(65536) - num:i($ReloadValue)"!]
[!ENDIF!][!//

[!IF "($Wdg_MaxTimers > num:i(2))"!][!//

[!VAR "FastTimeout" = "WdgSettingsConfig/*[@index = $Index]/WdgSettingsFast/Wdg2FastModeTimeoutValue "!][!//
[!CALL "Wdg_ReloadValue", "SystemClockVal"="num:i($SystemClock)", "TimeoutVal"="$FastTimeout", "ClockDivider"="num:i(256)", "ReloadValue"="num:i(0)"!][!//
[!CALL "Wdg_TimingValidation", "ReloadValue"="num:i($ReloadValue)", "WdgTimeNodeName"="'Wdg2FastModeTimeoutValue'","MaxReloadTime"="$MaxReloadTime","Resolution"="$Resolution"!][!//
[!VAR "FastModeReloadValue2" = "num:i(65536) - num:i($ReloadValue)"!]
[!ENDIF!][!//

[!ENDNOCODE!][!//

    /* Resolution of watchdog timer in fast mode  : [!"$Resolution"!] ms
       Minimum timeout period in fast mode        : [!"$Resolution"!] ms
       Maximum timeout period in fast mode        : [!"$MaxReloadTime"!] ms */
[!IF "num:i($WDGQMCOUNT) != num:i(0) "!][!//       
    {
[!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!][!//     
      (uint16)[!"num:i($FastModeReloadValue0)"!]U, /* Fast Mode Reload Value for WDG0 */
[!ENDIF!][!//  
[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
[!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!][!//      
      (uint16)[!"num:i($FastModeReloadValue1)"!]U, /* Fast Mode Reload Value for WDG1 */
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!][!//        
      (uint16)[!"num:i($FastModeReloadValue2)"!]U  /* Fast Mode Reload Value for WDG2 */
[!ENDIF!][!//      
[!ENDIF!][!//
    },
[!ENDIF!][!//    
[!/*
    /* Configuration: WdgSlowModeTimeoutValue
       Reload value for Slow mode in milliseconds  */
*/!][!//
[!NOCODE!]
[!CALL "Wdg_MaxReloadTime", "SystemClockVal"="num:i($SystemClock)", "ClockDivider"="num:i(16384)", "MaxReloadTime"="num:i(0)"!][!//
[!CALL "Wdg_Resolution", "SystemClockVal"="num:i($SystemClock)", "ClockDivider"="num:i(16384)", "Resolution"="num:i(0)"!][!//


[!VAR "SlowTimeout" = "WdgSettingsConfig/*[@index = $Index]/WdgSettingsSlow/Wdg0SlowModeTimeoutValue "!][!//
[!CALL "Wdg_ReloadValue", "SystemClockVal"="num:i($SystemClock)", "TimeoutVal"="$SlowTimeout", "ClockDivider"="num:i(16384)", "ReloadValue"="num:i(0)"!][!//
[!CALL "Wdg_TimingValidation", "ReloadValue"="num:i($ReloadValue)", "WdgTimeNodeName"="'Wdg0SlowModeTimeoutValue'","MaxReloadTime"="$MaxReloadTime","Resolution"="$Resolution"!][!//
[!VAR "SlowModeReloadValue0" = "num:i(65536) - num:i($ReloadValue)"!]


[!IF "($Wdg_MaxTimers > num:i(1))"!][!//
[!VAR "SlowTimeout" = "WdgSettingsConfig/*[@index = $Index]/WdgSettingsSlow/Wdg1SlowModeTimeoutValue "!][!//
[!CALL "Wdg_ReloadValue", "SystemClockVal"="num:i($SystemClock)", "TimeoutVal"="$SlowTimeout", "ClockDivider"="num:i(16384)", "ReloadValue"="num:i(0)"!][!//
[!CALL "Wdg_TimingValidation", "ReloadValue"="num:i($ReloadValue)", "WdgTimeNodeName"="'Wdg1SlowModeTimeoutValue'","MaxReloadTime"="$MaxReloadTime","Resolution"="$Resolution"!][!//
[!VAR "SlowModeReloadValue1" = "num:i(65536) - num:i($ReloadValue)"!]
[!ENDIF!][!//

[!IF "($Wdg_MaxTimers > num:i(2))"!][!//

[!VAR "SlowTimeout" = "WdgSettingsConfig/*[@index = $Index]/WdgSettingsSlow/Wdg2SlowModeTimeoutValue"!][!//
[!CALL "Wdg_ReloadValue", "SystemClockVal"="num:i($SystemClock)", "TimeoutVal"="$SlowTimeout", "ClockDivider"="num:i(16384)", "ReloadValue"="num:i(0)"!][!//
[!CALL "Wdg_TimingValidation", "ReloadValue"="num:i($ReloadValue)", "WdgTimeNodeName"="'Wdg2SlowModeTimeoutValue'","MaxReloadTime"="$MaxReloadTime","Resolution"="$Resolution"!][!//
[!VAR "SlowModeReloadValue2" = "num:i(65536) - num:i($ReloadValue)"!] 
[!ENDIF!][!//

[!ENDNOCODE!][!//

    /* Resolution of watchdog timer in slow mode  : [!"$Resolution"!] ms
       Minimum timeout period in slow mode        : [!"$Resolution"!] ms
       Maximum timeout period in slow mode        : [!"$MaxReloadTime"!] ms */
[!IF "num:i($WDGQMCOUNT) != num:i(0) "!][!//         
    {
[!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!][!//
      (uint16)[!"num:i($SlowModeReloadValue0)"!]U, /* Slow Mode Reload Value for WDG0 */
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!//    
[!IF "WdgSafety/Wdg1SafetyEnable = 'false'"!][!//        
      (uint16)[!"num:i($SlowModeReloadValue1)"!]U, /* Slow Mode Reload Value for WDG1 */ 
[!ENDIF!][!//
[!ENDIF!][!//         
         
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'false'"!][!//  
      (uint16)[!"num:i($SlowModeReloadValue2)"!]U  /* Slow Mode Reload Value for WDG2 */
[!ENDIF!][!//         
[!ENDIF!][!//
    }, 
[!ENDIF!][!//

[!IF "num:i($WDGSAFECOUNT) != num:i(0)"!][!//


    {
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!][!//
[!IF "WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode = 'WDGIF_SLOW_MODE'"!][!//    
      (uint16)[!"num:i($SlowModeReloadValue0)"!]U, /* Slow Mode Reload Value for WDG0 */
[!ELSE!][!//
      (uint16)[!"num:i($FastModeReloadValue0)"!]U, /* Fast Mode Reload Value for WDG0 */
[!ENDIF!][!// 
[!ENDIF!][!// 

[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
[!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
 [!IF "WdgSettingsConfig/*[@index = $Index]/Wdg1DefaultMode = 'WDGIF_SLOW_MODE'"!][!//    
      (uint16)[!"num:i($SlowModeReloadValue1)"!]U, /* Slow Mode Reload Value for WDG1 */
 [!ELSE!][!//
      (uint16)[!"num:i($FastModeReloadValue1)"!]U,/* Fast Mode Reload Value for WDG1 */
 [!ENDIF!][!// 
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
[!IF "WdgSettingsConfig/*[@index = $Index]/Wdg2DefaultMode = 'WDGIF_SLOW_MODE'"!][!//    
      (uint16)[!"num:i($SlowModeReloadValue2)"!]U, /* Slow Mode Reload Value for WDG2 */
[!ELSE!][!//
      (uint16)[!"num:i($FastModeReloadValue2)"!]U, /* Fast Mode Reload Value for WDG2 */
[!ENDIF!][!//  
[!ENDIF!][!//  
[!ENDIF!][!//   
    }, 
[!ENDIF!][!//  

  
    /* Initial password */

[!NOCODE!][!//

[!VAR "Wdg0InitPass" = "WdgSettingsConfig/*[@index = $Index]/WdgInitialPassword/Wdg0InitialPassword"!][!//

[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
 [!VAR "Wdg1InitPass" = "WdgSettingsConfig/*[@index = $Index]/WdgInitialPassword/Wdg1InitialPassword"!][!//
  [!IF "($Wdg_MaxTimers > num:i(2))"!][!//
  [!VAR "Wdg2InitPass" = "WdgSettingsConfig/*[@index = $Index]/WdgInitialPassword/Wdg2InitialPassword"!][!//
  [!ENDIF!][!// 
[!ENDIF!][!//   
[!ENDNOCODE!][!//
[!IF "num:i($WDGSAFECOUNT) != num:i(0) "!][!//
    {
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!] [!//
      ([!"num:inttohex($Wdg0InitPass,4)"!]U), /*Initial password of WDG0  */
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
 [!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!] [!//
      ([!"num:inttohex($Wdg1InitPass,4)"!]U),/*Initial password of WDG1  */
 [!ENDIF!][!//
[!ENDIF!][!// 
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!] [!//
      ([!"num:inttohex($Wdg2InitPass,4)"!]U), /*Initial password of WDG2  */
[!ENDIF!][!//
[!ENDIF!][!//
    },
[!ENDIF!][!//
    /* Configuration : WdgDefaultMode:
       Default mode for watchdog driver initialization: WDG083:
       - WDGIF_OFF_MODE
       - WDGIF_SLOW_MODE
       - WDGIF_FAST_MODE
    */
    
[!NOCODE!][!//
[!//
[!IF "((WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode = 'WDGIF_OFF_MODE') or (WdgSettingsConfig/*[@index = $Index]/Wdg1DefaultMode = 'WDGIF_OFF_MODE') ) and (//WdgDisableAllowed = 'false')"!][!//
[!ASSERT "((WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode != 'WDGIF_OFF_MODE') and (WdgSettingsConfig/*[@index = $Index]/Wdg1DefaultMode != 'WDGIF_OFF_MODE')) or (//WdgDisableAllowed != 'false')"!][!//
 Config error: Default mode for one of the WDGs of [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured as WDGIF_OFFMODE. But watchdog disable is not allowed as per the general configuration.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//    

    {
      [!"WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode"!], /*Default Mode for WDG0 */
  [!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
         [!"WdgSettingsConfig/*[@index = $Index]/Wdg1DefaultMode"!], /*Default Mode for WDG1 */
  [!ENDIF!][!// 
[!IF "($Wdg_MaxTimers > num:i(2))"!][!// 
[!NOCODE!][!//
[!//
[!IF "((WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode = 'WDGIF_OFF_MODE') or (WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode1 = 'WDGIF_OFF_MODE') or(WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode2 = 'WDGIF_OFF_MODE') ) and (//WdgDisableAllowed = 'false')"!][!//
[!ASSERT "((WdgSettingsConfig/*[@index = $Index]/WdgDefaultMode != 'WDGIF_OFF_MODE') and (WdgSettingsConfig/*[@index = $Index]/Wdg1DefaultMode != 'WDGIF_OFF_MODE') and  (WdgSettingsConfig/*[@index = $Index]/Wdg2DefaultMode != 'WDGIF_OFF_MODE')) or (//WdgDisableAllowed != 'false')"!][!//
  Config error: Default mode for one of the WDGs of [!"node:name(WdgSettingsConfig/*[@index = $Index])"!] is configured as WDGIF_OFFMODE. But watchdog disable is not allowed as per the general configuration.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
      [!"WdgSettingsConfig/*[@index = $Index]/Wdg2DefaultMode"!] /*Default Mode for WDG2 */
[!ENDIF!][!//
    },
    
    /* TimerTolerance */
[!NOCODE!][!//
[!VAR "Wdg0TimerTol" = "WdgSettingsConfig/*[@index = $Index]/WdgTimerCheckTolerance/Wdg0TimerTolerance"!][!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
 [!VAR "Wdg1TimerTol" = "WdgSettingsConfig/*[@index = $Index]/WdgTimerCheckTolerance/Wdg1TimerTolerance"!][!//
[!ENDIF!][!// 
[!IF "($Wdg_MaxTimers > num:i(2))"!][!// 
[!VAR "Wdg2TimerTol" = "WdgSettingsConfig/*[@index = $Index]/WdgTimerCheckTolerance/Wdg2TimerTolerance"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "num:i($WDGSAFECOUNT) != num:i(0) and WdgSafety/WdgEnableTimecheck = 'true'"!] [!//
    {
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!][!//
      ([!"num:inttohex($Wdg0TimerTol,2)"!]U), /*Timer tolerance of WDG0 */
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
[!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
      ([!"num:inttohex($Wdg1TimerTol,2)"!]U), /*Timer tolerance of WDG1 */
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
     ([!"num:inttohex($Wdg2TimerTol,2)"!]U), /*Timer tolerance of WDG2 */
[!ENDIF!][!//
[!ENDIF!][!//
    },
[!ENDIF!][!//
    /*WdgSafetyProperty , 1 = WDGx safe; 0 WDGx QM */
[!NOCODE!][!//
[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!][!//
[!VAR "Wdg0Level" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Wdg0Level" = "num:i(0)"!][!//
[!ENDIF!][!//

[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
 [!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
 [!VAR "Wdg1Level" = "num:i(1)"!][!//
 [!ELSE!][!//
 [!VAR "Wdg1Level" = "num:i(0)"!][!//
 [!ENDIF!][!//
[!ENDIF!][!//
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
[!VAR "Wdg2Level" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "Wdg2Level" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
    {
      ([!"num:i($Wdg0Level)"!]U),
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
      ([!"num:i($Wdg1Level)"!]U),
[!ENDIF!][!//  
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
      ([!"num:i($Wdg2Level)"!]U),
[!ENDIF!][!//
    },
    /* WdgSafeIndex */
[!NOCODE!][!//
    [!VAR "NONSAFETY" = "num:i(255)"!][!//
    [!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!][!//
    [!VAR "SafeIndx0" = "num:i(0)"!][!//
    [!ELSE!][!//
    [!VAR "SafeIndx0" = "num:i(255)"!][!//
    [!ENDIF!][!//
 [!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
    [!IF "WdgSafety/Wdg0SafetyEnable = 'true' and WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
    [!VAR "SafeIndx1" = "num:i(1)"!][!//
    [!ELSEIF "WdgSafety/Wdg1SafetyEnable = 'true'"!][!//
    [!VAR "SafeIndx1" = "num:i(0)"!][!//
    [!ELSE!][!//
    [!VAR "SafeIndx1" = "num:i(255)"!][!//
    [!ENDIF!][!//
 [!ENDIF!][!//   
    [!IF "($Wdg_MaxTimers > num:i(2))"!][!//
    [!IF "WdgSafety/Wdg0SafetyEnable = 'true' and WdgSafety/Wdg1SafetyEnable = 'true' and WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
    [!VAR "SafeIndx2" = "num:i(2)"!][!//
    [!ELSEIF "(WdgSafety/Wdg0SafetyEnable = 'true' and WdgSafety/Wdg2SafetyEnable = 'true') or (WdgSafety/Wdg1SafetyEnable = 'true' and WdgSafety/Wdg2SafetyEnable = 'true')"!][!//
    [!VAR "SafeIndx2" = "num:i(1)"!][!//
     [!ELSEIF "WdgSafety/Wdg2SafetyEnable = 'true'"!][!//
     [!VAR "SafeIndx2" = "num:i(0)"!][!//
    [!ELSE!][!//
    [!VAR "SafeIndx2" = "num:i(255)"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "num:i($WDGSAFECOUNT) != num:i(0) "!][!//
    {
      ([!"num:i($SafeIndx0)"!]U),
[!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
      ([!"num:i($SafeIndx1)"!]U),
[!ENDIF!][!//  
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
      ([!"num:i($SafeIndx2)"!]U),
[!ENDIF!][!//
    },
[!ENDIF!][!//
    /*  WdgQmIndex*/ 
[!NOCODE!][!//
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false'"!][!//
    [!VAR "QmIndx0" = "num:i(0)"!][!//
    [!ELSE!][!//
    [!VAR "QmIndx0" = "num:i(255)"!][!//
    [!ENDIF!][!//
  [!IF "($Wdg_MaxTimers > num:i(1))"!][!// 
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false' and WdgSafety/Wdg1SafetyEnable = 'false'"!][!//
    [!VAR "QmIndx1" = "num:i(1)"!][!//
    [!ELSEIF "WdgSafety/Wdg1SafetyEnable = 'false'"!][!//
    [!VAR "QmIndx1" = "num:i(0)"!][!//
    [!ELSE!][!//
    [!VAR "QmIndx1" = "num:i(255)"!][!//
    [!ENDIF!][!//
  [!ENDIF!][!//  
    [!IF "($Wdg_MaxTimers > num:i(2))"!][!//
    [!IF "WdgSafety/Wdg0SafetyEnable = 'false' and WdgSafety/Wdg1SafetyEnable = 'false' and WdgSafety/Wdg2SafetyEnable = 'false'"!] [!//
    [!VAR "QmIndx2" = "num:i(2)"!][!//
    [!ELSEIF "(WdgSafety/Wdg0SafetyEnable = 'false' and WdgSafety/Wdg2SafetyEnable = 'false') or (WdgSafety/Wdg1SafetyEnable = 'false' and WdgSafety/Wdg2SafetyEnable = 'false')"!][!//
    [!VAR "QmIndx2" = "num:i(1)"!][!//
     [!ELSEIF "WdgSafety/Wdg2SafetyEnable = 'false'"!][!//
     [!VAR "QmIndx2" = "num:i(0)"!][!//
    [!ELSE!][!//
    [!VAR "QmIndx2" = "num:i(255)"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "num:i($WDGQMCOUNT) != num:i(0) "!][!//
    {
      ([!"num:i($QmIndx0)"!]U),
[!IF "($Wdg_MaxTimers > num:i(1))"!][!//  
      ([!"num:i($QmIndx1)"!]U),
[!ENDIF!][!//  
[!IF "($Wdg_MaxTimers > num:i(2))"!][!//
      ([!"num:i($QmIndx2)"!]U),
[!ENDIF!][!//
    }
[!ENDIF!][!//
  }[!// 
  
[!IF "$Index != num:i($No0fWdgModuleConfig)"!],[!ENDIF!]
[!ENDFOR!][!//
[!ENDSELECT!][!//
};


#define WDG_17_SCU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
