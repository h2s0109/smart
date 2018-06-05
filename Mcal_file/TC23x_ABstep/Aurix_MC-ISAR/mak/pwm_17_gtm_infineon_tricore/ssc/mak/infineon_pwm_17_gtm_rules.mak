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
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.10.25                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the PWM driver             **
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
#* AD          Abhishek Dwivedi                                              ** 
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.2 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1 : 2007.02.24, RS  : Initial Version, SSC rules to be compiled here
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_defs.mak

#***************************** SPECIFIC ****************************************/
headers = $(STANDARD_DEPENDANCY) $(PWM_DEP_HEADERS)
PWM_INC_PATHS_FILE = pwm_include_paths.ifx

build_pwm_driver : info incpaths $(PWM_SSC_OBJECTS)

$(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm.$(OBJ_FILE_SUFFIX) : $(PWM_BASE_PATH)\ssc\src\Pwm_17_Gtm.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_PWM) $(OUTPUT) $(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(PWM_INC_PATHS_FILE) $(OBJ_CREATION)  $(PWM_BASE_PATH)\ssc\src\Pwm_17_Gtm.c $(ERROR_REPORT)
	@-rm -f $(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm.ers

$(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm_Ver.$(OBJ_FILE_SUFFIX) : $(PWM_BASE_PATH)\ssc\src\Pwm_17_Gtm_Ver.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_PWM) $(OUTPUT) $(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm_Ver.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(PWM_INC_PATHS_FILE) $(OBJ_CREATION)  $(PWM_BASE_PATH)\ssc\src\Pwm_17_Gtm_Ver.c  $(ERROR_REPORT)
	@-rm -f $(PWM_BASE_PATH)/ssc/obj/Pwm_17_Gtm_Ver.ers

.PHONY: clean
clean:
	@-rm -f $(PWM_SSC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(PWM_SSC_OBJECTS)

incpaths:
	@echo $(STANDARD_INCLUDE) > $(PWM_INC_PATHS_FILE)
	@echo $(PWM_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	
info: 
	@echo -------------Compiling PWM Module---------------
