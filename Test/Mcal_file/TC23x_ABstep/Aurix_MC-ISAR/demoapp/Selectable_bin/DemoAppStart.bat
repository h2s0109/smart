@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2014)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : DemoAppStart.bat                                           **
REM *                                                                         **
REM *  VERSION   : 1.1.1                                                      **
REM *                                                                         **
REM *  DATE      : 2016.04.03                                                 **
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
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM * v1.1.1: 2016.04.03, Ravikiran : updated for TC29xBC Step.
REM * v1.1.0: 2015.03.30, Angeswaran : updated for TC27xDB Step.
REM                       - Controller Name to be passed with step name
REM                       - Param 5 is used to select C90 or C99 option
REM * v1.0.0: 2014.09.15, Angeswaran : updated for TC22x
REM * v0.1.7: 2013.06.13, Angeswaran : updated for TC26x and TC29x
REM * v0.1.6: 2012.09.07, Angeswaran : updated for WindRiver compiler
REM * v0.1.5: 2012.07.04, Angeswaran : Added compiler choice
REM * v0.1.4: 2011.03.21, Sai Kiran : Changed AurixFamily to Aurix
REM * v0.1.3: 2011.03.10, Yogesh  : Added Support for AURIX controllers.
REM                                             -removed AudoF,AudoM,Thebe controllers
REM                                             - removed GPTA mtrain commands
REM                                             - replaced GPTA with GTM
REM * v0.1.2: 2010.07.24, Basheer : Added Support for Thebe controllers.
REM * v0.1.1: 2010.04.09, Basheer : Updated as per UTP: AI00053090.
REM - Message added inside the demo_build_complete "Demo Executed successfully"
REM - Introduced label demo_build_failed, if gnu make does not return successfully.
REM - Removed redundant label demo_build_complete and demo_build_failed.
REM * v0.1.0: 2010.02.18, Prakash :
REM              - UTP AI00053231: Fr --> Fr_17_Eray, FR --> FR_17_ERAY
REM * v0.0.9: 2009.06.15, Hamzath : Added third parameter for AUDO NOCFG
REM * v0.0.8: 2009.06.01, Hamzath : Changed to suit Audo
REM * v0.0.7: 2009.04.29, Prakash : FlexRay demo: Added FlexTrain usage
REM * v0.0.6: 2009.02.24, Prakash : Added support for FlexRay driver demo
REM * v0.0.5: 2008.01.02, Hamzath : call ModuleDelivery batch file
REM * v0.0.4: 2007.12.03, Rutuja : Added support for Mchk driver delivery
REM * V0.0.3: 2007.11.28, Rutuja : Added support for Msc , SCI driver delivery
REM * V0.0.2: 2007.11.05, Prakash : Added support for CAN driver delivery
REM
REM * V0.0.1: 2007.09.20, RS  : Initial version
REM *
REM ***************************************************************************/

@ECHO OFF
REM ****************************************************************************
REM  Get MCAL Root Path
REM ****************************************************************************
SET SSC_ROOT=%~dp0
SET SSC_ELK_ROOT=%~dp0
SET SSC_ROOT=%SSC_ROOT:\demoapp\Selectable_bin\=%
SET SSC_ROOT=%SSC_ROOT: =" "%
SET SSC_ROOT=%SSC_ROOT:\=/%
SET SSC_HSM_ROOT=%SSC_ROOT:Aurix_MC-ISAR=Aurix_HSM_MC-ISAR%

REM ****************************************************************************
REM  Get GNU Root Path
REM ****************************************************************************
SET GNU_MAKE_PATH=%~dp0
SET GNU_MAKE_PATH=%GNU_MAKE_PATH:\Aurix_MC-ISAR\demoapp\Selectable_bin\=%
SET GNU_MAKE_PATH=%GNU_MAKE_PATH%\GNU


REM ****************************************************************************
REM  Set variables for integration
REM ****************************************************************************
SET DELIVERY_WITH_TEST=0
SET CODE_COVERAGE=0

REM ****************************************************************************
REM  Module Delivery Switches ON/OFF  ON moduled is delivered OFF moduled is not delivered
REM Ensure That all the dependent modules are made ON
REM ****************************************************************************

REM ****************************************************************************
REM Choose between Selectable and loadable
REM POSTBUILD_SELECTABLE or POSTBUILD_LOADABLE
REM ***************************************************************************

SET APP_CONFIG=POSTBUILD_SELECTABLE

SET FIRST_PARAM=%1
REM SET DRIVER_NAME=%2

REM ******Set controller to specific derivate
REM CONTROLLER can be set in the ModuleDelivery.bat

SET THIRD_PARAM=%3
SET CONTROLLER_PLUGIN=%3
IF %THIRD_PARAM% == TC27xBC SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC27xCA SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC27xDB SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC27xDC SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC26xBB SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC29xBB SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC29xBC SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC23xAB SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC22xAB SET CONTROLLER_PLUGIN=Aurix
IF %THIRD_PARAM% == TC21xAB SET CONTROLLER_PLUGIN=Aurix

SET DEVICE_STEP=%3

SET COMPILER_CHOICE=TASKING
SET COMPILER_TASKING_VER=V4
IF NOT "%4" == "" SET COMPILER_CHOICE=%4
IF "%4" == "TASKING_V4" SET COMPILER_CHOICE=TASKING
IF "%4" == "TASKING_V5" SET COMPILER_CHOICE=TASKING
IF "%4" == "TASKING_V5" SET COMPILER_TASKING_VER=V5
IF "%4" == "GNU" SET COMPILER_CHOICE=GNU
IF "%4" == "WINDRIVER" SET COMPILER_CHOICE=WINDRIVER

SET C_STANDARD=C90
IF "%5" == "C99" SET C_STANDARD=C99

REM variable to enable/disable the Tasking linker optimization
SET LTC_OPTM_ENABLED=YES
IF "%6" == "NO" SET LTC_OPTM_ENABLED=NO

SET PERL_AVAILABLE=NO
IF NOT "%7" == "" SET PERL_AVAILABLE=YES
IF NOT "%7" == "" SET PERL_TOOLPATH=%7
IF "%7" == "" SET PERL_TOOLPATH=.
IF "%7" == "NO_PERL" SET PERL_TOOLPATH=.
IF "%7" == "NO_PERL" SET PERL_AVAILABLE=NO

SET HSM_AVAILABLE=NO
IF "%8" == "HSM" SET HSM_AVAILABLE=YES



REM ****************************************************************************
REM  Demo option with/without config package
REM ****************************************************************************
IF %FIRST_PARAM%==CFG goto build_with_cfg_pkg
IF %FIRST_PARAM%==NOCFG goto build_with_no_cfg_pkg
goto error_invalid_first_param

:build_with_cfg_pkg
SET TRESOS_PATH=%2

IF NOT EXIST %SSC_ROOT%\demoapp\cfg goto error_no_cfg_pkg_installed
IF NOT EXIST %TRESOS_PATH% goto error_no_tresos_folder

REM ****************************************************************************
REM  Generate Module Configuration Files by calling the Code Generator
REM ****************************************************************************

ECHO STEP1: ................Generate Configuration Files............................

CALL %TRESOS_PATH%\tresos_cmd.bat -data %SSC_ROOT%\demoapp\cfg\tresos_workspace\Selectable_Cfg generate DemoApp
CALL %SSC_ROOT%\demoapp\Selectable_bin\MCAL_OpFileUpdate.bat

IF EXIST %SSC_HSM_ROOT%/hsm_infineon_tricore/ssc/src/Hsm.c CALL %SSC_ROOT%/demoapp/Selectable_bin/DemoAppHSMConfig.bat

REM ****************************************************************************
REM Build process common to both build_with_cfg_pkg and build_with_no_cfg_pkg options
REM ****************************************************************************
:build_common_stuff

REM *Set the environment variables as per module delivery
CALL %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat
REM *********************************************************************************************************
REM  Removed syntax error due to invocation of sh.exe instead of command.exe due to installation of cygwin
REM with path variable containg the cygwin bin folder path
REM *********************************************************************************************************
SET _TEMP_PATH=%PATH%
SET PATH=

REM ****************************************************************************
REM  Build Demo Application
REM ****************************************************************************

ECHO STEP2: Build Demo Application

IF %FR_DELIVERY%==STD_ON goto build_flexray

@"%GNU_MAKE_PATH%\gnumake.exe" -f %SSC_ROOT%\mak\demoapp\ssc\mak\DemoApp.mak
if NOT %errorlevel% == 0 Goto demo_build_failed
if %errorlevel% == 0 Goto demo_build_complete

:build_flexray
REM Run FlexTrain
%SSC_ROOT%\fr_17_eray_infineon_tricore\tool\FlexTrain.exe %SSC_ROOT%\fr_17_eray_infineon_tricore\cfg1\src\Fr_17_Eray_PBCfg.c
if NOT %errorlevel% == 0 Goto FrExitCodeIsOne
if %errorlevel% == 0 Goto FrExitCodeIsZero
:FrExitCodeIsZero
ECHO FlexTrain executed successfully.
REM Build demo application for FlexRay node 0
SET FR_17_ERAY_DELIVERY_SWITCH=0
IF EXIST %SSC_ROOT%\fr_17_eray_infineon_tricore\demo\obj\Fr_17_Eray_Demo.o del /F "%SSC_ROOT%"\fr_17_eray_infineon_tricore\demo\obj\Fr_17_Eray_Demo.o
IF EXIST %SSC_ROOT%\demoapp\obj\DemoApp.o del /F "%SSC_ROOT%"\demoapp\obj\DemoApp.o

@"%GNU_MAKE_PATH%\gnumake.exe" -f %SSC_ROOT%\mak\demoapp\ssc\mak\DemoApp.mak
move /Y ..\out\DemoAppSelectable.elf ..\out\DemoAppSelectable_node0.elf
if NOT %errorlevel% == 0 Goto demo_build_failed

REM Build demo application for FlexRay node 1
SET FR_17_ERAY_DELIVERY_SWITCH=1

del /F "%SSC_ROOT%"\fr_17_eray_infineon_tricore\demo\obj\Fr_17_Eray_Demo.o
del /F "%SSC_ROOT%"\demoapp\obj\DemoApp.o

@"%GNU_MAKE_PATH%\gnumake.exe" -f %SSC_ROOT%\mak\demoapp\ssc\mak\DemoApp.mak
move /Y ..\out\DemoAppSelectable.elf ..\out\DemoAppSelectable_node1.elf
if NOT %errorlevel% == 0 Goto demo_build_failed
if %errorlevel% == 0 Goto demo_build_complete

 :demo_build_failed
REM ****************************************************************************
REM  Demo Application failed
REM ****************************************************************************
ECHO Error: Demo build is Failed.
goto end

:demo_build_complete

REM ****************************************************************************
REM  Restoring the PATH variable
REM ****************************************************************************
SET PATH=%_TEMP_PATH%
ECHO Demo build Successfully.
goto end

REM ****************************************************************************
:error_no_cfg_pkg_installed
ECHO Error: Configuration package is not installed. You can use NOCFG option only.
goto end

:build_with_no_cfg_pkg

IF NOT EXIST %SSC_ROOT%\mcu_infineon_tricore goto error_no_basic_pkg_installed
IF NOT %DRIVER_NAME%==BASE IF NOT EXIST %SSC_ROOT%\%DRIVER_NAME%_infineon_tricore goto error_no_driver_pkg_installed
IF %DRIVER_NAME%==FLS goto error_no_fls_driver_demo

CALL DemoAppNoCfgSelectable.bat
goto build_common_stuff

:error_no_basic_pkg_installed
ECHO Error: Basic package is not installed.
goto end

:error_no_driver_pkg_installed
ECHO Error: %DRIVER_NAME% driver package is not installed.
goto end

:error_no_fls_driver_demo
echo "No FLS driver demo supported."
goto end

REM -yg :ExitCodeIsOne
REM -ygECHO mTrain Not Executed Successfully
REM -yg goto end

:FrExitCodeIsOne
ECHO FlexTrain execution failed.
goto end

REM ****************************************************************************
:end
PAUSE