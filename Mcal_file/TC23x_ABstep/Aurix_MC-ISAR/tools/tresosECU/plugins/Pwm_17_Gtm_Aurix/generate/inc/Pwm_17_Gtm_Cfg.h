[!/*****************************************************************************
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
**  $FILENAME  : Pwm_17_Gtm_Cfg.h $                                           **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**   $DATE       : 2016-03-22 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for Pwm_17_Gtm_Cfg.h file                    **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  TRACEABILITY: [cover parentID=SAS_AS_PWM003a_PWM003b,
                   DS_NAS_PWM_PR446,DS_NAS_PWM_PR699,DS_NAS_PWM_PR700,
                   DS_NAS_PWM_PR701,DS_NAS_PWM_PR704,DS_NAS_PWM_PR707,
                   DS_NAS_PWM_PR708,DS_NAS_PWM_PR709,DS_NAS_PWM_PR712,
                   DS_NAS_PWM_PR717,DS_NAS_PWM_PR724,DS_NAS_PWM_PR728,
                   DS_AS4XX_PWM_PR2849,
                   SAS_NAS_PWM_PR914,SAS_NAS_PWM_PR915,SAS_NAS_PWM_PR916,
                   SAS_AS4XX_PWM_PR678,
                   DS_NAS_HE2_PWM_PR3054_1,DS_NAS_EP_PWM_PR3054_1,
                   DS_NAS_HE2_PWM_PR3054_2,DS_NAS_EP_PWM_PR3054_2,
                   DS_NAS_HE2_PWM_PR3054_3,DS_NAS_EP_PWM_PR3054_3,
                   DS_NAS_HE2_PWM_PR3054_4,DS_NAS_EP_PWM_PR3054_4,
                    ]                                                         **
**                                                                            **
**                 Code template for Pwm_17_Gtm_Cfg.h file                    **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
*************************************************************************/!][!//
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
**  $FILENAME  : Pwm_17_Gtm_Cfg.h  $                                          **
**                                                                            **
**   $CC VERSION : \main\38 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**  DESCRIPTION  : PWM configuration generated out of ECU configuration       **
**                   file                                                     **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                     **
**                                                                            **
*******************************************************************************/

#ifndef PWM_17_GTM_CFG_H
#define PWM_17_GTM_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!NOCODE!][!//
[!INCLUDE "Pwm_17_Gtm.m"!][!//
[!ENDNOCODE!][!//
[!//
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
#define PWM_17_GTM_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define PWM_17_GTM_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define PWM_17_GTM_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)

[!VAR "MajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleSoftwareVer,"\.",'')"!][!//
#define PWM_17_GTM_SW_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define PWM_17_GTM_SW_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define PWM_17_GTM_SW_PATCH_VERSION  ([!"$RevisionVersion"!]U)
[!/*
MACRO: CG_PrintPeriodUpdateEndPeriodComments
Macro to print a set of comments;
parameter dummy ; may be for future use
*/!]
[!MACRO "CG_PrintPeriodUpdateEndPeriodComments"!][!//
/*
  Configuration: PWM_DUTY_PERIOD_UPDATED_ENDPERIOD
   Applicable for Variable Period Channel Class.
   Feature to have the duty cycle / period change, whether to update
   the duty / period at the end period or not.
   */
[!ENDMACRO!]
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!//
[!VAR "PwmFixedPeriodName" = "'PWM_FIXED_PERIOD'"!][!//
[!VAR "PwmFixedPeriodShiftName" = "'PWM_FIXED_PERIOD_SHIFTED'"!][!//
[!VAR "PwmVariablePeriodName" = "'PWM_VARIABLE_PERIOD'"!][!//
[!VAR "PwmFixedPeriodCenterName" = "'PWM_FIXED_PERIOD_CENTER_ALIGNED'"!][!//
[!//
/*
                    Container:PwmGeneral
*/
/* Instance ID for PWM_17_Gtm module */
#define PWM_17_GTM_INSTANCE_ID         ((uint8)[!"num:i(PwmGeneral/PwmIndex)"!]U)

/*
PWM075: Pre Compile time parameters are placed in Pwm_Cfg.h
*/
/*
  Configuration: PWM_DEV_ERROR_DETECT : PWM064 PWM078
  Configuration of Development Error Detection 
  PWM064: API Parameter Checking is enabled if this compiler
  switch is STD_ON.
  PWM078: All errors are reported to Det_ReportError if the
  switch is STD_ON.
  Adds/removes the Development error detection 
  from the code 
  - if STD_ON, Development error detection is enabled
  - if STD_OFF, Development error detection is disabled
*/
#define PWM_DEV_ERROR_DETECT                 [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmDevErrorDetect"!]

/*
  Configuration: PWM_DE_INIT_API
  Configuration of Pwm_DeInit API
  Adds/removes the service Pwm_DeInit() 
  from the code 
  - if STD_ON, Pwm_DeInit() can be used
  - if STD_OFF, Pwm_DeInit() cannot be used
*/
#define PWM_DE_INIT_API                      [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmDeInitApi"!]

/*
  Configuration: PWM_GET_OUTPUT_STATE_API
  Configuration of Pwm_Get_Output_State_Api
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_GetOutputState() can be used
  - if STD_OFF, Pwm_GetOutputState() cannot be used
*/
#define PWM_GET_OUTPUT_STATE_API                       [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmGetOutputState"!]

/*
  Configuration: PWM_SET_DUTY_CYCLE_API
  Configuration of Pwm_Set_Duty_Cycle_Api
  Adds/removes the service Pwm_GetOutputState() 
  from the code 
  - if STD_ON, Pwm_SetDutyCycle() can be used
  - if STD_OFF,Pwm_SetDutyCycle() cannot be used
*/
#define PWM_SET_DUTY_CYCLE_API                       [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmSetDutyCycle"!]

/*
  Configuration: PWM_SET_OUTPUT_TO_IDLE_API
  Configuration of Pwm_Set_Output_To_Idle_Api
  Adds/removes the service Pwm_SetOutputToIdle() 
  from the code 
  - if STD_ON, Pwm_SetOutputToIdle() can be used
  - if STD_OFF,Pwm_SetOutputToIdle() cannot be used
*/
#define PWM_SET_OUTPUT_TO_IDLE_API                       [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmSetOutputToIdle"!]

/*
  Configuration: PWM_SET_PERIOD_AND_DUTY_API
  Configuration of Pwm_Set_Period_And_Duty_Api
  Adds/removes the service Pwm_SetPeriodAndDuty() 
  from the code 
  - if STD_ON, Pwm_SetPeriodAndDuty() can be used
  - if STD_OFF,Pwm_SetPeriodAndDuty() cannot be used
*/
#define PWM_SET_PERIOD_AND_DUTY_API                       [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty"!]

/* Enables the handling of Shifted channel by offset
  - if STD_ON, Shifted channel is handled by offset
  - if STD_OFF, Shifted channel andled by trigger from 
               referenced Fixed period channel
*/
#define PWM_HANDLE_SHIFT_BY_OFFSET                       [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmHandleShiftByOffset"!]
/*
  Enables/Disables the Safety features 
  - if STD_ON, Safety features are enabled
  - if STD_OFF, Safety features are disabled
*/

#define PWM_SAFETY_ENABLE                 [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmSafety/PwmSafetyEnable"!]
/*
  Configuration: PWM_NOTIFICATION_SUPPORTED
  Adds/removes the service Pwm_EnableNotification()
  and Pwm_DisableNotification() from the code 
  - if STD_ON, Notification API's can be used
  - if STD_OFF, Notification API's cannot be used
*/
[!IF "node:exists(./PwmGeneral/PwmNotificationSupported)"!][!//
#define PWM_NOTIFICATION_SUPPORTED           [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmNotificationSupported"!]
[!ELSE!][!//
#define PWM_NOTIFICATION_SUPPORTED           (STD_OFF)
[!ENDIF!][!//

/*
  Configuration: PWM_NOTIFICATION_FOR_0_AND_100
  Enable Notification for 0% and 100% duty 
  - if STD_ON, Notification for 0% and 100% duty is supported
  - if STD_OFF, Notification for 0% and 100% duty is not supported
*/

[!IF "node:exists(./PwmGeneral/PwmEnable0Or100DutyNotification)"!][!//
#define PWM_NOTIF_FOR_100_0_ENABLE           [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmEnable0Or100DutyNotification"!]
[!ELSE!][!//
#define PWM_NOTIF_FOR_100_0_ENABLE           (STD_OFF)
[!ENDIF!][!//

[!IF "node:exists(./PwmGeneral/PwmDutycycleUpdatedEndperiod)"!][!//
/*
Configuration: PWM_DUTYCYCLE_UPDATED_ENDPERIOD
Applicable for Fixed Period Channel Class.
Feature to have the duty cycle change, whether to update
the duty at the end period or not.
*/
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD      [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmDutycycleUpdatedEndperiod"!]
[!ELSE!][!//
#define PWM_DUTYCYCLE_UPDATED_ENDPERIOD      (STD_OFF)
[!ENDIF!][!//


[!IF "node:exists(./PwmGeneral/PwmPeriodUpdatedEndperiod)"!][!//
[!VAR "DutyPeriodUpdate" = "./PwmGeneral/PwmPeriodUpdatedEndperiod"!][!//
[!CALL "CG_PrintPeriodUpdateEndPeriodComments"!][!//
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD    [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmPeriodUpdatedEndperiod"!]
[!ELSE!][!//
#define PWM_DUTY_PERIOD_UPDATED_ENDPERIOD    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PWM_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "node:exists(./PwmGeneral/PwmRunningInUser0Mode)"!][!//
[!IF "PwmGeneral/PwmRunningInUser0Mode = 'true'"!][!//
[!ASSERT "not((./PwmGeneral/PwmUserModeInitApiEnable != 'true') and (./PwmGeneral/PwmUserModeDeInitApiEnable != 'true') and (./PwmGeneral/PwmUserModeRuntimeApiEnable != 'true'))"!][!//
Config Error: when PwmGeneral/PwmRunningInUser0Mode is set as true, [!//
Then atleast any one of the switches: PwmUserModeInitApiEnable or [!//
PwmUserModeDeInitApiEnable or PwmUserModeRuntimeApiEnable should be selected.[!//
But in configuration none are selected.[!//
[!ENDASSERT!][!//
[!ENDIF!][!//
#define PWM_RUNNING_IN_USER_0_MODE_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmRunningInUser0Mode"!]
[!ELSE!][!//
#define PWM_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PWM_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "node:exists(./PwmGeneral/PwmUserModeInitApiEnable)"!][!//
#define PWM_USER_MODE_INIT_API_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmUserModeInitApiEnable"!]
[!ELSE!][!//
#define PWM_USER_MODE_INIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PWM_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Enable Supervisor mode in DeInit API 
*/
[!IF "node:exists(./PwmGeneral/PwmUserModeDeInitApiEnable)"!][!//
#define PWM_USER_MODE_DEINIT_API_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmUserModeDeInitApiEnable"!]
[!ELSE!][!//
#define PWM_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: PWM_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
[!IF "node:exists(./PwmGeneral/PwmUserModeRuntimeApiEnable)"!][!//
#define PWM_USER_MODE_RUNTIME_API_ENABLE     [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmUserModeRuntimeApiEnable"!]
[!ELSE!][!//
#define PWM_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
  Configuration: PWM_VERSION_INFO_API
  Adds/removes the service Pwm_GetVersionInfo() 
  from the code 
  - if STD_ON, Pwm_GetVersionInfo() can be used
  - if STD_OFF, Pwm_GetVersionInfo() cannot be used
*/
#define PWM_VERSION_INFO_API                 [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmVersionInfoApi"!]

[!IF "node:exists(./PwmConfigurationOfOptApiServices/PwmSyncGrpUpdateDutiesApi)"!][!//
/*
  Configuration: PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE
  Adds/removes the service Pwm_17_Gtm_SyncGrpUpdateDutiesApi() 
  from the code 
  - if STD_ON, Pwm_17_Gtm_SyncGrpUpdateDutiesApi() can be used
  - if STD_OFF, Pwm_17_Gtm_SyncGrpUpdateDutiesApi() cannot be used
*/
#define PWM_17_GTM_SYNCGRPUPDATEDUTIES_ENABLE                     [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmConfigurationOfOptApiServices/PwmSyncGrpUpdateDutiesApi  "!]
[!ENDIF!][!//

[!NOCODE!][!//
[!//
[!VAR "TotalPwmConfig" = "num:i(count(PwmChannelConfigSet/*))"!][!//
[!/* Determine only one PwmChannelConfigSet is configured 
                                        when PwmPBFixedAddress = true.*/!]
[!IF "PwmGeneral/PwmPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalPwmConfig != 1)"!][!//
Config Error: when PwmGeneral/PwmPBFixedAddress is set as true, [!//
Only one PwmChannelConfigSet configuration is allowed. [!//
But PwmChannelConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/* Total no. of config sets */
#define PWM_17_GTM_CONFIG_COUNT  ([!"num:i(count(PwmChannelConfigSet/*))"!]U)
/* Configuration : PwmPBFixedAddress
   This parameter enables the user to switch STD_ON/STD_OFF the
   PostBuild Fixed Address Feature  
*/
[!IF "node:exists(./PwmGeneral/PwmPBFixedAddress)"!][!//
#define PWM_PB_FIXEDADDR           [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmPBFixedAddress"!]
[!ELSE!][!//
#define PWM_PB_FIXEDADDR           (STD_OFF)
[!ENDIF!][!//

/* Configuration : PwmDutyShiftInTicks
   This parameter enables the user to enter the duty cycle and 
   shift value in absolute ticks, instead of percentage
*/
[!IF "node:exists(./PwmGeneral/PwmDutyShiftInTicks)"!][!//
#define PWM_DUTY_SHIFT_IN_TICKS     [!CALL "CG_ConfigSwitch", "nodeval" = "./PwmGeneral/PwmDutyShiftInTicks"!]
[!ELSE!][!//
#define PWM_DUTY_SHIFT_IN_TICKS     (STD_OFF)
[!ENDIF!][!//

/* Configured PWM Channels Symbolic Names */
[!LOOP "PwmChannelConfigSet/*"!][!//
[!LOOP "PwmChannel/*"!][!//
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmChannel_[!"node:name(.)"!]
#define Pwm_17_GtmConf_PwmChannel_[!"node:name(.)"!]     ((Pwm_17_Gtm_ChannelType)[!"PwmChannelId"!])
#endif
[!ENDLOOP!][!//
[!ENDLOOP!][!//

/* Configured PWM Groups Symbolic Names */
[!LOOP "PwmChannelConfigSet/*"!][!//
[!LOOP "PwmSyncGroup/*"!][!//
/*IFX_MISRA_RULE_01_04_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_05_01_STATUS=The generated macro may exceeds 31 
  characters to follow Autosar naming conventions*/
#ifndef Pwm_17_GtmConf_PwmSyncGroup_[!"node:name(.)"!]
#define Pwm_17_GtmConf_PwmSyncGroup_[!"node:name(.)"!]     ((uint8)[!"PwmGroupId"!])
#endif
[!ENDLOOP!][!//
[!ENDLOOP!][!//


/*
   Configuration:Max channels configured for Pwm
   Maximum Channels is calculated based on the number of channels configured 
   for each configuration.For instance if configuration set 1 has 5 channels 
   and configuration set 2 has 7 channels then the Maxchannels is 7.
*/
[!NOCODE!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "TotalPwmConfig" = "num:i(count(PwmChannelConfigSet/*))"!][!//
[!VAR "MaxChannels"= "num:i(0)"!][!//
[!VAR "PwmSetPeriodApi" = "./PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty"!][!//
[!FOR "PwmId" ="num:i(1)" TO "num:i($TotalPwmConfig)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!//
[!VAR "Count"= "num:i(count(PwmChannelConfigSet/*[num:i($PwmId)]/PwmChannel/*))"!][!//
[!IF "num:i($Count) > num:i($MaxChannels)"!][!//
[!VAR "MaxChannels" = "num:i($Count)"!][!//
[!ENDIF!][!//

[!SELECT "PwmChannelConfigSet/*[num:i($PwmId)]"!][!//
  [!VAR "FPCells" = "'STD_OFF'"!][!//
  [!VAR "FPSCells" = "'STD_OFF'"!][!//
  [!VAR "FPCCCells" = "'STD_OFF'"!][!//
  [!VAR "VPCells" = "'STD_OFF'"!][!//
  [!// Loop on fixed period channels
  [!LOOP "PwmChannel/*[PwmChannelClass/*[num:i(1)] = $PwmFixedPeriodName]"!][!//
  [!VAR "FPCells" = "'STD_ON'"!][!//
  [!ENDLOOP!][!//
  [!// Loop on fixed period shifted channels
  [!LOOP "PwmChannel/*[PwmChannelClass/*[num:i(1)] = $PwmFixedPeriodShiftName]"!][!//
  [!VAR "FPSCells" = "'STD_ON'"!][!//
  [!ENDLOOP!][!//
  [!// Loop on fixed period centre aligned channels
  [!LOOP "PwmChannel/*[PwmChannelClass/*[num:i(1)] = $PwmFixedPeriodCenterName]"!][!//
  [!VAR "FPCCCells" = "'STD_ON'"!][!//
  [!ENDLOOP!][!//
  [!// Loop on variable period channels
  [!LOOP "PwmChannel/*[PwmChannelClass/*[num:i(1)] = $PwmVariablePeriodName]"!][!//
  [!VAR "VPCells" = "'STD_ON'"!][!//
  [!ASSERT "$PwmSetPeriodApi = 'true'"!][!//
Config Error: when PwmConfigurationOfOptApiServices/PwmSetPeriodAndDuty is set as false, [!//
PwmChannelClass of [!"node:name(.)"!] should not be configured as type PWM_VARIABLE_PERIOD. [!//
  [!ENDASSERT!][!//
  [!ENDLOOP!][!//
[!ENDSELECT!][!//

[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//


#define PWM_MAX_CHANNELS   ((Pwm_17_Gtm_ChannelType)[!"$MaxChannels"!])

[!NOCODE!][!//
[!IF "PwmSafety/PwmSafetyEnable = 'true'"!][!//
 [!VAR "AsilBMax" = "num:i(0)"!][!//
 [!VAR "AsilBMax_Temp" = "num:i(0)"!][!//
 [!VAR "QMMax" = "num:i(0)"!][!//
 [!VAR "QMMax_Temp" = "num:i(0)"!][!//
 [!SELECT "PwmChannelConfigSet/*"!][!//
  [!VAR "AsilBMax_Temp" = "num:i(0)"!][!//
  [!VAR "QMMax_Temp" = "num:i(0)"!][!//
  [!LOOP "./PwmChannel/*"!][!//
   [!VAR "ChannelType" = "PwmSafetySignal"!][!//
   [!IF "$ChannelType = 'PWM_ASIL_TYPE'"!][!//
     [!VAR "AsilBMax_Temp" = "$AsilBMax_Temp + num:i(1)"!][!//
   [!ENDIF!][!//
   [!IF "$ChannelType = 'PWM_QM_TYPE'"!][!//
     [!VAR "QMMax_Temp" = "$QMMax_Temp + num:i(1)"!][!//
   [!ENDIF!][!//
  [!ENDLOOP!][!//
  [!IF "$AsilBMax_Temp > $AsilBMax"!][!//
   [!VAR "AsilBMax" = "$AsilBMax_Temp"!][!//
  [!ENDIF!][!//
  [!IF "$QMMax_Temp > $QMMax"!][!//
   [!VAR "QMMax" = "$QMMax_Temp"!][!//
  [!ENDIF!][!//
 [!ENDSELECT!][!//
[!ELSE!][!//
[!VAR "AsilBMax" = "num:i(0)"!][!//
[!VAR "QMMax" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "PwmSafety/PwmSafetyEnable = 'true'"!][!//
#define PWM_MAX_ASIL_CHANNELS  ( [!"num:i($AsilBMax)"!])

#define PWM_MAX_QM_CHANNELS    ([!"num:i($QMMax)"!])
[!ELSE!][!//
#define PWM_MAX_QM_CHANNELS    ([!"$MaxChannels"!])
[!ENDIF!][!//

/*
   Derived pre compile switches for optimization
   purpose
*/

#define PWM_VARIABLE_PERIOD_USED                     ([!"$VPCells"!])
#define PWM_FIXED_PERIOD_USED                        ([!"$FPCells"!])
#define PWM_FIXED_PERIOD_SHIFTED_USED                ([!"$FPSCells"!])
#define PWM_USED_FIXED_PERIOD_CENTER_ALIGNED         ([!"$FPCCCells"!])

/* Values to be update Shadow register to get 0% and 100% duty*/
#define PWM_SR0_VALUE    ([!"num:i(ecu:get('Pwm.SR0Value'))"!]U)
#define PWM_SR1_VALUE    ([!"num:i(ecu:get('Pwm.SR1Value'))"!]U)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
[!ENDSELECT!][!//

#endif
