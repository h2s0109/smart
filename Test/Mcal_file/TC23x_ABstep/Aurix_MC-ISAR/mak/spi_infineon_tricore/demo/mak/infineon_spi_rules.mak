#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2007)                                 **
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
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2007.09.22                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the SPI driver             **
#*                   demo objects only                                        **
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
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2007.09.22, RS  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(SPI_DEP_HEADERS)
SPI_INC_PATHS_FILE = spi_include_paths.ifx 

build_spi_driver : info incpaths $(SPI_DEMO_OBJECTS)

$(SPI_BASE_PATH)/demo/obj/Spi_Demo.$(OBJ_FILE_SUFFIX) : $(SPI_BASE_PATH)/demo/src/Spi_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(SPI_BASE_PATH)/demo/obj/Spi_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(SPI_INC_PATHS_FILE) $(OBJ_CREATION)  $(SPI_BASE_PATH)/demo/src/Spi_Demo.c  $(ERROR_REPORT)
	@-rm -f $(SPI_BASE_PATH)/demo/obj/Spi_Demo.ers


.PHONY: clean
clean:
	@-rm -f $(SPI_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(SPI_OBJECTS)

incpaths:
	@echo $(STANDARD_INCLUDE) > $(SPI_INC_PATHS_FILE)
	@echo $(SPI_INCLUDE_PATH) >> $(SPI_INC_PATHS_FILE)
	@echo $(SPI_DEMO_INCLUDE_PATH) >> $(SPI_INC_PATHS_FILE)
	@echo $(MCU_INCLUDE_PATH) >> $(SPI_INC_PATHS_FILE)

info: 
	@echo -------------Compiling SPI Demo---------------