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
#*  FILENAME  : infineon_pwm_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2012.11.14                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the PWM driver             **
#*                    demo objects only                                       **
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
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.3 : 2012.11.14, AT  : Updated for multiple compiler support.
#*  V0.0.2 : 2011.09.17, AT  : Changed for the added vendor id in the module name.
#*  V0.0.1 : 2007.09.22, RS  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_defs.mak
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak

#***************************** SPECIFIC ****************************************/
headers = $(STANDARD_DEPENDANCY) $(PWM_DEP_HEADERS)
PWM_INC_PATHS_FILE = pwm_include_paths.ifx

build_pwm_driver : info incpaths $(PWM_DEMO_OBJECTS)


$(PWM_BASE_PATH)/demo/obj/Pwm_17_Gtm_Demo.$(OBJ_FILE_SUFFIX) : $(PWM_BASE_PATH)/demo/src/Pwm_17_Gtm_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(PWM_BASE_PATH)/demo/obj/Pwm_17_Gtm_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(PWM_INC_PATHS_FILE)  $(OBJ_CREATION)  $(PWM_BASE_PATH)/demo/src/Pwm_17_Gtm_Demo.c  $(ERROR_REPORT)
	@-rm -f $(PWM_BASE_PATH)/demo/obj/Pwm_17_Gtm_Demo.ers


.PHONY: clean
clean:
	@-rm -f $(PWM_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(PWM_OBJECTS)

incpaths:
	@echo $(STANDARD_INCLUDE) > $(PWM_INC_PATHS_FILE)
	@echo $(PWM_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	@echo $(PWM_DEMO_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	@echo $(ICU_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	@echo $(PORT_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)

	
info: 
	@echo -------------Compiling PWM Demo--------------
