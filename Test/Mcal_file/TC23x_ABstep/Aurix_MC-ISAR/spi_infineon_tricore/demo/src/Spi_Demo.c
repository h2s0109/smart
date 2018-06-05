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
**  $FILENAME   : Spi_Demo.c $                                               **
**                                                                           **
**  $CC VERSION : \main\15 $                                                 **
**                                                                           **
**  $DATE       : 2013-10-28 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                - sample Demo Test for  SPI module                         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Std_Types.h"
#include "Mcal.h"
#include "Test_Print.h"
#include "Test_Time.h"
#include "Test_Main.h"
#include "Spi.h"
#include "Spi_Demo.h"
#include "DemoApp_Cfg.h"

/*******************************************************************************
**                      Private Variable Declarations                         **
*******************************************************************************/
#define SPI_EEPROM_DEMO (STD_ON)
#define SPI_LOOPBACK_DEMO (STD_OFF)

#if (SPI_EEPROM_DEMO == STD_ON)
/* define commands for eeprom */
#define EEP_CMD_WREN    0x06
#define EEP_CMD_WRDI    0x04
#define EEP_CMD_RDSR    0x05
#define EEP_CMD_WRSR    0x01
#define EEP_CMD_READ    0x03
#define EEP_CMD_WRITE   0x02

/* define status bits for eeprom */
#define EEP_STAT_PEN    0x80
#define EEP_STAT_BP1    0x08
#define EEP_STAT_BP0    0x04
#define EEP_STAT_WEN    0x02
#define EEP_STAT_NOT_RDY 0x01

#define LEVEL2_ASYNC_MODE_POLLING (0U) /* disable polling */

static uint8 cmdReadSR  = EEP_CMD_RDSR;
static uint8 cmdRead    = EEP_CMD_READ;
static uint8 cmdWrite   = EEP_CMD_WRITE;
static uint8 cmdWriteEn = EEP_CMD_WREN;

#define EEP_TESTDATA_LENGTH 24

const Spi_DataType EepTestWriteData[EEP_TESTDATA_LENGTH] =
{
/*  'D','L','-','A','U','T','O','S',
  'A','R','-','E','N','G','I','N',
  'E','E','R','I','N','G',0x00,0x00
*/
'I','N','F','I','N','E','O','N',
'-','T','E','C','H','N','L','O',
'G','I','E','S',0x00,0x00,0x00,0x00
};

Spi_DataType EepTestWriteUserData[16];

#ifdef _TASKING_C_TRICORE_
#pragma align 4
#endif

Spi_DataType  EepTestAddress[2];
Spi_DataType  EepTestReadByte;
volatile Spi_DataType EepTestSeqFlag;
volatile uint8 EepWriteProtectEn;

#ifdef _TASKING_C_TRICORE_
#pragma align restore
#endif

volatile Spi_DataType SpiSourceData[24] =
{
'S','S','C','-','T','R','A','N',
'S','F','E','R','-','C','O','M',
'P','L','E','T','E','D',0x00,0x00
};

volatile Spi_DataType SpiDestinationData[24] =
{
'S','S','C','-','T','R','A','N',
'S','F','E','R','-','F','A','I',
'L',0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
void Spi_EepromAccessDemo(void);
void EepTest_WriteByte(Spi_DataType* address, Spi_DataType* data);
Spi_DataType EepTest_ReadByte(const Spi_DataType* address);
void Spi_EepWriteProtectEnable(void);

#if (SPI_LEVEL_DELIVERED == 2U)
void Spi_Task(void);
#endif

extern void EepTest_EndOfCmdSeq(void);

/* Notification Function of Sequence: SpiConf_SpiSequence_EEP_SEQ_STAT */
extern void EepTest_EndOfStatSeq(void);

/* Notification Function of Sequence: SpiConf_SpiSequence_EEP_SEQ_DATA */
extern void EepTest_EndOfDataSeq(void);

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  uint8 Temp_Read[20];
#endif
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (SPI_EEPROM_DEMO == STD_ON)
/*******************************************************************************
** Syntax : void Spi_EepromAccessDemo(void)                                   **
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
** Description : Writes and Reads data from EEPROM asynchromously using QSPIx **
*******************************************************************************/
void Spi_EepromAccessDemo(void)
{
  uint8 it;
  Spi_DataType ch;

  print_f("------ Start of EEPROM access demo using SPI ------\n");
#if (SPI_LEVEL_DELIVERED == 0U)
  print_f("==> Sync Transmit , Spi Level Delivered 0,  ");
#endif
#if (SPI_LEVEL_DELIVERED == 1U)
  print_f("==> Async Transmit , Spi Level Delivered 1, ");
#endif
#if (SPI_LEVEL_DELIVERED == 2U)
  print_f("==> Async Transmit/s , Spi Level Delivered 2,  ");
#endif

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
print_f("SpiChannelBuffersAllowed EB  \n");
#endif

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
print_f("SpiChannelBuffersAllowed IB  \n");
#endif

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 2U)
print_f("SpiChannelBuffersAllowed EB & IB  \n");
#endif

#if (SPI_LEVEL_DELIVERED == 2U)
#if (LEVEL2_ASYNC_MODE_POLLING == 1U)
print_f("==> Switch to Polling Mode. \n");
/* For polling mode, Do call Spi_MainFunction_Handling in a task  */
Spi_SetAsyncMode(SPI_POLLING_MODE); /* if not set giving error TBD */
Test_Time_SetAlarm(0, 1, 0x100, Spi_Task);
#else
print_f("==> Switch to Interrupt Mode. \n");
Spi_SetAsyncMode(SPI_INTERRUPT_MODE);
#endif
#endif

  EepTestAddress[0] = 0x00; /*msb*/
  /* write enable */
  EepTestSeqFlag = 1;

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWriteEn,NULL_PTR,1);
#elif (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_WriteIB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWriteEn);
#else
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWriteEn,NULL_PTR,1);

#endif

#if (SPI_LEVEL_DELIVERED != 0U)
  Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_CMD);

  while(EepTestSeqFlag == 1)
  {
    if(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_CMD) == SPI_SEQ_FAILED)
    {
      print_f("WR EN cmd SEQ Failed\n");
      return;
    }
  }
#else
  Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_CMD);
  while(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_CMD) != SPI_SEQ_OK)
  {
    if(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_CMD) == SPI_SEQ_FAILED)
    {
      print_f("WR EN cmd SEQ Failed\n");
      return;
    }
  }
#endif
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_ReadIB(SpiConf_SpiChannel_EEP_CMD_CH, Temp_Read);
#endif

/************ read status register ***************/
  EepTestSeqFlag = 1;
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdReadSR, NULL_PTR,1);
  Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, NULL_PTR,
                                           (Spi_DataType *)&EepTestReadByte, 1);
#elif (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  /* Read status */
  Spi_WriteIB(SpiConf_SpiChannel_EEP_CMD_CH,
              (uint8 *)&cmdReadSR
              );

  Spi_WriteIB(SpiConf_SpiChannel_EEP_DATA_CH,
              (uint8 *)NULL_PTR
              );

#else
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdReadSR, NULL_PTR,1);
  Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, NULL_PTR,
                                           (Spi_DataType *)&EepTestReadByte, 1);
#endif

#if (SPI_LEVEL_DELIVERED != 0U)
  Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_STAT);
  while(EepTestSeqFlag == 1)
  {
    if(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_STAT)== SPI_SEQ_FAILED)
    {
      print_f("SEQ to get read status Failed\n");
      return;
    }
  };
#else
  Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_STAT);
  while(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_STAT) != SPI_SEQ_OK)
  {
    if(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_STAT)== SPI_SEQ_FAILED)
    {
      print_f("SEQ to get read status Failed\n");
      return;
    }
  }
#endif
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_ReadIB(SpiConf_SpiChannel_EEP_CMD_CH, Temp_Read);
  Spi_ReadIB(SpiConf_SpiChannel_EEP_DATA_CH, &EepTestReadByte);
#endif

  print_f("Status register value: %x\n",EepTestReadByte);

  for (it=0;it<16;it++) {
    EepTestWriteUserData[it] = '\0';
  }

  print_f("Enter the Data to be written (Maximum 15 Characters) : \n");
  getline((char *)EepTestWriteUserData, sizeof EepTestWriteUserData );
  print_f("\n\n");

  print_f ("Written data: ");
 /***************** Writes the data entered by the user ************/
  for (it=0;it<16;it++) {
    EepTestAddress[1] = it; /* lsb. */
    EepTest_WriteByte(EepTestAddress,(Spi_DataType *)&EepTestWriteUserData[it]);
    put_char(EepTestWriteUserData[it]);
  }

  print_f ("\nRead data: ");

  /******************* Read back the data from EEPROM *****************/
  for (it=0;it<16;it++) {
    EepTestAddress[1] = it; /* lsb. */
    ch = EepTest_ReadByte(EepTestAddress);
    put_char(ch);
  }

  put_char('\n');


  print_f("------ End of EEPROM access demo using SPI ------\n");
}

/*******************************************************************************
** Syntax : void  EepTest_WriteByte(Spi_DataType* address, Spi_DataType* data)**
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
** Description : Writes each byte on to EEPROM           .                    **
*******************************************************************************/
void  EepTest_WriteByte(Spi_DataType* address, Spi_DataType* data)
{
    /* write enable */
    EepTestSeqFlag = 1;
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
    Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWriteEn,NULL_PTR,1);
#elif (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_WriteIB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWriteEn);
#else
    Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWriteEn,NULL_PTR,1);

#endif

#if (SPI_LEVEL_DELIVERED != 0U)
    Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_CMD);
    while(EepTestSeqFlag == 1);
#else
    Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_CMD);
    while(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_CMD) != SPI_SEQ_OK)
    {}
#endif
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_ReadIB(SpiConf_SpiChannel_EEP_CMD_CH, Temp_Read);
#endif

    /* start write */
    EepTestSeqFlag = 1;

#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
    Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWrite, NULL_PTR,1);
#ifdef EEP_16_ADDRESS
    /* the length = 2 works. Although it is configured to be 16 bit.
    Shall it be only 1? */
    Spi_SetupEB(SpiConf_SpiChannel_EEP_ADDR_CH, address, NULL_PTR, 2);
#else
    Spi_SetupEB(SpiConf_SpiChannel_EEP_ADDR_CH, address, NULL_PTR, 2);
#endif
    Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, data, NULL_PTR, 1);

#elif (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_WriteIB(SpiConf_SpiChannel_EEP_CMD_CH,
              (uint8 *)&cmdWrite
              );

  Spi_WriteIB(SpiConf_SpiChannel_EEP_ADDR_CH,
              (uint8 *)address
              );
  Spi_WriteIB(SpiConf_SpiChannel_EEP_DATA_CH,
              (uint8 *)data
              );

#else
    Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdWrite, NULL_PTR,1);
    Spi_SetupEB(SpiConf_SpiChannel_EEP_ADDR_CH, address, NULL_PTR, 2);
    Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, data, NULL_PTR, 1);

#endif
#if (SPI_LEVEL_DELIVERED != 0U)
    Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_DATA);
    while(EepTestSeqFlag == 1);
#else
    Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_DATA);
    while(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_DATA) != SPI_SEQ_OK)
    {}
#endif
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_ReadIB(SpiConf_SpiChannel_EEP_CMD_CH, Temp_Read);
  Spi_ReadIB(SpiConf_SpiChannel_EEP_ADDR_CH, Temp_Read);
  Spi_ReadIB(SpiConf_SpiChannel_EEP_DATA_CH, Temp_Read);
#endif

    /* check status register */
    do {
      EepTestSeqFlag = 1;
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
      Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdReadSR, NULL_PTR,1);
      Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, NULL_PTR,
                                           (Spi_DataType *)&EepTestReadByte, 1);
#elif (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_WriteIB(SpiConf_SpiChannel_EEP_CMD_CH,
              (uint8 *)&cmdReadSR
              );

  Spi_WriteIB(SpiConf_SpiChannel_EEP_DATA_CH,
              (uint8 *)NULL_PTR
              );
#else
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdReadSR, NULL_PTR,1);
  Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, NULL_PTR,
                                           (Spi_DataType *)&EepTestReadByte, 1);
#endif

#if (SPI_LEVEL_DELIVERED != 0U)
      Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_STAT);
      while(EepTestSeqFlag == 1);
#else
      Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_STAT);
      while(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_STAT)!= SPI_SEQ_OK)
      {}
#endif
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_ReadIB(SpiConf_SpiChannel_EEP_CMD_CH, Temp_Read);
  Spi_ReadIB(SpiConf_SpiChannel_EEP_DATA_CH, &EepTestReadByte);
#endif

    } while(EepTestReadByte & EEP_STAT_NOT_RDY);
}

/*******************************************************************************
** Syntax : Spi_DataType EepTest_ReadByte(const Spi_DataType* address)        **
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
** Description : Reads data from EEPROM                  .                    **
*******************************************************************************/
Spi_DataType EepTest_ReadByte(const Spi_DataType* address)
{                

    /* start read */
    EepTestSeqFlag = 1;
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 1U)
    Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdRead, NULL_PTR,1);
#ifdef EEP_16_ADDRESS
    Spi_SetupEB(SpiConf_SpiChannel_EEP_ADDR_CH, address, NULL_PTR, 2);
#else
    Spi_SetupEB(SpiConf_SpiChannel_EEP_ADDR_CH, address, NULL_PTR, 2);
#endif
    Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, NULL_PTR,
                                           (Spi_DataType *)&EepTestReadByte, 1);
#elif (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_WriteIB(SpiConf_SpiChannel_EEP_CMD_CH,
              (uint8 *)&cmdRead
              );

  Spi_WriteIB(SpiConf_SpiChannel_EEP_ADDR_CH,
              (uint8 *)address
              );
  Spi_WriteIB(SpiConf_SpiChannel_EEP_DATA_CH,
              (uint8 *)Temp_Read /* dummy data */
              );
#else
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH,&cmdRead, NULL_PTR,1);
    Spi_SetupEB(SpiConf_SpiChannel_EEP_ADDR_CH, address, NULL_PTR, 2);
  Spi_SetupEB(SpiConf_SpiChannel_EEP_DATA_CH, NULL_PTR,
                                           (Spi_DataType *)&EepTestReadByte, 1);
#endif

#if (SPI_LEVEL_DELIVERED != 0U)
    Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_DATA);
    while(EepTestSeqFlag == 1);
#else
    Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_DATA);
  while(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_DATA) != SPI_SEQ_OK)
  {}
#endif
#if (SPI_CHANNEL_BUFFERS_ALLOWED == 0U)
  Spi_ReadIB(SpiConf_SpiChannel_EEP_CMD_CH, Temp_Read);
  Spi_ReadIB(SpiConf_SpiChannel_EEP_ADDR_CH, Temp_Read);
  Spi_ReadIB(SpiConf_SpiChannel_EEP_DATA_CH, &EepTestReadByte);
#endif
    return EepTestReadByte;
}



/* Notification functions */
void EepTest_EndOfCmdSeq(void)
{
  EepTestSeqFlag = 0;
/*  print_f("CmdSeqEnd\n");        */
}

void EepTest_EndOfStatSeq(void)
{
  EepTestSeqFlag = 0;
/*  print_f("StatSeqEnd\n"); */
}

void EepTest_EndOfDataSeq(void)
{
  EepTestSeqFlag = 0;
/*  print_f("DataSeqEnd\n"); */
}

#if (SPI_LEVEL_DELIVERED == 2)
volatile uint8 calledstatus = 0;
void Spi_Task(void)
{
   if(calledstatus == 0)
   {
   calledstatus = 1;
   Spi_MainFunction_Handling();
   calledstatus =0;
   }
   Test_Time_SetAlarm(0, 1, 0x200, Spi_Task);
}
#endif

#endif


#if (SPI_LOOPBACK_DEMO == STD_ON)

Spi_DataType SendData[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
                            0x99, 0xaa, 0xbb,0xcc,0xdd,0xee, 0x00}, RecData[16];
volatile uint8 seqcompleted;

/* Notification functions */
void EndOfSeqNotifCallback(void)
{
  seqcompleted = 0;
}
void EndOfJobNotifCallback(void)
{
  seqcompleted = 0;
}
void EepTest_EndOfCmdSeq(void)
{
  seqcompleted = 0;
  if(Spi_GetSequenceResult(SpiConf_SpiSequence_EEP_SEQ_CMD) == SPI_SEQ_FAILED)
  {
    print_f("\n SEQ Failed....\n");

  }
}
void EepTest_EndOfStatSeq(void)
{
}

void EepTest_EndOfDataSeq(void)
{
}

void Spi_EepromAccessDemo(void)
{
  uint8 i;

  print_f("------ Start of Sample demo using SPI in loop back mode------\n");

  seqcompleted = 1;
  Spi_SetupEB(SpiConf_SpiChannel_EEP_CMD_CH, SendData, RecData, 10);
#if (SPI_LEVEL_DELIVERED == 0U)
  Spi_SyncTransmit(SpiConf_SpiSequence_EEP_SEQ_CMD);
#else
  Spi_AsyncTransmit(SpiConf_SpiSequence_EEP_SEQ_CMD);
#endif

#if (SPI_LEVEL_DELIVERED != 0U)
  while(seqcompleted == 1);
#endif

  print_f ("Sent data on Spi bus: ");
  for (i=0;i<10;i++)
  {
    print_f("%x  ", SendData[i]);
  }

  put_char('\n');

  print_f ("Data received on Spi bus: ");
  for (i=0;i<10;i++)
  {
    print_f("%x  ", RecData[i]);
  }

  put_char('\n');

  print_f("------ End of Sample demo using SPI ------\n");

}

#endif
