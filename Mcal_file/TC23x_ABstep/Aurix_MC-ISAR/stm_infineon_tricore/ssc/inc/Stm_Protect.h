/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Stm_Protect.h $                                            **
**                                                                            **
**   $CC VERSION : \main\3 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-13 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file file define all the first level                  **
**                 indirection macros for Protected mode support              **
**                                                                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  STM_PROTECT_CFG_H
#define  STM_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Mcal_Options.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_STM (0x01U)

#if (STM_USER_MODE_RUNTIME_API_ENABLE == STD_ON) 
#define STM_RUNTIME_RESETENDINIT()                                           TRUSTED_ApplResetEndInit()
#define STM_RUNTIME_SETENDINIT()                                             TRUSTED_ApplSetEndInit()
#define STM_RUNTIME_WRITE32(reg, value)                                 OS_WritePeripheral32(OS_AREA_DRV_STM,(volatile uint32*)(volatile void*)(&(reg)),(value))
#define STM_RUNTIME_MODIFY32(reg,clearmask,setmask)                     OS_ModifyPeripheral32(OS_AREA_DRV_STM,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#define STM_RUNTIME_RESETSAFETYENDINIT(Time)                                 TRUSTED_ApplSafetyResetEndInit ((Time))
#define STM_RUNTIME_SETSAFETYENDINIT(void)                                       TRUSTED_ApplSafetysetEndInit(void)
#if (STM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)                            
  #define STM_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value)              OS_WritePeripheral32(OS_AREA_DRV_STM,(volatile uint32*)(volatile void*)(&(reg)),(value))
  #define STM_RUNTIME_USER_MODE_OS_API_READ32(reg)                           OS_ReadPeripheral32(OS_AREA_DRV_STM,(volatile uint32*)(volatile void*)(&(reg)))
  #define STM_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)  OS_ModifyPeripheral32(OS_AREA_DRV_STM,(volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif                                                                       
#endif /* STM_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */                        
 #endif 