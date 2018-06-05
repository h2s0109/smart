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
#*  FILENAME  : infineon_dio_defs.mak 	                                      **
#*                                                                            **
#*  VERSION   : 0.1.0                                                         **
#*                                                                            **
#*  DATE      : 2012.05.22                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the DIO driver files only			                    **
#*                 							                                              **
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
#* MDM          Mohammed Mustaq                                              **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.0.1 : MDM: Intial Version for Aurix AS321                   **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_check.mak

#***************************** SPECIFIC ****************************************/

DIO_SSC_OBJECTS = $(DIO_BASE_PATH)/ssc/obj/Dio.$(OBJ_FILE_SUFFIX)
DIO_SSC_OBJECTS += $(DIO_BASE_PATH)/ssc/obj/Dio_Ver.$(OBJ_FILE_SUFFIX)

DIO_PB_CFG_OBJECTS = $(DIO_BASE_PATH)/$(diopath)/obj/Dio_PBCfg.$(OBJ_FILE_SUFFIX)

DIO_LT_CFG_OBJECTS = $(DIO_BASE_PATH)/$(diopath)/obj/Dio_Lcfg.$(OBJ_FILE_SUFFIX)


ifeq ($(DIO_DELIVERY_MODE),VARIANTPB_SOURCE)
DIO_OBJECTS = $(DIO_SSC_OBJECTS) $(DIO_PB_CFG_OBJECTS)
DIO_CLEAN_OBJECTS = $(DIO_PB_CFG_OBJECTS) $(DIO_SSC_OBJECTS)

endif

ifeq ($(DIO_DELIVERY_MODE),VARIANTLT_SOURCE)
DIO_OBJECTS = $(DIO_SSC_OBJECTS) $(DIO_LT_CFG_OBJECTS)
DIO_CLEAN_OBJECTS = $(DIO_LT_CFG_OBJECTS) $(DIO_SSC_OBJECTS)

endif

DIO_INCLUDE_PATH  = $(CC_INC) "$(DIO_BASE_PATH)/$(diopath)/inc"

DIO_INCLUDE_PATH += $(CC_INC) "$(DIO_BASE_PATH)/ssc/inc"




ifeq ($(DIO_DEMO),STD_ON)
DIO_DEMO_OBJECTS = $(DIO_BASE_PATH)/demo/obj/Dio_Demo.$(OBJ_FILE_SUFFIX)
DIO_DEMO_INCLUDE_PATH = $(CC_INC) "$(DIO_BASE_PATH)/demo/inc"
else
DIO_DEMO_OBJECTS =
DIO_DEMO_INCLUDE_PATH =
endif
DIO_CLEAN_OBJECTS += $(DIO_DEMO_OBJECTS)

CLEAN_DRIVER_OBJECTS += $(DIO_SSC_OBJECTS)
CLEAN_DEMO_OBJECTS += $(DIO_DEMO_OBJECTS)

CLEAN_LT_CFG_OBJECTS += $(DIO_LT_CFG_OBJECTS)

# Following variables are to be used by the application

DIO_DEP_HEADERS = $(DIO_BASE_PATH)/ssc/inc/Dio.h $(DIO_BASE_PATH)/$(diopath)/inc/Dio_Cfg.h $(DIO_BASE_PATH)/ssc/inc/Dio_Ver.h
