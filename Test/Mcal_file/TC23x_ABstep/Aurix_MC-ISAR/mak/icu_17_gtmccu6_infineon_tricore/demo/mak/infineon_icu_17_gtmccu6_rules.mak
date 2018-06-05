#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2011)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_icu_17_gtmccu6_rules.mak                             **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2013.02.13                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the ICU driver             **
#*                       demo objects only                                    **
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
#* RS          Roopa Sirur                                                   **
#* VS          Vinod Shankar                                                 **
#* SS          Srinivas Shenoy                                               **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.3 : 2013.02.13, SS  : Changes for VendorApiInfix.
#*  V0.0.2 : 2011.09.18, VS  : Modified for Aurix.
#*  V0.0.1 : 2007.09.22, RS  : Initial Version.
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

build_icu_driver : info icuincpaths $(ICU_DEMO_OBJECTS)

$(ICU_BASE_PATH)/demo/obj/Icu_17_GtmCcu6_Demo.$(OBJ_FILE_SUFFIX) : $(ICU_BASE_PATH)/demo/src/Icu_17_GtmCcu6_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(ICU_BASE_PATH)/demo/obj/Icu_17_GtmCcu6_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ICU_INC_PATHS_FILE) $(OBJ_CREATION)  $(ICU_BASE_PATH)/demo/src/Icu_17_GtmCcu6_Demo.c  $(ERROR_REPORT)
	@-rm -f $(ICU_BASE_PATH)/demo/obj/Icu_17_GtmCcu6_Demo.ers	

.PHONY: clean
clean:
	@-rm -f $(ICU_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(ICU_OBJECTS)
	
icuincpaths:
	@echo $(STANDARD_INCLUDE) > $(ICU_INC_PATHS_FILE)
	@echo $(ICU_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)
	@echo $(ICU_DEMO_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)

info: 
	@echo -------------Compiling ICU Demo---------------

