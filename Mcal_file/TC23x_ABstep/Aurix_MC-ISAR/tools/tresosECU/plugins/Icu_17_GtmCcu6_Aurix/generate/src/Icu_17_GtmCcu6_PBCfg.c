[!/*****************************************************************************
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
**  $FILENAME   : Icu_17_GtmCcu6_PBCfg.c $                                   **
**                                                                           **
**  $CC VERSION : \main\50 $                                                 **
**                                                                           **
**  $DATE       : 2016-08-02 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :  Code template for Icu_17_GtmCcu6_PBCfg.c file             **
**                                                                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: no                                      **
**                                                                           **
************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=DS_AS_ICU189,DS_NAS_ICU_PR69_PR469,
                       DS_NAS_ICU_PR446,DS_MCAL_ICU_0001,
             DS_AS4XX_ICU_PR2849] 
             [/cover]    */!][!//
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
**  FILENAME  : Icu_17_GtmCcu6_PBCfg.c                                        **
**                                                                            **
**  $CC VERSION : \main\50 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Icu configuration generated out of ECU configuration       **
**                 file  (Icu_17_GtmCcu6.bmd)                                 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include module header File */
/* [cover parentID=SAS_AS_ICU219_ICU245_ICU247_ICU251_ICU254_ICU256_ICU115,
        DS_NAS_ICU_PR699,DS_NAS_ICU_PR709] */
#include "Icu_17_GtmCcu6.h"
/* [/cover] */
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_INTERRUPT_LEVEL_MODE          (0U)
#define GTM_INTERRUPT_PULSE_MODE          (1U)
#define GTM_INTERRUPT_PULSE_NOTIFY_MODE   (2U) 
#define GTM_INTERRUPT_SINGLE_PULSE_MODE   (3U)
/*
Configuration Options:
IcuAssignedHwunit
*/
[!IF "($derivate = 'TC2DX')"!][!//
/*
Configuration Options:
*/
[!ENDIF!][!//
#define ICU_ASSIGN_ERU0_PINLINE0 (0U)
#define ICU_ASSIGN_ERU0_PINLINE1 (1U)
#define ICU_ASSIGN_ERU0_PINLINE2 (2U)
#define ICU_ASSIGN_ERU0_PINLINE3 (3U)
#define ICU_ASSIGN_ERU1_PINLINE0 (4U)
#define ICU_ASSIGN_ERU1_PINLINE1 (5U)
#define ICU_ASSIGN_ERU1_PINLINE2 (6U)
#define ICU_ASSIGN_ERU1_PINLINE3 (7U)
#define ICU_ASSIGN_ERU2_PINLINE0 (8U)
#define ICU_ASSIGN_ERU2_PINLINE1 (9U)
#define ICU_ASSIGN_ERU2_PINLINE2 (10U)
#define ICU_ASSIGN_ERU2_PINLINE3 (11U)
#define ICU_ASSIGN_ERU3_PINLINE0 (12U)
#define ICU_ASSIGN_ERU3_PINLINE1 (13U)
#define ICU_ASSIGN_ERU3_PINLINE2 (14U)
#define ICU_ASSIGN_ERU3_PINLINE3 (15U)
#define ICU_ASSIGN_ERU4_PINLINE0 (16U)   
#define ICU_ASSIGN_ERU4_PINLINE1 (17U)  
#define ICU_ASSIGN_ERU4_PINLINE2 (18U)  
#define ICU_ASSIGN_ERU4_PINLINE3 (19U)  
#define ICU_ASSIGN_ERU5_PINLINE0 (20U)  
#define ICU_ASSIGN_ERU5_PINLINE1 (21U)  
#define ICU_ASSIGN_ERU5_PINLINE2 (22U)  
#define ICU_ASSIGN_ERU5_PINLINE3 (23U)  
#define ICU_ASSIGN_ERU6_PINLINE0 (24U)  
#define ICU_ASSIGN_ERU6_PINLINE1 (25U)  
#define ICU_ASSIGN_ERU6_PINLINE2 (26U) 
#define ICU_ASSIGN_ERU6_PINLINE3 (27U) 
#define ICU_ASSIGN_ERU7_PINLINE0 (28U) 
#define ICU_ASSIGN_ERU7_PINLINE1 (29U) 
#define ICU_ASSIGN_ERU7_PINLINE2 (30U) 
#define ICU_ASSIGN_ERU7_PINLINE3 (31U) 


/*
Define for unused ERU Line 
*/
#define ERU_REQLINE_UNUSED   (255U)
[!IF "ecu:get('Ccu6.Available') = 'true'"!][!//

/* CCU defines */
[!FOR "CcuKernalIndex" = "0" TO "ecu:get('Ccu6.MaxKernals') - 1"!][!//
[!FOR "CcIndex" = "0" TO "ecu:get('Ccu6.MaxT12Channels') - 1"!][!//
[!VAR "ChannelNumber" = "num:i(num:add($CcuKernalIndex, bit:shl($CcIndex, 4)))"!][!//
#define ICU_CCU6[!"$CcuKernalIndex"!]_CC6[!"$CcIndex"!] [!"num:inttohex($ChannelNumber,2)"!]U
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!VAR "IcuSafetyEnabled" = "IcuSafety/IcuSafetyEnable"!][!//
/*******************************************************************************
**                      Private Function like Macros                          **
*******************************************************************************/

[!NOCODE!]

[!INCLUDE "Icu_17_GtmCcu6.m"!][!//

[!ENDNOCODE!]

[!SELECT "as:modconf('Icu')[1]"!][!//
[!NOCODE!][!//
[!VAR "TotalIcuConfig" = "num:i(count(IcuConfigSet/*))"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
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
[!ENDSELECT!][!//
[!ASSERT "(num:i($TotalIcuConfig) <= num:i($TotalMcuConfig))"!][!//
Configuration Error: Each Icu Channel Config Set should have corresponding MCU Module Configuration
[!ENDASSERT!][!//
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalIcuConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!VAR "TotalConfig" = "$TotalIcuConfig"!]
[!ENDNOCODE!][!//
/*******************************************************************************
**                       Function Declarations                                **
*******************************************************************************/

#define ICU_17_GTMCCU6_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!FOR "ModuleId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//
[!NOCODE!][!//
[!IF "num:i($ModuleId) > num:i($TotalGtmConfig)"!][!//
[!VAR "GtmId" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "GtmId" = "$ModuleId"!][!//
[!ENDIF!][!//
[!IF "num:i($ModuleId) > num:i($TotalIcuConfig)"!][!//
[!VAR "IcuId" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "IcuId" = "$ModuleId"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDFOR!][!//
[!VAR "ReportWakeupSource" = "IcuGeneral/IcuReportWakeupSource"!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!LOOP "IcuConfigSet/*"!][!//
[!LOOP "IcuChannel/*"!][!//
[!NOCODE!]
[!VAR "NotifyFunction" = "'(Icu_17_GtmCcu6_NotifiPtrType)(0)'"!][!//
[!VAR "MeasMode" = "./IcuMeasurementMode"!][!//
[!IF "$MeasMode = 'ICU_MODE_TIMESTAMP'"!][!//
[!IF "node:exists(./IcuTimestampMeasurement/*[1]/IcuTimestampNotification/*[1]) = 'true'"!][!//
[!VAR "NotifyFunction" = "./IcuTimestampMeasurement/*[1]/IcuTimestampNotification/*[1]"!][!//
[!ELSE!][!//
[!VAR "NotifyFunction" = "''"!][!//
[!ENDIF!][!//
[!ELSEIF "$MeasMode = 'ICU_MODE_SIGNAL_EDGE_DETECT'"!][!//
[!IF "node:exists(./IcuSignalEdgeDetection/*[1]/IcuSignalNotification/*[1]) = 'true'"!][!//
[!VAR "NotifyFunction" = "./IcuSignalEdgeDetection/*[1]/IcuSignalNotification/*[1]"!][!//
[!ELSE!][!//
[!VAR "NotifyFunction" = "''"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "string-length($NotifyFunction) = 0"!][!//
[!VAR "NotifyFunction" = "'(Icu_17_GtmCcu6_NotifiPtrType)(0)'"!][!//
[!ENDIF!][!//
[!IF "$NotifyFunction = '"NULL"' or $NotifyFunction = 'NULL'"!][!//
[!VAR "NotifyFunction" = "'(Icu_17_GtmCcu6_NotifiPtrType)(0)'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "$NotifyFunction != '(Icu_17_GtmCcu6_NotifiPtrType)(0)'"!][!//
extern void [!"$NotifyFunction"!] (void);
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//

#define ICU_17_GTMCCU6_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#define ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!LOOP "./IcuConfigSet/*"!][!//
[!NOCODE!]
[!VAR "WakeupFlag" = "'false'"!][!//
[!LOOP "IcuChannel/*"!][!//
[!IF "./IcuWakeupCapability ='true'"!][!//
[!VAR "WakeupFlag" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//

[!IF "$WakeupFlag = 'false' and $ReportWakeupSource = 'true'"!][!//
[!ERROR!][!//
Error: Wrong Configuration. You have not configured any channel for wakeup capability  in Configuration [!"node:name(.)"!]
but IcuReportWakeupSource is set to true.In Post Build configuration, if IcuReportWakeupSource is set and One configuration has 
wakeup capable channel then all the configurations should have atleast one wakeup capable channel.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!LOOP "./IcuConfigSet/*"!][!//
[!VAR "IcuIndex" = "@index"!][!//
[!VAR "EruModuleLookUp" = "num:i(0)"!][!//
[!VAR "CcuModuleLookUp" = "num:i(0)"!][!//
/* 
   Channel Configuration Instance [!"node:name(.)"!]
*/
static const Icu_17_GtmCcu6_ChannelConfigType Icu_kChannelConfig[!"@index"!][ ] =
{
[!VAR "MaxChannels"= "num:i(count(IcuChannel/*))"!][!//
[!FOR "ChannelId" = "num:i(1)" TO "num:i($MaxChannels)"!][!//
[!SELECT "IcuChannel/*[IcuChannelId = num:i($ChannelId) - num:i(1)]"!][!//
  
  {
[!NOCODE!]
[!VAR "WakeupValue" = "'ICU_NOT_WAKEUPCAPABLE'"!][!//
[!VAR "MeasMode" = "./IcuMeasurementMode"!][!//
[!VAR "MeasModeValue" = "$MeasMode"!][!//
[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!VAR "SafetyType" = "./IcuSignalType"!][!//
[!ELSE!][!//
[!VAR "SafetyType" = "'ICU_QM_SIGNAL'"!][!//
[!ENDIF!][!//
[!VAR "CcuChannelConnection" = "'0U'"!][!//
[!ASSERT "node:refexists(./IcuAssignedHwUnit) = 'true'"!][!//
ERROR: ICU: AssignedHwUnit not configured
[!ENDASSERT!][!//
[!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!//
[!VAR "ChannelLocation" = "node:name(node:ref(./IcuAssignedHwUnit))"!][!//
[!IF "contains($nodepath, "GtmConfiguration") = 'true'"!][!//
[!CALL "CG_GetIndex","M_nodename" = "IcuAssignedHwUnit","M_ConfigSetIndex" = "$IcuIndex"!][!//
[!ELSEIF "contains($nodepath, "EruConfiguration") = 'true'"!][!//
[!CALL "CG_EruGetIndex","M_Erunodename" = "IcuAssignedHwUnit","M_EruConfigSetIndex" = "$IcuIndex"!][!//
[!ELSEIF "contains($nodepath, "CcuConfiguration") = 'true'"!][!//
[!CALL "CG_CcuGetIndex","M_Ccunodename" = "IcuAssignedHwUnit","M_CcuConfigSetIndex" = "$IcuIndex"!][!//
[!ENDIF!][!//
[!IF "contains($ChannelLocation, "ERU") = 'true'"!][!//
[!VAR "ChannelNumber" = "text:split($ChannelLocation, 'RU')[position()-1 = 1]"!][!//
[!VAR "SetPosition" = "($ChannelNumber)"!][!//
[!ASSERT "bit:and($EruModuleLookUp, bit:shl(1,$SetPosition)) = 0"!][!//
ERROR: ICU: ERU[!"$ChannelNumber"!] is configured more than once in [!"node:name(./../..)"!][!//
[!ENDASSERT!][!//
[!VAR "EruModuleLookUp" = "bit:bitset($EruModuleLookUp, $SetPosition)"!][!//
[!ENDIF!][!// 
[!IF "contains($nodepath, "CcuConfiguration") = 'true'"!][!//
[!VAR "ChannelNumber" = "text:split($ChannelLocation, 'c6')[position()-1 = 1]"!][!//
[!VAR "CcuKernalName" = "node:name(node:ref(./IcuAssignedHwUnit)/../../..)"!][!//
[!VAR "CcuKernalNumber" = "text:split($CcuKernalName, 'cu6')[position()-1 = 1]"!][!//
[!VAR "SetPosition" = "num:i(num:add(num:i($ChannelNumber), num:i(bit:shl($CcuKernalNumber, 2))))"!][!//
[!ASSERT "bit:and($CcuModuleLookUp, bit:shl(1,$SetPosition)) = 0"!][!//
ERROR: ICU: CCU6[!"$CcuKernalNumber"!] CC6[!"$ChannelNumber"!] is configured more than once!][!//
[!ENDASSERT!][!//
[!VAR "CcuModuleLookUp" = "bit:bitset($CcuModuleLookUp, $SetPosition)"!][!//
[!ENDIF!][!// 
[!VAR "GtmConfigIndex" = "num:i(0)"!][!//
[!VAR "ModuleConfigName1" = "substring-after($nodepath, "McuModuleConfiguration/")"!][!//
[!VAR "ModuleConfigName" = "substring-before($ModuleConfigName1, "/")"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!LOOP "McuModuleConfiguration/*"!][!//
   [!IF "$ModuleConfigName = @name"!][!//
   [!VAR "ModuleConfigIndex" = "num:i(@index)"!][!//
   [!VAR "GtmConfigIndex" = "$ModuleConfigIndex"!][!//
   [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!//
[!//
[!IF "$MeasModeValue = 'ICU_MODE_SIGNAL_EDGE_DETECT'"!][!//
[!// If any of the channel needs to be wakeup capable then 
[!// Gtm Clock should have the capability to disable Gtm Clock Sleep mode
[!// when sleep mode is requested.
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!// Access Gtm Clock Sleep Mode
[!VAR "GtmSelectIndex" = "concat('McuModuleConfiguration/*[',$GtmConfigIndex+1,']')"!][!//
[!SELECT "node:ref($GtmSelectIndex)"!][!//
[!VAR "GtmSleepMode" = "./GtmConfiguration/*[1]/GtmGeneral/GtmSleepMode"!][!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
[!VAR "Wakeup" = "./IcuWakeupCapability"!][!//
[!IF "$Wakeup = 'true'"!][!//
[!VAR "WakeupValue" = "'ICU_WAKEUPCAPABLE'"!][!//
[!ENDIF!][!//
    [!VAR "Wakeupreference" = "''"!][!//
    [!IF "$Wakeup = 'true'"!][!//
      [!IF "node:exists(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]) = 'true'"!][!//         
        [!IF "string-length(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]) > 0"!][!//
            [!VAR "Wakeupreference" = "node:name(node:ref(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]))"!][!//
        [!ENDIF!][!//
      [!ENDIF!][!//        
      [!//Wakeup will be configured only if Report Wakeup is enabled
      [!IF "node:value(../../../../IcuGeneral/IcuReportWakeupSource) = 'true'"!][!//
        [!ASSERT "not(string-length($Wakeupreference) = 0)" ,"Wrong Configuration: Wakeup reference not provided for a wakeup capable channel"!]
      [!ENDIF!][!//
    [!ENDIF!][!//
[!ASSERT "not($Wakeup = 'true' and $GtmSleepMode = 'GTM_SLEEP_ENABLE')"!][!// 
Configuration Error: Gtm Clock is not configured with Clock Sleep Disable request in Mcu ConfigSet[!"$GtmConfigIndex"!]. But ICU is having a Wakeup capable channel in Icu ConfigSet [!"$IcuIndex"!] in channel [!"@index"!] which refers to resource from Mcu Config Set [!"$GtmConfigIndex"!] . Change Gtm Clock Configuration
[!ENDASSERT!]
[!ENDIF!][!//

[!VAR "BufferKindValue" = "'0'"!][!//
[!VAR "MeasKindValue" = "'0U'"!][!//
[!IF "$MeasMode = 'ICU_MODE_SIGNAL_MEASUREMENT'"!][!//
[!VAR "MeasKind" = "./IcuSignalMeasurement/*[1]/IcuSignalMeasurementProperty"!][!//
[!IF "$SafetyType = 'ICU_ASIL_SIGNAL'"!][!//
[!VAR "BufferKind" = "./IcuSignalMeasurement/*[1]/IcuDutycycleBufferMarker"!][!//
[!VAR "BufferKindValue" = "$BufferKind"!][!//
[!ENDIF!][!//
[!ASSERT "not(string-length($MeasKind) = 0)","Wrong Configuration:Signal Measurement Property is not provided for a Signal Measurement Channel"!][!//
[!VAR "MeasKindValue" = "$MeasKind"!][!//
[!ELSEIF "$MeasMode = 'ICU_MODE_TIMESTAMP'"!][!//
[!VAR "MeasKind" = "./IcuTimestampMeasurement/*[1]/IcuTimestampMeasurementProperty"!][!//
[!IF "$SafetyType = 'ICU_ASIL_SIGNAL'"!][!//
[!VAR "BufferKind" = "./IcuTimestampMeasurement/*[1]/IcuTimestampBufferMarker "!][!//
[!VAR "BufferKindValue" = "$BufferKind"!][!//
[!ENDIF!][!//
[!ASSERT "not(string-length($MeasKind) = 0)","Wrong Configuration:Timestamp Measurement Property is not provided for a Timestamp Channel"!][!//
[!VAR "MeasKindValue" = "$MeasKind"!][!//
[!ELSE!][!//
[!VAR "BufferKindValue" = "'0'"!][!//
[!ENDIF!][!//
[!//
[!//
[!VAR "Edge" = "./IcuDefaultStartEdge"!][!//
[!VAR "EdgeValue" = "$Edge"!][!//
[!//
[!//   
[!ASSERT "node:refexists(./IcuAssignedHwUnit) = 'true'"!][!//
ERROR: ICU: AssignedHwUnit not configured
[!ENDASSERT!][!//
[!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!]
[!VAR "nodeval" = "node:name(node:ref(./IcuAssignedHwUnit))"!]

[!VAR "val" = "num:i(0)"!][!//
[!IF "contains($nodepath,'TimChannel') = 'true'"!][!//
[!CALL "CG_GetHwUnitGtmVal","nodepath" = "$nodepath"!][!//
[!VAR "Cell" = "$GlobalChannelNumber"!]
[!VAR "CellOption" = "'ICU_GTM_OPTION'"!]
[!ELSEIF "contains($nodepath,'EruConfiguration') = 'true'"!]
[!ASSERT "(node:ref(./IcuAssignedHwUnit)/EruChannelUsage = 'USED_BY_ICU_DRIVER')"!][!//
ERROR: ICU: EruChannelUsage of [!"node:path(node:ref(./IcuAssignedHwUnit))"!] is not configured for Icu. Please configure EruChannelUsage to "USED_BY_ICU_DRIVER". 
[!ENDASSERT!][!//   
[!VAR "line" = "node:ref(./IcuAssignedHwUnit)/EruInputLine"!][!//
[!ASSERT "contains($line, 'PORT') = 'true'"!][!//
ERROR: ICU: ERU Line not selected from the Available Port Configuration, Please Change the ERU Input Line Configuration
[!ENDASSERT!][!//
[!VAR "line" = "substring($line,11,1)"!][!//
[!VAR "Cell" = "substring($nodeval,4,1)"!][!//
[!VAR "Cell" = "concat('ICU_ASSIGN_ERU',$Cell)"!][!//
[!VAR "Cell" = "concat($Cell,'_PINLINE',$line)"!][!//
[!VAR "CellOption" = "'ICU_ERU_OPTION'"!]
[!ELSEIF "contains($nodepath,'CcuConfiguration') = 'true'"!]
[!VAR "CellOption" = "'ICU_CCU_OPTION'"!]
[!VAR "CcuChannelNumber" = "text:toupper($nodeval)"!][!//
[!VAR "KernalNodeName" = "node:name(node:ref(./IcuAssignedHwUnit)/../../..)"!]
[!VAR "CcuKernalNumber" = "text:toupper($KernalNodeName)"!][!//
[!VAR "Cell" = "concat('ICU_',$CcuKernalNumber, '_', $CcuChannelNumber)"!][!//
[!VAR "CcuChannelInput" = "node:ref(./IcuAssignedHwUnit)/CCChannelInputSelection"!][!//
[!VAR "CcuChannelInput" = "text:split($CcuChannelInput, '_')[position()-1 = 0]"!]
[!VAR "CcuChannelConnection" = "concat('ICU_CCU6_', $CcuChannelInput)"!][!//
[!ENDIF!][!//
[!//
[!//
[!VAR "NotifyFunction" = "''"!][!//
[!IF "$MeasMode = 'ICU_MODE_TIMESTAMP'"!][!//
[!IF "node:exists(./IcuTimestampMeasurement/*[1]/IcuTimestampNotification/*[1]) = 'true'"!][!// 
[!VAR "NotifyFunction" = "./IcuTimestampMeasurement/*[1]/IcuTimestampNotification/*[1]"!][!//
[!ELSE!][!// 
[!VAR "NotifyFunction" = "''"!][!//
[!ENDIF!][!// 
[!ELSEIF "$MeasMode = 'ICU_MODE_SIGNAL_EDGE_DETECT'"!][!//
[!IF "node:exists(./IcuSignalEdgeDetection/*[1]/IcuSignalNotification/*[1]) = 'true'"!][!// 
[!VAR "NotifyFunction" = "./IcuSignalEdgeDetection/*[1]/IcuSignalNotification/*[1]"!][!//
[!ELSE!][!// 
[!VAR "NotifyFunction" = "''"!][!//
[!ENDIF!][!// 
[!ENDIF!][!//
[!IF "string-length($NotifyFunction) = 0 or $NotifyFunction = '"NULL"' or $NotifyFunction = 'NULL' "!][!//
[!VAR "NotifyFunction" = "'(Icu_17_GtmCcu6_NotifiPtrType)0'"!][!//
[!ELSE!][!//
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
[!ASSERT "num:isnumber($NotifyFunction)= 'true'"!][!//
ERROR: Under LOADABLE option ICU Notification should be entered as an address. Change notification of [!"node:name(.)"!]
[!ENDASSERT!][!//
[!VAR "NotifyFunction" = "concat('(Icu_17_GtmCcu6_NotifiPtrType)',$NotifyFunction,'U')"!]
[!ELSE!][!//
[!ASSERT "num:isnumber($NotifyFunction)!= 'true'"!][!//
ERROR: Under SELECTABLE option ICU Notification should be entered as a function name. Change notification of [!"node:name(.)"!]
[!ENDASSERT!][!//
[!VAR "NotifyFunction" = "concat('&',$NotifyFunction)"!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
      /* ICU Channel [!"IcuChannelId"!] */
    [!"$NotifyFunction"!],/*Notification-function name*/
    {
      [!"$MeasModeValue"!],/*Measurement Mode*/
      [!"$EdgeValue"!],/*Default Start Edge */
      [!"$MeasKindValue"!],/*Measurement Property*/
      [!"$WakeupValue"!],/*Wakeup capability*/
      [!"$Cell"!],/* Assigned Hardware Resource Number */
      (uint8)[!"$CellOption"!], /* Assigned Hw Unit */
      [!"$CcuChannelConnection"!], /* CCU connection */
      [!"$SafetyType"!], /* Safety ON or OFF*/        
      0U,/* Reserved */
    #if (ICU_SAFETY_ENABLE == STD_ON)   
     [!"$BufferKindValue"!]U,/*Buffer Marker value */
    #endif   
[!NOCODE!][!//
[!VAR "IcuMcuClockRef" = "node:path(node:ref(./IcuAssignedHwUnit))"!][!//
[!IF "contains($IcuMcuClockRef, '/Tim/') = 'true'"!][!//
[!VAR "TimChannelInputSelectValue" ="node:ref($IcuMcuClockRef)/TimChannelGeneral/TimChannelInputSelect"!][!//
[!VAR "TimChannelClockSelectValue" ="node:ref($IcuMcuClockRef)/TimChannelGeneral/TimChannelClockSelect"!][!//
[!VAR "TimChannelGpr0InputSelectValue" ="node:ref($IcuMcuClockRef)/TimChannelGeneral/TimChannelGpr0InputSelect"!][!//
[!VAR "TimChFilterTimeForRisingEdgeValue" ="node:ref($IcuMcuClockRef)/TimChannelFilterConfig/TimChFilterTimeForRisingEdge"!][!//
[!VAR "TimChFilterTimeForFallingEdgeValue" ="node:ref($IcuMcuClockRef)/TimChannelFilterConfig/TimChFilterTimeForFallingEdge"!][!//
[!VAR "TimChannelFilterEnableValue" ="node:ref($IcuMcuClockRef)/TimChannelFilterConfig/TimChannelFilterEnable"!][!//
[!VAR "TimChFilterCounterFreqSelectValue" ="node:ref($IcuMcuClockRef)/TimChannelFilterConfig/TimChFilterCounterFreqSelect"!][!//
[!VAR "TimChFilterModeForRisingEdgeValue" ="node:ref($IcuMcuClockRef)/TimChannelFilterConfig/TimChFilterModeForRisingEdge"!][!//
[!VAR "TimChFilterModeForFallingEdgeValue" ="node:ref($IcuMcuClockRef)/TimChannelFilterConfig/TimChFilterModeForFallingEdge"!][!//
[!VAR "TimInterruptModeValue" ="node:ref($IcuMcuClockRef)/TimChannelInterrupt/TimInterruptMode"!][!//
[!VAR "TimInterruptModeValue" ="node:ref($IcuMcuClockRef)/TimChannelInterrupt/TimInterruptMode "!][!//
[!ASSERT "($TimChannelGpr0InputSelectValue = 'TIMEBASE_TBU_TS0' or $TimChannelGpr0InputSelectValue = 'TIMEBASE_TBU_TS1' or $TimChannelGpr0InputSelectValue = 'TIMEBASE_TBU_TS2')"!][!// 
Configuration Error: In case of TIEM mode inputs can only be TIMEBASE_TBU_TS0,TIMEBASE_TBU_TS1,TIMEBASE_TBU_TS2
[!ENDASSERT!]
[!IF "$TimChannelFilterEnableValue = 'true'"!][!//
[!VAR "FilterValue" = "'1U'"!][!//
[!ELSE!][!//
[!VAR "FilterValue" = "'0U'"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "TimChannelClockSelectValue" = "'0U'"!][!//
[!VAR "TimChannelInputSelectValue" = "'INPUT_OF_CURRENT_TIM_CHANNEL'"!][!//

[!VAR "TimChannelGpr0InputSelectValue" = "'0U'"!][!//
[!VAR "TimChFilterTimeForRisingEdgeValue" = "num:i(0)"!][!//
[!VAR "TimChFilterTimeForFallingEdgeValue" = "num:i(0)"!][!//
[!VAR "TimInterruptModeValue" = "'0U'"!][!//
[!VAR "FilterValue" = "'0U'"!][!//
[!VAR "TimChFilterCounterFreqSelectValue" = "'0U'"!][!//
[!VAR "TimChFilterModeForRisingEdgeValue" = "'0U'"!][!//
[!VAR "TimChFilterModeForFallingEdgeValue" = "'0U'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
     [!"$TimChFilterTimeForRisingEdgeValue"!]U,/* Filtering time for rising edge */
     [!"$TimChFilterTimeForFallingEdgeValue"!]U,/* Filtering time for falling edge */   
     [!"$TimInterruptModeValue"!],/* Filtering time for TIM interrupt mode */
     [!"$TimChannelClockSelectValue"!], /*Channel Clock Select */
     [!"$TimChannelGpr0InputSelectValue"!],  /* Gpr0 input select for the Tim channel */   
     [!"$FilterValue"!], /* Enables Filter for the Channel */
   /*Decides the filter Counter frequency for the TIM Channel */
     [!"$TimChFilterCounterFreqSelectValue"!],
   /*Decides the filter mode for rising Edge of the TIM Channel Input */
     [!"$TimChFilterModeForRisingEdgeValue"!],
   /*Decides the filter mode for falling Edge of the TIM Channel Input */ 
     [!"$TimChFilterModeForFallingEdgeValue"!], 
     /*Input channel select : current chl or previous chl */
   [!"$TimChannelInputSelectValue"!], 
    }
  }[!IF "$ChannelId != $MaxChannels"!],[!ENDIF!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!/* Validate the CCU channels in MCU which are configured for USED_BY_ICU_DRIVER but are not really used
     for ICU channel 
*/!][!NOCODE!][!//
[!VAR "CurrentConfigSet" = "@index"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!SELECT "McuModuleConfiguration/*[num:i($CurrentConfigSet) + 1]"!][!//
[!IF "node:exists(CcuConfiguration/*[1])"!][!//
[!VAR "Ccu6Count" = "num:i(0)"!][!//
[!LOOP "CcuConfiguration/*[1]/Ccu6/*"!][!//
[!VAR "IsCcuRequired" = "num:i(0)"!][!//
[!VAR "CcCount" = "num:i(0)"!][!//
[!LOOP "T12/Cc6/*"!][!//
[!IF "bit:and($CcuModuleLookUp, bit:shl(1, (($Ccu6Count * 4) + $CcCount))) > 0"!][!//
[!VAR "IsCcuRequired" = "num:i(1)"!][!//  
[!ASSERT "../../../General/Ccu6ModuleUsage = 'USED_BY_ICU_DRIVER'"!][!//
Configuration Error: CC6[!"$CcCount"!] of CCU6[!"$Ccu6Count"!] in MCU config set [!"$CurrentConfigSet"!] is used for ICU but Ccu6ModuleUsage is not 
configured to USED_BY_ICU_DRIVER. This has to be changed.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!VAR "CcCount" = "num:i($CcCount + 1)"!][!//
[!ENDLOOP!][!//
[!IF "$IsCcuRequired = num:i(0)"!][!//
[!ASSERT "General/Ccu6ModuleUsage != 'USED_BY_ICU_DRIVER'"!][!//
Configuration Error: None of the Channel in CCU6[!"$Ccu6Count"!] in MCU config set [!"$CurrentConfigSet"!] is used for ICU but Ccu6ModuleUsage is  
configured to USED_BY_ICU_DRIVER. This has to be changed.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!VAR "Ccu6Count" = "num:i($Ccu6Count + 1)"!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//

};

[!IF "$ReportWakeupSource = 'true'"!][!//
static const Icu_ChannelWakeupType Icu_kChannelWakeup[!"@index"!][ ] =

{
[!FOR "ChannelId" = "num:i(1)" TO "num:i($MaxChannels)"!][!//
[!SELECT "IcuChannel/*[IcuChannelId = num:i($ChannelId) - num:i(1)]"!][!//
[!//LOOP "IcuChannel/*"!][!//
[!NOCODE!]
[!VAR "Wakeup" = "'false'"!][!//
[!IF "node:exists(./IcuWakeupCapability) ='true'"!][!//
[!VAR "Wakeup" = "./IcuWakeupCapability"!][!//
[!ENDIF!][!//
[!VAR "MeasMode" = "./IcuMeasurementMode"!][!//
[!VAR "WakeupReason" = "'0'"!][!//
[!VAR "WakeupComment" = "'Not applicable'"!][!//
[!VAR "Wakeupreference" = "''"!][!//
[!IF "$Wakeup = 'true'"!][!//
[!IF "$MeasMode = 'ICU_MODE_SIGNAL_EDGE_DETECT'"!][!//
[!IF "node:exists(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]) = 'true'"!][!//         
[!IF "string-length(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]) > 0"!][!//
[!VAR "Wakeupreference" = "node:name(node:ref(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1]))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ASSERT "not(string-length($Wakeupreference) = 0)" ,"Wrong Configuration: Wakeup reference not provided for a wakeup capable channel"!]
[!IF "string-length($Wakeupreference) > 0"!][!//
[!VAR "WakeupReason" = "node:ref(./IcuWakeup/*[1]/IcuChannelWakeupInfo/*[1])/EcuMWakeupSourceId"!][!//
[!ELSE!][!//
[!VAR "WakeupReason" = "num:i(0)"!][!//
[!ENDIF!][!//
[!VAR "chindex" = "num:i($ChannelId) - num:i(1)"!][!//
[!VAR "WakeupComment" = "concat('WakeupSourceId Value for Channel ',num:i($chindex))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!/*IF "$Wakeup = 'true'"*/!][!//
[!/*IF "$MeasMode = 'ICU_MODE_SIGNAL_EDGE_DETECT'"*/!][!//
    {
        [!"$WakeupReason"!]U/*[!"$WakeupComment"!]*/
    }[!IF "$ChannelId != $MaxChannels"!],[!ENDIF!]
[!/* ENDIF */!][!//
[!/* ENDIF */!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

};
[!ENDIF!][!//

[!//
[!//






[!VAR "Counter0" = "num:i(0)"!][!//
[!VAR "Counter1" = "num:i(0)"!][!//
[!VAR "Counter2" = "num:i(0)"!][!//
[!VAR "Counter3" = "num:i(0)"!][!//
/*
typedef struct {
uint8 PhysicalChannelMap;
uint8 ChannelIndexMap;
}Icu_17_GtmCcu6_MapType; */


static const Icu_17_GtmCcu6_MapType Icu_17_GtmCcu6_MappingIndex[!"@index"!][ICU_MAX_CHANNELS] =
{
[!VAR "MaxChannels"= "num:i(count(IcuChannel/*))"!][!//
[!VAR "EdDeAsilGtm" = "0"!][!//
[!VAR "EdDeAsilCcu" = "0"!][!//
[!VAR "EdDeQm" = "0"!][!//
[!VAR "SgMeAsilGtm" = "0"!][!//
[!VAR "SgMeAsilCcu" = "0"!][!//
[!VAR "SgMeQm" = "0"!][!//
[!VAR "TiStAsilGtm" = "0"!][!//
[!VAR "TiStQm" = "0"!][!//
[!VAR "EdCnAsilGtm" = "0"!][!//
[!VAR "EdCnQm" = "0"!][!//

[!FOR "ChannelId" = "num:i(1)" TO "num:i($MaxChannels)"!][!//

[!SELECT "IcuChannel/*[IcuChannelId = num:i($ChannelId) - num:i(1)]"!][!//

[!NOCODE!]

[!/* to store each of the counter 10 variables are required
1. Edge detection, wakeup capable = true, Asil channel, Gtm
*/!]
[!VAR "IndexChannel" = "1"!][!//

[!VAR "nodepath" = "node:path(node:ref(./IcuAssignedHwUnit))"!]
[!VAR "nodeval" = "node:name(node:ref(./IcuAssignedHwUnit))"!]

[!VAR "val" = "num:i(0)"!][!//
[!IF "contains($nodepath,'TimChannel') = 'true'"!][!//
[!CALL "CG_GetHwUnitGtmVal","nodepath" = "$nodepath"!][!//
[!VAR "Cell" = "$GlobalChannelNumber"!]
[!VAR "CellOption" = "'ICU_GTM_OPTION'"!]
[!ELSEIF "contains($nodepath,'EruConfiguration') = 'true'"!]
[!ASSERT "(node:ref(./IcuAssignedHwUnit)/EruChannelUsage = 'USED_BY_ICU_DRIVER')"!][!//
ERROR: ICU: EruChannelUsage of [!"node:path(node:ref(./IcuAssignedHwUnit))"!] is not configured for Icu. Please configure EruChannelUsage to "USED_BY_ICU_DRIVER". 
[!ENDASSERT!][!//   
[!VAR "line" = "node:ref(./IcuAssignedHwUnit)/EruInputLine"!][!//
[!ASSERT "contains($line, 'PORT') = 'true'"!][!//
ERROR: ICU: ERU Line not selected from the Available Port Configuration, Please Change the ERU Input Line Configuration
[!ENDASSERT!][!//
[!VAR "line" = "substring($line,11,1)"!][!//
[!VAR "Cell" = "substring($nodeval,4,1)"!][!//
[!VAR "Cell" = "concat('ICU_ASSIGN_ERU',$Cell)"!][!//
[!VAR "Cell" = "concat($Cell,'_PINLINE',$line)"!][!//
[!VAR "CellOption" = "'ICU_ERU_OPTION'"!]
[!ELSEIF "contains($nodepath,'CcuConfiguration') = 'true'"!]
[!VAR "CellOption" = "'ICU_CCU_OPTION'"!]
[!VAR "CcuChannelNumber" = "text:toupper($nodeval)"!][!//
[!VAR "KernalNodeName" = "node:name(node:ref(./IcuAssignedHwUnit)/../../..)"!]
[!VAR "CcuKernalNumber" = "text:toupper($KernalNodeName)"!][!//
[!VAR "Cell" = "concat('ICU_',$CcuKernalNumber, '_', $CcuChannelNumber)"!][!//
[!VAR "CcuChannelInput" = "node:ref(./IcuAssignedHwUnit)/CCChannelInputSelection"!][!//
[!VAR "CcuChannelInput" = "text:split($CcuChannelInput, '_')[position()-1 = 0]"!]
[!VAR "CcuChannelConnection" = "concat('ICU_CCU6_', $CcuChannelInput)"!][!//
[!ENDIF!][!//

[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!VAR "SafetyType" = "./IcuSignalType"!][!//
[!IF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_GTM_OPTION'"!][!//
[!VAR "Counter0" = "$Counter0 + 1"!][!//
[!ELSEIF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_CCU_OPTION'"!][!//
[!VAR "Counter1" = "$Counter1 + 1"!][!//
[!ELSEIF "$SafetyType = 'ICU_QM_SIGNAL'"!][!//
[!VAR "Counter2" = "$Counter2 + 1"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "Counter2" = "$Counter2 + 1"!][!//
[!ENDIF!][!//

[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!ASSERT "not($SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_ERU_OPTION')"!][!//  
Error: ERU channels can not be mapped to ASIL signals
[!ENDASSERT!]
[!ENDIF!][!//

[!IF "./IcuMeasurementMode = 'ICU_MODE_SIGNAL_EDGE_DETECT' and ./IcuWakeupCapability = 'true'"!][!//
  [!IF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_GTM_OPTION'"!][!//
  [!VAR "EdDeAsilGtm" = "num:i($EdDeAsilGtm + 1)"!][!//
  [!VAR "IndexChannel" = "$EdDeAsilGtm"!][!//
  [!VAR "CommentIndex" = "'Wakeup capable, GTM, ASIL Signal'"!][!//
  [!ELSEIF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_CCU_OPTION'"!][!//
  [!VAR "EdDeAsilCcu" = "num:i($EdDeAsilCcu + 1)"!][!//
  [!VAR "IndexChannel" = "$EdDeAsilCcu"!][!//
  [!VAR "CommentIndex" = "'Wakeup capable, CCU6, ASIL Signal'"!][!//
  [!ELSE!][!//
  [!VAR "EdDeQm" = "num:i($EdDeQm + 1)"!][!//
  [!VAR "IndexChannel" = "$EdDeQm"!][!//
  [!VAR "CommentIndex" = "'Wakeup capable, QM Signal'"!][!//
  [!ENDIF!][!//
[!ELSEIF "./IcuMeasurementMode = 'ICU_MODE_SIGNAL_MEASUREMENT'"!][!//
  [!IF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_GTM_OPTION'"!][!//
  [!VAR "SgMeAsilGtm" = "num:i($SgMeAsilGtm + 1)"!][!//
  [!VAR "IndexChannel" = "$SgMeAsilGtm"!][!//
  [!VAR "CommentIndex" = "'Signal Measurement, GTM, ASIL Signal'"!][!//
  [!ELSEIF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_CCU_OPTION'"!][!//
  [!VAR "SgMeAsilCcu" = "num:i($SgMeAsilCcu + 1)"!][!//
  [!VAR "IndexChannel" = "$SgMeAsilCcu"!][!//
  [!VAR "CommentIndex" = "'Signal Measurement, CCU6, ASIL Signal'"!][!//
  [!ELSE!][!//
  [!VAR "SgMeQm" = "num:i($SgMeQm + 1)"!][!//
  [!VAR "IndexChannel" = "$SgMeQm"!][!//
  [!VAR "CommentIndex" = "'Signal Measurement, QM Signal'"!][!//
  [!ENDIF!][!// 
[!ELSEIF "./IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'"!][!//
  [!IF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_GTM_OPTION'"!][!//
  [!VAR "TiStAsilGtm" = "num:i($TiStAsilGtm + 1)"!][!//
  [!VAR "IndexChannel" = "$TiStAsilGtm"!][!//
  [!VAR "CommentIndex" = "'Time Stamp, ASIL Signal'"!][!//
  [!ELSE!][!//
  [!VAR "TiStQm" = "num:i($TiStQm + 1)"!][!//
  [!VAR "IndexChannel" = "$TiStQm"!][!//
  [!VAR "CommentIndex" = "'Time Stamp, QM Signal'"!][!//
  [!ENDIF!][!//
[!ELSEIF "./IcuMeasurementMode = 'ICU_MODE_EDGE_COUNTER'"!][!//
  [!IF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_GTM_OPTION'"!][!//
  [!VAR "EdCnAsilGtm" = "num:i($EdCnAsilGtm + 1)"!][!//
  [!VAR "IndexChannel" = "$EdCnAsilGtm"!][!//
  [!VAR "CommentIndex" = "'Edge Count, ASIL Signal'"!][!//
  [!ELSE!][!//
  [!VAR "EdCnQm" = "num:i($EdCnQm + 1)"!][!//
  [!VAR "IndexChannel" = "$EdCnQm"!][!//
  [!VAR "CommentIndex" = "'Edge Count, QM Signal'"!][!//
  [!ENDIF!][!//
[!ELSE!][!//
[!VAR "IndexChannel" = "1"!][!//
[!VAR "CommentIndex" = "'Edge Detection, Indexing not required'"!][!//
[!ENDIF!][!//
  


[!ENDNOCODE!][!//
  /*[!"node:name(.) "!]*/
  {   
[!IF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_GTM_OPTION'"!][!//
    [!"num:i(($Counter0) - 1)"!]U,
[!ELSEIF "$SafetyType = 'ICU_ASIL_SIGNAL' and $CellOption = 'ICU_CCU_OPTION'"!][!//
    [!"num:i(($Counter1)- 1)"!]U,
[!ELSEIF "$SafetyType = 'ICU_QM_SIGNAL'"!][!//
    [!"num:i(($Counter2)- 1)"!]U,
[!ENDIF!][!//
    /* [!"$CommentIndex"!] */
    [!"num:i($IndexChannel - 1)"!]U
  }[!IF "$ChannelId != $MaxChannels"!],[!ENDIF!]

[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDLOOP!][!//
[!ENDSELECT!][!//



const Icu_17_GtmCcu6_ConfigType Icu_ConfigRoot[] =
{
[!FOR "ModuleId" = "num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "IcuConfigSet/*[num:i($ModuleId)]"!][!//
[!NOCODE!][!//
[!IF "$IcuSafetyEnabled = 'true'"!][!//
[!VAR "TimestampQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_TIMESTAMP'and IcuSignalType='ICU_QM_SIGNAL']))"!][!//
[!VAR "SigmeasQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'and IcuSignalType='ICU_QM_SIGNAL']))"!][!//
[!VAR "EdgecountQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'and IcuSignalType='ICU_QM_SIGNAL']))"!][!//
[!VAR "SignalEdgeQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'and IcuSignalType='ICU_QM_SIGNAL']))"!][!//

[!VAR "TimestampAsilGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_TIMESTAMP'and IcuSignalType='ICU_ASIL_SIGNAL' and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "TimestampAsilCcu6Channels" = "num:i(0)"!][!//

[!VAR "SigmeasAsilGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'and IcuSignalType='ICU_ASIL_SIGNAL'and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "SigmeasAsilCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'and IcuSignalType='ICU_ASIL_SIGNAL'and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//

[!VAR "EdgecountAsilGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'and IcuSignalType='ICU_ASIL_SIGNAL'and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "EdgecountAsilCcu6Channels" = "num:i(0)"!][!//

[!VAR "SignalEdgeAsilGtmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'and IcuSignalType='ICU_ASIL_SIGNAL'and contains(node:path(node:ref(./IcuAssignedHwUnit)), "GtmConfiguration") = 'true']))"!][!//
[!VAR "SignalEdgeAsilCcu6Channels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'and IcuSignalType='ICU_ASIL_SIGNAL'and contains(node:path(node:ref(./IcuAssignedHwUnit)), "CcuConfiguration") = 'true']))"!][!//

[!ELSE!][!//
[!VAR "TimestampQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_TIMESTAMP']))"!][!//
[!VAR "SigmeasQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT']))"!][!//
[!VAR "EdgecountQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_EDGE_COUNTER']))"!][!//
[!VAR "SignalEdgeQmChannels" = "num:i(count(IcuChannel/*[IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT']))"!][!//
[!ENDIF!][!//
[!CALL "CC_IcuEruChannels","ModuleId" = "$ModuleId"!][!//
[!ENDNOCODE!][!//
  
  {
    [!IF "$IcuSafetyEnabled = 'true'"!][!//
    [!NOCODE!][!//
    [!VAR "Marker" = "num:i(0)"!][!//
    [!VAR "IcuModuleId" = "num:i(122)"!][!//
    [!VAR "Marker" = "num:inttohex(bit:or($Marker,bit:shl($IcuModuleId,16)))"!][!//
    [!ENDNOCODE!][!// 
    #if (ICU_SAFETY_ENABLE == STD_ON)
    /* Safety Marker */    
    [!"$Marker"!]U,
     #endif 
    [!ENDIF!][!//
[!AUTOSPACING!][!//  
    /*Pointer to channel configuration set */
    &Icu_kChannelConfig[!"string($ModuleId - num:i(1))"!][0],
  
  /* Pointer to Phsycial channel mapping set */
  &Icu_17_GtmCcu6_MappingIndex[!"string($ModuleId - num:i(1))"!][0],
  
    #if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
    &Icu_kChannelWakeup[!"string($ModuleId - num:i(1))"!][0],
    #endif
    #if (ICU_ERU_SIGEDGE_USED == STD_ON)
    {
[!IF "$IcuEruChannelNum0 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum0"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum0"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum1 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum1"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum1"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum2 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum2"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum2"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum3 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum3"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum3"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum4 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum4"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum4"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum5 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum5"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum5"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum6 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum6"!],
[!ELSE!][!//
           [!"$IcuEruChannelNum6"!]U,
[!ENDIF!][!//
[!IF "$IcuEruChannelNum7 = 'ERU_REQLINE_UNUSED'"!][!//
           [!"$IcuEruChannelNum7"!]
[!ELSE!][!//
           [!"$IcuEruChannelNum7"!]U
[!ENDIF!][!//
    },
    #endif
    #if (ICU_CCU6_USED == STD_ON)
    /* T12ClkSelection -> Lower 3 bits (Bits 0 to 2)
       T12PrescalerEnabled -> Bit 3
       Ccu6SleepEnable -> Bit 4
       Initialized by ICU or not -> Bit 7. ICU Initialization -> 0, 
                                           Other Driver Initialization -> 1
    */
    
  {
[!CALL "CC_IcuCcuWakeupChannels","ModuleId" = "$ModuleId"!][!//     
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!SELECT "McuModuleConfiguration/*[num:i($ModuleId)]"!][!//
[!IF "node:exists(CcuConfiguration/*[1])"!][!//
[!VAR "CcuKernalLoopCount" = "num:i(0)"!][!//
[!LOOP "CcuConfiguration/*[1]/Ccu6/*"!][!//
[!IF "General/Ccu6ModuleUsage = 'USED_BY_ICU_DRIVER'"!][!//
[!VAR "T12Parameters" = "T12/General/T12ClkSelection"!][!//
[!IF "T12/General/T12PrescalerEnabled = 'true'"!][!//
[!VAR "T12Parameters" = "bit:bitset($T12Parameters, 3)"!][!//
[!ENDIF!][!//
[!IF "bit:getbit($IsCcuWakeupNeeded, $CcuKernalLoopCount) = num:i(1)"!][!//
[!VAR "T12Parameters" = "bit:bitset($T12Parameters, 4)"!][!//
[!ENDIF!][!//
      [!"$T12Parameters"!]U,  
[!ELSE!][!//
      ICU_CCU6X_UNUSED,
[!ENDIF!][!//
[!VAR "CcuKernalLoopCount" = "num:i($CcuKernalLoopCount + 1)"!][!//
[!ENDLOOP!][!//
[!ELSE!][!/* If in case CCU is not configured for the configured in the config set then
ICU_CCU6X_UNUSED will be generated for all the kernals
*/!][!FOR "Ccu6UnusedCount" = "0" TO "ecu:get('Ccu6.MaxKernals') - 1"!][!//
      ICU_CCU6X_UNUSED,
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDSELECT!][!//
    },
    #endif
    /*
     Enter the no of channels configured in the following order
     1. Number of Signal Edge Detection Channels.
     2. Number of Timestamp channels
     3. Number of EdgeCount Channels
     4. Number of Signal Measurement Channels.
    */
    {[!"$SignalEdgeQmChannels"!]U,[!"$TimestampQmChannels"!]U,[!"$EdgecountQmChannels"!]U,[!"$SigmeasQmChannels"!]U}
     [!IF "$IcuSafetyEnabled = 'true'"!][!//
   #if (ICU_SAFETY_ENABLE == STD_ON)    
   /* ASIL : GTM channels for each mode */
   ,{[!"$SignalEdgeAsilGtmChannels"!]U,[!"$TimestampAsilGtmChannels"!]U,[!"$EdgecountAsilGtmChannels"!]U,[!"$SigmeasAsilGtmChannels"!]U}
   /* ASIL : CCU6 channels for each mode */
   ,{[!"$SignalEdgeAsilCcu6Channels"!]U,[!"$TimestampAsilCcu6Channels"!]U,[!"$EdgecountAsilCcu6Channels"!]U,[!"$SigmeasAsilCcu6Channels"!]U}  
   #endif
    [!ENDIF!][!//
 }[!//
[!IF "$ModuleId!= $TotalConfig"!],[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

};

#define ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!ENDSELECT!][!//