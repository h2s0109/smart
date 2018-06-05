[!/*
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
**  $FILENAME   : Gpt.m $                                                    **
**                                                                            **
**  $CC VERSION : \main\9 $                                                  **
**                                                                            **
**  $DATE       : 2013-07-25 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains code generator macros                   **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_Gpt_Driver,Release  4.0.3                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/



[!//
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('GPT_M'))"!][!//
[!VAR "GPT_M"="'true'"!][!//
[!/*
MACRO: CG_ConfigSwitch 
Macro to generate configuration switch Values STD_ON/STD_OFF based on configuration
true/false
*/!]
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]

/*******************************************************************************
** Name           : CG_GetHwUnitGtmVal                                        **
**                                                                            **
** Description    : Macro to check whether TOM/ATOM is configured for a       **
**                  Gpt channel                                               **
**                                                                            **
*******************************************************************************/

[!/*
MACRO "CG_GetHwUnitGtmVal
*/!][!//              
[!/*
MACRO "CG_GetHwUnitGtmVal
*/!][!//              
[!MACRO "CG_GetHwUnitGtmVal","nodepath" = ""!][!//

   [!VAR "ErrorConfig" = "num:i(0)"!]
   [!IF "contains($nodepath,'/Atom/') = 'true'"!]
     [!VAR "TomAtom" = "'ATOM'"!]
     [!VAR "McuModuleName" = "substring-after($nodepath,'McuModuleConfiguration/')"!][!//
     [!VAR "McuModuleName" = "substring-before($McuModuleName,'/GtmConfiguration')"!][!//
     [!VAR "AtomNumber" = "substring-after($nodepath,'Atom/')"!][!//
     [!VAR "AtomNumber" = "substring-before($AtomNumber,'/AtomChannel')"!][!//
     [!VAR "AtomNumber" = "substring-after($AtomNumber,'Atom_')"!][!//
     [!VAR "AtomChannelNumber" = "substring-after($nodepath,'AtomChannel/AtomChannel_')"!][!//
     [!//[!VAR "GlobalChannelNumber" = "num:i($AtomNumber + 1) * num:i($AtomChannelNumber)"!][!//
     [!//[!VAR "GlobalChannelNumber" = "num:i($GlobalChannelNumber + 48)"!][!//
     [!VAR "GlobalChannelNumber" = "concat('GTM_ATOM',$AtomNumber,'_CHANNEL',$AtomChannelNumber,'')"!][!//
   [!ELSEIF "contains($nodepath,'/Tom/') = 'true'"!]
     [!//[!VAR "TomAtom" = "'TOM'"!][!//
     [!VAR "McuModuleName" = "substring-after($nodepath,'McuModuleConfiguration/')"!][!//
     [!VAR "McuModuleName" = "substring-before($McuModuleName,'/GtmConfiguration')"!][!//
     [!VAR "TomNumber" = "substring-after($nodepath,'Tom/')"!][!//
     [!VAR "TomNumber" = "substring-before($TomNumber,'/TomChannel')"!][!//
     [!VAR "TomNumber" = "substring-after($TomNumber,'Tom_')"!][!//
     [!VAR "TomChannelNumber" = "substring-after($nodepath,'TomChannel/TomChannel_')"!][!//
     [!VAR "GlobalChannelNumber" = "concat('GTM_TOM',$TomNumber,'_CHANNEL',$TomChannelNumber,'')"!][!//
     [!//[!VAR "GlobalChannelNumber" = "num:i($TomNumber + 1) * num:i($TomChannelNumber)"!][!//
   [!ELSE!][!//
     [!VAR "ErrorConfig" = "num:i(0)"!]
   [!ENDIF!][!//
[!ENDMACRO!][!//

/*******************************************************************************
** Name           : CG_GetIndex                                               **
**                                                                            **
** Description    : Macro to check whether channels of IcuConfigset 'x'       **
**                  (=0,1,2..) are using GTM Tom/Atom channels of its         **  
**                  corresponding McuModuleConfiguration 'y' (=0,1,2)         **
**                  respectively                                              **
**                                                                            **
*******************************************************************************/


[!MACRO "CG_GetIndex","M_nodename" = "","M_ConfigSetIndex" = ""!][!//
[!NOCODE!]
	[!VAR "O_McuConfigSetIndexValue" = "node:ref($M_nodename)/../../../../../../@index"!][!//
	[!IF "$O_McuConfigSetIndexValue != $M_ConfigSetIndex"!][!//
	[!ERROR!][!//
Config Error: [!"node:path(.)"!] shall use Gtm TOM/ATOM channels which belongs to Mcu Config Set "[!"node:name(node:ref($M_nodename)/../../../../../../../*[$M_ConfigSetIndex+1])"!]" only.
  [!ENDERROR!][!//
	[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//



[!ENDIF!][!// IF "not(var:defined('GPT_M'))