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
#*  FILENAME  : infineon_cantrcv_17_6250gv33_rules.mak                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.12.28                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the CanTrcv Driver                   ** 
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
#* SK           SaiKiran B                                                   ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.12.28, SK  : Initial Version.
#*
#******************************************************************************/ 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/ssc/mak/infineon_cantrcv_17_6250gv33_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(CANTRCV_17_6250GV33_DEP_HEADERS) 
CANTRCV_17_6250GV33_INC_PATHS_FILE = cantrcv_17_6250gv33_include_paths.ifx 
 
 
build_cantrcv_17_6250GV33_driver : info cantrcv_17_6250gv33incpaths $(CANTRCV_17_6250GV33_SSC_OBJECTS) 
$(CANTRCV_17_6250GV33_BASE_PATH)/ssc/obj/CanTrcv_17_6250GV33.$(OBJ_FILE_SUFFIX) : $(CANTRCV_17_6250GV33_BASE_PATH)/ssc/src/CanTrcv_17_6250GV33.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h $(DIO_BASE_PATH)/ssc/inc/Dio.h 
	@$(COMPILE_CANTRCV_17_6250GV33)  $(OUTPUT) $(CANTRCV_17_6250GV33_BASE_PATH)/ssc/obj/CanTrcv_17_6250GV33.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(CANTRCV_17_6250GV33_INC_PATHS_FILE)  $(OBJ_CREATION)  $(CANTRCV_17_6250GV33_BASE_PATH)\ssc\src\CanTrcv_17_6250GV33.c  $(ERROR_REPORT) 
	@-rm -f $(CANTRCV_17_6250GV33_BASE_PATH)/ssc/obj/CanTrcv_17_6250GV33.ers 
 
print: 
	@echo $(CANTRCV_17_6250GV33_SSC_OBJECTS) 
cantrcv_17_6250gv33incpaths: 
	@echo $(STANDARD_INCLUDE) > $(CANTRCV_17_6250GV33_INC_PATHS_FILE)
	@echo $(CANTRCV_17_6250GV33_INCLUDE_PATH) >> $(CANTRCV_17_6250GV33_INC_PATHS_FILE) 
	@echo $(ECUM_INCLUDE_PATH) >> $(CANTRCV_17_6250GV33_INC_PATHS_FILE)
info:  
	@echo -------------Compiling CANTRCV_17_6250GV33 Module--------------- 
