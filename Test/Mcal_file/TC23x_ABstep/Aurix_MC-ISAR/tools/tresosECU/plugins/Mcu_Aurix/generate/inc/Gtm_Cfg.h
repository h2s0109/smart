[!/*
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
**  FILENAME  : Gtm_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 0.0.7                                                         **
**                                                                            **
**  DATE      : 2013.06.25                                                    **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=DS_NAS_PR446]
**                                                                            **
**  DESCRIPTION  : Configuration Generator Macros                             **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
**  TRACEABILITY: 
    [cover parentID=SAS_AS4XX_GTM_PR678,SAS_NAS_GTM_PR914,
    SAS_NAS_GTM_PR915,DS_NAS_EP_GTM_PR3054_1,DS_NAS_EP_GTM_PR3054_2,
    DS_NAS_EP_GTM_PR3054_3,DS_NAS_EP_GTM_PR3054_4]
                                                [/cover]                      **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** VS          Vinod Shankar	                                                **
** KP          Kaushal Purohit                                                **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
* V0.0.7 2013.06.25, KP : added ADC number of connection macro              **
* V0.0.6 2012.11.08, VS : Compiler Modifications                            **
* V0.0.5 2012.06.06, VS : UTP AI00071821 Fixed                              **
* V0.0.4 2012.04.25, VS : GTM Enhancement - Notification Included           **
* V0.0.3 2011.10.05, VS : Extra defines Introduced                          **
* V0.0.2 2011.04.05, VS : Review Changes                                    **
* V0.0.1 2011.02.11, VS : Initial Version of Gtm header file                **
*/
*/!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!// Generate this file only if Gtm is configured
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2011)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gtm_Cfg.h                                                    **
**                                                                            **
**  VERSION   : 0.0.6                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Mcu.bmd                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking/GNU/Diab                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GTM configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : complex driver                                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
[!NOCODE!][!//
[!VAR "McuSelect" = "'McuModuleConfiguration'"!][!//
[!VAR "TotalMcuConfig" = "num:i(count(node:ref($McuSelect)/*))"!][!//
[!VAR "TotalGtmConfig" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($McuSelect)/*))- 1)"!][!//
[!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleIndex + 1,']')"!][!//
[!VAR "Count" = "num:i(count(node:ref($McuSelectIndex)/GtmConfiguration/*))"!]
[!IF "$Count > num:i(0)"!][!//    
[!VAR "TotalGtmConfig" = "$TotalGtmConfig + $Count"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
#define GTM_CONFIG_COUNT  ([!"num:i($TotalMcuConfig)"!]U)
[!IF "$TotalGtmConfig > num:i(0)"!][!//
#ifndef GTMCFG_H
#define GTMCFG_H
[!IF "McuSafety/McuInitCheckApi = 'true' and McuSafety/McuSafetyEnable = 'true'"!][!//
#define GTM_MCUINITCHECK_API (STD_ON)
[!ELSE!][!//
#define GTM_MCUINITCHECK_API (STD_OFF)
[!ENDIF!][!//

[!IF "McuSafety/McuSafetyEnable = 'true'"!][!//
#define GTM_MCUSAFETY_ENABLE (STD_ON)
[!ELSE!][!//
#define GTM_MCUSAFETY_ENABLE (STD_OFF)
[!ENDIF!][!//


#define GTM_MCU_MODULE_INSTANCE ((uint8)0)

/*
Configuration: GTM_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "McuGeneralConfiguration/McuRunningInUser0Mode = 'true'"!][!//
#define GTM_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define GTM_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: GTM_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "McuGeneralConfiguration/McuUserModeInitApiEnable = 'true'"!][!//
#define GTM_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define GTM_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: GTM_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "McuGeneralConfiguration/McuUserModeDeInitApiEnable = 'true'"!][!//
#define GTM_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define GTM_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: GTM_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "McuGeneralConfiguration/McuUserModeRuntimeApiEnable = 'true'"!][!//
#define GTM_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define GTM_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/


/*****************************************************************************
**                                 GPT                                      **
******************************************************************************/
[!VAR "GptModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//.
[!VAR "GptModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//
#define  GTM_GPT_MODULE_USED                        ([!"$GptModuleUsed"!])
/*****************************************************************************
**                                 ICU                                      **
******************************************************************************/
[!VAR "IcuModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Icu')[1]"!][!/*
*/!][!VAR "IcuId" = "num:i(0)"!][!/*
*/!][!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!][!/*
*/!][!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!IF "contains($ChannelLocation, "TimChannel") = 'true'"!][!/*
*/!][!VAR "IcuModuleUsed" = "'STD_ON'"!][!/*
*/!][!ENDIF!][!/* [!IF "contains($ChannelLocation, "TimChannel") = 'true'"!]
*/!][!ENDLOOP!][!/*[!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!]
*/!][!ENDSELECT!][!//
#define GTM_ICU_MODULE_USED                          ([!"$IcuModuleUsed"!])
/*****************************************************************************
**                                 PWM                                      **
******************************************************************************/
[!VAR "PwmModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "PwmModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//
#define GTM_PWM_MODULE_USED                          ([!"$PwmModuleUsed"!])

[!NOCODE!][!/*
*/!][!VAR "TomUsed" = "'STD_OFF'"!][!/*
*/!][!VAR "TimUsed" = "'STD_OFF'"!][!/*
*/!][!VAR "McuSelect" = "'McuModuleConfiguration'"!][!/*
*/!][!VAR "TotalMcuConfig" = "num:i(count(node:ref($McuSelect)/*))"!][!/*
*/!][!FOR "ModuleId" ="num:i(0)" TO "(num:i($TotalMcuConfig)-1)"!][!/*
Validate PWM channels
*/!][!SELECT "as:modconf('Pwm')[1]"!][!/*
*/!][!SELECT "PwmChannelConfigSet/*[@index= $ModuleId]"!][!/*
*/!][!LOOP "PwmChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./PwmAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: PWM: PWMAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./PwmAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./PwmAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "TomUsed" = "'STD_ON'"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
Validate Gpt Channels
*/!][!SELECT "as:modconf('Gpt')[1]"!][!/*
*/!][!SELECT "GptChannelConfigSet/*[@index= $ModuleId]"!][!/*
*/!][!LOOP "GptChannelConfiguration/*"!][!/*
*/!][!ASSERT "node:refexists(./GptAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: GPT: GptAssignedHwUnit is not configured.[!/*
*/!][!ENDASSERT!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./GptAssignedHwUnit))"!][!/*
*/!][!VAR "ModuleLocation" = "node:name(node:ref(./GptAssignedHwUnit)/../..)"!][!/*
*/!][!VAR "ChannelNumber" = "text:split($ChannelLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleNumber" = "text:split($ModuleLocation, '_')[position()-1 = 1]"!][!/*
*/!][!VAR "ModuleType" = "text:split($ModuleLocation, '_')[position()-1 = 0]"!][!/*
*/!][!IF "$ModuleType = 'Tom'"!][!/*
*/!][!VAR "TomUsed" = "'STD_ON'"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDSELECT!][!/*
Validate the ICU channels
*/!][!VAR "IcuId" = "$ModuleId"!][!/*
*/!][!SELECT "as:modconf('Icu')[1]"!][!/*
*/!][!LOOP "IcuConfigSet/*[@index= $IcuId]/IcuChannel/*"!][!/*
*/!][!ASSERT "node:refexists(./IcuAssignedHwUnit) = 'true'"!][!/*
*/!]ERROR: ICU: Reference cell [!"@name"!] not provided - configure AssignedHwUnit
[!ENDASSERT!][!/*
*/!][!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!/*
*/!][!IF "contains($ChannelLocation, "ERU") != 'true'"!][!/*
*/!][!VAR "TimUsed" = "'STD_ON'"!][!/*
*/!][!ENDIF!][!/*
*/!][!ENDLOOP!][!/*
*/!][!ENDSELECT!][!/*
*/!][!ENDFOR!][!/*
*/!][!ENDNOCODE!][!//
/* TIM and TOM usage */
#define GTM_TOM_USED_BY_OTHER_DRIVERS    ([!"$TomUsed"!])
#define GTM_TIM_USED_BY_OTHER_DRIVERS    ([!"$TimUsed"!])



/* Resource Availability  */
#define GTM_TIM_MODULE  (0U)
#define GTM_NO_OF_TIM_MODULES   ([!"ecu:get('Gtm.NumberOfTimModules')"!]U)
#define GTM_CHANNELS_PER_TIM_MODULE    ([!"ecu:get('Gtm.NumberOfTimChannels')"!]U)
#define GTM_MAX_TIM_CHANNELS                                                  \
                          (GTM_NO_OF_TIM_MODULES * GTM_CHANNELS_PER_TIM_MODULE)

#define GTM_TOM_MODULE  (1U)
#define GTM_NO_OF_TOM_MODULES   ([!"ecu:get('Gtm.NumberOfTomModules')"!]U)
#define GTM_NO_OF_TGC_PER_MODULE  ([!"ecu:get('Gtm.NumberOfTGCPerTom')"!]U)
#define GTM_CHANNELS_PER_TOM_MODULE    ([!"ecu:get('Gtm.NumberOfTomChannels')"!]U)
#define GTM_TOM_CHANNELS_PER_TGC   ([!"ecu:get('Gtm.NumberOfChannelsPerTgc')"!]U)
#define GTM_MAX_TOM_CHANNELS                                                   \
                          (GTM_NO_OF_TOM_MODULES *  GTM_CHANNELS_PER_TOM_MODULE)

 


#define GTM_NO_OF_TBU_CHANNELS  ([!"ecu:get('Gtm.NumberOfTbuModules')"!]U)

#define GTM_NO_OF_TOUTSEL_REGISTERS  ([!"ecu:get('Gtm.NumberOfToutselRegister')"!]U)
#define GTM_NO_OF_ADC_MODULES ([!"ecu:get('Gtm.NumberOfAdcModules')"!]U)
#define GTM_ADC_CONN_PER_REGISTER ([!"ecu:get('Gtm.NumberOfConPerAdcModules')"!]U)
#define GTM_NO_OF_TTCAN_TRIGGERS ([!"ecu:get('Gtm.NumberOfTtcanTriggers')"!]U)

/* Gtm SFR resetting at Initialization is enabled */
[!IF "McuGeneralConfiguration/McuResetSfrAtInit = 'true'"!][!/*
*/!]#define GTM_SFR_RESET_ENABLE (STD_ON)[!/*
*/!][!ELSE!][!/*
*/!]#define GTM_SFR_RESET_ENABLE (STD_OFF)[!/*
*/!][!ENDIF!][!/*[!IF "McuGeneralConfiguration/McuResetSfrAtInit = 'true'"!]
*/!]
/* Gtm De-Init API enabled */
[!IF "McuGeneralConfiguration/McuDeInitApi = 'true'"!][!/*
*/!]#define GTM_DEINIT_API_ENABLE (STD_ON)
[!/*
*/!][!ELSE!][!/*
*/!]#define GTM_DEINIT_API_ENABLE (STD_OFF)
[!/*
*/!][!ENDIF!][!/*[!IF "McuGeneralConfiguration/McuDeInitApi = 'true'"!]
*/!]

[!/* Count the number of GTM channels for which notification is configured for TIM and TOM 
*/!][!VAR "ModuleId" = "num:i(0)"!][!/*
*/!][!VAR "NoOfTomChNotif" = "num:i(0)"!][!/*
*/!][!VAR "McuSelectIndex" = "concat('McuModuleConfiguration/*[',$ModuleId + 1,']')"!][!/*
*/!][!SELECT "node:ref($McuSelectIndex)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!VAR "NoOfTomChNotif" = "num:i(0)"!][!/*
*/!][!LOOP "Tom/*"!][!/*
*/!][!LOOP "TomChannel/*"!][!/*
*/!][!IF "./TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "TempCcu0" = "node:value(./TomChannelInterrupt/TomIntEnableOnPeriodMatchCcu0)"!][!/*
*/!][!VAR "TempCcu1" = "node:value(./TomChannelInterrupt/TomIntEnableOnDutyCycleMatchCcu1)"!][!/*
*/!][!VAR "Notification" = "node:value(./TomChannelInterrupt/TomNotification)"!][!/*
*/!][!IF "($TempCcu0 = 'true' or $TempCcu1 = 'true') and ($Notification != 'NULL_PTR')"!][!/*
*/!][!VAR "NoOfTomChNotif" = "num:i($NoOfTomChNotif + 1)"!][!/*
*/!][!ENDIF!][!/*[!IF "$TempCcu0 = 'true' or $TempCcu1 = 'true'"!]
*/!][!ENDIF!][!/*/TomChannelUsage/TomChannelUsage = 'USED_BY_GTM_DRIVER'
*/!][!ENDLOOP!][!/*LOOP "TomChannel/*
*/!][!ENDLOOP!][!/*LOOP "Tom/*"
*/!][!ENDSELECT!][!/*SELECT "node:ref($McuSelectIndex)"
*/!][!ENDSELECT!][!/*SELECT "node:ref($McuSelectIndex)"
*/!]

/*Number of TOM and  TIM channels configured for notifications*/
#define GTM_NO_OF_TOM_CH_CONF_NOTIF ([!"$NoOfTomChNotif"!]U)[!/*
[!/*
*/!][!SELECT "node:ref($McuSelectIndex)"!][!/*
*/!][!SELECT "GtmConfiguration/*[1]"!][!/*
*/!][!VAR "NoOfTimChNotif" = "num:i(0)"!][!/*
*/!][!LOOP "Tim/*"!][!/*
*/!][!LOOP "TimChannel/*"!][!/*
*/!][!IF "./TimChannelGeneral/TimChannelUsage = 'USED_BY_GTM_DRIVER'"!][!/*
*/!][!VAR "NewVal" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnNewVal)"!][!/*
*/!][!VAR "EcntOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnEcntOfl)"!][!/*
*/!][!VAR "CntOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnCntOfl)"!][!/*
*/!][!VAR "GprxOfl" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGprxOfl)"!][!/*
*/!][!VAR "ToDet" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnToDet)"!][!/*
*/!][!VAR "GlitchDet" = "node:value(./TimChannelInterrupt/TimInterruptEnableOnGlitchDet)"!][!/*
*/!][!VAR "Notification" = "node:value(./TimChannelInterrupt/TimNotification)"!][!/*
*/!][!IF "$Notification != 'NULL_PTR'"!][!/*
*/!][!IF "($NewVal = 'true' or $EcntOfl = 'true' or $CntOfl = 'true' or $GprxOfl = 'true' or $ToDet = 'true' or $GlitchDet = 'true')"!][!/*
*/!][!VAR "NoOfTimChNotif" = "num:i($NoOfTimChNotif + 1)"!][!/*
*/!][!ENDIF!][!/*IF "($NewVal = 'true' or $EcntOfl = 'true' or $CntOfl = 'true' or $GprxOfl = 'true' or $ToDet = 'true' or $GlitchDet = 'true')
*/!][!ENDIF!][!/*[!IF "$Notification != 'NULL_PTR'"!]
*/!][!ENDIF!][!/*[!IF "./TimChannelGeneral/TimChannelUsage = 'USED_BY_GTM_DRIVER'"!]
*/!][!ENDLOOP!][!/*[!LOOP "Tim/*"!]
*/!][!ENDLOOP!][!/*[!LOOP "TimChannel/*"!]
*/!][!ENDSELECT!][!/* [!SELECT "GtmConfiguration/*[1]"!]
*/!][!ENDSELECT!][!/*SELECT "node:ref($McuSelectIndex)"
*/!]
#define GTM_NO_OF_TIM_CH_CONF_NOTIF ([!"$NoOfTimChNotif"!]U)

/* Generating defines for Global Channel Numbers */
[!VAR "TotalCount" = "num:i(0)"!][!//
[!FOR "GcnModuleCount" = "0" TO "ecu:get('Gtm.NumberOfTimModules') - 1"!][!//
[!FOR "GcnCount" = "0" TO "ecu:get('Gtm.NumberOfTimChannels') - 1 "!][!//
#define GTM_TIM[!"num:i($GcnModuleCount)"!]_CHANNEL[!"num:i($GcnCount)"!]   ([!"num:dectoint(num:i($GcnCount) + ($TotalCount))"!]U)
[!ENDFOR!][!//
[!VAR "TotalCount" = "$TotalCount + ecu:get('Gtm.NumberOfTimChannels')"!][!//
[!ENDFOR!][!//
[!//
[!FOR "GcnModuleCount" = "0" TO "ecu:get('Gtm.NumberOfTomModules') - 1"!][!//
[!FOR "GcnCount" = "0" TO "ecu:get('Gtm.NumberOfTomChannels') - 1 "!][!//
#define GTM_TOM[!"num:i($GcnModuleCount)"!]_CHANNEL[!"num:i($GcnCount)"!]   ([!"num:dectoint(num:i($GcnCount) + ($TotalCount))"!]U)
[!ENDFOR!][!//
[!VAR "TotalCount" = "$TotalCount + ecu:get('Gtm.NumberOfTomChannels')"!][!//
[!ENDFOR!][!//
[!//

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#endif
[!ELSE!][!//
/*******************************************************************************
**                      GTM Not Configured                                    **
*******************************************************************************/
[!ENDIF!][!//
[!ENDSELECT!][!//
