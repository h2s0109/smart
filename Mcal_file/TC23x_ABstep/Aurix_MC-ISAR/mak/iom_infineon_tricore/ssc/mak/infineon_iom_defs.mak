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
#*  FILENAME  : infineon_iom_defs.mak                                         ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.10.19                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of IOM module                                   ** 
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
#* HM        Hamzath Mohammed                                                ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.10.19, HM  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/iom_infineon_tricore/ssc/mak/infineon_iom_check.mak 
#***************************** SPECIFIC ****************************************/  
IOM_SSC_OBJECTS = $(IOM_BASE_PATH)/ssc/obj/Iom.$(OBJ_FILE_SUFFIX) 
IOM_PB_CFG_OBJECTS = $(IOM_BASE_PATH)/$(iompath)/obj/Iom_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(IOM_DELIVERY_MODE),VARIANTPB_SOURCE) 
IOM_CLEAN_OBJECTS = $(IOM_SSC_OBJECTS) 
IOM_INCLUDE_PATH += $(CC_INC) "$(IOM_BASE_PATH)/ssc/inc" 
IOM_INCLUDE_PATH += $(CC_INC) "$(IOM_BASE_PATH)/$(iompath)/inc" 
endif 
IOM_DEMO_INCLUDE_PATH += $(CC_INC) "$(IOM_BASE_PATH)/demo/inc" 
 
 
ifeq ($(IOM_DEMO),STD_ON) 
IOM_DEMO_OBJECTS = $(IOM_BASE_PATH)/demo/obj/Iom_Demo.$(OBJ_FILE_SUFFIX) 
else 
IOM_DEMO_OBJECTS = 
endif 
IOM_CLEAN_OBJECTS += $(IOM_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(IOM_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(IOM_DEMO_OBJECTS) 
# Following variables are to be used by the application  
IOM_DEP_HEADERS = $(IOM_BASE_PATH)/ssc/inc/Iom.h $(IOM_BASE_PATH)/$(iompath)/inc/Iom_Cfg.h 
