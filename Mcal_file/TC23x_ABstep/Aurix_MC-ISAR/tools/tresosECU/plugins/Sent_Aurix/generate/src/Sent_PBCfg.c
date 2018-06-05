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
**  $FILENAME   : Sent_PBCfg.c $                                             **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2014-11-05 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Sent_PBCfg.c file                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
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
**  FILENAME  : Sent_PBCfg.c                                                  **
**                                                                            **
**  $CC VERSION : \main\9 $                                                  **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SENT configuration generated out of ECU configuration      **
**                 file  (Sent.bmd)                                           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Sent_Cfg.h"

[!NOCODE!][!//
[!INCLUDE "Sent.m"!][!//
[!ENDNOCODE!][!//
#define SENT_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!SELECT "as:modconf('Sent')[1]"!][!//
[!VAR "AccenInit" = "num:i(0)"!][!//
[!IF "SentGeneral/SentAccessEnable = 'SENT_ACCEN_INIT'"!][!//
[!VAR "AccenInit" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "TotalConfig" = "num:i(count(SentConfigSet/*))"!][!//
[!FOR "SentId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SentConfigSet/*[num:i($SentId)]"!][!//
/* SENT Channel Configuration for ConfigSet [!"num:i($SentId - 1)"!] */
static const Sent_ChannelCfgType Sent_ChanConfig[!"num:i($SentId - 1)"!][] = 
{
[!NOCODE!][!//
[!VAR "SPBClock" = "(node:ref(./SentSystemClock)/*/McuClockSPBFrequency)"!] [!//
[!VAR "SentClock" = "$SPBClock div SentModuleClkDiv"!] [!//
[!VAR "SentFracClock" = "$SentClock div (num:i(1024) - SentBaudFracStep)"!] [!//
[!VAR "SuspendEn" = "num:i(0)"!][!//
[!IF "SentSleepModeEnable = 'true'"!][!//
[!/* SUSEN bit is bit 19 in RCR register */!][!//
[!VAR "SuspendEn" = "num:i(524288)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "TotalChannels" = "num:i(0)"!][!//
[!VAR "TotalChannels" = "num:i(count(SentChannelConfigSet/*))"!][!//
[!FOR "Channel" = "0" TO "num:i($TotalChannels)"!][!//
[!SELECT "SentChannelConfigSet/*[num:i($Channel)]"!][!//
[!NOCODE!][!//
[!VAR "RCRVal" = "num:i(0)"!][!//
[!IF "SentChanIgnoreEndPulse = 'true'"!][!//
[!/* IEP bit is bit 1 */!][!//
[!VAR "RCRVal" = "bit:shl(2,0) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanCRCMode = 'SENT_IFX_ALTERNATE'"!][!//
[!/* ACE bit is bit 2 */!][!//
[!VAR "RCRVal" = "bit:shl(2,1) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanStatusNibbleCRCInc = 'true'"!][!//
[!/* SNI bit is bit 3 */!][!//
[!VAR "RCRVal" = "bit:shl(2,2) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanSerialProcEn = 'true'"!][!//
[!/* SDP bit is bit 4 */!][!//
[!VAR "RCRVal" = "bit:shl(2,3) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanSerialCrcDisable = 'true'"!][!//
[!/* SCDIS bit is bit 5 */!][!//
[!VAR "RCRVal" = "bit:shl(2,4) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanFrameCrcDisable = 'true'"!][!//
[!/* CDIS bit is bit 6 */!][!//
[!VAR "RCRVal" = "bit:shl(2,5) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanFrameChk = 'SENT_PAST_VALID_SYNC_PULSE'"!][!//
[!/* CFC bit is bit 7 */!][!//
[!VAR "RCRVal" = "bit:shl(2,6) + $RCRVal"!][!//
[!ENDIF!][!//
[!/* FRL bits are bit 8-15 */!][!//
[!VAR "RCRVal" = "num:i(SentChanFrameDataLen * 256) + $RCRVal"!][!//
[!IF "SentChanCRZEn = 'false'"!][!//
[!/* CFC bit is bit 16 */!][!//
[!VAR "RCRVal" = "bit:shl(2,15) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanEnESF = 'true'"!][!//
[!/* ESF bit is bit 17 */!][!//
[!VAR "RCRVal" = "bit:shl(2,16) + $RCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanDriftErrEn = 'false'"!][!//
[!/* IDE bit is bit 18 */!][!//
[!VAR "RCRVal" = "bit:shl(2,17) + $RCRVal"!][!//
[!ENDIF!][!//
[!/* Add SUSEN if enabled */!][!//
[!VAR "RCRVal" = "$SuspendEn + $RCRVal"!][!//
[!VAR "OutMac_ALTI" = "num:i(0)"!][!//
[!VAR "IOCRVal" = "num:i(0)"!][!//
[!CALL "CG_ALTI_Value","MacInputVal" = "SentChanPinSel"!][!//
[!VAR "IOCRVal" = "$OutMac_ALTI + $IOCRVal"!][!//
[!/* DEPTH bits are bit 4-7 */!][!//
[!VAR "IOCRVal" = "num:i(SentChanGlitchFilterDepth * 16) + $IOCRVal"!][!//
[!IF "SentChanOutPulse = 'SENT_ACTIVE_HIGH'"!][!//
[!/* OIE bit is bit 8 */!][!//
[!VAR "IOCRVal" = "bit:shl(2,7) + $IOCRVal"!][!//
[!ENDIF!][!//
[!IF "SentChanInPulse = 'SENT_ACTIVE_HIGH'"!][!//
[!/* IIE bit is bit 9 */!][!//
[!VAR "IOCRVal" = "bit:shl(2,8) + $IOCRVal"!][!//
[!ENDIF!][!//
[!VAR "SentChanPreDivClock" = "$SentFracClock div (num:i(1) + SentChanPreDiv)"!][!//    
[!VAR "SentChanBaudFreq" = "($SentChanPreDivClock * num:i(56)) div SentChanBaudDiv"!][!//
[!VAR "SentChanBaudRate" = "(num:i(1) div $SentChanBaudFreq) * num:i(1000000)"!][!//
[!ENDNOCODE!][!//
  {
    /* SENT_RCRx register value */
    ([!"num:inttohex($RCRVal, 8)"!]U),
    /* SENT_IOCRx register value */  
    ([!"num:inttohex($IOCRVal, 8)"!]U),
    /* SENT_VIEWx register value */  
    ([!"num:inttohex(SentChanDataView, 8)"!]U),
    /* SENT_CPDRx register value */  
    ([!"num:inttohex(SentChanPreDiv, 8)"!]U),
    /* SENT_CFDRx reg value (Baudrate tick time derived is [!"$SentChanBaudRate"!]us) */  
    ([!"num:inttohex(SentChanBaudDiv, 8)"!]U),
    /* Frame length */  
    ([!"SentChanFrameDataLen"!]U),
    /* Interrupt Node */
    ([!"SentChanIndex"!]U),        
    /* SENT Physical Channel Id */  
    ([!"SentChanIndex"!]U),
  },
[!ENDSELECT!][!//
[!ENDFOR!][!//
};

/* SRN to SENT logical channel mapping for ConfigSet [!"num:i($SentId - 1)"!] */
static const uint8 Srn_ChanMap[!"num:i($SentId - 1)"!][SENT_HW_MAX_CHANNELS] = 
{
[!FOR "SrnVal" = "0" TO "num:i(ecu:get('Sent.MaxChannelsSupported') - 1)"!][!//
[!VAR "LogicalChannel" = "'SENT_CHANNEL_NOT_MAPPED'"!][!//
[!FOR "Channel" = "0" TO "num:i($TotalChannels)"!][!//
[!SELECT "SentChannelConfigSet/*[num:i($Channel)]"!][!//
[!IF "SentChanIndex = num:i($SrnVal)"!][!//
[!VAR "LogicalChannel" = "num:i($Channel - 1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!IF "num:isnumber($LogicalChannel) = 'true'"!][!//
  ([!"$LogicalChannel"!]U),
[!ELSE!][!//
  ([!"$LogicalChannel"!]),
[!ENDIF!][!//
[!ENDFOR!][!//
};

[!ENDSELECT!][!//
[!ENDFOR!][!//


/* SENT Module Configuration */
const Sent_ConfigType Sent_ConfigRoot[[!"num:i($TotalConfig)"!]] = 
{
[!FOR "SentId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SentConfigSet/*[num:i($SentId)]"!][!//
  /* ConfigSet [!"num:i($SentId - 1)"!] */
  {
    /* Pointer to Channel configuration */
    &Sent_ChanConfig[!"num:i($SentId - 1)"!][0],
    /* Pointer to the SRN mapping array */
    &Srn_ChanMap[!"num:i($SentId - 1)"!][0],
[!NOCODE!][!//
[!VAR "SleepModeEn" = "num:i(0)"!][!//
[!IF "SentSleepModeEnable = 'true'"!][!//
[!/* Set the desired bit of CLC register i.e. 3rd bit */!][!//
[!VAR "SleepModeEn" = "num:i(8)"!][!//
[!ENDIF!][!//
[!/* Get the RMC value and left shift by 8 */!][!//
[!VAR "SentCLCRegVal" = "num:i(SentModuleClkDiv * 256)"!][!//
[!/* Add the EDIS bit if set */!][!//
[!VAR "SentCLCRegVal" = "$SentCLCRegVal + $SleepModeEn"!][!//
[!ENDNOCODE!][!//
    /* Module clock divider */
    ([!"num:inttohex($SentCLCRegVal, 8)"!]U),
    /* ACCEN0 register value */     
[!IF "$AccenInit = num:i(1)"!][!//
[!IF "node:exists(SentAccessEnVal/*[1])"!]
[!VAR "BuildSentAccenReg" = "num:i(0)"!][!//
[!VAR "LoopCount" = "num:i(0)"!][!// 
[!LOOP "(SentAccessEnVal/*[1]/SentEnableAccForTagId/*)"!][!//
[!IF "node:value(./EnableAccess) = 'true'"!][!// 
[!VAR "BuildSentAccenReg" = "bit:bitset($BuildSentAccenReg, $LoopCount)"!][!// 
[!ENDIF!][!// 
[!VAR "LoopCount" = "num:i($LoopCount + 1)"!][!// 
[!ENDLOOP!][!// 
    [!"num:inttohex($BuildSentAccenReg,8)"!]U,
[!ELSE!][!//
    0xFFFFFFFFU,
[!ENDIF!][!//   
[!ELSE!][!//
    0xFFFFFFFFU, 
[!ENDIF!][!//
    /* Module Fractional step divider */      
    ([!"num:i(SentBaudFracStep)"!]U),
    /* SENT channels configured */
[!NOCODE!][!//
[!VAR "MaxSentChannels" = "num:i(0)"!][!//
[!VAR "MaxSentChannels" = "num:i(count(SentChannelConfigSet/*))"!][!//
[!ENDNOCODE!][!//
    ([!"$MaxSentChannels"!]U),
  },
[!ENDSELECT!][!//
[!ENDFOR!][!//
};

[!ENDSELECT!][!//
#define SENT_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS= Memmap file included as per AUTOSAR*/
#include "MemMap.h"

[!AUTOSPACING!]
