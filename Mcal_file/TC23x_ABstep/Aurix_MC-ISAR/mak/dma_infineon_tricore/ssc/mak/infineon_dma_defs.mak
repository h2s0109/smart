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
#*  FILENAME  : infineon_dma_defs.mak                                         ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         **
#*                                                                            ** 
#*  DATE      : 2013.03.11                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of DMA module                                   ** 
#*                                                                            ** 
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
#* AC           Apurav Chandel                                               **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*                                                                            **
#*  V0.0.1: 2013.03.11, AC: Intial Version 				                            **
#*  V0.0.2: 2013.09.30. AC: updated for Dma_Callout_Stubs.c file              **
#*  V0.0.3: 2013.10.03. AC: Removed Dma_Callout_Stubs.c file                  **
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_check.mak 
#***************************** SPECIFIC ****************************************/  
DMA_SSC_OBJECTS = $(DMA_BASE_PATH)/ssc/obj/Dma.$(OBJ_FILE_SUFFIX) 
DMA_PB_CFG_OBJECTS = $(DMA_BASE_PATH)/$(dmapath)/obj/Dma_PBCfg.$(OBJ_FILE_SUFFIX)
 
ifeq ($(DMA_DELIVERY_MODE),VARIANTPB_SOURCE) 
DMA_CLEAN_OBJECTS = $(DMA_SSC_OBJECTS) 
DMA_INCLUDE_PATH += $(CC_INC) "$(DMA_BASE_PATH)/ssc/inc" 
DMA_INCLUDE_PATH += $(CC_INC) "$(DMA_BASE_PATH)/$(dmapath)/inc" 
endif 
DMA_DEMO_INCLUDE_PATH += $(CC_INC) "$(DMA_BASE_PATH)/demo/inc" 
 
 
ifeq ($(DMA_DEMO),STD_ON) 
DMA_DEMO_OBJECTS = $(DMA_BASE_PATH)/demo/obj/Dma_Demo.$(OBJ_FILE_SUFFIX) 
else 
DMA_DEMO_OBJECTS = 
endif 
DMA_CLEAN_OBJECTS += $(DMA_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(DMA_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(DMA_DEMO_OBJECTS) 
# Following variables are to be used by the application  
DMA_DEP_HEADERS = $(DMA_BASE_PATH)/ssc/inc/Dma.h $(DMA_BASE_PATH)/ssc/inc/Dma_Protect.h $(DMA_BASE_PATH)/$(dmapath)/inc/Dma_Cfg.h 
