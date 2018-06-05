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
#*  FILENAME  : infineon_spi_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.10.25                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the SPI driver             **
#*                   configuration files only                                 **
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
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(SPI_DEP_HEADERS)
SPI_INC_PATHS_FILE = spi_include_paths.ifx 


build_spi_driver : info spiincpaths $(SPI_PB_CFG_OBJECTS) 
$(SPI_BASE_PATH)/$(spipath)/obj/Spi_PBCfg.$(OBJ_FILE_SUFFIX) : $(SPI_BASE_PATH)/$(spipath)/src/Spi_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_SPI)  $(OUTPUT) $(SPI_BASE_PATH)/$(spipath)/obj/Spi_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(SPI_INC_PATHS_FILE)  $(OBJ_CREATION)  $(SPI_BASE_PATH)/$(spipath)/src/Spi_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(SPI_BASE_PATH)/$(spipath)/obj/Spi_PBCfg.ers 

print:
	@echo $(SPI_PB_CFG_OBJECTS) 

spiincpaths: 
	@echo $(STANDARD_INCLUDE) > $(SPI_INC_PATHS_FILE)
	@echo $(SPI_INCLUDE_PATH) >> $(SPI_INC_PATHS_FILE)
info: 
	@echo -------------Compiling SPI Configuration---------------