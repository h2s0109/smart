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
#*  FILENAME  : infineon_smu_rules.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2013.09.24                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the SMU Driver                       ** 
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
#* RK          Rutuja Kawathekar                                             ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2013.09.24, RK  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/smu_infineon_tricore/ssc/mak/infineon_smu_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(SMU_DEP_HEADERS) 
SMU_INC_PATHS_FILE = smu_include_paths.ifx 
 
 
build_smu_driver : info smuincpaths $(SMU_SSC_OBJECTS) 
$(SMU_BASE_PATH)/ssc/obj/Smu.$(OBJ_FILE_SUFFIX) : $(SMU_BASE_PATH)/ssc/src/Smu.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_SMU) $(OUTPUT) $(SMU_BASE_PATH)/ssc/obj/Smu.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(SMU_INC_PATHS_FILE)  $(OBJ_CREATION)  $(SMU_BASE_PATH)/ssc/src/Smu.c  $(ERROR_REPORT) 
	@-rm -f $(SMU_BASE_PATH)/ssc/obj/Smu.ers 
 
$(SMU_BASE_PATH)/ssc/obj/Sl_Ipc.$(OBJ_FILE_SUFFIX) : $(SMU_BASE_PATH)/ssc/src/Sl_Ipc.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_SMU) $(OUTPUT) $(SMU_BASE_PATH)/ssc/obj/Sl_Ipc.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(SMU_INC_PATHS_FILE)  $(OBJ_CREATION)  $(SMU_BASE_PATH)/ssc/src/Sl_Ipc.c  $(ERROR_REPORT) 
	@-rm -f $(SMU_BASE_PATH)/ssc/obj/Sl_Ipc.ers 
 
print: 
	@echo $(SMU_SSC_OBJECTS) 
smuincpaths: 
	@echo $(STANDARD_INCLUDE) > $(SMU_INC_PATHS_FILE) 
	@echo $(SMU_INCLUDE_PATH) >> $(SMU_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling SMU Module--------------- 
