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
#*  DATE      : 2012.10.31                                                    **
#*                                                                            **
#*                                                                            **                                                                            
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the DIO driver             **
#*                    configuration files only                                **
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
#* MM          Mohammed Mustaq                                              **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.3 : 2012.10.31, MM : Space after $(FF_READ) is removed
#*  V0.0.2 : 2012.10.25, AD : Module specific compile variable introduced
#*  V0.0.1 : 2012.05.22, MM : Initial version for AS321.
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

ifeq ($(DIO_DELIVERY_MODE),VARIANTPB_SOURCE)
build_dio_driver : info incpaths $(DIO_PB_CFG_OBJECTS)
endif

ifeq ($(DIO_DELIVERY_MODE),VARIANTLT_SOURCE)
build_dio_driver : info incpaths $(DIO_LT_CFG_OBJECTS)
endif

ifeq ($(DIO_DELIVERY_MODE),VARIANTPB_SOURCE)
$(DIO_BASE_PATH)/$(diopath)/obj/Dio_PBCfg.$(OBJ_FILE_SUFFIX) : $(DIO_BASE_PATH)/$(diopath)/src/Dio_PBCfg.c $(headers)
	@$(COMPILE_DIO)  $(OUTPUT) $(DIO_BASE_PATH)/$(diopath)/obj/Dio_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DIO_INC_PATHS_FILE) $(OBJ_CREATION) $(DIO_BASE_PATH)/$(diopath)/src/Dio_PBCfg.c  $(ERROR_REPORT)
	@-rm -f $(DIO_BASE_PATH)/$(diopath)/obj/Dio_PBCfg.ers
endif

ifeq ($(DIO_DELIVERY_MODE),VARIANTLT_SOURCE)
$(DIO_BASE_PATH)/$(diopath)/obj/Dio_Lcfg.$(OBJ_FILE_SUFFIX) : $(DIO_BASE_PATH)/$(diopath)/src/Dio_Lcfg.c $(headers)
	@$(COMPILE_DIO)  $(OUTPUT) $(DIO_BASE_PATH)/$(diopath)/obj/Dio_Lcfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(DIO_INC_PATHS_FILE) $(OBJ_CREATION) $(DIO_BASE_PATH)/$(diopath)/src/Dio_Lcfg.c  $(ERROR_REPORT)
	@-rm -f $(DIO_BASE_PATH)/$(diopath)/obj/Dio_Lcfg.ers
endif


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
	
info: 
	@echo -------------Compiling DIO Configuration---------------
