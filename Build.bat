ECHO OFF

Set NSIS_PATH=C:\Progra~2\NSIS
Set PYTHON_BUILD_SCRIPT=SCopy\setup.py
Set NSIS_SCRIPT=Build\smartcopy.nsi

Set QT_SRC=C:\Anaconda3\Library\plugins\platforms
Set QT_DEST= Output\platforms 

ECHO What do you want?
CHOICE /c 123 /m "1:build 2:NSIS Package 3:build+NSIS Package"
IF %ERRORLEVEL% EQU 1 goto Build_procedure
IF %ERRORLEVEL% EQU 2 goto Package_procedure
IF %ERRORLEVEL% EQU 3 goto Both_procedure

:Build_procedure 
    ECHO "build_procedure"
    start python %PYTHON_BUILD_SCRIPT% build
GOTO:EOF

:Package_procedure 
    ECHO "Package_procedure"
    start %NSIS_PATH%\makensis.exe /V4 %NSIS_SCRIPT%
GOTO:EOF

:Both_procedure
    ECHO "Both_procedure"
    START python %PYTHON_BUILD_SCRIPT% build
    ECHO  "Build finishd Successfully!"
    START %NSIS_PATH%\makensis.exe /V4 %NSIS_SCRIPT%
GOTO:EOF