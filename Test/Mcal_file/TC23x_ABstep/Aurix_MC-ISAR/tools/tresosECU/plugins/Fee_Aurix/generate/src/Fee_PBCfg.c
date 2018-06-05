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
**  $FILENAME   : Fee_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\18 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-12 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Fee_PBCfg.c file                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
   [cover parentID=DS_NAS_FEE_PR700,DS_NAS_FEE_PR701,DS_NAS_FEE_PR115,
    DS_NAS_FEE_PR704,DS_NAS_FEE_PR707,DS_NAS_FEE_PR708,SAS_NAS_FEE_PR726,
    DS_NAS_FEE_PR712,DS_NAS_FEE_PR713,DS_NAS_FEE_PR714,DS_NAS_FEE_PR716,
    DS_NAS_FEE_PR717,DS_NAS_FEE_PR719,DS_NAS_FEE_PR720,DS_NAS_FEE_PR723,
    DS_NAS_FEE_PR724,DS_NAS_FEE_PR728,DS_AS_FEE102,DS_NAS_FEE_PR446,
    SAS_AS4XX_FEE_PR680,DS_NAS_FEE_PR709]
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
**  $FILENAME   : Fee_PBCfg.c $                                              **
**                                                                           **
**  $CC VERSION : \main\18 $                                                 **
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include Fee Module Header File */
#include "Fee.h"

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Fee')[1]"!][!//
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

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
**                      Global Function Declarations                          **
*******************************************************************************/
[!//
[!IF "node:exists(FeeGeneral/FeeNvmJobEndNotification/*[1]) = 'true'"!][!//
[!VAR "jobend" = "FeeGeneral/FeeNvmJobEndNotification/*[1]"!][!//
[!ELSE!][!//
[!VAR "jobend" = "'NULL_PTR'"!][!//
[!ENDIF!][!//
[!IF "node:exists(FeeGeneral/FeeNvmJobErrorNotification/*[1]) = 'true'"!][!//
[!VAR "joberror" = "FeeGeneral/FeeNvmJobErrorNotification/*[1]"!][!//
[!ELSE!][!//
[!VAR "joberror" = "'NULL_PTR'"!][!//
[!ENDIF!][!//
[!VAR "illegalnotif" = "FeeIfxSpecificConfig/FeeIllegalStateNotification"!][!//
[!//
[!IF "num:isnumber($jobend) != 'true'"!][!//
[!IF "$jobend != 'NvM_JobEndNotification'"!][!//
[!IF "$jobend != 'NULL_PTR'"!][!//
[!IF "$jobend != ''"!][!//
[!IF "$jobend != '""'"!][!//

/* Job End Notification Function */
extern void [!"$jobend"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "num:isnumber($joberror) != 'true'"!][!//
[!IF "$joberror != 'NvM_JobErrorNotification'"!][!//
[!IF "$joberror != 'NULL_PTR'"!][!//
[!IF "$joberror != ''"!][!//
[!IF "$joberror != '""'"!][!//

/* Job Error Notification Function */
extern void [!"$joberror"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "num:isnumber($illegalnotif) != 'true'"!][!//
[!IF "$illegalnotif != 'NULL_PTR'"!][!//
[!IF "$illegalnotif != ''"!][!//
[!IF "$illegalnotif != '""'"!][!//

/* Illegal State Notification Function */
extern void [!"$illegalnotif"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
[!//
[!VAR "Count" = "'0'"!][!//
[!LOOP "FeeBlockConfiguration/*"!][!//
[!VAR "Count" = "$Count + '1'"!][!//
[!ENDLOOP!][!//
[!//
[!VAR "temp_count" = "'0'"!][!//
[!VAR "state_data_struct" = "FeeIfxSpecificConfig/FeeStateVarStructure"!][!//

/* Allocate space for state data variables in RAM */
#define FEE_START_SEC_VAR_FAST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* Fee State Variable structure */
static Fee_StateDataType [!"$state_data_struct"!];

#define FEE_STOP_SEC_VAR_FAST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!SELECT "as:modconf('Fls')[1]/FlsGeneral"!][!//
[!VAR "FeeFlsSectorSize" = "num:i(FlsTotalSize div 2)"!][!//
[!VAR "FeeAllowedBlockSize" = "num:i((($FeeFlsSectorSize - 1024 - 16) * 7) div 8)"!][!//
[!IF "$FeeAllowedBlockSize > 65535"!][!//
[!VAR "FeeAllowedBlockSize" = "num:i(65535)"!][!//
[!ENDIF!][!//
[!VAR "FeeAllowedThresholdSize" = "num:i($FeeFlsSectorSize - 1024 - 24)"!][!//
[!ENDSELECT!][!//

/* User configured logical block initialization structure */
#define FEE_START_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!IF "$Count > 1"!][!//
static const Fee_BlockType Fee_BlockConfig[] =
[!ELSE!][!//
static const Fee_BlockType Fee_BlockConfig =
[!ENDIF!][!//
{
[!LOOP "FeeBlockConfiguration/*"!][!//
[!IF "$Count > 1"!][!//
  {
[!ENDIF!][!//
[!VAR "imm" = "FeeImmediateData"!][!//
[!VAR "blk_num" = "FeeBlockNumber"!][!//
[!VAR "blk_size" = "FeeBlockSize"!][!//
[!IF "$blk_size > $FeeAllowedBlockSize"!][!//
[!ERROR!][!//
Error: Block size should not exceed the allowed limit ([!"$FeeAllowedBlockSize"!]).
Maximum block size that can be configured depends on the configured value of FlsTotalSize in FLS driver.
[!ENDERROR!][!//
[!ENDIF!][!//
[!VAR "blk_cycle_count" = "FeeNumberOfWriteCycles"!][!//
    [!"$blk_cycle_count"!]U, /* Block Cycle Count */
[!IF "$imm = 'true'"!][!//
    (uint8)FEE_IMMEDIATE_DATA,  /* Block type is Immediate */
[!ELSE!][!//
    (uint8)FEE_NORMAL_DATA,     /* Block type is Normal */
[!ENDIF!][!//
    [!"$blk_num"!]U, /* Block number */
    [!"$blk_size"!]U /* Fee Block Size */
[!VAR "temp_count" = "$temp_count + '1'"!][!//
[!IF "$Count > 1"!][!//
[!IF "$temp_count = $Count"!][!//
  }
[!ELSE!][!//
  },
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
};

[!VAR "unconfig" = "FeeIfxSpecificConfig/FeeUnConfigBlock"!][!//
[!VAR "useerasesuspend" = "FeeIfxSpecificConfig/FeeUseEraseSuspend"!][!//
[!SELECT "as:modconf('Fls')[1]/FlsIfxSpecificConfig"!][!//
[!IF "FlsUseEraseSuspend = 'false'"!][!//
[!IF "$useerasesuspend = 'true'"!][!//
[!ERROR!][!//
Error: Flash (FLS driver) should support erase suspend/resume feature!
Check the configuration parameter FlsUseEraseSuspend in FLS module.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!VAR "eraseallenable" = "FeeIfxSpecificConfig/FeeEraseAllEnable"!][!//
[!VAR "gc_restart" = "FeeIfxSpecificConfig/FeeGcRestart"!][!//
[!VAR "threshold" = "FeeIfxSpecificConfig/FeeThresholdValue"!][!//
[!IF "$threshold > $FeeAllowedThresholdSize"!][!//
[!ERROR!][!//
Error: Configured value of FeeThresholdValue is more than the allowed limit ([!"$FeeAllowedThresholdSize"!]).
Maximum allowed value of FeeThresholdValue depends on the configured value of FlsTotalSize in FLS driver.
[!ENDERROR!][!//
[!ENDIF!][!//
/* Fee Global initialization structure. */
const Fee_ConfigType Fee_ConfigRoot[] =
{
  {
    /* Fee State Data Structure */
    &[!"$state_data_struct"!],
    /* Pointer to logical block configurations */
[!IF "$Count > 1"!][!//
    &Fee_BlockConfig[0],
[!ELSE!][!//
    &Fee_BlockConfig,
[!ENDIF!][!//
[!IF "num:isnumber($jobend) != 'true'"!][!//
[!IF "$jobend = '""' or $jobend = '' or $jobend = 'NULL_PTR'"!][!//
[!VAR "jobend" = "'(Fee_NotifFunctionPtrType)NULL_PTR'"!][!//
[!ELSE!][!//
[!VAR "jobend" = "concat('&',$jobend)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "jobend" = "concat('(Fee_NotifFunctionPtrType)',$jobend)"!][!//
[!ENDIF!][!//
    /* Fee Job end notification API */
    [!"$jobend"!],
[!IF "num:isnumber($joberror) != 'true'"!][!//
[!IF "$joberror = '""' or $joberror = '' or $joberror = 'NULL_PTR'"!][!//
[!VAR "joberror" = "'(Fee_NotifFunctionPtrType)NULL_PTR'"!][!//
[!ELSE!][!//
[!VAR "joberror" = "concat('&',$joberror)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "joberror" = "concat('(Fee_NotifFunctionPtrType)',$joberror)"!][!//
[!ENDIF!][!//
    /* Fee Job error notification API */
    [!"$joberror"!],
    /* Fee threshold value */
    [!"$threshold"!]U,
    /* Number of blocks configured */
    [!"num:i($Count)"!]U,

    {
[!IF "$unconfig = 'FEE_UNCONFIG_BLOCK_IGNORE'"!][!//
      /* Ignore the unconfigured blocks */
      FEE_UNCONFIG_BLOCK_IGNORE,
[!ELSE!][!//
      /* Keep the unconfigured blocks */
      FEE_UNCONFIG_BLOCK_KEEP,
[!ENDIF!][!//
[!IF "$gc_restart = 'FEE_GC_RESTART_INIT'"!][!//
      /* Restart Garbage Collection during initialization */
      FEE_GC_RESTART_INIT,
[!ELSE!][!//
      /* Restart Garbage Collection when user job is requested */
      FEE_GC_RESTART_WRITE,
[!ENDIF!][!//
[!IF "$useerasesuspend = 'true'"!][!//
      /* Erase Suspend feature is enabled */
      FEE_ERASE_SUSPEND_ENABLED,
[!ELSE!][!//
      /* Erase Suspend feature is disabled */
      FEE_ERASE_SUSPEND_DISABLED,
[!ENDIF!][!//
      /* Reserved */
      0U
    },

[!IF "num:isnumber($illegalnotif) != 'true'"!][!//
[!IF "$illegalnotif = '""' or $illegalnotif = '' or $illegalnotif = 'NULL_PTR'"!][!//
[!VAR "illegalnotif" = "'(Fee_NotifFunctionPtrType)NULL_PTR'"!][!//
[!ELSE!][!//
[!VAR "illegalnotif" = "concat('&',$illegalnotif)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "illegalnotif" = "concat('(Fee_NotifFunctionPtrType)',$illegalnotif)"!][!//
[!ENDIF!][!//
    /* Fee Illegal State notification */
    [!"$illegalnotif"!],
[!IF "$eraseallenable = 'true'"!][!//
    /* Erase All feature is enabled */
    (boolean)TRUE
[!ELSE!][!//
    /* Erase All feature is disabled */
    (boolean)FALSE
[!ENDIF!][!//
  }
};

#define FEE_STOP_SEC_CONST_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define FEE_START_SEC_SPL_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
const Fee_ConfigType * Fee_CfgPtr = &Fee_ConfigRoot[0];
#define FEE_STOP_SEC_SPL_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!ENDSELECT!][!//
