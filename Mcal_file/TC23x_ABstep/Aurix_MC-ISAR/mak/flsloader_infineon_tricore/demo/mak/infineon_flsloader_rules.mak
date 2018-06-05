#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2009)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_flsloader_rules.mak                                  **
#*                                                                            **
#*  VERSION   : 1.0.0                                                         **
#*                                                                            **
#*  DATE      : 2009.03.02                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the FLSLOADER driver       **
#*                    Demo objects only                                         **
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
#* BM           Basheer Mohaideen                                            **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V1.0.0 : 2009.03.02, BM  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_defs.mak


#***************************** SPECIFIC ****************************************/
headers = $(STANDARD_DEPENDANCY) $(FLSLOADER_DEP_HEADERS)
#******** File Containing the include paths required for the FADC Driver
FLSLOADER_INC_PATHS_FILE = flsloader_include_paths.ifx


build_flsloader_driver : info flsloaderincpaths $(FLSLOADER_DEMO_OBJECTS)

$(FLSLOADER_BASE_PATH)/demo/obj/FlsLoader_Demo.$(OBJ_FILE_SUFFIX) : $(FLSLOADER_BASE_PATH)/demo/src/FlsLoader_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(FLSLOADER_BASE_PATH)/demo/obj/FlsLoader_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLSLOADER_INC_PATHS_FILE)  $(OBJ_CREATION)  $(FLSLOADER_BASE_PATH)/demo/src/FlsLoader_Demo.c  $(ERROR_REPORT)
	@-rm -f $(FLSLOADER_BASE_PATH)/demo/obj/FlsLoader_Demo.ers

.PHONY: clean
clean:
	@-rm -f $(FLSLOADER_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(FLSLOADER_OBJECTS)

flsloaderincpaths:
	@echo $(STANDARD_INCLUDE) > $(FLSLOADER_INC_PATHS_FILE)
	@echo $(FLSLOADER_INCLUDE_PATH) >> $(FLSLOADER_INC_PATHS_FILE)
	@echo $(FLSLOADER_DEMO_INCLUDE_PATH) >> $(FLSLOADER_INC_PATHS_FILE)

	
info: 
	@echo -------------Compiling FLSLOADER Demo---------------
