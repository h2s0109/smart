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
*******************************************************************************
**                                                                            **
**  $FILENAME   : Stm.c $                                                    **
**                                                                            **
**  $CC VERSION : \main\25 $                                                 **
**                                                                            **
**  $DATE       : 2016-07-01 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of STM driver.                             **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

/* Inclusion of controller sfr file */
#include "IfxSrc_reg.h"

/* Inclusion of Stm header file */
#include "Stm.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#ifndef STM_SW_MAJOR_VERSION
  #error "STM_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef STM_SW_MINOR_VERSION
  #error "STM_SW_MINOR_VERSION is not defined. "
#endif

#ifndef STM_SW_PATCH_VERSION
  #error "STM_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( STM_SW_MAJOR_VERSION != 0U )
  #error "STM_SW_MAJOR_VERSION does not match. "
#endif
#if ( STM_SW_MINOR_VERSION != 0U )
  #error "STM_SW_MINOR_VERSION does not match. "
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define STM_SAFETY_ENDINIT_TIMEOUT (150000U)
#define STM_REGISTER_OFFSET (0x100U)
#define STM_SET_MASK (0xFFFFFFFFU)
#define STM_REG_CLR_MASK    (0x00000000U)
#define STM_CMCON_SET_MASK  (0x001F001FU)
#define STM_ICR_CMP_SET_MASK  (0x00000051U)
#define STM0_SRC_BASE_CLRR_POS             (25U)
#define STM0_SRC_BASE_SRE_POS              (10U)
#define STM0_SRC_BASE_CLRR_CLR_MASK        (0x7D3F1CFFU)
#define STM0_SRC_BASE_CLRR_SET_MASK        ((uint32)1 << STM0_SRC_BASE_CLRR_POS)
#define STM0_SRC_BASE_SRE_CLR_MASK         (0x7F3F18FFU)
#define STM0_SRC_BASE_SRE_SET_MASK         ((uint32)1 << STM0_SRC_BASE_SRE_POS)
#define STM0_SRC_BASE_SRE_RES_MASK         ((uint32)0 << STM0_SRC_BASE_SRE_POS)
#define STM_CMCON_CMP0_CLR_MASK            (0x1F1F0000U)
#define STM_CMCON_CMP1_CLR_MASK            (0x00001F1FU)
#define STM_ICR_CMP0OS_CLR_MASK            (0x00000073U)
#define STM_ICR_CMP1OS_CLR_MASK            (0x00000037U)
#define STM_CLC_EDIS_CLR_MASK              (0x00000003U)


/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/* Mapping the code */
#define STM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
IFX_LOCAL_INLINE void Stm_SetBit(uint8* Data,uint8 BitPn);
IFX_LOCAL_INLINE void Stm_ClrBit(uint8* Data,uint8 BitPn);
IFX_LOCAL_INLINE uint8 Stm_GetBit(uint8 Data,uint8 BitPn);
IFX_LOCAL_INLINE void Stm_CopyBit(uint8 Source, uint8* DestinationData,
                  uint8 DestinationPosition);
#define STM_STOP_SEC_CODE
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
#define STM_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
Stm_ModuleParameterType  Stm_ModuleParameter[3];

#define STM_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"



/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Mapping the code */
#define STM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1730_PR1731]              **
**                                                                            **
** Syntax           : void Stm_EnableModule(ModuleNumber)                     **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function enables the STM interrupts and interrupt  **
**                     node mapping                                           **
*******************************************************************************/
void Stm_EnableModule(uint8 ModuleNumber)
{
  /* Reset End Init Protection to access regsiters */
  STM_SFR_RUNTIME_RESETENDINIT();
  /* Enable the STM module clock, by default STM clock is enabled */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_WRITE32(STM_BASE[ModuleNumber].CLC.U,STM_REG_CLR_MASK);
  /* Set End Init Protection */
  STM_SFR_RUNTIME_SETENDINIT();
  /* Compare register value is assigned its reset value */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_USER_MODE_WRITE32(STM_BASE[ModuleNumber].CMP[0U].U,          \
                                                              STM_REG_CLR_MASK);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_USER_MODE_WRITE32(STM_BASE[ModuleNumber].CMP[1U].U,          \
                                                              STM_REG_CLR_MASK);
   /* Configure the compare match control register in such a way
      that all the 32 bits of CMP0 and CMP1 registers are used to compare
      with first 32 bit values of 64 bit STM */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_USER_MODE_WRITE32(STM_BASE[ModuleNumber].CMCON.U,            \
                                                            STM_CMCON_SET_MASK);

  /* Enable the compare match interrupt and
     Tie the interrupt node with compare register -
     CMP0 compare match interrupt directed to interrupt node 0 and
     CMP1 compare match interrupt directed to interrupt node 1 */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_USER_MODE_WRITE32(STM_BASE[ModuleNumber].ICR.U,              \
                                                          STM_ICR_CMP_SET_MASK);


  /* Initialise the RAM variables corresponding to the STM module number */
  Stm_ModuleParameter[ModuleNumber].TimerMode = 0U;
  Stm_ModuleParameter[ModuleNumber].CompareRegValue[0U] = 0U;
  Stm_ModuleParameter[ModuleNumber].CompareRegValue[1U] = 0U;
  Stm_ModuleParameter[ModuleNumber].CurrentTimer[0U] =
                  &STM0_TIM0;
  Stm_ModuleParameter[ModuleNumber].CurrentTimer[1U] =
                  &STM0_TIM0;
  /* 0x2 = 10(binary):CMPO interrupt mapped to node 0 and CMP1 with node 1 */
  Stm_ModuleParameter[ModuleNumber].InterruptNodeMap = 0x2U;
}


/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1734]                     **
**                                                                            **
** Syntax           : void Stm_EnableAlarm(uint8 ModuleNumber,                **
**                    uint8 CompareRegisterId, uint8 TimerMode,uint32 Ticks,  **
**                    void (*Stm_Applicationfunction)(void))                  **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    CompareRegisterId - Compare register number             **
**                    TimerMode - One shot(1) or continuous(0)                **
**                    Ticks - Timer ticks w.r.t selected timer                **
**                    void (*Stm_Applicationfunction)(void)) -                **
**                    Functon pointer used for Call-back function             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function provides service to invoke a Call-back    **
                      function after the elapse of configured                 **
                      amount of time(scheduling a function)                   **
*******************************************************************************/
void Stm_EnableAlarm(uint8 ModuleNumber,
                     uint8 CompareRegisterId, uint8 TimerMode,uint32 Ticks,
                     Stm_CallbackFnPtrType Stm_Applicationfunction)
{
  uint8 InterruptNode;
  uint32 Temp;
  /* TimerMode can be one shot(1)/continuous(0):copy the same to RAM variable */
  Stm_CopyBit(TimerMode,&Stm_ModuleParameter[ModuleNumber].TimerMode,
              CompareRegisterId);
  /* Update the RAM variable with requested timer ticks */
  Stm_ModuleParameter[ModuleNumber].CompareRegValue[CompareRegisterId] = Ticks;

  /* Copy the Call-back function to be invoked */
  Stm_ModuleParameter[ModuleNumber].Stm_ArrayFunctionPointer[CompareRegisterId]
           = Stm_Applicationfunction;

  /* Load the compare register with given ticks */
  Temp = Stm_ModuleParameter[ModuleNumber].CompareRegValue[CompareRegisterId]
        +STM_SFR_RUNTIME_USER_MODE_READ32((Stm_ModuleParameter[ModuleNumber].  \
                                          CurrentTimer[CompareRegisterId])->U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_USER_MODE_WRITE32(STM_BASE[ModuleNumber]                     \
                 .CMP[CompareRegisterId].U,(Temp & STM_SET_MASK));
  /* Identify the Interrupt node mapped to the requested compare register */
  InterruptNode = Stm_GetBit(Stm_ModuleParameter[ModuleNumber].InterruptNodeMap,
                             CompareRegisterId);

  /* Configure the interrupt system to handle interrupts from STM as follows */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_MODIFY32(STM0_SRC_BASE[(InterruptNode+(2U* ModuleNumber))].U,\
                       STM0_SRC_BASE_CLRR_CLR_MASK,STM0_SRC_BASE_CLRR_SET_MASK)

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_MODIFY32(STM0_SRC_BASE[(InterruptNode+(2U* ModuleNumber))].U,\
                         STM0_SRC_BASE_SRE_CLR_MASK,STM0_SRC_BASE_SRE_SET_MASK)

}


/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1735]                     **
**                                                                            **
** Syntax           : void Stm_DisableAlarm(uint8 ModuleNumber,uint8          **
**                                          CompareRegisterId)                **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    CompareRegisterId - Compare register number             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function stops the invoke of a Call-back function  **
**                                                                            **
*******************************************************************************/
void Stm_DisableAlarm(uint8 ModuleNumber,uint8 CompareRegisterId)
{
  uint8 InterruptNode;
  /* Identify the Interrupt node mapped to the requested compare register */
  InterruptNode = Stm_GetBit(Stm_ModuleParameter[ModuleNumber].InterruptNodeMap,
                             CompareRegisterId);
  /* Disable the  requested STM service request */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_MODIFY32(STM0_SRC_BASE[(InterruptNode+(2U* ModuleNumber))].U,\
                         STM0_SRC_BASE_SRE_CLR_MASK,STM0_SRC_BASE_SRE_RES_MASK)

}

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1738]                     **
**                                                                            **
** Syntax           : void Stm_SetCompareMatchControl(uint8 ModuleNumber      **
**                     uint8 CompareRegisterId,uint8 Mstart,uint8 MSize)      **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    CompareRegisterId - Compare register number             **
**                    Mstart - The lowest bit number of the 64-bit STM        **
**                    MSize - Number of bits in register CMPx                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function provides service to write into the        **
**                    CMPx register.                                          **
**                                                                            **
*******************************************************************************/
void Stm_SetCompareMatchControl(uint8 ModuleNumber,
           uint8 CompareRegisterId,uint8 Mstart,uint8 MSize)
{
  volatile Ifx_STM_TIM0* Timer0BaseaddressPtr;
  uint8 TimerNumber;
  uint32 MstartsizeValue;
  /* Identify the user requested timer based on Mstart value, same will be used
    for reference to invoke a Call-back function */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on PhysAddrPtr to
     access the next byte of the network address passed*/
  Timer0BaseaddressPtr = &STM0_TIM0 + \
                              (ModuleNumber * (uint8)STM_REGISTER_OFFSET) ;

  TimerNumber = (Mstart/4U);

  /* Update the RAM varaible with the currenttimer to be used */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on PhysAddrPtr to
     access the next byte of the network address passed*/
  Stm_ModuleParameter[ModuleNumber].CurrentTimer[CompareRegisterId] =
                  (Timer0BaseaddressPtr + TimerNumber);
  if(CompareRegisterId == 0U)
  {
    /* Load the Compare control register with start bit location and
     number of bits used for comparision w.r.t CMP0 register */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on PhysAddrPtr to
     access the next byte of the network address passed*/
     MstartsizeValue = (uint32)(((uint32)Mstart << 8U) | (uint32)MSize);
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
     STM_SFR_RUNTIME_USER_MODE_MODIFY32(STM_BASE[ModuleNumber].CMCON.U,        \
                                       STM_CMCON_CMP0_CLR_MASK,MstartsizeValue)
  }
  else
  {
    /* Load the Compare control register with start bit location and
     number of bits used for comparision w.r.t CMP1 register */
    MstartsizeValue = (uint32)((((uint32)Mstart << 8U) | (uint32)MSize) << 16U);
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on PhysAddrPtr to
     access the next byte of the network address passed*/
    STM_SFR_RUNTIME_USER_MODE_MODIFY32(STM_BASE[ModuleNumber].CMCON.U,         \
                                       STM_CMCON_CMP1_CLR_MASK,MstartsizeValue)

  }
}



/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1732]                     **
**                                                                            **
** Syntax           : uint32 Stm_ReadTimerValue(uint8 ModuleNumber,           **
**                                              uint8 TimerNumber)            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - stm periheral number                     **
**                    TimerNumber - The TimerNumber values shall be           **
**                                  0,1,2,3,4,5 and 6                         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32 - Current running timer value in ticks           **
**                                                                            **
** Description      : This function returns individual TIM value of a         **
**                    particular STM module                                   **
**                                                                            **
*******************************************************************************/
uint32 Stm_ReadTimerValue(uint8 ModuleNumber,uint8 TimerNumber)
{
  uint32 lTimvalue;
  volatile Ifx_STM_TIM0 *Timer0BaseaddressPtr;

  /*Returns TIMx register value based on requested TimerNumber & ModuleNumber */
   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on PhysAddrPtr to
     access the next byte of the network address passed*/
   Timer0BaseaddressPtr = \
                  &STM0_TIM0 + (ModuleNumber * (uint8)STM_REGISTER_OFFSET) ;


  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmentic is done on PhysAddrPtr to
     access the next byte of the network address passed*/
  lTimvalue = STM_SFR_RUNTIME_USER_MODE_READ32((Timer0BaseaddressPtr           \
                                                             + TimerNumber)->U);
  return(lTimvalue);
}



/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1733]                     **
**                                                                            **
** Syntax           : Stm_TotalTimerCaptureType                               **
**                     Stm_ReadTotalTimerValue(uint8 ModuleNumber)            **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Stm_TotalTimerCaptureType : Holds the lower and upper   **
**                    32-bit values of a 64-bit STM timer                     **
**                                                                            **
** Description      : This function returns complete 64 bit STM Timer value   **
**                    of a particular STM module                              **
**                                                                            **
*******************************************************************************/
Stm_TotalTimerCaptureType Stm_ReadTotalTimerValue(uint8 ModuleNumber)
{
  Stm_TotalTimerCaptureType TotalTimerCapture;

  /* Returns the TIM0 and CAP register values based on requested ModuleNumber */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  TotalTimerCapture.LowerPart = STM_SFR_RUNTIME_USER_MODE_READ32               \
                                                (STM_BASE[ModuleNumber].TIM0.U);
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  TotalTimerCapture.UpperPart = STM_SFR_RUNTIME_USER_MODE_READ32               \
                                                 (STM_BASE[ModuleNumber].CAP.U);
   return(TotalTimerCapture);
}


/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1739]                     **
**                                                                            **
** Syntax           : void Stm_InterruptNodeSelection(uint8 ModuleNumber,     **
**                    uint8 CompareRegisterId, uint8 InterruptNodeNum)        **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    CompareRegisterId - Compare register number             **
**                    InterruptNodeNum - values can be 0 or 1                 **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function does service to change the Interrupt node **
**                    mapping to the compare registers.                       **
**                                                                            **
*******************************************************************************/
void Stm_InterruptNodeSelection(uint8 ModuleNumber,uint8 CompareRegisterId,
                                             uint8 InterruptNodeNum)
{
  if(CompareRegisterId == 0U )
  {
    /* Update CMP0 Interrupt Output selection based on requested Node number */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
    STM_SFR_RUNTIME_USER_MODE_MODIFY32(STM_BASE[ModuleNumber].ICR.U,           \
                               STM_ICR_CMP0OS_CLR_MASK,(uint32)InterruptNodeNum)
  }
  else
  {
    /* Update CMP1 Interrupt Output selection based on requested Node number */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
    STM_SFR_RUNTIME_USER_MODE_MODIFY32(STM_BASE[ModuleNumber].ICR.U,           \
                               STM_ICR_CMP1OS_CLR_MASK,(uint32)InterruptNodeNum)
  }
  /* Update the RAM variable with given Interrupt node number */
  Stm_CopyBit(InterruptNodeNum,
   &Stm_ModuleParameter[ModuleNumber].InterruptNodeMap,CompareRegisterId);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1740]                     **
**                                                                            **
** Syntax           : void Stm_SetAccessEnable(uint8 ModuleNumber,            **
**                                uint32 WriteAccessValue)                    **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    WriteAccessValue - Value to restrict bus master access  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                      - sets the STMx_ACCEN0 register                       **
*******************************************************************************/
void Stm_SetAccessEnable(uint8 ModuleNumber,uint32 WriteAccessValue)
{
  STM_SFR_RUNTIME_RESETSAFETYENDINIT(STM_SAFETY_ENDINIT_TIMEOUT);
  /* Load the STM module specific STMx_ACCEN0 register based on given input */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_WRITE32(STM_BASE[ModuleNumber].ACCEN0.U,WriteAccessValue);
  STM_SFR_RUNTIME_SETSAFETYENDINIT();
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1741]                     **
**                                                                            **
** Syntax           : uint32 Stm_GetAccessEnable(uint8 ModuleNumber)          **
**                                                                            **
** Service ID       : 0x08                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function reads back the STMx_ACCEN0 value          **
**                                                                            **
*******************************************************************************/
uint32 Stm_GetAccessEnable(uint8 ModuleNumber)
{
 /* Reads back the STMx_ACCEN0 register value */
 /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
 return((uint32)STM_SFR_RUNTIME_USER_MODE_READ32(STM_BASE[ModuleNumber].       \
                                                                   ACCEN0.U));
}



/*******************************************************************************
** Traceability      : [cover parentID=DS_NAS_STM_PR1736]                     **
**                                                                            **
** Syntax           : void Stm_SleepModeHandle(uint8 ModuleNumber,            **
                                       uint8 SleemodeControl)                 **
**                                                                            **
** Service ID       : 0x09                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    SleemodeControl - 0 or 1                                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                    To enable/disable of STM during controller sleep mode   **
**                                                                            **
*******************************************************************************/
void Stm_SleepModeHandle(uint8 ModuleNumber, uint8 SleemodeControl)
{
  /* Reset End Init Protection to access regsiters */
  STM_SFR_RUNTIME_RESETENDINIT();
  /* Enable/disable the requested STM during Controller sleep mode */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM_SFR_RUNTIME_MODIFY32(STM_BASE[ModuleNumber].CLC.U,                       \
                                  STM_CLC_EDIS_CLR_MASK,(uint32)SleemodeControl)
  /* Set End Init Protection */
  STM_SFR_RUNTIME_SETENDINIT();
}

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
** Syntax           : void Stm_SetBit(uint8* Data,uint8 BitPn)                **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Data - Input variable                                   **
**                    BitPn - Bit number                                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                    Set the respective bit in the variable                  **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Stm_SetBit(uint8* Data,uint8 BitPn)
{
  *Data|=(uint8)(0x01U<<BitPn);
}

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
** Syntax           : void Stm_ClrBit(uint8* Data,uint8 BitPn)                **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Data - Input variable                                   **
**                    BitPn - Bit number                                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                    Clear the respective bit in the variable                **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Stm_ClrBit(uint8* Data,uint8 BitPn)
{
  *Data&=(~(uint8)(0x01U<<BitPn));
}

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
** Syntax           : void Stm_GetBit(uint8 Data,uint8 BitPn)                 **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Data - Input variable                                   **
**                    BitPn - Bit number                                      **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : Returns the respective bit                              **
**                                                                            **
** Description      : This function:                                          **
**                    Get the respective bit in the variable                  **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint8 Stm_GetBit(uint8 Data,uint8 BitPn)
{
  uint8 Value;
  Value = (((uint8)Data >> BitPn) & 0x01U);
  return(Value);
}

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
** Syntax           : void Stm_CopyBit(uint8 Source, uint8* DestinationData,  **
**                     uint8 DestinationPosition)                             **
**                                                                            **
** Service ID       :                                                         **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : Source - Input variable                                 **
**                    DestinationData - Output variable                       **
**                    DestinationPosition - Bit position in output variable   **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                    copy the respective bit in the output variable          **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Stm_CopyBit(uint8 Source, uint8* DestinationData,
                  uint8 DestinationPosition)
{
  if(Source)
  {
    Stm_SetBit(DestinationData,DestinationPosition);
  }
  else
  {
    Stm_ClrBit(DestinationData,DestinationPosition);
  }
}


/*******************************************************************************
**                                                                            **
** Syntax           : void Stm_Isr(uint8 ModuleNumber,uint8 InterruptNode)    **
**                                                                            **
** Service ID       : 0x10                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ModuleNumber - Stm Peripheral number                    **
**                    InterruptNode - 0 or 1                                  **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**                      - is the interrupt handler and collects the interrupt **
**                        node and invoke the call-back function              **
*******************************************************************************/
void Stm_Isr(uint8 ModuleNumber,uint8 InterruptNode)
{
  uint8 CompareRegisterId;
  uint32 CurrentCmpvalue;
  uint32 Value;

  /* Identify the Compare register ID mapped to the invoked interrupt node */
  CompareRegisterId =
  Stm_GetBit(Stm_ModuleParameter[ModuleNumber].InterruptNodeMap,InterruptNode);

  /* Clear the service request flag */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  Value = STM0_SRC_BASE[(InterruptNode + (2U * ModuleNumber))].U;
  Value &= STM0_SRC_BASE_CLRR_CLR_MASK;
  Value |= STM0_SRC_BASE_CLRR_SET_MASK;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
  STM0_SRC_BASE[(InterruptNode + (2U * ModuleNumber))].U = Value;
  if(Stm_GetBit(Stm_ModuleParameter[ModuleNumber].TimerMode,
                CompareRegisterId) == 0U)
  {
      /* Reload the compare register again as the request is invoke the call
          back function in continuous mode */
     CurrentCmpvalue = (uint32)
     ((Stm_ModuleParameter[ModuleNumber].CompareRegValue[CompareRegisterId])
+ (Stm_ModuleParameter[ModuleNumber].CurrentTimer[CompareRegisterId])->U);
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
     STM_BASE[ModuleNumber].CMP[CompareRegisterId].U  =
       (unsigned_int)(CurrentCmpvalue & (STM_SET_MASK));

  }
  else
  {
      /* Requested for one shot mode, So disable the service request */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
    Value = STM0_SRC_BASE[(InterruptNode + (2U * ModuleNumber))].U;
    Value &= STM0_SRC_BASE_SRE_CLR_MASK;
    Value |= STM0_SRC_BASE_SRE_RES_MASK;
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
            efficiently access the SFRs of multiple STM kernels*/
    STM0_SRC_BASE[(InterruptNode + (2U * ModuleNumber))].U = Value;
  }
    /* Invoke the call-back Function */
  Stm_ModuleParameter[ModuleNumber].
     Stm_ArrayFunctionPointer[CompareRegisterId]();
}

/*Memory Map of the STM Code*/
#define STM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"