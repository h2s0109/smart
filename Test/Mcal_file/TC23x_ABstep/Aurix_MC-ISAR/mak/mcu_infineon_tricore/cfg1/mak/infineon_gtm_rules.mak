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
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.10.25                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the GTM driver            **
#*                    Configuration objects                                    **
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
#* AD          Abhishek Dwivedi                                              ** 
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.2 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1 : 2007.09.22, RS  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak

#***************************** SPECIFIC ****************************************/
headers = $(STANDARD_DEPENDANCY) $(GTM_DEP_HEADERS) 
GTM_INC_PATHS_FILE = gtm_include_paths.ifx


build_gtm_driver : info gtmincpaths $(GTM_PB_CFG_OBJECTS) 
$(GTM_BASE_PATH)/$(gtmpath)/obj/Gtm_PBCfg.$(OBJ_FILE_SUFFIX) : $(GTM_BASE_PATH)/$(gtmpath)/src/Gtm_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_GTM)  $(OUTPUT) $(GTM_BASE_PATH)/$(gtmpath)/obj/Gtm_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(GTM_INC_PATHS_FILE)  $(OBJ_CREATION)  $(GTM_BASE_PATH)/$(gtmpath)/src/Gtm_PBCfg.c  $(ERROR_REPORT)
	@-rm -f $(GTM_BASE_PATH)/$(gtmpath)/obj/Gtm_PBCfg.ers





print:
	@echo $(GTM_PB_CFG_OBJECTS) 
	
gtmincpaths: 
	@echo $(STANDARD_INCLUDE) > $(GTM_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(GTM_INC_PATHS_FILE)
	

info: 
	@echo -------------Compiling GTM Configuration---------------
	
