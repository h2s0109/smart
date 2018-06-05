[!/*
*******************************************************************************
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
**  $FILENAME   : EcuM.m $                                                   **
**                                                                           **
**  $CC VERSION : \main\41 $                                                 **
**                                                                           **
**  $DATE       : 2015-12-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                the macros needed for Configuration Template files         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************
*/!]

[!NOCODE!][!//
[!VAR "GptPBFixedAddress"   =  "'false'"!][!//
[!VAR "McuPBFixedAddress"   =  "'false'"!][!//
[!VAR "FrPBFixedAddress"   =  "'false'"!][!//
[!VAR "IcuPBFixedAddress"   =  "'false'"!][!//
[!VAR "CanPBFixedAddress"   =  "'false'"!][!//
[!VAR "FlsPBFixedAddress"   =  "'false'"!][!//
[!VAR "PwmPBFixedAddress"   =  "'false'"!][!//
[!VAR "WdgPBFixedAddress"   =  "'false'"!][!//
[!VAR "LinPBFixedAddress"   =  "'false'"!][!//
[!VAR "EthPBFixedAddress"   =  "'false'"!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!IF "node:exists(GptDriverConfiguration/GptPBFixedAddress)"!][!//
[!VAR "GptPBFixedAddress" = "GptDriverConfiguration/GptPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!IF "node:exists(McuGeneralConfiguration/McuPBFixedAddress)"!][!//
[!VAR "McuPBFixedAddress" = "McuGeneralConfiguration/McuPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Fr')[1]"!][!//
[!IF "node:exists(FrGeneral/FrPBFixedAddress)"!][!//
[!VAR "FrPBFixedAddress" = "FrGeneral/FrPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!IF "node:exists(IcuGeneral/IcuPBFixedAddress)"!][!//
[!VAR "IcuPBFixedAddress" = "IcuGeneral/IcuPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Can')[1]"!][!//
[!IF "node:exists(CanGeneral/CanPBFixedAddress)"!][!//
[!VAR "CanPBFixedAddress" = "CanGeneral/CanPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!IF "node:exists(FlsGeneral/FlsPBFixedAddress)"!][!//
[!VAR "FlsPBFixedAddress" = "FlsGeneral/FlsPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!IF "node:exists(PwmGeneral/PwmPBFixedAddress)"!][!//
[!VAR "PwmPBFixedAddress" = "PwmGeneral/PwmPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Wdg')[1]"!][!//
[!IF "node:exists(WdgGeneral/WdgPBFixedAddress)"!][!//
[!VAR "WdgPBFixedAddress" = "WdgGeneral/WdgPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Lin')[1]"!][!//
[!IF "node:exists(LinGeneral/LinPBFixedAddress)"!][!//
[!VAR "LinPBFixedAddress" = "LinGeneral/LinPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Eth')[1]"!][!//
[!IF "node:exists(EthGeneral/EthPBFixedAddress)"!][!//
[!VAR "EthPBFixedAddress" = "EthGeneral/EthPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!/*
MACRO CG_BuildPBDriverCfgTypeList
Macro to get the list modules used in driver init call list.
Used to generate elements of EcuM_ConfigType_Tag
*/!][!//
[!MACRO "CG_BuildPBDriverCfgTypeList", "List" = ""!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "ModuleName" = "./EcuMModuleID"!][!//
[!IF "$ModuleName != 'Fee' and $ModuleName != 'RamTst' and $ModuleName != 'CanTrcv_17_6250GV33' and $ModuleName != 'CanTrcv_17_6251G' and $ModuleName != 'FlsLoader' and $ModuleName != 'Hssl'"!][!//
[!IF "$ModuleName != 'Mcu' and $ModuleName != 'Gpt' and $ModuleName != 'Fr_17_Eray' and $ModuleName != 'Icu_17_GtmCcu6' and $ModuleName != 'Lin_17_AscLin' and $ModuleName != 'Fls_17_Pmu' and $ModuleName != 'Pwm_17_Gtm' and $ModuleName != 'Wdg_17_Scu' and $ModuleName != 'Can_17_MCanP' and $ModuleName != 'Eth_17_EthMac'"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//
[!VAR "ModGeneral" = "concat($ModuleName,'General')"!][!//
[!VAR "ModPBFixedAddress" = "concat($ModuleName,'PBFixedAddress')"!][!//
[!VAR "RetVal1" = "concat($ModGeneral,'/',$ModPBFixedAddress)"!][!//
[!IF "node:exists($RetVal1) = 'true'"!][!//
[!VAR "RetVal" = "node:ref($RetVal1)"!][!//
[!IF "$RetVal = 'false'"!]
  const struct [!"$ModuleName"!]_ConfigType   * [!"$ModuleName"!]_ConfigData;[!//
[!ENDIF!][!//
[!ELSE!]
  const struct [!"$ModuleName"!]_ConfigType   * [!"$ModuleName"!]_ConfigData;[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSEIF "$ModuleName = 'Mcu' and $McuPBFixedAddress = 'false'"!]
  const struct [!"$ModuleName"!]_ConfigType   * [!"$ModuleName"!]_ConfigData;[!//
[!ELSEIF "$ModuleName = 'Gpt' and $GptPBFixedAddress = 'false'"!]
  const struct [!"$ModuleName"!]_ConfigType   * [!"$ModuleName"!]_ConfigData;[!//
[!ELSEIF "$ModuleName = 'Fr_17_Eray' and $FrPBFixedAddress = 'false'"!]
  const struct [!"$ModuleName"!]_ConfigType   * [!"$ModuleName"!]_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Icu_17_GtmCcu6' and $IcuPBFixedAddress = 'false'"!]
  const struct Icu_17_GtmCcu6_ConfigType   * Icu_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Fls_17_Pmu' and $FlsPBFixedAddress = 'false'"!]
  const struct Fls_17_Pmu_ConfigType   * Fls_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Pwm_17_Gtm' and $PwmPBFixedAddress = 'false'"!]
  const struct Pwm_17_Gtm_ConfigType   * Pwm_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Wdg_17_Scu' and $WdgPBFixedAddress = 'false'"!]
  const struct Wdg_17_Scu_ConfigType   * Wdg_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Lin_17_AscLin' and $LinPBFixedAddress = 'false'"!]
  const struct Lin_17_AscLin_ConfigType   * Lin_17_AscLin_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Can_17_MCanP' and $CanPBFixedAddress = 'false'"!]
  const struct Can_17_MCanP_ConfigType   * Can_ConfigData;[!//  
[!ELSEIF "$ModuleName = 'Eth_17_EthMac' and $EthPBFixedAddress = 'false'"!]
const struct Eth_17_EthMac_ConfigType   * Eth_ConfigData;[!//  
[!ELSE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//


[!/*
MACRO CG_RefCheck
Macro to Check the selected EcuMModuelConfigurationRefernces are matched
with any one of the EcuMDrierInitList's or not.
*/!][!//
[!MACRO "CG_RefCheck", "List" = ""!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "ModuleName" = "./EcuMModuleID"!][!//
[!IF "$ModuleName = $RefModuleName"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Fr_17_Eray' and $RefModuleName = 'Fr'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Icu_17_GtmCcu6' and $RefModuleName = 'Icu'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Fls_17_Pmu' and $RefModuleName = 'Fls'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Pwm_17_Gtm' and $RefModuleName = 'Pwm'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Wdg_17_Scu' and $RefModuleName = 'Wdg'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Lin_17_AscLin' and $RefModuleName = 'Lin'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Can_17_MCanP' and $RefModuleName = 'Can'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Eth_17_EthMac' and $RefModuleName = 'Eth'"!][!//
 [!VAR "ModuleMapped" = "'ON'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//


[!MACRO "CG_BuildDriverCallListZero", "List" = ""!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "EcuMModuleId" = "./EcuMModuleID"!]
[!"$EcuMModuleId"!]_Init(); \
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//


[!/*
MACRO CG_BuildDriverCallList
Macro to build initialization list of drivers in list DriverInitListOne.
This macros used for selectable configuration.
Precondition: None
Postcondition: <Mod>_Init call list is built.
*/!][!//
[!MACRO "CG_BuildDriverCallList", "List" = ""!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!VAR "RamTstModuleIdExist" = "'OFF'"!][!//
[!VAR "FeeModuleIdExist" = "'OFF'"!][!//
[!VAR "CanTrcv6250GV33ModuleIdExist" = "'OFF'"!][!//
[!VAR "CanTrcv6251GModuleIdExist" = "'OFF'"!][!//
[!VAR "FlsLoaderModuleIdExist" = "'OFF'"!][!//
[!VAR "HsslModuleIdExist" = "'OFF'"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!IF "@index = num:i(0)"!][!//
\
[!ENDIF!][!//
[!VAR "EcuMModuleId" = "./EcuMModuleID"!][!//
[!IF "$EcuMModuleId = 'Fls_17_Pmu'"!][!//
[!VAR "FlsInitialized" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$EcuMModuleId = 'Fee'"!][!//
[!VAR "FeeModuleIdExist" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "contains($EcuMModuleId, 'Fr') = 'true'"!][!//
[!IF "$EcuMModuleId != 'Fr_17_Eray'"!][!//
[!ERROR!][!//
ERROR: For the FR module initialization EcuMModuleId should be Fr_17_Eray.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains($EcuMModuleId, 'Icu') = 'true'"!][!//
[!IF "$EcuMModuleId != 'Icu_17_GtmCcu6'"!][!//
[!ERROR!][!//
ERROR: For the Icu module initialization EcuMModuleId should be Icu_17_GtmCcu6.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "(contains($EcuMModuleId, 'Can') = 'true') and (contains($EcuMModuleId, 'CanTrcv') != 'true')"!][!//
[!IF "$EcuMModuleId != 'Can_17_MCanP'"!][!//
[!ERROR!][!//
ERROR: For the Can module initialization EcuMModuleId should be Can_17_MCanP.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "(contains($EcuMModuleId, 'Fls') = 'true') and ($EcuMModuleId != 'FlsLoader')"!][!//
[!IF "$EcuMModuleId != 'Fls_17_Pmu'"!][!//
[!ERROR!][!//
ERROR: For the Fls module initialization EcuMModuleId should be Fls_17_Pmu.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains($EcuMModuleId, 'Pwm') = 'true'"!][!//
[!IF "$EcuMModuleId != 'Pwm_17_Gtm'"!][!//
[!ERROR!][!//
ERROR: For the Pwm module initialization EcuMModuleId should be Pwm_17_Gtm.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains($EcuMModuleId, 'Wdg') = 'true'"!][!//
[!IF "$EcuMModuleId != 'Wdg_17_Scu'"!][!//
[!ERROR!][!//
ERROR: For the Wdg module initialization EcuMModuleId should be Wdg_17_Scu.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains($EcuMModuleId, 'Lin') = 'true'"!][!//
[!IF "$EcuMModuleId != 'Lin_17_AscLin'"!][!//
[!ERROR!][!//
ERROR: For the Lin module initialization EcuMModuleId should be Lin_17_AscLin.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains($EcuMModuleId, 'Eth') = 'true'"!][!//
[!IF "$EcuMModuleId != 'Eth_17_EthMac'"!][!//
[!ERROR!][!//
ERROR: For the Eth module initialization EcuMModuleId should be Eth_17_EthMac.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$EcuMModuleId != 'Fee' and $EcuMModuleId != 'Mcu' and $EcuMModuleId != 'Gpt' and $EcuMModuleId != 'RamTst' and $EcuMModuleId != 'CanTrcv_17_6250GV33' and $EcuMModuleId != 'CanTrcv_17_6251G' and $EcuMModuleId != 'Fr_17_Eray' and $EcuMModuleId != 'FlsLoader' and $EcuMModuleId != 'Hssl' and $EcuMModuleId != 'Pwm_17_Gtm' and $EcuMModuleId != 'Icu_17_GtmCcu6' and $EcuMModuleId != 'Lin_17_AscLin' and $EcuMModuleId != 'Fls_17_Pmu' and $EcuMModuleId != 'Wdg_17_Scu' and $EcuMModuleId != 'Can_17_MCanP' and $EcuMModuleId != 'Eth_17_EthMac'"!][!//
[!SELECT "as:modconf($EcuMModuleId)[1]"!][!//
[!VAR "ModGeneral" = "concat($EcuMModuleId,'General')"!][!//
[!VAR "ModPBFixedAddress" = "concat($EcuMModuleId,'PBFixedAddress')"!][!//
[!VAR "RetVal1" = "concat($ModGeneral,'/',$ModPBFixedAddress)"!][!//
[!IF "node:exists($RetVal1) = 'true'"!][!//
[!VAR "RetVal" = "node:ref($RetVal1)"!][!//
[!IF "$RetVal = 'true'"!][!//
  [!"$EcuMModuleId"!]_Init(&[!"$EcuMModuleId"!]_ConfigRoot[0]);  \
[!ELSE!][!//
  [!"$EcuMModuleId"!]_Init(configptr->[!"$EcuMModuleId"!]_ConfigData);  \
[!ENDIF!][!//
[!ELSE!][!//
  [!"$EcuMModuleId"!]_Init(configptr->[!"$EcuMModuleId"!]_ConfigData);  \
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSEIF "$EcuMModuleId = 'Gpt' and $GptPBFixedAddress = 'true'"!][!//
  Gpt_Init(&Gpt_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Gpt' and $GptPBFixedAddress = 'false'"!][!//
  Gpt_Init(configptr->Gpt_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Fr_17_Eray' and $FrPBFixedAddress = 'true'"!][!//
  Fr_17_Eray_Init(&Fr_17_Eray_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Fr_17_Eray' and $FrPBFixedAddress = 'false'"!][!//
  Fr_17_Eray_Init(configptr->Fr_17_Eray_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Pwm_17_Gtm' and $PwmPBFixedAddress = 'true'"!][!//
  Pwm_17_Gtm_Init(&Pwm_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Pwm_17_Gtm' and $PwmPBFixedAddress = 'false'"!][!//
  Pwm_17_Gtm_Init(configptr->Pwm_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Icu_17_GtmCcu6' and $IcuPBFixedAddress = 'true'"!][!//
  Icu_17_GtmCcu6_Init(&Icu_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Icu_17_GtmCcu6' and $IcuPBFixedAddress = 'false'"!][!//
  Icu_17_GtmCcu6_Init(configptr->Icu_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Fls_17_Pmu' and $FlsPBFixedAddress = 'true'"!][!//
  Fls_17_Pmu_Init(&Fls_17_Pmu_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Fls_17_Pmu' and $FlsPBFixedAddress = 'false'"!][!//
  Fls_17_Pmu_Init(configptr->Fls_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Wdg_17_Scu' and $WdgPBFixedAddress = 'true'"!][!//
  Wdg_17_Scu_Init(&Wdg_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Wdg_17_Scu' and $WdgPBFixedAddress = 'false'"!][!//
  Wdg_17_Scu_Init(configptr->Wdg_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Lin_17_AscLin' and $LinPBFixedAddress = 'true'"!][!//
  Lin_17_AscLin_Init(&Lin_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Lin_17_AscLin' and $LinPBFixedAddress = 'false'"!][!//
  Lin_17_AscLin_Init(configptr->Lin_17_AscLin_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Can_17_MCanP' and $CanPBFixedAddress = 'true'"!][!//
  Can_17_MCanP_Init(&Can_17_MCanP_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Can_17_MCanP' and $CanPBFixedAddress = 'false'"!][!//
  Can_17_MCanP_Init(configptr->Can_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'Eth_17_EthMac' and $EthPBFixedAddress = 'true'"!][!//
  Eth_17_EthMac_Init(&Eth_ConfigRoot[0]);  \
[!ELSEIF "$EcuMModuleId = 'Eth_17_EthMac' and $EthPBFixedAddress = 'false'"!][!//
  Eth_17_EthMac_Init(configptr->Eth_ConfigData);  \
[!ELSEIF "$EcuMModuleId = 'RamTst'"!][!//
[!VAR "RamTstModuleIdExist" = "'ON'"!][!//
[!ELSEIF "$EcuMModuleId = 'CanTrcv_17_6250GV33'"!][!//
[!VAR "CanTrcv6250GV33ModuleIdExist" = "'ON'"!][!//
[!ELSEIF "$EcuMModuleId = 'CanTrcv_17_6251G'"!][!//
[!VAR "CanTrcv6251GModuleIdExist" = "'ON'"!][!//
[!ELSEIF "$EcuMModuleId = 'FlsLoader'"!][!//
[!VAR "FlsLoaderModuleIdExist" = "'ON'"!][!//
[!ELSEIF "$EcuMModuleId = 'Hssl'"!][!//
[!VAR "HsslModuleIdExist" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$FeeModuleIdExist = 'ON' and $FlsInitialized != num:i(1)"!][!//
[!ERROR!][!//
Fls Should be initialized before Fee, In the EcuMDriverInitList --> EcuMDriverInitItem --> EcuMModuleId, Fls should be configured first and then Fee.[!//
[!ENDERROR!][!//
[!ENDIF!][!//
[!IF "$FeeModuleIdExist = 'ON' and $FlsInitialized = num:i(1)"!][!//
  Fee_Init();  \
  do  \
  {  \
    Fls_17_Pmu_MainFunction();  \
    Fee_MainFunction();  \
  }while(Fee_GetStatus() != MEMIF_IDLE);/* Wait for FEE Init to complete*/  \
[!VAR "FeeModuleIdExist" = "'OFF'"!][!//
[!ENDIF!][!//
[!IF "$RamTstModuleIdExist = 'ON'"!][!//
  RamTst_Init();  \
[!VAR "RamTstModuleIdExist" = "'OFF'"!][!//
[!ENDIF!][!//
[!IF "$CanTrcv6250GV33ModuleIdExist = 'ON'"!][!//
  CanTrcv_17_6250GV33_Init(NULL_PTR);  \
[!VAR "CanTrcv6250GV33ModuleIdExist" = "'OFF'"!][!//
[!ENDIF!][!//
[!IF "$CanTrcv6251GModuleIdExist = 'ON'"!][!//
  CanTrcv_17_6251G_Init(NULL_PTR);  \
[!VAR "CanTrcv6251GModuleIdExist" = "'OFF'"!][!//
[!ENDIF!][!//
[!IF "$FlsLoaderModuleIdExist = 'ON'"!][!//
  FlsLoader_Init(NULL_PTR);  \
[!VAR "FlsLoaderModuleIdExist" = "'OFF'"!][!//
[!ENDIF!][!//
[!IF "$HsslModuleIdExist = 'ON'"!][!//
  Hssl_Init(0U);  \
[!VAR "HsslModuleIdExist" = "'OFF'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//

[!/*
MACRO CG_BuildDriverCallListLoadable
Macro to build initialization list of drivers in list DriverInitListOne.
This macros used for loadable configuration.
Precondition: None
Postcondition: <Mod>_Init call list is built.
*/!][!//

[!MACRO "CG_BuildDriverCallListLoadable", "ModName" = ""!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "ErrorFlag" = "'0'"!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*)) - num:i(1)"!][!//
[!/* example[!//
ASpath:/Mcu/Mcu/Default_0[!//
ModuleConfigName should hold Default_0[!//
ObtainedModuleNamefromRef should hold Mcu[!//
Variable ModuleConfigIndex is updated in CG_GetModuleConfigIndex */!][!//
[!VAR "ModuleConfigRefPath1" = "(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[@index = $Index1])"!][!//
[!VAR "ModuleConfigRefPath" = "substring-after($ModuleConfigRefPath1, ":")"!][!//
[!VAR "ModuleConfigName1" = "substring-after($ModuleConfigRefPath, "/")"!][!//
[!VAR "ModuleConfigName1" = "substring-after($ModuleConfigName1, "/")"!][!//
[!VAR "ObtainedModuleNamefromRef" = "substring-before($ModuleConfigName1, "/")"!][!//
[!VAR "ModuleConfigName" = "substring-after($ModuleConfigRefPath, "/")"!][!//
[!VAR "ModuleConfigName" = "substring-after($ModuleConfigName, "/")"!][!//
[!VAR "ModuleConfigName" = "substring-after($ModuleConfigName, "/")"!][!//
[!IF "$ModName = 'Fr_17_Eray' and $ObtainedModuleNamefromRef = 'Fr' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Icu_17_GtmCcu6' and $ObtainedModuleNamefromRef = 'Icu' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Can_17_MCanP' and $ObtainedModuleNamefromRef = 'Can' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Fls_17_Pmu' and $ObtainedModuleNamefromRef = 'Fls' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Pwm_17_Gtm' and $ObtainedModuleNamefromRef = 'Pwm' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Wdg_17_Scu' and $ObtainedModuleNamefromRef = 'Wdg' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Lin_17_AscLin' and $ObtainedModuleNamefromRef = 'Lin' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = 'Eth_17_EthMac' and $ObtainedModuleNamefromRef = 'Eth' "!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!ENDIF!][!//
[!IF "$ModName = $ObtainedModuleNamefromRef"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!IF "$ModuleName = 'Mcu'"!][!//
[!VAR "McuModuleExist" = "'ON'"!][!//
[!ENDIF!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!IF "$ModuleName != 'Fee' and $ModuleName != 'RamTst' and $ModuleName != 'CanTrcv_17_6250GV33'and $ModuleName != 'CanTrcv_17_6251G' and $ModuleName != 'FlsLoader' and $ModuleName != 'Hssl'"!][!//
[!IF "$ModuleName != 'Mcu' and $ModuleName != 'Gpt' and $ModuleName != 'Fr_17_Eray' and $ModuleName != 'Icu_17_GtmCcu6' and $ModuleName != 'Lin_17_AscLin' and $ModuleName != 'Fls_17_Pmu' and $ModuleName != 'Pwm_17_Gtm' and $ModuleName != 'Wdg_17_Scu' and $ModuleName != 'Can_17_MCanP' and $ModuleName != 'Eth_17_EthMac'"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//
[!VAR "ModGeneral" = "concat($ModuleName,'General')"!][!//
[!VAR "ModPBFixedAddress" = "concat($ModuleName,'PBFixedAddress')"!][!//
[!VAR "RetVal1" = "concat($ModGeneral,'/',$ModPBFixedAddress)"!][!//
[!IF "node:exists($RetVal1) = 'true'"!][!//
[!VAR "RetVal" = "node:ref($RetVal1)"!][!//
[!IF "$RetVal = 'false'"!]
  &[!"$ModuleName"!]_ConfigRoot[0], [!//
[!ENDIF!][!//
[!ELSE!]
  &[!"$ModuleName"!]_ConfigRoot[0], [!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSEIF "$ModuleName = 'Mcu' and $McuPBFixedAddress = 'false'"!]
  &[!"$ModuleName"!]_ConfigRoot[0], [!//
[!ELSEIF "$ModuleName = 'Gpt' and $GptPBFixedAddress = 'false'"!]
  &[!"$ModuleName"!]_ConfigRoot[0], [!//
[!ELSEIF "$ModuleName = 'Fr_17_Eray' and $FrPBFixedAddress = 'false'"!]
  &[!"$ModuleName"!]_ConfigRoot[0], [!//  
[!ELSEIF "$ModuleName = 'Icu_17_GtmCcu6' and $IcuPBFixedAddress = 'false'"!]
  &Icu_ConfigRoot[0], [!//  
[!ELSEIF "$ModuleName = 'Fls_17_Pmu' and $FlsPBFixedAddress = 'false'"!]
  &Fls_17_Pmu_ConfigRoot[0], [!//  
[!ELSEIF "$ModuleName = 'Pwm_17_Gtm' and $PwmPBFixedAddress = 'false'"!]
  &Pwm_ConfigRoot[0], [!//  
[!ELSEIF "$ModuleName = 'Wdg_17_Scu' and $WdgPBFixedAddress = 'false'"!]
  &Wdg_ConfigRoot[0], [!//        
[!ELSEIF "$ModuleName = 'Lin_17_AscLin' and $LinPBFixedAddress = 'false'"!]
  &Lin_ConfigRoot[0], [!//   
[!ELSEIF "$ModuleName = 'Eth_17_EthMac' and $EthPBFixedAddress = 'false'"!]
  &Eth_ConfigRoot[0], [!//          
[!ELSEIF "$ModuleName = 'Can_17_MCanP' and $CanPBFixedAddress = 'false'"!]
  &Can_17_MCanP_ConfigRoot[0], [!//  
[!ELSE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Fr_17_Eray' and $ObtainedModuleNamefromRef = 'Fr' and $FrPBFixedAddress = 'false'"!]
  &[!"$ModuleName"!]_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Icu_17_GtmCcu6' and $ObtainedModuleNamefromRef = 'Icu' and $IcuPBFixedAddress = 'false'"!]
  &Icu_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Fls_17_Pmu' and $ObtainedModuleNamefromRef = 'Fls' and $FlsPBFixedAddress = 'false'"!]
  &Fls_17_Pmu_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Pwm_17_Gtm' and $ObtainedModuleNamefromRef = 'Pwm' and $PwmPBFixedAddress = 'false'"!]
  &Pwm_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Wdg_17_Scu' and $ObtainedModuleNamefromRef = 'Wdg' and $WdgPBFixedAddress = 'false'"!]
  &Wdg_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Lin_17_AscLin' and $ObtainedModuleNamefromRef = 'Lin' and $LinPBFixedAddress = 'false'"!]
  &Lin_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Eth_17_EthMac' and $ObtainedModuleNamefromRef = 'Eth' and $EthPBFixedAddress = 'false'"!]
  &Eth_ConfigRoot[0], [!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Can_17_MCanP' and $ObtainedModuleNamefromRef = 'Can' and $CanPBFixedAddress = 'false'"!]
  &Can_17_MCanP_ConfigRoot[0], [!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$ModName != 'Fee' and $ModName != 'RamTst' and $ModName != 'CanTrcv6250GV33' and $ModName != 'CanTrcv6251G' and $ModName != 'FlsLoader' and $ModName != 'Hssl'"!][!//
[!ASSERT "$ErrorFlag = '1'"!][!//
Error: Given module [!"$ModName"!] ID in DriverInitItem does not have a reference in EcuMFixedModuleConfigurationRef[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//


[!/*
MACRO CG_BuildIncludeFileList
Macro to build list of module header files to include.
Precondition: None
Postcondition: List of include files like below :
#include Adc.h
#include Icu.h
...
*/!][!//
[!MACRO "CG_BuildIncludeFileList", "List" = ""!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*)) - num:i(1)"!][!//
[!VAR "Selection" = "(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[@index = $Index1])"!][!//
[!VAR "ModuleConfigName" = "substring-after($Selection, "ASPath:/")"!][!//
[!VAR "ModuleName1" = "substring-after($ModuleConfigName, "/")"!][!//
[!VAR "ModuleName" = "substring-before($ModuleName1, "/")"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "EcuMModId" = "./EcuMModuleID"!][!//
[!IF "$ModuleName = $EcuMModId"!][!//
[!IF "$ModuleName != 'Mcu'"!][!//
#define ECUM_USES_[!"translate(($ModuleName), 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')"!]
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$ModuleName = 'Fr' and $EcuMModId = 'Fr_17_Eray'"!][!//
#define ECUM_USES_FR_17_ERAY
[!ENDIF!][!//
[!IF "$ModuleName = 'Icu' and $EcuMModId = 'Icu_17_GtmCcu6'"!][!//
#define ECUM_USES_ICU
[!ENDIF!][!//
[!IF "$ModuleName = 'Fls' and $EcuMModId = 'Fls_17_Pmu'"!][!//
#define ECUM_USES_FLS
[!ENDIF!][!//
[!IF "$ModuleName = 'Pwm' and $EcuMModId = 'Pwm_17_Gtm'"!][!//
#define ECUM_USES_PWM
[!ENDIF!][!//
[!IF "$ModuleName = 'Wdg' and $EcuMModId = 'Wdg_17_Scu'"!][!//
#define ECUM_USES_WDG
[!ENDIF!][!//
[!IF "$ModuleName = 'Lin' and $EcuMModId = 'Lin_17_AscLin'"!][!//
#define ECUM_USES_LIN
[!ENDIF!][!//
[!IF "$ModuleName = 'Eth' and $EcuMModId = 'Eth_17_EthMac'"!][!//
#define ECUM_USES_ETH
[!ENDIF!][!//
[!IF "$ModuleName = 'Can' and $EcuMModId = 'Can_17_MCanP'"!][!//
#define ECUM_USES_CAN
[!ENDIF!][!//
[!IF "$ModuleName = 'Mcu'"!][!//
[!VAR "McuModUsed " = "'ON'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!/*
MACRO CG_BuildIncludePreComModFileList
Macro to build list of module header files to include.
Precondition: None
Postcondition: List of include files like below :
#include Fee.h
#include RamTst.h
#include CanTrcv6251G.h
#include CanTrcv6250GV33.h
#include FlsLoader.h
#include Hssl.h
...
*/!][!//
[!MACRO "CG_BuildIncludePreComModFileList", "List" = ""!][!//
[!VAR "DriverList" = "concat($List,'/*[1]')"!][!//
[!SELECT "node:ref('EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]')"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "EcuMModId" = "./EcuMModuleID"!][!//
[!IF "$EcuMModId = 'Fee' or $EcuMModId = 'RamTst' or $EcuMModId = 'CanTrcv_17_6251G' or $EcuMModId = 'CanTrcv_17_6250GV33' or $EcuMModId = 'FlsLoader' or $EcuMModId = 'Hssl'"!][!//
#define ECUM_USES_[!"translate(($EcuMModId), 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//


MACRO CG_GetModuleConfigIndex
Macro to get the index of a module configuration selected in ECU configuration.
Precondition: Set variable ConfigIndex to -1
Postcondition: The index of module configuration is available in ConfigIndex
*/!][!//
[!MACRO "CG_GetModuleConfigIndex","ModuleConfigRefPath" = "", "ModuleConfigName" = ""!][!//
[!NOCODE!][!//
[!VAR "ModuleName" = "$ModuleConfigRefPath"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//
[!// Mcu -> McuModuleConfiguration
[!IF "$ModuleName = 'Mcu'"!][!//
[!LOOP "McuModuleConfiguration/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Gpt'"!][!//
[!LOOP "GptChannelConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "@index"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Spi'"!][!//
[!LOOP "SpiDriver/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'I2c'"!][!//
[!LOOP "I2cDriver/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Smu'"!][!//
[!LOOP "SmuConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Uart'"!][!//
[!LOOP "UartConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Pwm'"!][!//
[!LOOP "PwmChannelConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Lin_17_AscLin'"!][!//
[!LOOP "LinGlobalConfig/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Eth_17_EthMac'"!][!//
[!LOOP "EthConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Fr_17_Eray'"!][!//
[!LOOP "FrMultipleConfiguration/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Icu'"!][!//
[!LOOP "IcuConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Can'"!][!//
[!LOOP "CanConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Fls_Pmu_17'"!][!//
[!LOOP "FlsConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!// 
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Wdg'"!][!//
[!LOOP "WdgSettingsConfig/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Dio'"!][!//
[!LOOP "DioConfig/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSEIF "$ModuleName = 'Msc'"!][!//
[!LOOP "MscConfigSet/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
[!IF "contains($ModuleName, 'Fr') = 'true'"!][!//
[!IF "$ModuleName != 'Fr_17_Eray'"!][!//
[!ERROR!][!//
ERROR: For the FR module initialization EcuMModuleId should be Fr_17_Eray.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!VAR "ModuleConfigset" = "concat($ModuleName,'ConfigSet')"!][!//
[!LOOP "node:ref($ModuleConfigset)/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "@index"!][!//
   [!VAR "ModuleConfigIndex" = "num:i($ModuleConfigIndex)"!][!//
   [!VAR "RefError" = "num:i(1)"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModuleName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*
MACRO CG_CheckDriverCallListUniqueness
Macro to check if DriverInitListOne and DriverInitListTwo are unique.
DriverInitListOne and DriverInitListTwo should be unique, otherwise driver(s)
would be initialized multiple times.
Precondition: Set variable Drivers 'Empty'
Postcondition: Error if the lists are not unique
*/!][!//

[!MACRO "CG_CheckDriverCallListUniqueness", "List" = ""!][!//
[!VAR "DriverList" = "concat($List, '/*[1]')"!][!//
[!SELECT "node:ref($DriverList)"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "ModuleName" = "./EcuMModuleID"!][!//
[!IF "contains($Drivers, $ModuleName) = 'true'"!][!//
[!ERROR!][!//
ERROR: [!"$ModuleName"!] is configured to initialize more than once.
Check EcuMDriverListZero, EcuMDriverListOne, EcuMDriverListTwo and EcuMDriverListThree.
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "Drivers" = "concat($Drivers, $ModuleName)"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//


[!MACRO "GetConfigIndex", "ModName" = "", "CfgIndex" = ""!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[num:i($CfgIndex)]"!][!//
[!VAR "ErrorFlag" = "'0'"!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*)) - num:i(1)"!][!//
[!/* example[!//
ASpath:/Mcu/Mcu/Default_0[!//
ModuleConfigName should hold Default_0[!//
ObtainedModuleNamefromRef should hold Mcu, the second Mcu[!//[!//
Variable ModuleConfigIndex is updated in CG_GetModuleConfigIndex */!][!//
[!VAR "ModuleConfigRefPath1" = "(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[@index = $Index1])"!][!//
[!VAR "ModuleConfigRefPath" = "substring-after($ModuleConfigRefPath1, ":")"!][!//
[!VAR "ModuleConfigName1" = "substring-after($ModuleConfigRefPath, "/")"!][!//
[!VAR "ModuleConfigName1" = "substring-after($ModuleConfigName1, "/")"!][!//
[!VAR "ObtainedModuleNamefromRef" = "substring-before($ModuleConfigName1, "/")"!][!//
[!VAR "ModuleConfigName" = "substring-after($ModuleConfigRefPath, "/")"!][!//
[!VAR "ModuleConfigName" = "substring-after($ModuleConfigName, "/")"!][!//
[!VAR "ModuleConfigName" = "substring-after($ModuleConfigName, "/")"!][!//
[!IF "$ModName = $ObtainedModuleNamefromRef"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!CALL "CG_GetModuleConfigIndex",  "ModuleConfigRefPath" = "$ObtainedModuleNamefromRef", "ModuleConfigName" = "$ModuleConfigName"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* Special handling for FlexRay */!][!//
[!IF "$ModName = 'Fr_17_Eray' and $ObtainedModuleNamefromRef = 'Fr'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Fr')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "FrMultipleConfiguration/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for FlexRay */!][!//
[!/* Special handling for Icu */!][!//
[!IF "$ModName = 'Icu_17_GtmCcu6' and $ObtainedModuleNamefromRef = 'Icu'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "IcuConfigSet/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Icu */!][!//
[!/* Special handling for Can */!][!//
[!IF "$ModName = 'Can_17_MCanP' and $ObtainedModuleNamefromRef = 'Can'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Can')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "CanConfigSet/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Can */!][!//
[!/* Special handling for Fls */!][!//
[!IF "$ModName = 'Fls_17_Pmu' and $ObtainedModuleNamefromRef = 'Fls'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "FlsConfigSet/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Fls */!][!//
[!/* Special handling for Pwm */!][!//
[!IF "$ModName = 'Pwm_17_Gtm' and $ObtainedModuleNamefromRef = 'Pwm'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "PwmChannelConfigSet/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Pwm */!][!//
[!/* Special handling for Wdg */!][!//
[!IF "$ModName = 'Wdg_17_Scu' and $ObtainedModuleNamefromRef = 'Wdg'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Wdg')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "WdgSettingsConfig/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Wdg */!][!//
[!/* Special handling for Lin */!][!//
[!IF "$ModName = 'Lin_17_AscLin' and $ObtainedModuleNamefromRef = 'Lin'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Lin')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "LinGlobalConfig/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Lin */!][!//
[!/* Special handling for Eth */!][!//
[!IF "$ModName = 'Eth_17_EthMac' and $ObtainedModuleNamefromRef = 'Eth'"!][!//
[!VAR "ErrorFlag" = "'1'"!][!//
[!SELECT "as:modconf('Eth')[1]"!][!//
[!VAR "RefError" = "num:i(0)"!][!//
[!LOOP "EthConfigSet/*"!][!//
[!IF "$ModuleConfigName = @name"!][!//
[!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
[!VAR "RefError" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ASSERT "$RefError = num:i(1)"!][!//
Error: Given module ConfigSet reference [!"$ModuleConfigName"!] in EcuMFixedModuleConfigurationRef does not match with [!"$ModName"!] ConfigSet Name.
Please provide the correct Module reference path in EcuMFixedModuleConfigurationRef.[!//
[!ENDASSERT!][!//
[!ENDSELECT!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!/* End Special handling for Eth */!][!//
[!ENDFOR!][!//
[!IF "$ModName != 'Fee' and $ModName != 'RamTst' and $ModName != 'CanTrcv_17_6250GV33' and $ModName != 'CanTrcv_17_6251G' and $ModName != 'FlsLoader' and $ModName != 'Hssl'"!][!//
[!ASSERT "$ErrorFlag = '1'"!][!//
Error: Given module [!"$ModName"!] ID in EcuMDriverInitListOne EcuMDriverInitItem does not have a reference in EcuMFixedConfiguration/EcuMFixedModuleConfigurationRef.
Please select the Module reference path.[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//
