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
**  $FILENAME   : Fee_Fcpt.c $                                               **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2014-05-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains function pointer table for Fee module,  **
**                required for integration with upper layers or for          **
**                application sharing. This file is for evaluation purpose   **
**                only.                                                      **
**                                                                           **
** [/cover]                                                                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
                  [cover parentID = DS_NAS_FEE_PR1053]
                  [/cover]
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* 
 Include Fee_Fcpt.h
*/
#include "Fee_Fcpt.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
     
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro like functions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/* 
   Fee_Header_Const_Type: This structure is used for creating a pointer table 
   to Fee interface and is typically used to share Fee between multiple 
   applications                                                               */

#define FEE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
const Fee_Header_Const_Type Fee_Header_Const[ ] =
{
   (void *)&Fee_Write,
   (void *)&Fee_Read,
   (void *)&Fee_InvalidateBlock,
   (void *)&Fee_Cancel,
   (void *)&Fee_GetStatus,
   (void *)&Fee_GetJobResult,
   (void *)&Fee_EraseImmediateBlock,
   (void *)&Fee_Init,
   (void *)&Fls_17_Pmu_Init,
   (void *)&Fls_17_Pmu_MainFunction,
   (void *)&Fee_MainFunction,
   (void *)&Fee_17_EnableGcStart,
   (void *)&Fee_17_DisableGcStart,
   #if (FEE_SET_MODE_SUPPORTED == STD_ON)
   (void *)&Fee_SetMode,
   #else
   NULL_PTR, /* Api Fee_SetMode is not configured */
   #endif
   #if (FEE_GET_CYCLE_COUNT_API == STD_ON)
   (void *)&Fee_17_GetCycleCount,
   #else
   NULL_PTR, /* Api Fee_17_GetCycleCount is not configured */
   #endif
   #if (FEE_GET_PREV_DATA_API == STD_ON)
   (void *)&Fee_17_GetPrevData,
   #else
   NULL_PTR, /* Api Fee_17_GetPrevData is not configured */
   #endif
};
#define FEE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

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
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/***********************        End of File     *******************************/

