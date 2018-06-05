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
**  $FILENAME   : Can_17_MCanP_Cfg.h $                                       **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\19 $                               **
**                                                                            **
**  $DATE       : 2016-07-23 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for Can_17_MCanP_Cfg.h file                  **
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
**  $FILENAME   : Can_17_MCanP_Cfg.h $                                       **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\19 $                               **
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
**                   file (Can_17_MCanP.bmd)                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/**  TRACEABILITY: [cover parentID=DS_AS_CAN047,
                   DS_NAS_PR446,DS_AS4XX_CAN_PR2849,SAS_NAS_CAN_PR914,
                   SAS_NAS_CAN_PR915,SAS_AS4XX_CAN_PR678,SAS_NAS_CAN_PR916
                   DS_NAS_HE2_CAN_PR2893,DS_NAS_EP_CAN_PR2893,
                   DS_NAS_EP_CAN_PR3054_1,DS_NAS_EP_CAN_PR3054_2,
                   DS_NAS_EP_CAN_PR3054_3,DS_NAS_EP_CAN_PR3054_4]             **
**                                                                            **
**  [/cover]                                                                 **/


#ifndef CAN_17_MCANP_CFG_H
#define CAN_17_MCANP_CFG_H

[!/* Include Code Generator Macros */!][!//
[!INCLUDE "Can_17_MCanP.m"!][!//

[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "MainOscillatorFrequency" = "num:i(McuGeneralConfiguration/McuMainOscillatorFrequency)"!][!//
[!VAR "FmPllEnable" = "(McuGeneralConfiguration/McuFmPllEnable)"!][!//
[!ENDSELECT!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Can')[1]"!][!//
[!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/

/* Autosar specification version */
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]
#define CAN_17_MCANP_AS_VERSION ([!"$NewString"!])
[!IF "$MajorVersion = num:i(4)"!][!//
#define CAN_17_MCANP_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define CAN_17_MCANP_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define CAN_17_MCANP_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/* Vendor specific implementation version information */
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define CAN_17_MCANP_SW_MAJOR_VERSION  ([!"$SwMajorVersion"!]U)
#define CAN_17_MCANP_SW_MINOR_VERSION  ([!"$SwMinorVersion"!]U)
#define CAN_17_MCANP_SW_PATCH_VERSION  ([!"$SwPatchVersion"!]U)

[!VAR "ConfigCount" = "num:i(count(CanConfigSet/*)) - 1"!][!//
[!VAR "TxObjectType" = "'TRANSMIT'"!][!//
[!VAR "RxObjectType" = "'RECEIVE'"!][!//
[!VAR "StandardObjectIdType" = "'STANDARD'"!][!//
[!//

/*******************************************************************************
**                     Configuration options                                  **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!/* Extract Configuration Information */!][!//
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
[!VAR "FDNodesPresent" = "num:i(0)"!][!//
[!VAR "ISOHardwareSupport" = "num:i(0)"!][!//
[!VAR "FDISOframesPresent" = "num:i(0)"!][!//
[!VAR "Protocolfeaturesupport" = "num:i(0)"!][!//
[!VAR "MaxHwObjIdCount" = "num:i(0)"!][!//
[!VAR "TxObjectType" = "'TRANSMIT'"!][!//
[!VAR "RxObjectType" = "'RECEIVE'"!][!//
[!VAR "MsgObSize" = "num:i(1)"!][!//
[!VAR "NumOfCtrlKer1" = "num:i(ecu:get('Can.MaxCtrlKer'))"!][!//
[!//
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
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
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!//
[!IF "ecu:get('Can.MaxKernels') = '2'"!][!//
/* CAN ModuleR is available. i.e Additional 2 nodes/128 message objects are present */    
#define CAN_MOD_R_AVAILABLE
[!ENDIF!][!//
[!//
[!NOCODE!][!//
[!//Start Calculation of Maximum transmit hardware objects ID configured in a ConfigSet
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "Kernel1Arr" = "'#'"!][!//
[!VAR "Kernel2Arr" = "'#'"!][!//
[!VAR "Kernel1ArrCnt" = "num:i(0)"!][!//
[!VAR "Kernel2ArrCnt" = "num:i(0)"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
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
[!IF "$TxObjectCountMax > num:i(0)"!][!//
[!IF "num:i(count(CanHardwareObject/*[CanObjectType=$TxObjectType])) > num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer0FD" = "num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer1FD" = "num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer0STD" = "num:i(0)"!][!//
[!VAR "CanTxHwObjectIdKer1STD" = "num:i(0)"!][!//
[!LOOP "CanHardwareObject/*"!][!//
[!VAR "CanControllerRefPath" = "node:path(node:ref(CanControllerRef))"!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "CanTxHwObjectIdKer0FD" = "$CanTxHwObjectIdKer0FD + num:i(1)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "CanTxHwObjectIdKer0STD" = "$CanTxHwObjectIdKer0STD + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "((CanObjectType=$RxObjectType) and (text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1))"!][!//
[!SELECT "node:ref($CanControllerRefPath)"!][!//
[!IF "((./CanControllerActivation = 'true') and (node:exists(CanControllerFdBaudrateConfig/*[1])))"!][!//
[!VAR "CanTxHwObjectIdKer1FD" = "$CanTxHwObjectIdKer1FD + num:i(1)"!][!//
[!ELSE!][!//
[!IF "(./CanControllerActivation = 'true')"!][!//
[!VAR "CanTxHwObjectIdKer1STD" = "$CanTxHwObjectIdKer1STD + num:i(1)"!][!//
[!ENDIF!][!//
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
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] < $NumOfCtrlKer1"!][!//
 [!VAR "Kernel1Arr" = "concat($Kernel1Arr,string(num:i($CanTxHwObjectIdKer0 )),'#')"!][!//
 [!VAR "Kernel1ArrCnt"="$Kernel1ArrCnt + num:i(1)"!][!//
[!ENDIF!][!//
[!IF "text:split(node:ref(CanControllerRef)/CanHwControllerId, '_')[position()-1 = 1] >= $NumOfCtrlKer1"!][!//
 [!VAR "Kernel2Arr" = "concat($Kernel2Arr,string(num:i($CanTxHwObjectIdKer1 )),'#')"!][!//
 [!VAR "Kernel2ArrCnt"="$Kernel2ArrCnt + num:i(1)"!][!//
[!ENDIF!][!//
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
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//[!IF "$TxObjectCountMax > num:i(0)"!][!//
[!ENDSELECT!][!//
[!//End of Calculation of Maximum transmit hardware objects ID configured in a ConfigSet
[!//Calculation ofMaximum transmit hardware objects ID configured in a ConfigSet
[!VAR "FirstHwObj1" = "num:i(0)"!][!//
[!VAR "LastHwObj1" = "num:i(0)"!][!//
[!VAR "MaxHwObjOffset1" = "num:i(0)"!][!//
[!VAR "FirstHwObj2" = "num:i(0)"!][!//
[!VAR "LastHwObj2" = "num:i(0)"!][!//
[!VAR "MaxHwObjOffset2" = "num:i(0)"!][!//
[!IF "(num:i($Kernel1ArrCnt) > num:i(0))"!][!//
[!VAR "FirstHwObj1" ="num:i(text:split($Kernel1Arr, '#')[num:i(1)])"!][!//
[!VAR "LastHwObj1" ="num:i(text:split($Kernel1Arr, '#')[num:i($Kernel1ArrCnt)])"!][!//
[!VAR "MaxHwObjOffset1" = "num:i($LastHwObj1 - $FirstHwObj1)"!][!//
[!ENDIF!][!//
[!IF "(num:i($Kernel2ArrCnt) > num:i(0))"!][!//
[!VAR "FirstHwObj2" ="num:i(text:split($Kernel2Arr, '#')[num:i(1)])"!][!//
[!VAR "LastHwObj2" ="num:i(text:split($Kernel2Arr, '#')[num:i($Kernel2ArrCnt)])"!][!//
[!VAR "MaxHwObjOffset2" = "num:i($LastHwObj2 - $FirstHwObj2)"!][!//
[!ENDIF!][!//
[!IF "(num:i($MaxHwObjOffset1) > num:i($MaxHwObjOffset2))"!][!//
[!VAR "MaxHwObjOffset2" = "num:i($MaxHwObjOffset1 + num:i(1))"!][!//
[!ELSE!][!//
[!VAR "MaxHwObjOffset2" = "num:i($MaxHwObjOffset2 + num:i(1))"!][!//
[!ENDIF!][!//
[!IF "(num:i($MaxHwObjIdCount) < num:i($MaxHwObjOffset2))"!][!//
[!VAR "MaxHwObjIdCount" = "num:i($MaxHwObjOffset2)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!//
/* Number of Config sets */
#define CAN_CONFIG_COUNT  ([!"num:i($ConfigCount + 1)"!]U)

/* Number of Kernels available in the device */
#define CAN_NUM_KERNELS_IN_DEVICE  ([!"ecu:get('Can.MaxKernels')"!]U)

/* Number of CAN Controllers available in the device */
#define CAN_NUM_CONTROLLERS_IN_DEVICE  ([!"ecu:get('Can.MaxControllers')"!]U)

/* Number of CAN Controllers available in the First Kernel */
#define CAN_NUM_CONTROLLERS_IN_KERNEL1  ([!"ecu:get('Can.MaxCtrlKer')"!]U)

/* Maximum number of CAN Controllers configured in a ConfigSet */
#define CAN_NUM_CONTROLLER_MAX         ([!"$ControllerConfigMax"!]U)

/* Maximum transmit hardware objects ID configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTID_MAX   ([!"$MaxHwObjIdCount"!]U)

/* Maximum number of transmit hardware objects configured in a ConfigSet */
#define CAN_TX_HARDWARE_OBJECTS_MAX    ([!"$TxObjectCountMax"!]U)

/* Maximum number of receive hardware objects configured in a ConfigSet */
#define CAN_RX_HARDWARE_OBJECTS_MAX    ([!"$RxObjectCountMax"!]U)

/* Maximum number of Rx FIFO configurations in a ConfigSet */
#define CAN_NUM_RX_FIFO_MAX            ([!"$NumFifoConfigsMax"!]U)

/* Configured Message Identifier Type */
/* STD_ON  : Only Standard Message Identifiers are configured */
/* STD_OFF : At least one Extended/Mixed Message Identifier is configured */
#define CAN_STANDARD_ID_ONLY           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "$StandardIdOnly"!] [!//

[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!//
[!ASSERT "num:i(count(CanController/*[CanControllerActivation='true'])) > num:i(0)"!][!//
ERROR: Atleast one of the CanController should be activated in CanConfigSet [!"node:name(.)"!].
[!ENDASSERT!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!//

/*******************************************************************************
**                      CAN General Information                               **
*******************************************************************************/
/* Is fOSC clock selected as the input source for CAN Baud rate calculations? */
#define CAN_BR_EXT_OSLTR_CLKSEL           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanBaudRateClkSelExtOsc"!]

[!IF "ecu:get('Mcu.fErayPllExists')='true'"!][!//
/* Is ERAY clock selected as the input source for CAN Baud rate calculations? */
#define CAN_BR_ERAY_PLL_CLKSEL           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanBaudRateClkSelErayPll"!]
[!IF "CanGeneral/CanBaudRateClkSelErayPll ='true'"!][!//
[!ASSERT "$MainOscillatorFrequency >= num:i(16)"!][!//
ERROR: ERAY clock shall be selected only if Main Oscillator frequency is greater than or equal to 16 MHz.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!IF "CanGeneral/CanBaudRateClkSelErayPll ='false'"!][!//
[!ASSERT "$FmPllEnable = 'false'"!][!//
ERROR: When FM PLL is used, ERAY clock shall be selected to ensure stable CAN communication.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ELSE!][!//
/* Is ERAY clock selected as the input source for CAN Baud rate calculations? */
#define CAN_BR_ERAY_PLL_CLKSEL           (STD_OFF)[!//
[!ENDIF!][!//

/* Is FD enabled ? */
#define CAN_FD_ENABLE           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($FDNodesPresent))"!][!//


/* Is Any Recieve hardware object configured in Kernal 0 ? */
#define CAN_RX_OBJECT_KER0           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($CanRxHwObjectKer0))"!][!//


/* Is Any Recieve hardware object configured in Kernal 1 ? */
#define CAN_RX_OBJECT_KER1           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($CanRxHwObjectKer1))"!][!//


/* Is Any Transmit hardware object configured in Kernal 0 ? */
#define CAN_TX_OBJECT_KER0           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($CanTxHwObjectKer0))"!][!//


/* Is Any Transmit hardware object configured in Kernal 1 ? */
#define CAN_TX_OBJECT_KER1           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($CanTxHwObjectKer1))"!][!//

[!IF "ecu:get('Can.FDFeaturePresent')='true' and ecu:get('Can.FDIsoFrameSupport')='true'"!][!//
[!VAR "ISOHardwareSupport" = "num:i(1)"!][!//
[!ENDIF!][!//
/*Can ISO Hardware enable switch*/
#define CAN_HARDWARE_ISO_SUPPORT     [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($ISOHardwareSupport))"!][!//

[!IF "ecu:get('Can.FDFeaturePresent')='true' and ecu:get('Can.FDIsoFrameSupport')='true'"!][!//
[!IF "CanGeneral/CanISOFrameSupport ='true' and (boolean(num:i($FDNodesPresent)))"!][!//
[!VAR "FDISOframesPresent" = "num:i(1)"!][!//
[!ENDIF!][!//

/*Configuration to Support ISO or Non ISO frame*/
#define CAN_FD_SUPPORT_ISO_FRAME     [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($FDISOframesPresent))"!][!//
[!IF "CanGeneral/CanProtocolExceptionFeature ='true' and (boolean(num:i($FDNodesPresent)))"!][!//
[!VAR "Protocolfeaturesupport" = "num:i(1)"!][!//
[!ENDIF!][!//


/*Configuration to enable or disable protocol exception feature*/
#define CAN_PROTOCOL_EXCEPTION_FEATURE     [!//
[!CALL "CG_ConfigSwitch","nodeval" = "boolean(num:i($Protocolfeaturesupport))"!][!//

[!IF "CanGeneral/CanISOFrameSupport ='true'"!][!//
[!VAR "ISOFrameSupport" = "num:i(0)"!][!//
[!ELSE!][!//
[!VAR "ISOFrameSupport" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "CanGeneral/CanProtocolExceptionFeature = 'true'"!][!//
[!VAR "ProtocolExceptionFeature" = "num:i(0)"!][!//
[!ELSE!][!//
[!VAR "ProtocolExceptionFeature" = "num:i(1)"!][!//
[!ENDIF!][!//

/*Configuration value to enable or disable ISO or Non ISO frame feature*/
#define CAN_ISO_FRAME                           ([!"$ISOFrameSupport"!]U)

/*Configuration value to enable or disable protocol exception feature*/
#define CAN_PROTOCAL_EXCEPTION                  ([!"$ProtocolExceptionFeature"!]U)

[!ENDIF!][!//
/* Configuration: CAN_17_MCANP_INSTANCE_ID
 - Specifies the InstanceId of this module instance
*/
#define CAN_17_MCANP_INSTANCE_ID                ([!"CanGeneral/CanIndex"!]U)

/* Configuration: CAN_DEV_ERROR_DETECT
 - STD_ON  - DET is enabled
 - STD_OFF - DET is disabled
*/      
#define CAN_DEV_ERROR_DETECT           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanDevErrorDetection"!]

/* Configuration: CAN_VERSION_INFO_API
 - STD_ON  - Can_17_MCanP_GetVersionInfo API is enabled
 - STD_OFF - Can_17_MCanP_GetVersionInfo API is disabled
*/      
#define CAN_VERSION_INFO_API           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanVersionInfoApi"!]

/* Configuration: CAN_MULTIPLEXED_TRANSMISSION
 - STD_ON  - Multiplexed transmission feature is enabled
 - STD_OFF - Multiplexed transmission feature is disabled
*/      
#define CAN_MULTIPLEXED_TRANSMISSION   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanMultiplexedTransmission"!]

/* Configuration: CAN_TIMEOUT_DURATION
 - Specifies the maximum number of loops for blocking function until 
   a timeout is raised in short term wait loops
*/
#define CAN_TIMEOUT_DURATION    ([!"num:i(CanGeneral/CanTimeoutDurationFactor)"!]U)

/* Configuration: CAN_PB_FIXEDADDR
 - STD_ON  - PB fixed address optimization is enabled 
 - STD_OFF - PB fixed address optimization is disabled 
*/
#define CAN_PB_FIXEDADDR               [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanPBFixedAddress"!]

/* Configuration: CAN_DEBUG_SUPPORT
 - STD_ON  - Debug support is enabled 
 - STD_OFF - Debug support is disabled 
*/
#define CAN_DEBUG_SUPPORT              [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanDebugSupport"!]

/* Configuration: CAN_CHANGE_BAUDRATE_API
 - STD_ON  - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are enabled
 - STD_OFF - Can_17_MCanP_CheckBaudrate and Can_17_MCanP_ChangeBaudrate 
             APIs are disabled
*/
#define CAN_CHANGE_BAUDRATE_API              [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanChangeBaudrateApi"!]

#define CAN_RESET_SFR_AT_INIT              [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanResetSfrAtInit"!]

/* Configuration: CAN_RESET_SFR_AT_INIT
 - STD_ON  - CAN Kernel Registers’ reset feature is enabled
 - STD_OFF - CAN Kernel Registers’ reset feature is not enabled
*/

#define CAN_DEINIT_API              [!//
[!CALL "CG_ConfigSwitch","nodeval" = "CanGeneral/CanDeInitApi"!]

/* Configuration: CAN_DEINIT_API
 - STD_ON  - CAN De-initialization API is enabled
 - STD_OFF - CAN De-initialization API is not enabled
*/

/* CAN Hardware Timeout DEM */
[!IF "(node:exists(CanDemEventParameterRefs/*[1]) = 'true')"!][!//
[!SELECT "CanDemEventParameterRefs/*[1]"!][!//
[!IF "(node:exists(./CAN_E_TIMEOUT/*[1]) = 'true') and (node:value(./CAN_E_TIMEOUT /*[1]) != ' ' )"!][!//
#define CAN_E_TIMEOUT_DEM_REPORT   (CAN_ENABLE_DEM_REPORT)
#define CAN_E_TIMEOUT (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./CAN_E_TIMEOUT/*[1])))"!])
[!ELSE!][!//
#define CAN_E_TIMEOUT_DEM_REPORT   (CAN_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
#define CAN_E_TIMEOUT_DEM_REPORT   (CAN_DISABLE_DEM_REPORT)
[!ENDIF!]

[!IF "CanGeneral/CanDeInitApi = 'true'"!][!//
#define CAN_DEINIT_API (STD_ON)
[!ELSE!][!//
#define  CAN_DEINIT_API (STD_OFF)
[!ENDIF!][!//

[!IF "(CanGeneral/CanRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "CanGeneral/CanUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "CanGeneral/CanUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "CanGeneral/CanUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: CanRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
CanUserModeRuntimeApiEnable, CanUserModeInitApiEnable or CanUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: CAN_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "CanGeneral/CanRunningInUser0Mode = 'true'"!][!//
#define CAN_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define CAN_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: CAN_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "CanGeneral/CanUserModeInitApiEnable = 'true'"!][!//
#define CAN_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  CAN_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: CAN_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "CanGeneral/CanUserModeDeInitApiEnable = 'true'"!][!//
#define CAN_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  CAN_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: CAN_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "CanGeneral/CanUserModeRuntimeApiEnable = 'true'"!][!//
#define CAN_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  CAN_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//


/******************************************************************************/
                    /* CAN Controller Configurations */
/******************************************************************************/

[!VAR "WakeupSupport" = "num:i(0)"!][!//
[!FOR "HwControllerIndex" = "0" TO "num:i(ecu:get('Can.MaxControllers'))-1"!][!//
[!VAR "SearchStatus" = "num:i(0)"!][!//
[!VAR "RxProcessingTemp" = "num:i(0)"!][!//
[!VAR "TxProcessingTemp" = "num:i(0)"!][!//
[!VAR "BusoffProcessingTemp" = "num:i(0)"!][!//
[!VAR "WakeupSupportTemp" = "num:i(0)"!][!//
[!VAR "WakeupProcessingTemp" = "num:i(0)"!][!//
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//
[!LOOP "CanController/*"!][!//
[!IF "$SearchStatus = num:i(0)"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!IF "text:split(CanHwControllerId, '_')[position()-1 = 1] = $HwControllerIndex"!][!//
[!VAR "SearchStatus" = "num:i(1)"!][!//
[!VAR "InstanceTemp" = "$Instance"!][!//
[!VAR "ConfigSetTemp" = "node:name(../..)"!][!//
[!//
/******************************************************************************/
              /* [!"text:split(ecu:get('Can.HwController'), ',')[position()-1 = $HwControllerIndex]"!] Configuration */
/******************************************************************************/

/* [!"CanHwControllerId"!] Activation 
 - STD_ON  - Controller is used
 - STD_OFF - Controller is NOT used
*/      
#define CAN_HWCONTROLLER[!"$HwControllerIndex"!]_ACTIVATION           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "./CanControllerActivation"!]

/* [!"CanHwControllerId"!] Transmit Confirmation Event Processing
 - CAN_INTERRUPT - Transmission is notified through interrupt mechanism
 - CAN_POLLING   - Transmission is notified through polling mechanism  
*/      
#define CAN_TX_PROCESSING_HWCONTROLLER[!"$HwControllerIndex"!]      [!//
  [!CALL "CG_IsEventPolled", "event" = "./CanTxProcessing"!]

[!VAR "TxProcessingTemp" = "./CanTxProcessing"!][!//
/* [!"CanHwControllerId"!] Receive Indication Event Processing
 - CAN_INTERRUPT - Reception is notified through interrupt mechanism
 - CAN_POLLING   - Reception is notified through polling mechanism  
*/      
#define CAN_RX_PROCESSING_HWCONTROLLER[!"$HwControllerIndex"!]      [!//
  [!CALL "CG_IsEventPolled", "event" = "./CanRxProcessing"!]

[!VAR "RxProcessingTemp" = "./CanRxProcessing"!][!//
/* [!"CanHwControllerId"!] Wakeup Event Processing
 - CAN_INTERRUPT - Wakeup event is  notified through interrupt mechanism
 - CAN_POLLING   - Wakeup event is notified through polling mechanism  
*/      
#define CAN_WU_PROCESSING_HWCONTROLLER[!"$HwControllerIndex"!]      [!//
[!IF "./CanWakeupSupport = 'true'"!][!//
[!IF "./CanWakeupProcessing != ./CanRxProcessing"!][!//
[!ERROR!][!//
ERROR: CanWakeupProcessing and CanRxProcessing should be same for CanController [!"node:name(.)"!] in CanConfigSet [!"node:name(../..)"!]!
[!ENDERROR!][!//
[!ENDIF!][!//
  [!CALL "CG_IsEventPolled", "event" = "./CanWakeupProcessing"!]
[!ELSE!][!//
  (CAN_NO_PROCESSING)
[!ENDIF!][!//
[!VAR "WakeupSupportTemp" = "./CanWakeupSupport"!][!//
[!VAR "WakeupProcessingTemp" = "./CanWakeupProcessing"!][!//
[!IF "./CanWakeupSupport = 'true'"!][!//
[!VAR "WakeupSupport" = "num:i(1)"!][!//
[!ENDIF!][!//

/* [!"CanHwControllerId"!] Bus-Off Event Processing
 - CAN_INTERRUPT - Bus-off event notified through interrupt mechanism
 - CAN_POLLING   - Bus-off event notified through polling mechanism  
*/
#define CAN_BO_PROCESSING_HWCONTROLLER[!"$HwControllerIndex"!]      [!//
  [!CALL "CG_IsEventPolled", "event" = "./CanBusoffProcessing"!]

[!VAR "BusoffProcessingTemp" = "./CanBusoffProcessing"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!IF "$SearchStatus = 0"!][!//
/******************************************************************************/
              /* [!"text:split(ecu:get('Can.HwController'), ',')[position()-1 = $HwControllerIndex]"!] Configuration */
/******************************************************************************/

#define CAN_HWCONTROLLER[!"$HwControllerIndex"!]_ACTIVATION           (STD_OFF)

[!ELSE!][!//
[!IF "$InstanceTemp < $ConfigCount"!][!//
[!FOR "Instance1" = "$InstanceTemp + 1" TO "$ConfigCount"!][!//
[!VAR "SelectConfig1" = "concat('CanConfigSet/*[',$Instance1 + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig1)"!][!//
[!LOOP "CanController/*"!][!//
[!IF "CanControllerActivation = 'true'"!][!//
[!IF "text:split(CanHwControllerId, '_')[position()-1 = 1] = $HwControllerIndex"!][!//
[!ASSERT "$TxProcessingTemp = ./CanTxProcessing"!][!//
ERROR: 

Configuration of the pre-compile configuration parameter CanTxProcessing for a given CanHwControllerId should be same across configuration sets!

CanTxProcessing for CanHwControllerId [!"CanHwControllerId"!]:

in CanConfigSet [!"$ConfigSetTemp"!] is [!"$TxProcessingTemp"!]
in CanConfigSet [!"node:name(../..)"!] is [!"CanTxProcessing"!]

They should be same!
[!ENDASSERT!][!//
[!ASSERT "$RxProcessingTemp = ./CanRxProcessing"!][!//
ERROR: 

Configuration of the pre-compile configuration parameter CanRxProcessing for a given CanHwControllerId should be same across configuration sets!

CanRxProcessing for CanHwControllerId [!"CanHwControllerId"!]:

in CanConfigSet [!"$ConfigSetTemp"!] is [!"$RxProcessingTemp"!]
in CanConfigSet [!"node:name(../..)"!] is [!"CanRxProcessing"!]

They should be same!
[!ENDASSERT!][!//
[!ASSERT "$BusoffProcessingTemp = ./CanBusoffProcessing"!][!//
ERROR: 

Configuration of the pre-compile configuration parameter CanBusoffProcessing for a given CanHwControllerId should be same across configuration sets!

CanBusoffProcessing for CanHwControllerId [!"CanHwControllerId"!]:

in CanConfigSet [!"$ConfigSetTemp"!] is [!"$BusoffProcessingTemp"!]
in CanConfigSet [!"node:name(../..)"!] is [!"CanBusoffProcessing"!]

They should be same!
[!ENDASSERT!][!//
[!ASSERT "$WakeupSupportTemp = ./CanWakeupSupport"!][!//
ERROR: 

Configuration of the pre-compile configuration parameter CanWakeupSupport for a given CanHwControllerId should be same across configuration sets!

CanWakeupSupport for CanHwControllerId [!"CanHwControllerId"!]:

in CanConfigSet [!"$ConfigSetTemp"!] is [!"$WakeupSupportTemp"!]
in CanConfigSet [!"node:name(../..)"!] is [!"CanWakeupSupport"!]

They should be same!
[!ENDASSERT!][!//
[!IF "./CanWakeupSupport = 'true'"!][!//
[!ASSERT "$WakeupProcessingTemp = ./CanWakeupProcessing"!][!//
ERROR: 

Configuration of the pre-compile configuration parameter CanWakeupProcessing for a given CanHwControllerId should be same across configuration sets!

CanWakeupProcessing for CanHwControllerId [!"CanHwControllerId"!]:

in CanConfigSet [!"$ConfigSetTemp"!] is [!"$WakeupProcessingTemp"!]
in CanConfigSet [!"node:name(../..)"!] is [!"CanWakeupProcessing"!]

They should be same!
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!//
/****************** End Of CAN Controller Configurations **********************/

/* Configuration: CAN_WAKEUP_CONFIGURED
 - STD_ON  - At least one of the CAN controllers supports wakeup
 - STD_OFF - None of the CAN controllers supports wakeup
*/      
[!IF "$WakeupSupport = num:i(1)"!][!//
#define CAN_WAKEUP_CONFIGURED                  (STD_ON)
[!ELSE!][!//
#define CAN_WAKEUP_CONFIGURED                  (STD_OFF)
[!ENDIF!][!//

/* Configuration: CAN_LPDU_RX_CALLOUT
 - STD_ON  - L-PDU receive callout support enabled
 - STD_OFF - L-PDU receive callout support disabled
*/      
[!IF "node:exists(CanGeneral/CanLPduReceiveCalloutFunction/*[1]) = 'true'"!][!//
[!VAR "RxLPduCallout" = "CanGeneral/CanLPduReceiveCalloutFunction/*[1]"!][!//
[!IF "$RxLPduCallout = '""' or $RxLPduCallout = '' or $RxLPduCallout = 'NULL_PTR'"!][!//
#define CAN_LPDU_RX_CALLOUT                    (STD_OFF)
[!ELSE!][!//
#define CAN_LPDU_RX_CALLOUT                    (STD_ON)
[!ENDIF!][!//
[!ELSE!][!//
#define CAN_LPDU_RX_CALLOUT                    (STD_OFF)
[!ENDIF!][!//

/*******************************************************************************
    Symbolic Name Defintions of CAN Controllers and CAN Hardware Objects
*******************************************************************************/
[!FOR "Instance" = "0" TO "$ConfigCount"!][!//
[!VAR "SelectConfig" = "concat('CanConfigSet/*[',$Instance + 1,']')"!][!//
[!SELECT "node:ref($SelectConfig)"!][!//

/*******************************************************************************
    [!"@name"!] -> Symbolic Name Defintions of CAN Controllers 
*******************************************************************************/

[!LOOP "CanController/*"!][!//
#ifdef Can_17_MCanPConf_CanController_[!"@name"!] /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanController_[!"@name"!] != [!"CanControllerId"!]U)
    #error Can_17_MCanPConf_CanController_[!"@name"!] is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanController_[!"@name"!]   ([!"CanControllerId"!]U) 
#endif /* #ifdef Can_17_MCanPConf_CanController_[!"@name"!] */
[!ENDLOOP!][!//

/*******************************************************************************
    [!"@name"!] -> Symbolic Name Defintions of CAN Hardware Objects 
*******************************************************************************/

[!LOOP "CanHardwareObject/*"!][!//
#ifdef Can_17_MCanPConf_CanHardwareObject_[!"@name"!] /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_[!"@name"!] != [!"CanObjectId"!]U)
    #error Can_17_MCanPConf_CanHardwareObject_[!"@name"!] is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_[!"@name"!]   ([!"CanObjectId"!]U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_[!"@name"!] */
[!ENDLOOP!][!//

[!LOOP "CanFifoConfiguration/*"!][!//
#ifdef Can_17_MCanPConf_CanHardwareObject_[!"@name"!] /* to prevent double declaration */
  #if (Can_17_MCanPConf_CanHardwareObject_[!"@name"!] != [!"CanFifoObjectId"!]U)
    #error Can_17_MCanPConf_CanHardwareObject_[!"@name"!] is already defined with a different value
  #endif  
#else
  /*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters 
  to follow Autosar naming conventions*/
  /*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
  to follow Autosar naming conventions*/
  #define Can_17_MCanPConf_CanHardwareObject_[!"@name"!]   ([!"CanFifoObjectId"!]U) 
#endif /* #ifdef Can_17_MCanPConf_CanHardwareObject_[!"@name"!] */
[!ENDLOOP!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

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
[!ENDSELECT!]
#endif  /* CAN_17_MCANP_CFG_H */