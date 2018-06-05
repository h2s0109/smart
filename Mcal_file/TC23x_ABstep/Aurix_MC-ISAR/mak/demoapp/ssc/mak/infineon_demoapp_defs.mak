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
#*  FILENAME  : infineon_demoapp_defs.mak                                     **
#*                                                                            **
#*  VERSION   : 0.2.0                                                         **
#*                                                                            **
#*  DATE      : 2014.03.11                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This is a public mak file which defines variables required **
#*                 to build the DemoApp file.                                 **
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
#* SK           Sai Kiran B                                                  **
#* VS           Vinod Shankar                                                **
#* PR           Pawan Reddy                                                  **
#* SGN          Gururaj Nath S                                               **
#* AK           Ashish Kumar                                                 **
#* PM           Puneetha Mukherjee                                           **
#* SS           Srinivas Shenoy                                              **
#* KP           Kaushal Purohit                                              **
#* BM           Basheer Mohaideen                                            **
#* AJ           Abdul Jaffar                                                 **
#* RK           Rutuja Kawathekar                                            **
#* JN           Jayaprakash Narayana                                         **
#* SS           Srinivas Shenoy                                              **
#* MK           Mundhra Karan                                                **
#*                                                                           **
#*****************************************************************************/

#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  VERSION   : 0.2.0 : MK: Updated for HSM                                   **
#*  VERSION   : 0.1.14: SS: Updated for OS                                    **
#*  VERSION   : 0.1.13: JN: Updated for I2C                                   **
#*  VERSION   : 0.1.12: RK: Updated for SMU                                   **
#*  VERSION   : 0.1.11: AJ: Updated for DSADC                                 **
#*  VERSION   : 0.1.10: SGN: VendorApiInfix changes for CAN                   **
#*  VERSION   : 0.1.9 : Vani: VendorApiInfix changes for FLS                  **
#*  VERSION   : 0.1.8 : BM: VendorApiInfix changes for WDG                    **
#*  VERSION   : 0.1.7 : KP: VendorApiInfix changes for LIN                    **
#*  VERSION   : 0.1.6 : SS: VendorApiInfix changes for ICU                    **
#*  VERSION   : 0.1.5 : AT: CanTrcv demo build disabled                       **
#*  VERSION   : 0.1.4 : SK: Updated for CanTrcv                               **
#*  VERSION   : 0.1.3 : PM: Updated for Hssl                                  **
#*  VERSION   : 0.1.2 : AK: Updated for SENT                                  **
#*  VERSION   : 0.1.2 : SGN: Updated for CAN path                             **
#*  VERSION   : 0.1.1 : VS: Adapted to UTP AI00064361                         **
#*  VERSION   : 0.1.0 : PR: Intial Version for Aurix                          **
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(COMPILER_MAKE_PATH)/compiler.mak
include $(SSC_ROOT)/mak/tricore_general/ssc/mak/infineon_mcallib_defs.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_general_defs.mak
include $(SSC_ROOT)/mak/irq_infineon_tricore/ssc/mak/infineon_irq_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak

TARGETS =
DEMO_TARGETS=
CLEAN_TARGETS =
POSTBUILD_TARGETS =
PRECOMPILE_TARGETS=
PBCFG_OBJECTS_LINK_ONLY=
#*******************************************************************************************
#MCU
#*******************************************************************************************
ifeq ($(MCU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_mcu_defs.mak
headers += $(MCU_DEP_HEADERS)
TARGETS += mcu
CLEAN_TARGETS += clean_mcu
APP_INCLUDE_DIRS += mcu_inc
OBJECTS_LINK_ONLY += $(MCU_SSC_OBJECTS)
ifeq ($(MCU_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(MCU_DEMO_OBJECTS)
headers += $(SSC_ROOT)/mcu_infineon_tricore/demo/inc/Mcu_Demo.h
DEMO_TARGETS += mcu_demo
endif
POSTBUILD_TARGETS += mcu_cfg
PBCFG_OBJECTS_LINK_ONLY = $(MCU_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#STM
#*******************************************************************************************
ifeq ($(STM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/stm_infineon_tricore/ssc/mak/infineon_stm_defs.mak
headers += $(STM_DEP_HEADERS)
headers += $(SSC_ROOT)/stm_infineon_tricore/demo/inc/Stm_Demo.h
TARGETS += stm
CLEAN_TARGETS += clean_stm
OBJECTS_LINK_ONLY += $(STM_SSC_OBJECTS)
ifeq ($(STM_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(STM_DEMO_OBJECTS)
headers += $(SSC_ROOT)/stm_infineon_tricore/demo/inc/Stm_Demo.h
DEMO_TARGETS += stm_demo
endif
endif
#*******************************************************************************************
#GTM
#*******************************************************************************************
ifeq ($(GTM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
headers += $(GTM_DEP_HEADERS)
TARGETS += gtm
CLEAN_TARGETS += clean_gtm
APP_INCLUDE_DIRS += gtm_inc
OBJECTS_LINK_ONLY += $(GTM_SSC_OBJECTS)

ifeq ($(GTM_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(GTM_DEMO_OBJECTS)
headers += $(SSC_ROOT)/mcu_infineon_tricore/demo/inc/Gtm_Demo.h
DEMO_TARGETS += gtm_demo
endif
POSTBUILD_TARGETS += gtm_cfg
PBCFG_OBJECTS_LINK_ONLY += $(GTM_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#*******************************************************************************************
#PORT
#*******************************************************************************************
ifeq ($(PORT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/port_infineon_tricore/ssc/mak/infineon_port_defs.mak
headers += $(PORT_DEP_HEADERS)
TARGETS += port
CLEAN_TARGETS += clean_port
APP_INCLUDE_DIRS += port_inc
OBJECTS_LINK_ONLY += $(PORT_SSC_OBJECTS)
POSTBUILD_TARGETS += port_cfg
PBCFG_OBJECTS_LINK_ONLY += $(PORT_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#DIO
#*******************************************************************************************
ifeq ($(DIO_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_defs.mak
headers += $(DIO_DEP_HEADERS)
TARGETS += dio
CLEAN_TARGETS += clean_dio
APP_INCLUDE_DIRS += dio_inc
OBJECTS_LINK_ONLY += $(DIO_SSC_OBJECTS)
ifeq ($(DIO_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(DIO_DEMO_OBJECTS)
headers += $(SSC_ROOT)/dio_infineon_tricore/demo/inc/Dio_Demo.h
DEMO_TARGETS += dio_demo
endif
ifeq ($(DIO_DELIVERY_MODE),VARIANTPB_SOURCE)
POSTBUILD_TARGETS += dio_cfg
PBCFG_OBJECTS_LINK_ONLY += $(DIO_PB_CFG_OBJECTS)
endif
ifeq ($(DIO_DELIVERY_MODE),VARIANTLT_SOURCE)
PRECOMPILE_TARGETS += dio_lcfg
OBJECTS_LINK_ONLY += $(DIO_LT_CFG_OBJECTS)
endif
endif



#*******************************************************************************************
#GPT
#*******************************************************************************************
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
headers += $(GPT_DEP_HEADERS)

TARGETS += gpt
CLEAN_TARGETS += clean_gpt
APP_INCLUDE_DIRS += gpt_inc
OBJECTS_LINK_ONLY += $(GPT_SSC_OBJECTS)

ifeq ($(GPT_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(GPT_DEMO_OBJECTS)
headers += $(SSC_ROOT)/gpt_infineon_tricore/demo/inc/Gpt_Demo.h
DEMO_TARGETS += gpt_demo
endif
POSTBUILD_TARGETS += gpt_cfg
PBCFG_OBJECTS_LINK_ONLY += $(GPT_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#SPI
#*******************************************************************************************
ifeq ($(SPI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak
headers += $(SPI_DEP_HEADERS)
headers += $(SSC_ROOT)/spi_infineon_tricore/demo/inc/Spi_Demo.h
TARGETS += spi
CLEAN_TARGETS += clean_spi
APP_INCLUDE_DIRS += spi_inc
OBJECTS_LINK_ONLY += $(SPI_SSC_OBJECTS)

ifeq ($(SPI_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(SPI_DEMO_OBJECTS)
headers += $(SSC_ROOT)/spi_infineon_tricore/demo/inc/Spi_Demo.h
DEMO_TARGETS += spi_demo
endif
POSTBUILD_TARGETS += spi_cfg
PBCFG_OBJECTS_LINK_ONLY += $(SPI_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#MLI
#*******************************************************************************************
ifeq ($(MLI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mli_infineon_tricore/ssc/mak/infineon_mli_defs.mak
headers += $(MLI_DEP_HEADERS)
headers += $(SSC_ROOT)/mli_infineon_tricore/demo/inc/Mli_Demo.h
TARGETS += mli
CLEAN_TARGETS += clean_mli
APP_INCLUDE_DIRS += mli_inc
OBJECTS_LINK_ONLY += $(MLI_SSC_OBJECTS)

ifeq ($(MLI_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(MLI_DEMO_OBJECTS)
headers += $(SSC_ROOT)/mli_infineon_tricore/demo/inc/Mli_Demo.h
DEMO_TARGETS += mli_demo
endif

POSTBUILD_TARGETS += mli_cfg
PBCFG_OBJECTS_LINK_ONLY += $(MLI_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#CAN
#*******************************************************************************************
ifeq ($(CAN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/can_17_mcanp_infineon_tricore/ssc/mak/infineon_can_17_mcanp_defs.mak
headers += $(CAN_DEP_HEADERS)
TARGETS += can
CLEAN_TARGETS += clean_can
APP_INCLUDE_DIRS += can_inc
OBJECTS_LINK_ONLY += $(CAN_SSC_OBJECTS)

ifeq ($(CAN_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(CAN_DEMO_OBJECTS)
headers += $(SSC_ROOT)/can_17_mcanp_infineon_tricore/demo/inc/Can_17_MCanP_Demo.h
DEMO_TARGETS += can_demo
endif
POSTBUILD_TARGETS += can_cfg
PBCFG_OBJECTS_LINK_ONLY += $(CAN_PB_CFG_OBJECTS)


endif


#*******************************************************************************************
#ADC
#*******************************************************************************************
ifeq ($(ADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak
headers += $(ADC_DEP_HEADERS)
headers += $(SSC_ROOT)/adc_infineon_tricore/demo/inc/Adc_Demo.h
TARGETS += adc
CLEAN_TARGETS += clean_adc
OBJECTS_LINK_ONLY += $(ADC_SSC_OBJECTS)

ifeq ($(ADC_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(ADC_DEMO_OBJECTS)
headers += $(SSC_ROOT)/adc_infineon_tricore/demo/inc/Adc_Demo.h
DEMO_TARGETS += adc_demo
endif
POSTBUILD_TARGETS += adc_cfg
PBCFG_OBJECTS_LINK_ONLY += $(ADC_PB_CFG_OBJECTS)


endif
#*******************************************************************************************
#BFX
#*******************************************************************************************
ifeq ($(BFX_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/bfx_infineon_tricore/ssc/mak/infineon_bfx_defs.mak
headers += $(BFX_DEP_HEADERS)
headers += $(SSC_ROOT)/bfx_infineon_tricore/demo/inc/Bfx_Demo.h
TARGETS += bfx
CLEAN_TARGETS += clean_bfx
OBJECTS_LINK_ONLY += $(BFX_SSC_OBJECTS)

ifeq ($(BFX_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(BFX_DEMO_OBJECTS)
headers += $(SSC_ROOT)/bfx_infineon_tricore/demo/inc/Bfx_Demo.h
DEMO_TARGETS += bfx_demo
endif

endif
#*******************************************************************************************
#HSM
#*******************************************************************************************
ifeq ($(HSM_DELIVERY),STD_ON)
include $(SSC_HSM_ROOT)/mak/hsm_infineon_tricore/ssc/mak/infineon_hsm_defs.mak
headers += $(HSM_DEP_HEADERS)
headers += $(SSC_HSM_ROOT)/hsm_infineon_tricore/demo/inc/Hsm_Demo.h
TARGETS += hsm
CLEAN_TARGETS += clean_hsm
OBJECTS_LINK_ONLY += $(HSM_SSC_OBJECTS)

ifeq ($(HSM_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(HSM_DEMO_OBJECTS)
headers += $(SSC_HSM_ROOT)/hsm_infineon_tricore/demo/inc/Hsm_Demo.h
DEMO_TARGETS += hsm_demo
endif

endif
#*******************************************************************************************
#FADC
#*******************************************************************************************

ifeq ($(FADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fadc_infineon_tricore/ssc/mak/infineon_fadc_defs.mak
headers += $(FADC_DEP_HEADERS)
headers += $(SSC_ROOT)/fadc_infineon_tricore/demo/inc/Fadc_Demo.h
TARGETS += fadc
CLEAN_TARGETS += clean_fadc
APP_INCLUDE_DIRS += fadc_inc
OBJECTS_LINK_ONLY += $(FADC_SSC_OBJECTS)

ifeq ($(FADC_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(FADC_DEMO_OBJECTS)
headers += $(SSC_ROOT)/fadc_infineon_tricore/demo/inc/Fadc_Demo.h
DEMO_TARGETS += fadc_demo
endif
POSTBUILD_TARGETS += fadc_cfg
PBCFG_OBJECTS_LINK_ONLY += $(FADC_PB_CFG_OBJECTS)

endif
#*******************************************************************************************
#PWM
#*******************************************************************************************

ifeq ($(PWM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_defs.mak
headers += $(PWM_DEP_HEADERS)
headers += $(SSC_ROOT)/pwm_17_gtm_infineon_tricore/demo/inc/Pwm_17_Gtm_Demo.h
TARGETS += pwm
CLEAN_TARGETS += clean_pwm
APP_INCLUDE_DIRS += pwm_inc
OBJECTS_LINK_ONLY += $(PWM_SSC_OBJECTS)

ifeq ($(PWM_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(PWM_DEMO_OBJECTS)
headers += $(SSC_ROOT)/pwm_17_gtm_infineon_tricore/demo/inc/Pwm_17_Gtm_Demo.h
DEMO_TARGETS += pwm_demo
endif
POSTBUILD_TARGETS += pwm_cfg
PBCFG_OBJECTS_LINK_ONLY += $(PWM_PB_CFG_OBJECTS)

endif
#*******************************************************************************************
#SENT
#*******************************************************************************************

ifeq ($(SENT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sent_infineon_tricore/ssc/mak/infineon_sent_defs.mak
headers += $(SENT_DEP_HEADERS)
TARGETS += sent
CLEAN_TARGETS += clean_sent
OBJECTS_LINK_ONLY += $(SENT_SSC_OBJECTS)

ifeq ($(SENT_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(SENT_DEMO_OBJECTS)
headers += $(SSC_ROOT)/sent_infineon_tricore/demo/inc/Sent_Demo.h
DEMO_TARGETS += sent_demo
endif
POSTBUILD_TARGETS += sent_cfg
PBCFG_OBJECTS_LINK_ONLY += $(SENT_PB_CFG_OBJECTS)

endif

#*******************************************************************************************
#IOM
#*******************************************************************************************

ifeq ($(IOM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/iom_infineon_tricore/ssc/mak/infineon_iom_defs.mak
headers += $(IOM_DEP_HEADERS)
TARGETS += iom
CLEAN_TARGETS += clean_iom
OBJECTS_LINK_ONLY += $(IOM_SSC_OBJECTS)

ifeq ($(IOM_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(IOM_DEMO_OBJECTS)
headers += $(SSC_ROOT)/iom_infineon_tricore/demo/inc/Iom_Demo.h
DEMO_TARGETS += iom_demo
endif
POSTBUILD_TARGETS += iom_cfg
PBCFG_OBJECTS_LINK_ONLY += $(IOM_PB_CFG_OBJECTS)

endif
#*******************************************************************************************
#DMA
#*******************************************************************************************

ifeq ($(DMA_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_defs.mak
headers += $(DMA_DEP_HEADERS)
TARGETS += dma
CLEAN_TARGETS += clean_dma
APP_INCLUDE_DIRS += dma_inc
OBJECTS_LINK_ONLY += $(DMA_SSC_OBJECTS)

ifeq ($(DMA_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(DMA_DEMO_OBJECTS)
headers += $(SSC_ROOT)/dma_infineon_tricore/demo/inc/Dma_Demo.h
DEMO_TARGETS += dma_demo
endif
POSTBUILD_TARGETS += dma_cfg
PBCFG_OBJECTS_LINK_ONLY += $(DMA_PB_CFG_OBJECTS)

endif
#*******************************************************************************************
#FLSLOADER
#*******************************************************************************************

ifeq ($(FLSLOADER_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_defs.mak
headers += $(FLSLOADER_DEP_HEADERS)
headers += $(SSC_ROOT)/flsloader_infineon_tricore/demo/inc/FlsLoader_Demo.h
TARGETS += flsloader
CLEAN_TARGETS += clean_flsloader
APP_INCLUDE_DIRS += flsloader_inc
OBJECTS_LINK_ONLY += $(FLSLOADER_OBJECTS)

ifeq ($(FLSLOADER_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(FLSLOADER_DEMO_OBJECTS)
headers += $(SSC_ROOT)/flsloader_infineon_tricore/demo/inc/FlsLoader_Demo.h
DEMO_TARGETS += flsloader_demo
endif

endif

#*******************************************************************************************
#HSSL
#*******************************************************************************************

ifeq ($(HSSL_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/hssl_infineon_tricore/ssc/mak/infineon_hssl_defs.mak
headers += $(HSSL_DEP_HEADERS)
headers += $(SSC_ROOT)/hssl_infineon_tricore/demo/inc/Hssl_Demo.h
TARGETS += hssl
CLEAN_TARGETS += clean_fee
APP_INCLUDE_DIRS += hssl_inc
OBJECTS_LINK_ONLY += $(HSSL_OBJECTS)

ifeq ($(HSSL_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(HSSL_DEMO_OBJECTS)
headers += $(SSC_ROOT)/hssl_infineon_tricore/demo/inc/Hssl_Demo.h
DEMO_TARGETS += hssl_demo
endif
PRECOMPILE_TARGETS += hssl_cfg
OBJECTS_LINK_ONLY += $(HSSL_CFG_OBJECTS)

endif

#*******************************************************************************************
#*******************************************************************************************
#FLS
#*******************************************************************************************

ifeq ($(FLS_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_defs.mak
headers += $(FLS_DEP_HEADERS)
headers += $(SSC_ROOT)/fls_17_pmu_infineon_tricore/demo/inc/fls_17_pmu_Demo.h
TARGETS += fls
CLEAN_TARGETS += clean_fls
APP_INCLUDE_DIRS += fls_inc
OBJECTS_LINK_ONLY += $(FLS_OBJECTS)

ifeq ($(FLS_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(FLS_DEMO_OBJECTS)
headers += $(SSC_ROOT)/fls_17_pmu_infineon_tricore/demo/inc/Fls_17_Pmu_Demo.h
DEMO_TARGETS += fls_demo
endif
POSTBUILD_TARGETS += fls_cfg
PBCFG_OBJECTS_LINK_ONLY += $(FLS_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#FEE
#*******************************************************************************************

ifeq ($(FEE_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fee_infineon_tricore/ssc/mak/infineon_fee_defs.mak
headers += $(FEE_DEP_HEADERS)
headers += $(SSC_ROOT)/fee_infineon_tricore/demo/inc/fee_Demo.h
TARGETS += fee
CLEAN_TARGETS += clean_fee
APP_INCLUDE_DIRS += fee_inc
OBJECTS_LINK_ONLY += $(FEE_OBJECTS)

ifeq ($(FEE_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(FEE_DEMO_OBJECTS)
headers += $(SSC_ROOT)/fee_infineon_tricore/demo/inc/Fee_Demo.h
DEMO_TARGETS += fee_demo
endif
PRECOMPILE_TARGETS += fee_cfg
OBJECTS_LINK_ONLY += $(FEE_CFG_OBJECTS)

endif
#*******************************************************************************************
#WDG
#*******************************************************************************************

ifeq ($(WDG_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_defs.mak
headers += $(WDG_DEP_HEADERS)
headers += $(SSC_ROOT)/wdg_17_scu_infineon_tricore/demo/inc/Wdg_17_Scu_Demo.h
TARGETS += wdg
CLEAN_TARGETS += clean_wdg
APP_INCLUDE_DIRS += wdg_inc
OBJECTS_LINK_ONLY += $(WDG_SSC_OBJECTS)

ifeq ($(WDG_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(WDG_DEMO_OBJECTS)
headers += $(SSC_ROOT)/wdg_17_scu_infineon_tricore/demo/inc/Wdg_17_Scu_Demo.h
DEMO_TARGETS += wdg_demo
endif
POSTBUILD_TARGETS += wdg_cfg
PBCFG_OBJECTS_LINK_ONLY += $(WDG_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#ICU
#*******************************************************************************************

ifeq ($(ICU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_defs.mak
headers += $(ICU_DEP_HEADERS)
headers += $(SSC_ROOT)/icu_17_gtmccu6_infineon_tricore/demo/inc/Icu_17_GtmCcu6_Demo.h
TARGETS += icu
CLEAN_TARGETS += clean_icu
APP_INCLUDE_DIRS += icu_inc
OBJECTS_LINK_ONLY += $(ICU_SSC_OBJECTS)

ifeq ($(ICU_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(ICU_DEMO_OBJECTS)
headers += $(SSC_ROOT)/icu_17_gtmccu6_infineon_tricore/demo/inc/Icu_17_GtmCcu6_Demo.h
DEMO_TARGETS += icu_demo
endif
POSTBUILD_TARGETS += icu_cfg
PBCFG_OBJECTS_LINK_ONLY += $(ICU_PB_CFG_OBJECTS)
endif
#*******************************************************************************************
#ERU
#*******************************************************************************************

ifeq ($(ERU_DELIVERY),STD_ON)

endif

#*******************************************************************************************
# MSC
#*******************************************************************************************
ifeq ($(MSC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/msc_infineon_tricore/ssc/mak/infineon_msc_defs.mak
headers += $(MSC_DEP_HEADERS)
TARGETS += msc
CLEAN_TARGETS += clean_msc
APP_INCLUDE_DIRS += msc_inc
OBJECTS_LINK_ONLY += $(MSC_SSC_OBJECTS)

ifeq ($(MSC_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(MSC_DEMO_OBJECTS)
headers += $(SSC_ROOT)/msc_infineon_tricore/demo/inc/Msc_Demo.h
DEMO_TARGETS += msc_demo
endif
POSTBUILD_TARGETS += msc_cfg
PBCFG_OBJECTS_LINK_ONLY += $(MSC_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
# MCHK
#*******************************************************************************************
ifeq ($(MCHK_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mchk_infineon_tricore/ssc/mak/infineon_mchk_defs.mak
headers += $(MCHK_DEP_HEADERS)
TARGETS += mchk
CLEAN_TARGETS += clean_mchk
APP_INCLUDE_DIRS += mchk_inc
OBJECTS_LINK_ONLY += $(MCHK_SSC_OBJECTS)

ifeq ($(MCHK_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(MCHK_DEMO_OBJECTS)
headers += $(SSC_ROOT)/mchk_infineon_tricore/demo/inc/Mchk_Demo.h
DEMO_TARGETS += mchk_demo
endif
POSTBUILD_TARGETS += mchk_cfg
PBCFG_OBJECTS_LINK_ONLY += $(MCHK_PB_CFG_OBJECTS)
endif


#*******************************************************************************************
#SCI
#*******************************************************************************************
ifeq ($(SCI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/sci_infineon_tricore/ssc/mak/infineon_sci_defs.mak
headers += $(SCI_DEP_HEADERS)
TARGETS += sci
CLEAN_TARGETS += clean_sci
OBJECTS_LINK_ONLY += $(SCI_SSC_OBJECTS)

ifeq ($(SCI_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(SCI_DEMO_OBJECTS)
headers += $(SSC_ROOT)/sci_infineon_tricore/demo/inc/Sci_Demo.h
DEMO_TARGETS += sci_demo
endif
POSTBUILD_TARGETS += sci_cfg
PBCFG_OBJECTS_LINK_ONLY += $(SCI_PB_CFG_OBJECTS)
PRECOMPILE_TARGETS += sci_lcfg
OBJECTS_LINK_ONLY += $(SCI_LT_CFG_OBJECTS)
endif

#*******************************************************************************************
#FR
#*******************************************************************************************
ifeq ($(FR_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/ssc/mak/infineon_fr_17_eray_defs.mak
headers += $(FR_DEP_HEADERS)
TARGETS += fr
CLEAN_TARGETS += clean_fr
APP_INCLUDE_DIRS += fr_inc
OBJECTS_LINK_ONLY += $(FR_SSC_OBJECTS)

ifeq ($(FR_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(FR_DEMO_OBJECTS)
headers += $(SSC_ROOT)/fr_17_eray_infineon_tricore/demo/inc/Fr_17_Eray_Demo.h
DEMO_TARGETS += fr_demo
endif
POSTBUILD_TARGETS += fr_cfg
PBCFG_OBJECTS_LINK_ONLY += $(FR_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
#LIN
#*******************************************************************************************
ifeq ($(LIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_defs.mak
headers += $(LIN_DEP_HEADERS)
TARGETS += lin
CLEAN_TARGETS += clean_lin
APP_INCLUDE_DIRS += lin_inc
OBJECTS_LINK_ONLY += $(LIN_SSC_OBJECTS)

ifeq ($(LIN_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(LIN_DEMO_OBJECTS)
headers += $(SSC_ROOT)/lin_17_AscLin_infineon_tricore/demo/inc/Lin_17_AscLin_Demo.h
DEMO_TARGETS += lin_demo
endif
POSTBUILD_TARGETS += lin_cfg
PBCFG_OBJECTS_LINK_ONLY += $(LIN_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
#ETH
#*******************************************************************************************
ifeq ($(ETH_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_defs.mak
headers += $(ETH_DEP_HEADERS)
TARGETS += eth
CLEAN_TARGETS += clean_eth
APP_INCLUDE_DIRS += eth_inc
OBJECTS_LINK_ONLY += $(ETH_SSC_OBJECTS)

ifeq ($(ETH_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(ETH_DEMO_OBJECTS)
headers += $(SSC_ROOT)/eth_17_ethmac_infineon_tricore/demo/inc/Eth_17_EthMac_Demo.h
DEMO_TARGETS += eth_demo
endif
POSTBUILD_TARGETS += eth_cfg
PBCFG_OBJECTS_LINK_ONLY += $(ETH_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
#CRC
#*******************************************************************************************

ifeq ($(CRC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/crc_infineon_tricore/ssc/mak/infineon_crc_defs.mak
headers += $(CRC_DEP_HEADERS)
headers += $(SSC_ROOT)/crc_infineon_tricore/demo/inc/Crc_Demo.h
TARGETS += crc
CLEAN_TARGETS += clean_crc
APP_INCLUDE_DIRS += crc_inc
OBJECTS_LINK_ONLY += $(CRC_OBJECTS)

ifeq ($(CRC_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(CRC_DEMO_OBJECTS)
headers += $(SSC_ROOT)/crc_infineon_tricore/demo/inc/Crc_Demo.h
DEMO_TARGETS += crc_demo
endif

endif

#*******************************************************************************************
#CANTRCV 6251G
#*******************************************************************************************

ifeq ($(CANTRCV_6251G_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251g_defs.mak
headers += $(CANTRCV_17_6251G_DEP_HEADERS)
headers += $(SSC_ROOT)/cantrcv_17_6251g_infineon_tricore/demo/inc/CanTrcv_17_6251G_Demo.h
TARGETS += cantrcv_17_6251G
CLEAN_TARGETS += clean_cantrcv_17_6251G
APP_INCLUDE_DIRS += cantrcv_17_6251G_inc
OBJECTS_LINK_ONLY += $(CANTRCV_17_6251G_SSC_OBJECTS)

ifeq ($(CANTRCV_17_6251G_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(CANTRCV_17_6251G_DEMO_OBJECTS)
headers += $(SSC_ROOT)/cantrcv_17_6251g_infineon_tricore/demo/inc/CanTrcv_17_6251G_Demo.h
DEMO_TARGETS += cantrcv_17_6251G_demo
PRECOMPILE_TARGETS += cantrcv_17_6251G_cfg
OBJECTS_LINK_ONLY += $(CANTRCV_17_6251G_PC_CFG_OBJECTS)
endif



endif

#*******************************************************************************************
#CANTRCV 6250GV33
#*******************************************************************************************

ifeq ($(CANTRCV_6250GV33_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/ssc/mak/infineon_cantrcv_17_6250gv33_defs.mak
headers += $(CANTRCV_17_6250GV33_DEP_HEADERS)
headers += $(SSC_ROOT)/cantrcv_17_6250gv33_infineon_tricore/demo/inc/CanTrcv_17_6250GV33_Demo.h
TARGETS += cantrcv_17_6250GV33
CLEAN_TARGETS += clean_cantrcv_17_6250GV33
APP_INCLUDE_DIRS += cantrcv_17_6250GV33_inc
OBJECTS_LINK_ONLY += $(CANTRCV_17_6250GV33_SSC_OBJECTS)

ifeq ($(CANTRCV_17_6250GV33_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(CANTRCV_17_6250GV33_DEMO_OBJECTS)
headers += $(SSC_ROOT)/cantrcv_17_6250gv33_infineon_tricore/demo/inc/CanTrcv_17_6250GV33_Demo.h
DEMO_TARGETS += cantrcv_17_6250gv33_demo
PRECOMPILE_TARGETS += cantrcv_17_6250GV33_cfg
OBJECTS_LINK_ONLY += $(CANTRCV_17_6250GV33_PC_CFG_OBJECTS)
endif



endif
#*******************************************************************************************
#STDLIN
#*******************************************************************************************

ifeq ($(STDLIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/stdlin_infineon_tricore/ssc/mak/infineon_stdlin_defs.mak
headers += $(STDLIN_DEP_HEADERS)
headers += $(SSC_ROOT)/stdlin_infineon_tricore/demo/inc/StdLin_Demo.h
TARGETS += stdlin
CLEAN_TARGETS += clean_stdlin
APP_INCLUDE_DIRS += stdlin_inc
OBJECTS_LINK_ONLY += $(STDLIN_SSC_OBJECTS)

ifeq ($(STDLIN_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(STDLIN_DEMO_OBJECTS)
headers += $(SSC_ROOT)/stdlin_infineon_tricore/demo/inc/StdLin_Demo.h
DEMO_TARGETS += stdlin_demo
endif
PRECOMPILE_TARGETS += stdlin_cfg
OBJECTS_LINK_ONLY += $(STDLIN_CFG_OBJECTS)
endif

#*******************************************************************************************
#UART
#*******************************************************************************************
ifeq ($(UART_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_defs.mak
headers += $(UART_DEP_HEADERS)
TARGETS += uart
CLEAN_TARGETS += clean_uart
APP_INCLUDE_DIRS += uart_inc
OBJECTS_LINK_ONLY += $(UART_SSC_OBJECTS)

ifeq ($(UART_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(UART_DEMO_OBJECTS)
headers += $(SSC_ROOT)/uart_infineon_tricore/demo/inc/Uart_Demo.h
DEMO_TARGETS += uart_demo
endif
POSTBUILD_TARGETS += uart_cfg
PBCFG_OBJECTS_LINK_ONLY += $(UART_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
# DSADC
#*******************************************************************************************
ifeq ($(DSADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/dsadc_infineon_tricore/ssc/mak/infineon_dsadc_defs.mak
headers += $(DSADC_DEP_HEADERS)
TARGETS += dsadc
CLEAN_TARGETS += clean_dsadc
APP_INCLUDE_DIRS += dsadc_inc
OBJECTS_LINK_ONLY += $(DSADC_SSC_OBJECTS)

ifeq ($(DSADC_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(DSADC_DEMO_OBJECTS)
headers += $(SSC_ROOT)/dsadc_infineon_tricore/demo/inc/Dsadc_Demo.h
DEMO_TARGETS += dsadc_demo
endif
POSTBUILD_TARGETS += dsadc_cfg
PBCFG_OBJECTS_LINK_ONLY += $(DSADC_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
# SMU
#*******************************************************************************************
ifeq ($(SMU_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/smu_infineon_tricore/ssc/mak/infineon_smu_defs.mak
headers += $(SMU_DEP_HEADERS)
TARGETS += smu
CLEAN_TARGETS += clean_smu
APP_INCLUDE_DIRS += smu_inc
OBJECTS_LINK_ONLY += $(SMU_SSC_OBJECTS)

ifeq ($(SMU_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(SMU_DEMO_OBJECTS)
headers += $(SSC_ROOT)/smu_infineon_tricore/demo/inc/Smu_Demo.h
DEMO_TARGETS += smu_demo
endif
POSTBUILD_TARGETS += smu_cfg
PBCFG_OBJECTS_LINK_ONLY += $(SMU_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
# I2C
#*******************************************************************************************
ifeq ($(I2C_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/i2c_infineon_tricore/ssc/mak/infineon_i2c_defs.mak
headers += $(I2C_DEP_HEADERS)
TARGETS += i2c
CLEAN_TARGETS += clean_i2c
APP_INCLUDE_DIRS += i2c_inc
OBJECTS_LINK_ONLY += $(I2C_SSC_OBJECTS)

ifeq ($(I2C_DEMO),STD_ON)
OBJECTS_LINK_ONLY += $(I2C_DEMO_OBJECTS)
headers += $(SSC_ROOT)/i2c_infineon_tricore/demo/inc/I2c_Demo.h
DEMO_TARGETS += i2c_demo
endif
POSTBUILD_TARGETS += i2c_cfg
PBCFG_OBJECTS_LINK_ONLY += $(I2C_PB_CFG_OBJECTS)
endif

#*******************************************************************************************
#OS
#*******************************************************************************************
ifeq ($(OS_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/os_infineon_tricore/ssc/mak/infineon_os_defs.mak
TARGETS += os

OBJECTS_LINK_ONLY += $(OS_SSC_OBJECTS)
endif

#*******************************************************************************************
#ECUM
#*******************************************************************************************


PBCFG_OBJECTS_LINK_ONLY += $(ECUM_PB_CFG_OBJECTS)




#******************************************************************************
# The final output name - with output format elf. Map file will also come in the same name
# specified below
#******************************************************************************


PROJCFGNAME = DemoAppPBConfiguration

MODULE = demoapp


#******************************************************************************
# The following are the header files needed for compiling Test_Module.c
# This is an application file, For adding the dependant header files, keep adding the
#  module dep variables For example GPT_DEP_HEADERS holds Gpt.h and associated GPT_Cfg.h
#******************************************************************************

headers += $(STANDARD_DEPENDANCY) $(DET_FILE_PATH)/Det.h $(STDTEST_BASE_PATH)/inc/Test_Print.h $(SSC_ROOT)/DemoApp/inc/DemoApp_FctCall.h
headers += $(STDTEST_BASE_PATH)/inc/Test_Main.h $(STDTEST_BASE_PATH)/inc/Test_Time.h

#******************************************************************************
# An input file is required to spool in all the object files and pass it to the linker.
# Its mandatory to use a file to read the inputs to a linker.
# Windows has the limitation: There should not be more than 1024 characters to execute any command.
# If more than 1024 characters are used then The input line is too long error occurs.
# As this poses a severe limitation, file must be used to pass into a linker.
#******************************************************************************

LINK_INP_FILE = obj_link_files.txt

PBCFG_LINK_INP_FILE = cfg_link_files.txt
#******************************************************************************
# Add all the necessary include paths for your application files
#******************************************************************************

APPLN_INCLUDE_PATH += $(CC_INC) $(PROJINC)

#******************************************************************************
# The variable OBJECTS_LINK_ONLY has the list of all objects that needs to be built for making the link file.
# This variable has all the values as a result of including all the .defs file.
# To have a clear cut distinction APPLN_OBJECTS are separated out.
#******************************************************************************

OBJECTS_LINK_ONLY += $(IRQ_OBJECTS)
OBJECTS_LINK_ONLY += $(STDTEST_OBJECTS)
OBJECTS_LINK_ONLY += $(ECUM_OBJECTS)

APPLN_OBJECTS = $(OUTDIR)/DemoApp.$(OBJ_FILE_SUFFIX)
ifeq ($(PERL_AVAILABLE),YES)
APPLN_OBJECTS += $(OUTDIR)/DemoApp_FctCall.$(OBJ_FILE_SUFFIX)
endif

DEMOAPP_INC_PATHS_FILE = demoapp_include_path.ifx


#*********************************************************************************
#setting up post build targets
#*********************************************************************************

ifeq ($(APP_CONFIG),POSTBUILD_SELECTABLE)

PROJNAME = DemoAppSelectable
endif

ifeq ($(APP_CONFIG),POSTBUILD_LOADABLE)

PROJNAME = DemoAppLoadable
endif

export BATCH_PATH ?= $(CURDIR)
BATCH_PATH := $(subst /,\,$(BATCH_PATH))

PERL_SCRIPT_PATH = $(BATCH_PATH)/_scripts
PERL_PATH = $(SSC_ROOT)/../perl
PERL      = $(PERL_TOOLPATH)/perl.exe
