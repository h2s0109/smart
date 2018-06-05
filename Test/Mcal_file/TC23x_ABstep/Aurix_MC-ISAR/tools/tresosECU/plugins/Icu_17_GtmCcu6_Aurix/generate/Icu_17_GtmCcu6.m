[!/*
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Icu_17_GtmCcu6.m                                              **
**                                                                            **
**  VERSION   : 0.0.7                                                         **
**                                                                            **
**  DATE      : 2012-09-10                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX                                                **
**                                                                            **
**  COMPILER  : NA                                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Configuration Generator Macros                             **
**                                                                            **
**  TRACEABILITY:                                                             **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_ICU_Driver.pdf,Release 4.0.3 & 3.2.1       **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** VS          Vinod Shankar                                                  **
** VM          Venkatesh Maddera                                              **
** LR          Lokesh Revanasiddappa                                          **
** SS          Srinivas Shenoy			                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V0.0.7: 2013-02-13, SS  : Changes for VendorApiInfix
 * V0.0.6: 2012-09-10, VS  : Support of CCU. AI00066335
 * V0.0.5: 2012-07-11, LR  : Added Macro CG_GetIndex & CG_GetIndexERU 
 * V0.0.4: 2012-06-12, LR  : Added Header Protection
 * V0.0.3: 2012-05-02, LR  : Updated Traceability
 * V0.0.2: 2011-03-31, VM  : Updated the review comments REV_002598. 
 * V0.0.1: 2011-03-22, VM  : Initial Version 
 *
**************************************************************************/!]
[!//
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('ICU_17_GTMCCU6_M'))"!][!//
[!VAR "ICU_17_GTMCCU6_M"="'true'"!][!//
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
[!MACRO "CG_GetHwUnitGtmVal","nodepath" = ""!][!//

   [!VAR "ErrorConfig" = "num:i(0)"!]
   [!VAR "McuModuleName" = "substring-after($nodepath,'McuModuleConfiguration/')"!][!//
   [!VAR "McuModuleName" = "substring-before($McuModuleName,'/GtmConfiguration')"!][!//
   [!VAR "TimNumber" = "substring-after($nodepath,'Tim/')"!][!//
   [!VAR "TimNumber" = "substring-before($TimNumber,'/TimChannel')"!][!//
   [!VAR "TimNumber" = "substring-after($TimNumber,'Tim_')"!][!//
   [!VAR "TimChannelNumber" = "substring-after($nodepath,'TimChannel/TimChannel_')"!][!//
   [!VAR "GlobalChannelNumber" = "concat('GTM_TIM',$TimNumber,'_CHANNEL',$TimChannelNumber,'')"!][!//
   [!VAR "ErrorConfig" = "num:i(0)"!]
[!ENDMACRO!][!//

/*******************************************************************************
** Name             : CC_IcuEruChannels                                          **
**                                                                            **
** Description      : Macro to fill the channel numbers                       **
**                                                                            **
*******************************************************************************/
  [!MACRO "CC_IcuEruChannels", "ModuleId" = ""!][!// 
  [!NOCODE!][!//
  [!VAR "IcuEruChannelNum0" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum1" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum2" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum3" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum4" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum5" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum6" = "'ERU_REQLINE_UNUSED'"!]
  [!VAR "IcuEruChannelNum7" = "'ERU_REQLINE_UNUSED'"!]  
  [!SELECT "as:modconf('Icu')[1]/IcuConfigSet/*[num:i($ModuleId)]"!][!//
  [!LOOP "IcuChannel/*"!][!//
  [!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!//
  [!VAR "nodeval" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!//
  [!IF "contains($nodeval,'ERU0') = 'true'"!][!//
  [!VAR "IcuEruChannelNum0"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU1') = 'true'"!][!//
  [!VAR "IcuEruChannelNum1"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU2') = 'true'"!][!//
  [!VAR "IcuEruChannelNum2"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU3') = 'true'"!][!//
  [!VAR "IcuEruChannelNum3"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU4') = 'true'"!][!//
  [!VAR "IcuEruChannelNum4"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU5') = 'true'"!][!//
  [!VAR "IcuEruChannelNum5"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU6') = 'true'"!][!//
  [!VAR "IcuEruChannelNum6"= "./IcuChannelId"!][!//
  [!ELSEIF "contains($nodeval,'ERU7') = 'true'"!][!//
  [!VAR "IcuEruChannelNum7"= "./IcuChannelId"!][!//  
  [!ENDIF!][!//
  [!ENDLOOP!][!//
  [!ENDSELECT!][!//
  [!ENDNOCODE!][!//
  [!ENDMACRO!]
  
/*******************************************************************************
** Name           : CG_GetIndex                                               **
**                                                                            **
** Description    : Macro to check whether channels of IcuConfigset 'x'       **
**                 (=0,1,2..) are using GTM Tim channels of its corresponding **  
**                  McuModuleConfiguration 'y' (=0,1,2) respectively          **
**                                                                            **
*******************************************************************************/
  
[!MACRO "CG_GetIndex","M_nodename" = "","M_ConfigSetIndex" = ""!][!//
[!NOCODE!]
	[!VAR "O_McuConfigSetIndexValue" = "node:ref($M_nodename)/../../../../../../@index"!][!//
	[!IF "$O_McuConfigSetIndexValue != $M_ConfigSetIndex"!][!//
	[!ERROR!][!//
Config Error: [!"node:path(.)"!] shall use Gtm TIM channels which belongs to Mcu Config Set "[!"node:name(node:ref($M_nodename)/../../../../../../../*[$M_ConfigSetIndex+1])"!]" only.
  [!ENDERROR!][!//
	[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//

/*******************************************************************************
** Name           : CG_EruGetIndex                                            **
**                                                                            **
** Description    : Macro to check whether channels of IcuConfigset 'x'       **
**                  (=0,1,2..) are using ERU channels of its corresponding    **
**                  McuModuleConfiguration 'y' (=0,1,2) respectively          **
**                                                                            **
*******************************************************************************/

[!MACRO "CG_EruGetIndex","M_Erunodename" = "","M_EruConfigSetIndex" = ""!][!//
[!NOCODE!]
	[!VAR "O_McuEruConfigSetIndexValue" = "node:ref($M_Erunodename)/../../../@index"!][!//
	[!IF "$O_McuEruConfigSetIndexValue != $M_EruConfigSetIndex"!][!//
	[!ERROR!][!//
Config Error: [!"node:path(.)"!] shall use ERU channels which belongs to Mcu Config Set "[!"node:name(node:ref($M_Erunodename)/../../../../*[$M_EruConfigSetIndex+1])"!]" only.
  [!ENDERROR!][!//	
	[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//

/*******************************************************************************
** Name           : CG_CcuGetIndex                                            **
**                                                                            **
** Description    : Macro to check whether channels of IcuConfigset 'x'       **
**                  (=0,1,2..) are using CCU channels of its corresponding    **
**                  McuModuleConfiguration 'y' (=0,1,2) respectively          **
**                                                                            **
*******************************************************************************/

[!MACRO "CG_CcuGetIndex","M_Ccunodename" = "","M_CcuConfigSetIndex" = ""!][!//
[!NOCODE!]
	[!VAR "O_McuCcuConfigSetIndexValue" = "node:ref($M_Ccunodename)/../../../../../../../@index"!][!//
	Location checked is [!"(node:ref($M_Ccunodename)/../../../../../../../@index)"!]
	[!IF "$O_McuCcuConfigSetIndexValue != $M_CcuConfigSetIndex"!][!//
	[!ERROR!][!//
Config Error: [!"node:path(.)"!] shall use CCU channels which belongs to Mcu Config Set [!"$M_CcuConfigSetIndex"!] only.
  [!ENDERROR!][!//	
	[!ENDIF!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//  
[!ENDIF!][!// IF "not(var:defined('ICU_17_GTMCCU6_M'))

/*******************************************************************************
** Name             : CC_IcuCcuWakeupChannels                                 **
**                                                                            **
** Description      : Macro to fill the Wakeup Information                    **
**                                                                            **
*******************************************************************************/
[!MACRO "CC_IcuCcuWakeupChannels", "ModuleId" = ""!][!// 
[!NOCODE!][!//
[!VAR "IsCcuWakeupNeeded" = "num:i(0)"!][!//
[!SELECT "as:modconf('Icu')[1]/IcuConfigSet/*[num:i($ModuleId)]"!][!//
[!LOOP "IcuChannel/*"!][!//
[!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!//
[!IF "contains($nodepath,'CcuConfiguration') = 'true'"!]
[!VAR "KernalNodeName" = "node:name(node:ref(./IcuAssignedHwUnit)/../../..)"!]
[!VAR "CcuKernalNumber" = "text:toupper($KernalNodeName)"!][!//
[!//  Get Kernal Number 
[!VAR "CcuKernalValue" = "text:split($CcuKernalNumber, 'CU6')[position()-1 = 1]"!][!//
[!VAR "CcuWakeup" = "./IcuWakeupCapability"!][!//
[!IF "$CcuWakeup = 'true'"!][!//
[!VAR "IsCcuWakeupNeededTemp" = "num:i(bit:shl(1, $CcuKernalValue))"!][!//
[!VAR "IsCcuWakeupNeeded" = "bit:or($IsCcuWakeupNeeded, $IsCcuWakeupNeededTemp)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//