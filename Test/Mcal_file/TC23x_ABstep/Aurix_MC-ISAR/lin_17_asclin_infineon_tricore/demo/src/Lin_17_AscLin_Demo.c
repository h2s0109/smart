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
**  $FILENAME   : Lin_17_AscLin_Demo.c $                                     **
**                                                                           **
**  $CC VERSION : \main\20 $                                                 **
**                                                                           **
**  $DATE       : 2015-11-02 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - sample Demo Test for  LIN module                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"
#include "Lin_17_AscLin.h"
#include "Lin_17_AscLin_Demo.h"
#include "DemoApp_Cfg.h"
#include "IfxCpu_reg.h"

#define MAX_WAIT_LOOP           (0xFFF0)
#define LIN_CHANNELID0_CONFIG0 (0)

#define OPERATIONAL_STATE (LIN_OPERATIONAL)
#define CPU_PSW_USER_MODE_MASK (0xFFFFF3FFU)
#define SET_USER_MODE_MASK ((1U  <<  10U))
/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/
uint8 Sdu_Data[][8] = 
{
  {1,2,3,4,5,6,7,8}, 
  {0xFF, 0x00, 0xFF, 0x00,0xFF, 0x00,0xFF, 0x00}  
 };

Lin_PduType Lin_Pdu[] = 
{
/*Lin_FramePidType Pid, Lin_FrameCsModelType Cs,Lin_FrameResponseType Drc,Lin_FrameDlType Dl, uint8 *SduPtr */
  {0x80, LIN_ENHANCED_CS, LIN_MASTER_RESPONSE, 8, Sdu_Data[0] },
  {0xC1, LIN_ENHANCED_CS, LIN_SLAVE_RESPONSE, 8,  Sdu_Data[1]}  
};

#ifdef _TASKING_C_TRICORE_
#pragma align 4
#endif

uint8 UserData[8] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
volatile uint8 *SlaveSduPtr = UserData;

#ifdef _TASKING_C_TRICORE_
#pragma align restore
#endif

/*******************************************************************************
**                      Private Function Declarations                           **
*******************************************************************************/
void Lin_GetStatusDemo(void);

/*******************************************************************************
**                      Private Function Definitions                           **
*******************************************************************************/
void Lin_Master_Response(void)
{
  Lin_StatusType  Ret2 ;
  Std_ReturnType Ret1;

  print_f(" Start Send Frame. (MASTER RESPONSE) \n  ");
  Ret1 = Lin_17_AscLin_SendFrame(LIN_CHANNELID0_CONFIG0, &Lin_Pdu[0]);
  
  if (Ret1 == E_NOT_OK)
    print_f(" Error in sending Frame.\n ");

  do{
    Ret2 = Lin_17_AscLin_GetStatus(LIN_CHANNELID0_CONFIG0, (uint8 **)&SlaveSduPtr);
    
    if ((Ret2 != LIN_TX_BUSY) && (Ret2 != LIN_TX_OK)&& (Ret2 != OPERATIONAL_STATE))
    {
      print_f(" Transmit Error..."); 
      break;
    }
  }while(Ret2 != LIN_TX_OK );

  if (Ret2 == LIN_TX_OK)
  {
    print_f("LIN Header (PID 0x80) Transmitted sucessfully. ");
    print_f("Data (0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8) is transmitted. please verify it at the slave\n");
  }
  else
  {
      print_f(" Lin Master->Slave Response Failed. Response code: %x \n", Ret2);    
  }

}

void Lin_Slave_Response(void)
{
  uint8  i;
  Lin_StatusType  Ret2;
  Std_ReturnType Ret1;

  print_f(" Start Send Frame. (SLAVE RESPONSE) \n  ");
  Ret1 = Lin_17_AscLin_SendFrame(LIN_CHANNELID0_CONFIG0, &Lin_Pdu[1]);
  
  if (Ret1 == E_NOT_OK)
    print_f(" Lin Slave->Master Response Failed. \n ");

  do{
    Ret2 = Lin_17_AscLin_GetStatus(LIN_CHANNELID0_CONFIG0, (uint8 **)&SlaveSduPtr);
    
    if ((Ret2 != LIN_TX_BUSY) && (Ret2 != LIN_RX_OK) && 
        (Ret2 != LIN_RX_NO_RESPONSE) && (Ret2 != LIN_RX_BUSY) && (Ret2 != OPERATIONAL_STATE))
    {
      print_f(" Lin Slave->Master Response Failed \n"); 
      break;
    }
  }while(Ret2 != LIN_RX_OK );

  if(Ret2 == LIN_RX_OK )
  {
    print_f("LIN Frame (PID 0xC1) Transmission sucessful .\n");
    print_f("data Received @ Master  \n");  
    for (i=0; i < 8 ; i++)
    {
      print_f("%x ",SlaveSduPtr[i]);
    }
  }
}


void Lin_GoToSleepDemo()
{
     uint32 WaitLoop;

     print_f("\n Started sending the Sleep command \n");
     Lin_17_AscLin_GoToSleep(LIN_CHANNELID0_CONFIG0);
      WaitLoop = 0;
      while( (LIN_CH_SLEEP != (Lin_17_AscLin_GetStatus(LIN_CHANNELID0_CONFIG0, (uint8 **)&SlaveSduPtr))) && (WaitLoop < MAX_WAIT_LOOP))
      {
         WaitLoop++;
      };
      
      if(WaitLoop == MAX_WAIT_LOOP)
      {
         print_f("Not sent Sleep Command within loop count of %d \n", WaitLoop); 
      }
      else
      {
         print_f("Lin Channel is in Sleep state \n");
      }

}

void Lin_GoToSleepInternalDemo()
{
  
      /* Internal Sleep  - Lin_GoToSleepInternal */
    Lin_17_AscLin_GoToSleepInternal(LIN_CHANNELID0_CONFIG0);
    print_f(" Requested for Sleep internal \n");
    print_f(" Current status :");
    Lin_GetStatusDemo();
}

void Lin_WakeupDemo()
{
   /* Validate Wakeup - Lin_WakeUpValidation */
   print_f("\n  Started sending the Wakeup command \n");
   Lin_17_AscLin_Wakeup(LIN_CHANNELID0_CONFIG0);
   while( LIN_CH_SLEEP == (Lin_17_AscLin_GetStatus(LIN_CHANNELID0_CONFIG0, (uint8 **)&SlaveSduPtr)))
    {};
   print_f("Lin Channel is in Operational state \n");
  
}

void Lin_WakeUpValidationDemo()
{
    /* Validate Wakeup - Lin_WakeUpValidation */
    #if ((LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION >= 4U) && \
     (LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION >= 0U) && \
     (LIN_17_ASCLIN_AR_RELEASE_REVISION_VERSION <= 2U))
      Lin_17_AscLin_WakeupValidation();
     #else
      Lin_17_AscLin_CheckWakeup(LIN_CHANNELID0_CONFIG0);
     #endif
    print_f(" Requested for Lin_WakeUpValidation \n");
  
}
void Lin_GetStatusDemo()
{
  uint8 Ret2;
  uint8 Counter;
    Ret2 = (uint8)Lin_17_AscLin_GetStatus(LIN_CHANNELID0_CONFIG0, (uint8 **)&SlaveSduPtr);

    switch(Ret2)
    {
       case LIN_TX_BUSY         :
          print_f(" LIN_TX_BUSY \n");
          break;
       case LIN_NOT_OK             :
          print_f(" LIN_NOT_OK \n");
          break;
       case LIN_TX_HEADER_ERROR             :
          print_f(" LIN_TX_HEADER_ERROR \n");
          break;
       case LIN_TX_ERROR             :
          print_f(" LIN_TX_ERROR \n");
          break;
       case LIN_RX_BUSY             :
          print_f(" LIN_RX_BUSY \n");
          break;
       case LIN_RX_ERROR             :
          print_f(" LIN_RX_ERROR \n");
          break;
       case LIN_RX_NO_RESPONSE             :
          print_f(" LIN_RX_NO_RESPONSE \n");
          break;
       case LIN_CH_SLEEP             :
          print_f(" LIN_CH_SLEEP \n");
          break;
       case OPERATIONAL_STATE      :
          print_f(" LIN_OPERATIONAL \n");
          break;
       case LIN_RX_OK               :
          print_f(" LIN_RX_OK \n");
          print_f(" Received Data's. Here it displays all data's present in buffer. Consider depending on data length considered ");
          for(Counter = 0; Counter < 8; Counter++)
          {
             print_f("0x%X, ", *( SlaveSduPtr + Counter ) );
          }
          break;
       case LIN_TX_OK               :
          print_f(" LIN_TX_OK \n");
          break;
    #ifdef LIN_17_TIMEOUT_SUPPORT
       case LIN_TX_HEADER_TIMEOUT_ERROR               :
          print_f(" LIN_TX_HEADER_TIMEOUT_ERROR \n");
          break;
       case LIN_RX_RESPONSE_TIMEOUT_ERROR               :
          print_f(" LIN_RX_RESPONSE_TIMEOUT_ERROR \n");
          break;
    #endif
    }

}


/*******************************************************************************
** Syntax : void Lin_DriverDemo()                                             ** 
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): Channel:                                                  ** 
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Master Sends the Header and response to slave(ID - 0x80)     **
*******************************************************************************/
void Lin_Demo()
{
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  /* IFX_MCAL_RUN_MODE_DEFINE = 0 indicates MCAL,
  runs in Supervisor mode*/
  #if(IFX_MCAL_RUN_MODE_DEFINE != 0U)
  uint32 Cpu_PSW;
  #endif 
  #endif 
  char szString[80];
  int loopvar;
  loopvar = 0;

  print_f("\n---------------  Start of LIN driver demo ---------------\n");
  
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  /* IFX_MCAL_RUN_MODE_DEFINE = 0 indicates MCAL,
    runs in Supervisor mode*/
  #if(IFX_MCAL_RUN_MODE_DEFINE != 0U)
      /* Set the user-1 mode on*/
  Cpu_PSW = (uint32)MFCR(CPU_PSW);
  Cpu_PSW = (Cpu_PSW & CPU_PSW_USER_MODE_MASK);
  Cpu_PSW = (Cpu_PSW | SET_USER_MODE_MASK);
  MTCR (CPU_PSW, Cpu_PSW); /* Set mode to user-1 mode. */
  #endif /* IFX_MCAL_RUN_MODE_DEFINE */
  #endif /* IFX_MCAL_RUN_MODE_DEFINE */
  
   do{
    print_f("\n---------------  LIN driver Demo Menu---------------\n");
    print_f("\n  <0>LIN: Master -> Slave Respone");
    print_f("\n  <1>LIN: Slave -> Master Respone");
    print_f("\n  <2>LIN: Send Sleep Command to bus - Lin_GoToSleep");
    print_f("\n  <3>LIN: Send Wakeup Signal to Bus (250us to 5ms) - Lin_WakeUp");
    print_f("\n  <5>LIN: Get Status - Lin_GetStatus");
    print_f("\n  <6>LIN: Internal Sleep  - Lin_GoToSleepInternal ");
    print_f("\n  <.>Back To Main Menu");
    print_f("\n ENTER YOUR OPTION:  ");
    getline(szString, sizeof szString - 1);
    print_f("\n\n");

  switch (*szString)
  {
    case '0':
    {      
      Lin_Master_Response();
      break;
    }
    case '1':
    {      
      Lin_Slave_Response();
      break;
    }
    case '2':
    {      
      Lin_GoToSleepDemo();
      break;
    }
    case '3':
    {      
      Lin_WakeupDemo();
      break;
    }
    case '5':
    {      
      Lin_GetStatusDemo();
      break;
    }
    case '6':
    {      
      Lin_GoToSleepInternalDemo();
      break;
    }
    case '.':
    {
      loopvar = 1;
      break;
    }

  }
}while(loopvar == 0);

  print_f("\n---------------  End of LIN driver demo ---------------\n");

}



