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
#*  FILENAME  : infineon_adc_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2012.09.17                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the ADC driver             **
#*                   demo objects only                                        **
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
#* AT           Angeswaran Thangaswamy                                       **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.2 : 2012.09.17, AT  : Updated for WINDRIVER compiler.
#*  V0.0.2 : 2012.08.21, AT  : Updated for GNU compiler.
#*  V0.0.1 : 2011.09.26, AT  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak


#***************************** SPECIFIC ****************************************/
headers = $(STANDARD_DEPENDANCY) $(ADC_DEP_HEADERS)
ADC_INC_PATHS_FILE = adc_include_paths.ifx

build_adc_driver : info adcincpaths $(ADC_DEMO_OBJECTS)

$(ADC_BASE_PATH)/demo/obj/Adc_Demo.$(OBJ_FILE_SUFFIX) : $(ADC_BASE_PATH)/demo/src/Adc_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(ADC_BASE_PATH)/demo/obj/Adc_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ADC_BASE_PATH)/demo/src/Adc_Demo.c  $(ERROR_REPORT)
	@-rm -f $(ADC_BASE_PATH)/demo/obj/Adc_Demo.ers


.PHONY: clean
clean:
	@-rm -f $(ADC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(ADC_OBJECTS)
adcincpaths:
	@echo $(STANDARD_INCLUDE) > $(ADC_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(ADC_INC_PATHS_FILE)
	@echo $(ADC_INCLUDE_PATH) >> $(ADC_INC_PATHS_FILE)
	@echo $(ADC_DEMO_INCLUDE_PATH) >> $(ADC_INC_PATHS_FILE)

	
info: 
	@echo -------------Compiling ADC Demo---------------
