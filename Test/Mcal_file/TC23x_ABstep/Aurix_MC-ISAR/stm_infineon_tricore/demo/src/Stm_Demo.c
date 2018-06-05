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
**  $FILENAME   : Stm_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\7 $                                                  **
**                                                                           **
**  $DATE       : 2014-09-17 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - functionality of Stm driver.                             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "stdio.h"
#include "Std_Types.h"
#include "Test_Print.h"
#include "Stm_Demo.h"
#include "Dio.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#ifndef TRB_LED
#define TRB_LED DioConf_DioChannel_TRB_LED
#endif
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static uint32 getParamU32(char s[]);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

volatile uint32 Toggle = 0;
void Stm_DemoAppCbk(void);


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
 
/*******************************************************************************
** Syntax : void Stm_StartDemo(void)                                          **
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
**                                                                            **
*******************************************************************************/
void Stm_StartDemo(void)
{
  char szString[40];
  uint8 TempUSage = 0;
  
  while (TempUSage != 1U)
  {
    print_f("\n\n\n");
    print_f("\n/*********************************************************/\n");
    print_f("\n                STM DRIVER TEST MENU                      \n ");
    print_f("\n                                                          \n ");
    print_f("     1. Stm_EnableAlarm(): Enter ticks value for LED blinking\n ");
    print_f("     2. Stm_DisableAlarm(): To stop the LED blinking\n ");
    print_f("     x.  Back To Main Menu                                  \n ");
    print_f("                                                            \n ");
    print_f("\n/*********************************************************/\n");
    print_f("  Enter Your Option :: "); 
    
    getline(szString, sizeof (szString - 1));
     
    switch (*szString)
    {
       case '1':
       {
        uint32 Ticksvalue = 0U;
        
        print_f("\n  Enter Ticks : ");
        getline(szString, 40);        
        Ticksvalue = (uint32) getParamU32(szString);
        /* Enable the STM module for interrupt mapping */
        Stm_EnableModule(0);
        /*service to invoke a Call-back function after the elapse of
          given amount of time (scheduling a function) */
        Stm_EnableAlarm(0,0,0,Ticksvalue,Stm_DemoAppCbk);
        break;
       }
       case '2':
       {        
        Dio_WriteChannel (TRB_LED,STD_HIGH);
        Stm_DisableAlarm(0,0);
        break;
       }       
       case 'x':
       case 'X':
         TempUSage = 1;
         break;
       default :
         print_f(" \n\n Invalid option \n ");
       break;
   }
  }

}


void Stm_DemoAppCbk(void)
{
  if(Toggle == 1)
  {
    Dio_WriteChannel (TRB_LED,STD_HIGH);
    Toggle = 0;
  }
  else
  {
     Dio_WriteChannel (TRB_LED,STD_LOW);
    Toggle = 1;
  }  
}


static uint32 getParamU32(char s[])
{  
  uint32 i, n;  
  
  n = 0U;  
  
  for (i = 0U; s[i] >= '0' && s[i] <= '9'; ++i)
  {
    n = 10 * n + (s[i] - '0');
  }
  
  return n;  
}
