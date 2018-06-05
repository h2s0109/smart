#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2007)                                 **
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
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.11.02                                                    **
#*                                                                            **
#*                                                                            **                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the MCU driver             **
#*                       demo objects only                                    **
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
#* RS           Roopa Sirur                                                  **
#* MK           Mundhra Karan                                                **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  
#*  V0.0.2 : 2012.11.02, MK  : Multi compiler support changes
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

build_mcu_driver : info incpaths $(MCU_DEMO_OBJECTS)



$(MCU_BASE_PATH)/demo/obj/Mcu_Demo.$(OBJ_FILE_SUFFIX) : $(MCU_BASE_PATH)/demo/src/Mcu_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(MCU_BASE_PATH)/demo/obj/Mcu_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(MCU_INC_PATHS_FILE) $(OBJ_CREATION)  $(MCU_BASE_PATH)/demo/src/Mcu_Demo.c $(ERROR_REPORT)
	@-rm -f $(MCU_BASE_PATH)/demo/obj/Mcu_Demo.ers


.PHONY: clean
clean:
	@-rm -f $(MCU_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(MCU_OBJECTS)
	
incpaths:
	@echo $(STANDARD_INCLUDE) > $(MCU_INC_PATHS_FILE)
	@echo $(MCU_INCLUDE_PATH) >> $(MCU_INC_PATHS_FILE)
	@echo $(MCU_DEMO_INCLUDE_PATH) >> $(MCU_INC_PATHS_FILE)
	

info: 
	@echo -------------Compiling MCU Demo---------------
