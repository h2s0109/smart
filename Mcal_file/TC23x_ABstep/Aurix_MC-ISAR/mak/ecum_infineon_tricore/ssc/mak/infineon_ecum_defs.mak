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
#*  FILENAME  : infineon_ecum_defs.mak                                         **
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
#*                 to build the ECUM driver files only                        **
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

include $(SSC_ROOT)/mak/base_make.mak
#***************************** SPECIFIC ****************************************/

ECUM_SSC_OBJECTS = $(ECUM_BASE_PATH)/ssc/obj/EcuM.$(OBJ_FILE_SUFFIX)

ECUM_CALLOUTSTUBS_OBJECTS = $(ECUM_BASE_PATH)/ssc/obj/EcuM_Callout_Stubs.$(OBJ_FILE_SUFFIX)

ECUM_CFG_OBJECTS = $(ECUM_BASE_PATH)/cfg1/obj/EcuM_LCfg.$(OBJ_FILE_SUFFIX) 

ECUM_PB_CFG_OBJECTS = $(ECUM_BASE_PATH)/cfg1/obj/EcuM_PBCfg.$(OBJ_FILE_SUFFIX)

ECUM_OBJECTS = $(ECUM_SSC_OBJECTS) $(ECUM_CALLOUTSTUBS_OBJECTS) $(ECUM_CFG_OBJECTS)

ECUM_CLEAN_OBJECTS = $(ECUM_PB_CFG_OBJECTS) $(ECUM_CFG_OBJECTS) $(ECUM_SSC_OBJECTS) $(ECUM_CALLOUTSTUBS_OBJECTS)

ECUM_INCLUDE_PATH = $(CC_INC) "$(ECUM_BASE_PATH)/ssc/inc"

ECUM_INCLUDE_PATH += $(CC_INC) "$(ECUM_BASE_PATH)/cfg1/inc"


CLEAN_DRIVER_OBJECTS += $(ECUM_SSC_OBJECTS) $(ECUM_CFG_OBJECTS) $(ECUM_CALLOUTSTUBS_OBJECTS)

# Following variables are to be used by the application 

ECUM_DEP_HEADERS = $(ECUM_BASE_PATH)/ssc/inc/EcuM.h $(ECUM_BASE_PATH)/cfg1/inc/EcuM_Cfg.h  