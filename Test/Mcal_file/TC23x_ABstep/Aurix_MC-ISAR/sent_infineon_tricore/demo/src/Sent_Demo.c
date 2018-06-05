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
**  $FILENAME   : Sent_Demo.c $                                              **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2015-11-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for SENT module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Test_Time.h"
#include "Test_Print.h"
#include "DemoApp_Cfg.h"
#include "Sent_Demo.h"
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
static void Sent_PollingHandler (void);
static void printChanState (Sent_ChanStateType State);
static uint32 getParamU32(char s[]);
static void Sent_StartChannelDemo(uint8 ChannelId);
static void Sent_ParseSensorData(uint32 Data, uint8 StatNibble);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
Sent_ChanStatusType Sent_Stat;
uint32 Sent_RxData[SENT_HW_MAX_CHANNELS];
#if (SENT_SPC_USED == STD_ON)
Sent_SpcType Sent_Spc;
#endif
uint8 Sent_RxOverflowFlag[SENT_HW_MAX_CHANNELS];
uint8 Sent_TxUnderflowFlag[SENT_HW_MAX_CHANNELS];
uint8 Sent_ProtocolErrFlag[SENT_HW_MAX_CHANNELS];
uint8 Sent_WdgErrFlag[SENT_HW_MAX_CHANNELS];
uint8 Sent_TxSuccessFlag[SENT_HW_MAX_CHANNELS];
uint8 IgnoreCount = 0U;
uint8 AllowMenuPrint = 0U;
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/* Macros */




/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
 
/*******************************************************************************
** Syntax : void Sent_StartDemo(void)                                         **
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
void Sent_StartDemo(void)
{
  char szString[4];
  uint8 TempUSage = 0;
  /* Sent_PollingHandler to be called at 1ms at 80MHz */
  Test_Time_SetAlarm(0,0,800000,Sent_PollingHandler);
  
  while (TempUSage != 1U)
  {
    print_f("\n\n\n");
    print_f("\n/*********************************************************/\n");
    print_f("\n                SENT DRIVER TEST MENU                     \n ");
    print_f("\n                                                          \n ");
    print_f("     1.  Start Sent Channel Test                            \n ");
    print_f("     x.  Back To Main Menu                                  \n ");
    print_f("                                                            \n ");
    print_f("\n/*********************************************************/\n");
    print_f("  Enter Your Option :: ");
    
    getline(szString, sizeof (szString - 1));
     
    switch (*szString)
    {
       case '1':
       {
        uint8 ChannelId = 0U;
        
        print_f("\n  Enter Channel Num : ");
        getline(szString, 4);        
        ChannelId = (uint8) getParamU32(szString);
        Sent_StartChannelDemo(ChannelId);
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

static void Sent_StartChannelDemo(uint8 ChannelId)
{
  char szString[20];
  uint8 TempUSage = 0;

  while (TempUSage != 1U)
  {
    print_f("\n");
    print_f("\n/**************For Channel Id: %d*****************", ChannelId);    
    print_f("\n/*********************************************************/\n");
    print_f("     1.  Enable SENT Channel                                \n ");
    print_f("     2.  Disable SENT Channel                               \n ");
    print_f("     3.  Get SENT Channel Data                              \n ");    
    print_f("     4.  Get SENT Channel Status                            \n ");
    print_f("     5.  Enable Watchdog Timer (To Disable: Provide '0')    \n ");
    #if (SENT_SPC_USED == STD_ON)    
    print_f("     6.  Start SPC Sync Master Pulse                        \n ");
    #endif
    #if (SENT_ACCEN_API == STD_ON)    
    print_f("     7.  Get the SENT Access Enable register value          \n ");
    print_f("     8.  Set the SENT Access Enable register value          \n ");    
    #endif
    print_f("     x.  Back To SENT Main Menu                             \n ");
    print_f("                                                            \n ");
    print_f("\n/*********************************************************/\n");
    print_f("  Enter Your Option :: ");
    
    AllowMenuPrint = 1U;
    
    getline(szString, sizeof (szString - 1));
    
    switch (*szString)
    {
       case '1':
       {
        Sent_SetChannel(ChannelId, SENT_ENABLE);
        IgnoreCount = 1U;                
        break;
       }
       case '2' :
       {
        Sent_SetChannel(ChannelId, SENT_DISABLE);
        break;
       }
       case '3' :
       {
        print_f("\nSENT Channel Data: %x\n", Sent_RxData[ChannelId]);
        Sent_ParseSensorData(Sent_RxData[ChannelId], Sent_Stat.StatCommNibble);
        
        break;
       }       
       case '4' :
       {
        Sent_ReadChannelStatus(ChannelId, &Sent_Stat);
        print_f("\nSENT Channel State: ");
        printChanState (Sent_Stat.ChanStat);
        print_f("\nSENT Channel Timestamp: %x\n", Sent_Stat.RxTimeStamp);        
        break;
       }
       case '5' :
       {
        uint16 TimerVal;
        print_f("\nEnter Watchdog Timer Reload Value: ");        
        getline(szString, 20);    
        TimerVal = (uint16) getParamU32(szString);
        IgnoreCount = 1U;                        
        Sent_SetWdgTimer(ChannelId, TimerVal);
        break;
       }
       #if (SENT_SPC_USED == STD_ON)           
       case '6' :
       {
        Sent_Spc.Mode = SYNC_MODE;
        Sent_Spc.Delay = 0;
        Sent_Spc.PulseLength = 2; /* 3 ticks */
        Sent_Spc.TimeBase = PULSE_NOMINAL_FREQ;
        Sent_Spc.TriggerSource = PULSE_START_IMMED;
        Sent_SpcGenPulse(ChannelId, &Sent_Spc);        
        break;
       }
       #endif
       #if (SENT_ACCEN_MODE == SENT_ACCEN_API)           
       case '7' :
       {
        print_f("\nSENT_ACCEN0 Reg value: 0x%08x\n", Sent_GetAccessEnable());
        break;
       }

       case '8' :
       {
        uint32 AccenRegVal;
        
        print_f("\nEnter Access Enable value in decimal: ");        
        getline(szString, 20);    
        AccenRegVal = getParamU32(szString);       
        Sent_SetAccessEnable(AccenRegVal);        
        break;
       }       
       #endif
       case 'x':
       case 'X':
         TempUSage = 1;
         break;
       default :
         print_f(" \n\n Invalid option \n ");
       break;
   }
    
   AllowMenuPrint = 0U; 
  }

}

static void Sent_PollingHandler (void)
{
  uint32 ChannelId;
  
  if (IgnoreCount > 0)
  {
    IgnoreCount--;
  }
  
  if (AllowMenuPrint == 0) return;
  
  for (ChannelId = 0; ChannelId < SENT_HW_MAX_CHANNELS; ChannelId++)
  {
    if (Sent_RxOverflowFlag[ChannelId] == 1U)
    {
      Sent_RxOverflowFlag[ChannelId] = 0;              
      print_f("\nSENT Channel %d RX OVERFLOW occurred\n", ChannelId);       
    }

    if (Sent_TxSuccessFlag[ChannelId] == 1U)
    {
      Sent_TxSuccessFlag[ChannelId] = 0;                    
      print_f("\nSENT Channel %d TX Transmit success occurred\n", ChannelId);       
    }

    if (Sent_TxUnderflowFlag[ChannelId] == 1U)
    {
      Sent_TxUnderflowFlag[ChannelId] = 0;                          
      print_f("\nSENT Channel %d TX UNDERFLOW occurred\n", ChannelId);       
    }

    if (Sent_ProtocolErrFlag[ChannelId] == 1U)
    {
      Sent_ProtocolErrFlag[ChannelId] = 0;                                
      print_f("\nSENT Channel %d protocol error occurred\n", ChannelId);       
    }

    if (Sent_WdgErrFlag[ChannelId] == 1U)
    {
      Sent_WdgErrFlag[ChannelId] = 0;                                      
      print_f("\nSENT Channel %d Watchdog error occurred\n", ChannelId);       
    }
  }
}

void Sent_DemoAppCbk (Sent_ChannelIdxType ChannelId, uint32 Stat)
{
  uint16 IntFlagEnabled;

  IntFlagEnabled = (uint16)Stat;
  
  while (IntFlagEnabled)
  {
    /* Loop through all the enabled bits */
    switch (IntFlagEnabled & ((uint16)~(IntFlagEnabled - 1U)))
    {
      case SENT_INT_RDI_EVENT:        
        /* Ignore RDI bit, useful only when Frame Length is greater than
         * 8 nibbles since it can indicate that end of frame
         */
         break;
      case SENT_INT_RSI_EVENT:
        Sent_RxData[ChannelId] = Sent_ReadData(ChannelId);
        break;

      case SENT_INT_RBI_EVENT:
        Sent_RxOverflowFlag[ChannelId] = 1U;              
        break;

      #if (SENT_SPC_USED == STD_ON)        
      case SENT_INT_TDI_EVENT:
        Sent_TxSuccessFlag[ChannelId] = 1U;
        break;
      
      case SENT_INT_TBI_EVENT:
        /* If Transmit successful, then ignore Underflow since it is expected
         * in our SPC use case
         */        
        if (Sent_TxSuccessFlag[ChannelId] == 0U)
        {
          Sent_TxUnderflowFlag[ChannelId] = 1U;
        }
        break;          
          
      #endif /* SENT_SPC_USED == STD_ON */

      case SENT_INT_SDI_EVENT:
        /* Do nothing since no sensor usecase */
        break;
        
      case SENT_INT_WDI_EVENT:
        /* Ignore since sensor would be already sending some data */
        if (IgnoreCount == 0)
        {
          Sent_WdgErrFlag[ChannelId] = 1U;
        }
        break;

      case SENT_TRANS_INPROGRESS_EVENT:
        /* Do nothing */
        break;
        
      default:
        /* Any other will be flagged as protocol error */
        /* Ignore since sensor would be already sending some data */        
        if (IgnoreCount == 0)
        {      
          Sent_ProtocolErrFlag[ChannelId] = 1U;
        }
        break;          
    } /* end of switch */
    
    /* Clear the rightmost bit */
    IntFlagEnabled &= (IntFlagEnabled - 1U);
  }; /* end of while */     
}

static void printChanState (Sent_ChanStateType State)
{
  switch (State)
  {
    case SENT_STOP: print_f("STOP\n");
    break;
    
    case SENT_INITIALIZED: print_f("INITIALIZED\n");
    break;    

    case SENT_RUNNING: print_f("RUNNING\n");
    break;        

    case SENT_SYNCHRONIZED: print_f("SYNCHRONIZED\n");
    break;            
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

static void Sent_ParseSensorData(uint32 Data, uint8 StatNibble)
{    
  uint8 RangeVal = 0;    
  short HallVal = 0, Temperature = 0;    
  
  /* select B range [mT] */    
  if((StatNibble & 0x3) == 0) RangeVal = 200;    
  if((StatNibble & 0x3) == 1) RangeVal = 100;    
  if((StatNibble & 0x3) == 3) RangeVal =  50;    
  
  HallVal = (short)((((Data & 0xFFFF) * RangeVal)/0x7FFF) - RangeVal);    
  Temperature = ((short)((Data >> 16) & 0x00FF) - 55);    

  print_f("\nRange = +/- %dmT", RangeVal);    
  print_f("\nHALL data        B = %dmT",HallVal);    
  print_f("\nTemperature data T = %d DegreeC",Temperature);    
}
