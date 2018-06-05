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
#*  FILENAME  : infineon_uart_defs.mak                                         ** 
#*                                                                            ** 
#*  VERSION   : 0.1.0                                                         **
#*                                                                            ** 
#*  DATE      : 2012.09.22                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the UART driver files only			      **
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
#* DNS           Deepak Nair S                                                  **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.0 : DNS: Intial Version for Aurix                          **
#*
#******************************************************************************/
  
#***************************** REQUIRE ****************************************/ 

include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_check.mak 

#***************************** SPECIFIC ****************************************/  
UART_SSC_OBJECTS = $(UART_BASE_PATH)/ssc/obj/Uart.$(OBJ_FILE_SUFFIX) 
UART_PB_CFG_OBJECTS = $(UART_BASE_PATH)/$(uartpath)/obj/Uart_PBCfg.$(OBJ_FILE_SUFFIX) 
 
 
ifeq ($(UART_DELIVERY_MODE),VARIANTPB_SOURCE) 
UART_CLEAN_OBJECTS = $(UART_SSC_OBJECTS) 
UART_INCLUDE_PATH += $(CC_INC) "$(UART_BASE_PATH)/ssc/inc" 
UART_INCLUDE_PATH += $(CC_INC) "$(UART_BASE_PATH)/$(uartpath)/inc" 
endif 
UART_DEMO_INCLUDE_PATH += $(CC_INC) "$(UART_BASE_PATH)/demo/inc" 
 
 
ifeq ($(UART_DEMO),STD_ON) 
UART_DEMO_OBJECTS = $(UART_BASE_PATH)/demo/obj/Uart_Demo.$(OBJ_FILE_SUFFIX) 
else 
UART_DEMO_OBJECTS = 
endif 
UART_CLEAN_OBJECTS += $(UART_DEMO_OBJECTS) 
 
 
CLEAN_DRIVER_OBJECTS += $(UART_SSC_OBJECTS) 
CLEAN_DEMO_OBJECTS += $(UART_DEMO_OBJECTS) 
# Following variables are to be used by the application  
UART_DEP_HEADERS = $(UART_BASE_PATH)/ssc/inc/Uart.h $(UART_BASE_PATH)/$(uartpath)/inc/Uart_Cfg.h
