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
#*  FILENAME  : infineon_fls_17_pmu_defs.mak                                  **
#*                                                                            **
#*  VERSION   : 0.1.2                                                         **
#*                                                                            **
#*  DATE      : 2013.02.22                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the FLS driver files only                         **
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
#* SGN          Gururaj Nath S                                               **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.2 : SGN : Updated for file splitting                      **
#*  VERSION   : 0.1.1 : Vani: Updated with Vendor APIInfix chnages            **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_check.mak

#***************************** SPECIFIC ****************************************/


FLS_AC_OBJECTS = $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_ac.$(OBJ_FILE_SUFFIX) 

FLS_SSC_OBJECTS = $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu.$(OBJ_FILE_SUFFIX) 
FLS_SSC_OBJECTS += $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_Ver.$(OBJ_FILE_SUFFIX) 

FLS_SSC_OBJECTS += $(FLS_AC_OBJECTS)
FLS_INCLUDE_PATH = $(CC_INC) "$(FLS_BASE_PATH)/ssc/inc"

ifeq ($(FLS_DELIVERY_MODE),VARIANTPB_SOURCE)
FLS_PB_CFG_OBJECTS = $(FLS_BASE_PATH)/$(flspath)/obj/Fls_17_Pmu_PBCfg.$(OBJ_FILE_SUFFIX)
FLS_INCLUDE_PATH += $(CC_INC) "$(FLS_BASE_PATH)/$(flspath)/inc"
endif

ifeq ($(FLS_DEMO),STD_ON)
FLS_DEMO_OBJECTS = $(FLS_BASE_PATH)/demo/obj/Fls_17_Pmu_Demo.$(OBJ_FILE_SUFFIX)
FLS_DEMO_INCLUDE_PATH = $(CC_INC) "$(FLS_BASE_PATH)/demo/inc"
else
FLS_DEMO_OBJECTS =
FLS_DEMO_INCLUDE_PATH = 
endif

FLS_OBJECTS = $(FLS_SSC_OBJECTS) $(FLS_DEMO_OBJECTS)
FLS_CLEAN_OBJECTS = $(FLS_OBJECTS)

CLEAN_DRIVER_OBJECTS += $(FLS_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(FLS_DEMO_OBJECTS) 

# Following variables are to be used by the application 
FLS_DEP_HEADERS = $(FLS_BASE_PATH)/ssc/inc/Fls_17_Pmu.h $(FLS_BASE_PATH)/ssc/inc/Fls_17_Pmu_Local.h $(FLS_BASE_PATH)/ssc/inc/Fls_17_Pmu_ac.h $(FLS_BASE_PATH)/$(flspath)/inc/Fls_17_Pmu_Cfg.h

ifeq ($(FLS_EMULATION),ON)
FLS_INCLUDE_PATH += $(CC_INC) "$(TEST_ROOT)/fee_test/inc"
FLS_DEP_HEADERS  += $(TEST_ROOT)/fee_test/inc/FlsEmulation.h
endif
