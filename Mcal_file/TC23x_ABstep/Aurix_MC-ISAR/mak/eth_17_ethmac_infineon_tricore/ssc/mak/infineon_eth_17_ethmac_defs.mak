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
#*  FILENAME  : infineon_eth_17_ethmac_defs.mak                                      **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.03.02                                                    **
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
#* PB           P.Balakrishnan                                               **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.0 : 2012.03.02, PB  : Initial version.
#*
#******************************************************************************/

#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_check.mak

#***************************** SPECIFIC ****************************************/

ETH_SSC_OBJECTS = $(ETH_BASE_PATH)/ssc/obj/Eth_17_EthMac.$(OBJ_FILE_SUFFIX)
ETH_PB_CFG_OBJECTS = $(ETH_BASE_PATH)/$(ethpath)/obj/Eth_17_EthMac_PBCfg.$(OBJ_FILE_SUFFIX) 

ifeq ($(ETH_DELIVERY_MODE),VARIANTPB_SOURCE)
ETH_CLEAN_OBJECTS = $(ETH_SSC_OBJECTS) 
ETH_INCLUDE_PATH += $(CC_INC) "$(ETH_BASE_PATH)/ssc/inc" 
ETH_INCLUDE_PATH += $(CC_INC) "$(ETH_BASE_PATH)/$(ethpath)/inc"
endif
ETH_DEMO_INCLUDE_PATH += $(CC_INC) "$(ETH_BASE_PATH)/demo/inc" 


ifeq ($(ETH_DEMO),STD_ON)
ETH_DEMO_OBJECTS = $(ETH_BASE_PATH)/demo/obj/Eth_17_EthMac_Demo.$(OBJ_FILE_SUFFIX)
else
ETH_DEMO_OBJECTS =
endif
ETH_CLEAN_OBJECTS += $(ETH_DEMO_OBJECTS) 

CLEAN_DRIVER_OBJECTS += $(ETH_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(ETH_DEMO_OBJECTS) 
# Following variables are to be used by the application  
ETH_DEP_HEADERS = $(ETH_BASE_PATH)/ssc/inc/Eth_17_EthMac.h $(ETH_BASE_PATH)/ssc/inc/Eth_17_EthMac_Types.h $(ETH_BASE_PATH)/$(ethpath)/inc/Eth_17_EthMac_Cfg.h 
