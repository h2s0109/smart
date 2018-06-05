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
**  $FILENAME   : CanTrcv_17_6250GV33.c $                                    **
**                                                                           **
**  $CC VERSION : \main\37 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-18 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of CANTRCV_17_6250GV33 driver.               **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY :
[cover parentID= ASW:1530,ASW:1443,DS_NAS_CANTRCV_PR734,DS_NAS_CANTRCV_PR912, 
DS_NAS_CANTRCV_PR919,DS_AS_CANTRCV024_CANTRCV058,DS_AS_CANTRCV057, 
DS_AS403_CANTRCV152_CANTRCV155, DS_AS403_CANTRCV151_CANTRCV153, 
DS_AS403_CANTRCV154,DS_AS403_CANTRCV160,
SAS_AS_CANTRCV061_CANTRCV063_CANTRCV064_CANTRCV065_CANTRCV067_CANTRCV068,
SAS_NAS_ALL_PR749,SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652,SAS_NAS_ALL_PR630_PR631,
DS_NAS_CANTRCV_PR131,DS_AS_CANTRCV069,DS_NAS_CANTRCV_PR115,
DS_AS_CANTRCV_PR637_PR638_PR639,DS_AS403_6251G_CANTRCV086 [/cover]
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* CanTrcv067:Header file structure */
#include "CanTrcv_17_6250GV33.h"

/* CAN Interface Header file  */
#include "CanIf.h"

/* Inclusion of EcuM Module header file*/
#include "EcuM.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#ifndef CANTRCV_17_6250GV33_AR_RELEASE_MAJOR_VERSION
  #error "CANTRCV_17_6250GV33_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6250GV33_AR_RELEASE_MINOR_VERSION
  #error "CANTRCV_17_6250GV33_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6250GV33_AR_RELEASE_REVISION_VERSION
  #error "CANTRCV_17_6250GV33_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6250GV33_SW_MAJOR_VERSION
  #error "CANTRCV_17_6250GV33_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6250GV33_SW_MINOR_VERSION
  #error "CANTRCV_17_6250GV33_SW_MINOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6250GV33_SW_PATCH_VERSION
  #error "CANTRCV_17_6250GV33_SW_PATCH_VERSION is not defined. "
#endif

#if ( CANTRCV_17_6250GV33_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "CANTRCV_17_6250GV33_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( CANTRCV_17_6250GV33_AR_RELEASE_MINOR_VERSION != 0U )
  #error "CANTRCV_17_6250GV33_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#if ( CANTRCV_17_6250GV33_AR_RELEASE_REVISION_VERSION != 3U )
  #error "CANTRCV_17_6250GV33_AR_RELEASE_REVISION_VERSION does not match. "
#endif

#if ( CANTRCV_17_6250GV33_SW_MAJOR_VERSION != 2U )
  #error "CANTRCV_17_6250GV33_SW_MAJOR_VERSION does not match. "
#endif

#if ( CANTRCV_17_6250GV33_SW_MINOR_VERSION != 1U )
  #error "CANTRCV_17_6250GV33_SW_MINOR_VERSION does not match. "
#endif


/*
  Inter Module Checks to avoid integration of incompatible files
*/
#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#if (IFX_DET_VERSION_CHECK == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif
/*#if (IFX_DET_VERSION_CHECK == STD_ON)*/


#endif
/* End Of CANTRCV_17_6250GV33_DEV_ERROR_DETECT */


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* CAN Transceiver Driver states. */
#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
/* CAN Transceiver Driver is NOT initialized. */
#define  CANTRCV_DS_UNINIT                       ((uint8)0)
/* CAN Transceiver Driver is initialized. */
#define  CANTRCV_DS_READY                        ((uint8)1)
#endif
 /* #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */

/* Pin settings for different Modes */

/* Normal Mode */
#define  CANTRCV_NORMAL_VAL                      (0)
/* Stand By Mode */
#define  CANTRCV_STANDBY_VAL                     (1U)

#define CANTRCV_MAX_CH_SUPPORT (CANTRCV_17_6250GV33_MAX_CH_SUPPORT)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/******************************************************************************
**                      Imported Global Constant Declaration                 **
******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define CANTRCV_17_6250GV33_START_SEC_CODE
#include "MemMap.h"

IFX_LOCAL_INLINE void CanTrcv_lPutCurMode(uint8 Channel,
                                       CanTrcv_TrcvModeType Value);
#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType CanTrcv_lCheckUninitDet(uint8 serviceId);
static Std_ReturnType CanTrcv_lCheckNetwork(uint8 networkid, uint8 serviceId)  ;
#endif

#define CANTRCV_17_6250GV33_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define CANTRCV_17_6250GV33_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* CAN transceiver hardware Current Mode */
#if ( CANTRCV_17_6250GV33_DEBUG_SUPPORT == STD_ON )
/*IFX_MISRA_RULE_08_10_STATUS=Variable Cantrcv_CurrentMode is declared as
 extern in CanTrcv_17_6250GV33_Dbg.h, which will be included application for
 debugging*/
volatile CanTrcv_TrcvModeType Cantrcv_CurrentMode[CANTRCV_MAX_CH_SUPPORT];
#else
static CanTrcv_TrcvModeType Cantrcv_CurrentMode[CANTRCV_MAX_CH_SUPPORT];
#endif

#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
/* CAN hardware initialization updation */
static uint8 CanTrcv_DriverState;
#endif
 /* (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */
#define CANTRCV_17_6250GV33_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CANTRCV_17_6250GV33_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* CanTrcv001:CanTrcv_Init API  */
/******************************************************************************
** Traceability : [cover parentID=DS_AS_CANTRCV001, 
 DS_AS_CANTRCV100, DS_AS_CANTRCV180,
 DS_AS403_CANTRCV148_CANTRCV113_CANTRCV167]                                  **
** Syntax :void CanTrcv_17_6250GV33_Init(const CanTrcv_ConfigType* ConfigPtr)**
** [/cover]                                                                  **
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
**                                                                           **
******************************************************************************/
void CanTrcv_17_6250GV33_Init(const CanTrcv_ConfigType* ConfigPtr)
{

   volatile uint8  Can_Network = 0U;
  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
  /* CAN transceiver hardware is not Initialized */
  CanTrcv_DriverState = CANTRCV_DS_UNINIT;
  #endif
  /* End of (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */

  while(Can_Network < CANTRCV_17_6250GV33_CHANNELS_CFG)
  {
    /* Set the CAN transceiver hardware to configured mode. */
    /*IFX_MISRA_RULE_01_02_STATUS=Can_Network Variable is made volatile
    and is used as a index in the below array.This is to avoid warnings in 
    Windriver*/
    /*IFX_MISRA_RULE_12_02_STATUS=Can_Network isw made volatile and the
  order of evaluation does not affect the intended result */
    Dio_WriteChannel(CanTrcv_kNetwork[Can_Network],
      (Dio_LevelType)CanTrcv_KCtrlPin[Can_Network]);

    /*IFX_MISRA_RULE_01_02_STATUS=Can_Network Variable is made 
    volatile and is used as a index in the below array.This is to avoid 
    warnings in Windriver*/
        /*IFX_MISRA_RULE_12_02_STATUS=Can_Network isw made volatile and the
  order of evaluation does not affect the intended result */
    CanTrcv_lPutCurMode(Can_Network,
                     (CanTrcv_TrcvModeType)CanTrcv_NetworkMode[Can_Network]);
    Can_Network++;
  }

  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
  /* CAN transceiver hardware is configured and is ready for use. */
  CanTrcv_DriverState = CANTRCV_DS_READY;
  #endif
  
  UNUSED_PARAMETER(ConfigPtr)
  
  /* End of  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)*/
  return;
} /* End of CanTrcv_init function */

/* CanTrcv002:CanTrcv_SetOpMode API  */
/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV055,DS_AS_CANTRCV087_CANTRCV089_CANTRCV122,
DS_AS403_CANTRCV002, DS_AS403_CANTRCV103, 
DS_AS403_CANTRCV158_CANTRCV085,
DS_AS403_CANTRCV102_CANTRCV105_CANTRCV120_CANTRCV121_CANTRCV123_CANTRCV161_CANTRCV114_CANTRCV117,
DS_AS403_CANTRCV104]                                 **
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_SetOpMode                     **
**                     (uint8 Transceiver, CanTrcv_TrcvModeType OpMode)      **
** [/cover]                                                                  **
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
Std_ReturnType CanTrcv_17_6250GV33_SetOpMode(
  uint8 Transceiver, CanTrcv_TrcvModeType OpMode
)
{
  Std_ReturnType ReturnValue;
  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)

   Std_ReturnType DevErrorExists;

  /* CanTrcv122: If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_SETOPMODE)  ;
  if (DevErrorExists == E_OK)
  {
    /* CanTrcv123: If called with an invalid network number CanNetwork */
    DevErrorExists = CanTrcv_lCheckNetwork(Transceiver,CANTRCV_SID_SETOPMODE) ;
  }

  if (DevErrorExists == E_OK)
  {
     /* CanTrcv132: If called with InvalidOpMode */
    if ((OpMode != CANTRCV_TRCVMODE_NORMAL) &&
       (OpMode != CANTRCV_TRCVMODE_STANDBY) &&
       (OpMode != CANTRCV_TRCVMODE_SLEEP))
    {
      /* Paramter is not valid. Report error to DET. */
      Det_ReportError(
                       CANTRCV_17_6250GV33_MODULE_ID,
                       CANTRCV_17_6250GV33_INSTANCE_ID,
                       CANTRCV_SID_SETOPMODE,
                       CANTRCV_E_PARAM_TRCV_OPMODE
                     );
      DevErrorExists = E_NOT_OK ;
    }
  }

  if (DevErrorExists == E_NOT_OK)
  {
    ReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  else
  {
  #endif
    /*(CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */
   /* Set Default return value to E_OK */
   ReturnValue = (Std_ReturnType)E_OK;

   if (OpMode == CANTRCV_TRCVMODE_NORMAL)
   {
      /* Set the CAN transceiver hardware to Normal mode. */
      Dio_WriteChannel(CanTrcv_kNetwork[Transceiver],
                                (Dio_LevelType)CANTRCV_NORMAL_VAL);
      /* Update the Current mode as Normal */
      CanTrcv_lPutCurMode(Transceiver,CANTRCV_TRCVMODE_NORMAL);
    }
    else if ( OpMode == CANTRCV_TRCVMODE_STANDBY)
    {
      /* Set the CAN transceiver hardware to Standby mode. */
      Dio_WriteChannel(CanTrcv_kNetwork[Transceiver],
                                (Dio_LevelType)CANTRCV_STANDBY_VAL);
      /* Update the Current mode as Stand by */
      CanTrcv_lPutCurMode(Transceiver,CANTRCV_TRCVMODE_STANDBY);
    }
    else  /*if( OpMode == CANTRCV_TRCVMODE_SLEEP) */
    {
      /* CanTrcv105: If the requested mode is not supported by the underlying
      transceiver hardware, the function CanTrcv_SetOpMode
      shall return E_NOT_OK*/
      ReturnValue = (Std_ReturnType)E_NOT_OK;
    }

     /*CanTrcv158: The CanTrcv module shall invoke the callback function
                 CanIf_TrcvModeIndication, for each mode switch request
                 with call to CanTrcv_SetOpMode,after the requested mode
                 has been reached.*/
    if(ReturnValue == E_OK)
    {
       CanIf_TrcvModeIndication(Transceiver,OpMode);
    }

  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
  }
  #endif

  /* If No DET, returns E_OK */
  return (ReturnValue);

} /* End of CanTrcv_SetOpMode function */

/* CanTrcv_17_6250GV33_GetOpMode API */
/* CanTrcv005:CanTrcv_GetOpMode API  */
/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV106_CANTRCV124_CANTRCV132,
DS_AS403_CANTRCV005, DS_AS403_CANTRCV115_CANTRCV129, 
]
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_GetOpMode                     **
**                     (uint8 Transceiver, CanTrcv_TrcvModeType* OpMode)     **
** [/cover]                                                                  **
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
Std_ReturnType CanTrcv_17_6250GV33_GetOpMode(
  uint8 Transceiver, CanTrcv_TrcvModeType* OpMode
)
{
  Std_ReturnType DevErrorExists ;

  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)

  /* CanTrcv124: If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_GETOPMODE);
  if (DevErrorExists == E_OK)
  {
    /* CanTrcv129: If called with an invalid network number CanNetwork */
    DevErrorExists = CanTrcv_lCheckNetwork(Transceiver,CANTRCV_SID_GETOPMODE);
  }
  if (DevErrorExists == E_OK)
  {
     /* CanTrcv132: If called with OpMode==NULL */
    if (OpMode == NULL_PTR)
    {
      /* Paramter is not valid. Report error to DET. */
      Det_ReportError(
                       CANTRCV_17_6250GV33_MODULE_ID,
                       CANTRCV_17_6250GV33_INSTANCE_ID,
                       CANTRCV_SID_GETOPMODE,
                       CANTRCV_E_PARAM_POINTER
                     );
      DevErrorExists = E_NOT_OK ;
    }
  }
  if (DevErrorExists == E_OK)
  {

  #endif
     /*(CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */
    DevErrorExists = E_OK;

    *OpMode = Cantrcv_CurrentMode[Transceiver];

  #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)
  }
  #endif

  /* If No DET raised, returns E_OK */
  return (DevErrorExists);

} /* End of CanTrcv_17_6250GV33_GetOpModeMode function */


/* CanTrcv007:CanTrcv_GetBusWuReason API  */

/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV090, DS_AS_CANTRCV107_CANTRCV125_CANTRCV133,
DS_AS403_CANTRCV007, DS_AS403_CANTRCV116_CANTRCV130
]
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_GetBusWuReason               **
**                 (uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason) **
** [/cover]                                                                  **
**                                                                           **
** Service ID:  0x03                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  reentrant                                                    **
**                                                                           **
** Parameters (in): Transceiver -CAN transceiver to which API call has       **
**                               to be applied.                              **
**                  reason - Pointer to wakeup Reasonof the bus the API is   **
**                           applied to.                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                                                                           **
**                                                                           **
** Description : Returns the Wake up reason of specified CanNetwork          **
** CanTrcv107: The function CanTrcv_GetBusWuReason shall return the reason   **
**             for the wake up that the CAN transceiver has detected.        **
**             The ability to detect and differentiate the possible wakeup   **
**             reasons depends strongly on the CAN transceiver hardware.     **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6250GV33_GetBusWuReason
(
 uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason
)
{
   /* return the wake up reason - CANTRCV_WU_NOT_SUPPORTED.
      as  TLE6250GV33 does not support Wakeup functionality*/
   *reason = CANTRCV_WU_NOT_SUPPORTED;
   UNUSED_PARAMETER(Transceiver)
   return (E_OK);
} /* End of CanTrcv_17_6250GV33_GetBusWuReason function */

/* CanTrcv009:CanTrcv_SetWakeupMode API  */
/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV127,
DS_AS403_CANTRCV009, 
DS_AS403_CANTRCV093_CANTRCV094_CANTRCV095_CANTRCV111_CANTRCV131, 
]
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_SetWakeupMode                 **
**           (uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)  **
** [/cover]                                                                  **
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
** Return value:                                                             **
**                E_NOT_OK                                                   **
**                                                                           **
** Description : This function enables, disables and clears the              **
**               notification for wake up events on the addressed Network.   **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6250GV33_SetWakeupMode(
                 uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode
                 )
{
  /* TLE62 TLE6250GV33 does not support Wakep functionality,
  so return with E_NOT_OK */
  UNUSED_PARAMETER(Transceiver)
  if(TrcvWakeupMode != (CanTrcv_TrcvWakeupModeType)0)\
  {/* To suppress GNU warnings */}
  return ((Std_ReturnType)E_NOT_OK);
} /* End of CanTrcv_17_6250GV33_SetWakeupMode function */


/* CanTrcv013:CanTrcv_CheckWakeup API  */
/*******************************************************************************
** Traceability : [cover parentID=
DS_AS403_CANTRCV143, DS_AS403_CANTRCV144, DS_AS403_CANTRCV145, 
DS_AS403_CANTRCV146, 
]
** Syntax : Std_ReturnType CanTrcv_17_6250GV33_CheckWakeup ( uint8 Transceiver )
** [/cover]                                                                   **
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
** Return value:  E_NOT_OK                                                    **
**                                                                            **
** Description : Scheduled function to scan all busses for wakeup events      **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType CanTrcv_17_6250GV33_CheckWakeup(uint8 Transceiver)
{
  /* TLE62 TLE6250GV33 does not support Wakep functionality,
  so return with E_NOT_OK */
  UNUSED_PARAMETER(Transceiver)
  return ((Std_ReturnType)E_NOT_OK);
}  /* End of CanTrcv_17_6250GV33_CB_WakeUpByBus function */


/******************************************************************************
**                      Private Function Definitions                         **
******************************************************************************/
#if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON)

/*******************************************************************************
** Syntax:          static Std_ReturnType CanTrcv_lCheckUninitDet (           **
**                                                           uint8 serviceId) **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  serviceId:  service id for DET                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    RetVal                                                    **
**                                                                            **
** Description:    This function will check whether the Initialisation has    **
**                 been done                                                  **
*******************************************************************************/
static Std_ReturnType CanTrcv_lCheckUninitDet(uint8 serviceId)
{
  Std_ReturnType RetVal;
  /* Check if driver is initialized */
  if (CanTrcv_DriverState == CANTRCV_DS_UNINIT)
  {
    /* Driver not initialized. Report error to DET. */
    Det_ReportError(CANTRCV_17_6250GV33_MODULE_ID, 
                    CANTRCV_17_6250GV33_INSTANCE_ID,
                    serviceId, 
                    CANTRCV_E_UNINIT);
    RetVal = E_NOT_OK;
  }
  else
  {
    RetVal = E_OK;
  }
  return RetVal;
}

/*******************************************************************************
** Syntax:          static Std_ReturnType CanTrcv_lCheckNetwork (             **
**                                          uint8 networkid, uint8 serviceId) **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  networkid: Network ID / channel Number                    **
**                  serviceId:  service id for DET                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    This function will check whether the networkid is valid    **
**                                                                            **
*******************************************************************************/
static Std_ReturnType CanTrcv_lCheckNetwork(uint8 networkid, uint8 serviceId)
{
  Std_ReturnType RetVal;
  /* Check if driver is initialized */
  if (networkid > (CANTRCV_17_6250GV33_CHANNELS_CFG - 1U))
  {
    /* Driver not initialized. Report error to DET. */
    Det_ReportError(CANTRCV_17_6250GV33_MODULE_ID, 
                    CANTRCV_17_6250GV33_INSTANCE_ID,
                    serviceId, 
                    CANTRCV_E_INVALID_TRANSCEIVER);
    RetVal = E_NOT_OK ;
  }
  else
  {
    RetVal = E_OK;
  }
  return RetVal;
}
#endif
 /* #if (CANTRCV_17_6250GV33_DEV_ERROR_DETECT == STD_ON) */

/*******************************************************************************
** Syntax:          IFX_LOCAL_INLINE void CanTrcv_lPutCurMode (uint8 Channel, **
**                                             CanTrcv_TrcvModeType Value)    **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  Channel: CANTRCV channel Number                           **
**                  Value:  Mode to set                                       **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    This function will set the variable at the required        **
**                 position.                                                  **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void CanTrcv_lPutCurMode(uint8 Channel,
                                  CanTrcv_TrcvModeType Value)
{
  Cantrcv_CurrentMode[Channel] = Value;
}



#define CANTRCV_17_6250GV33_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"