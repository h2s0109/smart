/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Iom.c $                                                    **
**                                                                            **
**  $CC VERSION : \main\27 $                                                 **
**                                                                            **
**  $DATE       : 2016-05-18 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                functionality of IOM driver.                                **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/


/* Own header file, this includes precompile/static configuration file also */
#include "Iom.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

#ifndef IOM_SW_MAJOR_VERSION
#error "IOM_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef IOM_SW_MINOR_VERSION
#error "IOM_SW_MINOR_VERSION is not defined. "
#endif

#ifndef IOM_SW_PATCH_VERSION
#error "IOM_SW_PATCH_VERSION is not defined. "
#endif

/* Check for Correct inclusion of headers */
#if ( IOM_SW_MAJOR_VERSION != 2U )
#error "IOM_SW_MAJOR_VERSION does not match. "
#endif
#if ( IOM_SW_MINOR_VERSION != 1U )
#error "IOM_SW_MINOR_VERSION does not match. "
#endif

#if (IOM_DEV_ERROR_DETECT == STD_ON)

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

#endif /*#if (IOM_DEV_ERROR_DETECT == STD_ON)*/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define IOM_KRST_TIMEOUT_VALUE  (0x00000100U)

#define IOM_REG_SETMASK_VALUE   (0x00000001U)
#define IOM_REG_CLRMASK_VALUE   (0xFFFFFFFFU)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define IOM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"
/* Function to reset Kernels */
static void Iom_lResetKernels(uint8 ServiceId);
#define IOM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*
* To be used for global or static variables (32 bits) that are initialized
* after every reset (the normal case)
Inclusion of MemMap.h
*/

#define IOM_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"
#if (IOM_DEINIT_API == STD_ON)
static const Iom_ConfigType *Iom_kConfigPtr;
#endif
#define IOM_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"

#define IOM_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"

#if(IOM_DEV_ERROR_DETECT == STD_ON)
/* To indicate whether IOM driver is initialised or not.
If equal to 1: Driver is initialised
if equal to 0: Driver is deinitiaised */
static uint8 Iom_InitStatus;
#endif

#define IOM_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*Memory Map of the  Code*/
#define IOM_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_IOM_PR1742]                          **
**                                                                            **
** Syntax : void Iom_Init(const Iom_ConfigType *ConfigPtr)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       0x01                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  ConfigPtr - Pointer to configuration set                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This routine initializes the IOM module.                 **
**                                                                            **
*******************************************************************************/
void Iom_Init(const Iom_ConfigType *ConfigPtr)
{
uint8 FpcId;
uint8 LamId;
uint8 ChannelIndex;
/* local pointers to FPC and LAM unit */
const Iom_FpcConfigType *LocalFpcPtr;
const Iom_LamConfigType *LocalLamPtr;
#if (IOM_DEINIT_API == STD_OFF)
const Iom_ConfigType *Iom_kConfigPtr;
#endif
#if(IOM_DEV_ERROR_DETECT == STD_ON)
uint8 DetErr;
DetErr = 0U;
if(Iom_InitStatus == IOM_INITIALISED)
{
/* Report IOM_E_INIT DET */
Det_ReportError((uint16)IOM_MODULE_ID,
IOM_INSTANCE_ID,
IOM_SID_INIT,
IOM_E_INIT
);
/* Skip the API functionality and return from the API */
DetErr = 1U;
}
#if(IOM_PB_FIXED_ADDRESS == STD_OFF)
if(ConfigPtr == NULL_PTR)
#else
if(ConfigPtr != &Iom_ConfigRoot[0U])
#endif /* IOM_PB_FIXED_ADDRESS == STD_OFF */
{
/* Report IOM_E_PARAM_INVAID DET */
Det_ReportError((uint16)IOM_MODULE_ID,
IOM_INSTANCE_ID,
IOM_SID_INIT,
IOM_E_PARAM_CONFIG
);
/* Skip the API functionality and return from the API */
DetErr = 1U;
}
if(DetErr == 0U)
#endif
{
Iom_kConfigPtr = ConfigPtr;
/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_INIT_RESETENDINIT();
/* Enable IOM module clock */
IOM_SFR_INIT_WRITE32(IOM_CLC.U,Iom_kConfigPtr->ClkCntrl);
/* set the ENDINIT bit in the WDT_CONSR register in order to enable the
write-protection for
registers protected via the EndInit feature */
IOM_SFR_INIT_SETENDINIT();

/* Checking  the status of DISS bit in the IOM_CLC Register */
if(((IOM_SFR_INIT_USER_MODE_READ32(IOM_CLC.U) & IOM_CLC_DISS) >> \
IOM_CLC_DISS_BITPOS) == 0U)
{
/*kernel reset for all available kernels*/
#if(IOM_RESET_SFR_INIT == STD_ON)
Iom_lResetKernels(IOM_INIT_ACCESS);
#endif

/* Set Access Enable reg0  */
#if(IOM_ACCEN_MODE != IOM_ACCEN_API)
{
/* Clear the SafetyENDINIT bit in the WDT_CON0 register in order
to disable the write-protection for registers protected
via the EndInit feature */
IOM_SFR_INIT_RESETSAFETYENDINIT_TIMED(IOM_SAFETY_ENDINIT_TIMEOUT);
/*update IOM_ACCEN0 register*/
IOM_SFR_INIT_WRITE32(IOM_ACCEN0.U,Iom_kConfigPtr->AccessEnReg0);
/* set the SafetyENDINIT bit in the WDT_CON0 register in order
to enable the write-protection for registers protected
via the EndInit feature */
IOM_SFR_INIT_SETSAFETYENDINIT_TIMED();
}
#endif
/* Set ECM and GTM configuration registers */
/*update IOM_ECMCCFG register*/
IOM_SFR_INIT_USER_MODE_WRITE32 \
(IOM_ECMCCFG.U,Iom_kConfigPtr->EcmConfig->EcmCountConfig);
/*update IOM_ECMSELR register */
IOM_SFR_INIT_USER_MODE_WRITE32 \
(IOM_ECMSELR.U,Iom_kConfigPtr->EcmConfig->EcmGlobEntSel);
/*update IOM_GTMEXR register */
IOM_SFR_INIT_USER_MODE_WRITE32(IOM_GTMEXR.U, Iom_kConfigPtr->GtmConfig);

/* Set FPC congfiguration register */
for(ChannelIndex = 0U;
ChannelIndex < Iom_kConfigPtr->MaxChannel;
ChannelIndex++)
{
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
LocalFpcPtr = &Iom_kConfigPtr->FpcConfig[ChannelIndex];
FpcId = (uint8)LocalFpcPtr->FpcNo;
/*update IOM_FPCCTR register*/
IOM_SFR_INIT_USER_MODE_WRITE32 \
(IOM_MODULE_GLOB.FPCCTR[FpcId].U, LocalFpcPtr->FpcCfg);
}
/* Set LAM configuartion  */
for(ChannelIndex = 0U;
ChannelIndex < Iom_kConfigPtr->MaxChannel;
ChannelIndex++)
{
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
LocalLamPtr = &Iom_kConfigPtr->LamConfig[ChannelIndex];
LamId = (uint8)LocalLamPtr->LamNo;
/*update IOM_LAMEWS register*/
IOM_SFR_INIT_USER_MODE_WRITE32\
(IOM_MODULE_GLOB.LAMEWS[LamId].U, LocalLamPtr->LamEntWinCount);
/*update IOM_LAMCFG register*/
IOM_SFR_INIT_USER_MODE_WRITE32\
(IOM_MODULE_GLOB.LAMCFG[LamId].U,LocalLamPtr->LamCfg);

}
#if(IOM_DEV_ERROR_DETECT == STD_ON)
/* Set initialisation status to indicate initialization is done */
Iom_InitStatus = IOM_INITIALISED;
#endif  /*(IOM_DEV_ERROR_DETECT == STD_ON)*/
} /*End of ((IOM_SFR_INIT_USER_MODE_READ32(IOM_CLC.U) & IOM_CLC_DISS) >> 1)\
== 0  */
else
{
#if(IOM_DEV_ERROR_DETECT == STD_ON)
/* Set initialisation status to indicate the module is unnitialized */
Iom_InitStatus = IOM_UNINITIALIZED;
#endif /* End of (IOM_DEV_ERROR_DETECT == STD_ON) */
}

} /* DetErr == 0U for IOM_E_PARAM_INVAID */
return;
}/* End of Iom_Init */

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_IOM_PR1750]                          **
**                                                                            **
** Syntax : void Iom_DeInit(void)                                             **
**   [/cover]                                                                 **
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
**               deinitializing all hardware timer channels to their          **
**               power on reset state.                                        **
**                                                                            **
*******************************************************************************/
#if (IOM_DEINIT_API == STD_ON)
void Iom_DeInit(void)
{
volatile uint32 ReadBack;
uint8 FpcId;
uint8 LamId;
uint8 ChannelIndex;
#if (IOM_DEV_ERROR_DETECT == STD_ON)
uint8 DetErr;
DetErr = 0U;
if(Iom_InitStatus == IOM_UNINITIALIZED )
{
/* Report DET IOM_E_UNINIT */
Det_ReportError((uint16)IOM_MODULE_ID,
IOM_INSTANCE_ID,
IOM_SID_DEINIT,
IOM_E_UNINIT
);
DetErr = 1U;
}
if(DetErr == 0U)
#endif
{
/* Set ECM ,GTM and Access enable reg0 registers to reset value */
/*update IOM_ECMCCFG register*/
IOM_SFR_DEINIT_USER_MODE_WRITE32(IOM_ECMCCFG.U,(uint32)0U);
/*update IOM_ECMSELR register*/
IOM_SFR_DEINIT_USER_MODE_WRITE32(IOM_ECMSELR.U,(uint32)0U);
/*update IOM_GTMEXR register*/
IOM_SFR_DEINIT_USER_MODE_WRITE32(IOM_GTMEXR.U,(uint32)0U);

/* Clear the SafetyENDINIT bit in the WDT_CON0 register in order
to disable the write-protection for registers protected
via the EndInit feature */
IOM_SFR_DEINIT_RESETSAFETYENDINIT_TIMED(IOM_SAFETY_ENDINIT_TIMEOUT);
/*update IOM_ACCEN0 register*/
IOM_SFR_DEINIT_WRITE32(IOM_ACCEN0.U,IOM_ACCEN0_SET_VALUE);
/* set the SafetyENDINIT bit in the WDT_CON0 register in order
to enable the write-protection for registers protected
via the EndInit feature */
IOM_SFR_DEINIT_SETSAFETYENDINIT_TIMED();

/* Reset FPC and LAM registers */
for(ChannelIndex = 0U;
ChannelIndex < Iom_kConfigPtr->MaxChannel;
ChannelIndex++)
{
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
FpcId = (uint8)Iom_kConfigPtr->FpcConfig[ChannelIndex].FpcNo;
/*update IOM_FPCCTR register*/
IOM_SFR_DEINIT_USER_MODE_WRITE32(IOM_MODULE_GLOB.FPCCTR[FpcId].U, 0U);
}
for(ChannelIndex = 0U;
ChannelIndex < Iom_kConfigPtr->MaxChannel;
ChannelIndex++)
{
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
LamId = (uint8)Iom_kConfigPtr->LamConfig[ChannelIndex].LamNo;
/*update IOM_LAMEWS register*/
IOM_SFR_DEINIT_USER_MODE_WRITE32(IOM_MODULE_GLOB.LAMEWS[LamId].U, 0U);
/*update IOM_LAMCFG register*/
IOM_SFR_DEINIT_USER_MODE_WRITE32(IOM_MODULE_GLOB.LAMCFG[LamId].U, 0U);
}
/* kernel reset for all available kernels*/
Iom_lResetKernels(IOM_DEINIT_ACCESS);
/* Request to disable the module */
/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_DEINIT_RESETENDINIT();
/*update DISR (bit 0) to 1*/
IOM_SFR_DEINIT_MODIFY32(IOM_CLC.U,IOM_CLC_DISR,(uint32)1U)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_DEINIT_SETENDINIT();
/* Read back the CLC register to flush the pipeline effects */
ReadBack = IOM_SFR_DEINIT_USER_MODE_READ32(IOM_CLC.U);
UNUSED_PARAMETER(ReadBack)

#if(IOM_DEV_ERROR_DETECT == STD_ON)
/* Reset initialisation status to indicate deinitialization is done */
Iom_InitStatus = IOM_UNINITIALIZED ;
#endif  /*(IOM_DEV_ERROR_DETECT == STD_ON)*/

}  /* DetErr = 0  */
return;
} /* end of Deinit API */
#endif



/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_IOM_PR1744]                          **
**                                                                            **
** Syntax : void Iom_ClrFpcEdgeStatus(uint8 FpcNo,uint8 Edge)                 **
**    [/cover]                                                                **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Reentrant                                                     **
**                                                                            **
** Parameters (in): FpcNo: Numeric identifier of the GPT channel              **
**                  Edge: Indicates positive, negative or both edge           **
** Parameters (out): None                                                     **
**                                                                            **
** Return value: None                                                         **
**                                                                            **
** Description : Service to clear rising nad falling edge glitches            **
**                                                                            **
*******************************************************************************/
void Iom_ClrFpcEdgeStatus(uint8 FpcNo,uint8 Edge)
{
uint32 EdgeRsClr;
uint32 EdgeFaClr;
uint32 EdgeClr;
uint8 FpcId;
uint8 EdgeNo;
FpcId = FpcNo & 0x0fU;
EdgeNo = Edge & 0x03U;
if(EdgeNo == 0U) /* to clear rising edge */
{
EdgeRsClr = ~((uint32)1U << (FpcId + 16U));
EdgeClr = IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_FPCESR.U) & EdgeRsClr;
/*update IOM_FPCESR register*/
IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_FPCESR.U,EdgeClr);

}
else if(EdgeNo == 1U) /* to clear falling edge */
{
EdgeFaClr = ~((uint32)1U << FpcId);
EdgeClr = EdgeFaClr & EdgeFaClr;
/*update IOM_FPCESR register*/
IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_FPCESR.U,EdgeClr);
}
else if(EdgeNo == 2U) /* to clear both edges */
{
EdgeFaClr = ~((uint32)1U << FpcId);
EdgeRsClr = ~((uint32)1U << (FpcId + 16U));
EdgeClr = EdgeFaClr & EdgeRsClr;
/*update IOM_FPCESR register*/
IOM_SFR_RUNTIME_USER_MODE_WRITE32(IOM_FPCESR.U, EdgeClr);
}
else
{
/* Empty  */
}
return;
}


/*******************************************************************************
** Traceability    :                                                          **
**                                                                            **
** Syntax          : static void Iom_lResetKernels(uint8)                     **
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
static void Iom_lResetKernels(uint8 ServiceId)
{
volatile uint32 ReadBack;
uint32 TimeOutVar;
if(ServiceId == IOM_INIT_ACCESS)
{
/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for
registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_INIT_RESETENDINIT();
/*update IOM_KRST0 register*/
IOM_SFR_INIT_MODIFY32(IOM_KRST0.U,\
(IOM_REG_CLRMASK_VALUE),IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_INIT_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_INIT_USER_MODE_READ32(IOM_KRST0.U);

/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for
registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_INIT_RESETENDINIT();
/*update IOM_KRST1 register*/
IOM_SFR_INIT_MODIFY32(IOM_KRST1.U,\
IOM_REG_CLRMASK_VALUE,IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_INIT_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_INIT_USER_MODE_READ32(IOM_KRST1.U);
TimeOutVar = IOM_KRST_TIMEOUT_VALUE;
do
{
TimeOutVar--;
}while(((((IOM_SFR_INIT_USER_MODE_READ32(IOM_KRST0.U)) &\
IOM_KRST0_RSTSTAT) >> IOM_KRST0_RSTSTAT_BITPOS)!= 1U) &&\
(TimeOutVar > 0U));

/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_INIT_RESETENDINIT();
/*update IOM_KRSTCLR register */
IOM_SFR_INIT_MODIFY32(IOM_KRSTCLR.U,\
(IOM_REG_CLRMASK_VALUE),IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for registers protected via the EndInit feature */
IOM_SFR_INIT_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_INIT_USER_MODE_READ32(IOM_KRSTCLR.U);

}
else if(ServiceId == IOM_DEINIT_ACCESS)
{
/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for
registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_DEINIT_RESETENDINIT();
/*update IOM_KRST0 register*/
IOM_SFR_DEINIT_MODIFY32(IOM_KRST0.U,\
(IOM_REG_CLRMASK_VALUE),IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_DEINIT_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_DEINIT_USER_MODE_READ32(IOM_KRST0.U);
/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for
registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_DEINIT_RESETENDINIT();
/*update IOM_KRST1 register*/
IOM_SFR_DEINIT_MODIFY32(IOM_KRST1.U,\
IOM_REG_CLRMASK_VALUE,IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for
registers protected via the EndInit feature */
IOM_SFR_DEINIT_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_DEINIT_USER_MODE_READ32(IOM_KRST1.U);
TimeOutVar = IOM_KRST_TIMEOUT_VALUE;
do
{
TimeOutVar--;
}while(((((IOM_SFR_DEINIT_USER_MODE_READ32(IOM_KRST0.U)) &\
IOM_KRST0_RSTSTAT) >> IOM_KRST0_RSTSTAT_BITPOS)!= 1U) &&\
(TimeOutVar > 0U));

/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_DEINIT_RESETENDINIT();
/*update IOM_KRSTCLR register */
IOM_SFR_DEINIT_MODIFY32(IOM_KRSTCLR.U,\
(IOM_REG_CLRMASK_VALUE),IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for registers protected via the EndInit feature */
IOM_SFR_DEINIT_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_DEINIT_USER_MODE_READ32(IOM_KRSTCLR.U);

}
else
{
/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_RUNTIME_RESETENDINIT();
/*update IOM_KRST0 register*/
IOM_SFR_RUNTIME_MODIFY32(IOM_KRST0.U,\
(IOM_REG_CLRMASK_VALUE),IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for registers protected via the EndInit feature */
IOM_SFR_RUNTIME_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_KRST0.U);

/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for registers protected via the EndInit feature*/
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_RUNTIME_RESETENDINIT();
/*update IOM_KRST1 register*/
IOM_SFR_RUNTIME_MODIFY32(IOM_KRST1.U,\
IOM_REG_CLRMASK_VALUE,IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for registers protected via the EndInit feature */
IOM_SFR_RUNTIME_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_KRST1.U);
TimeOutVar = IOM_KRST_TIMEOUT_VALUE;
do
{
TimeOutVar--;
}while(((((IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_KRST0.U)) &\
IOM_KRST0_RSTSTAT) >> IOM_KRST0_RSTSTAT_BITPOS) != 1U) &&\
(TimeOutVar > 0U));

/* Clear the ENDINIT bit in the WDT_CONSR register in order to disable
the write-protection for registers protected via the EndInit feature */
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
IOM_SFR_RUNTIME_RESETENDINIT();
/*update IOM_KRSTCLR register */
IOM_SFR_RUNTIME_MODIFY32(IOM_KRSTCLR.U,\
(IOM_REG_CLRMASK_VALUE),IOM_REG_SETMASK_VALUE)
/* set the ENDINIT bit in the WDT_CONSR register in order to enable
the write-protection for registers protected via the EndInit feature */
IOM_SFR_RUNTIME_SETENDINIT();
/*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic is used to
efficiently access the SFRs of multiple IOM kernels*/
ReadBack = (uint32)IOM_SFR_RUNTIME_USER_MODE_READ32(IOM_KRSTCLR.U);

}
UNUSED_PARAMETER(ReadBack)
}

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
void Iom_ResetKernel(void)
{
Iom_lResetKernels(IOM_RUNTIME_ACCESS);
return;
}


#define IOM_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
allowed only for MemMap.h*/
#include "MemMap.h"
