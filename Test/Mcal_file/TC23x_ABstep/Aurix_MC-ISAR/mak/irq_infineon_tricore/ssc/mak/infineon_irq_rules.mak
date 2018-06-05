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
#*  FILENAME  : infineon_irq_rules.mak                                        **
#*                                                                            **
#*  VERSION   : 0.2.2                                                         **
#*                                                                            **
#*  DATE      : 2014.03.12                                                    **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the standard test files    **
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
#* AD           Abhishek Dwivedi                                             ** 
#* AT           Angeswaran Thangaswamy                                       **
#* PR           Pawan Reddy                                                  **
#* VS           Vinod Shankar                                                **
#* RS           Roopa Sirur                                                  **
#* JV           Jaidev Venkataraman                                          **
#* SGN          Gururaj Nath S                                               **
#* RC           Rashmi Chadaga                                               **
#* AK           Ashish Kumar                                                 **
#* SK           Sai Kiran                                                    **
#* RR           Rudragouda Rudnoor                                           **
#* DNS          Deepak Nair S                                                **
#* MSB          Manish Singh Bisht                                           **
#* JN           Jayaprakash Narayana                                         **
#* MK           Mundhra	Karan                                                **
#* VP           Vasanthi P                                                   **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.2.2: 2014.03.12, VP  : Updated for STM Demo
#*  V0.2.1: 2014.03.11, MK  : Updated for HSM
#*  V0.2.0: 2013.11.29, JN  : Updated for I2C
#*  V0.1.9: 2013.09.25, RC  : Eru_Irq.c to be compiled irrespective of whether 
#*                            ERU_DELIVERY is ON or OFF but ICU_DELIVERY ON    
#*  V0.1.8: 2013.09.20, MSB : Fixed UTP:AI00157749 Added AscLin_Irq.c in place 
#*                            of Lin_Irq.c and Uart_Irq.c and removed Sci_Irq.c
#*  V0.1.7: 2013.03.11, SGN : Updated VendorApiInfix changes for CAN
#*  V0.1.6: 2013.02.25, AT  : Updated VendorApiInfix changes for FLS
#*  V0.1.5: 2013.02.21, AT  : Icu & Lin path and file names updated
#*  V0.1.4: 2012.11.26, DNS : Updated for Uart module
#*  V0.1.4: 2012.11.23, RR  : STM specific changes done: Multicompiler support
#*  V0.1.3: 2012.11.15, AT  : Adc.h included in Irq.h
#*  V0.1.2: 2012.11.11, SK  : Updated for GNU/WINDRIVER compiler
#*  V0.1.1: 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.9: 2012.09.17, AT  : Updated for WINDRIVER compiler
#*  V0.0.8: 2012.08.22, AT  : Updated for GNU compiler
#*  V0.0.7: 2012.05.10, SGN : Corrected CAN path
#*  V0.0.6: 2011.03.22, PR  : Changed ON to STD_ON
#*  V0.0.5: 2011.03.18, VS  : GTM Included
#*  V0.0.4: 2007.09.22, RS  : Added ERU.
#*  V0.0.3: 2007.06.19, RS  : Added FLS.
#*  V0.0.2: 2007.04.28, JV  : Renamed Module. Added FADC.
#*  V0.0.1: 2007.03.30, RS  : Initial version.
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/irq_infineon_tricore/ssc/mak/infineon_irq_defs.mak
IRQ_INCLUDE_MODS = 
ifeq ($(MCU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_mcu_inc
endif
ifeq ($(GTM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
IRQ_INCLUDE_DIRS += irq_gtm_inc
endif
ifeq ($(PORT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak
IRQ_INCLUDE_DIRS += irq_port_inc
endif
ifeq ($(DIO_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_defs.mak
IRQ_INCLUDE_DIRS += irq_dio_inc
endif
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
IRQ_INCLUDE_DIRS += irq_gpt_inc
endif
ifeq ($(SPI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak
IRQ_INCLUDE_DIRS += irq_spi_inc
IRQ_INCLUDE_MODS += $(SPI_DEP_HEADERS)
endif
ifeq ($(MLI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mli_infineon_tricore/ssc/mak/infineon_mli_defs.mak
IRQ_INCLUDE_DIRS += irq_mli_inc
endif
ifeq ($(ADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak
IRQ_INCLUDE_DIRS += irq_adc_inc
IRQ_INCLUDE_MODS += $(ADC_DEP_HEADERS)
endif
ifeq ($(STM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/stm_infineon_tricore/ssc/mak/infineon_stm_defs.mak
IRQ_INCLUDE_DIRS += irq_stm_inc
IRQ_INCLUDE_MODS += $(STM_DEP_HEADERS)
endif
ifeq ($(DMA_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_defs.mak
IRQ_INCLUDE_DIRS += irq_dma_inc
endif
ifeq ($(FADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fadc_infineon_tricore/ssc/mak/infineon_fadc_defs.mak
IRQ_INCLUDE_DIRS += irq_fadc_inc
endif
ifeq ($(FLS_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_defs.mak
IRQ_INCLUDE_DIRS += irq_fls_inc
endif
ifeq ($(CAN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_defs.mak
IRQ_INCLUDE_DIRS += irq_can_inc
endif
ifeq ($(MSC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_defs.mak
IRQ_INCLUDE_DIRS += irq_msc_inc
endif

ifeq ($(LIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/lin_17_asclin_infineon_tricore/ssc/mak/infineon_lin_17_asclin_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_lin_inc
IRQ_INCLUDE_MODS += $(LIN_DEP_HEADERS)
endif
ifeq ($(UART_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_uart_inc
IRQ_INCLUDE_MODS += $(UART_DEP_HEADERS)
endif

ifeq ($(ETH_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_eth_inc
endif

ifeq ($(HSSL_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_hssl_inc
endif

ifeq ($(ICU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_icu_inc
endif

ifeq ($(CCU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_icu_inc
endif

ifeq ($(SENT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_sent_inc
endif

ifeq ($(STDLIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/stdlin_infineon_tricore/ssc/mak/infineon_stdlin_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
IRQ_INCLUDE_DIRS += irq_stdlin_inc
endif
ifeq ($(I2C_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/i2c_infineon_tricore/ssc/mak/infineon_i2c_defs.mak
IRQ_INCLUDE_DIRS += irq_i2c_inc
IRQ_INCLUDE_MODS += $(I2C_DEP_HEADERS)
endif

ifeq ($(HSM_DELIVERY),STD_ON)
include $(SSC_HSM_ROOT)/mak/hsm_infineon_tricore/ssc/mak/infineon_hsm_defs.mak
IRQ_INCLUDE_DIRS += irq_hsm_inc
IRQ_INCLUDE_MODS += $(HSM_DEP_HEADERS)
endif

headers = $(STANDARD_DEPENDANCY) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DEM_FILE_PATH)/Dem.h 

IRQ_INC_PATHS_FILE = irq_include_path.ifx


build_std_test_driver : info intincpaths printer $(IRQ_OBJECTS) printer_clean

printer: $(IRQ_INCLUDE_DIRS)

irq_mcu_inc:	
	@-echo $(IRQ_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(MCU_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)	

irq_gtm_inc:
	@-echo $(GTM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_port_inc:
	@-echo $(PORT_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_dio_inc:
	@-echo $(DIO_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	
irq_gpt_inc:
	@-echo $(GPT_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	
irq_spi_inc:	
	@-echo $(SPI_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_mli_inc:	
	@-echo $(MLI_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_adc_inc:	
	@-echo $(ADC_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
irq_stm_inc:	
	@-echo $(STM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_dma_inc:	
	@-echo $(DMA_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_fadc_inc:	
	@-echo $(FADC_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_fls_inc:	
	@-echo $(FLS_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_icu_inc:	
	@-echo $(ICU_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	
irq_can_inc:	
	@-echo $(CAN_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_msc_inc:	
	@-echo $(MSC_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

	
irq_eth_inc:
	@-echo $(ETH_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_hssl_inc:
	@-echo $(HSSL_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_lin_inc:
	@-echo $(LIN_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_uart_inc:
	@-echo $(UART_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_stdlin_inc:
	@-echo $(STDLIN_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_sent_inc:
	@-echo $(SENT_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	@-echo $(ECUM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	
irq_hsm_inc:	
	@-echo $(HSM_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)

irq_i2c_inc:	
	@-echo $(I2C_INCLUDE_PATH) >> $(IRQ_INC_PATHS_FILE)
	
  
$(IRQ_BASE_PATH)/ssc/obj/Mcal_Trap.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Mcal_Trap.c $(headers) $(STDTEST_BASE_PATH)/inc/Test_Print.h $(MCU_DEP_HEADERS) $(MCU_BASE_PATH)/ssc/inc/Mcu.h
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Mcal_Trap.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Mcal_Trap.c $(ERROR_REPORT) 
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Mcal_Trap.ers


$(IRQ_BASE_PATH)/ssc/obj/Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(IRQ_INCLUDE_MODS)
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Irq.c $(ERROR_REPORT) 
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Gtm_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Gtm_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(GTM_BASE_PATH)/ssc/inc/Gtm.h 
	@$(COMPILE_GTM) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Gtm_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION)  $(IRQ_BASE_PATH)/ssc/src/Gtm_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Gtm_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Spi_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Spi_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(SPI_BASE_PATH)/ssc/inc/Spi.h 
	@$(COMPILE_SPI) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Spi_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION)  $(IRQ_BASE_PATH)/ssc/src/Spi_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Spi_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Mli_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Mli_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(MLI_BASE_PATH)/ssc/inc/Mli.h 
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Mli_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Mli_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Mli_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Adc_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Adc_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(ADC_BASE_PATH)/ssc/inc/Adc.h
	@$(COMPILE_ADC) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Adc_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Adc_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Adc_Irq.ers
 
ifeq ($(STM_DELIVERY),STD_ON) 
$(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Stm_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(STM_BASE_PATH)/ssc/inc/Stm.h
	@$(COMPILE_STM) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) -DSTM_DEMO_ON $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Stm_Irq.c  $(ERROR_REPORT) 
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.ers  
else
$(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Stm_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(STDTEST_BASE_PATH)/inc/Test_Time.h
	@$(COMPILE_STM) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Stm_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Stm_Irq.ers 
endif
 
$(IRQ_BASE_PATH)/ssc/obj/Dma_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Dma_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h 
	@$(COMPILE_DMA) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Dma_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Dma_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Dma_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Fadc_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Fadc_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(FADC_BASE_PATH)/ssc/inc/Fadc.h
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Fadc_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Fadc_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Fadc_Irq.ers


$(IRQ_BASE_PATH)/ssc/obj/Fls_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Fls_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(FLS_BASE_PATH)/ssc/inc/Fls_17_Pmu.h
	@$(COMPILE_FLS) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Fls_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Fls_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Fls_Irq.ers


$(IRQ_BASE_PATH)/ssc/obj/Eru_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Eru_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Eru_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Eru_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Eru_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Can_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Can_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(CAN_BASE_PATH)/ssc/inc/Can_17_MCanP.h
	@$(COMPILE_CAN) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Can_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Can_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Can_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Msc_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Msc_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(MSC_BASE_PATH)/ssc/inc/Msc.h
	@$(COMPILE_MSC) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Msc_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Msc_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Msc_Irq.ers

	
$(IRQ_BASE_PATH)/ssc/obj/AscLin_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/AscLin_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(IRQ_INCLUDE_ASCLIN)
	@$(COMPILE_LIN) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/AscLin_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/AscLin_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/AscLin_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Eth_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Eth_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(ETH_BASE_PATH)/ssc/inc/Eth_17_EthMac.h
	@$(COMPILE_ETH) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Eth_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Eth_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Eth_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/hssl_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/hssl_irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(HSSL_BASE_PATH)/ssc/inc/Hssl.h
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/hssl_irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/hssl_irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/hssl_irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Ccu6_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Ccu6_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Ccu6_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Ccu6_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Ccu6_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/Sent_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Sent_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(SENT_BASE_PATH)/ssc/inc/Sent.h
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Sent_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION) $(IRQ_BASE_PATH)/ssc/src/Sent_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Sent_Irq.ers

$(IRQ_BASE_PATH)/ssc/obj/I2c_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/I2c_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(I2C_BASE_PATH)/ssc/inc/I2c.h 
	@$(COMPILE_I2C) $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/I2c_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION)  $(IRQ_BASE_PATH)/ssc/src/I2c_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/I2c_Irq.ers
	

$(IRQ_BASE_PATH)/ssc/obj/Hsm_Irq.$(OBJ_FILE_SUFFIX) : $(IRQ_BASE_PATH)/ssc/src/Hsm_Irq.c $(headers) $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h $(HSM_BASE_PATH)/ssc/inc/Hsm.h 
	@"$(COMPILER)" $(OUTPUT) $(IRQ_BASE_PATH)/ssc/obj/Hsm_Irq.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(IRQ_INC_PATHS_FILE) $(OBJ_CREATION)  $(IRQ_BASE_PATH)/ssc/src/Hsm_Irq.c  $(ERROR_REPORT)
	@-rm -f $(IRQ_BASE_PATH)/ssc/obj/Hsm_Irq.ers

.PHONY: std_clean

std_clean:
	@-rm -f *.err

printer_clean:
	@-rm -f $(IRQ_INC_PATHS_FILE)
	
intincpaths:
	@echo $(STANDARD_INCLUDE) > $(IRQ_INC_PATHS_FILE)
		
info: 
	@echo -------------Compiling IRQ Module---------------
	
