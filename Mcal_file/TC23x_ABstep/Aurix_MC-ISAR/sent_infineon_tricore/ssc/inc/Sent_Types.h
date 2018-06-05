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
**  $FILENAME   : Sent_Types.h $                                             **
**                                                                           **
**  $CC VERSION : \main\8 $                                                  **
**                                                                           **
**  $DATE       : 2015-11-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - typedefs required for SENT Module.                      **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
#ifndef SENT_TYPES_H
#define SENT_TYPES_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Value for ACCEN types */
#define SENT_ACCEN_DEFAULT        0U
#define SENT_ACCEN_INIT           1U
#define SENT_ACCEN_API            2U

/* SRN to SENT logical channel not mapped */
#define SENT_CHANNEL_NOT_MAPPED   255U

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* Type definition for Channel Ids */
typedef uint8 Sent_ChannelIdxType;

/* Type definition for SENT Event/s to be notified */
typedef uint32 Sent_NotifType;

/* Type definition for Channel enable/disable operations */
typedef enum
{
  SENT_DISABLE        = 0x00U,
  SENT_ENABLE         = 0x01U,
}Sent_ChanOpType;

/* Type definition for SENT Application notification function pointer */
typedef void (*Sent_NotifFnPtrType) (Sent_ChannelIdxType ChannelId, 
                                                      Sent_NotifType Stat);

/*
  Structure definition for a SENT channel configuration
*/
typedef struct _Sent_ChannelCfgType
{
  /* SENT_RCRx register value */
  uint32          ChanRxCtrl;
  /* SENT_IOCRx register value */  
  uint32          ChanIOCtrl;
  /* SENT_VIEWx register value */  
  uint32          ChanDataView;
  /* SENT_CPDRx register value */  
  uint16          ChanPreDiv;  
  /* SENT_CFDRx register value */  
  uint16          ChanFracDiv;
  /* Frame length */  
  uint8           ChanFrameLen;
  /* Interrupt node configured for the channel */
  uint8           ChanIntNode;      
  /* Physical Channel Id */  
  Sent_ChannelIdxType  ChannelId;
}Sent_ChannelCfgType;


/*
  Structure definition for SENT configuration
*/
typedef struct Sent_ConfigType
{
  /* Pointer to Channel configuration */
  const Sent_ChannelCfgType *ChanCfgPtr;
  /* SRN mapping to SENT logical channels */
  const uint8               *SrnToChanMapPtr;
  /* Module clock divider */
  uint32                    ModuleClkDiv;
  /* ACCEN0 access value */
  uint32                    AccenRegVal;  
  /* Module Fractional step divider */
  uint16                    ModuleFracDivStep;  
  /* Number of SENT channels configured */
  uint8                     NumChannelsConfigured;
}Sent_ConfigType;

/* Structure definition to receive serial data */
typedef struct _Sent_RxSerialDataType
{
  /* 16-bit serial data */
  uint16    Data;
  /* 4/8-bit Message Id */
  uint8     MsgId;
  /* CRC of the serial data */
  uint8     Crc;
  /* Configuration bit */
  uint8     Configuration;
}Sent_RxSerialDataType;

/* Enumeration to depict Channel state */
typedef enum
{
  SENT_STOP = 0x00U,
  SENT_INITIALIZED,
  SENT_RUNNING,
  SENT_SYNCHRONIZED
}Sent_ChanStateType;

/* Structure definition for Channel Status */
typedef struct _Sent_ChanStatusType
{
  /* Channel state */
  Sent_ChanStateType  ChanStat;
  /* Timestamp of the last received SENT frame */
  uint32              RxTimeStamp;
  /* Interrupt Status bitmap */
  uint32              IntStat;
  /* CRC of the last received SENT frame */
  uint8               RxCrc;
  /* Status and Comm Nibble of the last received SENT frame */
  uint8               StatCommNibble;
}Sent_ChanStatusType;

#endif /* SENT_TYPES_H */
