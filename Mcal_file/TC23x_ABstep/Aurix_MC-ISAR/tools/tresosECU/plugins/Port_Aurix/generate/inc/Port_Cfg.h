[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Port_Cfg.h $                                               **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\8 $                                **
**                                                                            **
**  $DATE       : 2016-04-07 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : Code template for Port_Cfg.h file                           **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_Port_Driver,Release 4.0                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=SAS_AS_PORT076,SAS_AS_PORT100,
                 DS_NAS_PORT_PR700,DS_NAS_PORT_PR701,DS_NAS_PORT_PR704,
                 DS_NAS_PORT_PR707,DS_NAS_PORT_PR708,DS_NAS_PORT_PR709,
                 DS_NAS_PORT_PR712,DS_NAS_PORT_PR713,DS_NAS_PORT_PR714,
                 DS_NAS_PORT_PR716,DS_NAS_PORT_PR717,DS_NAS_PORT_PR719,
                 DS_NAS_PORT_PR720,DS_NAS_PORT_PR723,DS_NAS_PORT_PR724,
                 DS_NAS_PORT_PR728,DS_NAS_PORT_PR741,DS_NAS_PORT_PR446,
                 SAS_NAS_PORT_PR914,SAS_NAS_PORT_PR915,SAS_NAS_PORT_PR916,
                 SAS_AS4XX_PORT_PR678,DS_NAS_EP_PORT_PR3054_1,
                 DS_NAS_EP_PORT_PR3054_2,DS_NAS_EP_PORT_PR3054_4]
                 [/cover] */!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Port_Cfg.h                                                    **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\8 $                                **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Port configuration generated from 
                   ECU configuration file (Port.bmd )                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H
[!//
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Port')[1]"!][!//. 
[!//
[!NOCODE!][!//
[!INCLUDE "..\Port.m"!][!//
[!ENDNOCODE!][!//
[!//
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
[!ASSERT "not(PortGeneral/PortPBFixedAddress = 'true')"!][!//
For EcuMPostBuildConfigType = Loadable, PortPBFixedAddress should be False[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!NOCODE!][!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!][!//
[!ENDNOCODE!]
#define PORT_AR_RELEASE_MAJOR_VERSION     ([!"$MajorVersion"!]U)
#define PORT_AR_RELEASE_MINOR_VERSION     ([!"$MinorVersion"!]U)
#define PORT_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)

[!VAR "MajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleSoftwareVer,"\.",'')"!][!//
#define PORT_SW_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define PORT_SW_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define PORT_SW_PATCH_VERSION  ([!"$RevisionVersion"!]U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
                     Container : PortGeneralConfiguration
*/


/*
Configuration: PORT_DEV_ERROR_DETECT
- if Selected, DET is Enabled 
- if Deselected, DET is Disabled 
*/
[!VAR "nodeval" = "PortGeneral/PortDevErrorDetect"!][!//
[!IF "$nodeval = 'true'"!][!//
#define PORT_DEV_ERROR_DETECT       (STD_ON)
[!ELSE!][!//
#define PORT_DEV_ERROR_DETECT       (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PORT_VERSION_INFO_API 
- if Selected,  Function Port_GetVersionInfo is available  
- if Deselected, Function Port_GetVersionInfo is not available 
*/
[!VAR "nodeval" = "PortGeneral/PortVersionInfoApi"!][!//
[!IF "$nodeval = 'true'"!][!//
#define PORT_VERSION_INFO_API       (STD_ON)
[!ELSE!][!//
#define PORT_VERSION_INFO_API       (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PORT_SET_PIN_MODE_API 
- if Selected,  Function Port_SetPinMode is available  
- if Deselected, Function Port_SetPinMode is not available 
*/
[!VAR "nodeval" = "PortGeneral/PortSetPinModeApi"!][!//
[!IF "$nodeval = 'true'"!][!//
#define PORT_SET_PIN_MODE_API       (STD_ON)
[!ELSE!][!//
#define PORT_SET_PIN_MODE_API       (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PORT_SET_PIN_DIRECTION_API
- if Selected,  Function Port_SetPinDirection is available  
- if Deselected, Function Port_SetPinDirection is not available 
*/
[!VAR "nodeval" = "PortGeneral/PortSetPinDirectionApi"!][!//
[!IF "$nodeval = 'true'"!][!//
#define PORT_SET_PIN_DIRECTION_API  (STD_ON)
[!ELSE!][!//
#define PORT_SET_PIN_DIRECTION_API  (STD_OFF)
[!ENDIF!][!//

[!VAR "PortPBFixAddr" = "'STD_OFF'"!][!//
[!IF "node:exists(PortGeneral/PortPBFixedAddress)"!][!//
[!IF "PortGeneral/PortPBFixedAddress = 'true'"!][!//
[!VAR "PortPBFixAddr" = "'STD_ON'"!][!//
[!ELSE!][!//
[!VAR "PortPBFixAddr" = "'STD_OFF'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
/* Port Fixed Address usage */
#define PORT_PB_FIXEDADDR           ([!"$PortPBFixAddr"!])

[!IF "(PortGeneral/PortRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "PortGeneral/PortUserModeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "PortGeneral/PortUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: PortRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
PortUserModeRuntimeApiEnable or PortUserModeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//
/*
Configuration: PORT_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
#define PORT_RUNNING_IN_USER_0_MODE_ENABLE   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "PortGeneral/PortRunningInUser0Mode"!][!//

/*
Configuration: PORT_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
#define PORT_USER_MODE_INIT_API_ENABLE         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "PortGeneral/PortUserModeInitApiEnable"!][!//

/*
Configuration: PORT_USER_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
#define PORT_USER_MODE_RUNTIME_API_ENABLE           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "PortGeneral/PortUserModeRuntimeApiEnable"!][!//



/*
Configuration: PORT_SAFETY_ENABLE
- if Selected,  Safety feature is enabled
- if Deselected, Safety features is disabled 
*/
[!VAR "nodeval" = "PortSafety/PortSafetyEnable"!][!//
[!IF "$nodeval = 'true'"!][!//
#define PORT_SAFETY_ENABLE  (STD_ON)
[!ELSE!][!//
#define PORT_SAFETY_ENABLE  (STD_OFF)
[!ENDIF!][!//


/*
Configuration: PORT_INIT_CHECK_API
- if Selected,  Safety feature is enabled
- if Deselected, Safety features is disabled 
*/
[!VAR "nodeval" = "PortSafety/PortInitCheckApi"!][!//
[!IF "PortSafety/PortSafetyEnable = 'true'"!][!//
[!IF "$nodeval = 'true'"!][!//
#define PORT_INIT_CHECK_API  (STD_ON)
[!ELSE!][!//
#define PORT_INIT_CHECK_API  (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
#define PORT_INIT_CHECK_API  (STD_OFF)
[!ENDIF!][!//

                                              
/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 
*/
[!CALL "CG_GetAvailablePorts00to31"!][!//

/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 9 is for Port 41 
*/
[!CALL "CG_GetAvailablePorts32to63"!][!//

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 
*/
[!CALL "CG_GetReadOnlyPorts00to31"!][!//

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 9 is for Port 41 
*/
[!CALL "CG_GetReadOnlyPorts32to63"!][!//

/* Maximum Port Number(Hex) */
[!CALL "CG_GetMaxPortNum"!][!//

/* Maximum PortPinID */
[!CALL "CG_GetMaxAvailablePortPinId"!][!//

/* Max Port Number available */
[!CALL "CG_GetNumOfPorts"!][!//


[!CALL "CG_GetPCSRPorts00to31"!][!//

/* Definition to specify the ports that PCSR on the
   microcontroller
   Bit value = 0 implies the port supports PCSR
   Bit value = 1 implies the port does not support PCSR
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 9 is for Port 41 
*/
[!CALL "CG_GetPCSRPorts32to63"!][!//

/* Definitions to specify the pins available in the port 
   Bit value = 0 implies the pin is not available
   Bit value = 1 implies the pin is available
   Bit 0 is for Pin 0, Bit 1 is for Pin 1, ... , Bit 15 is for Pin 15
*/
[!CALL "CG_GetAvailablePortPins"!][!//
/* Total nubber of port config sets */
#define PORT_CONFIG_COUNT   ([!"num:i(count(PortConfigSet/*))"!]U)
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
[!VAR "ConfigCount" = "num:i(count(PortConfigSet/*))"!][!//
[!FOR "CfgPosition" ="num:i(1)" TO "num:i(($ConfigCount))"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
/* 
  User Defined Symbolic names of all port pins Port_ConfigSet[!"num:i(string($CfgPosition)- num:i(1))"!]
*/

[!FOR "PortNumber" = "num:i(0)" TO "num:i(ecu:get('Port.MaxAvailablePort'))"!][!//
[!//
[!IF "contains(ecu:get('Port.PortsAvailable'), concat('_', $PortNumber, '_'))"!][!//
/*
                                   Port[!"$PortNumber"!]                                      
*/
[!CALL "CG_GetPortPinSymbolicName","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//

[!ENDIF!][!//
[!//
[!ENDFOR!]

[!ENDFOR!][!//

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

#endif /* PORT_CFG_H */
[!ENDSELECT!]
