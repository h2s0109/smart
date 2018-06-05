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
**  $FILENAME   : Iom_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\12 $                                                 **
**                                                                           **
**  $DATE       : 2015-01-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  IOM module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "Iom.h"
#include "Std_Types.h"
#include "Gtm.h"
#include "Test_Print.h"
#include "DemoApp_Cfg.h"
#include "IfxSmu_reg.h"

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
 void Iom_Demo(void);
 static uint16 getParamU32(char c[]);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
** Syntax : void Iom_Demo(void)                                               **
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
** Description : Demo Application for IOM                                     **
*******************************************************************************/
void Iom_Demo(void)
{
  uint32 LamThreshold;
  uint16 Delay;
  char szString[10];
  char c[10];
  uint8 TempUsage = 0U;
  print_f("\n *******************************************************\n");
  print_f("\n Demo to check duty of monitor signal beyond threshold\n");
  print_f("\n *******************************************************\n");
  print_f("\n NOTE:Period and dutycycle values of reference\
         \n and monitor signals are 3000 and 4000 ticks respectively \n");
  print_f("\n.Refer Demo_App.txt file for pin connections \n");
  Gtm_EnableTomCoherantUpdate(0U,15U);
  Gtm_SetTomHostTrigger(0U,0U);
    
  while (TempUsage != 1U)
  {
    print_f("\n 1. Change monitor signal duty\n");
    print_f("To set monitor signal low, enter value greater 1000\n");
    print_f("To set monitor signal high, enter 62538\n");
    
    print_f("\n 2. Get LAM threshold value \n");
    print_f("\n 3. Set LAM threshold value \n");
    print_f("\n X. Go back to main menu    \n"); 
    print_f("\n/*********************************************************/\n");
    print_f("\n/*********************************************************/\n");
    if(SMU_AG2.U == 0U)
    {
      print_f("\n Monitor signal is within threshold \n");
    }
    else
    {
      print_f("\n Monitor signal is incorrect \n");
    }
    print_f("\n/*********************************************************/\n");
    print_f("\n/*********************************************************/\n");
    print_f("  Enter Your Option :: ");
 
    getline(szString,sizeof(szString) - 1U);

    switch(*szString)
    {
      case '1':
      {   
        print_f("\n Enter delay\n");
        getline(c,sizeof(c) - 1U);
        Delay = (uint16)getParamU32(c);
        Gtm_SetTomShadowValSr0(0U,15U,3999U);
        Gtm_SetTomShadowValSr1(0U,15U,2999+Delay);
        break;
      }
      case '2': 
      {
        LamThreshold = Iom_GetLamThreshold(0U);
        print_f("\n LAM threshold value : %d \n", LamThreshold);
        break;
      }
      case '3': 
      {
        print_f("\n  Set threshold\n");
        getline(c,sizeof(c) - 1U);
        LamThreshold = (uint32)getParamU32(c);
        Iom_SetLamThreshold(0U,LamThreshold);
        break;
      }
  
      case 'x':
       case 'X':TempUsage = 1;
                break;
       default: print_f("/n Enter valid option /n");
        break;

    }

  }


} /*End of Iom_Demo function */
/* function to retrieve the parameter */      
static uint16 getParamU32(char c[])
{
  uint8 i;
  uint16 n = 0U;
  for(i = 0U; c[i] >= '0' && c[i] <= '9'; ++i)
  {
    n = 10 * n + (c[i] - '0');
  }
  return n;
}

