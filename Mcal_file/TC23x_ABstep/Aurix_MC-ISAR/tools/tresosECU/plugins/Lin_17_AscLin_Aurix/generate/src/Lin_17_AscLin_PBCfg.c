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
**  $FILENAME   : Lin_17_AscLin_PBCfg.c $                                    **
**                                                                           **
**  $CC VERSION : \main\40 $                                                 **
**                                                                           **
**  $DATE       : 2015-06-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Lin_17_AscLin_PBCfg.c file               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
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
**  FILENAME  : Lin_17_AscLin_PBCfg.c                                         **
**                                                                            **
**  $CC VERSION : \main\40 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  MODULE DECRIPTION : Lin_17_AscLin.bmd/.xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Lin configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_LIN_Driver, Release 4.0.3                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
TRACEABILITY : [cover parentID= DS_NAS_LIN_PR446, SAS_AS_LIN064,
DS_NAS_LIN_PR701,DS_NAS_LIN_PR704,DS_NAS_LIN_PR707,DS_NAS_LIN_PR708,
DS_NAS_LIN_PR712,DS_NAS_LIN_PR713,DS_NAS_LIN_PR714,DS_NAS_LIN_PR716,
DS_NAS_LIN_PR719,DS_NAS_LIN_PR720,DS_NAS_LIN_PR723,DS_NAS_LIN_PR724,
DS_NAS_LIN_PR709,DS_NAS_LIN_PR699,SAS_AS4XX_LIN_PR680,DS_NAS_LIN_PR717,
DS_NAS_LIN_PR700,DS_NAS_LIN_PR728,SAS_NAS_LIN_PR729] [/cover]      
*******************************************************************************/
/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/

/* Include LIN Module File */
#include "Lin_17_AscLin.h"
    
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
                     Container: LinChannelConfiguration
*/
#define LIN_17_ASCLIN_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Lin')[1]"!][!//
[!//

[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//

[!/*
MACRO: Lin_CalcBaudParams.
Baudrate Parameter is calculated using the below formula
fPD = fA / (BRG.PRESCALER + 1)
fOVS = fPD * BRG.NUMERATOR / BRG.DENOMINATOR
fSHIFT or Baudrate= fOVS / (BITCON.OVERSAMPLING + 1)

*/!][!//
[!//
[!MACRO "Lin_CalcBaudParams", "BaudRate" = "", "input_freq2" = ""!][!//
[!NOCODE!][!//
[!VAR "BaudConfig_found" = "num:i(2)"!][!//
 [!VAR "N_D" = "num:f(0.001)"!][!//
 [!VAR "O" = "num:i(16)"!][!//  /* BITCON.OVERSAMPLING + 1*/
  [!FOR "inc" = "num:i(0)" TO "num:i(1000)"!][!//  /* ForLoop1 */
    [!VAR "temp_pre" = "(num:i($input_freq2) * num:f($N_D) ) div ( ($BaudRate) * ($O))"!][!//
      [!IF "num:i($temp_pre) < num:i(4096) and num:i($temp_pre) >= num:i(1) and num:f($N_D) <=num:f(1)"!][!//   /* If Condition1 */
        [!VAR "temp_baud" = "(num:i($input_freq2) * num:f($N_D) ) div ( num:i($temp_pre) * ($O))"!][!//
          [!IF "num:i($temp_baud) = num:i($BaudRate)"!][!//   /* If Condition2 */
              [!VAR "Numerator" = "num:i(num:f($N_D) * 1000)"!][!//
              [!VAR "Denominator" = "num:i(1000)"!][!//
              [!VAR "Prescalar" = "num:i(($temp_pre)-1)"!][!//
              [!VAR "BaudConfig_found" = "num:i(1)"!][!//
              [!BREAK!][!//
          [!ENDIF!][!//      /* End Of If Condition2 */
      [!ENDIF!][!//         /* End Of If Condition1 */
  [!VAR "N_D" = "($N_D)+ num:f(0.001)"!][!//
  [!ENDFOR!][!// /* End of ForLoop1 */  

[!IF "$BaudConfig_found != num:i(1)"!][!//
[!ERROR!][!//
BaudRate Configuration couldnot be found for the input frequency LinSysClockRef: [!"$input_freq2"!] and LinChannelBaudRate: [!"$BaudRate"!]
[!ENDERROR!][!//
[!ENDIF!]

[!ENDNOCODE!][!//
[!ENDMACRO!][!//


/* Lin_Channel: User configured channel initialization structure. */
[!VAR "TotalConfig" = "num:i(count(LinGlobalConfig/*))"!][!//
[!ASSERT "(node:refexists(./LinGeneral/LinSysClockRef) = 'true')"!][!//
Config Error: Lin system clock reference not provided.
[!ENDASSERT!]
[!VAR "input_freq" = "num:i(node:ref(./LinGeneral/LinSysClockRef)/McuClockASCLINFFrequency)"!][!//
[!LOOP "LinGlobalConfig/*"!][!//

[!VAR "TotalChannel" = "num:i(count(LinChannel/*))"!][!//
[!VAR "ConfigIdx" = "@index"!][!//
static const Lin_17_AscLin_ChannelType  Lin_kChannelConfig[!"@index"!][[!"string(num:i($TotalChannel))"!]] = 
{
[!LOOP "LinChannel/*"!][!//
[!NOCODE!][!//
[!IF "LinAutoCalcBaudParams = 'true'"!][!//
[!CALL "Lin_CalcBaudParams", "BaudRate" = "LinChannelBaudRate", "input_freq2" = "$input_freq"!][!//
[!VAR "BaudRate" = "num:i(LinChannelBaudRate)"!][!//
[!ELSE!][!//
[!VAR "Numerator" = "num:i(LinChanBaudNumerator)"!][!//
[!VAR "Denominator" = "num:i(LinChanBaudDenominator)"!][!//
[!VAR "Prescalar" = "num:i(LinChanBaudPrescalar)"!][!//
[!VAR "fPD" = "num:i($input_freq) div (num:i($Prescalar) + 1)"!][!//
[!VAR "fOVS" = "num:i($fPD) * num:i($Numerator) div num:i($Denominator)"!][!//
[!VAR "BaudRate" = "num:i($fOVS) div (num:i(15) + 1)"!][!//
[!IF "$BaudRate > num:i(20000)"!][!//
[!ERROR!][!//
CONFIG ERROR: BaudRate  > 20000 is not allowed for Lin. Reconfigure the LinChanBaudNumerator, LinChanBaudDenominator, LinChanBaudPrescalar parameters.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!/*
Wakeup pulse duration = 150usec 
    = No of Microticks * (PS+1) div fA (in Hz)
=> 150 = No of microticks * (PS+1) div fA (in Mhz)
=> 150 * fA (in Mhz) = No of Micro ticks * (PS+1)
*/!][!//
[!VAR "WakeupIocrDepth" = "num:i(1)"!][!//
[!VAR "WakeupPrescalar" = "num:i(1)"!][!//
[!VAR "wakeupval_found" = "num:i(0)"!][!//
[!VAR "expectedval" = "(num:i($input_freq) div num:i(1000000)) * num:i(150)"!][!//

[!FOR "WakeupPrescalar" = "num:i(1)" TO "num:i(4095)"!][!//
[!FOR "WakeupIocrDepth" = "num:i(1)" TO "num:i(63)"!][!//

[!VAR "CalcVal1" = "num:i($WakeupPrescalar) * num:i($WakeupIocrDepth)"!][!//
[!VAR "CalcVal2" = "num:i($WakeupPrescalar) * num:i($WakeupIocrDepth + 1)"!][!//

[!IF "num:i($expectedval) = num:i($CalcVal1)"!][!//
[!VAR "wakeupval_found" = "num:i(1)"!][!//
[!BREAK!][!//
[!ELSEIF "(num:i($expectedval) > num:i($CalcVal1)) and  (num:i($expectedval) <= num:i($CalcVal2))"!][!//
[!VAR "wakeupval_found" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!]
[!ENDFOR!][!//
[!IF "$wakeupval_found = num:i(1)"!][!//
[!VAR "WakeupPrescalar" = "num:i($WakeupPrescalar) -  1"!][!//
[!BREAK!][!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDNOCODE!][!//
  /* LIN Channel ID: [!"LinChannelId"!] Configuration */
  {
    /* BaudRate : [!"$BaudRate"!] Hz  */
    {
       [!"$Numerator"!]U,  /* BRG.NUMERATOR value */
       [!"$Denominator"!]U,    /* BRG.DENOMINATOR value */
       [!"$Prescalar"!]U,  /* BITCON.PRESCALAR value */
       [!"num:i($WakeupPrescalar)"!]U,  /* Prescalar value for wakeup detection */       
       [!"LinInterByteSpace"!]U, /* Inter byte or response space value */
       [!"num:i($WakeupIocrDepth)"!]U /* IOCR DEPTH value for wakeup detection */
    },
[!IF "LinChannelWakeupSupport = 'true'"!][!//
[!ASSERT "(node:refexists(LinChannelEcuMWakeupSource) = 'true')"!][!//
Config Error: LinChannelEcuMWakeupSource reference not provided for Channel ID: [!"LinChannelId"!].
[!ENDASSERT!]
[!VAR "WakeupSupport" = "node:ref(./LinChannelEcuMWakeupSource)/EcuMWakeupSourceId"!][!//
    [!"$WakeupSupport"!]U,          /* EcuM Wakeup Source ID */
[!ELSE!][!//
[!//
[!IF "node:refexists(LinChannelEcuMWakeupSource) = 'true'"!][!//  
[!VAR "WakeupSupport" = "node:ref(./LinChannelEcuMWakeupSource)/EcuMWakeupSourceId"!][!//
    [!"$WakeupSupport"!]U,          /* EcuM Wakeup Source ID */
[!ELSE!][!//
    0U,                             /* EcuM Wakeup Source ID */
[!ENDIF!][!//       
[!//
[!ENDIF!][!//       
    LIN_[!"LinChanAssignedHw"!],                   /* Hw Module used */
[!AUTOSPACING!]
[!IF "node:exists(LinChannelWakeupSupport)"!][!//
[!IF "LinChannelWakeupSupport = 'true'"!][!//
    LIN_CHANNEL_WAKEUP_ENABLED,    /* Wakeup Support */
[!ELSE!][!//
    LIN_CHANNEL_WAKEUP_DISABLED,   /* Wakeup Support */
[!ENDIF!]
[!ELSE!][!//
    LIN_CHANNEL_WAKEUP_DISABLED,   /* Wakeup Support */
[!ENDIF!][!//
    /*Rx alternate pin select */
[!IF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_A') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(0)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_B') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(1)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_C') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(2)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_D') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(3)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_E') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(4)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_F') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(5)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_G') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(6)"!][!//
[!ELSEIF "contains(LinRxAlternateInputSignal,'SELECT_DATALINE_H') = 'true'"!][!//
[!VAR "RxSelLine" = "num:i(7)"!][!//
[!ELSE!][!//
[!ENDIF!][!//
    [!"$RxSelLine"!]U
  },
[!ENDLOOP!][!//
};
[!ENDLOOP!][!//

[!IF "$MajorVersion = num:i(4)"!][!//

/* 
   The over all initialization data for the LIN driver. 
   The user configured Lin driver initialization structure.
*/
const Lin_17_AscLin_ConfigType  Lin_ConfigRoot[[!"string(num:i($TotalConfig))"!]] = 
 {
[!LOOP "LinGlobalConfig/*"!][!//  
   {
      Lin_kChannelConfig[!"@index"!],
     [!VAR "TotalChannel" = "num:i(count(LinChannel/*))"!][!//
      [!"$TotalChannel"!]U,
   }[!//
[!IF "@index != $TotalConfig -1"!],[!ENDIF!]
  
[!ENDLOOP!]
 };
[!ENDIF!][!//
[!ENDSELECT!][!//

#define LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
is allowed only for MemMap.h*/
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

