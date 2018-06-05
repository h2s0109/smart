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
**  $FILENAME   : Sent.h $                                                   **
**                                                                           **
**  $CC VERSION : \main\20 $                                                 **
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

#ifndef SENT_H
#define SENT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/* Pre-compile/static configuration parameters for SENT  */
#include "Sent_Cfg.h"

/* Conditional Inclusion of Developement Error Tracer File */
#if (SENT_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (SENT_DEV_ERROR_DETECT == STD_ON) */

#if ((SENT_USER_MODE_INIT_API_ENABLE == STD_ON) || \
     (SENT_USER_MODE_RUNTIME_API_ENABLE == STD_ON) || \
     (SENT_USER_MODE_DEINIT_API_ENABLE == STD_ON) || \
     (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON))
           #include "Sent_Protect.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*****************************************1*************************************/

/* SENT Vendor ID */
#define SENT_VENDOR_ID                     (17U)
/* SENT Module ID */
#define SENT_MODULE_ID                     (255U)

/* To access the respective Sent Channel through array indexing */
#define SENT_CHANNEL                       (&(MODULE_SENT.CH[0]))
/* To access the Sent Channel's RDR register through array indexing */
#define SENT_RDR                           (&(MODULE_SENT.RDR[0]))
/* To access the Sent Channel's RDR register through array indexing */
#define SENT_TIMESTAMP                     (&(MODULE_SENT.RTS[0]))
/* To access the Sent Interrupt Nodes through array indexing */
#define SENT_SRC                           (&(SRC_SENT0))

#define SENT_INIT_ACCESS                    (1U)
#define SENT_DEINIT_ACCESS                  (2U)

/*
  Development error codes
*/
#if (SENT_DEV_ERROR_DETECT == STD_ON)

/* Sent module Status Uninitialized */
#define SENT_UNINITIALIZED              ((uint8)0)
/* Status to indicate that SENT module is initialized */
#define SENT_INITIALIZED                ((uint8)1U)

/* Service is called with invalid parameter */
#define SENT_E_PARAM_INVALID           ((uint8)0x0A)

/* Service is called before Init */
#define SENT_E_UNINIT                  ((uint8)0x0B)

/*
  Service ID number for all SENT driver services
*/
/* Service ID for Sent_Init */
#define SENT_SID_INIT                   ((uint8)0)
/* Service ID for Sent_SetChannel */
#define SENT_SID_SETCHANNEL             ((uint8)1)
/* Service ID for Sent_ReadData */
#define SENT_SID_READDATA               ((uint8)2)
/* Service ID for Sent_ReadSerialData */
#define SENT_SID_READSERIALDATA         ((uint8)3)
/* Service ID for Sent_ReadChannelStatus */
#define SENT_SID_READCHANSTATUS         ((uint8)4)
/* Service ID for Sent_SpcGenPulse */
#define SENT_SID_SPCGENPULSE            ((uint8)5)
/* Service ID for Sent_SetWdgTimer */
#define SENT_SID_CONFIGWDG              ((uint8)6)
/* Service ID for Sent_GetVersionInfo */
#define SENT_SID_GETVERINFO             ((uint8)7)
/* Service ID for Sent_GetAccessEnable */
#define SENT_SID_GETACCEN               ((uint8)8)
/* Service ID for Sent_SetAccessEnable */
#define SENT_SID_SETACCEN               ((uint8)9)
/* Service ID for Sent_DeInit */
#define SENT_SID_DEINIT                 ((uint8)10)

#endif /* SENT_DEV_ERROR_DETECT */

/*
  Macros required for configuring the SENT driver
*/

/* Default Interrupt Enable bits
 * SCRI, SDI, WSI, CRCI, NVI, NNI, FDI, FRI, TDI, RBI and RSI
 */
#define SENT_CHANNEL_CFG_INTEN          (0x1FEDU)
#define SENT_TIMEOUT_VALUE              ((uint16)0xFFFFU)

/* SENT Channel Event status bits */
#define SENT_INT_RSI_EVENT              (0x1U)
#define SENT_INT_RDI_EVENT              (0x2U)
#define SENT_INT_RBI_EVENT              (0x4U)
#define SENT_INT_TDI_EVENT              (0x8U)
#define SENT_INT_TBI_EVENT              (0x10U)
#define SENT_INT_FRI_EVENT              (0x20U)
#define SENT_INT_FDI_EVENT              (0x40U)
#define SENT_INT_NNI_EVENT              (0x80U)
#define SENT_INT_NVI_EVENT              (0x100U)
#define SENT_INT_CRCI_EVENT             (0x200U)
#define SENT_INT_WSI_EVENT              (0x400U)
#define SENT_INT_SDI_EVENT              (0x800U)
#define SENT_INT_SCRI_EVENT             (0x1000U)
#define SENT_INT_WDI_EVENT              (0x2000U)
#define SENT_TRANS_INPROGRESS_EVENT     (0x4000U)
#define SENT_MIN_CHANFRAMELEN           (8U)

/*
  Macros used in protected mode support.
*/
#define SENT_CLC_DISS_MASK          0x00000002U
#define SENT_KRST0_RST_CLEARMASK    0xFFFFFFFEU
#define SENT_KRST0_RST_SETMASK      0x00000001U
#define SENT_KRST1_RST_CLEARMASK    0xFFFFFFFFU
#define SENT_KRST1_RST_SETMASK      0x00000001U
#define SENT_KRST0_RSTSTAT_SETMASK  0x00000002U
#define SENT_KRSTCLR_CLR_CLEARMASK  0xFFFFFFFFU
#define SENT_KRSTCLR_CLR_SETMASK    0x00000001U
#define SENT_RCR_CEN_CLEARMASK      0xFFFFFFFEU
#define SENT_CLC_DISR_CLEARMASK     0xFFFFFFFEU
#define SENT_INTEN_RSI_CLEARMASK    0xFFFFFFFEU
#define SENT_INTEN_RDI_CLEARMASK    0xFFFFFFFDU
#define SENT_INTEN_RDI_SETMASK      0x00000002U
#define SENT_INTEN_TBI_CLEARMASK    0xFFFFFFEFU
#define SENT_INTEN_TBI_SETMASK      0x00000010U
#define SENT_INTEN_WDI_CLEARMASK    0xFFFFDFFFU
#define SENT_INTEN_WDI_SETMASK      0x00002000U
#define SENT_SCR_TRQ_MASK           0x00008000U
#define SENT_SRC_SRE_CLEARMASK      0xFFFFFBFFU
#define SENT_SRC_SRE_SETMASK        0x00000400U
#define SENT_CLC_DISR_SETMASK       0x00000001U
#define SENT_FDR_STEP_CLEARMASK     0xFFFFFC00U
#define SENT_FDR_DM_CLEARMASK       0xFFFF3FFFU
#define SENT_FDR_DM_SETMASK         0x00004000U
#define SENT_SDS_SD_MASK            0x0000FFFFU
#define SENT_SDS_MID_MASK           0x00FF0000U
#define SENT_SDS_CON_MASK           0x80000000U
#define SENT_SDS_SCRC_MASK          0x3F000000U
#define SENT_WDT_WDLX_CLEARMASK     0xFFFF0000U
#define SENT_RSR_CST_MASK           0x00000030U
#define SENT_RSR_CRC_MASK           0x0000000FU
#define SENT_RSR_SCN_MASK           0x00000F00U

#define SENT_CLC_DISS_BITPOS        1U
#define SENT_SDS_MID_BITPOS         16U
#define SENT_SDS_CON_BITPOS         31U
#define SENT_SDS_SCRC_BITPOS        24U
#define SENT_RSR_CST_BITPOS         4U
#define SENT_RSR_SCN_BITPOS         8U
#define SENT_SCR_TRQ_BITPOS         15U
#define SENT_KRST0_RSTSTAT_BITPOS   1U


#if (SENT_USER_MODE_INIT_API_ENABLE == STD_ON)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_RESETENDINIT()           (SENT_INIT_RESETENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_SETENDINIT()             (SENT_INIT_SETENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_INIT_WRITE32(reg,value)       SENT_INIT_WRITE32((reg),(value))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_INIT_MODIFY32(reg,clearmask,setmask)  \
                               SENT_INIT_MODIFY32((reg),(clearmask),(setmask));

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_RESETSAFETYENDINIT_TIMED(Time)           \
                       (SENT_INIT_RESETSAFETYENDINIT_TIMED(Time))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_SETSAFETYENDINIT_TIMED()       \
                                            (SENT_INIT_SETSAFETYENDINIT_TIMED())

#if (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_SFR_INIT_USER_MODE_WRITE32(reg, value)     \
                              SENT_INIT_USER_MODE_OS_API_WRITE32((reg),(value))

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a
  braced initialiser*/
  #define SENT_SFR_INIT_USER_MODE_READ32(reg)             \
                                          SENT_INIT_USER_MODE_OS_API_READ32(reg)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
  #define SENT_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
                SENT_INIT_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))

 #else
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define SENT_SFR_INIT_USER_MODE_WRITE32(reg, value)          ((reg) = (value))

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define SENT_SFR_INIT_USER_MODE_READ32(reg)                   (reg)

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define SENT_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
     { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask);\
                                                                 (reg) = (val);}

#endif /* SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */

#else

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_RESETENDINIT()  (Mcal_ResetENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_INIT_WRITE32(reg, value)  ((reg)=(value))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
 /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_INIT_MODIFY32(reg, clearmask,setmask) \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_SETENDINIT() (Mcal_SetENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_RESETSAFETYENDINIT_TIMED(Time)       \
                      (Mcal_ResetSafetyENDINIT_Timed(Time))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_SETSAFETYENDINIT_TIMED()   (Mcal_SetSafetyENDINIT_Timed())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_INIT_USER_MODE_WRITE32(reg,value)     ((reg) = (value))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_INIT_USER_MODE_READ32(reg) (reg)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
   /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_INIT_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
    { uint32 (val); (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}

#endif /* SENT_USER_MODE_INIT_API_ENABLE == STD_ON  */

#if (SENT_USER_MODE_RUNTIME_API_ENABLE == STD_ON)
/*SENT UserMode is enabled*/
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(Time)  \
                   (SENT_RUNTIME_RESETSAFETYENDINIT_TIMED(Time))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_RUNTIME_SETSAFETYENDINIT_TIMED() \
                                        (SENT_RUNTIME_SETSAFETYENDINIT_TIMED())

#if (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)

    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
    #define SENT_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)  \
                          SENT_RUNTIME_USER_MODE_OS_API_WRITE32((reg), (value))

    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
    #define SENT_SFR_RUNTIME_USER_MODE_READ32(reg)        \
                                      SENT_RUNTIME_USER_MODE_OS_API_READ32(reg)
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
    calls definition, it is declared as a function like macro*/
   /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
    #define SENT_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
             SENT_RUNTIME_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))

#else
   /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define SENT_SFR_RUNTIME_USER_MODE_WRITE32(reg, value)     ((reg) = (value))

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  #define SENT_SFR_RUNTIME_USER_MODE_READ32(reg)    (reg)

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask) \
      { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); \
                                           (val) |= (setmask); (reg) = (val);}

#endif /* SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON  */

#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_RUNTIME_RESETSAFETYENDINIT_TIMED(Time)   \
                      (Mcal_ResetSafetyENDINIT_Timed(Time))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_RUNTIME_SETSAFETYENDINIT_TIMED() \
                                                (Mcal_SetSafetyENDINIT_Timed())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_RUNTIME_USER_MODE_WRITE32(reg,value)    ((reg) = (value))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_RUNTIME_USER_MODE_READ32(reg)      (reg)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_RUNTIME_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
   { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}

#endif /* SENT_USER_MODE_RUNTIME_API_ENABLE = STD_ON */

#if (SENT_USER_MODE_DEINIT_API_ENABLE == STD_ON)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_DEINIT_RESETENDINIT()  (SENT_DEINIT_RESETENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_DEINIT_SETENDINIT()    (SENT_DEINIT_SETENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_DEINIT_MODIFY32(reg,clearmask,setmask)  \
                               SENT_DEINIT_MODIFY32((reg),(clearmask),(setmask))

#if (SENT_RUNNING_IN_USER_0_MODE_ENABLE == STD_ON)
  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
  initialiser*/
  #define SENT_SFR_DEINIT_USER_MODE_READ32(reg) \
                                SENT_DEINIT_USER_MODE_OS_API_READ32(reg)

  /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
/*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
  #define SENT_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
              SENT_DEINIT_USER_MODE_OS_API_MODIFY32((reg),(clearmask),(setmask))

#else
    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    #define SENT_SFR_DEINIT_USER_MODE_READ32(reg)      (reg)

    /*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
   modification of OS protected calls, so it cannot be expand to a braced
   initialiser*/
    #define SENT_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask) \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}
    #endif /* SENT_RUNNING_IN_USER_MODE_ENABLE == STD_ON  */

#else
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_DEINIT_RESETENDINIT()  (Mcal_ResetENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
  modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_DEINIT_MODIFY32(reg, clearmask,setmask) \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                               (reg) = (val);}
/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define SENT_SFR_DEINIT_SETENDINIT()  (Mcal_SetENDINIT())

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
  /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_DEINIT_USER_MODE_READ32(reg)         (reg)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
    /*IFX_MISRA_RULE_19_04_STATUS=First level of indirection is used to support
modification of OS protected calls, so it cannot be expand to a braced
 initialiser*/
#define SENT_SFR_DEINIT_USER_MODE_MODIFY32(reg,clearmask,setmask)  \
    { uint32 (val) ; (val) = (reg) ; (val) &= (clearmask); (val) |= (setmask); \
                                                                (reg) = (val);}

#endif  /* SENT_USER_MODE_DEINIT_API_ENABLE == STD_ON  */


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* SPC Related Typedefs */
#if (SENT_SPC_USED == STD_ON)

typedef enum
{
  PULSE_NOMINAL_FREQ,
  PULSE_LAST_SYNC_FREQ,
}Sent_SpcTimeBaseType;

typedef enum
{
  PULSE_STOP,
  PULSE_START_IMMED,
  PULSE_START_SYNC,
  PULSE_START_EXT_TRIGGER,
}Sent_SpcTrigSrcType;

typedef enum
{
  SYNC_MODE,
  BIDIRECTIONAL_MODE,
}Sent_SpcMode;

typedef struct _Sent_SpcType
{
  Sent_SpcMode          Mode;
  Sent_SpcTrigSrcType   TriggerSource;
  Sent_SpcTimeBaseType  TimeBase;
  uint8                 PulseLength;
  uint8                 Delay;
}Sent_SpcType;

#endif /* (SENT_SPC_USED == STD_ON) */

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define SENT_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/* Declaration of Sent Post Build Configuration */
extern const Sent_ConfigType Sent_ConfigRoot[SENT_CONFIG_COUNT];

#define SENT_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

#define SENT_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* Declaration of the Sent driver configuration pointer */
extern const Sent_ConfigType  *Sent_kConfigPtr;
#define SENT_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#define SENT_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_Init                                          **
**                    (                                                       **
**                      const Sent_ConfigType *ConfigPtr                      **
**                    )                                                       **
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
extern void Sent_Init
(
  const Sent_ConfigType *ConfigPtr
);

/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_SetChannel                                    **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      Sent_ChanOpType Operation                             **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
**                    Operation - Enable/Disable the channel
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:
**                      - Enables/Disables the SENT Channel                   **
*******************************************************************************/
extern void Sent_SetChannel
(
  Sent_ChannelIdxType ChannelId,
  Sent_ChanOpType Operation
);

/*******************************************************************************
**                                                                            **
** Syntax           : uint32 Sent_ReadData                                    **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId                         **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
**                                                                            **
** Parameters (out) : Data read from the SENT Channel                         **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - reads the nibbles recieved in the Data register     **
*******************************************************************************/
extern uint32 Sent_ReadData
(
  Sent_ChannelIdxType ChannelId
);

/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_ReadSerialData                                **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      Sent_RxSerialDataType *DataPtr                        **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x03                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
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
extern void Sent_ReadSerialData
(
  Sent_ChannelIdxType ChannelId,
  Sent_RxSerialDataType *DataPtr
);

/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_ReadChannelStatus                             **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      Sent_ChanStatusType *StatPtr                          **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
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
extern void Sent_ReadChannelStatus
(
  Sent_ChannelIdxType ChannelId,
  Sent_ChanStatusType *StatPtr
);

#if (SENT_SPC_USED == STD_ON)
/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_SpcGenPulse                                   **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      const Sent_SpcType *SpcCfgPtr                         **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x05                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
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
extern void Sent_SpcGenPulse
(
  Sent_ChannelIdxType ChannelId,
  const Sent_SpcType *SpcCfgPtr
);
#endif

/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_SetWdgTimer                                   **
**                    (                                                       **
**                      Sent_ChannelIdxType ChannelId,                        **
**                      uint16 WdgTimerReloadVal                              **
**                    )                                                       **
**                                                                            **
** Service ID       : 0x06                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
**                    WdgTimerReloadVal - Watchdog Reload Timer value         **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - configures the Channel's watchdog timer             **
*******************************************************************************/
extern void Sent_SetWdgTimer
(
  Sent_ChannelIdxType ChannelId,
  uint16 WdgTimerReloadVal
);

/*******************************************************************************
** Traceability     : [cover parentID=]                                       **
**                                                                            **
** Syntax           : void Sent_GetVersionInfo                                **
**                    (                                                       **
**                      Std_VersionInfoType *VersionInfoPtr                   **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x07                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : VersionInfoPtr - Pointer to where to store the          **
**                    version information of this module.                     **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - returns the version information of this module                         **
**     The version information include : Module ID, Vendor ID,                **
**     Vendor specific version numbers                                        **
**   - This function is available if the SENT_VERSION_INFO_API is set ON      **
**                                                                            **
*******************************************************************************/
/* Enable / Disable the use of the function */
#if ( ((SENT_VERSION_INFO_API == STD_ON) && (SENT_DEV_ERROR_DETECT == STD_ON)) )
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like
macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define Sent_GetVersionInfo(VersionInfoPtr)                                    \
{                                                                              \
  /* Check for DET: SENT_E_PARAM_INVALID */                                    \
  if ((VersionInfoPtr) == NULL_PTR)                                            \
  {                                                                            \
    /* Report SENT_E_PARAM_INVALID DET if service called with                  \
       NULL_PTR                                                                \
    */                                                                         \
    Det_ReportError(                                                           \
      (uint16)SENT_MODULE_ID,                                                  \
      SENT_INSTANCE_ID,                                                        \
      SENT_SID_GETVERINFO,                                                     \
      SENT_E_PARAM_INVALID);                                                   \
  }                                                                            \
  else                                                                         \
  {                                                                            \
        /* Vendor ID information */                                            \
        ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = SENT_VENDOR_ID;   \
        /* Sent module ID information */                                       \
        ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = SENT_MODULE_ID;   \
        /* Sent module Software major version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =           \
                                           (uint8)SENT_SW_MAJOR_VERSION;       \
        /* Sent module Software minor version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =           \
                                           (uint8)SENT_SW_MINOR_VERSION;       \
        /* Sent module Software patch version information */                   \
        ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =           \
                                           (uint8)SENT_SW_PATCH_VERSION;       \
  }                                                                            \
}
#elif((SENT_VERSION_INFO_API == STD_ON) && (SENT_DEV_ERROR_DETECT == STD_OFF))
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as a function like
macro as per AUTOSAR*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced
 initialiser*/
#define Sent_GetVersionInfo(VersionInfoPtr)                                    \
{                                                                              \
  /* Vendor ID information */                                                  \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = SENT_VENDOR_ID;         \
  /* Sent module ID information */                                             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = SENT_MODULE_ID;         \
  /* Sent module Software major version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =                 \
                                     (uint8)SENT_SW_MAJOR_VERSION;             \
  /* Sent module Software minor version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =                 \
                                     (uint8)SENT_SW_MINOR_VERSION;             \
  /* Sent module Software patch version information */                         \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =                 \
                                     (uint8)SENT_SW_PATCH_VERSION;             \
}/* Sent_GetVersionInfo */
#else /*(SENT_VERSION_INFO_API==STD_OFF)&&(SENT_DEV_ERROR_DETECT==STD_OFF)*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macro used to generate compile time
 error in case of incorrect configuration*/
#define Sent_GetVersionInfo(VersionInfoPtr)                                    \
(ERROR_Sent_GetVersionInfo_NOT_SELECTED)

#endif /* (SENT_VERSION_INFO_API) */

#if (SENT_ACCEN_MODE == SENT_ACCEN_API)
/*******************************************************************************
**                                                                            **
** Syntax           : uint32 Sent_GetAccessEnable                             **
**                    (                                                       **
**                    )                                                       **
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
** Return value    : none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - retrieves the SENT_ACCEN0 register value            **
*******************************************************************************/
extern uint32 Sent_GetAccessEnable
(
  void
);

/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_SetAccessEnable                               **
**                    (                                                       **
**                      uint32 AccenRegVal                                    **
**                    )                                                       **
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
extern void Sent_SetAccessEnable
(
  uint32 AccenRegVal
);
#endif /* (SENT_ACCEN_API == STD_ON) */

#if (SENT_DEINIT_API == STD_ON)
/*******************************************************************************
**                                                                            **
** Syntax           : void Sent_DeInit                                        **
**                    (                                                       **
**                      void                                                  **
**                    )                                                       **
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
extern void Sent_DeInit
(
  void
);
#endif

/*******************************************************************************
**                      Global Function Declarations:                         **
**             Functions to be Called From Interrupt/Scheduler Context        **
*******************************************************************************/
/*******************************************************************************
** Syntax           : void Sent_Isr (Sent_ChannelIdxType ChannelId)           **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       Non-Reentrant                                            **
**                                                                            **
** Parameters(in)   : ChannelId - SENT logical channel                        **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description      : This function:                                          **
**                      - is the interrupt handler and collects the status    **
**                        of the relevant channels and inform the user        **
*******************************************************************************/
extern void Sent_Isr(Sent_ChannelIdxType ChannelId);


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#define SENT_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

#endif /* SENT_H */
