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
**  $FILENAME   : CanTrcv_17_6250GV33.h $                                    **
**                                                                           **
**  $CC VERSION : \main\27 $                                                 **
**                                                                           **
**  $DATE       : 2016-07-19 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of CanTrcv_17_6250GV33 driver.               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY : [cover parentID=  ASW:1546,DS_AS403_CANTRCV169_1,
   DS_AS403_CANTRCV169_2, DS_AS403_CANTRCV169_3,DS_NAS_CANTRCV_PR746,
   DS_AS403_CANTRCV169_4,DS_AS403_CANTRCV169_5,DS_AS403_CANTRCV169_6,
   DS_AS403_CANTRCV169_7,DS_AS403_CANTRCV169_8,SAS_NAS_ALL_PR748,
   SAS_NAS_ALL_PR125,SAS_NAS_ALL_PR453_PR1649,SAS_NAS_ALL_PR454,
   SAS_NAS_ALL_PR624,SAS_NAS_ALL_PR1648_PR230,
   DS_NAS_CANTRCV_PR643_1,DS_NAS_CANTRCV_PR643_2,DS_NAS_CANTRCV_PR699,
   DS_AS403_CANTRCV162_CANTRCV163_CANTRCV165_CANTRCV166_CANTRCV084_CANTRCV164,
   DS_NAS_CANTRCV_PR1650_PR1654,DS_NAS_CANTRCV_PR1651_PR235_PR236_PR628]
**  [/cover]                                                                  **
**                                                                            **
*******************************************************************************/

#ifndef CANTRCV_17_6250GV33_H
#define CANTRCV_17_6250GV33_H

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

/* Can_GeneralTypes.h contains prototype of CANTRCV Interface Defines */
#include "Can_GeneralTypes.h"

/* Pre-compile configuration parameters for CanTrcv */
#include "CanTrcv_17_6250GV33_Cfg.h"

/* MCAL header file containing global macros, type definitions and functions
  needed by all MCAL drivers. */
#include "Mcal.h"

/* CanTrcv048: Enable / Disable DET checking */
#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
 /*(CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define CANTRCV_17_6250GV33_VENDOR_ID         ((uint16)17)
#define CANTRCV_17_6250GV33_MODULE_ID         ((uint16)70)


#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
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
/* Configured baud rate is not supported by the transceiver,
   valid for Partial networking*/
#define CANTRCV_E_BAUDRATE_NOT_SUPPORTED         ((uint8)0x25)
/*
  API Service ID's
*/
/* API Service ID for CanTrcv_Init() */
#define CANTRCV_SID_INIT                         ((uint8)0x00)
/* API Service ID for CanTrcv_SetOpMode() */
#define CANTRCV_SID_SETOPMODE                    ((uint8)0x01)
/* API Service ID for CanTrcv_GetOpMode() */
#define CANTRCV_SID_GETOPMODE                    ((uint8)0x02)
/* API Service ID for CanTrcv_GetBusWuReason() */
#define CANTRCV_SID_GETBUSWUREASON               ((uint8)0x03)
/* API Service ID for CanTrcv_GetVersioninfo() */
#define CANTRCV_SID_GETVERSIONINFO               ((uint8)0x04)
/* API Service ID for CanTrcv_SetWakeupMode() */
#define CANTRCV_SID_SETWAKEUPMODE                ((uint8)0x05)
/* API Service ID for CanTrcv_MainFunction() */
#define CANTRCV_SID_MAINFUNCTION                 ((uint8)0x06)
/* API Service ID for CanTrcv_CheckWakeup() */
#define CANTRCV_SID_CHECKWAKEUP                  ((uint8)0x07)

#endif
/* #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */

/*
  CanTrcvWakeUpSupport modes
*/

/* CAN transceiver wakeup is supported by Polling */
#define  CANTRCV_WAKE_UP_BY_POLLING              (1U)
/* CAN transceiver wakeup is not supported */
#define  CANTRCV_WAKE_UP_NOT_SUPPORTED           (2U)

/*******************************************************************************
**                      Global Function like macros                           **
*******************************************************************************/
#define CANTRCV_17_6250GV33_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV008, DS_AS_CANTRCV108, DS_AS_CANTRCV110,
DS_AS403_CANTRCV134,DS_NAS_CANTRCV_PR128
]
** Syntax : void CanTrcv_17_6250GV33_GetVersionInfo                           **
**               (Std_VersionInfoType* VersionInfoPtr)                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
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
#if ((CANTRCV_17_6250GV33_GET_VERSION_INFO == STD_ON) &&                       \
              (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON))
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand
to a braced  initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like
 macro as per AUTOSAR*/
#define CanTrcv_17_6250GV33_GetVersionInfo(versioninfo)                        \
{                                                                              \
   /* CanTrcv133: If called with OpMode==NULL */                               \
  if ((versioninfo) == NULL_PTR)                                           \
  {                                                                            \
    /* Paramter is not valid. Report error to DET. */                          \
    Det_ReportError(                                                           \
                     CANTRCV_17_6250GV33_MODULE_ID,                            \
                     CANTRCV_17_6250GV33_INSTANCE_ID,                          \
                     CANTRCV_SID_GETVERSIONINFO,                               \
                     CANTRCV_E_PARAM_POINTER                                   \
                   );                                                          \
                                                                               \
  }                                                                            \
  else                                                                         \
  {                                                                            \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* return version information : */                                         \
    /* Get  Vendor ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->vendorID =                          \
                                          CANTRCV_17_6250GV33_VENDOR_ID;       \
    /* Get  Module ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->moduleID =                          \
                                          CANTRCV_17_6250GV33_MODULE_ID;       \
    /* Get  module Software major version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                               (uint8)CANTRCV_17_6250GV33_SW_MAJOR_VERSION;    \
    /* Get  module Software minor version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                               (uint8)CANTRCV_17_6250GV33_SW_MINOR_VERSION;    \
    /* Get  module Software patch version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                               (uint8)CANTRCV_17_6250GV33_SW_PATCH_VERSION;    \
  }                                                                            \
}/* end of CanTrcv_17_6250GV33_GetVersionInfo() */
#elif ((CANTRCV_17_6250GV33_GET_VERSION_INFO == STD_ON) &&                     \
              (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_OFF))
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand
to a braced  initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like
 macro as per AUTOSAR*/
#define CanTrcv_17_6250GV33_GetVersionInfo(versioninfo)                        \
{                                                                              \
    /* (pointer VersionInfoPtr is not checked for NULL pointer) */             \
    /* Get  Vendor ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->vendorID =                          \
                                          CANTRCV_17_6250GV33_VENDOR_ID;       \
    /* Get  Module ID */                                                    \
    ((Std_VersionInfoType*)(versioninfo))->moduleID =                          \
                                          CANTRCV_17_6250GV33_MODULE_ID;       \
    /* Get  module Software major version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_major_version =                  \
                               (uint8)CANTRCV_17_6250GV33_SW_MAJOR_VERSION;    \
    /* Get  module Software minor version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_minor_version =                  \
                               (uint8)CANTRCV_17_6250GV33_SW_MINOR_VERSION;    \
    /* Get  module Software patch version */                                \
    ((Std_VersionInfoType*)(versioninfo))->sw_patch_version =                  \
                               (uint8)CANTRCV_17_6250GV33_SW_PATCH_VERSION;    \
}/* end of CanTrcv_17_6250GV33_GetVersionInfo() */
#else
#define CanTrcv_17_6250GV33_GetVersionInfo(versioninfo)                        \
        ERROR_CanTrcv_17_6250GV33_GetVersionInfo_NOT_SELECTED
#endif
/******************************************************************************/
#define CANTRCV_17_6250GV33_STOP_SEC_CODE
#include "MemMap.h"

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
#define CANTRCV_17_6250GV33_START_SEC_CONST_16BIT
#include "MemMap.h"
extern const Dio_ChannelType CanTrcv_kNetwork[CANTRCV_17_6250GV33_CHANNELS_CFG];
/*IFX_MISRA_RULE_08_07_STATUS= array CanTrcv_KCtrlPin is declared as
 extern in Cantrcv_17_6250GV33.h,
 which will be initialized in CanTrcv_17_6250GV33_Cfg.c*/
extern const Dio_PortLevelType  \
     CanTrcv_KCtrlPin[CANTRCV_17_6250GV33_CHANNELS_CFG];
#define CANTRCV_17_6250GV33_STOP_SEC_CONST_16BIT
#include "MemMap.h"

#define CANTRCV_17_6250GV33_START_SEC_CONST_8BIT
#include "MemMap.h"
/*IFX_MISRA_RULE_08_07_STATUS= array CanTrcv_NetworkMode is declared as
 extern in ECantrcv_17_6250GV33.h,
 which will be initialized in CanTrcv_17_6250GV33_Cfg.c*/
extern const CanTrcv_TrcvModeType  \
     CanTrcv_NetworkMode[CANTRCV_17_6250GV33_CHANNELS_CFG];
#define CANTRCV_17_6250GV33_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define CANTRCV_17_6250GV33_START_SEC_CODE
#include "MemMap.h"

/* CanTrcv001:CanTrcv_Init API  */
/******************************************************************************
** Syntax :void CanTrcv_17_6250GV33_Init(ConfigPtr)                         **
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
extern void CanTrcv_17_6250GV33_Init(const CanTrcv_ConfigType* ConfigPtr);

/* CanTrcv002:CanTrcv_SetOpMode API  */
/******************************************************************************
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_SetOpMode                     **
**                     (uint8 Transceiver, CanTrcv_TrcvModeType OpMode)      **
**                                                                           **
** Service ID:  0x01                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): Transceiver -CAN transceiver to which API call has       **
**                               to be applied.                              **
**                  OpMode - The parameter says to which operation mode the  **
**                           change shall be performed.                      **
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
** CanTrcv158: The CanTrcv module shall invoke the callback function         **
**             CanIf_TrcvModeIndication, for each mode switch request        **
**             with call to CanTrcv_SetOpMode,after the requested mode       **
**             has been reached.                                             **
**                                                                           **
******************************************************************************/

extern Std_ReturnType CanTrcv_17_6250GV33_SetOpMode
(
  uint8 Transceiver, CanTrcv_TrcvModeType OpMode
);

/* CanTrcv005:CanTrcv_GetOpMode API  */
/******************************************************************************
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_GetOpMode                     **
**                     (uint8 Transceiver, CanTrcv_TrcvModeType* OpMode)     **
**                                                                           **
** Service ID:  0x02                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in):  Transceiver -CAN transceiver to which API call has      **
**                               to be applied.                              **
**                  OpMode - Pointer to the operation mode of the bus the API**
**                           is applied too.                                 **
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
extern Std_ReturnType CanTrcv_17_6250GV33_GetOpMode
(
  uint8 Transceiver, CanTrcv_TrcvModeType* OpMode
);


/******************************************************************************
** Syntax : Std_ReturnType  CanTrcv_17_6250GV33_GetBusWuReason               **
**                 (uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason) **
**                                                                           **
** Service ID:  0x03                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in): Transceiver -CAN transceiver to which API call has       **
**                               to be applied.                              **
**                  Reason - Pointer to wakeup Reasonof the bus the API is   **
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
extern Std_ReturnType CanTrcv_17_6250GV33_GetBusWuReason
(
 uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason
);

/* CanTrcv009:CanTrcv_SetWakeupMode API  */
/******************************************************************************
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_SetWakeupMode                 **
**           (uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)  **
**                                                                           **
** Service ID:  0x05                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): Transceiver -CAN transceiver to which API call has       **
**                               to be applied.                              **
**                  TrcvWakeupMode - Requested Transreceiver Wakeup Reason   **
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
extern Std_ReturnType CanTrcv_17_6250GV33_SetWakeupMode
(
  uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode
);

/* CanTrcv013:CanTrcv_CheckWakeup API  */
/*******************************************************************************
** Syntax : void CanTrcv_17_6250GV33_CheckWakeup ( uint8 Transceiver )        **
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
extern Std_ReturnType CanTrcv_17_6250GV33_CheckWakeup(uint8 Transceiver);



 /* End of
(CANTRCV_17_6250GV33_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING)*/
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define CANTRCV_17_6250GV33_STOP_SEC_CODE
#include "MemMap.h"

#endif /* CANTRCV_17_6250GV33_H */
