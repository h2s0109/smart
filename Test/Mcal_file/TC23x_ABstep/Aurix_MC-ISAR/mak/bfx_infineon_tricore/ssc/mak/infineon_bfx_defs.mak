#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2012)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_bfx_defs.mak 	                                      **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.10.26                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the BFX Library files only			              **
#*                 							                                  **
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
#* YP          Yadunandan Puttaswamy                                         **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.0.1 : YP: Intial Version                                    **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/bfx_infineon_tricore/ssc/mak/infineon_bfx_check.mak

#***************************** SPECIFIC ****************************************/

BFX_SSC_OBJECTS = $(BFX_BASE_PATH)/ssc/obj/Bfx.$(OBJ_FILE_SUFFIX) 




BFX_INCLUDE_PATH = $(CC_INC) "$(BFX_BASE_PATH)/ssc/inc"




ifeq ($(BFX_DEMO),STD_ON)
BFX_DEMO_OBJECTS = $(BFX_BASE_PATH)/demo/obj/Bfx_Demo.$(OBJ_FILE_SUFFIX)
BFX_DEMO_INCLUDE_PATH = $(CC_INC) "$(BFX_BASE_PATH)/demo/inc"
else
BFX_DEMO_OBJECTS =
BFX_DEMO_INCLUDE_PATH = 
endif
BFX_CLEAN_OBJECTS += $(BFX_DEMO_OBJECTS)

CLEAN_DRIVER_OBJECTS += $(BFX_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(BFX_DEMO_OBJECTS)

# Following variables are to be used by the application 

BFX_DEP_HEADERS = $(BFX_BASE_PATH)/ssc/inc/Bfx.h 
