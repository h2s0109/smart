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
**  $FILENAME   : Fls_17_Pmu_PBCfg.c $                                       **
**                                                                           **
**  $CC VERSION : \main\42 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-17 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Fls_17_Pmu_PBCfg.c file                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
                 [cover parentID=DS_AS_FLS179,DS_AS_FLS205,DS_NAS_FLS_PR446,
                  DS_NAS_FLS_PR894,DS_NAS_FLS_PR700,DS_NAS_FLS_PR701,
                  DS_NAS_FLS_PR704,DS_NAS_FLS_PR707,DS_NAS_FLS_PR708,
                  DS_NAS_FLS_PR712,DS_NAS_FLS_PR713,DS_NAS_FLS_PR714,
                  DS_NAS_FLS_PR717,DS_NAS_FLS_PR719,DS_NAS_FLS_PR720,
                  DS_NAS_FLS_PR724,DS_NAS_FLS_PR728,SAS_AS_FLS107_FLS159,
                  DS_NAS_FLS_PR709,DS_NAS_FLS_PR716,DS_NAS_FLS_PR723,
                  DS_NAS_FLS_PR115,SAS_NAS_FLS_PR82,SAS_AS4XX_FLS_PR680]
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
**  $FILENAME   : Fls_17_Pmu_PBCfg.c $                                       **
**                                                                           **
**  $CC VERSION : \main\42 $                                                 **
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

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include Flash Module File */
#include "Fls_17_Pmu.h"
#include "Fls_17_Pmu_ac.h"
/* Include Diagnostic Error Manager Header */
#include "Dem.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

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

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!VAR "FlsTotalConfig" = "num:i(count(FlsConfigSet/*))"!][!//
[!FOR "ModuleId" ="num:i(1)" TO "num:i($FlsTotalConfig)"!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$FlsTotalConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!SELECT "as:modconf('Fls')[1]/FlsConfigSet/*[num:i($ModuleId)]"!][!//
[!IF "node:exists(./FlsJobEndNotification/*[1]) = 'true'"!][!//
[!VAR "Notification1" = "./FlsJobEndNotification/*[1]"!][!//
[!ELSE!][!//
[!VAR "Notification1" = "''"!][!//
[!ENDIF!][!//
[!IF "string-length($Notification1) = 0"!][!//
[!VAR "Notification1" = "'(Fls_NotifFunctionPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "$Notification1 = '"NULL"' or $Notification1 = 'NULL'or $Notification1 = 'NULL_PTR' or $Notification1 = ''"!][!//
[!VAR "Notification1" = "'(Fls_NotifFunctionPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
[!VAR "Notification1" = "concat('(Fls_NotifFunctionPtrType)',($Notification1))"!][!//
[!ELSE!][!//
[!VAR "Notification1" = "$Notification1"!][!//
[!ENDIF!][!//
[!IF "$Notification1 != '(Fls_NotifFunctionPtrType)0'"!][!//
/* Function declaration of Fls Job End Notification */
extern void [!"$Notification1"!](void);
[!ELSE!][!//
/* Job End Notification Function is not configured */
[!ENDIF!][!//

[!IF "node:exists(./FlsJobErrorNotification /*[1]) = 'true'"!][!//
[!VAR "Notification2" = "./FlsJobErrorNotification/*[1]"!][!//
[!ELSE!][!//
[!VAR "Notification2" = "''"!][!//
[!ENDIF!][!//
[!IF "string-length($Notification2) = 0"!][!//
[!VAR "Notification2" = "'(Fls_NotifFunctionPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "$Notification2 = '"NULL"' or $Notification2 = 'NULL' or $Notification2 = 'NULL_PTR' or $Notification2 = ''"!][!//
[!VAR "Notification2" = "'(Fls_NotifFunctionPtrType)0'"!][!//
[!ENDIF!][!//
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
[!VAR "Notification2" = "concat('(Fls_NotifFunctionPtrType)',($Notification2))"!][!//
[!ELSE!][!//
[!VAR "Notification2" = "$Notification2"!][!//
[!ENDIF!][!//
[!IF "$Notification2 != '(Fls_NotifFunctionPtrType)0'"!][!//
/* Function declaration of Fls Job Error Notifications */
extern void [!"$Notification2"!](void);
[!ELSE!][!//
/* Job Error Notification Function is not configured */
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "NotifIllegalState" = "FlsIfxSpecificConfig/FlsIllegalStateNotification"!][!//
[!NOCODE!][!//
    [!IF "string-length($NotifIllegalState) != 0 and $NotifIllegalState != '"NULL"' and $NotifIllegalState != 'NULL' and $NotifIllegalState != 'NULL_PTR' and $NotifIllegalState != ''"!][!//
    [!IF "$PostBuildType != 'SELECTABLE'"!][!//
    [!ASSERT "num:isnumber($NotifIllegalState)= 'true'"!][!//
    ERROR: Under LOADABLE option FlsIllegalStateNotification should be entered as an Address.[!//
    [!ENDASSERT!][!//
    [!ELSE!][!//
    [!ASSERT "num:isnumber($NotifIllegalState)!= 'true'"!][!//
    ERROR: Under SELECTABLE option FlsIllegalStateNotification should be entered as a function name.[!//
    [!ENDASSERT!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//

[!IF "string-length($NotifIllegalState) != 0 and $NotifIllegalState != '"NULL"' and $NotifIllegalState != 'NULL' and $NotifIllegalState != 'NULL_PTR' and $NotifIllegalState != ''"!][!//
/* Function declaration of Illegal State Notification */
extern void [!"$NotifIllegalState"!](void);
[!ELSE!][!//
/* Illegal State Notification function is not configured */
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

/*******************************************************************************
**                      Global Constant Definitions                          **
*******************************************************************************/
[!SELECT "as:modconf('Fls')[1]"!][!//
[!NOCODE!][!//
    [!VAR "NotifIllegalState" = "FlsIfxSpecificConfig/FlsIllegalStateNotification"!][!//
    [!IF "string-length($NotifIllegalState) = 0 or $NotifIllegalState = '"NULL"' or $NotifIllegalState = 'NULL' or $NotifIllegalState = 'NULL_PTR'"!][!//
    [!VAR "NotifIllegalState" = "'(Fls_NotifFunctionPtrType)0'"!][!//
    [!ELSE!][!//
    [!IF "$PostBuildType != 'SELECTABLE'"!][!//
    [!VAR "NotifIllegalState" = "concat('(Fls_NotifFunctionPtrType)',($NotifIllegalState))"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "state_data_struct" = "FlsIfxSpecificConfig/FlsStateVarStruct"!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!// 
#define FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* Fls State Variable structure */
#if(FLS_DEBUG_SUPPORT == STD_OFF)
static Fls_17_Pmu_StateType  [!"$state_data_struct"!];
#else
Fls_17_Pmu_StateType  [!"$state_data_struct"!];
#endif

#define FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
[!ENDIF!][!//
[!ENDSELECT!][!//

#define FLS_17_PMU_START_SEC_POSTBUILDCFG
#include "MemMap.h"

const Fls_17_Pmu_ConfigType Fls_17_Pmu_ConfigRoot[] = 
{
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!VAR "FlsAcLoadOnJobStart" =  "FlsGeneral/FlsAcLoadOnJobStart"!][!//
[!VAR "FlsDevErrorDetect" =  "FlsGeneral/FlsDevErrorDetect"!][!//
[!VAR "FlsTotalConfig" = "num:i(count(FlsConfigSet/*))"!][!//
[!VAR "CompareFailDemReport" = "num:i(0)"!][!//
[!VAR "EraseFailDemReport" = "num:i(0)"!][!//
[!VAR "ReadFailDemReport" = "num:i(0)"!][!//
[!VAR "WriteFailDemReport" = "num:i(0)"!][!//
[!NOCODE!][!//
[!//
[!/* Determine only one FlsConfigSet is configured 
                                        when FlsPBFixedAddress = true.*/!]
[!IF "FlsGeneral/FlsPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($FlsTotalConfig != 1)"!][!//
Config Error: when FlsGeneral/FlsPBFixedAddress is set as true, [!//
Only one FlsConfigSet configuration is allowed. [!//
But FlsConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
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
[!FOR "ModuleId" ="num:i(1)" TO "num:i($FlsTotalConfig)"!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$FlsTotalConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!SELECT "FlsConfigSet/*[num:i($ModuleId)]"!][!//
  {
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
[!ASSERT "num:isnumber($state_data_struct)= 'true'"!][!//
ERROR: Under LOADABLE option FlsStateVarStruct should be entered as a Address.[!//
[!ENDASSERT!][!//
    /* Fls state variable structure */
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_17_Pmu_StateType *)[!"$state_data_struct"!]U,
[!ELSE!][!//
[!ASSERT "num:isnumber($state_data_struct)!= 'true'"!][!//
ERROR: Under Selectable option FlsStateVarStruct should be entered as a Variable name[!//
[!ENDASSERT!][!//
    /* Fls state variable structure */
    &[!"$state_data_struct"!],
[!ENDIF!][!//

    /* Maximum number of bytes to Read in one cycle */
    /* Fast Mode */
    [!"FlsMaxReadFastMode"!]U,
    /* Normal Mode */
    [!"FlsMaxReadNormalMode"!]U,
[!NOCODE!][!//
    [!/* FlsJobEndNotification*/!][!//
    [!IF "node:exists(./FlsJobEndNotification/*[1]) = 'true'"!][!//
    [!VAR "Notification1" = "./FlsJobEndNotification/*[1]"!][!//
    [!ELSE!][!//
    [!VAR "Notification1" = "''"!][!//
    [!ENDIF!][!//
    [!IF "string-length($Notification1) = 0 or $Notification1 = '"NULL"' or $Notification1 = 'NULL' or $Notification1 = 'NULL_PTR'"!][!//
    [!VAR "Notification1" = "'(Fls_NotifFunctionPtrType)0'"!][!//
    [!ELSE!][!//
    [!IF "$PostBuildType != 'SELECTABLE'"!][!//
    [!ASSERT "num:isnumber($Notification1)= 'true'"!][!//
    ERROR: Under LOADABLE option FlsJobEndNotification should be entered as a Address. Change notification of [!"node:name(.)"!][!//
    [!ENDASSERT!][!//
    [!VAR "Notification1" = "concat('(Fls_NotifFunctionPtrType)',($Notification1))"!][!//
    [!ELSE!][!//
    [!ASSERT "num:isnumber($Notification1)!= 'true'"!][!//
    ERROR: Under SELECTABLE option FlsJobEndNotification should be entered as a function name. Change notification of [!"node:name(.)"!][!//
    [!ENDASSERT!][!//
    [!VAR "Notification1" = "$Notification1"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!/* FlsJobErrorNotification */!][!//
    [!IF "node:exists(./FlsJobErrorNotification /*[1]) = 'true'"!][!//
    [!VAR "Notification2" = "./FlsJobErrorNotification/*[1]"!][!//
    [!ELSE!][!//
    [!VAR "Notification2" = "''"!][!//
    [!ENDIF!][!//
    [!IF "string-length($Notification2) = 0 or $Notification2 = '"NULL"' or $Notification2 = 'NULL' or $Notification2 = 'NULL_PTR'"!][!//
    [!VAR "Notification2" = "'(Fls_NotifFunctionPtrType)0'"!][!//
    [!ELSE!][!//
    [!IF "$PostBuildType != 'SELECTABLE'"!][!//
    [!ASSERT "num:isnumber($Notification2)= 'true'"!][!//
    ERROR: Under LOADABLE option FlsJobErrorNotification should be entered as a Address. Change notification of [!"node:name(.)"!][!//
    [!ENDASSERT!][!//
    [!VAR "Notification2" = "concat('(Fls_NotifFunctionPtrType)',($Notification2))"!][!//
    [!ELSE!][!//
    [!ASSERT "num:isnumber($Notification2)!= 'true'"!][!//
    ERROR: Under SELECTABLE option FlsJobErrorNotification should be entered as a function name. Change notification of [!"node:name(.)"!][!//
    [!ENDASSERT!][!//
    [!VAR "Notification2" = "$Notification2"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDNOCODE!][!//

    /* Job End Notification */
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!IF "$Notification1 = '(Fls_NotifFunctionPtrType)0'"!][!//
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    [!"$Notification1"!],
[!ELSE!][!//
    &[!"$Notification1"!],
[!ENDIF!][!//
[!ELSE!][!//
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    [!"($Notification1)"!]U,
[!ENDIF!][!//

    /* Job Error Notification */
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!IF "$Notification2 = '(Fls_NotifFunctionPtrType)0'"!][!//
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    [!"$Notification2"!],
[!ELSE!][!//
    &[!"$Notification2"!],
[!ENDIF!][!//
[!ELSE!][!//
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    [!"($Notification2)"!]U,
[!ENDIF!][!//

    /* Illegal State Notification */
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!IF "$NotifIllegalState = '(Fls_NotifFunctionPtrType)0'"!][!//
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    [!"$NotifIllegalState"!],
[!ELSE!][!//
    &[!"$NotifIllegalState"!],
[!ENDIF!][!//
[!ELSE!][!//
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    [!"($NotifIllegalState)"!]U,
[!ENDIF!][!//

    /*Wait state configuration for Read access and error correction */
    (((uint32)[!"FlsWaitStateRead"!] << 6U) | 
      ((uint32)[!"FlsWaitStateErrorCorrection"!] << 12U) ),
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!IF "$FlsAcLoadOnJobStart = 'false'"!]
    /*Flash access code address in RAM */ 
    (Fls_WriteCmdPtrType)(void*)&Fls_WriteCmdCycles,
    /*Flash access code address in RAM */
    (Fls_EraseCmdPtrType)(void*)&Fls_EraseCmdCycles,
[!ELSE!]
    /*Flash access code address in RAM */ 
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_WriteCmdPtrType)[!"num:inttohex(./FlsAcWrite)"!]U,
    /*Flash access code address in RAM */      
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_EraseCmdPtrType)[!"num:inttohex(./FlsAcErase)"!]U,
[!ENDIF!][!/* ($FlsAcLoadOnJobStart = false) */!][!//
[!ELSE!]
[!/* ($PostBuildType = 'LOADABLE') */!][!//
    /*Flash access code address in RAM */ 
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_WriteCmdPtrType)[!"num:inttohex(./FlsAcWrite)"!]U,
    /*Flash access code address in RAM */      
    /*IFX_MISRA_RULE_11_01_STATUS=Address is stored as a pointer*/
    /*IFX_MISRA_RULE_11_03_STATUS=Address is stored as a pointer*/
    (Fls_EraseCmdPtrType)[!"num:inttohex(./FlsAcErase)"!]U,
[!ENDIF!][!/* ($PostBuildType = 'SELECTABLE') */!][!//
[!IF "$FlsDevErrorDetect = 'true'"!][!//
    /* FlsCallCycle for timeout monitoring, convert to us by multiplying by 
       1000 * 1000 */
[!VAR "CallCycle" = "FlsCallCycle"!][!//
[!VAR "CallCycle" = "$CallCycle * 1000 * 1000"!][!//
    [!"num:i($CallCycle)"!]U,
[!ENDIF!][!// 
[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_COMPARE_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_COMPARE_FAILED/*[1]) != '' )"!][!//
    /* Dem value for FLS_E_COMPARE_FAILED  */
    (Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_COMPARE_FAILED/*[1])))"!],
[!ELSE!][!//
[!IF "$CompareFailDemReport = num:i(1)"!][!//
    (Dem_EventIdType)0U,
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_ERASE_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_ERASE_FAILED/*[1]) != '' )"!][!//
    /* Dem value for FLS_E_ERASE_FAILED  */
    (Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_ERASE_FAILED/*[1])))"!],
[!ELSE!][!//
[!IF "$EraseFailDemReport = num:i(1)"!][!//
    (Dem_EventIdType)0U,
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_READ_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_READ_FAILED/*[1]) != '' )"!][!//
    /* Dem value for FLS_E_READ_FAILED  */
    (Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_READ_FAILED/*[1])))"!],
[!ELSE!][!//
[!IF "$ReadFailDemReport = num:i(1)"!][!//
    (Dem_EventIdType)0U,
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "(node:exists(./FlsDemEventParameterRefs/*[1]/FLS_E_WRITE_FAILED/*[1]) = 'true') and (node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_WRITE_FAILED/*[1]) != '' )"!][!//
    /* Dem value for FLS_E_WRITE_FAILED  */
    (Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./FlsDemEventParameterRefs/*[1]/FLS_E_WRITE_FAILED/*[1])))"!],
[!ELSE!][!//
[!IF "$WriteFailDemReport = num:i(1)"!][!//
    (Dem_EventIdType)0U,
[!ENDIF!][!//
[!ENDIF!][!//

    /* Default mode of FLS driver */
    [!"FlsDefaultMode"!]
[!IF "not(node:islast())"!]
  },
[!ELSE!][!//
  }
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
};


#define FLS_17_PMU_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

