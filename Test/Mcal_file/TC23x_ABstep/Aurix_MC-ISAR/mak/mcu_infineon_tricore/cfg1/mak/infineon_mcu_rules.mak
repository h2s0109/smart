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
#*  FILENAME  : infineon_mcu_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2012.11.02                                                    **
#*                                                                            **
#*                                                                            **                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the MCU driver             **
#*                    configuration objects only                              **
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
#* MK          Mundhra Karan                                                 ** 
#* AD          Abhishek Dwivedi                                              ** 
#* RS          Roopa Sirur                                                   **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.3 : 2012.11.02, MK  : Multi compiler support changes
#*  V0.0.2 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1:  2007.09.22, RS  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak


#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(MCU_DEP_HEADERS) 
MCU_INC_PATHS_FILE = mcu_include_paths.ifx


build_mcu_driver : info mcuincpaths $(MCU_PB_CFG_OBJECTS) 
$(MCU_BASE_PATH)/$(mcupath)/obj/Mcu_PBCfg.$(OBJ_FILE_SUFFIX) : $(MCU_BASE_PATH)/$(mcupath)/src/Mcu_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_MCU)  $(OUTPUT) $(MCU_BASE_PATH)/$(mcupath)/obj/Mcu_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(MCU_INC_PATHS_FILE)  $(OBJ_CREATION)  $(MCU_BASE_PATH)/$(mcupath)/src/Mcu_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(MCU_BASE_PATH)/$(mcupath)/obj/Mcu_PBCfg.ers 

print:
	@echo $(MCU_PB_CFG_OBJECTS) 
	
mcuincpaths: 
	@echo $(STANDARD_INCLUDE) > $(MCU_INC_PATHS_FILE)
	@echo $(MCU_INCLUDE_PATH) >> $(MCU_INC_PATHS_FILE)
	

info: 
	@echo -------------Compiling MCU Configuration---------------
