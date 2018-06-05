[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Iom_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  $DATE       : 2016-03-18 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Iom_Cfg.h file                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  FILENAME  : Iom_Cfg.h                                                    **
**                                                                           **
**  $CC VERSION : \main\9 $                                                  **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                     **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : IOM configuration generated out of ECU configuration      **
**                 file (Iom.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/


#ifndef IOM_CFG_H
#define IOM_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#define IOM_ACCEN_DEFAULT (0U)
#define IOM_ACCEN_INIT (1U)
#define IOM_ACCEN_API (2U)
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define IOM_CONFIG_COUNT  				  ([!"num:i(count(IomConfigSet))"!]U)
[!SELECT "as:modconf('Iom')[1]"!][!//
[!//
[!AUTOSPACING!][!// 
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//

#define IOM_SW_MAJOR_VERSION              ([!"$SwMajorVersion"!]U)
#define IOM_SW_MINOR_VERSION              ([!"$SwMinorVersion"!]U)
#define IOM_SW_PATCH_VERSION              ([!"$SwPatchVersion"!]U)  

[!NOCODE!][!//
[!/* For loadable build PBfixedAddress should be False */!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$PostBuildType = 'LOADABLE'"!][!//
[!ASSERT "not(IomGeneral/IomPBFixedAddress = 'true')"!][!//
For EcuMPostBuildConfigType = Loadable, IomPBFixedAddress should be False[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//

/* Configuration: IOM_VERSION_INFO_API
Preprocessor switch for enabling version information Iom_GetVersionInfo() API  
- if STD_ON, VersionInfo API is Enabled 
- if STD_OFF, VersionInfo API is Disabled 
*/
#define IOM_VERSION_INFO_API  ([!//
[!IF "IomGeneral/IomVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Configuration: IOM_DEINIT_API
Preprocessor switch for enabling Iom_Deinit API 
- if STD_ON, Deinit API is Enabled 
- if STD_OFF, Deinit API is Disabled 
*/
#define IOM_DEINIT_API  ([!//
[!IF "IomGeneral/IomDeinitApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: IOM_DEV_ERROR_DETECT
Preprocessor switch for enabling the development error detection and 
reporting. 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define IOM_DEV_ERROR_DETECT  ([!//
[!IF "IomGeneral/IomDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

#define IOM_RESET_SFR_INIT  ([!//
[!IF "IomGeneral/IomResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


/*
Configuration: IOM_ACCEN_MODE
Preprocessor switch used to initialze access enable register 0
- if IOM_ACCEN_DEFAULT, access enable register has default value
- if IOM_ACCEN_INIT, access enable register is initialized during initialization
- if IOM_ACCEN_API, access enable register 0 is set by calling 
                    Iom_SetAccessEnReg0() API
  */

#define IOM_ACCEN_MODE ([!"IomGeneral/IomAccessEnableReg0"!])

[!NOCODE!][!//
[!//
[!VAR "TotalIomConfig" = "num:i(count(IomConfigSet/*))"!][!//
[!/* Determine only one IomConfigSet is configured 
                                        when IomPBFixedAddress = true.*/!]
[!IF "IomGeneral/IomPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalIomConfig != 1)"!][!//
Config Error: when IomGeneral/IomPBFixedAddress is set as true, [!//
Only one IomConfigSet configuration is allowed. [!//
But IomConfigSet has more than one configuration.[!//
[!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

 
 /*
Configuration: IOM_PB_FIXED_ADDRESS 
Preprocessor switch for selecting loadable fixed address feature. 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled 
*/
#define IOM_PB_FIXED_ADDRESS   ([!//
[!IF "IomGeneral/IomPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
/* Instance id for the IOM module */
#define IOM_INSTANCE_ID ([!"(IomGeneral/IomIndex )"!]U)

[!IF "(IomGeneral/IomRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "IomGeneral/IomUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "IomGeneral/IomUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "IomGeneral/IomUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: IomRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
IomUserModeRuntimeApiEnable, IomUserModeInitApiEnable or IomUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: IOM_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "IomGeneral/IomRunningInUser0Mode = 'true'"!][!//
#define IOM_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define IOM_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: IOM_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "IomGeneral/IomUserModeInitApiEnable = 'true'"!][!//
#define IOM_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  IOM_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: IOM_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "IomGeneral/IomUserModeDeInitApiEnable = 'true'"!][!//
#define IOM_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  IOM_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: IOM_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "IomGeneral/IomUserModeRuntimeApiEnable = 'true'"!][!//
#define IOM_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  IOM_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/




 /******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
  

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /* IOM_CFG_H */
