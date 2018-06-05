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
**  $FILENAME  : Bfx.c                                                        **
**                                                                            **
**  $CC VERSION : \main\31 $                                                 **
**                                                                            **
**  $DATE      : 2013-06-26 $                                                 **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Bfx Library                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
/*  TRACEABILITY :  [cover parentID=SAS_AS_BFX222,SAS_NAS_ALL_PR749           **
**                                       SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652, **
**                                       SAS_NAS_ALL_PR630_PR631,             **
**                                       DS_NAS_BFX_PR115]                    **
**                                      [/cover]                              **
**                                                                            */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Own header file */
#include "Bfx.h"

/*******************************************************************************
**                      Imported Compiler Switch Checks                       **
*******************************************************************************/
/**********Traceability : *****************************************************/


/* BFX Header File Version Check */
#ifndef BFX_SW_MAJOR_VERSION
  #error "BFX_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef BFX_SW_MINOR_VERSION
  #error "BFX_SW_MINOR_VERSION is not defined. "
#endif

#ifndef BFX_SW_PATCH_VERSION
  #error "BFX_SW_PATCH_VERSION is not defined. "
#endif

/* AUTOSAR Secification File Version Check */
#ifndef BFX_AR_RELEASE_MAJOR_VERSION
  #error "BFX_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef BFX_AR_RELEASE_MINOR_VERSION
  #error "BFX_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef BFX_AR_RELEASE_REVISION_VERSION
  #error "BFX_AR_RELEASE_REVISION_VERSION is not defined. "
#endif

#if (BFX_AR_RELEASE_MAJOR_VERSION != 4U)
  #error "BFX_AR_RELEASE_MAJOR_VERSION does not match. "
#endif

#if (BFX_AR_RELEASE_MINOR_VERSION != 0U)
  #error "BFX_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#if (BFX_SW_MAJOR_VERSION != 3U)
  #error "BFX_SW_MAJOR_VERSION does not match. "
#endif

#if (BFX_SW_MINOR_VERSION != 0U)
  #error "BFX_SW_MINOR_VERSION does not match. "
#endif
/********************************* [/cover] ***********************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define BFX_DEFAULT_WIDTH              (1U)
#define BFX_EIGHT                      (8U)
#define BFX_SIXTEEN                   (16U)
#define BFX_TWENTYFOUR                (24U)
#define BFX_DEFAULT_STATUS_1  (0xFFFFFFFFU)
#define BFX_DEFAULT_STATUS_0  (0x00000000U)

/******************************************************************************/

/***************************** [/cover] ***************************************/
/***************** [cover parentID=SAS_AS_BFX210] ***************/
#define BFX_START_SEC_CODE
#include "MemMap.h"
/********************************* [/cover] ***********************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
uint32 Bfx_lGetMaskValue(uint8 BitStartPn, uint8 BitLn);

IFX_LOCAL_INLINE uint32 Bfx_lParity(uint32 Data);

IFX_LOCAL_INLINE void Bfx_lInsert8Bits(uint8 * target,
                                       uint8 sourceval,
                                       uint8 pos,
                                       uint8 width);

IFX_LOCAL_INLINE void Bfx_lInsert16Bits(uint16 * target,
                                        uint16 sourceval,
                                        uint8 pos,
                                        uint8 width);

IFX_LOCAL_INLINE void Bfx_lInsert32Bits(uint32 * target,
                                        uint32 sourceval,
                                        uint8 pos,
                                        uint8 width);

IFX_LOCAL_INLINE uint32 Bfx_lExtractBits(uint32 value, uint8 pos, uint8 width);
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
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
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : uint32 Bfx_lGetMaskValue(                              **
**                       uint8 BitStartPn,                                    **
**                       uint8 BitLn                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : BitStartPn - Start bit position                        **
**                     BitLn      - Bit field length                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function returns uint32 number which has          **
**                     continuous series of 1s depending on BitStartPn and    **
**                     BitLn. BitStartPn is starting position where series of **
**                     1s will start and BitLn is Length of the series of 1s  **
**                     or number of Continuous 1s in the series.              **
*******************************************************************************/
uint32 Bfx_lGetMaskValue(uint8 BitStartPn, uint8 BitLn)
{

  uint32 ResultValue;

  if(BitLn == BFX_MAX_LENGTH_32BIT)
  {
    /*Case when bit length (BitLn) will be 32*/
    ResultValue = BFX_MASK_ALL_32BIT;
  }
  else 
  {
    /*Case when BitLn<BFX_MAX_LENGTH_32BIT.*/
    ResultValue = ((1UL << BitLn) - 1UL);
    ResultValue = ResultValue << BitStartPn;
  }

  return ResultValue;

}

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : uint32 Bfx_lParity(                                    **
**                       uint32 Data                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : Data -                                                 **
**                     BitLn      - Bit field length                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function returns a byte parity for a 32bit data   **
*******************************************************************************/
#ifdef _DIABDATA_C_TRICORE_
#if (_DIABDATA_C_TRICORE_ == 1U)
IFX_LOCAL_INLINE uint32 Bfx_lParity(uint32 Data)
{

  uint32 ResultVal;

  /*IFX_MISRA_RULE_08_09_STATUS=intrinsic function _parity seen as undefined*/
  /*IFX_MISRA_RULE_08_01_STATUS=No declaration available for intrinsic
  function __parity*/
  /*IFX_MISRA_RULE_08_01_STATUS=No declaration available for intrinsic
  function __parity*/
  /*IFX_MISRA_RULE_10_01_STATUS=Intrinsic function should not be checked
  for MISRA violations*/
  ResultVal = _parity(Data);
  
  return ResultVal;
}

#endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : uint32 Bfx_lParity(                                    **
**                       uint32 Data                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : Data -                                                 **
**                     BitLn      - Bit field length                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function returns a byte parity for a 32bit data   **
*******************************************************************************/
#elif defined _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1)
IFX_LOCAL_INLINE uint32 Bfx_lParity(uint32 Data)
{

  uint32 ResultVal;
  
  /*IFX_MISRA_RULE_08_09_STATUS=intrinsic function _parity seen as undefined*/
  /*IFX_MISRA_RULE_08_01_STATUS=No declaration available for intrinsic
  function __parity*/
  /*IFX_MISRA_RULE_08_01_STATUS=No declaration available for intrinsic
  function __parity*/
  /*IFX_MISRA_RULE_10_01_STATUS=Intrinsic function should not be checked
  for MISRA violations*/
  ResultVal = (uint32)__parity(Data);

  return ResultVal;
}

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : uint32 Bfx_lParity(                                    **
**                       uint32 Data                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : Data -                                                 **
**                     BitLn      - Bit field length                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function returns a byte parity for a 32bit data   **
*******************************************************************************/
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
IFX_LOCAL_INLINE uint32 Bfx_lParity(uint32 Data)
{

  uint32 ResultVal = 0U;

  /*IFX_MISRA_RULE_08_09_STATUS=intrinsic function _parity seen as undefined*/
  /*IFX_MISRA_RULE_08_01_STATUS=No declaration available for intrinsic
  function __parity*/
  /*IFX_MISRA_RULE_08_01_STATUS=No declaration available for intrinsic
  function __parity*/
  /*IFX_MISRA_RULE_10_01_STATUS=Intrinsic function should not be checked
  for MISRA violations*/
  ResultVal = __builtin_parity (Data);

  return ResultVal;
}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : void Bfx_lInsert8Bits(                                 **
**                       uint8 * target,                                      **
**                       uint8 sourceval,                                     **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : target - Target Data ptr                               **
**                     sourceval - Source Data                                **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : void                                                   **
**                                                                            **
** Description       : This function replaces certain number                  **
**                     of consequetive bits in target from                    **
**                     sourceval based on pos and width                       **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1)
IFX_LOCAL_INLINE void Bfx_lInsert8Bits(uint8 * target,
                                       uint8 sourceval,
                                       uint8 pos,
                                       uint8 width)
{

  __asm("ld.bu d3,[%0]" : : "a"(target) : "d3");
  __asm("mov d4,%0" : : "d"(pos) : "d4");
  __asm("mov d5,%0" : : "d"(width) : "d5");
  __asm("insert d2,d3,%0,e4" : : "d" (sourceval) : "d2");
  __asm("st.b [%0],d2" : :"a"(target));

  /*IFX_MISRA_RULE_16_07_STATUS=Data Pointer used to change data 
  but by assembly code*/
}

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : void Bfx_lInsert8Bits(                                 **
**                       uint8 * target,                                      **
**                       uint8 sourceval,                                     **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : target - Target Data ptr                               **
**                     sourceval - Source Data                                **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : void                                                   **
**                                                                            **
** Description       : This function replaces certain number                  **
**                     of consequetive bits in target from                    **
**                     sourceval based on pos and width                       **
*******************************************************************************/
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
IFX_LOCAL_INLINE void Bfx_lInsert8Bits(uint8 * target,
                                       uint8 sourceval,
                                       uint8 pos,
                                       uint8 width)
{


  __asm__("ld.bu %%d3,[%0]" : : "a"(target) : "d3");
  __asm__("mov %%d4,%0" : : "d"(pos) : "d4");
  __asm__("mov %%d5,%0" : : "d"(width) : "d5");
  __asm__("insert %%d2,%%d3,%0,%%e4" : : "d" (sourceval) : "d2");
  __asm__("st.b [%0],%%d2" : :"a"(target));


  /*IFX_MISRA_RULE_16_07_STATUS=Data Pointer used to change data 
  but by assembly code*/
}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : void Bfx_lInsert16Bits(                                **
**                     uint16 * target,                                       **
**                       uint16 sourceval,                                    **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : target - Target Data ptr                               **
**                     sourceval - Source Data                                **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : void                                                   **
**                                                                            **
** Description       : This function replaces certain number                  **
**                     of consequetive bits in target from                    **
**                     sourceval based on pos and width                       **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1)
IFX_LOCAL_INLINE void Bfx_lInsert16Bits(uint16 * target,
                                        uint16 sourceval,
                                        uint8 pos,
                                        uint8 width)
{

  __asm("ld.hu d3,[%0]" : : "a"(target) : "d3");
  __asm("mov d4,%0" : : "d"(pos) : "d4");
  __asm("mov d5,%0" : : "d"(width) : "d5");
  __asm("insert d2,d3,%0,e4" : : "d" (sourceval) : "d2");
  __asm("st.h [%0],d2" : :"a"(target));

  /*IFX_MISRA_RULE_16_07_STATUS=Data Pointer used to change data 
  but by assembly code*/
}

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : void Bfx_lInsert16Bits(                                **
**                       uint16 * target,                                     **
**                       uint16 sourceval,                                    **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : target - Target Data ptr                               **
**                     sourceval - Source Data                                **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : void                                                   **
**                                                                            **
** Description       : This function replaces certain number                  **
**                     of consequetive bits in target from                    **
**                     sourceval based on pos and width                       **
*******************************************************************************/
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
IFX_LOCAL_INLINE void Bfx_lInsert16Bits(uint16 * target,
                                        uint16 sourceval,
                                        uint8 pos,
                                        uint8 width)
{


  __asm__("ld.hu %%d3,[%0]" : : "a"(target) : "d3");
  __asm__("mov %%d4,%0" : : "d"(pos) : "d4");
  __asm__("mov %%d5,%0" : : "d"(width) : "d5");
  __asm__("insert %%d2,%%d3,%0,%%e4" : : "d" (sourceval) : "d2");
  __asm__("st.h [%0],%%d2" : :"a"(target));


  /*IFX_MISRA_RULE_16_07_STATUS=Data Pointer used to change data 
  but by assembly code*/
}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : void Bfx_lInsert32Bits(                                **
**                       uint32 * target,                                     **
**                       uint32 sourceval,                                    **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : target - Target Data ptr                               **
**                     sourceval - Source Data                                **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : void                                                   **
**                                                                            **
** Description       : This function replaces certain number                  **
**                     of consequetive bits in target from                    **
**                     sourceval based on pos and width                       **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1)
IFX_LOCAL_INLINE void Bfx_lInsert32Bits(uint32 * target,
                                        uint32 sourceval,
                                        uint8 pos,
                                        uint8 width)
{

  __asm("ld.w d3,[%0]" : : "a"(target) : "d3");
  __asm("mov d4,%0" : : "d"(pos) : "d4");
  __asm("mov d5,%0" : : "d"(width) : "d5");
  __asm("insert d2,d3,%0,e4" : : "d" (sourceval) : "d2");
  __asm("st.w [%0],d2" : :"a"(target));

  /*IFX_MISRA_RULE_16_07_STATUS=Data Pointer used to change data 
  but by assembly code*/
}

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : void Bfx_lInsert32Bits(                                **
**                       uint32 * target,                                     **
**                       uint32 sourceval,                                    **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : target - Target Data ptr                               **
**                     sourceval - Source Data                                **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : void                                                   **
**                                                                            **
** Description       : This function replaces certain number                  **
**                     of consequetive bits in target from                    **
**                     sourceval based on pos and width                       **
*******************************************************************************/
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
IFX_LOCAL_INLINE void Bfx_lInsert32Bits(uint32 * target,
                                        uint32 sourceval,
                                        uint8 pos,
                                        uint8 width)
{

  __asm__("ld.w %%d3,[%0]" : : "a"(target) : "d3");
  __asm__("mov %%d4,%0" : : "d"(pos) : "d4");
  __asm__("mov %%d5,%0" : : "d"(width) : "d5");
  __asm__("insert %%d2,%%d3,%0,%%e4" : : "d" (sourceval) : "d2");
  __asm__("st.w [%0],%%d2" : :"a"(target));

  /*IFX_MISRA_RULE_16_07_STATUS=Data Pointer used to change data 
  but by assembly code*/
 }

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : uint32 Bfx_lExtractBits(                               **
**                       uint32 value,                                        **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : value - Data                                           **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function extracts certain number of bits          **
**                     from value based on pos and width                      **
*******************************************************************************/
#ifdef _TASKING_C_TRICORE_
#if (_TASKING_C_TRICORE_ == 1)
IFX_LOCAL_INLINE uint32 Bfx_lExtractBits(uint32 value,uint8 pos,uint8 width)
{

  uint32 res;

  res = __extru((signed_int)(value),(signed_int)(pos),(signed_int)(width));

  return res;
}

#endif /* #if (_TASKING_C_TRICORE_ == 1U) */

/*******************************************************************************
** Traceability      : [cover parentID=]                                      **
**                                                                            **
**                                                                            **
** Syntax            : uint32 Bfx_lExtractBits(                               **
**                       uint32 value,                                        **
**                       uint8 pos,                                           **
**                       uint8 width                                          **
**                     )                                                      **
**                                                                            **
**                                                                            **
**                                                                            **
** Service ID        : None                                                   **
**                                                                            **
** Sync/Async        : Synchronous                                            **
**                                                                            **
** Reentrancy        : Re-entrant                                             **
**                                                                            **
** Parameters (in)   : value - Data                                           **
**                     pos - Position                                         **
**                     width - Width                                          **
**                                                                            **
** Parameters (out)  : None                                                   **
**                                                                            **
** Return value      : uint32                                                 **
**                                                                            **
** Description       : This function extracts certain number of bits          **
**                     from value based on pos and width                      **
*******************************************************************************/
#elif defined _GNU_C_TRICORE_
#if (_GNU_C_TRICORE_ == 1U)
IFX_LOCAL_INLINE uint32 Bfx_lExtractBits(uint32 value, uint8 pos, uint8 width) 
{

  uint32 res;

  __asm__ volatile ("mov %%d14,%2  \n\
               mov %%d15,%3  \n\
               extr.u %0,%1,%%e14"
               : "=d" (res) : "d" (value), "d" (pos), "d" (width):"d14","d15");




  return res;

}

#endif /* #if (_GNU_C_TRICORE_ == 1U) */
#endif
/*******************************************************************************
**                      Global Function Definitions                           **
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
void Bfx_SetBit_u8u8(uint8* const Data, uint8 BitPn)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  *Data |= (uint8)(0x01U << BitPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert8Bits(Data,(uint8)BFX_DEFAULT_STATUS_1,BitPn,BFX_DEFAULT_WIDTH);

  #endif 
}

/*******************************************************************************
** Traceability      : [cover parentID=DS_AS_BFX001,DS_AS_BFX002,DS_AS_BFX008 **
                                                DS_NAS_BFX_PR128]             **
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
void Bfx_SetBit_u16u8(uint16* const Data, uint8 BitPn)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  *Data |= (uint16)(1UL << BitPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert16Bits(Data,(uint16)BFX_DEFAULT_STATUS_1,BitPn,BFX_DEFAULT_WIDTH);

  #endif
}

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
void Bfx_SetBit_u32u8(uint32* const Data, uint8 BitPn)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  *Data |= (uint32)(1UL << BitPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert32Bits(Data,(uint32)BFX_DEFAULT_STATUS_1,BitPn,BFX_DEFAULT_WIDTH);

  #endif
}

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
void Bfx_ClrBit_u8u8(uint8* const Data, uint8 BitPn)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  *Data &= (uint8)(~(1UL << BitPn));

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert8Bits(Data,BFX_DEFAULT_STATUS_0,BitPn,BFX_DEFAULT_WIDTH);

  #endif
}

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
void Bfx_ClrBit_u16u8(uint16* const Data, uint8 BitPn)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  *Data &= (uint16) ~(1UL << BitPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert16Bits(Data,BFX_DEFAULT_STATUS_0,BitPn,BFX_DEFAULT_WIDTH);

  #endif
}

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
void Bfx_ClrBit_u32u8(uint32* const Data, uint8 BitPn)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  *Data &= (~(1UL << BitPn));

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert32Bits(Data,BFX_DEFAULT_STATUS_0,BitPn,BFX_DEFAULT_WIDTH);

  #endif
}

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
boolean Bfx_GetBit_u8u8_u8(uint8 Data,uint8 BitPn)
{
  boolean ResultValue;

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)
  if((uint8)(Data & ((uint8)(1UL << BitPn))) != 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }
  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else
  if(Bfx_lExtractBits((uint32)Data,BitPn,BFX_DEFAULT_WIDTH) != 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }
  #endif

  return ResultValue;
}
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
boolean Bfx_GetBit_u16u8_u8(uint16 Data,uint8 BitPn)
{
  boolean ResultValue;
  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)
  if((uint16)(Data & ((uint16)(1UL << BitPn))) != 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  if( Bfx_lExtractBits((uint32)Data,BitPn,
                                     (uint8)BFX_DEFAULT_WIDTH) != (uint32)0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }
  #endif

  return ResultValue;
}
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
boolean Bfx_GetBit_u32u8_u8(uint32 Data,uint8 BitPn)
{
  boolean ResultValue;

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)
  if((Data & (1UL << BitPn)) != 0UL )
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }
  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else
  if(Bfx_lExtractBits(Data,BitPn,BFX_DEFAULT_WIDTH) != 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }
  #endif

return ResultValue;
}

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
void Bfx_SetBits_u8u8u8u8(uint8* const Data,
                          uint8 BitStartPn,
                          uint8 BitLn,
                          uint8 Status)
{
  #ifndef _DIABDATA_C_TRICORE_
  uint8 SourceData = BFX_DEFAULT_STATUS_0;
  #endif

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  /*Get Local Mask value corresponding to BitStartPn and BitLn.*/
  uint8 LocalMask = (uint8)Bfx_lGetMaskValue(BitStartPn,BitLn);

  if(Status != 0U)
  {
    /*Data is equal to Bitwise OR of Data and Local Mask value*/
    *Data |= LocalMask;
  }
  else
  {
    /*Data is equal to Bitwise AND of Data and complement of Local Mask value*/
    *Data &= (~LocalMask);
  }

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else
  if(Status != 0U)
  {
    SourceData = (uint8)BFX_DEFAULT_STATUS_1;
  }

  Bfx_lInsert8Bits(Data,SourceData,BitStartPn,BitLn);

  #endif

}

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
void Bfx_SetBits_u16u8u8u8(uint16* const Data,
                           uint8 BitStartPn,
                           uint8 BitLn,
                           uint8 Status)
{
  #ifndef _DIABDATA_C_TRICORE_
  uint16 SourceData = BFX_DEFAULT_STATUS_0;
  #endif

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  /*Get Local Mask value corresponding to BitStartPn and BitLn.*/
  uint16 LocalMask = (uint16)Bfx_lGetMaskValue(BitStartPn,BitLn);

  if(Status != 0U)
  {
    /*Data is equal to Bitwise OR of Data and Local Mask value*/
    *Data |= LocalMask;
  }
  else
  {
    /*Data is equal to Bitwise AND of Data and complement of Local Mask value*/
    *Data &= (~LocalMask);
  }

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else
  if(Status != 0U)
  {
    SourceData = (uint16)BFX_DEFAULT_STATUS_1;
  }

  Bfx_lInsert16Bits(Data,SourceData,BitStartPn,BitLn);

  #endif

}

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
void Bfx_SetBits_u32u8u8u8(uint32* const Data,
                           uint8 BitStartPn,
                           uint8 BitLn,
                           uint8 Status)
{

  #ifndef _DIABDATA_C_TRICORE_
  uint32 SourceData = BFX_DEFAULT_STATUS_0;
  #endif
  
  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  /*Get Local Mask value corresponding to BitStartPn and BitLn.*/
  uint32 LocalMask = Bfx_lGetMaskValue(BitStartPn,BitLn);

  if(Status != 0U)
  {
    /*Data is equal to Bitwise OR of Data and Local Mask value*/
    *Data |= LocalMask;
  }
  else
  {
    /*Data is equal to Bitwise AND of Data and complement of Local Mask value*/
    *Data &= (~LocalMask);
  }

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  if(Status != 0U)
  {
    SourceData = BFX_DEFAULT_STATUS_1;
  }

  if(BitLn == BFX_MAX_LENGTH_32BIT)
  {
    *Data = SourceData;
  }
  else
  {
    Bfx_lInsert32Bits(Data,SourceData,BitStartPn,BitLn);
  }

#endif


}

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
uint8 Bfx_GetBits_u8u8u8_u8(uint8 Data, uint8 BitStartPn, uint8 BitLn)
{

  uint8 ResultValue;

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  /*Get Local Mask value corresponding to BitStartPn and BitLn.*/
  uint8 LocalMask = (uint8)Bfx_lGetMaskValue(BitStartPn,BitLn);

  /*  Step 1. Intermediate value is obtained by performing Bitwise AND of Data 
  and Local Mask value.
  Step 2. Right Shift the intermediate value obtained in Step 1 BitStartPn
  number of times.
  */

  ResultValue = ((Data & LocalMask) >> BitStartPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  ResultValue = (uint8)Bfx_lExtractBits((uint32)Data,BitStartPn,BitLn);

  #endif

  return ResultValue;

}

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
uint16 Bfx_GetBits_u16u8u8_u16(uint16 Data, uint8 BitStartPn, uint8 BitLn)
{

  uint16 ResultValue;

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  /*Get Local Mask value corresponding to BitStartPn and BitLn.*/

  uint16 LocalMask = (uint16)Bfx_lGetMaskValue(BitStartPn,BitLn);

  /*  Step 1. Intermediate value is obtained by performing Bitwise AND of Data
  and Local Mask value.
  Step 2. Right Shift the intermediate value obtained in Step 1 BitStartPn
  number of times.
  */

  ResultValue = ((Data & LocalMask) >> BitStartPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  ResultValue = (uint16)Bfx_lExtractBits((uint32)Data,BitStartPn,BitLn);

  #endif

  return ResultValue;
}

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
uint32 Bfx_GetBits_u32u8u8_u32(uint32 Data, uint8 BitStartPn, uint8 BitLn)
{

  uint32 ResultValue;

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  /*Get Local Mask value corresponding to BitStartPn and BitLn.*/

  uint32 LocalMask = Bfx_lGetMaskValue(BitStartPn,BitLn);

  /*  Step 1. Intermediate value is obtained by performing Bitwise AND of Data
  and Local Mask value.
  Step 2. Right Shift the intermediate value obtained in Step 1 BitStartPn
  number of times.
  */

  ResultValue = ((Data & LocalMask) >> BitStartPn);

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else
  if(BitLn == BFX_MAX_LENGTH_32BIT)
  {
    ResultValue = Data;
  }
  else
  {
    ResultValue = Bfx_lExtractBits(Data,BitStartPn,BitLn);
  }

  #endif

  return ResultValue;
}

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
boolean Bfx_TstBitMask_u8u8_u8(uint8 Data, uint8 Mask)
{

  boolean ResultValue;

  if((Data & Mask) == Mask)
  {
    ResultValue = (boolean)TRUE;
  }

  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
boolean Bfx_TstBitMask_u16u16_u8(uint16 Data, uint16 Mask)
{

  boolean ResultValue;

  if((Data & Mask) == Mask)
  {
    ResultValue = (boolean)TRUE;
  }

  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
boolean Bfx_TstBitMask_u32u32_u8(uint32 Data, uint32 Mask)
{

  boolean ResultValue;

  if((Data & Mask) == Mask)
  {
    ResultValue = (boolean)TRUE;
  }

  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
boolean Bfx_TstBitLnMask_u8u8_u8(uint8 Data, uint8 Mask)
{

  boolean ResultValue;

  if((uint8)(Data & Mask) != 0U)
  {
    ResultValue = (boolean)TRUE;
  }

  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
boolean Bfx_TstBitLnMask_u16u16_u8(uint16 Data, uint16 Mask)
{

  boolean ResultValue;

  if(((uint16)(Data & Mask)) != 0U)
  {
    ResultValue = (boolean)TRUE;
  }

  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
boolean Bfx_TstBitLnMask_u32u32_u8(uint32 Data, uint32 Mask)
{

  boolean ResultValue;

  if((Data & Mask) != 0UL)
  {
    ResultValue = (boolean)TRUE;
  }

  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
boolean Bfx_TstParityEven_u8_u8(uint8 Data)
{

  boolean ResultValue;

  if(Bfx_lParity((uint32)Data) == 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;
}

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
boolean Bfx_TstParityEven_u16_u8(uint16 Data)
{

  boolean ResultValue;
  uint32 ParityValue;

  ParityValue = Bfx_lParity((uint32)Data);

  #ifndef _GNU_C_TRICORE_
  if(ParityValue != 0U)
  {
    ParityValue = (ParityValue & 1U) ^ (ParityValue>>BFX_EIGHT);
  }
  #endif

  if (ParityValue == 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}


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
boolean Bfx_TstParityEven_u32_u8(uint32 Data)
{

  boolean ResultValue;
  uint32 ParityValue;

  ParityValue = Bfx_lParity(Data);

  #ifndef _GNU_C_TRICORE_
  if(ParityValue != 0U)
  {
    ParityValue = (ParityValue & 1U) ^ ((ParityValue>>BFX_EIGHT) & 1U) ^ 
    ((ParityValue>>BFX_SIXTEEN) & 1U) ^ (ParityValue>>BFX_TWENTYFOUR);
  }
  #endif

  if (ParityValue == 0U)
  {
    ResultValue = (boolean)TRUE;
  }
  else
  {
    ResultValue = (boolean)FALSE;
  }

  return ResultValue;

}

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
void Bfx_CopyBit_u8u8u8u8(
uint8* const DestinationData,
uint8 DestinationPosition,
uint8 SourceData,
uint8 SourcePosition
)
{
  /*Check SourcePosition bit of SourceData*/

  if(Bfx_GetBit_u8u8_u8(SourceData,SourcePosition) == (boolean)TRUE)
  {
    /*Set DestinationPosition bit of DestinationData*/
    Bfx_SetBit_u8u8(DestinationData,DestinationPosition);
  }
  else
  {
    /*Clear DestinationPosition bit of DestinationData*/
    Bfx_ClrBit_u8u8(DestinationData,DestinationPosition);
  }

}


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
void Bfx_CopyBit_u16u8u16u8(uint16* const DestinationData,
                            uint8 DestinationPosition,
                            uint16 SourceData,
                            uint8 SourcePosition)
{

  /*Check SourcePosition bit of SourceData*/

  if(Bfx_GetBit_u16u8_u8(SourceData,SourcePosition) == (boolean)TRUE)

  {/*Set DestinationPosition bit of DestinationData*/
    Bfx_SetBit_u16u8(DestinationData,DestinationPosition);
  }

  else

  {/*Clear DestinationPosition bit of DestinationData*/
    Bfx_ClrBit_u16u8(DestinationData,DestinationPosition);
  }

}


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
void Bfx_CopyBit_u32u8u32u8(uint32* const DestinationData,
                            uint8 DestinationPosition,
                            uint32 SourceData,
                            uint8 SourcePosition)
{

  /*Check SourcePosition bit of SourceData*/

  if(Bfx_GetBit_u32u8_u8(SourceData,SourcePosition) == (boolean)TRUE)

  {
    /*Set DestinationPosition bit of DestinationData*/
    Bfx_SetBit_u32u8(DestinationData,DestinationPosition);
  }
  else
  {
    /*Clear DestinationPosition bit of DestinationData*/
    Bfx_ClrBit_u32u8(DestinationData,DestinationPosition);
  }

}

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
void Bfx_PutBits_u8u8u8u8(uint8* const Data,
                          uint8 BitStartPn,
                          uint8 BitLn,
                          uint8 Pattern)
{

  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  uint8 DatamaskValue;
  uint8 PatternmaskValue;

  /*  Get the Complement of Local Mask value corresponding to BitStartPn and
  BitLn.
  */

  DatamaskValue = (uint8)
                  (~((uint8)Bfx_lGetMaskValue(BitStartPn,BitLn)));

  /*Get Local Pattern Mask value corresponding to 0th position and BitLn.*/

  PatternmaskValue = (uint8)Bfx_lGetMaskValue(0U,BitLn);

  /*  Data is equal to Bitwise OR of
  1.) Bitwise AND of Data and DatamaskValue and
  2.) Left Shift of (AND of Pattern and PatternmaskValue), BitStartPn number
  of times.
  */

  *Data = (uint8)((uint8)(*Data & DatamaskValue) |
          (uint8)(((uint32)Pattern & (uint32)PatternmaskValue) << BitStartPn));

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert8Bits(Data,Pattern,BitStartPn,BitLn);

  #endif

}


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
void Bfx_PutBits_u16u8u8u16(uint16* const Data,
                            uint8 BitStartPn,
                            uint8 BitLn,
                            uint16 Pattern)
{
  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  uint16 DatamaskValue;
  uint16 PatternmaskValue;

  /*  Get the Complement of Local Mask value corresponding to BitStartPn and
  BitLn.
  */

  DatamaskValue = (uint16)
                  ~((uint16)Bfx_lGetMaskValue(BitStartPn,BitLn));

  /*Get Local Pattern Mask value corresponding to 0th position and BitLn.*/

  PatternmaskValue = (uint16)Bfx_lGetMaskValue(0U,BitLn);

  /*  Data is equal to Bitwise OR of
  1.) Bitwise AND of Data and DatamaskValue and
  2.) Left Shift of (AND of Pattern and PatternmaskValue), BitStartPn number
  of times.
  */

  *Data = ((uint16)(*Data & DatamaskValue) |
          (uint16)(((uint32)Pattern & (uint32)PatternmaskValue) << BitStartPn));

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  Bfx_lInsert16Bits(Data,Pattern,BitStartPn,BitLn);

  #endif

}


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
void Bfx_PutBits_u32u8u8u32(uint32* const Data,
                            uint8 BitStartPn,
                            uint8 BitLn,
                            uint32 Pattern)
{
  #ifdef _DIABDATA_C_TRICORE_
  #if (_DIABDATA_C_TRICORE_ == 1U)

  uint32 DatamaskValue;
  uint32 PatternmaskValue;

  /*  Get the Complement of Local Mask value corresponding to BitStartPn and
  BitLn.
  */

  DatamaskValue = ~((uint32)Bfx_lGetMaskValue(BitStartPn,BitLn));

  /*Get Local Pattern Mask value corresponding to 0th position and BitLn.*/

  PatternmaskValue = (uint32)Bfx_lGetMaskValue(0U,BitLn);

  /*  Data is equal to Bitwise OR of
  1.) Bitwise AND of Data and DatamaskValue and
  2.) Left Shift of (AND of Pattern and PatternmaskValue), BitStartPn 
  number of times.
  */

  *Data = ((*Data & DatamaskValue) |
            ((Pattern & PatternmaskValue) << BitStartPn));

  #endif /* #if (_DIABDATA_C_TRICORE_ == 1U) */
  #else

  if(BitLn == BFX_MAX_LENGTH_32BIT)
  {
    *Data = Pattern;
  }
  else
  {
    Bfx_lInsert32Bits(Data,Pattern,BitStartPn,BitLn);
  }

  #endif

}

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
void Bfx_PutBit_u8u8u8(uint8* const Data, uint8 BitPn, uint8 Status)
{

  if(Status == 1U)
  {
    /*Step 1. Get the intermediate value obtained when 0x01 is left shifted
    BitPn number of times.
    Step 2. Bitwise OR Data with the intermediate value obtained in Step 1.
    Step 3. Update the value of Data with the value obtained after Step 2.
    */

    *Data = (*Data | (uint8)(0x01U << BitPn));

  }
  else
  {
    /*Step 4. Get the intermediate value obtained when 0x01 is left shifted 
    BitPn number of times.
    Step 5. Bitwise Complement the intermediate value obtained in Step 4 and
    then Bitwise AND it with Data.
    Step 6. Update the value of Data with the value obtained after Step 5.
    */

    *Data = (*Data & (uint8)(~(uint8)(0x01U << BitPn)));
  }

}


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
void Bfx_PutBit_u16u8u8(uint16* const Data, uint8 BitPn, uint8 Status)
{

  if(Status == 1U)
  {
    /*  Step 1. Get the intermediate value obtained when 0x01 is left shifted
    BitPn number of times.
    Step 2. Bitwise OR Data with the intermediate value obtained in Step 1.
    Step 3. Update the value of Data with the value obtained after Step 2.
    */

    *Data = (uint16)(*Data | (uint16)(1UL << BitPn));
  }
  else
  {
    /*  Step 4. Get the intermediate value obtained when 0x01 is left shifted 
    BitPn number of times.
    Step 5. Bitwise Complement the intermediate value obtained in Step 4 and
    then Bitwise AND it with Data.
    Step 6. Update the value of Data with the value obtained after Step 5.
    */

    *Data = (uint16)(*Data & (uint16)(~(uint16)(1UL << BitPn)));
  }

}


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
void Bfx_PutBit_u32u8u8(uint32* const Data, uint8 BitPn, uint8 Status)
{

  if(Status == 1U)
  {
    /*Step 1. Get the intermediate value obtained when 0x01 is left shifted
    BitPn number of times.
    Step 2. Bitwise OR Data with the intermediate value obtained in Step 1.
    Step 3. Update the value of Data with the value obtained after Step 2.
    */

    *Data = (*Data | (0x01UL << BitPn));
  }
  else
  {
    /*Step 4. Get the intermediate value obtained when 0x01 is left shifted 
    BitPn number of times.
    Step 5. Bitwise Complement the intermediate value obtained in Step 4 and
    then Bitwise AND it with Data.
    Step 6. Update the value of Data with the value obtained after Step 5.
    */

    *Data = (*Data & (~(0x01UL << BitPn)));
  }

}
/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Functions                      **
*******************************************************************************/

/*******************************************************************************
**                            LOW Level Driver Functions                      **
*******************************************************************************/
#define BFX_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives 
is allowed only for MemMap.h*/
#include "MemMap.h"

