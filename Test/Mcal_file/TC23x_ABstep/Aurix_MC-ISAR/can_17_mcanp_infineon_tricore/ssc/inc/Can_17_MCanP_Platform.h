/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2016)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Can_17_MCanP_Platform.h $                                  **
**                                                                           **
**  $CC VERSION : \main\4 $                                                  **
**                                                                           **
**  $DATE       : 2016-07-14 $                                               **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                - CAN driver API implementation                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
#ifndef CAN_17_MCANP_PLATFORM_H
#define CAN_17_MCANP_PLATFORM_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
 /*for proctected mode support macros */
/* #include "Can_17_MCanP.h"*/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*#if(CAN_PB_FIXEDADDR == STD_ON)*/
/* The config pointer is initialised to first instance of configuration */
/*extern const Can_17_MCanP_ConfigType* const Can_kConfigPtr;
#endif*/

#ifdef CAN_MOD_R_AVAILABLE
#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 3U )
/* CAN base address Kernel wise */
extern Ifx_CAN* const CAN_KER[2];
#else
/* CAN base address Kernel wise */
extern Ifx_CAN* const CAN_KER[2];
#endif
#else
/* CAN base address Kernel wise */
extern Ifx_CAN* const CAN_KER[1];
#endif
#define CAN_17_MCANP_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*#define CAN_17_MCANP_START_SEC_VAR_32BIT*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
/*#include "MemMap.h"*/

/*#if(CAN_PB_FIXEDADDR == STD_OFF)*/
/* Pointer to store config pointer */
/*extern const Can_17_MCanP_ConfigType* Can_kConfigPtr;
#endif*/

/*#define CAN_17_MCANP_STOP_SEC_VAR_32BIT*/
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
/*#include "MemMap.h"*/

#define  CAN_CR_INIT_CLEARMASK                     (0xFFFFFFFEU)
#define  CAN_CR_CCE_CLEARMASK                      (0xFFFFFFFFU)
#define  CAN_CR_CCE_SETMASK                        (0x00000020U)
#define  CAN_BTR_DIV8_CLEARMASK                    (0xFFFF7FFFU)
#define  CAN_BTR_DIV8_SHIFT                        (15U)

/*******************************************************************************
**                      Global Function Declaration                           **
*******************************************************************************/
/* Memory map of the CAN driver code */
#define CAN_17_MCANP_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
extern void Can_lFrameInitialise(uint8 KerIdx,uint8 HwCtrlIDKer,\
                uint16 CanControllerFDBaudrate,uint16 CanControllerTxDelayComp);
#define CAN_17_MCANP_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif