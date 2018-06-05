/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME  : Dma_Demo.c                                                   **
**                                                                            **
**  $CC VERSION : \main\14 $                                                 **
**                                                                            **
**  $DATE      : 2013-06-26 $                                                 **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - Demo application for Dma Driver                          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
*******************************************************************************/
/*  TRACEABILITY :                                                            **
                                                                              **
                                                                              */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"
#include "Dma_Demo.h"
#include "Dma.h"
#include "DemoApp_Cfg.h"
#include "IfxDma_reg.h"
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define DMA_TEST_DATA_LENGTH   ((uint8)14U)
#define DMA_LLCOUNT            ((uint8)4U)
#define DMA_UPPER_LENGTH       ((uint8)4U)
#define DMA_LOWER_LENGTH       ((uint8)8U)
#define DMA_CAMEL_LENGTH       ((uint8)16U)
#define DMA_DIGIT_LENGTH       ((uint8)12U)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

static const uint8 Dma_SourceBuffer[DMA_TEST_DATA_LENGTH] =
                      {'D','M','A',' ','D','E','M','O',' ','P','A','S','S',' '};   
static const uint8 DmaDemo_DefaultString[DMA_TEST_DATA_LENGTH]=
                      {'D','M','A',' ','D','E','M','O',' ','F','A','I','L',' '};           
/*
* linked list variable declarations
*/

#define DMA_START_SEC_CONST_32BIT
/*
* Since channel data width to be used for linked list operation is 32bit so all
* linked list variables wil be 32bit aligned. If data width is changed then
* memmap section might be needed to change accordingly.
* Here in this section const variables will be kept
* Inclusion of MemMap.h
*/
#include "MemMap.h"

static const uint8 DmaDemo_DefaultUpper[DMA_UPPER_LENGTH] =
              {'C','a','p','s'};
static const uint8 DmaDemo_DefaultCamel[DMA_CAMEL_LENGTH] =
              {' ','C','a','m','e','l','C','a','s','e','-','M','i','x','e','d'};
static const uint8 DmaDemo_DefaultLower[DMA_LOWER_LENGTH] =
              {' ','L','o','w','C','a','s','e'};
static const uint8 DmaDemo_DefaultDigit[DMA_DIGIT_LENGTH] =
              {' ','D','i','g','i','t','s','(','0','-','9',')'};

static const uint8 DmaDemo_SrcUpperCase[DMA_UPPER_LENGTH] =
              {'A','B','C','D'};
static const uint8 DmaDemo_SrcCamelCase[DMA_CAMEL_LENGTH]   =
              {'_','E','f','G','h','I','j','K','l','M','n','O','p','Q','r','S'};
static const uint8 DmaDemo_SrcLowerCase[DMA_LOWER_LENGTH] =
              {'_','t','u','v','w','x','y','z'};
static const uint8 DmaDemo_SrcDigit[DMA_DIGIT_LENGTH] =
              {'_','0','1','2','3','4','5','6','7','8','9','.'};

#define DMA_STOP_SEC_CONST_32BIT
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint8 Dma_Destinationbuffer[DMA_TEST_DATA_LENGTH];
#define DMA_START_SEC_VAR_32BIT
/*
* for 32bit non constant variables
* Inclusion of MemMap.h
*/
#include "MemMap.h"
static uint8 DmaDemo_DstUpperCase[DMA_UPPER_LENGTH];
static uint8 DmaDemo_DstLowerCase[DMA_LOWER_LENGTH];
static uint8 DmaDemo_DstCamelCase[DMA_CAMEL_LENGTH];
static uint8 DmaDemo_DstDigit[DMA_DIGIT_LENGTH];

#define DMA_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*for linked list operation, base address of ExtBuffer should be 32 byte aligned
or else it will give bus errors which can be observed by calling
Dma_GetMoveEngineErrFlags() api.*/

#ifdef _TASKING_C_TRICORE_
#pragma align 32
Dma_FullTxCtrlSetType ExtBuffer[DMA_LLCOUNT];
#pragma align restore
#endif

#ifdef _GNU_C_TRICORE_
Dma_FullTxCtrlSetType ExtBuffer[DMA_LLCOUNT] __attribute__ ((aligned (32U)));
#endif

#ifdef _DIABDATA_C_TRICORE_
Dma_FullTxCtrlSetType ExtBuffer[DMA_LLCOUNT];
#pragma section IOSECT standard RW address=0x700004E0U
#pragma use_section IOSECT ExtBuffer
#endif

/* length is divided by 4 as 4 bytes will be transferred in
one move(in case of ch_data width=32)
configuration used, RROAT=1, INCS/INCD=1, CHDW=2 */

Dma_TransactionSetType Dma_TCS[DMA_LLCOUNT] =
{
{0,(uint32)DmaDemo_SrcUpperCase,(uint32)DmaDemo_DstUpperCase,(uint16)(DMA_UPPER_LENGTH)/4U,1U},
{0,(uint32)DmaDemo_SrcCamelCase,(uint32)DmaDemo_DstCamelCase,(uint16)(DMA_CAMEL_LENGTH)/4U,1U},
{0,(uint32)DmaDemo_SrcLowerCase,(uint32)DmaDemo_DstLowerCase,(uint16)(DMA_LOWER_LENGTH)/4U,1U},
{0,(uint32)DmaDemo_SrcDigit,(uint32)DmaDemo_DstDigit,(uint16)(DMA_DIGIT_LENGTH)/4U,1U}
};
/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Local Function Declarations                           **
*******************************************************************************/
/*******************************************************************************
** Syntax : void Dma_Demo(void)                                               **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   : Synchronous                                                **
**                                                                            **
** Reentrancy:   : Non Reentrant                                              **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Demo Tests for all the delivered Modules.                    **
*******************************************************************************/
void Dma_Demo(void)
{
  uint32 LoopCtr;
  uint32 PressedKey;
  uint16 tcount;
  uint8 i;
  uint8 CopyError=0U;
  Std_ReturnType ReturnValue;

   /* Print user information */
  print_f("\n\n\n");
  print_f("\n----------------------------------\n");
  print_f("\n       DMA DRIVER DEMO MENU      ");
  print_f("\n        ENTER YOUR OPTION        ");
  print_f("\n----------------------------------\n");
  LoopCtr = 1U;

  while(LoopCtr != 0U)
  {
    print_f("\n**************************************************************");
    print_f("\n '1'. Start a SW transaction");
    print_f("\n '2'. Perform transaction via linked list");
    print_f("\n 'x'. Exit and go back to main menu");
    print_f("\n**************************************************************");

    /* Get the Key pressed from user */
    PressedKey = get_char();

    if(PressedKey == '1')
    {
      /*RROAT should be equal to 1 for this transaction to complete in one go*/;
      tcount=(uint16)DMA_TEST_DATA_LENGTH;
      print_f("\n Source value= ");
      for (i=0U; i< tcount;i++)
      {
        put_char(Dma_SourceBuffer[i]);
      }
      print_f("\n Original Destination value= ");
      for (i=0U; i< tcount;i++)
      {
        Dma_Destinationbuffer[i] = DmaDemo_DefaultString[i];
        put_char(Dma_Destinationbuffer[i]);
      }

    /*Starts the software transaction by passing source, destination address and
      transfer count for channel 8 */

      Dma_StartSwTransaction(DMA_CH8, (uint32 *)&Dma_SourceBuffer[0] ,
                         (uint32 *)&Dma_Destinationbuffer[0], tcount);

      print_f("\n Final Destination value = ");

      for (i=0U; i<tcount;i++)
      {
        put_char(Dma_Destinationbuffer[i]);
      }
    }

    else if(PressedKey == '2')
    {
     /*
     *Final destination value should be english alphabets followed
     *by numerical digits in increasing order. First 3 letters should be in
     *Upper case and next 8 should be mix of lower and upper case and rest
     *should be in small case
     */
      print_f("\n\nOriginal Destination value= ");
      for (i=0U; i< DMA_UPPER_LENGTH;i++)
      {
        DmaDemo_DstUpperCase[i] = DmaDemo_DefaultUpper[i];
        put_char(DmaDemo_DstUpperCase[i]);
      }
      for (i=0U; i< DMA_CAMEL_LENGTH;i++)
      {
        DmaDemo_DstCamelCase[i] = DmaDemo_DefaultCamel[i];
        put_char(DmaDemo_DstCamelCase[i]);
      }
      for (i=0U; i< DMA_LOWER_LENGTH;i++)
      {
        DmaDemo_DstLowerCase[i] = DmaDemo_DefaultLower[i];
        put_char(DmaDemo_DstLowerCase[i]);
      }
      for (i=0U; i< DMA_DIGIT_LENGTH;i++)
      {
        DmaDemo_DstDigit[i] = DmaDemo_DefaultDigit[i];
        put_char(DmaDemo_DstDigit[i]);
      }

      ReturnValue = Dma_ConfigChannelLinkList(DMA_CH9,(Dma_TransactionSetType*)
                     &Dma_TCS,(Dma_FullTxCtrlSetType*)&ExtBuffer, DMA_LLCOUNT);
      if(ReturnValue == E_NOT_OK)
        break;

      print_f("\nFinal Destination value   = ");

      for (i=0U; i< DMA_UPPER_LENGTH;i++)
      {
        put_char(DmaDemo_DstUpperCase[i]);
        if(DmaDemo_DstUpperCase[i]!=DmaDemo_SrcUpperCase[i])
        {
          CopyError=1U;
        }
      }
      for (i=0U; i< DMA_CAMEL_LENGTH;i++)
      {
        put_char(DmaDemo_DstCamelCase[i]);
        if(DmaDemo_DstCamelCase[i]!=DmaDemo_SrcCamelCase[i])
        {
          CopyError=1U;
        }
      }
      for (i=0U; i< DMA_LOWER_LENGTH;i++)
      {
        put_char(DmaDemo_DstLowerCase[i]);
        if(DmaDemo_DstLowerCase[i]!=DmaDemo_SrcLowerCase[i])
        {
          CopyError=1U;
        }
      }
      for (i=0U; i< DMA_DIGIT_LENGTH;i++)
      {
        put_char(DmaDemo_DstDigit[i]);
        if(DmaDemo_DstDigit[i]!=DmaDemo_SrcDigit[i])
        {
          CopyError=1U;
        }
      }

      if(CopyError==1U)
      {
        print_f("\nError occured while copying data v%d \n",CopyError);
        print_f("DMA DEMO FAILED \n");
      }
      else
      {
        print_f("\n\nNo error obserevd as source/destination data are same \n");
        print_f("Result : DMA DEMO PASSED  \n");
      }
      LoopCtr = 0U;
    }

    else if((PressedKey == 'X') || (PressedKey == 'x'))
    {
      LoopCtr = 0U;

    }
    
    else
    {
      print_f("\n  Invalid key pressed,  ");
    }
  }/* end of while */
  print_f("\n----------------------------------\n");
  print_f("\n       END OF DMA DEMO            \n");
  print_f("\n----------------------------------\n");
  return;

} /* end of Dma_Demo */

