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
#*  FILENAME  : infineon_adc_defs.mak                                         ** 
#*                                                                            ** 
#*  VERSION   : 0.1.2                                                         **
#*                                                                            ** 
#*  DATE      : 2014.01.22                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of ADC module                                   ** 
#*                                                                            ** 
#*                                                                            ** 
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      ** 
#*                                                                            ** 
#******************************************************************************/ 

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* AT           Angeswaran Thangaswamy                                       **
#* PR           Pawan Reddy                                                  **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.2 : 2014-01-22, AT: Added Adc_HwHandle.c and Adc_Calibration.c       **
#*                                           for compilation                  **
#*  V0.1.1 : 2013-07-31, AT: Added new files for compilation                  **
#*  V0.1.0 : 2011-03-22, PR: Intial Version for Aurix                         **
#*
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_check.mak 

#***************************** SPECIFIC ****************************************/  
ADC_SSC_OBJECTS = $(ADC_BASE_PATH)/ssc/obj/Adc.$(OBJ_FILE_SUFFIX) 
ADC_SSC_OBJECTS += $(ADC_BASE_PATH)/ssc/obj/Adc_ConvHandle.$(OBJ_FILE_SUFFIX) 
ADC_SSC_OBJECTS += $(ADC_BASE_PATH)/ssc/obj/Adc_HwHandle.$(OBJ_FILE_SUFFIX) 
ADC_SSC_OBJECTS += $(ADC_BASE_PATH)/ssc/obj/Adc_Ver.$(OBJ_FILE_SUFFIX) 
ADC_SSC_OBJECTS += $(ADC_BASE_PATH)/ssc/obj/Adc_Calibration.$(OBJ_FILE_SUFFIX) 

ADC_PB_CFG_OBJECTS = $(ADC_BASE_PATH)/$(adcpath)/obj/Adc_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(ADC_DELIVERY_MODE),VARIANTPB_SOURCE) 
ADC_CLEAN_OBJECTS = $(ADC_SSC_OBJECTS) $(ADC_PB_CFG_OBJECTS) 
ADC_INCLUDE_PATH += $(CC_INC) "$(ADC_BASE_PATH)/ssc/inc" 
ADC_INCLUDE_PATH += $(CC_INC) "$(ADC_BASE_PATH)/$(adcpath)/inc" 
endif 
ADC_DEMO_INCLUDE_PATH += $(CC_INC) "$(ADC_BASE_PATH)/demo/inc" 
 
 
ifeq ($(ADC_DEMO),STD_ON) 
ADC_DEMO_OBJECTS = $(ADC_BASE_PATH)/demo/obj/Adc_Demo.$(OBJ_FILE_SUFFIX) 
else 
ADC_DEMO_OBJECTS = 
endif 
ADC_CLEAN_OBJECTS += $(ADC_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(ADC_SSC_OBJECTS)
CLEAN_LT_CFG_OBJECTS += $(ADC_LT_CFG_OBJECTS)
CLEAN_DEMO_OBJECTS += $(ADC_DEMO_OBJECTS) 
# Following variables are to be used by the application  
ADC_DEP_HEADERS = $(ADC_BASE_PATH)/ssc/inc/Adc.h $(ADC_BASE_PATH)/ssc/inc/Adc_Utility.h $(ADC_BASE_PATH)/ssc/inc/Adc_ConvHandle.h $(ADC_BASE_PATH)/ssc/inc/Adc_HwHandle.h $(ADC_BASE_PATH)/$(adcpath)/inc/Adc_Cfg.h 
