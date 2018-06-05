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
**  $FILENAME   : Can_17_MCanP_Demo.h $                                      **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-25 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Import file for demo application for CAN driver          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
** Syntax : void Can_17_MCanP_Demo(void)                                      **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : DemoApp for CAN driver                                       **
**                                                                            **
*******************************************************************************/
#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"

extern void Can_17_MCanP_Demo(void);

#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"
