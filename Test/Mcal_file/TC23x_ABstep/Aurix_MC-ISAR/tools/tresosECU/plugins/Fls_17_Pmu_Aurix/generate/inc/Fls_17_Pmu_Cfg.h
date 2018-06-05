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
**  $FILENAME   : Fls_17_Pmu_Cfg.h $                                         **
**                                                                           **
**  $CC VERSION : \main\46 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Fls_17_Pmu_Cfg.h file                   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
                 [cover parentID=DS_AS_FLS251_FLS001_2,
                  DS_NAS_FLS_PR1052,DS_NAS_FLS_PR734,DS_NAS_FLS_PR700,
                  DS_NAS_FLS_PR701,DS_NAS_FLS_PR704,DS_NAS_FLS_PR707,
                  DS_NAS_FLS_PR709,DS_NAS_FLS_PR712,DS_NAS_FLS_PR713,
                  DS_NAS_FLS_PR716,DS_NAS_FLS_PR717,DS_NAS_FLS_PR719,
                  DS_NAS_FLS_PR723,DS_NAS_FLS_PR724,DS_NAS_FLS_PR728,
                  DS_AS403_FLS365_1,DS_AS403_FLS365_2,DS_AS403_FLS365_3,
                  DS_AS403_FLS365_4,DS_AS403_FLS365_5,DS_AS403_FLS365_6,
                  DS_AS403_FLS365_7,DS_AS403_FLS365_8,DS_AS403_FLS322,
                  DS_NAS_FLS_PR708,DS_NAS_FLS_PR714,DS_NAS_FLS_PR720,
                  DS_AS4XX_FLS_PR2849,DS_NAS_FLS_PR914,SAS_AS4XX_FLS_PR678,
                  DS_NAS_HE2_FLS_PR3054_1,DS_NAS_EP_FLS_PR3054_1,
                  DS_NAS_HE2_FLS_PR3054_2,DS_NAS_EP_FLS_PR3054_2,
                  DS_NAS_HE2_FLS_PR3054_4,DS_NAS_EP_FLS_PR3054_4]
                 [/cover]
************************************************************************/!][!//
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
**  $FILENAME   : Fls_17_Pmu_Cfg.h $                                         **
**                                                                           **
**  $CC VERSION : \main\46 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : FLS configuration generated out of ECU configuration      **
**                   file (Fls_17_Pmu.bmd)                                   **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef FLS_17_PMU_CFG_H 
#define FLS_17_PMU_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Typedefs Imported from Mem Interface */ 
#include "MemIf_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!//
[!VAR "IfxFeeUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('Fee')[1]"!][!//
[!IF "node:exists(FeeIfxSpecificConfig) = 'true'"!][!//
[!VAR "IfxFeeUsed" = "'ON'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!//
/*
  Published parameters
*/

/* FLS Instance ID */
#define FLS_17_PMU_INSTANCE_ID                ((uint8)[!"num:i(FlsGeneral/FlsDriverIndex)"!])

#define Fls_17_PmuConf_FlsGeneral_FlsDriverIndex  (FLS_17_PMU_INSTANCE_ID)

[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "PatchVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
/* Autosar specification version */
#define FLS_17_PMU_AR_RELEASE_MAJOR_VERSION           ([!"$MajorVersion"!]U)
#define FLS_17_PMU_AR_RELEASE_MINOR_VERSION           ([!"$MinorVersion"!]U)
#define FLS_17_PMU_AR_RELEASE_REVISION_VERSION        ([!"$PatchVersion"!]U)
[!//
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//

/* Vendor specific implementation version information */
#define FLS_17_PMU_SW_MAJOR_VERSION           ([!"$SwMajorVersion"!]U)
#define FLS_17_PMU_SW_MINOR_VERSION           ([!"$SwMinorVersion"!]U)
#define FLS_17_PMU_SW_PATCH_VERSION           ([!"$SwPatchVersion"!]U)

/* Total Number of Config Sets */
#define FLS_17_PMU_CONFIG_COUNT               ([!"num:i(count(FlsConfigSet/*))"!]U)

/*
  The following macros will enable or disable a particular feature in FLS 
  module.Set the macro to STD_ON to enable the feature and STD_OFF to 
  disable the same.  
*/
/* Enable/Disable Development error detection(DET)  */
#define FLS_DEV_ERROR_DETECT         ([!//
[!IF "FlsGeneral/FlsDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Flash access code is to be loaded before job start true/false*/
#define FLS_AC_LOAD_ON_JOB_START     ([!//
[!IF "FlsGeneral/FlsAcLoadOnJobStart = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Flash job interrupt mode or polling mode*/
#define FLS_USE_INTERRUPTS          ([!//
[!IF "FlsGeneral/FlsUseInterrupts = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_cancel api selection*/
#define FLS_CANCEL_API             ([!//
[!IF "FlsGeneral/FlsCancelApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_SetMode api selection*/
#define FLS_SET_MODE_API             ([!//
[!IF "FlsGeneral/FlsSetModeApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_compare api selection*/
#define FLS_COMPARE_API            ([!//
[!IF "FlsGeneral/FlsCompareApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_GetJobResult api selection*/
#define FLS_GET_JOB_RESULT_API     ([!//
[!IF "FlsGeneral/FlsGetJobResultApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_GetStatus api selection*/
#define FLS_GET_STATUS_API         ([!//
[!IF "FlsGeneral/FlsGetStatusApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_GetVersionInfo api selection*/
#define FLS_VERSION_INFO_API   ([!//
[!IF "FlsGeneral/FlsVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Erase suspend/resume feature selection*/
#define FLS_USE_ERASESUSPEND   ([!//
[!IF "FlsIfxSpecificConfig/FlsUseEraseSuspend = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*Fls_ResetSftAtInit Feature selection*/
#define FLS_RESET_SFR_INIT    ([!//
[!IF "FlsGeneral/FlsResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


/* Enable/Disable Debug support  */
[!IF "FlsGeneral/FlsDebugSupport = 'true'"!][!//
#define FLS_DEBUG_SUPPORT     (STD_ON)

[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!IF "$PostBuildType = 'SELECTABLE'"!][!//
/* define the state variable for extern declaration in Fls_17_Pmu_Dbg.h*/
[!VAR "state_data_struct" = "FlsIfxSpecificConfig/FlsStateVarStruct"!][!//
#define FLS_STATE_VAR       [!"$state_data_struct"!]
[!ENDIF!][!//
[!ELSE!][!//
#define FLS_DEBUG_SUPPORT     (STD_OFF)
[!ENDIF!][!//


[!IF "$IfxFeeUsed = 'ON'"!][!//
/* IFX FEE is being used in configuration */
#define FLS_IFX_FEE_USED        (STD_ON)
[!ELSE!][!//
/* IFX FEE is not in use */
#define FLS_IFX_FEE_USED        (STD_OFF)
[!ENDIF!][!//

/*DFLASH base/start address*/
#define FLS_BASE_ADDRESS           ([!"num:inttohex(FlsGeneral/FlsBaseAddress)"!]U)

/*DFLASH total size*/
#define FLS_TOTAL_SIZE             ([!"num:inttohex(FlsGeneral/FlsTotalSize)"!]U)

#define DFLASH_BANK0_PHYSICAL    (FLS_BASE_ADDRESS)

/* Macro to Define  FLS_OFFSET of DFLASH0 and DFLASH1 */
#define FLS_OFFSET               ((uint32)[!"num:inttohex(FlsGeneral/FlsTotalSize div 2)"!]U)


/* Physical Adress of data flash bank 1 */
#define DFLASH_BANK1_PHYSICAL    ([!"num:inttohex(num:add(num:i(FlsGeneral/FlsBaseAddress), num:i(FlsGeneral/FlsTotalSize div 2)))"!]U)

[!VAR "NumberofSector" = "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*[1]/FlsNumberOfSectors"!][!//
[!VAR "SectorAddress" = "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*[1]/FlsSectorStartaddress"!][!//
[!VAR "SectorPageSize" = "FlsConfigSet/*[1]/FlsSectorList/FlsSector/*[1]/FlsPageSize"!][!//

/* Number of DFLASH Banks */
#define FLS_NUMBER_OF_SECTORS    ([!"$NumberofSector"!]U) /* FLS_NUMBER_OF_SECTORS */
#define FLS_SECTOR_STARTADDRESS ([!"$SectorAddress"!]U)
/* Total size of each Data flash bank */
#define FLS_SECTOR_SIZE          ([!"num:inttohex(FlsGeneral/FlsTotalSize div 2)"!]U) /* FLS_SECTOR_SIZE */
/* Page size of the Data flash is 128 bytes */
#define FLS_PAGE_SIZE            ([!"$SectorPageSize"!]U)  /* FLS_PAGE_SIZE */
/* Number of Flash logical sectors to be erased in one erase command */
#define FLS_ERASE_SECTORS    ([!"num:i(FlsGeneral/FlsTotalSize div 16384)"!]U)

[!NOCODE!][!//
[!//
[!VAR "TotalFlsConfig" = "num:i(count(FlsConfigSet/*))"!][!//
[!/* Determine only one FlsConfigSet is configured 
                                        when FlsPBFixedAddress = true.*/!]
[!IF "FlsGeneral/FlsPBFixedAddress = 'true'"!][!//
[!//
[!ASSERT "not($TotalFlsConfig != 1)"!][!//
Config Error: when FlsGeneral/FlsPBFixedAddress is set as true, [!//
Only one FlsConfigSet configuration is allowed. [!//
But FlsConfigSet has more than one configuration.[!//
[!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

[!IF "node:exists(FlsGeneral/FlsPBFixedAddress)"!][!//
#define FLS_PB_FIXEDADDR          ([!//
[!IF "FlsGeneral/FlsPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ELSE!][!//
/* If the feature is not used then configuration is generated with default */
#define FLS_PB_FIXEDADDR          (STD_OFF)
[!ENDIF!][!//

[!IF "(FlsGeneral/FlsRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "FlsGeneral/FlsUserModeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "FlsGeneral/FlsUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: FlsRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
FlsUserModeRuntimeApiEnable or FlsUserModeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: FLS_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "FlsGeneral/FlsRunningInUser0Mode = 'true'"!][!//
#define FLS_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define FLS_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: FLS_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "FlsGeneral/FlsUserModeInitApiEnable = 'true'"!][!//
#define FLS_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  FLS_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: FLS_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init APIs
- if STD_OFF, Disable Protected mode in APIs other than Init APIs
*/
[!IF "FlsGeneral/FlsUserModeRuntimeApiEnable = 'true'"!][!//
#define FLS_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  FLS_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//


/* erase and write times are published in us */
[!VAR "EraseTime" = "FlsPublishedInformation/FlsEraseTime"!][!//
#define FLS_17_PMU_ERASE_TIME            ([!"num:i($EraseTime)"!]U)

[!VAR "WriteTime" = "FlsPublishedInformation/FlsWriteTime"!][!//
#define FLS_17_PMU_WRITE_TIME            ([!"num:i($WriteTime)"!]U)


[!VAR "CompareFailDemReport" = "num:i(0)"!][!//
[!VAR "EraseFailDemReport" = "num:i(0)"!][!//
[!VAR "ReadFailDemReport" = "num:i(0)"!][!//
[!VAR "WriteFailDemReport" = "num:i(0)"!][!//
[!VAR "FlsTotalConfig" = "num:i(count(FlsConfigSet/*))"!][!//
[!FOR "ModuleId" ="num:i(1)" TO "num:i($FlsTotalConfig)"!][!//
[!SELECT "FlsConfigSet/*[num:i($ModuleId)]"!][!//
[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_COMPARE_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_COMPARE_FAILED/*[1]) != '' )"!][!//
[!VAR "CompareFailDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//

[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_ERASE_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_ERASE_FAILED/*[1]) != '' )"!][!//
[!VAR "EraseFailDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//

[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_WRITE_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_WRITE_FAILED/*[1]) != '' )"!][!//
[!VAR "WriteFailDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//

[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_READ_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_READ_FAILED/*[1]) != '' )"!][!//
[!VAR "ReadFailDemReport" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

[!IF "$CompareFailDemReport = num:i(1)"!][!//
#define FLS_E_COMPARE_FAILED_DEM_REPORT    (ENABLE_DEM_REPORT)
[!ELSE!][!//
#define FLS_E_COMPARE_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!IF "$EraseFailDemReport = num:i(1)"!][!//
#define FLS_E_ERASE_FAILED_DEM_REPORT    (ENABLE_DEM_REPORT)
[!ELSE!][!//
#define FLS_E_ERASE_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!IF "$WriteFailDemReport = num:i(1)"!][!//
#define FLS_E_WRITE_FAILED_DEM_REPORT    (ENABLE_DEM_REPORT)
[!ELSE!][!//
#define FLS_E_WRITE_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!IF "$ReadFailDemReport = num:i(1)"!][!//
#define FLS_E_READ_FAILED_DEM_REPORT    (ENABLE_DEM_REPORT)
[!ELSE!][!//
#define FLS_E_READ_FAILED_DEM_REPORT    (DISABLE_DEM_REPORT)
[!ENDIF!][!//

/* Hardare Timeout for Command cycle*/
#define FLS_CMDCYCLE_TIMEOUT            (25U)

/*Timeout for Erase suspend/resume feature*/
#if (FLS_USE_ERASESUSPEND == STD_ON)
#define FLS_ERASESUSPEND_TIMEOUT        ([!"num:inttohex(FlsIfxSpecificConfig/FlsEraseSuspendTimeout)"!]U)
#endif

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
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* FLS_17_PMU_CFG_H */
[!ENDSELECT!]
