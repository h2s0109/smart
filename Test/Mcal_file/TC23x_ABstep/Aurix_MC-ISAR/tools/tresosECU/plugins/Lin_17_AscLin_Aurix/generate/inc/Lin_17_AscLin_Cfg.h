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
**  $FILENAME   : Lin_17_AscLin_Cfg.h $                                      **
**                                                                           **
**  $CC VERSION : \main\43 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-06 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Lin_17_AscLin_Cfg.h file                 **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
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
**  FILENAME  : Lin_17_AscLin_Cfg.h                                           **
**                                                                            **
**  $CC VERSION : \main\43 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  MODULE DECRIPTION : Lin_17_AscLin.bmd/.xdm                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Lin configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_LIN_Driver, Release 4.0.3                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
  TRACEABILITY : [cover parentID= DS_AS_LIN224,DS_AS4XX_LIN_PR2849,
DS_NAS_LIN_PR127,SAS_NAS_LIN_PR914,SAS_NAS_LIN_PR915,SAS_NAS_LIN_PR916,
SAS_AS4XX_LIN_PR678,DS_NAS_HE2_LIN_PR3054_1,DS_NAS_HE2_LIN_PR3054_2,
DS_NAS_HE2_LIN_PR3054_4,DS_NAS_EP_LIN_PR3054_1,DS_NAS_EP_LIN_PR3054_2,
DS_NAS_EP_LIN_PR3054_4] [/cover] 
*******************************************************************************/
#ifndef LIN_17_ASCLIN_CFG_H 
#define LIN_17_ASCLIN_CFG_H 
  

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Lin')[1]"!][!//
[!//

/*Section to Generate Autosar Specific Version Information*/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]

[!IF "$MajorVersion = num:i(4)"!][!//
#define LIN_17_ASCLIN_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define LIN_17_ASCLIN_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define LIN_17_ASCLIN_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/*Section to Generate Vendor Specific Version Information*/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define LIN_17_ASCLIN_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define LIN_17_ASCLIN_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define LIN_17_ASCLIN_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)
[!//


/*
         Container : LinGeneralConfiguration
*/

/*
Configuration: LIN_DEV_ERROR_DETECT 
- if STD_ON, DET is Enabled 
- if STD_OFF,DET is Disabled
The detection of all development errors is configurable (On / Off) 
at precompile time. The switch LIN_DEV_ERROR_DETECT (see chapter 10) shall
activate or deactivate the detection of all development errors.

If the switch LIN_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled. 
*/
#define LIN_DEV_ERROR_DETECT  ([!//
[!IF "LinGeneral/LinDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


/*
Configuration: LIN_VERSION_INFO_API 
- if STD_ON, Function Lin_GetVersionInfo is available  
- if STD_OFF,Function Lin_GetVersionInfo is not available 
*/
#define LIN_VERSION_INFO_API  ([!//
[!IF "LinGeneral/LinVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: LIN_PB_FIXEDADDR 
- if STD_ON, Fixed Address feature is Enabled 
- if STD_OFF,Fixed Address feature is Disabled
*/
#define LIN_PB_FIXEDADDR  ([!//
[!IF "LinGeneral/LinPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: LIN_RESET_SFR_INIT 
- if STD_ON :SFRs will be reset to default values before intialization 
- if STD_OFF :SFRs will not be reset to default values before intialization
*/
#define LIN_RESET_SFR_INIT  ([!//
[!IF "LinGeneral/LinResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


/*
Configuration: LIN_USER_MODE_RUNTIME_API_ENABLE
- if STD_ON, all APIs except Init and DeInit APIs are running in user mode and 
             protected register access is enabled for those APIs.
- if STD_OFF, all APIs except Init and DeInit APIs are running in supervisor mode and 
             protected register access is disabled for those APIs.
*/
#define LIN_USER_MODE_RUNTIME_API_ENABLE  ([!//
[!IF "LinGeneral/LinUserModeRuntimeApiEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: LIN_USER_MODE_INIT_API_ENABLE
- if STD_ON, Init API is running in user mode and 
             protected register access is enabled for Init API.
- if STD_OFF, Init API is running in running in supervisor mode and 
             protected register access is disabled for Init API.
*/
#define LIN_USER_MODE_INIT_API_ENABLE  ([!//
[!IF "LinGeneral/LinUserModeInitApiEnable = 'true'"!] [!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: LIN_RUNNING_IN_USER_0_MODE_ENABLE
- if STD_ON, user0 mode is enabled.
- if STD_OFF, user1 mode is enbled.
*/
#define LIN_RUNNING_IN_USER_0_MODE_ENABLE  ([!//
[!IF "LinGeneral/LinRunningInUser0Mode = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)
[!IF "LinGeneral/LinRunningInUser0Mode = 'true'"!]
[!ASSERT "LinGeneral/LinUserModeRuntimeApiEnable = 'true' or LinGeneral/LinUserModeInitApiEnable = 'true'"!]
 Config Errror: Inorder to configure LinRunningInUser0Mode as true, either or both of the parameters  LinUserModeRuntimeApiEnable,
 LinUserModeInitApiEnable should be configured as true.
[!ENDASSERT!]
[!ENDIF!]
/*
Configuration: LIN_INDEX 
*/
#define LIN_INDEX  ([!"LinGeneral/LinIndex"!]U)

/* Number of ASCLIN busses */
[!VAR "MaxAscLinMod"= "ecu:get('AscLin.MaxNoOfAscLinModules')"!][!//
#define LIN_MAX_HW_UNIT ([!"$MaxAscLinMod"!]U)

#define LIN_ASCLIN0 (0U)
#define LIN_ASCLIN1 (1U)
[!IF "$MaxAscLinMod > 2"!][!//
#define LIN_ASCLIN2 (2U)
[!ENDIF!][!//
[!IF "$MaxAscLinMod > 3"!][!//
#define LIN_ASCLIN3 (3U)
[!ENDIF!][!//
[!IF "$MaxAscLinMod > 4"!][!//
#define LIN_ASCLIN4 (4U)
[!ENDIF!][!//

[!// The following defines are unused. They shall be enabled if needed
[!NOCODE!][!//

/* 
Configuration: LIN_TIMEOUT_DURATION 
*/
#define LIN_TIMEOUT_DURATION  ([!"LinGeneral/LinTimeoutDuration"!]U)
[!ENDNOCODE!][!//


/* 
Configuration : LIN_MAXIMUM_CHANNEL 
It is the maximum lin channels configured.
*/
[!VAR "TotalConfig" = "num:i(count(LinGlobalConfig/*))"!][!//
[!VAR "MaxChannels"= "num:i(0)"!][!//
[!LOOP "LinGlobalConfig/*"!][!//
[!VAR "Count"= "num:i(count(LinChannel/*))"!][!//
[!IF "$Count > $MaxChannels"!][!//
[!VAR "MaxChannels" = "$Count"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
#define LIN_MAXIMUM_CHANNEL ([!"$MaxChannels"!]U)

[!NOCODE!][!//
[!VAR "TotalConfig" = "num:i(count(LinGlobalConfig/*))"!][!//
[!VAR "Asc0Used" = "num:i(0)"!][!//
[!VAR "Asc1Used" = "num:i(0)"!][!//
[!VAR "Asc2Used" = "num:i(0)"!][!//
[!VAR "Asc3Used" = "num:i(0)"!][!//
[!VAR "Asc4Used" = "num:i(0)"!][!//

[!LOOP "LinGlobalConfig/*"!][!//

[!VAR "tmp" = "num:i(count(LinChannel/*[LinChanAssignedHw='ASCLIN0']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN0 module shouldn't be configured for more than 1 Lin Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc0Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(LinChannel/*[LinChanAssignedHw='ASCLIN1']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN1 module shouldn't be configured for more than 1 Lin Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc1Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(LinChannel/*[LinChanAssignedHw='ASCLIN2']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN2 module shouldn't be configured for more than 1 Lin Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc2Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(LinChannel/*[LinChanAssignedHw='ASCLIN3']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN3 module shouldn't be configured for more than 1 Lin Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc3Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!VAR "tmp" = "num:i(count(LinChannel/*[LinChanAssignedHw='ASCLIN4']))"!][!//
[!IF "$tmp > 1"!][!//
[!ERROR "ASCLIN4 module shouldn't be configured for more than 1 Lin Channel"!][!//
[!ENDIF!][!//
[!IF "$tmp = 1"!][!//
[!VAR "Asc4Used" = "num:i(1)"!][!//
[!ENDIF!][!//

[!ENDLOOP!][!//

[!VAR "McuAscLinRef" = "node:path(node:ref(./LinGeneral/LinSysClockRef)/../../../AscLinConfiguration)"!][!//

[!IF "$Asc0Used = num:i(1)"!][!//
[!VAR "McuAscLin0Ref" = "node:ref(concat($McuAscLinRef,'/AscLin0'))"!]
[!IF "$McuAscLin0Ref != 'USE_FOR_LIN_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN0 Channel for LIN in Mcu Configuration. container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$Asc1Used = num:i(1)"!][!//
[!VAR "McuAscLin1Ref" = "node:ref(concat($McuAscLinRef,'/AscLin1'))"!]
[!IF "$McuAscLin1Ref != 'USE_FOR_LIN_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN1 Channel for LIN in Mcu Configuration. container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$Asc2Used = num:i(1)"!][!//
[!VAR "McuAscLin2Ref" = "node:ref(concat($McuAscLinRef,'/AscLin2'))"!]
[!IF "$McuAscLin2Ref != 'USE_FOR_LIN_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN2 Channel for LIN in Mcu Configuration . container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$Asc3Used = num:i(1)"!][!//
[!VAR "McuAscLin3Ref" = "node:ref(concat($McuAscLinRef,'/AscLin3'))"!]
[!IF "$McuAscLin3Ref != 'USE_FOR_LIN_DRIVER'"!][!//
[!ERROR "Configure the ASCLIN3 Channel for LIN in Mcu Configuration . container AscLinConfiguration"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

/*
Configuration: LIN_ASCLINx_USED 
- if STD_ON, ASCLINx is used   
- if STD_OFF,ASCLINx is not used  
*/

#define LIN_ASCLIN0_USED  ([!IF "$Asc0Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//


#define LIN_ASCLIN1_USED  ([!IF "$Asc1Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//

[!IF "$MaxAscLinMod > 2"!][!//
#define LIN_ASCLIN2_USED  ([!IF "$Asc2Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//
[!ENDIF!][!//

[!IF "$MaxAscLinMod > 3"!][!//
#define LIN_ASCLIN3_USED  ([!IF "$Asc3Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//
[!ENDIF!][!//

[!IF "$MaxAscLinMod > 4"!][!//
#define LIN_ASCLIN4_USED  ([!IF "$Asc4Used = num:i(1)"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)[!//
[!ENDIF!][!//


/* Total no. of config sets */
#define LIN_17_ASCLIN_CONFIG_COUNT  ([!"num:i(count(LinGlobalConfig/*))"!]U)


[!NOCODE!][!//

/* 
Configuration : Lin Channel IDs 
  LIN_CHANNELIDm_CONFIGn (x)
  where m is channel id no given in configuration, n is global config no
  x is internal Lin channel no.
*/
[!VAR "GlobalWakeupSupport" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "num:i(0)" TO "num:i($TotalConfig)- num:i(1)"!][!//
[!LOOP "LinGlobalConfig/*[@index= $ModuleIndex]/LinChannel/*"!][!//
[!VAR "CurLinChan" = "num:i(LinChannelId)"!][!//
[!IF "num:i(count(../*[num:i(LinChannelId)=num:i($CurLinChan)])) > 1"!][!//
[!ERROR "Config Error: one or more Lin Channels contains same LinChannelId."!][!//
[!ENDIF!][!//
[!//  Channel wakeup support for all channels is disabled, then 
[!IF "LinChannelWakeupSupport = 'true'"!][!//
[!VAR "GlobalWakeupSupport" = "num:i(1)"!][!//
[!ENDIF!]

[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//

/* Module Debug Support */
[!IF "LinGeneral/LinDebugSupport = 'true'"!][!//
#define LIN_DEBUG_SUPPORT   (STD_ON)
[!ELSE!][!//
#define LIN_DEBUG_SUPPORT  (STD_OFF)
[!ENDIF!][!//

[!IF "$GlobalWakeupSupport = num:i(1)"!][!//
/* LinChannelWakeupSupport is enabled for atleast 1 
                                              channel on all the config sets */
#define LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT   (STD_ON)
[!ELSE!][!//
/* LinChannelWakeupSupport is disabled for all the channels 
                                                     on all the config sets */
#define LIN_GLOBAL_CHANNEL_WAKEUP_SUPPORT  (STD_OFF)
[!ENDIF!][!//

[!IF "LinGeneral/LinHwMcuTrigSleepEnable = 'true'"!][!//
#define LIN_ASCLIN_CLC (0U)
[!ELSE!][!//
#define LIN_ASCLIN_CLC (0x08U)
[!ENDIF!]

[!SELECT "as:modconf('Lin')[1]"!][!//
[!LOOP "./LinGlobalConfig/*"!][!//
/* 
   Lin Channel ID Enumerations for Channel Configuration Instance 
   [!"node:name(.)"!]
*/
[!VAR "ChannelCounter" = "'0'"!][!//
[!LOOP "./LinChannel/*"!][!//
#ifndef LinConf_LinChannel_[!"node:name(.)"!]
#define LinConf_LinChannel_[!"node:name(.)"!]  ((uint8)[!"LinChannelId"!]U)
#endif
[!VAR "ChannelCounter" = "$ChannelCounter + 1"!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//

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
#endif  /* LIN_17_ASCLIN_CFG_H */

[!ENDSELECT!][!//
