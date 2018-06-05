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
**  $FILENAME   : Iom.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\34 $                                                 **
**                                                                           **
**  $DATE       : 2016-06-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This header file exports functionalities of IOM driver     **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/*  TRACEABILITY: [cover parentID= DS_NAS_IOM_PR1743,DS_NAS_IOM_PR1751_0,    **
**               DS_NAS_IOM_PR1751_1,DS_NAS_IOM_PR1747_1,DS_NAS_IOM_PR1747   **
**               DS_NAS_IOM_PR1745,DS_NAS_IOM_PR1745_1,DS_NAS_IOM_PR1746_1,  **
**               DS_NAS_IOM_PR1746,DS_NAS_IOM_PR1752,DS_NAS_IOM_PR1753_1,    **
**               DS_NAS_IOM_PR1753,DS_NAS_IOM_PR1748,DS_NAS_IOM_PR1749,      **
**               DS_NAS_IOM_PR1759_1,DS_NAS_IOM_PR1759_2]
[/cover]
*/


#ifndef  IOM_H
#define  IOM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Iom Pre-compile/static configuration file */
#include "Iom_Cfg.h"

/* Include Iom definitions  */
#include "IfxIom_reg.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"
#include "Mcal_DmaLib.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (IOM_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

#endif /* (IOM_DEV_ERROR_DETECT == STD_ON) */

#if ((IOM_USER_MODE_INIT_API_ENABLE == STD_ON) || \
     (IOM_USER_MODE_RUNTIME_API_ENABLE == STD_ON) || \
     (IOM_USER_MODE_DEINIT_API_ENABLE == STD_ON) ||\
     (IOM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
           #include "Iom_Protect.h"
#endif
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/*
  Macros used in protected mode support.
*/
#define IOM_CLC_DISS                0x00000002U
#define IOM_CLC_DISR                0xFFFFFFFEU
#define IOM_KRST0_RSTSTAT           0x00000002U
#define IOM_FPCCTR_CMP              0xFFFF0000U
#define IOM_FPCCTR_CMP_SETMASK      0x0000FFFFU
#define IOM_CLC_DISS_BITPOS         1U
#define IOM_KRST0_RSTSTAT_BITPOS    1U
#define IOM_INIT_ACCESS             1U
#define IOM_DEINIT_ACCESS           2U
#define IOM_RUNTIME_ACCESS          3U



#if (IOM_USER_MODE_INIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_RESETENDINIT()           IOM_INIT_RESETENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_SETENDINIT()             IOM_INIT_SETENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
 /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_WRITE32(reg,value)      IOM_INIT_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_MODIFY32(reg,clearmask,setmask)     \
                                  IOM_INIT_MODIFY32((reg),(clearmask),(setmask))
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_RESETSAFETYENDINIT_TIMED(Time)  \
                                        IOM_INIT_RESETSAFETYENDINIT_TIMED(Time)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_SETSAFETYENDINIT_TIMED()  IOM_INIT_SETSAFETYENDINIT_TIMED()
#if (IOM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define IOM_SFR_INIT_USER_MODE_WRITE32(reg, value)        \
                              IOM_INIT_USER_MODE_OS_API_WRITE32((reg),(value))
   /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define IOM_SFR_INIT_USER_MODE_READ32(reg)                 \
                                          IOM_INIT_USER_MODE_OS_API_READ32(reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define IOM_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
                 IOM_INIT_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
  #else
   /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define IOM_SFR_INIT_USER_MODE_WRITE32(reg,value)    ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define IOM_SFR_INIT_USER_MODE_READ32(reg)                   (reg)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define IOM_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
     { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                                   (reg) = val;}
#endif /* IOM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_RESETENDINIT()                   (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_WRITE32(reg, value)              ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
 /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_MODIFY32(reg, clearmask,setmask) \
  {uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask);(reg) = val;}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_SETENDINIT()                      (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_RESETSAFETYENDINIT_TIMED(Time)       \
                                           (Mcal_ResetSafetyENDINIT_Timed(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_SETSAFETYENDINIT_TIMED()    (Mcal_SetSafetyENDINIT_Timed())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_USER_MODE_WRITE32(reg, value)     ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_INIT_USER_MODE_READ32(reg)             (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
   /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
  {uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask);(reg) = val;}
#endif /* IOM_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (IOM_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define IOM_SFR_RUNTIME_RESETENDINIT()         IOM_RUNTIME_RESETENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define IOM_SFR_RUNTIME_SETENDINIT()           IOM_RUNTIME_SETENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_RUNTIME_MODIFY32(reg,clearmask,setmask)   \
                             IOM_RUNTIME_MODIFY32((reg),(clearmask),(setmask))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define IOM_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(Time)  \
                              IOM_RUNTIME_RESETSAFETYENDINIT_TIMED(Time)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define IOM_SFR_RUNTIME_SETSAFETYENDINIT_TIMED()    \
                               IOM_RUNTIME_SETSAFETYENDINIT_TIMED()
#if (IOM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
    #define IOM_SFR_RUNTIME_USER_MODE_WRITE32(reg, value) \
                           IOM_RUNTIME_USER_MODE_OS_API_WRITE32((reg),(value))
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
    modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
    #define IOM_SFR_RUNTIME_USER_MODE_READ32(reg)        \
                                        IOM_RUNTIME_USER_MODE_OS_API_READ32(reg)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
     modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
    #define IOM_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
              IOM_RUNTIME_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
     modification of OS protected calls, so it cannot be expand to a braced
    initialiser*/
  #define IOM_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)         ((reg) = (value))
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define IOM_SFR_RUNTIME_USER_MODE_READ32(reg)                 (reg)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define IOM_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
      { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                                   (reg) = val;}
#endif /* IOM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_RUNTIME_RESETENDINIT()           (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_RUNTIME_MODIFY32(reg, clearmask,setmask) \
  {uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask);(reg) = val;}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_RUNTIME_SETENDINIT()              (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(Time)   \
                                           (Mcal_ResetSafetyENDINIT_Timed(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_RUNTIME_SETSAFETYENDINIT_TIMED() (Mcal_SetSafetyENDINIT_Timed())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)    ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_RUNTIME_USER_MODE_READ32(reg)      (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
   {uint32 val ; val = (reg); val &= (clearmask); val |= (setmask);(reg) = val;}
#endif /* IOM_USER_MODE_RUNTIME_API_ENABLE = STD_ON */

#if (IOM_USER_MODE_DEINIT_API_ENABLE == STD_ON)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define IOM_SFR_DEINIT_RESETENDINIT()            IOM_DEINIT_RESETENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
#define IOM_SFR_DEINIT_SETENDINIT()              IOM_DEINIT_SETENDINIT()
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_WRITE32(reg,value)   IOM_DEINIT_WRITE32((reg),(value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)  \
                             IOM_DEINIT_MODIFY32((reg),(clearmask),(setmask))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_RESETSAFETYENDINIT_TIMED(Time)    \
                              IOM_DEINIT_RESETSAFETYENDINIT_TIMED(Time)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_SETSAFETYENDINIT_TIMED() \
                                            IOM_DEINIT_SETSAFETYENDINIT_TIMED()
#if (IOM_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
initialiser*/
    #define IOM_SFR_DEINIT_USER_MODE_WRITE32(reg, value)\
                          IOM_DEINIT_USER_MODE_OS_API_WRITE32((reg),(value))
   /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
     calls definition, it is declared as a function like macro*/
     /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
        modification of OS protected calls, so it cannot be expand to a braced
        initialiser*/
    #define IOM_SFR_DEINIT_USER_MODE_READ32(reg)\
               IOM_DEINIT_USER_MODE_OS_API_READ32(reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
      #define IOM_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
          IOM_DEINIT_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define IOM_SFR_DEINIT_USER_MODE_WRITE32(reg,value)    ((reg) = (value))
   /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    #define IOM_SFR_DEINIT_USER_MODE_READ32(reg)             (reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
    #define IOM_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
      { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                                (reg) = val;}
    #endif /* IOM_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */
#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_DEINIT_RESETENDINIT()            (Mcal_ResetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
   /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_WRITE32(reg, value)       ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_MODIFY32(reg, clearmask,setmask) \
     { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                               (reg) = val;}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_DEINIT_SETENDINIT()               (Mcal_SetENDINIT())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_DEINIT_RESETSAFETYENDINIT_TIMED(Time)   \
                          (Mcal_ResetSafetyENDINIT_Timed(Time))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_DEINIT_SETSAFETYENDINIT_TIMED()  (Mcal_SetSafetyEndInit_Timed())
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_DEINIT_USER_MODE_WRITE32(reg, value)   ((reg) = (value))
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define IOM_SFR_DEINIT_USER_MODE_READ32(reg)            (reg)
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define IOM_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
     { uint32 val ; val = (reg) ; val &= (clearmask); val |= (setmask); \
                                                                (reg) = val;}
#endif  /* IOM_USER_MODE_DEINIT_API_ENABLE == STD_ON  */

 /* IOM Vendor ID */
#define IOM_VENDOR_ID                     (17U)

/* IOM Module ID */
#define IOM_MODULE_ID                     (255U)

#define IOM_MODULE_GLOB (MODULE_IOM)

#define IOM_SAFETY_ENDINIT_TIMEOUT (150000U)

#define IOM_KRSTCLR_SETMASK_VALUE (0x00000001U)
#define IOM_KRSTCLR_CLRMASK_VALUE (0xFFFFFFFFU)
#define IOM_ACCEN0_CLRMASK_VALUE  (0xFFFFFFFFU)
#define IOM_ACCEN0_SET_VALUE      (0xFFFFFFFFU)
/* Development error codes */

#if (IOM_DEV_ERROR_DETECT == STD_ON)
/* Indicates module is initialized */
#define IOM_INITIALISED       ((uint8)0x01)
/* Indicates module is uninitialized */
#define IOM_UNINITIALIZED     ((uint8)0x00)
/* Inidicates module initialized before calling Iom_Init() */
#define IOM_E_INIT            ((uint8)0x01)
/*  Indicates module uninitialized */
#define IOM_E_UNINIT          ((uint8)0x02)
/* Inidicates invalid configuration pointer */
#define IOM_E_PARAM_CONFIG    ((uint8)0x03)
/* Inidicates invalid parameter */
#define IOM_E_PARAM_INVALID   ((uint8)0x04)


/* Service ID for Iom_Init */
#define IOM_SID_INIT                          ((uint8)0x01U)
#define IOM_SID_DEINIT                        ((uint8)0x02U)
#define IOM_SID_GETVERINFO                    ((uint8)0x03U)
#define IOM_SID_SETFPCCOMP                    ((uint8)0x04U)
#define IOM_SID_GETFPCCOMP                    ((uint8)0x05U)
#define IOM_SID_GETFPCEDGESTAT                ((uint8)0x06U)
#define IOM_SID_CLRFPCEDGESTAT                ((uint8)0x07U)
#define IOM_SID_SETLAMTHRES                   ((uint8)0x08U)
#define IOM_SID_GETLAMTHRES                   ((uint8)0x09U)
#define IOM_SID_GETLAMENTWINCOUNT             ((uint8)0x0AU)
#define IOM_SID_SETLAMCONFIG                  ((uint8)0x0BU)
#define IOM_SID_GETLAMCONFIG                  ((uint8)0x0CU)
#define IOM_SID_GETECMGLOBEVESEL              ((uint8)0x0DU)
#define IOM_SID_SETECMGLOBEVESEL              ((uint8)0x0EU)
#define IOM_SID_GETECMTHRES                   ((uint8)0x0FU)
#define IOM_SID_SETECMTHRES                   ((uint8)0x10U)
#define IOM_SID_GETACCENREG                   ((uint8)0x11U)
#define IOM_SID_SETACCENREG                   ((uint8)0x12U)
#define IOM_SID_RESET                         ((uint8)0x13U)
#define IOM_SID_CLRRESET                      ((uint8)0x14U)
#endif



/*******************************************************************************
** Traceability     : [cover parentID=]                                       **
**                                                                            **
** Syntax           : void Iom_GetVersionInfo                                 **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : VersionInfoPtr - Pointer to store the                   **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - returns the version information of this module                         **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This function is available if the IOM_VERSION_INFO_API is set ON       **
**                                                                            **
*******************************************************************************/
/* Enable / Disable the use of the function */
#if ( ((IOM_VERSION_INFO_API == STD_ON) && (IOM_DEV_ERROR_DETECT == STD_ON)) )
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function
 like macro as per AUTOSAR*/
 /*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define Iom_GetVersionInfo(VersionInfoPtr)                                    \
{                                                                              \
  /* Check for DET: IOM_E_PARAM_INVALID */                                    \
  if ((VersionInfoPtr) == NULL_PTR)                                            \
  {                                                                            \
    /* Report IOM_E_PARAM_INVALID DET if service called with                  \
       NULL_PTR                                                                \
    */                                                                         \
    Det_ReportError(                                                           \
      (uint16)IOM_MODULE_ID,                                                  \
      IOM_INSTANCE_ID,                                                        \
      IOM_SID_GETVERINFO,                                                    \
      IOM_E_PARAM_INVALID);                                                   \
  }                                                                            \
  else                                                                         \
  {                                                                            \
        /* Vendor ID information */                                            \
        ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = IOM_VENDOR_ID;   \
        /* Iom module ID information */                                       \
        ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = IOM_MODULE_ID;   \
        /* Iom module Software major version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =           \
                                           (uint8)IOM_SW_MAJOR_VERSION;       \
        /* Iom module Software minor version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =           \
                                           (uint8)IOM_SW_MINOR_VERSION;       \
        /* Iom module Software patch version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =           \
                                           (uint8)IOM_SW_PATCH_VERSION;       \
  }                                                                            \
}
#elif((IOM_VERSION_INFO_API == STD_ON) && (IOM_DEV_ERROR_DETECT == STD_OFF))
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function
 like macro as per AUTOSAR*/
  /*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define Iom_GetVersionInfo(VersionInfoPtr)                                    \
{                                                                              \
  /* Vendor ID information */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = IOM_VENDOR_ID;         \
  /* Iom module ID information */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = IOM_MODULE_ID;         \
  /* Iom module Software major version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                     (uint8)IOM_SW_MAJOR_VERSION;             \
  /* Iom module Software minor version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                     (uint8)IOM_SW_MINOR_VERSION;             \
  /* Iom module Software patch version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                     (uint8)IOM_SW_PATCH_VERSION;             \
}/* Iom_GetVersionInfo */
#else /*(IOM_VERSION_INFO_API==STD_OFF)&&(IOM_DEV_ERROR_DETECT==STD_OFF)*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function
 like macro as per AUTOSAR*/
#define Iom_GetVersionInfo(VersionInfoPtr)                                    \
(ERROR_Iom_GetVersionInfo_NOT_SELECTED)

#endif /* (IOM_VERSION_INFO_API) */
/*lint +e961*/
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/


 /* Type definition for FPC module */
typedef struct Iom_FpcConfigType
{
  uint32 FpcCfg;  /* FPC control value and compare value */
  uint16 FpcNo;    /* FPC unit Id */
}Iom_FpcConfigType;

/* Type definition for LAM module */
typedef struct Iom_LamConfigType
{
  uint32 LamEntWinCount; /* LAM event window threshold */
  uint32 LamCfg;  /* LAM Configuration register value */
  uint16 LamNo;    /* LAM unit Id */
}Iom_LamConfigType;

/* Type definition for ECM module */
typedef struct Iom_EcmConfigType
{
  uint32 EcmCountConfig;  /* ECM counter configuration register value*/
  uint32 EcmGlobEntSel;  /* ECM golbal event selection register value*/
}Iom_EcmConfigType;

/* Type definition for IOM channel */
typedef struct Iom_ConfigType
{
  const Iom_FpcConfigType *FpcConfig;
  const Iom_LamConfigType *LamConfig;
  const Iom_EcmConfigType *EcmConfig;
  uint32 GtmConfig;
  uint32 ClkCntrl;
  #if(IOM_ACCEN_MODE != IOM_ACCEN_API)
  uint32 AccessEnReg0;
  #endif
  /* Number of FPC and LAM uints */
  uint16 MaxChannel;
}Iom_ConfigType;


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* Declaration of Iom Post Build Configuration */

#define IOM_START_SEC_POSTBUILDCFG
#include "MemMap.h"
extern const struct Iom_ConfigType Iom_ConfigRoot[IOM_CONFIG_COUNT];
#define IOM_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/


/*Memory Map of the  Code*/
#define IOM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Iom_Init(const Iom_ConfigType *ConfigPtr)                    **
**                                                                            **
** Service ID:  0x01                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in): ConfigPtr (Pointer to a selected configuration structure) **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Driver Module Initialization function.                       **
**                                                                            **
*******************************************************************************/
extern void Iom_Init(const Iom_ConfigType *ConfigPtr);

/*******************************************************************************
** Syntax : void Iom_DeInit(void)                                             **
**                                                                            **
** Service ID:  0x02                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Driver Module Deinitialization function.Service for          **
**               deinitializing all hardware timers power on reset state.     **
**                                                                            **
**                                                                            **
*******************************************************************************/
#if (IOM_DEINIT_API == STD_ON)
extern void Iom_DeInit(void);
#else
/*IFX_MISRA_RULE_19_04_STATUS=Iom_DeInit cannot be expand to a braced
 initialiser*/
/*IFX_MISRA_RULE_19_07_STATUS=Iom_DeInit is declared as a function
 like macro as per AUTOSAR*/
#define Iom_DeInit()  ERROR_Gpt_DeInit_NOT_SELECTED

#endif

/*******************************************************************************
** Syntax : void Iom_ClrFpcEdgeStatus(uint8 FpcNo,uint8 Edge)                 **
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): FpcNo: Numeric identifier of the GPT channel              **
**                  Edge: Indicates positive, negative or both edge           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service to clear positive, negative or both edge glitches    **
**                                                                            **
*******************************************************************************/
extern void Iom_ClrFpcEdgeStatus(uint8 FpcNo,uint8 Edge);

/*******************************************************************************
** Syntax : void Iom_ResetKernel(void)                                        **
**                                                                            **
** Service ID:  0x13                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service to reset IOM kernel                             **
**                                                                            **
*******************************************************************************/
extern void Iom_ResetKernel(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Iom_GetFpcEdgeStatus(void)          **
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint32                                                       **
**                                                                            **
** Description : Service for reading the FPC Edge status of register          **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint32 Iom_GetFpcEdgeStatus(void)
{
  return((uint32)IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_FPCESR.U));
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_ClrResetStatus(void)              **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service clear the kernel reset status bit               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_ClrResetStatus(void)
{
  /* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
  the write-protection for
  registers protected via the EndInit feature */
  IOM_SFR_RUNTIME_RESETENDINIT();
  /*update IOM_KRSTCLR register*/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  IOM_SFR_RUNTIME_MODIFY32(IOM_MODULE_GLOB.KRSTCLR.U,\
        IOM_KRSTCLR_CLRMASK_VALUE,IOM_KRSTCLR_SETMASK_VALUE)
  /* set the ENDINIT bit in the WDT_CONSR register in order to enable
  the write-protection for
  registers protected via the EndInit feature */
  IOM_SFR_RUNTIME_SETENDINIT();
  return;
}
/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_SetEcmThresVal(uint8 CounterNo,   **
**                                                       uint8 CountVal)      **
**                                                                            **
** Service ID:  0x10                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): CounterNo: Counter number                                 **
**                  Value: Threshold value for the counter                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description :This service shall change the ECMs counter threshold value    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_SetEcmThresVal(uint8 CounterNo,
                                             uint8 CountVal,
                                             uint8 SelInput)
 {
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 EcmThres;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 CountValue;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 CountId;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 Input;
  CountValue = CountVal & 0x0fU;
  CountId = CounterNo & 0x03U;
  Input = SelInput & 0x0fU;
  EcmThres = ((uint32)Input << (CountId * 8U)) |
              ((uint32)CountValue << (4U + (CountId * 8U)));
   /*update IOM_ECMCCFG register*/
  IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_ECMCCFG.U,EcmThres);
  return;
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint8 Iom_GetEcmThresVal(uint8 CounterNo)  **
**                                                                            **
** Service ID:  0x0F                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): CounterNo : Counter number in ECM                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint8                                                        **
**                                                                            **
** Description : This service shall return threshold value of the counter     **
**               in ECM                                                       **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_8_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint8 Iom_GetEcmThresVal(uint8 CounterNo)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 CountThres;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 ThresVal;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 CounterId;
  CounterId = CounterNo & 0x03U;
  CountThres = (uint32)0x0000000fU <<(4U + (CounterId * 8U));
  ThresVal = (CountThres & IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_ECMCCFG.U))\
                    >> (4U + (CounterId * 8U));
  return((uint8)ThresVal);
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_SetFpcCompare(uint8 FpcNO,        **
**                                                      uint16  CompVal)      **
**                                                                            **
** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): FpcNo: Fpc number                                         **
**                 CompVal: Compare value for the FPC                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: void                                                         **
**                                                                            **
** Description : Service to set FPC compare value                             **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_SetFpcCompare(uint8 FpcNo,uint16 CompVal)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 FpcId;
  FpcId = FpcNo & 0x0fU;
  /*update IOM_FPCCTR register*/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  IOM_SFR_RUNTIME_USER_MODE_MODIFY32\
             (IOM_MODULE_GLOB.FPCCTR[FpcId].U, IOM_FPCCTR_CMP,(uint32)CompVal)
  return;
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint16 Iom_GetFpcCompare(uint8 FpcNO)      **
**                                                                            **
** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): FpcNo: Fpc number                                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint32                                                       **
**                                                                            **
** Description : Service shall be  provided to get the FPC compare value      **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint16 Iom_GetFpcCompare(uint8 FpcNo)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 FpcId;
  FpcId = FpcNo & 0x0fU;
   return ((uint16)((IOM_SFR_INIT_USER_MODE_READ32\
                  (IOM_MODULE_GLOB.FPCCTR[FpcId].U)) & IOM_FPCCTR_CMP_SETMASK));
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_SetLamThreshold(uint8 LamNo,      **
**                                                        uint32 Value)       **
**                                                                            **
** Service ID:  0x08                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): LamNo: LAM unit number                                    **
**                  Value: Threshold value
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service for changing LAM threshold value                     **
**                                                                            **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_SetLamThreshold(uint8 LamNo,uint32 ThresVal)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 LamThres;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 LamId;
  LamId = LamNo & 0x0fU;
  LamThres = ThresVal & 0x00ffffffU;
  /*update IOM_LAMEWS register*/
 IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_MODULE_GLOB.LAMEWS[LamId].U,LamThres);
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Iom_GetLamThreshold(uint8 LamNo)    **
**                                                                            **
** Service ID:  0x09                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in):   LamNO: Lam number                                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: LAM unit threshold value                                     **
**                                                                            **
** Description : Service shall return Lam threshold value                     **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint32 Iom_GetLamThreshold(uint8 LamNo)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 ThresVal;
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 LamId;
  LamId = LamNo & 0x0fU;
  ThresVal = (uint32)IOM_SFR_RUNTIME_USER_MODE_READ32\
                            (IOM_MODULE_GLOB.LAMEWS[LamId].U) & 0x00ffffffU;
  return(ThresVal);
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Iom_GetLamEntWinCount(uint8 LamNo)  **
**                                                                            **
** Service ID:  0x0A                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Non Reentrant                                                 **
**                                                                            **
** Parameters (in): LamNo: Lam number                                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint32                                                       **
**                                                                            **
** Description : Service for reading event window count value                 **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint32 Iom_GetLamEntWinCount(uint8 LamNo)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 LamId;
  LamId = LamNo & 0x0fU;
  return((uint32)IOM_SFR_RUNTIME_USER_MODE_READ32\
                (IOM_MODULE_GLOB.LAMEWC[LamId].U));

}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_SetLamConfig(uint8 LamNo,         **
**                                                     uint32 ConfigVal)      **
**                                                                            **
** Service ID:  0x0B                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): LamNo: LAM unit number                                    **
**                  ConfigVal:LAM configuration value                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service is provided to change LAM configuration         **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_SetLamConfig(uint8 LamNo, uint32 ConfigVal)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 LamId;
  LamId = LamNo & 0x0fU;
  /*update IOM_LAMCFG register*/
  IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_MODULE_GLOB.LAMCFG[LamId].U,\
                                                                     ConfigVal);
}

/******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Iom_GetLamConfig(uint8 LamNo)       **
**                                                                            **
** Service ID:  0x0C                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): LamNo: Lam number                                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint32                                                       **
**                                                                            **
** Description : This service shall return Lam configuration value            **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint32 Iom_GetLamConfig(uint8 LamNo)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint8 LamId;
  LamId = LamNo & 0x0fU;
  return((uint32)IOM_SFR_RUNTIME_USER_MODE_READ32\
                                    (IOM_MODULE_GLOB.LAMCFG[LamId].U));

}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Iom_GetEcmGlobalEveSel(void)        **
**                                                                            **
** Service ID:  0x0D                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: uint32                                                       **
**                                                                            **
** Description : This service shall return Global event selection register    **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint32 Iom_GetEcmGlobalEveSel(void)
{
  return((uint32)IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_ECMSELR.U));
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_SetEcmGlobalEveSel(uint32 Value)  **
**                                                                            **
** Service ID:  0x0E                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Value: To select channel/counter output                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service shall set Global event selection register       **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_SetEcmGlobalEveSel(uint32 Value)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 EcmVal;
  EcmVal = Value & 0x000fffffU;
  /*update IOM_ECMSELR register*/
  IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_ECMSELR.U,EcmVal);
}

#if (IOM_ACCEN_MODE == IOM_ACCEN_API)
/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE uint32 Iom_GetAccessEnReg0(void)           **
**                                                                            **
** Service ID:  0x11                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): None                                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: Access enable register 0 value                               **
**                                                                            **
** Description : This service shall read access enable register 0 value       **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE uint32 Iom_GetAccessEnReg0(void)
{
  return((uint32)IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_ACCEN0.U));
}

/*******************************************************************************
** Syntax : _IFXEXTERN_ IFX_INLINE void Iom_SetAccessEnReg0(uint32 Value)     **
**                                                                            **
** Service ID:  0x12                                                          **
**                                                                            **
** Sync/Async: Synchronous                                                    **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): Value: to set access enable register 0                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : This service shall set access enable register 0 to controls  **
**            write access to IOM kernel addresses for transactions with      **
**               with master tag id n                                         **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
_IFXEXTERN_ IFX_INLINE void Iom_SetAccessEnReg0(uint32 Value)
{
/*IFX_MISRA_RULE_08_05_STATUS=Allowed inline functions defined in header files*/
  uint32 IOM_ACCEN0_SETMASK_VALUE = Value;
    /* Clear the SafetyENDINIT bit in the WDT_CON0 register in order
    to disable the write-protection for registers protected
    via the EndInit feature */
    IOM_SFR_RUNTIME_RESETSAFETYENDINIT(SENT_SAFETY_ENDINIT_TIMEOUT);
        IOM_SFR_RUNTIME_MODIFY32(*((uint32 *)((void *)&IOM_ACCEN0)),\
                          (~IOM_ACCEN0_CLRMASK_VALUE),IOM_ACCEN0_SETMASK_VALUE);
    /* set the SafetyENDINIT bit in the WDT_CON0 register in order
    to enable the write-protection for registers protected
    via the EndInit feature */
    IOM_SFR_RUNTIME_SETSAFETYENDINIT();
}
#endif

#define IOM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"




#endif /* IOM_H */
