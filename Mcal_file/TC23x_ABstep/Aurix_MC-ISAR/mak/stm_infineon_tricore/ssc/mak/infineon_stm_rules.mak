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
#*  FILENAME  : infineon_stm_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2007.09.23             
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the STM driver             **
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
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2007.09.23, RS  : Only SSC based files should be compiled in this mak
#*  V0.0.1 : 2007.02.23, RS  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/stm_infineon_tricore/ssc/mak/infineon_stm_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(STM_DEP_HEADERS)
STM_INC_PATHS_FILE = stm_include_paths.ifx 

build_stm_driver : info stmincpaths $(STM_SSC_OBJECTS) 

$(STM_BASE_PATH)/ssc/obj/Stm.$(OBJ_FILE_SUFFIX) : $(STM_BASE_PATH)\ssc\src\Stm.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h $(STM_BASE_PATH)\ssc\inc\Stm_Protect.h
	@$(COMPILE_STM) $(OUTPUT) $(STM_BASE_PATH)/ssc/obj/Stm.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STM_INC_PATHS_FILE) $(OBJ_CREATION)  $(STM_BASE_PATH)\ssc\src\Stm.c  $(ERROR_REPORT) 
	@-rm -f $(STM_BASE_PATH)/ssc/obj/Stm.ers 

.PHONY: clean
clean:
	@-rm -f $(STM_SSC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(STM_SSC_OBJECTS) 

stmincpaths: 
	@echo $(STANDARD_INCLUDE) > $(STM_INC_PATHS_FILE)
	@echo $(STM_INCLUDE_PATH) >> $(STM_INC_PATHS_FILE)	
	
info: 
	@echo -------------Compiling STM Module---------------