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
**  $FILENAME   : Icu_17_GtmCcu6_Demo.c $                                    **
**                                                                           **
**  $CC VERSION : \main\13 $                                                 **
**                                                                           **
**  $DATE       : 2013-10-24 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  ICU module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Icu_17_GtmCcu6.h"
#include "Icu_17_GtmCcu6_Demo.h"
#include "Test_Print.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
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
#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"

extern void Timer_DelayTicks(uint32 ReqTimeTicks );

#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/* Icu Duty Cycle Variable */

#define ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

Icu_17_GtmCcu6_DutyCycleType DutyCycle_Values1;

#define ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define ICU_17_GTMCCU6_START_SEC_VAR_32BIT
#include "MemMap.h"

uint32 IcuKeep;

#define ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define ICU_17_GTMCCU6_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_DemoStart(void)                                          **
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
void Icu_17_GtmCcu6_DemoStart(void)
{
  

} /* Icu_17_GtmCcu6_DemoStart */

/*******************************************************************************
** Syntax : void Icu_17_GtmCcu6_Demo(void)                                               **
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
void Icu_17_GtmCcu6_Demo(void)
{  
  uint32 DutyCycle;
  uint32 Delay;   
  /*  delay value */
  Delay = 300000U;
  
  if (IcuKeep == 0U)
  {
    Icu_17_GtmCcu6_StartSignalMeasurement(0);
	IcuKeep++;
  }
  *(uint32*)(0xf003a018u)  = 0x80801000;         
  Timer_DelayTicks(Delay);  
  *(uint32*)(0xf003a000u) |= (1 << 10);             
  Timer_DelayTicks(Delay);
  Icu_17_GtmCcu6_GetDutyCycleValues(0,&DutyCycle_Values1);
  DutyCycle = (uint32)((DutyCycle_Values1.ActiveTime * 200U) \
  + (DutyCycle_Values1.PeriodTime)) \
  / (uint32)(2U * DutyCycle_Values1.PeriodTime);
  
  if(DutyCycle == (uint32)(-1))
  {
    DutyCycle = 0U;
  }
  print_f("High Time = %x    Period = %x Duty Cycle %d \n",
  DutyCycle_Values1.ActiveTime,DutyCycle_Values1.PeriodTime,DutyCycle);
} /* Icu_17_GtmCcu6_Demo */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
void Icu_SignalEdgeNotification(void)
{
}

#define ICU_17_GTMCCU6_STOP_SEC_CODE
#include "MemMap.h"
