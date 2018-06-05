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
**  $FILENAME   : Fls_17_Pmu_Demo.c $                                        **
**                                                                           **
**  $CC VERSION : \main\26 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - sample Demo Test for FLS  module                        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Fls_17_Pmu.h"

#include "Test_Print.h"
#include "Test_Time.h"

#if  ( FLS_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define SECTOR_0 FLS_SECTOR_START_ADDRESS
#define SECTOR_1 (FLS_SECTOR_START_ADDRESS + FLS_SECTOR_SIZE)

/* num : 1 to 32 */
#define PageAddr(num) (FLS_PAGE_SIZE * (num-1))
#define SectorAddr(num) ((FLS_SECTOR_START_ADDRESS + (num*FLS_SECTOR_SIZE)))

#define FLS_BUF_SIZE   (512U)

#define Time_s(num)    (num*60*1000000)

#define CALL_CYCLE     (70 * 10000) /* (1000000U) */
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"

IFX_INLINE void Fls_lFillBuf(void);

IFX_INLINE Std_ReturnType Fls_lDemoCompare(void); 

IFX_INLINE Std_ReturnType Fls_lDemoWrite(void);

IFX_INLINE Std_ReturnType Fls_lDemoRead(void); 

IFX_INLINE Std_ReturnType Fls_lDemoSetup(void);

Std_ReturnType Fls_lDemoCancel(uint32 JobType);

void Fls_lCallMain(void);

#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"

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
#define FLS_17_PMU_START_SEC_VAR_32BIT
#include "MemMap.h"

static uint8 DataBuffer[FLS_BUF_SIZE];
static uint8 DataBufferRead[FLS_BUF_SIZE];

#define FLS_17_PMU_STOP_SEC_VAR_32BIT
#include "MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax           : void Fls_Demo(void)                                     **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/


void Fls_17_Pmu_Demo(void)
{
  volatile uint32 delay = 0U;
  Std_ReturnType resultflag;    

  print_f("\n---------------  Start of FLS driver demo ---------------\n");
  
  print_f("\nCore ID = %d \n", Mcal_GetCoreId());
    
  /* Clear the DFlash to start the FLS Demo */
  /* FLS_STATE_VAR.FlsEraseTimeoutCycleCount = 0x100; for Debug support test */
  
  resultflag = Fls_lDemoSetup();
  if( resultflag == E_OK)
  {  
    print_f("\n1.Write Blk1 with data :  \n");     
    /* 1. Fill buffer with 12345... data */
    Fls_lFillBuf();
    resultflag = Fls_lDemoWrite();
    if( resultflag == E_OK)
    {
      print_f("\n2.Comparing the data : \n");             
      /* 2. Compare the contents of DFlash with the buffer */
      resultflag = Fls_lDemoCompare();
      if(resultflag == E_OK)
      {
        print_f("The data in the flash is same as data in buffer");      
        
        resultflag = Fls_lDemoRead();
        if(resultflag == E_OK)
        {
          print_f("\nDemoRead successful \n");
          resultflag = Fls_lDemoCancel(FLS_ERASE);
          if(resultflag == E_OK)
          {
            while(delay < 0xFFFFFFU)
            {
              delay++;
            }
            resultflag = Fls_lDemoCancel(FLS_WRITE);
            if(resultflag == E_OK)
            {
              delay = 0U;
              while(delay < 0xFFFFU)
              {
                delay++;
              }
              resultflag = Fls_lDemoCancel(FLS_READ);
              if(resultflag == E_OK)
              {
                resultflag = Fls_lDemoCancel(FLS_COMPARE);
              }
            }
          }
          if(resultflag == E_OK)
          {
            resultflag = Fls_17_Pmu_Read(0U,DataBufferRead,FLS_BUF_SIZE);
            if(resultflag == E_OK)
            {
              if(Fls_17_Pmu_GetStatus() == MEMIF_BUSY)
              {
                print_f("Calling CancelNonEraseJobs for Read "); 
                Fls_17_Pmu_CancelNonEraseJobs();
              }
              if((Fls_17_Pmu_GetStatus() == MEMIF_IDLE) && 
                (Fls_17_Pmu_GetJobResult() == MEMIF_JOB_CANCELED) )
              {
                resultflag = E_OK;
              }
              else
              {
                resultflag = E_NOT_OK;
              }
            }
          }          
        }
        if(resultflag == E_OK)
        {
          print_f("\n\n      FLS driver demo result: PASSED \n");
        }
      }/*end of step2 */
    }/*end of step1 */
  }/*end of Setup */

  if( resultflag != E_OK)
  {  
    print_f("\n\n      FLS driver demo result: FAILED \n");
  }

  print_f("\n---------------  End of FLS driver demo ---------------\n");
}

/*******************************************************************************
** Syntax           : <function syntax>                                       **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/
IFX_INLINE void Fls_lFillBuf()
{
  uint16 i;

  i=0;
  do
  {
    DataBuffer[i] = (uint8)i;
    print_f(" %x ",DataBuffer[i]);          
    i++;      
  }while(i < FLS_BUF_SIZE);

}

/*******************************************************************************
** Syntax           : <function syntax>                                       **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fls_lDemoCompare()
{ 
  Std_ReturnType resultflag;
  volatile uint32 count = 0U;     

  resultflag = Fls_17_Pmu_Compare(0U,DataBuffer,FLS_BUF_SIZE);
  if(resultflag == E_OK)
  {
    while((Fls_17_Pmu_GetStatus() != MEMIF_IDLE) && (count < Time_s(2U)))
    {
      /* Wait till Job completion */
      count++;
      Fls_lCallMain();
      
   }
      
    if( (Fls_17_Pmu_GetStatus() != MEMIF_IDLE) || 
        (Fls_17_Pmu_GetJobResult() != MEMIF_JOB_OK)
      )
    {
      resultflag = E_NOT_OK;
    }
  }
  return(resultflag);
} 

/*******************************************************************************
** Syntax           : <function syntax>                                       **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fls_lDemoRead()
{ 
  Std_ReturnType resultflag;
  volatile uint32 count = 0U;     

   count = 0U;
  resultflag = Fls_17_Pmu_Read(0U,DataBufferRead,FLS_BUF_SIZE);
  if(resultflag == E_OK)
  {
    while((Fls_17_Pmu_GetStatus() != MEMIF_IDLE) && (count < Time_s(2U)))
    {
      /* Wait till Job is finished */
      count++;
      Fls_lCallMain();
    }
      
    if( (Fls_17_Pmu_GetStatus() != MEMIF_IDLE) || 
        (Fls_17_Pmu_GetJobResult() != MEMIF_JOB_OK)
      )
    {
      resultflag = E_NOT_OK;
    }
    else
    {
      uint32 i;
      i=0;
      while((i < FLS_BUF_SIZE) && (resultflag != E_NOT_OK))
      {
        if(DataBuffer[i] != DataBufferRead[i])
        {
          resultflag = E_NOT_OK;
        }
        i++;  
      }
    }    
  }
#if(FLS_IFX_FEE_USED == STD_ON)  
  if(resultflag == E_OK)
  {
    if(Fls_17_Pmu_ReadWordsSync(0U,(const uint32*)DataBufferRead,
                            (FLS_BUF_SIZE/4)) == E_OK)
    {
      resultflag = Fls_17_Pmu_CompareWordsSync(0U,(const uint32*)DataBufferRead,
                                        (FLS_BUF_SIZE/4));
    }
    else
    {
      resultflag = E_NOT_OK;
    }
  }
#endif
  return(resultflag);
} 

/*******************************************************************************
** Syntax           : <function syntax>                                       **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/

Std_ReturnType Fls_lDemoCancel(uint32 JobType)
{ 
  Std_ReturnType resultflag;

  switch(JobType)                                      
  {
    case FLS_WRITE:
    {
      resultflag = Fls_17_Pmu_Write(0U,DataBuffer,FLS_BUF_SIZE);

      if((resultflag == E_OK) && Fls_17_Pmu_GetStatus() == MEMIF_BUSY)
      {
        print_f("\n Cancelling Write \n");
        Fls_17_Pmu_Cancel();
      }
      if((Fls_17_Pmu_GetStatus() == MEMIF_IDLE) && 
          (Fls_17_Pmu_GetJobResult() == MEMIF_JOB_CANCELED) )
      {
        resultflag = E_OK;
      }
      else
      {
        resultflag = E_NOT_OK;
      }
      break;
    }

    case FLS_ERASE:
    {
      resultflag = Fls_17_Pmu_Erase(0U,FLS_SECTOR_SIZE);

      if((resultflag == E_OK) && Fls_17_Pmu_GetStatus() == MEMIF_BUSY)
      {
        print_f("\n Cancelling Erase \n");
        Fls_17_Pmu_Cancel();
      }
      if((Fls_17_Pmu_GetStatus() == MEMIF_IDLE) && 
          (Fls_17_Pmu_GetJobResult() == MEMIF_JOB_CANCELED) )
      {
        resultflag = E_OK;
      }
      else
      {
        resultflag = E_NOT_OK;
      }
      break;
    }
 
    case FLS_READ:
    {
      resultflag = Fls_17_Pmu_Read(0U,DataBufferRead,FLS_BUF_SIZE);

      if((resultflag == E_OK) && Fls_17_Pmu_GetStatus() == MEMIF_BUSY)
      {
        print_f("\n Cancelling Read \n");
        Fls_17_Pmu_Cancel();
      }
      if((Fls_17_Pmu_GetStatus() == MEMIF_IDLE) && 
          (Fls_17_Pmu_GetJobResult() == MEMIF_JOB_CANCELED) )
      {
        resultflag = E_OK;
      }
      else
      {
        resultflag = E_NOT_OK;
      }
      break;
    }

    case FLS_COMPARE:
    {
      resultflag = Fls_17_Pmu_Compare(0U,DataBufferRead,FLS_BUF_SIZE);

      if((resultflag == E_OK) && Fls_17_Pmu_GetStatus() == MEMIF_BUSY)
      {
        print_f("\n Cancelling Compare \n");
        Fls_17_Pmu_Cancel();
      }
      if((Fls_17_Pmu_GetStatus() == MEMIF_IDLE) && 
          (Fls_17_Pmu_GetJobResult() == MEMIF_JOB_CANCELED) )
      {
        resultflag = E_OK;
      }
      else
      {
        resultflag = E_NOT_OK;
      }
      break;
    }
    default :
      resultflag = E_NOT_OK;
      break;
 
  }
    
  return(resultflag);
} 

/*******************************************************************************
** Syntax           : <function syntax>                                       **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fls_lDemoWrite()
{ 
  Std_ReturnType resultflag1;
 #if(FLS_IFX_FEE_USED == STD_ON)
 Std_ReturnType resultflag2;
 #endif
  uint32 WriteSize;
  uint32 WriteAddr;
  volatile uint32 count = 0U;
  
  WriteSize = FLS_BUF_SIZE * 5U;
  WriteAddr = 0U;
  do{
    resultflag1 = Fls_17_Pmu_Write(WriteAddr,DataBuffer,FLS_BUF_SIZE);
    if(resultflag1 == E_OK)
    {
      while((Fls_17_Pmu_GetStatus() != MEMIF_IDLE) && (count < Time_s(2U)))
      {
        /* Wait till Job is finished */
        count++;
        Fls_lCallMain();
      }
      if( (Fls_17_Pmu_GetStatus() != MEMIF_IDLE) || 
          (Fls_17_Pmu_GetJobResult() != MEMIF_JOB_OK)
        )
      {
        resultflag1 = E_NOT_OK;
      }
      else
      {
        resultflag1 = Fls_17_Pmu_Compare(WriteAddr,DataBuffer,FLS_BUF_SIZE); 
        if(resultflag1 == E_OK)
        {
          count = 0U;
          while((Fls_17_Pmu_GetStatus() != MEMIF_IDLE) && (count < Time_s(1)))
          {
            /* Wait till Job is finished */
            count++;
            Fls_lCallMain();
          }
          if( (Fls_17_Pmu_GetStatus() != MEMIF_IDLE) || 
              (Fls_17_Pmu_GetJobResult() != MEMIF_JOB_OK)
            )
          {
            resultflag1 = E_NOT_OK;
            print_f("\n compare data failed at: 0x%x \n",WriteAddr);
          }
#if(FLS_IFX_FEE_USED == STD_ON)
          resultflag2 = Fls_17_Pmu_CompareWordsSync(WriteAddr,
                                   (const uint32*)DataBuffer,(FLS_BUF_SIZE/4));
          if(resultflag2 == E_OK)
          {
            print_f("\nComparing with margin 0 successful\n");
          }
          else
          {
            print_f("\nComparing with margin 0 failed\n");
          }
#endif
        }

        print_f("\nWritten and compared data at: 0x%x \n",WriteAddr);

        if(resultflag1 == E_OK)
        {
          WriteSize -= FLS_BUF_SIZE ;
          WriteAddr += FLS_BUF_SIZE ;
        }
      }    
    }
  }while((WriteSize > 0U) && (resultflag1 == E_OK));

  return(resultflag1);
} 

/*******************************************************************************
** Syntax           : <function syntax>                                       **
**                                                                            **
** Service ID       : None/<Specified>                                        **
**                                                                            **
** Sync/Async       : Synchronous / Asynchronous                              **
**                                                                            **
** Reentrancy       : Non-reentrant / Reentrant                               **
**                                                                            **
** Parameters(in)   : None/<Specified>                                        **
**                                                                            **
** Parameters (out) : None/<Specified>                                        **
**                                                                            **
** Return value     : None/<Specified>                                        **
**                                                                            **
** Description      : <Suitable Description>                                  **
**                                                                            **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fls_lDemoSetup(void)
{
  Std_ReturnType resultflag1;
  #if(FLS_IFX_FEE_USED == STD_ON)
  Std_ReturnType resultflag2;
  uint32 UnerasedWordlineAddressPtr;
  uint8 UnerasedWordlineCountPtr;
  #endif
  volatile uint32 count = 0U;
  
   /* Clear the entire DFlash */
  print_f("\nErasing Flash... Please wait... \n");
  resultflag1 = Fls_17_Pmu_Erase(0U,FLS_TOTAL_SIZE);
  
  if(resultflag1 == E_OK)
  {      	
    #if (FLS_USE_ERASESUSPEND == STD_ON)  
    resultflag1 = Fls_17_Pmu_SuspendErase(0U);
    
    if(resultflag1 == E_OK)
    {
      print_f("\n Suspend Erase Passed");
    }
    else
    {
      print_f("\nSuspend Erase Failed");
    }
    
    while(count <= CALL_CYCLE)
    {
     count++;
    }
    
    resultflag1 = Fls_17_Pmu_ResumeErase(0U);
    if(resultflag1 == E_OK)
    {
      print_f("\n Resume Erase Passed");
    }
    else
    {
      print_f("\n Resume Erase Failed");
    }
    
    count = 0U;
    #endif
    while((Fls_17_Pmu_GetStatus() != MEMIF_IDLE) && (count < Time_s(2U)))
    {
      /* Wait till Erase completed */
      print_f("*");
      count++;
      Fls_lCallMain();
    }
      
    if( (Fls_17_Pmu_GetStatus() != MEMIF_IDLE) || 
        (Fls_17_Pmu_GetJobResult() != MEMIF_JOB_OK)
      )
    {
      resultflag1 = E_NOT_OK;
    }
  }
#if(FLS_IFX_FEE_USED == STD_ON)
  resultflag2 = Fls_17_Pmu_VerifyErase(0U, &UnerasedWordlineAddressPtr, 
                                           &UnerasedWordlineCountPtr);
  if(resultflag2 == E_OK)
  {
    print_f("\nVerify Erase for Sector0: WLAddr: %x , WLCount : %x \n",
                      UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr);
  }
  else
  {
    print_f("\nVerify Erase for Sector0 Failed: WLAddr: %x , WLCount : %x \n",
                         UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr);
  }
  resultflag2 = Fls_17_Pmu_VerifyErase(1U, &UnerasedWordlineAddressPtr, 
                                           &UnerasedWordlineCountPtr);
  if(resultflag2 == E_OK)
  {
    print_f("\nVerify Erase for Sector1: WLAddr: %x , WLCount : %x \n",
                  UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr);
  }
  else
  {
    print_f("\nVerify Erase for Sector1 Failed : WLAddr: %x , WLCount : %x \n",
                          UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr);
  }
#endif  
  return(resultflag1);
}


void Fls_lCallMain(void)
{

  volatile uint32 CallCycleTime;
  CallCycleTime = 0U;
  
  while(CallCycleTime <= CALL_CYCLE)
  {
   CallCycleTime++;
  }

  
  Fls_17_Pmu_MainFunction();
}

#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"

void DemoNotifJobEnd(void)
{
#if(FLS_IFX_FEE_USED == STD_ON)	
  Fls_17_Pmu_Job_Type JobType;
  JobType = Fls_17_Pmu_GetNotifCaller();
  if(JobType == FLS_ERASE)
  {
    print_f("\nNotif for Job End, called for FLS_ERASE\n");
  }
  else if(JobType == FLS_WRITE)
  {
    print_f("\nNotif for Job End, called for FLS_WRITE \n");
  }
  else if(JobType == FLS_READ)
  {
    print_f("\nNotif for Job End, called for FLS_READ \n");
  }
  else if(JobType == FLS_COMPARE)
  {
    print_f("\nNotif for Job End, called for FLS_COMPARE \n");
  }
#else
  print_f("\nNotif for Job End \n");
#endif  

}


void DemoNotifJobError(void)
{

#if(FLS_IFX_FEE_USED == STD_ON)	
  Fls_17_Pmu_Job_Type JobType;
  JobType = Fls_17_Pmu_GetNotifCaller();
  if(JobType == FLS_ERASE)
  {
    print_f("\nNotif for Job Error, called for FLS_ERASE\n");
  }
  else if(JobType == FLS_WRITE)
  {
    print_f("\nNotif for Job Error, called for FLS_WRITE \n");
  }
  else if(JobType == FLS_READ)
  {
    print_f("\nNotif for Job Error, called for FLS_READ \n");
  }
  else if(JobType == FLS_COMPARE)
  {
    print_f("\nNotif for Job Error, called for FLS_COMPARE \n");
  }
  else if(JobType == FLS_CANCEL_JOB)
  {
    print_f("\nNotif for Job Error, called for FLS_CANCEL_JOB \n");
  }
#else
  print_f("\nNotif for Job Error \n");
#endif  
  
}


