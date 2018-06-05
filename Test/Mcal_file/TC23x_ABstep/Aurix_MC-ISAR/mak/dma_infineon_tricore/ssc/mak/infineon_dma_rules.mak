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
#*  FILENAME  : infineon_dma_rules.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.3                                                         ** 
#*                                                                            ** 
#*  DATE      : 2013.10.03                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the DMA Driver                       ** 
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
#* AC          Apurav Chandel                                                ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2013.03.11, AC  : Initial Version.                              **
#*  V0.0.2 : 2013.09.30. AC  : updated for Dma_Callout_Stubs.c file          **
#*  V0.0.3 : 2013.10.03. AC  : Removed Dma_Callout_Stubs.c file              **
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_defs.mak 
#***************************** SPECIFIC ***************************************/  
headers = $(STANDARD_DEPENDANCY) $(DMA_DEP_HEADERS) 
DMA_INC_PATHS_FILE = dma_include_paths.ifx 
 
 
build_dma_driver : info dmaincpaths $(DMA_SSC_OBJECTS) 
$(DMA_BASE_PATH)/ssc/obj/Dma.$(OBJ_FILE_SUFFIX) : $(DMA_BASE_PATH)/ssc/src/Dma.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h $(DMA_BASE_PATH)\ssc\inc\Dma_Protect.h
	@$(COMPILE_DMA) $(OUTPUT) $(DMA_BASE_PATH)/ssc/obj/Dma.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DMA_INC_PATHS_FILE)  $(OBJ_CREATION)  $(DMA_BASE_PATH)\ssc\src\Dma.c  $(ERROR_REPORT) 
	@-rm -f $(DMA_BASE_PATH)/ssc/obj/Dma.ers 
 
 
print: 
	@echo $(DMA_SSC_OBJECTS) 
dmaincpaths: 
	@echo $(STANDARD_INCLUDE) > $(DMA_INC_PATHS_FILE) 
	@echo $(DMA_INCLUDE_PATH) >> $(DMA_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling DMA Module--------------- 
