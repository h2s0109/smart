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
#*  FILENAME  : infineon_port_rules.mak                                       **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2012.11.06                                                    **
#*                                                                            **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the PORT driver            **
#*                                configuraton file only                      **
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
#* MM          Mohammed Mustaq                                               **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.3: 2012.11.06, MM  : Updated for multi compilet support
#*  V0.0.2: 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1: 2007.09.22, RS  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak

#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(PORT_DEP_HEADERS) 
PORT_INC_PATHS_FILE = port_include_paths.ifx


build_port_driver : info portincpaths $(PORT_PB_CFG_OBJECTS) 
$(PORT_BASE_PATH)/$(portpath)/obj/Port_PBCfg.$(OBJ_FILE_SUFFIX) : $(PORT_BASE_PATH)/$(portpath)/src/Port_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_PORT)  $(OUTPUT) $(PORT_BASE_PATH)/$(portpath)/obj/Port_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(PORT_INC_PATHS_FILE)  $(OBJ_CREATION)  $(PORT_BASE_PATH)/$(portpath)/src/Port_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(PORT_BASE_PATH)/$(portpath)/obj/Port_PBCfg.ers 


print:
	@echo $(PORT_PB_CFG_OBJECTS) 

portincpaths: 
	@echo $(STANDARD_INCLUDE) > $(PORT_INC_PATHS_FILE)
	@echo $(PORT_INCLUDE_PATH) >> $(PORT_INC_PATHS_FILE)

info: 
	@echo -------------Compiling PORT Configuration---------------