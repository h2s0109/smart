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
**  $FILENAME   : Fee_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\10 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-07 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains sample Demo Test for FEE module        **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Fee.h"
#include "Fee_Demo.h"
#include "Test_Print.h"

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

#define FEE_BLK_1      (1U)
#define FEE_BLK1_SIZE  (20U)

#define FEE_BLK_2      (2U)
#define FEE_BLK2_SIZE  (12U)

#define FEE_BUF_SIZE   (25U)

#define Time_s(num) (num*60*1000000)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
void Fee_lFillWriteBuf_Seed( uint16 BlkSize,
                                    uint8 seed,
                                    boolean print
                                  );
                                  
void Fee_lFillWriteBuf_Const( uint16 BlkSize, 
                                     uint8 val,
                                     boolean print
                                   );
                                   
IFX_INLINE Std_ReturnType Fee_lDemoRead( 
                                     uint16 BlockNumber, 
                                     uint16 Length  
                                   );

IFX_INLINE Std_ReturnType Fee_lDemoWrite(uint16 BlockNumber);

IFX_INLINE Std_ReturnType Fee_lComp(uint16 BlkSize);

IFX_INLINE Std_ReturnType Fee_lDemoSetup(void);


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
static boolean Fee_DemoCheckStatus;
static uint8 Fee_DemoCalled;
static uint8 WriteDataBuffer[FEE_BUF_SIZE];
static uint8 ReadDataBuffer[FEE_BUF_SIZE];

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Syntax           : void Fee_Demo(void)                                     **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Write/Read of blocks with desired data                  **
**                                                                            **
*******************************************************************************/

/* 1. Write Blk1 with 12341 data
   2. Write Blk2 with AAAAA data
   3. Write Blk1 with ABCDA data
   4. Write Blk2 with 66666 data
   5. Check if Blk1 has ABCDA data
   6. Check if Blk2 has 66666 data
*/

void Fee_Demo(void)
{
  Std_ReturnType resultflag;    

  Fee_DemoCheckStatus = FALSE;
  resultflag = E_OK;
  
  print_f("\n---------------  Start of FEE driver demo ---------------\n");
  
  if(Fee_DemoCalled == 0U)
  {
    /* Clear the DFlash to start the FEE Demo */
    resultflag = Fee_lDemoSetup();
    Fee_DemoCalled = 1U;
  }
  
  if(resultflag == E_OK)
  {  
    print_f("\n1.Write Blk1 with data :  \n");     

    /* Fill the buffer with 0xA,0xB,0xC,0xD,0xA,0xB... */
    /* 1. Write Blk1 with 12341 data */
    Fee_lFillWriteBuf_Seed(FEE_BLK1_SIZE,1,TRUE);
    resultflag = Fee_lDemoWrite(FEE_BLK_1);
    if( resultflag == E_OK)
    {
      print_f("\n2.Write Blk2 with data : \n");             
      /* 2. Write Blk2 with AAAAA data */
      Fee_lFillWriteBuf_Const(FEE_BLK2_SIZE,0xA,TRUE);
      resultflag = Fee_lDemoWrite(FEE_BLK_2);
      if(resultflag == E_OK)
      {
        print_f("\n3.Write Blk1 with data : \n");         
        /* 3. Write Blk1 with ABCDA data */
        Fee_lFillWriteBuf_Seed(FEE_BLK1_SIZE,0xA,TRUE);
        resultflag = Fee_lDemoWrite(FEE_BLK_1);
        if(resultflag == E_OK)
        {
          print_f("\n4.Write Blk2 with data : \n");           
          /* 4. Write Blk2 with 99999 data */
          Fee_lFillWriteBuf_Const(FEE_BLK2_SIZE,0x9,TRUE);
          resultflag = Fee_lDemoWrite(FEE_BLK_2);
          if(resultflag == E_OK)
          {
            print_f("\n5.Reading Blk1 data : \n");                     
            /* 5. Check if Blk1 has ABCDA data */
            Fee_lFillWriteBuf_Seed(FEE_BLK1_SIZE,0xA,FALSE);
            resultflag = Fee_lDemoRead(FEE_BLK_1,FEE_BLK1_SIZE);
            if(resultflag == E_OK)
            {
              resultflag = Fee_lComp(FEE_BLK1_SIZE);
              if(resultflag == E_OK)
              {
                print_f("\n6.Reading Blk2 data : \n");                                 
                /* 6. Check if Blk2 has 99999 data */
                Fee_lFillWriteBuf_Const(FEE_BLK2_SIZE,0x9,FALSE);
                resultflag = Fee_lDemoRead(FEE_BLK_2,FEE_BLK2_SIZE);
                if(resultflag == E_OK)
                {
                  resultflag = Fee_lComp(FEE_BLK2_SIZE);
                  if(resultflag == E_OK)
                  {
                     print_f("\n\n      FEE driver demo result: PASSED \n");
                     
                  }/*end of compare */                
                }/*end of step6 */  
              }/*end of compare */  
            }/*end of step5 */  
          }/*end of step4 */
        }/*end of step3 */
      }/*end of step2 */
    }/*end of step1 */
  }/*end of Setup */

  if( resultflag != E_OK)
  {  
    print_f("\n\n      FEE driver demo result: FAILED \n");
  }

  print_f("\n---------------  End of FEE driver demo ---------------\n");

}

/*******************************************************************************
** Syntax           : void Fee_lFillWriteBuf_Seed                             **
**                    (                                                       **
**                        uint16 BlkSize, uint8 seed, boolean print           **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : BlkSize : Size of the block                             **
**                    Seed    : Starting value to be written                  **
**                    print   : Enable/Disable printing of data being written **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function fills the buffer with data starting with  **
**                    value 'seed' and then keeps incrementing the same       **
**                                                                            **
*******************************************************************************/
void Fee_lFillWriteBuf_Seed(uint16 BlkSize, uint8 seed, boolean print)
{
  uint16 i=0;

  i=0;
  do
  {
    if(i < BlkSize)
    {
        WriteDataBuffer[i] = (i%4) + seed;
        if(print)
        {
          print_f(" %x ",WriteDataBuffer[i]);          
        }
    }
    else
    {
      WriteDataBuffer[i] = 0;
    }
    i++;      
  }while(i < FEE_BUF_SIZE);

}

/*******************************************************************************
** Syntax           : void Fee_lFillWriteBuf_Const                            **
**                    (                                                       **
**                        uint16 BlkSize, uint8 val, boolean print            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : BlkSize : Size of the block                             **
**                    val    : value to be written                            **
**                    print   : Enable/Disable printing of data being written **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function fills the buffer with data 'val'          **
*******************************************************************************/

void Fee_lFillWriteBuf_Const(uint16 BlkSize, uint8 val,boolean print)
{
  uint16 i=0;

  i=0;
  do
  {
    if(i < BlkSize)
    {
        WriteDataBuffer[i] = val;
        if(print)
        {
          print_f(" %x ",WriteDataBuffer[i]);          
        }
    }
    else
    {
      WriteDataBuffer[i] = 0;
    }
    i++;
  }while(i < FEE_BUF_SIZE);

}

/*******************************************************************************
** Syntax           : IFX_INLINE Std_ReturnType Fee_lDemoRead                 **
**                    (                                                       **
**                        uint16 BlockNumber, uint16 Length                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : BlockNumber : Number of the block                       **
**                    Length      : Number of bytes to be read                **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Return status of the Read operation                     **
**                                                                            **
** Description      : This reads the required number of bytes                 **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fee_lDemoRead( uint16 BlockNumber, 
                                       uint16 Length)
{ 
  uint16 i;
  Std_ReturnType resultflag;
  volatile uint32 count;                 
  resultflag = Fee_Read(BlockNumber,0,ReadDataBuffer,Length);
  if(resultflag == E_OK)
  {
    while(Fee_DemoCheckStatus != TRUE) 
    {
      /* Wait till Fee_DemoCheckStatus is Set Nvm_JobEndNotification or 
         Nvm_JobErrorNotification */
      count++;
      Fee_MainFunction();
      Fls_17_Pmu_MainFunction();
      
    }
      
    if( (Fee_GetStatus() != MEMIF_IDLE) || 
        (Fee_GetJobResult() != MEMIF_JOB_OK)
      )
    {
      resultflag = E_NOT_OK;
    }
    
    for(i=0; i<Length; i++)
    {
      print_f(" %x ",ReadDataBuffer[i]);
    }
    
    Fee_DemoCheckStatus = FALSE;
  }
  return(resultflag);
} 

/*******************************************************************************
** Syntax           : IFX_INLINE Std_ReturnType Fee_lDemoWrite                **
**                    (                                                       **
**                        uint16 BlockNumber                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : BlockNumber : Number of the block                       **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Return status of the Write operation                    **
**                                                                            **
** Description      : This writes the specified block                         **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fee_lDemoWrite( uint16 BlockNumber)
{ 
  Std_ReturnType resultflag;
  volatile uint32 count;
                   
  resultflag = Fee_Write(BlockNumber,WriteDataBuffer);
  if(resultflag == E_OK)
  {
    while(Fee_DemoCheckStatus != TRUE) 
    {
      /* Wait till Fee_DemoCheckStatus is Set Nvm_JobEndNotification or 
         Nvm_JobErrorNotification */
      count++;
      Fee_MainFunction();
      Fls_17_Pmu_MainFunction();
    }
      
    if( 
        (Fee_GetJobResult() != MEMIF_JOB_OK)
      )
    {
      resultflag = E_NOT_OK;
    }
    
    Fee_DemoCheckStatus = FALSE;
  }
  return(resultflag);
  
} 

/*******************************************************************************
** Syntax           : IFX_INLINE Std_ReturnType Fee_lComp                     **
**                    (                                                       **
**                        uint16 BlkSize                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : BlkSize : Number of the bytes to be compared            **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Return status of the Compare operation                  **
**                                                                            **
** Description      : This function compares the read data with expected data **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fee_lComp(uint16 BlkSize)
{
  uint16 i;
  Std_ReturnType retval;
  
  retval = E_OK;
  
  for(i=0;i<BlkSize;i++)
  {
    if(WriteDataBuffer[i] != ReadDataBuffer[i])
    {
      retval = E_NOT_OK;
    }
  }
  return(retval);
}
/*******************************************************************************
** Syntax           : void NvM_JobEndNotification (void)                      **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function marks the completion of the requested     **
**                     operation                                              **
*******************************************************************************/
void NvM_JobEndNotification (void)
{
    Fee_DemoCheckStatus = TRUE;
}
/*******************************************************************************
** Syntax           : void NvM_JobErrorNotification (void)                    **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function marks the completion of the requested     **
**                     operation(failure)                                     **
*******************************************************************************/
void NvM_JobErrorNotification (void)
{
  Fee_DemoCheckStatus = TRUE;
}

/*******************************************************************************
** Syntax           : void NvM_IllegalStateNotification (void)                **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : This function indicates that the FEE has reached an     **
**                     illegal state                                          **
*******************************************************************************/
void NvM_IllegalStateNotification (void)
{
  Fee_DemoCheckStatus = TRUE;
  print_f("\nIllegal state notification function called: ");
  print_f("FEE reached illegal state");
}

/*******************************************************************************
** Syntax           : IFX_INLINE Std_ReturnType Fee_lDemoSetup(void)          **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-reentrant                                           **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : Return status of the erasing of DFLASH                  **
**                                                                            **
** Description      : This function erases the DFLASH allowing for the start  **
**                    of the demo                                             **
*******************************************************************************/
IFX_INLINE Std_ReturnType Fee_lDemoSetup(void)
{
  Std_ReturnType resultflag;
   
  
   /* Clear the entire DFlash */
  resultflag = Fls_17_Pmu_Erase(0,FLS_TOTAL_SIZE);
  
  if(resultflag == E_OK)
  {
    while(Fls_17_Pmu_GetStatus() != MEMIF_IDLE)
    {
      /* Wait till Flash is erased */      
      Fls_17_Pmu_MainFunction();
    }
      
    Fee_DemoCheckStatus = FALSE;
  }
  
  Fee_Init();
  
  while(Fee_GetStatus() != MEMIF_IDLE)
  {
      Fee_MainFunction();
      Fls_17_Pmu_MainFunction();
  }
  return(resultflag);
}
