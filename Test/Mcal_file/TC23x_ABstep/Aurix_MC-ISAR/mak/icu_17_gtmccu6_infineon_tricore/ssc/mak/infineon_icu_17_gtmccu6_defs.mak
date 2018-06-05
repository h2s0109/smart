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
#*  FILENAME  : infineon_icu_17_gtmccu6_defs.mak                              **
#*                                                                            **
#*  VERSION   : 0.1.1                                                         **
#*                                                                            **
#*  DATE      : 2013.02.13                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the ICU driver files only                         **
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
#* SS           Srinivas Shenoy                                              **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.1 : SS: Changes for VendorApiInfix                        **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_check.mak

#***************************** SPECIFIC ****************************************/

ICU_SSC_OBJECTS = $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6.$(OBJ_FILE_SUFFIX) $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Safe.$(OBJ_FILE_SUFFIX) $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Ver.$(OBJ_FILE_SUFFIX)
ICU_PB_CFG_OBJECTS = $(ICU_BASE_PATH)/$(icupath)/obj/Icu_17_GtmCcu6_PBCfg.$(OBJ_FILE_SUFFIX) 

ifeq ($(ICU_DELIVERY_MODE),VARIANTPB_SOURCE)
ICU_CLEAN_OBJECTS = $(ICU_SSC_OBJECTS) 
ICU_INCLUDE_PATH += $(CC_INC) "$(ICU_BASE_PATH)/ssc/inc" 
ICU_INCLUDE_PATH += $(CC_INC) "$(ICU_BASE_PATH)/$(icupath)/inc"
endif
ICU_DEMO_INCLUDE_PATH += $(CC_INC) "$(ICU_BASE_PATH)/demo/inc" 

ifeq ($(ICU_DEMO),STD_ON)
ICU_DEMO_OBJECTS = $(ICU_BASE_PATH)/demo/obj/Icu_17_GtmCcu6_Demo.$(OBJ_FILE_SUFFIX)
else
ICU_DEMO_OBJECTS =
endif
ICU_CLEAN_OBJECTS += $(ICU_DEMO_OBJECTS) 

CLEAN_DRIVER_OBJECTS += $(ICU_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(ICU_DEMO_OBJECTS) 
# Following variables are to be used by the application  
ICU_DEP_HEADERS = $(ICU_BASE_PATH)/ssc/inc/Icu_17_GtmCcu6.h $(ICU_BASE_PATH)/$(icupath)/inc/Icu_17_GtmCcu6_Cfg.h $(ICU_BASE_PATH)/ssc/inc/Icu_17_GtmCcu6_Local.h $(ICU_BASE_PATH)/ssc/inc/Icu_17_GtmCcu6_Safe.h $(ICU_BASE_PATH)/ssc/inc/Icu_17_GtmCcu6_Ver.h
