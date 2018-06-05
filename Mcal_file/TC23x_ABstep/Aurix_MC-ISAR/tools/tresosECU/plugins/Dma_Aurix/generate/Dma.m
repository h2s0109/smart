[!/*
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
**  $FILENAME   : Dma.m $                                                    **
**                                                                           **
**  $CC VERSION : \main\15 $                                                 **
**                                                                           **
**  $DATE       : 2014-05-14 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                -Configuration Generator Macros                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
  TRACEBILITY : [cover parentID = DS_NAS_DMA_PR78][/cover]
*****************************************************************************/!]
[!//
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('DMA_M'))"!][!//
[!VAR "DMA_M"="'true'"!][!//


[!/*****************************************************************************
** Name             : Compare_DmaChannels                                     **
**                                                                            **
** Description      : Macro to check that whether in MCU Dma channels are     **
**                    configured to use for DMA complex driver                **
**                                                                            **
******************************************************************************/!]
[!/*
Compares the dma channel/s in MCU (allocated for DMA complex driver).
Raises an error if they don't match
McuDmaRef: reference to Mcu/McuModuleConfiguration/DmaConfiguration
DmaCh: Reference to Dma/DmaConfigSet/DmaChannelConfiguration/DmaChannelNumber
 */!]
[!MACRO "Compare_DmaChannels", "DmaCh" = "","ConfigSetIndex" = ""!]
[!NOCODE!]
[!SELECT "as:modconf('Dma')[1]"!][!//
[!VAR "McuDmaRef" = "(node:path(node:ref(DmaConfigSet/*[@index=$ConfigSetIndex]/DmaConfigReferencetoMcu/DmaReferenceValue)))"!][!//
[!// To extract the value of McuModuleConfiguration configuration
[!VAR "McuModConfigIndex0"="substring-after($McuDmaRef,'McuModuleConfiguration/')"!][!//
[!VAR "McuModConfigIndex"="substring-before($McuModConfigIndex0,'/DmaConfiguration')"!][!//
[!ENDSELECT!][!//

[!IF "node:ref($McuDmaRef)/DmaChannel/*[@index=$DmaCh]/ChannelUsed != 'USE_FOR_DMA_CDD'"!][!//
[!ERROR!]
In Mcu module configuration '[!"$McuModConfigIndex"!]', configure Dma channel number [!"$DmaCh"!] in DmaConfiguration container as USE_FOR_DMA_CDD. In Dma, this channel ID is located in DmaConfigSet index [!"$ConfigSetIndex"!]. [!//
[!ENDERROR!][!//
[!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Dma_Prr0Config                                          **
**                                                                            **
** Description      : Macro to calculate Value for PRR0 register from         **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Dma_Prr0Config", "PRR00" = "", "PRR01"="", "PRR02"="", "PRR03"="", "DmaPat0"=""!]
[!NOCODE!]

[!VAR "DmaPat0" = "bit:or($DmaPat0,bit:shl($PRR00,0))"!][!//
[!VAR "DmaPat0" = "bit:or($DmaPat0,bit:shl($PRR01,8))"!][!//
[!VAR "DmaPat0" = "bit:or($DmaPat0,bit:shl($PRR02,16))"!][!//
[!VAR "DmaPat0" = "bit:or($DmaPat0,bit:shl($PRR03,24))"!][!//

[!ENDNOCODE!]
[!ENDMACRO!]

[!/*****************************************************************************
** Name             : Dma_Prr1Config                                          **
**                                                                            **
** Description      : Macro to calculate Value for PRR1 register from         **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Dma_Prr1Config", "PRR10" = "", "PRR11"="", "PRR12"="", "PRR13"="", "DmaPat1"=""!]
[!NOCODE!]

[!VAR "DmaPat1" = "bit:or($DmaPat1,bit:shl($PRR10,0))"!][!//
[!VAR "DmaPat1" = "bit:or($DmaPat1,bit:shl($PRR11,8))"!][!//
[!VAR "DmaPat1" = "bit:or($DmaPat1,bit:shl($PRR12,16))"!][!//
[!VAR "DmaPat1" = "bit:or($DmaPat1,bit:shl($PRR13,24))"!][!//

[!ENDNOCODE!]
[!ENDMACRO!]


[!/*****************************************************************************
** Name             : Dma_ErrEn0Config                                        **
**                                                                            **
** Description      : Macro to calculate Value for EER0 register from         **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Dma_ErrEn0Config", "SrcErr0" = "", "DstErr0"="", "LLErr0"="", "RamErr0"="", "DmaMovEng0Err"=""!]
[!NOCODE!]

[!IF "$SrcErr0= 'TRUE'"!][!//
[!VAR "DmaMovEng0Err" = "bit:or($DmaMovEng0Err,bit:shl(1,16))"!][!//
[!ENDIF!][!//

[!IF "$DstErr0= 'TRUE'"!][!//
[!VAR "DmaMovEng0Err" = "bit:or($DmaMovEng0Err,bit:shl(1,17))"!][!//
[!ENDIF!][!//

[!IF "$RamErr0= 'TRUE'"!][!//
[!VAR "DmaMovEng0Err" = "bit:or($DmaMovEng0Err,bit:shl(1,24))"!][!//
[!ENDIF!][!//

[!IF "$LLErr0= 'TRUE'"!][!//
[!VAR "DmaMovEng0Err" = "bit:or($DmaMovEng0Err,bit:shl(1,26))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]

[!/*****************************************************************************
** Name             : Dma_ErrEn1Config                                        **
**                                                                            **
** Description      : Macro to calculate Value for EER1 register from         **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Dma_ErrEn1Config", "SrcErr1" = "", "DstErr1"="", "LLErr1"="", "RamErr1"="", "DmaMovEng1Err"=""!]
[!NOCODE!]

[!IF "$SrcErr1= 'TRUE'"!][!//
[!VAR "DmaMovEng1Err" = "bit:or($DmaMovEng1Err,bit:shl(1,16))"!][!//
[!ENDIF!][!//

[!IF "$DstErr1= 'TRUE'"!][!//
[!VAR "DmaMovEng1Err" = "bit:or($DmaMovEng1Err,bit:shl(1,17))"!][!//
[!ENDIF!][!//

[!IF "$RamErr1= 'TRUE'"!][!//
[!VAR "DmaMovEng1Err" = "bit:or($DmaMovEng1Err,bit:shl(1,24))"!][!//
[!ENDIF!][!//

[!IF "$LLErr1= 'TRUE'"!][!//
[!VAR "DmaMovEng1Err" = "bit:or($DmaMovEng1Err,bit:shl(1,26))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]



[!/*****************************************************************************
** Name             : Dma_ChcfgrConfig                                        **
**                                                                            **
** Description      : Macro to calculate Value for CHCFGR register from       **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Dma_ChcfgrConfig", "DataWidth" = "", "BlockMode"="", "HwMode"="", "Priority"="","PeripheralSelect"="","PatternSelect"="","DmaTransferReqState"="","DmaChannelConfig"=""!][!//
[!NOCODE!]
[!IF "$DataWidth= 'WIDTH_16BITS'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,21))"!][!//
[!ELSEIF "$DataWidth= 'WIDTH_32BITS'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(2,21))"!][!//
[!ELSEIF "$DataWidth= 'WIDTH_64BITS'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(3,21))"!][!//
[!ELSEIF "$DataWidth= 'WIDTH_128BITS'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(4,21))"!][!//
[!ELSEIF "$DataWidth= 'WIDTH_256BITS'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(5,21))"!][!//
[!ENDIF!][!//

[!IF "$BlockMode= 'MOVES_2'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,16))"!][!//
[!ELSEIF "$BlockMode= 'MOVES_4'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(2,16))"!][!//
[!ELSEIF "$BlockMode= 'MOVES_8'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(3,16))"!][!//
[!ELSEIF "$BlockMode= 'MOVES_16'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(4,16))"!][!//
[!ELSEIF "$BlockMode= 'MOVES_3'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(5,16))"!][!//
[!ELSEIF "$BlockMode= 'MOVES_5'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(6,16))"!][!//
[!ELSEIF "$BlockMode= 'MOVES_9'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(7,16))"!][!//
[!ENDIF!][!//

[!IF "$HwMode= 'HARDWARE_CONTINOUS_MODE'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,20))"!][!//
[!ENDIF!][!//

[!IF "$Priority= 'MEDIUM'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,30))"!][!//
[!ELSEIF "$Priority= 'HIGH'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(3,30))"!][!//
[!ENDIF!][!//

[!IF "$PeripheralSelect= 'DAISY_CHAIN_SELECT'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,28))"!][!//
[!ENDIF!][!//

[!IF "(($PatternSelect= 'DISABLED') or(($DataWidth = 'WIDTH_8BITS') and ($PatternSelect = 'PAT00_PAT02_8BIT' or $PatternSelect = 'PAT01_PAT03_8BIT' or $PatternSelect = 'PAT00_PAT02_N_PAT01_PAT03_8BIT' or $PatternSelect = 'PAT10_PAT12_8BIT' or $PatternSelect = 'PAT11_PAT13_8BIT' or $PatternSelect = 'PAT10_PAT12_N_PAT11_PAT13_8BIT'))
or (($DataWidth = 'WIDTH_16BITS') and ($PatternSelect = 'ALIGNED_MODE_PAT0_16BIT' or $PatternSelect = 'UNALIGNED_MODE_PAT0_16BIT' or $PatternSelect = 'COMBINED_MODE_PAT0_16BIT' or $PatternSelect = 'ALIGNED_MODE_PAT1_16BIT' or $PatternSelect = 'UNALIGNED_MODE_PAT1_16BIT' or $PatternSelect = 'COMBINED_MODE_PAT1_16BIT'))
or (($DataWidth = 'WIDTH_32BITS') and ($PatternSelect = 'RD0_10_PAT0_10_32BIT' or $PatternSelect = 'RD0_32_PAT0_32_32BIT' or $PatternSelect = 'RD0_30_PAT0_30_32BIT' or $PatternSelect = 'RD0_10_PAT1_10_32BIT' or $PatternSelect = 'RD0_32_PAT1_32_32BIT' or $PatternSelect = 'RD0_30_PAT1_30_32BIT')))"!][!//

  [!IF "$PatternSelect= 'PAT00_PAT02_8BIT' or $PatternSelect = 'ALIGNED_MODE_PAT0_16BIT' or $PatternSelect= 'RD0_10_PAT0_10_32BIT'"!][!//
    [!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,24))"!][!//
  [!ELSEIF "$PatternSelect= 'PAT01_PAT03_8BIT' or $PatternSelect = 'UNALIGNED_MODE_PAT0_16BIT' or $PatternSelect= 'RD0_32_PAT0_32_32BIT'"!][!//
    [!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(2,24))"!][!//
  [!ELSEIF "$PatternSelect= 'PAT00_PAT02_N_PAT01_PAT03_8BIT' or $PatternSelect = 'COMBINED_MODE_PAT0_16BIT' or $PatternSelect= 'RD0_30_PAT0_30_32BIT'"!][!//
    [!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(3,24))"!][!//
  [!ELSEIF "$PatternSelect= 'PAT10_PAT12_8BIT' or $PatternSelect = 'ALIGNED_MODE_PAT1_16BIT' or $PatternSelect= 'RD0_10_PAT1_10_32BIT'"!][!//
    [!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(5,24))"!][!//
  [!ELSEIF "$PatternSelect= 'PAT11_PAT13_8BIT' or $PatternSelect = 'UNALIGNED_MODE_PAT1_16BIT' or $PatternSelect= 'RD0_32_PAT1_32_32BIT'"!][!//
    [!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(6,24))"!][!//
  [!ELSEIF "$PatternSelect= 'PAT10_PAT12_N_PAT11_PAT13_8BIT' or $PatternSelect = 'COMBINED_MODE_PAT1_16BIT' or $PatternSelect= 'RD0_30_PAT1_30_32BIT'"!][!//
    [!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(7,24))"!][!//
  [!ENDIF!][!//
[!ELSE!][!//
  [!ERROR!]
  Pattern Selection Error: Mismatch found between Channel data width and type of Pattern selection chosen. Cuurently pattern selection value [!"$PatternSelect"!] is chosen for data width [!"substring-after($DataWidth,'WIDTH_')"!][!//
  [!ENDERROR!][!//
[!ENDIF!][!//

[!IF "$DmaTransferReqState= 'RESET_ONLY_AFTER_TRANSACTION'"!][!//
[!VAR "DmaChannelConfig" = "bit:or($DmaChannelConfig,bit:shl(1,19))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]

[!/*****************************************************************************
** Name             : Dma_AdicrConfig                                         **
**                                                                            **
** Description      : Macro to calculate Value for ADICR register from        **
**                    Configuration                                           **
**                                                                            **
******************************************************************************/!]
[!MACRO "Dma_AdicrConfig", "DmaCh1" = "","ConfigSetIndex1" = "","SrcModFactor" = "", "SrcCirclBufferLen"="", "IncrementSrcAddr"="", "DestModFactor"="","DestCirclBufferLen"="","IncrementDestAddr"="","TxReqLostIntEn"="","IntCtrl"="","TcountThreshold"="","WrpSrc"="","WrpDest"="","ShadowCtrl"="","SrcCirclBuffEn"="","DestCirclBuffEn"="", "DmaAddrIntControl"=""!][!//
[!NOCODE!]

[!IF "$SrcModFactor= 'FACTOR_2'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,0))"!][!//
[!ELSEIF "$SrcModFactor= 'FACTOR_4'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(2,0))"!][!//
[!ELSEIF "$SrcModFactor= 'FACTOR_8'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(3,0))"!][!//
[!ELSEIF "$SrcModFactor= 'FACTOR_16'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(4,0))"!][!//
[!ELSEIF "$SrcModFactor= 'FACTOR_32'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(5,0))"!][!//
[!ELSEIF "$SrcModFactor= 'FACTOR_64'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(6,0))"!][!//
[!ELSEIF "$SrcModFactor= 'FACTOR_128'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(7,0))"!][!//
[!ENDIF!][!//

[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl($SrcCirclBufferLen,8))"!][!//

[!IF "$IncrementSrcAddr= 'INCREMENT_SRC_ADDR'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,3))"!][!//
[!ENDIF!][!//

[!IF "$DestModFactor= 'FACTOR_2'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,4))"!][!//
[!ELSEIF "$DestModFactor= 'FACTOR_4'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(2,4))"!][!//
[!ELSEIF "$DestModFactor= 'FACTOR_8'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(3,4))"!][!//
[!ELSEIF "$DestModFactor= 'FACTOR_16'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(4,4))"!][!//
[!ELSEIF "$DestModFactor= 'FACTOR_32'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(5,4))"!][!//
[!ELSEIF "$DestModFactor= 'FACTOR_64'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(6,4))"!][!//
[!ELSEIF "$DestModFactor= 'FACTOR_128'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(7,4))"!][!//
[!ENDIF!][!//

[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl($DestCirclBufferLen,12))"!][!//

[!IF "$IncrementDestAddr= 'INCREMENT_DEST_ADDR'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,7))"!][!//
[!ENDIF!][!//

[!IF "$TxReqLostIntEn= 'ENABLE'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,23))"!][!//
[!ENDIF!][!//

[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl($TcountThreshold,28))"!][!//

[!IF "$IntCtrl= 'INT_DISABLED_TCOUNT_DECREMENT'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,26))"!][!//
[!ELSEIF "$IntCtrl= 'INT_ENABLED_TCOUNT_IRDV'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(2,26))"!][!//
[!ELSEIF "$IntCtrl= 'INT_ENABLED_TCOUNT_DECREMENT'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(3,26))"!][!//
[!ENDIF!][!//

[!IF "$WrpSrc= 'ENABLE'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,24))"!][!//
[!ENDIF!][!//

[!IF "$WrpDest= 'ENABLE'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,25))"!][!//
[!ENDIF!][!//

[!IF "$ShadowCtrl= 'SOURCE_ADDRESS_BUFF_RD'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'DESTINATION_ADDRESS_BUFF_RD'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(2,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'SOURCE_ADDRESS_BUFF_WR'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(5,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'DESTINATION_ADDRESS_BUFF_WR'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(6,16))"!][!//
[!ENDIF!][!//

[!IF "(../../../../DmaGeneralConfiguration/DmaDoubleBufferEnable = 'false') and ($ShadowCtrl= 'DOUBLE_SOURCE_BUFF_SW' or $ShadowCtrl= 'DOUBLE_SOURCE_BUFF_AUTO' or $ShadowCtrl= 'DOUBLE_DESTINATION_BUFF_SW' or $ShadowCtrl= 'DOUBLE_DESTINATION_BUFF_AUTO')"!][!//
[!WARNING!]
Shadow register config warning: Enable double buffering mode in DmaGeneralConfiguration container first if you wish to use Dma channel [!"$DmaCh1"!] in DmaConfigSet_[!"$ConfigSetIndex1"!] for [!"$ShadowCtrl"!] operation!
[!ENDWARNING!]
[!ELSE!][!//
[!IF "$ShadowCtrl= 'DOUBLE_SOURCE_BUFF_SW'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(8,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'DOUBLE_SOURCE_BUFF_AUTO'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(9,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'DOUBLE_DESTINATION_BUFF_SW'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(10,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'DOUBLE_DESTINATION_BUFF_AUTO'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(11,16))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "(../../../../DmaGeneralConfiguration/DmaLinkedListEnable = 'false') and ($ShadowCtrl= 'LINKED_LIST' or $ShadowCtrl= 'ACCUMULATED_LINKED_LIST' or $ShadowCtrl= 'SAFE_LINKED_LIST' or $ShadowCtrl= 'CONDITIONAL_LINKED_LIST')"!][!//
[!WARNING!]
Shadow register config warning: Enable Linked list mode in DmaGeneralConfiguration container first if you wish to use Dma channel [!"$DmaCh1"!] in DmaConfigSet_[!"$ConfigSetIndex1"!] for [!"$ShadowCtrl"!] operation!
[!ENDWARNING!]
[!ELSE!][!//
[!IF "$ShadowCtrl= 'LINKED_LIST'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(12,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'ACCUMULATED_LINKED_LIST'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(13,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'SAFE_LINKED_LIST'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(14,16))"!][!//
[!ELSEIF "$ShadowCtrl= 'CONDITIONAL_LINKED_LIST'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(15,16))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$SrcCirclBuffEn= 'ENABLE'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,20))"!][!//
[!ENDIF!][!//

[!IF "$DestCirclBuffEn= 'ENABLE'"!][!//
[!VAR "DmaAddrIntControl" = "bit:or($DmaAddrIntControl,bit:shl(1,21))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!]
[!ENDMACRO!]

[!ENDIF!][!// IF "not(var:defined('DMA_M'))
