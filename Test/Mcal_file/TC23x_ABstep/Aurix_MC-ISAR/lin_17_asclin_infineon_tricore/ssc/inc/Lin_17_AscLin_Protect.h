/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2016)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This is a demo file and the contents of this file has to be modified by
** the customer                                                               **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Lin_17_AscLin_Protect.h $                                  **
**                                                                            **
**   $CC VERSION : \main\2 $                                                  **
**                                                                            **
**   $DATE       : 2016-04-19 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file define all the first level                       **
**                 indirection macros for Protected mode support. This is a   **
**                 demo file and the contents of this file has to be modified **
**                 by the customer                                            **
**  MAY BE CHANGED BY USER [Yes/No]: Yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
** Traceabilty      :                                                         **
**                                                                            **
*******************************************************************************/

#ifndef  LIN_PROTECT_CFG_H
#define  LIN_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Lin_17_AscLin_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_LIN                  (101U)
#if (LIN_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_INIT_RESETENDINIT()                      TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_INIT_SETENDINIT()                         TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_INIT_WRITE32(reg,value)                    OS_WritePeripheral32\
          ((OS_AREA_DRV_LIN),(volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_INIT_MODIFY32(reg,clearmask,setmask)         OS_ModifyPeripheral32\
        ((OS_AREA_DRV_LIN),(volatile uint32*)(volatile void*)(&(reg)),\
                (clearmask),(setmask));
#if (LIN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define LIN_INIT_USER_MODE_OS_API_READ32(reg)            OS_ReadPeripheral32\
                  ((OS_AREA_DRV_LIN),(volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define LIN_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)    \
            OS_ModifyPeripheral32((OS_AREA_DRV_LIN),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* LIN_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (LIN_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_RESETENDINIT()                    TRUSTED_ApplResetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_SETENDINIT()                       TRUSTED_ApplSetEndInit()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_WRITE32(reg, value)                 OS_WritePeripheral32\
          ((OS_AREA_DRV_LIN),(volatile uint32*)(volatile void*)(&(reg)),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_READ32(reg)                             OS_ReadPeripheral32\
                  ((OS_AREA_DRV_LIN),(volatile uint32*)(volatile void*)(&(reg)))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_MODIFY32(reg,clearmask,setmask)        OS_ModifyPeripheral32\
        ((OS_AREA_DRV_LIN),(volatile uint32*)(volatile void*)(&(reg)),\
                                                        (clearmask),(setmask));
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_RESETSAFETYENDINIT(Time)     TRUSTED_ApplSafetyResetEndInit\
                                                                        ((Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_DEINIT_SETSAFETYENDINIT()             TRUSTED_ApplSafetysetEndInit()
#if (LIN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define LIN_DEINIT_USER_MODE_OS_API_WRITE32(reg, value)   \
            OS_WritePeripheral32((OS_AREA_DRV_LIN),\
                (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define LIN_DEINIT_USER_MODE_OS_API_READ32(reg)        \
        OS_ReadPeripheral32((OS_AREA_DRV_LIN),\
                (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define LIN_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)  \
        OS_ModifyPeripheral32((OS_AREA_DRV_LIN),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* LIN_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

#if (LIN_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define LIN_RUNTIME_MODIFY32(reg,clearmask,setmask)        \
          OS_ModifyPeripheral32((OS_AREA_DRV_LIN),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#if (LIN_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define LIN_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value)      \
        OS_WritePeripheral32((OS_AREA_DRV_LIN),\
                    (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define LIN_RUNTIME_USER_MODE_OS_API_READ32(reg)  \
        OS_ReadPeripheral32((OS_AREA_DRV_LIN),\
                    (volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define LIN_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)  \
        OS_ModifyPeripheral32((OS_AREA_DRV_LIN),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* LIN_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
 #endif