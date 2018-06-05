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
REM *  FILENAME  : DemoAppClean.bat                                           **
REM *                                                                         **
REM *  VERSION   : 0.0.6                                                      **
REM *                                                                         **
REM *  DATE      : 2010.03.10                                                 **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file is used to Cleaning the object                **      
REM *                 generated during build                                  **
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
REM * RS           Roopa Sirur                                                **
REM * Rutuja       Rutuja Kawathekar                                          **
REM * Basheer      Basheer Mohaideen                                          **
REM * YG              Yogesh G                                                   **
REM ***************************************************************************/


REM ****************************************************************************
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM * v0.0.6: 2011.03.10, YG : Audo changed to Aurix
REM * v0.0.5: 2007.01.02, Basheer: call ModuleDelivery batch file
REM * v0.0.4: 2007.12.11, Rutuja : Added ERU, CAN support
REM * v0.0.3: 2007.12.08, Rutuja : Added Mchk, split clean
REM * v0.0.2: 2007.11.28, Rutuja : Added Msc,Sci
REM * V0.0.1: 2007.09.19, RS  : Initial version
REM *
REM ***************************************************************************/


REM ****************************************************************************
REM  Get MCAL Root Path 
REM ****************************************************************************
SET SSC_ROOT=%~dp0
SET SSC_ROOT=%SSC_ROOT:\demoapp\Selectable_bin\=%
SET SSC_ROOT=%SSC_ROOT: =" "%

REM ****************************************************************************
REM  Get GNU Root Path 
REM ****************************************************************************
SET GNU_MAKE_PATH=%~dp0
SET GNU_MAKE_PATH=%GNU_MAKE_PATH:\Aurix_MC-ISAR\demoapp\Selectable_bin\=%
SET GNU_MAKE_PATH=%GNU_MAKE_PATH%\GNU

REM ****************************************************************************
REM  CALL ModuleDelivery batch 
REM ****************************************************************************
CALL %SSC_ROOT%\demoapp\Selectable_bin\ModuleDelivery.bat

REM ****************************************************************************
REM  Cleaning the object generated during build
REM ****************************************************************************

ECHO Cleaning the object files generated during build
"%GNU_MAKE_PATH%\gnumake.exe" -f %SSC_ROOT%\mak\demoapp\ssc\mak\DemoApp.mak clean
"%GNU_MAKE_PATH%\gnumake.exe" -f %SSC_ROOT%\mak\demoapp\ssc\mak\DemoApp.mak clean_loadable_cfg_data
PAUSE
