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
**  $FILENAME   : Dio_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2014-08-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This contains the functionality for DIO driver             **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxPort_reg.h"
#include "Dio.h"
#include "Dio_Demo.h"
#include "Test_Print.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* defined due to the Symbolic Name change btw AS403 and AS321 */
#ifndef DioChannel_LED
#define DioChannel_LED DioConf_DioChannel_DioChannel_LED
#endif

#ifndef DioChannelGroup_LED
#define DioChannelGroup_LED DioConf_DioChannelGroup_DioChannelGroup_LED
#endif

#ifndef DioChannel_MC_Demo
#define DioChannel_MC_Demo DioConf_DioChannel_DioChannel_MC_Demo
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
extern volatile uint8 DemoApp_GlowLed;
static uint8 DioDemo_LedCount;
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
** Syntax : void DemoApp_Dio(void)                                            **
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
** Timing         : Fixed Cyclic/Variable Cyclic                              **
**                                                                            **
** Description : Dio Demo functions are called                                **
*******************************************************************************/
void DemoApp_Dio(void)
{
   char szString[4U];
   uint8 TempUSage = 0U;
   Dio_PortLevelType GroupLevel;
   Dio_LevelType PinLevel;

   while (TempUSage != 1U)
   {
     print_f("\n\n\n");
     print_f("\n/******************************************************");
     print_f("*********************/\n");
     print_f("\n                       DIO DRIVER TEST MENU                \n");
     print_f("                   ENTER YOUR OPTION                         \n");
     print_f("              < 1 >  DIO Driver Demo LED_Pin_ON              \n");
     print_f("              < 2 >  DIO Driver Demo LED_Pin_OFF             \n");
     print_f("              < 3 >  DIO Driver Demo LED Series ON           \n");
     print_f("              < 4 >  DIO Driver Demo LED Series OFF          \n");
     print_f("              < x >  Back To Main Menu                       \n");
     print_f("\n/******************************************************");
     print_f("*********************/\n");
     print_f("Option: ");

     getline(szString, sizeof szString - 1);

     switch (*szString)
     {
        case '1':
             print_f("\n Set the LED Pin ON \n ");
             PinLevel = STD_LOW;
             Dio_WriteChannel(DioChannel_LED,PinLevel);
             Continue();
             break;

        case '2' :
             print_f("\n Set the LED Pin OFF \n ");
             PinLevel = STD_HIGH;
             Dio_WriteChannel(DioChannel_LED,PinLevel);
             Continue();
             break;

        case '3' :
             print_f("\n Set the LED Series ON \n ");
             GroupLevel = 0;
             Dio_WriteChannelGroup(DioChannelGroup_LED,
                                    GroupLevel);
             Continue();
             break;

        case '4' :
             print_f("\n Set the LED Series OFF \n ");
             GroupLevel = 0xFFU;
             Dio_WriteChannelGroup(DioChannelGroup_LED,
                                    GroupLevel);
             Continue();
             break;

        /* Go Back to Main Menu */
        case 'x':
        case 'X':
         TempUSage = 1U;
         break;

        default :
        {
           print_f("\n Invalid Option Choosen \n ");
           break;
        }
     }
   }
}/* DemoApp_Dio() */



void DemoApp_McDioDemo(void)
{
  Dio_LevelType PinLevel;
	if(DemoApp_GlowLed == 1U)
  {
  	DemoApp_GlowLed = 0U;
    DioDemo_LedCount++;
    
	  if( DioDemo_LedCount == 1U)
	  {
	     PinLevel = STD_LOW;
	     Dio_WriteChannel(DioChannel_MC_Demo,PinLevel);
	
	  }
	  else if(DioDemo_LedCount == 2U)
	  {
	     PinLevel = STD_HIGH;
	     Dio_WriteChannel(DioChannel_MC_Demo,PinLevel);
	     DioDemo_LedCount = 0U;
	  } 
  }	
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

