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
**  $FILENAME : Pwm_17_Gtm.m     $                                           **
**                                                                            **
**   $CC VERSION : \main\9 $                                                  **
**                                                                            **
**   $DATE       : 2013-08-20 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Configuration Generator Macros                             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**  TRACEABILITY: [cover parentID=DS_NAS_PR699]                               **
**                                                                            **
**                 Configuration Generator Macros                             **
**                                                                            **
**  [/cover]
********************************************************************************

[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('PWM_17_GTM_M'))"!][!//
[!VAR "PWM_17_GTM_M"="'true'"!][!//
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

[!/*
MACRO "CG_GetHwUnitGtmVal
*/!][!//              
[!/*
MACRO "CG_GetHwUnitGtmVal
*/!][!//              
[!MACRO "CG_GetHwUnitGtmVal","nodepath" = "", "nodeval" = ""!][!//

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
** Name             : CG_GetIndex                                             **
**                                                                            **
** Description      : Macro to check the Mcu/Gtm config Index                 **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_GetIndex","M_nodename" = "","M_ConfigSetIndex" = ""!][!//
[!NOCODE!]
	[!VAR "O_McuConfigSetIndexValue" = "node:ref($M_nodename)/../../../../../../@index"!][!//
	[!IF "$O_McuConfigSetIndexValue != $M_ConfigSetIndex"!][!//
	[!ERROR!][!//
Config Error: [!"node:path(.)"!] shall use Gtm TOM/ATOM channels which belongs to McuModuleConfiguration_[!"$M_ConfigSetIndex"!] only.
               [!ENDERROR!][!//
	[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//
[!ENDIF!][!// IF "not(var:defined('PWM_17_GTM_M'))

