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
**  $FILENAME  : Dma_Callout.c                                                **
**                                                                            **
**  $CC VERSION : \main\3 $                                                  **
**                                                                            **
**  $DATE      : 2013-06-26 $                                                 **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Implementation of DMA call out functions                 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/
/*  TRACEABILITY :                                                            **
**                                                                            */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Inclusion of Dma.h header file */
#include "Dma_Callout.h"
/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*Memory Map of the DMA Code*/
#define DMA_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
void Dma_ErrorCallOut(uint8 Channel, uint8 Error)
{
	UNUSED_PARAMETER(Channel)
	UNUSED_PARAMETER(Error)
	/*User Code Begins Here*/
}
#define DMA_STOP_SEC_CODE
#include "MemMap.h"