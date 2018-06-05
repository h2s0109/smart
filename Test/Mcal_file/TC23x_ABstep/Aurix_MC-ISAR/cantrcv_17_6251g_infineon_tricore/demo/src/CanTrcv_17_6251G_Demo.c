
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
**  $FILENAME   : CanTrcv_17_6251G_Demo.c $                                  **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2014-09-18 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  CanTrcv 6251G                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "CanTrcv_17_6251G_Demo.h"
#include "CanTrcv_17_6251G.h"
#include "Test_Print.h"
#include "EcuM.h"

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
  Std_ReturnType RetVal;
  uint32 DemoTest;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
** Syntax : void CanTrcv_17_6251G_Demo(void)                                               **
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
** Description : Performs the start-up procedure to estimate the estimate     **
**                 the transmission delays and programs them into the MLI     **
**                 local transmitter and MLI remote receiver                  **
**              Writes data to the MLI remote receiver                        **
**              Reads data from MLI remote receiver                           **
*******************************************************************************/

void CanTrcv_17_6251G_Demo()
{
  uint8 CanTraceiver;
  
  CanTrcv_TrcvModeType GetOpMode;
  CanTrcv_TrcvWakeupReasonType Reason;
   
  DemoTest = 0; 
  CanTraceiver = 0;
  RetVal = E_OK;
	
  /* CanTrcv_17_6251G_Init Initialization execution */
  print_f("\nCanTrcv_17_6251G_Init started..\n");
  CanTrcv_17_6251G_Init(NULL_PTR); 
  
  if(RetVal == E_OK)
  {
    print_f("\n CanTrcv_17_6251G_Init Execution PASSED \n");	  
  }

  /* NORMAL MODE testing */
  print_f("\nNORMAL MODE testing started..\n");
	RetVal = CanTrcv_17_6251G_SetWakeupMode(CanTraceiver,CANTRCV_WUMODE_CLEAR);
  if(RetVal == E_OK)
  {
    print_f("\n CanTrcv_17_6251G_SetWakeupMode Execution Passed \n");	  
  }
  else   
  {
      print_f("\n CanTrcv_17_6251G_SetWakeupMode: DET occured \n");
      DemoTest = 1;	
  }
	
	RetVal = CanTrcv_17_6251G_SetOpMode(CanTraceiver,CANTRCV_TRCVMODE_NORMAL);
	
  if(RetVal == E_OK)
  {
    print_f("\n CanTrcv_17_6251G_SetOpMode Execution Passed \n");	  
  }
  else 
  {
      print_f("\n Requested mode is not supported by CanTrcv_17_6251G_SetOpMode or DET occured \n");
      DemoTest = 1;	
  }

	RetVal = CanTrcv_17_6251G_GetOpMode(CanTraceiver,&GetOpMode);
  if(RetVal == E_OK)
  {
    print_f("\n CanTrcv_17_6251G_GetOpMode Execution Passed \n");	  
  }
  else 
  {
      print_f("\n CanTrcv_17_6251G_GetOpMode: DET occured \n");
      DemoTest = 1;	
  }
  if( GetOpMode == CANTRCV_TRCVMODE_NORMAL)
  { 
  	 print_f("\n NORMAL mode transition after Init  is passed\n");	  
   }
   else
   {
   	print_f("\n OP Mode is not NORMAL, NORMAL Mode transition FAILED \n");
   	DemoTest = 1;
    }	
   
   /* STANDBY MODE testing */
   print_f("\nNORMAL to STANDBY MODE testing started..\n");
   
  RetVal = CanTrcv_17_6251G_SetOpMode(CanTraceiver,CANTRCV_TRCVMODE_STANDBY);

	RetVal = CanTrcv_17_6251G_GetOpMode(CanTraceiver,&GetOpMode);

  if( GetOpMode == CANTRCV_TRCVMODE_STANDBY)
  { 
  	 print_f("\nPAssed : NORMAL to STANDBY mode transition is passed\n");	  
     DemoTest = 0;  
   }
   else
   {
   	print_f("\n OP Mode is not STANDBY, NORMAL to STANDBY Mode transition FAILED \n");
   	DemoTest = 1;
    }	
   	   

  /* SLEEP MODE testing */
  print_f("\nSTANDBY to SLEEP MODE testing started..\n");
	RetVal = CanTrcv_17_6251G_SetWakeupMode(CanTraceiver,CANTRCV_WUMODE_ENABLE);
  
  RetVal = CanTrcv_17_6251G_SetOpMode(CanTraceiver,CANTRCV_TRCVMODE_SLEEP);

	RetVal = CanTrcv_17_6251G_GetOpMode(CanTraceiver,&GetOpMode);

  if( GetOpMode == CANTRCV_TRCVMODE_SLEEP)
  { 
  	 print_f("\nPAssed : STANDBY to SLEEP mode transition is passed\n");	  
   } 
   else
   {
   	print_f("\n OP Mode is not SLEEP, Mode transition FAILED \n");
   	DemoTest = 1;
    }	
   
    
    /* SLEEP to STANDBY MODE testing */
/*  print_f("\nSLEEP to STANDBY MODE testing started..\n");   
	RetVal = CanTrcv_17_6251G_SetOpMode(CanTraceiver,CANTRCV_TRCVMODE_STANDBY);	
  RetVal = CanTrcv_17_6251G_GetOpMode(CanTraceiver,&GetOpMode);
  if( GetOpMode == CANTRCV_TRCVMODE_STANDBY)  
   { 
  	 print_f("\n SLEEP to STANDBY mode transition is passed\n");	  
   } 
   else
   {
   	print_f("\n OP Mode is not STANDBY, SLEEP to STANDBY mode transition \n");
   	DemoTest = 1;
    }	
  
*/

  /* Change STANDBY to NORMAL MODE  */
/*  
  print_f("\n STANDBY to NORMAL MODE testing started..\n"); 
  RetVal = CanTrcv_17_6251G_SetOpMode(CanTraceiver,CANTRCV_TRCVMODE_NORMAL);	
  
	RetVal = CanTrcv_17_6251G_GetOpMode(CanTraceiver,&GetOpMode);
  if( GetOpMode == CANTRCV_TRCVMODE_NORMAL)
  { 
  	 print_f("\nPAssed : STANDBY to NORMAL  mode transition is passed\n");
   }
   else
   {
   	print_f("\n OP Mode is not NORMAL, STANDBY to NORMAL Mode transition FAILED \n");
   	DemoTest = 1;
    }	

*/
   /* CanTrcv_17_6251G_GetBusWuReason test */
   print_f("\n CanTrcv_17_6251G_GetBusWuReason test started..\n");      
   RetVal = CanTrcv_17_6251G_GetBusWuReason(CanTraceiver,&Reason); 
   if(RetVal == E_OK)
  {
    print_f("\n CanTrcv_17_6251G_GetBusWuReason Execution Passed \n");	  
  }
  else 
  {
      print_f("\n CanTrcv_17_6251G_GetBusWuReason: DET occured \n");
      DemoTest = 1;	
  }
  if( Reason == CANTRCV_WU_INTERNALLY)
  { 
  	 print_f("\n Wakeup Reason is CANTRCV_WU_INTERNALLY, \nCanTrcv_17_6251G_GetBusWuReason functionality Passed \n");	  
   }
   else
   {
   	print_f("\n Wakeup Reason is not CANTRCV_WU_INTERNALLY, CanTrcv_17_6251G_GetBusWuReason \n");
   	DemoTest = 1;
   } 
 	RetVal = CanTrcv_17_6251G_SetWakeupMode(CanTraceiver,CANTRCV_WUMODE_ENABLE);

  #if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING)
  
   CanTrcv_17_6251G_MainFunction(); 
   print_f("\n CanTrcv_17_6251G_MainFunction Execution Passed \n");	  

  #endif
  
  
  #if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING)
 	RetVal = CanTrcv_17_6251G_CheckWakeup(CanTraceiver);
  if(RetVal == E_OK)
  {
    print_f("\n CanTrcv_17_6251G_CheckWakeup Execution Passed \n");	  
  }
  else   
  {
    print_f("\n CanTrcv_17_6251G_CheckWakeup: No Wakeup, Hence Wakeup is not detected \n");
  } 
  #endif
  if(DemoTest == 0)
  {
    print_f("\n Demo Passed \n");	  
  }
  else   
  {
    print_f("\n Demo Failed \n");
    DemoTest = 1;	
  } 
  	
  	
  #if (0)
  #if (CANTRCV_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_ISR)
 
	  CanTrcv_17_6251G_CB_WakeupByBus(CanTraceiver); 

  #endif
  #endif
                                             
}









