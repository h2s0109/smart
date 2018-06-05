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
#*  FILENAME  : infineon_stm_defs.mak                                         **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.11.18                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines configuration for the STM module         **
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
#* RR           Rudragouda Rudnoor                                           **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2012.11.18, RR  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/stm_infineon_tricore/ssc/mak/infineon_stm_check.mak 
#***************************** SPECIFIC ****************************************/  

STM_SSC_OBJECTS = $(STM_BASE_PATH)/ssc/obj/Stm.$(OBJ_FILE_SUFFIX) 


STM_CLEAN_OBJECTS = $(STM_SSC_OBJECTS) 
STM_INCLUDE_PATH += $(CC_INC) "$(STM_BASE_PATH)/ssc/inc" 
 

ifeq ($(STM_DEMO),STD_ON)
STM_DEMO_OBJECTS = $(STM_BASE_PATH)/demo/obj/Stm_Demo.$(OBJ_FILE_SUFFIX)
STM_INCLUDE_PATH += $(CC_INC) "$(STM_BASE_PATH)/demo/inc" 
STM_DEMO_INCLUDE_PATH += $(CC_INC) "$(STM_BASE_PATH)/demo/inc" 
else
STM_DEMO_OBJECTS =
STM_DEMO_INCLUDE_PATH =
endif

STM_CLEAN_OBJECTS += $(STM_DEMO_OBJECTS)


CLEAN_DRIVER_OBJECTS += $(STM_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(STM_DEMO_OBJECTS) 
# Following variables are to be used by the application 
STM_DEP_HEADERS = $(STM_BASE_PATH)/ssc/inc/Stm.h $(STM_BASE_PATH)/ssc/inc/Stm_Protect.h