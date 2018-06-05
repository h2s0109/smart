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
#*  FILENAME  : infineon_can_17_rules.mak                                     **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2013.02.25                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file builds the Demo of CAN Driver               **
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
#* SGN          Gururaj Nath S                                               ** 
#*                                                                           ** 
#*                                                                           ** 
#*****************************************************************************/ 
#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*
#*  V0.0.3 : 2013.02.25, SGN : Updated for AI00133871
#*  V0.0.2 : 2012.12.18, SGN : Removed the space after FF_READ for compiler 
#*                             abstraction
#*  V0.0.1 : 2012.05.10, SGN : Initial version, baselined from Audo
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(CAN_DEP_HEADERS) 
CAN_INC_PATHS_FILE = can_include_paths.ifx 
 
 
build_can_driver : info canincpaths $(CAN_DEMO_OBJECTS) 
$(CAN_BASE_PATH)/demo/obj/Can_17_MCanP_Demo.$(OBJ_FILE_SUFFIX) : $(CAN_BASE_PATH)/demo/src/Can_17_MCanP_Demo.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h $(CAN_BASE_PATH)/demo/inc/Can_17_MCanP_Demo.h $(STDTEST_BASE_PATH)/inc/CanIf_Cbk.h $(ECUM_BASE_PATH)/ssc/inc/EcuM.h  
	@"$(COMPILER)"  $(OUTPUT) $(CAN_BASE_PATH)/demo/obj/Can_17_MCanP_Demo.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(CAN_INC_PATHS_FILE)  $(OBJ_CREATION)  $(CAN_BASE_PATH)/demo/src/Can_17_MCanP_Demo.c  $(ERROR_REPORT) 
	@-rm -f $(CAN_BASE_PATH)/demo/obj/Can_17_MCanP_Demo.ers 
 
 
print: 
	@echo $(CAN_DEMO_OBJECTS) 
canincpaths: 
	@echo $(STANDARD_INCLUDE) > $(CAN_INC_PATHS_FILE) 
	@echo $(CAN_INCLUDE_PATH) >> $(CAN_INC_PATHS_FILE) 
	@echo $(CAN_DEMO_INCLUDE_PATH) >> $(CAN_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(CAN_INC_PATHS_FILE) 
	
info:  
	@echo -------------Compiling CAN Demo--------------- 
