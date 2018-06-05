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
#*  FILENAME  : infineon_dio_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2007.09.19                                                    **
#*                                                                            **
#*                                                                            **                                                                            
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the DIO driver             **
#*                              demo objects only                               **
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
#*  V0.0.1:  2007.09.19, RS  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_defs.mak


#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(DIO_DEP_HEADERS) 
DIO_INC_PATHS_FILE = dio_include_paths.ifx 

build_dio_driver : info incpaths $(DIO_DEMO_OBJECTS)


$(DIO_BASE_PATH)/demo/obj/Dio_Demo.$(OBJ_FILE_SUFFIX) : $(DIO_BASE_PATH)/demo/src/Dio_Demo.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(DIO_BASE_PATH)/demo/obj/Dio_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DIO_INC_PATHS_FILE) $(OBJ_CREATION) $(DIO_BASE_PATH)/demo/src/Dio_Demo.c  $(ERROR_REPORT)
	@-rm -f $(DIO_BASE_PATH)/demo/obj/Dio_Demo.ers


.PHONY: clean
clean:
	@-rm -f $(DIO_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(DIO_OBJECTS)
incpaths:
	@echo $(STANDARD_INCLUDE) > $(DIO_INC_PATHS_FILE)
	@echo $(DIO_INCLUDE_PATH) >> $(DIO_INC_PATHS_FILE)
	@echo $(DIO_DEMO_INCLUDE_PATH) >> $(DIO_INC_PATHS_FILE)

info: 
	@echo -------------Compiling DIO Demo---------------
