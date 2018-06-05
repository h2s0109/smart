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
#*  FILENAME  : base_make.mak                                                 **
#*                                                                            **
#*  VERSION   : 0.2.0                                                         **
#*                                                                            **
#*  DATE      : 2013-03-11                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines path variables of compiler,driver modules**
#*                 GNU Make path used accross the modules.                    **
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
#* AD           Abhishek Dwivedi                                              **
#* AT           Angeswaran Thangaswamy                                        **
#* RS           Roopa Sirur                                                   **
#* MP           Meenakshi Priyadarshini                                       **
#* JV           Jaidev Venkataraman                                           **
#* Rutuja       Rutuja Kawathekar                                             **
#* YG           Yogesh G                                                      **
#* SGN          Gururaj Nath S                                                **
#* AK           Ashish Kumar                                                  **
#* PM           Puneetha Mukherjee                                            **
#* SS           Srinivas Shenoy                                               **
#* KP           Kaushal Purohit                                               **
#* BM           Basheer Mohaideen                                             **
#* DNS          Deepak Nair S                                                 **
#* AJ           Abdul Jaffar                                                  **
#* JN           Jayaprakash Narayana                                          **
#* MK           Mundhra Karan                                                 **
#******************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  v0.2.0 : 2014-03-11, MK  : Added support for HSM
#*  v0.1.13: 2014-03-07, SS  : Added support for OS
#*  v0.1.12: 2013-10-10, JN  : Added support for I2C driver
#*  v0.1.11: 2013-09-24, AJ  : Added support for DSADC
#*  v0.1.10: 2013-09-24, Rutuja  : Added support for SMU
#*  v0.1.9: 2013-02-28, DNS: Updated for VendorApiInfix of PWM
#*  v0.1.8: 2013-02-25, SGN: Updated for VendorApiInfix of FLS
#*  v0.1.7: 2013-02-25, SGN: Updated for VendorApiInfix of CAN
#*  v0.1.6: 2013-02-21, BM: WDG changes for VendorApiInfix
#*  v0.1.5: 2013-02-21, SS: LIN changes for VendorApiInfix
#*  v0.1.4: 2013-02-15, SS: ICU changes for VendorApiInfix
#*  v0.1.3: 2012-11-02, AD: Support for CRC,BFC,UART
#*  v0.1.2: 2012-10-31, AK: Support for SENT
#*  v0.1.1: 2012-08-21, AT: Updated for GNU compiler
#*  v0.1.0: 2012-05-10, SGN: Corrected CAN path
#*  v0.0.9: 2011-03-10, YG:GPTA changed to GTM, FADC to SDADC for Aurix platform
#*  v0.0.8: 2010-02-15, PrakashG : AI00053231: File/Folder name change
#*                                    Fr to Fr_17_Eray, fr to fr_17_eray
#*  v0.0.7: 2009-10-21, SC       : Added support for RamTst driver
#*  v0.0.6: 2009.01.16, Prakash  : Added support for Fr driver
#*  v0.0.5: 2007.11.28, Rutuja  : Added Msc,Sci,CAN,Mchk
#*  v0.0.4: 2007.11.14, MP  : Changed the DELIVERY_WITH_TEST path
#*  V0.0.3: 2007.06.19, RS  : Added FEE, FLS,WDG, ICU
#*  V0.0.2: 2007.04.28, JV  : Changed INT to IRQ
#*  V0.0.1: 2007.02.23, RS  : Initial version for header file
#******************************************************************************/

# Define the base paths of all the driver modules,test stubs,complier.mak makefile

#SSC_ROOT = X:/aimmc_sw_aurix/03_Implementation/00_Source/Aurix_MC-ISAR

COMPILER_MAKE_PATH = $(SSC_ROOT)/mak/general/compiler

MCU_BASE_PATH = $(SSC_ROOT)/mcu_infineon_tricore

MLI_BASE_PATH = $(SSC_ROOT)/mli_infineon_tricore

GTM_BASE_PATH = $(SSC_ROOT)/mcu_infineon_tricore

HSSL_BASE_PATH = $(SSC_ROOT)/hssl_infineon_tricore

GPT_BASE_PATH = $(SSC_ROOT)/gpt_infineon_tricore

WDG_BASE_PATH = $(SSC_ROOT)/wdg_17_scu_infineon_tricore

ICU_BASE_PATH = $(SSC_ROOT)/icu_17_gtmccu6_infineon_tricore

PWM_BASE_PATH = $(SSC_ROOT)/pwm_17_gtm_infineon_tricore

SENT_BASE_PATH = $(SSC_ROOT)/sent_infineon_tricore

IOM_BASE_PATH = $(SSC_ROOT)/iom_infineon_tricore

DIO_BASE_PATH = $(SSC_ROOT)/dio_infineon_tricore

PORT_BASE_PATH = $(SSC_ROOT)/port_infineon_tricore

SPI_BASE_PATH = $(SSC_ROOT)/spi_infineon_tricore

STM_BASE_PATH = $(SSC_ROOT)/stm_infineon_tricore

MCALLIB_BASE_PATH = $(SSC_ROOT)/tricore_general

IRQ_BASE_PATH = $(SSC_ROOT)/irq_infineon_tricore

ECUM_BASE_PATH = $(SSC_ROOT)/ecum_infineon_tricore

CAN_BASE_PATH = $(SSC_ROOT)/can_17_mcanp_infineon_tricore

CANTRCV_17_6251G_BASE_PATH = $(SSC_ROOT)/cantrcv_17_6251G_infineon_tricore

CANTRCV_17_6250GV33_BASE_PATH = $(SSC_ROOT)/cantrcv_17_6250GV33_infineon_tricore

ADC_BASE_PATH = $(SSC_ROOT)/adc_infineon_tricore

SDADC_BASE_PATH = $(SSC_ROOT)/sdadc_infineon_tricore

DMA_BASE_PATH = $(SSC_ROOT)/dma_infineon_tricore

FLSLOADER_BASE_PATH = $(SSC_ROOT)/flsloader_infineon_tricore

FEE_BASE_PATH = $(SSC_ROOT)/fee_infineon_tricore

FLS_BASE_PATH = $(SSC_ROOT)/fls_17_pmu_infineon_tricore

WDG_BASE_PATH = $(SSC_ROOT)/wdg_17_scu_infineon_tricore

ERU_BASE_PATH = $(SSC_ROOT)/eru_infineon_tricore

MCHK_BASE_PATH = $(SSC_ROOT)/mchk_infineon_tricore

MSC_BASE_PATH = $(SSC_ROOT)/msc_infineon_tricore

SCI_BASE_PATH = $(SSC_ROOT)/sci_infineon_tricore

FR_BASE_PATH = $(SSC_ROOT)/fr_17_eray_infineon_tricore

LIN_BASE_PATH = $(SSC_ROOT)/lin_17_AscLin_infineon_tricore

STDLIN_BASE_PATH = $(SSC_ROOT)/stdlin_infineon_tricore

ETH_BASE_PATH = $(SSC_ROOT)/eth_17_ethmac_infineon_tricore

CRC_BASE_PATH = $(SSC_ROOT)/crc_infineon_tricore

BFX_BASE_PATH = $(SSC_ROOT)/bfx_infineon_tricore

UART_BASE_PATH = $(SSC_ROOT)/uart_infineon_tricore

SMU_BASE_PATH = $(SSC_ROOT)/smu_infineon_tricore

DSADC_BASE_PATH = $(SSC_ROOT)/dsadc_infineon_tricore

I2C_BASE_PATH = $(SSC_ROOT)/i2c_infineon_tricore

OS_BASE_PATH = $(SSC_ROOT)/os_infineon_tricore

HSM_BASE_PATH = $(SSC_HSM_ROOT)/hsm_infineon_tricore

# Select the path for test stub files based on module Test or demo application

ifeq ($(DELIVERY_WITH_TEST),1)
DET_FILE_PATH = $(TEST_ROOT)/integration_general/inc
DEM_FILE_PATH = $(TEST_ROOT)/integration_general/inc
OS_FILE_PATH = $(TEST_ROOT)/integration_general/inc
STDTEST_BASE_PATH = $(TEST_ROOT)/integration_general

else
DET_FILE_PATH = $(SSC_ROOT)/integration_general/inc
DEM_FILE_PATH = $(SSC_ROOT)/integration_general/inc
OS_FILE_PATH = $(SSC_ROOT)/integration_general/inc
STDTEST_BASE_PATH = $(SSC_ROOT)/integration_general
endif
