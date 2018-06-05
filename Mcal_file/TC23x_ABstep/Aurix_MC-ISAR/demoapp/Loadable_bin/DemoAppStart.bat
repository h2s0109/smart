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
REM *  DATE      : 2016.04.04                                                 **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file creates the DemoApplication for loadable cfg  **
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
REM * AT          Angeswaran Thangaswamy                                      **
REM * Prakash     Prakash Gudnavar                                            **
REM * Rutuja      Rutuja Kawathekar                                           **
REM * Basheer     Basheer Mohaideen                                           **
REM ***************************************************************************/


REM ****************************************************************************
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM * v1.1.1: 2016.04.04, Ravikiran : updated for TC29xBC Step.
REM * v1.1.0: 2015.03.30, Angeswaran : updated for TC27xDB Step.
REM                       - Controller Name to be passed with step name
REM                       - Param 4 is used to select C90 or C99 option
REM                       - Param 6 is used to enable/disable the Tasking
REM                       - linker optimization options
REM * v1.0.0: 2014.09.15, AT : Updated for TC22x.
REM * v0.1.0: 2013.06.14, AT : Updated for TC26x and TC29x.
REM * v0.0.9: 2012.11.24, AT : Updated for multi compiler support.
REM * v0.0.8: 2010.07.24, Basheer : Added Support for Thebe controllers.
REM * v0.0.7: 2010.04.09, Basheer : Updated as per UTP: AI00053090.
REM - Message added inside the demo_build_complete "Demo Build successfully"
REM - Introduced label demo_build_failed, if gnu make does not return successfully.
REM * v0.0.6, 2009.06.01, Hamzath : changed to suit Audo
REM * v0.0.6, 2009.06.01, Hamzath : changed to suit Audo
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
SET SSC_ROOT=%SSC_ROOT:\demoapp\Loadable_bin\=%
SET SSC_ROOT=%SSC_ROOT: =" "%
SET SSC_ROOT=%SSC_ROOT:\=/%
REM ****************************************************************************
REM  Get GNU Root Path 
REM ****************************************************************************
SET GNU_MAKE_PATH=%~dp0
SET GNU_MAKE_PATH=%GNU_MAKE_PATH:\Aurix_MC-ISAR\demoapp\Loadable_bin\=%
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

SET APP_CONFIG=POSTBUILD_LOADABLE


REM ****************************************************************************
REM  Generate Module Configuration Files by calling the Code Generator 
REM ****************************************************************************

ECHO STEP1: ................Generate Configuration Files............................

SET TRESOS_PATH=%1

IF NOT EXIST %TRESOS_PATH% goto errorlabel

CALL %TRESOS_PATH%\tresos_cmd.bat -data %SSC_ROOT%\demoapp\cfg\tresos_workspace\Loadable_Cfg generate DemoApp

REM ******Set controller variable happens in ModuleDelivery.bat file.

SET SECOND_PARAM=%2
SET CONTROLLER_PLUGIN=%2
IF %SECOND_PARAM% == TC27xBC SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC27xCA SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC27xDB SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC27xDC SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC26xBB SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC29xBB SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC29xBC SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC23xAB SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC22xAB SET CONTROLLER_PLUGIN=Aurix
IF %SECOND_PARAM% == TC21xAB SET CONTROLLER_PLUGIN=Aurix

SET DEVICE_STEP=%2
SET COMPILER_CHOICE=TASKING
SET COMPILER_TASKING_VER=V4

IF NOT "%3" == "" SET COMPILER_CHOICE=%3
IF "%3" == "TASKING_V4" SET COMPILER_CHOICE=TASKING
IF "%3" == "TASKING_V5" SET COMPILER_CHOICE=TASKING
IF "%3" == "TASKING_V5" SET COMPILER_TASKING_VER=V5

IF "%3" == "GNU" SET COMPILER_CHOICE=GNU
IF "%3" == "WINDRIVER" SET COMPILER_CHOICE=WINDRIVER

SET C_STANDARD=C90
IF "%4" == "C99" SET C_STANDARD=C99

REM variable to enable/disable the Tasking linker optimization
SET LTC_OPTM_ENABLED=YES
IF "%5" == "NO" SET LTC_OPTM_ENABLED=NO

SET PERL_AVAILABLE=NO
IF NOT "%6" == "" SET PERL_AVAILABLE=YES
IF NOT "%6" == "" SET PERL_TOOLPATH=%6
IF "%6" == "" SET PERL_TOOLPATH=.


CALL %SSC_ROOT%\demoapp\Loadable_bin\MCAL_OpFileUpdate.bat

REM mTrain need not be called as Gpta_PBCfg.c is not required in Loadable elf
REM *Set the environment variables as per module delivery 
CALL %SSC_ROOT%\demoapp\Loadable_bin\ModuleDelivery.bat
REM *********************************************************************************************************
REM  Removed syntax error due to invocation of sh.exe instead of command.exe due to installation of cygwin 
REM with path variable containg the cygwin bin folder path 
REM *********************************************************************************************************
REM SET _TEMP_PATH=%PATH%
REM SET PATH=

REM ****************************************************************************
REM  Build Demo Application
REM ****************************************************************************

ECHO STEP2: Build Demo Application
@"%GNU_MAKE_PATH%\gnumake.exe" -f %SSC_ROOT%\mak\demoapp\ssc\mak\DemoApp.mak 
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
REM  Demo Build success and Restoring the PATH variable 
REM ****************************************************************************
SET PATH=%_TEMP_PATH%
ECHO Demo build Successfully.
goto end

:errorlabel
ECHO Tresos tool path does not exist or not given.
goto end

:end
PAUSE