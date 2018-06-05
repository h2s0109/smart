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
**  $FILENAME   : Eth_17_EthMac_Cfg.h $                                      **
**                                                                           **
**  $CC VERSION : \main\41 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Eth_17_EthMac_Cfg.h file                 **
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
**  FILENAME  : Eth_17_EthMac_Cfg.h                                          **
**                                                                           **
**  $CC VERSION : \main\41 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : ETH configuration generated out of ECU configuration      **
**                 file(Eth_17_EthMac.bmd/.xdm)                              **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**  Traceability   :                                                          **
**  [cover parentID= SAS_NAS_ETH_PR914,SAS_NAS_ETH_PR915,
    SAS_NAS_ETH_PR916,SAS_NAS_ETH_PR82,DS_NAS_HE2_ETH_PR3054_1,
    DS_NAS_HE2_ETH_PR3054_2,DS_NAS_HE2_ETH_PR3054_4,DS_NAS_EP_ETH_PR3054_1,
    DS_NAS_EP_ETH_PR3054_2,DS_NAS_EP_ETH_PR3054_4] [/cover]                 **
*******************************************************************************/


#ifndef ETH_17_ETHMAC_CFG_H
#define ETH_17_ETHMAC_CFG_H
  

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!AUTOSPACING!]
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
#define ETH_17_AR_RELEASE_MAJOR_VERSION      ([!"$MajorVersion"!]U)
#define ETH_17_AR_RELEASE_MINOR_VERSION      ([!"$MinorVersion"!]U)
#define ETH_17_AR_RELEASE_REVISION_VERSION   ([!"$RevisionVersion"!]U)

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define ETH_17_ETHMAC_SW_MAJOR_VERSION              ([!"$SwMajorVersion"!]U)
#define ETH_17_ETHMAC_SW_MINOR_VERSION              ([!"$SwMinorVersion"!]U)
#define ETH_17_ETHMAC_SW_PATCH_VERSION              ([!"$SwPatchVersion"!]U)
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Eth')[1]"!][!//
[!//

/*
         Container : EthGeneralConfiguration
*/

/*
Configuration: ETH_17_DEV_ERROR_DETECT 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled
   This parameter shall activate or 
deactivate the detection of all development errors. 
*/
#define ETH_17_DEV_ERROR_DETECT  ([!//
[!IF "EthGeneral/EthDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_17_PB_FIXEDADDR
   This parameter enables the user to fix the PB config pointer to first 
   instance of configuration
*/
/* [cover parentID= DS_NAS_ETH_PR915] [/cover] */
#define ETH_17_PB_FIXEDADDR  ([!//
[!IF "EthGeneral/EthPBFixedAddress  = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_17_DEBUG_SUPPORT
Preprocessor switch to enable/disable the Debug Support
- if STD_ON, Debug Support Enabled 
- if STD_OFF, Debug Support Disabled 
*/
#define ETH_17_DEBUG_SUPPORT  ([!//
[!IF "EthGeneral/EthDebugSupport    = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_17_VERSION_INFO_API 
- if STD_ON, Function Eth_17_GetVersionInfo is available  
- if STD_OFF,Function Eth_17_GetVersionInfo is not available 
*/
#define ETH_17_VERSION_INFO_API  ([!//
[!IF "EthGeneral/EthVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, user0 mode is enabled.
- if STD_OFF, user1 mode is enbled.
*/
#define ETH_RUNNING_IN_USER_0_MODE_ENABLE  ([!//
[!IF "EthGeneral/EthRunningInUser0Mode = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!IF "EthGeneral/EthRunningInUser0Mode = 'true'"!]
[!ASSERT "EthGeneral/EthUserModeRuntimeApiEnable = 'true' or EthGeneral/EthUserModeInitApiEnable = 'true'"!]
 Config Errror: Inorder to configure EthRunningInUser0Mode as true, either or both of the parameters  EthUserModeRuntimeApiEnable,
 EthUserModeInitApiEnable should be configured as true.
[!ENDASSERT!]
[!ENDIF!]

/*
Configuration: ETH_USER_MODE_RUNTIME_API_ENABLE

*/
#define ETH_USER_MODE_RUNTIME_API_ENABLE  ([!//
[!IF "EthGeneral/EthUserModeRuntimeApiEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_USER_MODE_INIT_API_ENABLE

*/
#define ETH_USER_MODE_INIT_API_ENABLE  ([!//
[!IF "EthGeneral/EthUserModeInitApiEnable = 'true'"!] [!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* [cover parentID= DS_AS4XX_ETH_PR2849] [/cover] */
[!VAR "TotalConfig" = "num:i(count(EthConfigSet/*))"!][!//
[!FOR "ConfigId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//  
[!SELECT "EthConfigSet/*[num:i($ConfigId)]/EthCtrlConfig/*[num:i(1)]"!][!//  

#ifndef Eth_17_EthMacConf_EthCtrlConfig_[!"node:name(.)"!]
/* Index of the Controller in use */
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 characters
 to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 characters
 to follow Autosar naming conventions*/
#define Eth_17_EthMacConf_EthCtrlConfig_[!"node:name(.)"!] ([!//
[!"num:i(node:value(./EthCtrlIdx))"!]U)
#endif
[!ENDSELECT!][!//
[!ENDFOR!][!//

/* Total no. of config sets */
#define ETH_17_ETHMAC_CONFIG_COUNT  ([!"num:i(count(EthConfigSet/*))"!]U)

/*
Configuration: ETH_17_INDEX 
- Ethernet Driver Instance ID, used in DET_Report(.,.) Interface.
*/
#define ETH_17_INDEX ([!//
[!"num:i(node:value(EthGeneral/EthIndex))"!]U)

[!VAR "TotalConfig" = "num:i(count(EthConfigSet/*))"!][!//
[!VAR "EthAccessDemReport" = "num:i(0)"!][!//
[!VAR "EthtimeoutDemReport" = "num:i(0)"!][!//
[!VAR "EthSeqErrDemReport" = "num:i(0)"!][!//
[!FOR "ConfigId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//  
[!SELECT "EthConfigSet/*[num:i($ConfigId)]/EthCtrlConfig/*[num:i(1)]"!][!//  
[!IF "(node:exists(./EthDemEventParameterRefs/*[1]/ETH_E_ACCESS/*[1]) = 'true') and (node:value(./EthDemEventParameterRefs/*[1]/ETH_E_ACCESS/*[1]) != '' )"!][!//
[!VAR "EthAccessDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "(node:exists(./EthDemEventParameterRefs/*[1]/ETH_E_TIMEOUT/*[1]) = 'true') and (node:value(./EthDemEventParameterRefs/*[1]/ETH_E_TIMEOUT/*[1]) != '' )"!][!//
[!VAR "EthtimeoutDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "(node:exists(./EthDemEventParameterRefs/*[1]/ETH_E_FRAMESEQ/*[1]) = 'true') and (node:value(./EthDemEventParameterRefs/*[1]/ETH_E_FRAMESEQ/*[1]) != '' )"!][!//
[!VAR "EthSeqErrDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
/*
 DEM for Hardware Access error ETH_E_ACCESS
*/
[!IF "$EthAccessDemReport = num:i(1)"!][!//
#define ETH_17_E_ACCESS_DEM_REPORT     (ETH_17_ENABLE_DEM_REPORT)
[!ELSE!][!//
#define ETH_17_E_ACCESS_DEM_REPORT     (ETH_17_DISABLE_DEM_REPORT)
[!ENDIF!][!//

/*
 DEM for Timeout error ETH_E_TIMEOUT
*/
[!IF "$EthtimeoutDemReport = num:i(1)"!][!//
#define ETH_17_E_TIMEOUT_DEM_REPORT    (ETH_17_ENABLE_DEM_REPORT)
[!ELSE!][!//
#define ETH_17_E_TIMEOUT_DEM_REPORT    (ETH_17_DISABLE_DEM_REPORT)
[!ENDIF!][!//

/*
 DEM for Sequence Error ETH_E_FRAMESEQ
*/
[!IF "$EthSeqErrDemReport = num:i(1)"!][!//
#define ETH_17_E_FRAMESEQ_DEM_REPORT   (ETH_17_ENABLE_DEM_REPORT)
[!ELSE!][!//
#define ETH_17_E_FRAMESEQ_DEM_REPORT   (ETH_17_DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!SELECT "EthConfigSet/*[num:i(1)]/EthCtrlConfig/*[num:i(1)]"!][!//
/*
Configuration: ETH_17_ENA_MII_API 
- if STD_ON, Functions Eth_17_WriteMii,Eth_17_ReadMii are available  
- if STD_OFF,Functions Eth_17_WriteMii,Eth_17_ReadMii are not available 
*/
#define ETH_17_ENA_MII_API  ([!//
[!IF "./EthCtrlEnableMii = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_17_ENA_RX_INT 
- STD_ON if EthCtrlEnableRxInterrupt is Enabled  
- STD_OFF if EthCtrlEnableRxInterrupt is Disabled 
*/
#define ETH_17_ENA_RX_INT  ([!//
[!IF "./EthCtrlEnableRxInterrupt = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_17_ENA_TX_INT 
- STD_ON if EthCtrlEnableTxInterrupt is Enabled  
- STD_OFF if EthCtrlEnableTxInterrupt is Disabled
*/
#define ETH_17_ENA_TX_INT  ([!//
[!IF "./EthCtrlEnableTxInterrupt = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


[!ENDSELECT!][!//

/*
Configuration: ETH_17_SPEED 
Parameter selects the speed of the Ethernet Interface 
if 0 then 10MBPS
if 1 then 100MBPS
*/
#define ETH_17_SPEED  ([!//
[!IF "EthGeneral/EthSpeed = 'ETH_100MBPS'"!][!//
[!ASSERT "EthGeneral/EthOpMode != 'HALFDUPLEX'", "Half Duplex mode Supports only 10 MBPS Speed"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
)

/*
Configuration: ETH_17_PHY_INTERFACE 
Parameter selects the type of PHY Interface 
RMII Mode - 0x01000000
[!IF "ecu:get('Eth.MIIAvailable') = 'TRUE'"!][!//
MII  Mode - 0x00000000
[!ENDIF!][!//
*/
[!ASSERT "(((EthGeneral/EthPhyInterface) = 'RMII') or (ecu:get('Eth.MIIAvailable') = 'TRUE'))"!][!//
Config Error in EthPhyInterface: MII mode is unavailable. Select RMII.
[!ENDASSERT!][!//

#define ETH_17_PHY_INTERFACE  [!//
 [!IF "EthGeneral/EthPhyInterface = 'RMII'"!][!//
 (0x01000000U) /* RMII MODE */[!// 
 [!ELSE!][!//
 (0x00000000U) /* MII MODE */ [!// 
 [!ENDIF!][!//

/* Maximum timeout count for hardware timeout errors*/
#define ETH_17_MAXTIMEOUT_COUNT  ([!//
[!"num:i(node:value(EthGeneral/EthTimeoutCount))"!][!//
U)

/* Contains the lower 16 bits of the MAC address.*/
 [!VAR "HighMac" = "num:i(node:value(EthGeneral/EthMacAddressLower32bits ))"!][!//
 [!VAR "MaskValue1" = "bit:shl((bit:and(num:i(255),num:i($HighMac))),8)"!][!//
 [!VAR "MaskValue2" = "bit:shr((bit:and(num:i(65280),num:i($HighMac))),8)"!][!//
 [!VAR "HighMac" = "(bit:or(num:i($MaskValue1),num:i($MaskValue2)))"!][!//
#define ETH_17_DEFAULT_MACADDRESS_HIGH  ([!"num:inttohex($HighMac,8)"!]U)

/*Contains the upper 32 bits of the MAC address.*/
 [!VAR "HighMac" = "num:i(node:value(EthGeneral/EthMacAddressLower32bits ))"!][!//
 [!VAR "MaskValue1" = "bit:and(bit:shr($HighMac,16),255)"!][!//
 [!VAR "LowMac" = "bit:shl($MaskValue1,24)"!][!//
 [!VAR "MaskValue1" = "bit:shl(bit:and(bit:shr($HighMac,24),255),16)"!][!//
 [!VAR "LowMac" = "bit:or($LowMac,$MaskValue1)"!][!//
 [!VAR "HighMac" = "num:i(node:value(EthGeneral/EthMacAddressUpper16bits ))"!][!//
 [!VAR "MaskValue1" = "bit:shl(bit:and($HighMac,255),8)"!][!//
 [!VAR "LowMac" = "bit:or($LowMac,$MaskValue1)"!][!//
 [!VAR "LowMac" = "bit:or($LowMac,bit:and(bit:shr($HighMac,8),255))"!][!//
#define ETH_17_DEFAULT_MACADDRESS_LOW  ([!"num:inttohex($LowMac,8)"!]U)

/*
Configuration: ETH_17_OPMODE 
Parameter selects the speed of the Ethernet Interface 
if 1 then FULLDUPLEX
if 0 then HALFDUPLEX
*/
#define ETH_17_OPMODE  ([!//
[!IF "EthGeneral/EthOpMode = 'FULLDUPLEX'"!][!//
1U[!//
[!ELSE!][!//
0U[!//
[!ENDIF!][!//
)

#define ETH_17_MDIO_ALTINPUT  [!//
[!IF "EthGeneral/EthMdioAlternateInput = 'SELECT_P00_0'"!][!//
(0x00000000U)/* Port0 and Pin0 selected */[!// 
[!ELSEIF "EthGeneral/EthMdioAlternateInput = 'SELECT_P21_1'"!][!//
(0x00000001U)/* Port21 and Pin1 selected */[!// 
[!ELSEIF "EthGeneral/EthMdioAlternateInput = 'SELECT_P12_1'"!][!//
(0x00000002U)/* Port12 and Pin1 selected */[!//
[!ELSEIF "EthGeneral/EthMdioAlternateInput = 'SELECT_P21_3'"!][!//
(0x00000003U)/* Port21 and Pin3 selected */[!//
[!ELSE!]
#error incorrect configuration for ETH_17_MDIO_ALTINPUT
[!ENDIF!][!//

#define ETH_17_REFCLK_ALTINPUT  [!//
[!IF "EthGeneral/EthRclkAlternateInput = 'SELECT_P11_12'"!][!//
(0x00000000U) /* Port11 and Pin12 selected */[!//
[!ELSEIF "EthGeneral/EthRclkAlternateInput = 'SELECT_P11_4'"!][!//
(0x00000004U) /* Port11 and Pin4 selected */ [!// 
[!ELSEIF "EthGeneral/EthRclkAlternateInput = 'SELECT_P12_0'"!][!//
(0x00000008U)/* Port12 and Pin0 selected */[!//	
[!ELSE!]
#error incorrect configuration for ETH_17_REFCLK_ALTINPUT
[!ENDIF!][!//


#define ETH_17_RXER_ALTINPUT  [!//
[!IF "EthGeneral/EthRxErrAlternateInput = 'SELECT_P11_13'"!][!//
(0x00000000U) /* Port11 and Pin13 selected */[!//
[!ELSEIF "EthGeneral/EthRxErrAlternateInput = 'SELECT_P21_7'"!][!//
(0x00000400U) /* Port21 and Pin7 selected */ [!// 
[!ELSEIF "EthGeneral/EthRxErrAlternateInput = 'SELECT_P10_3'"!][!//
(0x00000800U) /* Port10 and Pin3 selected */ [!// 
[!ELSE!]
#error incorrect configuration for ETH_17_RXER_ALTINPUT
[!ENDIF!][!//
[!VAR "EthRelDerivate" = "ecu:get('Rel.Derivate') "!][!//
[!IF "(EthGeneral/EthPhyInterface = 'MII') and (($EthRelDerivate = '_TRICORE_TC234') or ($EthRelDerivate = '_TRICORE_TC237'))"!][!//
#define ETH_17_CRS_ALTINPUT  (0x00000020U) /* Port10 and Pin1 selected */
#define ETH_17_COL_ALTINPUT  (0x00000040U) /* Port10 and Pin2 selected */
#define ETH_17_RXD3_ALTINPUT  (0x00040000U) /* Port10 and Pin5 selected */
#define ETH_17_TXCLK_ALTINPUT  (0x00200000U) /* Port13 and Pin1 selected */
[!ELSE!][!//
/* In RMII, signal unused, In MII mode of TC27x and 
   TC29x port11 and pin14 selected*/
#define ETH_17_CRS_ALTINPUT   (0x00000000U)
/* In RMII, signal unused, In MII mode of TC27x and 
   TC29x port11 and pin15 selected*/
#define ETH_17_COL_ALTINPUT   (0x00000000U) 
/* In RMII, signal unused, In MII mode of TC27x and 
TC29x port11 and pin7 selected*/
#define ETH_17_RXD3_ALTINPUT  (0x00000000U) 
/* In RMII, signal unused, In MII mode of TC27x and 
   TC29x port11 and pin5 selected*/
#define ETH_17_TXCLK_ALTINPUT (0x00000000U) 
[!ENDIF!][!//
#define ETH_17_GPCTL_CONFIG  (ETH_17_PHY_INTERFACE  | ETH_17_RXER_ALTINPUT |\
                              ETH_17_REFCLK_ALTINPUT| ETH_17_MDIO_ALTINPUT|\
                              ETH_17_CRS_ALTINPUT   | ETH_17_COL_ALTINPUT|\
                              ETH_17_RXD3_ALTINPUT  | ETH_17_TXCLK_ALTINPUT)

[!VAR "TotalConfig" = "num:i(count(EthConfigSet/*))"!][!//
[!VAR "TxBuffer"= "num:i(0)"!][!//
[!VAR "RxBuffer"= "num:i(0)"!][!//
[!FOR "ConfigId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "EthConfigSet/*[num:i($ConfigId)]"!][!//
[!VAR "MaxControllers"= "num:i(count(EthCtrlConfig/*))"!][!// 
[!FOR "ControllerId" = "num:i(1)" TO "num:i($MaxControllers)"!][!//
[!SELECT "EthCtrlConfig/*[num:i($ControllerId)]"!][!//	
[!NOCODE!][!//
[!ASSERT "(./EthCtrlRxBufLenByte) mod 4 = 0"!][!//
Config Error in EthCtrlRxBufLenByte: The buffer length should be a multiple of 4.
[!ENDASSERT!][!//
[!ASSERT "(./EthCtrlTxBufLenByte) mod 4 = 0"!][!//
Config Error in EthCtrlTxBufLenByte: The buffer length should be a multiple of 4.
[!ENDASSERT!][!//

[!VAR "EthCtrlRxBufLenBytevalue" = "./EthCtrlRxBufLenByte"!][!//
[!VAR "EthCtrlTxBufLenBytevalue" = "./EthCtrlTxBufLenByte"!][!//
[!VAR "EthRxBufTotalvalue" = "./EthRxBufTotal"!][!//
[!VAR "EthTxBufTotalvalue" = "./EthTxBufTotal"!][!//
[!IF "$TxBuffer < (num:i($EthCtrlTxBufLenBytevalue) * num:i($EthTxBufTotalvalue))"!][!//
[!VAR "TxBuffer" = "(string(num:i($EthCtrlTxBufLenBytevalue) * num:i($EthTxBufTotalvalue)))"!][!//
[!ENDIF!]!][!// 
[!IF "$RxBuffer < (num:i($EthCtrlRxBufLenBytevalue) * num:i($EthRxBufTotalvalue) + num:i(1524) - num:i($EthCtrlRxBufLenBytevalue))"!][!//
[!VAR "RxBuffer" = "(string(num:i($EthCtrlRxBufLenBytevalue) * num:i($EthRxBufTotalvalue) + num:i(1524) - num:i($EthCtrlRxBufLenBytevalue)))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

#define ETH_17_TXBUFFER_COUNT  ([!"num:max(./EthConfigSet/*/EthCtrlConfig/*[1]/EthTxBufTotal)"!]U)
#define ETH_17_RXBUFFER_COUNT  ([!"num:max(./EthConfigSet/*/EthCtrlConfig/*[1]/EthRxBufTotal)"!]U)
#define ETH_17_TXBUFFER_SIZE   ([!"string($TxBuffer)"!]U)
#define ETH_17_RXBUFFER_SIZE   ([!"string($RxBuffer)"!]U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* ETH_17_ETHMAC_CFG_H */

[!ENDSELECT!][!//
