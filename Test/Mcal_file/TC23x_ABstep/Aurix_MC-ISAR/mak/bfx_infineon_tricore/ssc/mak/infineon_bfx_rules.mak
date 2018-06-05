#******************************************************************************* 
#*                                                                            ** 
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
#*  FILENAME  : infineon_bfx_rules.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.09.18                                                    **  
#*                                                                            ** 
#*  AUTHOR    : Yadunandan Puttaswamy                                         ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the Bfx Library                      ** 
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
#* PY          Yadunandan Puttaswamy                                         ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.09.18, PY  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/bfx_infineon_tricore/ssc/mak/infineon_bfx_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) 
BFX_INC_PATHS_FILE = bfx_include_paths.ifx 

build_bfx_library : info bfxincpaths $(BFX_SSC_OBJECTS)	 
$(BFX_BASE_PATH)/ssc/obj/Bfx.$(OBJ_FILE_SUFFIX) : $(BFX_BASE_PATH)/ssc/src/Bfx.c $(headers) 
	@$(COMPILE_BFX)  $(OUTPUT) $(BFX_BASE_PATH)/ssc/obj/Bfx.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(BFX_INC_PATHS_FILE)  $(OBJ_CREATION)  $(BFX_BASE_PATH)\ssc\src\Bfx.c  $(ERROR_REPORT) 
	@-rm -f $(BFX_BASE_PATH)/ssc/obj/Bfx.ers 



.PHONY: clean
clean:
	@-rm -f $(BFX_SSC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx
	
print: 
	@echo $(BFX_SSC_OBJECTS) 
bfxincpaths: 
	@echo $(STANDARD_INCLUDE) > $(BFX_INC_PATHS_FILE)
	@echo $(BFX_INCLUDE_PATH) >> $(BFX_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling BFX Module--------------- 
