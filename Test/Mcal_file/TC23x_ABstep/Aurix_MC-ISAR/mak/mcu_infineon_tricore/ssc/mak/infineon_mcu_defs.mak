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
#*  FILENAME  : infineon_mcu_defs.mak 	                                      **
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
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the MCU module and associates with appropriate folder. **
#*                 						                                                **
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

include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_check.mak

#***************************** SPECIFIC ****************************************/

MCU_SSC_OBJECTS = $(MCU_BASE_PATH)/ssc/obj/Mcu.$(OBJ_FILE_SUFFIX)
MCU_SSC_OBJECTS += $(MCU_BASE_PATH)/ssc/obj/Mcu_Ver.$(OBJ_FILE_SUFFIX)
MCU_SSC_OBJECTS += $(MCU_BASE_PATH)/ssc/obj/Mcu_Platform.$(OBJ_FILE_SUFFIX)

ifeq ($(MCU_CRC_USED),ON)
MCU_SSC_OBJECTS += $(MCU_BASE_PATH)/ssc/obj/Mcu_Crc.$(OBJ_FILE_SUFFIX)
endif
ifeq ($(MCU_DMA_USED),ON)
MCU_SSC_OBJECTS += $(MCU_BASE_PATH)/ssc/obj/Mcu_Dma.$(OBJ_FILE_SUFFIX)
endif

MCU_PB_CFG_OBJECTS = $(MCU_BASE_PATH)/$(mcupath)/obj/Mcu_PBCfg.$(OBJ_FILE_SUFFIX) 

ifeq ($(MCU_DELIVERY_MODE),VARIANTPB_SOURCE) 

MCU_CLEAN_OBJECTS = $(MCU_SSC_OBJECTS) 

MCU_INCLUDE_PATH += $(CC_INC) "$(MCU_BASE_PATH)/ssc/inc" 

MCU_INCLUDE_PATH += $(CC_INC) "$(MCU_BASE_PATH)/$(mcupath)/inc" 
endif 
MCU_DEMO_INCLUDE_PATH += $(CC_INC) "$(MCU_BASE_PATH)/demo/inc" 


ifeq ($(MCU_DEMO),STD_ON)
MCU_DEMO_OBJECTS = $(MCU_BASE_PATH)/demo/obj/Mcu_Demo.$(OBJ_FILE_SUFFIX)
else
MCU_DEMO_OBJECTS =
endif
MCU_CLEAN_OBJECTS += $(MCU_DEMO_OBJECTS)


CLEAN_DRIVER_OBJECTS += $(MCU_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(MCU_DEMO_OBJECTS) 
# Following variables are to be used by the application 

MCU_DEP_HEADERS = $(MCU_BASE_PATH)/ssc/inc/Mcu.h $(MCU_BASE_PATH)/$(mcupath)/inc/Mcu_Cfg.h 
