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
#*  FILENAME  : infineon_wdg_17_scu_defs.mak                                  **
#*                                                                            **
#*  VERSION   : 0.1.0                                                         **
#*                                                                            **
#*  DATE      : 2011.03.22                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the WDG driver files only                         **
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

include $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_check.mak

#***************************** SPECIFIC ****************************************/

WDG_SSC_OBJECTS = $(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu.$(OBJ_FILE_SUFFIX)
ifeq ($(WDG_SAFETY_USED),STD_ON)
WDG_SSC_OBJECTS += $(WDG_BASE_PATH)/ssc/obj/Wdg_17_Scu_Safe.$(OBJ_FILE_SUFFIX)
endif
WDG_PB_CFG_OBJECTS = $(WDG_BASE_PATH)/$(wdgpath)/obj/Wdg_17_Scu_PBCfg.$(OBJ_FILE_SUFFIX) 

ifeq ($(WDG_DELIVERY_MODE),VARIANTPB_SOURCE) 
WDG_CLEAN_OBJECTS = $(WDG_SSC_OBJECTS) 
WDG_INCLUDE_PATH += $(CC_INC) "$(WDG_BASE_PATH)/ssc/inc" 
WDG_INCLUDE_PATH += $(CC_INC) "$(WDG_BASE_PATH)/$(wdgpath)/inc" 
endif 
WDG_DEMO_INCLUDE_PATH += $(CC_INC) "$(WDG_BASE_PATH)/demo/inc" 

ifeq ($(WDG_DEMO),STD_ON) 
WDG_DEMO_OBJECTS = $(WDG_BASE_PATH)/demo/obj/Wdg_17_Scu_Demo.$(OBJ_FILE_SUFFIX) 
else 
WDG_DEMO_OBJECTS = 
endif 
WDG_CLEAN_OBJECTS += $(WDG_DEMO_OBJECTS) 

CLEAN_DRIVER_OBJECTS += $(WDG_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(WDG_DEMO_OBJECTS) 
# Following variables are to be used by the application  
WDG_DEP_HEADERS = $(WDG_BASE_PATH)/ssc/inc/Wdg_17_Scu.h $(WDG_BASE_PATH)/ssc/inc/Wdg_17_Scu_Safe.h $(WDG_BASE_PATH)/$(wdgpath)/inc/Wdg_17_Scu_Cfg.h 
