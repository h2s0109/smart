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
**  $FILENAME   : Can_17_MCanP_Platform.c $                                  **
**                                                                           **
**  $CC VERSION : \main\5 $                                                  **
**                                                                           **
**  $DATE       : 2016-07-22 $                                               **
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
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Register definition file for Aurix target */
#include "IfxCan_reg.h"
#include "IfxSrc_reg.h"
/*for proctected mode support macros */
#include "Can_17_MCanP.h"
/*including header file for Can_17_MCanP_Platform.c*/
#include "Can_17_MCanP_Platform.h"


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CAN_ONE                         (1U)
#define CAN_17_MCANP_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#ifdef CAN_MOD_R_AVAILABLE
#if (CAN_NUM_CONTROLLERS_IN_KERNEL1 == 3U )
/* CAN base address Kernel wise */
Ifx_CAN* const CAN_KER[] = { &MODULE_CAN, &MODULE_CAN1 };
#else
/* CAN base address Kernel wise */
Ifx_CAN* const CAN_KER[] = { &MODULE_CAN, &MODULE_CANR };
#endif
#else
/* CAN base address Kernel wise */
Ifx_CAN* const CAN_KER[] = { &MODULE_CAN };
#endif

#define CAN_17_MCANP_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/* Memory map of the CAN driver code */
#define CAN_17_MCANP_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Syntax           :                  void Can_lFrameInitialise              **
**                                           (                                **
**                                             uint8 KerIdx,                  **
**                                             uint8 HwCtrlIDKer              **
**                                             uint16 CanControllerFDBaudrate **
**                                             uint16 CanControllerTxDelayComp**
**                                           )                                **
**                                                                            **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Reentrant                                               **
**                                                                            **
** Parameters (in)  : KerIdx - Associated CAN Kernal Id                       **
**                    HwCtrlIDKer - Associated CAN Hardwarecontroller ID      **
**                    CanControllerFDBaudrate                                 **
**                      CanControllerTxDelayComp                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      :  this api is for FD frame ISO support                   **
**                                                                            **
*******************************************************************************/
void Can_lFrameInitialise(uint8 KerIdx,uint8 HwCtrlIDKer,\
                 uint16 CanControllerFDBaudrate,uint16 CanControllerTxDelayComp)
{
    CAN_SFR_INIT_USER_MODE_MODIFY32(CAN_KER[KerIdx]->N[HwCtrlIDKer].CR.U,\
                  CAN_NCR_FDEN_CLEARMASK,(uint32)CAN_ONE << CAN_NCR_FDEN_BITPOS)

    /* Set Fast Node Bit Timing value */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
    CAN_SFR_INIT_USER_MODE_WRITE32(CAN_KER[KerIdx]->N[HwCtrlIDKer].FBTR.U,\
                                        (unsigned_int)CanControllerFDBaudrate);

    /* Set Transceiver Delay Compensation Offset values */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
    CAN_SFR_INIT_USER_MODE_WRITE32(CAN_KER[KerIdx]->N[HwCtrlIDKer].TDCR.U,\
                                        (unsigned_int)CanControllerTxDelayComp);
}
#define CAN_17_MCANP_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"