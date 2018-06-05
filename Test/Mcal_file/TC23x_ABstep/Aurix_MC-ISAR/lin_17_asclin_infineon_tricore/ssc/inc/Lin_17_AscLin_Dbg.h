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
**  $FILENAME   : Lin_17_AscLin_Dbg.h $                                      **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-11 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This header file exports                                   **
**                 - functionality of Lin driver.                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
#ifndef LIN_17_ASCLIN_DBG_H
#define LIN_17_ASCLIN_DBG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Pre-compile/static configuration parameters for LIN                        */
#include "Lin_17_AscLin.h"  

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
#if (LIN_DEBUG_SUPPORT == STD_ON)

#define LIN_17_ASCLIN_START_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

extern Lin_17_AscLin_ChannelInfoType 
                                 Lin_17_AscLin_ChannelInfo[LIN_MAXIMUM_CHANNEL];
                                 
#define LIN_17_ASCLIN_STOP_SEC_VAR_UNSPECIFIED
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
 is allowed only for MemMap.h*/
#include "MemMap.h"

#endif /*(LIN_DEBUG_MODE == ON)*/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* LIN_17_ASCLIN_DBG_H */

