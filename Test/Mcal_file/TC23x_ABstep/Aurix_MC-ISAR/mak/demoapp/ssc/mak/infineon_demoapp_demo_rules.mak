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
#*  FILENAME  : infineon_demoapp_demo_rules.mak                               **
#*                                                                            **
#*  VERSION   : 0.2.5                                                         **
#*                                                                            **
#*  DATE      : 2013.10.11                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build Demo Application           **
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
#* SK          Sai Kiran B                                                    **
#* AT          Angeswaran Thangaswamy                                         **
#* VS          Vinod Shankar                                                  **
#* Prakash     Prakash Gudnavar                                               **
#* Rutuja      Rutuja Kawathekar                                              **
#* SGN         Gururaj Nath S                                                 **
#* AK           Ashish Kumar                                                  **
#* PM          Puneetha Mukherjee                                             **
#* DNS         Deepak Nair S                                                  **
#* SS           Srinivas Shenoy                                               **
#* BM          Basheer Mohaideen                                              **
#* AJ          Abdul Jaffar                                                   **
#* JN          Jayaprakash Narayana                                           **
#* MK          Mundhra Karan                                                  **
#******************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.2.5: 2013.10.11, MK       : Updated for HSM.
#*  V0.2.4: 2013.10.10, JN       : Updated for I2C.
#*  V0.2.3: 2013.09.24, AJ       : Updated for DSADC.
#*  V0.2.2: 2013.02.25, SGN      : VendorApiInfix changes for CAN.
#*  V0.2.1: 2013.02.23, Vani     : VendorApiInfix changes for FLS.
#*  V0.2.0: 2013.02.21, BM       : VendorApiInfix changes for WDG.
#*  V0.1.9: 2013.02.14, SS       : VendorApiInfix changes for ICU.
#*  V0.1.8: 2013.01.31, DNS      : Updated for Pwm Vendor ApiInfix
#*  V0.1.7: 2013.01.31, AT       : cantrcv_17_6250gv33_demo renamed
#*  V0.1.6: 2012.12.28, SK       : Updated for CanTrcv
#*  V0.1.5: 2012.10.19, AK       : Updated for SENT
#*  V0.1.4: 2012.08.21, AT       : Updated for GNU compiler
#*  V0.1.3: 2012.05.15, SGN      : Corrected CAN path
#*  V0.1.2: 2012.03.16, VS       : Adapted to AI00064361
#*  V0.1.1: 2011..03.10, Yogesh  : AudoF --> Aurix
#*  v0.1.0: 2010-02-15, PrakashG : AI00053231: File/Folder name change 
#*                                    Fr to Fr_17_Eray, fr to fr_17_eray
#*  V0.0.9: 2009.10.22, Hamzath : RamTst added
#*  V0.0.8: 2009.04.02, Hamzath : CanTrcv6250GV33 added
#*  V0.0.7: 2009.02.23, Hamzath : CanTrcv6251G added
#*  V0.0.6: 2009.02.24, Prakash : Added preprocessor switch definition for FR 
#*                                driver demo
#*  V0.0.5: 2009.02.05, Prakash : Added support for FR driver demo
#*  V0.0.4: 2007.11.05, Rutuja  : Added support for Mchk driver demo
#*  V0.0.3: 2007.11.30, Rutuja  : Added support for Msc driver demo
#*  V0.0.2: 2007.11.05, Prakash : Added support for CAN driver demo
#*  V0.0.1: 2007.09.19, RS  : Initial version.
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_defs.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_safetlib_defs.mak

ifeq ($(FR_17_ERAY_DELIVERY_SWITCH),0)
FR_PBCFG="-DFR_17_ERAY_PBCFG_0"
endif
 
ifeq ($(FR_17_ERAY_DELIVERY_SWITCH),1)
FR_PBCFG="-DFR_17_ERAY_PBCFG_1"
endif

SUPPRESS_WARNING = 
ifeq ($(COMPILER_CHOICE),GNU)
SUPPRESS_WARNING = -w
endif

# compiling mcallib,gpt, are optional, more important thing is to include the object files.
ifeq ($(DEMO_FCTLIST_GEN),1)
all : check app_clean info proj_files
else
all : check app_clean $(DEMO_TARGETS) other_includes info proj_files link_app  
endif
#all : 
check:
	@-IF EXIST "$(COMPILER)" (echo ---------------------------- Aurix_MC-ISAR --------------------------) ELSE echo Complier Directory Doesn't exists
#	@echo DEMO_FCTLIST_GEN=$(DEMO_FCTLIST_GEN)	
  
app_clean :
	@-rm -f $(APPLN_OBJECTS)

mcu_demo :
	@-echo $(MCU_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mcu_infineon_tricore/demo/mak/infineon_mcu_rules.mak
	@-echo $(MCU_INCLUDE_PATH) > $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(MCU_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
bfx_demo :
	@-echo $(BFX_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/bfx_infineon_tricore/demo/mak/infineon_bfx_rules.mak
	@-echo $(BFX_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(BFX_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

hsm_demo :
	@-echo $(HSM_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_HSM_ROOT)/mak/hsm_infineon_tricore/demo/mak/infineon_hsm_rules.mak
	@-echo $(HSM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(HSM_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

stm_demo :
	@-echo $(STM_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/stm_infineon_tricore/demo/mak/infineon_stm_rules.mak
	@-echo $(STM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(STM_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
gtm_demo :
	@-echo $(GTM_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mcu_infineon_tricore/demo/mak/infineon_gtm_rules.mak
	@-echo $(GTM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(GTM_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

hssl_demo:
	@-echo $(HSSL_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/hssl_infineon_tricore/demo/mak/infineon_hssl_rules.mak
	@-echo $(HSSL_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(HSSL_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
dio_demo:
	@-echo $(DIO_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dio_infineon_tricore/demo/mak/infineon_dio_rules.mak
	@-echo $(DIO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(DIO_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

dma_demo:
	@-echo $(DMA_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dma_infineon_tricore/demo/mak/infineon_dma_rules.mak
	@-echo $(DMA_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(DMA_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
gpt_demo:
	@-echo $(GPT_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/gpt_infineon_tricore/demo/mak/infineon_gpt_rules.mak
	@-echo $(GPT_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(GPT_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
spi_demo:
	@-echo $(SPI_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/spi_infineon_tricore/demo/mak/infineon_spi_rules.mak
	@-echo $(SPI_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(SPI_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

mli_demo:
	@-echo $(MLI_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mli_infineon_tricore/demo/mak/infineon_mli_rules.mak
	@-echo $(MLI_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(MLI_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
can_demo :
	@-echo $(CAN_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/demo/mak/infineon_can_17_mcanp_rules.mak	
	@-echo $(CAN_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(CAN_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
cantrcv_17_6251G_demo:
	@-echo $(CANTRCV_17_6251G_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/demo/mak/infineon_cantrcv_17_6251g_rules.mak
	@-echo $(CANTRCV_17_6251G_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(CANTRCV_17_6251G_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

cantrcv_17_6250gv33_demo:
	@-echo $(CANTRCV_17_6250GV33_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/demo/mak/infineon_cantrcv_17_6250gv33_rules.mak
	@-echo $(CANTRCV_17_6250GV33_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(CANTRCV_17_6250GV33_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
		
pwm_demo:
	@-echo $(PWM_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/demo/mak/infineon_pwm_17_gtm_rules.mak
	@-echo $(PWM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(PWM_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

sent_demo:
	@-echo $(SENT_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sent_infineon_tricore/demo/mak/infineon_sent_rules.mak
	@-echo $(SENT_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(SENT_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
iom_demo:
	@-echo $(IOM_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/iom_infineon_tricore/demo/mak/infineon_iom_rules.mak
	@-echo $(IOM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(IOM_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
		
adc_demo:
	@-echo $(ADC_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/adc_infineon_tricore/demo/mak/infineon_adc_rules.mak
	@-echo $(ADC_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(ADC_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

sdadc_demo:
	@-echo $(SDADC_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sdadc_infineon_tricore/demo/mak/infineon_sdadc_rules.mak
	@-echo $(SDADC_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(SDADC_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
flsloader_demo:
	@-echo $(FLSLOADER_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/flsloader_infineon_tricore/demo/mak/infineon_flsloader_rules.mak
	@-echo $(FLSLOADER_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(FLSLOADER_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
fls_demo:
	@-echo $(FLS_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/demo/mak/infineon_fls_17_pmu_rules.mak
	@-echo $(FLS_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(FLS_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
fee_demo:
	@-echo $(FEE_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fee_infineon_tricore/demo/mak/infineon_fee_rules.mak
	@-echo $(FEE_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(FEE_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
    
wdg_demo:
	@-echo $(WDG_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/demo/mak/infineon_wdg_17_scu_rules.mak
	@-echo $(WDG_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(WDG_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
    
icu_demo:
	@-echo $(ICU_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/demo/mak/infineon_icu_17_gtmccu6_rules.mak
	@-echo $(ICU_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(ICU_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
    
	
eru_demo:
	@-echo $(ERU_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/eru_infineon_tricore/demo/mak/infineon_eru_rules.mak
	@-echo $(ERU_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(ERU_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
msc_demo:
	@-echo $(MSC_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/msc_infineon_tricore/demo/mak/infineon_msc_rules.mak
	@-echo $(MSC_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(MSC_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
mchk_demo:
	@-echo $(MCHK_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mchk_infineon_tricore/demo/mak/infineon_mchk_rules.mak
	@-echo $(MCHK_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(MCHK_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
sci_demo:
	@-echo $(SCI_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sci_infineon_tricore/demo/mak/infineon_sci_rules.mak
	@-echo $(SCI_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(SCI_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
fr_demo:
	@-echo $(FR_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/demo/mak/infineon_fr_17_eray_rules.mak
	@-echo $(FR_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(FR_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

lin_demo:
	@-echo $(LIN_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/demo/mak/infineon_lin_17_AscLin_rules.mak
	@-echo $(LIN_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(LIN_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

eth_demo:
	@-echo $(ETH_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/demo/mak/infineon_eth_17_ethmac_rules.mak
	@-echo $(ETH_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(ETH_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)


stdlin_demo:
	@-echo $(STDLIN_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/stdlin_infineon_tricore/demo/mak/infineon_stdlin_rules.mak
	@-echo $(STDLIN_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(STDLIN_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
uart_demo:
	@-echo $(UART_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/uart_infineon_tricore/demo/mak/infineon_uart_rules.mak
	@-echo $(UART_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(UART_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
crc_demo:
	@-echo $(CRC_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/crc_infineon_tricore/demo/mak/infineon_crc_rules.mak
	@-echo $(CRC_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(CRC_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

dsadc_demo:
	@-echo $(DSADC_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dsadc_infineon_tricore/demo/mak/infineon_dsadc_rules.mak
	@-echo $(DSADC_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(DSADC_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

i2c_demo:
	@-echo $(I2C_DEMO_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/i2c_infineon_tricore/demo/mak/infineon_i2c_rules.mak
	@-echo $(I2C_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	@-echo $(I2C_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

other_includes : stdtest_inc irq_inc ecum_inc port_inc demoincpaths flsloader_inc

stdtest_inc:
	@-echo $(STDTEST_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)

irq_inc: 
	@-echo $(IRQ_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
	
hssl_inc: 
	@-echo $(HSSL_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)	
	
ecum_inc: 
	@-echo $(ECUM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
port_inc:
	@-echo $(PORT_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
stm_inc:
	@-echo $(STM_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)  
demoincpaths:
	@-echo $(STANDARD_INCLUDE) >> $(DEMOAPP_INC_PATHS_FILE)
flsloader_inc:
#	@-echo $(FLSLOADER_DEMO_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)
#	@-echo $(FLSLOADER_INCLUDE_PATH) >> $(DEMOAPP_INC_PATHS_FILE)	
				
proj_files: $(APPLN_OBJECTS)

$(OUTDIR)/DemoApp.$(OBJ_FILE_SUFFIX) : $(PROJSRC)/DemoApp.c $(headers)
	@"$(COMPILER)" $(OUTPUT) $(OUTDIR)/DemoApp.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(SAFETLIB_INTEGRATION) $(FR_PBCFG) $(FF_READ)$(DEMOAPP_INC_PATHS_FILE) $(OBJ_CREATION)    $(PROJSRC)/DemoApp.c  $(ERROR_REPORT)
	@-rm -f $(OUTDIR)/DemoApp.ers

ifeq ($(PERL_AVAILABLE),YES)
$(OUTDIR)/DemoApp_FctCall.$(OBJ_FILE_SUFFIX) : $(PROJSRC)/DemoApp_FctCall.c $(headers)
	@"$(COMPILER)" $(OUTPUT) $(OUTDIR)/DemoApp_FctCall.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(SUPPRESS_WARNING) $(FR_PBCFG) $(FF_READ)$(DEMOAPP_INC_PATHS_FILE) $(OBJ_CREATION)    $(PROJSRC)/DemoApp_FctCall.c  $(ERROR_REPORT)
	@-rm -f $(OUTDIR)/DemoApp_FctCall.ers
endif
 
# Add more files if you need here.  

link_app:
	@-echo $(APPLN_OBJECTS) >> $(LINK_INP_FILE)
  	
info: 
	@-echo -------------Compiling DemoApp---------------
