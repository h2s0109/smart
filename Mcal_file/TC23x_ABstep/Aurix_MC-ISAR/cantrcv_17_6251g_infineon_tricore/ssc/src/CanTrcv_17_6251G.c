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
**  $FILENAME   : CanTrcv_17_6251G.c $                                       **
**                                                                           **
**  $CC VERSION : \main\45 $                                                 **
**                                                                           **
**  $DATE       : 2015-01-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of CANTRCV_17_6251G driver.                  **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                                                                            **
**  TRACEABILITY :
[cover parentID= ASW:1530,DS_NAS_CANTRCV_PR734,DS_NAS_CANTRCV_PR912, 
DS_NAS_CANTRCV_PR919, DS_AS_CANTRCV024_CANTRCV058,DS_AS_CANTRCV057, 
DS_AS403_CANTRCV152_CANTRCV155, DS_AS403_CANTRCV151_CANTRCV153, 
DS_AS403_CANTRCV154, DS_AS403_CANTRCV160,SAS_NAS_ALL_PR749,
SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652,SAS_NAS_ALL_PR630_PR631,
DS_NAS_CANTRCV_PR131,
SAS_AS_CANTRCV061_CANTRCV063_CANTRCV064_CANTRCV065_CANTRCV067_CANTRCV068,
DS_AS_CANTRCV069,DS_NAS_CANTRCV_PR115,
DS_AS_CANTRCV_PR637_PR638_PR639,DS_AS403_6251G_CANTRCV086 [/cover]
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* CanTrcv067:Header file structure */
#include "CanTrcv_17_6251G.h"


/* Inclusion of EcuM Module header file*/
#include "EcuM.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#ifndef CANTRCV_17_6251G_AR_RELEASE_MAJOR_VERSION
  #error "CANTRCV_17_6251G_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6251G_AR_RELEASE_MINOR_VERSION
  #error "CANTRCV_17_6251G_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6251G_SW_MAJOR_VERSION
  #error "CANTRCV_17_6251G_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6251G_SW_MINOR_VERSION
  #error "CANTRCV_17_6251G_SW_MINOR_VERSION is not defined. "
#endif

#ifndef CANTRCV_17_6251G_SW_PATCH_VERSION
  #error "CANTRCV_17_6251G_SW_PATCH_VERSION is not defined. "
#endif

#if ( CANTRCV_17_6251G_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "CANTRCV_17_6251G_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if ( (CANTRCV_17_6251G_AR_RELEASE_MINOR_VERSION != 0U) )
  #error "CANTRCV_17_6251G_AR_RELEASE_MINOR_VERSION does not match. "
#endif


#if ( CANTRCV_17_6251G_SW_MAJOR_VERSION != 2U )
  #error "CANTRCV_17_6251G_SW_MAJOR_VERSION does not match. "
#endif

#if ( CANTRCV_17_6251G_SW_MINOR_VERSION != 2U )
  #error "CANTRCV_17_6251G_SW_MINOR_VERSION does not match. "
#endif


/*
  Inter Module Checks to avoid integration of incompatible files
*/
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

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
/* End Of CANTRCV_17_6251G_DEV_ERROR_DETECT */


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* CAN Transceiver Driver states. */
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
/* CAN Transceiver Driver is NOT initialized. */
#define  CANTRCV_DS_UNINIT                       ((uint8)0)
/* CAN Transceiver Driver is initialized. */
#define  CANTRCV_DS_READY                        ((uint8)1)
#endif
 /* #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */

/* Pin settings for different Modes */

/* Normal Mode */
#define  CANTRCV_NORMAL_VAL                    ((uint8)(3U))
/* Stand By Mode */
#define  CANTRCV_STANDBY_VAL                   ((uint8)(0U))
/* Sleep Mode */
#define  CANTRCV_SLEEP_VAL                     ((uint8)(1U))

#define CANTRCV_ZERO_U                           (0U)
#define CANTRCV_ONE_U                            (1U)

#define EN_POS                           ((uint8)(0U))
#define NSTB_POS                         ((uint8)(1U))
#define NERR_POS                         ((uint8)(2U))
#define EN_MASK                          ((uint8)(0x1U))
#define NSTB_MASK                        ((uint8)(0x2U))
#define NSTB_SHIFT                       ((uint8)(1U))

#define NORMAL_EN_VAL                    ((uint8)(1U))
#define NORMAL_NSTB_VAL                  ((uint8)(1U))
#define STANDBY_EN_VAL                   ((uint8)(0U))
#define STANDBY_NSTB_VAL                 ((uint8)(0U))
#define SLEEP_EN_VAL                     ((uint8)(1U))
#define SLEEP_NSTB_VAL                   ((uint8)(0U))




/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/******************************************************************************
**                      Imported Global Constant Declaration                 **
******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define CANTRCV_17_6251G_START_SEC_CODE
#include "MemMap.h"

static void CanTrcv_lCheckInitWakeup(uint8 CanNetwork);
IFX_LOCAL_INLINE void CanTrcv_lWakeup(uint8 Channel,
                                   CanTrcv_TrcvWakeupModeType Value);
#if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT != CANTRCV_WAKE_UP_NOT_SUPPORTED)
static void CanTrcv_lCheckWakeup(uint8 CanNetwork);
#endif
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType CanTrcv_lDetTest(uint8 CanNetwork, uint8 ApiId);
#endif
/* End of #if(CANTRCV_17_6251G_DEV_ERROR_REPORT == STD_ON) */
IFX_LOCAL_INLINE void CanTrcv_lPutCurMode(uint8 Channel,
                                          CanTrcv_TrcvModeType Value);
IFX_LOCAL_INLINE void CanTrcv_lPutWuReason(uint8 Channel,
                                      CanTrcv_TrcvWakeupReasonType Value);
IFX_LOCAL_INLINE uint8 CanTrcv_lGetPendWakeup(uint8 CanNetwork);
IFX_LOCAL_INLINE void CanTrcv_lSetPendWakeup(uint8 CanNetwork);
IFX_LOCAL_INLINE void CanTrcv_lClearPendWakeup(uint8 CanNetwork);
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
static Std_ReturnType CanTrcv_lCheckUninitDet(uint8 serviceId);
static Std_ReturnType CanTrcv_lCheckNetwork(uint8 networkid, uint8 serviceId);
#endif

static void CanTrcv_lSetChannelMode(uint8 CanNetwork);

#define CANTRCV_17_6251G_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define CANTRCV_17_6251G_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* WakeUp Reason */
#if ( CANTRCV_17_6251G_DEBUG_SUPPORT == STD_ON )
static volatile  CanTrcv_TrcvWakeupReasonType 
                      Cantrcv_WuReason[CANTRCV_17_6251G_MAX_CH_SUPPORT];
#else
static CanTrcv_TrcvWakeupReasonType 
                            Cantrcv_WuReason[CANTRCV_17_6251G_MAX_CH_SUPPORT];
#endif

/* CAN transceiver hardware Current Mode */
#if ( CANTRCV_17_6251G_DEBUG_SUPPORT == STD_ON )
static volatile CanTrcv_TrcvModeType 
                          Cantrcv_CurrentMode[CANTRCV_17_6251G_MAX_CH_SUPPORT];
#else
static CanTrcv_TrcvModeType 
                          Cantrcv_CurrentMode[CANTRCV_17_6251G_MAX_CH_SUPPORT];
#endif

/* Enable/Disable the notification */
static CanTrcv_TrcvWakeupModeType 
                              CanTrcv_Wakeup[CANTRCV_17_6251G_MAX_CH_SUPPORT];

#define CANTRCV_17_6251G_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define CANTRCV_17_6251G_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

static uint8 CanTrcv_WakeupFlagIndication[CANTRCV_17_6251G_MAX_CH_SUPPORT];
/* Set/Clear the pending notification */
static uint8 CanTrcv_PendWakeup;
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
/* CAN hardware initialization updation */
static uint8 CanTrcv_DriverState;
#endif
 /* (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */

#define CANTRCV_17_6251G_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CANTRCV_17_6251G_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Syntax:          IFX_LOCAL_INLINE void CanTrcv_lPutCurMode (uint8 Channel,
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
  Cantrcv_CurrentMode[Channel] = Value ;
}

/*******************************************************************************
** Syntax:          IFX_LOCAL_INLINE void CanTrcv_lPutWuReason (uint8 Channel,
**                                     CanTrcv_TrcvWakeupReasonType  Value)   **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  Channel: CANTRCV channel Number                           **
**                  Value:  Reason to be set                                  **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    This function will set the variable at the required        **
**                 position.                                                  **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void CanTrcv_lPutWuReason(uint8 Channel,
                                      CanTrcv_TrcvWakeupReasonType Value)
{
  Cantrcv_WuReason[Channel] = Value;
}
/*******************************************************************************
** Syntax:          IFX_LOCAL_INLINE void CanTrcv_lWakeup (uint8 Channel,
**                                  CanTrcv_TrcvWakeupModeType Value)         **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  Channel: CANTRCV channel Number                           **
**                  Value:  Value to set                                      **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    This function will set the variable at the required        **
**                 position.                                                  **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void CanTrcv_lWakeup(uint8 Channel,
                                    CanTrcv_TrcvWakeupModeType Value)
{
  CanTrcv_Wakeup[Channel] = Value;
}

/* CanTrcv001:CanTrcv_Init API  */
/******************************************************************************
** Traceability : [cover parentID=
 DS_AS_CANTRCV001, DS_AS_CANTRCV100, DS_AS_CANTRCV180, 
 DS_AS403_CANTRCV148_CANTRCV113_CANTRCV167
 ]
** Syntax : void CanTrcv_17_6251G_Init(const CanTrcv_ConfigType* ConfigPtr)  **
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
**             This API also validates whether there has been a wake up      **
**             due to transceiver activity and if TRUE,                      **
**             reporting will be done to EcuM by calling                    **
**             EcuM_SetWakeupEvent, which in turns reports to EcuM via      **
**             API EcuM_SetWakeupEvent.                                      **
**                                                                           **
******************************************************************************/
void CanTrcv_17_6251G_Init(const CanTrcv_ConfigType* ConfigPtr)
{
  volatile uint8 Can_Network = CANTRCV_ZERO_U;
  
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  uint8 ReturnValue = E_OK;
  #endif
  
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  /* CAN transceiver hardware is not Initialized */
  CanTrcv_DriverState = CANTRCV_DS_UNINIT;
  #endif
  /* End of (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */
  
   while(Can_Network < CANTRCV_17_6251G_CHANNELS_CFG)
  {
     /* Check whether there has been a wake up due to transceiver activity and 
     if TRUE, reporting to EcuM via API EcuM_SetWakeupEvent */
     CanTrcv_lCheckInitWakeup(Can_Network);
     
    /* check Whether CAN transceiver hardware is Set to Normal */
    if(CanTrcv6251G_NetworkMode[Can_Network] != CANTRCV_TRCVMODE_NORMAL)
    {  
           /* Update the CAN transceiver hardware to Configured mode */
        CanTrcv_lSetChannelMode(Can_Network);
    }
    #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

    if(CanTrcv_lDetTest(Can_Network,CANTRCV_SID_INIT))
    {
      
        ReturnValue  = E_NOT_OK;
      break;

    }

    #endif

    Can_Network++;
  }
  
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  if(ReturnValue == E_OK)
  {
     CanTrcv_DriverState = CANTRCV_DS_READY;
  }
  #endif  

  UNUSED_PARAMETER(ConfigPtr)
  return;
} /* End of CanTrcv_init function */


/*******************************************************************************
** Syntax:          static void CanTrcv_lSetChannelMode(uint8 CanNetwork)    **
**                                                                            **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  Can_Nework: CANTRCV channel Number                        **
**                  Value:  Mode to set                                       **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    This function will set the Mode of the can Network         **
**                                                                            **
**                                                                            **
*******************************************************************************/
static void CanTrcv_lSetChannelMode(uint8 CanNetwork)
{
   #if (CANTRCV_17_6251G_INIT_SLEEP_STATE == STD_ON)
   volatile uint32 Timeout;
   #endif

   /* Update the CAN transceiver hardware to Configured mode */
   /*IFX_MISRA_RULE_17_04_STATUS=Can_Network value will be within the range 
   and pointer arithemetic will not cause side-effects*/
   Dio_WriteChannel(CanTrcv6251G_kChannel[CanNetwork][NSTB_POS], \
   (Dio_LevelType)
   ((uint8)(CanTrcv6251G_KCtrlPin[CanNetwork] & NSTB_MASK)>>NSTB_SHIFT));
   Dio_WriteChannel(CanTrcv6251G_kChannel[CanNetwork][EN_POS], \
        (Dio_LevelType)((uint8)CanTrcv6251G_KCtrlPin[CanNetwork]& EN_MASK));
            
    #if (CANTRCV_17_6251G_INIT_SLEEP_STATE == STD_ON)
    /*Check whether CAN transceiver is configured to Sleep mode*/
    if(CanTrcv6251G_NetworkMode[CanNetwork] == CANTRCV_TRCVMODE_SLEEP)
    {
      
       Timeout = (uint32)CANTRCV_17_6251G_WAIT_COUNT;
       /* If CAN transceiver is configured to Sleep mode, 
          then delay is required. */
       while (Timeout > CANTRCV_ZERO_U)
       {
            Timeout--;
       } 
    }
    #endif
             
    CanTrcv_lPutCurMode(CanNetwork,CanTrcv6251G_NetworkMode[CanNetwork]);
    

    /*End of CANTRCV_17_6251G_INIT_SLEEP_STATE */
    return;
}
/* CanTrcv002:CanTrcv_SetOpMode API  */
/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV055,DS_AS_CANTRCV087_CANTRCV089_CANTRCV122,
DS_AS403_CANTRCV002, DS_AS403_CANTRCV103, DS_AS403_CANTRCV158_CANTRCV085,
DS_AS403_CANTRCV102_CANTRCV105_CANTRCV120_CANTRCV121_CANTRCV123_CANTRCV161_CANTRCV114_CANTRCV117,
DS_AS403_CANTRCV104]                                                         **
** Syntax : Std_ReturnType CanTrcv_17_6251G_SetOpMode                        **
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
** Description : Sets the Transceiver to the specified mode.                 **
** CanTrcv102: The function CanTrcv_SetOpMode shall switch the internal state**
**             of channel Transceiver to the value of the parameter OpMode   **
**             which can be CANTRCV_NORMAL, CANTRCV_STANDBY or CANTRCV_SLEEP.**
**                                                                           **
**             This API is applicable to each transceiver with each value for**
**             parameter CanTrcv_SetOpMode regardless of whether the         **
**             transceiver hardware supports these modes or not.             **
** CanTrcv105: If the requested mode is not supported by the underlying      **
**             transceiver hardware, the function CanTrcv_SetOpMode shall    **
**             return E_NOT_OK.                                              **
** CanTrcv158: The CanTrcv module shall invoke the callback function         **
**             CanIf_TrcvModeIndication, for each mode switch request        **
**             with call to CanTrcv_SetOpMode,after the requested mode       **
**             has been reached.                                             **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6251G_SetOpMode(uint8 Transceiver,
CanTrcv_TrcvModeType OpMode )
{
  volatile uint32 Timeout;
  Std_ReturnType ReturnValue;
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  CanTrcv_TrcvModeType CurrentMode;
  #endif

  /* Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

  Std_ReturnType DevErrorExists;

  CurrentMode = CANTRCV_TRCVMODE_NORMAL;

  /*  If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_SETOPMODE)  ;

  if (DevErrorExists == E_OK)
  {
    /*  If called with an invalid network number CanNetwork */
    DevErrorExists = CanTrcv_lCheckNetwork(Transceiver,CANTRCV_SID_SETOPMODE);
  }

  if (DevErrorExists == E_OK)
  {
    CurrentMode = Cantrcv_CurrentMode[Transceiver];

    if (OpMode == CANTRCV_TRCVMODE_STANDBY)
    {
        /* CanTrcv120: If the function CanTrcv_SetOpMode is called with
      OpMode== STANDBY and the channel CanNetwork is not
      in mode NORMAL or STANDBY Report error to DET. */

        if((CurrentMode != CANTRCV_TRCVMODE_NORMAL )  \
        && (CurrentMode != CANTRCV_TRCVMODE_STANDBY ))
        {
          Det_ReportError(
                      CANTRCV_17_6251G_MODULE_ID,
                      CANTRCV_17_6251G_INSTANCE_ID,
                      CANTRCV_SID_SETOPMODE,
                      CANTRCV_E_TRCV_NOT_NORMAL
                    );
          DevErrorExists = E_NOT_OK;
        }
    }
  }
  if (DevErrorExists == E_OK)
  {
    if (OpMode == CANTRCV_TRCVMODE_SLEEP)
    {
        /* CanTrcv121: If the function CanTrcv_SetOpMode is called with
      OpMode== SLEEP and the channel CanNetwork is not
      in mode STANDBY or SLEEP Report error to DET. */

        if ((CurrentMode!= CANTRCV_TRCVMODE_STANDBY )
               && (CurrentMode != CANTRCV_TRCVMODE_SLEEP)
              )
        {
        Det_ReportError(
                      CANTRCV_17_6251G_MODULE_ID,
                      CANTRCV_17_6251G_INSTANCE_ID,
                      CANTRCV_SID_SETOPMODE,
                      CANTRCV_E_TRCV_NOT_STANDBY
                    );
        DevErrorExists = E_NOT_OK;
        }
    }
  }
  if (DevErrorExists == E_OK)
  {
  /* CanTrcv132: If called with InvalidOpMode */
  if ((OpMode != CANTRCV_TRCVMODE_NORMAL) && 
      (OpMode != CANTRCV_TRCVMODE_STANDBY)
     && (OpMode != CANTRCV_TRCVMODE_SLEEP))
  {
    /* Paramter is not valid. Report error to DET. */
     Det_ReportError(
                     CANTRCV_17_6251G_MODULE_ID,
                     CANTRCV_17_6251G_INSTANCE_ID,
                     CANTRCV_SID_SETOPMODE,
                     CANTRCV_E_PARAM_TRCV_OPMODE
                   );
     DevErrorExists = E_NOT_OK;
  }

  }
  if (DevErrorExists == E_OK)
  {
     DevErrorExists = CanTrcv_lDetTest(Transceiver,CANTRCV_SID_SETOPMODE);

  }
  

  if (DevErrorExists == E_NOT_OK)
  {
    ReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  else
  {
  #endif
   /*(CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */
  /* End of DET error switch */
  {
    if (OpMode == CANTRCV_TRCVMODE_NORMAL)
    {
  if(Cantrcv_CurrentMode[Transceiver] != CANTRCV_TRCVMODE_NORMAL)
  {
      if (Dio_ReadChannel(CanTrcv6251G_kChannel[Transceiver][NERR_POS]))
      {
        /* No Notifucation is called if call to
        CanTrcv_Goto_NormalMode has caused wake up */

        CanTrcv_lPutWuReason(Transceiver,CANTRCV_WU_INTERNALLY);
      }
    }
      /* Set the CAN transceiver hardware to Normal mode. */
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][NSTB_POS], \
                                      (Dio_LevelType)NORMAL_NSTB_VAL);
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][EN_POS], \
                                      (Dio_LevelType)NORMAL_EN_VAL); 

      /* Update the Current mode as Normal */
      CanTrcv_lPutCurMode(Transceiver,CANTRCV_TRCVMODE_NORMAL);

    }/*  end of( OpMode == CANTRCV_TRCVMODE_NORMAL) */
    else if (OpMode == CANTRCV_TRCVMODE_STANDBY)
    {
      /* Set the CAN transceiver hardware to Standby mode. */
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][NSTB_POS], \
                                (Dio_LevelType)(STANDBY_NSTB_VAL));
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][EN_POS], \
                                (Dio_LevelType)(STANDBY_EN_VAL)); 

      /* Update the Current mode as Stand by */
      CanTrcv_lPutCurMode(Transceiver,CANTRCV_TRCVMODE_STANDBY);
    }
    else /* if( OpMode == CANTRCV_TRCVMODE_SLEEP)*/
    {
      /* Set the CAN transceiver hardware to Sleep mode. */
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][NSTB_POS], \
                                      (Dio_LevelType)(SLEEP_NSTB_VAL));
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][EN_POS], \
                                      (Dio_LevelType)(SLEEP_EN_VAL)); 

      Timeout = (uint32)CANTRCV_17_6251G_WAIT_COUNT;
      while (Timeout > 0U)
      {
        Timeout--;
      }
      /* Update the Current mode as Sleep */
      CanTrcv_lPutCurMode(Transceiver,CANTRCV_TRCVMODE_SLEEP);
    }

    /*Invoke call back function after each mode switch*/
   CanIf_TrcvModeIndication(Transceiver,OpMode);

    /* Set return value to E_OK */
   ReturnValue = (Std_ReturnType)E_OK;
  }
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  }
  #endif
  /*CanTrcv158: The CanTrcv module shall invoke the callback function
                         CanIf_TrcvModeIndication, for each mode switch request
                        with call to CanTrcv_SetOpMode,after the requested mode
                         has been reached.*/

    /* If No DET raised, returns E_OK , else return with E_NOT_OK*/

  return (ReturnValue);

} /* End of CanTrcv_SetOpMode function */

/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV106_CANTRCV124_CANTRCV132,
DS_AS403_CANTRCV005, DS_AS403_CANTRCV115_CANTRCV129, 
]
** Syntax : Std_ReturnType CanTrcv_17_6251G_GetOpMode                        **
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
**                                to be applied.                             **
**                  OpMode - Pointer to the operation mode of the bus the API**
**                           is applied too.                                 **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description :  Returns the actual state of specified Transceiver          **
** CanTrcv106: The function CanTrcv_GetOpMode shall return the actual        **
**             state of the CAN transceiver driver in the parameter OpMode.  **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6251G_GetOpMode(
  uint8 Transceiver, CanTrcv_TrcvModeType* OpMode
)
{

  Std_ReturnType DevErrorExists ;

  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */

  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

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
                       CANTRCV_17_6251G_MODULE_ID,
                       CANTRCV_17_6251G_INSTANCE_ID,
                       CANTRCV_SID_GETOPMODE,
                       CANTRCV_E_PARAM_POINTER
                     );
      DevErrorExists = E_NOT_OK ;
    }
  }
  if (DevErrorExists == E_OK)
  {
      /* Check for DET errors */
     DevErrorExists = CanTrcv_lDetTest(Transceiver,CANTRCV_SID_GETOPMODE);

     /*CanTrcv115: If there is no/incorrect communication to the transceiver,
     report DET error */
  }
  if (DevErrorExists == E_OK)
  {
  #endif
  /* End of DET error switch */
  {
    /* Current mode of the Bus */
    *OpMode = Cantrcv_CurrentMode[Transceiver];

    /* Set return value to E_OK */
   DevErrorExists = (Std_ReturnType)E_OK;
  }
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  }
  #endif

  /* If No DET raised, returns E_OK */
  return (DevErrorExists);

} /* End of CanTrcv_17_6251G_GetOpModeMode function */


/* CanTrcv007:CanTrcv_GetBusWuReason API  */
/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV090, DS_AS_CANTRCV107_CANTRCV125_CANTRCV133,
DS_AS403_CANTRCV007, DS_AS403_CANTRCV116_CANTRCV130
]
** Syntax : Std_ReturnType CanTrcv_17_6251G_GetBusWuReason                  **
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
**                                to be applied.                             **
**                  reason - Pointer to wakeup Reasonof the bus the API is   **
**                           applied to.                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description : Returns the Wake up reason of specified Transceiver         **
** CanTrcv107: The function CanTrcv_GetBusWuReason shall return the reason   **
**             for the wake up that the CAN transceiver has detected.        **
**             The ability to detect and differentiate the possible wakeup   **
**             reasons depends strongly on the CAN transceiver hardware.     **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6251G_GetBusWuReason(
 uint8 Transceiver, CanTrcv_TrcvWakeupReasonType* reason
)
{
  Std_ReturnType DevErrorExists ;

  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)


  /* CanTrcv125: If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_GETBUSWUREASON);

  if (DevErrorExists == E_OK)
  {

    /* CanTrcv130: If called with an invalid network number CanNetwork */
    DevErrorExists = CanTrcv_lCheckNetwork(Transceiver,
                               CANTRCV_SID_GETBUSWUREASON);

  }

  if (DevErrorExists == E_OK)
  {
     /* CanTrcv133: If called with OpMode==NULL */
    if (reason == NULL_PTR)
    {
      /* Paramter is not valid. Report error to DET. */
      Det_ReportError(
                       CANTRCV_17_6251G_MODULE_ID,
                       CANTRCV_17_6251G_INSTANCE_ID,
                       CANTRCV_SID_GETBUSWUREASON,
                       CANTRCV_E_PARAM_POINTER
                     );

      DevErrorExists = E_NOT_OK;
    }
  }
  
  if (DevErrorExists == E_OK)
  {
     /* Check for DET errors */
     DevErrorExists = CanTrcv_lDetTest(Transceiver,CANTRCV_SID_GETBUSWUREASON);
  }
  
  if (DevErrorExists == E_OK)
  {
  #endif

   /*(CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */
  {
    /* return the wake up reason. */
    *reason = (CanTrcv_TrcvWakeupReasonType)Cantrcv_WuReason[Transceiver];

  /* If No DET raised, returns E_OK else retrun with E_NOT_OK */
   DevErrorExists = E_OK;

  }
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  }

  #endif
  return (DevErrorExists);
} /* End of CanTrcv_17_6251G_GetBusWuReason function */

/* CanTrcv009:CanTrcv_SetWakeupMode API  */
/******************************************************************************
** Traceability : [cover parentID=
DS_AS_CANTRCV127,
DS_AS403_CANTRCV009, 
DS_AS403_CANTRCV093_CANTRCV094_CANTRCV095_CANTRCV111_CANTRCV131, 
]
** Syntax : Std_ReturnType CanTrcv_17_6251G_SetWakeupMode                    **
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
** Return value:  E_OK                                                       **
**                E_NOT_OK                                                   **
**                                                                           **
** Description : This function enables, disables and clears the              **
**               notification for wake up events on the addressed Network.   **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6251G_SetWakeupMode(
   uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode
)
{
  Std_ReturnType DevErrorExists ;

  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

  /* CanTrcv127: If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_SETWAKEUPMODE);

  if (DevErrorExists == E_OK)
  {
    /* CanTrcv131: If called with an invalid network number CanNetwork */
    DevErrorExists = CanTrcv_lCheckNetwork(Transceiver,
                                       CANTRCV_SID_SETWAKEUPMODE);
  }

  if (DevErrorExists == E_OK)
  {
    /* CanTrcv133: If called with OpMode==NULL */
    if ((TrcvWakeupMode != CANTRCV_WUMODE_ENABLE) &&
       (TrcvWakeupMode != CANTRCV_WUMODE_DISABLE) &&
       (TrcvWakeupMode != CANTRCV_WUMODE_CLEAR))
      {

        /* Paramter is not valid. Report error to DET. */
        Det_ReportError(
                         CANTRCV_17_6251G_MODULE_ID,
                         CANTRCV_17_6251G_INSTANCE_ID,
                         CANTRCV_SID_SETWAKEUPMODE,
                         CANTRCV_E_PARAM_TRCV_WAKEUP_MODE
                       );
        DevErrorExists = E_NOT_OK;

    }
  }
  
  if (DevErrorExists == E_OK)
  {
      /* Check for DET errors */
     DevErrorExists = CanTrcv_lDetTest(Transceiver,CANTRCV_SID_SETWAKEUPMODE);

    /*If there is no/incorrect communication to the transceiver,
    report DET error */

  }
  if (DevErrorExists == E_OK)
  {   
  #endif
  /*(CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */ 
  {
    /* CanTrcv117: If the function CanTrcv_SetWakeupMode is called with
     TrcvWakupMode==CANTRCV_WUMODE_ENABLE and if the CanTrcv module has a
     stored wakeup event pending for the addressed bus, the CanTrcv module
     shall execute the notification within the API call or immediately after*/

    if (TrcvWakeupMode == CANTRCV_WUMODE_ENABLE)
    {
      /* Enable the wake up for the related bus */
      CanTrcv_lWakeup(Transceiver,CANTRCV_WUMODE_ENABLE);

      /* Check for pending wakeup events */
      if (CANTRCV_PENWU_SET == CanTrcv_lGetPendWakeup(Transceiver))
      {
        /* Call the wake up event function from CAN interface. */
        CanTrcv_WakeupFlagIndication[Transceiver] = CANTRCV_ONE_U;
      }
    }
    /* CanTrcv093: Disabled: If the function CanTrcv_SetWakeupMode is
     called with TrcvWakeupMode==CANTRCV_WUMODE_DISABLE, then the notifications
     for wakeup events are disabled on the addressed network. */

    else if (TrcvWakeupMode == CANTRCV_WUMODE_DISABLE)
    {
      /* Disable the notification  */
      CanTrcv_lWakeup(Transceiver,CANTRCV_WUMODE_DISABLE);
    }
    /* CanTrcv094: Clear: If the function CanTrcv_SetWakeupMode is called with
     TrcvWakeupMode==CANTRCV_WUMODE_CLEAR, then a stored wakeup event is
     cleared on the addressed network. */

    else /* if( TrcvWakeupMode == CANTRCV_WUMODE_CLEAR)*/
    {
      /* Clear the pending wakeup events. */
      CanTrcv_lClearPendWakeup(Transceiver);

      /* Clear the wake up for the related bus */
      CanTrcv_lWakeup(Transceiver,CANTRCV_WUMODE_CLEAR);

    }
    /* Set Return Value to E_OK */
    DevErrorExists = (Std_ReturnType)E_OK;
  }
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  }
  #endif
  /* If No DET raised, returns E_OK, otherwise return E_NOT_OK */
  return (DevErrorExists);
} /* End of CanTrcv_17_6251G_SetWakeupMode function */

#if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING)
/* CanTrcv013:CanTrcv_MainFunction API  */
/*******************************************************************************
** Traceability : [cover parentID=
DS_AS_6251G_CANTRCV013, DS_AS_6251G_CANTRCV112_CANTRCV128,
DS_AS403_6251G_CANTRCV091
]
** Syntax : void CanTrcv_17_6251G_MainFunction ( void )                       **
** [/cover]                                                                   **
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
void CanTrcv_17_6251G_MainFunction()
{

  volatile uint8 Can_Network = CANTRCV_ZERO_U;
  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

  Std_ReturnType DevErrorExists;

  /* CanTrcv128: If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_MAINFUNCTION);

  if (DevErrorExists == E_OK)
  {
  #endif
   /*(CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */

  /* CanTrcv112: The CanTrcv_MainFunction shall scan all busses in STANDBY and
     SLEEP for wake up events and shall perform these events by calling
     the appropriate callback function. */
    while(Can_Network < CANTRCV_17_6251G_CHANNELS_CFG)
   {
      /* Check for valid wake up */
      CanTrcv_lCheckWakeup(Can_Network);
      Can_Network++;
  }
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  }
  #endif

  return;
} /* End of CanTrcv_MainFunction function */
#endif
/*End Of
(CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT == CANTRCV_WAKE_UP_BY_POLLING) */


/******************************************************************************
** Traceability : [cover parentID=
DS_AS403_CANTRCV143, DS_AS403_CANTRCV144, DS_AS403_CANTRCV145, 
DS_AS403_CANTRCV146, 
]
** Syntax : Std_ReturnType CanTrcv_17_6251G_CheckWakeup(uint8 Transceiver)   **
** [/cover]                                                                  **
**                                                                           **
** Service ID:  0x07                                                         **
**                                                                           **
** Sync/Async:  Synchronous                                                  **
**                                                                           **
** Reentrancy:  non reentrant                                                **
**                                                                           **
** Parameters (in): Transceiver - Transceiver to which the API               **
**                               call has to be applied.                     **
** Parameters (out):  E_OK :when a valid interrupt is detected               **
**                    E_NOT_OK : when a no interrupt is detected             **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description :                                                             **
** CanTrcv012: This function is called by underlying SPAL CANIF driver in    **
**                  case a wake up interrupt is detected. The API validates  **
**                  wake up reason in terms whether it is a wake up or not.  **
**                                                                           **
******************************************************************************/
Std_ReturnType CanTrcv_17_6251G_CheckWakeup(uint8 Transceiver)
{
  Std_ReturnType DevErrorExists ;

  /* CanTrcv040: Detected development errors will be reported to the error hook
  of the Development Error Tracer (Det) if the pre-processor switch
  CanTrcvDevErrorDetect is set. */
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

  /* CanTrcv135: If called before the CanTrcv module has been initialized */
  DevErrorExists = CanTrcv_lCheckUninitDet(CANTRCV_SID_CHECKWAKEUP);

  if (DevErrorExists == E_OK)
  {
    /* CanTrcv130: If called with an invalid network number CanNetwork */
    DevErrorExists = CanTrcv_lCheckNetwork(Transceiver,
                            CANTRCV_SID_CHECKWAKEUP);
  }

  if (DevErrorExists == E_OK)
  {

  #endif
   /* End of (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON) */

  /* if the flag is set then return E_OK*/
  if(CanTrcv_WakeupFlagIndication[Transceiver])
  {
    CanTrcv_WakeupFlagIndication[Transceiver] = 0U;
    if (CANTRCV_TRCVMODE_SLEEP == Cantrcv_CurrentMode[Transceiver])
    {
       /* Set the CAN transceiver hardware to Standby mode,
       workaroud to release WKP flag in SLEEP Mode */
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][NSTB_POS], \
                                 (Dio_LevelType)(STANDBY_NSTB_VAL));
         Dio_WriteChannel(CanTrcv6251G_kChannel[Transceiver][EN_POS], \
                                 (Dio_LevelType)(STANDBY_EN_VAL)); 

      /* Update the Current Mode of Bus to STANDBY because
      any Wake up in SLEEP mode, Cantrcv hardware will go to STANDBY mode. */
       CanTrcv_lPutCurMode(Transceiver,CANTRCV_TRCVMODE_STANDBY);

    }  /* End of SLEEP Mode */

    DevErrorExists = E_OK;
    /* Update Wakeup event to EcuM */
    EcuM_SetWakeupEvent(((uint32)1U) << CanTrcv_kWakeupSourceRef[Transceiver]);
  }
  else
  {
    DevErrorExists = E_NOT_OK;
  }
  #if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
  }
  #endif

  return (DevErrorExists);
}  /* End of CanTrcv_17_6251G_CheckWakeUp function */


/******************************************************************************
**                      Private Function Definitions                         **
******************************************************************************/
#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)
/******************************************************************************
** Syntax: static Std_ReturnType CanTrcv_lDetTest(uint8 CanNetwork,uint8 ApiId)
**                                                                           **
** Service ID:  none                                                         **
**                                                                           **
** Sync/Async:  none                                                         **
**                                                                           **
** Reentrancy:  none                                                         **
**                                                                           **
** Parameters (in): none                                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  E_OK: No Production error                                  **
**                E_NOT_OK: Production Error                                 **
**                                                                           **
** Description : Local functon:                                              **
**  Function to detect DET error for no/incorrect communication to the       **
**  transceiver.                                                             **
******************************************************************************/
static Std_ReturnType CanTrcv_lDetTest(uint8 CanNetwork, uint8 ApiId)
{
  Std_ReturnType retValue;

  CanTrcv_TrcvModeType CurrentMode;

  CurrentMode = Cantrcv_CurrentMode[CanNetwork];

  /* Production error is not present */
  retValue =(Std_ReturnType) E_OK;

 /* If Network is not communicating. Report error to DET. */ 
    if ((Dio_ReadChannel(CanTrcv6251G_kChannel[CanNetwork][NERR_POS])== 0U) && \
          (CurrentMode == CANTRCV_TRCVMODE_NORMAL ))
      {
        /* Report to DET */
        Det_ReportError(CANTRCV_17_6251G_MODULE_ID, 
                        CANTRCV_17_6251G_INSTANCE_ID, 
                        ApiId, 
                        CANTRCV_E_NO_TRCV_CONTROL); 

        retValue = (Std_ReturnType)E_NOT_OK;
      }
  return (retValue);

} /* End of CanTrcv_lDetTest function */
#endif
/*#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)*/


#if (CANTRCV_17_6251G_GENERAL_WAKE_UP_SUPPORT != CANTRCV_WAKE_UP_NOT_SUPPORTED)
/******************************************************************************
** Syntax: static void CanTrcv_lCheckWakeup(uint8 CanNetwork)                **
**                                                                           **
** Service ID:  none                                                         **
**                                                                           **
** Sync/Async:  none                                                         **
**                                                                           **
** Reentrancy:  none                                                         **
**                                                                           **
** Parameters (in): none                                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Local functon:                                              **
**              This function is used to detect valid wakeup in network.     **
******************************************************************************/
static void CanTrcv_lCheckWakeup(uint8 CanNetwork)
{  
  /* Check for valid wakeup event */
  if (Dio_ReadChannel(CanTrcv6251G_kChannel[CanNetwork][NERR_POS]) == 0U)
  {

    if (Cantrcv_CurrentMode[CanNetwork] == CANTRCV_TRCVMODE_NORMAL )
    {
      
    }   /* End of NORMAL Mode */    
    else
    {
      /* Check if Wakeup is enabled for the specified network */

      if (CanTrcv_kWakeupFlag[CanNetwork])
      {
        /* Set the Wake up reason to Wake up by bus */
        CanTrcv_lPutWuReason(CanNetwork,CANTRCV_WU_BY_BUS);

        /* If Wake is detected & Current mode is SLEEP or STANDBY
        Check for Enabled the wake up */
        if (CANTRCV_WUMODE_ENABLE == CanTrcv_Wakeup[CanNetwork])
        {

          /* Update Wakeup event to CAN interface. */
          CanTrcv_WakeupFlagIndication[CanNetwork] = CANTRCV_ONE_U;

        }
        else if (CANTRCV_WUMODE_DISABLE == CanTrcv_Wakeup[CanNetwork])
        {

          /* Update the pending wakeup event*/
          CanTrcv_lSetPendWakeup(CanNetwork);

        }
        else /* if(CANTRCV_WUMODE_CLEAR == CanTrcv_Wakeup[CanNetwork])*/
        {
          /* Do nothing - added for Misra check */
        }

      }
    }
  }
  return ;
} /* End of CanTrcv_lCheckWakeup function */
#endif
/* End of Wakeup support != CANTRCV_WAKE_UP_NOT_SUPPORTED */

/******************************************************************************
** Syntax: static void CanTrcv_lCheckInitWakeup(uint8 CanNetwork )           **
**                                                                           **
** Service ID:  none                                                         **
**                                                                           **
** Sync/Async:  none                                                         **
**                                                                           **
** Reentrancy:  none                                                         **
**                                                                           **
** Parameters (in): none                                                     **
**                                                                           **
** Parameters (out):  none                                                   **
**                                                                           **
** Return value:  none                                                       **
**                                                                           **
** Description : Local functon:                                              **
**              This function is used to detect wakeup in Init function.     **
******************************************************************************/
static void CanTrcv_lCheckInitWakeup(uint8 CanNetwork)
{
    /* Initially Disable the Wakeup for the channel */
  CanTrcv_lWakeup(CanNetwork, CANTRCV_WUMODE_ENABLE);

  /* Initially Pending Wakeup is cleared for Bus 0 */
  CanTrcv_lClearPendWakeup(CanNetwork);

  /* Default Wakeup reason for Bus is Power ON */
  CanTrcv_lPutWuReason(CanNetwork, CANTRCV_WU_POWER_ON);
    
  /* Check if Wakeup is enabled for the specified network */
  if (CanTrcv_kWakeupFlag[CanNetwork])
  {
    /* Check for Wake up by bus */
    if (Dio_ReadChannel(CanTrcv6251G_kChannel[CanNetwork][NERR_POS]) == 
      CANTRCV_ZERO_U)
    {
      /* Set the Wake up reason to Wake up by bus */
      CanTrcv_lPutWuReason(CanNetwork,CANTRCV_WU_BY_BUS);
      /* Update Wakeup event to EcuM */
      EcuM_SetWakeupEvent(((uint32)1U) << CanTrcv_kWakeupSourceRef[CanNetwork]);
    }
  }

  /* Update default mode as Normal ,Workaround for Hardware Issue
  to Detect wakeup's if CantrcvInitstate is STANDBY/SLEEP  */
         Dio_WriteChannel(CanTrcv6251G_kChannel[CanNetwork][NSTB_POS], \
                 (Dio_LevelType)(NORMAL_NSTB_VAL));
         Dio_WriteChannel(CanTrcv6251G_kChannel[CanNetwork][EN_POS], \
                     (Dio_LevelType)(NORMAL_EN_VAL)); 

  /* Update the Current mode as Normal */
  CanTrcv_lPutCurMode(CanNetwork,CANTRCV_TRCVMODE_NORMAL);

  return;
} /* End of CanTrcv_lCheckInitWakeup function */


#if (CANTRCV_17_6251G_DEV_ERROR_DETECT == STD_ON)

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
** Return value:    None                                                      **
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
    Det_ReportError(CANTRCV_17_6251G_MODULE_ID, CANTRCV_17_6251G_INSTANCE_ID,
                    serviceId, CANTRCV_E_UNINIT);
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
  if (networkid > (CANTRCV_17_6251G_CHANNELS_CFG - 1U))
  {

    /* Driver not initialized. Report error to DET. */
    Det_ReportError(CANTRCV_17_6251G_MODULE_ID, CANTRCV_17_6251G_INSTANCE_ID,
                    serviceId, CANTRCV_E_INVALID_TRANSCEIVER);
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
** Syntax:   IFX_LOCAL_INLINE uint8 CanTrcv_lGetPendWakeup(uint8 CanNetwork)  **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                            **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  CanNetwork: Network ID / channel Number                   **
**                                                                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    function to get the pending wakeup's of the network,if any **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint8 CanTrcv_lGetPendWakeup(uint8 CanNetwork)
{
 return ((CanTrcv_PendWakeup >> CanNetwork) & 0x01U )  ;
}

/*******************************************************************************
** Syntax:  IFX_LOCAL_INLINE void CanTrcv_lSetPendWakeup(uint8 CanNetwork)    **
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                           **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  CanNetwork: Network ID / channel Number                   **
**                                                                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:     Function to Set the pending wakeup's of the network       **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void CanTrcv_lSetPendWakeup(uint8 CanNetwork)
{
  CanTrcv_PendWakeup |= (uint8)( (uint32)1U << CanNetwork ) ;
}

/*******************************************************************************
** Syntax:    IFX_LOCAL_INLINE void CanTrcv_lClearPendWakeup(uint8 CanNetwork)**
**                                                                            **
** Sync/Async:      Synchronous                                               **
**                                                                           **
** Reentrancy:      Reentrant                                                 **
**                                                                            **
** Parameters(in):  CanNetwork: Network ID / channel Number                   **
**                                                                            **
** Parameters(out): None                                                      **
**                                                                            **
** Return value:    None                                                      **
**                                                                            **
** Description:    function to Clear the pending wakeup of the network        **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void CanTrcv_lClearPendWakeup(uint8 CanNetwork)
{
  CanTrcv_PendWakeup &= (uint8)(~((uint32)1 << CanNetwork ));
}

#define CANTRCV_17_6251G_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
