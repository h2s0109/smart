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
#*  FILENAME  : infineon_integration_general_defs.mak                         **
#*                                                                            **
#*  VERSION   : 0.1.3                                                         **
#*                                                                            **
#*  DATE      : 2012-10-19                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the standard test stub files only                 **
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
#* SGN          Gururaj Nath S                                               **
#* AK           Ashish Kumar                                                 **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.3 :AK: Update for SENT callout                            **
#*  VERSION   : 0.1.2 :SGN: Removed Fee_Fcpt                                  **
#*  VERSION   : 0.1.1 :SGN: Changed ON to STD_ON                              **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak
include $(SSC_ROOT)/mak/base_make.mak

CANIF_INCLUDE = STD_OFF
STDTEST_INCLUDE_PATH = $(CC_INC) $(STDTEST_BASE_PATH)/inc 

STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Test_Print.$(OBJ_FILE_SUFFIX)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Test_Time.$(OBJ_FILE_SUFFIX)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/SafetyReport.$(OBJ_FILE_SUFFIX)
ifeq ($(DEM_DELIVERY),STD_ON)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Dem.$(OBJ_FILE_SUFFIX)
endif
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Os.$(OBJ_FILE_SUFFIX)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/OsStub.$(OBJ_FILE_SUFFIX)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Det.$(OBJ_FILE_SUFFIX)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/SchM.$(OBJ_FILE_SUFFIX)
ifeq ($(CAN_DELIVERY),STD_ON)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/CanIf_Cbk.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(ETH_DELIVERY),STD_ON)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/EthIf_Cbk.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(CANTRCV_6251G_DELIVERY),STD_ON)
CANIF_INCLUDE = STD_ON
endif

ifeq ($(CANTRCV_6250GV33_DELIVERY),STD_ON)
CANIF_INCLUDE = STD_ON
endif
ifeq ($(CANIF_INCLUDE),STD_ON)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/CanIf.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(SENT_DELIVERY),STD_ON)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Sent_Callout.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(DMA_DELIVERY),STD_ON)
STDTEST_OBJECTS += $(STDTEST_BASE_PATH)/obj/Dma_Callout.$(OBJ_FILE_SUFFIX)
endif

STDTEST_CLEAN_OBJECTS += $(STDTEST_OBJECTS)

OBJECTS_LINK_ONLY += $(STDTEST_OBJECTS)

CLEAN_ALL_OBJECTS += $(STDTEST_OBJECTS)