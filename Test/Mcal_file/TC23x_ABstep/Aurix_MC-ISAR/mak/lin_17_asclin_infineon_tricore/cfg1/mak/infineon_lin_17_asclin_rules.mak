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
#*  FILENAME  : infineon_lin_17_AscLin_rules.mak                              **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2013.2.21                                                     **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file builds the LIN Driver                       **
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
#* AD          Abhishek Dwivedi                                              ** 
#* KP          Kaushal Purohit                                               ** 
#* CKP     Chaithanya Kumar Pokala                                           **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.3 : 2013.2.21,  KP  : VendorApiInfix changes added for LIN.
#*  V0.0.2 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.1: 2009.01.30, CKP  : Initial version.
#*
#******************************************************************************/
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(LIN_DEP_HEADERS) 
LIN_INC_PATHS_FILE = lin_include_paths.ifx 
 
 
build_lin_driver : info linincpaths $(LIN_PB_CFG_OBJECTS) 
$(LIN_BASE_PATH)/$(linpath)/obj/Lin_17_AscLin_PBCfg.$(OBJ_FILE_SUFFIX) : $(LIN_BASE_PATH)/$(linpath)/src/Lin_17_AscLin_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_LIN)  $(OUTPUT) $(LIN_BASE_PATH)/$(linpath)/obj/Lin_17_AscLin_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(LIN_INC_PATHS_FILE)  $(OBJ_CREATION)  $(LIN_BASE_PATH)/$(linpath)/src/Lin_17_AscLin_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(LIN_BASE_PATH)/$(linpath)/obj/Lin_17_AscLin_PBCfg.ers 
 
 
print: 
	@echo $(LIN_PB_CFG_OBJECTS) 
linincpaths: 
	@echo $(STANDARD_INCLUDE) > $(LIN_INC_PATHS_FILE) 
	@echo $(LIN_INCLUDE_PATH) >> $(LIN_INC_PATHS_FILE) 
	@echo $(ECUM_INCLUDE_PATH) >> $(LIN_INC_PATHS_FILE)
info:  
	@echo -------------Compiling LIN Configuration--------------- 
