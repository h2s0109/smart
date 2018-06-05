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
**  $FILENAME   : Can_17_MCanP_Demo.c $                                      **
**                                                                           **
**  $CC VERSION : \main\11 $                                                 **
**                                                                           **
**  $DATE       : 2014-07-10 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - Demo application for CAN driver                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Can_17_MCanP_Demo.h"
#include "Can_17_MCanP.h"
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

#define CAN_17_MCANP_START_SEC_VAR_8BIT
#include "MemMap.h"

/* Global variables used for pass/fail criteria */
uint8 Test_RxConfirmCount;
uint8 Test_TxConfirmCount;

#define CAN_17_MCANP_STOP_SEC_VAR_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_VAR_8BIT
#include "MemMap.h"

/* Data Bytes For CAN Frame */
uint8 tx_data_1[][8] = {
    {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 },
    {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18 }, 
    {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28 }, 
    {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38 },
    {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48 }, 
    {0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58 }, 
    {0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68 },
    {0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78 }, 
    {0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88 }, 
    {0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98 },
} ;

#define CAN_17_MCANP_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define CAN_17_MCANP_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/* CAN Frame PDU Info With Standard Identifier */
Can_PduType PduInfo_1[] = 
{
  {8,  8, 0x123, tx_data_1[0] },
  {12, 8, 0x111, tx_data_1[1] },
  {9,  8, 0x456, tx_data_1[2] },
  {13, 8, 0x222, tx_data_1[3] }
};

/* CAN Frame PDU Info With Extended Identifier */
Can_PduType PduInfo_ExtId[] = 
{
  {10, 8, 0x8AAAAAAA, tx_data_1[4]},
  {14, 8, 0x81111111, tx_data_1[5]}
};

/* CAN Frame PDU Info With Mixed Identifier */
Can_PduType PduInfo_1_Mixed[] = 
{
  {15, 8, 0x00C,      tx_data_1[6] },
  {15, 8, 0x80300000, tx_data_1[7] }
};

Can_PduType PduInfo_2_Mixed[] = 
{
  {11, 8, 0x00A,      tx_data_1[8] },
  {11, 8, 0x80280000, tx_data_1[9] }
};

#define CAN_17_MCANP_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"

static void Can_StandardFrameTx(void);
static void Can_ExtendedFrameTx(void);
static void Can_MixedModeSupport(void);
static void Can_TestEnableDisableInterrupt(void);
static void Can_BaudrateChangeUsage(void);

#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

#define CAN_17_MCANP_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Can_17_MCanP_Demo (void)                                     **
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
void Can_17_MCanP_Demo(void)
{
  char szString[80];
  volatile uint8 TempUSage = 0;

  while (!TempUSage)
  {
    print_f("\n\n\n");
    print_f("\n/*********************************************************/\n");
    print_f("\n                CAN DRIVER TEST MENU                      \n ");
    print_f("\n                                                          \n ");
    print_f("     1.  Transfer of Standard Frame between CAN controllers \n ");
    print_f("     2.  Transfer of Extended Frame between CAN controllers \n ");
    print_f("     3.  Mixed Mode Support                                 \n ");
    print_f("     4.  Test Enabling and Disabling of Tx and Rx Interrupts\n ");
    print_f("     5.  Changing Baudrate                                  \n ");
    print_f("     x.  Back To Main Menu                                  \n ");
    print_f("                                                            \n ");
    print_f("\n/*********************************************************/\n");
    print_f("  Enter Your Option :: ");
    
    getline(szString, sizeof szString - 1);
     
    switch (*szString)
    {
       case '1':
       {
           Can_StandardFrameTx();
           break;
       }
       case '2' :
       {
           Can_ExtendedFrameTx();
           break;
       }
       case '3' :
       {
           Can_MixedModeSupport();
           break;
       }
       case '4' :
       {
           Can_TestEnableDisableInterrupt();
           break;
       }
       case '5' :
       {
           Can_BaudrateChangeUsage();
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
}/* Can_17_MCanP_Demo() */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
** Syntax : static void Can_StandardFrameTx(void)                             **
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
** Description : Transmission and Reception of CAN frames with Standard Id    **
**                                                                            **
*******************************************************************************/
static void Can_StandardFrameTx(void)
{
  volatile uint32 Counter;
  uint8 Test_TxCount = 0;
  uint8 i;

  Test_TxConfirmCount = 0;
  Test_RxConfirmCount = 0;

  /* Can_17_MCanP_Init(&Can_ConfigRoot[0]); */

  /* Put the CAN controllers into started state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_START);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_START);

  print_f("\n---------------------------------------------------------\n");
  print_f(" Standard Id Message Transfer Between Controller 0 and 1 \n");
  print_f("---------------------------------------------------------\n");

  for (i=0; i<2; i++)
  { 
    /* Data transmission by Controller 0 to 1 */
    print_f("\n Standard Id Message Transfer From Controller 0 to 1 \n");
    Can_17_MCanP_Write(i+8, &PduInfo_1[i*2]) ;
    
    /* Increment transmit counter */
    Test_TxCount++ ;
    
    /* Delay */
    Counter = 0x5FFFF;
    while(Counter--) ;
    
    #if (CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Write();
    #endif
    #if (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Read();
    #endif

    /* Data transmission by Controller 1 to 0 */
    print_f("\n Standard Id Message Transfer From Controller 1 to 0 \n");
    Can_17_MCanP_Write(i+12, &PduInfo_1[(i*2)+1]) ;
    
    /* Increment transmit counter */
    Test_TxCount++ ;
    
    /* Delay */
    Counter = 0x5FFFF;
    while(Counter--) ;
    
    #if (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Write();
    #endif
    #if (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Read();
    #endif
  }

  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;

  /* Put the CAN controllers into stopped state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_STOP);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_STOP);

  if((Test_TxConfirmCount!=Test_TxCount)||(Test_RxConfirmCount!=Test_TxCount))
  {
    print_f("\nCAN message transfer didn't happen. \n");
    print_f("Number of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : FAILED \n");    
  }
  else
  {
    print_f("\nNumber of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : SUCCESS \n");    
  }
}

/*******************************************************************************
** Syntax : static void Can_ExtendedFrameTx(void)                             **
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
** Description : Transmission and Reception of CAN frames with Extended Id    **
**                                                                            **
*******************************************************************************/
static void Can_ExtendedFrameTx(void)
{
  volatile uint32 Counter;
  uint8 Test_TxCount = 0;

  Test_TxConfirmCount = 0;
  Test_RxConfirmCount = 0;

  /* Put the CAN controllers into started state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_START);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_START);
   
  print_f("\n--------------------------------------------------------\n");
  print_f(" Extended Id Message Transfer Between Controller 0 and 1 \n");
  print_f("--------------------------------------------------------\n");
     
  /* Data transmission by Controller 0 to 1 */
  print_f("\n Extended Id Message Transfer From Controller 0 to 1 \n");
  Can_17_MCanP_Write(10, &PduInfo_ExtId[0]) ;
  
  /* Increment transmit counter */
  Test_TxCount++ ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  #if (CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Write();
  #endif
  #if (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Read();
  #endif

  /* Data transmission by Controller 1 to 0 */
  print_f("\n Extended Id Message Transfer From Controller 1 to 0 \n");
  Can_17_MCanP_Write(14, &PduInfo_ExtId[1]) ;
  
  /* Increment transmit counter */
  Test_TxCount++ ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  #if (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Write();
  #endif
  #if (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Read();
  #endif

  /* Put the CAN controllers into stopped state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_STOP);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_STOP);

  if((Test_TxConfirmCount!=Test_TxCount)||(Test_RxConfirmCount!=Test_TxCount))
  {
    print_f("\nCAN message transfer didn't happen. \n");
    print_f("Number of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : FAILED \n");    
  }
  else
  {
    print_f("\nNumber of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : SUCCESS \n");    
  }
}

/*******************************************************************************
** Syntax : static void Can_MixedModeSupport(void)                            **
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
** Description : Transmission and Reception of CAN frames with Mixed Id       **
**                                                                            **
*******************************************************************************/
static void Can_MixedModeSupport(void)
{
  volatile uint32 Counter;
  uint8 Test_TxCount = 0;

  Test_TxConfirmCount = 0;
  Test_RxConfirmCount = 0;

  /* Put the CAN controllers into started state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_START);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_START);

  print_f("\n------------------------------------------------------\n");
  print_f(" Mixed Id Message Transfer Between Controller 0 and 1 \n");
  print_f("------------------------------------------------------\n");
    
  /* Data transmission by Controller 1 to 0 */
  print_f("\n Standard Id Message Transfer From Controller 1 to 0 \n");
  Can_17_MCanP_Write(15, &PduInfo_1_Mixed[0]) ;
  
  /* Increment transmit counter */
  Test_TxCount++ ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  #if (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Write();
  #endif
  #if (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Read();
  #endif

  /* Data transmission by Controller 1 to 0 */
  print_f("\n Extended Id Message Transfer From Controller 1 to 0 \n");
  Can_17_MCanP_Write(15, &PduInfo_1_Mixed[1]) ;
  
  /* Increment transmit counter */
  Test_TxCount++ ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  #if (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Write();
  #endif
  #if (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Read();
  #endif

  /* Data transmission by Controller 0 to 1 */
  print_f("\n Standard Id Message Transfer From Controller 0 to 1 \n");
  Can_17_MCanP_Write(11, &PduInfo_2_Mixed[0]) ;
  
  /* Increment transmit counter */
  Test_TxCount++ ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  #if (CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Write();
  #endif
  #if (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Read();
  #endif

  /* Data transmission by Controller 0 to 1 */
  print_f("\n Extended Id Message Transfer From Controller 0 to 1 \n");
  Can_17_MCanP_Write(11, &PduInfo_2_Mixed[1]) ;
  
  /* Increment transmit counter */
  Test_TxCount++ ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  #if (CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Write();
  #endif
  #if (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
  Can_17_MCanP_MainFunction_Read();
  #endif

  /* Put the CAN controllers into stopped state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_STOP);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_STOP);

  if((Test_TxConfirmCount!=Test_TxCount)||(Test_RxConfirmCount!=Test_TxCount))
  {
    print_f("\nCAN message transfer didn't happen. \n");
    print_f("Number of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : FAILED \n");    
  }
  else
  {
    print_f("\nNumber of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : SUCCESS \n");    
  }
}

/*******************************************************************************
** Syntax : static void Can_TestEnableDisableInterrupt(void)                  **
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
** Description : Usage of Can_17_MCanP_DisableControllerInterrupts and        **
**               Can_17_MCanP_EnableControllerInterrupts APIs                 **
**                                                                            **
*******************************************************************************/
static void Can_TestEnableDisableInterrupt(void)
{
#if((CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)&&\
    (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)&&\
    (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)&&\
    (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT))

  volatile uint32 Counter;
  uint8 DemoResult_2_Failed = 0;

  Test_TxConfirmCount = 0;
  Test_RxConfirmCount = 0;

  /* Put the CAN controllers into started state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_START);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_START);

  print_f("\n---------------------------------------------\n");
  print_f(" Usage of APIs \n");
  print_f(" \t- Can_17_MCanP_DisableControllerInterrupts \n");
  print_f(" \t- Can_17_MCanP_EnableControllerInterrupts \n");
  print_f("---------------------------------------------\n");
  
  print_f("\n Disabling Controller 0 interrupts... \n");
  Can_17_MCanP_DisableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_0);

  print_f("\n Disabling Controller 0 interrupts one more time \n");
  Can_17_MCanP_DisableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_0);

  print_f("\n Controller 1 transmitting a message to Controller 0\n");
  print_f("\n No receive indication expected now\n");
  
  /* Controller 1 sends a message */
  Can_17_MCanP_Write(12, &PduInfo_1[1]) ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  if((Test_TxConfirmCount != 1 ) || (Test_RxConfirmCount != 0))
  {
    DemoResult_2_Failed++ ; 
  }        
  
  print_f("\n Controller 0 transmitting a message to Controller 0\n");
  print_f("\n No transmit indication expected now\n");
  
  /* Controller 0 sends a message */
  Can_17_MCanP_Write(8, &PduInfo_1[0]) ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
  
  if((Test_TxConfirmCount != 1 ) || (Test_RxConfirmCount != 1))
  {
    DemoResult_2_Failed++ ; 
  }      
  
  print_f("\n Disabling Controller 1 interrupts... ");
  Can_17_MCanP_DisableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_1);

  print_f("\n Disabling Controller 1 interrupts one more time ");
  Can_17_MCanP_DisableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_1);

  print_f("\n No transmit and receive indications expected now\n");
  
  print_f("\n Controller 1 transmitting a message to Controller 0\n");
  
  /* Controller 1 sends a message */
  Can_17_MCanP_Write(9, &PduInfo_1[2]) ;
  
  print_f("\n Controller 0 transmitting a message to Controller 1\n");

  /* Controller 0 sends a message */
  Can_17_MCanP_Write(13, &PduInfo_1[3]) ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;

  if((Test_TxConfirmCount != 1 ) || (Test_RxConfirmCount != 1))
  {
    DemoResult_2_Failed++ ; 
  }      
    
  print_f("\n Enabling interrupts ONCE for both controllers... ");
  Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_0);
  Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_1);

  print_f("\n Still there SHOULDN'T be any transmit or recieve indications");
  
  print_f("\n Controller 1 is transmitting a message to Controller 0\n");
    
  /* Controller 1 sends a message */
  Can_17_MCanP_Write(14, &PduInfo_ExtId[1]) ;

  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;

  print_f("\n Controller 0 is transmitting a message to Controller 1\n");

  /* Controller 0 sends a message */
  Can_17_MCanP_Write(10, &PduInfo_ExtId[0]) ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;

  if((Test_TxConfirmCount != 1 ) || (Test_RxConfirmCount != 1))
  {
    DemoResult_2_Failed++ ; 
  }      
    
  print_f("\n Enabling interrupts SECOND TIME for both controllers... ");
  Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_0);
  Can_17_MCanP_EnableControllerInterrupts(Can_17_MCanPConf_CanController_CanController_0_1);

  print_f("\n Pending transmit ok and receive indications ARE expected now\n");

  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
 
  if((Test_TxConfirmCount != 6 ) || (Test_RxConfirmCount != 6))
  {
    DemoResult_2_Failed++ ; 
  }        
  
  print_f("\n\n Transmit and receive indications for new transmit requests");
  print_f("\n are expected as usual now.\n");
  print_f("\n Controller 1 is transmitting a message.\n");
  
  /* Controller 1 sends a message */
  Can_17_MCanP_Write(12, &PduInfo_1[1]) ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;
 
  if((Test_TxConfirmCount != 7 ) || (Test_RxConfirmCount != 7))
  {
    DemoResult_2_Failed++ ; 
  }
  
  print_f("\n Controller 0 is transmitting a message.\n");
  
  /* Controller 0 sends a message */
  Can_17_MCanP_Write(8, &PduInfo_1[0]) ;
  
  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;

  /* Put the CAN controllers into stopped state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_STOP);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_STOP);

  if((Test_TxConfirmCount != 8 ) || (Test_RxConfirmCount != 8))
  {
    DemoResult_2_Failed++ ; 
  }

  if(DemoResult_2_Failed)
  {
    print_f("\n Result : FAILED \n");    
  }
  else
  {
    print_f("\n Result : SUCCESS \n");    
  }

#else

  print_f("\n For CAN controllers 0 and 1, both Tx and Rx ");
  print_f("processing should be interrupt mode\n");

#endif
}

/*******************************************************************************
** Syntax : static void Can_BaudrateChangeUsage(void)                         **
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
** Description : Usage of Can_17_MCanP_CheckBaudrate and                      **
**               Can_17_MCanP_ChangeBaudrate APIs                             **
**               for changing baudrate                                        **
**                                                                            **
*******************************************************************************/
static void Can_BaudrateChangeUsage(void)
{
  volatile uint32 Counter;
  Std_ReturnType RetVal;

  uint8 i;
  uint8 Test_TxCount;
  
  Test_TxCount = 0;
  Test_TxConfirmCount = 0;
  Test_RxConfirmCount = 0;

  print_f(" \n\n Current CAN communication baudrate is 500kbps \n");
  print_f(" \n CAN controllers should be in STOPPED state while changing ");
  print_f(" baudrate \n");
  
  print_f(" \n Set the CAN controller state to STOPPED state \n");
  /* Put the CAN controllers into stopped state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_STOP);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_STOP);

  print_f(" \n\n Change the CAN controllers baudrate to 1Mbps \n");

  /* check Baudrate 1Mbps for Can_17_MCanPConf_CanController_CanController_0_0 */
  RetVal = Can_17_MCanP_CheckBaudrate(Can_17_MCanPConf_CanController_CanController_0_0, 1000);
  if (E_OK == RetVal)
  {
    /* If baudrate is configured then change baudrate */
    RetVal = Can_17_MCanP_ChangeBaudrate(Can_17_MCanPConf_CanController_CanController_0_0, 1000);
    UNUSED_PARAMETER (RetVal)
  }
  
  /* check Baudrate 1Mbps for Can_17_MCanPConf_CanController_CanController_0_1 */
  RetVal = Can_17_MCanP_CheckBaudrate(Can_17_MCanPConf_CanController_CanController_0_1, 1000);
  if (E_OK == RetVal)
  {
    /* If baudrate is configured then change baudrate */
    RetVal = Can_17_MCanP_ChangeBaudrate(Can_17_MCanPConf_CanController_CanController_0_1, 1000);
    UNUSED_PARAMETER (RetVal)
  }

  print_f(" \n Set the CAN controller state to STARTED state \n");
  /* Put the CAN controllers into started state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_START);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_START);

  print_f("\n---------------------------------------------------------\n");
  print_f(" Standard Id Message Transfer Between Controller 0 and 1 \n");
  print_f("---------------------------------------------------------\n");

  for (i=0; i<2; i++)
  { 
    /* Data transmission by Controller 0 to 1 */
    print_f("\n Standard Id Message Transfer From Controller 0 to 1 \n");
    Can_17_MCanP_Write(i+8, &PduInfo_1[i*2]) ;
    
    /* Increment transmit counter */
    Test_TxCount++ ;
    
    /* Delay */
    Counter = 0x5FFFF;
    while(Counter--) ;
    
    #if (CAN_TX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Write();
    #endif
    #if (CAN_RX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Read();
    #endif

    /* Data transmission by Controller 1 to 0 */
    print_f("\n Standard Id Message Transfer From Controller 1 to 0 \n");
    Can_17_MCanP_Write(i+12, &PduInfo_1[(i*2)+1]) ;
    
    /* Increment transmit counter */
    Test_TxCount++ ;
    
    /* Delay */
    Counter = 0x5FFFF;
    while(Counter--) ;
    
    #if (CAN_TX_PROCESSING_HWCONTROLLER1 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Write();
    #endif
    #if (CAN_RX_PROCESSING_HWCONTROLLER0 == CAN_POLLING)
    Can_17_MCanP_MainFunction_Read();
    #endif
  }

  /* Delay */
  Counter = 0x5FFFF;
  while(Counter--) ;

  /* Put the CAN controllers into stopped state */
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_0, CAN_T_STOP);
  Can_17_MCanP_SetControllerMode (Can_17_MCanPConf_CanController_CanController_0_1, CAN_T_STOP);

  if((Test_TxConfirmCount!=Test_TxCount)||(Test_RxConfirmCount!=Test_TxCount))
  {
    print_f("\nCAN message transfer didn't happen. \n");
    print_f("Number of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : FAILED \n");    
  }
  else
  {
    print_f("\nNumber of transmits = %d \n", Test_TxCount);
    print_f("Number of transmit confirmations = %d \n", Test_TxConfirmCount);
    print_f("Number of receive indications = %d \n", Test_RxConfirmCount);
    print_f("Result : SUCCESS \n");    
  }
}

#define CAN_17_MCANP_STOP_SEC_CODE
#include "MemMap.h"
