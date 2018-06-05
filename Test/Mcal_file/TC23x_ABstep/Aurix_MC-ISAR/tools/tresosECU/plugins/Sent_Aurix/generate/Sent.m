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
**  $FILENAME   : Sent.m $                                                   **
**                                                                           **
**  $CC VERSION : \main\2 $                                                  **
**                                                                           **
**  $DATE       : 2014-02-24 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : Configuration Generator Macros                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
/******************************************************************************/
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('Sent_M'))"!][!//
[!VAR "Sent_M"="'true'"!][!//
/*******************************************************************************
** Name             : CG_ConfigSwitch                                         **
**                                                                            **
** Description      : Macro to generate configuration switch Values ON/OFF    **
**                    based on configuration true/false                       **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_ConfigSwitch", "MacInputVal" = ""!][!//
[!//
[!IF "$MacInputVal = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]

/*******************************************************************************
** Name             : CG_ALTI_Value                                           **
**                                                                            **
** Description      : Macro to retrieve the value in OutMac_ALTI variable     **
**                    based on the MacInputVal value                          **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_ALTI_Value", "MacInputVal" = ""!][!//
[!//
[!IF "$MacInputVal = 'SENT_ALT_INPUT0'"!][!//
[!VAR "OutMac_ALTI" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SENT_ALT_INPUT1'"!][!//
[!VAR "OutMac_ALTI" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'SENT_ALT_INPUT2'"!][!//
[!VAR "OutMac_ALTI" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SENT_ALT_INPUT3'"!][!//
[!VAR "OutMac_ALTI" = "num:i(3)"!]
[!ELSE!][!//
[!ERROR"Config Error: Wrong Channel Pin Select."!]
[!ENDIF!]
[!ENDMACRO!]

[!ENDIF!][!// IF "not(var:defined('Sent_M'))

