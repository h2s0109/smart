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
#*  FILENAME  : infineon_fls_17_pmu_rules.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2013.02.22                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the FLS driver             **
#*                   Demo objects only                                        **
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
#* RS          Roopa Sirur                                                   **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.2 : 2013.02.22, RS  : Updated Fls names with vendor API infix.
#*  V0.0.1 : 2007.09.22, RS  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(FLS_DEP_HEADERS) 
FLS_INC_PATHS_FILE = fls_include_paths.ifx 

build_fls_driver : info flsincpaths $(FLS_DEMO_OBJECTS)

$(FLS_BASE_PATH)/demo/obj/Fls_17_Pmu_Demo.$(OBJ_FILE_SUFFIX) : $(FLS_BASE_PATH)/demo/src/Fls_17_Pmu_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(FLS_BASE_PATH)/demo/obj/Fls_17_Pmu_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLS_INC_PATHS_FILE) $(OBJ_CREATION)  $(FLS_BASE_PATH)/demo/src/Fls_17_Pmu_Demo.c  $(ERROR_REPORT)
	@-rm -f $(FLS_BASE_PATH)/demo/obj/Fls_17_Pmu_Demo.ers

.PHONY: clean
clean:
	@-rm -f $(FLS_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(FLS_OBJECTS)
	
flsincpaths:
	@echo $(STANDARD_INCLUDE) > $(FLS_INC_PATHS_FILE)
	@echo $(FLS_INCLUDE_PATH) >> $(FLS_INC_PATHS_FILE)
	@echo $(FLS_DEMO_INCLUDE_PATH) >> $(FLS_INC_PATHS_FILE)            
	
info: 
	@echo -------------Compiling FLS Demo---------------

