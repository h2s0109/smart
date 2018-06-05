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
#*  FILENAME  : infineon_sent_rules.mak   		                              **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2012.10.31                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the SENT driver            **
#*                    demo objects only                                       **
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
#* AK           Ashish Kumar   			                                     **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.2 : 2012.10.31, AK  : Support for GNU and WINDRIVER compiler
#*  V0.0.1 : 2012.10.22, AK  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak
include $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_defs.mak
#***************************** SPECIFIC ****************************************/
headers = $(STANDARD_DEPENDANCY) $(SENT_DEP_HEADERS)
SENT_INC_PATHS_FILE = sent_include_paths.ifx

build_sent_driver : info incpaths $(SENT_DEMO_OBJECTS)


$(SENT_BASE_PATH)/demo/obj/Sent_Demo.$(OBJ_FILE_SUFFIX) : $(SENT_BASE_PATH)/demo/src/Sent_Demo.c $(headers)
	@$(COMPILE_SENT) $(OUTPUT) $(SENT_BASE_PATH)/demo/obj/Sent_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(SENT_INC_PATHS_FILE)  $(OBJ_CREATION)  $(SENT_BASE_PATH)/demo/src/Sent_Demo.c  $(ERROR_REPORT)
	@-rm -f $(SENT_BASE_PATH)/demo/obj/Sent_Demo.ers


.PHONY: clean
clean:
	@-rm -f $(SENT_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

print:
	@echo $(SENT_OBJECTS)

incpaths:
	@echo $(STANDARD_INCLUDE) > $(SENT_INC_PATHS_FILE)
	@echo $(SENT_INCLUDE_PATH) >> $(SENT_INC_PATHS_FILE)
	@echo $(SENT_DEMO_INCLUDE_PATH) >> $(SENT_INC_PATHS_FILE)
	@echo $(PORT_INCLUDE_PATH) >> $(SENT_INC_PATHS_FILE)

	
info: 
	@echo -------------Compiling SENT Demo--------------
