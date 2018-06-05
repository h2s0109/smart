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
**  $FILENAME   : Icu_17_GtmCcu6_Demo.h $                                    **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2013-06-21 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                 - sample Demo Test for ICU module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

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

#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_Demo(void)                                    **
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
** Return value    : none                                                     **
**                                                                            **
** Description :Read out the PWM Duty Cycle and Period.The PWM must be        **
** generated using the PWM Demo befor using this ICU Demo.                    **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_Demo(void);

/*******************************************************************************
** Syntax : void Icu_DemoStart(void)                                          **
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
** Return value    : none                                                     **
**                                                                            **
** Description :Starts the ICU Demo Application                               **
**                                                                            **
*******************************************************************************/
extern void Icu_17_GtmCcu6_DemoStart(void);

#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"