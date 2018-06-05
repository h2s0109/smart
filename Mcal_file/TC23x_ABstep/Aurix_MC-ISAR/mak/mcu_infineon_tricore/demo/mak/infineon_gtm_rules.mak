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
#*  FILENAME  : infineon_gtm_rules.mak                                       **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2013.02.15                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the GTM driver            **
#*                   Demo objects only                                        **
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
#* RS           Roopa Sirur                                                  **
#* SS          Srinivas Shenoy                                               ** 
#* DNS         Deepak Nair S                                                 ** 
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.3 : 2013-02-15, DNS : PWM changes for VendorApiInfix
#*  V0.0.2 : 2013-02-15, SS  : ICU changes for VendorApiInfix
#*  V0.0.1 : 2007.09.22, RS  : Initial version.
#*                             
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
endif
ifeq ($(ICU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
endif
ifeq ($(PWM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_defs.mak
endif

GTM_INC += gtm_port_inc

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

headers = $(STANDARD_DEPENDANCY) $(GTM_DEP_HEADERS) $(GPT_DEP_HEADERS) $(PWM_DEP_HEADERS) $(ICU_DEP_HEADERS) $(SPI_DEP_HEADERS)
GTM_INC_PATHS_FILE = gtm_include_paths.ifx


build_gtm_driver : info incpaths gtm_includes  $(GTM_DEMO_OBJECTS)

$(GTM_BASE_PATH)/demo/obj/Gtm_Demo.$(OBJ_FILE_SUFFIX) : $(GTM_BASE_PATH)/demo/src/Gtm_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(GTM_BASE_PATH)/demo/obj/Gtm_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(GTM_INC_PATHS_FILE) $(OBJ_CREATION) $(GTM_BASE_PATH)/demo/src/Gtm_Demo.c  $(ERROR_REPORT)
	@-rm -f $(GTM_BASE_PATH)/demo/obj/Gtm_Demo.ers



.PHONY: clean
clean:
	@-rm -f $(GTM_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(GTM_OBJECTS)
	
incpaths:
	@echo $(STANDARD_INCLUDE) > $(GTM_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	@echo $(GTM_DEMO_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	

info: 
	@echo -------------Compiling GTM Demo---------------
	
gtm_includes : $(GTM_INC)

gtm_gpt_inc :	
	@-echo $(GPT_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)
	
gtm_icu_inc :	
	@-echo $(ICU_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)
	
gtm_spi_inc :	
	@-echo $(SPI_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)
	
gtm_pwm_inc :	
	@-echo $(PWM_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)

gtm_port_inc :	
	@-echo $(PORT_INCLUDE_PATH) >>  $(GTM_INC_PATHS_FILE)	