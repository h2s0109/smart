/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Sent.c $                                                   **
**                                                                           **
**  $CC VERSION : \main\29 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-18 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains functionality of SENT driver.           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of SENT Register description file */
#include "IfxSent_reg.h"

/* Inclusion of SRC Register description file */
#include "IfxSrc_reg.h"

/* Pre-compile/static configuration parameters for SENT  */
/* Includes Own header file Sent.h */
#include "Sent.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#ifndef SENT_SW_MAJOR_VERSION
  #error "SENT_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef SENT_SW_MINOR_VERSION
  #error "SENT_SW_MINOR_VERSION is not defined. "
#endif

#ifndef SENT_SW_PATCH_VERSION
  #error "SENT_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( SENT_SW_MAJOR_VERSION != 0U )
  #error "SENT_SW_MAJOR_VERSION does not match. "
#endif
#if ( SENT_SW_MINOR_VERSION != 2U )
  #error "SENT_SW_MINOR_VERSION does not match. "
#endif

#if (SENT_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif
#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if (IFX_DET_VERSION_CHECK == STD_ON)

#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif /* (IFX_DET_VERSION_CHECK == STD_ON) */

#endif /*#if (SENT_DEV_ERROR_DETECT == STD_ON)*/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#if(SENT_DEV_ERROR_DETECT == STD_ON)
/* Status indicating the Channel is not configured */
#define SENT_CHAN_NOT_CONFIGURED   ((sint8)-1)
#endif  /*(SENT_DEV_ERROR_DETECT == STD_ON)*/

#define SENT_SAFETY_ENDINIT_TIMEOUT (150000U)

#define SENT_SPCCONFIG_TRIGSRC_SHIFT  (6U)
#define SENT_SPCCONFIG_DELAY_SHIFT    (8U)
#define SENT_SPCCONFIG_TIMEBASE_SHIFT (14U)

#define SENT_KERNEL_RESET_WAIT_COUNT  (0x00000100U)

/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define SENT_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if (SENT_DEV_ERROR_DETECT == STD_ON)
/* function to verify DET check */
static uint32 Sent_lDetCheck(uint8 ServiceID,
                                       Sent_ChannelIdxType ChannelId,
                                       const void * Ptr);
#endif

#if((SENT_RESET_SFR_AT_INIT == STD_ON) || (SENT_DEINIT_API == STD_ON))
/* Function to reset Kernels */
static void Sent_lResetKernels(uint8 ServiceId);
#endif

#define SENT_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define SENT_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/* Global array of function pointers for respective Channels */
static Sent_NotifFnPtrType Sent_FnCbkPtr[SENT_HW_MAX_CHANNELS];

/* To store the Sent driver configuration pointer */
const Sent_ConfigType  *Sent_kConfigPtr;

#define SENT_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/* Start 8 bit variable section */
#define SENT_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if(SENT_DEV_ERROR_DETECT == STD_ON)

/* Init Status Variable. It has to be initialized to "0U" after every reset as 0
   represents the deinitialized state */
static uint8 Sent_InitStatus;

/* Internal SENT channel mapping to determine the exact ChannelId */
static sint8 Sent_ChannelMap[SENT_HW_MAX_CHANNELS];
#endif  /*(SENT_DEV_ERROR_DETECT == STD_ON)*/

/* Stop 8 bit variable section */
#define SENT_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Mapping the code */
#define SENT_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1693_PR1694_PR1695,
                                       DS_NAS_SENT_PR1696_PR1697]             **
**                                                                            **
** Syntax           : void Sent_Init                                          **
**                    (                                                       **
**                      const Sent_ConfigType *ConfigPtr                      **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to SENT configuration               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                      - Initializes the SENT Module, Baud Rate registers    **
**                      - Also configures the respective Channels registers   **
*******************************************************************************/
void Sent_Init (const Sent_ConfigType *ConfigPtr)
{
  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  uint8 DetError;
  DetError = 0U;

  #if (SENT_PB_FIXED_ADDRESS == STD_ON)
  if (ConfigPtr != &Sent_ConfigRoot[0])
  #else
  if (ConfigPtr == NULL_PTR)
  #endif
  {
    /* Report SENT_E_PARAM_INVAID DET */
    Det_ReportError(
      (uint16)SENT_MODULE_ID,
      SENT_INSTANCE_ID,
      SENT_SID_INIT,
      SENT_E_PARAM_INVALID);
    /* Skip the API functionality and return from the API */
    DetError = 1U;
  }

  if (DetError == 0U)
  #endif /* SENT_DEV_ERROR_DETECT == STD_ON */
  {
    volatile uint32 ReadBack;
    uint32 TempVal;
    Sent_ChannelIdxType ChanIndex;
    Sent_ChannelIdxType ChannelId;

    /* Clear the ENDINIT bit in the WDT_CONSR register  in order to disable the
    write-protection for registers protected via the EndInit feature */
    SENT_SFR_INIT_RESETENDINIT();

    /* Enable the SENT module clock */
    SENT_SFR_INIT_WRITE32(SENT_CLC.U,ConfigPtr->ModuleClkDiv);

    /*Set the ENDINIT bit in the WDT_CONSR register in order to enable the
    write-protection for registers protected via the EndInit feature */
    SENT_SFR_INIT_SETENDINIT();

    /* Read back the CLC register to flush the pipeline effects */
    ReadBack = SENT_SFR_INIT_USER_MODE_READ32(SENT_CLC.U);

    UNUSED_PARAMETER(ReadBack)

    /*Clear the ENDINIT bit in the WDT_CONSR register in order to disable the
    write-protection for registers protected via the EndInit feature */
    SENT_SFR_INIT_RESETENDINIT();

    /* Check whether SENT_CLC DISS is equal to 0U */
    if(((SENT_SFR_INIT_USER_MODE_READ32(SENT_CLC.U) & \
                          SENT_CLC_DISS_MASK) >> SENT_CLC_DISS_BITPOS) == 0U)
    {
    #if (SENT_RESET_SFR_AT_INIT == STD_ON)
    Sent_lResetKernels(SENT_INIT_ACCESS);
    #endif

    /* Load the Fractional Divider register */
    SENT_SFR_INIT_MODIFY32(SENT_FDR.U, SENT_FDR_STEP_CLEARMASK,\
                                          (uint32)ConfigPtr->ModuleFracDivStep)

    /* Set the Divider Mode in FDR register to 1U */
    SENT_SFR_INIT_MODIFY32(SENT_FDR.U, SENT_FDR_DM_CLEARMASK,\
                                                SENT_FDR_DM_SETMASK)

    /* Configure the TimeStamp Pre-Divider register with the same
     * frequency as fracdiv
    */
    SENT_SFR_INIT_WRITE32(SENT_TPD.U, 0U);

    /*Set the ENDINIT bit in the WDT_CONSR register in order to enable the
    write-protection for registers protected via the EndInit feature */
    SENT_SFR_INIT_SETENDINIT();

    /* The function Sent_Init() shall also initialize all variables
       used by the SENT driver module to an initial state.
       There are no such variables in the SENT module
    */
    for (ChanIndex = 0U; ChanIndex < SENT_HW_MAX_CHANNELS ; ChanIndex++)
    {
      /* Initialize the Function pointers to NULL */
      Sent_FnCbkPtr[ChanIndex] = NULL_PTR;

      #if(SENT_DEV_ERROR_DETECT == STD_ON)
      /* Initialize the ChannelMap */
      Sent_ChannelMap[ChanIndex] = SENT_CHAN_NOT_CONFIGURED;
      #endif
    }
    for (ChanIndex = 0U; ChanIndex < ConfigPtr->NumChannelsConfigured;
                                                                ChanIndex++)
    {
      /* Retrieve the SENT Physical channel id */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Physical Channel Id linked to particular Logical Id*/
      ChannelId = ConfigPtr->ChanCfgPtr[ChanIndex].ChannelId;

      #if(SENT_DEV_ERROR_DETECT == STD_ON)
      /* Assign SENT Channel with ChanIndex */
      Sent_ChannelMap[ChanIndex] = (sint8)ChannelId;
      #endif

      Sent_FnCbkPtr[ChanIndex] = SentNotifFnPtrArray[ChanIndex];

      /* Consolidate the same Interrupt node for all interrupts specific to
       * a channel
       */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      TempVal = ConfigPtr->ChanCfgPtr[ChanIndex].ChanIntNode;
      TempVal = (TempVal << 28U) | (TempVal << 24U) | (TempVal << 20U) |
                (TempVal << 16U) | (TempVal << 12U) | (TempVal << 8U) |
                (TempVal << 4U) | TempVal;

      /* Configure the respective Channel registers */
      /* Update CPDR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].CPDR.U, \
                         (uint32)(ConfigPtr->ChanCfgPtr[ChanIndex].ChanPreDiv));
      /* Update CFDR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].CFDR.U, \
                       (uint32)(ConfigPtr->ChanCfgPtr[ChanIndex].ChanFracDiv));
      /* Update RCR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].RCR.U, \
                                  ConfigPtr->ChanCfgPtr[ChanIndex].ChanRxCtrl);
      /* Update IOCR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].IOCR.U, \
                                  ConfigPtr->ChanCfgPtr[ChanIndex].ChanIOCtrl);
      /* Update VIEW register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].VIEW.U, \
                                 ConfigPtr->ChanCfgPtr[ChanIndex].ChanDataView);
      /* Update INP register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].INP.U, TempVal);

      /* Update INTEN register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      SENT_SFR_INIT_USER_MODE_WRITE32(SENT_CHANNEL[ChannelId].INTEN.U, \
                                                       SENT_CHANNEL_CFG_INTEN);
      /* If more than 8 nibbles are configured per frame, then enable RDI
       * interrupt to be informed that 8 nibbles have been recieved or
       * last frame recieved
       */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      if (ConfigPtr->ChanCfgPtr[ChanIndex].ChanFrameLen >SENT_MIN_CHANFRAMELEN)
      {
        /* Clear RSI in INTEN register */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on
         SENT_CHANNEL to access the SFRs for a particular SENT Channel*/
         SENT_SFR_INIT_USER_MODE_MODIFY32(SENT_CHANNEL[ChannelId].INTEN.U, \
                             SENT_INTEN_RSI_CLEARMASK, 0U)

        /*Enable only RDI interrupt */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on
         SENT_CHANNEL to access the SFRs for a particular SENT Channel*/
         SENT_SFR_INIT_USER_MODE_MODIFY32(SENT_CHANNEL[ChannelId].INTEN.U, \
                             SENT_INTEN_RDI_CLEARMASK, SENT_INTEN_RDI_SETMASK)
      }

      /* Enable the configured SENT Interrupt Node */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_SRC
       to access the Register for a particular SENT Channel*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
       to access the Configuration of a particular Channel*/
      SENT_SFR_INIT_MODIFY32\
                   (SENT_SRC[ConfigPtr->ChanCfgPtr[ChanIndex].ChanIntNode].U, \
                                 SENT_SRC_SRE_CLEARMASK, SENT_SRC_SRE_SETMASK)

       } /* end of for */

    #if (SENT_ACCEN_MODE == SENT_ACCEN_INIT)

    /* Clear the SafetyENDINIT bit in the WDT_CON0 register in order to disable
    the write-protection for registers protected via the EndInit feature */
    SENT_SFR_INIT_RESETSAFETYENDINIT_TIMED(SENT_SAFETY_ENDINIT_TIMEOUT);

    /* Set the ACCEN0 register */
    SENT_SFR_INIT_WRITE32(SENT_ACCEN0.U, ConfigPtr->AccenRegVal);

    /* Set the SafetyENDINIT bit in the WDT_CON0 register in order to enable
    the write-protection for registers protected via the EndInit feature */
    SENT_SFR_INIT_SETSAFETYENDINIT_TIMED();

    #endif

    #if(SENT_DEV_ERROR_DETECT == STD_ON)
    /* Set Status to indicate that initialization is done */
    Sent_InitStatus = SENT_INITIALIZED;
    #endif  /*(SENT_DEV_ERROR_DETECT == STD_ON)*/

    /* Store Sent configuration ptr for access by other APIs */
    Sent_kConfigPtr = ConfigPtr;

    } /*SENT_CLC.B.DISS == 0U*/
   else
   {
   #if (SENT_DEV_ERROR_DETECT == STD_ON)
    /* Set Status to indicate that module is  uninitialized */
   Sent_InitStatus = SENT_UNINITIALIZED;
   #endif/*(SENT_DEV_ERROR_DETECT == STD_ON)*/
   }

  }/* DetError == 0U for SENT_E_PARAM_INVAID */

  return;
}/* End of Function: Sent_Init */

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1705]                    **
**                                                                            **
** Syntax           : void Sent_SetChannel                                    **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      Sent_ChanOpType Operation                             **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : Channel_Id - SENT Channel number                        **
**                    Operation - SENT_ENABLE/SENT_DISABLE                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - Enables/Disables the SENT Channel                   **
*******************************************************************************/
void Sent_SetChannel(Sent_ChannelIdxType ChannelId, Sent_ChanOpType Operation)
{
  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  if (Sent_lDetCheck(SENT_SID_SETCHANNEL, ChannelId, NULL_PTR) == E_OK)
  #endif
  {
    uint8 Flag;
    Sent_ChannelIdxType ChanIdx;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

    Flag = ((Operation == SENT_ENABLE) ? 1U : 0U);

    /* To set the Channel Enable bit in RCR register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
     to access the SFRs for a particular SENT Channel*/
     SENT_SFR_RUNTIME_USER_MODE_MODIFY32(SENT_CHANNEL[ChanIdx].RCR.U, \
                                          SENT_RCR_CEN_CLEARMASK, (uint32)Flag)

  }
  return;
} /* End of Function: Sent_SetChannel */

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1698]                    **
**                                                                            **
** Syntax           : uint32 Sent_ReadData                                    **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId                         **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT Channel whose data has to be read      **
**                                                                            **
** Parameters (out) : Data read from the SENT Channel                         **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - reads the nibbles recieved in the Data register     **
*******************************************************************************/
uint32 Sent_ReadData (Sent_ChannelIdxType ChannelId)
{
  uint32 DataVal;

  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  DataVal = 0U;
  if (Sent_lDetCheck(SENT_SID_READDATA, ChannelId, NULL_PTR) == E_OK)
  #endif
  {
    Sent_ChannelIdxType ChanIdx;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_RDR
       to access the SFR for a particular SENT Channel*/
       DataVal = SENT_SFR_RUNTIME_USER_MODE_READ32(SENT_RDR[ChanIdx].U);

  }

  return DataVal;
} /* End of Function: Sent_ReadData */

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1699_PR1700]             **
**                                                                            **
** Syntax           : void Sent_ReadSerialData                                **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      Sent_RxSerialDataType *DataPtr                        **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT Channel's serial data has to be read   **
**                                                                            **
** Parameters (out) : DataPtr - Data pointer pointing to the serial data read **
**                              from the SENT Channel                         **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - reads the Serial data recieved and collected over   **
**                        several SENT frames                                 **
*******************************************************************************/
void Sent_ReadSerialData(Sent_ChannelIdxType ChannelId,
                                            Sent_RxSerialDataType *DataPtr)
{
  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  if (Sent_lDetCheck(SENT_SID_READSERIALDATA, ChannelId, DataPtr) == E_OK)
  #endif
  {
    Sent_ChannelIdxType ChanIdx;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

    /* To read Serial Data(SD) from SDS register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    DataPtr->Data = (uint16)(SENT_SFR_RUNTIME_USER_MODE_READ32\
                              (SENT_CHANNEL[ChanIdx].SDS.U) & SENT_SDS_SD_MASK);

    /* To read Message ID(MID) from SDS register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    DataPtr->MsgId = (uint8)((SENT_SFR_RUNTIME_USER_MODE_READ32\
      (SENT_CHANNEL[ChanIdx].SDS.U) & SENT_SDS_MID_MASK)>> SENT_SDS_MID_BITPOS);

    /* To read Configuration bit(CON) from SDS register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    DataPtr->Configuration = (uint8)((SENT_SFR_RUNTIME_USER_MODE_READ32\
    (SENT_CHANNEL[ChanIdx].SDS.U) &  SENT_SDS_CON_MASK) >> SENT_SDS_CON_BITPOS);

    /* To read SCRC bits from SDS register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    DataPtr->Crc = (uint8)((SENT_SFR_RUNTIME_USER_MODE_READ32\
   (SENT_CHANNEL[ChanIdx].SDS.U) & SENT_SDS_SCRC_MASK) >> SENT_SDS_SCRC_BITPOS);

  }

  return;
} /* End of Function: Sent_ReadSerialData */

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1703]                    **
**                                                                            **
** Syntax           : void Sent_ReadChannelStatus                             **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      Sent_ChanStatusType *StatPtr                          **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT Channel's status has to be read        **
**                                                                            **
** Parameters (out) : StatPtr - Pointer pointing to the status of the SENT    **
**                              Channel                                       **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - reads the Channel status                            **
**                      - Also collects the Timestamp                         **
*******************************************************************************/
void Sent_ReadChannelStatus (Sent_ChannelIdxType ChannelId,
                                            Sent_ChanStatusType *StatPtr)
{
  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  if (Sent_lDetCheck(SENT_SID_READCHANSTATUS, ChannelId, StatPtr) == E_OK)
  #endif
  {
    Sent_ChannelIdxType ChanIdx;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_TIMESTAMP
       to access the SFR for a particular SENT Channel*/
    StatPtr->RxTimeStamp = SENT_SFR_RUNTIME_USER_MODE_READ32\
                                                   (SENT_TIMESTAMP[ChanIdx].U);
    /* To read Channel status(CST) from RSR register */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    StatPtr->ChanStat = (Sent_ChanStateType)((SENT_SFR_RUNTIME_USER_MODE_READ32\
    (SENT_CHANNEL[ChanIdx].RSR.U) & SENT_RSR_CST_MASK) >> SENT_RSR_CST_BITPOS);

    /* To read SCN bits from RSR register */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    StatPtr->StatCommNibble = (uint8)((SENT_SFR_RUNTIME_USER_MODE_READ32\
    (SENT_CHANNEL[ChanIdx].RSR.U) & SENT_RSR_SCN_MASK) >> SENT_RSR_SCN_BITPOS);

    /* To read CRC bits from RSR register */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    StatPtr->RxCrc = (uint8)(SENT_SFR_RUNTIME_USER_MODE_READ32\
                           ( SENT_CHANNEL[ChanIdx].RSR.U) & SENT_RSR_CRC_MASK);

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    StatPtr->IntStat = SENT_SFR_RUNTIME_USER_MODE_READ32\
                                             (SENT_CHANNEL[ChanIdx].INTSTAT.U);
  }
  return;
} /* End of Function: Sent_ReadChannelStatus */

#if (SENT_SPC_USED == STD_ON)
/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1701_PR1702,
                                       DS_NAS_SENT_PR1708_PR1709]             **
**                                                                            **
** Syntax           : void Sent_SpcGenPulse                                   **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      const Sent_SpcType *SpcCfgPtr                         **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT Channel's status has to be read        **
**                    Sent_SpcType - Pointer to configure the SPC mode and    **
**                                   generate a master pulse                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - generates a Master pulse for SPC Sync transmission  **
**                      - can be used for Bi-Directional mode also            **
*******************************************************************************/
void Sent_SpcGenPulse (Sent_ChannelIdxType ChannelId,
                                              const Sent_SpcType *SpcCfgPtr)
{
  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  uint8 Error;

  Error = 0U;
  if (Sent_lDetCheck(SENT_SID_SPCGENPULSE, ChannelId, SpcCfgPtr) == E_OK)
  #endif
  {
    uint16 TimeOut = SENT_TIMEOUT_VALUE;
    Sent_ChannelIdxType ChanIdx;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

    /* check if Transaction is in progress, before proceeding !!! */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    while ((((SENT_SFR_RUNTIME_USER_MODE_READ32\
    (SENT_CHANNEL[ChanIdx].SCR.U) & SENT_SCR_TRQ_MASK) >> SENT_SCR_TRQ_BITPOS) \
                                                       == 1U) && (TimeOut > 0U))
    {
      /* Wait for Transaction to be completed */
      TimeOut--;
    }

    if (TimeOut == 0U)
    {
      Sent_FnCbkPtr[ChannelId] (ChannelId, SENT_TRANS_INPROGRESS_EVENT);
      /* Skip the API functionality and return from the API */
      Error = 1U;
    }

    if (Error == 0U)
    {
      uint32 SCR_RegVal;

      SCR_RegVal = (SpcCfgPtr->PulseLength) |
        ((uint32)SpcCfgPtr->TriggerSource << SENT_SPCCONFIG_TRIGSRC_SHIFT) |
        ((uint32)SpcCfgPtr->Delay << SENT_SPCCONFIG_DELAY_SHIFT) |
        ((uint32)SpcCfgPtr->TimeBase << SENT_SPCCONFIG_TIMEBASE_SHIFT);

      /* Update SCR register*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
      SENT_SFR_RUNTIME_USER_MODE_WRITE32(SENT_CHANNEL[ChanIdx].SCR.U, \
                                                                   SCR_RegVal);
      if (SpcCfgPtr->Mode == BIDIRECTIONAL_MODE)
      {
        /* Enable Buffer Underflow interrupt also */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on
         SENT_CHANNELto access the SFRs for a particular SENT Channel*/
         SENT_SFR_RUNTIME_USER_MODE_MODIFY32(SENT_CHANNEL[ChanIdx].INTEN.U, \
                              SENT_INTEN_TBI_CLEARMASK, SENT_INTEN_TBI_SETMASK)
      }
    } /* Error == 0U for SENT_E_TRANS_INPROGRESS */
  } /* DetError == 0U for SENT_E_NOT_INITIALIZED */

  return;
} /* End of Function: Sent_SpcGenPulse */
#endif /* SENT_SPC_USED == STD_ON */

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1706]                    **
**                                                                            **
** Syntax           : void Sent_SetWdgTimer                                   **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      uint16 WdgTimerReloadVal                              **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT Channel's status has to be read        **
**                    WdgTimerReloadVal - Watchdog Reload Timer value         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - configures the Channel's watchdog timer             **
*******************************************************************************/
void Sent_SetWdgTimer (Sent_ChannelIdxType ChannelId,uint16 WdgTimerReloadVal)
{
  #if (SENT_DEV_ERROR_DETECT == STD_ON)
  if (Sent_lDetCheck(SENT_SID_CONFIGWDG, ChannelId, NULL_PTR) == E_OK)
  #endif
  {
    Sent_ChannelIdxType ChanIdx;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

    /* To set WDI bits in INTEN to 1U*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    SENT_SFR_RUNTIME_USER_MODE_MODIFY32(SENT_CHANNEL[ChanIdx].INTEN.U, \
                              SENT_INTEN_WDI_CLEARMASK, SENT_INTEN_WDI_SETMASK)

    /* To set WDLx in WDT register to WdgTimerReloadVal */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    SENT_SFR_RUNTIME_USER_MODE_MODIFY32(SENT_CHANNEL[ChanIdx].WDT.U, \
                           SENT_WDT_WDLX_CLEARMASK, (uint32)WdgTimerReloadVal)
  }

  return;
} /* End of Function: Sent_SetWdgTimer */

#if (SENT_ACCEN_MODE == SENT_ACCEN_API)
/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1707_2]                  **
**                                                                            **
** Syntax           : uint32 Sent_GetAccessEnable                             **
**                    (                                                       **
**                    )                                                       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : returns the SENT_ACCEN0 register value                   **
**                                                                            **
** Description      : This function:                                          **
**                      - retrieves the SENT_ACCEN0 register value            **
*******************************************************************************/
uint32 Sent_GetAccessEnable (void)
{
  return ((uint32)SENT_SFR_RUNTIME_USER_MODE_READ32(SENT_ACCEN0.U));
}/* End of Function: Sent_GetAccessEnable */

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1707_1]                  **
**                                                                            **
** Syntax           : void Sent_SetAccessEnable                               **
**                    (                                                       **
**                      uint32 AccenRegVal                                    **
**                    )                                                       **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : AccenRegVal - Register value to be written to ACCEN0    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - sets the SENT_ACCEN0 register                       **
*******************************************************************************/
void Sent_SetAccessEnable (uint32 AccenRegVal)
{

  /* Clear the SafetyENDINIT bit in the WDT_CON0 register in order to disable
  the write-protection for registers protected via the EndInit feature */
  SENT_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(SENT_SAFETY_ENDINIT_TIMEOUT);

  /*Update SENT_ACCEN0 register*/
  SENT_SFR_INIT_WRITE32(SENT_ACCEN0.U,AccenRegVal);

  /* Set the SafetyENDINIT bit in the WDT_CON0 register in order to enable
  the write-protection for registers protected via the EndInit feature */
  SENT_SFR_RUNTIME_SETSAFETYENDINIT_TIMED();


}/* End of Function: Sent_SetAccessEnable */

#endif /* SENT_ACCEN_API */

#if (SENT_DEINIT_API == STD_ON)
/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1693_1]                  **
**                                                                            **
** Syntax           : void Sent_DeInit                                        **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x0A                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                      - De-Initializes the SENT Module and it's registers,  **
**                      - also with respective Channels registers             **
*******************************************************************************/
void Sent_DeInit (void)
{
  Sent_ChannelIdxType ChanIndex;
  Sent_ChannelIdxType ChannelId;

  for (ChanIndex = 0U; ChanIndex < Sent_kConfigPtr->NumChannelsConfigured;
                                                                  ChanIndex++)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
     to access the Physical Channel Id linked to particular Logical Id*/
    ChannelId = Sent_kConfigPtr->ChanCfgPtr[ChanIndex].ChannelId;

    /* Disable the configured Channel registers */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
    SENT_SFR_DEINIT_USER_MODE_MODIFY32(SENT_CHANNEL[ChannelId].RCR.U, \
                                 SENT_RCR_CEN_CLEARMASK, 0U)

    /* Initialize the Function pointers to NULL */
    Sent_FnCbkPtr[ChanIndex] = NULL_PTR;

    #if(SENT_DEV_ERROR_DETECT == STD_ON)
    /* Initialize the ChannelMap */
    Sent_ChannelMap[ChanIndex] = SENT_CHAN_NOT_CONFIGURED;
    #endif

    UNUSED_PARAMETER(ChannelId)
  }

  /* Set to NULL */
  Sent_kConfigPtr = NULL_PTR;

  /* Sent Kernel Reset to set registers to default value */
  Sent_lResetKernels(SENT_DEINIT_ACCESS);

  /*Clear the ENDINIT bit in the WDT_CONSR register in order to disable the
  write-protection for registers protected via the EndInit feature */
  SENT_SFR_DEINIT_RESETENDINIT();

  /* Disable the SENT module clock */
  SENT_SFR_DEINIT_MODIFY32(SENT_CLC.U, SENT_CLC_DISR_CLEARMASK, \
                                                        SENT_CLC_DISR_SETMASK)
  /*Set the ENDINIT bit in the WDT_CONSR register in order to enable the
  write-protection for registers protected via the EndInit feature */
  SENT_SFR_DEINIT_SETENDINIT();

  #if(SENT_DEV_ERROR_DETECT == STD_ON)
  /* Set Status to indicate that de-initialization is done */
  Sent_InitStatus = 0U;
  #endif  /*(SENT_DEV_ERROR_DETECT == STD_ON)*/

}/* End of Function: Sent_DeInit */
#endif

#if((SENT_RESET_SFR_AT_INIT == STD_ON) || (SENT_DEINIT_API == STD_ON))
/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Sent_lResetKernels(uint8)                    **
**                                                                            **
** Service ID      : NA                                                       **
**                                                                            **
** Sync/Async      : Synchronous                                              **
**                                                                            **
** Reentrancy      : NA                                                       **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description     : This function :                                          **
**   - Execute kernel reset for all available kernels                         **
*******************************************************************************/
static void Sent_lResetKernels(uint8 ServiceId)
{
  volatile uint32 Readback;
  uint32 WaitCount;

  if(ServiceId == SENT_INIT_ACCESS)
  {
    /*Clear the ENDINIT bit in the WDT_CONSR register in order to disable the
      write-protection for registers protected via the EndInit feature */
      SENT_SFR_INIT_RESETENDINIT();

    /* Set request to reset the SENT Kernel */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      SENT_SFR_INIT_MODIFY32(SENT_KRST0.U,SENT_KRST0_RST_CLEARMASK,\
                                      SENT_KRST0_RST_SETMASK)

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      Readback = SENT_SFR_INIT_USER_MODE_READ32(SENT_KRST0.U);

    /* To set RST bit in KRST1 register to 1U. Reserve bit access
      is ensured for KRST1 register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      SENT_SFR_INIT_MODIFY32(SENT_KRST1.U,SENT_KRST1_RST_CLEARMASK,\
                                     SENT_KRST1_RST_SETMASK)

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      Readback = SENT_SFR_INIT_USER_MODE_READ32(SENT_KRST1.U);

    /*Set the ENDINIT bit in the WDT_CONSR register again to enable the
      write-protection and to prevent a time-out */
      SENT_SFR_INIT_SETENDINIT();

      WaitCount = (uint32)SENT_KERNEL_RESET_WAIT_COUNT;
      do
      {
          WaitCount--;
      }
       while((((SENT_SFR_INIT_USER_MODE_READ32\
       (SENT_KRST0.U) & SENT_KRST0_RSTSTAT_SETMASK) >> 1U) != \
                 SENT_KRST0_RSTSTAT_BITPOS)&&(WaitCount > 0U));

    /*Clear the ENDINIT bit in the WDT_CONSR register in order to disable the
      write-protection for registers protected via the EndInit feature */
      SENT_SFR_INIT_RESETENDINIT();

      /* Clear the SENT Kernel Reset Flag. Reserve bit access is ensured
       for KRSTCLR register */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      SENT_SFR_INIT_MODIFY32(SENT_KRSTCLR.U,SENT_KRSTCLR_CLR_CLEARMASK,\
                                                     SENT_KRSTCLR_CLR_SETMASK)

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      Readback = SENT_SFR_INIT_USER_MODE_READ32(SENT_KRSTCLR.U);

      /* Set the ENDINIT bit in the WDT_CONSR register again to enable the
      write-protection and to prevent a time-out */
      SENT_SFR_INIT_SETENDINIT();
  }
  else
  {
      /*Clear the ENDINIT bit in the WDT_CONSR register in order to disable the
      write-protection for registers protected via the EndInit feature */
      SENT_SFR_DEINIT_RESETENDINIT();

    /* Set request to reset the SENT Kernel */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      SENT_SFR_DEINIT_MODIFY32(SENT_KRST0.U,SENT_KRST0_RST_CLEARMASK,\
                                      SENT_KRST0_RST_SETMASK)

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      Readback = SENT_SFR_DEINIT_USER_MODE_READ32(SENT_KRST0.U);

    /* To set RST bit in KRST1 register to 1U. Reserve bit access
      is ensured for KRST1 register*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      SENT_SFR_DEINIT_MODIFY32(SENT_KRST1.U,SENT_KRST1_RST_CLEARMASK,\
                                     SENT_KRST1_RST_SETMASK)

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      Readback = SENT_SFR_DEINIT_USER_MODE_READ32(SENT_KRST1.U);

    /*Set the ENDINIT bit in the WDT_CONSR register again to enable the
      write-protection and to prevent a time-out */
      SENT_SFR_DEINIT_SETENDINIT();

      WaitCount = (uint32)SENT_KERNEL_RESET_WAIT_COUNT;
      do
      {
          WaitCount--;
      }
       while((((SENT_SFR_DEINIT_USER_MODE_READ32\
       (SENT_KRST0.U) & SENT_KRST0_RSTSTAT_SETMASK) >> 1U) != \
                 SENT_KRST0_RSTSTAT_BITPOS)&&(WaitCount > 0U));

    /*Clear the ENDINIT bit in the WDT_CONSR register in order to disable the
      write-protection for registers protected via the EndInit feature */
      SENT_SFR_DEINIT_RESETENDINIT();

      /* Clear the SENT Kernel Reset Flag. Reserve bit access is ensured
       for KRSTCLR register */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      SENT_SFR_DEINIT_MODIFY32(SENT_KRSTCLR.U,SENT_KRSTCLR_CLR_CLEARMASK,\
                                                    SENT_KRSTCLR_CLR_SETMASK)

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
      efficiently access the SFRs of multiple SENT kernels*/
      Readback = SENT_SFR_DEINIT_USER_MODE_READ32(SENT_KRSTCLR.U);

      /* Set the ENDINIT bit in the WDT_CONSR register again to enable the
      write-protection and to prevent a time-out */
      SENT_SFR_DEINIT_SETENDINIT();

  }

  UNUSED_PARAMETER(Readback)
}
#endif

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_SENT_PR1704]                    **
**                                                                            **
** Syntax           : void Sent_Isr (Sent_ChannelIdxType ChannelId)           **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel number                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - is the interrupt handler and collects the status    **
**                        of the relevant channels and inform the user        **
*******************************************************************************/
void Sent_Isr (Sent_ChannelIdxType ChannelId)
{
  Sent_NotifType IntStat;
  Sent_ChannelIdxType ChanIdx;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on ChanCfgPtr
   to access the Physical Channel Id linked to particular Logical Id*/
  ChanIdx = Sent_kConfigPtr->ChanCfgPtr[ChannelId].ChannelId;

  /* Store interrupt status bits for the Channel */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
  IntStat = SENT_CHANNEL[ChanIdx].INTSTAT.U;

  /* Notify the Application */
  Sent_FnCbkPtr[ChannelId](ChannelId, IntStat);

  /* Clear the respective Interrupt events */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on SENT_CHANNEL
       to access the SFRs for a particular SENT Channel*/
  SENT_CHANNEL[ChanIdx].INTCLR.U = IntStat;

} /* End of Interrupt Handler : Sent_Isr */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
** Syntax           : void Sent_lDetCheck                                     **
**                    (                                                       **
**                      uint8 ServiceID                                       **
**                      Sent_ChannelIdxType ChannelId                         **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ServiceID - Informs Service ID of an API                **
**                    ChannelId - SENT Channel number                         **
**                    OutPtr    - Output pointer                              **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : E_OK: No DET error occurred                              **
**                   E_NOT_OK: DET error occurred                             **
**                                                                            **
** Description      : This function:                                          **
**                       - checks whether SENT module is initialized or not   **
**                       - also verifies if the SENT channel has been         **
**                         configured or not. Raising DET if error.           **
**                       - also verifies if the OutPtr is not NULL            **
*******************************************************************************/
#if (SENT_DEV_ERROR_DETECT == STD_ON)
static uint32 Sent_lDetCheck (uint8 ServiceID,
                                        Sent_ChannelIdxType ChannelId,
                                        const void *Ptr)
{
  uint32 RetVal = E_OK;

  if (Sent_InitStatus != SENT_INITIALIZED)
  {
    /* Report to DET */
    Det_ReportError(
                     (uint16)SENT_MODULE_ID,
                     SENT_INSTANCE_ID,
                     ServiceID,
                     SENT_E_UNINIT
                   );
    RetVal = E_NOT_OK;
  }

  if ( (RetVal == E_OK) && ((ChannelId >= SENT_HW_MAX_CHANNELS) ||
       (Sent_ChannelMap[ChannelId] == SENT_CHAN_NOT_CONFIGURED) ) )
  {
    /* Report to DET */
    Det_ReportError(
                     (uint16)SENT_MODULE_ID,
                     SENT_INSTANCE_ID,
                     ServiceID,
                     SENT_E_PARAM_INVALID
                   );
    RetVal = E_NOT_OK;
  }

  if ( (RetVal == E_OK) &&
        ((ServiceID == SENT_SID_SPCGENPULSE) ||
        (ServiceID == SENT_SID_READCHANSTATUS) ||
        (ServiceID == SENT_SID_READSERIALDATA)) )
  {
    if (Ptr == NULL_PTR)
    {
      /* Report to DET */
      Det_ReportError(
                       (uint16)SENT_MODULE_ID,
                       SENT_INSTANCE_ID,
                       ServiceID,
                       SENT_E_PARAM_INVALID
                     );
      RetVal = E_NOT_OK;
    }
  }

  return RetVal;
} /* End of Function: Sent_lDetCheck */
#endif

/*Memory Map of the SENT Code*/
#define SENT_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
