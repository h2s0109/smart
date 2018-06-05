/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME  : Pwm_17_Gtm_Demo.c $                                         **
**                                                                            **
**  $CC VERSION : \main\17 $                                                 **
**                                                                            **
**  $DATE       : 2014-09-16 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - sample Demo Test for PWM module                          **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Pwm_17_Gtm.h"
#include "Pwm_17_Gtm_Demo.h"
#include "Test_Print.h"
#include "DemoApp_Cfg.h"
#if (ICU_DELIVERY == STD_ON)
#include "Icu_17_GtmCcu6.h"
#endif
#include "Port.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* defined due to the Symbolic Name change btw AS403 and AS321 */
#ifndef PwmChannel_0
#define PwmChannel_0 Pwm_17_GtmConf_PwmChannel_PwmChannel_0
#endif

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (ICU_DELIVERY == STD_ON)
extern uint32 IcuKeep;
#endif
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/* Macros */
#define PWM_PERIOD                    (0x7999U)
#define PWM_DUTY                      (0x4000U)

/* Duty Cycle for PWM */
uint32 DutyCycle = 50U;         
volatile uint16 duty = 0;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
volatile uint16 Pwm_NotifCtr[1];
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */


/* Parameter Function for the parMenu */
/*char* pszFunction = "PWM Duty Cycle";*/
char pszFunction[20] = "PWM Duty Cycle";


/* Parameter Option For PWM : DC */
static const PAR_t Pwm_DutyCyclePar[] = 
{
  {
    PAR_TYP_DEC,                    /* uwType */ /*  for configuration 1 */
    sizeof(DutyCycle),              /* uwSize */
    &DutyCycle,                     /* pvData */
    0,                              /* uwMin */
    100,                            /* uwMax */
    "DutyCycle in Percent%",        /* szText */
    "%d"                            /* szOutputFormat */
  }
};      

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
 
/*******************************************************************************
** Syntax : void Pwm_17_Gtm_StartDemo(void)                                   **
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
** Description : Enables the notification and Starts PWM with 50% duty        **
**                                                                            **
*******************************************************************************/
void Pwm_17_Gtm_StartDemo(void)
{
  /* Change the pin mode to handle GTM output signal */
  #ifndef  PWM_DEMO_PIN_EP
  Port_SetPinMode(PORT_33_PIN_8,PORT_PIN_MODE_ALT1);
  #else
  Port_SetPinMode(PWM_DEMO_PIN_EP,PORT_PIN_MODE_ALT1);
  #endif  
  #if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Enable PWM channel notifications */
  Pwm_17_Gtm_EnableNotification(PwmChannel_0,PWM_BOTH_EDGES);
  #endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON */

  /* Start PWM */
  Pwm_17_Gtm_SetPeriodAndDuty(PwmChannel_0,PWM_PERIOD,PWM_DUTY);
  #if (ICU_DELIVERY == STD_ON)
  if (IcuKeep == 0U)
  {
    Icu_17_GtmCcu6_StartSignalMeasurement(0);
    IcuKeep++;
  }
  #endif
}

/*******************************************************************************
** Syntax : void Pwm_17_Gtm_ChangeDutyDemo(void)                              **
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
** Description :                                                              **
*******************************************************************************/
void Pwm_17_Gtm_ChangeDutyDemo(void)
{
 
  /* Change Duty Cycle Of PWM */
  /*pszFunction = "PWM Duty Cycle";*/
  if (ParMenu(&pszFunction[0], 
             (PAR_t *)Pwm_DutyCyclePar,  
              sizeof Pwm_DutyCyclePar/sizeof Pwm_DutyCyclePar[0]
     ) != 'q')
  {
    
    duty = (uint16)(((0x8000U * DutyCycle) + 50U) / 100U ) ;
  }        

  #if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Disable PWM channel notifications */
  Pwm_17_Gtm_DisableNotification(PwmChannel_0);
  #endif

  #if  (PWM_SET_DUTY_CYCLE_API == STD_ON)
  /* Set the PWM Duty */
  Pwm_17_Gtm_SetDutyCycle(PwmChannel_0,duty);
  #endif

  #if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
  /* Enable PWM channel notifications */
  Pwm_17_Gtm_EnableNotification(PwmChannel_0,PWM_BOTH_EDGES);
  #endif
}


/*******************************************************************************
** Syntax : void  Pwm_17_Gtm_DemoDisableNotification(void)                    **
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
** Description :    The Blinking will stop i.e the timer is stopped and the   **
         LED will remain in the State high or Low depending on its last state **
*******************************************************************************/
void Pwm_17_Gtm_DemoDisableNotification(void)
{
    #if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
     Pwm_17_Gtm_SetOutputToIdle(PwmChannel_0);
    #endif
      
    #if  (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /* Disable PWM channel notifications */
     Pwm_17_Gtm_DisableNotification(PwmChannel_0);
    #endif

  /* Change the pin mode to handle DIO output signal */
  #ifndef  PWM_DEMO_PIN_EP
  Port_SetPinMode(PORT_33_PIN_8,PORT_PIN_MODE_GPIO);
  #else
  Port_SetPinMode(PWM_DEMO_PIN_EP,PORT_PIN_MODE_GPIO);
  #endif

 }


#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

void Pwm_NotifCh00 (void)
{
    Pwm_NotifCtr[0]++;
}

#endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON */
