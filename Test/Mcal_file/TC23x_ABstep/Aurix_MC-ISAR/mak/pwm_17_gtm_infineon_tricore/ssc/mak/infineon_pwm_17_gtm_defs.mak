#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2013)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_pwm_defs.mak                                         **
#*                                                                            **
#*  VERSION   : 0.1.0                                                         **
#*                                                                            **
#*  DATE      : 2011.03.22                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the PWM driver files only                         **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* PR           Pawan Reddy                                                  **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_check.mak 

#***************************** SPECIFIC ****************************************/  

PWM_SSC_OBJECTS = $(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm.$(OBJ_FILE_SUFFIX) $(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm_Ver.$(OBJ_FILE_SUFFIX)

PWM_PB_CFG_OBJECTS = $(PWM_BASE_PATH)/$(pwmpath)/obj/Pwm_17_Gtm_PBCfg.$(OBJ_FILE_SUFFIX) 

 
ifeq ($(PWM_DELIVERY_MODE),VARIANTPB_SOURCE) 
PWM_CLEAN_OBJECTS = $(PWM_SSC_OBJECTS) 
PWM_INCLUDE_PATH += $(CC_INC) "$(PWM_BASE_PATH)/ssc/inc" 
PWM_INCLUDE_PATH += $(CC_INC) "$(PWM_BASE_PATH)/$(pwmpath)/inc" 
endif 
PWM_DEMO_INCLUDE_PATH += $(CC_INC) "$(PWM_BASE_PATH)/demo/inc" 
 

ifeq ($(PWM_DEMO),STD_ON)
PWM_DEMO_OBJECTS = $(PWM_BASE_PATH)/demo/obj/Pwm_17_Gtm_Demo.$(OBJ_FILE_SUFFIX)
else
PWM_DEMO_OBJECTS =
endif
PWM_CLEAN_OBJECTS += $(PWM_DEMO_OBJECTS)


CLEAN_DRIVER_OBJECTS += $(PWM_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(PWM_DEMO_OBJECTS) 
# Following variables are to be used by the application  
PWM_DEP_HEADERS = $(PWM_BASE_PATH)/ssc/inc/Pwm_17_Gtm.h $(PWM_BASE_PATH)/ssc/inc/Pwm_17_Gtm_Ver.h $(PWM_BASE_PATH)/ssc/inc/Pwm_Protect.h $(PWM_BASE_PATH)/$(pwmpath)/inc/Pwm_17_Gtm_Cfg.h 