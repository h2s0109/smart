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
#*  FILENAME  : infineon_uart_rules.mak                                       **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2012.09.22                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file builds the UART Driver                      **
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
#* DNS     Deepak Nair S                                                     **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1: 2012.09.22, DNS  : Initial version.
#*
#******************************************************************************/
 
 
 
 
#***************************** REQUIRE ****************************************/
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 

include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_defs.mak 
#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(UART_DEP_HEADERS) 
UART_INC_PATHS_FILE = uart_include_paths.ifx 
 
 
build_uart_driver : info uartincpaths $(UART_PB_CFG_OBJECTS) 
$(UART_BASE_PATH)/$(uartpath)/obj/Uart_PBCfg.$(OBJ_FILE_SUFFIX) : $(UART_BASE_PATH)/$(uartpath)/src/Uart_PBCfg.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_UART)  $(OUTPUT) $(UART_BASE_PATH)/$(uartpath)/obj/Uart_PBCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(UART_INC_PATHS_FILE)  $(OBJ_CREATION)  $(UART_BASE_PATH)/$(uartpath)/src/Uart_PBCfg.c  $(ERROR_REPORT) 
	@-rm -f $(UART_BASE_PATH)/$(uartpath)/obj/Uart_PBCfg.ers 
 


 
print: 
	@echo $(UART_PB_CFG_OBJECTS) 
uartincpaths: 
	@echo $(STANDARD_INCLUDE) > $(UART_INC_PATHS_FILE) 
	@echo $(UART_INCLUDE_PATH) >> $(UART_INC_PATHS_FILE) 
	
info:  
	@echo -------------Compiling UART Configuration--------------- 
