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
**  $FILENAME   : Gtm_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\21 $                                                 **
**                                                                           **
**  $DATE       : 2014-09-17 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  GTM module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Mcal.h"
#include "Gtm.h"
#include "Port.h"
#include "Test_Print.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* GTM Fixed Clock 4 is 1525 Hz. */
/* Time is in seconds) */
  /* GTM_DEMO_EP to be configured in PortPinSymbolicName value if required */
  #ifndef GTM_DEMO_EP  
  #define GtmDemo_TicksCalc(Time) ((Time) * 1525)
  #else
  #define GtmDemo_TicksCalc(Time) ((Time) * 763)
  #endif
  
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
 void Gtm_Demo(void);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint8 GtmDemo_DutyCycleBackup = 50;
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
** Syntax : void Gtm_Demo(void)                                          **
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
** Description : Demo Application for GTM                                     **
*******************************************************************************/
void Gtm_Demo(void)
{
	
  char szString[80];
	uint16 DutyCycle; 
	uint8 TempUSage = 1U;
  uint8 ModuleNumber=0,ChannelNumber=0;
  /* GTM_DEMO_EP to be configured in PortPinSymbolicName value if required */
  #ifndef GTM_DEMO_EP  
  Port_SetPinMode(PORT_33_PIN_10,PORT_PIN_MODE_ALT1); 
  #else
  Port_SetPinMode(GTM_DEMO_EP,PORT_PIN_MODE_ALT1);
  ChannelNumber=5;
  #endif
  
  while (TempUSage == 1U)
  {
     print_f("\n\n\n");
     print_f("\n/*********************************************************/\n");
     print_f("\n           GTM DRIVER DEMO MENU                          ");
     print_f("\n             ENTER YOUR OPTION                              ");
     print_f("\n 1. Enable PWM Generation in Port33 Pin10(Run this only once)");
     print_f("\n 2. Change Period to 5 s   ");
     print_f("\n 3. Change Period to 10 s  ");		 
     print_f("\n 4. Change Period to 15 s  ");		 		 		 
     print_f("\n 5. Change Period to 20 s  ");		 		 
     print_f("\n 6. Change Duty to 0 Percent       ");   
     print_f("\n 7. Change Duty to 25 Percent      ");   
     print_f("\n 8. Change Duty to 50 Percent      ");   		 
     print_f("\n 9. Change Duty to 75 Percent      ");   		 		 
     print_f("\n A. Change Duty to 100 Percent     ");  
     print_f("\n X. Go back to main menu    ");  		 
     print_f("\n Option: ");
     
     getline(szString, sizeof szString - 1);                                   
      
     switch (*szString)
     {
       case '1': 	Gtm_EnableTomChannel(ModuleNumber, ChannelNumber);
       break;
			 case '2':  DutyCycle = ((uint16)GtmDemo_TicksCalc(5) * GtmDemo_DutyCycleBackup)/100;                               
			 						Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle);                                      
			 						Gtm_SetTomShadowValSr0(ModuleNumber, ChannelNumber,GtmDemo_TicksCalc(5));                                      
			 break;
			 case '3':  DutyCycle = ((uint16)GtmDemo_TicksCalc(10) * GtmDemo_DutyCycleBackup)/100;
			 						Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle);
			 						Gtm_SetTomShadowValSr0(ModuleNumber, ChannelNumber,GtmDemo_TicksCalc(10));
			 break;
			case '4':   DutyCycle = ((uint16)GtmDemo_TicksCalc(15) * GtmDemo_DutyCycleBackup)/100;
			 						Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle);
			 						Gtm_SetTomShadowValSr0(ModuleNumber, ChannelNumber,GtmDemo_TicksCalc(15));
				break;
			case '5':   DutyCycle = ((uint16)GtmDemo_TicksCalc(20) * GtmDemo_DutyCycleBackup)/100;
			 						Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle);
			 						Gtm_SetTomShadowValSr0(ModuleNumber, ChannelNumber,GtmDemo_TicksCalc(20));							 
				break;
			case '6': 	
									DutyCycle = Gtm_GetTomCompareValCm0(ModuleNumber, ChannelNumber);
				          Gtm_SetTomCompareValCm1(ModuleNumber, ChannelNumber,DutyCycle);
				          Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle); 
                  ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber].\
                                             CH[ChannelNumber].CTRL.U) |=    \
                                      (unsigned_int)(GTM_BIT_SET << GTM_TOM_SL_POS); 	
				          GtmDemo_DutyCycleBackup = 0;						 
				break;
			case '7': 	DutyCycle =  Gtm_GetTomCompareValCm0(ModuleNumber, ChannelNumber);
									DutyCycle = DutyCycle/4;
				          ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber].\
				                               CH[ChannelNumber].CTRL.U) &=   \
                               (unsigned_int)(~(GTM_BIT_SET << GTM_TOM_SL_POS));  									
				          Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle); 
				          GtmDemo_DutyCycleBackup = 25;						 
				break;
			case '8': 	DutyCycle =  Gtm_GetTomCompareValCm0(ModuleNumber, ChannelNumber);
									DutyCycle = DutyCycle/2;
				          ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber].\
				              CH[ChannelNumber].CTRL.U) &=   \
                                  (unsigned_int)(~(GTM_BIT_SET << GTM_TOM_SL_POS));  									
									Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle); 	
									GtmDemo_DutyCycleBackup = 50;					 
				break;
			case '9': 	DutyCycle =  Gtm_GetTomCompareValCm0(ModuleNumber, ChannelNumber);
									DutyCycle = (DutyCycle * 3)/4;
				          ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber].\
				                         CH[ChannelNumber].CTRL.U) &=   \
                                   (unsigned_int)(~(GTM_BIT_SET << GTM_TOM_SL_POS));  									
									Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle); 	
									GtmDemo_DutyCycleBackup = 75;					 
				break;
			case 'a':
			case 'A': 	DutyCycle =  Gtm_GetTomCompareValCm0(ModuleNumber, ChannelNumber);
									Gtm_SetTomCompareValCm1(ModuleNumber, ChannelNumber,DutyCycle); 
									Gtm_SetTomShadowValSr1(ModuleNumber, ChannelNumber,DutyCycle); 
				          ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNumber].\
				                                  CH[ChannelNumber].CTRL.U) &=   \
                                   (unsigned_int)(~(GTM_BIT_SET << GTM_TOM_SL_POS));                                       								
									GtmDemo_DutyCycleBackup = 100;						 
				break;

       case 'x':
       case 'X':TempUSage = 0U;
       	       	Gtm_DisableTomChannel(ModuleNumber, ChannelNumber);
       	       	#ifndef GTM_DEMO_EP  
                Port_SetPinMode(PORT_33_PIN_10,PORT_PIN_MODE_GPIO); 
                #else
                Port_SetPinMode(GTM_DEMO_EP,PORT_PIN_MODE_GPIO);
                #endif
       break;
				        



    }/* End of Case */
  }/* End of While loop */


}/* End of Gtm_Demo function */


	
      
