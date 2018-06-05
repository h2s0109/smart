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
**  $FILENAME  : Bfx.h $                                                      **
**                                                                            **
**  $CC VERSION : \main\26 $                                                 **
**                                                                            **
**  $DATE      : 2013-06-26 $                                                 **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This header file exports                                   **
**                 - functionality of BFX Library.                            **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
/*  TRACEABILITY : [cover parentID=SAS_AS_BFX220,SAS_NAS_ALL_PR746            **
                                        ,SAS_NAS_ALL_PR748,]                  **
**                 [/cover]                                                   */

#ifndef BFX_H
#define BFX_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Platform_Types.h and Compiler.h  */
/*[cover parentID=SAS_AS_BFX211]*/
/*[cover parentID=DS_AS_BFX212]*/
#include "Std_Types.h"
#include "Mcal.h"
/*[/cover]*/
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*
  Published parameters
*/
/* BFX Vendor ID - Vendor ID of the dedicated implementation of this
module according to the AUTOSAR vendor list */
#define BFX_VENDOR_ID     ((uint16)17)
/*BFX Module ID - Module ID of this module from Module List */
#define BFX_MODULE_ID     ((uint16)205)


/* [cover parentID=DS_AS_BFX133] */
/* [cover parentID=DS_AS_BFX001_PI] */
/* BFX AR Major Version - Major version number of AUTOSAR specification on
which the appropriate implementation is based on */
#define BFX_AR_RELEASE_MAJOR_VERSION     (4U)
/* BFX AR Minor Version - Minor version number of AUTOSAR specification on
which the appropriate implementation is based on */
#define BFX_AR_RELEASE_MINOR_VERSION     (0U)
/* BFX AR Patch Version - Patch level version number of AUTOSAR
specification on which the appropriate implementation is based on */
#define BFX_AR_RELEASE_REVISION_VERSION  (3U)

/* BFX SW Major Version - Major version number of the vendor specific
implementation of the module */
#define BFX_SW_MAJOR_VERSION  (3U)
/* BFX SW Minor Version - Minor version number of the vendor specific
implementation of the module */
#define BFX_SW_MINOR_VERSION  (0U)
/* BFX SW Patch Version - Patch level version number of the vendor specific
implementation of the module */
#define BFX_SW_PATCH_VERSION  (0U)
/*Bfx_GetVersionInfo is implemented as a macro function*/
/*[cover parentID=DS_AS_BFX301,DS_AS_BFX302]*/
/*IFX_MISRA_RULE_19_07_STATUS=GetVersionInfo is declared as function like macro
 as per AUTOSAR.*/
/*IFX_MISRA_RULE_19_04_STATUS=GetVersionInfo cannot be expand to a braced 
 initialiser*/ 
#define Bfx_GetVersionInfo(VersionInfoPtr)                                   \
{                                                                            \
  ((Std_VersionInfoType*)(VersionInfoPtr))->vendorID = BFX_VENDOR_ID;        \
  ((Std_VersionInfoType*)(VersionInfoPtr))->moduleID = BFX_MODULE_ID;        \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_major_version =               \
                                    (uint8)BFX_SW_MAJOR_VERSION;             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_minor_version =               \
                                    (uint8)BFX_SW_MINOR_VERSION;             \
  ((Std_VersionInfoType*)(VersionInfoPtr))->sw_patch_version =               \
                                    (uint8)BFX_SW_PATCH_VERSION;             \
}/* end of Bfx_GetVersionInfo() */

/*[/cover]*/

#define BFX_MASK_ALL_32BIT (0xFFFFFFFFUL)

#define BFX_MAX_LENGTH_8BIT (8U)

#define BFX_MAX_LENGTH_8BIT_LONG (8UL)

#define BFX_MAX_LENGTH_16BIT (16U)

#define BFX_MAX_LENGTH_32BIT (32U)

#define BFX_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX001,DS_AS_BFX002,DS_AS_BFX008]**
**                                                                            **
** Syntax            : void Bfx_SetBit_u8u8(                                  **
**                      uint8* const Data,                                    **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x01                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn - Bit position                                   **
**                                                                            **
** Parameters(in-out): Data  - Pointer to input data                          **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the logical status of input    **
**                     data as '1' at the requested bit position.             **
**                                                                            **
*******************************************************************************/
extern void Bfx_SetBit_u8u8(uint8* const Data, uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX001,DS_AS_BFX002,DS_AS_BFX008]**
**                                                                            **
** Syntax            : void Bfx_SetBit_u16u8(                                 **
**                      uint16* const Data,                                   **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x02                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn - Bit position                                   **
**                                                                            **
** Parameters(in-out): Data  - Pointer to input data                          **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the logical status of input    **
**                    data as '1' at the requested bit position.              **
**                                                                            **
*******************************************************************************/
extern void Bfx_SetBit_u16u8(uint16* const Data, uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX001,DS_AS_BFX002,DS_AS_BFX008]**
**                                                                            **
** Syntax            : void Bfx_SetBit_u32u8(                                 **
**                      uint32* const Data,                                   **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x03                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn - Bit position                                   **
**                                                                            **
** Parameters(in-out): Data  - Pointer to input data                          **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the logical status of input    **
**                    data as '1' at the requested bit position.              **
**                                                                            **
*******************************************************************************/
extern void Bfx_SetBit_u32u8(uint32* const Data, uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX010,DS_AS_BFX011,DS_AS_BFX015]**
**                                                                            **
** Syntax            : void Bfx_ClrBit_u8u8(                                  **
**                      uint8* const Data,                                    **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x06                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn - Bit position                                   **
**                                                                            **
** Parameters(in-out): Data  - Pointer to input data                          **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall clear the logical status of the    **
**                    input data to '0' at the requested bit position.        **
**                                                                            **
*******************************************************************************/
extern void Bfx_ClrBit_u8u8(uint8* const Data, uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX010,DS_AS_BFX011,DS_AS_BFX015]**
**                                                                            **
** Syntax            : void Bfx_ClrBit_u16u8(                                 **
**                      uint16* const Data,                                   **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x07                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn - Bit position                                   **
**                                                                            **
** Parameters(in-out): Data  - Pointer to input data                          **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall clear the logical status of the    **
**                     input data to '0' at the requested bit position.       **
**                                                                            **
*******************************************************************************/
extern void Bfx_ClrBit_u16u8(uint16* const Data, uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX010,DS_AS_BFX011,DS_AS_BFX015]**
**                                                                            **
** Syntax            : void Bfx_ClrBit_u32u8(                                 **
**                      uint32* const Data,                                   **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x08                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn - Bit position                                   **
**                                                                            **
** Parameters(in-out): Data  - Pointer to input data                          **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall clear the logical status of the    **
**                     input data to '0' at the requested bit position.       **
**                                                                            **
*******************************************************************************/
extern void Bfx_ClrBit_u32u8(uint32* const Data, uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX016,DS_AS_BFX017,DS_AS_BFX020]**
**                                                                            **
** Syntax            : boolean Bfx_GetBit_u8u8_u8(                            **
**                      uint8 Data,                                           **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x0a                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Data  - Input Data                                     **
**                     BitPn - Bit position                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function shall return the logical status of the   **
**                     input data for the requested bit position.             **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_GetBit_u8u8_u8(uint8 Data,uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX016,DS_AS_BFX017,DS_AS_BFX020]**
**                                                                            **
** Syntax            : boolean Bfx_GetBit_u16u8_u8(                           **
**                      uint16 Data,                                          **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x0b                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Data  - Input Data                                     **
**                    BitPn - Bit position                                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function shall return the logical status of the   **
**                     input data for the requested bit position.             **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_GetBit_u16u8_u8(uint16 Data,uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX016,DS_AS_BFX017,DS_AS_BFX020]**
**                                                                            **
** Syntax            : boolean Bfx_GetBit_u32u8_u8(                           **
**                      uint32 Data,                                          **
**                      uint8 BitPn                                           **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x0c                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Data  - Input Data                                     **
**                     BitPn - Bit position                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function shall return the logical status of the   **
**                     input data for the requested bit position.             **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_GetBit_u32u8_u8(uint32 Data,uint8 BitPn);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX021,DS_AS_BFX022,DS_AS_BFX025]**
**                                                                            **
** Syntax            : void Bfx_SetBits_u8u8u8u8(                             **
**                       uint8* const Data,                                   **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn,                                         **
**                       uint8 Status                                         **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x020                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Status      - Status value                             **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the input data as '1' or '0' as**
**                     per 'Status' value starting from 'BitStartPn' for the  **
**                     length 'BitLn'.                                        **
**                                                                            **
*******************************************************************************/
extern void Bfx_SetBits_u8u8u8u8(
  uint8* const Data,
  uint8 BitStartPn,
  uint8 BitLn,
  uint8 Status
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX021,DS_AS_BFX022,DS_AS_BFX025]**
**                                                                            **
** Syntax            : void Bfx_SetBits_u16u8u8u8(                            **
**                       uint16* const Data,                                  **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn,                                         **
**                       uint8 Status                                         **
**                     )                                                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x021                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Status      - Status value                             **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the input data as '1' or '0' as**
**                     per 'Status' value starting from 'BitStartPn' for the  **
**                     length 'BitLn'.                                        **
**                                                                            **
*******************************************************************************/
extern void Bfx_SetBits_u16u8u8u8(
  uint16* const Data,
  uint8 BitStartPn,
  uint8 BitLn,
  uint8 Status
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX021,DS_AS_BFX022,DS_AS_BFX025]**
**                                                                            **
** Syntax            : void Bfx_SetBits_u32u8u8u8(                            **
**                       uint32* const Data,                                  **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn,                                         **
**                       uint8 Status                                         **
**                      )                                                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x022                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Status      - Status value                             **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the input data as '1' or '0' as**
**                     per 'Status' value starting from 'BitStartPn' for the  **
**                     length 'BitLn'.                                        **
**                                                                            **
*******************************************************************************/
extern void Bfx_SetBits_u32u8u8u8(
  uint32* const Data,
  uint8 BitStartPn,
  uint8 BitLn,
  uint8 Status
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX28,DS_AS_BFX029,DS_AS_BFX034] **
**                                                                            **
** Syntax            :  uint8 Bfx_GetBits_u8u8u8_u8(                          **
**                          uint8 Data,                                       **
**                          uint8 BitStartPn,                                 **
**                          uint8 BitLn                                       **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x026                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : uint8                                                  **
**                                                                            **
** Description       : This function shall return the Bits of the input data  **
**                     starting from  'BitStartPn' for the length of 'BitLn'. **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern uint8 Bfx_GetBits_u8u8u8_u8(
  uint8 Data,
  uint8 BitStartPn,
  uint8 BitLn
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX28,DS_AS_BFX029,DS_AS_BFX034] **
**                                                                            **
** Syntax            :  uint16 Bfx_GetBits_u16u8u8_u16(                       **
**                          uint16 Data,                                      **
**                          uint8 BitStartPn,                                 **
**                          uint8 BitLn                                       **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x027                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : uint16                                                 **
**                                                                            **
** Description       : This function shall return the Bits of the input data  **
**                     starting from  'BitStartPn' for the length of 'BitLn'. **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern uint16 Bfx_GetBits_u16u8u8_u16(
  uint16 Data,
  uint8 BitStartPn,
  uint8 BitLn
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX28,DS_AS_BFX029,DS_AS_BFX034] **
**                                                                            **
** Syntax            :  uint32 Bfx_GetBits_u32u8u8_u32(                       **
**                          uint32 Data,                                      **
**                          uint8 BitStartPn,                                 **
**                          uint8 BitLn                                       **
**                       )                                                    **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x028                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function shall return the Bits of the input data  **
**                     starting from  'BitStartPn' for the length of 'BitLn'. **
**                                                                            **
**                                                                            **
*******************************************************************************/
extern uint32 Bfx_GetBits_u32u8u8_u32(
  uint32 Data,
  uint8 BitStartPn,
  uint8 BitLn
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX046,DS_AS_BFX047,DS_AS_BFX050]**
**                                                                            **
** Syntax            : boolean Bfx_TstBitMask_u8u8_u8(                        **
**                       uint8 Data,                                          **
**                       uint8 Mask                                           **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x036                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function makes a test on the input variable and if**
**                     all the bits are set as per the mask value, function   **
**                     shall return 1 or else 0.                              **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstBitMask_u8u8_u8(uint8 Data, uint8 Mask);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX046,DS_AS_BFX047,DS_AS_BFX050]**
**                                                                            **
** Syntax            : boolean Bfx_TstBitMask_u16u16_u8(                      **
**                       uint16 Data,                                         **
**                       uint16 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x037                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function makes a test on the input variable and if**
**                     all the bits are set as per the mask value, function   **
**                     shall return 1 or else 0.                              **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstBitMask_u16u16_u8(uint16 Data,uint16 Mask);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX046,DS_AS_BFX047,DS_AS_BFX050]**
**                                                                            **
** Syntax            : boolean Bfx_TstBitMask_u32u32_u8(                      **
**                       uint32 Data,                                         **
**                       uint32 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x038                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function makes a test on the input variable and if**
**                     all the bits are set as per the mask value, function   **
**                     shall return 1 or else 0.                              **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstBitMask_u32u32_u8(uint32 Data,uint32 Mask);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX051,DS_AS_BFX052,DS_AS_BFX055]**
**                                                                            **
** Syntax            : boolean Bfx_TstBitLnMask_u8u8_u8(                      **
**                       uint8 Data,                                          **
**                       uint8 Mask                                           **
**                      )                                                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x03a                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function makes a test on the input data and if at **
**                     least one bit is set as per the mask, then the function**
**                     shall return '1' or else '0'.                          **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstBitLnMask_u8u8_u8(uint8 Data, uint8 Mask);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX051,DS_AS_BFX052,DS_AS_BFX055]**
**                                                                            **
** Syntax            : boolean Bfx_TstBitLnMask_u16u16_u8(                    **
**                       uint16 Data,                                         **
**                       uint16 Mask                                          **
**                      )                                                     **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x03b                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function makes a test on the input data and if at **
**                     least one bit is set as per the mask, then the function**
**                     shall return '1' or else '0'.                          **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstBitLnMask_u16u16_u8(uint16 Data,uint16 Mask);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX051,DS_AS_BFX052,DS_AS_BFX055]**
**                                                                            **
** Syntax            : boolean Bfx_TstBitLnMask_u32u32_u8(                    **
**                       uint32 Data,                                         **
**                       uint32 Mask                                          **
**                     )                                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x03c                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                     Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function makes a test on the input data and if at **
**                     least one bit is set as per the mask, then the function**
**                     shall return '1' or else '0'.                          **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstBitLnMask_u32u32_u8(uint32 Data,uint32 Mask);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX056,DS_AS_BFX057,DS_AS_BFX060]**
**                                                                            **
** Syntax            : boolean Bfx_TstParityEven_u8_u8(                       **
**                          uint8 Data                                        **
**                     )                                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x40                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function tests the number of bits set to 1. If    **
**                     this number is even, it shall return 1, otherwise it   **
**                     returns 0.                                             **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstParityEven_u8_u8(uint8 Data);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX056,DS_AS_BFX057,DS_AS_BFX060]**
**                                                                            **
** Syntax            : boolean Bfx_TstParityEven_u16_u8(                      **
**                          uint16 Data                                       **
**                     )                                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x41                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function tests the number of bits set to 1. If    **
**                     this number is even, it shall return 1, otherwise it   **
**                     returns 0.                                             **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstParityEven_u16_u8(uint16 Data);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX056,DS_AS_BFX057,DS_AS_BFX060]**
**                                                                            **
** Syntax            : boolean Bfx_TstParityEven_u32_u8(                      **
**                          uint32 Data                                       **
**                     )                                                      **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x42                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Data        - Input data                               **
**                                                                            **
** Parameters(in-out): none                                                   **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : boolean                                                **
**                                                                            **
** Description       : This function tests the number of bits set to 1. If    **
**                     this number is even, it shall return 1, otherwise it   **
**                     returns 0.                                             **
**                                                                            **
*******************************************************************************/
extern boolean Bfx_TstParityEven_u32_u8(uint32 Data);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX101,DS_AS_BFX102,DS_AS_BFX108]**
**                                                                            **
** Syntax            : void Bfx_CopyBit_u8u8u8u8(                             **
**                       uint8* const DestinationData,                        **
**                       uint8 DestinationPosition,                           **
**                       uint8 SourceData,                                    **
**                       uint8 SourcePosition                                 **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x066                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : DestinationPosition  - Destination position            **
**                     SourceData           - Source data                     **
**                     SourcePosition       - Source position                 **
**                                                                            **
** Parameters(in-out): DestinationData      - Pointer to destination data     **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall copy a bit from source data from   **
**                     bit position to destination data at bit position.      **
**                                                                            **
*******************************************************************************/
extern void Bfx_CopyBit_u8u8u8u8(
  uint8* const DestinationData,
  uint8 DestinationPosition,
  uint8 SourceData,
  uint8 SourcePosition
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX101,DS_AS_BFX102,DS_AS_BFX108]**
**                                                                            **
** Syntax            : void Bfx_CopyBit_u16u8u16u8(                           **
**                       uint16* const DestinationData,                       **
**                       uint8 DestinationPosition,                           **
**                       uint16 SourceData,                                   **
**                       uint8 SourcePosition                                 **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x067                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : DestinationPosition  - Destination position            **
**                     SourceData           - Source data                     **
**                     SourcePosition       - Source position                 **
**                                                                            **
** Parameters(in-out): DestinationData      - Pointer to destination data     **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall copy a bit from source data from   **
**                     bit position to destination data at bit position.      **
**                                                                            **
*******************************************************************************/
extern void Bfx_CopyBit_u16u8u16u8(
  uint16* const DestinationData,
  uint8 DestinationPosition,
  uint16 SourceData,
  uint8 SourcePosition
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX101,DS_AS_BFX102,DS_AS_BFX108]**
**                                                                            **
** Syntax            : void Bfx_CopyBit_u32u8u32u8(                           **
**                       uint32* const DestinationData,                       **
**                       uint8 DestinationPosition,                           **
**                       uint32 SourceData,                                   **
**                       uint8 SourcePosition                                 **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x068                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : DestinationPosition  - Destination position            **
**                     SourceData           - Source data                     **
**                     SourcePosition       - Source position                 **
**                                                                            **
** Parameters(in-out): DestinationData      - Pointer to destination data     **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall copy a bit from source data from   **
**                     bit position to destination data at bit position.      **
**                                                                            **
*******************************************************************************/
extern void Bfx_CopyBit_u32u8u32u8(
  uint32* const DestinationData,
  uint8 DestinationPosition,
  uint32 SourceData,
  uint8 SourcePosition
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX110,DS_AS_BFX111,DS_AS_BFX112]**
**                                                                            **
** Syntax            : void Bfx_PutBits_u8u8u8u8(                             **
**                       uint8* const Data,                                   **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn,                                         **
**                       uint8 Pattern                                        **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x070                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Pattern     - Pattern to be set                        **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall put bits as mentioned in Pattern to**
**                     the input Data from the specified bit position.        **
**                                                                            **
*******************************************************************************/
extern void Bfx_PutBits_u8u8u8u8(
  uint8* const Data,
  uint8 BitStartPn,
  uint8 BitLn,
  uint8 Pattern
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX110,DS_AS_BFX111,DS_AS_BFX112]**
**                                                                            **
** Syntax            : void Bfx_PutBits_u16u8u8u16(                           **
**                       uint16* const Data,                                  **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn,                                         **
**                       uint16 Pattern                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x071                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Pattern     - Pattern to be set                        **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall put bits as mentioned in Pattern to**
**                     the input Data from the specified bit position.        **
**                                                                            **
*******************************************************************************/
extern void Bfx_PutBits_u16u8u8u16(
  uint16* const Data,
  uint8 BitStartPn,
  uint8 BitLn,
  uint16 Pattern
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX110,DS_AS_BFX111,DS_AS_BFX112]**
**                                                                            **
** Syntax            : void Bfx_PutBits_u32u8u8u32(                           **
**                       uint32* const Data,                                  **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn,                                         **
**                       uint32 Pattern                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x072                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitStartPn  - Start bit position                       **
**                     BitLn       - Bit field length                         **
**                     Pattern     - Pattern to be set                        **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall put bits as mentioned in Pattern to**
**                     the input Data from the specified bit position.        **
**                                                                            **
*******************************************************************************/
extern void Bfx_PutBits_u32u8u8u32(
  uint32* const Data,
  uint8 BitStartPn,
  uint8 BitLn,
  uint32 Pattern
  );

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX130,DS_AS_BFX131,DS_AS_BFX132]**
**                                                                            **
** Syntax            : void Bfx_PutBit_u8u8u8(                                **
**                       uint8* const Data,                                   **
**                       uint8 BitPn,                                         **
**                       uint8 Status                                         **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x085                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn       - Bit position                             **
**                     Status      - Status value                             **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall update the bit specified by BitPn  **
**                     of input data as '1' or '0' as per 'Status' value.     **
**                                                                            **
*******************************************************************************/
extern void Bfx_PutBit_u8u8u8(uint8* const Data, uint8 BitPn, uint8 Status);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX130,DS_AS_BFX131,DS_AS_BFX132]**
**                                                                            **
** Syntax            : void Bfx_PutBit_u16u8u8(                               **
**                       uint16* const Data,                                  **
**                       uint8 BitPn,                                         **
**                       uint8 Status                                         **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x086                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn       - Bit position                             **
**                     Status      - Status value                             **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall update the bit specified by BitPn  **
**                     of input data as '1' or '0' as per 'Status' value.     **
**                                                                            **
*******************************************************************************/
extern void Bfx_PutBit_u16u8u8(uint16* const Data, uint8 BitPn, uint8 Status);

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX130,DS_AS_BFX131,DS_AS_BFX132]**
**                                                                            **
** Syntax            : void Bfx_PutBit_u32u8u8(                               **
**                       uint32* const Data,                                  **
**                       uint8 BitPn,                                         **
**                       uint8 Status                                         **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x087                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : BitPn       - Bit position                             **
**                     Status      - Status value                             **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall update the bit specified by BitPn  **
**                     of input data as '1' or '0' as per 'Status' value.     **
**                                                                            **
*******************************************************************************/
extern void Bfx_PutBit_u32u8u8(uint32* const Data, uint8 BitPn, uint8 Status);
/*[/cover]*/
/*******************************************************************************
**                    Global IFX_INLINE Function Definitions                  **
*******************************************************************************/
/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX035,DS_AS_BFX036,DS_AS_BFX038]**
**                                                                            **
** Syntax            : void Bfx_SetBitMask_u8u8(                              **
**                       uint8* const Data,                                   **
**                       uint8 Mask                                           **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x02a                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask used to set bits                    **
**                                                                            **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the data to logical status '1' **
**                     as per the corresponding Mask bits when set to value 1 **
**                     and remaining bits will retain their original values.  **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_SetBitMask_u8u8(uint8* const Data, uint8 Mask)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data |= Mask;/*Data is equal to Bitwise OR of Data and Mask.*/
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX035,DS_AS_BFX036,DS_AS_BFX038]**
**                                                                            **
** Syntax            : void Bfx_SetBitMask_u16u16(                            **
**                       uint16* const Data,                                  **
**                       uint16 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x02b                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask used to set bits                    **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the data to logical status '1' **
**                     as per the corresponding Mask bits when set to value 1 **
**                     and remaining bits will retain their original values.  **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_SetBitMask_u16u16(
uint16* const Data,
uint16 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data |= Mask;/*Data is equal to Bitwise OR of Data and Mask.*/
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX035,DS_AS_BFX036,DS_AS_BFX038]**
**                                                                            **
** Syntax            : void Bfx_SetBitMask_u32u32(                            **
**                       uint32* const Data,                                  **
**                       uint32 Mask                                          **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x02c                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask used to set bits                    **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall set the data to logical status '1' **
**                     as per the corresponding Mask bits when set to value 1 **
**                     and remaining bits will retain their original values.  **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_SetBitMask_u32u32(
uint32* const Data,
uint32 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data |= Mask;/*Data is equal to Bitwise OR of Data and Mask.*/
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX039,DS_AS_BFX040,DS_AS_BFX045]**
**                                                                            **
** Syntax            : void Bfx_ClrBitMask_u8u8(                              **
**                       uint8* const Data,                                   **
**                       uint8 Mask                                           **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x030                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall clear the logical status to '0' for**
**                     the input data for all the bit positions as per the    **
**                     mask. This function shall clear the data to logical    **
**                     status '0' as per the corresponding mask bits value    **
**                     when set to 1. The remaining bits shall retain their   **
**                     original values.                                       **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ClrBitMask_u8u8(uint8* const Data, uint8 Mask)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{/*Data is equal to Bitwise AND of Data and Bitwise complement of Mask.*/
  *Data &= (~Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX039,DS_AS_BFX040,DS_AS_BFX045]**
**                                                                            **
** Syntax            : void Bfx_ClrBitMask_u16u16(                            **
**                       uint16* const Data,                                  **
**                       uint16 Mask                                          **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x031                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall clear the logical status to '0' for**
**                     the input data for all the bit positions as per the    **
**                     mask. This function shall clear the data to logical    **
**                     status '0' as per the corresponding mask bits value    **
**                     when set to 1. The remaining bits shall retain their   **
**                     original values.                                       **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ClrBitMask_u16u16(
uint16* const Data, 
uint16 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{/*Data is equal to Bitwise AND of Data and Bitwise complement of Mask.*/
  *Data &= (~Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX039,DS_AS_BFX040,DS_AS_BFX045]**
**                                                                            **
** Syntax            : void Bfx_ClrBitMask_u32u32(                            **
**                       uint32* const Data,                                  **
**                       uint32 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x032                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall clear the logical status to '0' for**
**                     the input data for all the bit positions as per the    **
**                     mask. This function shall clear the data to logical    **
**                     status '0' as per the corresponding mask bits value    **
**                     when set to 1. The remaining bits shall retain their   **
**                     original values.                                       **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ClrBitMask_u32u32(
uint32* const Data,
uint32 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{/*Data is equal to Bitwise AND of Data and Bitwise complement of Mask.*/
  *Data &= (~Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX061,DS_AS_BFX062,DS_AS_BFX065]**
**                                                                            **
** Syntax            : void Bfx_ToggleBits_u8(                                **
**                       uint8* const Data                                    **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x46                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : None                                                   **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function toggles all the bits of data             **
**                     (1's Complement Data).                                 **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ToggleBits_u8(uint8* const Data)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = ~(*Data);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX061,DS_AS_BFX062,DS_AS_BFX065]**
**                                                                            **
** Syntax            : void Bfx_ToggleBits_u16(                               **
**                       uint16* const Data                                   **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x47                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : None                                                   **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function toggles all the bits of data             **
**                     (1's Complement Data).                                 **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ToggleBits_u16(uint16* const Data)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = ~(*Data);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX061,DS_AS_BFX062,DS_AS_BFX065]**
**                                                                            **
** Syntax            : void Bfx_ToggleBits_u32(                               **
**                       uint32* const Data                                   **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x48                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : None                                                   **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function toggles all the bits of data             **
**                     (1's Complement Data).                                 **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ToggleBits_u32(uint32* const Data)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = ~(*Data);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX066,DS_AS_BFX067,DS_AS_BFX069]**
**                                                                            **
** Syntax            : void Bfx_ToggleBitMask_u8u8(                           **
**                       uint8* const Data,                                   **
**                       uint8 Mask                                           **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x04a                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function toggles the bits of data when the        **
**                     corresponding bit of the mask is enabled and set to 1. **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ToggleBitMask_u8u8(
uint8* const Data, 
uint8 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = (*Data) ^ (Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX066,DS_AS_BFX067,DS_AS_BFX069]**
**                                                                            **
** Syntax            : void Bfx_ToggleBitMask_u16u16(                         **
**                       uint16* const Data,                                  **
**                       uint16 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x04b                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function toggles the bits of data when the        **
**                     corresponding bit of the mask is enabled and set to 1. **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ToggleBitMask_u16u16(
uint16* const Data, 
uint16 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = (*Data) ^ (Mask);
}


/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX066,DS_AS_BFX067,DS_AS_BFX069]**
**                                                                            **
** Syntax            : void Bfx_ToggleBitMask_u32u32(                         **
**                       uint32* const Data,                                  **
**                       uint32 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x04c                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function toggles the bits of data when the        **
**                     corresponding bit of the mask is enabled and set to 1. **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ToggleBitMask_u32u32(
uint32* const Data, 
uint32 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = (*Data) ^ (Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX070,DS_AS_BFX071,DS_AS_BFX075]**
**                                                                            **
** Syntax            : void Bfx_ShiftBitRt_u8u8(                              **
**                       uint8* const Data,                                   **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x050                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift right count                        **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall shift data to the right by         **
**                     ShiftCnt. The most significant bit (left-most bit) is  **
**                     replaced by a '0' bit and the least significant bit    **
**                     (right-most bit) is dis-carded for every single bit    **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ShiftBitRt_u8u8(
uint8* const Data, 
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = *Data >> ShiftCnt;
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX070,DS_AS_BFX071,DS_AS_BFX075]**
**                                                                            **
** Syntax            : void Bfx_ShiftBitRt_u16u8(                             **
**                       uint16* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x051                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift right count                        **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall shift data to the right by         **
**                     ShiftCnt. The most significant bit (left-most bit) is  **
**                     replaced by a '0' bit and the least significant bit    **
**                     (right-most bit) is dis-carded for every single bit    **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ShiftBitRt_u16u8(
uint16* const Data, 
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = *Data >> ShiftCnt;
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX070,DS_AS_BFX071,DS_AS_BFX075]**
**                                                                            **
** Syntax            : void Bfx_ShiftBitRt_u32u8(                             **
**                       uint32* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x052                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift right count                        **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall shift data to the right by         **
**                     ShiftCnt. The most significant bit (left-most bit) is  **
**                     replaced by a '0' bit and the least significant bit    **
**                     (right-most bit) is dis-carded for every single bit    **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ShiftBitRt_u32u8(
uint32* const Data, 
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = *Data >> ShiftCnt;
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX076,DS_AS_BFX077,DS_AS_BFX080]**
**                                                                            **
** Syntax            : void Bfx_ShiftBitLt_u8u8(                              **
**                       uint8* const Data,                                   **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x056                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift left count                         **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall shift data to the left by ShiftCnt.**
**                     The least significant bit (right-most bit) is replaced **
**                     by a '0' bit and the most significant bit              **
**                     (left-most bit) is dis-carded for every single bit     **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ShiftBitLt_u8u8(
uint8* const Data, 
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = (uint8)(((uint32)(*Data)) << ShiftCnt);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX076,DS_AS_BFX077,DS_AS_BFX080]**
**                                                                            **
** Syntax            : void Bfx_ShiftBitLt_u16u8(                             **
**                       uint16* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x057                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift left count                         **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall shift data to the left by ShiftCnt.**
**                     The least significant bit (right-most bit) is replaced **
**                     by a '0' bit and the most significant bit              **
**                     (left-most bit) is dis-carded for every single bit     **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ShiftBitLt_u16u8(
uint16* const Data, 
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = (uint16)(((uint32)*Data) << ShiftCnt);
}


/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX076,DS_AS_BFX077,DS_AS_BFX080]**
**                                                                            **
** Syntax            : void Bfx_ShiftBitLt_u32u8(                             **
**                       uint32* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x058                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift left count                         **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall shift data to the left by ShiftCnt.**
**                     The least significant bit (right-most bit) is replaced **
**                     by a '0' bit and the most significant bit              **
**                     (left-most bit) is dis-carded for every single bit     **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_ShiftBitLt_u32u8(
uint32* const Data, 
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
  *Data = *Data << ShiftCnt;
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX086,DS_AS_BFX087,DS_AS_BFX090]**
**                                                                            **
** Syntax            : void Bfx_RotBitRt_u8u8(                                **
**                       uint8* const Data,                                   **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x05a                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift count                              **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall rotate data to the right by        **
**                     ShiftCnt. The least significant bit is rotated to the  **
**                     most significant bit location for every single bit     **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_RotBitRt_u8u8(uint8* const Data, uint8 ShiftCnt)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to addition of
    1)  Data Right Shifted by ShiftCnt number of times and
    2)  Data Left Shifted by ((Max Length or (Max Position +1))-ShiftCnt)
      number of times.
*/
  *Data = (uint8)(*Data >> ShiftCnt) +
          (uint8)((((uint32)(*Data)) <<
          ((uint8)(BFX_MAX_LENGTH_8BIT_LONG - ShiftCnt))));
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX086,DS_AS_BFX087,DS_AS_BFX090]**
**                                                                            **
** Syntax            : void Bfx_RotBitRt_u16u8(                               **
**                       uint16* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x05b                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift count                              **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall rotate data to the right by        **
**                     ShiftCnt. The least significant bit is rotated to the  **
**                     most significant bit location for every single bit     **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_RotBitRt_u16u8(
uint16* const Data,
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to addition of
    1)  Data Right Shifted by ShiftCnt number of times and
    2)  Data Left Shifted by ((Max Length or (Max Position +1))-ShiftCnt)
      number of times.
*/
  *Data = (uint16)(*Data >> ShiftCnt) +
          (uint16)(((uint32)*Data) << (uint8)(BFX_MAX_LENGTH_16BIT - ShiftCnt));
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX086,DS_AS_BFX087,DS_AS_BFX090]**
**                                                                            **
** Syntax            : void Bfx_RotBitRt_u32u8(                               **
**                       uint32* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x05c                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift count                              **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall rotate data to the right by        **
**                     ShiftCnt. The least significant bit is rotated to the  **
**                     most significant bit location for every single bit     **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_RotBitRt_u32u8(
uint32* const Data,
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to addition of
    1)  Data Right Shifted by ShiftCnt number of times and
    2)  Data Left Shifted by ((Max Length or (Max Position +1))-ShiftCnt)
      number of times.
*/
  *Data = (*Data >> ShiftCnt) +
          (*Data << (uint8)(BFX_MAX_LENGTH_32BIT - ShiftCnt));
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX095,DS_AS_BFX096,DS_AS_BFX098]**
**                                                                            **
** Syntax            : void Bfx_RotBitLt_u8u8(                                **
**                       uint8* const Data,                                   **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x060                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift count                              **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall rotate data to the left by         **
**                     ShiftCnt. The most significant bit is rotated to the   **
**                     least significant bit location for every single bit    **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_RotBitLt_u8u8(uint8* const Data,uint8 ShiftCnt)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to addition of
    1)Data Left Shifted by ShiftCnt number of times and
    2)Data Right Shifted by (Max Length or (MaxPos+1))-ShiftCnt number of times.
*/
  *Data = (uint8)(((uint32)*Data) << ShiftCnt) +
          (uint8)(*Data >> (uint8)(BFX_MAX_LENGTH_8BIT - ShiftCnt));
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX095,DS_AS_BFX096,DS_AS_BFX098]**
**                                                                            **
** Syntax            : void Bfx_RotBitLt_u16u8(                               **
**                       uint16* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x061                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift count                              **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall rotate data to the left by         **
**                     ShiftCnt. The most significant bit is rotated to the   **
**                     least significant bit location for every single bit    **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_RotBitLt_u16u8(
uint16* const Data,
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to addition of
    1)  Data Left Shifted by ShiftCnt number of times and
    2)  Data Right Shifted by (Max Length or (MaxPos+1))-ShiftCnt number of
        times.
*/
  *Data = (uint16)(((uint32)*Data) << ShiftCnt) +
          (uint16)(*Data >> (uint8)(BFX_MAX_LENGTH_16BIT - ShiftCnt));
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX095,DS_AS_BFX096,DS_AS_BFX098]**
**                                                                            **
** Syntax            : void Bfx_RotBitLt_u32u8(                               **
**                       uint32* const Data,                                  **
**                       uint8 ShiftCnt                                       **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x062                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : ShiftCnt    - Shift count                              **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall rotate data to the left by         **
**                     ShiftCnt. The most significant bit is rotated to the   **
**                     least significant bit location for every single bit    **
**                     shift cycle.                                           **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_RotBitLt_u32u8(
uint32* const Data,
uint8 ShiftCnt
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to addition of
    1)  Data Left Shifted by ShiftCnt number of times and
    2)  Data Right Shifted by (Max Length or (MaxPos+1))-ShiftCnt number of
        times.
*/
  *Data = (*Data << ShiftCnt) +
          (*Data >> (BFX_MAX_LENGTH_32BIT - ShiftCnt));
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX120,DS_AS_BFX122,DS_AS_BFX124]**
**                                                                            **
** Syntax            : void Bfx_PutBitsMask_u8u8u8(                           **
**                       uint8* const Data,                                   **
**                       uint8 Pattern,                                       **
**                       uint8 Mask                                           **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x080                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Pattern     - Pattern to be set                        **
**                     Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall put bits as mentioned in Pattern to**
**                     the input Data when corresponding Mask bits enabled    **
**                     and set to 1.                                          **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_PutBitsMask_u8u8u8(
uint8* const Data,
uint8 Pattern,
uint8 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to Bitwise OR of
    1)  Bitwise AND of Data and complement of Mask and
    2)  Bitwise AND of Pattern and Mask.
*/
  *Data = (*Data & (uint8)(~Mask)) | (uint8)(Pattern & Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX120,DS_AS_BFX122,DS_AS_BFX124]**
**                                                                            **
** Syntax            : void Bfx_PutBitsMask_u16u16u16(                        **
**                       uint16* const Data,                                  **
**                       uint16 Pattern,                                      **
**                       uint16 Mask                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x081                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Pattern     - Pattern to be set                        **
**                     Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall put bits as mentioned in Pattern to**
**                     the input Data when corresponding Mask bits enabled    **
**                     and set to 1.                                          **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_PutBitsMask_u16u16u16(
uint16* const Data,
uint16 Pattern,
uint16 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to Bitwise OR of
    1)  Bitwise AND of Data and complement of Mask and
    2)  Bitwise AND of Pattern and Mask.
*/
  *Data = (*Data & (uint16)(~Mask)) | (uint16)(Pattern & Mask);
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX120,DS_AS_BFX122,DS_AS_BFX124]**
**                                                                            **
** Syntax            : void Bfx_PutBitsMask_u32u32u32(                        **
**                       uint32* const Data,                                  **
**                       uint32 Pattern,                                      **
**                       uint32 Mask                                          **
**                      )                                                     **
**                                                                            **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID        : 0x082                                                  **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Reentrant                                              **
**                                                                            **
** Parameters (in)   : Pattern     - Pattern to be set                        **
**                     Mask        - Mask value                               **
**                                                                            **
** Parameters(in-out): Data        - Pointer to input data                    **
**                                                                            **
** Parameters (out)  : none                                                   **
**                                                                            **
** Return value      : none                                                   **
**                                                                            **
** Description       : This function shall put bits as mentioned in Pattern to**
**                     the input Data when corresponding Mask bits enabled    **
**                     and set to 1.                                          **
**                                                                            **
*******************************************************************************/
_IFXEXTERN_ IFX_INLINE void Bfx_PutBitsMask_u32u32u32(
uint32* const Data,
uint32 Pattern,
uint32 Mask
)
/*IFX_MISRA_RULE_08_05_STATUS=Inline function definition is allowed
 in header file*/
{
/*  Data is equal to Bitwise OR of
    1)  Bitwise AND of Data and complement of Mask and
    2)  Bitwise AND of Pattern and Mask.
*/
  *Data = (*Data & (~Mask)) | (Pattern & Mask);
}

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Definitions                    **
*******************************************************************************/
#define BFX_STOP_SEC_CODE
#include "MemMap.h"

#endif /* BFX_H */

