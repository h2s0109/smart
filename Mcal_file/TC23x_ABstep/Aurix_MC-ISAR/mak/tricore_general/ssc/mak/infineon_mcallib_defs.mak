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
#*  FILENAME  : infineon_mcallib_defs.mak                                     **
#*                                                                            **
#*  VERSION   : 0.1.3                                                         **
#*                                                                            **
#*  DATE      : 2013.07.17                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the MCAL library files only		                    **
#*                 						                                                **
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
#* SK           Sai Kiran                                                    **
#* AT           Angeswaran Thangaswamy                                       **
#* PR           Pawan Reddy                                                  **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.3: 2013.07.17, AT  : Wdtcon.c compilation removed
#*  V0.1.2: 2013.02.27, SK  : Mcal Library Split
#*  V0.1.1: 2012.08.22, AT  : Updated for GNU compiler
#*  V0.1.0: PR: Intial Version for Aurix                         
#*
#******************************************************************************/

#***************************** SPECIFIC ****************************************/

MCALLIB_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal.$(OBJ_FILE_SUFFIX)
MCALLIB_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_TcLib.$(OBJ_FILE_SUFFIX)
MCALLIB_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_WdgLib.$(OBJ_FILE_SUFFIX)
MCALLIB_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_DmaLib.$(OBJ_FILE_SUFFIX)

MCALLIB_CLEAN_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal.$(OBJ_FILE_SUFFIX)

#***************************** REGISTRY ****************************************/

OBJECTS_LINK_ONLY += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal.$(OBJ_FILE_SUFFIX)
OBJECTS_LINK_ONLY += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_TcLib.$(OBJ_FILE_SUFFIX)
OBJECTS_LINK_ONLY += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_WdgLib.$(OBJ_FILE_SUFFIX)
OBJECTS_LINK_ONLY += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_DmaLib.$(OBJ_FILE_SUFFIX)

CLEAN_DRIVER_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal.$(OBJ_FILE_SUFFIX)
CLEAN_DRIVER_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_TcLib.$(OBJ_FILE_SUFFIX)
CLEAN_DRIVER_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_WdgLib.$(OBJ_FILE_SUFFIX)
CLEAN_DRIVER_OBJECTS += $(MCALLIB_BASE_PATH)/ssc/obj/Mcal_DmaLib.$(OBJ_FILE_SUFFIX)


