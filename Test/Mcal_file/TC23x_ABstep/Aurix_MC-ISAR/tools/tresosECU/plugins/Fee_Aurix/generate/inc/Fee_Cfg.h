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
**  $FILENAME   : Fee_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\26 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Fee_Cfg.h file                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
    [cover parentID=DS_NAS_FEE_PR700,DS_NAS_FEE_PR708,DS_NAS_FEE_PR914,
     DS_NAS_FEE_PR701,DS_NAS_FEE_PR704,DS_NAS_FEE_PR707,SAS_AS4XX_FEE_PR678,
     DS_NAS_FEE_PR712,DS_NAS_FEE_PR713,DS_NAS_FEE_PR714,
     DS_NAS_FEE_PR716,DS_NAS_FEE_PR717,DS_NAS_FEE_PR719,
     DS_NAS_FEE_PR723,DS_NAS_FEE_PR724,DS_NAS_FEE_PR728,
     SAS_AS_FEE060_FEE069_FEE002,DS_AS_FEE011_FEE062,
     DS_AS_FEE065,DS_NAS_FEE_PR446,DS_NAS_FEE_PR127,DS_AS_FEE045,
     DS_NAS_FEE_PR912,DS_AS4XX_FEE_PR2849,DS_NAS_FEE_PR720, 
     DS_NAS_FEE_PR1649]
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
**  $FILENAME   : Fee_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\26 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : FEE configuration generated out of ECU configuration      **
**                   file (Fee.bmd)                                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef  FEE_CFG_H
#define  FEE_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Typedefs Imported from Memory Abstract Interface */ 
#include "MemIf_Types.h"

/* Callback functions imported from NvM Module */
#include "NvM_Cbk.h"

/* Functions imported from Fls Module */
#include "Fls_17_Pmu.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
[!SELECT "as:modconf('Fee')[1]"!][!//

/* FEE AS version information */
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!][!//
#define FEE_AS_VERSION ([!"$NewString"!])
[!IF "$MajorVersion = num:i(4)"!][!//
#define FEE_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define FEE_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define FEE_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/* Vendor specific implementation version information */
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define FEE_SW_MAJOR_VERSION  ([!"$SwMajorVersion"!]U)
#define FEE_SW_MINOR_VERSION  ([!"$SwMinorVersion"!]U)
#define FEE_SW_PATCH_VERSION  ([!"$SwPatchVersion"!]U)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
                        
/*******************************************************************************
**                    Static configuration parameters                         **
*******************************************************************************/

/* Development error detection enabled/disabled */
[!IF "FeeGeneral/FeeDevErrorDetect = 'true'"!][!//
#define FEE_DEV_ERROR_DETECT       (STD_ON)
[!ELSE!][!//
#define FEE_DEV_ERROR_DETECT       (STD_OFF)
[!ENDIF!][!//

/* Fee_GetVersionInfo API enabled/disabled */
[!IF "FeeGeneral/FeeVersionInfoApi = 'true'"!][!//
#define FEE_VERSION_INFO_API       (STD_ON)
[!ELSE!][!//
#define FEE_VERSION_INFO_API       (STD_OFF)
[!ENDIF!][!//

/* Fee_GetCycleCount API enabled/disabled */
[!IF "FeeIfxSpecificConfig/FeeGetCycleCountApi = 'true'"!][!//
#define FEE_GET_CYCLE_COUNT_API    (STD_ON)
[!ELSE!][!//
#define FEE_GET_CYCLE_COUNT_API    (STD_OFF)
[!ENDIF!][!//

/* Fee_SetMode API enabled/disabled */
[!IF "FeeGeneral/FeeSetModeSupported = 'true'"!][!//
#define FEE_SET_MODE_SUPPORTED     (STD_ON)
[!ELSE!][!//
#define FEE_SET_MODE_SUPPORTED     (STD_OFF)
[!ENDIF!][!//

/* Fee_17_GetPrevData API enabled/disabled */
[!IF "FeeIfxSpecificConfig/FeeGetPrevDataApi = 'true'"!][!//
#define FEE_GET_PREV_DATA_API      (STD_ON)
[!ELSE!][!//
#define FEE_GET_PREV_DATA_API      (STD_OFF)
[!ENDIF!][!//

[!IF "FeeIfxSpecificConfig/FeeMaxBytesPerCycle = 'FEE_MAX_BYTES_64'"!][!//
#define FEE_MAX_BYTES_PER_CYCLE      (64U)
[!ELSEIF "FeeIfxSpecificConfig/FeeMaxBytesPerCycle = 'FEE_MAX_BYTES_128'"!][!//
#define FEE_MAX_BYTES_PER_CYCLE      (128U)
[!ELSEIF "FeeIfxSpecificConfig/FeeMaxBytesPerCycle = 'FEE_MAX_BYTES_256'"!][!//
#define FEE_MAX_BYTES_PER_CYCLE      (256U)
[!ELSE!][!//
#define FEE_MAX_BYTES_PER_CYCLE      (512U)
[!ENDIF!][!//
[!IF "FeeIfxSpecificConfig/FeeVirginFlashIllegalState = 'true'"!][!//
/* FEE reaches illegal state upon detection virgin flash */
#define FEE_VIRGIN_FLASH_ILLEGAL_STATE      (STD_ON)
[!ELSE!][!//
/* FEE programs state pages upon detection of virgin flash */
#define FEE_VIRGIN_FLASH_ILLEGAL_STATE      (STD_OFF)
[!ENDIF!][!//

/* Enable/Disable Debug support  */
[!IF "FeeGeneral/FeeDebugSupport = 'true'"!][!//
#define FEE_DEBUG_SUPPORT     (STD_ON)
/* define the state variable for extern declaration in Fee_Dbg.h*/
[!VAR "state_data_struct" = "FeeIfxSpecificConfig/FeeStateVarStructure"!][!//
#define FEE_STATE_VAR       [!"$state_data_struct"!]
[!ELSE!][!//
#define FEE_DEBUG_SUPPORT     (STD_OFF)
[!ENDIF!][!//

/* Erase suspend/resume feature supported in FLS */
[!SELECT "as:modconf('Fls')[1]/FlsIfxSpecificConfig"!][!//
#define FEE_FLS_SUPPORTS_ERASE_SUSPEND  ([!//
[!IF "FlsUseEraseSuspend = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!ENDSELECT!][!//

/* DFlash WordLine size */
#define FEE_DFLASH_WORDLINE_SIZE     ([!"num:i(ecu:get('Fee.FlsWordLineSize'))"!]U)

#define FEE_CONTINUE          (0U)
#define FEE_STOP_AT_GC        (1U)

#define FEE_UNCFG_BLK_OVERFLOW_HANDLE    ([!"FeeIfxSpecificConfig/FeeUnConfigBlkOverflowHandle"!])

/* Virtual page size, i.e., DF_EEPROM page size */
#define FEE_VIRTUAL_PAGE_SIZE      ([!"num:i(FeeGeneral/FeeVirtualPageSize)"!]U)

/* Logical block's overhead in bytes */
#define FEE_BLOCK_OVERHEAD         ([!"num:i(FeePublishedInformation/FeeBlockOverhead)"!]U)

/* Logical block's data page overhead in bytes */
#define FEE_PAGE_OVERHEAD          ([!"num:i(FeePublishedInformation/FeePageOverhead)"!]U)

/* Maximum blocking (delay) time in ms */
#define FEE_MAXIMUM_BLOCKING_TIME  ([!"num:i(FeePublishedInformation/FeeMaximumBlockingTime)"!]U)

/* Maximum number of configured blocks to be handled */
[!VAR "feemaxblkcnt" = "FeeIfxSpecificConfig/FeeMaxBlockCount"!][!//
[!IF "num:i(count(FeeBlockConfiguration/*)) > $feemaxblkcnt"!][!//
[!WARNING!][!//
More number of blocks are configured than the value specified for FeeMaxBlockCount!
Number of configured blocks: [!"num:i(count(FeeBlockConfiguration/*))"!]
Configured value of FeeMaxBlockCount: [!"$feemaxblkcnt"!]
It is recommended to configure the value of FeeMaxBlockCount appropriately!
[!ENDWARNING!][!//
[!VAR "feemaxblkcnt" = "num:i(count(FeeBlockConfiguration/*))"!][!//
[!ENDIF!][!//
[!SELECT "as:modconf('Fls')[1]/FlsGeneral"!][!//
[!VAR "FeeFlsSectorSize" = "num:i(FlsTotalSize div 2)"!][!//
[!VAR "FeeAllowedNumberOfBlocks" = "num:i((($FeeFlsSectorSize - 1024) div 24) - 10)"!][!//
[!ENDSELECT!][!//
[!IF "$feemaxblkcnt > $FeeAllowedNumberOfBlocks"!][!//
[!ERROR!][!//
Error: Number of Blocks configured is more than the allowed limit ([!"$FeeAllowedNumberOfBlocks"!]).
Maximum number of blocks that can be configured depends on the configured value of FlsTotalSize in FLS driver.
[!ENDERROR!][!//
[!ENDIF!][!//
#define FEE_MAX_BLOCK_COUNT        ([!"num:i($feemaxblkcnt)"!]U)

/* Symbolic names of logical blocks */
[!LOOP "FeeBlockConfiguration/*"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
#ifdef FeeConf_FeeBlockConfiguration_[!"$SymbolicName"!] 
/* to prevent double declaration */
#error FeeConf_FeeBlockConfiguration_[!"$SymbolicName"!] already defined
#else 
#define FeeConf_FeeBlockConfiguration_[!"$SymbolicName"!] ((uint16)[!"(num:i(./FeeBlockNumber))"!])
#endif /* #ifdef FeeConf_FeeBlockConfiguration_[!"$SymbolicName"!] */

[!ENDLOOP!][!//

#define FEE_DISABLE_DEM_REPORT   (0U)
#define FEE_ENABLE_DEM_REPORT    (1U)

[!VAR "FeeDemEnabled" = "num:i(0)"!][!//
/* DEM Configurations */
[!IF "(node:exists(FeeDemEventParameterRefs/*[1]) = 'true')"!][!//
[!SELECT "FeeDemEventParameterRefs/*[1]"!][!//
[!IF "(node:refexists(./FEE_E_GC_INIT/*[1]) = 'true') and (node:value(./FEE_E_GC_INIT/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_GC_INIT_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)
#define FEE_E_GC_INIT                (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_GC_INIT/*[1])))"!])
[!ELSE!][!//
#define FEE_GC_INIT_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_WRITE/*[1]) = 'true') and (node:value(./FEE_E_WRITE/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_WRITE_DEM_REPORT         (FEE_ENABLE_DEM_REPORT)
#define FEE_E_WRITE                  (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_WRITE/*[1])))"!])
[!ELSE!][!//
#define FEE_WRITE_DEM_REPORT         (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_READ/*[1]) = 'true') and (node:value(./FEE_E_READ/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_READ_DEM_REPORT          (FEE_ENABLE_DEM_REPORT)
#define FEE_E_READ                   (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_READ/*[1])))"!])
[!ELSE!][!//
#define FEE_READ_DEM_REPORT          (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_GC_WRITE/*[1]) = 'true') and (node:value(./FEE_E_GC_WRITE/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_GC_WRITE_DEM_REPORT      (FEE_ENABLE_DEM_REPORT)
#define FEE_E_GC_WRITE               (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_GC_WRITE/*[1])))"!])
[!ELSE!][!//
#define FEE_GC_WRITE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_GC_READ/*[1]) = 'true') and (node:value(./FEE_E_GC_READ/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_GC_READ_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)
#define FEE_E_GC_READ                (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_GC_READ/*[1])))"!])
[!ELSE!][!//
#define FEE_GC_READ_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_GC_ERASE/*[1]) = 'true') and (node:value(./FEE_E_GC_ERASE/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_GC_ERASE_DEM_REPORT      (FEE_ENABLE_DEM_REPORT)
#define FEE_E_GC_ERASE               (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_GC_ERASE/*[1])))"!])
[!ELSE!][!//
#define FEE_GC_ERASE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_INVALIDATE/*[1]) = 'true') and (node:value(./FEE_E_INVALIDATE/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_INVALIDATE_DEM_REPORT    (FEE_ENABLE_DEM_REPORT)
#define FEE_E_INVALIDATE             (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_INVALIDATE/*[1])))"!])
[!ELSE!][!//
#define FEE_INVALIDATE_DEM_REPORT    (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_WRITE_CYCLES_EXHAUSTED/*[1]) = 'true') and (node:value(./FEE_E_WRITE_CYCLES_EXHAUSTED/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_ENABLE_DEM_REPORT)
#define FEE_E_WRITE_CYCLES_EXHAUSTED (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_WRITE_CYCLES_EXHAUSTED/*[1])))"!])
[!ELSE!][!//
#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_GC_TRIG/*[1]) = 'true') and (node:value(./FEE_E_GC_TRIG/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_GC_TRIG_DEM_REPORT       (FEE_ENABLE_DEM_REPORT)
#define FEE_E_GC_TRIG                (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_GC_TRIG/*[1])))"!])
[!ELSE!][!//
#define FEE_GC_TRIG_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "(node:refexists(./FEE_E_UNCONFIG_BLK_EXCEEDED/*[1]) = 'true') and (node:value(./FEE_E_UNCONFIG_BLK_EXCEEDED/*[1]) != ' ' )"!][!//
[!VAR "FeeDemEnabled" = "num:i(1)"!][!//
#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_ENABLE_DEM_REPORT)
#define FEE_E_UNCONFIG_BLK_EXCEEDED  (DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FEE_E_UNCONFIG_BLK_EXCEEDED/*[1])))"!])
[!ELSE!][!//
#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
#define FEE_GC_INIT_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_WRITE_DEM_REPORT         (FEE_DISABLE_DEM_REPORT)
#define FEE_READ_DEM_REPORT          (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_WRITE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_READ_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_ERASE_DEM_REPORT      (FEE_DISABLE_DEM_REPORT)
#define FEE_INVALIDATE_DEM_REPORT    (FEE_DISABLE_DEM_REPORT)
#define FEE_WRITE_CYCLES_DEM_REPORT  (FEE_DISABLE_DEM_REPORT)
#define FEE_GC_TRIG_DEM_REPORT       (FEE_DISABLE_DEM_REPORT)
#define FEE_UNCFG_BLK_DEM_REPORT     (FEE_DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!IF "$FeeDemEnabled = num:i(1)"!][!//
#define FEE_DEM_ENABLED              (STD_ON)
[!ELSE!][!//
#define FEE_DEM_ENABLED              (STD_OFF)
[!ENDIF!][!//
[!ENDSELECT!][!//

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

#define FEE_CONFIG_PTR      (Fee_CfgPtr)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#endif /* #ifndef FEE_CFG_H */
