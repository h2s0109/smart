[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart_PBCfg.c $                                             **
**                                                                           **
**  $CC VERSION : \main\24 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Uart_PBCfg.c file                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**  TRACEABILITY : [cover parentID = DS_NAS_UART_PR709,SAS_NAS_UART_PR726,
                  SAS_NAS_UART_PR916,SAS_NAS_UART_PR916]                      **
**                [/cover]                                                   **
******************************************************************************/!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Uart_PBCfg.c $                                             **
**                                                                            **
**  $CC VERSION : \main\24 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Uart configuration generated out of ECU configuration      **
**                 file(Uart.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include UART Module File */
#include "Uart.h"

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
/*
               Container: UartConfigSet
*/
#define UART_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
[!//
[!SELECT "as:modconf('Uart')[1]"!][!//
 [!VAR "UartNotify" = "'NULL_PTR'"!][!//
 [!LOOP "UartConfigSet/*"!][!//
  [!LOOP "UartChannel/*"!][!//
   [!LOOP "UartNotification/*"!][!//
    [!VAR "UartNotify" = "."!][!//
    [!IF "$UartNotify = 'NULL_PTR'"!][!//
    [!ELSE!][!//
 /* Notification Function of [!"node:name(.)"!] */
  extern void [!"$UartNotify"!](Uart_ErrorIdType ErrorId);

    [!ENDIF!][!//
   [!ENDLOOP!][!//
  [!ENDLOOP!][!//
 [!ENDLOOP!][!//
[!ENDSELECT!][!// 
[!//
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Uart')[1]"!][!//
[!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//

[!/*
MACRO: Uart_CalcBaudParams.
Baudrate Parameter is calculated using the below formula
fPD = fA / (BRG.PRESCALER + 1)
fOVS = fPD * BRG.NUMERATOR / BRG.DENOMINATOR
fSHIFT or Baudrate= fOVS / (BITCON.OVERSAMPLING + 1)
*/!][!//
[!//
[!MACRO "Uart_CalcBaudParams", "BaudRate" = "", "input_freq2" = ""!][!//
[!NOCODE!][!//
 [!VAR "BaudConfig_found" = "num:i(2)"!][!//
 [!VAR "N_D" = "num:f(0.001)"!][!//
  [!FOR "inc" = "num:i(0)" TO "num:i(1000)"!][!//  /* ForLoop1 */
  [!FOR "O" = "num:i(9)" TO "num:i(16)"!][!//  /* ForLoop2 */
    [!VAR "temp_pre" = "(num:i($input_freq2) * num:f($N_D) ) div ( ($BaudRate) * ($O))"!][!//
      [!IF "num:i($temp_pre) < num:i(4096) and num:i($temp_pre) >= num:i(1) and num:f($N_D) <=num:f(1)"!][!//   /* If Condition1 */
        [!VAR "temp_baud" = "(num:i($input_freq2) * num:f($N_D) ) div ( num:i($temp_pre) * ($O))"!][!//
          [!IF "num:i($temp_baud) = num:i($BaudRate)"!][!//   /* If Condition2 */
              [!VAR "Numerator" = "num:i(num:f($N_D) * 1000)"!][!//
              [!VAR "Denominator" = "num:i(1000)"!][!//
              [!VAR "Prescalar" = "num:i(($temp_pre)-1)"!][!//
              [!VAR "Oversampling" = "num:i(($O)-1)"!][!//
              [!VAR "BaudConfig_found" = "num:i(1)"!][!//
              [!BREAK!][!//
          [!ENDIF!][!//      /* End Of If Condition2 */
      [!ENDIF!][!//         /* End Of If Condition1 */
  [!ENDFOR!][!// /* End of ForLoop2 */   
  [!IF "$BaudConfig_found = num:i(1)"!][!//
  [!BREAK!][!//
  [!ENDIF!][!// 
  [!VAR "N_D" = "($N_D)+ num:f(0.001)"!][!//
  [!ENDFOR!][!// /* End of ForLoop1 */  
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
/* Uart Channel Initialization Data */
[!VAR "TotalConfig" = "num:i(count(UartConfigSet/*))"!][!//
[!LOOP "UartConfigSet/*"!][!//
[!//
[!//
[!ASSERT "(node:refexists(./UartSysClockRef) = 'true')"!][!//
Config Error: Uart System Clock Reference is not provided.
[!ENDASSERT!]
[!VAR "input_freq" = "num:i(node:ref(./UartSysClockRef)/McuClockASCLINFFrequency)"!][!//
[!//
 [!VAR "TotalChannel" = "num:i(count(UartChannel/*))"!][!//
 [!VAR "ConfigIdx" = "@index"!][!//

static const Uart_ChannelType  Uart_kChannelConfig[!"@index"!][[!"string(num:i($TotalChannel))"!]] = 
{
[!LOOP "UartChannel/*"!][!//
[!//
 [!NOCODE!][!//
  [!IF "UartAutoCalcBaudParams = 'true'"!][!// /*If 1*/
   [!CALL "Uart_CalcBaudParams", "BaudRate" = "UartBaudRate", "input_freq2" = "$input_freq"!][!//
   [!VAR "BaudRate" = "num:i(UartBaudRate)"!][!//
  
  [!VAR "New_Baud" = "( ($input_freq2 * $Numerator) div  (($Prescalar+1) * ($Oversampling+1) * ($Denominator)))"!][!//
  [!IF "num:i($New_Baud) = num:i($BaudRate)"!][!// /*If 2*/
  [!ELSE!][!//
   [!ERROR!][!//
     ERROR: BaudRate could not be calculated automatically.Please enter Baud parameters manually.
   [!ENDERROR!][!//
  [!ENDIF!][!//  /*If 2 close*/
  [!ELSE!][!//
   [!VAR "Numerator" = "num:i(UartChanBaudNumerator)"!][!//
   [!VAR "Denominator" = "num:i(UartChanBaudDenominator)"!][!//
   [!VAR "Prescalar" = "num:i(UartChanBaudPrescalar)"!][!//
   [!VAR "Oversampling" = "num:i(UartChanBaudOverSampling)"!][!//
   [!VAR "fPD" = "num:i($input_freq) div (num:i($Prescalar) + 1)"!][!//
   [!VAR "fOVS" = "num:i($fPD) * num:i($Numerator) div num:i($Denominator)"!][!//
   [!VAR "BaudRate" = "num:i($fOVS) div (num:i($Oversampling) + 1)"!][!//
   [!IF "$BaudRate > num:i(6250000)"!][!//
    [!ERROR!][!//
    CONFIG ERROR: BaudRate  > 6250000 is not allowed for Uart. Reconfigure the UartChanBaudNumerator, UartChanBaudDenominator, UartChanBaudPrescalar UartChanBaudOversampling parameters.
    [!ENDERROR!][!//
   [!ENDIF!][!//
  [!ENDIF!][!//  /*If 1 close*/
 [!ENDNOCODE!][!//
[!//
  {  /* Notification function pointers for UART Module */
    {
      /* Call-back Notification Function for Write operation */
    [!VAR "SymbolicName" = "UartNotification/UartTransmitNotifPtr"!][!//
    [!IF "($SymbolicName != 'NULL_PTR')"!][!//
      &[!"$SymbolicName"!],
    [!ELSE!][!//
      [!"$SymbolicName"!],
    [!ENDIF!][!//
      /* Call-back Notification Function for Read operation */
    [!VAR "SymbolicName" = "UartNotification/UartRecieveNotifPtr"!][!//
    [!IF "($SymbolicName != 'NULL_PTR')"!][!//
      &[!"$SymbolicName"!],
    [!ELSE!][!//
      [!"$SymbolicName"!],
    [!ENDIF!][!//
      /* Call-back Notification Function for AbortWrite operation */
    [!VAR "SymbolicName" = "UartNotification/UartAbortTransmitNotifPtr"!][!//
    [!IF "($SymbolicName != 'NULL_PTR')"!][!//
      &[!"$SymbolicName"!],
    [!ELSE!][!//
      [!"$SymbolicName"!],
    [!ENDIF!][!//
      /* Call-back Notification Function for AbortRead operation */
    [!VAR "SymbolicName" = "UartNotification/UartAbortReceiveNotifPtr"!][!//
    [!IF "($SymbolicName != 'NULL_PTR')"!][!//
      &[!"$SymbolicName"!],
    [!ELSE!][!//
      [!"$SymbolicName"!],
    [!ENDIF!][!//
    },
  	/* BaudRate : [!"$BaudRate"!] Hz  */
    [!"$Numerator"!]U,       /* BRG.NUMERATOR value */
    [!"$Denominator"!]U,     /* BRG.DENOMINATOR value */
    [!"$Prescalar"!]U,       /* BITCON.PRESCALAR value */
    [!"$Oversampling"!]U,       /* BITCON.Oversampling value */
    UART_[!"UartHwUnit"!],    /* HW Unit used */
    [!"UartStopBits"!]U,      /* Number of Stop Bits*/
    [!"UartDataLength"!]U,      /* DataLength*/
    [!AUTOSPACING!]
[!IF "contains(UartRxPinSelection,'SELECT_DATALINE_A') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(0)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_B') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(1)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_C') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(2)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_D') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(3)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_E') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(4)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_F') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(5)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_G') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(6)"!][!//
[!ELSEIF "contains(UartRxPinSelection,'SELECT_DATALINE_H') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(7)"!][!//
[!ELSE!][!//
[!ENDIF!][!//
    [!"$RxSelLine"!]U,      /* UartRxPinSelection */
[!IF "contains(UartParityBit,'NOPARITY') = 'true'"!][!//
[!VAR "UartParityEnable" = "num:i(0)"!][!//
[!VAR "UartParity" = "num:i(0)"!][!//
[!ELSEIF "contains(UartParityBit,'ODDPARITY') = 'true'"!][!//
[!VAR "UartParityEnable" = "num:i(1)"!][!//
[!VAR "UartParity" = "num:i(1)"!][!//
[!ELSEIF "contains(UartParityBit,'EVENPARITY') = 'true'"!][!//
[!VAR "UartParityEnable" = "num:i(1)"!][!//
[!VAR "UartParity" = "num:i(0)"!][!//
[!ELSE!][!//
[!ENDIF!][!//
    [!"$UartParityEnable"!]U,      /*Parity Enable*/ 
    [!"$UartParity"!]U,      /* Odd or Even Parity */ 
[!IF "UartCTSEnable = 'true'"!][!//
 [!VAR "UartCtsEnable" = "num:i(1)"!][!//
 [!IF "contains(UartCTSPolarity,'HIGH') = 'true'"!][!//
  [!VAR "UartCtsPolarity" = "num:i(0)"!][!//
 [!ELSEIF "contains(UartCTSPolarity,'LOW') = 'true'"!][!//
  [!VAR "UartCtsPolarity" = "num:i(1)"!][!//
 [!ENDIF!][!//
[!ELSE!][!//
 [!VAR "UartCtsEnable" = "num:i(0)"!][!//
 [!VAR "UartCtsPolarity" = "num:i(0)"!][!//
[!ENDIF!][!//
    [!"$UartCtsEnable"!]U,      /*CTS Enable*/
    [!"$UartCtsPolarity"!]U,      /*RTS/CTS Polarity*/
  },
[!ENDLOOP!][!//
};
[!ENDLOOP!][!//

/* Uart Module Initialization Data */

const Uart_ConfigType  Uart_ConfigRoot[[!"string(num:i($TotalConfig))"!]] = 
 {
[!LOOP "UartConfigSet/*"!][!//  
   {
      Uart_kChannelConfig[!"@index"!],
     [!VAR "TotalChannel" = "num:i(count(UartChannel/*))"!][!//
      [!"$TotalChannel"!]U,
   }[!//
[!IF "@index != $TotalConfig -1"!],[!ENDIF!]
  
[!ENDLOOP!]
 };

[!ENDSELECT!][!//
[!//
#define UART_STOP_SEC_POSTBUILDCFG
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

