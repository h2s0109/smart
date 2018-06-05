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
**  $FILENAME   : Mcu_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\19 $                                                 **
**                                                                           **
**  $DATE       : 2015-07-15 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  MCU module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Test_Main.h"
#include "Mcu.h"
#include "Mcu_Local.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "IfxSmu_reg.h"

#define MCU_SAFETY_ENDINT_TIMEOUT ((uint32)150000U)

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (MCU_SET_STANDBY_CONTROL_API == STD_ON)
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
#endif

#if (MCU_SAFETY_ENABLE == STD_ON) && (MCU_INITCHECK_API == STD_ON)
/*******************************************************************************
** Syntax : void Mcu_InitCheckDemo(void)                                      **
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
** Description : This routine calls Mcu_InitCheck                             **
*******************************************************************************/
void Mcu_InitCheckDemo(void)
{ 
  if (Mcu_InitCheck(Mcu_kConfigPtr) == E_OK)
  {
    print_f("MCU Initialization verification successful\n");
  }
  else
  {
    print_f("MCU Initialization verification failed\n");  
  }
  
  if ((SMU_DBG.U != 0x1U) || ((SMU_AG3.U & 0x7FFU) != 0U))
  {
    print_f("SMU not in RUN state/Clock Monitoring failed-Check SMU alarms\n");  
  }
}
#endif

/*******************************************************************************
** Syntax : void Mcu_SWResetDemo(void)                                        **
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
** Description : This routine calls Mcu_PerformReset , calls for the SW reset **
*******************************************************************************/
void Mcu_SWResetDemo(void)
{ 
  #if (MCU_CLR_COLD_RESET_STAT_API == STD_ON)
  Mcu_ClearColdResetStatus();
  #endif

  #if (MCU_SAFETY_ENABLE == STD_ON)
  /*Clear the SafetyENDINIT bit in the WDT_CON0 register in order
  to disable the write-protection for registers protected
  via the EndInit feature */
  Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
  #endif

  #if (MCU_PERFORM_RESET_API==STD_ON)
  Mcu_PerformReset();
  #endif

  /* No need to call SetSafetyENDINIT to allow watchdog to timeout if SW reset
   *  fails 
   */
}

/*******************************************************************************
** Syntax : void Mcu_GetResetReasonDemo(void)                                 **
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
** Description : This routine checks for one of the folowing reset reson      **
                  1.MCU_ESR0_RESET                                            **
                  2.MCU_ESR1_RESET                                            **
                  3.MCU_WATCHDOG_RESET                                        **
                  4.MCU_SW_RESET                                              **
                  5.MCU_POWER_ON_RESET                                        **
                  6.MCU_RESET_UNDEFINED                                       **
*******************************************************************************/
void Mcu_GetResetReasonDemo(void)
{ 
  uint32 ResetValue;

  ResetValue = Mcu_GetResetRawValue();
  print_f("Raw Value = 0x%x \n",ResetValue);

  /* If more than 1 bit set, print the different reset reasons */
  while (ResetValue)
  {
    switch ((ResetValue & ((uint32)~(ResetValue - 1U))))
    { 
      case 0x0:
       {
         print_f("MCU_ESR0_RESET Occured\n");
         break;
       }
      case 0x1:
       {
         print_f("MCU_ESR1_RESET Occured\n");
         break;
       }
      case 0x8: 
       {
         print_f("MCU_SMU_RESET Occured\n");
         break;
       } 
      case 0x10:
       {
         print_f("MCU_SW_RESET Occured\n");
         break;
       }
      case 0x20:
       {
         print_f("MCU_STM0_RESET Occured\n");
         break;
       }     
      case 0x40:
       {
         print_f("MCU_STM1_RESET Occured\n");
         break;
       } 
      case 0x80:
       {
         print_f("MCU_STM2_RESET Occured\n");
         break;
       } 
      case 0x10000:
       {
         print_f("MCU_POWER_ON_RESET Occured\n");
         break;
       }      
      case 0x40000:
       {
         print_f("MCU_CB0_RESET Occured\n");
         break;
       }
      case 0x80000:
       {
         print_f("MCU_CB1_RESET Occured\n");
         break;
       }
      case 0x100000:
       {
         print_f("MCU_CB3_RESET Occured\n");
         break;
       }
      case 0x200000:
       {
         print_f("MCU_TP_RESET Occured\n");
         break;
       }
      case 0x800000:
       {
         print_f("MCU_EVR13_RESET Occured\n");
         break;
       }
      case 0x1000000:
       {
         print_f("MCU_EVR33_RESET Occured\n");
         break;
       }     
      case 0x2000000:
       {
         print_f("MCU_SUPPLY_WDOG_RESET Occured\n");
         break;
       }
      case 0x10000000:
       {
         print_f("MCU_STBYR_RESET Occured\n");
         break;
       }     
      default :
       print_f("Undefined RESET Occured \n" );
      break;
  }
  /* Clear the rightmost bit */
  ResetValue &= (ResetValue - 1U);
  if (ResetValue)
  {
    print_f("and " );
  }
 }
}

/*******************************************************************************
** Syntax : void Mcu_GotoStandbyDemoMenu(void)                                **
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
void Mcu_GotoStandbyDemoMenu(void)
{
  char szString[16];
  uint8 TempUSage = 0;

  
  while (TempUSage != 1)
  {
    print_f("\n\n\n");
    print_f("\n/*********************************************************/\n");
    print_f("\n                MCU STANDBY TEST MENU                     \n ");
    print_f("\n                                                          \n ");
    print_f("     1.  Go to Standby                                      \n ");
    #if (MCU_SET_STANDBY_CONTROL_API == STD_ON)
    print_f("     2.  Update Standby Control register                    \n ");
    #endif
    #if (MCU_RAMP_TO_BACKUP_FREQ_API == STD_ON)
    print_f("     3.  Ramp down the clock to back up clock frequency     \n ");    
    #endif
    print_f("     4.  Check and clear wakeup status bits                 \n ");
    print_f("     5.  Go to Idle and wakeup after 10 seconds             \n ");    
    print_f("     x.  Back To Main Menu                                  \n ");
    print_f("                                                            \n ");
    print_f("\n/*********************************************************/\n");
    print_f("  Enter Your Option :: ");
    
    getline(szString, sizeof (szString - 1));
     
    switch (*szString)
    {
       case '1':
       {
        uint32 LoopCtr;
        uint32 *RARPtr;

        RARPtr = (uint32 *)MCU_STANDBY_DSPR0_RAR_AREA;
        /* PLS UDE loads some wrong data in DSPR0 area of Standby RAM
         * Workaround: Hence clearing it with 0's
         */
        for (LoopCtr = 0U; LoopCtr < MCU_STANDBY_DSPR0_RAR_SIZE; LoopCtr++)
        {
          *RARPtr = 0U;
          RARPtr++;
        }
        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_ResetENDINIT();    
        Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
        #endif
        Mcu_SetMode(MCU_STANDBY);
        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_SetSafetyENDINIT_Timed();           
        Mcal_SetENDINIT();   
        #endif
        break;
       }
       #if (MCU_SET_STANDBY_CONTROL_API == STD_ON)
       case '2':
       {
         uint32 PMSWCR0_RegVal;
         
        print_f("\n  Enter PMSWCR0 Register Value : ");
        getline(szString, 16); 
        PMSWCR0_RegVal = (uint32) getParamU32(szString);   
        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
        #endif        
        Mcu_SetStandbyCtrlReg(PMSWCR0_RegVal);
        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_SetSafetyENDINIT_Timed();           
        #endif        
        break;
       }
       #endif
       #if (MCU_RAMP_TO_BACKUP_FREQ_API == STD_ON)
       case '3':
       {
        Mcu_RampToBackUpClockFreq();
        break;
       } 
       #endif
       case '4':
       {
        uint32 WkpValue;
      
        WkpValue = Mcu_ChkWkpStdby();
        print_f("\n Wakeup Stat raw value %x\n", WkpValue);

        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_ResetSafetyENDINIT_Timed(MCU_SAFETY_ENDINT_TIMEOUT);
        #endif        
        /* Clear the relevant wakeup bits */
        Mcu_ClrWkpStdby(WkpValue & 0x1FC);  
        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_SetSafetyENDINIT_Timed();           
        #endif  
        
        WkpValue = WkpValue & 0x1FC;
        /* If more than 1 bit set, print the different wakeup reasons */
        while (WkpValue)
        {
          switch (WkpValue & ((uint32)~(WkpValue - 1U)))
          {
            case 0x4: print_f("ESR1 Wakeup Occured\n");
            break;
      
            case 0x8: print_f("ESR1 Wakeup Overrun Occured\n");
            break;
      
            case 0x10: print_f("PinA Wakeup Occured\n");
            break;
      
            case 0x20: print_f("PinA Wakeup Overrun Occured\n");
            break;
      
            case 0x40: print_f("PinB Wakeup Occured\n");
            break;   
      
            case 0x80: print_f("PinB Wakeup Overrun Occured\n");
            break;
      
            case 0x100: print_f("Power Wakeup Occured\n");
            break;      
          }
          
          /* Clear the rightmost bit */
          WkpValue &= (WkpValue - 1U);
          if (WkpValue)
          {
            print_f("and " );
          }    
        }
        break;
       }
       case '5':
       {
        /* Wake up after 10 seconds */
        Test_Time_SetAlarm(0, 1, 10 * Get_Fstm(), Mcu_GetResetReasonDemo);
        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_ResetENDINIT();
        #endif        
        
        Mcu_SetMode(MCU_IDLE);

        #if (MCU_SAFETY_ENABLE == STD_ON)
        Mcal_SetENDINIT();
        #endif         
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










