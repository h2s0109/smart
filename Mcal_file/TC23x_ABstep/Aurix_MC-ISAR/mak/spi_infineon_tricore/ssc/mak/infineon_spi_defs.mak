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
#*  FILENAME  : infineon_spi_defs.mak                                         **
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
#*                 to build the SPI driver files only                         **
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
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_check.mak 
#***************************** SPECIFIC ****************************************/  

SPI_SSC_OBJECTS = $(SPI_BASE_PATH)/ssc/obj/Spi.$(OBJ_FILE_SUFFIX) 
SPI_SSC_OBJECTS += $(SPI_BASE_PATH)/ssc/obj/Spi_Ver.$(OBJ_FILE_SUFFIX)
SPI_SSC_OBJECTS += $(SPI_BASE_PATH)/ssc/obj/SpiSlave.$(OBJ_FILE_SUFFIX)

SPI_PB_CFG_OBJECTS = $(SPI_BASE_PATH)/$(spipath)/obj/Spi_PBCfg.$(OBJ_FILE_SUFFIX) 



ifeq ($(SPI_DELIVERY_MODE),VARIANTPB_SOURCE) 
SPI_CLEAN_OBJECTS = $(SPI_SSC_OBJECTS) 
SPI_INCLUDE_PATH += $(CC_INC) "$(SPI_BASE_PATH)/ssc/inc" 
SPI_INCLUDE_PATH += $(CC_INC) "$(SPI_BASE_PATH)/$(spipath)/inc" 
endif 
SPI_DEMO_INCLUDE_PATH += $(CC_INC) "$(SPI_BASE_PATH)/demo/inc" 
 

ifeq ($(SPI_DEMO),STD_ON)
SPI_DEMO_OBJECTS = $(SPI_BASE_PATH)/demo/obj/Spi_Demo.$(OBJ_FILE_SUFFIX)
else
SPI_DEMO_OBJECTS =
endif

SPI_CLEAN_OBJECTS += $(SPI_DEMO_OBJECTS)


CLEAN_DRIVER_OBJECTS += $(SPI_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(SPI_DEMO_OBJECTS) 
# Following variables are to be used by the application 
SPI_DEP_HEADERS = $(SPI_BASE_PATH)/ssc/inc/Spi.h $(SPI_BASE_PATH)/$(spipath)/inc/Spi_Cfg.h