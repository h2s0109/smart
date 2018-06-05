#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2010)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_fr_17_eray_rules.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2010.02.15                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file builds the FR Driver                        **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      **
#*                                                                            **
#******************************************************************************/
#******************************************************************************* 
#*                      Author(s) Identity                                    ** 
#******************************************************************************* 
#*                                                                            ** 
#* Initials     Name                                                          ** 
#* ---------------------------------------------------------------------------** 
#* Prakash      Prakash Gudnavar                                              ** 
#*                                                                            ** 
#******************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  v0.0.2: 2010-02-15, PrakashG : AI00053231: File/Folder name change 
#*                                    Fr to Fr_17_Eray, fr to fr_17_eray
#*  V0.0.1 : 2009.01.16, Prakash  : Initial Version.
#*
#******************************************************************************/ 
 
#***************************** REQUIRE ****************************************/
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/ssc/mak/infineon_fr_17_eray_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(FR_DEP_HEADERS) 
FR_INC_PATHS_FILE = fr_include_paths.ifx 
 
 
build_fr_driver : info frincpaths $(FR_SSC_OBJECTS) 
$(FR_BASE_PATH)/ssc/obj/Fr_17_Eray.$(OBJ_FILE_SUFFIX) : $(FR_BASE_PATH)\ssc\src\Fr_17_Eray.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h
	@$(COMPILE_WITH_CODECOV) $(OUTPUT) $(FR_BASE_PATH)/ssc/obj/Fr_17_Eray.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FR_INC_PATHS_FILE)  $(OBJ_CREATION)  $(FR_BASE_PATH)\ssc\src\Fr_17_Eray.c  $(ERROR_REPORT) 
	@-rm -f $(FR_BASE_PATH)/ssc/obj/Fr_17_Eray.ers 


 
print: 
	@echo $(FR_SSC_OBJECTS) 
frincpaths: 
	@echo $(STANDARD_INCLUDE) > $(FR_INC_PATHS_FILE) 
	@echo $(FR_INCLUDE_PATH) >> $(FR_INC_PATHS_FILE)
info:  
	@echo -------------Compiling FR Module--------------- 
