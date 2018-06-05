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
#*                        configuration objects only                          **
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
#*  V0.0.3 : 2013.02.13, SS  : Changes for VendorApiInfix.
#*  V0.0.2 : 2012.10.25, AD  : Module specific compile variable introduced
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

build_icu_driver : info icuincpaths $(ICU_PB_CFG_OBJECTS)

$(ICU_BASE_PATH)/$(icupath)/obj/Icu_17_GtmCcu6_PBCfg.$(OBJ_FILE_SUFFIX) : $(ICU_BASE_PATH)/$(icupath)/src/Icu_17_GtmCcu6_PBCfg.c $(headers)
	@$(COMPILE_ICU)  $(OUTPUT) $(ICU_BASE_PATH)/$(icupath)/obj/Icu_17_GtmCcu6_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ICU_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ICU_BASE_PATH)/$(icupath)/src/Icu_17_GtmCcu6_PBCfg.c  $(ERROR_REPORT)
	@-rm -f $(ICU_BASE_PATH)/$(icupath)/obj/Icu_17_GtmCcu6_PBCfg.ers


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
	@echo $(GTM_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(ICU_INC_PATHS_FILE)

info: 
	@echo -------------Compiling ICU Configuration---------------

