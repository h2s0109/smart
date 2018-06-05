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
**  $FILENAME   : Sent_Callout.c $                                           **
**                                                                           **
**  $CC VERSION : \main\6 $                                                  **
**                                                                           **
**  $DATE       : 2014-03-12 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : Implementation of SENT interface callout functions for     **
**                notifications of SENT channel's events or errors           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                     **
**                                                                           **
******************************************************************************/

#include "Sent_Callout.h"
#include "Sent_Demo.h"

/* Call-out function for Channel 0 */
void Sent_Callout_Chan0 (Sent_ChannelIdxType ChannelId, Sent_NotifType Stat)
{
  Sent_DemoAppCbk(ChannelId, (uint32) Stat);
}

/* Call-out function for Channel 1 */
void Sent_Callout_Chan1 (Sent_ChannelIdxType ChannelId, Sent_NotifType Stat)
{
  Sent_DemoAppCbk(ChannelId, (uint32) Stat);
}


