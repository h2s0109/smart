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
**  $FILENAME   : Iom_PBCfg.c $                                              **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  $DATE       : 2016-07-31 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                Code template for Iom_PBCfg.c file                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/!][!//
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
***************************************************************************** **
**                                                                            **
**  FILENAME  : Iom_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\8 $                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : IOM configuration generated out of ECU configuration       **
**                 file (Iom.bmd/.xdm)                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Includes                                             **
*******************************************************************************/

/* Include module header file */
#include "Iom.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]



/* Memory Mapping the configuration constant */
#define IOM_START_SEC_POSTBUILDCFG
#include "MemMap.h"



/*******************************************************************************
**                     Utility Macros                                         **
*******************************************************************************/



/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/



[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Iom')[1]"!][!//
[!//  
[!VAR "TotalConfig" = "num:i(count(IomConfigSet/*))"!][!//
[!FOR "ModuleIndex" = "1" TO "num:i($TotalConfig)"!][!//
[!VAR "ModulePath" = "'IomConfigSet/*[num:i($IomId)]'"!][!//
[!VAR "FpcCount" = "num:i(count(IomConfigSet/*[num:i($ModuleIndex)]/IomFpcConfiguration/*))"!][!//


/* FPC configuration */
static const Iom_FpcConfigType Iom_kFpcConfiguration[!"num:i($ModuleIndex)"!][] =
{  
[!FOR "FpcIndex" = "0" TO "(num:i($FpcCount)- 1)"!][!//
  {
[!SELECT "IomConfigSet/*[num:i($ModuleIndex)]/IomFpcConfiguration/*[($FpcIndex) + num:i(1)]"!][!//
[!NOCODE!][!//
[!VAR "FpcCompVal" = "./IomFpcCompareVal"!][!//
[!VAR "FpcResetTimer" = "./IomFpcResetTimer"!][!//
[!VAR "FpcResetTimerVal" = "num:i(0)"!][!//
[!IF "$FpcResetTimer = 'TIMER_CLEAR'"!][!//
[!VAR "FpcResetTimerVal" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "FpcConfVal" = "bit:or(num:i(substring(./IomFpcMode,5,1)),num:i(bit:shl(num:i(substring(./IomFpcMonInputSel,6,1)),num:i(3))))"!][!//
[!VAR "FpcConfVal1" = "bit:or(num:i($FpcConfVal),num:i(bit:shl(num:i($FpcResetTimerVal),num:i(6))))"!][!//
[!VAR "FpcConfVal2" = "bit:or(num:i($FpcConfVal1),num:i(bit:shl(num:i(substring(./IomFpcReferInputSel,6,1)),num:i(8))))"!][!//
[!VAR "FpcConfVal3" = "bit:or(num:i($FpcCompVal),num:i(bit:shl(num:i($FpcConfVal2),num:i(16))))"!][!//
[!ENDNOCODE!][!//
/* FPC control register value */
([!"num:inttohex($FpcConfVal3,8)"!]U),
/* FPC unit number */
((uint8) [!"(./IomFpcHwUnit)"!]U)
[!ENDSELECT!][!//
  } [!IF "($FpcIndex)!=(num:i($FpcCount)- 1)"!],[!ENDIF!]
  
[!ENDFOR!][!//

};

[!VAR "LamCount" = "num:i(count(IomConfigSet/*[num:i($ModuleIndex)]/IomLamConfiguration/*))"!][!//
/* LAM Configuration */
static const Iom_LamConfigType Iom_kLamConfiguration[!"num:i($ModuleIndex)"!][] =
{
[!FOR "LamIndex" = "0" TO "(num:i($LamCount)- 1)"!][!//
  {
[!SELECT "IomConfigSet/*[num:i($ModuleIndex)]/IomLamConfiguration/*[($LamIndex) + num:i(1)]"!][!//
[!NOCODE!][!//
[!VAR "LamInvReferSignal" = "./IomLamInvReferSignal"!][!//
[!VAR "LamInvReferSignalVal" = "num:i(0)"!][!//
[!IF "$LamInvReferSignal = 'true'"!][!//
[!VAR "LamInvReferSignalVal" = "num:i(1)"!][!//
[!ENDIF!][!// 
[!VAR "LamInvMonSignal" = "./IomLamInvMonSignal"!][!//
[!VAR "LamInvMonSignalVal" = "num:i(0)"!][!//
[!IF "$LamInvMonSignal = 'true'"!][!//
[!VAR "LamInvMonSignalVal" = "num:i(1)"!][!//
[!ENDIF!][!// 
[!VAR "LamMonSrcSelect" = "./IomLamMonSrcSelect"!][!//
[!VAR "LamMonSrcSelectVal" = "num:i(0)"!][!//
[!IF "$LamMonSrcSelect = 'MON_SIGNAL_EXOR_FPCR'"!][!//
[!VAR "LamMonSrcSelectVal" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "LamRunMode" = "./IomLamRunMode"!][!//
[!VAR "LamRunModeVal" = "num:i(0)"!][!//
[!IF "$LamRunMode = 'EVENT_WINDOW_GATED'"!][!//
[!VAR "LamRunModeVal" = "num:i(1)"!][!//
[!ENDIF!][!// 
[!VAR "LamEventWinSelect" = "./IomLamEventWinSelect"!][!//
[!VAR "LamEventWinSelectVal" = "num:i(0)"!][!//
[!IF "$LamEventWinSelect = 'EVENT_WIN_GEN_MON'"!][!//
[!VAR "LamEventWinSelectVal" = "num:i(1)"!][!//
[!ENDIF!][!//  
[!VAR "LamEveWinActEdgeSel" = "./IomLamEveWinActiveEdgeSelect"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(0)"!][!//
[!IF "$LamEveWinActEdgeSel = 'NEITHER_GATE_POS_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(1)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'NEITHER_GATE_NEG_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(2)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'NEITHER_GATE_EITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(3)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'POS_GATE_NEITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(4)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'POS_GATE_POS_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(5)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'POS_GATE_NEG_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(6)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'POS_GATE_EITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(7)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'NEG_GATE_NEITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(8)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'NEG_GATE_POS_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(9)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'NEG_GATE_NEG_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(10)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'NEG_GATE_EITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(11)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'EITHER_GATE_NEITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(12)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'EITHER_GATE_POS_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(13)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'EITHER_GATE_NEG_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(14)"!][!//
[!ELSEIF "$LamEveWinActEdgeSel = 'EITHER_GATE_EITHER_CLR'"!][!//
[!VAR "LamEveWinActEdgeSelVal" = "num:i(15)"!][!//
[!ENDIF!][!//  
[!VAR "LamInvEventWin" = "./IomLamInvEventWin"!][!//
[!VAR "LamInvEventWinVal" = "num:i(0)"!][!//
[!IF "$LamInvEventWin = 'true'"!][!//
[!VAR "LamInvEventWinVal" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//  
  /* LAM threshold value */ 
  ((uint32)[!"(./IomLamThreshold )"!]U),
  /* LAM configuration value */ 
[!NOCODE!][!//  
[!VAR "LamConfVal" = "bit:or(num:i($LamInvReferSignalVal),num:i(bit:shl(num:i($LamInvMonSignalVal),num:i(1))))"!][!//
[!VAR "LamConfVal1" = "bit:or(num:i($LamConfVal),num:i(bit:shl(num:i($LamMonSrcSelectVal),num:i(2))))"!][!//
[!VAR "LamConfVal2" = "bit:or(num:i($LamConfVal1),num:i(bit:shl(num:i($LamRunModeVal),num:i(3))))"!][!//
[!VAR "LamConfVal3" = "bit:or(num:i($LamConfVal2),num:i(bit:shl(num:i($LamEventWinSelectVal),num:i(4))))"!][!//
[!VAR "LamConfVal4" = "bit:or(num:i($LamConfVal3),num:i(bit:shl(num:i($LamEveWinActEdgeSelVal),num:i(8))))"!][!//
[!VAR "LamConfVal5" = "bit:or(num:i($LamConfVal4),num:i(bit:shl(num:i($LamInvEventWinVal),num:i(12))))"!][!// 
[!VAR "LamConfVal6" = "bit:or(num:i($LamConfVal5),num:i(bit:shl(num:i(substring(./IomLamMonInputSel,19,2)),num:i(16))))"!][!//
[!VAR "LamConfVal7" = "bit:or(num:i($LamConfVal6),num:i(bit:shl(num:i(substring(./IomLamRefInputSel,17,2)),num:i(20))))"!][!//
[!ENDNOCODE!][!//
([!"num:inttohex($LamConfVal7,8)"!]U),
/* LAM unit number */
 ((uint8) [!"(./IomLamHwUnit)"!]U)
[!ENDSELECT!][!//
  }[!IF "($LamIndex)!=(num:i($LamCount)- 1)"!],[!ENDIF!]

[!ENDFOR!][!//
}; 
/* ECM configuration */
static const Iom_EcmConfigType Iom_kEcmConfiguration[!"num:i($ModuleIndex)"!] =
{  
[!SELECT "IomConfigSet/*[num:i($ModuleIndex)]/IomEcmConfiguration/*[1]"!][!//
/* ECM counter configuration */
[!NOCODE!][!//
[!VAR "EcmCntVal" = "bit:or(num:i(./IomEcmEventSel0),num:i(bit:shl(num:i(./IomEcmThreshold0),num:i(4))))"!][!//
[!VAR "EcmCntVal1" = "bit:or(num:i($EcmCntVal),num:i(bit:shl(num:i(./IomEcmEventSel1),num:i(8))))"!][!//
[!VAR "EcmCntVal2" = "bit:or(num:i($EcmCntVal1),num:i(bit:shl(num:i(./IomEcmThreshold1),num:i(12))))"!][!//
[!VAR "EcmCntVal3" = "bit:or(num:i($EcmCntVal2),num:i(bit:shl(num:i(./IomEcmEventSel2),num:i(16))))"!][!//
[!VAR "EcmCntVal4" = "bit:or(num:i($EcmCntVal3),num:i(bit:shl(num:i(./IomEcmThreshold2),num:i(20))))"!][!//
[!VAR "EcmCntVal5" = "bit:or(num:i($EcmCntVal4),num:i(bit:shl(num:i(./IomEcmEventSel3),num:i(24))))"!][!// 
[!VAR "EcmCntVal6" = "bit:or(num:i($EcmCntVal5),num:i(bit:shl(num:i(./IomEcmThreshold3),num:i(28))))"!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($EcmCntVal6,8)"!]U,[!//
[!ENDSELECT!][!//

[!SELECT "IomConfigSet/*[num:i($ModuleIndex)]/IomEcmConfiguration/IomEventCombModGlobalSel"!][!//
[!NOCODE!][!//
[!VAR "EcmEventSel" = "'IomEcmEventCombSel'"!][!//
[!VAR "EcmCountHex" = "num:i(0)"!]
[!FOR "EcmCount" = "0" TO "15"!][!//
[!VAR "EcmValue" = "node:value(node:ref(concat($EcmEventSel,$EcmCount)))"!][!//
[!IF "$EcmValue = 'DISABLE_CHANNEL_EVENT'"!][!//
[!VAR "EcmCountHex" = "bit:or(num:i($EcmCountHex),bit:shl(num:i(0),num:i($EcmCount)))"!][!//
[!ELSE!][!//
[!VAR "EcmCountHex" = "bit:or(num:i($EcmCountHex),bit:shl(num:i(1),num:i($EcmCount)))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!// 
[!VAR "EcmAccEventSel" = "'IomEcmAccEventCombSel'"!][!//
[!FOR "EcmAccCount" = "0" TO "3"!][!//
[!VAR "EcmAccValue" = "node:value(node:ref(concat($EcmAccEventSel,$EcmAccCount)))"!][!//
[!IF "$EcmAccValue = 'DISABLE_COUNT_EVENT'"!][!//
[!VAR "EcmCountHex" = "bit:or(num:i($EcmCountHex),bit:shl(num:i(0),num:i(16 + num:i($EcmAccCount))))"!][!//
[!ELSE!][!//
[!VAR "EcmCountHex" = "bit:or(num:i($EcmCountHex),bit:shl(num:i(1),num:i(16 + num:i($EcmAccCount))))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDSELECT!][!//
([!"num:inttohex($EcmCountHex,8)"!]U)[!//

};

[!ENDFOR!][!//

 const Iom_ConfigType Iom_ConfigRoot[[!"($TotalConfig)"!]] = 
{
  [!FOR "ModuleIndex" = "1" TO "num:i($TotalConfig)"!][!//
  {
  
    &Iom_kFpcConfiguration[!"num:i($ModuleIndex)"!][0],
    &Iom_kLamConfiguration[!"num:i($ModuleIndex)"!][0],
    &Iom_kEcmConfiguration[!"num:i($ModuleIndex)"!],

[!SELECT "IomConfigSet/*[num:i($ModuleIndex)]/IomGtmConfiguration"!][!//
[!NOCODE!][!//
[!VAR "GtmString" = "'IomGtmInput'"!][!//
[!VAR "GtmAccessHex" = "num:i(0)"!][!//
[!FOR "GtmCount" = "0" TO "7"!][!//
[!VAR "GtmAccessValue" = "node:value(node:ref(concat($GtmString,$GtmCount)))"!][!//
[!IF "$GtmAccessValue = 'ENABLE_GTM_INPUT'"!][!//
[!VAR "GtmAccessHex" = "bit:or(num:i($GtmAccessHex),bit:shl(num:i(1),num:i($GtmCount)))"!][!//
[!ELSE!][!//
[!VAR "GtmAccessHex" = "bit:or(num:i($GtmAccessHex),bit:shl(num:i(0),num:i($GtmCount)))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDSELECT!][!//
[!"num:inttohex($GtmAccessHex,8)"!]U,
[!SELECT "IomConfigSet/*[num:i($ModuleIndex)]/IomSysConfiguration/IomClcConfiguration"!][!// 
[!NOCODE!][!//
[!VAR "ClcSleepMode" = "./IomClcSleepModeEn"!][!//
[!"$ClcSleepMode"!][!//
[!VAR "ClcRmcval" = "./IomClcRmcVal"!][!//
[!"num:i($ClcRmcval)"!]
[!VAR "ClcSleepModeVal" = "num:i(0)"!][!//
[!IF "$ClcSleepMode = 'true'"!][!//
[!VAR "ClcSleepModeVal" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "ClkConfVal" = "bit:or(num:i(0),num:i(bit:shl(num:i($ClcSleepModeVal),num:i(3))))"!][!//
[!VAR "ClkConfVal1" = "bit:or(num:i($ClkConfVal),num:i(bit:shl(num:i($ClcRmcval),num:i(8))))"!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($ClkConfVal1,8)"!]U,
[!ENDSELECT!][!//  
[!IF "(node:value(./IomGeneral/IomAccessEnableReg0) = 'IOM_ACCEN_INIT')"!][!//
[!SELECT "IomConfigSet/IomConfigSet_0/IomSysConfiguration/IomAccessEnReg0Config/*[1]"!][!//
[!VAR "AccessString" = "'IomAccessEnReg0_0'"!][!//
[!VAR "AccessHex" = "num:i(0)"!][!//
[!FOR "AccessCount" = "0" TO "9"!][!//
[!VAR "AccessValue" = "node:value(node:ref(concat($AccessString,$AccessCount)))"!][!//
[!IF "$AccessValue = 'true'"!][!//
[!VAR "AccessHex" = "bit:or(num:i($AccessHex),bit:shl(num:i(1),num:i($AccessCount)))"!][!//
[!ELSE!][!//
[!VAR "AccessHex" = "bit:or(num:i($AccessHex),bit:shl(num:i(0),num:i($AccessCount)))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "AccessString" = "'IomAccessEnReg0_'"!][!//
[!FOR "AccessCount" = "10" TO "31"!][!//
[!VAR "AccessValue" = "node:value(node:ref(concat($AccessString,$AccessCount)))"!][!//
[!IF "$AccessValue = 'true'"!][!//
[!VAR "AccessHex" = "bit:or(num:i($AccessHex),bit:shl(num:i(1),num:i($AccessCount)))"!][!//
[!ELSE!][!//
[!VAR "AccessHex" = "bit:or(num:i($AccessHex),bit:shl(num:i(0),num:i($AccessCount)))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!"num:inttohex($AccessHex,8)"!]U,
[!ELSEIF "(node:value(./IomGeneral/IomAccessEnableReg0) = 'IOM_ACCEN_DEFAULT')"!][!//
0xFFFFFFFFU,
[!ENDIF!] 
[!"num:i($FpcCount)"!]U

  }  [!IF "($ModuleIndex)!= num:i($TotalConfig)"!],[!ENDIF!]
  
  [!ENDFOR!][!//
}; 

#define IOM_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR*/
#include "MemMap.h"

[!ENDSELECT!][!//
[!AUTOSPACING!][!// 
