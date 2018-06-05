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
#*  FILENAME  : infineon_cantrcv_17_6251g_defs.mak                            ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         **
#*                                                                            ** 
#*  DATE      : 2012.12.28                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file contains the variable definitions                ** 
#*                            of CANTRCV_17_6251G module                      ** 
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
#* SK           SaiKiran B                                                   ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.12.28, SK  : Initial Version.
#*
#******************************************************************************/ 
 
#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251g_check.mak 

#***************************** SPECIFIC ****************************************/  
CANTRCV_17_6251G_SSC_OBJECTS = $(CANTRCV_17_6251G_BASE_PATH)/ssc/obj/CanTrcv_17_6251G.$(OBJ_FILE_SUFFIX) 

CANTRCV_17_6251G_PC_CFG_OBJECTS = $(CANTRCV_17_6251G_BASE_PATH)/$(cantrcv_17_6251gpath)/obj/CanTrcv_17_6251G_Cfg.$(OBJ_FILE_SUFFIX) 
 
ifeq ($(CANTRCV_17_6251G_DELIVERY_MODE),VARIANTPC_SOURCE) 
CANTRCV_17_6251G_CLEAN_OBJECTS = $(CANTRCV_17_6251G_SSC_OBJECTS) $(CANTRCV_17_6251G_PC_CFG_OBJECTS) 
CANTRCV_17_6251G_INCLUDE_PATH += $(CC_INC) "$(CANTRCV_17_6251G_BASE_PATH)/ssc/inc" 
CANTRCV_17_6251G_INCLUDE_PATH += $(CC_INC) "$(CANTRCV_17_6251G_BASE_PATH)/$(cantrcv_17_6251gpath)/inc" 
CANTRCV_17_6251G_INCLUDE_PATH += $(CC_INC) "$(DIO_BASE_PATH)/ssc/inc" 
CANTRCV_17_6251G_INCLUDE_PATH += $(CC_INC) "$(DIO_BASE_PATH)/$(cantrcv_17_6251gpath)/inc" 
CANTRCV_17_6251G_INCLUDE_PATH += $(CC_INC) "$(ECUM_BASE_PATH)/ssc/inc" 
CANTRCV_17_6251G_INCLUDE_PATH += $(CC_INC) "$(ECUM_BASE_PATH)/$(cantrcv_17_6251gpath)/inc" 

endif 
CANTRCV_17_6251G_DEMO_INCLUDE_PATH += $(CC_INC) "$(CANTRCV_17_6251G_BASE_PATH)/demo/inc" 
  
ifeq ($(CANTRCV_17_6251G_DEMO),STD_ON) 
CANTRCV_17_6251G_DEMO_OBJECTS = $(CANTRCV_17_6251G_BASE_PATH)/demo/obj/CanTrcv_17_6251G_Demo.$(OBJ_FILE_SUFFIX) 
else 
CANTRCV_17_6251G_DEMO_OBJECTS = 
endif 
CANTRCV_17_6251G_CLEAN_OBJECTS += $(CANTRCV_17_6251G_DEMO_OBJECTS) 
 
CLEAN_DRIVER_OBJECTS += $(CANTRCV_17_6251G_SSC_OBJECTS)
CLEAN_DEMO_OBJECTS += $(CANTRCV_17_6251G_DEMO_OBJECTS) 
# Following variables are to be used by the application  
CANTRCV_17_6251G_DEP_HEADERS = $(CANTRCV_17_6251G_BASE_PATH)/ssc/inc/CanTrcv_17_6251G.h $(CANTRCV_17_6251G_BASE_PATH)/$(cantrcv_17_6251gpath)/inc/CanTrcv_17_6251G_Cfg.h 
