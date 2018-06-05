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
**  $FILENAME   : Dma_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-06 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Dma_PBCfg.c file                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
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
**  FILENAME  : Dma_PBCfg.c                                                  **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : DMA configuration generated out of ECU configuration      **
**                 file (Dma.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEBILITY : 
    [cover parentID = DS_NAS_DMA_PR69_PR469_PR122_PR123,DS_NAS_DMA_PR647,
    DS_NAS_DMA_PR446,DS_NAS_DMA_PR699,DS_NAS_DMA_PR709,
    SAS_NAS_DMA_PR914,SAS_NAS_DMA_PR915,SAS_NAS_DMA_PR916,
    SAS_NAS_DMA_PR82,DS_NAS_DMA_PR704,SAS_NAS_DMA_PR60,
    DS_NAS_DMA_PR707,DS_NAS_DMA_PR708,DS_NAS_DMA_PR712
    ]
**  [/cover]                                                                 **
*******************************************************************************/

[!NOCODE!][!//
[!INCLUDE "Dma.m"!][!//
[!ENDNOCODE!][!//
/*******************************************************************************
**                            Includes                                        **
*******************************************************************************/
/* Include module header file */
#include "Dma.h"
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*
                     Container: DmaChannelConfiguration
*/

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Dma')[1]"!][!//
/* Memory Mapping the configuration constant */
#define DMA_START_SEC_POSTBUILDCFG
#include "MemMap.h"
[!VAR "ConfigSetIndex" = "num:i(0)"!][!//
[!VAR "NoOfConfigSets" = "num:i(count(DmaConfigSet/*))"!][!//
[!VAR "ChannelIndex" = "num:i(0)"!][!//
[!VAR "ChannelIndexj" = "num:i(0)"!][!//
[!//

/************************** DMA Channel Config Root ***************************/
[!FOR "ConfigSetIndex" = "0" TO "(num:i($NoOfConfigSets)- 1)"!][!//
[!VAR "NoOfChannels" = "num:i(count(DmaConfigSet/*[@index=$ConfigSetIndex]/DmaChannelConfiguration/*))"!][!//

/******** Configuration of channels in DmaConfigSet([!"$ConfigSetIndex"!]) ********/
static const Dma_ChannelConfigType Dma_kChannelConfigRoot[!"$ConfigSetIndex"!][]=
{
[!FOR "ChannelIndex" = "0" TO "(num:i($NoOfChannels)- 1)"!][!//
 {
  [!SELECT "DmaConfigSet/*[@index=$ConfigSetIndex]/DmaChannelConfiguration/*[@index=$ChannelIndex]"!][!//
  [!NOCODE!][!//
  [!// for checking (1) if the channel IDs have been duplicated in a Dma config set, (2) whether a hardware resource partition has been assigned different modes by different channels in same config set
  [!VAR "abc"="DmaChannelNumber"!]
  [!VAR "Hrp"="DmaChannelHwResourceConfig/DmaChannelHwResourcePartition"!]
  [!VAR "HrpMode"="DmaChannelHwResourceConfig/DmaHwResourceMode"!]

  [!FOR "ChannelIndexj" = "0" TO "(num:i($NoOfChannels)- 1)"!][!//
    [!VAR "xyz"="../*[@index=$ChannelIndexj]/DmaChannelNumber"!]
    [!VAR "Hrpj"="../*[@index=$ChannelIndexj]/DmaChannelHwResourceConfig/DmaChannelHwResourcePartition"!]
    [!VAR "HrpModej"="../*[@index=$ChannelIndexj]/DmaChannelHwResourceConfig/DmaHwResourceMode"!]
    [!ASSERT "not(($ChannelIndex != $ChannelIndexj) and ($abc = $xyz))"!][!//
      Config Error: Channel ID = [!"$abc"!] duplicated at indices [!"$ChannelIndex"!] and [!"$ChannelIndexj"!] for DmaConfigset_[!"$ConfigSetIndex"!]
    [!ENDASSERT!]
    [!ASSERT "not(($Hrp = $Hrpj) and ($HrpMode != $HrpModej))"!][!//
      Hardware partition config warning: mode clash between channels [!"$abc"!] and [!"$xyz"!] for hardware partition [!"$Hrp"!] for DmaConfigset_[!"$ConfigSetIndex"!]!
    [!ENDASSERT!]
  [!ENDFOR!][!//
  [!// macro for checking DMA resource clash in mcu.
  [!CALL "Compare_DmaChannels", "DmaCh" = "DmaChannelNumber", "ConfigSetIndex"="$ConfigSetIndex"!][!//

  [!VAR "ChannelID" = "DmaChannelNumber"!][!//
  [!VAR "DmaChannelConfig" = "num:i(0)"!][!//
  [!CALL "Dma_ChcfgrConfig", "DataWidth" = "DmaChannelWidth", "BlockMode"="DmaNoOfMoves", "HwMode"="DmaChannelHwMode", "Priority"="DmaBusPriority","PeripheralSelect"="DmaPeripheralRequest","PatternSelect"="DmaPatternSelection","DmaTransferReqState"="DmaTransferReqStateReset", "DmaChannelConfig"="$DmaChannelConfig"!][!//

  [!VAR "DmaAddrIntControl" = "num:i(0)"!][!//
  [!CALL "Dma_AdicrConfig", "DmaCh1" = "DmaChannelNumber", "ConfigSetIndex1"="$ConfigSetIndex","SrcModFactor" = "DmaSourceAddrMod", "SrcCirclBufferLen"="DmaSourceCircularLength", "IncrementSrcAddr"="DmaAddSubSrcAddr", "DestModFactor"="DmaDestinationAddrMod","DestCirclBufferLen"="DmaDestinationCircularLength","IncrementDestAddr"="DmaAddSubDstAddr","TxReqLostIntEn"="DmaTransactionReqLostEn","IntCtrl"="DmaInterruptControl","TcountThreshold"="DmaInterruptRaiseValue","WrpSrc"="DmaWrapSourceEn","WrpDest"="DmaWrapDestinationEn","ShadowCtrl"="DmaShadowControlConfig","SrcCirclBuffEn"="DmaSrcCircularBufEn","DestCirclBuffEn"="DmaDstCircularBufEn", "DmaAddrIntControl"="$DmaAddrIntControl"!][!//

  [!VAR "Partition" = "DmaChannelHwResourceConfig/DmaChannelHwResourcePartition"!][!//
  [!VAR "DmaHwResourcePartition" = "num:i(0)"!][!//
  [!IF "$Partition= 'HW_RESOURCE_PARTITION_1'"!][!//
    [!VAR "DmaHwResourcePartition" = "num:i(1)"!][!//
  [!ELSEIF "$Partition= 'HW_RESOURCE_PARTITION_2'"!][!//
    [!VAR "DmaHwResourcePartition" = "num:i(2)"!][!//
  [!ELSEIF "$Partition= 'HW_RESOURCE_PARTITION_3'"!][!//
    [!VAR "DmaHwResourcePartition" = "num:i(3)"!][!//
  [!ENDIF!][!//

  [!VAR "PartitionMode" = "DmaChannelHwResourceConfig/DmaHwResourceMode"!][!//
  [!VAR "DmaHwResourceMode" = "num:i(1)"!][!//
  [!IF "$PartitionMode= 'USER_MODE'"!][!//
    [!VAR "DmaHwResourceMode" = "num:i(0)"!][!//
  [!ENDIF!][!//

  [!ENDNOCODE!][!//
/* Configuration for DMA Channel([!"$ChannelID"!]) */
  [!"text:toupper(num:inttohex($DmaChannelConfig,8))"!]U, /* Configuration for DMA register CHCFGR */
  [!"text:toupper(num:inttohex($DmaAddrIntControl,8))"!]U, /* Configuration for DMA register ADICR */
  [!"text:toupper(num:inttohex($DmaHwResourceMode,2))"!]U,       /* Configuration for DMA register MODE */
  [!"text:toupper(num:inttohex($DmaHwResourcePartition,2))"!]U,       /* Configuration for DMA register HRR */
  [!"$ChannelID"!]U           /*DMA channel ID*/
[!ENDSELECT!][!//
[!AUTOSPACING!][!//
 }[!IF "$ChannelIndex != $NoOfChannels -1"!],
[!ENDIF!][!//
[!ENDFOR!][!//

};
[!ENDFOR!][!//

/*************************** DMA Config Root **********************************/

const Dma_ConfigType Dma_ConfigRoot[[!"num:i($NoOfConfigSets)"!]]=
{
[!FOR "ConfigSetIndex" = "0" TO "(num:i($NoOfConfigSets)- 1)"!][!//
[!VAR "NoOfChannels" = "num:i(count(DmaConfigSet/*[@index=$ConfigSetIndex]/DmaChannelConfiguration/*))"!][!//
/*************** Configuration for DmaConfigSet([!"$ConfigSetIndex"!]) ***************/
 {
[!SELECT "DmaConfigSet/*[@index=$ConfigSetIndex]/DmaMoveEngineConfiguration"!][!//
[!NOCODE!][!//

[!VAR "DmaPat0" = "num:i(0)"!][!//
[!CALL "Dma_Prr0Config", "PRR00" = "DmaPatternConfig/DmaPat00", "PRR01"="DmaPatternConfig/DmaPat01", "PRR02"="DmaPatternConfig/DmaPat02", "PRR03"="DmaPatternConfig/DmaPat03", "DmaPat0"="$DmaPat0"!][!//
[!VAR "DmaPat1" = "num:i(0)"!][!//
[!CALL "Dma_Prr1Config", "PRR10" = "DmaPatternConfig/DmaPat10", "PRR11"="DmaPatternConfig/DmaPat11", "PRR12"="DmaPatternConfig/DmaPat12", "PRR13"="DmaPatternConfig/DmaPat13", "DmaPat1"="$DmaPat1"!][!//
[!VAR "DmaMovEng0Err" = "num:i(0)"!][!//
[!CALL "Dma_ErrEn0Config", "SrcErr0" = "DmaErrorEnableConfiguration/DmaMovEng0SrcError", "DstErr0"="DmaErrorEnableConfiguration/DmaMovEng0DstError", "LLErr0"="DmaErrorEnableConfiguration/DmaMovEng0LinkListError", "RamErr0"="DmaErrorEnableConfiguration/DmaMovEng0RAMError", "DmaMovEng0Err"="$DmaMovEng0Err"!][!//
[!VAR "DmaMovEng1Err" = "num:i(0)"!][!//
[!CALL "Dma_ErrEn1Config", "SrcErr1" = "DmaErrorEnableConfiguration/DmaMovEng1SrcError", "DstErr1"="DmaErrorEnableConfiguration/DmaMovEng1DstError", "LLErr1"="DmaErrorEnableConfiguration/DmaMovEng1LinkListError", "RamErr1"="DmaErrorEnableConfiguration/DmaMovEng1RAMError", "DmaMovEng1Err"="$DmaMovEng1Err"!][!//

[!AUTOSPACING!]

[!ENDNOCODE!][!//
  &Dma_kChannelConfigRoot[!"$ConfigSetIndex"!][0U], /* Address of channel config root
                                  for DMA configuration [[!"$ConfigSetIndex"!]] */
  [!"text:toupper(num:inttohex($DmaPat0,8))"!]U, /* Configuration for DMA register PRR0 */
  [!"text:toupper(num:inttohex($DmaPat1,8))"!]U, /* Configuration for DMA register PRR1 */
  [!"text:toupper(num:inttohex($DmaMovEng0Err,8))"!]U, /* Configuration for DMA register ERR0 */
  [!"text:toupper(num:inttohex($DmaMovEng1Err,8))"!]U, /* Configuration for DMA register ERR1 */
  [!"$NoOfChannels"!]U           /*Number of channels configured*/
[!ENDSELECT!][!//
[!AUTOSPACING!][!//
 }[!IF "$ConfigSetIndex != $NoOfConfigSets -1"!],
[!ENDIF!][!//
[!ENDFOR!][!//

};
[!ENDSELECT!][!//

#define DMA_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
#include "MemMap.h"