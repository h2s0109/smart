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
#*  FILENAME  : infineon_gpt_defs.mak 					                              **
#*                                                                            **
#*  VERSION   : 0.1.0                                                         **
#*                                                                            **
#*  DATE      : 2011.03.22                                                    **
#*                                        
#*                                                                            **                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the GPT driver files only			                    **
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

include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_check.mak 

#***************************** SPECIFIC ****************************************/  
GPT_SSC_OBJECTS = $(GPT_BASE_PATH)/ssc/obj/Gpt.$(OBJ_FILE_SUFFIX) 
GPT_SSC_OBJECTS += $(GPT_BASE_PATH)/ssc/obj/Gpt_Ver.$(OBJ_FILE_SUFFIX)
GPT_PB_CFG_OBJECTS = $(GPT_BASE_PATH)/$(gptpath)/obj/Gpt_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(GPT_DELIVERY_MODE),VARIANTPB_SOURCE) 
GPT_CLEAN_OBJECTS = $(GPT_SSC_OBJECTS) 
GPT_INCLUDE_PATH += $(CC_INC) "$(GPT_BASE_PATH)/ssc/inc" 
GPT_INCLUDE_PATH += $(CC_INC) "$(GPT_BASE_PATH)/$(gptpath)/inc" 
endif 
GPT_DEMO_INCLUDE_PATH += $(CC_INC) "$(GPT_BASE_PATH)/demo/inc" 
 
 
ifeq ($(GPT_DEMO),STD_ON) 
GPT_DEMO_OBJECTS = $(GPT_BASE_PATH)/demo/obj/Gpt_Demo.$(OBJ_FILE_SUFFIX) 
else 
GPT_DEMO_OBJECTS = 
endif 
GPT_CLEAN_OBJECTS += $(GPT_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(GPT_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(GPT_DEMO_OBJECTS) 
# Following variables are to be used by the application  
GPT_DEP_HEADERS = $(GPT_BASE_PATH)/ssc/inc/Gpt.h $(GPT_BASE_PATH)/$(gptpath)/inc/Gpt_Cfg.h 