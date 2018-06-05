#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2011)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  FILENAME  : infineon_lin_17_AscLin_defs.mak                               **
#*                                                                            ** 
#*  VERSION   : 0.0.2                                                         **
#*                                                                            ** 
#*  DATE      : 2013.02.21                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file builds the LIN Driver                       **
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
#* PR           Pawan Reddy                                                  **
#* KP           Kaushal Purohit                                              **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.0.2 : KP: VendorApiInfix support added                      **
#*  VERSION   : 0.0.1 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/
  
#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_check.mak 

#***************************** SPECIFIC ****************************************/  
LIN_SSC_OBJECTS = $(LIN_BASE_PATH)/ssc/obj/Lin_17_AscLin.$(OBJ_FILE_SUFFIX) 
LIN_PB_CFG_OBJECTS = $(LIN_BASE_PATH)/$(linpath)/obj/Lin_17_AscLin_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(LIN_DELIVERY_MODE),VARIANTPB_SOURCE) 
LIN_CLEAN_OBJECTS = $(LIN_SSC_OBJECTS) 
LIN_INCLUDE_PATH += $(CC_INC) "$(LIN_BASE_PATH)/ssc/inc" 
LIN_INCLUDE_PATH += $(CC_INC) "$(LIN_BASE_PATH)/$(linpath)/inc" 
endif 
LIN_DEMO_INCLUDE_PATH += $(CC_INC) "$(LIN_BASE_PATH)/demo/inc" 
 
 
ifeq ($(LIN_DEMO),STD_ON) 
LIN_DEMO_OBJECTS = $(LIN_BASE_PATH)/demo/obj/Lin_17_AscLin_Demo.$(OBJ_FILE_SUFFIX) 
else 
LIN_DEMO_OBJECTS = 
endif 
LIN_CLEAN_OBJECTS += $(LIN_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(LIN_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(LIN_DEMO_OBJECTS) 
# Following variables are to be used by the application  
LIN_DEP_HEADERS = $(LIN_BASE_PATH)/ssc/inc/Lin_17_AscLin.h $(LIN_BASE_PATH)/$(linpath)/inc/Lin_17_AscLin_Cfg.h
