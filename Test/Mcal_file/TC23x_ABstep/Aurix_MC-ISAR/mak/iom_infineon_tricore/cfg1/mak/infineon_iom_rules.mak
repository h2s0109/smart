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
#*  DESCRIPTION  : This make file builds the configuration of IOM Driver      ** 
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
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(IOM_DEP_HEADERS) 
IOM_INC_PATHS_FILE = iom_include_paths.ifx 
 
 
build_iom_driver : info iomincpaths $(IOM_PB_CFG_OBJECTS) 
$(IOM_BASE_PATH)/$(iompath)/obj/Iom_PBCfg.$(OBJ_FILE_SUFFIX) : $(IOM_BASE_PATH)/$(iompath)/src/Iom_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_IOM)  $(OUTPUT) $(IOM_BASE_PATH)/$(iompath)/obj/Iom_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IOM_INC_PATHS_FILE)  $(OBJ_CREATION)  $(IOM_BASE_PATH)/$(iompath)/src/Iom_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(IOM_BASE_PATH)/$(iompath)/obj/Iom_PBCfg.ers 
 
 
print: 
	@echo $(IOM_PB_CFG_OBJECTS) 
iomincpaths: 
	@echo $(STANDARD_INCLUDE) > $(IOM_INC_PATHS_FILE) 
	@echo $(IOM_INCLUDE_PATH) >> $(IOM_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling IOM Configuration--------------- 
