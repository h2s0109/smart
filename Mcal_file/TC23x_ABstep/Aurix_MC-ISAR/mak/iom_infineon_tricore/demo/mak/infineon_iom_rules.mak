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
#*  FILENAME  : infineon_iom_rules.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.10.19                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the demo of IOM Driver               ** 
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
#* HM         Hamzath                                                        ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.10.19, HM  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/iom_infineon_tricore/ssc/mak/infineon_iom_defs.mak 
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(IOM_DEP_HEADERS) $(GTM_DEP_HEADERS) 
IOM_INC_PATHS_FILE = iom_include_paths.ifx 
 
 
build_iom_driver : info iomincpaths $(IOM_DEMO_OBJECTS) 
$(IOM_BASE_PATH)/demo/obj/Iom_Demo.$(OBJ_FILE_SUFFIX) : $(IOM_BASE_PATH)/demo/src/Iom_Demo.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h $(IOM_BASE_PATH)/demo/inc/Iom_Demo.h 
	@$(COMPILE_IOM)  $(OUTPUT) $(IOM_BASE_PATH)/demo/obj/Iom_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IOM_INC_PATHS_FILE) $(OBJ_CREATION) $(IOM_BASE_PATH)/demo/src/Iom_Demo.c  $(ERROR_REPORT) 
	@-rm -f $(IOM_BASE_PATH)/demo/obj/Iom_Demo.ers 
 
 
print: 
	@echo $(IOM_DEMO_OBJECTS) 
iomincpaths: 
	@echo $(STANDARD_INCLUDE) > $(IOM_INC_PATHS_FILE) 
	@echo $(IOM_INCLUDE_PATH) >> $(IOM_INC_PATHS_FILE) 
	@echo $(GTM_INCLUDE_PATH) >> $(IOM_INC_PATHS_FILE) 
	@echo $(IOM_DEMO_INCLUDE_PATH) >> $(IOM_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling IOM Demo--------------- 
