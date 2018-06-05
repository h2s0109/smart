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
#*  FILENAME  : infineon_sent_defs.mak                          	          **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.10.22                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the SENT driver files only                        **
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
#* AK           Ashish Kumar   			                                     **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2012.10.22, AK  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_check.mak 

#***************************** SPECIFIC ****************************************/  

SENT_SSC_OBJECTS = $(SENT_BASE_PATH)/ssc/obj/Sent.$(OBJ_FILE_SUFFIX)
SENT_SSC_OBJECTS += $(SENT_BASE_PATH)/$(sentpath)/obj/Sent_LCfg.$(OBJ_FILE_SUFFIX) 

SENT_PB_CFG_OBJECTS = $(SENT_BASE_PATH)/$(sentpath)/obj/Sent_PBCfg.$(OBJ_FILE_SUFFIX) 

 
ifeq ($(SENT_DELIVERY_MODE),VARIANTPB_SOURCE) 
SENT_CLEAN_OBJECTS = $(SENT_SSC_OBJECTS) 
SENT_INCLUDE_PATH += $(CC_INC) "$(SENT_BASE_PATH)/ssc/inc" 
SENT_INCLUDE_PATH += $(CC_INC) "$(SENT_BASE_PATH)/$(sentpath)/inc" 
endif 


ifeq ($(SENT_DEMO),STD_ON)
SENT_DEMO_OBJECTS = $(SENT_BASE_PATH)/demo/obj/Sent_Demo.$(OBJ_FILE_SUFFIX)
SENT_DEMO_INCLUDE_PATH += $(CC_INC) "$(SENT_BASE_PATH)/demo/inc" 
SENT_CLEAN_OBJECTS += $(SENT_DEMO_OBJECTS)
else
SENT_DEMO_OBJECTS =
endif


CLEAN_DRIVER_OBJECTS += $(SENT_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(SENT_DEMO_OBJECTS) 
# Following variables are to be used by the application  
SENT_DEP_HEADERS = $(SENT_BASE_PATH)/ssc/inc/Sent.h $(SENT_BASE_PATH)/$(sentpath)/inc/Sent_Cfg.h $(SENT_BASE_PATH)/ssc/inc/Sent_Types.h 
