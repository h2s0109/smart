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
**  $FILENAME   : Eth_17_EthMac_PBCfg.c $                                    **
**                                                                           **
**  $CC VERSION : \main\29 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-22 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Eth_17_EthMac_PBCfg.h file               **
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
**  FILENAME  : Eth_17_EthMac_PBCfg.c                                        **
**                                                                           **
**  $CC VERSION : \main\29 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : Eth configuration generated out of ECU configuration      **
**                 file(Eth_17_EthMac.bmd/.xdm)                              **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**  Traceability   :                                                          **
**  [cover parentID= DS_NAS_ETH_PR69_PR469,DS_NAS_ETH_PR709,DS_NAS_ETH_PR446,
     SAS_NAS_ETH_PR914,SAS_NAS_ETH_PR915,SAS_NAS_ETH_PR916,SAS_NAS_ETH_PR82,
     DS_NAS_ETH_PR704,DS_NAS_ETH_PR707,DS_NAS_ETH_PR708,
     DS_NAS_ETH_PR712]
     [/cover]                                                                **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include ETH Module File */
#include "Eth_17_EthMac.h"
    
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!AUTOSPACING!]
[!SELECT "as:modconf('Eth')[1]"!][!//

/*
                     Container: EthConfigset
*/
#define ETH_17_ETHMAC_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
[!VAR "TotalConfig" = "num:i(count(EthConfigSet/*))"!][!//
[!FOR "ConfigId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//  
[!SELECT "EthConfigSet/*[num:i($ConfigId)]"!][!//

static const Eth_CtrlConfigType  Eth_CtrlConfig[!"string($ConfigId - num:i(1))"!][] =
{
[!VAR "MaxControllers"= "num:i(count(EthCtrlConfig/*))"!][!// 
[!FOR "ControllerId" = "num:i(1)" TO "num:i($MaxControllers)"!][!//
[!SELECT "EthCtrlConfig/*[num:i($ControllerId)]"!][!//  
[!NOCODE!][!//
[!VAR "EthCtrlRxBufLenBytevalue" = "./EthCtrlRxBufLenByte"!][!//
[!VAR "EthCtrlTxBufLenBytevalue" = "./EthCtrlTxBufLenByte"!][!//
[!VAR "EthRxBufTotalvalue" = "./EthRxBufTotal"!][!//
[!VAR "EthTxBufTotalvalue" = "./EthTxBufTotal"!][!//
[!VAR "EthDmaIdleTransitWaitTime" = "./EthDmaIdleTransitionWaitTime"!][!//
[!ENDNOCODE!][!//
  /* Eth Controller [!"string($ControllerId - num:i(1))"!] */
  {
    (uint16)[!"$EthCtrlRxBufLenBytevalue"!],  /*Receive Buffer Length*/
    (uint16)[!"$EthCtrlTxBufLenBytevalue"!],  /*Transmit Buffer Length*/
    (uint16)[!"$EthDmaIdleTransitWaitTime"!], /*ETH,DMA Idle tranition timeout*/
    /*DEM Id for Ethernet controller hardware test failure*/
    [!IF "(node:exists(./EthDemEventParameterRefs/*[1]/ETH_E_ACCESS/*[1]) = 'true') and (node:value(./EthDemEventParameterRefs/*[1]/ETH_E_ACCESS/*[1]) != ' ' )"!][!//     
    DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./EthDemEventParameterRefs/*[1]/ETH_E_ACCESS/*[1])))"!],
    [!ELSE!][!//
    ETH_17_DISABLE_DEM_REPORT,
    [!ENDIF!][!//    
    /*DEM Id for Ethernet controller hardware timeout failure*/
    [!IF "(node:exists(./EthDemEventParameterRefs/*[1]/ETH_E_TIMEOUT/*[1]) = 'true') and (node:value(./EthDemEventParameterRefs/*[1]/ETH_E_TIMEOUT/*[1]) != ' ' )"!][!//     
    DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./EthDemEventParameterRefs/*[1]/ETH_E_TIMEOUT/*[1])))"!],
    [!ELSE!][!//
    ETH_17_DISABLE_DEM_REPORT,
    [!ENDIF!][!//    
    /*DEM Id for Ethernet controller Frame Sequence Error */
    [!IF "(node:exists(./EthDemEventParameterRefs/*[1]/ETH_E_FRAMESEQ/*[1]) = 'true') and (node:value(./EthDemEventParameterRefs/*[1]/ETH_E_FRAMESEQ/*[1]) != ' ' )"!][!//     
    DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./EthDemEventParameterRefs/*[1]/ETH_E_FRAMESEQ/*[1])))"!],
    [!ELSE!][!//
    ETH_17_DISABLE_DEM_REPORT,
    [!ENDIF!][!//    
    (uint8)[!"$EthRxBufTotalvalue"!],         /*Total Receive Buffer*/
    (uint8)[!"$EthTxBufTotalvalue"!],         /*Total Transmit Buffer*/
  }
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!][!//


const Eth_17_EthMac_ConfigType Eth_ConfigRoot[] =
{
[!FOR "ModuleId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//  
[!SELECT "EthConfigSet/*[num:i($ModuleId)]"!][!//

  {
    /*Pointer to Ethernet PostBuild configuration set[!"string($ModuleId - num:i(1))"!]*/
    &Eth_CtrlConfig[!"string($ModuleId - num:i(1))"!][0]
  }[!//
[!IF "$ModuleId != $TotalConfig"!],[!ENDIF!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

};

#define ETH_17_ETHMAC_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

