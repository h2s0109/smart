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
**   $FILENAME   : EcuM_PBCfg.c $                                             **
**                                                                            **
**   $CC VERSION : \main\39 $                                                 **
**                                                                            **
**   $DATE       : 2014-10-15 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for EcuM_PBCfg.c file                        **
**                                                                            **
**   SPECIFICATION(S) : AUTOSAR_SWS_ECU_StateManager.pdf                      **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
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
**   $FILENAME   : EcuM_PBCfg.c $                                             **
**                                                                            **
**   $CC VERSION : \main\39 $                                                 **
**                                                                            **
**   DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                            **
**   GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : EcuM configuration generated from ECU configuration file  **
**                                                                            **
**   SPECIFICATION(S) : AUTOSAR_SWS_ECU_StateManager.pdf, AS4.0               **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
*******************************************************************************/
[!NOCODE!]
[!INCLUDE "EcuM.m"!][!//
[!ENDNOCODE!][!//
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"

#include "Mcu.h"

#ifdef ECUM_USES_GPT
#include "Gpt.h"
#endif
#ifdef ECUM_USES_PORT
#include "Port.h"
#endif
#ifdef ECUM_USES_DIO
#include "Dio.h"
#endif
#ifdef ECUM_USES_DMA
#include "Dma.h"
#endif
#ifdef ECUM_USES_SPI
#include "Spi.h"
#endif
#ifdef ECUM_USES_ADC
#include "Adc.h"
#endif
#ifdef ECUM_USES_FLS
#include "Fls_17_Pmu.h"
#endif
#ifdef ECUM_USES_FEE
#include "Fee.h"
#endif
#ifdef ECUM_USES_CAN
#include "Can_17_MCanP.h"
#endif
#ifdef ECUM_USES_PWM
#include "Pwm_17_Gtm.h"
#endif
#ifdef ECUM_USES_FADC
#include "Fadc.h"
#endif
#ifdef ECUM_USES_ICU
#include "Icu_17_GtmCcu6.h"
#endif
#ifdef ECUM_USES_WDG
#include "Wdg_17_Scu.h"
#endif
#ifdef ECUM_USES_MLI
#include "Mli.h"
#endif
#ifdef ECUM_USES_SCI
#include "Sci.h"
#endif
#ifdef ECUM_USES_MCHK
#include "Mchk.h"
#endif
#ifdef ECUM_USES_MSC
#include "Msc.h"
#endif
#ifdef ECUM_USES_FR_17_ERAY
#include "Fr_17_Eray.h"
#endif
#ifdef ECUM_USES_LIN
#include "Lin_17_AscLin.h"
#endif
#ifdef ECUM_USES_UART
#include "Uart.h"
#endif
#ifdef ECUM_USES_ETH
#include "Eth_17_EthMac.h"
#endif
#ifdef ECUM_USES_CRC
#include "Crc.h"
#endif
#ifdef ECUM_USES_RAMTST
#include "RamTst_Api.h"
#endif
#ifdef ECUM_USES_CANTRCV_17_6250GV33
#include "CanTrcv_17_6250GV33.h"
#endif
#ifdef ECUM_USES_CANTRCV_17_6251G
#include "CanTrcv_17_6251G.h"
#endif
#ifdef ECUM_USES_FLSLOADER
#include "FlsLoader.h"
#endif
#ifdef ECUM_USES_SENT
#include "Sent.h"
#endif
#ifdef ECUM_USES_IOM
#include "Iom.h"
#endif
#ifdef ECUM_USES_HSSL
#include "Hssl.h"
#endif
#ifdef ECUM_USES_DSADC
#include "Dsadc.h"
#endif
#ifdef ECUM_USES_SMU
#include "Smu.h"
#endif
#ifdef ECUM_USES_I2C
#include "I2c.h"
#endif
/*******************************************************************************
**                      Private Macro Definitions                             **
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
#define ECUM_START_SEC_POSTBUILDCFG
#include "MemMap.h"
[!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*"!][!//
[!IF "EcuMPostBuildConfigType = 'SELECTABLE'"!][!//
[!VAR "IsSelectableSelected" = "'TRUE'"!][!//
[!ELSE!][!//
[!VAR "IsSelectableSelected" = "'FALSE'"!][!//
[!ENDIF!]
[!ENDSELECT!][!//
[!IF "$IsSelectableSelected = 'TRUE'"!]
const EcuM_ConfigType EcuM_ConfigAlternative[] = 
{
[!VAR "EcumConfigCount" = "num:i(count(as:modconf('EcuM')[1]/EcuMConfiguration/*))"!][!//
[!VAR "EcuM_Mod_String" = "''"!][!//
[!FOR "EcumCfgPosition" ="num:i(1)" TO "num:i($EcumConfigCount)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[num:i($EcumCfgPosition)]"!][!//
  {
    /* Identifier of post-build time configuration */
    [!"EcuMCommonConfiguration/EcuMPostbuildConfigId"!],
    /* Hash Identifier of pre compile time configuration */
    [!"num:inttohex(EcuMCommonConfiguration/EcuMConfigConsistencyHash)"!],
[!NOCODE!][!//
[!VAR "EcuM_tmp_Mod_String" = "''"!][!//
[!LOOP "./EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]/EcuMDriverInitItem/*"!]
[!IF "$EcumCfgPosition = num:i(1)"!][!//
[!VAR "EcuM_Mod_String" = "concat($EcuM_Mod_String,node:value(./EcuMModuleID))"!][!//
[!ELSE!][!//
[!VAR "EcuM_tmp_Mod_String" = "concat($EcuM_tmp_Mod_String,node:value(./EcuMModuleID))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$EcumCfgPosition != num:i(1)"!][!//
[!IF "not(contains($EcuM_tmp_Mod_String,$EcuM_Mod_String) = 'true' and contains($EcuM_Mod_String,$EcuM_tmp_Mod_String) = 'true')"!][!//
[!ERROR!][!//
ERROR: The order of initialization in EcuMInitListOne is not consistent across the configuration.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1]) != 'true'"!][!//
[!ERROR!][!//
ERROR: MCU driver configuration empty, In the EcuMFixedModuleConfigurationRef Mcu Reference should exist.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "ConfigIndex" = "'0'"!][!//
[!VAR "ConfigIndex" = "'0'"!][!//
[!VAR "McuExist" = "'STD_OFF'"!][!//
[!NOCODE!][!//
[!VAR "Drivers" = "'Empty'"!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!CALL "CG_CheckDriverCallListUniqueness", "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!VAR "ReferenceExists"= "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1])"!][!//
[!VAR "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "ModuleName" = "./EcuMModuleID"!][!//
[!VAR "ModuleConfigName" = "'aaa'"!][!//
[!VAR "ModuleConfigIndex" = "num:i(255)"!][!//
[!IF "$ReferenceExists = 'true'"!][!//
[!CALL "GetConfigIndex",  "ModName" = "$ModuleName", "CfgIndex" = "$EcumCfgPosition"!][!//
[!IF "$ModuleName != 'Fee' and $ModuleName != 'RamTst' and $ModuleName != 'CanTrcv_17_6250GV33' and $ModuleName != 'CanTrcv_17_6251G' and $ModuleName != 'FlsLoader' and $ModuleName != 'Hssl'"!][!//
[!IF "$ModuleName != 'Mcu' and $ModuleName != 'Gpt' and $ModuleName != 'Fr_17_Eray' and $ModuleName != 'Icu_17_GtmCcu6' and $ModuleName != 'Lin_17_AscLin' and $ModuleName != 'Fls_17_Pmu' and $ModuleName != 'Pwm_17_Gtm' and $ModuleName != 'Wdg_17_Scu' and $ModuleName != 'Can_17_MCanP' and $ModuleName != 'Eth_17_EthMac'"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//
[!VAR "ModGeneral" = "concat($ModuleName,'General')"!][!//
[!VAR "ModPBFixedAddress" = "concat($ModuleName,'PBFixedAddress')"!][!//
[!VAR "RetVal1" = "concat($ModGeneral,'/',$ModPBFixedAddress)"!][!//
[!IF "node:exists($RetVal1) = 'true'"!][!//
[!VAR "RetVal" = "node:ref($RetVal1)"!][!//
[!IF "$RetVal = 'false'"!]
    &[!"$ModuleName"!]_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//
[!ENDIF!][!//
[!ELSE!]
    &[!"$ModuleName"!]_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSEIF "$ModuleName = 'Mcu' and $McuPBFixedAddress = 'false'"!]
    &[!"$ModuleName"!]_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//
[!ELSEIF "$ModuleName = 'Gpt' and $GptPBFixedAddress = 'false'"!]
    &[!"$ModuleName"!]_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//
[!ELSEIF "$ModuleName = 'Fr_17_Eray' and $FrPBFixedAddress = 'false'"!]
    &[!"$ModuleName"!]_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Icu_17_GtmCcu6' and $IcuPBFixedAddress = 'false'"!]
    &Icu_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Fls_17_Pmu' and $FlsPBFixedAddress = 'false'"!]
    &Fls_17_Pmu_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Pwm_17_Gtm' and $PwmPBFixedAddress = 'false'"!]
    &Pwm_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Wdg_17_Scu' and $WdgPBFixedAddress = 'false'"!]
    &Wdg_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Lin_17_AscLin' and $LinPBFixedAddress = 'false'"!]
    &Lin_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Eth_17_EthMac' and $EthPBFixedAddress = 'false'"!]
  &Eth_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSEIF "$ModuleName = 'Can_17_MCanP' and $CanPBFixedAddress = 'false'"!]
    &Can_17_MCanP_ConfigRoot[[!"num:i($ModuleConfigIndex)"!]],[!//  
[!ELSE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!]
    0xFF                  /* EcuM Internal Data */
  }
[!ENDSELECT!][!//
[!IF "$EcumCfgPosition!= $EcumConfigCount"!],[!ENDIF!][!//
[!ENDFOR!][!//
};

[!ELSE!][!//
/* Configuration Set for MC-ISAR_Aurix Demo Application */
const  EcuM_ConfigType EcuM_ConfigRoot = 
{
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*"!][!//
[!/* There is only one configuration if loadable */!][!//
[!//
  /* Identifier of post-build time configuration */
  0,
  /* Hash Identifier of pre compile time configuration */
  [!"num:inttohex(EcuMCommonConfiguration/EcuMConfigConsistencyHash)"!],
[!NOCODE!][!//
[!IF "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1]) != 'true'"!][!//
[!ERROR!][!//
ERROR: MCU driver configuration empty, In the EcuMMdouleConfigurationRef Mcu Reference should exist.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!VAR "Drivers" = "'Empty'"!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!CALL "CG_CheckDriverCallListUniqueness", "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1]) = 'true'"!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!VAR "ReferenceExists"= "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1])"!][!//
[!VAR "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "ModuleName" = "./EcuMModuleID"!][!//
[!IF "$ReferenceExists = 'true'"!][!//
[!CALL "CG_BuildDriverCallListLoadable",  "ModName" = "$ModuleName"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDIF!]
  0xFF                /* EcuM Internal Data */
[!ENDSELECT!][!//
};
[!ENDIF!]


#define ECUM_STOP_SEC_POSTBUILDCFG
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
