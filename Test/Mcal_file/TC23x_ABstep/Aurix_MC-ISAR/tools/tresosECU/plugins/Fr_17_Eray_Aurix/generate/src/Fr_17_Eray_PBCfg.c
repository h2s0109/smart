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
**  $FILENAME   : Fr_17_Eray_PBCfg.c $                                       **
**                                                                            **
**  $CC VERSION : \main\49 $                                                 **
**                                                                            **
**  $DATE       : 2016-07-07 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for Fr_17_Eray_PBCfg.c file                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
**************************************************************************/!][!//
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
**  $FILENAME   : Fr_17_Eray_PBCfg.c $                                       **
**                                                                            **
**  $CC VERSION : \main\49 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : FR configuration generated out of ECU configuration file   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/** Traceability : [cover parentID=DS_NAS_FR_PR446,
           DS_NAS_FR_PR700,DS_NAS_FR_PR701,DS_NAS_FR_PR704,DS_NAS_FR_PR707,
            DS_NAS_FR_PR708,DS_NAS_FR_PR712,DS_NAS_FR_PR713,DS_NAS_FR_PR714,
            DS_NAS_FR_PR716,DS_NAS_FR_PR717,DS_NAS_FR_PR723,DS_NAS_FR_PR724,
            DS_NAS_FR_PR728,DS_NAS_FR_PR709,SAS_AS4XX_FR_PR680,DS_AS403_FR485
            DS_AS403_FR487,DS_AS_FR481_FR482_FR483,DS_AS403_FR624]
** [/cover]                                                                  **/

[!NOCODE!]
[!INCLUDE "Fr_17_Eray.m"!][!//
[!ENDNOCODE!]

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */ 
#include "Fr_17_Eray.h"

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
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
                      Global Constant Definitions                          
*******************************************************************************/

/* macro values for  FrIfGdSampleClockPeriod */
#define T12_5NS ((uint8)0)
#define T25NS   ((uint8)1)
#define T50NS   ((uint8)2)
#define T100NS  ((uint8)3)
#define T200NS  ((uint8)4)

[!NOCODE!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "MainOscillatorFrequency" = "num:i(McuGeneralConfiguration/McuMainOscillatorFrequency)"!][!//
[!VAR "ModulePath" = "'McuModuleConfiguration'"!][!//
[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i($Count)- 1)"!][!//
[!SELECT "node:ref($ModulePath)/*[@index = $ModuleIndex]"!][!//
[!VAR "LoopVar" = "'McuClockSettingConfig'"!][!//
[!LOOP "node:ref($LoopVar)/*"!][!//
[!SELECT "McuClockReferencePoint"!][!//
[!VAR "ErayPllNDivider" = "num:i(McuErayPllNDivider)+1"!][!//
[!VAR "ErayPllK2Divider" = "num:i(McuErayPllK2Divider)+1"!][!//McuErayDivider
[!VAR "ErayDivider" = "num:i(McuErayDivider)"!][!//
[!ASSERT "not($ErayDivider = num:i(0))"!][!//
Config Error :Invalid McuErayDivider in McuModuleConfiguration_[!"$ModuleIndex"!], McuErayDivider must not be 0 
[!ENDASSERT!][!//
[!VAR "PllClockOut" = "num:i(($ErayPllNDivider * $MainOscillatorFrequency) div num:i($ErayPllK2Divider * $ErayDivider) )"!][!//
[!ASSERT "not($PllClockOut != 80)"!][!//
Config Error :Invalid Pll_Eray frequency in McuModuleConfiguration_[!"$ModuleIndex"!]. Supported frequencie(s): 80MHz
Example configuration: for 20MHz Crystal: McuErayPllNDivider - 19,McuErayPllK2Divider - 4, McuErayDivider - 1
[!ENDASSERT!][!//
[!ENDSELECT!][!// 
[!ENDLOOP!][!// 
[!ENDSELECT!][!// 
[!ENDFOR!][!// 
[!ENDSELECT!][!// 
[!ENDNOCODE!][!//           
[!VAR "ModuleName" = "'Fr'"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(FrMultipleConfiguration/*))"!][!//
[!NOCODE!][!//
[!//
[!/* Determine only one FrMultipleConfiguration is configured 
                                        when FrBFixedAddress = true.*/!]
[!IF "FrGeneral/FrPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($ConfigCount != 1)"!][!//
Config Error: when FrGeneral/FrPBFixedAddres is set as true, [!//
Only one FrMultipleConfiguration configuration is allowed. [!//
But FrMultipleConfiguration has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!//
[!//
[!//
[!/* Start of dump for FlexTrain */!][!//
[!VAR "MSG_RAM_SIZE_TOTAL" = "num:i(8192)"!][!//
[!VAR "MSG_BUFFER_COUNT_MAX" = "num:i(128)"!][!//
[!VAR "FlexTrainForFifo" = "num:i(0)"!][!//
/*
@@@@@@START_OF_FLEX-TRAIN_DUMP@@@@@@
NUMBER_OF_PB_CFG [!"$ConfigCount"!]
MSG_RAM_SIZE_TOTAL [!"$MSG_RAM_SIZE_TOTAL"!]
MSG_BUFFER_COUNT_MAX [!"$MSG_BUFFER_COUNT_MAX"!]
[!/* Dummy comment - introduced to get rid of syntax highlight issue with next line */!]
[!FOR "Instance" = "0" TO "$ConfigCount - 1"!][!/* DUMP_FOR1 */!][!//
PB_CFG_START
[!SELECT "FrMultipleConfiguration/*[@index = $Instance]"!][!//
[!VAR "Counter" = "num:i(count(./FrController/*))"!][!//
[!FOR "Index" = "0" TO "(num:i($Counter)- 1)"!][!//
[!SELECT "./FrController/*[@index = $Index]"!][!//
[!VAR "ControllerPath" = "node:path(.)"!][!//
[!VAR "ControllerIdx" = "./FrCtrlIdx"!][!//
[!/* Example: ControllerPath = /AUTOSAR/TOP-LEVEL-PACKAGES/Fr/ELEMENTS/Fr/FrMultipleConfiguration/Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-after($ControllerPath, 'FrMultipleConfiguration')"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath1" = "substring-after($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath1 = /FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-before($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath2 = /Default_0 */!][!//
[!VAR "ControllerPath2" = "concat($ControllerPath2, $ControllerPath1)"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController_0 */!][!//
[!VAR "CtrlRefFound" = "num:i(0)"!][!//
[!LOOP "as:modconf('FrIf')[1]/FrIfConfig/*"!][!/* DUMP_LOOP1 */!][!//
[!LOOP "FrIfCluster/*"!][!/* DUMP_LOOP2 */!][!//
[!VAR "CurrentCluster" = "node:path(.)"!][!//
[!VAR "MacroPerCycle" = "FrIfGMacroPerCycle"!][!//
[!VAR "NumberOfStaticSlots" = "FrIfGNumberOfStaticSlots"!][!//
[!VAR "MSG_RAM_DYNAMIC" = "num:i(0)"!][!//
[!LOOP "FrIfController/*"!][!/* DUMP_LOOP3 */!][!//
[!VAR "FrIfControllerPath" = "node:ref(node:path(./FrIfFrCtrlRef))"!][!//
[!VAR "FrIfControllerPath" = "substring-after($FrIfControllerPath, '/Fr/Fr')"!][!//
[!IF "$FrIfControllerPath = $ControllerPath2"!][!/* IF1 */!][!//
[!//
[!VAR "SumOfLPduLengths" = "num:i(0)"!][!//
[!LOOP "FrIfLPdu/*"!][!/* DUMP_LOOP9 */!][!//
[!VAR "SumOfLPduLengths" = "$SumOfLPduLengths + node:ref(FrIfVBTriggeringRef)/FrIfLSduLength"!][!//
[!ENDLOOP!][!/* DUMP_LOOP9 */!][!//
[!VAR "LPduCount" = "num:i(count(FrIfLPdu/*))"!][!//
[!IF "num:i($SumOfLPduLengths + ($LPduCount * 16)) > $MSG_RAM_SIZE_TOTAL"!][!//
FLEX_TRAIN_RUN_REQUIRED YES [!"$ControllerIdx"!] [!"num:i($SumOfLPduLengths + ($LPduCount * 16))"!]
[!ELSE!][!//
FLEX_TRAIN_RUN_REQUIRED NO [!"$ControllerIdx"!] [!"num:i($SumOfLPduLengths + ($LPduCount * 16))"!]
[!ENDIF!][!//
[!//
[!VAR "KeySlotId" = "num:i(2048)"!][!/* 2047 is maximum slot ID possible */!][!//
[!VAR "KeySlotUsedForStartup" = "node:value(node:ref(concat($ControllerPath, '/FrPKeySlotUsedForStartup')))"!][!//
[!VAR "KeySlotUsedForSync" = "node:value(node:ref(concat($ControllerPath, '/FrPKeySlotUsedForSync')))"!][!//
[!IF "node:exists(concat($ControllerPath, '/FrPKeySlotId'))"!][!//
[!VAR "KeySlotId" = "node:ref(concat($ControllerPath, '/FrPKeySlotId'))"!][!//
[!/* ---------  Config Rule FR_CR_097 ---------*/!][!//
[!ASSERT "$KeySlotId <= $NumberOfStaticSlots"!][!//
Error: Key Slot ID of controller [!"$ControllerPath"!] corresponds to a dynamic slot.
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!ENDIF!][!//
[!VAR "KeySlotLPduExists" = "num:i(0)"!][!//
[!VAR "KeySlotLPduIdx" = "'NO_LPDU_IDX'"!][!//
[!IF "($KeySlotId != num:i(2048)) and ($KeySlotId != num:i(0))"!][!/* Key slot Id exists */!][!//
[!LOOP "FrIfLPdu/*"!][!/* DUMP_LOOP8 */!][!//
[!IF "(node:ref(FrIfVBTriggeringRef)/FrIfSlotId) = $KeySlotId"!][!//
KEY_SLOT_LPDU,1,[!"FrIfLPduIdx"!],[!"num:i(node:ref(FrIfVBTriggeringRef)/FrIfLSduLength)"!]
[!VAR "KeySlotLPduIdx" = "FrIfLPduIdx"!][!//
[!VAR "KeySlotLPduExists" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP8 */!][!//
[!/* ---------  Config Rule FR_CR_209 ---------*/!][!//
[!ASSERT "$KeySlotLPduExists = num:i(1)"!][!//
Error: There is no LPDU that corresponds to Key Slot ID for [!"$ControllerPath"!].
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!ELSE!][!//
KEY_SLOT_LPDU,0
[!ASSERT "($KeySlotUsedForStartup = 'false') and ($KeySlotUsedForSync = 'false')"!][!//
Error: There is no Key Slot ID configured for controller [!"$ControllerPath"!], Hence FrPKeySlotUsedForStartup or FrPKeySlotUsedForSync cannot be enabled for that controller.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!//
[!IF "node:exists(concat($ControllerPath, '/FrFifo/*[1]'))"!][!//
FIFO_LPDU[!//
[!/* ---------  Config Rule FR_CR_202 ---------*/!][!//
[!ASSERT "node:isconsecutive(FrIfLPdu/*/FrIfLPduIdx, 0)"!][!//
Error: FrIfLPduIdx not consecutive.
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!VAR "FrFifoPath" = "concat($ControllerPath, '/FrFifo/FrFifo_0')"!][!//
[!VAR "FifoLpduLength" = "num:i(0)"!][!//
[!VAR "RejectStaticSegment" = "num:i(0)"!][!//
[!IF "node:value(concat($FrFifoPath, '/FrRejectStaticSegment')) = 'true'"!][!//
[!VAR "RejectStaticSegment" = "num:i(1)"!][!//
[!ENDIF!][!//
[!LOOP "FrIfLPdu/*"!][!/* DUMP_LOOP7 */!][!//
[!VAR "RejectLpdu" = "num:i(0)"!][!//
[!VAR "LpduChannel" = "substring-after(node:ref(FrIfVBTriggeringRef)/FrIfChannel, '_')"!][!//
[!VAR "LpduCycleCode" = "node:ref(FrIfVBTriggeringRef)/FrIfBaseCycle + node:ref(FrIfVBTriggeringRef)/FrIfCycleRepetition"!][!//
[!VAR "LpduFid" = "node:ref(FrIfVBTriggeringRef)/FrIfSlotId"!][!//
[!IF "$RejectStaticSegment = num:i(1)"!][!//
[!IF "$LpduFid <= $NumberOfStaticSlots"!][!//
[!VAR "RejectLpdu" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$RejectLpdu = num:i(0)"!][!//
[!VAR "FifoChannel" = "substring-after(node:ref(concat($FrFifoPath, '/FrChannels')), '_')"!][!//
[!IF "$LpduChannel = $FifoChannel"!][!//
[!VAR "FifoCycleCode" = "node:value(node:ref(concat($FrFifoPath, '/FrBaseCycle'))) + node:value(node:ref(concat($FrFifoPath, '/FrCycleRepetition')))"!][!//
[!IF "$LpduCycleCode = $FifoCycleCode"!][!//
[!VAR "RejectionFilterID" = "num:i(node:value(node:ref(concat($FrFifoPath, '/FrFrameIdRejectionFilter'))))"!][!//
[!VAR "RejectionFilterMask" = "num:i(node:value(node:ref(concat($FrFifoPath, '/FrFrameIdRejectionFilterMask'))))"!][!//
[!VAR "RejectionFilter" = "bit:or(num:i($RejectionFilterID),num:i($RejectionFilterMask))"!][!//
[!VAR "RejectLpdu" = "num:i(1)"!][!//
[!FOR "BitPosition" = "0" TO "10"!][!/* for 11 bit FID */!][!//
[!VAR "getBit" = "bit:getbit(num:i($RejectionFilterMask),num:i($BitPosition))"!][!//
[!IF "$getBit = 'false'"!][!//
[!IF "$RejectLpdu = num:i(1)"!][!//
[!IF "bit:getbit(num:i($RejectionFilter),num:i($BitPosition)) = bit:getbit(num:i($LpduFid),num:i($BitPosition))"!][!//
[!VAR "RejectLpdu" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "RejectLpdu" = "num:i(0)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$RejectLpdu = num:i(0)"!][!//
[!IF "$FifoLpduLength = num:i(0)"!][!//
[!VAR "FifoLpduLength" = "num:i(node:ref(FrIfVBTriggeringRef)/FrIfLSduLength)"!][!//
[!ELSE!][!//
[!ASSERT "$FifoLpduLength = num:i(node:ref(FrIfVBTriggeringRef)/FrIfLSduLength)"!][!//
Error: Fifo data length must be same for all the Fifo Lpdus, the Lpdu([!"FrIfLPduIdx"!]) is configured with wrong length for [!"$ControllerPath"!].
[!ENDASSERT!][!//
[!ASSERT "FrIfLPduIdx != $KeySlotLPduIdx"!][!//
Error: Keyslot Lpdu can not be part of FIFO for [!"$ControllerPath"!].
[!ENDASSERT!][!//
[!ENDIF!][!//
[!IF "node:ref(FrIfVBTriggeringRef)/FrIfAlwaysTransmit = 'true'"!][!//
[!VAR "LPduTxStatus" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "LPduIdxPath" = "node:path(.)"!][!//
[!NOCODE!][!//
[!CALL "CG_GetLPduIdxPath", "LPduIdxPath" = "$LPduIdxPath"!][!//
[!CALL "CG_MsBufDir", "CurrentCluster" = "$CurrentCluster", "LPduIdxPath" = "$LPduIdxPath"!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//
[!//
[!ASSERT "$LPduTxStatus = num:i(0)"!][!//
Error: Only receive LPDU can be configured for FIFO, LPDU[!"FrIfLPduIdx"!] is a Transmit LPDU for [!"$ControllerPath"!]
[!ENDASSERT!][!//
[!VAR "FlexTrainForFifo" = "num:i(1)"!][!//
,[!"FrIfLPduIdx"!][!//
,[!"num:i(node:ref(FrIfVBTriggeringRef)/FrIfLSduLength)"!][!//
[!IF "$LpduFid <= $NumberOfStaticSlots"!][!//
,S[!//
[!ELSE!][!//
,D[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP7 */!]
[!ENDIF!][!//
[!//
[!VAR "DynamicSlotCount" = "num:i(0)"!][!//
[!LOOP "FrIfLPdu/*"!][!//
[!IF "num:i(node:ref(FrIfVBTriggeringRef)/FrIfSlotId) > $NumberOfStaticSlots"!][!//
[!VAR "DynamicSlotCount" = "num:i($DynamicSlotCount + num:i(1))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
DYNAMIC_LPDU,[!"$DynamicSlotCount"!][!//
[!/* ---------  Config Rule FR_CR_202 ---------*/!][!//
[!ASSERT "node:isconsecutive(FrIfLPdu/*/FrIfLPduIdx, 0)"!][!//
Error: FrIfLPduIdx not consecutive for [!"$ControllerPath"!].
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!LOOP "FrIfLPdu/*"!][!/* DUMP_LOOP7 */!][!//
[!IF "(node:ref(FrIfVBTriggeringRef)/FrIfSlotId) > $NumberOfStaticSlots"!][!//
[!/* ---------  Config Rule FR_CR_211 ---------*/!][!//
[!ASSERT "(node:ref(FrIfVBTriggeringRef)/FrIfChannel) != 'FRIF_CHANNEL_AB'"!][!//
Error: Dynamic segment LPDU ([!"FrIfVBTriggeringRef"!]) is configured for both the channels (A and B) for [!"$ControllerPath"!].
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
,[!"FrIfLPduIdx"!][!//
,[!"num:i(node:ref(FrIfVBTriggeringRef)/FrIfLSduLength)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP7 */!]
[!//
[!VAR "FrIfCtrlName" = "substring-after(node:path(.), 'FrIfController/')"!][!//
[!LOOP "../../FrIfJobList/FrIfJob/*"!][!/* DUMP_LOOP4 */!][!//
[!VAR "CommOpCount" = "num:i(0)"!][!//
[!LOOP "FrIfCommunicationOperation/*"!][!/* DUMP_LOOP5 */!][!//
[!/* Find out if there are any LPDUs that need share message objects i.e. the 
      LPDUs that are not dynamic and LPDU that corresponds to key slot id.
      Note that IF conditions are same as used inside the forthcoming loop
        LOOP "FrIfCommunicationOperation/*"
*/!][!//
[!IF "contains(FrIfLPduIdxRef, $FrIfCtrlName)"!][!//
[!IF "num:i(node:ref(node:ref(./FrIfLPduIdxRef)/FrIfVBTriggeringRef)/FrIfSlotId) <= $NumberOfStaticSlots"!][!//
[!IF "node:ref(./FrIfLPduIdxRef)/FrIfLPduIdx != $KeySlotLPduIdx"!][!//
[!VAR "CommOpCount" = "$CommOpCount + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP5 */!][!//
[!IF "num:i($CommOpCount) != num:i(0)"!][!//
[!"num:i((FrIfCycle * $MacroPerCycle) + FrIfMacrotick)"!],[!"num:i($CommOpCount)"!][!//
[!LOOP "FrIfCommunicationOperation/*"!][!/* DUMP_LOOP6 */!][!//
[!IF "contains(FrIfLPduIdxRef, $FrIfCtrlName)"!][!//
[!/* Message buffers shared only by LPDUs meant for static segment */!][!//
[!IF "num:i(node:ref(node:ref(./FrIfLPduIdxRef)/FrIfVBTriggeringRef)/FrIfSlotId) <= $NumberOfStaticSlots"!][!//
[!IF "node:ref(./FrIfLPduIdxRef)/FrIfLPduIdx != $KeySlotLPduIdx"!][!/* LPDU corresponding to key slot */!][!//
,[!"node:ref(./FrIfLPduIdxRef)/FrIfLPduIdx"!][!//
,[!"num:i(node:ref(node:ref(./FrIfLPduIdxRef)/FrIfVBTriggeringRef)/FrIfLSduLength)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP6 */!]
[!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP4 */!][!//
[!VAR "CtrlRefFound" = "num:i(1)"!][!//
[!//
[!BREAK!][!//
[!ENDIF!][!/* IF1 */!][!//
[!ENDLOOP!][!/* DUMP_LOOP3 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP2 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDLOOP!][!/* DUMP_LOOP1 */!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
PB_CFG_END

[!ENDFOR!][!/* DUMP_FOR1 */!][!//
@@@@@@END_OF_FLEX-TRAIN_DUMP@@@@@@
*/
[!//End of dump for FlexTrain
[!//
[!//
[!//
#define FR_17_ERAY_START_SEC_POSTBUILDCFG
#include "MemMap.h"
[!FOR "Instance" = "0" TO "$ConfigCount - 1"!][!/* RECONFIG_FOR1 */!][!//
[!//
[!SELECT "FrMultipleConfiguration/*[@index = $Instance]"!][!//
[!VAR "Counter" = "num:i(count(./FrController/*))"!][!//
[!FOR "Index" = "0" TO "(num:i($Counter)- 1)"!][!//
[!SELECT "./FrController/*[@index = $Index]"!][!//
[!VAR "ControllerPath" = "node:path(.)"!][!//
[!VAR "ControllerIndex" = "./FrCtrlIdx"!][!//
[!/* Example: ControllerPath = /AUTOSAR/TOP-LEVEL-PACKAGES/Fr/ELEMENTS/Fr/FrMultipleConfiguration/Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-after($ControllerPath, 'FrMultipleConfiguration')"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath1" = "substring-after($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath1 = /FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-before($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath2 = /Default_0 */!][!//
[!VAR "ControllerPath2" = "concat($ControllerPath2, $ControllerPath1)"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController_0 */!][!//
[!/* ControllerPath path2 = [!"$ControllerPath2"!]*/!][!//
[!/* Following variable is used to terminate the loop */!][!//
[!VAR "CtrlRefFound" = "num:i(0)"!][!//
[!LOOP "as:modconf('FrIf')[1]/FrIfConfig/*"!][!/* RECONFIG_LOOP1 */!][!//
[!LOOP "FrIfCluster/*"!][!/* LOOP1 */!][!/* RECONFIG_LOOP2 */!][!//
[!//
[!VAR "NumberOfStaticSlots" = "FrIfGNumberOfStaticSlots"!][!//
[!VAR "CurrentCluster" = "node:path(.)"!][!//
[!LOOP "FrIfController/*"!][!/* RECONFIG_LOOP3 */!][!//
[!VAR "FrIfControllerPath" = "node:ref(node:path(./FrIfFrCtrlRef))"!][!//
[!VAR "FrIfControllerPath" = "substring-after($FrIfControllerPath, '/Fr/Fr')"!][!//
[!IF "$FrIfControllerPath = $ControllerPath2"!][!/* RECONFIG_IF1 */!][!//
[!VAR "SumOfLPduLengths" = "num:i(0)"!][!//
[!LOOP "FrIfLPdu/*"!][!/* RECONFIG_LOOP4 */!][!//
[!VAR "SumOfLPduLengths" = "$SumOfLPduLengths + node:ref(FrIfVBTriggeringRef)/FrIfLSduLength"!][!//
[!ENDLOOP!][!/* RECONFIG_LOOP4 */!][!//
[!//
[!//
[!//
[!VAR "LPduCount" = "num:i(count(FrIfLPdu/*))"!][!//
[!VAR "MSG_RAM_SIZE_REQD" = "num:i($SumOfLPduLengths + ($LPduCount * 16))"!][!//
[!IF "($MSG_RAM_SIZE_REQD > $MSG_RAM_SIZE_TOTAL) or ($LPduCount > $MSG_BUFFER_COUNT_MAX) or (($FlexTrainForFifo = num:i(1)) and ($Instance = num:i(0)))"!][!/* RECONFIG_IF2 */!][!//
[!/* 
  FlexTrain tool run is required to find LPDU to message buffer mapping. 
  FlexTrain tool output follows.
*/!]
[!/* ---------  Config Rule FR_CR_098 ---------*/!][!//
[!ASSERT "as:modconf($ModuleName)[1]/FrGeneral/FrBufferReconfig = 'true'"!][!//
Error: Buffer reconfiguration is required but FrBufferReconfig is OFF (false)
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
/* Forward declarations */
/*IFX_MISRA_RULE_08_12_STATUS=This forward declaration is needed as Flextrain shall write
 the reconfigurable Lpdu to MsgBuffer mapping array only at the end of the file*/
static const uint8 Fr_17_Eray_LPduIdx2MsgBuff_[!"$ControllerIndex"!]_[!"$Instance"!][] ;
/*IFX_MISRA_RULE_08_12_STATUS=This forward declaration is needed as Flextrain shall write
 the reconfigurable Lpdu to MsgBuffer mapping array only at the end of the file*/
static const uint16 Fr_17_Eray_DataPointerOffset_[!"$ControllerIndex"!]_[!"$Instance"!][] ;
[!ELSE!][!/* RECONFIG_IF2 */!][!//
/*
  LPduIdx to message buffer mapping for Controller [!"$ControllerIndex"!]: Post-build configuration [!"$Instance"!]   
*/
[!VAR "LPduCount" = "num:i(count(FrIfLPdu/*))"!][!//
[!//
static const uint8 Fr_17_Eray_LPduIdx2MsgBuff_[!"$ControllerIndex"!]_[!"$Instance"!][[!"num:i($LPduCount)"!]] = {[!//
[!//
[!FOR "k" = "0" TO "$LPduCount - 2"!][!/* RECONFIG_FOR2 */!][!//
[!"$k"!]U, [!//
[!ENDFOR!][!/* RECONFIG_FOR2 */!][!//
[!"num:i($LPduCount - 1)"!]U} ; 
[!//
static const uint16 Fr_17_Eray_DataPointerOffset_[!"$ControllerIndex"!]_[!"$Instance"!][[!"num:i($LPduCount)"!]] = {[!//
[!/* Note: Data pointer is pointer to the first 32-bit word of the 
Data Section of the addressed Message Buffer in the Message RAM. */!][!//
[!VAR "DataPointerOffset" = "num:i($LPduCount * 4)"!][!//
[!FOR "i" = "0" TO "$LPduCount - 2"!][!/* RECONFIG_FOR3 */!][!//
[!VAR "vCrcReg" = "0"!][!//
[!VAR "LPduIdxPath" = "node:path(FrIfLPdu/*[FrIfLPduIdx = $i])"!][!//
[!NOCODE!]
[!CALL "CG_GetLPduIdxPath", "LPduIdxPath" = "$LPduIdxPath"!][!//
[!ENDNOCODE!][!//
[!SELECT "node:ref(FrIfLPdu/*[FrIfLPduIdx = $i]/FrIfVBTriggeringRef)"!][!/* RECONFIG_SELECT1 */!][!//
[!"$DataPointerOffset"!]U, [!//
[!IF "(FrIfLSduLength mod 4) = 0"!][!/* RECONFIG_IF3 */!][!//
[!VAR "DataPointerOffset" = "num:i($DataPointerOffset + (FrIfLSduLength div 4))"!][!//
[!ELSE!][!//
[!VAR "DataPointerOffset" = "num:i($DataPointerOffset + (FrIfLSduLength div 4) + 1)"!][!//
[!ENDIF!][!/* RECONFIG_IF3 */!][!//
[!ENDSELECT!][!/* RECONFIG_SELECT1 */!][!//
[!ENDFOR!][!/* RECONFIG_FOR3 */!][!//
[!"$DataPointerOffset"!]U} ; 
[!//

[!ENDIF!][!/* RECONFIG_IF2 */!][!//
[!VAR "CtrlRefFound" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!/* RECONFIG_IF1 */!][!//
[!ENDLOOP!][!/* RECONFIG_LOOP3 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!]
[!ENDLOOP!][!/* RECONFIG_LOOP2 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!]
[!ENDLOOP!][!/* RECONFIG_LOOP1 */!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!/* RECONFIG_FOR1 */!][!//
[!//
[!//
[!//
[!/*
Case 1: An FrController is not referred in any cluster in any of the FrIf (post-build) configurations
    ==> This is an error. 
Case 2: An FrController is referred in multiple clusters in any of the FrIf (post-build) configurations
    ==> In this case, first cluster (found by the XPath search) that refers to FrController is considered
Case 3: An FrController is referred in multiple clusters in multiple FrIf (post-build) configurations
    ==> In this case, first cluster of first FrIf module confguration (found by the XPath search), 
        that refers to FrController is considered
*/!]

[!FOR "Instance" = "0" TO "$ConfigCount - 1"!][!/* LPDU_CONFIG_FOR1 */!][!//
[!//
[!SELECT "FrMultipleConfiguration/*[@index = $Instance]"!][!//
[!VAR "Counter" = "num:i(count(./FrController/*))"!][!//
[!FOR "Index" = "0" TO "(num:i($Counter)- 1)"!][!//
[!SELECT "./FrController/*[@index = $Index]"!][!//
[!VAR "ControllerPath" = "node:path(.)"!][!//
[!VAR "ControllerIndex" = "./FrCtrlIdx"!][!//
[!/* ControllerPath path = [!"$ControllerPath"!]*/!][!//
[!/* Example: ControllerPath = /AUTOSAR/TOP-LEVEL-PACKAGES/Fr/ELEMENTS/Fr/FrMultipleConfiguration/Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-after($ControllerPath, 'FrMultipleConfiguration')"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath1" = "substring-after($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath1 = /FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-before($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath2 = /Default_0 */!][!//
[!VAR "ControllerPath2" = "concat($ControllerPath2, $ControllerPath1)"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController_0 */!][!//
[!/* ControllerPath path2 = [!"$ControllerPath2"!]*/!][!//
[!/* Following variable is used to terminate the loop */!][!//
[!VAR "CtrlRefFound" = "num:i(0)"!][!//
[!LOOP "as:modconf('FrIf')[1]/FrIfConfig/*"!][!/* LPDU_CONFIG_LOOP1 */!][!//
[!LOOP "FrIfCluster/*"!][!/* LPDU_CONFIG_LOOP2 */!][!//
[!//
[!VAR "ClusterChannels" = "FrIfGChannels"!][!//
[!VAR "NumberOfStaticSlots" = "FrIfGNumberOfStaticSlots"!][!//
[!VAR "PayloadLengthStatic" = "FrIfGPayloadLengthStatic"!][!//
[!VAR "CurrentCluster" = "node:path(.)"!][!//
[!LOOP "FrIfController/*"!][!/* LPDU_CONFIG_LOOP3 */!][!//
[!VAR "FrIfControllerPath" = "node:ref(node:path(./FrIfFrCtrlRef))"!][!//
[!VAR "FrIfControllerPath" = "substring-after($FrIfControllerPath, '/Fr/Fr')"!][!//
[!IF "$FrIfControllerPath = $ControllerPath2"!][!/* LPDU_CONFIG_IF1 */!][!//
[!VAR "LPduCount" = "num:i(count(FrIfLPdu/*))"!][!//
[!/* ---------  Config Rule FR_CR_204 ---------*/!][!//
[!ASSERT "$LPduCount < num:i(255)"!][!//
Error: Number of LPDUs configured ([!"$LPduCount"!] is more than supported (255, Id = 0 to 254).
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!VAR "PayloadLengthDynMax" = "node:value(node:ref(concat($ControllerPath, '/FrPPayloadLengthDynMax')))"!][!//
[!VAR "KeySlotUsedForStartup" = "num:i(0)"!][!//
[!VAR "KeySlotUsedForSync" = "num:i(0)"!][!//
[!VAR "KeySlotId" = "num:i(2048)"!][!/* 2047 is maximum slot ID possible */!][!//
[!IF "node:exists(concat($ControllerPath, '/FrPKeySlotId'))"!][!//
[!VAR "KeySlotId" = "node:ref(concat($ControllerPath, '/FrPKeySlotId'))"!][!//
[!IF "node:value(node:ref(concat($ControllerPath, '/FrPKeySlotUsedForStartup'))) = 'true'"!][!//
[!VAR "KeySlotUsedForStartup" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "StaticLPduCount" = "num:i(0)"!][!//
[!LOOP "FrIfLPdu/*"!][!/* LPDU_CONFIG_LOOP4 */!][!//
[!IF "(node:ref(FrIfVBTriggeringRef)/FrIfSlotId) <= $NumberOfStaticSlots"!][!//
[!VAR "StaticLPduCount" = "num:i($StaticLPduCount + 1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* LPDU_CONFIG_LOOP4 */!][!//
[!IF "node:value(node:ref(concat($ControllerPath, '/FrPKeySlotUsedForSync'))) = 'true'"!][!//
[!VAR "KeySlotUsedForSync" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!VAR "LatestTx" = "node:ref(concat($ControllerPath, '/FrPLatestTx'))"!][!//
[!VAR "NumberOfStaticSlots" = "num:i(node:value(concat($CurrentCluster,'/FrIfGNumberOfStaticSlots')))"!][!//
[!VAR "NumberOfMinislots" = "num:i(node:value(concat($CurrentCluster,'/FrIfGNumberOfMinislots')))"!][!//
[!/* ---------  Config Rule FR_CR_092 ---------*/!][!//
[!ASSERT "not($LatestTx > $NumberOfMinislots)"!][!//
Error: PLatestTx [!"$LatestTx"!] is greater than number of configured Minislots - [!"$NumberOfMinislots"!]
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!//
[!VAR "WakeupChannel" = "node:ref(concat($ControllerPath, '/FrPWakeupChannel'))"!][!//
[!VAR "WakeupChannel2" = "substring-after($WakeupChannel, 'FR_CHANNEL_')"!][!//
[!VAR "Channels" = "node:ref(concat($ControllerPath, '/FrPChannels'))"!][!//
[!VAR "Channels2" = "substring-after($Channels, 'FR_CHANNEL_')"!][!//
[!/* ---------  Config Rule FR_CR_213 ---------*/!][!//
[!ASSERT "contains($Channels2, $WakeupChannel2)"!][!//
Error: Wakeup channel can not be [!"$WakeupChannel"!] when CC channel configuration FrPChannels is [!"$Channels"!] 
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!/* ---------  Config Rule FR_CR_099 ---------*/!][!//
[!ASSERT "contains($ClusterChannels, $Channels)"!][!//
Error: Node channel configuration (FrPChannels) can not be [!"$Channels"!] when cluster channel configuration (GChannels) is [!"$ClusterChannels"!] 
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!//
/*************** LPDU configuration Controller [!"$ControllerIndex"!] (PB Config [!"$Instance"!]) ***************/
static const Fr_17_Eray_LPduConfigType Fr_17_Eray_kLPduConfig_[!"$ControllerIndex"!]_[!"$Instance"!] [[!"$LPduCount"!]] =
{
[!FOR "i" = "0" TO "$LPduCount - 1"!][!/* LPDU_CONFIG_FOR2 */!][!//
[!VAR "vCrcReg" = "0"!][!//
[!VAR "LPduIdxPath" = "node:path(FrIfLPdu/*[FrIfLPduIdx = $i])"!][!//
[!NOCODE!]
[!CALL "CG_GetLPduIdxPath", "LPduIdxPath" = "$LPduIdxPath"!][!//
[!ENDNOCODE!][!//
[!SELECT "node:ref(FrIfLPdu/*[FrIfLPduIdx = $i]/FrIfVBTriggeringRef)"!][!/* LPDU_CONFIG_SELECT1 */!][!//
[!NOCODE!]
[!//
[!/* Find out the LPDU direction */!][!//
[!IF "FrIfAlwaysTransmit = 'true'"!][!//
[!VAR "LPduTxStatus" = "num:i(1)"!][!//
[!ELSE!][!//
[!CALL "CG_MsBufDir", "CurrentCluster" = "$CurrentCluster", "LPduIdxPath" = "$LPduIdxPath"!][!//
[!ENDIF!][!//
[!//
[!/****************** Start of Header CRC calculation *******************/!][!//
[!VAR "CurrentSlotId" = "FrIfSlotId"!][//
[!IF "FrIfSlotId > $NumberOfStaticSlots"!][!/* Daynamic frame */!][!//
[!VAR "LSduLength16BitWords" = "FrIfLSduLength div 2"!][//
[!CALL "CG_HeaderCRC", "Sync" = "num:i(0)", "Sfi" = "num:i(0)", "Fid" = "FrIfSlotId", "Plc" = "$LSduLength16BitWords"!][!//
[!ELSE!][!/* Static frame */!][!//
[!IF "FrIfSlotId = $KeySlotId"!][!/* Key slot frame (one of the static frames)*/!][!//
[!/* ---------  Config Rule FR_CR_210 ---------*/!][!//
[!ASSERT "$LPduTxStatus = num:i(1)"!][!//
Error: Key slot ([!"$KeySlotId"!]) is configured to be used by a receive frame/LPDU.
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!/* 
    Note: $PayloadLengthStatic is already in terms of 16 bit words since 
            GPayloadLengthStatic is mentioned in terms of 16 bit words 
*/!][!//
[!CALL "CG_HeaderCRC", "Sync" = "$KeySlotUsedForSync", "Sfi" = "$KeySlotUsedForStartup", "Fid" = "FrIfSlotId", "Plc" = "$PayloadLengthStatic"!][!//
[!ELSE!][!//
[!/* Not a keyslot id frame : Sync = 0, Sfi = 0 */!][!//
[!CALL "CG_HeaderCRC", "Sync" = "num:i(0)", "Sfi" = "num:i(0)", "Fid" = "FrIfSlotId", "Plc" = "$PayloadLengthStatic"!][!//
[!ENDIF!][!/* KeySlot or not ? */!][!//
[!ENDIF!][!/* Static or dynamic ? */!][!//
[!/****************** End of Header CRC calculation *********************/!][!//
[!//
[!VAR "CtrlChCfg" = "substring-after(node:value(concat($ControllerPath, '/FrPChannels')), '_')"!]
[!VAR "LpduChCfg" = "substring-after(FrIfChannel, '_')"!]
[!IF "$CtrlChCfg != 'CHANNEL_AB'"!]
[!/* ---------  Config Rule FR_CR_212 ---------*/!][!//
[!ASSERT "$CtrlChCfg = $LpduChCfg"!]
Error: Channel configuration for LPDU [!"$i"!] ([!"$LpduChCfg"!]) is not consistent with channel configuration on CC ([!"$CtrlChCfg"!]).
[!ENDASSERT!]
[!/* ------------------------------------------*/!][!//
[!ENDIF!]
[!ENDNOCODE!][!//
  /* -------------------------  LPDU [!"$i"!] ------------------------------- */
  {
    {
      {
        [!"FrIfSlotId"!]U,              /* Slot ID */
[!/* ---------  Config Rule FR_CR_206 ---------*/!][!//
[!ASSERT "FrIfBaseCycle < FrIfCycleRepetition"!][!//
Error: FrIfBaseCycle ([!"FrIfBaseCycle"!]) is not less than FrIfCycleRepetition ([!"FrIfCycleRepetition"!]) for frame [!"node:path(.)"!]
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
        [!"num:i(FrIfCycleRepetition + FrIfBaseCycle)"!]U,              /* Cycle code */
        (uint8)(FR_[!"substring-after(FrIfChannel,'_')"!] + (Fr_ChannelType)0x1),  /* FrPChannels , add 0x1 as the hw regs take ChannelA = 1, ChannelB = 2 and ChannelAB = 3 */
        [!"$LPduTxStatus"!]U,              /* Message Buffer Direction: 0 - Receive, 1 - Transmit */
[!IF "FrIfPayloadPreamble = 'true'"!][!//
        1U[!//
[!ELSE!][!//
        0U[!//
[!ENDIF!],              /* PPIT: 0 - Disable, 1 - Enable */
        1U,              /* Transmission Mode : 1 - Single shot - always single shot */
        0U               /* Message Buffer Service Request - always set to 0 */
      }
    },
    {
      {
[!IF "$LPduTxStatus = num:i(1)"!][!//
        [!"$vCrcReg"!]U,       /* Header CRC */
[!ELSE!][!//
        0x0U,       /* Header CRC */
[!ENDIF!][!// 
[!/* ---------  Config Rule FR_CR_203 ---------*/!][!//
[!ASSERT "num:i(FrIfLSduLength mod 2) = num:i(0)"!][!//
Error: LSDU length for frame [!"node:path(.)"!] is not even number ([!"FrIfLSduLength"!])
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!//
[!IF "FrIfSlotId <= $NumberOfStaticSlots"!][!//
[!/* ---------  Config Rule FR_CR_216 ---------*/!][!//
[!ASSERT "num:i(FrIfLSduLength div 2) <= $PayloadLengthStatic"!][!//
Error: LSDU length for frame [!"node:path(.)"!] ([!"num:i(FrIfLSduLength div 2)"!] 16-bit words) is more than gPayloadLengthStatic ([!"$PayloadLengthStatic"!] 16-bit words)
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!ELSE!][!//
[!/* ---------  Config Rule FR_CR_217 ---------*/!][!//
[!ASSERT "num:i(FrIfLSduLength div 2) <= $PayloadLengthDynMax"!][!//
Error: LSDU length for frame [!"node:path(.)"!] ([!"num:i(FrIfLSduLength div 2)"!] 16-bit words) is more than PPayloadLengthDynMax ([!"$PayloadLengthDynMax"!] 16-bit words)
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!ENDIF!][!//
[!ASSERT "not((./FrIfSlotId <= $NumberOfStaticSlots) and (./FrIfAllowDynamicLSduLength = 'true')) "!][!//
Error: LSDU [!"node:path(.)"!] is configured as static frame and  FrIfAllowDynamicLSduLength is configured.
FrIfAllowDynamicLSduLength should not enabled for static frames.
[!ENDASSERT!][!//
[!/* Note: WRHS2.B.PLC is length of Data Section (number of 2-byte words) 
as configured by the Host. */!][!//
        [!"num:i(FrIfLSduLength div 2)"!]U,               /* Payload Length Configured */
        [!CALL "CG_ConfigSwitch2", "nodeval" = "FrIfAllowDynamicLSduLength"!]U,    /* FrIfAllowDynamicLSduLength */    
      }
    },
    [!/* Generate LPDU Reconfigurable Flag */!][!//
[!ENDSELECT!][!/* LPDU_CONFIG_SELECT1 */!][!//
[!SELECT "FrIfLPdu/*[FrIfLPduIdx = $i]"!][!//
[!IF "FrIfReconfigurable = 'true'"!][!//
[!IF "($KeySlotUsedForSync = num:i(1)) and ($KeySlotUsedForStartup = num:i(1))"!][!//
[!ASSERT "$CurrentSlotId != $KeySlotId"!][!//
Error: Key slot ([!"$KeySlotId"!]) frame/LPDU can not be Reconfigured as it is used for Sync frame transmission .
[!ENDASSERT!][!//
[!ENDIF!][!//
FR_LPDU_RECONFIGURABLE
[!ELSE!][!//
FR_LPDU_NOT_RECONFIGURABLE
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "node:ref(FrIfLPdu/*[FrIfLPduIdx = $i]/FrIfVBTriggeringRef)"!][!/* LPDU_CONFIG_SELECT1 */!][!//
  }[!//
[!IF "$i < ($LPduCount - 1)"!], [!ENDIF!][!//
[!ENDSELECT!][!/* LPDU_CONFIG_SELECT1 */!][!//
[!ENDFOR!][!/* LPDU_CONFIG_FOR2 */!][!//
};
[!//
  
[!VAR "FrIfNodePath" = "$CurrentCluster"!][!//
[!//
[!/* IFX_FR010 */!][!//
[!/* ---------  Config Rule FR_CR_200 ---------*/!][!//
[!ASSERT "node:value(concat($FrIfNodePath,'/FrIfGdSampleClockPeriod')) = 'T12_5NS'"!][!//
Error: FlexRay driver supports only 80Mbps. Hence GdSampleClockPeriod should be T12_5NS.
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!//
[!/* IFX_FR011 */!][!//
[!/* ---------  Config Rule FR_CR_201 ---------*/!][!//
[!ASSERT "num:i(node:value(concat($FrIfNodePath,'/FrIfGdWakeupRxLow'))) >= num:i(11)"!][!//
Error: Minimum value gdWakeupSymbolRxLow should be 11. This is required to take care of hardware errata FlexRay AI.077
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
[!//
/***** Communication controller configuration Controller [!"$ControllerIndex"!] (PB Config [!"$Instance"!]) *****/
static const Fr_17_Eray_CCConfigType Fr_17_Eray_kCCCfg_[!"$ControllerIndex"!]_[!"$Instance"!] =
{ /* SUCC1 register configuration */
  {
    {
      0U,    /* CmdPOCBusy (Unused member) */
      [!CALL "CG_ConfigSwitch2", "nodeval" = "node:value(concat($ControllerPath, '/FrPKeySlotUsedForStartup'))"!]U,    /* pKeySlotUsedForStartup */
      [!CALL "CG_ConfigSwitch2", "nodeval" = "node:value(concat($ControllerPath, '/FrPKeySlotUsedForSync'))"!]U,    /* pKeySlotUsedForSync */
      0U,    /* Reserved bit */
      [!"num:inttohex(node:value(concat($FrIfNodePath,'/FrIfGColdStartAttempts')))"!]U, /* FrIfGColdStartAttempts */
      [!"node:value(concat($ControllerPath, '/FrPAllowPassiveToActive'))"!]U,    /* FrPAllowPassiveToActive */
[!IF "node:value(concat($ControllerPath, '/FrPWakeupChannel')) = 'FR_CHANNEL_A'"!][!//
      0U,     /* FrPWakeupChannel */
[!ELSE!][!//
      1U,     /* FrPWakeupChannel */
[!ENDIF!][!//
      [!CALL "CG_ConfigSwitch2", "nodeval" = "node:value(concat($ControllerPath, '/FrPKeySlotOnlyEnabled'))"!]U,    /* FrPKeySlotOnlyEnabled in FlexRay Protocol 2.1 Rev. A */
      [!CALL "CG_ConfigSwitch2", "nodeval" = "node:value(concat($ControllerPath, '/FrPAllowHaltDueToClock'))"!]U, /* FrPAllowHaltDueToClock */
      0U,    /* pChannelsMTS (Unused), 0 means no channels selected */  
      (uint8)([!"node:value(concat($ControllerPath, '/FrPChannels'))"!] + (Fr_ChannelType)0x1) /* FrPChannels, add 0x1 as the hw regs take ChannelA = 1, ChannelB = 2 and ChannelAB = 3  */
    }
  },
  
  /* SUCC2 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPdListenTimeout')))"!]U,  /* FrPdListenTimeout */
      [!"num:inttohex(num:i((node:value(concat($FrIfNodePath,'/FrIfGListenNoise')))-1))"!]U      /* (FrIfGListenNoise - 1) */
    }
  },
  
  /* SUCC3 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($FrIfNodePath,'/FrIfGMaxWithoutClockCorrectPassive')))"!]U,  /* FrIfGMaxWithoutClockCorrectPassive */
      [!"num:inttohex(node:value(concat($FrIfNodePath,'/FrIfGMaxWithoutClockCorrectFatal')))"!]U      /* FrIfGMaxWithoutClockCorrectFatal */
    }
  },
  
  /* NEMC register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGNetworkManagementVectorLength'))))"!]U   /* FrIfGNetworkManagementVectorLength */
    }
  },
  
  /* PRTC1 register setttings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdTSSTransmitter'))))"!]U,    /* FrIfGdTSSTransmitter' */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdCasRxLowMax'))))"!]U,     /* FrIfGdCasRxLowMax */
      0U,        /* Strobe Point Position. Always zero (default) */
      0U,        /* BRP. Always zero as driver supports only 10Mbps rate */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdWakeupRxWindow'))))"!]U,     /* FrIfgdWakeupRxWindow */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPWakeupPattern')))"!]U       /* FrPWakeupPattern */
    }
  },
  
  /* PRTC2 register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdWakeupRxIdle'))))"!]U,    /* FrIfgdWakeupRxIdle */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdWakeupRxLow'))))"!]U,     /* FrIfgdWakeupRxLow  */  
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdWakeupTxIdle'))))"!]U,    /* FrIfGdWakeupTxIdle  A*/
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdWakeupTxActive'))))"!]U   /* FrIfGdWakeupTxActive A*/
    }
  },
  
  /* MHDC register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGPayloadLengthStatic'))))"!]U,  /* FrIfGPayloadLengthStatic */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPLatestTx')))"!]U   /* FrPLatestTx */
    }
  },
  
  /* GTUC01 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPMicroPerCycle')))"!]U  /*UT: FrPMicroPerCycle */
    }
  },
  
  /* GTUC02 register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGMacroPerCycle'))))"!]U,   /* FrIfGMacroPerCycle */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGSyncFrameIDCountMax'))))"!]U [!//
      /* FrIfGSyncFrameIDCountMax maps to FrIfGSyncNodeMax FR Pr 2.1, */
    }
  },
  
  /* GTUC03 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPMicroInitialOffsetA')))"!]U,    /* FrPMicroInitialOffsetA [A] */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPMicroInitialOffsetB')))"!]U,    /* FrPMicroInitialOffsetB [B] */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPMacroInitialOffsetA')))"!]U,    /* FrPMacroInitialOffsetA [A] */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPMacroInitialOffsetB')))"!]U     /* FrPMacroInitialOffsetB [B] */
    }
  },
  
  /* GTUC04 register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGMacroPerCycle'))) - num:i(node:value(concat($FrIfNodePath,'/FrIfGdNit'))) - 1)"!]U[!//
,   /* NetworkIdleTimeStart = (FrIfGMacroPerCycle - FrIfGdNit - 1)*/
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPOffsetCorrectionStart')))"!]U[!//
,   /*FrIfGOffsetCorrectionStart(Range: 9 -15999) not present in AS40,maps to FrPOffsetCorrectionStart*/
    }
  },
      
  /* GTUC05 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPDelayCompensationA')))"!]U,     /* FrPDelayCompensationA */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPDelayCompensationB')))"!]U,     /* FrPDelayCompensationB */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPClusterDriftDamping')))"!]U,    /* FrPClusterDriftDamping */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPDecodingCorrection')))"!]U     /* FrPDecodingCorrection */
    }
  },
  
  /* GTUC06 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPdAcceptedStartupRange')))"!]U,   /* FrPdAcceptedStartupRange */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPRateCorrectionOut')))"!]U   /* is same as FrPdMaxDrift */
    }
  },
  
  /* GTUC07 register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdStaticSlot'))))"!]U,    /* FrIfGdStaticSlot */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGNumberOfStaticSlots'))))"!]U,    /* FrIfGNumberOfStaticSlots */
    }
  },
  
  /* GTUC08 register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdMinislot'))))"!]U,     /* FrIfGdMinislot */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGNumberOfMinislots'))))"!]U   /* FrIfGNumberOfMinislots */
    }
  },
  
  /* GTUC09 register settings */
  {
    {
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdActionPointOffset'))))"!]U,     /* FrIfgdActionPointOffset */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdMiniSlotActionPointOffset'))))"!]U,     /* FrIfgdMinislotActionPointOffset */
      [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdDynamicSlotIdlePhase'))))"!]U      /* FrIfgdDynamicSlotIdlePhase */
    }
  },
  
  /* GTUC10 register settings */
  {
    {
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPOffsetCorrectionOut')))"!]U,   /* FrPOffsetCorrectionOut */
      [!"num:inttohex(node:value(concat($ControllerPath, '/FrPRateCorrectionOut')))"!]U    /* FrPRateCorrectionOut */
    }
  },
  
  /* GTUC11 register settings */
  {
    {
      0x0000U,   /* Unused (FrPExternOffsetControl, FrPExternRateControl */
      0U,     /* FrPExternOffsetCorrection is not present in AS40*/ 
      0U      /* FrPExternRateCorrection is not present in AS40 */
    }
  },
  
  /* CUST1 register settings */
  {
    {
      0x00U,   /* Unused */
      0x00U,   /* Reserved */
      (uint8)[!"node:value(concat($ControllerPath, '/FrRxInputSelectionA'))"!],     /* FrRxInputSelection Channel A*/
      (uint8)[!"node:value(concat($ControllerPath, '/FrRxInputSelectionB'))"!],      /* FrRxInputSelection Channle B*/
      0x00U   /* Unused */
    }
  }    
    
};

[!IF "(node:exists(concat($ControllerPath, '/FrFifo/*[1]')))"!][!/* FIFO_NODE_CHECK */!][!// 
#if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)	
/***** FR Receive receive FIFO configuration Controller [!"$ControllerIndex"!] (PB Config [!"$Instance"!]) *****/  
static const Fr_17_Eray_RxFifoConfigType Fr_17_Eray_RxFifoConfig_[!"$ControllerIndex"!]_[!"$Instance"!] =
{ 
  [!NOCODE!][!//
  [!VAR "vFrChannels" = "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrChannels'))"!][!//
  [!IF "$vFrChannels = 'FR_CHANNEL_AB'"!][!//
  [!VAR "vFrChannelVal" = "num:i(0)"!][!//
  [!ELSEIF "$vFrChannels = 'FR_CHANNEL_B'"!][!//
  [!VAR "vFrChannelVal" = "num:i(1)"!][!//
  [!ELSE!][!//
  [!VAR "vFrChannelVal" = "num:i(2)"!][!//
  [!ENDIF!][!//
  [!VAR "vFrCycleRepetition" = "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrCycleRepetition'))"!][!//
  [!VAR "vFrBaseCycle" = "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrBaseCycle'))"!][!//
  [!ASSERT "$vFrBaseCycle < $vFrCycleRepetition"!][!//
  Error: FrIfBaseCycle ([!"$vFrBaseCycle"!]) is not less than FrIfCycleRepetition ([!"$vFrCycleRepetition"!]) in FIFO configuration
  [!ENDASSERT!][!//
  [!VAR "CycleCode" = "bit:or($vFrCycleRepetition,$vFrBaseCycle)"!][!//
  [!VAR "CycleCode" = "bit:shl($CycleCode,16)"!][!//
  [!VAR "FrameIdRejectionFilterMask" = "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrFrameIdRejectionFilterMask'))"!][!//
  [!VAR "FrameIdRejectionFilter" = "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrFrameIdRejectionFilter'))"!][!//
  [!VAR "FrameIdRejectionFilter" = "bit:shl($FrameIdRejectionFilter,2)"!][!//
  [!VAR "RejectStaticSegment" = "num:i(0)"!][!//
  [!VAR "RejectNullFrames" = "num:i(0)"!][!//  
  [!IF "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrRejectStaticSegment')) = 'true'"!][!//
  [!VAR "RejectStaticSegment" = "num:i(1)"!][!//
  [!ENDIF!][!//
  [!IF "node:value(concat($ControllerPath, '/FrFifo/*[1]/FrRejectNullFrames')) = 'true'"!][!//
  [!VAR "RejectNullFrames" = "num:i(1)"!][!//
  [!ENDIF!][!//
  [!VAR "RejectStaticSegment" = "bit:shl($RejectStaticSegment,23)"!][!//
  [!VAR "RejectNullFrames" = "bit:shl($RejectNullFrames,24)"!][!//
  [!VAR "FrfCfg" = "bit:or($vFrChannelVal,$FrameIdRejectionFilter)"!][!//
  [!VAR "FrfCfg" = "bit:or($FrfCfg,$CycleCode)"!][!//
  [!VAR "FrfCfg" = "bit:or($FrfCfg,$RejectStaticSegment)"!][!//
  [!VAR "FrfCfg" = "bit:or($FrfCfg,$RejectNullFrames)"!][!//
  [!ENDNOCODE!][!//
  /*Fifo Rejection Filter criteria 
    FrChannels|(FrFid<<2)|((FrCycleRepetition|FrBaseCycle)<<16U)|(RSS<23)|(RNF<24)
  */
  [!"$FrfCfg"!]U,[!//
   
  /* FIFO Rejection Filter Mask */ 
  [!"num:i($FrameIdRejectionFilterMask)"!]U,[!//
  
  /* Fifo Depth.*/  
  [!"node:value(concat($ControllerPath, '/FrFifo/*[1]/FrFifoDepth'))"!]U,[!//
    
};
#endif
[!ENDIF!][!/* FIFO_NODE_CHECK */!][!//
[!//
static const Fr_17_ReadCCParametersType Fr_17_Eray_ReadCCParameters_[!"$ControllerIndex"!]_[!"$Instance"!] =
{
   
   [!"num:i(node:value(concat($FrIfNodePath,'/FrIfGdCycle'))* 1000000000)"!]U,  /* FrIfGdCycle */
[!IF "node:value(concat($FrIfNodePath,'/FrIfGdBit')) = 'T100NS'"!][!//
      0U,     /* FrIfGdBit */
[!ELSEIF "node:value(concat($FrIfNodePath,'/FrIfGdBit')) = 'T200NS'"!][!//
      1U,     /* FrIfGdBit */
[!ELSE!][!//
      2U,     /* FrIfGdBit */
[!ENDIF!][!//
   [!"num:i(node:value(concat($FrIfNodePath,'/FrIfGdMacrotick'))* 1000000000)"!]U,  /* FrIfGdMacrotick */
   [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdNit'))))"!]U,  /* FrIfGdNit */
   [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGCycleCountMax'))))"!]U,  /* FrIfGCycleCountMax */
   [!"num:inttohex(num:i(node:value(concat($FrIfNodePath,'/FrIfGdSymbolWindow'))))"!]U,  /* FrIfGdSymbolWindow */
   [!"num:inttohex(node:value(concat($ControllerPath, '/FrPKeySlotId')))"!]U,     /* FrPKeySlotId */
   [!"num:inttohex(node:value(concat($ControllerPath, '/FrPPayloadLengthDynMax')))"!]U,     /* FrPPayloadLengthDynMax */
[!IF "node:value(concat($ControllerPath, '/FrPdMicrotick'))= 'T100NS'"!][!//
      0U,     /* FrPdMicrotick */
[!ELSEIF "node:value(concat($ControllerPath, '/FrPdMicrotick')) = 'T12_5NS'"!][!//
      1U,     /* FrPdMicrotick */
[!ELSEIF "node:value(concat($ControllerPath, '/FrPdMicrotick')) = 'T25NS'"!][!//
      2U,     /* FrPdMicrotick */
[!ELSE!][!//
      3U,     /* FrPdMicrotick */
[!ENDIF!][!//
};
  
[!VAR "CtrlRefFound" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!/* LPDU_CONFIG_IF1 */!][!//
[!ENDLOOP!][!/* LPDU_CONFIG_LOOP3 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!]
[!ENDLOOP!][!/* LPDU_CONFIG_LOOP2 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!]
[!ENDLOOP!][!/* LPDU_CONFIG_LOOP1 */!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

[!VAR "ControllerPath" = "node:path(.)"!][!//
[!VAR "FrClockDivider" = "num:i(0)"!][!//
[!VAR "LPDU_COUNT_TOTAL" = "num:i(0)"!][!//
static const struct Fr_17_Eray_CCType Fr_17_Eray_CC_[!"$Instance"!][] =
{
[!VAR "Counter" = "num:i(count(./FrController/*))"!][!//
[!FOR "Index" = "0" TO "(num:i($Counter)- 1)"!][!//
[!SELECT "./FrController/*[@index = $Index]"!][!//
[!VAR "ControllerPathTemp" = "node:path(.)"!][!//
[!/* Example: ControllerPathTemp = /AUTOSAR/TOP-LEVEL-PACKAGES/Fr/ELEMENTS/Fr/FrMultipleConfiguration/Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-after($ControllerPathTemp, 'FrMultipleConfiguration')"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath1" = "substring-after($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath1 = /FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-before($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath2 = /Default_0 */!][!//
[!VAR "ControllerPath2" = "concat($ControllerPath2, $ControllerPath1)"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController_0 */!][!//
[!VAR "ControllerIndex" = "./FrCtrlIdx"!][!//
[!VAR "CtrlRefFound" = "num:i(0)"!][!//
[!LOOP "as:modconf('FrIf')[1]/FrIfConfig/*"!][!/* CONFIG_ROOT_LOOP1 */!][!//
[!LOOP "FrIfCluster/*"!][!/*LOOP1*/!][!/* CONFIG_ROOT_LOOP2 */!][!//
[!VAR "NumberOfStaticSlots" = "FrIfGNumberOfStaticSlots"!][!//
[!LOOP "FrIfController/*"!][!/* CONFIG_ROOT_LOOP3 */!][!//
[!VAR "FrIfControllerPath" = "node:ref(node:path(./FrIfFrCtrlRef))"!][!//
[!VAR "FrIfControllerPath" = "substring-after($FrIfControllerPath, '/Fr/Fr')"!][!//
[!IF "$FrIfControllerPath = $ControllerPath2"!][!/* CONFIG_ROOT_IF1 */!][!//
[!VAR "LPDU_COUNT_TOTAL" = "num:i(count(FrIfLPdu/*))"!][!//
[!VAR "FrClockDivider" = "node:value(concat($ControllerPath, '/FrClockConfiguration/FrClockDivider'))"!]
[!VAR "CtrlRefFound" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!/* CONFIG_ROOT_IF1 */!][!//
[!ENDLOOP!][!/* CONFIG_ROOT_LOOP3 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDLOOP!][!/* CONFIG_ROOT_LOOP2  */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDLOOP!][!/* CONFIG_ROOT_LOOP1  */!][!//
[!/* ---------  Config Rule FR_CR_214 ---------*/!][!//
[!ASSERT "$CtrlRefFound = num:i(1)"!][!//
Error: FlexRay Communication Controller [!"$ControllerPath2"!] is not referrred by FrIf in any cluster.
[!ENDASSERT!][!//
[!/* ------------------------------------------*/!][!//
  {
    /* Pointer to configuration of Communication Controller */
    &Fr_17_Eray_kCCCfg_[!"$ControllerIndex"!]_[!"$Instance"!],
    
    /* Pointer to array of LPDU configurations */
    Fr_17_Eray_kLPduConfig_[!"$ControllerIndex"!]_[!"$Instance"!],
    
    #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
    [!IF "(node:exists(concat($ControllerPathTemp, '/FrFifo/*[1]')))"!][!/* FIFO_NODE_CHECK */!][!//
    &Fr_17_Eray_RxFifoConfig_[!"$ControllerIndex"!]_[!"$Instance"!],
    [!ELSE!][!//
    NULL_PTR,
    [!ENDIF!][!//
    #endif
    
    /* Pointer to leftout Fr_readCCconfig parameter structure */
    &Fr_17_Eray_ReadCCParameters_[!"$ControllerIndex"!]_[!"$Instance"!],
    
    /* Pointer to LPDU to message buffer mapping array */
    Fr_17_Eray_LPduIdx2MsgBuff_[!"$ControllerIndex"!]_[!"$Instance"!],
    
    /* Pointer to Data pointer offsets */
    Fr_17_Eray_DataPointerOffset_[!"$ControllerIndex"!]_[!"$Instance"!],
        
    /* ERAY Module clock configuration : Runtime Mode Control setting */
    [!"$FrClockDivider"!]U,
    
    /* Number of LPDUs configured */
    [!"$LPDU_COUNT_TOTAL"!]U,
    
    /* Controller Index */
    [!"$ControllerIndex"!]U,
    
    /*DEM Id for FlexRay controller hardware test failure.*/
    [!IF "(node:exists(./FrControllerDemEventParameterRefs/*[1]/FrDemCtrlTestResultRef/*[1]) = 'true') and (node:value(./FrControllerDemEventParameterRefs/*[1]/FrDemCtrlTestResultRef/*[1]) != ' ' )"!][!//     
    DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FrControllerDemEventParameterRefs/*[1]/FrDemCtrlTestResultRef/*[1])))"!],
    [!ELSE!][!//
    DEM_REPORT_DISABLED,
    [!ENDIF!][!// 
    
    /*DEM Id for FlexRay controller hardware response timeout. */
    [!IF "(node:exists(./FrControllerDemEventParameterRefs/*[1]/FrDemTimeoutRef/*[1]) = 'true') and (node:value(./FrControllerDemEventParameterRefs/*[1]/FrDemTimeoutRef/*[1]) != ' ' )"!][!//
    DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FrControllerDemEventParameterRefs/*[1]/FrDemTimeoutRef/*[1])))"!],
    [!ELSE!][!//
    DEM_REPORT_DISABLED,    
    [!ENDIF!][!//
    
    /*DEM Id for FlexRay Slot Status Error. */
    [!SELECT "node:ref(node:path(as:modconf('FrIf')[1]/FrIfConfig/*[1]/FrIfCluster/*[1]/FrIfController/*[@index = $Instance]/FrIfFrameTriggering/*[1]))"!][!//
    [!IF "(node:exists(./FrIfFrameTriggeringDemEventParameterRefs/*[1]/FrIfDemFTSlotStatusRef/*[1]) = 'true') and (node:value(./FrIfFrameTriggeringDemEventParameterRefs/*[1]/FrIfDemFTSlotStatusRef/*[1]) != ' ')"!][!//
    DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FrIfFrameTriggeringDemEventParameterRefs/*[1]/FrIfDemFTSlotStatusRef/*[1])))"!][!//
    [!ELSE!][!//
    DEM_REPORT_DISABLED    
    [!ENDIF!][!//
    [!ENDSELECT!][!//    
  }[!IF "$Index != ($Counter - 1)"!], [!ENDIF!][!//
[!ENDSELECT!][!//   
[!ENDFOR!][!//
};

static const uint8 Fr_17_Eray_CCMap_[!"$Instance"!][FR_NUM_CONTROLLERS_IN_DEVICE] =
{
[!FOR "ControllerNum" = "0" TO "(num:i(ecu:get('Eray.MaxControllers'))- 1)"!][!//
[!VAR "Found" = "num:i(0)"!][!//
[!LOOP "FrController/*"!][!//
[!IF "./FrCtrlIdx = $ControllerNum"!][!//
[!VAR "Found" = "num:i(1)"!][!//
  [!"@index"!]U[!IF "$ControllerNum != (num:i(ecu:get('Eray.MaxControllers')) - 1)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$Found = num:i(0)"!][!//
  255U[!IF "$ControllerNum != (num:i(ecu:get('Eray.MaxControllers')) - 1)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDFOR!][!//
};

[!ENDSELECT!][!//
[!ENDFOR!][!/* LPDU_CONFIG_FOR1 */!][!//

/* Implementation-specific post build configuration for FlexRay driver */
const struct Fr_17_Eray_ConfigType Fr_17_Eray_ConfigRoot[[!"$ConfigCount"!]] = 
{
[!FOR "Instance" = "0" TO "$ConfigCount - 1"!][!/* CONFIG_ROOT_FOR1 */!][!//
[!//
  {
  /***** (PB Config [!"$Instance"!]) *****/
    &Fr_17_Eray_CC_[!"$Instance"!][0],
    &Fr_17_Eray_CCMap_[!"$Instance"!][0]
  }[!IF "$Instance != ($ConfigCount - 1)"!], [!ENDIF!]
[!ENDFOR!][!/* CONFIG_ROOT_FOR1 */!][!//
};

#define FR_17_ERAY_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!ENDSELECT!][!//


