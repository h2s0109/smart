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
#*  FILENAME  : infineon_eth_17_ethmac_defs.mak                                     **
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
#* PB           P.Balakrishnan                                               **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.0 : 2012.03.02, PB  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(ETH_DEP_HEADERS)
ETH_INC_PATHS_FILE = eth_include_paths.ifx

build_eth_driver : info ethincpaths $(ETH_SSC_OBJECTS)

$(ETH_BASE_PATH)/ssc/obj/Eth_17_EthMac.$(OBJ_FILE_SUFFIX) : $(ETH_BASE_PATH)\ssc\src\Eth_17_EthMac.c $(headers) $(DET_FILE_PATH /Det.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h
	@$(COMPILE_WITH_CODECOV) $(OUTPUT) $(ETH_BASE_PATH)/ssc/obj/Eth_17_EthMac.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ETH_INC_PATHS_FILE) $(OBJ_CREATION)  $(ETH_BASE_PATH)\ssc\src\Eth_17_EthMac.c  $(ERROR_REPORT)
	@-rm -f $(ETH_BASE_PATH)/ssc/obj/Eth_17_EthMac.ers

.PHONY: clean
clean:
	@-rm -f $(ETH_SSC_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx

print:
	@echo $(ETH_SSC_OBJECTS)
	
ethincpaths:
	@echo $(STANDARD_INCLUDE) > $(ETH_INC_PATHS_FILE)
	@echo $(ETH_INCLUDE_PATH) >> $(ETH_INC_PATHS_FILE)


info: 
	@echo -------------Compiling ETH Module---------------

