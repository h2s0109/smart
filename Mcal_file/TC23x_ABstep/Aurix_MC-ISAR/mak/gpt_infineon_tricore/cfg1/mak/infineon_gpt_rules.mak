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
#*  FILENAME  : infineon_gpt_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.10.25                                                    **
#*                                                                            **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the GPT driver             **
#*                       Configuration Objects only                             **
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
#*  V0.0.1 : 2007.09.22, RS  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(GPT_DEP_HEADERS) 
GPT_INC_PATHS_FILE = gpt_include_paths.ifx

build_gpt_driver : info incpaths  $(GPT_PB_CFG_OBJECTS)

ifeq ($(GPT_DELIVERY_MODE),VARIANTPB_SOURCE) 
$(GPT_BASE_PATH)/$(gptpath)/obj/Gpt_PBCfg.$(OBJ_FILE_SUFFIX) : $(GPT_BASE_PATH)/$(gptpath)/src/Gpt_PBCfg.c $(headers)
	@$(COMPILE_GPT)  $(OUTPUT) $(GPT_BASE_PATH)/$(gptpath)/obj/Gpt_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(GPT_INC_PATHS_FILE) $(OBJ_CREATION)  $(GPT_BASE_PATH)/$(gptpath)/src/Gpt_PBCfg.c  $(ERROR_REPORT)
	@-rm -f $(GPT_BASE_PATH)/$(gptpath)/obj/Gpt_PBCfg.ers
endif

.PHONY: clean
clean:
	@-rm -f $(GPT_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(GPT_OBJECTS)

incpaths:
	@echo $(STANDARD_INCLUDE) > $(GPT_INC_PATHS_FILE)
	@echo $(GPT_INCLUDE_PATH) >> $(GPT_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(GPT_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(GPT_INC_PATHS_FILE)



info: 
	@echo -------------Compiling GPT Configuration---------------


