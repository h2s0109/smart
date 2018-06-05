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
#*  FILENAME  : infineon_can_17_mcanp_rules.mak                               **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2013.06.03                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file contains the variable definitions                **
#*                 of CAN driver                                              **
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
#* SGN          Gururaj Nath S                                               ** 
#*                                                                           ** 
#*                                                                           ** 
#*****************************************************************************/ 
#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*
#*  V0.0.3 : 2013.06.03, SGN : Updated for DFT
#*  V0.0.2 : 2013.02.25, SGN : Updated for AI00133871
#*  V0.0.1 : 2012.05.10, SGN : Initial version, baselined from Audo
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_check.mak 

#***************************** SPECIFIC ****************************************/  
CAN_SSC_OBJECTS = $(CAN_BASE_PATH)/ssc/obj/Can_17_MCanP.$(OBJ_FILE_SUFFIX)
CAN_SSC_OBJECTS += $(CAN_BASE_PATH)/ssc/obj/Can_17_MCanP_Platform.$(OBJ_FILE_SUFFIX) 
CAN_LT_CFG_OBJECTS = 
CAN_PB_CFG_OBJECTS = $(CAN_BASE_PATH)/$(canpath)/obj/Can_17_MCanP_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(CAN_DELIVERY_MODE),VARIANTPB_SOURCE) 
CAN_CLEAN_OBJECTS = $(CAN_SSC_OBJECTS) 
CAN_INCLUDE_PATH += $(CC_INC) "$(CAN_BASE_PATH)/ssc/inc" 
CAN_INCLUDE_PATH += $(CC_INC) "$(CAN_BASE_PATH)/$(canpath)/inc" 
endif 
CAN_DEMO_INCLUDE_PATH += $(CC_INC) "$(CAN_BASE_PATH)/demo/inc" 
 
 
ifeq ($(CAN_DEMO),STD_ON) 
CAN_DEMO_OBJECTS = $(CAN_BASE_PATH)/demo/obj/Can_17_MCanP_Demo.$(OBJ_FILE_SUFFIX) 
else 
CAN_DEMO_OBJECTS = 
endif 
CAN_CLEAN_OBJECTS += $(CAN_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(CAN_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(CAN_DEMO_OBJECTS) 
# Following variables are to be used by the application  
CAN_DEP_HEADERS = $(CAN_BASE_PATH)/ssc/inc/Can_17_MCanP.h $(CAN_BASE_PATH)/$(canpath)/inc/Can_17_MCanP_Cfg.h $(SSC_ROOT)/general/inc/ComStack_Types.h 

ifdef $(IFX_CAN_DEBUG02)
CAN_INCLUDE_PATH += $(CC_INC) "$(TEST_ROOT)/can/inc"
CAN_DEP_HEADERS  += $(TEST_ROOT)/can/inc/Test_CanDebug.h
endif
