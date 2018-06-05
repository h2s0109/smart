/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. This is a demo file and the contents of this file            **
** if required shall be modified by the customer.                             **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : fr_17_eray_protect.h $                                     **
**                                                                            **
**   $CC VERSION : \main\3 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-19 $                                               **
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
** Traceability     :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  FR_PROTECT_CFG_H
#define  FR_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Fr_17_Eray_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_FR                ((uint16)0x51)
#if (FR_USER_MODE_INIT_API_ENABLE == STD_ON)
#define FR_INIT_RESETENDINIT()        TRUSTED_ApplResetEndInit()
#define FR_INIT_SETENDINIT()          TRUSTED_ApplSetEndInit()
#define FR_INIT_WRITE32(reg, value)   OS_WritePeripheral32((OS_AREA_DRV_FR), \
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
#define FR_INIT_READ32(reg)           OS_ReadPeripheral32((OS_AREA_DRV_FR),  \
                                    (volatile uint32*)(volatile void*)(&(reg)))
#define FR_INIT_MODIFY32(reg,clearmask,setmask)                               \
                                       OS_ModifyPeripheral32((OS_AREA_DRV_FR),\
      (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));

  #if (FR_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define FR_INIT_USER_MODE_OS_API_WRITE32(reg, value)                        \
                                        OS_WritePeripheral32((OS_AREA_DRV_FR),\
                           (volatile uint32*)(volatile void*)(&(reg)),(value))
  #define FR_INIT_USER_MODE_OS_API_READ32(reg)                                \
                                         OS_ReadPeripheral32((OS_AREA_DRV_FR),\
                                    (volatile uint32*)(volatile void*)(&(reg)))
  #define FR_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)            \
                                      OS_ModifyPeripheral32((OS_AREA_DRV_FR), \
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
  #endif
#endif /* FR_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (FR_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
#define FR_RUNTIME_READ32(reg)        OS_ReadPeripheral32((OS_AREA_DRV_FR),  \
                                     (volatile uint32*)(volatile void*)(&(reg)))
#define FR_RUNTIME_MODIFY32(reg,clearmask,setmask)                            \
                                       OS_ModifyPeripheral32((OS_AREA_DRV_FR),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));

  #if (FR_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  #define FR_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value)                     \
                                        OS_WritePeripheral32((OS_AREA_DRV_FR),\
                             (volatile uint32*)(volatile void*)(&(reg)),(value))
  #define FR_RUNTIME_USER_MODE_OS_API_READ32(reg)                             \
                                         OS_ReadPeripheral32((OS_AREA_DRV_FR),\
                                     (volatile uint32*)(volatile void*)(&(reg)))
  #define FR_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)         \
                     OS_ModifyPeripheral32((OS_AREA_DRV_FR),(volatile uint32*)\
                                (volatile void*)(&(reg)),(clearmask),(setmask));
  #endif
#endif /* FR_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
#endif