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
REM *  VERSION   : 0.0.17                                                     **
REM *                                                                         **
REM *  DATE      : 2013-10-10                                                 **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file moves the files from output directory of      **
REM *          codegenerator to respective modules                            **
REM *                                                                         **
REM *                                                                         **
REM *  MAY BE CHANGED BY USER [yes/no]: YES                                   **
REM *                                                                         **
REM ***************************************************************************/


REM ****************************************************************************
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM * V0.0.17: 2013-10-10, JN   : Updated for I2C
REM * V0.0.16: 2013-07-25, AK   : SENT Lcfg file copy added
REM * V0.0.15: 2013-03-20, Vani  :  Updated for FLS
REM * V0.0.14: 2013-02-25, SGN  :  Updated for CAN for UTP AI00133871
REM * v0.0.13: 2013-01-08, KP   :  Updated for ETH and CRC
REM * v0.0.12: 2012-12-06, DNS  :  Updated UART build path
REM * v0.0.11: 2012-12-05, AK   :  Updated for SENT
REM * v0.0.10: 2012-08-08, MK   :  Updated Dio build path
REM * v0.0.9: 2012-08-07, SGN   :  Updated FEE path
REM * v0.0.8: 2012-05-21, SGN   :  Updated CAN path
REM * v0.0.7: 2009-10-21, SC    :  Added RAMTEST
REM * v0.0.6: 2009.06.01, Hamzath: Changed to Audo, add CONTROLLER_PLUGIN
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
SET GNU_MAKE_PATH=%GNU_MAKE_PATH:\Aurix_MC-ISAR\demoapp\Loadable_bin\=%
SET GNU_MAKE_PATH=%GNU_MAKE_PATH%\GNU

SET MCAL_BASE_PATH=%~dp0
SET MCAL_BASE_PATH=%MCAL_BASE_PATH:\demoapp\Loadable_bin\=%
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

SET DSADC_SRC_PATH=%MCAL_BASE_PATH%\dsadc_infineon_tricore\cfg1\src
SET DSADC_INC_PATH=%MCAL_BASE_PATH%\dsadc_infineon_tricore\cfg1\inc

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

SET ETH_SRC_PATH=%MCAL_BASE_PATH%\eth_17_ethmac_infineon_tricore\cfg1\src
SET ETH_INC_PATH=%MCAL_BASE_PATH%\eth_17_ethmac_infineon_tricore\cfg1\inc


SET CRC_INC_PATH=%MCAL_BASE_PATH%\crc_infineon_tricore\cfg1\inc

SET SCI_SRC_PATH=%MCAL_BASE_PATH%\sci_infineon_tricore\cfg1\src
SET SCI_INC_PATH=%MCAL_BASE_PATH%\sci_infineon_tricore\cfg1\inc

SET MCHK_SRC_PATH=%MCAL_BASE_PATH%\mchk_infineon_tricore\cfg1\src
SET MCHK_INC_PATH=%MCAL_BASE_PATH%\mchk_infineon_tricore\cfg1\inc

SET LIN_SRC_PATH=%MCAL_BASE_PATH%\lin_17_asclin_infineon_tricore\cfg1\src
SET LIN_INC_PATH=%MCAL_BASE_PATH%\lin_17_asclin_infineon_tricore\cfg1\inc

SET FR_SRC_PATH=%MCAL_BASE_PATH%\fr_17_eray_infineon_tricore\cfg1\src
SET FR_INC_PATH=%MCAL_BASE_PATH%\fr_17_eray_infineon_tricore\cfg1\inc

SET SENT_SRC_PATH=%MCAL_BASE_PATH%\sent_infineon_tricore\cfg1\src
SET SENT_INC_PATH=%MCAL_BASE_PATH%\sent_infineon_tricore\cfg1\inc

SET IOM_SRC_PATH=%MCAL_BASE_PATH%\iom_infineon_tricore\cfg1\src
SET IOM_INC_PATH=%MCAL_BASE_PATH%\iom_infineon_tricore\cfg1\inc

SET DEMO_INC_PATH=%MCAL_BASE_PATH%\demoapp\inc
SET DEMO_BAT_PATH=%MCAL_BASE_PATH%\demoapp\Loadable_bin

SET CANTRCV6251G_SRC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6251g_infineon_tricore\cfg1\src
SET CANTRCV6251G_INC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6251g_infineon_tricore\cfg1\inc

SET CANTRCV6250GV33_SRC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6250gv33_infineon_tricore\cfg1\src
SET CANTRCV6250GV33_INC_PATH=%MCAL_BASE_PATH%\cantrcv_17_6250gv33_infineon_tricore\cfg1\inc

SET RAMTST_SRC_PATH=%MCAL_BASE_PATH%\ramtst_infineon_tricore\cfg1\src
SET RAMTST_INC_PATH=%MCAL_BASE_PATH%\ramtst_infineon_tricore\cfg1\inc
SET RAMTST_MAK_PATH=%MCAL_BASE_PATH%\mak\ramtst_infineon_tricore\ssc\mak

SET I2C_SRC_PATH=%MCAL_BASE_PATH%\i2c_infineon_tricore\cfg1\src
SET I2C_INC_PATH=%MCAL_BASE_PATH%\i2c_infineon_tricore\cfg1\inc

SET DEMO_INC_PATH=%MCAL_BASE_PATH%\demoapp\inc
SET DEMO_BAT_PATH=%MCAL_BASE_PATH%\demoapp\Loadable_bin
SET DEM_INC_PATH=%MCAL_BASE_PATH%\integration_general\inc

REM ****************************************************************************
REM Move inside the output directory
REM ****************************************************************************

SET OUTPUT_DIR_PATH=%MCAL_BASE_PATH%\demoapp\cfg\tresos_workspace\Loadable_Cfg\DemoApp\output

REM ****************************************************************************
REM Delete the previuosly generated Mod_Cfg.c, Mod_Cfg.h files from respective folders
REM ****************************************************************************
IF EXIST %DIO_SRC_PATH%\Dio_Lcfg.c DEL /F /Q %DIO_SRC_PATH%\Dio_Lcfg.c
IF EXIST %DIO_SRC_PATH%\Dio_PBCfg.c DEL /F /Q %DIO_SRC_PATH%\Dio_PBCfg.c
IF EXIST %DIO_INC_PATH%\Dio_Cfg.h DEL /F /Q %DIO_INC_PATH%\Dio_Cfg.h

IF EXIST %PORT_INC_PATH%\Port_Cfg.h DEL /F /Q %PORT_INC_PATH%\Port_Cfg.h

IF EXIST %UART_SRC_PATH%\Uart_PBCfg.c DEL /F /Q %UART_SRC_PATH%\Uart_PBCfg.c
IF EXIST %UART_INC_PATH%\Uart_Cfg.h DEL /F /Q %UART_INC_PATH%\Uart_Cfg.h
IF EXIST %MCU_INC_PATH%\Mcu_Cfg.h DEL /F /Q %MCU_INC_PATH%\Mcu_Cfg.h
IF EXIST %MCU_MAK_PATH%\infineon_mcu_cfg.mak DEL /F /Q %MCU_MAK_PATH%\infineon_mcu_cfg.mak
IF EXIST %GTM_INC_PATH%\Gtm_Cfg.h DEL /F /Q %GTM_INC_PATH%\Gtm_Cfg.h
IF EXIST %GTM_SRC_PATH%\Gtm_Lcfg.c DEL /F /Q %GTM_SRC_PATH%\Gtm_Lcfg.c
IF EXIST %GPT_INC_PATH%\Gpt_Cfg.h DEL /F /Q %GPT_INC_PATH%\Gpt_Cfg.h

IF EXIST %SPI_INC_PATH%\Spi_Cfg.h DEL /F /Q %SPI_INC_PATH%\Spi_Cfg.h

IF EXIST %ICU_INC_PATH%\Icu_17_GtmCcu6_Cfg.h DEL /F /Q %ICU_INC_PATH%\Icu_17_GtmCcu6_Cfg.h
IF EXIST %IRQ_INC_PATH%\Irq_Cfg.h DEL /F /Q %IRQ_INC_PATH%\Irq_Cfg.h

IF EXIST %WDG_INC_PATH%\Wdg_17_Scu_Cfg.h DEL /F /Q %WDG_INC_PATH%\Wdg_17_Scu_Cfg.h
IF EXIST %WDG_MAK_PATH%\infineon_wdg_17_scu_cfg.mak DEL /F /Q %WDG_MAK_PATH%\infineon_wdg_17_scu_cfg.mak

IF EXIST %PWM_INC_PATH%\Pwm_17_Gtm_Cfg.h DEL /F /Q %PWM_INC_PATH%\Pwm_17_Gtm_Cfg.h

IF EXIST %ADC_INC_PATH%\Adc_Cfg.h DEL /F /Q %ADC_INC_PATH%\Adc_Cfg.h



IF EXIST %ECUM_INC_PATH%\EcuM_Cfg.h DEL /F /Q %ECUM_INC_PATH%\EcuM_Cfg.h
IF EXIST %ECUM_LCFG_PATH%\EcuM_LCfg.c DEL /F /Q %ECUM_LCFG_PATH%\EcuM_LCfg.c
IF EXIST %FLSLOADER_INC_PATH%\FlsLoader_Cfg.h DEL /F /Q %FLSLOADER_INC_PATH%\FlsLoader_Cfg.h
IF EXIST %FEE_INC_PATH%\Fee_Cfg.h DEL /F /Q %FEE_INC_PATH%\Fee_Cfg.h
IF EXIST %FEE_INC_PATH%\Fee_PBCfg.c DEL /F /Q %FEE_INC_PATH%\Fee_PBCfg.c

IF EXIST %FLS_INC_PATH%\Fls_17_Pmu_Cfg.h DEL /F /Q %FLS_INC_PATH%\Fls_17_Pmu_Cfg.h

IF EXIST %MLI_SRC_PATH%\Mli_LCfg.c DEL /F /Q %MLI_SRC_PATH%\Mli_LCfg.c
IF EXIST %MLI_INC_PATH%\Mli_Cfg.h DEL /F /Q %MLI_INC_PATH%\Mli_Cfg.h

IF EXIST %ERU_INC_PATH%\Eru_Cfg.h DEL /F /Q %ERU_INC_PATH%\Eru_Cfg.h

IF EXIST %CAN_SRC_PATH%\Can_17_MCanP_PBCfg.c DEL /F /Q %CAN_SRC_PATH%\Can_17_MCanP_PBCfg.c
IF EXIST %CAN_INC_PATH%\Can_17_MCanP_Cfg.h DEL /F /Q %CAN_INC_PATH%\Can_17_MCanP_Cfg.h

IF EXIST %MSC_INC_PATH%\Msc_Cfg.h DEL /F /Q %MSC_INC_PATH%\Msc_Cfg.h

IF EXIST %ETH_INC_PATH%\Eth_17_EthMac_Cfg.h DEL /F /Q %ETH_INC_PATH%\Eth_17_EthMac_Cfg.h

IF EXIST %CRC_INC_PATH%\Crc_Cfg.h DEL /F /Q %CRC_INC_PATH%\Crc_Cfg.h

IF EXIST %SCI_INC_PATH%\Sci_Cfg.h DEL /F /Q %SCI_INC_PATH%\Sci_Cfg.h

IF EXIST %MCHK_INC_PATH%\Mchk_Cfg.h DEL /F /Q %MCHK_INC_PATH%\Mchk_Cfg.h

IF EXIST %CANTRCV6251G_SRC_PATH%\CanTrcv_17_6251G_Cfg.c DEL /F /Q %CANTRCV6251G_SRC_PATH%\CanTrcv_17_6251G_Cfg.c
IF EXIST %CANTRCV6251G_INC_PATH%\CanTrcv_17_6251G_Cfg.h DEL /F /Q %CANTRCV6251G_INC_PATH%\CanTrcv_17_6251G_Cfg.h

IF EXIST %SENT_SRC_PATH%\Sent_PBCfg.c DEL /F /Q %SENT_SRC_PATH%\Sent_PBCfg.c
IF EXIST %SENT_SRC_PATH%\Sent_LCfg.c DEL /F /Q %SENT_SRC_PATH%\Sent_LCfg.c
IF EXIST %SENT_INC_PATH%\Sent_Cfg.h DEL /F /Q %SENT_INC_PATH%\Sent_Cfg.h

IF EXIST %IOM_SRC_PATH%\Iom_PBCfg.c DEL /F /Q %IOM_SRC_PATH%\Iom_PBCfg.c
IF EXIST %IOM_INC_PATH%\Iom_Cfg.h DEL /F /Q %IOM_INC_PATH%\Iom_Cfg.h

IF EXIST %CANTRCV6250GV33_SRC_PATH%\CanTrcv_17_6250GV33_Cfg.c DEL /F /Q %CANTRCV6250GV33_SRC_PATH%\CanTrcv_17_6250GV33_Cfg.c
IF EXIST %CANTRCV6250GV33_INC_PATH%\CanTrcv_17_6250GV33_Cfg.h DEL /F /Q %CANTRCV6250GV33_INC_PATH%\CanTrcv_17_6250GV33_Cfg.h
IF EXIST %RAMTST_SRC_PATH%\RamTst_Cfg.c DEL /F /Q %RAMTST_SRC_PATH%\RamTst_Cfg.c
IF EXIST %RAMTST_SRC_PATH%\RamTst_Lcfg.c DEL /F /Q %RAMTST_SRC_PATH%\RamTst_Lcfg.c
IF EXIST %RAMTST_INC_PATH%\RamTst_Cfg.h DEL /F /Q %RAMTST_INC_PATH%\RamTst_Cfg.h
IF EXIST %RAMTST_INC_PATH%\RamTst_CfgTypes.h DEL /F /Q %RAMTST_INC_PATH%\RamTst_CfgTypes.h

IF EXIST %I2C_SRC_PATH%\I2c_PBCfg.c DEL /F /Q %I2C_SRC_PATH%\I2c_PBCfg.c
IF EXIST %I2C_SRC_PATH%\I2c_LCfg.c DEL /F /Q %I2C_SRC_PATH%\I2c_LCfg.c
IF EXIST %I2C_INC_PATH%\I2c_Cfg.h DEL /F /Q %I2C_INC_PATH%\I2c_Cfg.h

IF EXIST %DSADC_SRC_PATH%\Dsadc_PBCfg.c DEL /F /Q %DSADC_SRC_PATH%\Dsadc_PBCfg.c
IF EXIST %DSADC_INC_PATH%\Dsadc_Cfg.h DEL /F /Q %DSADC_INC_PATH%\Dsadc_Cfg.h
IF EXIST %RAMTST_MAK_PATH%\infineon_ramtst_cfg.mak DEL /F /Q %RAMTST_MAK_PATH%\infineon_ramtst_cfg.mak
IF EXIST %DEM_INC_PATH%\Dem_PBcfg.h DEL /F /Q %DEM_INC_PATH%\Dem_PBcfg.h
IF EXIST %DEMO_INC_PATH%\DemoApp_Cfg.h DEL /F /Q %DEMO_INC_PATH%\DemoApp_Cfg.h
REM PAUSE
REM ****************************************************************************
REM Move corresponding Mod_Cfg.c, Mod_Cfg.h files to respective folders
REM ****************************************************************************
IF EXIST %OUTPUT_DIR_PATH%\src\Dio_Lcfg.c COPY %OUTPUT_DIR_PATH%\src\Dio_Lcfg.c %DIO_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Dio_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Dio_PBCfg.c %DIO_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Dio_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Dio_Cfg.h %DIO_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Port_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Port_Cfg.h %PORT_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Uart_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Uart_PBCfg.c %UART_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Uart_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Uart_Cfg.h %UART_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Mcu_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Mcu_Cfg.h %MCU_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\mak\infineon_mcu_cfg.mak COPY %OUTPUT_DIR_PATH%\mak\infineon_mcu_cfg.mak %MCU_MAK_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Gtm_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Gtm_Cfg.h %GTM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Gtm_Lcfg.c COPY %OUTPUT_DIR_PATH%\src\Gtm_Lcfg.c %GTM_SRC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Gpt_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Gpt_Cfg.h %GPT_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Spi_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Spi_Cfg.h %SPI_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Can_17_MCanP_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Can_17_MCanP_Cfg.h %CAN_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Can_17_MCanP_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Can_17_MCanP_PBCfg.c %CAN_SRC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Icu_17_GtmCcu6_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Icu_17_GtmCcu6_Cfg.h  %ICU_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Wdg_17_Scu_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Wdg_17_Scu_Cfg.h  %WDG_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\mak\infineon_wdg_17_scu_cfg.mak COPY %OUTPUT_DIR_PATH%\mak\infineon_wdg_17_scu_cfg.mak %WDG_MAK_PATH%


IF EXIST %OUTPUT_DIR_PATH%\inc\Pwm_17_Gtm_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Pwm_17_Gtm_Cfg.h  %PWM_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Adc_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Adc_PBCfg.c  %ADC_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Adc_Cfg.h  COPY %OUTPUT_DIR_PATH%\inc\Adc_Cfg.h  %ADC_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Dma_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Dma_Cfg.h  %DMA_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Irq_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Irq_Cfg.h  %IRQ_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\EcuM_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\EcuM_Cfg.h %ECUM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\EcuM_LCfg.c COPY %OUTPUT_DIR_PATH%\src\EcuM_LCfg.c %ECUM_LCFG_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\FlsLoader_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\FlsLoader_Cfg.h %FLSLOADER_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Fee_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Fee_PBCfg.c  %FEE_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Fee_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Fee_Cfg.h  %FEE_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Fls_17_Pmu_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Fls_17_Pmu_Cfg.h  %FLS_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Mli_LCfg.c  COPY %OUTPUT_DIR_PATH%\src\Mli_LCfg.c %MLI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Mli_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Mli_Cfg.h  %MLI_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Eru_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Eru_Cfg.h  %ERU_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Msc_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Msc_Cfg.h  %MSC_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Eth_17_EthMac_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Eth_17_EthMac_Cfg.h  %ETH_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Crc_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Crc_Cfg.h  %CRC_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Sci_LCfg.c  COPY %OUTPUT_DIR_PATH%\src\Sci_LCfg.c %SCI_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Sci_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Sci_Cfg.h  %SCI_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\inc\Lin_17_AscLin_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Lin_17_AscLin_Cfg.h  %LIN_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Fr_17_Eray_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Fr_17_Eray_Cfg.h  %FR_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Sent_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Sent_PBCfg.c %SENT_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Sent_LCfg.c COPY %OUTPUT_DIR_PATH%\src\Sent_LCfg.c %SENT_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Sent_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Sent_Cfg.h  %SENT_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\Iom_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Iom_PBCfg.c %IOM_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Iom_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\Iom_Cfg.h  %IOM_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\CanTrcv_17_6251G_Cfg.c COPY %OUTPUT_DIR_PATH%\src\CanTrcv_17_6251G_Cfg.c %CANTRCV6251G_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6251G_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6251G_Cfg.h  %CANTRCV6251G_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\CanTrcv_17_6250GV33_Cfg.c COPY %OUTPUT_DIR_PATH%\src\CanTrcv_17_6250GV33_Cfg.c %CANTRCV6250GV33_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6250GV33_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\CanTrcv_17_6250GV33_Cfg.h  %CANTRCV6250GV33_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\RamTst_Cfg.c         COPY %OUTPUT_DIR_PATH%\src\RamTst_Cfg.c               %RAMTST_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\RamTst_Lcfg.c        COPY %OUTPUT_DIR_PATH%\src\RamTst_Lcfg.c              %RAMTST_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\RamTst_Cfg.h         COPY %OUTPUT_DIR_PATH%\inc\RamTst_Cfg.h               %RAMTST_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\RamTst_CfgTypes.h    COPY %OUTPUT_DIR_PATH%\inc\RamTst_CfgTypes.h          %RAMTST_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\src\I2c_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\I2c_PBCfg.c %I2C_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\I2c_LCfg.c COPY %OUTPUT_DIR_PATH%\src\I2c_LCfg.c %I2C_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\I2c_Cfg.h COPY %OUTPUT_DIR_PATH%\inc\I2c_Cfg.h  %I2C_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\src\Dsadc_PBCfg.c COPY %OUTPUT_DIR_PATH%\src\Dsadc_PBCfg.c %DSADC_SRC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Dsadc_Cfg.h   COPY %OUTPUT_DIR_PATH%\inc\Dsadc_Cfg.h  %DSADC_INC_PATH%

IF EXIST %OUTPUT_DIR_PATH%\mak\infineon_ramtst_cfg.mak COPY %OUTPUT_DIR_PATH%\mak\infineon_ramtst_cfg.mak %RAMTST_MAK_PATH%
IF EXIST %OUTPUT_DIR_PATH%\inc\Dem_PBcfg.h COPY %OUTPUT_DIR_PATH%\inc\Dem_PBcfg.h %DEM_INC_PATH%
IF EXIST %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\ModuleDelivery.bat COPY %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\ModuleDelivery.bat  %DEMO_BAT_PATH%
IF EXIST %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\DemoApp_Cfg.h COPY %OUTPUT_DIR_PATH%\Demo_%CONTROLLER_PLUGIN%\DemoApp_Cfg.h  %DEMO_INC_PATH%
REM PAUSE

rmdir /S /Q %OUTPUT_DIR_PATH%
mkdir %OUTPUT_DIR_PATH%

REM ****************************************************************************
REM  End of the MCAL_OpUpdate.bat file
REM ****************************************************************************
