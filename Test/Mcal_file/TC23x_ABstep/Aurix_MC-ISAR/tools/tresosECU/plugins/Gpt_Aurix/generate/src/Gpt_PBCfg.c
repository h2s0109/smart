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
**  $FILENAME   : Gpt_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\23 $                                                 **
**                                                                           **
**  $DATE       : 2014-12-24 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Gpt_PBCfg.c file                        **
**                                                                           **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release 4.0.3                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY: [cover parentID=DS_NAS_GPT_PR69_PR469,DS_NAS_GPT_PR446,
    DS_NAS_GPT_PR699,DS_NAS_GPT_PR700,
    DS_NAS_GPT_PR701,DS_NAS_GPT_PR704,DS_NAS_GPT_PR707,DS_NAS_GPT_PR708,
    DS_NAS_GPT_PR712,DS_NAS_GPT_PR713,DS_NAS_GPT_PR714,DS_NAS_GPT_PR716,
    DS_NAS_GPT_PR717,DS_NAS_GPT_PR719,DS_NAS_GPT_PR720,DS_NAS_GPT_PR723,
    DS_NAS_GPT_PR724,DS_NAS_GPT_PR728,DS_NAS_GPT_PR709,
    SAS_AS4XX_GPT_PR680]
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
**  FILENAME  : Gpt_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\23 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Gpt.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GPT configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_GPT_Driver, Release AS4.0.3                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

[!NOCODE!]
[!INCLUDE "Gpt.m"!]
[!ENDNOCODE!]
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "Gpt.h"

/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/



/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

#define GPT_START_SEC_CODE
#include "MemMap.h"

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!VAR "GtmId" = "num:i(1)"!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!VAR "TotalGptConfig" = "num:i(count(GptChannelConfigSet/*))"!][!//
[!ENDSELECT!][!//
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
[!ASSERT "(num:i($TotalGptConfig) <= num:i($TotalGtmConfig))"!][!//
Configuration Error: Each GPT Channel Config Set should have corresponding GTM config set i.e. MCU Module Configration
[!ENDASSERT!][!// 
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalGptConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "node:exists(EcuMPostBuildConfigType) ='true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!//
/* 
   Channel Notification Function Declaration 
*/
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!LOOP "./GptChannelConfiguration/*"!][!//
[!IF "node:exists(GptNotification/*[1]) ='true'"!][!//
[!VAR "Notification" = "GptNotification/*[1]"!][!//
[!ASSERT "($Notification != 'NULL') and ($Notification != 'NULL_PTR') and ($Notification != '')"!][!//
ERROR: If Notification is not desired, then remove the Notification container. Notification of "NULL" , "NULL_PTR" or empty field is not allowed
[!ENDASSERT!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
/* [!"node:name(.)"!][!//
 channel notification function declaration */
extern void [!"$Notification"!](void);
[!ENDIF!][!// [!IF "$PostBuildType = 'SELECTABLE'"!]
[!ENDIF!][!// [!IF "node:exists(GptNotification/*[1]) ='true'"!]
[!ENDLOOP!][!//
[!ENDLOOP!][!//[!LOOP "./GptChannelConfigSet/*"!][!// 
[!ENDSELECT!][!//

#define GPT_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Memory Mapping the configuration constant */
#define GPT_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!VAR "ReportWakeupSource" = "GptDriverConfiguration/GptReportWakeupSource"!][!//
[!IF "$ReportWakeupSource = 'true'"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!NOCODE!][!//
[!VAR "WakeupFlag" = "'false'"!][!//
[!LOOP "GptChannelConfiguration/*"!][!//
[!IF "./GptEnableWakeup ='true'"!][!//
[!VAR "WakeupFlag" = "'true'"!][!// 
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!IF "$WakeupFlag = 'false'"!][!//
[!ERROR!][!//
Error: Wrong Configuration. You have not configured any channel for wakeup capability  in Configuration [!"node:name(.)"!]
but GptReportWakeupSource is set to true.In Post Build configuration, if GptReportWakeupSource is set and One configuration has 
wakeup capable channel then all the configurations should have atleast one wakeup capable channel.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!VAR "McuIndex"  = "num:i(0)"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!VAR "GptIndex" = "@index"!][!//
[!/*
 If any of the channel needs to be wakeup capable then 
 Gtm Clock should have the capability to disable GTM Clock Sleep mode
 when sleep mode is requested.
*/!][!SELECT "as:modconf('Mcu')[1]"!][!//
[!/* Access Gtm Clock Sleep Mode
*/!][!VAR "GtmSelectIndex" = "concat('McuModuleConfiguration/*[',$McuIndex+1,']')"!][!//
[!SELECT "node:ref($GtmSelectIndex)"!][!//
[!VAR "GtmSleepMode" = "./GtmConfiguration/*[1]/GtmGeneral/GtmSleepMode"!][!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
[!VAR "GptChannelCount" = "num:i(0)"!][!//
[!VAR "GptChannelCountConfigured" = "num:i(count(GptChannelConfiguration/*))"!][!//
/* 
   Channel Configuration Instance [!"node:name(.)"!]
*/ 
[!VAR "MaxChannels"= "num:i(count(GptChannelConfiguration/*))"!][!//
static const Gpt_ChannelConfigType Gpt_kChannelConfig[!"@index"!][ ] =
{
[!FOR "ChannelId" = "num:i(1)" TO "num:i($MaxChannels)"!][!//
[!SELECT "GptChannelConfiguration/*[GptChannelId = num:i($ChannelId) - num:i(1)]"!][!//
[!//[!LOOP "./GptChannelConfiguration/*"!][!//
[!VAR "EnableWakeup" = "GptEnableWakeup"!][!//
[!ASSERT "not($EnableWakeup = 'true' and $GtmSleepMode = 'GTM_SLEEP_ENABLE')"!][!// 
Configuration Error: Gtm Clock is not configured with Sleep Disable request in ConfigSet[!"$McuIndex"!]. But GPT is having a wakeup capable channel in ConfigSet[!"$McuIndex"!]. Change the gtm clock configuration
[!ENDASSERT!][!//
[!VAR "TimerType" = "GptAssignedHwUnit"!][!//
[!NOCODE!][!//
[!IF "node:exists(GptNotification/*[1]) ='true'"!][!//
[!VAR "Notification" = "GptNotification/*[1]"!][!//
[!ENDIF!][!//
[!IF "node:exists(GptNotification/*[1]) !='true'"!][!//
  [!VAR "Notification" = "'NULL_PTR'"!][!//
[!ELSE!][!//
  [!IF "$PostBuildType != 'SELECTABLE'"!][!//
  [!ASSERT "num:isnumber($Notification)= 'true'"!][!//
   ERROR: Under LOADABLE option GptNotification should be entered as a Address. Change notification of channel [!"node:name(.)"!]
  [!ENDASSERT!][!//
  [!VAR "Notification" = "concat('(Gpt_NotificationPtrType)',$Notification)"!][!//
  [!ELSE!][!//
  [!ASSERT "num:isnumber($Notification)!= 'true'"!][!//
   ERROR: Under SELECTABLE option GptNotification should be entered as a function name. Change notification of channel [!"node:name(.)"!]
  [!ENDASSERT!][!//
  [!VAR "Notification" = "concat('&',$Notification)"!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!VAR "WakeupInfo" = "num:i(0)"!][!//
[!IF "node:value(../../../../GptDriverConfiguration/GptReportWakeupSource) = 'true' and node:value(./GptEnableWakeup) = 'true'"!][!//
 [!IF "node:exists(./GptWakeupConfiguration/*[1]/GptWakeupSourceRef) ='true' and string-length(./GptWakeupConfiguration/*[1]/GptWakeupSourceRef) > 0"!][!//
    [!VAR "nodepath" = "node:path(node:ref(./GptWakeupConfiguration/*[1]/GptWakeupSourceRef))"!][!//
  [!SELECT "node:ref($nodepath)"!][!//
  [!VAR "WakeupInfo" = "(EcuMWakeupSourceId)"!][!//
  [!ENDSELECT!][!//
 [!ELSE!][!//
  [!ERROR!][!//
Config Error: GptWakeupSourceRef is not configured for wakeup capable channel [!"node:path(node:current())"!].If wakeup functionality is needed,Provide reference to EcuM Wakeup source otherwise disable wakeup feature for the channel by unchecking GptEnableWakeup.  
  [!ENDERROR!][!//
 [!ENDIF!][!//
[!ENDIF!][!//
[!VAR "EnableWakeup" = "GptEnableWakeup"!][!//
[!IF "$EnableWakeup = 'true'"!][!//
[!VAR "EnableWakeup" = "'(boolean)TRUE'"!][!//
[!ELSE!][!//
[!VAR "EnableWakeup" = "'(boolean)FALSE'"!][!//
[!ENDIF!][!//
[!IF "node:refexists(./GptAssignedHwUnit) ='true'"!][!//
[!VAR "nodepath" = "node:path(node:ref(./GptAssignedHwUnit))"!][!//
[!CALL "CG_GetIndex","M_nodename" = "GptAssignedHwUnit","M_ConfigSetIndex" = "$GptIndex"!][!//	
[!VAR "PeriodCell" = "node:name(node:ref(./GptAssignedHwUnit))"!][!//
[!CALL "CG_GetHwUnitGtmVal","nodepath" = "$nodepath"!][!//
[!ASSERT "$ErrorConfig != 1"!][!//
Error: Gpt Channel is not Configured from TOM/ATOM for the channel [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ELSE!][!//
[!ERROR!][!//
Gtm Channel not Configured for the channel [!"node:name(.)"!]
[!ENDERROR!][!//
[!ENDIF!][!//
[!//
[!VAR "ChannelMode" = "GptChannelMode"!][!//
[!IF "$ChannelMode = 'GPT_CH_MODE_CONTINUOUS'"!][!//
[!VAR "ChannelMode" = "'GPT_MODE_CONTINUOUS'"!][!//
[!ENDIF!][!//
[!IF "$ChannelMode = 'GPT_CH_MODE_ONESHOT'"!][!//
[!VAR "ChannelMode" = "'GPT_MODE_ONESHOT'"!][!//
[!ENDIF!][!//
[!VAR "GptMcuClockRef" = "node:path(node:ref(./GptAssignedHwUnit))"!][!//
[!IF "contains($GptMcuClockRef, '/Tom/') = 'true'"!][!//
[!VAR "GptChannelClock_freq" ="node:ref($GptMcuClockRef)/TomChannelTimerParameters/TomChannelClockSelect"!][!//
[!ELSEIF "contains($GptMcuClockRef, '/Atom/') = 'true'"!][!//
[!VAR "GptChannelClock_freq" ="node:ref($GptMcuClockRef)/AtomChannelTimerParameters/AtomChannelClockSelect"!][!//
[!ENDIF!][!//
[!VAR "SignalType" = "GptSignalType"!][!//
[!IF "$SignalType = 'GPT_QM_SIGNAL'"!][!//
[!VAR "SignalType" = "'GPT_QM_SIGNAL'"!][!//
[!ENDIF!][!//
[!IF "$SignalType = 'GPT_ASIL_SIGNAL'"!][!//
[!VAR "SignalType" = "'GPT_ASIL_SIGNAL'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
  /* Channel Symbolic Name(ChannelId) : [!"node:name(.)"!] 
     GTM TOM/ATOM Channel : [!"$GlobalChannelNumber"!] in [!"$ChannelMode"!]
  */ 
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    [!"$Notification"!], /* Notification Function */
    #endif
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
        && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    [!"$WakeupInfo"!]U, /* Wakeup Info */
    #endif
    /* Assigned Hardware Unit */
    [!"$GlobalChannelNumber"!],
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    [!"$EnableWakeup"!], /* Wakeup Capability */
    #endif
    [!"$ChannelMode"!], /* Channel Mode */
    #if (GPT_SAFETY_ENABLE == STD_ON)
    [!"$SignalType"!], /* Channel Signal Type */
    #endif
    [!"$GptChannelClock_freq"!] /* Channel Clock frequency */
[!VAR "GptChannelCount" = "num:i($GptChannelCount + 1)"!][!//
  }[!IF "$GptChannelCount != $GptChannelCountConfigured"!],[!ENDIF!][!//
[!//[!ENDLOOP!][!// GptChannelConfiguration
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!VAR "McuIndex" = "num:i($McuIndex+1)"!][!//
[!ENDLOOP!][!// 
[!ENDSELECT!][!//
[!// GPT_CR_016: GptEnableDisableNotificationApi is Significant only if GptNotification 
[!// for any one of the channels is not NULL
[!NOCODE!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//"!][!//
[!VAR "NotifApi" = "GptConfigurationOfOptApiServices/GptEnableDisableNotificationApi"!][!//
[!VAR "Initialval" = "num:i(0)"!][!//
[!VAR "TotalGptChannel" = "num:i(0)"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
[!VAR "TotalGptChannelSet" = "num:i(count(GptChannelConfiguration/*))"!][!// 
[!VAR "TotalGptChannel" = "$TotalGptChannel + $TotalGptChannelSet"!]
[!LOOP "./GptChannelConfiguration/*"!][!// 
  [!IF "node:exists(GptNotification/*[1]) !='true'"!][!//
  [!VAR "Notification" = "'NULL_PTR'"!][!//     
  [!VAR "Initialval" = "$Initialval + 1"!][!//   
  [!VAR "Initialval" = "num:i($Initialval)"!][!//
  [!ELSE!][!//
  [!VAR "Notification" = "./GptNotification/*[1]"!][!//   
  [!ENDIF!][!//
  [!ENDLOOP!][!//[!LOOP "./GptChannelConfiguration/*"!][!// 
  [!ENDLOOP!][!//[!LOOP "./GptChannelConfigSet/*"!][!// 
[!ENDSELECT!][!//

  [!VAR "TotalGptChannel" = "num:i($TotalGptChannel)"!][!// 
  [!IF "$Initialval = $TotalGptChannel and $NotifApi = 'true' "!][!//
  [!ASSERT "$Initialval != $TotalGptChannel and $NotifApi = 'false'"!][!//
  ERROR: Wrong configuration. None of the channel contain valid Notification function name then GptEnableDisableNotificationApi should be false.
  [!ENDASSERT!][!//
  
  [!ELSEIF "$Initialval != $TotalGptChannel and $NotifApi = 'false'"!][!//  
  [!ASSERT "$NotifApi = 'true'"!][!//
  ERROR: Wrong configuration. if Any one channel has valid Notification function name, then GptDisableEnableNotificationApi should be true.
  [!ENDASSERT!][!//   
  [!ENDIF!][!//     
[!ENDNOCODE!][!//

/* 
Configuration: Configuration  
 Definition of Gpt_ConfigType structure
*/
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(GptChannelConfigSet/*))"!][!//
[!ENDSELECT!][!//
const Gpt_ConfigType Gpt_ConfigRoot[[!"$ConfigCount"!]] = 
{
[!SELECT "as:modconf('Gpt')[1]"!][!//"!][!//
[!LOOP "./GptChannelConfigSet/*"!][!//
  {  
    #if (GPT_SAFETY_ENABLE == STD_ON)
    (uint32)GPT_MODULE_ID << 16U,  
    #endif
    Gpt_kChannelConfig[!"@index"!],
[!NOCODE!][!//
  [!VAR "MaxChannels" = "num:i(count(GptChannelConfiguration/*))"!][!//
[!ENDNOCODE!][!// 
    [!"$MaxChannels"!]U,
[!IF "not(node:islast())"!][!//   
  },
[!ELSE!][!//
}
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
};

#define GPT_STOP_SEC_POSTBUILDCFG
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
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
