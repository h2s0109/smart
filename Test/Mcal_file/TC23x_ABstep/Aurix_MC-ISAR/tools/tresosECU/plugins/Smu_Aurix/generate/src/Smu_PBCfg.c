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
**   $FILENAME   : Smu_PBCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\14 $                                                 **
**                                                                            **
**   $DATE       : 2015-12-01 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for Smu_PBCfg.c file                         **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
******************************************************************************/!]
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
**  FILENAME  :  Smu_PBCfg.c                                                 **
**                                                                            **
**  VERSION   : 0.0.4                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SMU configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Smu_Cfg.h"
#include "Mcal_Options.h"

[!NOCODE!][!//
[!INCLUDE "Smu.m"!][!//
[!ENDNOCODE!][!//

/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_START_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_START_SEC_POSTBUILDCFG
#include "MemMap.h"
#endif
[!SELECT "as:modconf('Smu')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SmuConfigSet/*))"!][!//

/* SMU Module Configuration */
const Smu_ConfigType Smu_ConfigRoot[[!"num:i($TotalConfig)"!]] = 
{
[!FOR "SmuId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SmuConfigSet/*[num:i($SmuId)]"!][!//
[!VAR "GroupId" = "num:i(0)"!][!//
  {
    /* FSP Cfg */
[!NOCODE!][!//      
[!VAR "FSP" = "num:i(0)"!][!//
[!CALL "CG_FSP_Value","MacInputVal" = "SmuFSPHandling/SmuFSPPrescaler1"!][!//
[!/* PRE1 bit is bit 0,1,2 */!][!//
[!VAR "FSP" = "bit:shl($OutMac_FSP,0)"!][!//
[!CALL "CG_FSP_Value","MacInputVal" = "SmuFSPHandling/SmuFSPPrescaler2"!][!//
[!/* PRE2 bit is bit 3,4 */!][!//
[!VAR "FSP" = "bit:shl($OutMac_FSP,3)+ $FSP"!][!//
[!CALL "CG_FSP_Value","MacInputVal" = "SmuFSPHandling/SmuFSPSignalingMode"!][!//
[!VAR "FSP" = "bit:shl($OutMac_FSP,5)+ $FSP"!][!//
[!CALL "CG_FSP_Value","MacInputVal" = "SmuFSPHandling/SmuPESOnFSP"!][!//
[!VAR "FSP" = "bit:shl($OutMac_FSP,7)+ $FSP"!][!//
[!VAR "FSD" = "SmuFSPHandling/SmuFSPFaultStateDuration"!][!//
[!VAR "FSP" = "bit:shl($FSD,22)+ $FSP"!][!//
[!ENDNOCODE!][!//
    (uint32)[!"num:inttohex($FSP)"!]U,
 
    /* AGC Cfg */
[!NOCODE!][!//       
[!VAR "AGC" = "num:i(0)"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuInterruptSet0"!][!//
[!/* IGCS0 bit is bit 0,1,2 */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,0)"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuInterruptSet1"!][!//
[!/* IGCS1 bit is bit 4,5,6  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,4)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuInterruptSet2"!][!//
[!/* IGCS2 bit is bit 8,9,10  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,8)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuIdleRequest"!][!//
[!/* ICS bit is bit 16,17,18  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,16)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuIGCS0ActivatePES"!][!//
[!/* PES bit 24  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,24)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuIGCS1ActivatePES"!][!//
[!/* PES bit 25  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,25)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuIGCS2ActivatePES"!][!//
[!/* PES bit 26  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,26)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuNMIActivatePES"!][!//
[!/* PES bit 27  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,27)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuIdleActivatePES"!][!//
[!/* PES bit 28  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,28)+ $AGC"!][!//
[!CALL "CG_AGC_Value","MacInputVal" = "SmuAlarmGlobalConfig/SmuEnableFaultToRunState"!][!//
[!/* EFRST bit is bit 29  */!][!//
[!VAR "AGC" = "bit:shl($OutMac_AGC,29)+ $AGC"!][!//
[!ENDNOCODE!][!//
    (uint32)[!"num:inttohex($AGC)"!]U,
 
    /* RTC Cfg */
[!NOCODE!][!//  
[!//  /* SMU Recovery Timer "!] */
[!VAR "RT0" = "SmuRecoveryTimer/SmuEnableRT0"!][!//
[!VAR "RT1" = "SmuRecoveryTimer/SmuEnableRT1"!][!//
[!VAR "RTD" = "num:i(SmuRecoveryTimer/SmuRTDuration)"!][!//
[!IF "(($RT0 = 'SMU_RT_ENABLE')and($RT1 = 'SMU_RT_DISABLE'))"!][!//
[!VAR "RTD" = "(bit:shl(1,0) + bit:shl($RTD,8))"!][!//
[!ELSEIF "(($RT0 = 'SMU_RT_DISABLE')and($RT1 = 'SMU_RT_ENABLE'))"!]
[!VAR "RTD" = "(bit:shl(1,1) + bit:shl($RTD,8))"!][!//
[!ELSEIF "(($RT0 = 'SMU_RT_ENABLE')and($RT1 = 'SMU_RT_ENABLE'))"!]
[!VAR "RTD" = "(bit:shl(1,0) + bit:shl(1,1) + bit:shl($RTD,8))"!][!//
[!ELSEIF "(($RT0 = 'SMU_RT_DISABLE')and($RT1 = 'SMU_RT_DISABLE'))"!]
[!VAR "RTD" = "bit:shl($RTD,8)"!][!//
[!ELSE!] [!//
[!ENDIF!] [!//  
[!ENDNOCODE!][!//  
    (uint32)[!"num:inttohex($RTD)"!]U,
 
    /* RTAC0 Cfg */
[!NOCODE!][!//      
[!VAR "TotalRTAC0Config" = "num:i(count(SmuRT0Alarm/*))"!][!// 
[!VAR "RTAC0" = "num:i(0)"!][!//
[!FOR "RTAC0Id" ="num:i(1)" TO "(num:i($TotalRTAC0Config))"!][!//
[!SELECT "SmuRT0Alarm/*[num:i($RTAC0Id)]"!][!//
[!CALL "CG_RTACfg_Value","MacInputVal" = "SmuRT0AlarmGroupId"!][!//
[!VAR "RTACVar1" = "$OutMac_RTACCfg"!][!//
[!VAR "RTACVar2" = "SmuRT0AlarmId"!][!//
[!VAR "RTAC0" = "bit:or($RTAC0,(bit:shl($RTACVar1,(($RTAC0Id - num:i(1)) * num:i(8)))))"!][!//
[!VAR "RTAC0" = "bit:or($RTAC0,(bit:shl($RTACVar2,(($RTAC0Id - num:i(1)) * num:i(8))+num:i(3))))"!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!// 
[!ENDNOCODE!][!//
    (uint32)[!"num:inttohex($RTAC0)"!]U,
 
    /* RTAC1 Cfg */
[!NOCODE!][!//      
[!VAR "TotalRTAC1Config" = "num:i(count(SmuRT1Alarm/*))"!][!// 
[!VAR "RTAC1" = "num:i(0)"!][!//
[!FOR "RTAC1Id" ="num:i(1)" TO "(num:i($TotalRTAC1Config))"!][!//
[!SELECT "SmuRT1Alarm/*[num:i($RTAC1Id)]"!][!//
[!CALL "CG_RTACfg_Value","MacInputVal" = "SmuRT1AlarmGroupId"!][!//
[!VAR "RTACVar1" = "$OutMac_RTACCfg"!][!//
[!VAR "RTACVar2" = "SmuRT1AlarmId"!][!//
[!VAR "RTAC1" = "bit:or($RTAC1,(bit:shl($RTACVar1,(($RTAC1Id - num:i(1)) * num:i(8)))))"!][!//
[!VAR "RTAC1" = "bit:or($RTAC1,(bit:shl($RTACVar2,(($RTAC1Id - num:i(1)) * num:i(8))+num:i(3))))"!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!// 
[!ENDNOCODE!][!//
    (uint32)[!"num:inttohex($RTAC1)"!]U,
    
    /*AlarmConfig*/
    {
[!SELECT "SmuAlarmGroup/*"!][!//    
[!VAR "TotalAlarmConfig" = "num:i(count(SmuAlarmBehavior/*))"!][!// 
[!NOCODE!][!//  
[!VAR "AGCF0" = "num:i(0)"!][!//
[!VAR "AGCF1" = "num:i(0)"!][!//
[!VAR "AGCF2" = "num:i(0)"!][!// 
[!FOR "AlmId" ="num:i(1)" TO "(num:i($TotalAlarmConfig))"!][!//
[!SELECT "SmuAlarmBehavior/*[num:i($AlmId)]"!][!//
[!CALL "CG_AlmCfg_Value","MacInputVal" = "SmuAlarmIntBeh"!][!//
[!VAR "IntAlramBeh" = "$OutMac_AlmCfg"!][!//
[!VAR "Bit0" = "num:i(0)"!][!//
[!VAR "Bit1" = "num:i(0)"!][!//
[!VAR "Bit2" = "num:i(0)"!][!// 
[!VAR "Bit0" = "bit:shr(bit:and($IntAlramBeh,(bit:shl(num:i(1),0))),0)"!][!//
[!VAR "Bit1" = "bit:shr(bit:and($IntAlramBeh,(bit:shl(num:i(1),1))),1)"!][!//
[!VAR "Bit2" = "bit:shr(bit:and($IntAlramBeh,(bit:shl(num:i(1),2))),2)"!][!//
[!IF "$Bit0 = num:i(1)"!][!//
[!VAR "AGCF0" = "bit:or($AGCF0,(bit:shl(num:i(1),($AlmId - num:i(1)))))"!][!//
[!ENDIF!] [!//
[!IF "$Bit1 = num:i(1)"!][!//
[!VAR "AGCF1" = "bit:or($AGCF1,(bit:shl(num:i(1),($AlmId - num:i(1)))))"!][!//
[!ENDIF!][!//
[!IF "$Bit2 = num:i(1)"!][!//
[!VAR "AGCF2" = "bit:or($AGCF2,(bit:shl(num:i(1),($AlmId - num:i(1)))))"!][!//
[!ENDIF!] [!//  
[!ENDSELECT!][!//
[!ENDFOR!][!// 
[!VAR "GroupId" = "$GroupId + num:i(1)"!][!//
[!ENDNOCODE!][!//
      [!"num:inttohex($AGCF0)"!]U,[!"num:inttohex($AGCF1)"!]U,[!"num:inttohex($AGCF2)"!]U[!IF "$GroupId < num:i(7)"!],[!ELSE!][!VAR "GroupId" = "num:i(0)"!][!ENDIF!][!//
    
[!ENDSELECT!][!//
    },
    /*AlarmFspConfig*/
    {
[!SELECT "SmuAlarmGroup/*"!][!//    
[!VAR "TotalAlarmConfig" = "num:i(count(SmuAlarmBehavior/*))"!][!// 
[!NOCODE!][!//  
[!VAR "AGFSP" = "num:i(0)"!][!//
[!FOR "AlmId" ="num:i(1)" TO "(num:i($TotalAlarmConfig))"!][!//
[!SELECT "SmuAlarmBehavior/*[num:i($AlmId)]"!][!//
[!CALL "CG_AlmCfg_Value","MacInputVal" = "SmuAlarmFSP"!][!//
[!VAR "ExtAlramBeh" = "$OutMac_AlmCfg"!][!//
[!IF "$ExtAlramBeh = num:i(1)"!][!//
[!VAR "AGFSP" = "bit:or($AGFSP,(bit:shl(num:i(1),($AlmId - num:i(1)))))"!][!//
[!ENDIF!] [!//
[!ENDSELECT!][!//
[!ENDFOR!][!// 
[!VAR "GroupId" = "$GroupId + num:i(1)"!][!//
[!ENDNOCODE!][!//
      [!"num:inttohex($AGFSP)"!]U[!IF "$GroupId < num:i(7)"!],[!ELSE!][!VAR "GroupId" = "num:i(0)"!][!ENDIF!][!//
    
[!ENDSELECT!][!//
    }
  }[!IF "$SmuId < $TotalConfig"!],[!ENDIF!][!//
  
[!ENDSELECT!][!//
[!ENDFOR!][!//
};
[!ENDSELECT!][!//
[!AUTOSPACING!]
#if (IFX_SAFETLIB_USED == STD_ON)
#define IFX_SMU_STOP_SEC_POSTBUILDCFG_ASIL_B
#include "Ifx_MemMap.h"
#else
#define SMU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
#endif
