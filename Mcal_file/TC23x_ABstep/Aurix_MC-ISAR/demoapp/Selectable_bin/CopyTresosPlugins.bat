@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2007)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : CopyTresosPlugins.bat                                      **
REM *                                                                         **
REM *  VERSION   : 0.0.2                                                      **
REM *                                                                         **
REM *  DATE      : 2007.12.13                                                 **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file copies driver plugins for Tresos Studio       **
REM *                                                                         **
REM *  MAY BE CHANGED BY USER [yes/no]: no                                    **
REM *                                                                         **
REM ***************************************************************************/

REM ****************************************************************************
REM *                      Author(s) Identity                                 **
REM ****************************************************************************
REM *                                                                         **
REM * Initials     Name                                                       **
REM * ------------------------------------------------------------------------**
REM * Prakash     Prakash Gudnavar                                            **
REM *                                                                         **
REM ***************************************************************************/

REM ****************************************************************************
REM *                      Revision Control History                           **
REM ***************************************************************************/
REM
REM * V0.0.2: 2007.12.13, Hamzath: /D option removed
REM * V0.0.1: 2007.09.21, Prakash  : Initial version 
REM *
REM ***************************************************************************/

REM ****************************************************************************

REM  Check if destination folder is mentioned on command line
IF "%1" == "" GOTO NO-DST-DIR

REM  Check if destination folder exists
IF NOT EXIST %1 GOTO DST-DIR-DOESNOT-EXIST

REM  Copy plugin files
REM ----------------------------------------------------------------------------
REM /S - Copies directories and subdirectories except empty ones.
REM /R - Overwrites read-only files.
REM /K - Copies attributes. Normal Xcopy will reset read-only attributes.
REM /Y - Suppresses prompting to confirm you want to overwrite an
REM       existing destination file.
REM /F - Display full file path
REM ----------------------------------------------------------------------------
xcopy /S/R/K/Y/F ..\..\tools\tresosECU\plugins %1
IF "%2" == "YES" GOTO LICENSE_COPY
IF "%2" == "Yes" GOTO LICENSE_COPY
GOTO END

:LICENSE_COPY
xcopy ..\..\tools\tresosECU\license\tresos_Partner_Infineon.lic %1\..\configuration
GOTO END

:NO-DST-DIR
ECHO Error: Destination (plugins) directory not mentioned.
ECHO Usage: copy_plugins.bat destination-folder
GOTO END

:DST-DIR-DOESNOT-EXIST
ECHO Error: Destination folder doesn't exist

:END
