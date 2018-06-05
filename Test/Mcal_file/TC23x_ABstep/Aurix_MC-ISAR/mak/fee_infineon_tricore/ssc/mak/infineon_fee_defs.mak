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
#*  FILENAME  : infineon_fee_defs.mak                                         **
#*                                                                            **
#*  VERSION   : 0.1.3                                                         **
#*                                                                            **
#*  DATE      : 2013.08.07                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the FEE driver files only                         **
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
#*  VERSION   : 0.1.3 :SGN: Updated for file splitting                        **
#*  VERSION   : 0.1.2 :SGN: Added _Pmu to FLS files                           **
#*  VERSION   : 0.1.1 :SGN: Added _17 to FLS files                            **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/fee_infineon_tricore/ssc/mak/infineon_fee_check.mak
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_check.mak

#***************************** SPECIFIC ****************************************/

FEE_SSC_OBJECTS = $(FEE_BASE_PATH)/ssc/obj/Fee.$(OBJ_FILE_SUFFIX)
FEE_SSC_OBJECTS += $(FEE_BASE_PATH)/ssc/obj/Fee_Ver.$(OBJ_FILE_SUFFIX)
FEE_INCLUDE_PATH = $(CC_INC) "$(FEE_BASE_PATH)/ssc/inc"

ifeq ($(FEE_DELIVERY_MODE),VARIANTPC_SOURCE)
FEE_CFG_OBJECTS = $(FEE_BASE_PATH)/$(feepath)/obj/Fee_Cfg.$(OBJ_FILE_SUFFIX)
FEE_INCLUDE_PATH += $(CC_INC) "$(FEE_BASE_PATH)/$(feepath)/inc"
endif

FEE_INCLUDE_PATH += $(CC_INC) "$(MCU_BASE_PATH)/ssc/inc"
FEE_INCLUDE_PATH += $(CC_INC) "$(FLS_BASE_PATH)/ssc/inc"
FEE_INCLUDE_PATH += $(CC_INC) "$(FLS_BASE_PATH)/$(flspath)/inc"

FEE_DEMO_INCLUDE_PATH += $(CC_INC) "$(FEE_BASE_PATH)/demo/inc"

ifeq ($(FEE_DEMO),STD_ON)
FEE_DEMO_OBJECTS = $(FEE_BASE_PATH)/demo/obj/Fee_Demo.$(OBJ_FILE_SUFFIX)
else
FEE_DEMO_OBJECTS =
endif

FEE_OBJECTS = $(FEE_SSC_OBJECTS) $(FEE_CFG_OBJECTS) $(FEE_DEMO_OBJECTS)

FEE_CLEAN_OBJECTS = $(FEE_OBJECTS)

CLEAN_DRIVER_OBJECTS += $(FEE_SSC_OBJECTS) $(FEE_CFG_OBJECTS)
CLEAN_DEMO_OBJECTS += $(FEE_DEMO_OBJECTS) 

# Following variables are to be used by the application 
FEE_DEP_HEADERS = $(FEE_BASE_PATH)/ssc/inc/Fee.h $(FEE_BASE_PATH)/ssc/inc/Fee_Cbk.h $(FEE_BASE_PATH)/$(feepath)/inc/Fee_Cfg.h $(FLS_BASE_PATH)/ssc/inc/Fls_17_Pmu.h $(FLS_BASE_PATH)/$(flspath)/inc/Fls_17_Pmu_Cfg.h
