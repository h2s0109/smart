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
#*  FILENAME  : infineon_icu_17_gtmccu6_rules.mak                                     **
#*                                                                            **
#*  VERSION   : 0.0.4                                                         **
#*                                                                            **
#*  DATE      : 2013.02.13                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the ICU driver             **
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
#* SS          Srinivas Shenoy                                               **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.4 : 2013.02.13, SS  : Changes for VendorApiInfix.
#*  V0.0.3 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.2: 2007.09.21, RS: Only SSC based files should be compiled in this mak
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(ICU_DEP_HEADERS)
ICU_INC_PATHS_FILE = icu_include_paths.ifx

build_icu_driver : info icuincpaths $(ICU_SSC_OBJECTS)

$(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6.$(OBJ_FILE_SUFFIX) : $(ICU_BASE_PATH)\ssc\src\Icu_17_GtmCcu6.c $(headers) $(DET_FILE_PATH /Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_ICU) $(OUTPUT) $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ICU_INC_PATHS_FILE) $(OBJ_CREATION)  $(ICU_BASE_PATH)\ssc\src\Icu_17_GtmCcu6.c  $(ERROR_REPORT)
	@-rm -f $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6.ers

$(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Safe.$(OBJ_FILE_SUFFIX) : $(ICU_BASE_PATH)\ssc\src\Icu_17_GtmCcu6_Safe.c $(headers) $(DET_FILE_PATH /Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_ICU) $(OUTPUT) $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Safe.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ICU_INC_PATHS_FILE) $(OBJ_CREATION)  $(ICU_BASE_PATH)\ssc\src\Icu_17_GtmCcu6_Safe.c  $(ERROR_REPORT)
	@-rm -f $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Safe.ers

$(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Ver.$(OBJ_FILE_SUFFIX) : $(ICU_BASE_PATH)\ssc\src\Icu_17_GtmCcu6_Ver.c $(headers) $(DET_FILE_PATH /Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_ICU) $(OUTPUT) $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Ver.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ICU_INC_PATHS_FILE) $(OBJ_CREATION)  $(ICU_BASE_PATH)\ssc\src\Icu_17_GtmCcu6_Ver.c  $(ERROR_REPORT)
	@-rm -f $(ICU_BASE_PATH)/ssc/obj/Icu_17_GtmCcu6_Ver.ers
	
.PHONY: clean
clean:
	@-rm -f $(ICU_SSC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(ICU_SSC_OBJECTS)
	
icuincpaths:
	@echo $(STANDARD_INCLUDE) > $(ICU_INC_PATHS_FILE)
	@echo $(ICU_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)

info: 
	@echo -------------Compiling ICU Module---------------

