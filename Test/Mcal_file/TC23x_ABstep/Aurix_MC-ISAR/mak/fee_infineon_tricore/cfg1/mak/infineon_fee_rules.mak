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
#*  FILENAME  : infineon_fee_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2012.12.31                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the FEE driver             **
#*                   precompile configration objects only                     **
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
#*  V0.0.3 : 2012.12.31, SGN : Updated for compiler abstraction
#*  V0.0.2 : 2012.08.07, SGN : Updated Fee_PBCfg.c path
#*  V0.0.1 : 2007.09.22, RS  : Initial Version.
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

build_fee_driver : info feeincpaths $(FEE_CFG_OBJECTS)

ifeq ($(FEE_DELIVERY_MODE),VARIANTPC_SOURCE)
$(FEE_BASE_PATH)/$(feepath)/obj/Fee_Cfg.$(OBJ_FILE_SUFFIX) : $(FEE_BASE_PATH)/$(feepath)/src/Fee_PBCfg.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(FEE_BASE_PATH)/$(feepath)/obj/Fee_Cfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FEE_INC_PATHS_FILE)  $(OBJ_CREATION)  $(FEE_BASE_PATH)/$(feepath)/src/Fee_PBCfg.c  $(ERROR_REPORT)
	@-rm -f $(FEE_BASE_PATH)/$(feepath)/obj/Fee_Cfg.ers
endif

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
	@echo -------------Compiling FEE Configuration---------------

