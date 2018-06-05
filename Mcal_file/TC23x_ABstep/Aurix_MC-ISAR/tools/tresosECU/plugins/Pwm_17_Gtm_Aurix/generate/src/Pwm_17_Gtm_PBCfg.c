[!/*****************************************************************************
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
**  $FILENAME  : Pwm_17_Gtm_PBCfg.c $                                         **
**                                                                            **
**   $CC VERSION : \main\39 $                                                 **
**                                                                            **
**  $DATE      : 2013.08.27 $                                                **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for Pwm_17_Gtm_PBCfg.c file                  **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  TRACEABILITY: [cover parentID=DS_NAS_PWM_PR723,DS_NAS_PWM_PR699,
                   DS_NAS_PWM_PR700,DS_NAS_PWM_PR701,DS_NAS_PWM_PR704,
                   DS_NAS_PWM_PR707,DS_NAS_PWM_PR708,DS_NAS_PWM_PR709,
                   DS_NAS_PWM_PR712,DS_NAS_PWM_PR717,DS_NAS_PWM_PR724,
                   DS_NAS_PWM_PR728,DS_NAS_PWM_PR716,DS_MCAL_PWM_0901,
                   SAS_AS4XX_PWM_PR680]                                       **
**                                                                            **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
*************************************************************************/!][!//
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
**  $ FILENAME  : Pwm_17_Gtm_PBCfg.c $                                        **
**                                                                            **
**  $CC VERSION : \main\39 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**  DESCRIPTION  : PWM configuration generated out of ECU configuration       **
**                   file                                                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/
[!NOCODE!]
[!INCLUDE "Pwm_17_Gtm.m"!][!//
[!ENDNOCODE!]

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include module header File */ 
#include "Pwm_17_Gtm.h"
#include "Gtm.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*Notes on Requirements:
PWM040: General Limitation: All Channels should have same frequency
        to be observed by the user.
*/
/*
Configuration:
PWM Channel Configuration:
Elements / Attributes
1. Notification function pointer (if required)
2. Shift Value, only for PWM_FIXED_PERIOD_SHIFTED Class
   Input a value between 0 and 0x8000.
3. Default Duty Cycle ( duty cycle value between
   0 and 0x8000)
4. Pwm_Period:
   Enter in ticks
   PWM070: All time units should be in ticks.
5. Pwm_ConfigChannel:
   Go in the following parameter order
   a) Reference to Channel Number, for a Shifted, Center Aligned and
   Zero Shifted channel, a reference must be given. For a variable
   and Fixed Period channel class, reference should not be given.
   Reference should be given in the form of channel number index.
   b) Channel Class
      Possible Options: PWM_FIXED_PERIOD, PWM_FIXED_PERIOD_SHIFTED,
      PWM_FIXED_PERIOD_CENTER_ALIGNED, PWM_VARIABLE_PERIOD
   c) Channel Idle State:
      Possible Options: PWM_LOW, PWM_HIGH
      Output line goes into Idle state either after Pwm_SetOutputtoIdle
      or Pwm_DeInit.
   d) Channel Polarity:
      Possible Options: PWM_LOW, PWM_HIGH
      Initial Polarity state of the channel.
   e) Assigned HW Resource:
      TOM/ATOM Channel Number.
6. PwmSafetySignalType to indicate Chanel is ASIL or QM
   Needed only when safety is enabled
7. PwmSafetyChannelIndex to store the channel index of
   ASIL or QM signal.
 */

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*
Function Like Macro:Pwm_lConfigChannel
Macro that packs the PWM Channel Information.
Input Parameters:
ShiftReset: Shifted channel is reset by itself or by other channel
ShiftedSpl: Special handling of shifted channel is enabled or not
IsReferenceChannel:Is the channel reference to other channel or not
ReferenceChannel : Reference Channel
ChannelClass : Channel Class
ChannelCoherency : Channel Coherency
IdleState : Idle State
Polarity : Channel Polarity
AssignedHwUnit : Hardware Unit Used
*/ 
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro is uded to reduce the 
  memory usage*/
#define Pwm_lConfigChannel(ShiftReset,                   \
                           ShiftedSpl,                   \
                           IsReferenceChannel,           \
                           ReferenceChannel,             \
                           ChannelClass,                 \
                           ChannelCoherency,             \
                           IdleState,                    \
                           Polarity,                     \
                           AssignedHwUnit)               \
              ((uint32)( ((uint32)(ShiftReset) << 22UL)         |   \
                         ((uint32)(ShiftedSpl) << 21UL)         |   \
                         ((uint32)(IsReferenceChannel) << 20UL) |   \
                         ((uint32)(ReferenceChannel) << 13UL)   |   \
                         ((uint32)(ChannelClass) << 11UL)       |   \
                         ((uint32)(ChannelCoherency) << 10UL)   |   \
                         ((uint32)(IdleState) << 9UL)           |   \
                         ((uint32)(Polarity) << 8UL)            |   \
                         ((uint32)(AssignedHwUnit))                 \
                       )) 

/******************************************************************************/
#define PWM_17_GTM_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
  allowed only for MemMap.h*/
#include "MemMap.h"
/******************************************************************************/
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "PwmFixedPeriodName" = "'PWM_FIXED_PERIOD'"!][!//
[!VAR "TotalPwmConfig" = "num:i(count(PwmChannelConfigSet/*))"!][!//
[!VAR "PwmHandleShiftOffset" = "'false'"!][!//
[!IF "node:exists(PwmGeneral/PwmHandleShiftByOffset ) = 'true'"!][!//
[!IF "PwmGeneral/PwmHandleShiftByOffset  = 'true'"!]
[!VAR "PwmHandleShiftOffset" = "'true'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfig)"!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalPwmConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!VAR "DutyCycleEndPeriodNeeded" = "'false'"!][!//
[!VAR "PeriodEndPeriodNeeded" = "'false'"!][!//
[!IF "node:exists(./PwmGeneral/PwmDutycycleUpdatedEndperiod) = 'true'"!][!//
[!VAR "DutyCycleEndPeriodNeeded" = "node:value(./PwmGeneral/PwmDutycycleUpdatedEndperiod)"!][!//
[!ENDIF!][!//
[!IF "node:exists(./PwmGeneral/PwmPeriodUpdatedEndperiod) = 'true'"!][!//
[!VAR "PeriodEndPeriodNeeded" = "node:value(./PwmGeneral/PwmPeriodUpdatedEndperiod)"!][!//
[!ENDIF!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "PwmChannelConfigSet/*[num:i($PwmId)]"!][!//
[!//
[!NOCODE!]
[!VAR "Notification" = "'STD_OFF'"!]
[!IF "../../PwmGeneral/PwmNotificationSupported = 'true'"!]
[!VAR "Notification" = "'STD_ON'"!]
[!ENDIF!]

[!VAR "PwmGroupEnable" = "'STD_OFF'"!]
 [!IF "../../PwmConfigurationOfOptApiServices/PwmSyncGrpUpdateDutiesApi = 'true'"!]
   [!VAR "PwmGroupEnable" = "'STD_ON'"!]
 [!ENDIF!]

 [!VAR "Safety" = "'STD_OFF'"!]
 [!IF "../../PwmSafety/PwmSafetyEnable = 'true'"!]
   [!VAR "Safety" = "'STD_ON'"!]
 [!ENDIF!]
[!// Read the PwmDutyShiftInTicks value to find if duty and shift are in absolute ticks
[!VAR "DutyShiftInTicks" = "'false'"!][!//
[!IF "node:exists(../../PwmGeneral/PwmDutyShiftInTicks) = 'true'"!][!//
[!VAR "DutyShiftInTicks" = "../../PwmGeneral/PwmDutyShiftInTicks"!][!//
[!ENDIF!][!//

[!VAR "NumberofChannels" = "num:i(count(PwmChannel/*))"!][!//
[!ENDNOCODE!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!LOOP "PwmChannel/*"!][!//
[!IF "$Notification = 'STD_ON'"!][!//
[!IF "node:exists(./PwmNotification/*[num:i(1)]) = 'true'"!][!//
[!VAR "Notify" = "./PwmNotification/*[num:i(1)]"!][!//
[!ELSE!][!//
[!VAR "Notify" = "'(Pwm_17_Gtm_NotifiPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "string-length($Notify) = 0"!][!//
[!VAR "Notify" = "'(Pwm_17_Gtm_NotifiPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "$Notify = '"NULL_PTR"' or $Notify = 'NULL_PTR'"!][!//
[!VAR "Notify" = "'(Pwm_17_Gtm_NotifiPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "$Notify != '(Pwm_17_Gtm_NotifiPtrType)0'"!][!//
extern void [!"$Notify"!] (void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!VAR "MaxChannels"= "num:i(count(PwmChannel/*))"!][!//
static const Pwm_17_Gtm_ChannelConfigType Pwm_kChannelConfiguration[!"string(($PwmId)-num:i(1))"!][] = 
{
[!VAR "PwmQmcounter" = "num:i(0)"!][!//
[!VAR "PwmAsilcounter" = "num:i(0)"!][!//
[!FOR "ChannelId" = "num:i(1)" TO "num:i($MaxChannels)"!][!//
[!SELECT "PwmChannel/*[PwmChannelId = num:i($ChannelId) - num:i(1)]"!]
[!NOCODE!]
[!VAR "Notify" = "'(Pwm_17_Gtm_NotifiPtrType)0'"!][!//
[!IF "$Notification = 'STD_ON'"!][!//
[!IF "node:exists(./PwmNotification/*[num:i(1)]) = 'true'"!][!//
[!VAR "Notify" = "./PwmNotification/*[num:i(1)]"!][!//
[!ELSE!][!//
[!VAR "Notify" = "'NULL_PTR'"!][!//
[!ENDIF!][!//
[!IF "string-length($Notify) = 0 or $Notify = '"NULL_PTR"' or $Notify = 'NULL_PTR'"!]
[!VAR "Notify" = "'NULL_PTR'"!]
[!ELSE!][!//
  [!IF "$PostBuildType != 'SELECTABLE'"!][!//
    [!ASSERT "num:isnumber($Notify) = 'true'"!]
     ERROR: Under LOADABLE option PwmNotification should be entered as a Address. Change notification of [!"node:name(.)"!]
    [!ENDASSERT!][!//
    [!VAR "Notify" = "concat('(Pwm_17_Gtm_NotifiPtrType)',$Notify,'U')"!]
  [!ELSE!][!//
    [!ASSERT "num:isnumber($Notify)!= 'true'"!]
     ERROR: Under SELECTABLE option PwmNotification should be entered as a function name. Change notification of [!"node:name(.)"!]
    [!ENDASSERT!][!//
    [!VAR "Notify" = "concat('&',$Notify)"!]
  [!ENDIF!][!//
[!ENDIF!]
[!ENDIF!][!//
[!VAR "ShiftValue" = "num:i(0)"!][!//
[!VAR "PeriodValue" = "'0.0'"!][!//
[!ASSERT "node:exists(./PwmChannelClass/*[num:i(1)]) = 'true'"!][!//
Config Error: Pwm Channel class (PwmChannelClass) is not provided in [!"node:name(.)"!][!//
[!ENDASSERT!][!//
[!VAR "class" = "./PwmChannelClass/*[num:i(1)]"!][!//

[!VAR "classvalue" = "$class"!][!//

[!// Read the local coherent update value for this channel(true/false)
[!VAR "ChannelCoherency" = "'STD_OFF'"!][!//
[!IF "node:exists(PwmCoherentUpdate) = 'true'"!][!//
  [!IF "PwmCoherentUpdate = 'true'"!][!//
  [!VAR "ChannelCoherency" = "'STD_ON'"!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!IF "$DutyCycleEndPeriodNeeded = 'true'"!][!//
[!IF "./PwmChannelClass/*[num:i(1)] != 'PWM_VARIABLE_PERIOD'"!][!//
[!IF "$DutyCycleEndPeriodNeeded = 'true'"!][!//
[!VAR "ChannelCoherency" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$PeriodEndPeriodNeeded = 'true'"!][!//
[!IF "./PwmChannelClass/*[num:i(1)] = 'PWM_VARIABLE_PERIOD'"!][!//
[!IF "$PeriodEndPeriodNeeded = 'true'"!][!//
[!VAR "ChannelCoherency" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(./PwmReferenceChannel)"!][!//
[!VAR "RefShiftChn" = "node:path(node:ref(./PwmReferenceChannel))"!][!//
[!IF "node:exists(node:ref($RefShiftChn)/PwmCoherentUpdate)"!][!//
[!VAR "ChannelCoherency" = "node:ref($RefShiftChn)/PwmCoherentUpdate"!][!//
  [!IF "$ChannelCoherency = 'true'"!][!//
  [!VAR "ChannelCoherency" = "'STD_ON'"!][!//
  [!ELSE!][!//
  [!VAR "ChannelCoherency" = "'STD_OFF'"!][!//
  [!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!// Read the GTM Module number
[!VAR "val" = "num:i(0)"!][!//
[!ASSERT "node:refexists(./PwmAssignedHwUnit) = 'true'"!][!//
ERROR: PWM: [!"@name"!] : TOM/ATOM channel not provided, configure AssignedHwUnit
[!ENDASSERT!][!//
[!VAR "nodepath" = "node:path(node:ref(./PwmAssignedHwUnit))"!]
[!VAR "nodeval" = "node:name(node:ref(./PwmAssignedHwUnit))"!]
[!CALL "CG_GetHwUnitGtmVal","nodepath" = "$nodepath", "nodeval" = "$nodeval"!][!//
[!VAR "AssignedHw" = "$GlobalChannelNumber"!][!//

[!VAR "IsReference" = "num:i(0)"!][!//
[!IF "$classvalue = 'PWM_FIXED_PERIOD'"!][!//
[!VAR "currentnode" = "@name"!][!//
/*UTP:AI00112690 & AI00111943*/
[!FOR "counter1" = "num:i(0)" TO "num:i($NumberofChannels) - num:i(1)"!][!//
[!SELECT "../../PwmChannel/*[PwmChannelId = num:i($counter1)]"!][!//
[!VAR "classvalue1" = "./PwmChannelClass/*[num:i(1)]"!][!//
[!IF "$classvalue1 = 'PWM_FIXED_PERIOD_SHIFTED' or $classvalue1 = 'PWM_FIXED_PERIOD_CENTER_ALIGNED'"!][!//
[!VAR "refchannelid" = "(node:ref(./PwmReferenceChannel)/PwmChannelId)"!][!//
[!IF "num:i($ChannelId) = num:i($refchannelid) + num:i(1)"!][!//
[!ASSERT "num:i($ChannelId) < (num:i($counter1) + num:i(1) )"!][!//
ERROR: PwmChannelId of  [!"$currentnode"!] should be less than the PwmChannelId of [!"@name"!]
[!ENDASSERT!][!//
[!VAR "IsReference" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "refindex" = "'PWM_NOT_REFERENCED'"!][!//
[!IF "$classvalue = 'PWM_FIXED_PERIOD_SHIFTED' or $classvalue = 'PWM_FIXED_PERIOD_CENTER_ALIGNED'"!][!//
[!VAR "currentnode" = "@name"!][!//
[!VAR "refnode" = "node:name(node:ref(./PwmReferenceChannel))"!][!// 
/*ASSERT: PWM_CR_033 - Reference channel must be provided for shifted or centre aligned or zero shifted channel*/
[!ASSERT "not(string-length($refnode) = 0)", "Reference channel must be provided for shifted or centre aligned"!][!//
[!ASSERT "not($refnode = $currentnode)", "Reference Channel cannot be the same channel"!][!//
[!FOR "counter" = "num:i(0)" TO "num:i($NumberofChannels) - num:i(1)"!][!//
[!IF "$refnode = node:name(as:modconf('Pwm')[1]/PwmChannelConfigSet/*[num:i($PwmId)]/PwmChannel/*[@index = $counter])"!][!//
[!VAR "refindex" = "concat("Pwm_17_GtmConf_PwmChannel_",$refnode)"!][!//
/*ASSERT PWM_CR_034 - A referred channel can only be of Fixed Period Class*/
[!ASSERT "as:modconf('Pwm')[1]/PwmChannelConfigSet/*[num:i($PwmId)]/PwmChannel/*[@index = $counter]/PwmChannelClass/*[num:i(1)] = $PwmFixedPeriodName", "A referred channel can only be of Fixed Period Class"!][!//

[!VAR "RefShiftChn" = "num:i(0)"!][!//
[!VAR "RefPeriod" = "num:i(0)"!][!//
[!IF "$classvalue = 'PWM_FIXED_PERIOD_SHIFTED'"!][!//
[!VAR "ShiftValue" = "./PwmShiftValue"!][!//
[!IF "($DutyShiftInTicks = 'true')"!][!//
[!ASSERT "(node:refexists(./PwmReferenceChannel) = 'true')"!][!//
ERROR: PWM: Reference Channel is provided for PWM channel number [!"PwmChannelId"!]
[!ENDASSERT!][!//
[!VAR "RefShiftChn" = "node:path(node:ref(./PwmReferenceChannel))"!][!//
[!VAR "RefPeriod"= "node:ref($RefShiftChn)/PwmPeriodDefault"!][!//
[!ASSERT "$ShiftValue <= $RefPeriod"!][!//
ERROR: PWM Channel[!"PwmChannelId"!] ShiftValue is greater than Reference Period. Enter number less than or equal to Reference Period
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!VAR "refpath" = "node:path(node:ref(node:ref(./PwmReferenceChannel)/PwmAssignedHwUnit))"!][!//
[!VAR "refname" = "node:name(node:ref(node:ref(./PwmReferenceChannel)/PwmAssignedHwUnit))"!][!//
[!VAR "val" = "num:i(0)"!][!//
[!CALL "CG_GetHwUnitGtmVal","nodepath" = "$refpath", "nodeval" = "$refname"!][!//
[!VAR "refAssignedHw" = "num:i($val)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!VAR "DutyCycle" = "./PwmDutycycleDefault"!][!//
[!IF "($DutyShiftInTicks = 'true')"!][!//
[!VAR "PwmModuleLocation4Duty" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!//
[!VAR "PwmModuleNumber4Duty" = "text:split($PwmModuleLocation4Duty, '_')[position()-1 = 1]"!][!//
[!VAR "PwmModuleType4Duty" = "text:split($PwmModuleLocation4Duty, '_')[position()-1 = 0]"!][!//
[!IF "$PwmModuleType4Duty = 'Tom'"!][!//
[!ASSERT "$DutyCycle < num:i(65535)"!][!//
Config Error: In TOM[!"$PwmModuleNumber4Duty"!] Duty cycle value is greater than maximum allowed value 
[!ENDASSERT!][!//
[!ELSEIF "$PwmModuleType4Duty = 'Atom'"!][!//
[!ASSERT "$DutyCycle < num:i(16777215)"!][!//
Config Error: In ATOM[!"$PwmModuleNumber4Duty"!] Duty cycle value is greater than maximum allowed value 
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "PeriodValue" = "num:i(0)"!][!//
[!IF "node:exists(./PwmPeriodDefault)"!][!//
[!VAR "PeriodValue" = "./PwmPeriodDefault"!][!//
[!ENDIF!][!//
[!VAR "idlestate" = "./PwmIdleState"!][!//
[!VAR "polarity" = "./PwmPolarity"!][!//

[!VAR "ShiftedSpl" = "num:i(0)"!][!//
[!IF "$PwmHandleShiftOffset  = 'true'"!]
  [!IF "$classvalue = 'PWM_FIXED_PERIOD_SHIFTED' or $classvalue = 'PWM_FIXED_PERIOD'"!][!//
    [!VAR "ShiftedSpl" = "num:i(1)"!][!//
  [!ELSE!][!//
    [!VAR "ShiftedSpl" = "num:i(0)"!][!//
  [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "ShiftedSpl" = "num:i(0)"!][!//
[!ENDIF!][!//

[!VAR "ShiftReset" = "num:i(0)"!][!//
[!IF "$PwmHandleShiftOffset  = 'true'"!]
  [!IF " $classvalue = 'PWM_FIXED_PERIOD_CENTER_ALIGNED'"!][!//
    [!VAR "ShiftReset" = "num:i(1)"!][!//
  [!ELSE!][!//
      [!VAR "ShiftReset" = "num:i(0)"!][!//
    [!ENDIF!][!//  
[!ELSE!][!//
  [!IF "$classvalue = 'PWM_FIXED_PERIOD_SHIFTED' or $classvalue = 'PWM_FIXED_PERIOD_CENTER_ALIGNED'"!][!//
    [!VAR "ShiftReset" = "num:i(1)"!][!//
  [!ELSE!][!//
    [!VAR "ShiftReset" = "num:i(0)"!][!//
  [!ENDIF!][!//
[!ENDIF!][!//


/*ASSERT PWM_CR_035 - Reference not provided for PwmAssignedHwUnit*/
[!ASSERT "(node:refexists(./PwmAssignedHwUnit) = 'true')"!][!//
ERROR: PWM: GTM TOM/ATOM channel not provided configure AssignedHwUnit
[!ENDASSERT!][!//
[!VAR "ChannelSignalType" = "num:i(0)"!][!//
[!IF "node:exists(./PwmSafetySignal)"!][!//
[!VAR "ChannelSignalType" = "./PwmSafetySignal"!][!//
 [!IF "$ChannelSignalType = 'PWM_ASIL_TYPE'"!][!//
 [!VAR "ChannelSignalType" = "'PWM_ASIL_TYPE'"!][!//
 [!ELSE!][!//
 [!VAR "ChannelSignalType" = "'PWM_QM_TYPE'"!][!//
 [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* 
 *  Channel Number        : [!"PwmChannelId"!]
 *  Channel Symbolic Name : Pwm_17_GtmConf_PwmChannel_[!"node:name(.)"!] 
 *  Channel Class         : [!"$classvalue"!]
*/
  {
[!IF "$Notification = 'STD_ON'"!][!//
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
[!"$Notify"!], /* Notification function */
#endif
[!ENDIF!][!//
    Pwm_lConfigChannel(
                        [!"$ShiftReset"!]U,/* Channel reset from other channel or not*/
                        [!"$ShiftedSpl"!]U,/*Shift special handling*/
                        [!"$IsReference"!]U,/* if it is fixed channel is it also a reference
                         channel to shift/centre aligned channel */
                        [!"$refindex"!],
                        /* reference to the channel number */
                        [!"$classvalue"!],/* Channel Class */
                        [!"$ChannelCoherency"!],/* Coherency */
                        [!"$idlestate"!], /* channel Idle state */
                        [!"$polarity"!], /* channel polarity */
                        [!"$AssignedHw"!] /* channel hardware resource */
                      ),
    (Pwm_17_Gtm_PeriodType)[!"num:i($PeriodValue)"!], /* Default Period */
    (uint32)[!"$DutyCycle"!], /* Default Duty Cycle */
    (uint32)[!"$ShiftValue"!], /* Shift Value */
[!IF "$Safety = 'STD_ON'"!][!//
    #if (PWM_SAFETY_ENABLE == STD_ON)
    (uint8)[!"$ChannelSignalType"!], /* Channel Signal Type */
    #endif
[!ENDIF!][!//
[!IF "$ChannelSignalType = 'PWM_QM_TYPE'"!][!//
    (uint8)[!"$PwmQmcounter"!]  /*Qm Channel Index*/
[!VAR "PwmQmcounter" = "num:i(($PwmQmcounter) + 1)"!][!//
[!ELSEIF "$ChannelSignalType = 'PWM_ASIL_TYPE'"!][!//
    (uint8)[!"$PwmAsilcounter"!]  /*Asil Channel Index*/
[!VAR "PwmAsilcounter" = "num:i(($PwmAsilcounter) + 1)"!][!//
[!ENDIF!][!//
  }[!IF "$ChannelId != $MaxChannels"!],[!ENDIF!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!]
[!ENDSELECT!]

[!IF "$PwmGroupEnable = 'STD_ON'"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfig)"!][!//
[!SELECT "PwmChannelConfigSet/*[num:i($PwmId)]"!][!//
[!VAR "PwmIdForIndex" = " num:i(($PwmId) - num:i(1))"!][!//
[!ASSERT "(node:exists(./PwmSyncGroup/*) = 'true')"!][!//
ERROR: PWM: Atleast one group needs to be configured in case if PwmSyncGrpUpdateDutiesApi feature is enabled.Please check PwmChannelConfigSet_[!"$PwmIdForIndex"!] [!//
[!ENDASSERT!][!//
[!LOOP "PwmSyncGroup/*"!][!//
[!ASSERT "(node:exists(./PwmGroupChannels/*[num:i(2)]) = 'true')"!][!//
ERROR: PWM: Minimum two channels are needed to be configured in a PWM group if PwmSyncGrpUpdateDutiesApi feature is enabled.Please check PwmChannelConfigSet_[!"$PwmIdForIndex"!] [!//
[!ENDASSERT!][!//
[!VAR "MyPwmLoopCount" = "num:i(0)"!][!//
[!VAR "PwmChannelsLookUp1"  = "num:i(0)"!][!//
[!VAR "PwmChannelsLookUp2"  = "num:i(0)"!][!//
[!VAR "PwmChannelsLookUp3"  = "num:i(0)"!][!//
[!VAR "PwmChannelsLookUp4"  = "num:i(0)"!][!//
[!VAR "PwmChannelsLookUp5"  = "num:i(0)"!][!//
[!LOOP "PwmGroupChannels/*"!][!//
[!VAR "Myrefchannelid" = "(.)"!][!//
[!VAR "PWMGroupConfigNumberDummy" = "text:split($Myrefchannelid, '_')[position()-1 = 1]"!][!//
[!VAR "PWMGroupConfigNumber" = "text:split($PWMGroupConfigNumberDummy, '/')[position()-1 = 0]"!][!//
[!VAR "PWMGroupChannelNumber" = "text:split($Myrefchannelid, '_')[position()-2 = 1]"!][!//
[!VAR "MyJC" = "node:path($Myrefchannelid)"!][!//
[!VAR "MyJC3" = "concat($MyJC,'/PwmAssignedHwUnit')"!][!//
[!VAR "MyJC5" = "node:value($MyJC3)"!][!//
[!VAR "MyPwmChannelLocation" = "node:name($MyJC5)"!][!//
[!VAR "MyPwmModuleLocation" ="text:split($MyJC5, '/')[position()-1 = 5]"!][!//
[!VAR "MyPwmChannelNumber" = "text:split($MyPwmChannelLocation, '_')[position()-1 = 1]"!][!//
[!VAR "MyPwmModuleNumber" = "text:split($MyPwmModuleLocation, '_')[position()-1 = 1]"!][!//
[!VAR "MyPwmModuleType" = "text:split($MyPwmModuleLocation, '_')[position()-1 = 0]"!][!//
[!IF "$MyPwmLoopCount = num:i(0)"!][!//
[!VAR "Tom_Atom_Type" = "$MyPwmModuleType"!][!//
[!VAR "Tom_Atom_Num" = "$MyPwmModuleNumber"!][!//
[!VAR "TGC_Num" = "num:i($MyPwmChannelNumber div 8)"!][!//
[!ELSE!][!//
[!VAR "Tom_Atom_Type_New" = "$MyPwmModuleType"!][!//
[!VAR "Tom_Atom_Num_New" = "$MyPwmModuleNumber"!][!//
[!VAR "TGC_Num_New" = "num:i($MyPwmChannelNumber div 8)"!][!//
[!ASSERT "($Tom_Atom_Type = $Tom_Atom_Type_New)"!][!//
ERROR: PWM: TOM and ATOM channels configured inside the same group.Please check PwmChannelConfigSet [!"$PWMGroupConfigNumber"!] in PwmChannelConfigSet_[!"$PwmIdForIndex"!][!//
[!ENDASSERT!][!//
[!ASSERT "($Tom_Atom_Num = $Tom_Atom_Num_New)"!][!//
ERROR: PWM: TOM/ATOM channels of different TOM/ATOM are configured inside the same group.Please check PwmChannelConfigSet [!"$PWMGroupConfigNumber"!] in PwmChannelConfigSet_[!"$PwmIdForIndex"!][!//
[!ENDASSERT!][!//
[!ASSERT "($TGC_Num = $TGC_Num_New)"!][!//
ERROR: PWM: TOM/ATOM channels of different TGC are configured inside the same group.Please check PwmChannelConfigSet [!"$PWMGroupConfigNumber"!] in PwmChannelConfigSet_[!"$PwmIdForIndex"!][!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ASSERT "num:i($PWMGroupConfigNumber) = (num:i($PwmIdForIndex))"!][!//
ERROR: In PwmChannelConfigSet [!"$PwmIdForIndex"!] for the PwmSyncGroup,Channel [!"$PWMGroupChannelNumber"!] from PwmChannelConfigSet [!"$PWMGroupConfigNumber"!] is added.[!//
[!ENDASSERT!][!//
[!VAR "MyPwmLoopCount" = "num:i(($MyPwmLoopCount) + 1)"!][!//
[!/* Set the bit position based on channel number. If Channel number <32 take as it is else subtract by 32,64 and so on */!][!//
[!VAR "PwmGrpSetPosition" = "($PWMGroupChannelNumber)"!][!//
[!IF "$PWMGroupChannelNumber < num:i(32)"!][!//
[!ASSERT "bit:and($PwmChannelsLookUp1, bit:shl(1,$PwmGrpSetPosition)) = 0"!][!//
ERROR: In PwmChannelConfigSet [!"$PwmIdForIndex"!] for the PwmSyncGroup,PWM Channel[!"$PWMGroupChannelNumber"!] is configured more than once[!//
[!ENDASSERT!][!//
[!VAR "PwmChannelsLookUp1"  = "bit:bitset($PwmChannelsLookUp1, $PwmGrpSetPosition)"!][!//
[!ELSEIF "$PWMGroupChannelNumber < num:i(64)"!][!//
[!VAR "PwmGrpSetPosition" = "num:i(($PwmGrpSetPosition)-32)"!][!//
[!ASSERT "bit:and($PwmChannelsLookUp2, bit:shl(1,$PwmGrpSetPosition)) = 0"!][!//
ERROR: In PwmChannelConfigSet [!"$PwmIdForIndex"!] for the PwmSyncGroup,PWM Channel[!"$PWMGroupChannelNumber"!] is configured more than once[!//
[!ENDASSERT!][!//
[!VAR "PwmChannelsLookUp2"  = "bit:bitset($PwmChannelsLookUp2, $PwmGrpSetPosition)"!][!//
[!ELSEIF "$PWMGroupChannelNumber < num:i(96)"!][!//
[!VAR "PwmGrpSetPosition" = "num:i(($PwmGrpSetPosition)-64)"!][!//
[!ASSERT "bit:and($PwmChannelsLookUp3, bit:shl(1,$PwmGrpSetPosition)) = 0"!][!//
ERROR: In PwmChannelConfigSet [!"$PwmIdForIndex"!] for the PwmSyncGroup,PWM Channel[!"$PWMGroupChannelNumber"!] is configured more than once[!//
[!ENDASSERT!][!//
[!VAR "PwmChannelsLookUp3"  = "bit:bitset($PwmChannelsLookUp3, $PwmGrpSetPosition)"!][!//
[!ELSEIF "$PWMGroupChannelNumber < num:i(128)"!][!//
[!VAR "PwmGrpSetPosition" = "num:i(($PwmGrpSetPosition)-96)"!][!//
[!ASSERT "bit:and($PwmChannelsLookUp4, bit:shl(1,$PwmGrpSetPosition)) = 0"!][!//
ERROR: In PwmChannelConfigSet [!"$PwmIdForIndex"!] for the PwmSyncGroup,PWM Channel[!"$PWMGroupChannelNumber"!] is configured more than once[!//
[!ENDASSERT!][!//
[!VAR "PwmChannelsLookUp4"  = "bit:bitset($PwmChannelsLookUp4, $PwmGrpSetPosition)"!][!//
[!ELSE!][!//
[!VAR "PwmGrpSetPosition" = "num:i(($PwmGrpSetPosition)-128)"!][!//
[!ASSERT "bit:and($PwmChannelsLookUp5, bit:shl(1,$PwmGrpSetPosition)) = 0"!][!//
ERROR: In PwmChannelConfigSet [!"$PwmIdForIndex"!] for the PwmSyncGroup,PWM Channel[!"$PWMGroupChannelNumber"!] is configured more than once[!//
[!ENDASSERT!][!//
[!VAR "PwmChannelsLookUp5"  = "bit:bitset($PwmChannelsLookUp5, $PwmGrpSetPosition)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//

[!IF "$PwmGroupEnable = 'STD_ON'"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "TotalPwmConfig" = "num:i(count(PwmChannelConfigSet/*))"!][!//
[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfig)"!][!//
[!SELECT "PwmChannelConfigSet/*[num:i($PwmId)]"!][!//
[!VAR "MaxGroup"= "num:i(count(PwmSyncGroup/*))"!][!//
[!FOR "PwmGId" = "num:i(1)" TO "num:i($MaxGroup)"!][!//
[!SELECT "PwmSyncGroup/*[PwmGroupId = num:i($PwmGId) - num:i(1)]"!]
[!VAR "GroupChanCount"= "num:i(count(PwmGroupChannels/*))"!][!//
[!VAR "PwmGroupId2" = "(num:i(num:i($PwmGId) - num:i(1)))"!][!//
 static const Pwm_17_Gtm_GrpChanConfigType Pwm_kCfg[!"num:i(num:i($PwmId)-num:i(1))"!]GrpChanConfig[!"string($PwmGroupId2)"!][] =
{
[!VAR "ChCount" = "(num:i(0))"!][!//
[!LOOP "PwmGroupChannels/*"!][!//
[!NOCODE!]
[!VAR "Get2refchannelid" = "(.)"!][!//
[!VAR "Get2JC" = "node:path($Get2refchannelid)"!][!//
[!VAR "Get2JC3" = "concat($Get2JC,'/PwmAssignedHwUnit')"!][!//
[!VAR "Get2RC1" = "concat($Get2JC,'/PwmChannelId')"!][!//
[!VAR "Get2RC5" = "node:value($Get2RC1)"!][!//
[!VAR "Get2JC5" = "node:value($Get2JC3)"!][!//
[!VAR "Get2PwmChannelLocation" = "node:name($Get2JC5)"!][!//
[!VAR "Get2PwmModuleLocation" ="text:split($Get2JC5, '/')[position()-1 = 5]"!][!//
[!VAR "Get2PwmChannelNumber" = "text:split($Get2PwmChannelLocation, '_')[position()-1 = 1]"!][!//
[!VAR "ChCount" = "(num:i(num:i($ChCount) + num:i(1)))"!][!//
[!ENDNOCODE!][!//
  {
    /* PWM channel Number*/
    (Pwm_17_Gtm_ChannelType)[!"$Get2RC5"!]U,
    /* Tom/Atom Channel Number*/
    (uint8)[!"$Get2PwmChannelNumber"!]U
  }[!IF "$ChCount != $GroupChanCount"!],[!ENDIF!]
[!ENDLOOP!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!]
[!ENDSELECT!]
[!ENDIF!][!//

[!IF "$PwmGroupEnable = 'STD_ON'"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "TotalPwmConfig" = "num:i(count(PwmChannelConfigSet/*))"!][!//
[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfig)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "PwmChannelConfigSet/*[num:i($PwmId)]"!][!//
[!//
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!VAR "MaxGroup"= "num:i(count(PwmSyncGroup/*))"!][!//
static const Pwm_17_Gtm_GroupConfigType Pwm_kGroupConfiguration[!"string(($PwmId)-num:i(1))"!][[!"$MaxGroup"!]] = 
{
[!FOR "PwmGId" = "num:i(1)" TO "num:i($MaxGroup)"!][!//
[!SELECT "PwmSyncGroup/*[PwmGroupId = num:i($PwmGId) - num:i(1)]"!]
[!NOCODE!]
[!VAR "GetTom_Atom_StoreVal" = "num:i(0)"!][!//
[!VAR "PwmGroupId1" = "(num:i(num:i($PwmGId) - num:i(1)))"!][!//
[!VAR "DataPtrMarker" = "(./PWMDutycycleBufferMarker)"!][!//
[!VAR "MaxGroupChannels"= "num:i(count(./PwmGroupChannels/*))"!][!//
[!VAR "GetChDetails" = "(./PwmGroupChannels/*[1])"!][!//
[!VAR "GetDetails" = "node:path($GetChDetails)"!][!//
[!VAR "GetHwDetails" = "concat($GetDetails,'/PwmAssignedHwUnit')"!][!//
[!VAR "GetHwDetailsasNode" = "node:value($GetHwDetails)"!][!//
[!VAR "GetPwmChannelLocation" = "node:name($GetHwDetailsasNode)"!][!//
[!VAR "GetPwmModuleLocation" ="text:split($GetHwDetailsasNode, '/')[position()-1 = 5]"!][!//
[!VAR "GetPwmModuleNumber" = "text:split($GetPwmModuleLocation, '_')[position()-1 = 1]"!][!//
[!VAR "GetPwmModuleType" = "text:split($GetPwmModuleLocation, '_')[position()-1 = 0]"!][!//
[!IF "$GetPwmModuleType = 'Atom'"!][!//
[!VAR "GetTom_Atom_StoreVal" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/* 
 *  Group Number        : [!"$PwmGroupId1"!]
 *  Group Symbolic Name : Pwm_PwmGroupId_[!"node:name(.)"!] 
*/
  {
[!IF "$Safety = 'STD_ON'"!][!//
    #if (PWM_SAFETY_ENABLE == STD_ON)
    /* Data pointer Marker to validate Duty Array */
    (uint32)   [!"$DataPtrMarker"!]U,
    #endif
[!ENDIF!][!//
    /* Group channel configuration*/
    &Pwm_kCfg[!"num:i(num:i($PwmId)-num:i(1))"!]GrpChanConfig[!"string($PwmGroupId1)"!][0],
    /* Max channels in the Group */
    (uint8)[!"$MaxGroupChannels"!]U,
    /* Channels in group is of type Tom(0) Or Atom(1) */
    (uint8)[!"$GetTom_Atom_StoreVal"!]U,
    /* ModuleNumber */
    (uint8)[!"$GetPwmModuleNumber"!]U
  }[!IF "$PwmGId != $MaxGroup"!],[!ENDIF!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!]
[!ENDSELECT!]
[!ENDIF!][!//
/*
Configuration:
1. Marker (if safety is enabled)
2. Address of Channel Configuration structure.
3. No of channels
4. Address of Group Configuration(if SyncGroup is enabled)
5. Number of groups(if SyncGroup is enabled)
*/

const Pwm_17_Gtm_ConfigType Pwm_ConfigRoot[[!"string(num:i($TotalPwmConfig))"!]] =
{
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfig)"!][!//
  {
[!IF "$Safety = 'STD_ON'"!][!//
[!NOCODE!][!//
[!VAR "Marker" = "num:i(0)"!][!//
[!VAR "ModuleId" = "num:i(121)"!][!//
[!VAR "Marker" = "num:inttohex(bit:or($Marker,bit:shl($ModuleId,16)))"!][!//
[!ENDNOCODE!][!//
    #if (PWM_SAFETY_ENABLE == STD_ON)
    /* Marker to check the config pointer */
    [!"$Marker"!]U,
    #endif
[!ENDIF!][!//
[!VAR "MaxChannels"= "num:i(count(PwmChannelConfigSet/*[num:i($PwmId)]/PwmChannel/*))"!][!//
    /* No of channels */
    (Pwm_17_Gtm_ChannelType)[!"$MaxChannels"!]U, 
    /* Pwm Channel Configuration */
    &Pwm_kChannelConfiguration[!"string(($PwmId)-num:i(1))"!][0][!IF "$PwmGroupEnable = 'STD_ON'"!],
[!VAR "MaxGroupIds"= "num:i(count(PwmChannelConfigSet/*[num:i($PwmId)]/PwmSyncGroup/*))"!][!//
    #if (PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE == STD_ON)
    /* Pwm Group Configuration */
    &Pwm_kGroupConfiguration[!"string(($PwmId)-num:i(1))"!][0],
    /* No of Groups */
    (uint8)[!"$MaxGroupIds"!]U
    #endif
[!ENDIF!][!//
  }[!IF "$PwmId != $TotalPwmConfig"!],[!ENDIF!]
[!ENDFOR!][!//
[!ENDSELECT!][!//
};


#define PWM_17_GTM_STOP_SEC_POSTBUILDCFG
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
[!IF "$Safety = 'STD_ON'"!][!//
[!NOCODE!][!//
[!VAR "PwmTomModuleLookUp1" = "num:i(0)"!][!//
[!VAR "PwmAtomModuleLookUp1" = "num:i(0)"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "TotalPwmConfigsets" = "num:i(count(PwmChannelConfigSet/*))"!][!//

[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfigsets)"!][!//[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "tempId" = "num:i(num:i($PwmId)-1)"!][!//
[!VAR "PwmTomModuleLookUp1" = "num:i(0)"!][!//
[!VAR "PwmAtomModuleLookUp1" = "num:i(0)"!][!//
[!SELECT "PwmChannelConfigSet/*[num:i($PwmId)]"!][!//
[!LOOP "PwmChannel/*"!][!//
[!VAR "PwmModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!//
[!VAR "PwmModuleNumber" = "text:split($PwmModuleLocation, '_')[position()-1 = 1]"!][!//
[!VAR "PwmModuleType" = "text:split($PwmModuleLocation, '_')[position()-1 = 0]"!][!//
[!VAR "PwmAsilTypeValue" = "./PwmSafetySignal"!][!//
[!IF "$PwmAsilTypeValue = 'PWM_QM_TYPE'"!][!//
[!VAR "PwmAsilCheck"="num:i(1)"!][!//
[!ELSEIF "$PwmAsilTypeValue = 'PWM_ASIL_TYPE'"!][!//
[!VAR "PwmAsilCheck"="num:i(2)"!][!//
[!ENDIF!][!//
[!IF "$PwmModuleType = 'Tom'"!][!//
[!VAR "PwmSetPosition" = "num:i(2 * $PwmModuleNumber)"!][!//
[!VAR "PwmTemp"="bit:and($PwmTomModuleLookUp1, bit:shl(3,$PwmSetPosition)) "!][!//
[!VAR "PwmTemp"="bit:shr($PwmTemp,$PwmSetPosition) "!][!//
[!IF "$PwmTemp = num:i(0)"!][!//
[!IF "$PwmAsilTypeValue = 'PWM_QM_TYPE'"!][!//
[!VAR "PwmTomModuleLookUp1" = "bit:bitset($PwmTomModuleLookUp1, $PwmSetPosition)"!][!//
[!ELSE!][!//
[!VAR "PwmTomModuleLookUp1" = "bit:bitset($PwmTomModuleLookUp1, $PwmSetPosition+1)"!][!//
[!ENDIF!][!//
[!ELSEIF "$PwmTemp = num:i(1)"!][!//
[!ASSERT "$PwmAsilTypeValue = 'PWM_QM_TYPE'"!][!//
Config Error: In PwmChannelConfigSet [!"$tempId"!] TOM[!"$PwmModuleNumber"!] is already configured for QM 
[!ENDASSERT!][!//
[!ELSEIF "$PwmTemp = num:i(2)"!][!//
[!ASSERT "$PwmAsilTypeValue = 'PWM_ASIL_TYPE'"!][!//
Config Error: In PwmChannelConfigSet [!"$tempId"!] TOM[!"$PwmModuleNumber"!] is already configured for ASIL 
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ELSEIF "$PwmModuleType = 'Atom'"!][!//
[!VAR "PwmSetPosition" = "num:i(2 * $PwmModuleNumber)"!][!//
[!VAR "PwmTemp"="bit:and($PwmAtomModuleLookUp1, bit:shl(3,$PwmSetPosition)) "!][!//
[!VAR "PwmTemp"="bit:shr($PwmTemp,$PwmSetPosition) "!][!//
[!IF "$PwmTemp = num:i(0)"!][!//
[!IF "$PwmAsilTypeValue = 'PWM_QM_TYPE'"!][!//
[!VAR "PwmAtomModuleLookUp1" = "bit:bitset($PwmAtomModuleLookUp1, $PwmSetPosition)"!][!//
[!ELSE!][!//
[!VAR "PwmAtomModuleLookUp1" = "bit:bitset($PwmAtomModuleLookUp1, $PwmSetPosition+1)"!][!//
[!ENDIF!][!//
[!ELSEIF "$PwmTemp = num:i(1)"!][!//
[!ASSERT "$PwmAsilTypeValue = 'PWM_QM_TYPE'"!][!//
Config Error: PwmChannelConfigSet [!"$tempId"!] ATOM[!"$PwmModuleNumber"!] is already configured for QM 
[!ENDASSERT!][!//
[!ELSEIF "$PwmTemp = num:i(2)"!][!//
[!ASSERT "$PwmAsilTypeValue = 'PWM_ASIL_TYPE'"!][!//
Config Error: PwmChannelConfigSet [!"$tempId"!] ATOM[!"$PwmModuleNumber"!] is already configured for ASIL 
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//