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
**  $FILENAME   : Sent_Protect.h $                                           **
**                                                                            **
**   $CC VERSION : \main\5 $                                                  **
**                                                                            **
**   $DATE       : 2016-05-18 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  :This is a demo file and the contents of this
                         file has to be modified by the customer              **
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

#ifndef  SENT_PROTECT_CFG_H
#define  SENT_PROTECT_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of McalOsConfig.h */
#include "McalOsConfig.h"
#include MCAL_OS_HEADER
#include "Sent_Cfg.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define OS_AREA_DRV_SENT                  (101U)
#if (SENT_USER_MODE_INIT_API_ENABLE == STD_ON)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_INIT_RESETENDINIT()          TRUSTED_ApplResetEndInit()

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_INIT_SETENDINIT()            TRUSTED_ApplSetEndInit()

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_INIT_WRITE32(reg,value)   OS_WritePeripheral32((OS_AREA_DRV_SENT),\
                          (volatile uint32*)(volatile void*)(&(reg)),(value))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_INIT_MODIFY32(reg,clearmask,setmask)     OS_ModifyPeripheral32\
   ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)),(clearmask),\
                                                                    (setmask));

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_INIT_RESETSAFETYENDINIT_TIMED(Time)  \
                                    TRUSTED_ApplSafetyResetEndInit_Timed((Time))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_INIT_SETSAFETYENDINIT_TIMED()  TRUSTED_ApplSafetySetEndInit_Timed()
#if (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_INIT_USER_MODE_OS_API_WRITE32(reg,value)   OS_WritePeripheral32\
       ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_INIT_USER_MODE_OS_API_READ32(reg)   OS_ReadPeripheral32\
                 ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_INIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)   \
                          OS_ModifyPeripheral32((OS_AREA_DRV_SENT),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* SENT_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (SENT_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_DEINIT_RESETENDINIT()         TRUSTED_ApplResetEndInit()

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
#define SENT_DEINIT_SETENDINIT()            TRUSTED_ApplSetEndInit()

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
#define SENT_DEINIT_MODIFY32(reg,clearmask,setmask)    OS_ModifyPeripheral32\
       ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)),\
                                                       (clearmask),(setmask));
#if (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
 /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
 #define SENT_DEINIT_USER_MODE_OS_API_WRITE32(reg, value)  OS_WritePeripheral32\
        ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_DEINIT_USER_MODE_OS_API_READ32(reg)  OS_ReadPeripheral32\
                ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_DEINIT_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)   \
              OS_ModifyPeripheral32((OS_AREA_DRV_SENT),\
              (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* SENT_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

#if (SENT_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
 /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
 #define SENT_RUNTIME_RESETSAFETYENDINIT_TIMED(Time)  \
                                   TRUSTED_ApplSafetyResetEndInit_Timed ((Time))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
#define SENT_RUNTIME_SETSAFETYENDINIT_TIMED()    \
                                            TRUSTED_ApplSafetySetEndInit_Timed()
#if (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_RUNTIME_USER_MODE_OS_API_WRITE32(reg, value)  \
                      OS_WritePeripheral32((OS_AREA_DRV_SENT),\
                            (volatile uint32*)(volatile void*)(&(reg)),(value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_RUNTIME_USER_MODE_OS_API_READ32(reg)   OS_ReadPeripheral32\
                ((OS_AREA_DRV_SENT),(volatile uint32*)(volatile void*)(&(reg)))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
 modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define SENT_RUNTIME_USER_MODE_OS_API_MODIFY32(reg,clearmask,setmask)    \
                 OS_ModifyPeripheral32((OS_AREA_DRV_SENT),\
             (volatile uint32*)(volatile void*)(&(reg)),(clearmask),(setmask));
#endif
#endif /* SENT_USER_MODE_RUNTIME_API_ENABLE == STD_ON  */
#endif