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
#*  FILENAME  : infineon_eth_17_rules.mak                                     **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.03.02                                                    **
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
#* PB          Balakrishnan                                                  **
#*                                                  **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  
#*  V0.0.1 : 2012.03.02, PB  : Initial Version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(ETH_DEP_HEADERS)
ETH_INC_PATHS_FILE = eth_include_paths.ifx

build_eth_driver : info ethincpaths $(ETH_DEMO_OBJECTS)

$(ETH_BASE_PATH)/demo/obj/Eth_17_EthMac_Demo.$(OBJ_FILE_SUFFIX) : $(ETH_BASE_PATH)/demo/src/Eth_17_EthMac_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(ETH_BASE_PATH)/demo/obj/Eth_17_EthMac_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ETH_INC_PATHS_FILE) $(OBJ_CREATION)  $(ETH_BASE_PATH)/demo/src/Eth_17_EthMac_Demo.c  $(ERROR_REPORT)
	@-rm -f $(ETH_BASE_PATH)/demo/obj/Eth_17_EthMac_Demo.ers	

.PHONY: clean
clean:
	@-rm -f $(ETH_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(ETH_OBJECTS)
	
ethincpaths:
	@echo $(STANDARD_INCLUDE) > $(ETH_INC_PATHS_FILE)
	@echo $(ETH_INCLUDE_PATH) >> $(ETH_INC_PATHS_FILE)
	@echo $(ETH_DEMO_INCLUDE_PATH) >> $(ETH_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(ETH_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(ETH_INC_PATHS_FILE)

info: 
	@echo -------------Compiling ETH Demo---------------

