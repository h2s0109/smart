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
#*  FILENAME  : infineon_integration_general_rules.mak                        **
#*                                                                            **
#*  VERSION   : 0.2.1                                                         **
#*                                                                            **
#*  DATE      : 2013-09-24                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the standard test files    **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/
#*******************************************************************************
#*                      Author(s) Identity                                    **
#*******************************************************************************
#*                                                                            **
#* Initials     Name                                                          **
#* ---------------------------------------------------------------------------**
#* AT          Angeswaran Thangaswamy                                         **
#* PR          Pawan Reddy                                                    **
#* RS          Roopa Sirur                                                    **
#* Prakash     Prakash Gudnavar                                               **
#* Rutuja      Rutuja Kawathekar                                              **
#* SGN         Gururaj Nath S                                                 **
#* AK          Ashish Kumar                                                   **
#* PM          Puneetha Mukherjee                                             **
#* KP          Kaushal Purohit                                                **
#* MM          Mohammed Mustaq                                                **
#* RK          Rutuja Kawathekar                                              **
#* AC          Apurav Chandel                                                 **
#* JP          Jayaprakash Narayana                                           **
#******************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.2.1: 2013.11.29, JP:   Added support for I2C
#*  V0.2.0: 2013.10.01, AC:   Added support for DMA
#*  V0.1.9: 2013.09.24, RK:   Added support for SMU
#*  V0.1.8: 2013.03.19, KP:   Renamed "SchM_Lin.h" to "SchM_Lin_17_AscLin.h"
#*  V0.1.7: 2013.03.08, BM:   Renamed "SchM_Wdg.h" to "SchM_Wdg_17_Scu.h"
#*  V0.1.6: 2013.03.01, MM:   Renamed "SchM_Icu.h" to "SchM_Icu_17_GtmCcu6.h"
#*  V0.1.5: 2013.02.25, Vani: Updated for VendorApiInfix for FLS
#*  V0.1.4: 2013.02.25, SGN: Updated for VendorApiInfix for CAN
#*  V0.1.3: 2013.02.21, KP: added VendorApiInfix support for LIN
#*  V0.1.2: 2012.10.19, PB: Update for ETH Callback
#*  V0.1.0: 2012.10.19, AK: Update for SENT callout
#*  V0.0.9: 2012.09.17, AT : Updated for GNU/WINDRIVER compiler
#*  v0.0.8: 2012.05.10, SGN: Corrected CAN path
#*  v0.0.7: 2011.03.22, PR : Updated ON to STD_ON
#*  v0.0.6: 2008.30.01, BM : Added CanIf_Cbk object suffix
#*  v0.0.5: 2007.12.03, Rutuja  : Added support for Mchk
#*  v0.0.4: 2007.11.28, Rutuja  : Added support for Msc,Sci
#*  V0.0.3: 2007.11.05, Prakash  : Added support for CanIf stub
#*  V0.0.2: 2007.06.19, RS  : Added FEE, FLS
#*  V0.0.1: 2007.02.23, RS  : Initial version.
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/irq_infineon_tricore/ssc/mak/infineon_irq_defs.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_general_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
ifeq ($(MCU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak
STDTEST_INCLUDE_DIRS += std_mcu_inc
endif
ifeq ($(HSSL_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_defs.mak
STDTEST_INCLUDE_DIRS += std_hssl_inc
endif
ifeq ($(PORT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak
STDTEST_INCLUDE_DIRS += std_port_inc
endif
ifeq ($(DIO_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_defs.mak
STDTEST_INCLUDE_DIRS += std_dio_inc
endif
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
STDTEST_INCLUDE_DIRS += std_gpt_inc
endif
ifeq ($(SPI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak
STDTEST_INCLUDE_DIRS += std_spi_inc
endif
ifeq ($(CAN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_defs.mak
STDTEST_INCLUDE_DIRS += std_can_inc
endif
ifeq ($(ETH_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_defs.mak
STDTEST_INCLUDE_DIRS += std_eth_inc
endif
ifeq ($(FEE_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fee_infineon_tricore/ssc/mak/infineon_fee_defs.mak
STDTEST_INCLUDE_DIRS += std_fee_inc
endif
ifeq ($(FLS_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_defs.mak
STDTEST_INCLUDE_DIRS += std_fls_inc
endif
ifeq ($(MSC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_defs.mak
STDTEST_INCLUDE_DIRS += std_msc_inc
endif
ifeq ($(SCI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sci_infineon_tricore/ssc/mak/infineon_sci_defs.mak
STDTEST_INCLUDE_DIRS += std_sci_inc
endif
ifeq ($(MCHK_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mchk_infineon_tricore/ssc/mak/infineon_mchk_defs.mak
STDTEST_INCLUDE_DIRS += std_mchk_inc
endif
ifeq ($(ADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak
STDTEST_INCLUDE_DIRS += std_adc_inc
endif

ifeq ($(CANTRCV_6251G_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251g_defs.mak
STDTEST_INCLUDE_DIRS += std_cantrcv6251G_inc
endif

ifeq ($(CANTRCV_6250GV33_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/ssc/mak/infineon_cantrcv_17_6250gv33_defs.mak
STDTEST_INCLUDE_DIRS += std_cantrcv6250GV33_inc
endif

ifeq ($(FLSLOADER_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_defs.mak
STDTEST_INCLUDE_DIRS += std_flsloader_inc
endif

ifeq ($(SENT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_defs.mak
STDTEST_INCLUDE_DIRS += std_sent_inc
endif

ifeq ($(DMA_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_defs.mak
STDTEST_INCLUDE_DIRS += std_dma_inc
endif

ifeq ($(IOM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/iom_infineon_tricore/ssc/mak/infineon_iom_defs.mak
STDTEST_INCLUDE_DIRS += std_iom_inc
endif

ifeq ($(LIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_defs.mak
STDTEST_INCLUDE_DIRS += std_lin_inc
endif

ifeq ($(UART_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_defs.mak
STDTEST_INCLUDE_DIRS += std_uart_inc
endif

ifeq ($(STDLIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/stdlin_infineon_tricore/ssc/mak/infineon_stdlin_defs.mak
STDTEST_INCLUDE_DIRS += std_stdlin_inc
endif

ifeq ($(SMU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/smu_infineon_tricore/ssc/mak/infineon_smu_defs.mak
STDTEST_INCLUDE_DIRS += std_smu_inc
endif

ifeq ($(I2C_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/i2c_infineon_tricore/ssc/mak/infineon_i2c_defs.mak
STDTEST_INCLUDE_DIRS += std_i2c_inc
endif

headers = $(STANDARD_DEPENDANCY) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DEM_FILE_PATH)/Dem.h

STDTEST_INC_PATHS_FILE = stdtest_include_path.ifx


build_std_test_driver : info stdincpaths printer $(STDTEST_OBJECTS) printer_clean

printer: $(STDTEST_INCLUDE_DIRS)

std_mcu_inc:
	@-echo $(IRQ_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)
	@-echo $(MCU_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_hssl_inc:
	@-echo $(IRQ_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)
	@-echo $(HSSL_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_port_inc:
	@-echo $(PORT_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_dio_inc:
	@-echo $(DIO_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_gpt_inc:
	@-echo $(GPT_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_spi_inc:
	@-echo $(SPI_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_lin_inc:
	@-echo $(LIN_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_uart_inc:
	@-echo $(UART_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_can_inc:
	@-echo $(CAN_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_eth_inc:
	@-echo $(ETH_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_cantr_inc:
	@-echo $(CANTRCV_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_fee_inc:
	@-echo $(FEE_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_fls_inc:
	@-echo $(FLS_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_sci_inc:
	@-echo $(SCI_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_msc_inc:
	@-echo $(MSC_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_mchk_inc:
	@-echo $(MCHK_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_flsloader_inc:
	@-echo $(FLSLOADER_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_sent_inc:
	@-echo $(SENT_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)
	@-echo $(SENT_DEMO_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_dma_inc:
	@-echo $(DMA_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)
	
std_iom_inc:
	@-echo $(IOM_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)
	@-echo $(IOM_DEMO_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_adc_inc:
	@-echo $(ADC_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_cantrcv6251G_inc:
	@-echo $(CANTRCV_17_6251G_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_cantrcv6250GV33_inc:
	@-echo $(CANTRCV_17_6250GV33_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_stdlin_inc:
	@-echo $(STDLIN_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_smu_inc:
	@-echo $(SMU_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

std_i2c_inc:
	@-echo $(I2C_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

$(STDTEST_BASE_PATH)/obj/Test_Print.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Test_Print.c $(headers) $(STDTEST_BASE_PATH)/inc/Test_Print.h $(STDTEST_BASE_PATH)/inc/Test_Time.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Test_Print.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/Test_Print.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Test_Print.ers

$(STDTEST_BASE_PATH)/obj/Test_Time.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Test_Time.c $(headers) $(STDTEST_BASE_PATH)/inc/Test_Time.h $(IRQ_BASE_PATH)/ssc/inc/Irq.h $(IRQ_BASE_PATH)/cfg1/inc/Irq_Cfg.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Test_Time.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/Test_Time.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Test_Time.ers

$(STDTEST_BASE_PATH)/obj/SafetyReport.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/SafetyReport.c $(headers) $(STDTEST_BASE_PATH)/inc/SafetyReport.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/SafetyReport.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/SafetyReport.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/SafetyReport.ers
  
ifeq ($(DEM_DELIVERY),STD_ON)
$(STDTEST_BASE_PATH)/obj/Dem.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Dem.c $(headers) $(STDTEST_BASE_PATH)/inc/Dem.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Dem.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/Dem.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Dem.ers
endif

$(STDTEST_BASE_PATH)/obj/Os.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Os.c $(headers) $(STDTEST_BASE_PATH)/inc/Os.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Os.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE)  $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/Os.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Os.ers


$(STDTEST_BASE_PATH)/obj/OsStub.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/OsStub.c $(headers) $(STDTEST_BASE_PATH)/inc/McalOsConfig.h $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/OsStub.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE)  $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/OsStub.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/OsStub.ers

$(STDTEST_BASE_PATH)/obj/Det.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Det.c $(headers) $(STDTEST_BASE_PATH)/inc/Det.h $(STDTEST_BASE_PATH)/inc/Test_Print.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Det.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/Det.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Det.ers

$(STDTEST_BASE_PATH)/obj/SchM.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/SchM.c $(headers) $(STDTEST_BASE_PATH)/inc/SchM_Adc.h $(STDTEST_BASE_PATH)/inc/SchM_Icu_17_GtmCcu6.h $(STDTEST_BASE_PATH)/inc/SchM_Spi.h $(STDTEST_BASE_PATH)/inc/SchM_Fr_17_Eray.h $(STDTEST_BASE_PATH)/inc/SchM_Lin_17_AscLin.h $(STDTEST_BASE_PATH)/inc/SchM_Wdg_17_Scu.h $(STDTEST_BASE_PATH)/inc/SchM_Fls_17_Pmu.h
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/SchM.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION) $(STDTEST_BASE_PATH)/src/SchM.c $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/SchM.ers


$(STDTEST_BASE_PATH)/obj/CanIf_Cbk.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/CanIf_Cbk.c $(STDTEST_BASE_PATH)/inc/CanIf_Cbk.h $(headers)
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/CanIf_Cbk.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION)  $(STDTEST_BASE_PATH)/src/CanIf_Cbk.c  $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/CanIf_Cbk.ers

$(STDTEST_BASE_PATH)/obj/CanIf.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/CanIf.c $(STDTEST_BASE_PATH)/inc/CanIf.h $(headers)
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/CanIf.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION)  $(STDTEST_BASE_PATH)/src/CanIf.c  $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/CanIf.ers

ifeq ($(ETH_DELIVERY),STD_ON)
$(STDTEST_BASE_PATH)/obj/EthIf_Cbk.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/EthIf_Cbk.c $(STDTEST_BASE_PATH)/inc/EthIf_Cbk.h $(headers)
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/EthIf_Cbk.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION)  $(STDTEST_BASE_PATH)/src/EthIf_Cbk.c  $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/EthIf_Cbk.ers
endif

ifeq ($(SENT_DELIVERY),STD_ON)
$(STDTEST_BASE_PATH)/obj/Sent_Callout.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Sent_Callout.c $(STDTEST_BASE_PATH)/inc/Sent_Callout.h $(headers)
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Sent_Callout.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION)  $(STDTEST_BASE_PATH)/src/Sent_Callout.c  $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Sent_Callout.ers
endif

ifeq ($(DMA_DELIVERY),STD_ON)
$(STDTEST_BASE_PATH)/obj/Dma_Callout.$(OBJ_FILE_SUFFIX) : $(STDTEST_BASE_PATH)/src/Dma_Callout.c $(STDTEST_BASE_PATH)/inc/Dma_Callout.h $(headers)
	@"$(COMPILER)" $(OUTPUT) $(STDTEST_BASE_PATH)/obj/Dma_Callout.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(STDTEST_INC_PATHS_FILE) $(OBJ_CREATION)  $(STDTEST_BASE_PATH)/src/Dma_Callout.c  $(ERROR_REPORT)
	@-rm -f $(STDTEST_BASE_PATH)/obj/Dma_Callout.ers
endif

.PHONY: std_clean
std_clean:
	@-rm -f *.err

printer_clean:
	@-rm -f $(STDTEST_INC_PATHS_FILE)

stdincpaths:
	@echo $(STANDARD_INCLUDE) > $(STDTEST_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(STDTEST_INC_PATHS_FILE)

info:
	@echo -------------Compiling Standard Test(Integration General) Module---------------