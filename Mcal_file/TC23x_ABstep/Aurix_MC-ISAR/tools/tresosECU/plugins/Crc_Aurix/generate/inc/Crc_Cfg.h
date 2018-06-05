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
**  $FILENAME   : Crc_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\13 $                               **
**                                                                           **
**  $DATE       : 2016-03-20 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Crc_Cfg.h file                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID= AUTOSAR:12948,
     AUTOSAR:16190,ASW:1500,ASW:1501,ASW:1504,
     ASW:1507,ASW:1508,ASW:1509,ASW:1512,ASW:1516,ASW:1517,
     ASW:1524,ASW:1528,ASW:1246,SAS_NAS_CRC_PR914,SAS_NAS_CRC_PR915,
     SAS_AS4XX_CRC_PR678,DS_NAS_EP_CRC_PR3054_1,DS_NAS_EP_CRC_PR3054_2 ]
    [/cover]                                                            */!][!//
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
**  FILENAME  : Crc_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\13 $                               **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CRC configuration generated out of ECU configuration       **
**                 file (Crc.bmd)                                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
  

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
 #define CRC_RUNTIME_MODE 0x00
 #define CRC_TABLE_MODE 0x01
 #define CRC_INSTRUCTION_MODE 0x02

/*Macro for Initial Values of CRC*/
  #define CRC_INITIAL_VALUE8 0xFFU
  #define CRC_INITIAL_VALUE8H2F 0xFFU
  #define CRC_INITIAL_VALUE16 0xFFFFU
  #define CRC_INITIAL_VALUE32 0xFFFFFFFFU

[!AUTOSPACING!]
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Crc')[1]"!][!//
[!//

/*
         Container : CRCGeneral
*/

[!NOCODE!][!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!][!//
[!ENDNOCODE!][!//

/*Autosar specific information*/
 #define CRC_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
 #define CRC_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
 #define CRC_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)

[!VAR "MajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleSoftwareVer,"\.",'')"!][!//
/*Release specific information*/
 #define CRC_SW_MAJOR_VERSION  ([!"$MajorVersion"!]U)
 #define CRC_SW_MINOR_VERSION  ([!"$MinorVersion"!]U)
 #define CRC_SW_PATCH_VERSION  ([!"$RevisionVersion"!]U)
/*Macro for versioninfoapi*/
 #define CRC_VERSION_INFO_API  ([!//
[!IF "CrcGeneral/CrcVersionInfoApi  = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
 

[!IF "CrcGeneral/Crc16Mode/__1 = 'CRC_16_RUNTIME'"!][!//
 #define CRC_16_MODE (CRC_RUNTIME_MODE) [!//
[!ELSEIF "CrcGeneral/Crc16Mode/__1 = 'CRC_16_TABLE'"!][!//
 #define CRC_16_MODE (CRC_TABLE_MODE) [!//	
[!ENDIF!][!//
/*Macro for selection of 32 bit CRC method */

[!IF "CrcGeneral/Crc32Mode/__1 = 'CRC_32_INSTRUCTION'"!][!//
 #define CRC_32_MODE   (CRC_INSTRUCTION_MODE) [!//
[!ELSEIF "CrcGeneral/Crc32Mode/__1 = 'CRC_32_RUNTIME'"!][!//
 #define CRC_32_MODE (CRC_RUNTIME_MODE) [!//
[!ELSEIF "CrcGeneral/Crc32Mode/__1 = 'CRC_32_TABLE'"!][!//
 #define CRC_32_MODE (CRC_TABLE_MODE) [!//	
[!ENDIF!][!//

/*Macro for selection of 8 bit CRC method with 0x1D polynomial*/


[!IF "CrcGeneral/Crc8Mode/__1 = 'CRC_8_RUNTIME'"!][!//
 #define CRC_8_MODE (CRC_RUNTIME_MODE)[!//
[!ELSEIF "CrcGeneral/Crc8Mode/__1 = 'CRC_8_TABLE'"!][!//
 #define CRC_8_MODE (CRC_TABLE_MODE)[!//	
[!ENDIF!][!//  

/*Macro for selection of 8 bit CRC method with 0x2F polynomial*/

[!IF "CrcGeneral/Crc8H2FMode/__1 = 'CRC_8H2F_RUNTIME'"!][!//
 #define CRC_8H2F_MODE (CRC_RUNTIME_MODE)[!//
[!ELSEIF "CrcGeneral/Crc8H2FMode/__1 = 'CRC_8H2F_TABLE'"!][!//
 #define CRC_8H2F_MODE (CRC_TABLE_MODE)[!//	
[!ENDIF!][!//

/*
Configuration: CRC_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "node:exists(./CrcGeneral/CrcRunningInUser0Mode)"!][!//
  [!IF "CrcGeneral/CrcRunningInUser0Mode = 'true'"!][!//
  [!ASSERT "not(./CrcGeneral/CrcUserModeRuntimeApiEnable != 'true')"!][!//
Config Error: when CrcGeneral/CrcRunningInUser0Mode is set as true, [!//
Then CrcUserModeRuntimeApiEnable should be selected.[!//
But in configuration it is not selected.[!//
  [!ENDASSERT!][!//
#define CRC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_ON)
  [!ELSE!][!//
#define CRC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define CRC_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: CRC_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
[!IF "node:exists(./CrcGeneral/CrcUserModeRuntimeApiEnable)"!][!//
  [!IF "CrcGeneral/CrcUserModeRuntimeApiEnable = 'true'"!][!//    
#define CRC_USER_MODE_RUNTIME_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define CRC_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define CRC_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
    Configuration : CRC_SAFETY_ENABLE
    Pre-processor switch to enable/disable the CRC driver safety features.
*/
[!IF "CrcSafety/CrcSafetyEnable = 'true'"!][!//
#define CRC_SAFETY_ENABLE (STD_ON)
[!ELSE!][!//
#define CRC_SAFETY_ENABLE (STD_OFF)
[!ENDIF!][!//

[!IF "CrcSafety/CrcSafetyEnable = 'true'"!][!//
[!VAR "CrcMarkerValue" = "num:i(CrcSafety/CrcMarkerValue)"!][!//
#define CRC_DATAPTR_MARKER_VALUE   ([!"num:inttohex($CrcMarkerValue)"!]U)
[!ENDIF!][!//

[!ENDSELECT!][!//
