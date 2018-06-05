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
**  $FILENAME   : Crc_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x_as4.0.3\3 $                                **
**                                                                           **
**  $DATE       : 2015-01-12 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains demo application for CRC Library        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"

#include "Mcal.h"
#include "Crc.h"
#include "Crc_Demo.h"

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
**                      Private Function Declarations                         **
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
#ifdef CRC_8_MODE
          #if  CRC_8_MODE == 0x00000000
              #define CRC_8_IMPLEMENTATION_MODE "Runtime"
          #endif
          #if  CRC_8_MODE == 0x00000001
              #define CRC_8_IMPLEMENTATION_MODE "Table"
          #endif
#endif  

#ifdef CRC_8H2F_MODE
          #if  CRC_8H2F_MODE == 0x00000000
              #define CRC_8H2F_IMPLEMENTATION_MODE "Runtime"
          #endif
          #if  CRC_8H2F_MODE == 0x00000001
              #define CRC_8H2F_IMPLEMENTATION_MODE "Table"
          #endif          
#endif  

#ifdef CRC_16_MODE
          #if  CRC_16_MODE == 0x00000000
              #define CRC_16_IMPLEMENTATION_MODE "Runtime"
          #endif
          #if  CRC_16_MODE == 0x00000001
              #define CRC_16_IMPLEMENTATION_MODE "Table"
          #endif
#endif  
        
#ifdef CRC_32_MODE
          #if  CRC_32_MODE == 0x00000000
              #define CRC_32_IMPLEMENTATION_MODE "Runtime"
          #endif
          #if  CRC_32_MODE == 0x00000001
              #define CRC_32_IMPLEMENTATION_MODE "Table"
          #endif
          #if  CRC_32_MODE == 0x00000002
              #define CRC_32_IMPLEMENTATION_MODE "INSTRUCTION"
          #endif
#endif          
/*******************************************************************************
** Traceability     : 
**                                                                            **
** Syntax           : void Crc_Demo(void)                                     **
**                                                                            **
**                                                                            **
** Service ID       : none                                                    **
**                                                                            **
** Sync/Async       : N/A                                                     **
**                                                                            **
** Reentrancy       : N/A                                                     **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      :This function is for demonstration of CRC 8 bit          **
**   (polynomial = 0x1D),CRC 8 bit(polynomial = 0x2F),CRC 16 bit(polynomial = **
**          0x1021),CRC 32 bit(polynomial = 0x04C11DB7)                       **
**                                                                            **
*******************************************************************************/
void Crc_Demo(void)
{
   #if (CRC_VERSION_INFO_API == (STD_ON))
   Std_VersionInfoType VersionInfoPtr;
   #endif /* #if (CRC_VERSION_INFO_API == (STD_ON)) */   
   const uint8 CrcMessage8[13]={0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0xFF};
   char szString[4];
   uint8 TempUSage = 0;
   uint8 i = 0x0;
     #ifdef CRC_8_IMPLEMENTATION_MODE
       uint8 Crc8Result;
     #endif
     #ifdef CRC_8H2F_IMPLEMENTATION_MODE
       uint8 Crc8H2FResult;
     #endif
     #ifdef CRC_16_IMPLEMENTATION_MODE
       uint16 Crc16Result;
     #endif
     #ifdef CRC_32_IMPLEMENTATION_MODE
       uint32 Crc32Result;
     #endif

   while (TempUSage!=1)
   {
     print_f("\n\n\n");
     print_f("\n/******************************************************");
     print_f("*********************/\n");
     print_f("\n                       CRC DRIVER TEST MENU                \n");
     print_f("                   ENTER YOUR OPTION                         \n");
     
#ifdef CRC_8_IMPLEMENTATION_MODE
     print_f("              < 1 >  CRC Driver Demo 8bitCRC with 0x1D polynomial  and %s based method  Calculations \n",CRC_8_IMPLEMENTATION_MODE);
#endif

#ifdef CRC_8H2F_IMPLEMENTATION_MODE
     print_f("              < 2 >  CRC Driver Demo 8bitCRC with 0x2F polynomial  and  %s based method  Calculations \n",CRC_8H2F_IMPLEMENTATION_MODE);
#endif

#ifdef CRC_16_IMPLEMENTATION_MODE
     print_f("              < 3 >  CRC Driver Demo 16bitCRC with 0x1021 polynomial  and %s based method  Calculations \n",CRC_16_IMPLEMENTATION_MODE);
#endif

#ifdef CRC_32_IMPLEMENTATION_MODE
     print_f("              < 4 >  CRC Driver Demo 32bitCRC with 0x04C11DB7 polynomial and %s based method  Calculations  \n",CRC_32_IMPLEMENTATION_MODE);
#endif     

     print_f("              < x >  Back To Main Menu                       \n");
     print_f("\n/******************************************************");
     print_f("*********************/\n");
     print_f("Option: ");

     getline(szString, sizeof szString - 1);

     switch (*szString)
     {
        case '1':
              #ifdef CRC_8_IMPLEMENTATION_MODE
                   print_f("\n CRC Driver Demo 8bit CRC with 0x1D polynomial  and %s based method selected\n ",CRC_8_IMPLEMENTATION_MODE);
                   print_f("input data is:\t");
                   
                   for(i=0;i<12;i++)
                   {
                       print_f("0x%x,\t",CrcMessage8[i]);
                   }
                   Crc8Result = Crc_CalculateCRC8(CrcMessage8, 12, 0xFF,TRUE);
                   print_f("Crc 8 with 0x1D polynomial is : 0x%x",Crc8Result);
                   if(Crc8Result == 0xAF)
                   {
                     print_f("\nResult = PASS");
                   }
                   else
                   {
                     print_f("\nResult = FAIL");       	
                   }

              #endif
            break;

        case '2' :
              #ifdef CRC_8H2F_IMPLEMENTATION_MODE
                   print_f("\n CRC Driver Demo 8bit CRC with 0x2F polynomial  and %s based method selected\n ",CRC_8H2F_IMPLEMENTATION_MODE);
                   print_f("input data is:\t");
                   for(i=0;i<12;i++)
                   {
                       print_f("0x%x,\t",CrcMessage8[i]);
                   }
                   Crc8H2FResult = Crc_CalculateCRC8H2F(CrcMessage8, 12, 0xFF,TRUE);
                   print_f("Crc 8 with 0x2F polynomial is :0x%x",Crc8H2FResult);
                   if(Crc8H2FResult == 0xBB)
                   {
                     print_f("\nResult = PASS");
                   }
                   else
                   {
                     print_f("\nResult = FAIL");       	
                   }
              #endif
             break;

        case '3' :
              #ifdef CRC_16_IMPLEMENTATION_MODE
                   print_f("\n CRC Driver Demo 16bit CRC with 0x1021 polynomial  and %s based method selected\n ",CRC_16_IMPLEMENTATION_MODE);
                   print_f("input data is:\t");
                   for(i=0;i<12;i++)
                   {
                     print_f("0x%x,\t",CrcMessage8[i]);
                   }
                   Crc16Result = Crc_CalculateCRC16((uint8 *)CrcMessage8, 12, 0xFFFF,TRUE);
                   print_f("Crc 16 with 0x1021 polynomial is :0x%x",Crc16Result);                        
                   if(Crc16Result == 0x19BF)
                   {
                     print_f("\nResult = PASS");
                   }
                   else
                   {
                     print_f("\nResult = FAIL");       	
                   }

              #endif
             break;

        case '4' :
              #ifdef CRC_32_IMPLEMENTATION_MODE
                   print_f("\n CRC Driver Demo 32bit CRC with 0x04C11DB7 polynomial  and %s based method selected\n ",CRC_32_IMPLEMENTATION_MODE);
                   print_f("input data is:\t");
                   for(i=0;i<12;i++)
                   {
                       print_f("0x%x,\t",CrcMessage8[i]);
                   }  

                   Crc32Result = Crc_CalculateCRC32((uint8 *)CrcMessage8, 12, 0xFFFFFFFF,TRUE);
                   print_f("Crc 32 with 0x04C11DB7 polynomial is :0x%x",Crc32Result);
                   if(Crc32Result == 0x4DF4ABCD)
                   {
                     print_f("\nResult = PASS");
                   }
                   else
                   {
                     print_f("\nResult = FAIL");       	
                   }
               #endif
             break;
         case '5' :
          #if (CRC_VERSION_INFO_API == (STD_ON))
   
                   print_f("\n CRC Version Information API Demo selected\n ");
                   
                   Crc_GetVersionInfo(&VersionInfoPtr);           
                   print_f("\nVendor ID=%d",VersionInfoPtr.vendorID);
                   print_f("\nModule ID=%d",VersionInfoPtr.moduleID);
                   print_f("\nSoftware Major Version ID=%d",VersionInfoPtr.sw_major_version);
                   print_f("\nSoftware Minor Version=%d",VersionInfoPtr.sw_minor_version);
                   print_f("\nSoftware Patch Version=%d",VersionInfoPtr.sw_patch_version);
          #endif                                        
          break;
        /* Go Back to Main Menu */
        case 'x':
        case 'X':
         TempUSage = 1;
         break;

        default :
        {
           print_f("\n Invalid Option Choosen \n ");
           break;
        }
     }
   }
}/* DemoApp_CRC() */
