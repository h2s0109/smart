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
#*  FILENAME  : infineon_ecum_rules.mak                                       **
#*                                                                            **
#*  VERSION   : 0.1.6                                                         **
#*                                                                            **
#*  DATE      : 2013-09-25                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the DIO driver             **
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
#* AT           Angeswaran Thangaswamy                                       **
#* PR           Pawan Reddy                                                  **
#* RS           Roopa Sirur                                                  **
#* BM           Basheer Mohaideen                                            **
#* SGN          Gururaj Nath S                                               **
#* AK           Ashish Kumar                                                 **
#* PM          Puneetha Mukherjee                                            ** 
#* basavath    Tejaswini Basavarajaiah                                       **
#* KP           Kaushal Purohit                                               **
#* SS           Srinivas Shenoy                                              **
#* AJ           Abdul Jaffar                                                 **
#* RK           Rutuja Kawathekar                                            **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.1.7: 2013.10.15, JN       : I2C Support added
#*  V0.1.6: 2013.09.25, RK       : SMU Support
#*  V0.1.5: 2013.09.24, AJ       : DSADC Support added 
#*  V0.1.4: 2013.02.25, SGN      : CAN Changes for VendorApiInfix 
#*  V0.1.3: 2013.02.21, KP       : LIN Changes for VendorApiInfix 
#*  V0.1.2: 2013.02.15, SS       : Changes for VendorApiInfix
#*  V0.1.1: 2012.11.08, basavath  : Added support for IOM
#*  V0.1.0: 2012.10.19, AK       : support for SENT
#*  V0.0.9: 2012.09.17, AT       : Updated for GNU/WINDRIVER compiler
#*  V0.0.8: 2012-05-10, SGN      : changed CAN Path
#*  V0.0.7: 2011-03-22, PR       : changed ON to STD_ON
#*  V0.0.6: 2010-04-09, BM       : Added support for Flex Ray.
#*                               - Updated as per UTP: AI00054570
#*  V0.0.5: 2009-10-21, SC       : Added support for RamTst     
#*  V0.0.4: 2007.11.05, Prakash  : Added support for CAN driver 
#*  V0.0.3: 2007.09.21, RS  : Changed year, added comments
#*  V0.0.2: 2007.06.19, RS  : Added FEE, FLS, WDG, ICU
#*  V0.0.1: 2007.02.23, RS  : Initial version.
#*
#******************************************************************************/


#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/irq_infineon_tricore/ssc/mak/infineon_irq_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_safetlib_defs.mak
ifeq ($(MCU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak
endif
ifeq ($(PORT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak
endif
ifeq ($(DIO_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_defs.mak
endif
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
endif
ifeq ($(SPI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak
endif
ifeq ($(PWM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_defs.mak
endif
ifeq ($(ADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak
endif
ifeq ($(FADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fadc_infineon_tricore/ssc/mak/infineon_fadc_defs.mak
endif
ifeq ($(MLI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mli_infineon_tricore/ssc/mak/infineon_mli_defs.mak
endif
ifeq ($(DMA_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_defs.mak
endif
ifeq ($(FLS_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_defs.mak
endif
ifeq ($(FEE_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fee_infineon_tricore/ssc/mak/infineon_fee_defs.mak
endif
ifeq ($(WDG_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_defs.mak
endif
ifeq ($(ICU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
endif
ifeq ($(CAN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_defs.mak
endif
ifeq ($(MCHK_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mchk_infineon_tricore/ssc/mak/infineon_mchk_defs.mak
endif
ifeq ($(MSC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_defs.mak
endif
ifeq ($(SCI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sci_infineon_tricore/ssc/mak/infineon_sci_defs.mak
endif

ifeq ($(LIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_defs.mak
endif

ifeq ($(UART_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_defs.mak
endif

ifeq ($(ETH_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_defs.mak
endif

ifeq ($(CRC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/crc_infineon_tricore/ssc/mak/infineon_crc_defs.mak
endif


ifeq ($(CANTRCV_6251G_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251g_defs.mak
endif

ifeq ($(CANTRCV_6250GV33_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/ssc/mak/infineon_cantrcv_17_6250gv33_defs.mak
endif

ifeq ($(RAMTST_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/ramtst_infineon_tricore/ssc/mak/infineon_ramtst_defs.mak
endif

ifeq ($(FR_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/ssc/mak/infineon_fr_17_eray_defs.mak
endif

ifeq ($(FLSLOADER_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_defs.mak
endif

ifeq ($(SENT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_defs.mak
endif

ifeq ($(IOM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/iom_infineon_tricore/ssc/mak/infineon_iom_defs.mak
endif

ifeq ($(HSSL_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_defs.mak
endif

ifeq ($(DSADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dsadc_infineon_tricore/ssc/mak/infineon_dsadc_defs.mak
endif

ifeq ($(SMU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/smu_infineon_tricore/ssc/mak/infineon_smu_defs.mak
endif

ifeq ($(I2C_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/i2c_infineon_tricore/ssc/mak/infineon_i2c_defs.mak
endif
#***************************** SPECIFIC ****************************************/

headers = $(STANDARD_DEPENDANCY) $(ECUM_DEP_HEADERS)
ECUM_INC_PATHS_FILE = ecum_include_paths.ifx

ifeq ($(MCU_DELIVERY),STD_ON)
addon_headers += $(MCU_DEP_HEADERS)
ECUM_DEP_INC += ecum_mcu_inc 
endif

ifeq ($(PORT_DELIVERY),STD_ON)
addon_headers += $(PORT_DEP_HEADERS)
ECUM_DEP_INC += ecum_port_inc 
endif

ifeq ($(DIO_DELIVERY),STD_ON)
addon_headers += $(DIO_DEP_HEADERS)
ECUM_DEP_INC += ecum_dio_inc 
endif

ifeq ($(GPT_DELIVERY),STD_ON)
addon_headers += $(GPT_DEP_HEADERS)
ECUM_DEP_INC += ecum_gpt_inc 
endif


ifeq ($(SPI_DELIVERY),STD_ON)
addon_headers += $(SPI_DEP_HEADERS)
ECUM_DEP_INC += ecum_spi_inc 
endif

ifeq ($(ADC_DELIVERY),STD_ON)
addon_headers += $(ADC_DEP_HEADERS)
ECUM_DEP_INC += ecum_adc_inc 
endif

ifeq ($(FADC_DELIVERY),STD_ON)
addon_headers += $(FADC_DEP_HEADERS)
ECUM_DEP_INC += ecum_fadc_inc 
endif

ifeq ($(PWM_DELIVERY),STD_ON)
addon_headers += $(PWM_DEP_HEADERS)
ECUM_DEP_INC += ecum_pwm_inc 
endif

ifeq ($(DMA_DELIVERY),STD_ON)
addon_headers += $(DMA_DEP_HEADERS)
ECUM_DEP_INC += ecum_dma_inc 
endif

ifeq ($(MLI_DELIVERY),STD_ON)
addon_headers += $(MLI_DEP_HEADERS)
ECUM_DEP_INC += ecum_mli_inc 
endif

ifeq ($(FLS_DELIVERY),STD_ON)
addon_headers += $(FLS_DEP_HEADERS)
ECUM_DEP_INC += ecum_fls_inc 
endif

ifeq ($(FEE_DELIVERY),STD_ON)
addon_headers += $(FEE_DEP_HEADERS)
ECUM_DEP_INC += ecum_fee_inc 
endif

ifeq ($(WDG_DELIVERY),STD_ON)
addon_headers += $(WDG_DEP_HEADERS)
ECUM_DEP_INC += ecum_wdg_inc 
endif

ifeq ($(ICU_DELIVERY),STD_ON)
addon_headers += $(ICU_DEP_HEADERS)
ECUM_DEP_INC += ecum_icu_inc 
endif

ifeq ($(CAN_DELIVERY),STD_ON)
addon_headers += $(CAN_DEP_HEADERS)
ECUM_DEP_INC += ecum_can_inc 
endif

ifeq ($(MCHK_DELIVERY),STD_ON)
addon_headers += $(MCHK_DEP_HEADERS)
ECUM_DEP_INC += ecum_mchk_inc 
endif

ifeq ($(MSC_DELIVERY),STD_ON)
addon_headers += $(MSC_DEP_HEADERS)
ECUM_DEP_INC += ecum_msc_inc 
endif

ifeq ($(SCI_DELIVERY),STD_ON)
addon_headers += $(SCI_DEP_HEADERS)
ECUM_DEP_INC += ecum_sci_inc 
endif


ifeq ($(LIN_DELIVERY),STD_ON)
addon_headers += $(LIN_DEP_HEADERS)
ECUM_DEP_INC += ecum_lin_inc 
endif

ifeq ($(UART_DELIVERY),STD_ON)
addon_headers += $(UART_DEP_HEADERS)
ECUM_DEP_INC += ecum_uart_inc 
endif

ifeq ($(ETH_DELIVERY),STD_ON)
addon_headers += $(ETH_DEP_HEADERS)
ECUM_DEP_INC += ecum_eth_inc 
endif


ifeq ($(CANTRCV_6251G_DELIVERY),STD_ON)
addon_headers += $(CANTRCV_17_6251G_DEP_HEADERS)
ECUM_DEP_INC += ecum_cantrcv6251G_inc 
endif

ifeq ($(CANTRCV_6250GV33_DELIVERY),STD_ON)
addon_headers += $(CANTRCV_17_6250GV33_DEP_HEADERS)
ECUM_DEP_INC += ecum_cantrcv6250GV33_inc 
endif


ifeq ($(RAMTST_DELIVERY),STD_ON)
addon_headers += $(RAMTST_DEP_HEADERS)
ECUM_DEP_INC += ecum_ramtst_inc 
endif


ifeq ($(FR_DELIVERY),STD_ON)
addon_headers += $(FR_DEP_HEADERS)
ECUM_DEP_INC += ecum_fr_inc 
endif


ifeq ($(FLSLOADER_DELIVERY),STD_ON)
addon_headers += $(FLSLOADER_DEP_HEADERS)
ECUM_DEP_INC += ecum_flsloader_inc 
endif

ifeq ($(SENT_DELIVERY),STD_ON)
addon_headers += $(SENT_DEP_HEADERS)
ECUM_DEP_INC += ecum_sent_inc
endif

ifeq ($(IOM_DELIVERY),STD_ON)
addon_headers += $(IOM_DEP_HEADERS)
ECUM_DEP_INC += ecum_iom_inc
endif

ifeq ($(HSSL_DELIVERY),STD_ON)
addon_headers += $(HSSL_DEP_HEADERS)
ECUM_DEP_INC += ecum_hssl_inc 
endif

ifeq ($(DSADC_DELIVERY),STD_ON)
addon_headers += $(DSADC_DEP_HEADERS)
ECUM_DEP_INC += ecum_dsadc_inc 
endif

ifeq ($(SMU_DELIVERY),STD_ON)
addon_headers += $(SMU_DEP_HEADERS)
ECUM_DEP_INC += ecum_smu_inc
endif

ifeq ($(I2C_DELIVERY),STD_ON)
addon_headers += $(I2C_DEP_HEADERS)
ECUM_DEP_INC += ecum_i2c_inc
endif

build_ecum_driver : info ecumincpaths $(ECUM_OBJECTS)


$(ECUM_BASE_PATH)/ssc/obj/EcuM.$(OBJ_FILE_SUFFIX) : $(ECUM_BASE_PATH)/ssc/src/EcuM.c $(headers) $(addon_headers) $(ECUM_BASE_PATH)/ssc/inc/EcuM_Cbk.h 
	@"$(COMPILER)"  $(OUTPUT) $(ECUM_BASE_PATH)/ssc/obj/EcuM.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ECUM_INC_PATHS_FILE) $(OBJ_CREATION) $(ECUM_BASE_PATH)/ssc/src/EcuM.c $(ERROR_REPORT)
	@-rm -f $(ECUM_BASE_PATH)/ssc/obj/EcuM.ers
	
$(ECUM_BASE_PATH)/ssc/obj/EcuM_Callout_Stubs.$(OBJ_FILE_SUFFIX) : $(ECUM_BASE_PATH)/ssc/src/EcuM_Callout_Stubs.c $(headers) $(addon_headers) $(ECUM_BASE_PATH)/ssc/inc/EcuM_Cbk.h $(IRQ_BASE_PATH)/ssc/inc/Irq.h 
	@"$(COMPILER)"  $(OUTPUT) $(ECUM_BASE_PATH)/ssc/obj/EcuM_Callout_Stubs.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ECUM_INC_PATHS_FILE) $(SAFETLIB_INTEGRATION) $(OBJ_CREATION) $(ECUM_BASE_PATH)/ssc/src/EcuM_Callout_Stubs.c $(ERROR_REPORT)
	@-rm -f $(ECUM_BASE_PATH)/ssc/obj/EcuM_Callout_Stubs.ers

$(ECUM_BASE_PATH)/cfg1/obj/EcuM_LCfg.$(OBJ_FILE_SUFFIX) : $(ECUM_BASE_PATH)/cfg1/src/EcuM_LCfg.c $(headers)
	@"$(COMPILER)"  $(OUTPUT) $(ECUM_BASE_PATH)/cfg1/obj/EcuM_LCfg.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ECUM_INC_PATHS_FILE) $(OBJ_CREATION)  $(ECUM_BASE_PATH)/cfg1/src/EcuM_LCfg.c $(ERROR_REPORT)
	@-rm -f $(ECUM_BASE_PATH)/cfg1/obj/EcuM_LCfg.ers




.PHONY: clean
clean:
	@-rm -f $(ECUM_OBJECTS)

.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err
	@-rm -f *.ifx
	
print:
	@echo $(ECUM_OBJECTS)
	
ecumincpaths: ecum_inc $(ECUM_DEP_INC)

ecum_inc:
	@echo $(STANDARD_INCLUDE) > $(ECUM_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	@echo $(IRQ_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)	
ecum_mcu_inc :	
	@-echo $(MCU_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_port_inc :	
	@-echo $(PORT_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_dio_inc :	
	@-echo $(DIO_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_gpt_inc :	
	@-echo $(GPT_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	

ecum_spi_inc :	
	@-echo $(SPI_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_adc_inc :	
	@-echo $(ADC_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_fadc_inc :	
	@-echo $(FADC_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_pwm_inc :	
	@-echo $(PWM_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_dma_inc :	
	@-echo $(DMA_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_mli_inc :	
	@-echo $(MLI_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_fls_inc :	
	@-echo $(FLS_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_fee_inc :	
	@-echo $(FEE_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_wdg_inc :	
	@-echo $(WDG_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_icu_inc :
	@-echo $(ICU_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)


ecum_can_inc :
	@-echo $(CAN_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
ecum_mchk_inc :
	@-echo $(MCHK_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
ecum_msc_inc :
	@-echo $(MSC_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
ecum_sci_inc :
	@-echo $(SCI_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_lin_inc :
	@-echo $(LIN_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_uart_inc :
	@-echo $(UART_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_eth_inc :
	@-echo $(ETH_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_cantrcv6251G_inc :
	@-echo $(CANTRCV_17_6251G_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_cantrcv6250GV33_inc :
	@-echo $(CANTRCV_17_6250GV33_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)	

ecum_ramtst_inc :
	@-echo $(RAMTST_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)	
	
ecum_fr_inc :
	@-echo $(FR_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
		
ecum_flsloader_inc :
	@-echo $(FLSLOADER_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_sent_inc :
	@-echo $(SENT_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_iom_inc :
	@-echo $(IOM_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)	

ecum_hssl_inc :	
	@-echo $(HSSL_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)

ecum_dsadc_inc :
	@-echo $(DSADC_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)	

ecum_smu_inc :
	@-echo $(SMU_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
	
ecum_i2c_inc :
	@-echo $(I2C_INCLUDE_PATH) >> $(ECUM_INC_PATHS_FILE)
		
info: 
	@echo -------------Compiling ECUM Module---------------	
