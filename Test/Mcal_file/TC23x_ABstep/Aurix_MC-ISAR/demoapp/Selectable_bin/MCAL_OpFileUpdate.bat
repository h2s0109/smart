@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2013)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : MCAL_OpFileUpdate.bat                                      **
REM *                                                                         **
REM *  VERSION   : 0.1.8                                                      **
REM *                                                                         **
REM *  DATE      : 2013-10-10                                                 **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file moves the files from output directory of      **
REM *                 codegenerator to respective modules                     **
REM *                                                                         **
REM *                                                                         **
REM *  MAY BE CHANGED BY USER [yes/no]: YES                                   **
REM *                                                                         **
REM ***************************************************************************/

REM ****************************************************************************
REM *                      Author(s) Identity                                 **
REM ****************************************************************************
REM *                                                                         **
REM * Initials     Name                                                       **
REM * ------------------------------------------------------------------------**
REM * PR           Pawan Reddy                                                **
REM * SK           Sai Kiran                                                  **
REM * Rutuja       Rutuja Kawathekar                                          **
REM * SGN          Gururaj Nath S                                             **
REM * MM           Mohammed Mustaq                                            **
REM * AK           Ashish Kumar                                               **
REM * DNS          Deepak Nair S                                              **
REM * SS           Srinivas Shenoy                                            **
REM * KP           Kaushal Purohit                                            **
REM * DNS          Deepak Nair S                                              **
REM * AJ           Abdul Jaffar                                               **
REM * JN           Jayaprakash Narayana                                       **
REM ***************************************************************************/


REM ****************************************************************************
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM * V0.1.8 : 2013-10-10, JN : I2C Module added
REM * V0.1.7 : 2013-09-25, Rutuja : added SMU Module
REM * V0.1.6 : 2013-09-24, AJ : DSADC Module added
REM * V0.1.5 : 2013-07-26, SK : StdLin Module added
REM * V0.1.4 : 2013-07-25, AK : SENT Lcfg file copy added
REM * V0.1.3 : 2013-07-23, KP : GTM Lcfg file copy changes added UTP[AI00198181]
REM * V0.1.2 : 2013-07-03, AK : MCU generated makefile copy added
REM * V0.1.1 : 2013-02-28, DNS : VendorApiInfix changes for PWM
REM * V0.1.0 : 2013-02-26, Vani: VendorApiInfix changes for FLS
REM * V0.0.19: 2013-02-25, SGN: VendorApiInfix changes for CAN
REM * v0.0.18: 2013-02-21, SS : VendorApiInfix changes for LIN
REM * v0.0.17: 2013-02-15, SS : VendorApiInfix changes for ICU
REM * v0.0.16: 2012-10-30, DNS : Support for UART
REM * v0.0.16: 2012-10-19, AK : Support for SENT
REM * v0.0.15: 2012-08-07, SGN : Corrected FEE path
REM * v0.0.14: 2012-06-06, MM  :  Added Path for Dio_Lcfg.c
REM * v0.0.13: 2012-05-10, SGN  :  Corrected CAN path
REM * v0.0.12: 2011-03-22, PR   :  added DemoApp_cfg.h

REM * v0.0.11: 2011-03-10, SKB   :  Corrected the file path for generated files.
REM * v0.0.10: 2011-03-10, YG    :  Replace GPTA with GTM , FADC with SDADC for AURIX platforms
REM * v1.2.0: 2010.02.09, Prakash :
REM              - UTP AI00053231: Fr --> Fr_17_Eray, FR --> FR_17_ERAY
REM * v0.0.8: 2009-10-21, SC    :  Added RAMTEST
REM * v0.0.7: 2009.06.01, Hamzath: Changes to support AudoS CONTROLLER->CONTROLLER_PLUGIN
REM * v0.0.6: 2009.04.12, Prakash: Added support for Fr
REM * v0.0.5: 2008.01.30, Basheer: Added If exist before copy
REM * v0.0.4: 2008.01.02, Hamzath: Added Demo files
REM * v0.0.3: 2007.11.28, Rutuja : Added Mchk
REM * v0.0.2: 2007.11.28, Rutuja : Added Msc,Sci
REM * V0.0.1: 2007.09.20, RS  : Initial version
REM *
REM ***************************************************************************/

@ECHO OFF

REM ****************************************************************************
REM Sets the root path of the AUTOSAR MCAL2 directory
REM ****************************************************************************

SET GNU_MAKE_PATH=%~dp0
SET GNU_MAKE_PATH=%GNU_MAKE_PATH:\Aurix_MC-ISAR\demoapp\Selectable_bin\=%
SET GNU_MAKE_PATH=%GNU_MAKE_PATH%\GNU

SET MCAL_BASE_PATH=%~dp0
SET MCAL_BASE_PATH=%MCAL_BASE_PATH:\demoapp\Selectable_bin\=%
SET MCAL_BASE_PATH=%MCAL_BASE_PATH: =" "%

REM ****************************************************************************
REM Mod_Cfg.c and Mod_Cfg.h directory path for each module

REM ****************************************************************************
SET DIO_SRC_PATH=%MCAL_BASE_PATH%\dio_infineon_tricore\cfg1\src
SET DIO_INC_PATH=%MCAL_BASE_PATH%\dio_infineon_tricore\cfg1\inc

SET PORT_SRC_PATH=%MCAL_BASE_PATH%\port_infineon_tricore\cfg1\src
SET PORT_INC_PATH=%MCAL_BASE_PATH%\port_infineon_tricore\cfg1\inc
SET UART_SRC_PATH=%MCAL_BASE_PATH%\uart_infineon_tricore\cfg1\src
SET UART_INC_PATH=%MCAL_BASE_PATH%\uart_infineon_tricore\cfg1\inc

SET MCU_SRC_PATH=%MCAL_BASE_PATH%\mcu_infineon_tricore\cfg1\src
SET MCU_INC_PATH=%MCAL_BASE_PATH%\mcu_infineon_tricore\cfg1\inc
SET MCU_MAK_PATH=%MCAL_BASE_PATH%\mak\mcu_infineon_tricore\ssc\mak

SET HSSL_SRC_PATH=%MCAL_BASE_PATH%\hssl_infineon_tricore\cfg1\src
SET HSSL_INC_PATH=%MCAL_BASE_PATH%\hssl_infineon_tricore\cfg1\inc

SET GPT_SRC_PATH=%MCAL_BASE_PATH%\gpt_infineon_tricore\cfg1\src
SET GPT_INC_PATH=%MCAL_BASE_PATH%\gpt_infineon_tricore\cfg1\inc

SET GTM_SRC_PATH=%MCAL_BASE_PATH%\mcu_infineon_tricore\cfg1\src
SET GTM_INC_PATH=%MCAL_BASE_PATH%\mcu_infineon_tricore\cfg1\inc

SET SPI_SRC_PATH=%MCAL_BASE_PATH%\spi_infineon_tricore\cfg1\src
SET SPI_INC_PATH=%MCAL_BASE_PATH%\spi_infineon_tricore\cfg1\inc

SET ICU_SRC_PATH=%MCAL_BASE_PATH%\icu_17_gtmccu6_infineon_tricore\cfg1\src
SET ICU_INC_PATH=%MCAL_BASE_PATH%\icu_17_gtmccu6_infineon_tricore\cfg1\inc

SET WDG_SRC_PATH=%MCAL_BASE_PATH%\wdg_17_scu_infineon_tricore\cfg1\src
SET WDG_INC_PATH=%MCAL_BASE_PATH%\wdg_17_scu_infineon_tricore\cfg1\inc
SET WDG_MAK_PATH=%MCAL_BASE_PATH%\mak\wdg_17_scu_infineon_tricore\ssc\mak

SET PWM_SRC_PATH=%MCAL_BASE_PATH%\pwm_17_gtm_infineon_tricore\cfg1\src
SET PWM_INC_PATH=%MCAL_BASE_PATH%\pwm_17_gtm_infineon_tricore\cfg1\inc

SET ADC_SRC_PATH=%MCAL_BASE_PATH%\adc_infineon_tricore\cfg1\src
SET ADC_INC_PATH=%MCAL_BASE_PATH%\adc_infineon_tricore\cfg1\inc

SET SDADC_SRC_PATH=%MCAL_BASE_PATH%\sdadc_infineon_tricore\cfg1\src
SET SDADC_INC_PATH=%MCAL_BASE_PATH%\sdadc_infineon_tricore\cfg1\inc

SET DMA_SRC_PATH=%MCAL_BASE_PATH%\dma_infineon_tricore\cfg1\src
SET DMA_INC_PATH=%MCAL_BASE_PATH%\dma_infineon_tricore\cfg1\inc

SET ECUM_SRC_PATH=%MCAL_BASE_PATH%\ecum_infineon_tricore\cfg1\src
SET ECUM_INC_PATH=%MCAL_BASE_PATH%\ecum_infineon_tricore\cfg1\inc
SET ECUM_LCFG_PATH=%MCAL_BASE_PATH%\ecum_infineon_tricore\cfg1\src

SET FLSLOADER_INC_PATH=%MCAL_BASE_PATH%\flsloader_infineon_tricore\cfg1\inc

SET IRQ_INC_PATH=%MCAL_BASE_PATH%\irq_infineon_tricore\cfg1\inc

SET FEE_SRC_PATH=%MCAL_BASE_PATH%\fee_infineon_tricore\cfg1\src
SET FEE_INC_PATH=%MCAL_BASE_PATH%\fee_infineon_tricore\cfg1\inc

SET FLS_SRC_PATH=%MCAL_BASE_PATH%\fls_17_pmu_infineon_tricore\cfg1\src
SET FLS_INC_PATH=%MCAL_BASE_PATH%\fls_17_pmu_infineon_tricore\cfg1\inc

SET MLI_SRC_PATH=%MCAL_BASE_PATH%\mli_infineon_tricore\cfg1\src
SET MLI_INC_PATH=%MCAL_BASE_PATH%\mli_infineon_tricore\cfg1\inc

SET ERU_SRC_PATH=%MCAL_BASE_PATH%\eru_infineon_tricore\cfg1\src
SET ERU_INC_PATH=%MCAL_BASE_PATH%\eru_infineon_tricore\cfg1\inc

SET CAN_SRC_PATH=%MCAL_BASE_PATH%\can_17_mcanp_infineon_tricore\cfg1\src
SET CAN_INC_PATH=%MCAL_BASE_PATH%\can_17_mcanp_infineon_tricore\cfg1\inc

SET MSC_SRC_PATH=%MCAL_BASE_PATH%\msc_infineon_tricore\cfg1\src
SET MSC_INC_PATH=%MCAL_BASE_PATH%\msc_infineon_tricore\cfg1\inc

SET SCI_SRC_PATH=%MCAL_BASE_PATH%\sci_infineon_tricore\cfg1\src
SET SCI_INC_PATH=%MCAL_BASE_PATH%\sci_infineon_tricore\cfg1\inc

SET MCHK_SRC_PATH=%MCAL_BASE_PATH%\mchk_infineon_tricore\cfg1\src
SET MCHK_INC_PATH=%MCAL_BASE_PATH%\mchk_infineon_tricore\cfg1\inc

SET LIN_SRC_PATH=%MCAL_BASE_PATH%\lin_17_AscLin_infineon_tricore\cfg1\src
SET LIN_INC_PATH=%MCAL_BASE_PATH%\lin_17_AscLin_infineon_tricore\cfg1\inc

SET FR_SRC_PATH=%MCAL_BASE_PATH%\fr_17_eray_infineon_tricore\cfg1\src
SET FR_INC_PATH=%MCAL_BASE_PATH%\fr_17_eray_infineon_tricore\cfg1\inc

SET DEMO_INC_PATH=%MCAL_BASE_PATH%\demoapp\inc
SET DEMO_BAT_PATH=%MCAL_BASE_PATH%\demoapp\Selectable_bin

SET CANTRCV6251G_SRC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6251g_infineon_tricore\cfg1\src
SET CANTRCV6251G_INC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6251g_infineon_tricore\cfg1\inc

SET CANTRCV6250GV33_SRC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6250gv33_infineon_tricore\cfg1\src
SET CANTRCV6250GV33_INC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6250gv33_infineon_tricore\cfg1\inc

SET ETH_SRC_PATH=%MCAL_BASE_PATH%\eth_17_ethmac_infineon_tricore\cfg1\src
SET ETH_INC_PATH=%MCAL_BASE_PATH%\eth_17_ethmac_infineon_tricore\cfg1\inc

SET SENT_SRC_PATH=%MCAL_BASE_PATH%\sent_infineon_tricore\cfg1\src
SET SENT_INC_PATH=%MCAL_BASE_PATH%\sent_infineon_tricore\cfg1\inc

SET IOM_SRC_PATH=%MCAL_BASE_PATH%\iom_infineon_tricore\cfg1\src
SET IOM_INC_PATH=%MCAL_BASE_PATH%\iom_infineon_tricore\cfg1\inc

SET CRC_INC_PATH=%MCAL_BASE_PATH%\crc_infineon_tricore\cfg1\inc

SET STDLIN_SRC_PATH=%MCAL_BASE_PATH%\stdlin_infineon_tricore\cfg1\src
SET STDLIN_INC_PATH=%MCAL_BASE_PATH%\stdlin_infineon_tricore\cfg1\inc
SET STDLIN_MAK_PATH=%MCAL_BASE_PATH%\mak\stdlin_infineon_tricore\ssc\mak

SET DEM_INC_PATH=%MCAL_BASE_PATH%\integration_general\inc

SET DSADC_SRC_PATH=%MCAL_BASE_PATH%\dsadc_infineon_tricore\cfg1\src
SET DSADC_INC_PATH=%MCAL_BASE_PATH%\dsadc_infineon_tricore\cfg1\inc

SET SMU_SRC_PATH=%MCAL_BASE_PATH%\smu_infineon_tricore\cfg1\src
SET SMU_INC_PATH=%MCAL_BASE_PATH%\smu_infineon_tricore\cfg1\inc

SET I2C_SRC_PATH=%MCAL_BASE_PATH%\i2c_infineon_tricore\cfg1\src
SET I2C_INC_PATH=%MCAL_BASE_PATH%\i2c_infineon_tricore\cfg1\inc

REM ****************************************************************************
REM Move inside the output directory
REM ****************************************************************************

SET OUTPUT_DIR_PATH=%MCAL_BASE_PATH%\demoapp\cfg\tresos_workspace\Selectable_Cfg\DemoApp\output

REM ****************************************************************************
REM Delete the previuosly generated Mod_Cfg.c, Mod_Cfg.h files from respective folders
REM ****************************************************************************
IF EXIST %DIO_SRC_PATH%\Dio_Lcfg.c DEL /F /Q %DIO_SRC_PATH%\Dio_Lcfg.c
IF EXIST %DIO_SRC_PATH%\Dio_PBCfg.c DEL /F /Q %DIO_SRC_PATH%\Dio_PBCfg.c
IF EXIST %DIO_INC_PATH%\Dio_Cfg.h DEL /F /Q %DIO_INC_PATH%\Dio_Cfg.h
IF EXIST %PORT_SRC_PATH%\Port_PBCfg.c DEL /F /Q %PORT_SRC_PATH%\Port_PBCfg.c
IF EXIST %PORT_INC_PATH%\Port_Cfg.h DEL /F /Q %PORT_INC_PATH%\Port_Cfg.h
IF EXIST %HSSL_SRC_PATH%\Hssl_Lcfg.c DEL /F /Q %HSSL_SRC_PATH%\Hssl_Lcfg.c
IF EXIST %HSSL_INC_PATH%\Hssl_Cfg.h DEL /F /Q %HSSL_INC_PATH%\Hssl_Cfg.h
IF EXIST %UART_SRC_PATH%\Uart_PBCfg.c DEL /F /Q %UART_SRC_PATH%\Uart_PBCfg.c
IF EXIST %UART_INC_PATH%\Uart_Cfg.h DEL /F /Q %UART_INC_PATH%\Uart_Cfg.h
IF EXIST %MCU_SRC_PATH%\Mcu_PBCfg.c DEL /F /Q %MCU_SRC_PATH%\Mcu_PBCfg.c
IF EXIST %MCU_INC_PATH%\Mcu_Cfg.h DEL /F /Q %MCU_INC_PATH%\Mcu_Cfg.h
IF EXIST %MCU_MAK_PATH%\infineon_mcu_cfg.mak DEL /F /Q %MCU_MAK_PATH%\infineon_mcu_cfg.mak
IF EXIST %GTM_SRC_PATH%\Gtm_PBCfg.c DEL /F /Q %GTM_SRC_PATH%\Gtm_PBCfg.c
IF EXIST %GTM_SRC_PATH%\Gtm_Lcfg.c DEL /F /Q %GTM_SRC_PATH%\Gtm_Lcfg.c
IF EXIST %GTM_INC_PATH%\Gtm_Cfg.h DEL /F /Q %GTM_INC_PATH%\Gtm_Cfg.h
IF EXIST %GPT_SRC_PATH%\Gpt_PBCfg.c DEL /F /Q %GPT_SRC_PATH%\Gpt_PBCfg.c
IF EXIST %GPT_INC_PATH%\Gpt_Cfg.h DEL /F /Q %GPT_INC_PATH%\Gpt_Cfg.h
IF EXIST %SPI_SRC_PATH%\Spi_PBCfg.c DEL /F /Q %SPI_SRC_PATH%\Spi_PBCfg.c
IF EXIST %SPI_INC_PATH%\Spi_Cfg.h DEL /F /Q %SPI_INC_PATH%\Spi_Cfg.h
IF EXIST %ICU_SRC_PATH%\Icu_17_GtmCcu6_PBCfg.c DEL /F /Q %ICU_SRC_PATH%\Icu_17_GtmCcu6_PBCfg.c
IF EXIST %ICU_INC_PATH%\Icu_17_GtmCcu6_Cfg.h DEL /F /Q %ICU_INC_PATH%\Icu_17_GtmCcu6_Cfg.h
IF EXIST %IRQ_INC_PATH%\Irq_Cfg.h DEL /F /Q %IRQ_INC_PATH%\Irq_Cfg.h
IF EXIST %WDG_SRC_PATH%\Wdg_17_Scu_PBCfg.c DEL /F /Q %WDG_SRC_PATH%\Wdg_17_Scu_PBCfg.c
IF EXIST %WDG_INC_PATH%\Wdg_17_Scu_Cfg.h DEL /F /Q %WDG_INC_PATH%\Wdg_17_Scu_Cfg.h
IF EXIST %WDG_MAK_PATH%\infineon_wdg_17_scu_cfg.mak DEL /F /Q %WDG_MAK_PATH%\infineon_wdg_17_scu_cfg.mak
IF EXIST %PWM_SRC_PATH%\Pwm_17_Gtm_PBCfg.c DEL /F /Q %PWM_SRC_PATH%\Pwm_17_Gtm_PBCfg.c
IF EXIST %PWM_INC_PATH%\Pwm_17_Gtm_Cfg.h DEL /F /Q %PWM_INC_PATH%\Pwm_17_Gtm_Cfg.h
IF EXIST %ADC_SRC_PATH%\Adc_PBCfg.c DEL /F /Q %ADC_SRC_PATH%\Adc_PBCfg.c
IF EXIST %ADC_INC_PATH%\Adc_Cfg.h DEL /F /Q %ADC_INC_PATH%\Adc_Cfg.h
IF EXIST %SDADC_SRC_PATH%\Sdadc_PBCfg.c DEL /F /Q %SDADC_SRC_PATH%\Sdadc_PBCfg.c
IF EXIST %SDADC_INC_PATH%\Sdadc_Cfg.h DEL /F /Q %SDADC_INC_PATH%\Sdadc_Cfg.h
IF EXIST %DMA_SRC_PATH%\Dma_PBCfg.c DEL /F /Q %DMA_SRC_PATH%\Dma_PBCfg.c
IF EXIST %DMA_INC_PATH%\Dma_Cfg.h DEL /F /Q %DMA_INC_PATH%\Dma_Cfg.h
IF EXIST %ECUM_SRC_PATH%\EcuM_PBCfg.c DEL /F /Q %ECUM_SRC_PATH%\EcuM_PBCfg.c
IF EXIST %ECUM_INC_PATH%\EcuM_Cfg.h DEL /F /Q %ECUM_INC_PATH%\EcuM_Cfg.h
IF EXIST %ECUM_LCFG_PATH%\EcuM_LCfg.c DEL /F /Q %ECUM_LCFG_PATH%\EcuM_LCfg.c
IF EXIST %FLSLOADER_INC_PATH%\FlsLoader_Cfg.h DEL /F /Q %FLSLOADER_INC_PATH%\FlsLoader_Cfg.h
IF EXIST %FEE_SRC_PATH%\Fee_PBCfg.c DEL /F /Q %FEE_SRC_PATH%\Fee_PBCfg.c
IF EXIST %FEE_INC_PATH%\Fee_Cfg.h DEL /F /Q %FEE_INC_PATH%\Fee_Cfg.h
IF EXIST %FLS_SRC_PATH%\Fls_17_Pmu_PBCfg.c DEL /F /Q %FLS_SRC_PATH%\Fls_17_Pmu_PBCfg.c
IF EXIST %FLS_INC_PATH%\Fls_17_Pmu_Cfg.h DEL /F /Q %FLS_INC_PATH%\Fls_17_Pmu_Cfg.h
IF EXIST %MLI_SRC_PATH%\Mli_PBCfg.c DEL /F /Q %MLI_SRC_PATH%\Mli_PBCfg.c
IF EXIST %MLI_SRC_PATH%\Mli_LCfg.c DEL /F /Q %MLI_SRC_PATH%\Mli_LCfg.c
IF EXIST %MLI_INC_PATH%\Mli_Cfg.h DEL /F /Q %MLI_INC_PATH%\Mli_Cfg.h
IF EXIST %ERU_SRC_PATH%\Eru_PBCfg.c DEL /F /Q %ERU_SRC_PATH%\Eru_PBCfg.c
IF EXIST %ERU_INC_PATH%\Eru_Cfg.h DEL /F /Q %ERU_INC_PATH%\Eru_Cfg.h
IF EXIST %CAN_SRC_PATH%\Can_17_MCanP_PBCfg.c DEL /F /Q %CAN_SRC_PATH%\Can_17_MCanP_PBCfg.c
IF EXIST %CAN_INC_PATH%\Can_17_MCanP_Cfg.h DEL /F /Q %CAN_INC_PATH%\Can_17_MCanP_Cfg.h
IF EXIST %MSC_SRC_PATH%\Msc_PBCfg.c DEL /F /Q %MSC_SRC_PATH%\Msc_PBCfg.c
IF EXIST %MSC_INC_PATH%\Msc_Cfg.h DEL /F /Q %MSC_INC_PATH%\Msc_Cfg.h
IF EXIST %SCI_SRC_PATH%\Sci_PBCfg.c DEL /F /Q %SCI_SRC_PATH%\Sci_PBCfg.c
IF EXIST %SCI_SRC_PATH%\Sci_LCfg.c DEL /F /Q %SCI_SRC_PATH%\Sci_LCfg.c
IF EXIST %SCI_INC_PATH%\Sci_Cfg.h DEL /F /Q %SCI_INC_PATH%\Sci_Cfg.h
IF EXIST %MCHK_SRC_PATH%\Mchk_PBCfg.c DEL /F /Q %MCHK_SRC_PATH%\Mchk_PBCfg.c
IF EXIST %MCHK_INC_PATH%\Mchk_Cfg.h DEL /F /Q %MCHK_INC_PATH%\Mchk_Cfg.h
IF EXIST %LIN_SRC_PATH%\Lin_17_AscLin_PBCfg.c DEL /F /Q %LIN_SRC_PATH%\Lin_17_AscLin_PBCfg.c
IF EXIST %LIN_INC_PATH%\Lin_17_AscLin_Cfg.h DEL /F /Q %LIN_INC_PATH%\Lin_17_AscLin_Cfg.h
IF EXIST %FR_SRC_PATH%\Fr_17_Eray_PBCfg.c DEL /F /Q %FR_SRC_PATH%\Fr_17_Eray_PBCfg.c
IF EXIST %FR_INC_PATH%\Fr_17_Eray_Cfg.h DEL /F /Q %FR_INC_PATH%\Fr_17_Eray_Cfg.h

IF EXIST %ETH_SRC_PATH%\Eth_17_EthMac_PBCfg.c DEL /F /Q %ETH_SRC_PATH%\Eth_17_EthMac_PBCfg.c
IF EXIST %ETH_INC_PATH%\Eth_17_EthMac_Cfg.h DEL /F /Q %ETH_INC_PATH%\Eth_17_EthMac_Cfg.h

IF EXIST %SENT_SRC_PATH%\Sent_PBCfg.c DEL /F /Q %SENT_SRC_PATH%\Sent_PBCfg.c
IF EXIST %SENT_SRC_PATH%\Sent_LCfg.c DEL /F /Q %SENT_SRC_PATH%\Sent_LCfg.c
IF EXIST %SENT_INC_PATH%\Sent_Cfg.h DEL /F /Q %SENT_INC_PATH%\Sent_Cfg.h

IF EXIST %IOM_SRC_PATH%\Iom_PBCfg.c DEL /F /Q %IOM_SRC_PATH%\Iom_PBCfg.c
IF EXIST %IOM_INC_PATH%\Iom_Cfg.h DEL /F /Q %IOM_INC_PATH%\Iom_Cfg.h


IF EXIST %CRC_INC_PATH%\Crc_Cfg.h DEL /F /Q %CRC_INC_PATH%\Crc_Cfg.h

IF EXIST %CANTRCV6251G_SRC_PATH%\CanTrcv_17_6251G_Cfg.c DEL /F /Q %CANTRCV6251G_SRC_PATH%\CanTrcv_17_6251G_Cfg.c
IF EXIST %CANTRCV6251G_INC_PATH%\CanTrcv_17_6251G_Cfg.h DEL /F /Q %CANTRCV6251G_INC_PATH%\CanTrcv_17_6251G_Cfg.h

IF EXIST %CANTRCV6250GV33_SRC_PATH%\CanTrcv_17_6250GV33_Cfg.c DEL /F /Q %CANTRCV6250GV33_SRC_PATH%\CanTrcv_17_6250GV33_Cfg.c
IF EXIST %CANTRCV6250GV33_INC_PATH%\CanTrcv_17_6250GV33_Cfg.h DEL /F /Q %CANTRCV6250GV33_INC_PATH%\CanTrcv_17_6250GV33_Cfg.h

IF EXIST %STDLIN_SRC_PATH%\StdLin_Cfg.c DEL /F /Q %STDLIN_SRC_PATH%\StdLin_Cfg.c
IF EXIST %STDLIN_INC_PATH%\StdLin_Cfg.h DEL /F /Q %STDLIN_INC_PATH%\StdLin_Cfg.h
IF EXIST %STDLIN_MAK_PATH%\infineon_stdlin_cfg.mak DEL /F /Q %STDLIN_MAK_PATH%\infineon_stdlin_cfg.mak

IF EXIST %DEM_INC_PATH%\Dem_PBcfg.h DEL /F /Q %DEM_INC_PATH%\Dem_PBcfg.h
IF EXIST %DEMO_INC_PATH%\DemoApp_Cfg.h DEL /F /Q %DEMO_INC_PATH%\DemoApp_Cfg.h

IF EXIST %DSADC_SRC_PATH%\Dsadc_PBCfg.c DEL /F /Q %DSADC_SRC_PATH%\Dsadc_PBCfg.c
IF EXIST %DSADC_INC_PATH%\Dsadc_Cfg.h DEL /F /Q %DSADC_INC_PATH%\Dsadc_Cfg.h

IF EXIST %SMU_SRC_PATH%\Smu_PBCfg.c DEL /F /Q %SMU_SRC_PATH%\Smu_PBCfg.c
IF EXIST %SMU_INC_PATH%\Smu_Cfg.h DEL /F /Q %SMU_INC_PATH%\Smu_Cfg.h

IF EXIST %I2C_SRC_PATH%\I2c_PBCfg.c DEL /F /Q %I2C_SRC_PATH%\I2c_PBCfg.c
IF EXIST %I2C_SRC_PATH%\I2c_LCfg.c DEL /F /Q %I2C_SRC_PATH%\I2c_LCfg.c
IF EXIST %I2C_INC_PATH%\I2c_Cfg.h DEL /F /Q %I2C_INC_PATH%\I2c_Cfg.h

REM *************************************************************************************************************
REM Delete the previously generated SafeTlib specific *Cfg.c and *Cfg.h files from Cfg folder of SafeTlib package 
REM *************************************************************************************************************
SET SAFET_SRC_PATH=..\..\..\01_SafeTlib\Cfg\src
SET SAFET_INC_PATH=..\..\..\01_SafeTlib\Cfg\inc
SET SAFET_MAK_PATH=..\..\..\01_SafeTlib

IF EXIST %SAFET_SRC_PATH%\*.c DEL /F /Q %SAFET_SRC_PATH%\*.c
IF EXIST %SAFET_INC_PATH%\*.h DEL /F /Q %SAFET_INC_PATH%\*.h

REM PAUSE
REM ****************************************************************************
REM Move corresponding Mod_Cfg.c, Mod_Cfg.h files to respective folders
REM ****************************************************************************
IF EXIST %OUTPUT_DIR_PATH%\src\Dio_Lcfg.c COPY %OUTPUT_DIR_PATH%\src\Dio_Lcfg.c %DIO_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Dio_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Dio_PBCfg.c %DIO_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Dio_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Dio_Cfg.h %DIO_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Port_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Port_PBCfg.c %PORT_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Port_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Port_Cfg.h %PORT_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Hssl_Lcfg.c COPY %OUTPUT_DIR_PATH%\src\Hssl_Lcfg.c %HSSL_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Hssl_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Hssl_Cfg.h %HSSL_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Uart_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Uart_PBCfg.c %UART_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Uart_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Uart_Cfg.h %UART_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Mcu_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Mcu_PBCfg.c %MCU_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Mcu_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Mcu_Cfg.h %MCU_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\mak\infineon_mcu_cfg.mak COPY %OUTPUT_DIR_PATH%\mak\infineon_mcu_cfg.mak %MCU_MAK_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Gtm_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Gtm_PBCfg.c %GTM_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Gtm_Lcfg.c COPY %OUTPUT_DIR_PATH%\src\Gtm_Lcfg.c %GTM_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Gtm_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Gtm_Cfg.h %GTM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Gpt_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Gpt_PBCfg.c %GPT_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Gpt_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Gpt_Cfg.h %GPT_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Spi_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Spi_PBCfg.c %SPI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Spi_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Spi_Cfg.h %SPI_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Can_17_MCanP_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Can_17_MCanP_Cfg.h %CAN_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Can_17_MCanP_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Can_17_MCanP_PBCfg.c %CAN_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Icu_17_GtmCcu6_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Icu_17_GtmCcu6_PBCfg.c  %ICU_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Icu_17_GtmCcu6_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Icu_17_GtmCcu6_Cfg.h  %ICU_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Wdg_17_Scu_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Wdg_17_Scu_Cfg.h  %WDG_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Wdg_17_Scu_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Wdg_17_Scu_PBCfg.c %WDG_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\mak\infineon_wdg_17_scu_cfg.mak COPY %OUTPUT_DIR_PATH%\mak\infineon_wdg_17_scu_cfg.mak %WDG_MAK_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Pwm_17_Gtm_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Pwm_17_Gtm_PBCfg.c %PWM_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Pwm_17_Gtm_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Pwm_17_Gtm_Cfg.h  %PWM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Adc_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Adc_PBCfg.c  %ADC_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Adc_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Adc_Cfg.h  %ADC_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Sdadc_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Sdadc_PBCfg.c %SDADC_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Sdadc_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Sdadc_Cfg.h  %SDADC_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Dma_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Dma_PBCfg.c %DMA_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Dma_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Dma_Cfg.h  %DMA_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Irq_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Irq_Cfg.h  %IRQ_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\EcuM_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\EcuM_PBCfg.c %ECUM_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\EcuM_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\EcuM_Cfg.h %ECUM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\EcuM_LCfg.c COPY %OUTPUT_DIR_PATH%\src\EcuM_LCfg.c %ECUM_LCFG_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\FlsLoader_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\FlsLoader_Cfg.h %FLSLOADER_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Fee_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Fee_PBCfg.c  %FEE_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Fee_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Fee_Cfg.h  %FEE_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Fls_17_Pmu_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Fls_17_Pmu_PBCfg.c  %FLS_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Fls_17_Pmu_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Fls_17_Pmu_Cfg.h  %FLS_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Mli_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Mli_PBCfg.c %MLI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Mli_LCfg.c  COPY %OUTPUT_DIR_PATH%\src\Mli_LCfg.c %MLI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Mli_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Mli_Cfg.h  %MLI_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Eru_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Eru_PBCfg.c %ERU_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Eru_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Eru_Cfg.h  %ERU_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Msc_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Msc_PBCfg.c %MSC_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Msc_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Msc_Cfg.h  %MSC_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Sci_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Sci_PBCfg.c %SCI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Sci_LCfg.c  COPY %OUTPUT_DIR_PATH%\src\Sci_LCfg.c %SCI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Sci_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Sci_Cfg.h  %SCI_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Mchk_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Mchk_PBCfg.c %MCHK_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Mchk_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Mchk_Cfg.h  %MCHK_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Lin_17_AscLin_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Lin_17_AscLin_PBCfg.c %LIN_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Lin_17_AscLin_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Lin_17_AscLin_Cfg.h  %LIN_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Fr_17_Eray_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Fr_17_Eray_PBCfg.c %FR_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Fr_17_Eray_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Fr_17_Eray_Cfg.h  %FR_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\DemoApp_Cfg.h COPY %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\DemoApp_Cfg.h  %DEMO_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Eth_17_EthMac_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Eth_17_EthMac_PBCfg.c %ETH_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Eth_17_EthMac_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Eth_17_EthMac_Cfg.h  %ETH_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Sent_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Sent_PBCfg.c %SENT_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Sent_LCfg.c COPY %OUTPUT_DIR_PATH%\src\Sent_LCfg.c %SENT_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Sent_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Sent_Cfg.h  %SENT_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Iom_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Iom_PBCfg.c %IOM_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Iom_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Iom_Cfg.h  %IOM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Crc_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Crc_Cfg.h  %CRC_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\CanTrcv_17_6251G_Cfg.c COPY %OUTPUT_DIR_PATH%\src\CanTrcv_17_6251G_Cfg.c %CANTRCV6251G_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6251G_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6251G_Cfg.h  %CANTRCV6251G_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\CanTrcv_17_6250GV33_Cfg.c COPY %OUTPUT_DIR_PATH%\src\CanTrcv_17_6250GV33_Cfg.c %CANTRCV6250GV33_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6250GV33_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6250GV33_Cfg.h  %CANTRCV6250GV33_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\StdLin_Cfg.c         COPY %OUTPUT_DIR_PATH%\src\StdLin_Cfg.c               %STDLIN_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\StdLin_Cfg.h         COPY %OUTPUT_DIR_PATH%\inc\StdLin_Cfg.h               %STDLIN_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\mak\infineon_stdlin_cfg.mak COPY %OUTPUT_DIR_PATH%\mak\infineon_stdlin_cfg.mak %STDLIN_MAK_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Dem_PBcfg.h COPY %OUTPUT_DIR_PATH%\inc\Dem_PBcfg.h %DEM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\ModuleDelivery.bat COPY %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\ModuleDelivery.bat  %DEMO_BAT_PATH%

IF EXIST %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\DemoApp_Cfg.h COPY %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\DemoApp_Cfg.h  %DEMO_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Dsadc_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Dsadc_PBCfg.c %DSADC_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Dsadc_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Dsadc_Cfg.h  %DSADC_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Smu_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Smu_PBCfg.c %SMU_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Smu_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Smu_Cfg.h  %SMU_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\I2c_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\I2c_PBCfg.c %I2C_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\I2c_LCfg.c COPY %OUTPUT_DIR_PATH%\src\I2c_LCfg.c %I2C_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\I2c_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\I2c_Cfg.h  %I2C_INC_PATH%

REM ***************************************************************************
REM Move SafeTlib Configuration files into Safetlib Specific Cfg folder
REM ***************************************************************************

IF EXIST %OUTPUT_DIR_PATH%\src\ClkmTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\ClkmTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\ClkmTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\ClkmTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\CpuBusMpuLfmTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\CpuBusMpuLfmTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CpuBusMpuLfmTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CpuBusMpuLfmTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\CpuBusMpuSpfmTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\CpuBusMpuSpfmTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CpuBusMpuSpfmTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CpuBusMpuSpfmTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\CpuMpuTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\CpuMpuTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CpuMpuTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CpuMpuTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\DmaTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\DmaTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\DmaTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\DmaTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\PhlSramTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\PhlSramTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\PhlSramTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\PhlSramTst_Cfg.h %SAFET_INC_PATH% 
IF EXIST %OUTPUT_DIR_PATH%\src\IomTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\IomTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\IomTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\IomTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\FceTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\FceTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\FceTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\FceTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\IRTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\IRTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\IRTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\IRTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\LmuBusMpuLfmTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\LmuBusMpuLfmTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\LmuBusMpuLfmTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\LmuBusMpuLfmTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\MbistTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\MbistTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\MbistTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\MbistTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\OscWdgTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\OscWdgTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\OscWdgTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\OscWdgTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\PmuEccEdcTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\PmuEccEdcTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\PmuEccEdcTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\PmuEccEdcTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SafeWdgAscLin_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\SafeWdgAscLin_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SafeWdgAscLin_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SafeWdgAscLin_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SafeWdgExtAlive_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\SafeWdgExtAlive_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SafeWdgExtAlive_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SafeWdgExtAlive_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SafeWdgExtCic_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\SafeWdgExtCic_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SafeWdgExtCic_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SafeWdgExtCic_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SafeWdgIf_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\SafeWdgIf_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SafeWdgIf_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SafeWdgIf_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SafeWdgInt_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\SafeWdgInt_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SafeWdgInt_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SafeWdgInt_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SfrTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\SfrTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SfrTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SfrTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\Smu_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Smu_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Smu_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Smu_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SmuTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\SmuTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SmuTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SmuTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SpbTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\SpbTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SpbTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SpbTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SramEccTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\SramEccTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SramEccTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SramEccTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\SriTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\SriTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\SriTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\SriTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\TstHandler_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\TstHandler_PBCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\TstHandler_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\TstHandler_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\VltmTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\VltmTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\VltmTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\VltmTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\WdgTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\WdgTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\WdgTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\WdgTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\inc\CpuSbstTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CpuSbstTst_Cfg.h %SAFET_INC_PATH% 

IF EXIST %OUTPUT_DIR_PATH%\src\PflashMonTst_LCfg.c COPY %OUTPUT_DIR_PATH%\src\PflashMonTst_LCfg.c %SAFET_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\PflashMonTst_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\PflashMonTst_Cfg.h %SAFET_INC_PATH% 
IF EXIST %OUTPUT_DIR_PATH%\SafeTlibCD_Cfg.mak  COPY %OUTPUT_DIR_PATH%\SafeTlibCD_Cfg.mak %SAFET_MAK_PATH%\SafeTlibCD
IF EXIST %OUTPUT_DIR_PATH%\SafeWdgCD_Cfg.mak COPY %OUTPUT_DIR_PATH%\SafeWdgCD_Cfg.mak %SAFET_MAK_PATH%\SafeWdgCD

REM PAUSE

rmdir /S /Q %OUTPUT_DIR_PATH%
mkdir %OUTPUT_DIR_PATH%

REM ****************************************************************************
REM  End of the MCAL_OpUpdate.bat file
REM ****************************************************************************
