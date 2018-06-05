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
#*  FILENAME  : infineon_port_defs.mak                                        **
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
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the PORT driver files only	                      **
#*                 			                                                      **
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

include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_check.mak 

#***************************** SPECIFIC ****************************************/  

PORT_SSC_OBJECTS = $(PORT_BASE_PATH)/ssc/obj/Port.$(OBJ_FILE_SUFFIX) 

PORT_PB_CFG_OBJECTS = $(PORT_BASE_PATH)/$(portpath)/obj/Port_PBCfg.$(OBJ_FILE_SUFFIX) 


ifeq ($(PORT_DELIVERY_MODE),VARIANTPB_SOURCE) 
PORT_CLEAN_OBJECTS = $(PORT_SSC_OBJECTS) 
PORT_INCLUDE_PATH += $(CC_INC) "$(PORT_BASE_PATH)/ssc/inc" 
PORT_INCLUDE_PATH += $(CC_INC) "$(PORT_BASE_PATH)/$(portpath)/inc" 
endif 
PORT_DEMO_INCLUDE_PATH += $(CC_INC) "$(PORT_BASE_PATH)/demo/inc" 
 
 
ifeq ($(PORT_DEMO),STD_ON) 
PORT_DEMO_OBJECTS = $(PORT_BASE_PATH)/demo/obj/Port_Demo.$(OBJ_FILE_SUFFIX) 
else 
PORT_DEMO_OBJECTS = 
endif 
PORT_CLEAN_OBJECTS += $(PORT_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(PORT_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(PORT_DEMO_OBJECTS) 
# Following variables are to be used by the application  
PORT_DEP_HEADERS = $(PORT_BASE_PATH)/ssc/inc/Port.h $(PORT_BASE_PATH)/ssc/inc/Port_Ver.h $(PORT_BASE_PATH)/$(portpath)/inc/Port_Cfg.h 