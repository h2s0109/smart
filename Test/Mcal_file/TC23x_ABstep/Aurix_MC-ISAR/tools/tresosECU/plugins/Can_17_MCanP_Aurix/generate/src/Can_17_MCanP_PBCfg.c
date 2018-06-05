[!/*****************************************************************************
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
**  $FILENAME   : Can_17_MCanP_PBCfg.c $                                     **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\27 $                               **
**                                                                            **
**  $DATE       : 2016-08-09 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for Can_17_MCanP_PBCfg.c file                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/************************************************************************/!][!//
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
**  $FILENAME   : Can_17_MCanP_PBCfg.c $                                     **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\27 $                               **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CAN configuration generated out of ECU configuration       **
**                   file(Can_17_MCanP.bmd)                                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_NAS_CAN_PR69_PR469_PR122,DS_NAS_CAN_PR446,
            DS_NAS_CAN_PR700,DS_NAS_CAN_PR701,DS_NAS_CAN_PR704,DS_NAS_CAN_PR707,
            DS_NAS_CAN_PR708,DS_NAS_CAN_PR712,DS_NAS_CAN_PR713,DS_NAS_CAN_PR714,
            DS_NAS_CAN_PR716,DS_NAS_CAN_PR717,DS_NAS_CAN_PR723,DS_NAS_CAN_PR724,
            DS_NAS_CAN_PR728,DS_NAS_CAN_PR709,SAS_AS4XX_CAN_PR680]              
                     [/cover]                                                **/

[!//
[!/* Include Code Generator Macros */!][!//
[!INCLUDE "Can_17_MCanP.m"!][!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include CAN Driver Header File */
#include "Can_17_MCanP.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_POSTBUILDCFG
#include "MemMap.h"
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Can')[1]"!][!//
[!//
[!/* Extract Configuration Information */!][!//
[!VAR "ConfigCount" = "num:i(count(CanConfigSet/*)) - 1"!][!//
[!VAR "TxObjectType" = "'TRANSMIT'"!][!//
[!VAR "RxObjectType" = "'RECEIVE'"!][!//
[!VAR "StandardObjectIdType" = "'STANDARD'"!][!//
[!//
[!IF "CanGeneral/CanMultiplexedTransmission = 'true'"!][!//
[!VAR "MultiplexedTransmission" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "MultiplexedTransmission" = "num:i(0)"!][!//
[!ENDIF!][!//
[!//
[!VAR "StandardIdOnly" = "'true'"!][!//
[!VAR "ControllerConfigMax" = "num:i(0)"!][!//
[!VAR "TxObjectCountMax" = "num:i(0)"!][!//
[!VAR "RxObjectCountMax" = "num:i(0)"!][!//
[!VAR "NumFifoConfigsMax" = "num:i(0)"!][!//
[!VAR "WakeupSupported" = "num:i(0)"!][!//
[!VAR "NumOfCtrlKer1" = "num:i(ecu:get('Can.MaxCtrlKer'))"!][!//
[!VAR "FDNodesPresent" = "num:i(0)"!][!//
[!VAR "MsgObSize" = "num:i(1)"!][!//
[!//
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!IF "CanWakeupSupport = 'true'"!][!//
[!VAR "WakeupSupported" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "CanController/*"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "FDNodesPresent" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!//
[!IF "$RxObjectCountMax < num:i(count(CanHardwareObject/*[CanObjectType=$RxObjectType]))"!][!//
[!VAR "RxObjectCountMax" = "num:i(count(CanHardwareObject/*[CanObjectType=$RxObjectType]))"!][!//
[!ENDIF!][!//
[!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
[!IF "$NumFifoConfigsMax < num:i(count(CanFifoConfiguration/*))"!][!//
[!VAR "NumFifoConfigsMax" = "num:i(count(CanFifoConfiguration/*))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!VAR "TotalTxMO" = "num:i(0)"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
[!LOOP "CanHardwareObject/*[CanObjectType=$TxObjectType]"!][!//
[!VAR "TotalTxMO" = "num:i($TotalTxMO + CanMultiplexedHwObjects)"!][!//
[!ENDLOOP!][!//
[!IF "$TxObjectCountMax < $TotalTxMO"!][!//
[!VAR "TxObjectCountMax" = "$TotalTxMO"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "$TxObjectCountMax < num:i(count(CanHardwareObject/*[CanObjectType=$TxObjectType]))"!][!//
[!VAR "TxObjectCountMax" = "num:i(count(CanHardwareObject/*[CanObjectType=$TxObjectType]))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!LOOP "CanHardwareObject/*"!][!//
[!IF "./CanIdType != $StandardObjectIdType"!][!//
[!VAR "StandardIdOnly" = "'false'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
[!LOOP "CanFifoConfiguration/*"!][!//
[!IF "./CanFifoIdType != $StandardObjectIdType"!][!//
[!VAR "StandardIdOnly" = "'false'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!//
[!IF "$ControllerConfigMax < num:i(count(CanController/*))"!][!//
[!VAR "ControllerConfigMax" = "num:i(count(CanController/*))"!][!//
[!ENDIF!][!//
[!//
[!LOOP "CanController/*"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "FDNodesPresent" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!VAR "CanRxHwObjectKer0" = "num:i(count(CanHardwareObject/*[(CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1)]))"!][!//
[!VAR "CanRxHwObjectKer1" = "num:i(count(CanHardwareObject/*[(CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1)]))"!][!//
[!VAR "CanTxHwObjectKer0" = "num:i(count(CanHardwareObject/*[(CanObjectType=$TxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1)]))"!][!//
[!VAR "CanTxHwObjectKer1" = "num:i(count(CanHardwareObject/*[(CanObjectType=$TxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1)]))"!][!//
[!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

/******************************************************************************/
                /* CAN Controller Baudrate Configurations */
/******************************************************************************/
                          /* Baudrate Setting */
   /* (uint16)((DIV8 << 15)|(TSEG2 << 12)|(TSEG1 << 8)|(SJW << 6)|(BRP)) */
   /* SJW   -> CanControllerSyncJumpWidth - 1                            */
   /* TSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1              */
   /* TSEG2 -> CanControllerSeg2 - 1                                     */
/******************************************************************************/
[!//
[!VAR "CanMcuExtOscClock" = "0"!][!//
[!VAR "CanMcuClockRef" = "''"!][!//
[!VAR "CanSystemClock" ="num:i(0)"!][!//

[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!//
[!FOR "ControlIndex" ="num:i(0)" TO "num:i(count(CanController/*)-1)"!][!//
[!IF "CanController/*[@index = $ControlIndex]/CanControllerActivation = 'true'"!][!//
[!IF "node:refexists(CanController/*[@index = $ControlIndex]/CanCpuClockRef) ='true'"!][!//
[!VAR "CanMcuClockRef" = "node:path(node:ref(CanController/*[@index = $ControlIndex]/CanCpuClockRef))"!][!//
[!IF "../../CanGeneral/CanBaudRateClkSelErayPll ='true'"!][!// 
[!VAR "CanSystemClock" ="num:i(node:ref($CanMcuClockRef)/McuClockErayFrequency)"!][!//
[!ELSEIF "../../CanGeneral/CanBaudRateClkSelExtOsc ='true'"!][!// 
[!VAR "CanMcuExtOscClock" ="num:i(node:ref('/AUTOSAR/TOP-LEVEL-PACKAGES/Mcu/ELEMENTS/Mcu/McuGeneralConfiguration/McuMainOscillatorFrequency'))"!][!//
[!VAR "CanSystemClock" = "num:i($CanMcuExtOscClock * num:i(1000000))"!][!//
[!ELSE!][!//
[!VAR "CanSystemClock" ="num:i(node:ref($CanMcuClockRef)/McuClockCANFrequency)"!][!//
[!ENDIF!][!//
[!BREAK!][!//
[!ELSE!][!//
[!ERROR!][!//
 Error: CanCpuClockRef is not Configured for CanController [!"@name"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!//
[!//
[!LOOP "CanController/*"!][!//
[!IF "./CanControllerActivation = 'true'"!][!//
[!IF "node:refexists(./CanCpuClockRef) ='true'"!][!//
[!VAR "CanMcuClockRefNext" = "node:path(node:ref(./CanCpuClockRef))"!][!//
[!ASSERT "$CanMcuClockRefNext = $CanMcuClockRef"!][!//
 Error: CanCpuClockRef should refer to the same MCU clock in all CanController Configurations of the CanConfigset [!"node:name(../..)"!]!
[!ENDASSERT!][!//
[!VAR "CanMcuClockRef" = "$CanMcuClockRefNext"!][!//
[!VAR "CANModuleClock" = "0"!][!//
[!VAR "ClkDivider" = "../../CanClockConfiguration/CanClockDividerMode"!][!//
[!VAR "Prescalar" = "../../CanClockConfiguration/CanClockStepValue"!][!//
[!IF "$ClkDivider = 'NORMAL_DIVIDER'"!][!//
[!VAR "CANModuleClock" = "($CanSystemClock) div (num:i(1024) - num:i($Prescalar)) + 0.5"!][!//
[!ELSE!][!//
[!VAR "CANModuleClock" = "($CanSystemClock * num:i($Prescalar)) div (num:i(1024)) + 0.5"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR!][!//
 Error: CanCpuClockRef is not Configured for CanController [!"@name"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!//
[!//
[!//
[!FOR "TempIndex" = "0" TO "num:i(count(CanController/*)) - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "./CanControllerActivation = 'true'"!][!//
[!VAR "MaxConfigCount" = "num:i(count(./CanControllerBaudrateConfig/*))"!][!//

/* [!"../../@name"!] -> [!"./@name"!] Baudrate Configuration */

static const Can_17_MCanP_ControllerBaudrateConfigType Can_kBaudrateConfig_[!"$Instance"!]_[!"CanControllerId"!][] = 
{
[!FOR "i" = "1" TO "$MaxConfigCount"!][!//
[!VAR "ModuleClockBy8" = "num:i(0)"!][!//
[!VAR "TimeQuantaNanoSecond" = "num:i(1000000000) div ( ((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)*num:i(1000)))"!][!//
[!VAR "BRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(1000000000)) - 1)+ 0.5)"!][!//
[!IF "$BRP > 63"!][!//
[!//
[!IF "(./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!ERROR!][!//
ERROR: Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is not possible in CAN FD mode.Since it cause BRP vale greater than 63. This is not allowed when controller configured for CAN FD.
[!ENDERROR!][!//
[!ELSE!][!//
[!//
[!VAR "BRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(8000000000)) - 1) + 0.5)"!][!//
[!VAR "ModuleClockBy8" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "$ModuleClockBy8 != num:i(1)"!][!//
[!VAR "GetMinReqBR" = "(($CANModuleClock) div (64 * (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)))))"!][!//
[!VAR "GetMaxReqBR" = "(($CANModuleClock) div (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1))))"!][!//
[!ELSE!][!//
[!VAR "GetMinReqBR" = "((($CANModuleClock) div (64 * (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)))))div 8)"!][!//
[!VAR "GetMaxReqBR" = "((($CANModuleClock) div (3+ (num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1))))div 8)"!][!//
[!ENDIF!][!//
[!//
[!ASSERT " not((( num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)*num:i(1000)) < $GetMinReqBR))"!][!//
ERROR: Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is Less than the Minimum allowed Baud rate [!"num:i($GetMinReqBR + 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDASSERT!][!//
[!//
[!ASSERT " not((( num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)*num:i(1000)) > $GetMaxReqBR))"!][!//
ERROR: Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is greater than the Maximum allowed Baud rate [!"num:i($GetMaxReqBR - 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDASSERT!][!//
[!//
[!ASSERT "(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1) >= (./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
 Error: CanControllerSeg1 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDASSERT!][!//
[!ASSERT "(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2) >= (./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
 Error: CanControllerSeg2 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDASSERT!][!//
[!IF "node:exists(./CanControllerFdBaudrateConfig/*[1])"!][!//
[!ASSERT "num:i(7) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 7<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=79.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2) <= num:i(79)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 7<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=79.
[!ENDASSERT!][!//
[!ASSERT "num:i(3) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 3 <= (CanControllerPropSeg + CanControllerSeg1) <= 64.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1) <= num:i(64)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 3 <= (CanControllerPropSeg + CanControllerSeg1) <= 64.
[!ENDASSERT!][!//
[!ELSE!][!//
[!ASSERT "num:i(0) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 0 <= CanControllerPropSeg <= 15.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg) <= num:i(15)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 0 <= CanControllerPropSeg <= 15.
[!ENDASSERT!][!//
[!ASSERT "num:i(2) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 2 <= CanControllerSeg2 <= 8.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2) <= num:i(8)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 2 <= CanControllerSeg2 <= 8.
[!ENDASSERT!][!//
[!ASSERT "num:i(1) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 1 <= CanControllerSyncJumpWidth <= 4.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth) <= num:i(4)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 1 <= CanControllerSyncJumpWidth <= 4.
[!ENDASSERT!][!//
[!ASSERT "num:i(7) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 7<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=24.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2) <= num:i(24)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 7<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=24.
[!ENDASSERT!][!//
[!ASSERT "num:i(3) <= num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 3 <= (CanControllerPropSeg + CanControllerSeg1) <= 16.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1) <= num:i(16)"!][!//
 Error: CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 3 <= (CanControllerPropSeg + CanControllerSeg1) <= 16.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!//
[!IF "node:exists(./CanControllerFdBaudrateConfig/*[1])"!][!//
[!VAR "SJW" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)),8)"!][!//
[!VAR "TSEG1" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)),22)"!][!//
[!VAR "TSEG2" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)),16)"!][!//
[!ELSE!][!//
[!VAR "SJW" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)),6)"!][!//
[!VAR "TSEG1" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)),8)"!][!//
[!VAR "TSEG2" = "bit:shl((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)),12)"!][!//
[!ENDIF!][!//
[!VAR "DIV8" = "bit:shl((num:i($ModuleClockBy8)),15)"!][!//
[!VAR "tempNBTR" = "bit:or($BRP,$SJW)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$TSEG1)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$TSEG2)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$DIV8)"!][!//
  {
    /* Configured Baudrate -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps */
[!IF "$ModuleClockBy8 != num:i(1)"!][!//
    /* Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * (num:i($BRP)+1))) div 1000"!] kbps */
[!ELSE!][!//
    /* Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * ((num:i($BRP)+1) * 8))) div 1000"!] kbps */
[!ENDIF!][!//
    /* BRP   -> [!"num:i($BRP)"!] */
    /* SJW   -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)"!]  */
    /* TSEG1 -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)"!]  */
    /* TSEG2 -> [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)"!]  */
    /* DIV8  -> [!"num:i($ModuleClockBy8)"!]  */
    [!"num:inttohex($tempNBTR)"!]U,
    [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!]U
  }[!//
[!IF "$i < $MaxConfigCount"!][!//
,
[!ENDIF!][!//
[!ENDFOR!][!//

};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

static const Can_BaudrateConfigPtrType Can_kBaudrateConfig_[!"$Instance"!][] = 
{
[!FOR "TempIndex" = "0" TO "num:i(count(CanController/*)) - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "./CanControllerActivation = 'true'"!][!//
  { &Can_kBaudrateConfig_[!"$Instance"!]_[!"CanControllerId"!][0] },
[!ELSE!][!//
  { NULL_PTR },
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};

[!IF "$FDNodesPresent = num:i(1)"!][!//
/******************************************************************************/
                /* CAN Controller FD Config Parameters */
/******************************************************************************/
                          /* Baudrate Setting */
   /* (uint16)((FTSEG2 << 12)|(FTSEG1 << 8)|(FSJW << 6)|(FBRP)) */
   /* SJW   -> CanControllerSyncJumpWidth - 1                            */
   /* TSEG1 -> CanControllerPropSeg + CanControllerSeg1 - 1              */
   /* TSEG2 -> CanControllerSeg2 - 1                                     */
/******************************************************************************/

[!FOR "TempIndex" = "0" TO "num:i(count(CanController/*)) - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "./CanControllerActivation = 'true'"!][!//
[!IF "node:exists(CanControllerFdBaudrateConfig/*[1])"!][!//

/* [!"../../@name"!] -> [!"./@name"!] FD Configuration Parameters */

static const Can_FDConfigParamType Can_kFDConfigParam_[!"$Instance"!]_[!"CanControllerId"!] = 
{
[!VAR "i" = "num:i(1)"!][!//
[!VAR "TimeQuantaNanoSecond" = "num:i(1000000000) div ( ((num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg))+(num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * (num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerFdBaudRate)*num:i(1000)))"!][!//
[!VAR "FBRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(1000000000)) - 1)+ 0.5)"!][!//
[!//
[!VAR "GetMinReqBR" = "(($CANModuleClock) div (64 * (3+ (num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)))))"!][!//
[!VAR "GetMaxReqBR" = "(($CANModuleClock) div (3+ (num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1))+(num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1))))"!][!//
[!//
[!ASSERT " not((( num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerFdBaudRate)*num:i(1000)) < $GetMinReqBR))"!][!//
ERROR: Configured Baud rate [!"num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerFdBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is Less than the Minimum allowed Baud rate [!"num:i($GetMinReqBR + 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDASSERT!][!//
[!//
[!ASSERT " not((( num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerFdBaudRate)*num:i(1000)) > $GetMaxReqBR))"!][!//
ERROR: Configured Baud rate [!"num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerFdBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is greater than the Maximum allowed Baud rate [!"num:i($GetMaxReqBR - 1)"!].
Acceptable Baud rate range depends upon configured CAN Module clock, CanControllerPropSeg, CanControllerSeg1 and CanControllerSeg2.
Change baud rate or any of the above parameters to get configured baud rate with in allowed range.
[!ENDASSERT!][!//
[!//
[!ASSERT "(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1) >= (./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
 Error: CanControllerSeg1 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDASSERT!][!//
[!ASSERT "(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2) >= (./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth)"!][!//
 Error: CanControllerSeg2 should be greater than or equal to CanControllerSyncJumpWidth in CanControllerBaudrateConfig [!"node:name(./CanControllerBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDASSERT!][!//
[!ASSERT "num:i(4) <= num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2)"!][!//
 Error: CanControllerFdBaudrateConfig [!"node:name(./CanControllerFdBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range  for Data bit time in CAN FD: 4<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=24.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1 + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2) <= num:i(24)"!][!//
 Error: CanControllerFdBaudrateConfig [!"node:name(./CanControllerFdBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range for Data bit time in CAN FD: 4<=(CanControllerPropSeg + CanControllerSeg1 + CanControllerSeg2)<=24.
[!ENDASSERT!][!//
[!ASSERT "num:i(3) <= num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1)"!][!//
 Error: CanControllerFdBaudrateConfig [!"node:name(./CanControllerFdBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 3 <= (CanControllerPropSeg + CanControllerSeg1) <= 16.
[!ENDASSERT!][!//
[!ASSERT "num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1) <= num:i(16)"!][!//
 Error: CanControllerFdBaudrateConfig [!"node:name(./CanControllerFdBaudrateConfig/*[position()=$i])"!] of CanController [!"node:name(.)"!] of CanConfigSet [!"node:name(../..)"!] violates the allowed range: 3 <= (CanControllerPropSeg + CanControllerSeg1) <= 16.
[!ENDASSERT!][!//
[!//
[!VAR "FSJW" = "bit:shl((num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)),6)"!][!//
[!VAR "FTSEG1" = "bit:shl((num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)),8)"!][!//
[!VAR "FTSEG2" = "bit:shl((num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)),12)"!][!//
[!VAR "tempFNBTR" = "bit:or($FBRP,$FSJW)"!][!//
[!VAR "tempFNBTR" = "bit:or($tempFNBTR,$FTSEG1)"!][!//
[!VAR "tempFNBTR" = "bit:or($tempFNBTR,$FTSEG2)"!][!//
[!VAR "TDCO" = "bit:shl((num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerTrcvDelayCompensationOffset) div num:i($TimeQuantaNanoSecond)),8)"!][!//
[!VAR "TDCEnable" = "0"!][!//
[!IF "$TDCO > (num:i(0))"!][!//
[!VAR "TDCEnable" = "1"!][!//
[!ENDIF!][!//
[!VAR "TDC" = "bit:shl((num:i($TDCEnable)),15)"!][!//
[!VAR "tempNTDCR" = "bit:or($TDCO,$TDC)"!][!//
[!VAR "TxBRS" = "0"!][!//
[!IF "./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerTxBitRateSwitch = 'true'"!][!//
[!VAR "TxBRS" = "1"!][!//
[!ENDIF!][!//
    /* Configured FD Baudrate -> [!"num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerFdBaudRate)"!] kbps */
    /* Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1))+(num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2))+1) * (num:i($FBRP)+1))) div 1000"!] kbps */
    /* FBRP   -> [!"num:i($FBRP)"!] */
    /* FSJW   -> [!"num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSyncJumpWidth - 1)"!]  */
    /* FTSEG1 -> [!"num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerPropSeg + ./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg1 - 1)"!]  */
    /* FTSEG2 -> [!"num:i(./CanControllerFdBaudrateConfig/*[position()=$i]/CanControllerSeg2 - 1)"!]  */
    [!"num:inttohex($tempFNBTR)"!]U,
    [!"num:inttohex($tempNTDCR)"!]U,
    [!"num:i($TxBRS)"!]U
[!//
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

static const Can_FDConfigParamPtrType Can_kFDConfigParam_[!"$Instance"!][] = 
{
[!FOR "TempIndex" = "0" TO "num:i(count(CanController/*)) - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "(./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
  { &Can_kFDConfigParam_[!"$Instance"!]_[!"CanControllerId"!] },
[!ELSE!][!//
  { NULL_PTR },
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};

[!ENDIF!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!//
[!//

[!VAR "CanRxCalloutFnExists" = "num:i(0)"!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!/* Extract Receive L-PDU Callout Function Pointer */!][!//
[!IF "node:exists(CanGeneral/CanLPduReceiveCalloutFunction/*[1]) = 'true'"!][!//
[!VAR "RxLPduCallout" = "CanGeneral/CanLPduReceiveCalloutFunction/*[1]"!][!//
[!IF "$RxLPduCallout != '""' and $RxLPduCallout != '' and $RxLPduCallout != 'NULL_PTR'"!][!//
[!VAR "CanRxCalloutFnExists" = "num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "node:exists(EcuMPostBuildConfigType) = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "$CanRxCalloutFnExists = num:i(1)"!][!//
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
[!ASSERT "num:isnumber($RxLPduCallout)= 'true'"!][!//
 ERROR: Under LOADABLE option CanLPduReceiveCalloutFunction should be entered as a Address.[!//
[!ENDASSERT!][!//
[!ELSE!][!//
[!ASSERT "num:isnumber($RxLPduCallout)!= 'true'"!][!//
 ERROR: Under SELECTABLE option CanLPduReceiveCalloutFunction should be entered as a function name.[!//
[!ENDASSERT!][!//
/* CAN L-PDU Receive Callout Function */
/*IFX_MISRA_RULE_08_08_STATUS= Support L-PDU callout function if configured*/
extern boolean [!"$RxLPduCallout"!] (uint8 Hrh,
                                     Can_IdType CanId,
                                     uint8 CanDlc,
                                     const uint8 *CanSduPtr);
[!ENDIF!][!//
[!ENDIF!][!//

[!/* Based on CanRxInputSelection and CanControllerLoopbackEnable, generate the setting for CAN_NPCR register */!][!//
/******************************************************************************/
            /* Loopback and receive input pin selection setting */
/******************************************************************************/
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//

/* Config [!"$Instance"!] */
static const struct Can_NPCRValueType Can_kNPCR_[!"$Instance"!][] = 
{
[!FOR "TempIndex" = "0" TO "num:i(count(CanController/*)) - 1"!][!//
[!VAR "NPCRTemp" = "num:i(0)"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!IF "CanControllerLoopbackEnable = 'true'"!][!//
[!VAR "NPCRTemp" = "bit:bitset($NPCRTemp,8)"!][!//
  /* LoopBack Enabled, [!//
[!ELSE!][!//
  /* LoopBack Disabled, [!//
[!ENDIF!][!//
[!IF "CanRxInputSelection = 'RXDCANxA'"!][!//
RXDCANxA */
[!ELSEIF "CanRxInputSelection = 'RXDCANxB'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,1)"!][!//
RXDCANxB */
[!ELSEIF "CanRxInputSelection = 'RXDCANxC'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,2)"!][!//
RXDCANxC */
[!ELSEIF "CanRxInputSelection = 'RXDCANxD'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,3)"!][!//
RXDCANxD */
[!ELSEIF "CanRxInputSelection = 'RXDCANxE'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,4)"!][!//
RXDCANxE */
[!ELSEIF "CanRxInputSelection = 'RXDCANxF'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,5)"!][!//
RXDCANxF */
[!ELSEIF "CanRxInputSelection = 'RXDCANxG'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,6)"!][!//
RXDCANxG */
[!ELSEIF "CanRxInputSelection = 'RXDCANxH'"!][!//
[!VAR "NPCRTemp" = "bit:or($NPCRTemp,7)"!][!//
RXDCANxH */
[!ENDIF!][!//
  { [!"$NPCRTemp"!]U },
[!ELSE!][!//
  /* CAN Controller is deactivated */
  { 0U },
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!][!//

[!/* Extract Wakeup Source Id from Configuration */!][!//
[!IF "$WakeupSupported = num:i(1)"!][!//
/******************************************************************************/
            /* CAN Controller wakeup source configuration */
/******************************************************************************/
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!//

/* Config [!"$Instance"!] */
static const uint32 Can_kWakeupSourceId_[!"$Instance"!][] = 
{
[!FOR "TempIndex" = "0" TO "num:i(count(CanController/*)) - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!IF "CanWakeupSupport = 'true'"!][!//
[!IF "node:exists(./CanWakeupSourceRef/*[1]) = 'true'"!][!//
[!IF "node:refexists(./CanWakeupSourceRef/*[1]) ='true'"!][!//
  [!"bit:shl(1,num:i(node:ref(./CanWakeupSourceRef/*[1])/EcuMWakeupSourceId))"!]U,  /* 1 << [!"num:i(node:ref(./CanWakeupSourceRef/*[1])/EcuMWakeupSourceId)"!] */
[!ELSE!][!//
  0U,  /* Wakeup source not configured for CAN Controller [!"CanControllerId"!] */
[!ENDIF!][!//
[!ELSE!][!//
  0U,  /* Wakeup source not configured for CAN Controller [!"CanControllerId"!] */
[!ENDIF!][!//
[!ELSE!][!//
  0U,  /* CAN Controller [!"CanControllerId"!] does not support wakeup */
[!ENDIF!][!//
[!ELSE!][!//
  0U,  /* CAN Controller [!"CanControllerId"!] not activated */
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

/*******************************************************************************
               Transmit / Receive Hardware Object Configurations
********************************************************************************
 Tx Object -> { HW MO Id, [No. of Multiplexed MOs,] Hw Controller Id, Id Type }
        Rx Object -> { Mask, Msg Id, HW MO Id, Hw Controller Id, [Id Type] }
********************************************************************************
       Note: [1] If the associated CAN Controller is not activated then,
                   Hw Controller Id -> 255
             [2] If CanFilterMaskRef is not configured then, 
                   Mask -> 0x7ff - for STANDARD Msg Id Type
                           0x1fffffff - for EXTENDED/MIXED Msg Id Type
*******************************************************************************/

[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "Kernel1Arr" = "'#'"!][!//
[!VAR "Kernel2Arr" = "'#'"!][!//
[!VAR "Kernel1ArrCnt" = "num:i(0)"!][!//
[!VAR "Kernel2ArrCnt" = "num:i(0)"!][!//
[!VAR "Kernel1RxArr" = "'#'"!][!//
[!VAR "Kernel2RxArr" = "'#'"!][!//
[!VAR "Kernel1RxArrCnt" = "num:i(0)"!][!//
[!VAR "Kernel2RxArrCnt" = "num:i(0)"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!IF "$TxObjectCountMax > num:i(0)"!][!//
[!IF "num:i(count(CanHardwareObject/*[CanObjectType=$TxObjectType])) > num:i(0)"!][!//
/* [!"./@name"!] -> Transmit Hardware Object Configuration */
static const Can_TxHwObjectConfigType Can_kTxHwObjectConfig_[!"num:i($Instance)"!][] = 
{ 
[!VAR "CanTxHwObjectIdKer0FD" = "num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer1FD" = "num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer0STD" = "num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer1STD" = "num:i(0)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "(node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!VAR "CanTxHwObjectIdKer0FD" = "$CanTxHwObjectIdKer0FD + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "CanTxHwObjectIdKer0STD" = "$CanTxHwObjectIdKer0STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "(node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!VAR "CanTxHwObjectIdKer1FD" = "$CanTxHwObjectIdKer1FD + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "CanTxHwObjectIdKer1STD" = "$CanTxHwObjectIdKer1STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "CanTxHwObjectIdKer0" = "($CanTxHwObjectIdKer0FD * num:i(3)) + $CanTxHwObjectIdKer0STD"!][!//
[!VAR "CanTxHwObjectIdKer1" = "($CanTxHwObjectIdKer1FD * num:i(3)) + $CanTxHwObjectIdKer1STD"!][!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
[!LOOP "CanFifoConfiguration/*"!][!//
[!IF "node:refexists(CanFifoControllerRef) ='true'"!][!//
[!IF "(node:ref(CanFifoControllerRef)/CanControllerActivation = 'true')and (text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1)"!][!//
[!VAR "CanTxHwObjectIdKer0" = "$CanTxHwObjectIdKer0 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!IF "(node:ref(CanFifoControllerRef)/CanControllerActivation = 'true')and (text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1)"!][!//
[!VAR "CanTxHwObjectIdKer1" = "$CanTxHwObjectIdKer1 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR!][!//
 Error: CanFifoControllerRef is not Configured for CanFifoObjectId [!"CanFifoObjectId"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!VAR "NumHOConfigs" = "num:i(count(CanHardwareObject/*)-1)"!][!//
[!FOR "MOIndex" = "num:i(count(CanHardwareObject/*[CanObjectType=$RxObjectType]))" TO "num:i($NumHOConfigs)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "MsgObSize" = "num:i(3)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "MsgObSize" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "CanObjectId = $MOIndex"!][!//
  {[!//
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
 [!"num:i($CanTxHwObjectIdKer0 )"!]U,[!//
 [!VAR "Kernel1Arr" = "concat($Kernel1Arr,string(num:i($CanTxHwObjectIdKer0 )),'#')"!][!//
 [!VAR "Kernel1ArrCnt"="$Kernel1ArrCnt + num:i(1)"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
 [!"num:i($CanTxHwObjectIdKer0 + (CanMultiplexedHwObjects - 1)* $MsgObSize)"!]U,[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1"!][!//
 [!"num:i($CanTxHwObjectIdKer1 )"!]U,[!//
 [!VAR "Kernel2Arr" = "concat($Kernel2Arr,string(num:i($CanTxHwObjectIdKer1 )),'#')"!][!//
 [!VAR "Kernel2ArrCnt"="$Kernel2ArrCnt + num:i(1)"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
 [!"num:i($CanTxHwObjectIdKer1 + (CanMultiplexedHwObjects - 1)* $MsgObSize)"!]U,[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!/*  [!"CanObjectId"!]U, */!][!//
[!IF "node:refexists(CanControllerRef) = 'true'"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!VAR "CanConfigSetPath" = "substring-before(node:path(.), "/CanHardwareObject/")"!][!//
[!IF "contains($CanControllerRefPath, $CanConfigSetPath) = 'true'"!][!//
[!ELSE!][!//
[!ERROR!][!//
[!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
[!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanObjectId [!"CanObjectId"!] is referred to a CanController which does not belong to the same CanConfigSet.
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true'"!][!//
 [!"text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1]"!]U[!//
[!ELSE!][!//
 255U[!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR!][!//
   CanControllerRef is not Configured for CanHardwareObject [!"@name"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$StandardIdOnly = 'false'"!][!//
, [!CALL "CG_GetHwObjectIdType", "node" = "CanIdType"!][!//
[!ENDIF!][!//
 }[!//
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
[!VAR "CanTxHwObjectIdKer0" = "$CanTxHwObjectIdKer0 + (CanMultiplexedHwObjects * $MsgObSize)"!][!//
[!ELSE!][!//
[!VAR "CanTxHwObjectIdKer0" = "$CanTxHwObjectIdKer0 + $MsgObSize"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
[!VAR "CanTxHwObjectIdKer1" = "$CanTxHwObjectIdKer1 + (CanMultiplexedHwObjects * $MsgObSize)"!][!//
[!ELSE!][!//
[!VAR "CanTxHwObjectIdKer1" = "$CanTxHwObjectIdKer1 + $MsgObSize"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "ecu:get('Can.MaxCtrlKer') = '3'"!][!//
[!IF "($CanTxHwObjectIdKer0 > num:i(128)) or ($CanTxHwObjectIdKer1 > num:i(128))"!][!//
[!ERROR!][!//
     Total number of message objects configured either to
     Kernel1(Node0+Node1+Node2) or Kernel2(Node3+Node4+Node5) exceeds the 
     allowed limit (128)
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "ecu:get('Can.MaxCtrlKer') = '4'"!][!//
[!IF "($CanTxHwObjectIdKer0 > num:i(256)) or ($CanTxHwObjectIdKer1 > num:i(128))"!][!//
[!ERROR!][!//
     Total number of message objects configured either to
     Kernel1(Node0+Node1+Node2+Node3) or Kernel2(Node4+Node5) exceeds the 
     allowed limit (Kernel1-256,Kernel2-128)
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$MOIndex < num:i($NumHOConfigs)"!][!//
,
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

};
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$RxObjectCountMax > num:i(0)"!][!//
[!IF "num:i(count(CanHardwareObject/*[CanObjectType=$RxObjectType])) > num:i(0)"!][!//
/* [!"./@name"!] -> Receive Hardware Object Configuration */
static const Can_RxHwObjectConfigType Can_kRxHwObjectConfig_[!"num:i($Instance)"!][] = 
{[!//
[!VAR "CanRxHwObjectCntKer0" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer1" = "num:i(0)"!][!//
[!VAR "temp" = "num:i(0)"!][!//
[!VAR "NumMO" = "num:i(count(CanHardwareObject/*)-1)"!][!//
[!FOR "MOIndex" = "0" TO "$NumMO"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!IF "CanObjectId = $MOIndex"!][!//
[!IF "CanObjectType = $RxObjectType"!][!//
[!IF "$temp = num:i(1)"!][!//
,[!//
[!ENDIF!][!//
[!IF "$temp = num:i(0)"!][!//
[!VAR "temp" = "num:i(1)"!][!//
[!ENDIF!][!//

  {[!//
[!IF "node:refexists(CanFilterMaskRef/*[1]) ='true'"!][!//
[!IF "node:refexists(CanControllerRef) ='true'"!][!//
[!VAR "CanFilterMaskRefPath" = "node:path(node:ref(CanFilterMaskRef/*[1]))"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!IF "contains($CanFilterMaskRefPath, $CanControllerRefPath) = 'true'"!][!//
[!ELSE!][!//
[!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
[!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
[!VAR "CanMaskConfigSetName" = "substring-after($CanFilterMaskRefPath, "CanConfigSet/")"!][!//
[!VAR "CanMaskConfigSetName" = "substring-before($CanMaskConfigSetName, "/")"!][!//
[!IF "contains($CanConfigSetName, $CanMaskConfigSetName) = 'true'"!][!//
[!WARNING!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanObjectId [!"CanObjectId"!] is referred to a Filter Mask which does not belong to the referred CanController.
[!ENDWARNING!][!//
[!ELSE!][!//
[!ERROR!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanObjectId [!"CanObjectId"!] is referred to a Filter Mask which does not belong to the same CanConfigSet.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
 [!"num:inttohex(node:ref(CanFilterMaskRef/*[1])/CanFilterMaskValue)"!]U,[!//
[!ELSE!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
 0x7ffU,[!//
[!ELSE!][!//
 0x1fffffffU,[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "CanIdType = 'STANDARD'"!][!//
[!ASSERT "num:i(CanIdValue) >= num:i(0) and num:i(CanIdValue) <= num:i(2047)"!][!//
 Error in CanObjectId [!"CanObjectId"!] of CanConfigSet [!"node:name(../..)"!]: Allowed range for STANDARD CanIdType is: 0 to 0x7FF.
[!ENDASSERT!][!//
[!ELSE!][!//
[!IF "CanIdType = 'EXTENDED'"!][!//
[!ASSERT "num:i(CanIdValue) >= num:i(0) and num:i(CanIdValue) <= num:i(536870911)"!][!//
 Error in CanObjectId [!"CanObjectId"!] of CanConfigSet [!"node:name(../..)"!]: Allowed range for EXTENDED CanIdType is: 0 to 0x1FFFFFFF.
[!ENDASSERT!][!//
[!ELSE!][!//
[!IF "num:i(CanIdValue) != num:i(0)"!][!//
[!ASSERT "num:i(CanIdValue) >= num:i(262144) and num:i(CanIdValue) <= num:i(536608768)"!][!//
 Error in CanObjectId [!"CanObjectId"!] of CanConfigSet [!"node:name(../..)"!]: Allowed range for MIXED CanIdType is: 0x0 and 0x40000 to 0x1FFC0000.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
 [!"num:inttohex(CanIdValue)"!]U,[!//
[!IF "node:refexists(CanControllerRef) ='true'"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!VAR "CanConfigSetPath" = "substring-before(node:path(.), "/CanHardwareObject/")"!][!//
[!IF "contains($CanControllerRefPath, $CanConfigSetPath) = 'true'"!][!//
[!ELSE!][!//
[!ERROR!][!//
[!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
[!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanObjectId [!"CanObjectId"!] is referred to a CanController which does not belong to the same CanConfigSet.
[!ENDERROR!][!//
[!ENDIF!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "MsgObSize" = "num:i(3)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "MsgObSize" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
 [!"num:i($CanRxHwObjectCntKer0)"!]U,[!//
[!VAR "Kernel1RxArr" = "concat($Kernel1RxArr,string(num:i($CanRxHwObjectCntKer0 )),'#')"!][!//
[!VAR "Kernel1RxArrCnt"="$Kernel1RxArrCnt + num:i(1)"!][!//
[!VAR "CanRxHwObjectCntKer0" = "$CanRxHwObjectCntKer0 + $MsgObSize"!][!//
[!ELSE!][!//
 [!"num:i($CanRxHwObjectCntKer1)"!]U,[!//
[!VAR "Kernel2RxArr" = "concat($Kernel2RxArr,string(num:i($CanRxHwObjectCntKer1 )),'#')"!][!//
[!VAR "Kernel2RxArrCnt"="$Kernel2RxArrCnt + num:i(1)"!][!//
[!VAR "CanRxHwObjectCntKer1" = "$CanRxHwObjectCntKer1 + $MsgObSize"!][!//
[!ENDIF!][!//
[!IF "ecu:get('Can.MaxCtrlKer') = '3'"!][!//
[!IF "($CanRxHwObjectCntKer0 > num:i(128)) or ($CanRxHwObjectCntKer1 > num:i(128))"!][!//
[!ERROR!][!//
     Total number of message objects configured either to
     Kernel1(Node0+Node1+Node2) or Kernel2(Node3+Node4+Node5) exceeds the 
     allowed limit (128)
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "ecu:get('Can.MaxCtrlKer') = '4'"!][!//
[!IF "($CanRxHwObjectCntKer0 > num:i(256)) or ($CanRxHwObjectCntKer1 > num:i(128))"!][!//
[!ERROR!][!//
     Total number of message objects configured either to
     Kernel1(Node0+Node1+Node2+Node3) or Kernel2(Node4+Node5) exceeds the 
     allowed limit (Kernel1-256,Kernel2-128)
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:ref(CanControllerRef)/CanControllerActivation = 'true'"!][!//
 [!"text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1]"!]U[!//
[!ELSE!][!//
 255U[!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR!][!//
   CanControllerRef is not Configured for CanHardwareObject [!"@name"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$StandardIdOnly = 'false'"!][!//
, [!CALL "CG_GetHwObjectIdType", "node" = "CanIdType"!][!//
[!ENDIF!][!//
 }[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

};
[!ENDIF!][!//
[!ENDIF!][!//
[!//

/*******************************************************************************
     CAN Hardware object Id <-> CAN Transmit/Recieve Object Handle Mapping      
*******************************************************************************/
[!VAR "temp" = "num:i(0)"!][!//
[!VAR "FirstHwObj" = "num:i(0)"!][!//
[!VAR "LastHwObj" = "num:i(0)"!][!//
[!VAR "HwObj" = "num:i(0)"!][!//
[!VAR "HwObjOffset" = "num:i(0)"!][!//
[!VAR "PrevHwObjOffset" = "num:i(0)"!][!//
[!VAR "MaxHwObjOffset" = "num:i(0)"!][!//
[!VAR "HwObjOffsetCntKer1" = "num:i(0)"!][!//
[!VAR "HwObjOffsetCntKer2" = "num:i(0)"!][!//
[!IF "(num:i($Kernel1ArrCnt) > num:i(0))"!][!//
[!VAR "FirstHwObj" ="num:i(text:split($Kernel1Arr, '#')[num:i(1)])"!][!//
[!VAR "LastHwObj" ="num:i(text:split($Kernel1Arr, '#')[num:i($Kernel1ArrCnt)])"!][!//
[!VAR "MaxHwObjOffset" = "num:i($LastHwObj - $FirstHwObj)"!][!//
[!ENDIF!][!//
[!NOCODE!][!//
[!IF "$CanTxHwObjectKer0 > num:i(0)"!][!//
[!IF "(num:i($Kernel1ArrCnt) > num:i(0))"!][!//
[!CODE!][!//
/* [!"./@name"!] -> Kernal 0 CAN Hw Object ID - CAN Hth Mapping */
static const uint8 Can_kTxObjectHthKer0Map_[!"num:i($Instance)"!][] =
{[!//
[!ENDCODE!][!//
[!FOR "LoopCnt" = "num:i(1)" TO "$Kernel1ArrCnt"!][!//
[!VAR "HwObj" ="num:i(text:split($Kernel1Arr, '#')[num:i($LoopCnt)])"!][!//
[!VAR "HwObjOffset" = "num:i($HwObj - $FirstHwObj)"!][!//
[!FOR "LoopCnt2" = "num:i($PrevHwObjOffset)" TO "num:i($MaxHwObjOffset)"!][!//
[!VAR "HwObjOffsetCntKer1" = "num:i($HwObjOffsetCntKer1 + num:i(1))"!][!//
[!IF "(num:i($HwObjOffset) = num:i($LoopCnt2))"!][!//
[!CODE!][!//
 [!"num:i($LoopCnt - num:i(1))"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!VAR "PrevHwObjOffset" = "num:i($HwObjOffset + num:i(1))"!][!//
[!BREAK!][!//
[!ELSE!][!//
[!CODE!][!//
 [!"num:i(0)"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//end of [!FOR "LoopCnt" = "num:i(1)" TO "$Kernel1ArrCnt"!][!//

[!CODE!][!//
 };
 
[!ENDCODE!][!//
[!ENDIF!][!//[!IF "$CanTxHwObjectKer0 > num:i(0)"!][!//
[!ENDIF!][!//End of [!IF "(num:i($Kernel1ArrCnt) > num:i(0))"!][!//
[!//
[!VAR "FirstHwObj" = "num:i(0)"!][!//
[!VAR "LastHwObj" = "num:i(0)"!][!//
[!VAR "HwObj" = "num:i(0)"!][!//
[!VAR "HwObjOffset" = "num:i(0)"!][!//
[!VAR "PrevHwObjOffset" = "num:i(0)"!][!//
[!VAR "MaxHwObjOffset" = "num:i(0)"!][!//
[!IF "$CanTxHwObjectKer1 > num:i(0)"!][!//
[!CODE!][!//
/* [!"./@name"!] -> Kernal 1 CAN Hw Object ID - CAN Hth Mapping */
static const uint8 Can_kTxObjectHthKer1Map_[!"num:i($Instance)"!][] =
{[!//
[!ENDCODE!][!//
[!IF "(num:i($Kernel2ArrCnt) > num:i(0))"!][!//
[!VAR "FirstHwObj" ="num:i(text:split($Kernel2Arr, '#')[num:i(1)])"!][!//
[!VAR "LastHwObj" ="num:i(text:split($Kernel2Arr, '#')[num:i($Kernel2ArrCnt)])"!][!//
[!VAR "MaxHwObjOffset" = "num:i($LastHwObj - $FirstHwObj)"!][!//
[!CODE!][!//
[!ENDCODE!][!//
[!FOR "LoopCnt" = "num:i(1)" TO "$Kernel2ArrCnt"!][!//
[!VAR "HwObj" ="num:i(text:split($Kernel2Arr, '#')[num:i($LoopCnt)])"!][!//
[!VAR "HwObjOffset" = "num:i($HwObj - $FirstHwObj)"!][!//
[!FOR "LoopCnt2" = "num:i($PrevHwObjOffset)" TO "num:i($MaxHwObjOffset)"!][!//
[!VAR "HwObjOffsetCntKer2" = "num:i($HwObjOffsetCntKer2 + num:i(1))"!][!//
[!IF "(num:i($HwObjOffset) = num:i($LoopCnt2))"!][!//
[!CODE!][!//
 [!"num:i($LoopCnt - num:i(1))"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!VAR "PrevHwObjOffset" = "num:i($HwObjOffset + num:i(1))"!][!//
[!BREAK!][!//
[!ELSE!][!//
[!CODE!][!//
 [!"num:i(0)"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
 };
 
[!ENDCODE!][!//
[!ENDIF!][!//End of [!IF "(num:i($Kernel2ArrCnt) > num:i(0))"!][!//
[!ENDIF!][!//[!IF "$CanTxHwObjectKer1 > num:i(0)"!][!//
[!ENDNOCODE!][!//
[!NOCODE!]
[!VAR "temp" = "num:i(0)"!][!//
[!VAR "FirstHwObj" = "num:i(0)"!][!//
[!VAR "HrhIndex" = "num:i(0)"!][!//
[!VAR "LastHwObj" = "num:i(0)"!][!//
[!VAR "HwObj" = "num:i(0)"!][!//
[!VAR "HwObjOffset" = "num:i(0)"!][!//
[!VAR "PrevHwObjOffset" = "num:i(0)"!][!//
[!VAR "MaxHwObjOffset" = "num:i(0)"!][!//
[!VAR "HwObjOffsetCntKer1" = "num:i(0)"!][!//
[!VAR "HwObjOffsetCntKer2" = "num:i(0)"!][!//
[!IF "(num:i($Kernel1RxArrCnt) > num:i(0))"!][!//
[!VAR "FirstHwObj" ="num:i(text:split($Kernel1RxArr, '#')[num:i(1)])"!][!//
[!VAR "LastHwObj" ="num:i(text:split($Kernel1RxArr, '#')[num:i($Kernel1RxArrCnt)])"!][!//
[!VAR "MaxHwObjOffset" = "num:i($LastHwObj - $FirstHwObj)"!][!//
[!ENDIF!][!//
[!IF "$CanRxHwObjectKer0 > num:i(0)"!][!//
[!CODE!][!//
/* [!"./@name"!] -> Kernal 0 CAN Hw Object ID - CAN Hrh Mapping */
static const uint8 Can_kRxObjectHrhKer0Map_[!"num:i($Instance)"!][] =
{[!//
[!ENDCODE!][!//
[!IF "(num:i($Kernel1RxArrCnt) > num:i(0))"!][!//
[!FOR "LoopCnt" = "num:i(1)" TO "$Kernel1RxArrCnt"!][!//
[!VAR "HwObj" ="num:i(text:split($Kernel1RxArr, '#')[num:i($LoopCnt)])"!][!//
[!VAR "HwObjOffset" = "num:i($HwObj - $FirstHwObj)"!][!//
[!FOR "LoopCnt2" = "num:i($PrevHwObjOffset)" TO "num:i($MaxHwObjOffset)"!][!//
[!VAR "HwObjOffsetCntKer1" = "num:i($HwObjOffsetCntKer1 + num:i(1))"!][!//
[!IF "(num:i($HwObjOffset) = num:i($LoopCnt2))"!][!//
[!CODE!][!//
 [!"num:i($HrhIndex)"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!VAR "PrevHwObjOffset" = "num:i($HwObjOffset + num:i(1))"!][!//
[!VAR "HrhIndex" = "num:i($HrhIndex + num:i(1))"!][!//
[!BREAK!][!//
[!ELSE!][!//
[!CODE!][!//
 [!"num:i(0)"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
 };
 
[!ENDCODE!][!//
[!ENDIF!][!//[!IF "(num:i($Kernel1ArrCnt) > num:i(0))"!][!//
[!ENDIF!][!//End of [!IF "$CanRxHwObjectKer0 > num:i(0)"!][!//
[!//
[!IF "$CanRxHwObjectKer1 > num:i(0)"!][!//
[!VAR "FirstHwObj" = "num:i(0)"!][!//
[!VAR "LastHwObj" = "num:i(0)"!][!//
[!VAR "HwObj" = "num:i(0)"!][!//
[!VAR "HwObjOffset" = "num:i(0)"!][!//
[!VAR "PrevHwObjOffset" = "num:i(0)"!][!//
[!VAR "MaxHwObjOffset" = "num:i(0)"!][!//
[!CODE!][!//
/* [!"./@name"!] -> Kernal 1 CAN Hw Object ID - CAN Hrh Mapping */
static const uint8 Can_kRxObjectHrhKer1Map_[!"num:i($Instance)"!][] =
{[!//
[!ENDCODE!][!//
[!IF "(num:i($Kernel2RxArrCnt) > num:i(0))"!][!//
[!VAR "FirstHwObj" ="num:i(text:split($Kernel2RxArr, '#')[num:i(1)])"!][!//
[!VAR "LastHwObj" ="num:i(text:split($Kernel2RxArr, '#')[num:i($Kernel2RxArrCnt)])"!][!//
[!VAR "MaxHwObjOffset" = "num:i($LastHwObj - $FirstHwObj)"!][!//
[!FOR "LoopCnt" = "num:i(1)" TO "$Kernel2RxArrCnt"!][!//
[!VAR "HwObj" ="num:i(text:split($Kernel2RxArr, '#')[num:i($LoopCnt)])"!][!//
[!VAR "HwObjOffset" = "num:i($HwObj - $FirstHwObj)"!][!//
[!FOR "LoopCnt2" = "num:i($PrevHwObjOffset)" TO "num:i($MaxHwObjOffset)"!][!//
[!VAR "HwObjOffsetCntKer2" = "num:i($HwObjOffsetCntKer2 + num:i(1))"!][!//
[!IF "(num:i($HwObjOffset) = num:i($LoopCnt2))"!][!//
[!CODE!][!//
 [!"num:i($HrhIndex)"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!VAR "HrhIndex" = "num:i($HrhIndex + num:i(1))"!][!//
[!VAR "PrevHwObjOffset" = "num:i($HwObjOffset + num:i(1))"!][!//
[!BREAK!][!//
[!ELSE!][!//
[!CODE!][!//
 [!"num:i(0)"!][!//
[!ENDCODE!][!//
[!IF "(num:i($MaxHwObjOffset) != num:i($LoopCnt2))"!][!//
[!CODE!][!//
,[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!CODE!][!//
 };
 
[!ENDCODE!][!//
[!ENDIF!][!//[!IF "(num:i($Kernel2RxArrCnt) > num:i(0))"!][!//
[!ENDIF!][!//[!IF "$CanRxHwObjectKer1 > num:i(0)"!][!//
[!ENDNOCODE!]
[!//
[!ENDSELECT!]
[!ENDFOR!][!//
/*******************************************************************************
              CAN Controller <-> CAN Hardware Object Mapping
********************************************************************************
        { First Rx Hardware Object, No. of Rx Hardware Objects, 
          First Tx Hardware Object, No. of Tx Hardware Objects }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!VAR "NumControllers" = "num:i(count(CanController/*))"!][!//
/* [!"./@name"!] -> CAN Controller - CAN Hardware Object Mapping */
static const Can_ControllerMOMapConfigType Can_kControllerMOMapConfig_[!"num:i($Instance)"!][] = 
{
[!VAR "CanRxHwObjectCntKer0FD" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer1FD" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer0STD" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer1STD" = "num:i(0)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "CanRxHwObjectCntKer0FD" = "$CanRxHwObjectCntKer0FD + num:i(1)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "CanRxHwObjectCntKer0STD" = "$CanRxHwObjectCntKer0STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "CanRxHwObjectCntKer1FD" = "$CanRxHwObjectCntKer1FD + num:i(1)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "CanRxHwObjectCntKer1STD" = "$CanRxHwObjectCntKer1STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "CanRxHwObjectCntKer0" = "($CanRxHwObjectCntKer0FD * num:i(3)) + $CanRxHwObjectCntKer0STD"!][!//
[!VAR "CanRxHwObjectCntKer1" = "($CanRxHwObjectCntKer1FD * num:i(3)) + $CanRxHwObjectCntKer1STD"!][!//

[!VAR "CanRxHwObjFifoCntKer0" = "num:i(0)"!][!//
[!VAR "CanRxHwObjFifoCntKer1" = "num:i(0)"!][!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
[!LOOP "CanFifoConfiguration/*"!][!//
[!IF "node:refexists(CanFifoControllerRef) ='true'"!][!//
[!IF "(node:ref(CanFifoControllerRef)/CanControllerActivation = 'true')and (text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1)"!][!//
[!VAR "CanRxHwObjFifoCntKer0" = "$CanRxHwObjFifoCntKer0 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!IF "(node:ref(CanFifoControllerRef)/CanControllerActivation = 'true')and (text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1)"!][!//
[!VAR "CanRxHwObjFifoCntKer1" = "$CanRxHwObjFifoCntKer1 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!VAR "CanTxHwObjectIdKer0" = "($CanRxHwObjectCntKer0) + $CanRxHwObjFifoCntKer0"!][!//
[!VAR "CanTxHwObjectIdKer1" = "($CanRxHwObjectCntKer1) + $CanRxHwObjFifoCntKer1"!][!//
[!VAR "CanRxHwObjectCntKer0" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer1" = "num:i(0)"!][!//
[!FOR "TempIndex" = "0" TO "$NumControllers - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!VAR "FirstRxMO" = "num:i(ecu:get('Can.MaxHwObjects')-1)"!][!//
[!VAR "NumRxMO" = "num:i(0)"!][!//
[!VAR "FirstTxMO" = "num:i(ecu:get('Can.MaxHwObjects')-1)"!][!//
[!VAR "NumTxMO" = "num:i(0)"!][!//
[!IF "$TempIndex > 0"!][!//
,
[!ENDIF!][!//
[!VAR "CanControllerIdTemp" = "CanControllerId"!][!//
[!LOOP "../../CanHardwareObject/*"!][!//
[!SELECT "node:ref(CanControllerRef)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "MsgObSize" = "num:i(3)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "MsgObSize" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "node:ref(CanControllerRef)/CanControllerId = $CanControllerIdTemp"!][!//
[!IF "CanObjectType=$RxObjectType"!][!//
[!VAR "NumRxMO" = "$NumRxMO + $MsgObSize"!][!//
[!IF "$FirstRxMO > CanObjectId"!][!//
[!VAR "FirstRxMO" = "CanObjectId"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "CanObjectType=$TxObjectType"!][!//
[!VAR "NumTxMO" = "$NumTxMO + $MsgObSize"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
[!VAR "NumTxMO" = "($NumTxMO + (CanMultiplexedHwObjects - 1)*$MsgObSize)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "CanControllerActivation = 'true'"!][!//
  { { [!//
[!IF "num:i($NumRxMO) > num:i(0)"!][!//
[!IF "text:split(CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
[!VAR "FirstRxMO" = "$CanRxHwObjectCntKer0"!][!//
[!VAR "CanRxHwObjectCntKer0" = "$CanRxHwObjectCntKer0 + $NumRxMO"!][!//
[!ELSE!][!//
[!VAR "FirstRxMO" = "$CanRxHwObjectCntKer1"!][!//
[!VAR "CanRxHwObjectCntKer1" = "$CanRxHwObjectCntKer1 + $NumRxMO"!][!//
[!ENDIF!][!//
[!"num:i($FirstRxMO)"!]U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
, [!"num:i($NumRxMO)"!]U, [!//
[!IF "num:i($NumTxMO) > num:i(0)"!][!//
[!IF "text:split(CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
[!VAR "FirstTxMO" = "$CanTxHwObjectIdKer0"!][!//
[!VAR "CanTxHwObjectIdKer0" = "$CanTxHwObjectIdKer0 + $NumTxMO"!][!//
[!ENDIF!][!//
[!IF "text:split(CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1"!][!//
[!VAR "FirstTxMO" = "$CanTxHwObjectIdKer1"!][!//
[!VAR "CanTxHwObjectIdKer1" = "$CanTxHwObjectIdKer1 + $NumTxMO"!][!//
[!ENDIF!][!//
[!"num:i($FirstTxMO)"!]U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
, [!"num:i($NumTxMO)"!]U } }[!//
[!ELSE!][!//
  { { 0U, 0U, 0U, 0U } }[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]
};
[!ENDSELECT!]
[!ENDFOR!]
[!//

/*******************************************************************************
              CAN Controller Handling of Events : Interrupt/Polling
********************************************************************************
        { CanBusoffProcessing, CanRxProcessing, 
          CanTxProcessing, CanWakeupProcessing }
********************************************************************************
           Note: If the CAN controller is not activated then,
                 { 0U, 0U, 0U, 0U } will be generated
*******************************************************************************/

[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!VAR "NumControllers" = "num:i(count(CanController/*))"!][!//
/* [!"./@name"!] -> CAN Controller - Handling of Events */
static const Can_EventHandlingType Can_kEventHandlingConfig_[!"num:i($Instance)"!][] = 
{
[!FOR "TempIndex" = "0" TO "$NumControllers - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "$TempIndex > 0"!][!//
,
[!ENDIF!][!//
[!IF "CanControllerActivation = 'true'"!][!//
 { { [!//
[!CALL "CG_IsEventPolled", "event" = "CanBusoffProcessing"!],[!//
[!CALL "CG_IsEventPolled", "event" = "CanRxProcessing"!],[!//
[!CALL "CG_IsEventPolled", "event" = "CanTxProcessing"!],[!//
[!CALL "CG_IsEventPolled", "event" = "CanWakeupProcessing"!][!//
} }[!//
[!ELSE!][!//
 { { 0U, 0U, 0U, 0U } }[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]
};
[!ENDSELECT!]
[!ENDFOR!]
[!//

/*******************************************************************************
              CAN Controller <-> Default Baudrate Mapping
********************************************************************************
          { NBTR Register Settings, Default Baudrate in kbps }
*******************************************************************************/

[!/* Extract Default Baudrate for each of the CAN Controllers */!][!//
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!VAR "NumControllers" = "num:i(count(CanController/*))"!][!//
/* [!"./@name"!] -> CAN Controller - default baudrate mapping */
static const Can_17_MCanP_ControllerBaudrateConfigType Can_kDefaultBaudrateConfig_[!"num:i($Instance)"!][] = 
{
[!FOR "TempIndex" = "0" TO "$NumControllers - 1"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "./CanControllerActivation = 'true'"!][!//
[!IF "node:refexists(CanControllerDefaultBaudrate) ='true'"!][!//
[!VAR "CanDefaultBaudrateRef" = "node:path(node:ref(CanControllerDefaultBaudrate))"!][!//
[!IF "contains($CanDefaultBaudrateRef, node:path(.)) = 'true'"!][!//
[!ELSE!][!//
[!ERROR!][!//
[!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
[!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanControllerId [!"CanControllerId"!] is referred to a default baudrate which does not belong to the same CanController.
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "ModuleClockBy8" = "num:i(0)"!][!//
[!VAR "TimeQuantaNanoSecond" = "num:i(1000000000) div ( ((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerPropSeg))+(num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSeg1))+(num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSeg2))+1) * (num:i(node:ref($CanDefaultBaudrateRef)/CanControllerBaudRate)*num:i(1000)))"!][!//
[!VAR "BRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(1000000000)) - 1)+ 0.5)"!][!//
[!IF "$BRP > 63"!][!//
[!//
[!IF "(./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!ERROR!][!//
ERROR: Configured Baud rate [!"num:i(./CanControllerBaudrateConfig/*[position()=$i]/CanControllerBaudRate)"!] kbps for controller Id [!"num:i(CanControllerId)"!] of CanConfigSet [!"node:name(../..)"!] is not possible in CAN FD mode.Since it cause BRP vale greater than 63. This is not allowed when controller configured for CAN FD.
[!ENDERROR!][!//
[!ELSE!][!//
[!//
[!VAR "BRP" = "num:i((((($TimeQuantaNanoSecond) * num:i($CANModuleClock)) div num:i(8000000000)) - 1) + 0.5)"!][!//
[!VAR "ModuleClockBy8" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(./CanControllerFdBaudrateConfig/*[1])"!][!//
[!VAR "SJW" = "bit:shl((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSyncJumpWidth - 1)),8)"!][!//
[!VAR "TSEG1" = "bit:shl((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerPropSeg + node:ref($CanDefaultBaudrateRef)/CanControllerSeg1 - 1)),22)"!][!//
[!VAR "TSEG2" = "bit:shl((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSeg2 - 1)),16)"!][!//
[!ELSE!][!//
[!VAR "SJW" = "bit:shl((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSyncJumpWidth - 1)),6)"!][!//
[!VAR "TSEG1" = "bit:shl((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerPropSeg + node:ref($CanDefaultBaudrateRef)/CanControllerSeg1 - 1)),8)"!][!//
[!VAR "TSEG2" = "bit:shl((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSeg2 - 1)),12)"!][!//
[!ENDIF!][!//
[!VAR "DIV8" = "bit:shl((num:i($ModuleClockBy8)),15)"!][!//
[!VAR "tempNBTR" = "bit:or($BRP,$SJW)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$TSEG1)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$TSEG2)"!][!//
[!VAR "tempNBTR" = "bit:or($tempNBTR,$DIV8)"!][!//
  /* CAN Controller [!"CanControllerId"!] :
     Configured Baudrate -> [!"num:i(node:ref($CanDefaultBaudrateRef)/CanControllerBaudRate)"!] kbps
[!IF "$ModuleClockBy8 != num:i(1)"!][!//
     Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerPropSeg + node:ref($CanDefaultBaudrateRef)/CanControllerSeg1))+(num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSeg2))+1) * (num:i($BRP)+1))) div 1000"!] kbps */
[!ELSE!][!//
     Actual Baudrate     -> [!"(num:i($CANModuleClock) div (((num:i(node:ref($CanDefaultBaudrateRef)/CanControllerPropSeg + node:ref($CanDefaultBaudrateRef)/CanControllerSeg1))+(num:i(node:ref($CanDefaultBaudrateRef)/CanControllerSeg2))+1) * ((num:i($BRP)+1) * 8))) div 1000"!] kbps */
[!ENDIF!][!//
  { [!"num:inttohex($tempNBTR)"!]U, [!"num:i(node:ref($CanDefaultBaudrateRef)/CanControllerBaudRate)"!]U }[!//
[!ELSE!][!//
[!ERROR!][!//
   CanControllerDefaultBaudrate not Configured for CanControllerId [!"CanControllerId"!] of CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!ELSE!][!//
  /* CAN controller [!"CanControllerId"!] is not activated */
  { 0U, 0U }[!//
[!ENDIF!][!//
[!IF "$TempIndex < ($NumControllers - 1)"!][!//
,
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

};
[!ENDSELECT!]
[!ENDFOR!]
[!//

[!IF "$NumFifoConfigsMax > num:i(0)"!][!//
/*******************************************************************************
                      CAN Receive FIFO Configurations
********************************************************************************
{Mask, Msg Id, Rx MO Id, Hw Controller Id, [Id Type,] Fifo Size, Fifo Threshold}
********************************************************************************
Note: [1] If the associated CAN Controller is not activated then,
            Rx MO Id -> 0
            Hw Controller Id -> 255
            Fifo Size -> 0
            Fifo Threshold -> 0
      [2] If CanFifoFilterMaskRef is not configured then, 
            Mask -> 0x7ff - for STANDARD Msg Id Type
                    0x1fffffff - for EXTENDED/MIXED Msg Id Type
*******************************************************************************/

[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!VAR "HwMOId" = "num:i(count(CanHardwareObject/*[CanObjectType=$RxObjectType]))"!][!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
/* [!"./@name"!] -> CAN Receive FIFO Configurations */
static const Can_RxFifoConfigType Can_kRxFifoHwObjectConfig_[!"$Instance"!][] =
{
[!VAR "HwMOIdKer0FD" = "num:i(0)"!][!//
[!VAR "HwMOIdKer1FD" = "num:i(0)"!][!//
[!VAR "HwMOIdKer0STD" = "num:i(0)"!][!//
[!VAR "HwMOIdKer1STD" = "num:i(0)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "(node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!VAR "HwMOIdKer0FD" = "$HwMOIdKer0FD + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "HwMOIdKer0STD" = "$HwMOIdKer0STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "(node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!VAR "HwMOIdKer1FD" = "$HwMOIdKer1FD + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "HwMOIdKer1STD" = "$HwMOIdKer1STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "HwMOIdKer0" = "($HwMOIdKer0FD * num:i(3)) + $HwMOIdKer0STD"!][!//
[!VAR "HwMOIdKer1" = "($HwMOIdKer1FD * num:i(3)) + $HwMOIdKer1STD"!][!//

[!VAR "TempIndex" = "num:i(0)"!][!//
[!LOOP "CanFifoConfiguration/*"!][!//
[!IF "$TempIndex > 0"!][!//
,
[!ENDIF!][!//
  { [!//
[!IF "node:refexists(CanFifoFilterMaskRef/*[1]) ='true'"!][!//
[!IF "node:refexists(CanFifoControllerRef) ='true'"!][!//
[!VAR "CanFifoFilterMaskRefPath" = "node:path(node:ref(CanFifoFilterMaskRef/*[1]))"!][!//
[!VAR "CanFifoControllerRefPath" = "node:path(node:ref(CanFifoControllerRef))"!][!//
[!IF "contains($CanFifoFilterMaskRefPath, $CanFifoControllerRefPath) = 'true'"!][!//
[!ELSE!][!//
[!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
[!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
[!VAR "CanMaskConfigSetName" = "substring-after($CanFifoFilterMaskRefPath, "CanConfigSet/")"!][!//
[!VAR "CanMaskConfigSetName" = "substring-before($CanMaskConfigSetName, "/")"!][!//
[!IF "contains($CanConfigSetName, $CanMaskConfigSetName) = 'true'"!][!//
[!WARNING!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanFifoObjectId [!"CanFifoObjectId"!] is referred to a Filter Mask which does not belong to the referred CanController.
[!ENDWARNING!][!//
[!ELSE!][!//
[!ERROR!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanFifoObjectId [!"CanFifoObjectId"!] is referred to a Filter Mask which does not belong to the same CanConfigSet.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!"num:inttohex(node:ref(CanFifoFilterMaskRef/*[1])/CanFilterMaskValue)"!]U, [!//
[!ELSE!][!//
[!IF "CanFifoIdType = 'STANDARD'"!][!//
0x7ffU, [!//
[!ELSE!][!//
0x1fffffffU, [!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "CanFifoIdType = 'STANDARD'"!][!//
[!ASSERT "num:i(CanFifoIdValue) >= num:i(0) and num:i(CanFifoIdValue) <= num:i(2047)"!][!//
 Error in CanFifoObjectId [!"CanFifoObjectId"!] of CanConfigSet [!"node:name(../..)"!]: Allowed range for STANDARD CanFifoIdType is: 0 to 0x7FF.
[!ENDASSERT!][!//
[!ELSE!][!//
[!IF "CanFifoIdType = 'EXTENDED'"!][!//
[!ASSERT "num:i(CanFifoIdValue) >= num:i(0) and num:i(CanFifoIdValue) <= num:i(536870911)"!][!//
 Error in CanFifoObjectId [!"CanFifoObjectId"!] of CanConfigSet [!"node:name(../..)"!]: Allowed range for EXTENDED CanFifoIdType is: 0 to 0x1FFFFFFF.
[!ENDASSERT!][!//
[!ELSE!][!//
[!IF "num:i(CanFifoIdValue) != num:i(0)"!][!//
[!ASSERT "num:i(CanFifoIdValue) >= num:i(262144) and num:i(CanFifoIdValue) <= num:i(536608768)"!][!//
 Error in CanFifoObjectId [!"CanFifoObjectId"!] of CanConfigSet [!"node:name(../..)"!]: Allowed range for MIXED CanFifoIdType is: 0x0 and 0x40000 to 0x1FFC0000.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!"num:inttohex(CanFifoIdValue)"!]U, [!//
[!IF "node:refexists(CanFifoControllerRef) ='true'"!][!//
[!VAR "CanFifoControllerRefPath" = "node:path(node:ref(CanFifoControllerRef))"!][!//
[!VAR "CanConfigSetPath" = "substring-before(node:path(.), "/CanFifoConfiguration/")"!][!//
[!IF "contains($CanFifoControllerRefPath, $CanConfigSetPath) = 'true'"!][!//
[!ELSE!][!//
[!ERROR!][!//
[!VAR "CanConfigSetName" = "substring-after(node:path(.), "CanConfigSet/")"!][!//
[!VAR "CanConfigSetName" = "substring-before($CanConfigSetName, "/")"!][!//
In CanConfigSet [!"$CanConfigSetName"!] the CanFifoObjectId [!"CanFifoObjectId"!] is referred to a CanController which does not belong to the same CanConfigSet.
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "node:ref(CanFifoControllerRef)/CanControllerActivation = 'true'"!][!//
[!IF "text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
[!"num:i($HwMOIdKer0)"!]U,[!//
[!VAR "HwMOIdKer0" = "$HwMOIdKer0 + num:i(CanFifoSize)"!][!//
[!ELSE!][!//
[!"num:i($HwMOIdKer1)"!]U,[!//
[!VAR "HwMOIdKer1" = "$HwMOIdKer1 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!IF "ecu:get('Can.MaxCtrlKer') = '3'"!][!//
[!IF "($CanRxHwObjectCntKer0 > num:i(128)) or ($CanRxHwObjectCntKer1 > num:i(128))"!][!//
[!ERROR!][!//
     Total number of message objects configured either to
     Kernel1(Node0+Node1+Node2) or Kernel2(Node3+Node4+Node5) exceeds the 
     allowed limit (128)
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "ecu:get('Can.MaxCtrlKer') = '4'"!][!//
[!IF "($CanRxHwObjectCntKer0 > num:i(256)) or ($CanRxHwObjectCntKer1 > num:i(128))"!][!//
[!ERROR!][!//
     Total number of message objects configured either to
     Kernel1(Node0+Node1+Node2+Node3) or Kernel2(Node4+Node5) exceeds the 
     allowed limit (Kernel1-256,Kernel2-128)
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
 [!"text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1]"!]U, [!//
[!ELSE!][!//
0U, 255U, [!//
[!ENDIF!][!//
[!ELSE!][!//
[!ERROR!][!//
   CanFifoControllerRef is not Configured in [!"@name"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$StandardIdOnly = 'false'"!][!//
[!CALL "CG_GetHwObjectIdType", "node" = "CanFifoIdType"!], [!//
[!ENDIF!][!//
[!IF "node:ref(CanFifoControllerRef)/CanControllerActivation = 'true'"!][!//
[!"num:i(CanFifoSize)"!]U, [!//
[!"num:i(CanFifoThreshold)"!]U }[!//
[!ELSE!][!//
0U, 0U }[!//
[!ENDIF!][!//
[!VAR "TempIndex" = "$TempIndex + 1"!][!//
[!ENDLOOP!]
};
[!ENDIF!][!//
[!ENDSELECT!]
[!ENDFOR!]
[!ENDIF!][!//

/******************************************************************************/
                      /* CAN Configuration Pointer */
/******************************************************************************/
      /* Over all CAN configurations in the array, pointer to one of the 
           configuration is passed as parameter to Can_Init API */   
/******************************************************************************/

const Can_17_MCanP_ConfigType Can_17_MCanP_ConfigRoot[] = 
{
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
  {
    /* Pointer to Loopback and receive input pin selection setting */
    &Can_kNPCR_[!"$Instance"!][0],
[!IF "$WakeupSupported = num:i(1)"!][!//

    /* Pointer to Wakeup Source Id Configuration */
    &Can_kWakeupSourceId_[!"$Instance"!][0],
[!ENDIF!][!//

    /* Pointer to CAN Controller <-> Hardware Objects Mapping */
    &Can_kControllerMOMapConfig_[!"$Instance"!][0],

    /* Pointer to CAN Controller Handling of Events : Interrupt/Polling */
    &Can_kEventHandlingConfig_[!"$Instance"!][0],

    /* Pointer to Controller Baudrate Configuration */
    &Can_kBaudrateConfig_[!"$Instance"!][0],

    /* Pointer to default baudrate configuration */
    &Can_kDefaultBaudrateConfig_[!"$Instance"!][0],

[!IF "$FDNodesPresent = num:i(1)"!][!//
	/* Pointer to CAN Controller FD Configuration Parameters*/
	&Can_kFDConfigParam_[!"$Instance"!][0],
[!ENDIF!][!//	

[!IF "$CanRxCalloutFnExists = num:i(1)"!][!//
    /* CAN L-PDU Receive Callout Function */
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
    (Can_LPduRxCalloutFnPtrType)[!"$RxLPduCallout"!],
[!ELSE!][!//
    &[!"$RxLPduCallout"!],
[!ENDIF!][!//
[!ENDIF!][!//

[!VAR "HOType" = "num:i(0)"!][!//
[!VAR "HOTypeController" = "num:i(0)"!][!//
[!FOR "HwObjIndex" ="num:i(0)" TO "num:i(count(CanHardwareObject/*)-1)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!IF "CanObjectId = $HwObjIndex"!][!//
[!IF "CanObjectType=$RxObjectType"!][!//
[!IF "$HOType = num:i(1)"!][!//
[!ERROR!][!//
  ERROR: All HRHs should have lower CanObjectId than all HTHs.
    Eg.: CanObjectId in increasing order: HRHs of CanControllerId 0, HRHs of CanControllerId 1, HTHs of CanControllerId 0, HTHs of CanControllerId 1, etc..
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "CanObjectType=$TxObjectType"!][!//
[!IF "$HOType = num:i(0)"!][!//
[!VAR "HOType" = "num:i(1)"!][!//
[!VAR "HOTypeController" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$HOTypeController > num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
[!ERROR!][!//
  Hardware Objects should be numbered and grouped as per the below rules:
    -HRHs belonging to a controller should be grouped together. These groups should be configured in the increasing order of CanControllerId.
    -HTHs belonging to a controller should be grouped together. These groups should be configured in the increasing order of CanControllerId.
    -All HRHs should have lower CanObjectId than all HTHs.
    Eg.: CanObjectId in increasing order: HRHs of CanControllerId 0, HRHs of CanControllerId 1, HTHs of CanControllerId 0, HTHs of CanControllerId 1, etc..
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "HOTypeController" = "num:i(node:ref(CanControllerRef)/CanControllerId)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!//
[!VAR "TotalRxMO_Size" = "num:i(0)"!][!//
[!VAR "TotalTxMO_Size" = "num:i(0)"!][!//
[!VAR "NumRxMO_FD" = "num:i(0)"!][!//
[!VAR "NumRxMO_STD" = "num:i(0)"!][!//
[!VAR "NumTxMO_FD" = "num:i(0)"!][!//
[!VAR "NumTxMO_STD" = "num:i(0)"!][!//
[!VAR "CanObjType" = "num:i(0)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!VAR "CanObjType" = "CanObjectType"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!IF "$CanObjType=$RxObjectType"!][!//
[!VAR "NumRxMO_FD" = "$NumRxMO_FD + 1"!][!//
[!ENDIF!][!//
[!IF "$CanObjType=$TxObjectType"!][!//
[!VAR "NumTxMO_FD" = "$NumTxMO_FD + 1"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!IF "$CanObjType=$RxObjectType"!][!//
[!VAR "NumRxMO_STD" = "$NumRxMO_STD + 1"!][!//
[!ENDIF!][!//
[!IF "$CanObjType=$TxObjectType"!][!//
[!VAR "NumTxMO_STD" = "$NumTxMO_STD + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDLOOP!][!//
[!VAR "TotalRxMO_Size" = "num:i($TotalRxMO_Size + ($NumRxMO_FD * num:i(3)) + $NumRxMO_STD)"!][!//
[!VAR "TotalTxMO_Size" = "num:i($TotalTxMO_Size + ($NumTxMO_FD * num:i(3)) + $NumTxMO_STD)"!][!//
[!VAR "TotalRxMO" = "num:i(0)"!][!//
[!VAR "TotalTxMO" = "num:i(0)"!][!//
[!LOOP "CanController/*"!][!//
[!VAR "NumRxMO" = "num:i(0)"!][!//
[!VAR "NumTxMO" = "num:i(0)"!][!//
[!VAR "CanControllerIdTemp" = "CanControllerId"!][!//
[!LOOP "../../CanHardwareObject/*"!][!//
[!IF "node:ref(CanControllerRef)/CanControllerId = $CanControllerIdTemp"!][!//
[!IF "CanObjectType=$RxObjectType"!][!//
[!VAR "NumRxMO" = "$NumRxMO + 1"!][!//
[!ENDIF!][!//
[!IF "CanObjectType=$TxObjectType"!][!//
[!VAR "NumTxMO" = "$NumTxMO + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "TotalRxMO" = "num:i($TotalRxMO + $NumRxMO)"!][!//
[!VAR "TotalTxMO" = "num:i($TotalTxMO + $NumTxMO)"!][!//
[!ENDLOOP!][!//
[!IF "$TxObjectCountMax > num:i(0)"!][!//
   /* Pointer to Configuration of transmit hardware objects */
[!IF "$TotalTxMO > 0"!][!//
    &Can_kTxHwObjectConfig_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$RxObjectCountMax > num:i(0)"!][!//
    /* Pointer to Configuration of receive hardware objects */
[!IF "$TotalRxMO > 0"!][!//
    &Can_kRxHwObjectConfig_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$NumFifoConfigsMax > 0"!][!//
    /* Pointer to the first Receive FIFO configuration */
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
    &Can_kRxFifoHwObjectConfig_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "(($TxObjectCountMax > num:i(0)) and ($CanTxHwObjectKer0 > num:i(0)))"!][!//
    /* Pointer to Configuration of Kernal0 Hth Mapping */
[!IF "$TotalTxMO > 0"!][!//
    &Can_kTxObjectHthKer0Map_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "(($TxObjectCountMax > num:i(0)) and ($CanTxHwObjectKer1 > num:i(0)))"!][!//
    /* Pointer to Configuration of Hth Mapping */
[!IF "$TotalTxMO > 0"!][!//
    &Can_kTxObjectHthKer1Map_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "(($RxObjectCountMax > num:i(0)) and ($CanRxHwObjectKer0 > num:i(0)))"!][!//
    /* Pointer to Configuration of Hrh Mapping */
[!IF "$TotalRxMO > 0"!][!//
    &Can_kRxObjectHrhKer0Map_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "(($RxObjectCountMax > num:i(0)) and ($CanRxHwObjectKer1 > num:i(0)))"!][!//
    /* Pointer to Configuration of Hrh Mapping */
[!IF "$TotalRxMO > 0"!][!//
    &Can_kRxObjectHrhKer1Map_[!"$Instance"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
[!ENDIF!][!//

    /* CAN Module clock configuration : Fractional Divider Register setting */
[!IF "CanClockConfiguration/CanClockDividerMode = 'NORMAL_DIVIDER'"!][!//
    /* NORMAL_DIVIDER - Bit 14 is set */
    /* CanClockStepValue [!"num:i(CanClockConfiguration/CanClockStepValue)"!] ([!"num:inttohex(CanClockConfiguration/CanClockStepValue)"!]) is assigned to bit 0-9. */
    [!"num:inttohex(bit:or(num:hextoint('0x00004000'),num:i(CanClockConfiguration/CanClockStepValue)))"!]U,
[!ELSE!][!//
    /* FRACTIONAL_DIVIDER - Bit 15 is set */
    /* CanClockStepValue [!"num:i(CanClockConfiguration/CanClockStepValue)"!] ([!"num:inttohex(CanClockConfiguration/CanClockStepValue)"!]) is assigned to bit 0-9. */
    [!"num:inttohex(bit:or(num:hextoint('0x00008000'),num:i(CanClockConfiguration/CanClockStepValue)))"!]U,
[!ENDIF!][!//

[!VAR "NumControllers" = "num:i(count(CanController/*))"!][!//
    /* Number of configured CAN controllers */
    [!"num:i($NumControllers)"!]U,
  
    /* CanControllerId --> CanHwControllerId (MultiCAN+ Controller Id) */
    { [!//
[!FOR "TempIndex" = "0" TO "$NumControllers"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "$TempIndex > 0"!][!//
, [!//
[!ENDIF!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!"text:split(CanHwControllerId, '_')[position()-1 = 1]"!]U[!//
[!ELSE!][!//
255U[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
 },
 
    /* CAN Controller-wise number of baudrate configurations */
    { [!//
[!FOR "TempIndex" = "0" TO "$NumControllers"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerId = $TempIndex"!][!//
[!IF "$TempIndex > 0"!][!//
, [!//
[!ENDIF!][!//
[!"num:i(count(./CanControllerBaudrateConfig/*))"!]U[!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
 },

[!IF "$TxObjectCountMax > num:i(0)"!][!//
    /* Total number of Transmit Hardware Objects */
    [!"num:i($TotalTxMO)"!]U,
[!ENDIF!][!//
  
[!IF "$RxObjectCountMax > num:i(0)"!][!//
    /* Total number of Receive Hardware Objects */
    [!"num:i($TotalRxMO)"!]U,
[!ENDIF!][!//
  
    /* Number of Receive Rx MOs + Rx FIFO MOs */
[!VAR "LastCanFifoSize" = "num:i(0)"!][!//
[!VAR "TotalRxFifoMO" = "num:i($TotalRxMO)"!][!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
[!LOOP "CanFifoConfiguration/*"!][!//
[!IF "node:ref(CanFifoControllerRef)/CanControllerActivation = 'true'"!][!//
[!VAR "TotalRxFifoMO" = "$TotalRxFifoMO + num:i(CanFifoSize)"!][!//
[!VAR "LastCanFifoSize" = "num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
    [!"num:i($TotalRxFifoMO)"!]U,
	
[!VAR "CanRxHwObjectCntKer0FD" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer1FD" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer0STD" = "num:i(0)"!][!//
[!VAR "CanRxHwObjectCntKer1STD" = "num:i(0)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "(node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!VAR "CanRxHwObjectCntKer0FD" = "$CanRxHwObjectCntKer0FD + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "CanRxHwObjectCntKer0STD" = "$CanRxHwObjectCntKer0STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSEIF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "(node:exists(CanControllerFdBaudrateConfig/*[1]))"!][!//
[!VAR "CanRxHwObjectCntKer1FD" = "$CanRxHwObjectCntKer1FD + num:i(1)"!][!//
[!ELSE!][!//
[!VAR "CanRxHwObjectCntKer1STD" = "$CanRxHwObjectCntKer1STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "CanRxHwObjectCntKer0" = "($CanRxHwObjectCntKer0FD * num:i(3)) + $CanRxHwObjectCntKer0STD"!][!//
[!VAR "CanRxHwObjectCntKer1" = "($CanRxHwObjectCntKer1FD * num:i(3)) + $CanRxHwObjectCntKer1STD"!][!//
[!VAR "CanRxHwObjFifoCntKer0" = "num:i(0)"!][!//
[!VAR "CanRxHwObjFifoCntKer1" = "num:i(0)"!][!//
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
[!LOOP "CanFifoConfiguration/*"!][!//
[!IF "node:refexists(CanFifoControllerRef) ='true'"!][!//
[!IF "(node:ref(CanFifoControllerRef)/CanControllerActivation = 'true')and (text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1)"!][!//
[!VAR "CanRxHwObjFifoCntKer0" = "$CanRxHwObjFifoCntKer0 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!IF "(node:ref(CanFifoControllerRef)/CanControllerActivation = 'true')and (text:split(node:ref(CanFifoControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1)"!][!//
[!VAR "CanRxHwObjFifoCntKer1" = "$CanRxHwObjFifoCntKer1 + num:i(CanFifoSize)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!VAR "CanTxHwObjectIdKer0" = "($CanRxHwObjectCntKer0)  + $CanRxHwObjFifoCntKer0"!][!//
[!VAR "CanTxHwObjectIdKer1" = "($CanRxHwObjectCntKer1)  + $CanRxHwObjFifoCntKer1"!][!//
[!IF "$TxObjectCountMax > num:i(0)"!][!//
    /* Transmit Hardware Objects Offset Kernel wise */
    { [!"num:i($CanTxHwObjectIdKer0)"!]U[!//
[!IF "ecu:get('Can.MaxKernels') > '1'"!][!//
, [!"num:i($CanTxHwObjectIdKer1)"!]U[!//
[!ENDIF!][!//
 },
[!ENDIF!][!//

[!IF "$RxObjectCountMax > num:i(0)"!][!//
    /* Receive Hardware Objects Offset Kernel wise */
    { [!"num:i(0)"!]U[!//
[!IF "ecu:get('Can.MaxKernels') > '1'"!][!//
, [!"num:i(0)"!]U[!//
[!ENDIF!][!//
 },
[!ENDIF!][!//

    /* Number of Rx FIFO MOs Kernel wise*/
    { [!"num:i($CanRxHwObjFifoCntKer0)"!]U[!//
[!IF "ecu:get('Can.MaxKernels') > '1'"!][!//
, [!"num:i($CanRxHwObjFifoCntKer1)"!]U[!//
[!ENDIF!][!//
 },

[!VAR "TotalRxFifoMOUsed" = "$TotalRxMO_Size+ $CanRxHwObjFifoCntKer0 + $CanRxHwObjFifoCntKer1"!][!//
[!IF "$TotalRxFifoMOUsed > num:i(ecu:get('Can.MaxHwObjects'))"!][!//
[!ERROR!][!//
Number of message objects required for the configuration is more than the number of message objects available in the hardware (i.e., [!"ecu:get('Can.MaxHwObjects')"!])!
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$RxObjectCountMax > num:i(0)"!][!//
    /* Last MSPND register to be scanned for Rx MOs */
[!ENDIF!][!//
[!VAR "TotalRxFifoMO_1" = "$TotalRxFifoMOUsed - $LastCanFifoSize + 1"!][!//
[!VAR "NumMspnd" = "0"!][!//
[!IF "$TotalRxFifoMO_1 > num:i(32)"!][!//
[!VAR "NumMspnd" = "1"!][!//
[!ENDIF!][!//
[!IF "$TotalRxFifoMO_1 > num:i(64)"!][!//
[!VAR "NumMspnd" = "2"!][!//
[!ENDIF!][!//
[!IF "$TotalRxFifoMO_1 > num:i(96)"!][!//
[!VAR "NumMspnd" = "3"!][!//
[!ENDIF!][!//
[!IF "$TotalRxFifoMO_1 > num:i(128)"!][!//
[!VAR "NumMspnd" = "4"!][!//
[!ENDIF!][!//
[!IF "$TotalRxFifoMO_1 > num:i(160)"!][!//
[!VAR "NumMspnd" = "5"!][!//
[!ENDIF!][!//
[!IF "$TotalRxFifoMO_1 > num:i(192)"!][!//
[!VAR "NumMspnd" = "6"!][!//
[!ENDIF!][!//
[!IF "$TotalRxFifoMO_1 > num:i(224)"!][!//
[!VAR "NumMspnd" = "7"!][!//
[!ENDIF!][!//
[!IF "($RxObjectCountMax > num:i(0)) or ($NumFifoConfigsMax > num:i(0))"!][!//
    [!"num:i($NumMspnd)"!]U,
[!ENDIF!][!//
  
[!IF "$TxObjectCountMax > num:i(0)"!][!//
    /* First MSPND register to be scanned for Tx MOs */
[!ENDIF!][!//
[!VAR "NumMspnd" = "0"!][!//
[!VAR "MinTxObjOffset" = "$CanTxHwObjectIdKer0"!][!//
[!IF "$CanTxHwObjectIdKer0 > $CanTxHwObjectIdKer1"!][!//
[!VAR "MinTxObjOffset" = "$CanTxHwObjectIdKer1"!][!//
[!ENDIF!][!//
[!VAR "NumMspnd" = "$MinTxObjOffset div 32"!][!//
[!IF "$TxObjectCountMax > num:i(0)"!][!//
    [!"num:i($NumMspnd)"!]U,
[!ENDIF!][!//
  
[!IF "$TxObjectCountMax > num:i(0)"!][!//
    /* Last MSPND register to be scanned for Tx MOs */
[!ENDIF!][!//
[!VAR "TotalMO" = "num:i($TotalRxFifoMOUsed)"!][!//
[!IF "$MultiplexedTransmission = num:i(1)"!][!//
[!LOOP "CanHardwareObject/*[CanObjectType=$TxObjectType]"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "MsgObSize" = "num:i(3)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "MsgObSize" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!VAR "TotalMO" = "num:i($TotalMO + (CanMultiplexedHwObjects * $MsgObSize))"!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
[!VAR "TotalMO" = "num:i($TotalMO + $TotalTxMO_Size)"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(ecu:get('Can.MaxHwObjects'))"!][!//
[!ERROR!][!//
  Number of message objects required for the configuration is more than the number of message objects available in the hardware (i.e., [!"ecu:get('Can.MaxHwObjects')"!])!
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "NumMspnd" = "0"!][!//
[!IF "$TotalMO > num:i(32)"!][!//
[!VAR "NumMspnd" = "1"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(64)"!][!//
[!VAR "NumMspnd" = "2"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(96)"!][!//
[!VAR "NumMspnd" = "3"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(128)"!][!//
[!VAR "NumMspnd" = "4"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(160)"!][!//
[!VAR "NumMspnd" = "5"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(192)"!][!//
[!VAR "NumMspnd" = "6"!][!//
[!ENDIF!][!//
[!IF "$TotalMO > num:i(224)"!][!//
[!VAR "NumMspnd" = "7"!][!//
[!ENDIF!][!//
[!IF "$TxObjectCountMax > num:i(0)"!][!//
    [!"num:i($NumMspnd)"!]U,
[!ENDIF!][!//

[!IF "$NumFifoConfigsMax > 0"!][!//
    /* Number of Receive FIFOs configured */
[!IF "node:exists(CanFifoConfiguration/*[1]) = 'true'"!][!//
    [!"num:i(count(CanFifoConfiguration/*))"!]U,
[!ELSE!][!//
    0U,
[!ENDIF!][!//
[!ENDIF!][!//
  }[!//
[!IF "$Instance < $ConfigCount"!],[!ENDIF!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//

#define CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
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

