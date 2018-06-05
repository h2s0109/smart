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
#*  FILENAME  : infineon_demoapp_driver_rules.mak                             **
#*                                                                            **
#*  VERSION   : 0.2.7                                                         **
#*                                                                            **
#*  DATE      : 2014.03.11                                                    **
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
#* SK         Sai Kiran B                                                     **
#* HM         Hamzath Mohammed                                                **
#* VS         Vinod Shankar                                                   **
#* SGN        Gururaj Nath S                                                  **
#* AK         Ashish Kumar                                                    **
#* PM         Puneetha Mukherjee                                              **
#* DNS        Deepak Nair S                                                   **
#* KP         Kaushal Purohit                                                 **
#* SS         Srinivas Shenoy                                                 **
#* BM         Basheer Mohaideen                                               **
#* AJ         Abdul Jaffar                                                    **
#* RK         Rutuja Kawathekar                                               **
#* JN         Jayaprakash Narayana                                            **
#* MK         Mundhra Karan                                                   **
#******************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.2.7: 2014.03.11, MK:  Added HSM
#*  V0.2.6: 2014.03.07, SS:  Updated for OS
#*  V0.2.5: 2013.10.10, JN:  Updated for I2C
#*  V0.2.4: 2013.09.25, RK:  Updated for SMU
#*  V0.2.3: 2013.09.24, AJ:  Updated for DSADC
#*  V0.2.2: 2013.02.25, SGN:  VendorApiInfix changes for CAN
#*  V0.2.1: 2013.02.23, Vani: VendorApiInfix changes for FLS
#*  V0.2.0: 2013.02.21, BM       : VendorApiInfix changes for WDG.
#*  V0.1.6: 2013.02.21, KP: VendorApiInfix changes for LIN.
#*  V0.1.5: 2013.02.14, SS: VendorApiInfix changes for ICU.
#*  V0.1.4: 2013.02.14, DNS: Updated for Pwm Vendor Api Infix
#*  V0.1.3: 2012.12.28, SK: Updated for CanTrcv
#*  V0.1.2: 2012.11.06, PM: Updated for Hssl
#*  V0.1.1: 2012.10.19, AK: Updated for SENT
#*  V0.1.0: 2012.05.10, SGN: Updated for CAN path
#*  V0.0.9: 2011.03.18, VS : Included GTM
#*  V0.0.8: 2011.03.10, YG : Replaced Audo---> Aurix, FADC ---> SDADC
#*  v0.0.7: 2010-02-15, PrakashG : AI00053231: File/Folder name change
#*                                    Fr to Fr_17_Eray, fr to fr_17_eray
#*  V0.0.6: 2009.10.21, HM : Split SSC into 6 variables
#*  V0.0.5: 2009.10.20, HM : add RamTst
#*  V0.0.4: 2009.04.02, HM : add CanTrcv6250GV33
#*  V0.0.3: 2009.03.24, HM : add CanTrcv6251G
#*  V0.0.2: 2009.02.05, Prakash : Added support for FR driver demo
#*  V0.0.1: 2007.09.19, HM  : Initial version adapted from DemoApp.mak
#*
#******************************************************************************/
include $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_defs.mak


# compiling .
all : check $(TARGETS)
#all :
check:
	@-IF EXIST "$(COMPILER)" (echo ---------------------------- Aurix_MC-ISAR --------------------------) ELSE echo Complier Directory Doesn't exists
mcu :
	@-echo $(MCU_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_rules.mak

bfx :
	@-echo $(BFX_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/bfx_infineon_tricore/ssc/mak/infineon_bfx_rules.mak

hsm :
	@-echo $(HSM_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_HSM_ROOT)/mak/hsm_infineon_tricore/ssc/mak/infineon_hsm_rules.mak

gtm :
	@-echo $(GTM_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_rules.mak

hssl :
	@-echo $(HSSL_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_rules.mak

port:
	@-echo $(PORT_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_rules.mak

dio:
	@-echo $(DIO_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_rules.mak

dma:
	@-echo $(DMA_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_rules.mak

gpt:
	@-echo $(GPT_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_rules.mak

spi:
	@-echo $(SPI_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_rules.mak

stm:
	@-echo $(STM_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/stm_infineon_tricore/ssc/mak/infineon_stm_rules.mak

stdlin:
	@-echo $(STDLIN_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/stdlin_infineon_tricore/ssc/mak/infineon_stdlin_rules.mak

can:
	@-echo $(CAN_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_rules.mak

cantrcv_17_6250gv33:
	@-echo $(CANTRCV_17_6250GV33_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/ssc/mak/infineon_cantrcv_17_6250gv33_rules.mak

cantrcv_17_6251g:
	@-echo $(CANTRCV_17_6251G_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251g_rules.mak

pwm:
	@-echo $(PWM_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_rules.mak

sent:
	@-echo $(SENT_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_rules.mak

iom:
	@-echo $(IOM_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/iom_infineon_tricore/ssc/mak/infineon_iom_rules.mak

adc:
	@-echo $(ADC_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_rules.mak

sdadc:
	@-echo $(SDADC_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sdadc_infineon_tricore/ssc/mak/infineon_sdadc_rules.mak

flsloader:
	@-echo $(FLSLOADER_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_rules.mak

fls:
	@-echo $(FLS_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_rules.mak

fee:
	@-echo $(FEE_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fee_infineon_tricore/ssc/mak/infineon_fee_rules.mak

wdg:
	@-echo $(WDG_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_rules.mak

icu:
	@-echo $(ICU_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_rules.mak

eru:
	@-echo $(ERU_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/eru_infineon_tricore/ssc/mak/infineon_eru_rules.mak
msc:
	@-echo $(MSC_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_rules.mak
mchk:
	@-echo $(MCHK_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/mchk_infineon_tricore/ssc/mak/infineon_mchk_rules.mak
sci:
	@-echo $(SCI_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/sci_infineon_tricore/ssc/mak/infineon_sci_rules.mak
fr:
	@-echo $(FR_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/ssc/mak/infineon_fr_17_eray_rules.mak
lin:
	@-echo $(LIN_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_rules.mak
eth:
	@-echo $(ETH_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_rules.mak
cantrcv_17_6251G:
	@-echo $(CANTRCV_17_6251G_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6251G_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251G_rules.mak
cantrcv_17_6250GV33:
	@-echo $(CANTRCV_17_6250GV33_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6250GV33_infineon_tricore/ssc/mak/infineon_cantrcv_17_6250GV33_rules.mak
uart:
	@-echo $(UART_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_rules.mak
crc:
	@-echo $(CRC_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/crc_infineon_tricore/ssc/mak/infineon_crc_rules.mak
ramtst:
	@-echo $(RAMTST_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@-echo $(RAMTST_SSC_OBJECTS_1) >> $(LINK_INP_FILE)
	@-echo $(RAMTST_SSC_OBJECTS_2) >> $(LINK_INP_FILE)
	@-echo $(RAMTST_SSC_OBJECTS_3) >> $(LINK_INP_FILE)
	@-echo $(RAMTST_SSC_OBJECTS_4) >> $(LINK_INP_FILE)
	@-echo $(RAMTST_SSC_OBJECTS_5) >> $(LINK_INP_FILE)
	@-echo $(RAMTST_SSC_OBJECTS_6) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/ramtst_infineon_tricore/ssc/mak/infineon_ramtst_rules.mak
dsadc:
	@-echo $(DSADC_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dsadc_infineon_tricore/ssc/mak/infineon_dsadc_rules.mak
smu:
	@-echo $(SMU_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/smu_infineon_tricore/ssc/mak/infineon_smu_rules.mak
i2c:
	@-echo $(I2C_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/i2c_infineon_tricore/ssc/mak/infineon_i2c_rules.mak
os:
	@-echo $(OS_SSC_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/os_infineon_tricore/ssc/mak/infineon_os_rules.mak
