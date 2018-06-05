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
**  $FILENAME   : CanTrcv_17_6250GV33_Dbg.h $                                **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2014-05-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - Debug information of CanTrcv_17_6250GV33 driver.        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

#ifndef CANTRCV_17_6250GV33_DBG_H
#define CANTRCV_17_6250GV33_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include "CanTrcv_17_6250GV33.h"
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

#define CANTRCV_17_6250GV33_START_SEC_VAR_8BIT
#include "MemMap.h"

#if ( CANTRCV_17_6250GV33_DEBUG_SUPPORT == STD_ON )
extern volatile CanTrcv_TrcvModeType \
                Cantrcv_CurrentMode[CANTRCV_17_6250GV33_MAX_CH_SUPPORT];
#endif


#define CANTRCV_17_6250GV33_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif /* CANTRCV_17_6250GV33_DBG_H */

