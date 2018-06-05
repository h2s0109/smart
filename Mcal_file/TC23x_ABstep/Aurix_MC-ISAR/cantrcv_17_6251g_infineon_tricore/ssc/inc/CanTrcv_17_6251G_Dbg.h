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
**  $FILENAME   : CanTrcv_17_6251G_Dbg.h $                                   **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2014-05-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - Debug information of CanTrcv_17_6251G_Dbg driver.       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/


#ifndef CANTRCV_17_6251G_DBG_H
#define CANTRCV_17_6251G_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "CanTrcv_17_6251G.h"
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

#if ( CANTRCV_17_6251G_DEBUG_SUPPORT == STD_ON )

#define CANTRCV_17_6251G_START_SEC_VAR_8BIT
#include "MemMap.h"

extern volatile CanTrcv_TrcvModeType \
                           Cantrcv_CurrentMode[CANTRCV_17_6251G_MAX_CH_SUPPORT];

#define CANTRCV_17_6251G_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define CANTRCV_17_6251G_START_SEC_VAR_16BIT
#include "MemMap.h"

extern volatile CanTrcv_TrcvWakeupReasonType \
                              Cantrcv_WuReason[CANTRCV_17_6251G_MAX_CH_SUPPORT];

#define CANTRCV_17_6251G_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#endif


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* CANTRCV_17_6251G_DBG_H */
