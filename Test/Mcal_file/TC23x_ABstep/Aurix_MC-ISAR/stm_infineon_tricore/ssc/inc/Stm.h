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
**  $FILENAME   : Stm.h $                                                    **
**                                                                            **
**  $CC VERSION : \main\17 $                                                 **
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


#ifndef STM_H
#define STM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Inclusion of controller sfr file */
#include "IfxStm_reg.h"
#if ((STM_USER_MODE_RUNTIME_API_ENABLE == STD_ON) ||                           \
     (STM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
     #include "Stm_Protect.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*****************************************1*************************************/
/*
  Requirement key - STM 121, STM 037 :
  Module Identification, Vendor Identification
*/
  /* Module ID */
#define STM_MODULE_ID       ((uint16)255)

  /* STM Vendor ID */
#define STM_VENDOR_ID       ((uint16)17)

  /* STM Instance ID */
#define STM_INSTANCE_ID       ((uint8)0) 


/* Vendor specific implementation version information */
#define STM_SW_MAJOR_VERSION   (0U)
#define STM_SW_MINOR_VERSION   (0U)
#define STM_SW_PATCH_VERSION   (1U)


#define STM_BASE (&(MODULE_STM0))

#define STM0_SRC_BASE  ((Ifx_SRC_SRCR *)(void *) &(SRC_STM_STM0_SR0))

#define STM1_SRC_BASE  ((Ifx_SRC_SRCR *)(void *) &(SRC_STM_STM1_SR0))

#define STM2_SRC_BASE  ((Ifx_SRC_SRCR *)(void *) &(SRC_STM_STM2_SR0))

#if (STM_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_RESETENDINIT()           (STM_RUNTIME_RESETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_SETENDINIT()             (STM_RUNTIME_SETENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_WRITE32(reg,value)                                     \
                                   (STM_RUNTIME_WRITE32((reg), (value)))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)                        \
                       STM_RUNTIME_MODIFY32((reg),(clearmask),(setmask))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_RESETSAFETYENDINIT(Time)                               \
                                          (STM_RUNTIME_RESETSAFETYENDINIT(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_SETSAFETYENDINIT()                                     \
                                              (STM_RUNTIME_SETSAFETYENDINIT())
#if (STM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define STM_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)                        \
                  (STM_RUNTIME_USER_MODE_OS_API_WRITE32((reg), (value)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define STM_SFR_RUNTIME_USER_MODE_READ32(reg)                                \
                                      (STM_RUNTIME_USER_MODE_OS_API_READ32(reg))
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define STM_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)            \
              STM_RUNTIME_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
#else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define STM_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)                        \
                                                 ((reg) = (unsigned_int)(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define STM_SFR_RUNTIME_USER_MODE_READ32(reg)                 (reg)
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define STM_SFR_RUNTIME_USER_MODE_MODIFY32(reg, clearmask ,setmask)          \
  { uint32 (val) ; (val) = (reg); (val) &= (clearmask); (val) |= (setmask);    \
                                                                (reg) = (val);}
#endif /* STM_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_RESETENDINIT()                   (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_WRITE32(reg, value)                                    \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_MODIFY32(reg, clearmask,setmask)                       \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}  
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_SETENDINIT()                      (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_RESETSAFETYENDINIT(Time)                               \
                                           (Mcal_ResetSafetyENDINIT_Timed(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_SETSAFETYENDINIT()       (Mcal_SetSafetyENDINIT_Timed())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)                          \
                                                 ((reg) = (unsigned_int)(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_USER_MODE_READ32(reg)             (reg)
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced 
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define STM_SFR_RUNTIME_USER_MODE_MODIFY32(reg, clearmask ,setmask)            \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}
#endif /* STM_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef struct Stm_ModuleParameterType
{
uint32 CompareRegValue[2];
volatile Ifx_STM_TIM0 *CurrentTimer[2];
void (*Stm_ArrayFunctionPointer[2])(void);
uint8 InterruptNodeMap;
uint8 TimerMode;
}Stm_ModuleParameterType;


typedef struct Stm_TotalTimerCaptureType
{
  uint32 LowerPart;
  uint32 UpperPart;
}Stm_TotalTimerCaptureType;

/* Type definition for STM Application notification function pointer */
typedef void (*Stm_CallbackFnPtrType) (void); 
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define STM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
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
void Stm_EnableModule(uint8 ModuleNumber);


/*******************************************************************************
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
                     Stm_CallbackFnPtrType Stm_Applicationfunction);
                     
                     
/*******************************************************************************
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
void Stm_DisableAlarm(uint8 ModuleNumber,uint8 CompareRegisterId);


/*******************************************************************************
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
           uint8 CompareRegisterId,uint8 Mstart,uint8 MSize);
           
           


/*******************************************************************************
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
uint32 Stm_ReadTimerValue(uint8 ModuleNumber,uint8 TimerNumber);



/*******************************************************************************
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
Stm_TotalTimerCaptureType Stm_ReadTotalTimerValue(uint8 ModuleNumber);



/*******************************************************************************
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
                                             uint8 InterruptNodeNum);

                                             
           
/*******************************************************************************
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
void Stm_SetAccessEnable(uint8 ModuleNumber,uint32 WriteAccessValue);


           
/*******************************************************************************
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
uint32 Stm_GetAccessEnable(uint8 ModuleNumber);      

     
/*******************************************************************************
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
**                                                                            **
*******************************************************************************/
void Stm_SleepModeHandle(uint8 ModuleNumber, uint8 SleemodeControl);

           
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
void Stm_Isr(uint8 ModuleNumber,uint8 InterruptNode);

#define STM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_STM_PR1737]                          **
**                                                                            **
** Syntax           : void  Stm_GetVersionInfo                                **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x11                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : versioninfo - Pointer to where to store the             **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - This function returns the version information of this module           **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**                                                                            **
*******************************************************************************/

/*IFX_MISRA_RULE_19_04_STATUS=IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo 
is declared as a function like macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define  Stm_GetVersionInfo(VersionInfoPtr)                             \
{                                                                       \
  if ((VersionInfoPtr) != (NULL_PTR))                                   \
  {                                                                     \
  /* Note that versioninfo pointer is not checked for NULL as the user  \
     is supposed to send the memory allocated pointer */                \
  /* STM Module ID */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = STM_MODULE_ID;   \
  /* STM vendor ID */                                                   \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = STM_VENDOR_ID;   \
  /* major version of STM */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =          \
                                     (uint8)STM_SW_MAJOR_VERSION;       \
  /* minor version of STM */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =          \
                                     (uint8)STM_SW_MINOR_VERSION;       \
  /* patch version of STM */                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =          \
                                     (uint8)STM_SW_PATCH_VERSION;       \
  }                                                                     \
}


#endif /* STM_H */