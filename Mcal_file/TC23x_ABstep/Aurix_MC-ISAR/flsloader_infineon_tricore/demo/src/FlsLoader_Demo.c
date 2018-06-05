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
**  $FILENAME   : FlsLoader_Demo.c $                                         **
**                                                                           **
**  $CC VERSION : \main\35 $                                                 **
**                                                                           **
**  $DATE       : 2015-06-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains the FlslOader demo application          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "FlsLoader.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "Mcal.h"

#if  ( FLSLOADER_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Passwords fixed for testing */

#define FLSLOADER_LOCKUNLOCK_DEMO 0
#define UCB_PFLASH_ADDR ((FlsLoader_AddressType)(0xAF100000U))
#define UCB_DFLASH_ADDR ((FlsLoader_AddressType)(0xAF100400U))
#define UCB_OTP_ADDR    ((FlsLoader_AddressType)(0xAF100C00U))
#define NUM_OF_SECT_3   (3U)
#define NUM_OF_SECT_1   (1U)
#define NUM_OF_SECT_2   (2U)
#define BUFFER_SIZE1    (512U) /*Number of bytes to be written = 2 Burst in PFLASH*/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Local Function Declarations                           **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_lDFlashDemo(void);
FlsLoader_ReturnType FlsLoader_lPFlashDemo(void);

#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
 FlsLoader_ReturnType FlsLoader_lLockDemo(void);
 FlsLoader_ReturnType FlsLoader_lDFUnLockDemo(void);
 FlsLoader_ReturnType FlsLoader_lPFUnLockDemo(void);
#endif



volatile  FlsLoader_ReturnType retval;
uint32 FlsLoader_Address = 0 ;
char FlashLoader_Address[25] = "Address in Hex";

static const PAR_t Flsloader_AddressStruct[] = 
{
  {
    PAR_TYP_HEX,                    /* uwType */
    sizeof(FlsLoader_Address),      /* uwSize */
    &FlsLoader_Address,             /* pvData */
    0x0U,                           /* uwMin */
    0xFFFFFFFFU,                    /* uwMax */
    "AddressValue",                 /* szText */
    "%x"                            /* szOutputFormat */
  }
}; 

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define FLSLOADER_START_SEC_VAR_32BIT
#include "MemMap.h"

uint8 buffer[512] =
{
0x11,0x11,0x11,0x11,0x22,0x22,0x22,0x22,
0x33,0x33,0x33,0x33,0x44,0x44,0x44,0x44,
0x55,0x55,0x55,0x55,0x66,0x66,0x66,0x66,
0x77,0x77,0x77,0x77,0x88,0x88,0x88,0x88,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x11,0x11,0x11,0x11,0x22,0x22,0x22,0x22,
0x33,0x33,0x33,0x33,0x44,0x44,0x44,0x44,
0x55,0x55,0x55,0x55,0x66,0x66,0x66,0x66,
0x77,0x77,0x77,0x77,0x88,0x88,0x88,0x88,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x11,0x11,0x11,0x11,0x22,0x22,0x22,0x22,
0x33,0x33,0x33,0x33,0x44,0x44,0x44,0x44,
0x55,0x55,0x55,0x55,0x66,0x66,0x66,0x66,
0x77,0x77,0x77,0x77,0x88,0x88,0x88,0x88,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x11,0x11,0x11,0x11,0x22,0x22,0x22,0x22,
0x33,0x33,0x33,0x33,0x44,0x44,0x44,0x44,
0x55,0x55,0x55,0x55,0x66,0x66,0x66,0x66,
0x77,0x77,0x77,0x77,0x88,0x88,0x88,0x88,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,
0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,

};

#define FLSLOADER_STOP_SEC_VAR_32BIT
#include "MemMap.h"

uint32 DfPassword[8] =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

uint32 PfPassword[8] =
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};



/*******************************************************************************
** Syntax           : void FlsLoader_Demo(void)                               **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Description      : FLSLOADEr driver Demo                                   **
**                                                                            **
*******************************************************************************/
void FlsLoader_Demo()
{
  uint8 TempUSage = 0;
  char szString[80];
  uint32 *SourcePtr;
  uint32 Data;

  FlsLoader_ReturnType retval1;

  #if (FLSLOADER_LOCKUNLOCK_DEMO == 1)
  FlsLoader_ReturnType retval2,retval11;
  #endif
#if 0
  #if (FLSLOADER_VERSION_INFO_API == STD_ON)
  Std_VersionInfoType VersionInfo;
  #endif
#endif


  print_f("\n---------------  Start of FLSLOADER driver demo ---------------\n");

#if 0
  #if (FLSLOADER_VERSION_INFO_API == STD_ON)
  FlsLoader_GetVersionInfo(&VersionInfo);
  print_f("\nFlsLoader Module ID : %d\n",VersionInfo.moduleID);
  print_f("\nFlsLoader Vendor ID : %d\n",VersionInfo.vendorID);
  print_f("\nFlsLoader Major Version ID : %d\n",VersionInfo.sw_major_version);
  print_f("\nFlsLoader Minor Version ID : %d\n",VersionInfo.sw_minor_version);
  print_f("\nFlsLoader Patch Version ID : %d\n",VersionInfo.sw_patch_version);
  #endif
#endif

  /* FlsLoader Initialization execution */
  print_f("\nFlsLoader_Init started..\n");
  retval = FlsLoader_Init(NULL_PTR);

  if(retval == FLSLOADER_E_OK)
  {
    print_f("\n FlsLoader_Init Execution Passed \n");
  }
  else
    if (retval == FLSLOADER_E_NOT_OK)
    {
      print_f("\n FlsLoader_Init Execution Failed, DET occured \n");
    }
    else
      if(retval == FLSLOADER_E_ROMVERSION)
      {
        print_f("\n FlsLoader_Init Execution Failed, DFLASH protected under OTP\n");
      }

 while (TempUSage!=1)
  {
    print_f("\n 1. DFlash Programming ");
    print_f("\n 2. DFlash Read ");
    print_f("\n 3. PFlash Programming ");
    print_f("\n 4. PFlash Read ");

#if (FLSLOADER_LOCKUNLOCK_DEMO == 1)
     print_f("\n 5. LOCK       ");
     print_f("\n 6. UNLOCK DFlash    ");
     print_f("\n 7. UNLOCK PFlash    ");
#endif
     print_f("\n X. Go back to main menu    ");
     print_f("\n Option: ");
     getline(szString, sizeof szString - 1);

     switch (*szString)
     {
      case '1':
        retval1 = FlsLoader_lDFlashDemo();
        if (retval1 == FLSLOADER_E_OK)
        {
          print_f("\n FlsLoader DFlash Demo Passed\n");
        }
        else
        {
          print_f("\n FlsLoader DFlash Demo Failed \n");
        }
        break;
      case '3':
        retval1 = FlsLoader_lPFlashDemo();
        if (retval1 == FLSLOADER_E_OK)
        {
          print_f("\n FlsLoader PFlash Demo Passed\n");
        }
        else
        {
          print_f("\n FlsLoader PFlash Demo Failed \n");
        }
        break;
      case '2':
        {
          print_f("\n Reading first 8 bytes from programmed DFlash Address\n");
          SourcePtr = (uint32*)FlsLoader_Address;
          Data = *SourcePtr;
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+1);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+2);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+3);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+4);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+5);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+6);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+7);
          print_f("\n Vaue at Address %x 0x%x\n",FlsLoader_Address,Data);
         }
        break;
      case '4':
        {
          print_f("\n Reading first 8 bytes from programmed PFlash Address\n");
          SourcePtr = (uint32*)FlsLoader_Address;
          Data = *SourcePtr;
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+1);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+2);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+3);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+4);
          print_f("\n Vaue at Address %x 0x%x",FlsLoader_Address,Data);
          Data = *(SourcePtr+5);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+6);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
          Data = *(SourcePtr+7);
          print_f("\n Vaue at Address %x 0x%x ",FlsLoader_Address,Data);
         }
        break;
  #if (FLSLOADER_LOCKUNLOCK_DEMO == 1)
      case '5':
        #if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
        retval2 = FlsLoader_lLockDemo();
        if (retval2 == FLSLOADER_E_OK)
        {
          print_f("\n FlsLoader Lock Demo Passed\n");
        }
        else
        {
          print_f("\n FlsLoader Lock Demo Failed \n");
        }
        #endif
        break;
      case '6':
        #if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
        print_f("\n Erasing the Flash where UCB write Protection is Enabled \n");
        print_f("\n API should return FLSLOADER_E_LOCKED \n");
        retval1 = FlsLoader_Erase(FlsLoader_Address,NUM_OF_SECT_1);
        if (retval1 == FLSLOADER_E_LOCKED)
        {
          print_f("\n FlsLoader_Erase returned FLSLOADER_E_LOCKED. expected output.\n");
          retval11 = FLSLOADER_E_OK;
          retval11 |= FlsLoader_lDFUnLockDemo();
        }
        else
        {
          print_f("\n FlsLoader is not locked properly, unlock cannot be executed .\n");
          retval11 = FLSLOADER_E_NOT_OK;
        }
        if (retval11 == FLSLOADER_E_OK)
        {
          print_f("\n FlsLoader Unlock Demo Passed\n");
        }
        else
        {
          print_f("\n FlsLoader Unlock Demo Failed \n");
        }
        #endif
        break;
      case '7':
        #if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
        print_f("\n Erasing the PFlash where UCB write Protection is Enabled \n");
        print_f("\n API should return FLSLOADER_E_LOCKED \n");
        retval11 =  FlsLoader_Erase((uint32)FlsLoader_Address, NUM_OF_SECT_1);
        if (retval11 == FLSLOADER_E_LOCKED)
        {
          print_f("\n FlsLoader_Erase returned FLSLOADER_E_LOCKED. expected output.\n");
          retval11 = FLSLOADER_E_OK;
          retval11 |= FlsLoader_lPFUnLockDemo();
        }
        else
        {
          print_f("\n PFlash1 is not locked properly, unlock cannot be executed .\n");
          retval11 = FLSLOADER_E_NOT_OK;
        }
        if (retval11 == FLSLOADER_E_OK)   
        {
          retval1 =  FlsLoader_Erase((uint32)FlsLoader_Address, NUM_OF_SECT_1);
          if (retval1 == FLSLOADER_E_OK)
          {
            print_f("\n FlsLoader Unlock Demo Passed\n");
          }
          else
          {
           print_f("\n FlsLoader Unlock Demo Failed \n");
          }
        }
        else
        {
          print_f("\n FlsLoader Demo Failed \n");
        }
        if (retval11 == FLSLOADER_E_OK)
        {
          print_f("\n FlsLoader Pflash1 Unlock Demo Passed\n");
        }
        else
        {
          print_f("\n FlsLoader Pflash1 Unlock Demo Failed \n");
        }
        #endif
        break;
  #endif
      case 'x':
        case 'X':TempUSage = 1;
        break;
       }
     }
}/* End of FlsLoader_Demo */

/*******************************************************************************
** Syntax           : void FlsLoader_lDFlashDemo(void)                        **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Description      : FLSLOADEr driver Demo                                   **
**                                                                            **
*******************************************************************************/

FlsLoader_ReturnType FlsLoader_lDFlashDemo()
{
  FlsLoader_ReturnType retval1;
  retval1 = FLSLOADER_E_NOT_OK;
  if (ParMenu(&FlashLoader_Address[0], 
     (PAR_t *)Flsloader_AddressStruct,  
     sizeof Flsloader_AddressStruct/sizeof Flsloader_AddressStruct[0]) != 'q')
  {
    print_f("\n Address in Hex , Value = 0x%x \n",FlsLoader_Address);
    print_f("\n Erase operation start..  \n");
    retval1 =  FlsLoader_Erase((uint32)FlsLoader_Address,NUM_OF_SECT_1);
    if(retval1 == FLSLOADER_E_OK)
    {
      print_f("\n DFlash_Erase Execution Passed \n");
      print_f("\n Programming at the specified address \n");
      retval1 = FlsLoader_Write((uint32)FlsLoader_Address, BUFFER_SIZE1,&buffer[0]);
      if(retval1 == FLSLOADER_E_OK)
      {
        print_f("\n DFlash_Write Execution Passed \n");
      }
      else if(retval1 == FLSLOADER_E_LOCKED)
      {
        print_f("\n DFlash_Write Execution stopped,Flash Protection is ON \n");
      }
      else if (retval1 == FLSLOADER_E_BUSY)
      {
        print_f("\n DFlash_Write  STOPPED, Flash is Busy \n");
      }
      else
      {
        print_f("\n DFlash_Write Failed, DET occured \n");
      }
    }
    else if(retval1 == FLSLOADER_E_LOCKED)
    {
      print_f("\n DFlash_Erase Execution stopped,Flash Protection is ON \n");
    }
    else if (retval1 == FLSLOADER_E_BUSY)
    {
      print_f("\n DFlash_Erase  STOPPED, Flash is Busy \n");
    }
    else
    {
      print_f("\n DFlash_Erase Failed, DET occured \n");
    }
  }
  return retval1;
}
/*******************************************************************************
** Syntax           : void FlsLoader_lPFlashDemo(void)                        **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Description      : FLSLOADEr driver Demo                                   **
**                                                                            **
*******************************************************************************/
FlsLoader_ReturnType FlsLoader_lPFlashDemo()
{
  FlsLoader_ReturnType retval1;
  retval1 = FLSLOADER_E_NOT_OK;
  if (ParMenu(&FlashLoader_Address[0], 
     (PAR_t *)Flsloader_AddressStruct,  
     sizeof Flsloader_AddressStruct/sizeof Flsloader_AddressStruct[0]) != 'q')
  {
    print_f("\n Address in Hex , Value = 0x%x \n",FlsLoader_Address);
    print_f("\n Erase operation start..  \n");
    retval1 = FlsLoader_Erase((uint32)FlsLoader_Address, NUM_OF_SECT_1);
    if(retval1 == FLSLOADER_E_OK)
    {
      print_f("\n PFlash_Erase Execution Passed \n");
      print_f("\n Programming at the specified address \n");
      retval1 = FlsLoader_Write((uint32)FlsLoader_Address, BUFFER_SIZE1,&buffer[0]);
      if(retval1 == FLSLOADER_E_OK)
      {
        print_f("\n PFlash_Write Execution Passed \n");
      }
      else if(retval1 == FLSLOADER_E_LOCKED)
      {
        print_f("\n PFlash_Write Execution stopped,Flash Protection is ON \n");
      }
      else if (retval1 == FLSLOADER_E_BUSY)
      {
        print_f("\n PFlash_Write  STOPPED, Flash is Busy \n");
      }
      else
      {
        print_f("\n PFlash_Write Failed, DET occured \n");
      }
    }
    else if(retval1 == FLSLOADER_E_LOCKED)
    {
      print_f("\n PFlash_Erase Execution stopped,Flash Protection is ON \n");
    }
    else if (retval1 == FLSLOADER_E_BUSY)
    {
      print_f("\n PFlash_Erase  STOPPED, Flash is Busy \n");
    }
    else
    {
      print_f("\n PFlash_Erase Failed, DET occured \n");
    }
  }
  return retval1;
}

#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Syntax           : void FlsLoader_lLockDemo(void)                          **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Description      : FLSLOADEr driver Demo                                   **
**                                                                            **
*******************************************************************************/
  /* Start of FlsLoader_Lock() Demo */
 FlsLoader_ReturnType FlsLoader_lLockDemo()
{
    FlsLoader_ReturnType retval3;

    print_f("\n FlsLoader_Lock Demo start..  \n");
    retval3 = FlsLoader_Lock();

    if(retval3 == FLSLOADER_E_OK)
    {
      print_f("\n FlsLoader_Lock Execution Passed \n");
    }
    else if(retval3 == FLSLOADER_E_LOCKED)
    {
      print_f("\n FlsLoader_Lock Execution stopped,Flash Protection is ON \n");
    }
    else if (retval3 == FLSLOADER_E_BUSY)
    {
      print_f("\n FlsLoader_Lock  STOPPED, Flash is Busy \n");
    }
    else
    {
      print_f("\n FlsLoader_Lock Failed \n");
    }
    return retval3;
}
#endif

#if (FLSLOADER_LOCK_UNLOCK_API == STD_ON)
/*******************************************************************************
** Syntax           : void FlsLoader_lDFUnLockDemo(void)                      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Description      : FLSLOADEr driver Demo                                   **
**                                                                            **
*******************************************************************************/
  /* Start of FlsLoader_UnLock() Demo */
FlsLoader_ReturnType FlsLoader_lDFUnLockDemo()
{
  FlsLoader_ReturnType retval4;
  uint32 DfStartAddress1;
  uint32 SectorSize1;
  SectorSize1 =1;
  DfStartAddress1 = FlsLoader_Address;
  print_f("\n FlsLoader_UnLock Demo start..  \n");
  retval4 = FlsLoader_UnLock(UCB_DFLASH_ADDR, &DfPassword[0]);
  if(retval4 == FLSLOADER_E_OK)
  {
    print_f("\n FlsLoader_UnLock Execution Passed \n");
  }
  else if (retval4 == FLSLOADER_E_BUSY)
  {
    print_f("\n FlsLoader_UnLock  STOPPED, Flash is Busy \n");
  }
  else
  {
    print_f("\n FlsLoader_UnLock Failed, DET occured \n");
  }
  if(retval4 == FLSLOADER_E_OK)
  {
    print_f("\n Erasing the Flash where UCB write Protection is disabled \n");
    print_f("\n API should return FLSLOADER_E_OK \n");
    retval4 = FlsLoader_Erase(DfStartAddress1,SectorSize1);
    if (retval4 == FLSLOADER_E_OK)
    {
      print_f("\n FlsLoader_Erase returned FLSLOADER_E_OK. expected output.\n");
    }
    else if (retval4 == FLSLOADER_E_LOCKED)
    {
      print_f("\n FlsLoader_Erase returned FLSLOADER_E_LOCKED. Incorrect output.\n");
    }
    else
    {
      print_f("\n FlsLoader_Erase execution Failed, DET occured \n");
    }
  }
  return retval4;
}

/*******************************************************************************
** Syntax           : void FlsLoader_lPFUnLockDemo(void)                      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Description      : FLSLOADEr driver Demo                                  **
**                                                                            **
*******************************************************************************/
  /* Start of FlsLoader_UnLock() Demo */
 FlsLoader_ReturnType FlsLoader_lPFUnLockDemo()
{
  FlsLoader_ReturnType retval4;
  uint32 PfStartAddress1;
  uint32 SectorSize1;
  PfStartAddress1 = FlsLoader_Address;
  SectorSize1 =1;
  print_f("\n FlsLoader_UnLock Demo start..  \n");
  retval4 = FlsLoader_UnLock(UCB_PFLASH_ADDR, &PfPassword[0]);
  if(retval4 == FLSLOADER_E_OK)
  {
    print_f("\n FlsLoader_UnLock Execution Passed \n");
  }
  else if (retval4 == FLSLOADER_E_BUSY)
  {
    print_f("\n FlsLoader_UnLock  STOPPED, Flash is Busy \n");
  }
  else
  {
    print_f("\n FlsLoader_UnLock Failed, DET occured \n");
  }
  if(retval4 == FLSLOADER_E_OK)
  {
    print_f("\n Erasing the Flash where UCB write Protection is disabled \n");
    print_f("\n API should return FLSLOADER_E_OK \n");
    retval4 = FlsLoader_Erase(PfStartAddress1,SectorSize1);
    if (retval4 == FLSLOADER_E_OK)
    {
      print_f("\n FlsLoader_Erase returned FLSLOADER_E_OK. expected output.\n");
    }
    else if (retval4 == FLSLOADER_E_LOCKED)
    {
      print_f("\n FlsLoader_Erase returned FLSLOADER_E_LOCKED. Incorrect output.\n");
    }
    else
    {
      print_f("\n FlsLoader_Erase execution Failed, DET occured \n");
    }
  }
  return  retval4;
}
#endif
   /* #if (FLSLOADER_LOCK_UNLOCK_API == STD_ON) */




