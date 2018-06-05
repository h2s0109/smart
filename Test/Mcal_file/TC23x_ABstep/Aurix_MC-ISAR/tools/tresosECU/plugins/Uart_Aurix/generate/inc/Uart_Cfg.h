[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Uart_Cfg.h $                                               **
**                                                                           **
**  $CC VERSION : \main\20 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-04 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Uart_Cfg.h file                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!/******************************************************************************
**  TRACEABILITY : [cover parentID = 
**  SAS_NAS_UART_PR914,SAS_NAS_UART_PR915,DS_NAS_HE2_UART_PR3054_1,
DS_NAS_EP_UART_PR3054_1,DS_NAS_HE2_UART_PR3054_2,DS_NAS_EP_UART_PR3054_2, 
DS_NAS_HE2_UART_PR3054_3,DS_NAS_EP_UART_PR3054_3,DS_NAS_HE2_UART_PR3054_4,
DS_NAS_EP_UART_PR3054_4] **
**                [/cover]                                                   **
******************************************************************************/!][!//
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
**  $FILENAME   : Uart_Cfg.h $                                               **
**                                                                            **
**  $CC VERSION : \main\20 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Uart configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
#ifndef UART_CFG_H 
#define UART_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Uart')[1]"!][!//
[!//
[!//
/*SW Version Information*/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
#define UART_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define UART_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define UART_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)
[!//

/*
         Container : UartGeneral Configuration
*/

/*
Derived Configuration for UartDevErrorDetect 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled
The detection of all development errors is configurable (On / Off) 
at precompile time. The switch UART_DEV_ERROR_DETECT  shall
activate or deactivate the detection of all development errors.

If the switch UART_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled. 
*/
#define UART_DEV_ERROR_DETECT  ([!//
[!IF "UartGeneral/UartDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Derived Configuration for UartVersionInfoApi 
- if STD_ON, Function Uart_GetVersionInfo is available  
- if STD_OFF,Function Uart_GetVersionInfo is not available 
*/
#define UART_VERSION_INFO_API  ([!//
[!IF "UartGeneral/UartVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Derived Configuration for UartPBFixedAddress 
- if STD_ON, Fixed Address feature is Enabled 
- if STD_OFF,Fixed Address feature is Disabled
*/
#define UART_PB_FIXEDADDR  ([!//
[!IF "UartGeneral/UartPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Derived Configuration for UartDeinitApi 
- if STD_ON, Function UartDeinitApi is available  
- if STD_OFF,Function UartDeinitApi is not available 
*/
#define UART_DEINIT_API  ([!//
[!IF "UartGeneral/UartDeInitApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
/*
Derived Configuration for UartAbortReadApi 
- if STD_ON, Function UartAbortReadApi is available  
- if STD_OFF,Function UartAbortReadApi is not available 
*/
#define UART_ABORT_READ_API  ([!//
[!IF "UartGeneral/UartAbortReadApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
/*
Derived Configuration for UartAbortWriteApi
- if STD_ON, Function UartAbortWriteApi is available  
- if STD_OFF,Function UartAbortWriteApi is not available 
*/
#define UART_ABORT_WRITE_API  ([!//
[!IF "UartGeneral/UartAbortWriteApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for UartDebugSupport*/
#define UART_DEBUG_SUPPORT  ([!//
[!IF "UartGeneral/UartDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for UartResetSfrAtInit*/
#define UART_RESET_SFR_INIT  ([!//
[!IF "UartGeneral/UartResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

[!IF "(UartGeneral/UartRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "UartGeneral/UartUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "UartGeneral/UartUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "UartGeneral/UartUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: UartRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
UartUserModeRuntimeApiEnable, UartUserModeInitApiEnable or UartUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: UART_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "UartGeneral/UartRunningInUser0Mode = 'true'"!][!//
#define UART_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define UART_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: UART_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "UartGeneral/UartUserModeInitApiEnable = 'true'"!][!//
#define UART_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  UART_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: UART_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "UartGeneral/UartUserModeDeInitApiEnable = 'true'"!][!//
#define UART_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  UART_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: UART_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "UartGeneral/UartUserModeRuntimeApiEnable = 'true'"!][!//
#define UART_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  UART_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/* Derived Configuration for UartIndex*/
#define UART_INDEX  ([!"UartGeneral/UartIndex"!]U)

/* Total no. of config sets */
#define UART_CONFIG_COUNT    ([!"num:i(count(UartConfigSet/*))"!]U)

/* Total Number of ASCLIN HW Units Available*/
[!VAR "MaxAscLinMod"= "ecu:get('AscLin.MaxNoOfAscLinModules')"!][!//
#define UART_MAX_HW_UNIT ([!"$MaxAscLinMod"!]U)

#define UART_ASCLIN0 (0U)
#define UART_ASCLIN1 (1U)
[!IF "$MaxAscLinMod > 2"!][!//
#define UART_ASCLIN2 (2U)
[!ENDIF!][!//
[!IF "$MaxAscLinMod > 3"!][!//
#define UART_ASCLIN3 (3U)
[!ENDIF!][!//
[!IF "$MaxAscLinMod > 4"!][!//
#define UART_ASCLIN4 (4U)
[!ENDIF!][!//

/* 
Derived Configuration for UartDataLength  
Flag Indicating if 9 bit Datalength is used in Any Configuration Set
*/
[!VAR "TotalConfig" = "num:i(count(UartConfigSet/*))"!][!//
[!VAR "NineBitFlag"= "num:i(0)"!][!//
[!LOOP "UartConfigSet/*"!][!//
[!LOOP "UartChannel/*"!][!//
[!VAR "tmp" = "num:i(./UartDataLength)"!][!//
[!IF "$tmp > 8"!][!//
[!VAR "NineBitFlag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
#define UART_NINEBITS_USED ([!//
[!IF "$NineBitFlag > 0"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* 
Configuration : UART_MAXIMUM_CHANNEL 
Maximum of No. of Uart channels configured in different PB Config Sets
*/
[!VAR "TotalConfig" = "num:i(count(UartConfigSet/*))"!][!//
[!VAR "MaxChannels"= "num:i(0)"!][!//
[!LOOP "UartConfigSet/*"!][!//
[!VAR "Count"= "num:i(count(UartChannel/*))"!][!//
[!IF "$Count > $MaxChannels"!][!//
[!VAR "MaxChannels" = "$Count"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
#define UART_MAXIMUM_CHANNEL ([!"$MaxChannels"!]U)

[!NOCODE!][!//
[!VAR "TotalConfig" = "num:i(count(UartConfigSet/*))"!][!//
[!VAR "Asc0Used" = "num:i(0)"!][!//
[!VAR "Asc1Used" = "num:i(0)"!][!//
[!VAR "Asc2Used" = "num:i(0)"!][!//
[!VAR "Asc3Used" = "num:i(0)"!][!//
[!VAR "Asc4Used" = "num:i(0)"!][!//

[!LOOP "UartConfigSet/*"!][!//

[!VAR "tmp" = "num:i(count(UartChannel/*[UartHwUnit='ASCLIN0']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN0 module shouldn't be configured for more than 1 Uart Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc0Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(UartChannel/*[UartHwUnit='ASCLIN1']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN1 module shouldn't be configured for more than 1 Uart Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc1Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(UartChannel/*[UartHwUnit='ASCLIN2']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN2 module shouldn't be configured for more than 1 Uart Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc2Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(UartChannel/*[UartHwUnit='ASCLIN3']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN3 module shouldn't be configured for more than 1 Uart Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc3Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(UartChannel/*[UartHwUnit='ASCLIN4']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN4 module shouldn't be configured for more than 1 Uart Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc4Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "McuAscLinRef" = "node:path(node:ref(./UartSysClockRef)/../../../AscLinConfiguration)"!][!//

[!ENDLOOP!][!//

[!IF "$Asc0Used = num:i(1)"!][!//
[!VAR "McuAscLin0Ref" = "node:ref(concat($McuAscLinRef,'/AscLin0'))"!]
[!IF "$McuAscLin0Ref != 'USE_FOR_UART_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN0 Channel for UART in Mcu Configuration. container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$Asc1Used = num:i(1)"!][!//
[!VAR "McuAscLin1Ref" = "node:ref(concat($McuAscLinRef,'/AscLin1'))"!]
[!IF "$McuAscLin1Ref != 'USE_FOR_UART_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN1 Channel for UART in Mcu Configuration. container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$Asc2Used = num:i(1)"!][!//
[!VAR "McuAscLin2Ref" = "node:ref(concat($McuAscLinRef,'/AscLin2'))"!]
[!IF "$McuAscLin2Ref != 'USE_FOR_UART_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN2 Channel for UART in Mcu Configuration . container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$Asc3Used = num:i(1)"!][!//
[!VAR "McuAscLin3Ref" = "node:ref(concat($McuAscLinRef,'/AscLin3'))"!]
[!IF "$McuAscLin3Ref != 'USE_FOR_UART_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN3 Channel for UART in Mcu Configuration . container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*
Configuration: UART_ASCLINx_USED 
- if STD_ON, ASCLINx is used   
- if STD_OFF,ASCLINx is not used  
*/

#define UART_ASCLIN0_USED  ([!IF "$Asc0Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//

#define UART_ASCLIN1_USED  ([!IF "$Asc1Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//

[!IF "$MaxAscLinMod > 2"!][!//
#define UART_ASCLIN2_USED  ([!IF "$Asc2Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//
[!ENDIF!][!//

[!IF "$MaxAscLinMod > 3"!][!//
#define UART_ASCLIN3_USED  ([!IF "$Asc3Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//
[!ENDIF!][!//

[!IF "$MaxAscLinMod > 4"!][!//
#define UART_ASCLIN4_USED  ([!IF "$Asc4Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//
[!ENDIF!][!//

/* Derived Configuration for UartSleepEnable*/
[!IF "UartGeneral/UartSleepEnable = 'true'"!][!//
#define UART_ASCLIN_CLC (0U)
[!ELSE!][!//
#define UART_ASCLIN_CLC (0x08U)
[!ENDIF!][!//

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* UART_CFG_H */

[!ENDSELECT!][!//
