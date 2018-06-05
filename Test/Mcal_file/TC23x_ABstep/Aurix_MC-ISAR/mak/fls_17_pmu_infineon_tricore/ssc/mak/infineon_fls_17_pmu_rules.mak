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
#*  FILENAME  : infineon_fls_17_pmu_rules.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.4                                                         **
#*                                                                            **
#*  DATE      : 2013.08.06                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the FLS driver             **
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
#* AD          Abhishek Dwivedi                                              **
#* RS          Roopa Sirur                                                   **
#* SGN         Gururaj Nath S                                                **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.4 : 2013.08.06, SGN : Updated for file splitting
#*  V0.0.3 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1 : 2007.06.19, RS  : Only SSC based files should be compiled in this mak
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(FLS_DEP_HEADERS) 
FLS_INC_PATHS_FILE = fls_include_paths.ifx 


build_fls_driver : info flsincpaths $(FLS_SSC_OBJECTS) 

$(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu.$(OBJ_FILE_SUFFIX) : $(FLS_BASE_PATH)\ssc\src\Fls_17_Pmu.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h 
	@$(COMPILE_FLS) $(OUTPUT) $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLS_INC_PATHS_FILE) $(OBJ_CREATION)  $(FLS_BASE_PATH)\ssc\src\Fls_17_Pmu.c  $(ERROR_REPORT)
	@-rm -f $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu.ers
		
$(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_Ver.$(OBJ_FILE_SUFFIX) : $(FLS_BASE_PATH)\ssc\src\Fls_17_Pmu_Ver.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h 
	@$(COMPILE_FLS) $(OUTPUT) $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_Ver.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLS_INC_PATHS_FILE) $(OBJ_CREATION)  $(FLS_BASE_PATH)\ssc\src\Fls_17_Pmu_Ver.c  $(ERROR_REPORT)
	@-rm -f $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_Ver.ers
		
$(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_ac.$(OBJ_FILE_SUFFIX) : $(FLS_BASE_PATH)\ssc\src\Fls_17_Pmu_ac.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h 
	@$(COMPILE_FLS) $(OUTPUT) $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_ac.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(FLS_INC_PATHS_FILE) $(OBJ_CREATION)  $(FLS_BASE_PATH)\ssc\src\Fls_17_Pmu_ac.c  $(ERROR_REPORT)
	@-rm -f $(FLS_BASE_PATH)/ssc/obj/Fls_17_Pmu_ac.ers


print:
	@echo $(FLS_OBJECTS)
	
flsincpaths:
	@echo $(STANDARD_INCLUDE) > $(FLS_INC_PATHS_FILE)
	@echo $(FLS_INCLUDE_PATH) >> $(FLS_INC_PATHS_FILE)
	
info: 
	@echo -------------Compiling FLS Module---------------

