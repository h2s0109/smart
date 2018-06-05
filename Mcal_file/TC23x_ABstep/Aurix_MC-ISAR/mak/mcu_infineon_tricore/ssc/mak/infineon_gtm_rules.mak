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
#*  FILENAME  : infineon_gtm_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.5                                                         **
#*                                                                            **
#*  DATE      : 2013.07.23                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the GPT driver             **
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
#* VS           Vinod Shankar                                                **
#* SS           Srinivas Shenoy                                              **
#* DNS          Deepak Nair S                                                **
#* KP           Kaushal Purohit                                              **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.5 : 2013.07.23, KP  : File split changes and changes as per UTP 
#*                                                                  [AI00198181]
#*  V0.0.4 : 2013.02.28, DNS : VendorApiInfix changes for PWM.
#*  V0.0.3 : 2013.02.15, SS  : VendorApiInfix changes for ICU.
#*  V0.0.2 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1 : 2011.03.18, VS  : Initial version.
#*  
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
endif
ifeq ($(ICU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
endif
ifeq ($(PWM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_defs.mak
endif

ifeq ($(GPT_DELIVERY),STD_ON)
GTM_INC += gtm_gpt_inc 
endif

ifeq ($(ICU_DELIVERY),STD_ON)
GTM_INC += gtm_icu_inc 
endif

ifeq ($(PWM_DELIVERY),STD_ON)
GTM_INC += gtm_pwm_inc 
endif


#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(GTM_DEP_HEADERS) $(GPT_DEP_HEADERS) $(PWM_DEP_HEADERS) $(ICU_DEP_HEADERS) 
GTM_INC_PATHS_FILE = gtm_include_paths.ifx


build_gtm_driver : info incpaths gtm_includes $(GTM_SSC_OBJECTS) 

$(GTM_BASE_PATH)/ssc/obj/Gtm.$(OBJ_FILE_SUFFIX) : $(GTM_BASE_PATH)\ssc\src\Gtm.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(GTM_BASE_PATH)\ssc\inc\Gtm_Local.h $(GTM_BASE_PATH)\ssc\inc\Gtm_Protect.h
	@$(COMPILE_GTM) $(OUTPUT) $(GTM_BASE_PATH)\ssc\obj\Gtm.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(GTM_INC_PATHS_FILE) $(OBJ_CREATION)  $(GTM_BASE_PATH)\ssc\src\Gtm.c  $(ERROR_REPORT)
	@-rm -f $(GTM_BASE_PATH)/ssc/obj/Gtm.ers	

$(GTM_BASE_PATH)/ssc/obj/Gtm_Platform.$(OBJ_FILE_SUFFIX) : $(GTM_BASE_PATH)\ssc\src\Gtm_Platform.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(GTM_BASE_PATH)\ssc\inc\Gtm_Local.h $(GTM_BASE_PATH)\ssc\inc\Gtm_Protect.h
	@$(COMPILE_GTM) $(OUTPUT) $(GTM_BASE_PATH)\ssc\obj\Gtm_Platform.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(GTM_INC_PATHS_FILE) $(OBJ_CREATION)  $(GTM_BASE_PATH)\ssc\src\Gtm_Platform.c  $(ERROR_REPORT)
	@-rm -f $(GTM_BASE_PATH)/ssc/obj/Gtm_Platform.ers	

$(GTM_BASE_PATH)/cfg1/obj/Gtm_Lcfg.$(OBJ_FILE_SUFFIX) : $(GTM_BASE_PATH)\cfg1\src\Gtm_Lcfg.c $(headers) $(DET_FILE_PATH)/Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h 
	@$(COMPILE_GTM) $(OUTPUT) $(GTM_BASE_PATH)\cfg1\obj\Gtm_Lcfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(GTM_INC_PATHS_FILE) $(OBJ_CREATION)  $(GTM_BASE_PATH)\cfg1\src\Gtm_Lcfg.c  $(ERROR_REPORT)
	@-rm -f $(GTM_BASE_PATH)/cfg1/obj/Gtm_Lcfg.ers	


.PHONY: clean
clean:
	@-rm -f $(GTM_SSC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(GTM_SSC_OBJECTS)
	
incpaths:
	@echo $(STANDARD_INCLUDE) > $(GTM_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	@echo $(GTM_DEMO_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	

info: 
	@echo -------------Compiling GTM Module---------------
	
gtm_includes : $(GTM_INC)

gtm_gpt_inc :	
	@-echo $(GPT_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)
	
gtm_icu_inc :	
	@-echo $(ICU_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)
	

gtm_pwm_inc :	
	@-echo $(PWM_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)