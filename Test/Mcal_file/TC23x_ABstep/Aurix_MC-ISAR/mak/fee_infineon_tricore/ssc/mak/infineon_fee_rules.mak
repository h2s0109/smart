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
#*  FILENAME  : infineon_fee_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.4                                                         **
#*                                                                            **
#*  DATE      : 2013.08.06                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the FEE driver             **
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
#* SGN         Gururaj Nath S                                                **
#* RS          Roopa Sirur                                                   **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.4 : 2013.08.06, SGN : Updated for file splitting
#*  V0.0.3 : 2012.12.31, SGN : Updated for compiler abstraction
#*  V0.0.2 : 2007.09.19, RS  : Selectable / loadable - only SSC files compiled
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/fee_infineon_tricore/ssc/mak/infineon_fee_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(FEE_DEP_HEADERS)
FEE_INC_PATHS_FILE = fee_include_paths.ifx

build_fee_driver : info feeincpaths $(FEE_SSC_OBJECTS)

$(FEE_BASE_PATH)/ssc/obj/Fee.$(OBJ_FILE_SUFFIX) : $(FEE_BASE_PATH)\ssc\src\Fee.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_WITH_CODECOV)  $(OUTPUT) $(FEE_BASE_PATH)/ssc/obj/Fee.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FEE_INC_PATHS_FILE) $(OBJ_CREATION)  $(FEE_BASE_PATH)\ssc\src\Fee.c  $(ERROR_REPORT)
	@-rm -f $(FEE_BASE_PATH)/ssc/obj/Fee.ers

$(FEE_BASE_PATH)/ssc/obj/Fee_Ver.$(OBJ_FILE_SUFFIX) : $(FEE_BASE_PATH)\ssc\src\Fee_Ver.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_WITH_CODECOV)  $(OUTPUT) $(FEE_BASE_PATH)/ssc/obj/Fee_Ver.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FEE_INC_PATHS_FILE) $(OBJ_CREATION)  $(FEE_BASE_PATH)\ssc\src\Fee_Ver.c  $(ERROR_REPORT)
	@-rm -f $(FEE_BASE_PATH)/ssc/obj/Fee_Ver.ers

.PHONY: clean
clean:
	@-rm -f $(FEE_OBJECTS)


.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(FEE_OBJECTS)
	
feeincpaths:
	@echo $(STANDARD_INCLUDE) > $(FEE_INC_PATHS_FILE)
	@echo $(FEE_INCLUDE_PATH) >> $(FEE_INC_PATHS_FILE)

info: 
	@echo -------------Compiling FEE Module---------------

