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
#*  VERSION   : 0.0.4                                                         **
#*                                                                            **
#*  DATE      : 2012.10.25                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the PWM driver             **
#*                     configuration objects only                             **
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
#* AD           Abhishek Dwivedi                                             **
#* AT           Angeswaran Thangaswamy                                       **
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#* V0.0.4 : 2012.10.25, AD  : Module specific compile variable introduced
#* V0.0.3 : 2012.06.13, AT  : included Gtm.h.
#* V0.0.2 : 2011.09.17, AT  : Changed for the added vendor id in the module name.
#* V0.0.1 : 2007.09.22, RS  : Initial Version.
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


build_pwm_driver : info pwmincpaths $(PWM_PB_CFG_OBJECTS) 
$(PWM_BASE_PATH)/$(pwmpath)/obj/Pwm_17_Gtm_PBCfg.$(OBJ_FILE_SUFFIX) : $(PWM_BASE_PATH)/$(pwmpath)/src/Pwm_17_Gtm_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_PWM)  $(OUTPUT) $(PWM_BASE_PATH)/$(pwmpath)/obj/Pwm_17_Gtm_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(PWM_INC_PATHS_FILE)  $(OBJ_CREATION)  $(PWM_BASE_PATH)/$(pwmpath)/src/Pwm_17_Gtm_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(PWM_BASE_PATH)/$(pwmpath)/obj/Pwm_17_Gtm_PBCfg.ers 
 
 

print:
	@echo $(PWM_PB_CFG_OBJECTS) 

pwmincpaths: 
	@echo $(STANDARD_INCLUDE) > $(PWM_INC_PATHS_FILE)
	@echo $(PWM_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(PWM_INC_PATHS_FILE)

info: 
	@echo -------------Compiling PWM Configuration---------------
