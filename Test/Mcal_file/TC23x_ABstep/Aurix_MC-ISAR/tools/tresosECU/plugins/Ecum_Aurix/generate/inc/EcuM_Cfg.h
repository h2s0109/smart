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
**   $FILENAME   : EcuM_Cfg.h $                                               **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
**                                                                            **
**   $DATE       : 2014-11-07 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for EcuM_Cfg.h file                          **
**                                                                            **
**   SPECIFICATION(S) : AUTOSAR_SWS_ECU_StateManager.pdf, AS4.0               **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: no                                      **
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
**   $FILENAME   : EcuM_Cfg.h $                                               **
**                                                                            **
**   $CC VERSION : \main\15 $                                                 **
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
**   SPECIFICATION(S) : AUTOSAR_SWS_ECU_StateManager.pdf, AS V4.0             **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
*******************************************************************************/
[!NOCODE!]
[!INCLUDE "EcuM.m"!][!//
[!ENDNOCODE!]

#ifndef ECUM_CFG_H
#define ECUM_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]
/* Autosar version of the module */
#define ECUM_AS_VERSION ([!"$NewString"!])

/* AUTOSAR specification version numbers */
[!IF "$MajorVersion = num:i(4)"!][!//
#define ECUM_AR_RELEASE_MAJOR_VERSION      ([!"$MajorVersion"!]U)
#define ECUM_AR_RELEASE_MINOR_VERSION      ([!"$MinorVersion"!]U)
#define ECUM_AR_RELEASE_REVISION_VERSION   ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define ECUM_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define ECUM_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define ECUM_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)


[!NOCODE!][!//
[!VAR "McuPBFixedAddress"   =  "'false'"!][!//
[!VAR "MCU_PB_FIXEDADDR"  =  "'STD_OFF'"!][!//

[!SELECT "as:modconf('Mcu')[1]"!][!//
[!IF "node:exists(McuGeneralConfiguration/McuPBFixedAddress)"!][!//
[!VAR "McuPBFixedAddress" = "McuGeneralConfiguration/McuPBFixedAddress"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$McuPBFixedAddress = 'true'"!][!//
	[!VAR "MCU_PB_FIXEDADDR" = "'STD_ON'"!][!//	
[!ENDIF!][!//		
[!ENDNOCODE!][!//
[!IF "$MCU_PB_FIXEDADDR = 'STD_ON'"!]
/* Macros indicating the Mcu using the fixed address STD_ON */	
#define MCU_USES_FIXED_ADDR   (STD_ON)	[!//
[!ELSE!]
/* Macros indicating the Mcu using the fixed address STD_OFF. */	
#define MCU_USES_FIXED_ADDR   (STD_OFF)	[!//
[!ENDIF!]
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*"!][!//
/* Macros indicating the modules used by ECU State Manager */
[!VAR "ModuleName" = "'YYY'"!][!//	
[!VAR "McuModUsed" = "'OFF'"!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!SELECT "EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]"!][!//
[!LOOP "EcuMDriverInitItem/*"!][!//
[!VAR "EcuMModId" = "EcuMModuleID"!][!//
[!IF "$EcuMModId = 'Mcu'"!][!//
[!VAR "McuModUsed " = "'ON'"!][!//
[!ENDIF!][!//
[!IF "$EcuMModId = 'Fee' or $EcuMModId = 'RamTst' or $EcuMModId = 'CanTrcv_17_6251G' or $EcuMModId = 'CanTrcv_17_6250GV33' or $EcuMModId = 'FlsLoader' or $EcuMModId = 'Hssl' "!][!//
#define ECUM_USES_[!"translate(($EcuMModId), 'abcdefghijklmnopqrstuvwxyz', 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')"!]
[!ENDIF!][!//
[!ENDLOOP!][!//	
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "TotalMcuModuleConfiguration" = "num:i(count(McuModuleConfiguration/*))"!][!//
[!FOR "McuCfgPosition" ="num:i(1)" TO "num:i($TotalMcuModuleConfiguration)"!][!//
[!VAR "GtmConfigured" = "num:i(count(McuModuleConfiguration/*[num:i($McuCfgPosition)]/GtmConfiguration/*))"!][!//
[!VAR "EruConfigured" = "num:i(count(McuModuleConfiguration/*[num:i($McuCfgPosition)]/EruConfiguration/*))"!][!//
[!VAR "CcuConfigured" = "num:i(count(McuModuleConfiguration/*[num:i($McuCfgPosition)]/CcuConfiguration/*))"!][!//
[!IF "$GtmConfigured >= num:i(1)"!][!// 
#define ECUM_USES_GTM
[!ENDIF!][!//
[!IF "$EruConfigured >= num:i(1)"!][!//
#define ECUM_USES_ERU
[!ENDIF!][!//
[!IF "$CcuConfigured >= num:i(1)"!][!//
#define ECUM_USES_CCU
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!IF "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1]) = 'true'"!][!//
[!CALL "CG_BuildIncludeFileList", "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!][!//
[!ENDIF!][!//									 
[!ENDIF!][!//

/*
Configuration Options: Ecum_PostBuildConfigType 
SELECTABLE : Post Build Selectable
LOADABLE : Post Build Loadable.
*/
#define ECUM_SELECTABLE (0)
#define ECUM_LOADABLE (1U)
/*
Configuration: Ecum_PostBuildConfigType 
SELECTABLE : Post Build Selectable
LOADABLE : Post Build Loadable.
*/

#define ECUM_POSTBUILD_CONFIG_TYPE (ECUM_[!"EcuMPostBuildConfigType"!])

[!VAR "FlsInitialized" = "num:i(0)"!][!//
/*
Configuration: EcuM_DriverInitListZeroConfig 
*/
#define EcuM_DriverInitListZeroConfig() \
{\
}
/*
Configuration: EcuM_DriverInitListOneConfig 
*/
#define EcuM_DriverInitListOneConfig(configptr) \
{\
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!IF "node:exists(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[1]) = 'true'"!][!//
[!CALL "CG_BuildDriverCallList", "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
}

/*
Configuration: EcuM_DriverInitListTwoConfig 
*/
#define EcuM_DriverInitListTwoConfig(configptr) \
{\
}
/*
Configuration: EcuM_DriverInitListThreeConfig 
*/
#define EcuM_DriverInitListThreeConfig(configptr) \
{\
}

/*
Configuration: EcuM_DriverRestartListConfig 
*/
#define EcuM_DriverRestartListConfig() \
{\
}
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/***********************************************
 Structure of post-build configuration data for the EcuM.
 The structure elements are generated by code generator, depending upon the 
 modules used in PB configuration
  
***********************************************/
typedef struct EcuM_ConfigType_Tag 
{
  /* Identifier for post-build time configuration */
  const uint16                         ConfigurationIdentifier;
  /* Hash Identifier of pre compile time configuration */
  const uint32                         PreCompileIdentifier; 
  /* Pointers to config data of other MCAL modules (Post-build Only) */    
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!CALL "CG_BuildPBDriverCfgTypeList", "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!]
[!ENDIF!][!//

 /* EcuM internal configuration data */
  const uint8               LocalConfigData;
}EcuM_ConfigType;

[!NOCODE!][!//
[!//  Error Checks:
[!FOR "Index1" = "num:i(0)" TO "num:i(count(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*)) - num:i(1)"!][!//
[!VAR "ModuleMapped" = "'STD_OFF'"!][!//
[!VAR "Selection" = "(EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef/*[@index = $Index1])"!][!//
[!VAR "ModuleConfigName" = "substring-after($Selection, "ASPath:/")"!][!//
[!VAR "ModuleName1" = "substring-after($ModuleConfigName, "/")"!][!//
[!VAR "RefModuleName" = "substring-before($ModuleName1, "/")"!][!//
[!IF "$ModuleMapped = 'STD_OFF'"!][!//
[!IF "node:exists(EcuMCommonConfiguration/EcuMDriverInitListOne/*[1]) = 'true'"!][!//
[!CALL "CG_RefCheck", "List" = "'EcuMCommonConfiguration/EcuMDriverInitListOne'"!]
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$ModuleMapped = 'STD_OFF'"!][!//
[!ERROR!][!//
ERROR: "The Selected  "[!"$RefModuleName"!]" Module Reference in the EcuMFixedConfiguration/*[1]/EcuMFixedModuleConfigurationRef is not 
matched with EcuMDriverInitListOne DriverInitItem -- > EcuMModuleID.  (For Ex:(Icu/Mcu))"
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!NOCODE!][!//
[!LOOP "EcuMCommonConfiguration/EcuMDriverInitListOne/*"!][!//
[!LOOP "EcuMDriverInitItem/*[1]"!][!//
[!VAR "ModuleName" = "./EcuMModuleID"!][!//
[!IF "$ModuleName != 'Mcu'"!][!//
[!ERROR!][!//
ERROR: Mcu Should be first Item of EcuMDriverInitListOne, EcuMDriverInitItem
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

[!IF "EcuMPostBuildConfigType = 'SELECTABLE'"!]
/*******************************************************************************
 * Exported name of post-build selectable configuration data for EcuM. 
 * Defined in the EcuM_Cfg.c
 ******************************************************************************/
#define ECUM_START_SEC_POSTBUILDCFG
#include "MemMap.h"

extern const struct EcuM_ConfigType_Tag EcuM_ConfigAlternative[] ;

#define ECUM_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
[!ELSE!]
/*******************************************************************************
 * Exported name of post-build loadable configuration data for EcuM. 
 * Defined in the EcuM_Cfg.c
 ******************************************************************************/
#define ECUM_START_SEC_POSTBUILDCFG
#include "MemMap.h"
	
extern const struct EcuM_ConfigType_Tag EcuM_ConfigRoot;

#define ECUM_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

#define ECUM_START_SEC_VAR_32BIT
#include "MemMap.h"

extern const struct EcuM_ConfigType_Tag *EcuM_ConfigAddressPtr;

#define ECUM_STOP_SEC_VAR_32BIT
#include "MemMap.h"
[!ENDIF!]
/************************************************
 * Declare parameter implemented as const.
 * Defined in the EcuM_Cfg.c
 ***********************************************/
#define ECUM_START_SEC_CONST_32BIT
#include "MemMap.h"

extern const uint32 EcuM_ConfigConsistencyHash;

#define ECUM_STOP_SEC_CONST_32BIT
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declaration	s                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!]
#endif  /* _ECUM_CFG_H */
