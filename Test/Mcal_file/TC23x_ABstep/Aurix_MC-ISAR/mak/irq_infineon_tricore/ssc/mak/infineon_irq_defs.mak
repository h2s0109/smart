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
#*  FILENAME  : infineon_irq_defs.mak                                         **
#*                                                                            **
#*  VERSION   : 0.1.7                                                         **
#*                                                                            **
#*  DATE      : 2014-03-11                                                    **
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the standard test stub files only                 **
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
#* VS           Vinod Shankar                                                **
#* PR           Pawan Reddy                                                  **
#* AK           Ashish Kumar                                                 **
#* MSB          Manish Singh Bisht                                           **
#* AC           Apurav Chandel                                               **
#* RC           Rashmi Chadaga                                               **
#* JN           Jayaprakash Narayana                                         **
#* MK           Mundhra Karan                                                **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.1.7 : MK: Updated for HSM                                   **
#*  VERSION   : 0.1.6 : JN: Updated for I2C                                   **
#*  VERSION   : 0.1.5 : RC : Eru_Irq.c to be compiled irrespective of whether **
#*                           ERU_DELIVERY is ON or OFF but ICU_DELIVERY ON    **
#*  VERSION   : 0.1.4 : AC : Dma_Irq.c to be compiled irrespective of whether **
#*                           DMA_DELIVERY is ON or OFF                        **
#*  VERSION   : 0.1.3 : MSB : Added AscLin_Irq.c in place of Lin_Irq.c and    **
#*                            Uart_Irq.c and removed Sci_Irq.c                **
#*  VERSION   : 0.1.2 : AK: Update for SENT                                   **
#*  VERSION   : 0.1.1 : VS: Updated for CCU6x. AI00066335                     **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#******************************************************************************/

include $(SSC_ROOT)/mak/base_make.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_safetlib_defs.mak

ASCLIN_IRQ_DEL = STD_OFF
ifeq ($(UART_DELIVERY), STD_ON)
ASCLIN_IRQ_DEL = STD_ON
endif

ifeq ($(LIN_DELIVERY), STD_ON)
ASCLIN_IRQ_DEL = STD_ON
endif

ifeq ($(STDLIN_DELIVERY), STD_ON)
ASCLIN_IRQ_DEL = STD_ON
endif

IRQ_INCLUDE_PATH = $(CC_INC) $(IRQ_BASE_PATH)/ssc/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(IRQ_BASE_PATH)/cfg1/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/Common
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/Cfg/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/SafeWdgCD/SafeWdgIf/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/SafeWdgCD/SafeWdgInt/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/SafeWdgCD/SafeWdgExtTlf/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/SafeWdgCD/SafeWdgQspi/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/SafeWdgCD/SafeWdgAscLin/inc
IRQ_INCLUDE_PATH += $(CC_INC) $(SAFET_BASE_FOLDER)/SafeWdgCD/SafeWdgExtCic/inc

IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Irq.$(OBJ_FILE_SUFFIX)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Mcal_Trap.$(OBJ_FILE_SUFFIX)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Dma_Irq.$(OBJ_FILE_SUFFIX)

ifeq ($(LIN_DELIVERY),STD_ON) 
IRQ_INCLUDE_ASCLIN += $(LIN_BASE_PATH)/ssc/inc/Lin_17_AscLin.h
endif

ifeq ($(UART_DELIVERY),STD_ON) 
IRQ_INCLUDE_ASCLIN += $(UART_BASE_PATH)/ssc/inc/Uart.h
endif

ifeq ($(SPI_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Spi_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(GTM_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Gtm_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(MLI_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Mli_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(ADC_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Adc_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(FADC_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Fadc_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(FLS_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Fls_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(ICU_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Eru_Irq.$(OBJ_FILE_SUFFIX)
endif


ifeq ($(CCU_DELIVERY),STD_ON)
ifeq ($(ICU_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Ccu6_Irq.$(OBJ_FILE_SUFFIX)
endif
endif
ifeq ($(CAN_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Can_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(MSC_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Msc_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(ASCLIN_IRQ_DEL),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/AscLin_Irq.$(OBJ_FILE_SUFFIX)
endif


ifeq ($(ETH_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Eth_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(SENT_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Sent_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(HSSL_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/hssl_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(I2C_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/I2c_Irq.$(OBJ_FILE_SUFFIX)
endif

ifeq ($(HSM_DELIVERY),STD_ON)
IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Hsm_Irq.$(OBJ_FILE_SUFFIX)
endif

IRQ_OBJECTS += $(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.$(OBJ_FILE_SUFFIX)


IRQ_CLEAN_OBJECTS += $(IRQ_OBJECTS)

OBJECTS_LINK_ONLY += $(IRQ_OBJECTS)

CLEAN_ALL_OBJECTS += $(IRQ_OBJECTS)

IRQ_DEP_HEADERS = $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h 