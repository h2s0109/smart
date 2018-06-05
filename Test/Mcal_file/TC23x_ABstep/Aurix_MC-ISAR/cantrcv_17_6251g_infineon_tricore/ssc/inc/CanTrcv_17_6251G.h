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
**  $FILENAME   : CanTrcv_17_6251G.h $                                       **
**                                                                           **
**  $CC VERSION : \main\23 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-09 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of CanTrcv_17_6251G driver.                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=  ASW:1546,DS_AS403_CANTRCV169_1, 
   DS_AS403_CANTRCV169_2, DS_AS403_CANTRCV169_3,DS_NAS_CANTRCV_PR746,
   DS_NAS_CANTRCV_PR699,DS_AS403_CANTRCV169_4,DS_AS403_CANTRCV169_5,
   DS_AS403_CANTRCV169_6,DS_AS403_CANTRCV169_7,DS_AS403_CANTRCV169_8,
   SAS_NAS_ALL_PR748,DS_NAS_CANTRCV_PR643_1,DS_NAS_CANTRCV_PR643_2,
   DS_AS403_CANTRCV162_CANTRCV163_CANTRCV165_CANTRCV166_CANTRCV084_CANTRCV164]
**  [/cover]                                                                  **
**                                                                            **
*******************************************************************************/


#ifndef CANTRCV_17_6251G_H
#define CANTRCV_17_6251G_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/* 
  Include Communication Stack Types 
    This file includes 
        - Std_Types.h   
  Std_Types.h incldes
        - Compiler.h
        - Platform_Types.h
*/
#include "ComStack_Types.h"

/* CanIf.h contains prototype of CAN Interface function */
#include "CanIf.h"


#include "Can_GeneralTypes.h"
/* Pre-compile configuration parameters for CanTrcv */
#include "CanTrcv_17_6251G_Cfg.h"

/* MCAL header file containing global macros, type definitions and functions 
  needed by all MCAL drivers. */
#include "Mcal.h"

/* CanTrcv048: Enable / Disable DET checking */
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
 /*(CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define CANTRCV_17_6251G_VENDOR_ID       ((uint16)17)
#define CANTRCV_17_6251G_MODULE_ID       ((uint16)70)

#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
/* API Service called with invalid CAN Network Parameter */
#define CANTRCV_E_INVALID_TRANSCEIVER            ((uint8)0x01)
/* API Service called with null parameter */
#define CANTRCV_E_PARAM_POINTER                  ((uint8)0x02)
/* API Service used without initialization */
#define CANTRCV_E_UNINIT                         ((uint8)0x11)
/* API service called in wrong operation mode */
#define CANTRCV_E_TRCV_NOT_STANDBY               ((uint8)0x21)
#define CANTRCV_E_TRCV_NOT_NORMAL                ((uint8)0x22)
/* API service called with invalid parameter for TrcvWakeupMode */
#define CANTRCV_E_PARAM_TRCV_WAKEUP_MODE         ((uint8)0x23)
/* API service called with invalid Opmode */
#define CANTRCV_E_PARAM_TRCV_OPMODE              ((uint8)0x24)
/* API service called with invalid Opmode,This is used for partial networking */
#define CANTRCV_E_BAUDRATE_NOT_SUPPORTED         ((uint8)0x25)
/* API service called with invalid Opmode */
#define CANTRCV_E_NO_TRCV_CONTROL                ((uint8)0x26)
/*
  API Service ID's
*/
/* API Service ID for CanTrcv_Init() */
#define CANTRCV_SID_INIT                         ((uint8)0)
/* API Service ID for CanTrcv_SetOpMode() */
#define CANTRCV_SID_SETOPMODE                    ((uint8)1)
/* API Service ID for CanTrcv_GetOpMode() */
#define CANTRCV_SID_GETOPMODE                    ((uint8)2)
/* API Service ID for CanTrcv_GetBusWuReason() */
#define CANTRCV_SID_GETBUSWUREASON               ((uint8)3)
/* API Service ID for CanTrcv_GetVersioninfo() */
#define CANTRCV_SID_GETVERSIONINFO               ((uint8)4)
/* API Service ID for CanTrcv_SetWakeupMode() */
#define CANTRCV_SID_SETWAKEUPMODE                ((uint8)5)
/* API Service ID for CanTrcv_MainFunction() */
#define CANTRCV_SID_MAINFUNCTION                 ((uint8)6)
/* API Service ID for CanTrcv_CB_wakeupByBus() */
#define CANTRCV_SID_CHECKWAKEUP                  ((uint8)7)

#endif
/* #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */


/* Pending wakeup Set */
#define CANTRCV_PENWU_SET                        (1U)


/*
  CanTrcv107:CanTrcvWakeUpSupport modes
*/

/* CAN transceiver wakeup is supported by Polling */
#define  CANTRCV_WAKE_UP_BY_POLLING              (1U)

/* CAN transceiver wakeup is not supported */
#define  CANTRCV_WAKE_UP_NOT_SUPPORTED           (2U)

/* By default,All Dem Reportings should be enabled */
#ifndef CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_0
#define CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_0      (ENABLE_DEM_REPORT)
#endif

#ifndef CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_1
#define CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_1      (ENABLE_DEM_REPORT)
#endif

#ifndef CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_2
#define CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_2      (ENABLE_DEM_REPORT)
#endif

#ifndef CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_3
#define CANTRCV_17_6251G_NO_TRCV_CONTROL_DEM_REPORT_3      (ENABLE_DEM_REPORT)
#endif

#ifndef CANTRCV_17_6251G_PROD_ERROR_REPORT
#define CANTRCV_17_6251G_PROD_ERROR_REPORT                 (STD_ON)
#endif

#define CANTRCV_OP_MODE_NORMAL (0U)
#define CANTRCV_OP_MODE_SLEEP  (1U)
#define CANTRCV_OP_MODE_STANDBY (2U)

/*******************************************************************************
**                      Global Function like macros                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/*
Type: CanTrcv_ConfigType
*/
typedef void CanTrcv_ConfigType;
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define CANTRCV_17_6251G_START_SEC_CONST_8BIT
#include "MemMap.h"


extern const uint8 CanTrcv_kWakeupFlag[CANTRCV_17_6251G_CHANNELS_CFG];
extern const uint8 CanTrcv_kWakeupSourceRef[CANTRCV_17_6251G_CHANNELS_CFG];


#define CANTRCV_17_6251G_STOP_SEC_CONST_8BIT
#include "MemMap.h"

#define CANTRCV_17_6251G_START_SEC_CONST_16BIT
#include "MemMap.h"

extern const Dio_ChannelType 
             CanTrcv6251G_kChannel[CANTRCV_17_6251G_CHANNELS_CFG][3];
/*IFX_MISRA_RULE_08_07_STATUS= array CanTrcv6251G_KCtrlPin is declared as
 extern in Cantrcv_17_6251G.h, which will be initialized 
 in CanTrcv_17_6251G_Cfg.c*/
extern const Dio_PortLevelType \
             CanTrcv6251G_KCtrlPin[CANTRCV_17_6251G_CHANNELS_CFG];

#define CANTRCV_17_6251G_STOP_SEC_CONST_16BIT
#include "MemMap.h"


#define CANTRCV_17_6251G_START_SEC_CONST_32BIT
#include "MemMap.h"

extern const CanTrcv_TrcvModeType 
             CanTrcv6251G_NetworkMode[CANTRCV_17_6251G_CHANNELS_CFG];
             
#define CANTRCV_17_6251G_STOP_SEC_CONST_32BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define CANTRCV_17_6251G_START_SEC_CODE
#include "MemMap.h"

/* CanTrcv001:CanTrcv_Init API  */
/******************************************************************************
** Syntax : void CanTrcv_17_6251G_Init(ConfigPtr)                            **
**                                                                           **
** Service ID:  0x00                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): none                                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Driver Module Initialization function                       **
** CanTrcv100: This API  sets the CAN transceiver                            **
**             hardware to the state configured by the configuration         **
**             parameter CanTrcvInitState.                                   **
**             This API also validates whether there has been a wake up      **
**             due to transceiver activity and if TRUE,                      **
**             reporting will be done to CanIf by calling                    **
**             CanIf_setWakeupEvent, which in turns reports to EcuM via      **
**             API EcuM_SetWakeupEvent.                                      **
**                                                                           **
******************************************************************************/
extern void CanTrcv_17_6251G_Init(const CanTrcv_ConfigType* ConfigPtr);

/* CanTrcv002:CanTrcv_SetOpMode API  */
/******************************************************************************
** Syntax : Std_ReturnType CanTrcv_17_6251G_SetOpMode                        **
**                     (CanIf_TransceiverModeType OpMode,unit8 CanNetwork)   **
**                                                                           **
** Service ID:  0x01                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): OpMode - The parameter says to which operation mode the  **
**                           change shall be performed.                      **
**                  CanNetwork - CAN Network to which the API                **
**                               call has to be applied.                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description : Sets the CanNetwork to the specified mode.                  **
** CanTrcv102: The function CanTrcv_SetOpMode shall switch the internal state**
**             of channel CanNetwork to the value of the parameter OpMode    **
**             which can be CANTRCV_NORMAL, CANTRCV_STANDBY or CANTRCV_SLEEP.**
**                                                                           **
**             This API is applicable to each transceiver with each value for**
**             parameter CanTrcv_SetOpMode regardless of whether the         **
**             transceiver hardware supports these modes or not.             **
** CanTrcv105: If the requested mode is not supported by the underlying      **
**             transceiver hardware, the function CanTrcv_SetOpMode shall    **
**             return E_NOT_OK.                                              **
**                                                                           **
******************************************************************************/

extern Std_ReturnType CanTrcv_17_6251G_SetOpMode 
(
uint8 Transceiver, CanTrcv_TrcvModeType OpMode
);

/* CanTrcv005:CanTrcv_GetOpMode API  */
/******************************************************************************
** Syntax : CanTrcv_OpModeType CanTrcv_17_6251G_GetOpMode                    **
**                     (CanIf_TransceiverModeType* OpMode,unit8 CanNetwork)  **
**                                                                           **
** Service ID:  0x02                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in): OpMode - Pointer to the operation mode of the bus the API**
**                           is applied too.                                 **
**                  CanNetwork - CAN Network to which the API                **
**                               call has to be applied.                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description :  Returns the actual state of specified CanNetwork           **
** CanTrcv106: The function CanTrcv_GetOpMode shall return the actual        **
**             state of the CAN transceiver driver in the parameter OpMode.  **
**                                                                           **
******************************************************************************/
extern Std_ReturnType CanTrcv_17_6251G_GetOpMode
(
  uint8 Transceiver, CanTrcv_TrcvModeType* OpMode
);

/* CanTrcv007:CanTrcv_GetBusWuReason API  */
/******************************************************************************
** Syntax : Std_ReturnType  CanTrcv_17_6251G_GetBusWuReason                  **
**                    (uint8 CanNetwork, CanIf_TrcvWakeupReasonType* reason) **
**                                                                           **
** Service ID:  0x03                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in): CanNetwork - CAN Network to which the API                **
**                               call has to be applied.                     **
**                  reason - Pointer to wakeup Reasonof the bus the API is   **
**                           applied to.                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description : Returns the Wake up reason of specified CanNetwork          **
** CanTrcv107: The function CanTrcv_GetBusWuReason shall return the reason   **
**             for the wake up that the CAN transceiver has detected.        **
**             The ability to detect and differentiate the possible wakeup   **
**             reasons depends strongly on the CAN transceiver hardware.     **
**                                                                           **
******************************************************************************/
extern Std_ReturnType CanTrcv_17_6251G_GetBusWuReason
(
 uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason
);
/*******************************************************************************
**                      Global Function like macros                           **
*******************************************************************************/
/*******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV008, DS_AS_CANTRCV108, DS_AS_CANTRCV110,
DS_AS403_CANTRCV134,DS_NAS_CANTRCV_PR128
]                              
** Syntax : void CanTrcv_17_6251G_GetVersionInfo                              **
**               (Std_VersionInfoType* VersionInfoPtr)                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): versioninfo (Pointer to where to store the version       **
**                                information of this module )                **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service returns the version information of this module. **
**               The version information includes:                            **
**               - Module Id                                                  **
**               - Vendor Id                                                  **
**               - Vendor specific version numbers (BSW00407)                 **
*******************************************************************************/
#if ((CANTRCV_17_6251G_GET_VERSION_INFO == STD_ON) &&                          \
              (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON))                
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand                  
to a braced  initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like 
 macro as per AUTOSAR*/
#define CanTrcv_17_6251G_GetVersionInfo(versioninfo)                           \
{                                                                              \
   /* CanTrcv133: If called with OpMode==NULL */                               \
  if (NULL_PTR == (versioninfo))                                               \
  {                                                                            \
    /* Paramter is not valid. Report error to DET. */                          \
    Det_ReportError(                                                           \
                     CANTRCV_17_6251G_MODULE_ID,                               \
                     CANTRCV_17_6251G_INSTANCE_ID,                             \
                     CANTRCV_SID_GETVERSIONINFO,                               \
                     CANTRCV_E_PARAM_POINTER                                   \
                   );                                                          \
                                                                               \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* return version information GPT181: */                                   \
    /* Get GPT Vendor ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->vendorID =                          \
                                             CANTRCV_17_6251G_VENDOR_ID;       \
    /* Get GPT Module ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->moduleID =                          \
                                             CANTRCV_17_6251G_MODULE_ID;       \
    /* Get GPT module Software major version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                               (uint8)CANTRCV_17_6251G_SW_MAJOR_VERSION;       \
    /* Get GPT module Software minor version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                               (uint8)CANTRCV_17_6251G_SW_MINOR_VERSION;       \
    /* Get GPT module Software patch version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                               (uint8)CANTRCV_17_6251G_SW_PATCH_VERSION;       \
  }                                                                            \
}/* end of CanTrcv_17_6251G_GetVersionInfo() */
#elif ((CANTRCV_17_6251G_GET_VERSION_INFO == STD_ON) &&                        \
              (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_OFF))                
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand                  
to a braced  initialiser*/                                                     \
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like 
 macro as per AUTOSAR*/                                                        
#define CanTrcv_17_6251G_GetVersionInfo(versioninfo)                           \
{                                                                              \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* return version information GPT181: */                                   \
    /* Get GPT Vendor ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->vendorID =                          \
                                             CANTRCV_17_6251G_VENDOR_ID;       \
    /* Get GPT Module ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->moduleID =                          \
                                             CANTRCV_17_6251G_MODULE_ID;       \
    /* Get GPT module Software major version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                               (uint8)CANTRCV_17_6251G_SW_MAJOR_VERSION;       \
    /* Get GPT module Software minor version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                               (uint8)CANTRCV_17_6251G_SW_MINOR_VERSION;       \
    /* Get GPT module Software patch version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                               (uint8)CANTRCV_17_6251G_SW_PATCH_VERSION;       \
}/* end of CanTrcv_17_6251G_GetVersionInfo() */                             
#else
#define CanTrcv_17_6251G_GetVersionInfo(versioninfo)                           \
        ERROR_CanTrcv_17_6251G_GetVersionInfo_NOT_SELECTED                  
#endif
/******************************************************************************/
 /*#if (CANTRCV_17_6251G_GET_VERSION_INFO == STD_ON) */

/* CanTrcv009:CanTrcv_SetWakeupMode API  */
/******************************************************************************
** Syntax : Std_ReturnType CanTrcv_17_6251G_SetWakeupMode                    **
**              (CanIf_TrcvWakeupModeType TrcvWakeupMode, uint8 CanNetwork)  **
**                                                                           **
** Service ID:  0x05                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): TrcvWakeupMode - Requested Transreceiver Wakeup Reason   **
**                  CanNetwork - CAN Network to which the API                **
**                               call has to be applied.                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description : This function enables, disables and clears the              **
**               notification for wake up events on the addressed Network.   **
**                                                                           **
******************************************************************************/
extern Std_ReturnType CanTrcv_17_6251G_SetWakeupMode
(
   uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);

#if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING)
/* CanTrcv013:CanTrcv_MainFunction API  */
/*******************************************************************************
** Syntax : void CanTrcv_17_6251G_MainFunction ( void )                       **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  NA                                                            **
**                                                                            **
** Reentrancy:  NA                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Scheduled function to  scan all busses for wakeup events     **
** CanTrcv112: The CAN bus transceiver may have cyclic jobs like polling      **
**             for a wakeup events(if configured). The cyclic called function **
**             has to scan all busses in STANDBY and SLEEP for wakeup events  **
**                                                                            **
*******************************************************************************/
extern void CanTrcv_17_6251G_MainFunction(void);
#endif
/*#if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING)*/

/* CanTrcv013:CanTrcv_CheckWakeup API  */
/*******************************************************************************
** Syntax : void CanTrcv_17_6251G_CheckWakeup ( uint8 Transceiver )           **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  NA                                                            **
**                                                                            **
** Reentrancy:  NA                                                            **
**                                                                            **
** Parameters (in): CAN transceiver to which API call has to be applied       **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Scheduled function to scan all busses for wakeup events      **
**                                                                            **
**                                                                            **
*******************************************************************************/

extern Std_ReturnType CanTrcv_17_6251G_CheckWakeup(uint8 Transceiver);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define CANTRCV_17_6251G_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANTRCV6251G_H */
