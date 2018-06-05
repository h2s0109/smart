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
**  $FILENAME   : Sent_LCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
**                                                                           **
**  $DATE       : 2014-11-05 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Sent_LCfg.c file                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!//
/******************************************************************************
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
**  FILENAME  : Sent_LCfg.c                                                  **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : SENT configuration generated out of ECU configuration     **
**                 file (Sent.bmd/.xdm)                                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "Sent_Cfg.h"
[!NOCODE!][!//
[!INCLUDE "Sent.m"!][!//
[!ENDNOCODE!][!//

/*******************************************************************************
**                      Global Macro Definitions                              **
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
**                      Global Constant Definitions                           **
*******************************************************************************/
#define SENT_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

[!AUTOSPACING!]
[!SELECT "SentConfigSet/*[num:i(1)]"!][!//
[!VAR "TotalChannels" = "num:i(count(SentChannelConfigSet/*))"!][!//
/* SENT Application Callout function pointer array per logical channel 
 * Common for all configuration sets
 */
const Sent_NotifFnPtrType SentNotifFnPtrArray[[!"num:i($TotalChannels)"!]] = 
{
[!FOR "Channel" = "0" TO "num:i($TotalChannels)"!][!//
[!SELECT "SentChannelConfigSet/*[num:i($Channel)]"!][!//
[!NOCODE!][!//
[!ASSERT "SentChanCalloutFn != 'NULL_PTR'"!][!//
Cfg ERROR: Callout function SentChanCalloutFn for SentChannelConfigSet[[!"num:i($Channel - 1)"!]] has not been configured, kindly provide the same.
[!ENDASSERT!][!//
[!ENDNOCODE!][!//
  &[!"SentChanCalloutFn"!],
[!ENDSELECT!][!//
[!ENDFOR!][!//
};

[!ENDSELECT!][!//

#define SENT_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR*/
#include "MemMap.h"
