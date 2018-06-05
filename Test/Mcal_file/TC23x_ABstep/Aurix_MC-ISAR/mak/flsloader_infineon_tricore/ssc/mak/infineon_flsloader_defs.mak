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
#*  FILENAME  : infineon_flsloader_defs.mak                                   **
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
#*                 to build the FLSLOADER driver files only                   **
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

include $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_check.mak

#***************************** SPECIFIC ****************************************/

FLSLOADER_SSC_OBJECTS = $(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader.$(OBJ_FILE_SUFFIX) 
FLSLOADER_SSC_OBJECTS += $(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader_Platform.$(OBJ_FILE_SUFFIX) 


FLSLOADER_OBJECTS = $(FLSLOADER_SSC_OBJECTS)   

ifeq ($(FLSLOADER_DELIVERY_MODE),VARIANTPC_SOURCE)
FLSLOADER_CLEAN_OBJECTS = $(FLSLOADER_SSC_OBJECTS)
FLSLOADER_INCLUDE_PATH = $(CC_INC) "$(FLSLOADER_BASE_PATH)/ssc/inc"
FLSLOADER_INCLUDE_PATH += $(CC_INC) "$(FLSLOADER_BASE_PATH)/$(flsloaderpath)/inc"
endif

FLSLOADER_DEMO_INCLUDE_PATH += $(CC_INC) "$(FLSLOADER_BASE_PATH)/demo/inc"

ifeq ($(FLSLOADER_DEMO),STD_ON)
FLSLOADER_DEMO_OBJECTS += $(FLSLOADER_BASE_PATH)/demo/obj/FlsLoader_Demo.$(OBJ_FILE_SUFFIX)
else
FLSLOADER_DEMO_OBJECTS =
endif

FLSLOADER_CLEAN_OBJECTS += $(FLSLOADER_DEMO_OBJECTS)

CLEAN_DRIVER_OBJECTS += $(FLSLOADER_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(FLSLOADER_DEMO_OBJECTS) 

# Following variables are to be used by the application 
FLSLOADER_DEP_HEADERS = $(FLSLOADER_BASE_PATH)/$(flsloaderpath)/inc/FlsLoader_Cfg.h $(FLSLOADER_BASE_PATH)/ssc/inc/FlsLoader.h $(FLSLOADER_BASE_PATH)/ssc/inc/FlsLoader_Local.h  