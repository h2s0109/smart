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
**  $FILENAME   : Gpt_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\20 $                                                 **
**                                                                           **
**  $DATE       : 2014-09-17 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  GPT module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "IfxPort_reg.h"
#include "Mcal.h"
#include "Gpt.h"
#include "Gpt_Demo.h"
#include "Test_Print.h"
#include "DemoApp_Cfg.h"
#include "Port.h"
/* Inclusion of Tasking sfr file */
#include "IfxScu_reg.h"
#include "IfxStm_reg.h"
#include "IfxSrc_reg.h"
#include "Mcu_Cfg.h"
#include "Dio.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CALC_TICKS(time_in_s) (1250 * time_in_s)

#ifndef TRB_LED
#define TRB_LED DioConf_DioChannel_TRB_LED
#endif
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
 void Gpt_StartDemo(void);
 void Gpt_StopDemo(void);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

static uint32 GptDemo_McTimeDelay;
static uint8 DemoApp_LedNewValAvailable;
char GptString[50] = "MULTICORE DEMO MENU";

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
static const PAR_t Gpt_McDemoPar[] = 
{
  {
    PAR_TYP_DEC,                    /* uwType */ /*  for configuration 1 */
    sizeof(GptDemo_McTimeDelay),              /* uwSize */
    &GptDemo_McTimeDelay,                     /* pvData */
    0,                              /* uwMin */
    10000,                            /* uwMax */
    "Enter LED glow rate in seconds (1 to 52s):",        /* szText */
    "%d"                            /* szOutputFormat */
  }
};  

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
 volatile uint16 GPT_Channel_Notif[2];

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* GPT channel notification function declartion */
 void Gpt_Notification(void);
 void Gpt_MulticoreNotif(void);
 
 
extern volatile uint32 DemoApp_LedGlowDur;
extern volatile uint8 DemoApp_GlowLed;
/*******************************************************************************
** Syntax           : uint32 Get_Fgtm()                                       **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32 - Fgtm                                           **
**                                                                            **
** Description      : This function calculates Fgtm runtime                   **
**                                                                            **
*******************************************************************************/

uint32 Get_Fgtm()
{
	uint8 PDIV = SCU_PLLCON0.B.PDIV;
	uint8 NDIV = SCU_PLLCON0.B.NDIV;
	uint8 K2DIV = SCU_PLLCON1.B.K2DIV;
	
	uint32 Fsrc = 0;
	uint32 Fgtm = 0;
	
	if(SCU_PLLCON0.B.VCOBYP == 0)
	{
		Fsrc = ((MCU_MAIN_OSC_FREQ * 1000000) * (NDIV+1)) / ((PDIV + 1) * (K2DIV + 1));
	}
	else
	{
		Fsrc = (MCU_MAIN_OSC_FREQ * 1000000) / (K2DIV + 1);
	}
	
	Fgtm = Fsrc / (SCU_CCUCON1.B.GTMDIV);

	return Fgtm;
}
/*******************************************************************************
** Syntax : void Gpt_StartDemo(void)                                          **
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
** Description : In this routine the LED will start blinking i.e the Timer is **
            started in the continuous mode & blinks in the timer notifications**
*******************************************************************************/
void Gpt_StartDemo(void)
{
  	 uint32 Fgtm = 0;
     GPT_Channel_Notif[0] = 0;
     Gpt_EnableNotification(0);
     Fgtm = Get_Fgtm();
     Fgtm = ((uint32)(Fgtm/65536));/* CMU_FXCLK(4) selected 2^16 */
     Gpt_StartTimer(0,/*Ticks*/4*Fgtm); /* TimeOut 4 sec */
}
/*******************************************************************************
** Syntax : void Gpt_Notification(void)                                       **
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
** Description :  GPT Channel Notifications                                   **
*******************************************************************************/
void Gpt_Notification(void)
{


  /* start blinking the LED connected to P33.9*/
  GPT_Channel_Notif[0]++;

  if( GPT_Channel_Notif[0] == 1)
  {
    Dio_WriteChannel (TRB_LED,STD_HIGH);
  }
  else if(GPT_Channel_Notif[0] == 2)
  {
   Dio_WriteChannel (TRB_LED,STD_LOW);

    GPT_Channel_Notif[0] = 0;
  }  
}

/*******************************************************************************
** Syntax : void  Gpt_StopDemo(void)                                          **
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
void Gpt_StopDemo(void)
  {
    Gpt_StopTimer(0);  

  }


void Gpt_MulticoreNotif(void)
{
  DemoApp_GlowLed = 1;
}


void Gpt_StartMCDemo(void)
{
  if(DemoApp_LedNewValAvailable == 1)
  {
	  DemoApp_LedNewValAvailable = 0;
	  if(DemoApp_LedGlowDur == 0)
	  {
	    Gpt_StopTimer(1);     
	  }
	  else
	  {
		  Gpt_EnableNotification(1);
		  Gpt_StopTimer(1);     
		  Gpt_StartTimer(1,
		                /*Ticks*/CALC_TICKS(DemoApp_LedGlowDur));	
		}

  }
}


void Gpt_MCDemo(void)
{
	volatile uint8 TempUSage = 0;

 Port_SetPinMode(PORT_33_PIN_10,PORT_PIN_MODE_GPIO); 
   while (!TempUSage)
  {
  	
	  if (ParMenu(&GptString[0], 
	             (PAR_t *)Gpt_McDemoPar,  
	              sizeof(Gpt_McDemoPar)/sizeof(Gpt_McDemoPar[0])
	     ) != 'q')
	  {
       if(GptDemo_McTimeDelay <= 52)
       {
	       DemoApp_LedGlowDur = GptDemo_McTimeDelay;
	       DemoApp_LedNewValAvailable = 1;
	       DemoApp_GlowLed= 0;    
       }
	  }
	  else
	  {
	  	DemoApp_LedGlowDur = 0;
	  	DemoApp_LedNewValAvailable = 1;
	  	TempUSage = 1;
	  	
	  }   	
  }
}



