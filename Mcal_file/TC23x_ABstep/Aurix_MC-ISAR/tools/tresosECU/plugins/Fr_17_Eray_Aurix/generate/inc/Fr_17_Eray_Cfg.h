[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Fr_17_Eray_Cfg.h $                                         **
**                                                                            **
**  $CC VERSION : \main\32 $                                                 **
**                                                                            **
**  $DATE       : 2016-07-08 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for Fr_17_Eray_Cfg.h file                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
**************************************************************************/!][!//

[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Fr_17_Eray_Cfg.h $                                         **
**                                                                            **
**  $CC VERSION : \main\32 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : FR configuration generated out of ECU configuration file   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/


/** Traceability : [cover parentID=DS_AS40X_FR667,DS_NAS_FR_PR913,
                   DS_AS403_PR2849,DS_NAS_FR_PR446,DS_AS403_FR_PR2849,
                   SAS_NAS_FR_PR914,SAS_NAS_FR_PR915,SAS_AS4XX_FR_PR678,
                   SAS_NAS_FR_PR916,DS_NAS_EP_FR_PR3054_1,
                   DS_NAS_EP_FR_PR3054_2,DS_NAS_EP_FR_PR3054_4,
                   DS_NAS_HE2_FR_PR3054_1,DS_NAS_HE2_FR_PR3054_2,
                   DS_NAS_HE2_FR_PR3054_4]
** [/cover]                                                                  **/

/******************************************************************************/
#ifndef  FR_17_ERAY_CFG_H
#define  FR_17_ERAY_CFG_H

[!NOCODE!]
[!INCLUDE "Fr_17_Eray.m"!]
[!ENDNOCODE!]

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                     Configuration options                                **
*******************************************************************************/

/*
Flex ray Controller Input Selection values are used to select alternate
receive input lines
*/
#define FR_RXSEL0  (0x00)
#define FR_RXSEL1  (0x01)
#define FR_RXSEL2  (0x02)
#define FR_RXSEL3  (0x03)

#define FR_LPDU_RECONFIGURABLE     (STD_ON)
#define FR_LPDU_NOT_RECONFIGURABLE (STD_OFF)

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!VAR "ModuleName" = "'Fr'"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//.
[!//

/* Fr Instance ID */
#define FR_17_ERAY_INSTANCE_ID                ((uint8)[!"num:i(FrGeneral/FrIndex)"!])

[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "PatchVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
/* Autosar specification version */
#define FR_17_ERAY_AR_RELEASE_MAJOR_VERSION           ([!"$MajorVersion"!]U)
#define FR_17_ERAY_AR_RELEASE_MINOR_VERSION           ([!"$MinorVersion"!]U)
#define FR_17_ERAY_AR_RELEASE_REVISION_VERSION        ([!"$PatchVersion"!]U)
[!//
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//

/* Vendor specific implementation version information */
#define FR_17_ERAY_SW_MAJOR_VERSION           ([!"$SwMajorVersion"!]U)
#define FR_17_ERAY_SW_MINOR_VERSION           ([!"$SwMinorVersion"!]U)
#define FR_17_ERAY_SW_PATCH_VERSION           ([!"$SwPatchVersion"!]U)

/*
Container : FrDriverConfiguration - FR392:
General configuration (parameters) of the FlexRay Driver module.
*/

/*
Configuration: FR_17_ERAY_RECONFIG_BUFFER
Adds/removes the service Fr_17_Eray_PrepapreLPdu() from the code
- if STD_ON, Fr_17_Eray_PrepapreLPdu() can be used
- if STD_OFF, Fr_17_Eray_PrepapreLPdu() can not be used
*/
#define FR_17_ERAY_RECONFIG_BUFFER                   [!CALL "CG_ConfigSwitch", "nodeval" = "FrGeneral/FrBufferReconfig"!][!//

/*
Configuration: FR_17_ERAY_CTRL_TEST_COUNT
Specifies the maximum number of iterations the FlexRay controller hardware test
is performed during controller initialization.
*/
#define FR_17_ERAY_CTRL_TEST_COUNT                   ([!"FrGeneral/FrCtrlTestCount"!]U)

/*
Configuration: FR_17_ERAY_DEV_ERROR_DETECT
Preprocessor switch to enable/disable the development error detection and
reporting.
- if STD_ON, Enable development error detection
- if STD_OFF, Disable development error detection
*/
#define FR_17_ERAY_DEV_ERROR_DETECT                  [!CALL "CG_ConfigSwitch", "nodeval" = "FrGeneral/FrDevErrorDetect"!][!//

/*Configuration: FR_17_ERAY_INDEX
Specifies the InstanceId of this module instance.*/
#define FR_17_ERAY_INDEX             ([!"FrGeneral/FrIndex"!]U)

/*
Configuration: FR_17_ERAY_NUM_CTRL_SUPPORTED
Determines the maximum number of communication controllers that the driver
supports.
*/
#define FR_17_ERAY_NUM_CTRL_SUPPORTED               ([!"FrGeneral/FrNumCtrlSupported"!]U)

/*
Configuration: FR_17_ERAY_RX_STRINGENT_CHECK
If stringent check is enabled (true), received frames are only accepted if no
slot status error occured.
*/
#define FR_17_ERAY_RX_STRINGENT_CHECK                [!CALL "CG_ConfigSwitch", "nodeval" = "FrGeneral/FrRxStringentCheck"!]

/*
Configuration: FR_17_ERAY_RX_STRINGENT_LENGTH_CHECK
If stringent check is enabled (true), received frames are only accepted the
received payload length matches the configured payload length.
*/
#define FR_17_ERAY_RX_STRINGENT_LENGTH_CHECK         [!CALL "CG_ConfigSwitch", "nodeval" = "FrGeneral/FrRxStringentLengthCheck"!]

/*
Configuration: FR_17_ERAY_VERSION_INFO_API
Adds/removes the service Fr_17_Eray_GetVersionInfo() from the code
- if STD_ON, Fr_17_Eray_GetVersionInfo() can be used
- if STD_OFF, Fr_17_Eray_GetVersionInfo() can not be used
*/
#define FR_17_ERAY_VERSION_INFO_API                  [!CALL "CG_ConfigSwitch", "nodeval" = "FrGeneral/FrVersionInfoApi"!][!//

/*
Configuration: FR_17_ERAY_NMVECTOR_ENABLE
Adds/removes the service Fr_17_Eray_GetNmVector() from the code
- if STD_ON, Fr_17_Eray_GetNmVector() can be used
- if STD_OFF, Fr_17_Eray_GetNmVector() can not be used
*/
#define FR_17_ERAY_NMVECTOR_ENABLE                   [!CALL "CG_ConfigSwitch", "nodeval" = "FrGeneral/FrNmVectorEnable"!][!//

/*
Configuration: FR_17_ERAY_TIMEOUT_DURATION
Specifies the maximum number of loops for blocking function until a timeout
is raised in short term wait loops.
*/
#define FR_17_ERAY_TIMEOUT_DURATION                  ([!"FrGeneral/FrTimeoutDurationFactor"!]U)



/* Debug mode is used for code coverage */
#define FR_17_ERAY_DEBUG_MODE    (OFF)

[!IF "(FrGeneral/FrRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "FrGeneral/FrUserModeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "FrGeneral/FrUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: FrRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
FrUserModeRuntimeApiEnable or FrUserModeInitApiEnable
[!ENDASSERT!][!//
[!ENDIF!][!//
/*
Configuration: FR_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, enable User0 mode
- if STD_OFF, enable User1 mode
*/
#define FR_RUNNING_IN_USER_0_MODE_ENABLE   [!//
[!CALL "CG_ConfigSwitch","nodeval" = "FrGeneral/FrRunningInUser0Mode"!][!//

/*
Configuration: FR_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API
- if STD_OFF, Enable Supervisor mode in Init API
*/
#define FR_USER_MODE_INIT_API_ENABLE         [!//
[!CALL "CG_ConfigSwitch","nodeval" = "FrGeneral/FrUserModeInitApiEnable"!][!//

/*
Configuration: FR_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
#define FR_USER_MODE_RUNTIME_API_ENABLE           [!//
[!CALL "CG_ConfigSwitch","nodeval" = "FrGeneral/FrUserModeRuntimeApiEnable"!][!//

[!NOCODE!][!//
[!//
[!VAR "TotalFrConfig" = "num:i(count(FrMultipleConfiguration/*))"!][!//
[!/* Determine only one FrMultipleConfiguration is configured
                                        when FrPBFixedAddress = true.*/!]
[!IF "FrGeneral/FrPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalFrConfig != 1)"!][!//
Config Error: when FrGeneral/FrPBFixedAddress is set as true, [!//
Only one FrMultipleConfiguration configuration is allowed. [!//
But FrMultipleConfiguration has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
/*
Configuration: FR_17_ERAY_PB_FIXEDADDR
- if ON, Fixed Address feature is Enabled
- if OFF,Fixed Address feature is Disabled
*/
[!VAR "FixedAddress" = "'STD_OFF'"!][!//
[!IF "node:exists(FrGeneral/FrPBFixedAddress)"!][!//
[!IF "FrGeneral/FrPBFixedAddress = 'true'"!][!//
[!VAR "FixedAddress" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
#define FR_17_ERAY_PB_FIXEDADDR                   ([!"$FixedAddress"!])

#define FR_RESET_SFR_AT_INIT              [!//
[!CALL "CG_ConfigSwitch","nodeval" = "FrGeneral/FrResetSfrAtInit"!]
/* Configuration: FR_RESET_SFR_AT_INIT
 - STD_ON  - FR Kernel Registers’ reset feature is enabled
 - STD_OFF - FR Kernel Registers’ reset feature is not enabled
*/

/* Module Debug Support */
[!IF "FrGeneral/FrDebugSupport = 'true'"!][!//
#define FR_17_ERAY_DEBUG_SUPPORT   (STD_ON)
[!ELSE!][!//
#define FR_17_ERAY_DEBUG_SUPPORT  (STD_OFF)
[!ENDIF!][!//

/* Dem reporting disabled macro */
#define DEM_REPORT_DISABLED (0U)
/*****************************************************************************/
/* Symbolic name defintions */
/*****************************************************************************/
/*
    Symbolic name defintions for FR controllers and timers.
    The symbolic names identify the controller/timers (within an ECU).
*/
[!SELECT "as:modconf($ModuleName)[1]"!][!/* SELECT1 */!][!//
[!LOOP "FrMultipleConfiguration/*"!][!/* LOOP4 */!][!//
[!VAR "OldControllerIdx" = "num:i(ecu:get('Eray.MaxControllers'))"!][!//
[!LOOP "FrController/*"!][!/* LOOP6 */!][!//
[!VAR "CurrControllerIdx" = "FrCtrlIdx"!][!//
[!ASSERT "$CurrControllerIdx != $OldControllerIdx"!][!//
Config Error: The Controller Index [!"$CurrControllerIdx"!] has already been allocated, [!//
configure a new controller for [!"node:path(.)"!][!//
[!ENDASSERT!][!//
#ifdef  Fr_17_ErayConf_FrController_[!"@name"!] /* to prevent double declaration */
#error  Fr_17_ErayConf_FrController_[!"@name"!] already defined
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
to follow Autosar naming conventions*/
#define Fr_17_ErayConf_FrController_[!"@name"!]       ([!"FrCtrlIdx"!]U)
[!VAR "OldControllerIdx" = "$CurrControllerIdx"!][!//
[!ENDLOOP!][!/* LOOP6 */!]
[!SELECT "FrController/*[1]/FrAbsoluteTimer/*"!][!/* SELECT3 */!][!//
#ifdef  Fr_17_ErayConf_FrAbsoluteTimer_[!"@name"!] /* to prevent double declaration */
#error  Fr_17_ErayConf_FrAbsoluteTimer_[!"@name"!] already defined
#endif
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceed 31 characters
to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceed 31 characters
to follow Autosar naming conventions*/
#define Fr_17_ErayConf_FrAbsoluteTimer_[!"@name"!]       ([!"FrAbsTimerIdx"!]U)
[!ENDSELECT!][!/* SELECT3 */!]
[!ENDLOOP!][!/* LOOP4 */!][!//
[!ENDSELECT!][!/* SELECT1 */!][!//
[!ENDSELECT!][!//SELECT "as:modconf($ModuleName)[1]"!][!//
/*****************************************************************************/

/*******************************************************************************
**                      Derived Configuration Parameters                      **
*******************************************************************************/
[!VAR "Controller0Available" = "num:i(0)"!][!//
[!VAR "Controller1Available" = "num:i(0)"!][!//
[!VAR "FR_MSG_BUFF_COUNT_MAX_0" = "num:i(0)"!][!//
[!VAR "FR_MSG_BUFF_COUNT_MAX_1" = "num:i(0)"!][!//
[!VAR "FrIfAllowDynamicLSduLengthFlag" = "num:i(0)"!][!//
[!VAR "FrFifoConfiguredFlag" = "num:i(0)"!][!//
[!SELECT "as:modconf($ModuleName)[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(FrMultipleConfiguration/*))"!][!//
[!FOR "Instance" = "0" TO "$ConfigCount - 1"!][!/* FOR1 */!][!//
[!SELECT "FrMultipleConfiguration/*[@index = $Instance]"!][!//
[!VAR "Counter" = "num:i(count(./FrController/*))"!][!//
[!FOR "Index" = "0" TO "(num:i($Counter)- 1)"!][!//
[!SELECT "./FrController/*[@index = $Index]"!][!//
[!VAR "ControllerIndex" = "./FrCtrlIdx"!][!//
[!VAR "ControllerPath" = "node:path(.)"!][!//
[!/* Example: ControllerPath = /AUTOSAR/TOP-LEVEL-PACKAGES/Fr/ELEMENTS/Fr/FrMultipleConfiguration/Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-after($ControllerPath, 'FrMultipleConfiguration')"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController/FrController_0 */!][!//
[!VAR "ControllerPath1" = "substring-after($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath1 = /FrController_0 */!][!//
[!VAR "ControllerPath2" = "substring-before($ControllerPath2, '/FrController')"!][!//
[!/* Example: ControllerPath2 = /Default_0 */!][!//
[!VAR "ControllerPath2" = "concat($ControllerPath2, $ControllerPath1)"!][!//
[!/* Example: ControllerPath2 = /Default_0/FrController_0 */!][!//
[!/* Check if FIFO is configured */!][!//
[!IF "(node:exists(concat($ControllerPath, '/FrFifo/*[1]')))"!][!/* FIFO_NODE_CHECK */!][!//
[!VAR "FrFifoConfiguredFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!LOOP "as:modconf('FrIf')[1]/FrIfConfig/*"!][!/* LOOP1 */!][!//
[!VAR "CtrlRefFound" = "num:i(0)"!][!//
[!LOOP "FrIfCluster/*"!][!/* LOOP2 */!][!//
[!LOOP "FrIfController/*"!][!/* LOOP3 */!][!//
[!VAR "FrIfControllerPath" = "node:ref(node:path(./FrIfFrCtrlRef))"!][!//
[!VAR "FrIfControllerPath" = "substring-after($FrIfControllerPath, '/Fr/Fr')"!][!//
[!IF "$FrIfControllerPath = $ControllerPath2"!][!/* IF1 */!][!//
[!VAR "CtrlRefFound" = "num:i(1)"!][!//
[!/* Added for FR224 */!][!//
[!LOOP "FrIfFrameTriggering/*"!][!/* LOOP4 */!][!//
[!IF "./FrIfAllowDynamicLSduLength = 'true'"!][!//
[!VAR "FrIfAllowDynamicLSduLengthFlag" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* LOOP4 */!][!//
[!//
[!ASSERT "$CtrlRefFound = num:i(1)"!][!//
Error: FlexRay controllers [!"$ControllerPath2"!] in Fr module is not referred by any of the FrIf clusters.
[!ENDASSERT!][!//
[!IF "$CtrlRefFound = 1"!][!//
[!IF "$ControllerIndex = num:i(0)"!][!//
[!VAR "Controller0Available" = "num:i(1)"!][!//
[!IF "$FR_MSG_BUFF_COUNT_MAX_0 < num:i(count(FrIfFrameTriggering/*))"!][!//
[!VAR "FR_MSG_BUFF_COUNT_MAX_0" = "num:i(count(FrIfFrameTriggering/*))"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$ControllerIndex = num:i(1)"!][!//
[!VAR "Controller1Available" = "num:i(1)"!][!//
[!IF "$FR_MSG_BUFF_COUNT_MAX_1 < num:i(count(FrIfFrameTriggering/*))"!][!//
[!VAR "FR_MSG_BUFF_COUNT_MAX_1" = "num:i(count(FrIfFrameTriggering/*))"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!/* LOOP3 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDLOOP!][!/* LOOP2 */!][!//
[!IF "$CtrlRefFound = 1"!][!BREAK!][!ENDIF!][!//
[!ENDLOOP!][!/* LOOP1 */!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//

/* Number of Config sets */
#define FR_CONFIG_COUNT  ([!"num:i($ConfigCount)"!]U)

/*
   Flag for FrIfAllowDynamicLSduLength usage.
   STD_ON: Header CRC is calculated in Fr_17_Eray_TransmitTxLPdu API.
   STD_OFF: Header CRC is calculated in code generation level with
   configured FrIfLSduLength.
*/
[!IF "$FrIfAllowDynamicLSduLengthFlag = num:i(1)"!][!//
#define FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH          (STD_ON)
[!ELSE!][!//
#define FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH          (STD_OFF)
[!ENDIF!][!//

[!/* ------------------------------------------*/!][!//
/* Flag for FIFO configuration */
[!IF "$FrFifoConfiguredFlag = num:i(1)"!][!//
#define FR_17_ERAY_FIFO_CONFIGURED          (STD_ON)
[!ELSE!][!//
#define FR_17_ERAY_FIFO_CONFIGURED          (STD_OFF)
[!ENDIF!][!//

[!/* ------------------------------------------*/!][!//
/*
   Estimated maximum number of message buffers used per controller.
  Min (128, max(LPDU count in all PB configurations))
*/
#define FR_17_ERAY_MSG_BUFF_COUNT_MAX_0 ([!"$FR_MSG_BUFF_COUNT_MAX_0"!]U)
#define FR_17_ERAY_MSG_BUFF_COUNT_MAX_1 ([!"$FR_MSG_BUFF_COUNT_MAX_1"!]U)

/* Number of ERAY Controllers available in the device */
#define FR_NUM_CONTROLLERS_IN_DEVICE  ([!"ecu:get('Eray.MaxControllers')"!]U)
[!IF "$Controller0Available = num:i(1)"!][!//
#define FR_17_ERAY_CONTROLLER0_CONFIGURED   (STD_ON)
[!ELSE!][!//
#define FR_17_ERAY_CONTROLLER0_CONFIGURED   (STD_OFF)
[!ENDIF!][!//
[!IF "$Controller1Available = num:i(1)"!][!//
#define FR_17_ERAY_CONTROLLER1_CONFIGURED   (STD_ON)
[!ELSE!][!//
#define FR_17_ERAY_CONTROLLER1_CONFIGURED   (STD_OFF)
[!ENDIF!][!//

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


#endif /* FR_17_ERAY_CFG_H */
