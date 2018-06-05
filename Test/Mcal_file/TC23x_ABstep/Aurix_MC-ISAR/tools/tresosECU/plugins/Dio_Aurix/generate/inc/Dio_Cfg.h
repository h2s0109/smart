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
**   $FILENAME   : Dio_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\43 $                                                 **
**                                                                            **
**   $DATE       : 2016-07-21 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Dio configuration generated out of ECU configuration file  **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
********************************************************************************
** TRACEABILITY    : [cover parentID=DS_AS_DIO180,SAS_AS_DIO066,DS_AS_DIO113,
                     SAS_AS4XX_DIO181,SAS_AS_DIO026_1_DIO020,
                     DS_AS_DIO050_DIO057_DIO058,DS_AS_DIO128,SAS_AS_DIO071,
                     DS_NAS_DIO_PR700,DS_NAS_DIO_PR701,SAS_AS4XX_DIO_PR678,
                     DS_NAS_DIO_PR707,DS_NAS_DIO_PR708,DS_NAS_DIO_PR712,
                     DS_NAS_DIO_PR704,DS_NAS_DIO_PR724,DS_NAS_DIO_PR709,
                     DS_NAS_DIO_PR717,DS_NAS_DIO_PR728, DS_AS403_PR2849_1,
                     DS_AS403_PR2849_2, DS_AS403_PR2849_3,SAS_NAS_DIO_PR914,
                     SAS_NAS_DIO_PR915,DS_AS4XX_DIO_PR2849_1,
                     DS_AS4XX_DIO_PR2849_2,DS_AS4XX_DIO_PR2849_3,
                     SAS_AS_DIO026_2_DIO017,DS_AS4XX_HE2_DIO_PR2934,
                     DS_AS4XX_EP_DIO_PR2934,
                     DS_NAS_EP_DIO_PR3054_1,DS_NAS_HE2_DIO_PR3054_1,
                     DS_NAS_EP_DIO_PR3054_2,DS_NAS_HE2_DIO_PR3054_2,
                     DS_NAS_EP_DIO_PR3054_4,DS_NAS_HE2_DIO_PR3054_4]        **
**                [/cover]                                                    **
*******************************************************************************/
/************************************************************************/!][!//
[!//
/*******************************************************************************
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
**   $FILENAME   : Dio_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\43 $                                                 **
**                                                                            **
**   DATE, TIME  : [!"$date"!], [!"$time"!]                                       **
**                                                                            **
**   GENERATOR   : Build [!"$buildnr"!]                                         **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : DIO configuration generated out of ECU configuration       **
**                  file                                                      **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Dio')"!][!//
[!//
[!/* Include Code Generator Macros */!][!//
[!NOCODE!][!//
[!INCLUDE "..\Dio.m"!][!//
[!//
[!VAR "ConfigCount" = "num:i(count(DioConfig/*))"!][!//
[!ENDNOCODE!][!//
[!//
[!/* Verify the validity of DIO configuration */!][!//
[!CALL "CG_VerifyDioConfig"!][!//
[!//
/*
 Notes:
 - The runtime configuration is handled by the Port Driver Module.
 - The configuration and usage of the DIO Driver Module is adapted to
   the microcontroller and ECU.

*/

/*Version check macros */
[!NOCODE!][!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!][!//
[!ENDNOCODE!][!//
#define DIO_AR_RELEASE_MAJOR_VERSION     ([!"$MajorVersion"!]U)
#define DIO_AR_RELEASE_MINOR_VERSION     ([!"$MinorVersion"!]U)
#define DIO_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)

[!VAR "MajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleSoftwareVer,"\.",'')"!][!//
#define DIO_SW_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define DIO_SW_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define DIO_SW_PATCH_VERSION  ([!"$RevisionVersion"!]U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*                          Container: DioSafety                             */
/*
Configuration: DIO_SAFETY_ENABLE
- if STD_ON, Safety feature is available
- if STD_OFF, Safety feature is not available
*/
#define DIO_SAFETY_ENABLE                   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioSafety/DioSafetyEnable"!][!//

/*
Configuration: DIO_INITCHECK_API
- if STD_ON, Dio_InitCheck API is available
- if STD_OFF, Dio_InitCheck API is not available
*/
[!IF "(DioSafety/DioSafetyEnable = 'true')"!][!//
#define DIO_INITCHECK_API                   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioSafety/DioInitCheckApi"!][!//
[!ELSE!][!//
#define DIO_INITCHECK_API                   (STD_OFF)
[!ENDIF!][!//

/*                          Container: DioGeneral                            */
/*
Configuration: PORT_PB_FIXED_ADDRESS
- if STD_ON, PortPBFixedAddress feature is available
- if STD_OFF, PortPBFixedAddress feature is not available
*/
#define DIO_PB_FIXED_ADDRESS                [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioPBFixedAddress"!][!//

/*
  Pre-processor switch to enable/disable detection of Development errors.
  - if defined ON, Development error detection is enabled
  - if defined OFF, Development error detection is disabled
*/
#define DIO_DEV_ERROR_DETECT                [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioDevErrorDetect"!][!//

/*
  Pre-Compiler switch to include the API Dio_GetVersionInfo()
  - if defined ON, Dio_GetVersionInfo API available
  - if defined OFF, Dio_GetVersionInfo API not available
*/
#define DIO_VERSION_INFO_API                [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioVersionInfoApi"!][!//

/*
  Pre-Compiler switch to include the API Dio_FlipChannel()
  - if defined ON, Dio_FlipChannel API available
  - if defined OFF, Dio_FlipChannel API not available
*/
#define DIO_FLIP_CHANNEL_API                [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioFlipChannelApi"!][!//

[!IF "(DioGeneral/DioRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "DioGeneral/DioUserModeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "DioGeneral/DioUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: DioRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
DioUserModeRuntimeApiEnable or DioUserModeInitApiEnable
[!ENDASSERT!][!//
[!ENDIF!][!//
/*
Configuration: DIO_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, enable User0 mode
- if STD_OFF, enable User1 mode
*/
#define DIO_RUNNING_IN_USER_0_MODE_ENABLE   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioRunningInUser0Mode"!][!//

/*
Configuration: DIO_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API
- if STD_OFF, Enable Supervisor mode in Init API
*/
#define DIO_USER_MODE_INIT_API_ENABLE         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioUserModeInitApiEnable"!][!//

/*
Configuration: DIO_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
#define DIO_USER_MODE_RUNTIME_API_ENABLE           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "DioGeneral/DioUserModeRuntimeApiEnable"!][!//

/* No. of Configuration Sets */
#define DIO_CONFIG_COUNT                     ([!"num:i($ConfigCount)"!]U)

[!IF "$ConfigCount > num:i(1)"!][!//
[!CALL "CG_Generate_Const_PortValues"!][!//
/* Number of Unique DioPort Symbolic names */
#define DIO_PORT_SET_U                      ([!"num:i(num:div(string-length($Superstring),num:mul(num:i(2),num:i(num:i($ConfigCount)))))"!]U)
[!CALL "CG_Generate_Const_ChnlValues"!][!//
/* Number of Unique DioChannel Symbolic names */
#define DIO_PORTPIN_SET_U                   ([!"num:i(num:div(string-length($Superstringchnl),num:mul(num:i(4),num:i(num:i($ConfigCount)))))"!]U)
[!CALL "CG_Generate_Const_ChnlGrp2Values"!][!//
/* Number of Unique DioChannelGroup Symbolic names */
#define DIO_CH_GRP_SET_U                    ([!"num:i(num:div(num:i(count(text:split($Superstringchnlgrp,':'))),num:i($ConfigCount)))"!]U)
[!ELSE!][!//
#define DIO_CH_GRP_SET_U                    (0U)
[!ENDIF!]
/* To specify if Loadable or Selectable configuration is used */
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!VAR "LoadableUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!IF "$PostBuildType = 'LOADABLE'"!][!//

[!ASSERT "not(DioGeneral/DioPBFixedAddress = 'true')"!][!//
For EcuMPostBuildConfigType=Loadable, DioPBFixedAddress should be False[!//
[!ENDASSERT!][!//

[!VAR "LoadableUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
#define DIO_LOADABLE_USED      ([!"$LoadableUsed"!])

/* The following macros are available only if development error detection
   or safety is on is enabled */
[!IF "DioSafety/DioSafetyEnable = 'true' or DioGeneral/DioDevErrorDetect = 'true'"!][!//

/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
[!CALL "CG_GetPortsAvailable00to31"!][!//

/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 */
[!CALL "CG_GetPortsAvailable32to40"!][!//

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
[!CALL "CG_GetReadOnlyPorts00to31"!][!//

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 8 is for Port 40 */
[!CALL "CG_GetReadOnlyPorts32to40"!][!//

/* Macro to define the maximum port available */
[!CALL "CG_GetMaxAvailablePort"!][!//

/* Value of the most significant pin on the port
   Note: In case of no pins on a port, the value is kept 0 */
[!CALL "CG_GetPortMSPin"!][!//
[!ENDIF!][!// DioSafety or DioDecerrorDetect

[!/* Macro to define the values to mask for the port pins */!][!//
[!CALL "CG_GetMaskForPortPins"!][!//

[!/* Macro to define the No of channel groups configured */!][!//
[!CALL "CG_GetDioChannelGroupCount"!][!//
/*******************************************************************************
**                           Global Symbols                                   **
*******************************************************************************/

/*
 Symbolic names for DIO Channels, Port & Channel groups
*/
[!IF "$ConfigCount = num:i(1)"!][!//
/*
                       Symbolic names for Channels
*/
[!FOR "PortNumber" = "num:i(0)" TO "ecu:get('Dio.MaxAvailablePort')"!][!//
[!//
[!IF "contains(ecu:get('Dio.AvailablePorts'),concat('_',$PortNumber,'_'))"!][!//
[!CALL "CG_GetDioChannelSymbolicNames","PortNum" = "$PortNumber"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!]

/*
                      Symbolic names for DIO ports
*/
[!CALL "CG_GetDioPortSymbolicNames"!][!//

[!FOR "CfgPosition" ="num:i(1)" TO "num:i(($ConfigCount))"!][!//
[!//

/* Number of Channel groups configured for the DioConfig[!"num:i(string($CfgPosition))"!] */
[!CALL "CG_GetNumOfDioChannelGroupsConfigured", "Instance" = "num:i(string($CfgPosition))", "Print" = "num:i(1)"!][!//
/*
      User Defined Symbolic Names for the DIO Ports, Channels & Channel Groups
      DioConfig [!"num:i(string($CfgPosition))"!]
*/
[!CALL "CG_GetUserDefinedSymbolicNames", "Instance" = "num:i(string($CfgPosition))"!][!//

[!ENDFOR!][!//
[!ELSE!][!//

/* Port Symbolic name mapping */

[!CALL "CG_PortIdMapSymbolicName"!][!//

/* Channel Symbolic name mapping */

[!CALL "CG_ChnlIdMapSymbolicName"!][!//

/* Channel Group Symbolic name mapping */

[!CALL "CG_Generate_Const_ChnlGrp1Values"!][!//
[!ENDIF!][!//

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Type                                      **
*******************************************************************************/
[!ENDSELECT!]
/* End of DIO_CFG_H */
#endif
