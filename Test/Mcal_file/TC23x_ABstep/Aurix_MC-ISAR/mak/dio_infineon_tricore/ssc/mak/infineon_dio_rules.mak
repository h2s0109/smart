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
#*  FILENAME  : infineon_dio_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2012.10.25                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the DIO driver             **
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
#* MM          Mohammed Mustaq                                               **
#* AD          Abhishek Dwivedi                                              **
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.4 : 2012.10.31, MM  : Removed the space after $(FF_READ),
#*                               as part of compiler changes
#*  V0.0.3 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.2:  2007.09.19, RS  : Updated as per the concept of loadable and
#*                               selectable.
#*  V0.0.1:  2007.02.23, RS  : Initial version.
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

build_dio_driver : info incpaths $(DIO_SSC_OBJECTS)


$(DIO_BASE_PATH)/ssc/obj/Dio.$(OBJ_FILE_SUFFIX) : $(DIO_BASE_PATH)\ssc\src\Dio.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h
	@$(COMPILE_DIO) $(OUTPUT) $(DIO_BASE_PATH)/ssc/obj/Dio.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DIO_INC_PATHS_FILE) $(OBJ_CREATION) $(DIO_BASE_PATH)\ssc\src\Dio.c  $(ERROR_REPORT)
	@-rm -f $(DIO_BASE_PATH)/ssc/obj/Dio.ers

$(DIO_BASE_PATH)/ssc/obj/Dio_Ver.$(OBJ_FILE_SUFFIX) : $(DIO_BASE_PATH)\ssc\src\Dio_Ver.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h
	@$(COMPILE_DIO) $(OUTPUT) $(DIO_BASE_PATH)/ssc/obj/Dio_Ver.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DIO_INC_PATHS_FILE) $(OBJ_CREATION) $(DIO_BASE_PATH)\ssc\src\Dio_Ver.c  $(ERROR_REPORT)
	@-rm -f $(DIO_BASE_PATH)/ssc/obj/Dio_Ver.ers

#.PHONY: clean
#clean:
#	@-rm -f $(DIO_OBJECTS)

#.PHONY: wipe
#wipe:
#	@-rm -f *.src
#	@-rm -f *.err

print:
	@echo $(DIO_OBJECTS)
incpaths:
	@echo $(STANDARD_INCLUDE) > $(DIO_INC_PATHS_FILE)
	@echo $(DIO_INCLUDE_PATH) >> $(DIO_INC_PATHS_FILE)

info:
	@echo -------------Compiling DIO Module---------------
