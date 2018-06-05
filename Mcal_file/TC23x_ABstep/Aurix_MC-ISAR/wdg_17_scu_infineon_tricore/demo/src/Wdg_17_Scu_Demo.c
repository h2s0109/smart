/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Wdg_17_Scu_Demo.c $                                        **
**                                                                            **
**  $CC VERSION : \main\35 $                                                 **
**                                                                            **
**  $DATE       : 2015-11-02 $                                               **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - sample Demo Test for  WDG module                         **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxScu_reg.h"
#include "IfxCpu_reg.h"
/* Inclusion of EcuM.h */
#include "EcuM.h"
#include "Wdg_17_Scu.h"
#include "Wdg_17_Scu_Safe.h"
#include "Wdg_17_Scu_Demo.h"
#include "Test_Print.h"
#include "Test_Time.h"

#ifdef IFX_MCAL_RUN_MODE_DEFINE
#if (IFX_MCAL_RUN_MODE_DEFINE!=0U)
#define CPU_PSW_USER_MODE_MASK (0xFFFFF3FFU)
#define SET_USER_MODE_MASK ((1U  <<  10U))
#endif
#endif

#define WDG_REGMAP  ((Ifx_SCU_WDTCPU *)(void *) &(SCU_WDTCPU0_CON0))
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
#if(WDG_MAXSAFE_TIMERS != 0U)
static void Wdg_17_Scu_lSafeTriggerDemo(void);
#if (WDG_SET_OFF_MODE_API == STD_ON)
static void Wdg_17_Scu_SetOffModeDemo(void);
#endif
#endif
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

const struct EcuM_ConfigType_Tag*   EcuMCore1ConfigPtr;

uint8 Wdg_Wdg1DemoStatusVar;
uint8 Wdg_Wdg2DemoStatusVar;

#if(WDG_MAXSAFE_TIMERS != 0U)
uint16 password[6]={0x00F0U,0x01E0U,0x03C0U,0x0780U,0x0F00U,0x1E01U};
uint16 SeqPass,ResetPass;
uint8 i[3];
uint8 j;
uint8 SafeCount;
#endif
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Wdg_17_Scu_Demo(void)                                        **
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
** Description : In this demo the Wdg can be started in the Fast mode or Slow **
** Mode for the said tiemout period. User should press the trigger key to stop**
** the WDG from resetting.                                                    **
** The user is provided the option to stop the WDG.                           **
** Note that If two consecutive resets are triggered by the WDG the target    **
** needs a Power On Reset.                                                    **
**                                                                            **
*******************************************************************************/

void Wdg_17_Scu_Demo(void)
{
  uint32 LoopCtr;
  uint32 PressedKey;

  /* Print user information */
  print_f("\n\n\n");
  print_f("\n/*****************************************************/\n");
  #if(WDG_MAX_TIMERS == 3U)
  print_f("\n     WDG DRIVER DEMO MENU - ALL 3 WDG's               ");
  #elif(WDG_MAX_TIMERS == 2U)
  print_f("\n     WDG DRIVER DEMO MENU - ALL 2 WDG's               ");
  #else
  print_f("\n     WDG DRIVER DEMO MENU                             ");
  #endif
  print_f("\n      ENTER YOUR OPTION                            ");
  print_f("\n/*****************************************************/\n");
  LoopCtr = 1U;

  while(LoopCtr != 0)
  {
   /*Demo Print for WDG 0 */
    print_f("\n 's'. Set WDG0 in slow mode");
    #if (WDG_17_SCU_MAJOR_VERSION==4)
    print_f("\n      Each press of key 's'will set trigger timeout period of 7 Seconds");
    #endif

    print_f("\n 'f'. Set WDG0 in Fast mode");
    #if (WDG_17_SCU_MAJOR_VERSION==4)
    print_f("\n      Each press of key 'f' will set trigger timeout period of 4 Seconds");
    #endif

    #if (WDG_17_SCU_MAJOR_VERSION==4)
    print_f("\n 't'. Press 't' to trigger WDG0 timeout for 4 seconds in current mode.");
    #endif
    #if (WDG_17_SCU_MAJOR_VERSION==3)
    print_f("\n 't'. Press 't',to trigger else WDG0 will overflow after the set time.");
    #endif
    print_f("\n 'x'. Stop WDG0 Timer \n");
   
    #if(WDG_MAX_TIMERS > 1U)
    /*Demo Print for WDG 1 with safety enabled */
    print_f("\n WDG1 configured with safety. ");
    print_f("\n Press a to initialize WDG1.");
    print_f("\n Press b to trigger WDG1 .");
    print_f("\n Press c to switch WDG1 to OFF mode .");
    print_f("\n 'a'. Set WDG1 initialization");
    print_f("\n      Each press of key 'a'will initialize WDG1");
    print_f("\n 'b'. Set WDG1 trigger");
    print_f("\n      Each press of key 'b' will set trigger ");
    print_f("\n 'c'. Press 'c' set to off mode.");
      
    #if(WDG_MAX_TIMERS == 3U)
    /*Demo Print for WDG 2 */
    print_f("\n 'j'. Set WDG2 in slow mode");
    #if (WDG_17_SCU_MAJOR_VERSION==4)

    print_f("\n      Each press of key 'j'will set trigger timeout period of 7 Seconds");
    #endif
    print_f("\n 'k'. Set WDG2 in Fast mode");
    #if (WDG_17_SCU_MAJOR_VERSION==4)
    print_f("\n      Each press of key 'k' will set trigger timeout period of 150 milli-seconds");
    #endif

    #if (WDG_17_SCU_MAJOR_VERSION==4)
    print_f("\n 'l'. Press 'l' to trigger WDG2 timeout for 4 seconds in current mode.");
    #endif
    #if (WDG_17_SCU_MAJOR_VERSION==3)
    print_f("\n 'l'. Press 'l',to trigger else WDG2 will overflow after the set time.");
    #endif
    print_f("\n 'm'. Stop WDG2 Timer \n");
    #endif
  #endif

    print_f("\n 'q'. Stop All WDG Timers and exit WDG demo \n");

    /* Get the Key pressed from user */
    PressedKey = get_char();

    if((PressedKey == 'S') || (PressedKey == 's'))
    {
       #if(WDG_MAXQM_TIMERS != 0U)
      Wdg_17_Scu_SetMode(WDGIF_SLOW_MODE);
       
      #if (WDG_17_SCU_MAJOR_VERSION==4)
      Wdg_17_Scu_SetTriggerCondition(7000);
      #endif
      #if (WDG_17_SCU_MAJOR_VERSION==3)
      Wdg_17_Scu_Trigger();
      #endif
      print_f("\n WDG0 has been started in Slow Mode \n");
      #endif
      
    }

    else if((PressedKey == 'F') || (PressedKey == 'f'))
    {
      #if(WDG_MAXQM_TIMERS != 0U)
      /* Start Watchdog in Fast Mode*/
      Wdg_17_Scu_SetMode(WDGIF_FAST_MODE);
      /* Start WDG Triggering */
      #if (WDG_17_SCU_MAJOR_VERSION==4)
      Wdg_17_Scu_SetTriggerCondition(4000);
      #endif
      #if (WDG_17_SCU_MAJOR_VERSION==3)
      Wdg_17_Scu_Trigger();
      #endif
      print_f("\n WDG0 has been started in Fast Mode \n");
      #endif
    }

    else if((PressedKey == 'T') || (PressedKey == 't'))
    {
      /* Start WDG Triggering */
      #if(WDG_MAXQM_TIMERS != 0U)
      #if (WDG_17_SCU_MAJOR_VERSION==4)
      Wdg_17_Scu_SetTriggerCondition(4000);
      #endif

      #if (WDG_17_SCU_MAJOR_VERSION==3)
      Wdg_17_Scu_Trigger();
      #endif
      print_f("\n WDG0 has been Triggered \n");
      #endif
    }

    /*Key pressed is 'X'*/
    else if((PressedKey == 'X') || (PressedKey == 'x'))
    {
       #if(WDG_MAXQM_TIMERS != 0U)
      Wdg_17_Scu_SetMode(WDGIF_OFF_MODE);
      print_f("\n WDG0 has been stoped \n");
      #endif
    }
    else if((PressedKey == 'A') || (PressedKey == 'a'))
    {
       if(0==Wdg_Wdg1DemoStatusVar)
       {
         Wdg_Wdg1DemoStatusVar = 1;
         print_f("\n WDG1 has been initialized \n");
       }
    }
    else if((PressedKey == 'B') || (PressedKey == 'b'))
    {
       if(0==Wdg_Wdg1DemoStatusVar)
       {
         Wdg_Wdg1DemoStatusVar = 2;
          print_f("\n WDG1 has been triggered \n");
       }
    }
    else if((PressedKey == 'C') || (PressedKey == 'c'))
    {
       if(0==Wdg_Wdg1DemoStatusVar)
       {
         Wdg_Wdg1DemoStatusVar = 3;
         print_f("\n WDG1 has been set to OFF mode \n");
       }
    }
    
    else if((PressedKey == 'J') || (PressedKey == 'j'))
    {
       if(0==Wdg_Wdg2DemoStatusVar)
       {
         Wdg_Wdg2DemoStatusVar = 1;
         print_f("\n WDG2 has been started in Slow Mode \n");
       }
    }
    else if((PressedKey == 'K') || (PressedKey == 'k'))
    {
       if(0==Wdg_Wdg2DemoStatusVar)
       {
          Wdg_Wdg2DemoStatusVar = 2;
          print_f("\n WDG2 has been started in Fast Mode \n");
       }
    }
    else if((PressedKey == 'L') || (PressedKey == 'l'))
    {
       if(0==Wdg_Wdg2DemoStatusVar)
       {
         Wdg_Wdg2DemoStatusVar = 3;
         print_f("\n WDG2 has been Triggered \n");
       }
    }
    else if((PressedKey == 'M') || (PressedKey == 'm'))
    {
       if(0==Wdg_Wdg2DemoStatusVar)
       {
         Wdg_Wdg2DemoStatusVar = 4;
         print_f("\n WDG2 has been stoped \n");
       }
    }
    else if((PressedKey == 'Q') || (PressedKey == 'q'))
    {
       Wdg_Wdg1DemoStatusVar = 4;
       Wdg_Wdg2DemoStatusVar = 4;
        #if(WDG_MAXQM_TIMERS != 0U)
       Wdg_17_Scu_SetMode(WDGIF_OFF_MODE);
       #endif
       /* Stop System Timer for WDG Triggering */
       LoopCtr = 0;
       print_f("\n All WDG's have been stopped \n");
    }
    else
    {
      print_f("\n  Invalid key pressed,  ");
    }
  }/* while */

  print_f("\n----------------------------------\n ");
  print_f("\n       EXIT WDG DEMO              \n ");
  print_f("\n----------------------------------\n ");
  return;

} /* WDG_Demo */

/*******************************************************************************
** Syntax : void Wdg_17_Scu_Core1Demo(void)                                   **
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
** Description : Execure WDG related APIs for Core1                           **
*******************************************************************************/
void Wdg_17_Scu_Core1Demo(void)
{
#ifdef IFX_MCAL_RUN_MODE_DEFINE
#if (IFX_MCAL_RUN_MODE_DEFINE!=0U)
  uint32 Cpu_PSW;
#endif
#endif
  switch (Wdg_Wdg1DemoStatusVar)
  {
    case 0:
    break;
    case 1:
    /*Determine ECU Configuration Set */
      #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_LOADABLE)
      /*Get Memory Location of the EcuM Configuration Set*/
      EcuMCore1ConfigPtr = EcuM_ConfigAddressPtr;
      /* In case of loadable the FlsStateVar memory area 48 bytes should be cleared.
        */
     #endif

     #if (ECUM_POSTBUILD_CONFIG_TYPE == ECUM_SELECTABLE)
     /*Get Configuration Set from available alternatives*/
     
      EcuMCore1ConfigPtr =  &EcuM_ConfigAlternative[0];
     
     #endif
      
     /*WDG1 initialization  */
       #if(WDG_PB_FIXEDADDR == STD_OFF)
       Wdg_17_Scu_Init(EcuMCore1ConfigPtr->Wdg_ConfigData);
       #else
       Wdg_17_Scu_Init(&Wdg_ConfigRoot[0]);
       #endif
      
       Wdg_Wdg1DemoStatusVar = 0;
       
    break;
    case 2:
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  #if (IFX_MCAL_RUN_MODE_DEFINE!=0U)
    /* Set mode to user-1 mode. */
    Cpu_PSW = (uint32)MFCR(CPU_PSW);
    Cpu_PSW = (Cpu_PSW & CPU_PSW_USER_MODE_MASK);
    Cpu_PSW = (Cpu_PSW | SET_USER_MODE_MASK);
    MTCR (CPU_PSW, Cpu_PSW);
  #endif
  #endif
  
    #if(WDG_MAXSAFE_TIMERS != 0U)
    /*WDG1 safe trigger  */
       Wdg_17_Scu_lSafeTriggerDemo();
       Wdg_Wdg1DemoStatusVar = 0;
    #endif
    break;
    case 3:
  #ifdef IFX_MCAL_RUN_MODE_DEFINE
  #if (IFX_MCAL_RUN_MODE_DEFINE!=0U)
    /* Set mode to user-1 mode. */
    Cpu_PSW = (uint32)MFCR(CPU_PSW);
    Cpu_PSW = (Cpu_PSW & CPU_PSW_USER_MODE_MASK);
    Cpu_PSW = (Cpu_PSW | SET_USER_MODE_MASK);
    MTCR (CPU_PSW, Cpu_PSW);
  #endif
  #endif
    /*WDG1 switch to OFF mode */
    #if (WDG_SET_OFF_MODE_API == STD_ON)
    #if(WDG_MAXSAFE_TIMERS != 0U)
       Wdg_17_Scu_SetOffModeDemo();
       Wdg_Wdg1DemoStatusVar = 0;
    #endif
    #endif
    break;
    
    default:
       Wdg_Wdg1DemoStatusVar = 0;
    break;

  }
}
/*******************************************************************************
** Syntax : void Wdg_17_Scu_Core2Demo(void)                                   **
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
** Description : Execure WDG related APIs for Core1                           **
*******************************************************************************/
void Wdg_17_Scu_Core2Demo(void)
{
  switch (Wdg_Wdg2DemoStatusVar)
  {
    case 0:
    break;
    case 1:
    /* switch WDG2 to slow mode */
       #if(WDG_MAXQM_TIMERS != 0U)
       Wdg_17_Scu_SetMode(WDGIF_SLOW_MODE);
       /* trigger WDG2 in slow mode */
       #if (WDG_17_SCU_MAJOR_VERSION==4)
       Wdg_17_Scu_SetTriggerCondition(7000);
       #endif
       #if (WDG_17_SCU_MAJOR_VERSION==3)
       Wdg_17_Scu_Trigger();
       #endif
       #endif
       Wdg_Wdg2DemoStatusVar = 0;
    break;
    case 2:
      #if(WDG_MAXQM_TIMERS != 0U)
      /* Start Watchdog in Fast Mode*/
      Wdg_17_Scu_SetMode(WDGIF_FAST_MODE);
      /* Start WDG Triggering */
      #if (WDG_17_SCU_MAJOR_VERSION==4)
      Wdg_17_Scu_SetTriggerCondition(4000);
      #endif
      #if (WDG_17_SCU_MAJOR_VERSION==3)
      Wdg_17_Scu_Trigger();
      #endif
      #endif
      Wdg_Wdg2DemoStatusVar = 0;
      
    break;
    case 3:
       #if(WDG_MAXQM_TIMERS != 0U)
      /* Start WDG Triggering */
       #if (WDG_17_SCU_MAJOR_VERSION==4)
       Wdg_17_Scu_SetTriggerCondition(4000);
       #endif

       #if (WDG_17_SCU_MAJOR_VERSION==3)
       Wdg_17_Scu_Trigger();
       #endif
       #endif
       Wdg_Wdg2DemoStatusVar = 0;
    break;
    case 4:
       #if(WDG_MAXQM_TIMERS != 0U)
       Wdg_17_Scu_SetMode(WDGIF_OFF_MODE);
       #endif
       Wdg_Wdg2DemoStatusVar = 0;
    break;
    default:
       Wdg_Wdg2DemoStatusVar = 0;
    break;
  }
}
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
  
  
/*******************************************************************************
** Syntax : void Wdg_17_Scu_SafeTriggerDemo(void)                             **
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
** Description : Execure WDG related APIs for Core1                           **
*******************************************************************************/
#if(WDG_MAXSAFE_TIMERS != 0U)
 void Wdg_17_Scu_lSafeTriggerDemo(void)
{

  uint16 Time;
  uint8 CoreId;
  /* get core id */
  CoreId = Mcal_GetCoreId();
  /* get password index of the respective core id */
  j = i[CoreId];
  /* Get sequence and reset password */
  if(j==4U)
  {
    Wdg_17_Scu_SetOffModeDemo();
    ResetPass = password[0];
   /*WDG1 initialization  */
    #if(WDG_PB_FIXEDADDR == STD_OFF)
    Wdg_17_Scu_InitAltResetPassword(EcuMCore1ConfigPtr->Wdg_ConfigData, ResetPass);
    #else
    Wdg_17_Scu_InitAltResetPassword(&Wdg_ConfigRoot[0], ResetPass);
    #endif
    i[CoreId] = 1U;
    SeqPass = password[i[CoreId]];
    i[CoreId]++;
  }
  else
  {
    SeqPass = password[j];
    i[CoreId]++;
  }

  /* Get the current WDG1 timer value */
  Time = (uint32)WDG_REGMAP[CoreId].SR.B.TIM;
  
  /*WDG1 safe trigger  */
  Wdg_17_Scu_SafeTrigger(SeqPass,(~Time));
}
#endif

/*******************************************************************************
** Syntax : void Wdg_17_Scu_SetOffModeDemo(void)                              **
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
** Description : Execure WDG related APIs for Core1                           **
*******************************************************************************/
#if (WDG_SET_OFF_MODE_API == STD_ON)
#if(WDG_MAXSAFE_TIMERS != 0U)
 void Wdg_17_Scu_SetOffModeDemo(void)
{
  uint8 CoreId;
  uint16 Pass1;
  uint16 Pass2;
  /* get core id */
  CoreId = Mcal_GetCoreId();
  j = i[CoreId];
  Pass1 = password[j];
  j++;
  Pass2 = password[j];
  /*Test_Time_DeInitAlarm (0U);*/
  Wdg_17_Scu_SetOffMode(Pass1,Pass2);
  print_f("WDG1 stopped");
}
#endif
#endif