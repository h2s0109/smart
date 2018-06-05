#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2012)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  FILENAME  : infineon_smu_defs.mak                                         ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2013.09.24                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of SMU module                                   ** 
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
#* RK        Rutuja Kawathekar                                               ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2013.09.24, RK  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/smu_infineon_tricore/ssc/mak/infineon_smu_check.mak 
#***************************** SPECIFIC ****************************************/  
SMU_SSC_OBJECTS = $(SMU_BASE_PATH)/ssc/obj/Smu.$(OBJ_FILE_SUFFIX) 
SMU_SSC_OBJECTS += $(SMU_BASE_PATH)/ssc/obj/Sl_Ipc.$(OBJ_FILE_SUFFIX) 
SMU_PB_CFG_OBJECTS = $(SMU_BASE_PATH)/$(smupath)/obj/Smu_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(SMU_DELIVERY_MODE),VARIANTPB_SOURCE) 
SMU_CLEAN_OBJECTS = $(SMU_SSC_OBJECTS) 
SMU_INCLUDE_PATH += $(CC_INC) "$(SMU_BASE_PATH)/ssc/inc" 
SMU_INCLUDE_PATH += $(CC_INC) "$(SMU_BASE_PATH)/$(smupath)/inc" 
endif 
SMU_DEMO_INCLUDE_PATH += $(CC_INC) "$(SMU_BASE_PATH)/demo/inc" 
 
 
ifeq ($(SMU_DEMO),STD_ON) 
SMU_DEMO_OBJECTS = $(SMU_BASE_PATH)/demo/obj/Smu_Demo.$(OBJ_FILE_SUFFIX) 
else 
SMU_DEMO_OBJECTS = 
endif 
SMU_CLEAN_OBJECTS += $(SMU_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(SMU_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(SMU_DEMO_OBJECTS) 
# Following variables are to be used by the application  
SMU_DEP_HEADERS = $(SMU_BASE_PATH)/ssc/inc/Smu.h $(SMU_BASE_PATH)/$(smupath)/inc/Smu_Cfg.h 
