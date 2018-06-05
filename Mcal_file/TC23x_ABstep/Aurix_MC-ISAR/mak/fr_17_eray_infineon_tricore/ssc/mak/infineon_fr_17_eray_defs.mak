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
#*  FILENAME  : infineon_fr_17_eray_defs.mak                                  ** 
#*                                                                            ** 
#*  VERSION   : 0.1.1                                                         **
#*                                                                            ** 
#*  DATE      : 2013.02.22                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions of FR module   ** 
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
#* PR           Pawan Reddy                                                  **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.1 : Vani: Updated for AI00143782                          **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/ssc/mak/infineon_fr_17_eray_check.mak 

#***************************** SPECIFIC ****************************************/  
FR_SSC_OBJECTS = $(FR_BASE_PATH)/ssc/obj/Fr_17_Eray.$(OBJ_FILE_SUFFIX) 
FR_LT_CFG_OBJECTS = 
FR_PB_CFG_OBJECTS = $(FR_BASE_PATH)/$(frpath)/obj/Fr_17_Eray_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(FR_DELIVERY_MODE),VARIANTPB_SOURCE) 
FR_CLEAN_OBJECTS = $(FR_SSC_OBJECTS) 
FR_INCLUDE_PATH += $(CC_INC) "$(FR_BASE_PATH)/ssc/inc" 
FR_INCLUDE_PATH += $(CC_INC) "$(FR_BASE_PATH)/$(frpath)/inc" 
endif 
FR_DEMO_INCLUDE_PATH += $(CC_INC) "$(FR_BASE_PATH)/demo/inc" 
 
 
ifeq ($(FR_DEMO),STD_ON) 
FR_DEMO_OBJECTS = $(FR_BASE_PATH)/demo/obj/Fr_17_Eray_Demo.$(OBJ_FILE_SUFFIX) 
else 
FR_DEMO_OBJECTS = 
endif 
FR_CLEAN_OBJECTS += $(FR_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(FR_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(FR_DEMO_OBJECTS) 
# Following variables are to be used by the application  
FR_DEP_HEADERS = $(FR_BASE_PATH)/ssc/inc/Fr_17_Eray.h $(FR_BASE_PATH)/$(frpath)/inc/Fr_17_Eray_Cfg.h $(SSC_ROOT)/integration_general/inc/Fr_GeneralTypes.h $(SSC_ROOT)/general/inc/ComStack_Types.h
