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
*******************************************************************************
**                                                                           **
**  $FILENAME   : Can_17_MCanP.m $                                           **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2013-11-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains macros used in Can_17_MCanP_PBCfg.c    **
**                 and Can_17_MCanP_Cfg.h                                    **
**                                                                           **
**  MAY BE CHANGED BY USER [Yes/No]: No                                      **
**                                                                           **
******************************************************************************/
/**  TRACEABILITY:                             [/cover]                     **/



/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 *
 *
 *
 * V0.0.4: 2013-02-25, SGN : Updated VendorApiInfix
 * V0.0.3: 2012-12-18, SGN : Updated file header for AS4.0.3
 * V0.0.2: 2012-05-14, SGN : Polling changed to POLLING
 * V0.0.1: 2012-05-03, SGN : Initial version (Baselined from AUDO V1.1.10)
*************************************************************************/!][!//
[!/* *** multiple inclusion protection *** */!][!//
[!IF "not(var:defined('CAN_17_MCANP_M'))"!][!//
[!VAR "CAN_17_MCANP_M"="'true'"!][!//
[!//
[!VAR "StdNodeType" = "'STANDARD'"!][!//
[!VAR "ExtNodeType" = "'EXTENDED'"!][!//
[!VAR "EventPolling" = "'POLLING'"!][!//
[!//
[!/*
MACRO: CG_ConfigSwitch 
Macro to generate configuration switch Values STD_ON/STD_OFF based on 
configuration true/false
*/!][!//
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!/*

*/!][!//
[!/*
MACRO: CG_GetHwObjectIdType 
Macro to get type CAN hardware object Id type
*/!][!//
[!MACRO "CG_GetHwObjectIdType", "node" = ""!][!//
[!//
[!IF "$node = $StdNodeType"!][!//
CAN_ID_STANDARD[!//
[!ELSEIF "$node = $ExtNodeType"!][!//
CAN_ID_EXTENDED[!//
[!ELSE!][!//
CAN_ID_MIXED[!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!/*


*/!][!//
[!/*
MACRO: CG_IsEventPolled 
Macro to get the event notification mechanism
*/!][!//
[!MACRO "CG_IsEventPolled", "event" = ""!][!//
[!IF "$event = $EventPolling"!][!//
(CAN_POLLING)[!//
[!ELSE!][!//
(CAN_INTERRUPT)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!/*


*/!][!//
[!ENDIF!][!//
