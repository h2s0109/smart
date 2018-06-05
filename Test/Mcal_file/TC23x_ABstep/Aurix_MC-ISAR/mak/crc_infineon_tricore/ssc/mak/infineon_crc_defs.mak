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
#*  FILENAME  : infineon_crc_defs.mak 	                                      **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.09.28                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the CRC Library files only			                  **
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
#* KP          Kaushal Purohit                                              **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.0.1 : KP: Intial Version for Aurix AS321                   **
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/crc_infineon_tricore/ssc/mak/infineon_crc_check.mak

#***************************** SPECIFIC ****************************************/

CRC_SSC_OBJECTS = $(CRC_BASE_PATH)/ssc/obj/Crc.$(OBJ_FILE_SUFFIX)




CRC_INCLUDE_PATH  = $(CC_INC) "$(CRC_BASE_PATH)/$(crcpath)/inc"

CRC_INCLUDE_PATH += $(CC_INC) "$(CRC_BASE_PATH)/ssc/inc"




ifeq ($(CRC_DEMO),STD_ON)
CRC_DEMO_OBJECTS = $(CRC_BASE_PATH)/demo/obj/Crc_Demo.$(OBJ_FILE_SUFFIX)
CRC_DEMO_INCLUDE_PATH = $(CC_INC) "$(CRC_BASE_PATH)/demo/inc"
else
CRC_DEMO_OBJECTS =
CRC_DEMO_INCLUDE_PATH = 
endif
CRC_CLEAN_OBJECTS += $(CRC_DEMO_OBJECTS)

CLEAN_DRIVER_OBJECTS += $(CRC_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(CRC_DEMO_OBJECTS)

# Following variables are to be used by the application 

CRC_DEP_HEADERS = $(CRC_BASE_PATH)/ssc/inc/Crc.h $(CRC_BASE_PATH)/ssc/inc/Crc_Protect.h $(CRC_BASE_PATH)/$(crcpath)/inc/Crc_Cfg.h