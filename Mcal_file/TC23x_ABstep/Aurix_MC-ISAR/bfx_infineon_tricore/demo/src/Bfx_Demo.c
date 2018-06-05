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
**  $FILENAME   : Bfx_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2013-08-23 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains demo application for Bfx Library        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

#include "Bfx.h"
#include "Bfx_Demo.h"

#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"


/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


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
**                      Private Function Declarations                         **
*******************************************************************************/
char Bfx_GetchwithPrint(void);
uint8 Bfx_GetIntegerwithPrint(void);
uint8 Bfx_Get8BitDecimalwithPrint(void);
uint16 Bfx_Get16BitDecimalwithPrint(void);
uint32 Bfx_Get32BitDecimalwithPrint(void);
void Bfx_Print8BitBinary(uint8);
void Bfx_Print16BitBinary(uint16 Data16);
void Bfx_Print32BitBinary(uint32 Data32);

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/*******************************************************************************
** Syntax : char Bfx_GetchwithPrint(void)                                     **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: char                                                         **
**                                                                            **
** Description : Gets a character and also prints the character on the screen.**
**                                                                            **
*******************************************************************************/

char Bfx_GetchwithPrint(void)
{
  char c;
  c=(uint8)get_char();
  print_f("%c",c);
  return c;
}
/*******************************************************************************
** Syntax : uint8 Bfx_GetIntegerwithPrint(void)                               **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: uint8                                                        **
**                                                                            **
** Description : Gets a number character, prints the character on screen and  **
**               returns its integer equivalent.                              **
**                                                                            **
*******************************************************************************/

uint8 Bfx_GetIntegerwithPrint(void)
{
  char c;
  uint8 i;
  c=(uint8)get_char();
  print_f("%c",c);
  i=c-'0';/*Coverting character to integer*/
  return i;
}
/*******************************************************************************
** Syntax : uint8 Bfx_Get8BitDecimalwithPrint(void)                           **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: uint8                                                         **
**                                                                            **
** Description : Accepts 3 Decimal characters, displays the 3 digit decimal   **
**               number and returns 3 digit decimal number equivalent.        **
**                                                                            **
*******************************************************************************/
/*Used to accept 8-bit number in Decimal from Keyboard and print it on screen*/
uint8 Bfx_Get8BitDecimalwithPrint(void)
{
  uint8 Data8=0;
  Data8=Bfx_GetIntegerwithPrint()*100;
  Data8+=(Bfx_GetIntegerwithPrint()*10);
  Data8+=(Bfx_GetIntegerwithPrint());/*Max value 255. Don't enter Data8>255.*/
  return Data8;
}
/*******************************************************************************
** Syntax : uint16 Bfx_Get16BitDecimalwithPrint(void)                         **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: uint16                                                       **
**                                                                            **
** Description : Accepts 5 Decimal characters, displays the 5 digit decimal   **
**               number and returns 5 digit decimal number equivalent.        **
**                                                                            **
*******************************************************************************/
/*Used to accept 16-bit number in Decimal from Keyboard and print it on screen*/
uint16 Bfx_Get16BitDecimalwithPrint(void)
{
  uint16 Data16=0;
  /*Data16 should not be greater than 65535.*/
  Data16=Bfx_GetIntegerwithPrint()*10000;
  Data16+=(Bfx_GetIntegerwithPrint()*1000);
  Data16+=(Bfx_GetIntegerwithPrint()*100);
  Data16+=(Bfx_GetIntegerwithPrint()*10);
  Data16+=(Bfx_GetIntegerwithPrint());
  return Data16;
}
/*******************************************************************************
** Syntax : uint32 Bfx_Get32BitDecimalwithPrint(void)                         **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: uint32                                                       **
**                                                                            **
** Description : Accepts 10 Decimal characters, displays the 10 digit decimal **
**               number and returns 10 digit decimal number equivalent.       **
**                                                                            **
*******************************************************************************/
/*Used to accept 32-bit number in Decimal from Keyboard and print it on screen*/
uint32 Bfx_Get32BitDecimalwithPrint(void)
{
  uint32 Data32=0;
  /*Data32 should not be greater than 4294967295.*/
  Data32=(Bfx_GetIntegerwithPrint()*1000000000);
  Data32+=(Bfx_GetIntegerwithPrint()*100000000);
  Data32+=(Bfx_GetIntegerwithPrint()*10000000);
  Data32+=(Bfx_GetIntegerwithPrint()*1000000);
  Data32+=(Bfx_GetIntegerwithPrint()*100000);
  Data32+=(Bfx_GetIntegerwithPrint()*10000);
  Data32+=(Bfx_GetIntegerwithPrint()*1000);
  Data32+=(Bfx_GetIntegerwithPrint()*100);
  Data32+=(Bfx_GetIntegerwithPrint()*10);
  Data32+=Bfx_GetIntegerwithPrint();
  return Data32;
}

/*******************************************************************************
** Syntax : void Bfx_Print8BitBinary(uint8)                                   **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): uint8 Data                                                **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Prints 8-bit Data in Binary                                  **
**                                                                            **
*******************************************************************************/

void Bfx_Print8BitBinary(uint8 Data8)
{
  uint8 ii=8;
  boolean b;
  print_f("     ");
  do
  {
    b=Bfx_GetBit_u8u8_u8(Data8,ii-1);
    if(b==TRUE)
      print_f("1");
    else if(b==FALSE)
      print_f("0");
    else
      print_f("\n?");
    ii--;
  }while(ii!=0);
}
/*******************************************************************************
** Syntax : Bfx_Print16BitBinary(uint16 Data16)                               **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): uint16 Data                                               **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Prints 16-bit Data in Binary                                 **
**                                                                            **
*******************************************************************************/

void Bfx_Print16BitBinary(uint16 Data16)
{
  uint8 ii=16;
  boolean b;
  print_f("     ");
  do
  {
    b=Bfx_GetBit_u16u8_u8(Data16,ii-1);
    if(b==TRUE)
      print_f("1");
    else if(b==FALSE)
      print_f("0");
    else
      print_f("\n?");
    ii--;
  }while(ii!=0);
}
/*******************************************************************************
** Syntax : void Bfx_Print32BitBinary(uint32 Data32)                          **
**                                                                            **
** Service ID:   : NA                                                         **
**                                                                            **
** Sync/Async:   :                                                            **
**                                                                            **
** Reentrancy:   :                                                            **
**                                                                            **
** Parameters (in): none                                                      **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value: none                                                         **
**                                                                            **
** Description : Prints 32-bit Data in Binary                                 **
**                                                                            **
*******************************************************************************/

void Bfx_Print32BitBinary(uint32 Data32)
{
  uint8 ii=32;
  boolean b;
  print_f("     ");
  do
  {
    b=Bfx_GetBit_u32u8_u8(Data32,ii-1);
    if(b==TRUE)
      print_f("1");
    else if(b==FALSE)
      print_f("0");
    else
      print_f("\n?");
    ii--;
  }while(ii!=0);
}

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
void Bfx_Demo(void)
{
	uint8 BitPn=0;
	uint8 Data8=0;
	uint8* pData8;
	pData8=&Data8;
	
	print_f("\n Start of BFX Demo");

	print_f("\n\n1. Bfx_SetBit_u8u8");
	print_f("\n\nvoid Bfx_SetBit_u8u8(uint8* const Data,"
                              "uint8 BitPn)");
                      print_f("\n\nEnter 8 bit Input Data (Max value 255)");
                      /*Max value 255. Don't enter Data8>255.*/
                      Data8=Bfx_Get8BitDecimalwithPrint();
                      print_f("\nData entered is %u",Data8);
                      print_f("\n\nEnter Bit Position(0-7)");
                      BitPn=Bfx_GetIntegerwithPrint();
                      Bfx_SetBit_u8u8(pData8,BitPn);
                      print_f("\n\nOutput Data is %u.",Data8);
	print_f("\n\n2. Bfx_ClrBit_u8u8");
	print_f("\n\nvoid Bfx_ClrBit_u8u8(uint8* const Data,"
                                " uint8 BitPn)");
                        print_f("\n\nEnter 8 bit Input Data (Max value 255)");
                        /*Max value 255. Don't enter Data8>255.*/
                        Data8=Bfx_Get8BitDecimalwithPrint();
                        print_f("\nData entered is %u",Data8);
                        print_f("\n\nEnter Bit Position(0-7)");
                        BitPn=Bfx_GetIntegerwithPrint();
                        Bfx_ClrBit_u8u8(pData8,BitPn);
                        print_f("\n\nOutput Data is %u.",Data8);
  print_f("\n\n3. Bfx_ToggleBits_u8");
	print_f("\n\nvoid Bfx_ToggleBits_u8(uint8* const Data)");
                        print_f("\n\nEnter 8 bit Input Data (Max value 255)");
                        /*Max value 255. Don't enter Data8>255.*/
                        Data8=Bfx_Get8BitDecimalwithPrint();
                        print_f("\nData entered is %u",Data8);
                        Bfx_ToggleBits_u8(pData8);
                        print_f("\n\nOutput Data is %u.",Data8);
}
