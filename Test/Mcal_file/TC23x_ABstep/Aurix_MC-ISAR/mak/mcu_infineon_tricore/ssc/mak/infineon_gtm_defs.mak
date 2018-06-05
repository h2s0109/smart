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
#*  FILENAME  : infineon_gtm_defs.mak                                         **
#*                                                                            **
#*  VERSION   : 0.1.1                                                         **
#*                                                                            **
#*  DATE      : 2013.07.23                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the GTM module and associates with appropriate folder.**
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
#*  V0.1.1 : 2013.07.23, KP  : File split changes and changes as per UTP 
#*                                                                  [AI00198181]
#*  v0.1.0 : 2011.04.27  PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_check.mak 

#***************************** SPECIFIC ****************************************/

GTM_SSC_OBJECTS = $(GTM_BASE_PATH)/ssc/obj/Gtm.$(OBJ_FILE_SUFFIX) 
GTM_SSC_OBJECTS += $(GTM_BASE_PATH)/ssc/obj/Gtm_Platform.$(OBJ_FILE_SUFFIX) 
GTM_SSC_OBJECTS += $(GTM_BASE_PATH)/cfg1/obj/Gtm_Lcfg.$(OBJ_FILE_SUFFIX) 

GTM_PB_CFG_OBJECTS = $(GTM_BASE_PATH)/$(gtmpath)/obj/Gtm_PBCfg.$(OBJ_FILE_SUFFIX) 


ifeq ($(GTM_DELIVERY_MODE),VARIANTPB_SOURCE)
GTM_CLEAN_OBJECTS = $(GTM_SSC_OBJECTS) 
GTM_INCLUDE_PATH += $(CC_INC) "$(GTM_BASE_PATH)/ssc/inc" 
GTM_INCLUDE_PATH += $(CC_INC) "$(GTM_BASE_PATH)/$(gtmpath)/inc" 
endif 
GTM_DEMO_INCLUDE_PATH += $(CC_INC) "$(GTM_BASE_PATH)/demo/inc" 




ifeq ($(GTM_DEMO),STD_ON)
GTM_DEMO_OBJECTS = $(GTM_BASE_PATH)/demo/obj/Gtm_Demo.$(OBJ_FILE_SUFFIX)
else 
GTM_DEMO_OBJECTS = 
endif 
GTM_CLEAN_OBJECTS += $(GTM_DEMO_OBJECTS) 

CLEAN_DRIVER_OBJECTS += $(GTM_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(GTM_DEMO_OBJECTS) 
# Following variables are to be used by the application 
GTM_DEP_HEADERS = $(GTM_BASE_PATH)/ssc/inc/Gtm.h $(GTM_BASE_PATH)/ssc/inc/Gtm_Protect.h $(GTM_BASE_PATH)/$(gtmpath)/inc/Gtm_Cfg.h