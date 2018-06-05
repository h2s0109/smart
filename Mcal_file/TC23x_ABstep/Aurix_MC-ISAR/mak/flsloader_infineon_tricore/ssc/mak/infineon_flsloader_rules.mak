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
#*  VERSION   : 1.0.1                                                         **
#*                                                                            **
#*  DATE      : 2013.08.20                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the FLSLOADER driver       **
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
#* BM          Basheer Moahdieen                                             **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V1.0.1 : 2009.03.02, Vani  : Updated for FlsLoader Platform.c
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


build_flsloader_driver : info flsloaderincpaths $(FLSLOADER_SSC_OBJECTS)
	
$(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader.$(OBJ_FILE_SUFFIX) : $(FLSLOADER_BASE_PATH)\ssc\src\FlsLoader.c $(headers) $(DET_FILE_PATH)/Det.h $(FLSLOADER_BASE_PATH)/ssc/inc/FlsLoader_Local.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h  
	@$(COMPILE_WITH_CODECOV)  $(OUTPUT) $(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLSLOADER_INC_PATHS_FILE) $(OBJ_CREATION)  $(FLSLOADER_BASE_PATH)\ssc\src\FlsLoader.c  $(ERROR_REPORT)
	@-rm -f $(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader.ers
	
$(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader_Platform.$(OBJ_FILE_SUFFIX) : $(FLSLOADER_BASE_PATH)\ssc\src\FlsLoader_Platform.c $(headers) $(DET_FILE_PATH)/Det.h $(FLSLOADER_BASE_PATH)/ssc/inc/FlsLoader_Local.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_WITH_CODECOV)  $(OUTPUT) $(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader_Platform.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLSLOADER_INC_PATHS_FILE) $(OBJ_CREATION)  $(FLSLOADER_BASE_PATH)\ssc\src\FlsLoader_Platform.c  $(ERROR_REPORT)
	@-rm -f $(FLSLOADER_BASE_PATH)/ssc/obj/FlsLoader_Platform.ers

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
	
	
info: 
	@echo -------------Compiling FLSLOADER Module---------------
