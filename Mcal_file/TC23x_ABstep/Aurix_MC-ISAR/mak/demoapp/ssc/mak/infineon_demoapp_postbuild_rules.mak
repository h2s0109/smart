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
#*  FILENAME  : infineon_demoapp_postbuild_rules.mak                          **
#*                                                                            **
#*  VERSION   : 0.1.7                                                         **
#*                                                                            **
#*  DATE      : 2013.10.10                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build postbuild configuration    **
#*                    files                                                   **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* HM           Hamzath Mohammed                                             **
#* AK           Ashish Kumar                                                 **
#* VS           Vinod Shankar                                                **
#* SGN          Gururaj Nath S                                               **
#* SS           Srinivas Shenoy                                              **
#* KP           Kaushal Purohit                                              **
#* BM           Basheer Mohaideen                                            **
#* AJ           Abdul Jaffar                                                 **
#* RK           Rutuja Kawathekar                                            **
#* JN           Jayaprakash Narayana                                         **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.1.7: 2013.10.10, JN:  Updated for I2C
#*  V0.1.6: 2013.09.25, RK:  Updated for SMU
#*  V0.1.5: 2013.09.24, AJ:  Updated for DSADC
#*  V0.1.4: 2013.02.25, SGN:  VendorApiInfix changes for CAN
#*  V0.1.3: 2013.02.23, Vani: VendorApiInfix changes for FLS
#*  V0.1.2: 2013.02.21, BM       : VendorApiInfix changes for WDG.
#*  V0.1.1: 2013.02.21, SS: VendorApiInfix changes for LIN.
#*  V0.1.0: 2013.02.14, SS: VendorApiInfix changes for ICU.
#*  V0.0.9: 2012.10.19, AK: Updated for SENT
#*  V0.0.8: 2012.05.10, SGN: Updated for CAN path
#*  V0.0.7: 2011.03.18, VS : Included GTM
#*  V0.0.6: 2011.03.10, YG : Changed Audo-- > Aurix, FADC ---> SDADC
#*  v0.0.5: 2010-02-15, PrakashG : AI00053231: File/Folder name change 
#*                                    Fr to Fr_17_Eray, fr to fr_17_eray
#*  V0.0.4: 2009.03.24, HM : Remove CanTrcv as it is precompile module
#*  V0.0.3: 2009.02.05, Prakash : Added support for FR driver demo
#*  V0.0.2: 2007.10.09, HM   : CFG is changed to PB_CFG
#*  V0.0.1: 2007.09.19, HM  : Initial version.
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_defs.mak

all : check info  $(POSTBUILD_TARGETS)

check:
	@-IF EXIST "$(COMPILER)" (echo ---------------------------- Aurix_MC-ISAR --------------------------) ELSE echo Complier Directory Doesn't exists
mcu_cfg:
	@-echo $(MCU_PB_CFG_OBJECTS) > $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mcu_infineon_tricore/$(mcupath)/mak/infineon_mcu_rules.mak

gtm_cfg:
	@-echo $(GTM_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mcu_infineon_tricore/$(gtmpath)/mak/infineon_gtm_rules.mak
	
port_cfg:
	@-echo $(PORT_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/port_infineon_tricore/$(portpath)/mak/infineon_port_rules.mak
	
dma_cfg:
	@-echo $(DMA_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dma_infineon_tricore/$(dmapath)/mak/infineon_dma_rules.mak
	
gpt_cfg:
	@-echo $(GPT_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/gpt_infineon_tricore/$(gptpath)/mak/infineon_gpt_rules.mak
	
spi_cfg:
	@-echo $(SPI_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/spi_infineon_tricore/$(spipath)/mak/infineon_spi_rules.mak

mli_cfg:
	@-echo $(MLI_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mli_infineon_tricore/$(mlipath)/mak/infineon_mli_rules.mak

dio_cfg:
	@-echo $(DIO_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dio_infineon_tricore/$(diopath)/mak/infineon_dio_rules.mak
		
can_cfg:
	@-echo $(CAN_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/$(canpath)/mak/infineon_can_17_mcanp_rules.mak
	
pwm_cfg:
	@-echo $(PWM_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/$(pwmpath)/mak/infineon_pwm_17_gtm_rules.mak
		
sent_cfg:
	@-echo $(SENT_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sent_infineon_tricore/$(sentpath)/mak/infineon_sent_rules.mak

iom_cfg:
	@-echo $(IOM_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/iom_infineon_tricore/$(iompath)/mak/infineon_iom_rules.mak
		
adc_cfg:
	@-echo $(ADC_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/adc_infineon_tricore/$(adcpath)/mak/infineon_adc_rules.mak

sdadc_cfg:
	@-echo $(SDADC_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sdadc_infineon_tricore/$(sdadcpath)/mak/infineon_sdadc_rules.mak
	    
fls_cfg:
	@-echo $(FLS_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/$(flspath)/mak/infineon_fls_17_pmu_rules.mak

wdg_cfg:
	@-echo $(WDG_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/$(wdgpath)/mak/infineon_wdg_17_scu_rules.mak
    
icu_cfg:
	@-echo $(ICU_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/$(icupath)/mak/infineon_icu_17_gtmccu6_rules.mak

msc_cfg:
	@-echo $(MSC_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/msc_infineon_tricore/$(mscpath)/mak/infineon_msc_rules.mak

mchk_cfg:
	@-echo $(MCHK_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mchk_infineon_tricore/$(mchkpath)/mak/infineon_mchk_rules.mak

sci_cfg:
	@-echo $(SCI_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sci_infineon_tricore/$(scipath)/mak/infineon_sci_rules.mak
fr_cfg:
	@-echo $(FR_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/$(frpath)/mak/infineon_fr_17_eray_rules.mak

lin_cfg:
	@-echo $(LIN_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/$(linpath)/mak/infineon_lin_17_AscLin_rules.mak

eth_cfg:
	@-echo $(ETH_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/$(ethpath)/mak/infineon_eth_17_ethmac_rules.mak

uart_cfg:
	@-echo $(UART_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/uart_infineon_tricore/$(uartpath)/mak/infineon_uart_rules.mak

dsadc_cfg:
	@-echo $(DSADC_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dsadc_infineon_tricore/$(dsadcpath)/mak/infineon_dsadc_rules.mak
	
smu_cfg:
	@-echo $(SMU_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/smu_infineon_tricore/$(smupath)/mak/infineon_smu_rules.mak	
	    					
i2c_cfg:
	@-echo $(I2C_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/i2c_infineon_tricore/$(i2cpath)/mak/infineon_i2c_rules.mak


info: 
	@echo -------------Compiling post build configuration files---------------