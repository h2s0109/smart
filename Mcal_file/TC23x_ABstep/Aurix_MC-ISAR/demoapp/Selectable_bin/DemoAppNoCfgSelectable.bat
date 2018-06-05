@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2011)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : DemoAppNoCfgSelectable.bat                                 **
REM *                                                                         **
REM *  VERSION   : 0.0.6                                                      **
REM *                                                                         **
REM *  DATE      : 2011.03.10                                                 **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file creates the DemoApplication                   **
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
REM * Prakash     Prakash Gudnavar                                            **
REM ***************************************************************************/


REM ****************************************************************************
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM * V0.0.5: 2009.06.15, added fourth parameter
REM * V0.0.4: 2009.05.12, Added SCI
REM * V0.0.3: 2009.05.01, Added Cantrcv, FR, FADC modules
REM * V0.0.2: 2008.05.07, Prakash  : Added support for FEE driver
REM *
REM * V0.0.1: 2008.04.27, Prakash  : Initial version 
REM ***************************************************************************/

@ECHO OFF
REM ****************************************************************************
REM  Get MCAL Root Path 
REM ****************************************************************************

REM ****************************************************************************
REM  Module Delivery Switches ON/OFF  ON moduled is delivered OFF moduled is not delivered
REM Ensure That all the dependent modules are made ON
REM ****************************************************************************

REM ****************************************************************************
REM Choose between Selectable and loadable
REM POSTBUILD_SELECTABLE or POSTBUILD_LOADABLE
REM ***************************************************************************

REM ****************************************************************************
REM  Generate Module Configuration Files by calling the Code Generator 
REM ****************************************************************************

REM ****************************************************************************
REM ****************************************************************************

IF %DRIVER_NAME%==CAN SET DRIVER_NAME_TITLE_CASE=Can
IF %DRIVER_NAME%==FEE SET DRIVER_NAME_TITLE_CASE=Fee
IF %DRIVER_NAME%==GPT SET DRIVER_NAME_TITLE_CASE=Gpt
IF %DRIVER_NAME%==SPI SET DRIVER_NAME_TITLE_CASE=Spi
IF %DRIVER_NAME%==ADC SET DRIVER_NAME_TITLE_CASE=Adc
IF %DRIVER_NAME%==PWM SET DRIVER_NAME_TITLE_CASE=Pwm
IF %DRIVER_NAME%==WDG SET DRIVER_NAME_TITLE_CASE=Wdg
IF %DRIVER_NAME%==ICU SET DRIVER_NAME_TITLE_CASE=Icu
IF %DRIVER_NAME%==DIO SET DRIVER_NAME_TITLE_CASE=Dio
IF %DRIVER_NAME%==DMA SET DRIVER_NAME_TITLE_CASE=Dma
IF %DRIVER_NAME%==FADC SET DRIVER_NAME_TITLE_CASE=Fadc
IF %DRIVER_NAME%==SCI SET DRIVER_NAME_TITLE_CASE=Sci
IF %DRIVER_NAME%==MSC SET DRIVER_NAME_TITLE_CASE=Msc
IF %DRIVER_NAME%==MLI SET DRIVER_NAME_TITLE_CASE=Mli
IF %DRIVER_NAME%==MCHK SET DRIVER_NAME_TITLE_CASE=Mchk

REM ****************************************************************************
REM Create DemoApp_Cfg.h
REM ****************************************************************************
type %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h.Part1 > %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h

@echo #define MCU_DELIVERY  (ON) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define DIO_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define PORT_DELIVERY  (ON) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define IRQ_DELIVERY  (ON) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define GTM_DELIVERY  (ON) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define CAN_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define SPI_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define ICU_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define GPT_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define ADC_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define FLS_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define FEE_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define MSC_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define MLI_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define SCI_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define FADC_DELIVERY (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define PWM_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define WDG_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define LIN_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define FR_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define FADC_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define MCHK_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define CANTRCV6250GV33_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define CANTRCV6251G_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define FLSLOADER_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define DMA_DELIVERY  (OFF) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
@echo #define %DRIVER_NAME%_DELIVERY  (ON) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h
IF %DRIVER_NAME%==FEE @echo #define FLS_DELIVERY  (ON) >> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h

@echo #endif /* DEMOAPP_CFG_H */>> %SSC_ROOT%\demoapp\inc\DemoApp_Cfg.h

REM ****************************************************************************
REM Create ModuleDelivery.bat
REM ****************************************************************************
@echo @ECHO OFF > %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET PORT_DELIVERY=ON>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET MCU_DELIVERY=ON>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET DIO_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET IRQ_DELIVERY=ON>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET GTM_DELIVERY=ON>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET CAN_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET SPI_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET ICU_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET GPT_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET ADC_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET FLS_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET FEE_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET MSC_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET MLI_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET SCI_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET FADC_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET PWM_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET WDG_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET LIN_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET FR_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET FLSLOADER_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET MCHK_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET CANTRCV6250GV33_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET CANTRCV6251G_DELIVERY=OFF>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET %DRIVER_NAME%_DELIVERY=ON>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
@echo SET CONTROLLER=%THIRD_PARAM%>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
IF %DRIVER_NAME%==FEE @echo SET FLS_DELIVERY=ON>> %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat


REM ****************************************************************************
REM Create EcuM_Cfg.h file
REM ****************************************************************************
type %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h.Part1 > %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo #define ECUM_USES_PORT >> %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo #define ECUM_USES_GTM >> %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h

IF %DRIVER_NAME%==BASE goto proceed_ecum_cfg_h_1

IF %DRIVER_NAME%==FEE @echo #define ECUM_USES_FLS >> %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h

@echo #define ECUM_USES_%DRIVER_NAME% >> %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h

:proceed_ecum_cfg_h_1
type %SSC_ROOT%\ecum_infineon_tricore\cfg1\inc\EcuM_Cfg.h.Part2 >> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

@echo Port_Init(configptr-^>Port_ConfigData);   \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

IF %DRIVER_NAME%==BASE goto proceed_ecum_cfg_h_2

IF %DRIVER_NAME%==DIO goto proceed_ecum_cfg_h_2
IF %DRIVER_NAME%==FLSLOADER goto proceed_ecum_cfg_h_2
IF %DRIVER_NAME%==CANTRCV6250GV33 goto proceed_ecum_cfg_h_2
IF %DRIVER_NAME%==CANTRCV6251G goto proceed_ecum_cfg_h_2

IF %DRIVER_NAME%==FEE  goto proceed_ecum_cfg_h_3

@echo %DRIVER_NAME_TITLE_CASE%_Init(configptr-^>%DRIVER_NAME_TITLE_CASE%_ConfigData);   \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
goto proceed_ecum_cfg_h_2

:proceed_ecum_cfg_h_3
@echo Fls_Init(configptr-^>Fls_ConfigData);   \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo Fee_Init();   \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo   do  \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo   {  \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo     Fls_MainFunction();  \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo     Fee_MainFunction();  \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo   } while(Fee_GetStatus() != MEMIF_IDLE);/* Wait for FEE Init to complete*/  \>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

:proceed_ecum_cfg_h_2
REM Do nothing

@echo }>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo #define EcuM_DriverInitListTwoConfig(configptr) {}>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
@echo #define EcuM_DriverRestartListConfig() {}>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

type %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h.Part3 >> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
  
@echo const struct Port_ConfigType   * Port_ConfigData;>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

IF %DRIVER_NAME%==BASE goto proceed_ecum_cfg_h_4
IF %DRIVER_NAME%==DIO goto proceed_ecum_cfg_h_4
IF %DRIVER_NAME%==FLSLOADER goto proceed_ecum_cfg_h_4
IF %DRIVER_NAME%==CANTRCV6250GV33 goto proceed_ecum_cfg_h_4
IF %DRIVER_NAME%==CANTRCV6251G goto proceed_ecum_cfg_h_4

IF %DRIVER_NAME%==FEE  goto proceed_ecum_cfg_h_5

@echo const struct %DRIVER_NAME_TITLE_CASE%_ConfigType   * %DRIVER_NAME_TITLE_CASE%_ConfigData;>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h
goto proceed_ecum_cfg_h_4

:proceed_ecum_cfg_h_5
@echo const struct Fls_ConfigType   * Fls_ConfigData;>> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

:proceed_ecum_cfg_h_4
REM Do nothing

type %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h.Part4 >> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\inc\EcuM_Cfg.h

REM ****************************************************************************
REM Create EcuM_PBCfg.c file
REM ****************************************************************************

type %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c.Part1 > %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c

@echo     ^&Port_ConfigRoot[0],>>  %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c

IF %DRIVER_NAME%==BASE goto proceed_ecum_pb_cfg_h_4
IF %DRIVER_NAME%==FEE  goto proceed_ecum_pb_cfg_h_5
IF %DRIVER_NAME%==DIO goto proceed_ecum_pb_cfg_h_4
IF %DRIVER_NAME%==FLSLOADER goto proceed_ecum_pb_cfg_h_4
IF %DRIVER_NAME%==CANTRCV6250GV33 goto proceed_ecum_pb_cfg_h_4
IF %DRIVER_NAME%==CANTRCV6251G goto proceed_ecum_pb_cfg_h_4


@echo     ^&%DRIVER_NAME_TITLE_CASE%_ConfigRoot[0],>>  %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c
goto proceed_ecum_pb_cfg_h_4

:proceed_ecum_pb_cfg_h_5
@echo     ^&Fls_ConfigRoot[0],>>  %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c

:proceed_ecum_pb_cfg_h_4
REM Do nothing

type %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c.Part2 >> %SSC_ROOT%\EcuM_infineon_tricore\cfg1\src\EcuM_PBCfg.c

REM ****************************************************************************
REM Create Gpta_Cfg.h file
REM ****************************************************************************
SET GTM_CFG_H_FILE=%SSC_ROOT%\mcu_infineon_tricore\cfg1\inc\Gtm_Cfg.h
echo #ifndef GTMCFG_H> %GTM_CFG_H_FILE%
echo #define GTMCFG_H>> %GTM_CFG_H_FILE%

REM -yg echo #define GPTA1_USED (OFF)>> %GPTA_CFG_H_FILE%
REM -ygecho #define LTCA2_USED (OFF)>> %GPTA_CFG_H_FILE%
echo #define GTM_GPT_MODULE_USED  (OFF)>> %GTM_CFG_H_FILE%
echo #define GTM_ICU_MODULE_USED  (OFF)>> %GTM_CFG_H_FILE%
echo #define GTM_SPI_MODULE_USED  (OFF)>> %GTM_CFG_H_FILE%
echo #define GTM_PWM_MODULE_USED  (OFF)>> %GTM_CFG_H_FILE%


echo #undef GTM_%DRIVER_NAME%_MODULE_USED >> %GTM_CFG_H_FILE%
IF NOT %DRIVER_NAME%==SPI echo #define GTM_%DRIVER_NAME%_MODULE_USED  (ON)>> %GTM_CFG_H_FILE%

echo extern const struct  Gtm_ConfigType Gtm_ConfigRoot[];>> %GTM_CFG_H_FILE%

echo #endif>> %GTM_CFG_H_FILE%

goto end

REM ****************************************************************************
:end
