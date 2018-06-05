[!/****************************************************************************
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
**  $FILENAME   : CanTrcv_17_6251G_Cfg.c $                                   **
**                                                                           **
**  $CC VERSION : \main\20 $                                                 **
**                                                                           **
**  $DATE       : 2015-01-27 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : CanTrcv configuration generated out of ECU configuration   **
**                 file                                                       **
**                                                                            **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
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
**  FILENAME  : CanTrcv_17_6251G_Cfg.c                                        **
**                                                                            **
**  $CC VERSION : \main\20 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  MODULE DECRIPTION : CanTrcv_17_6251G.bmd                                  **
**                                                                            **
**  VARIANT   : VariantPC                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : CanTrcv configuration generated out of ECU configuration   **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CAN_TransceiverDriver.pdf,Release AS4.0.3  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                                                                            **
    TRACEABILITY :[cover parentID= ASW:1499,ASW:1500,ASW:1501, 
                  ASW:1504, ASW:1507, ASW:1508, ASW:1509, ASW:1512,ASW:1513,
                  ASW:1514,ASW:1516,ASW:1517,ASW:1523,ASW:1524,ASW:1528]
**                                                                            **
*******************************************************************************/
[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('CanTrcv_17_6251G')[1]"!][!//

[!VAR "MaxChannels" = "ecu:get('CanTrcv.MaxChannels')"!][!//
[!VAR "CanTrcvConfigSetName" = "'CanTrcvConfigSet'"!][!//

/*******************************************************************************
**                             Includes                                       **
*******************************************************************************/
/* Include Dio header file */
#include "Dio.h"

/* Include CanTrcv header file */
#include "CanTrcv_17_6251G.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/******************************************************************************
**                      Imported Global Constant Declaration                 **
******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/* Mapping the configuration constant */

#define CANTRCV_17_6251G_START_SEC_CONST_16BIT
#include "MemMap.h"

[!SELECT "node:ref($CanTrcvConfigSetName)/*[1]"!][!//

[!VAR "NumChannel" = "num:i($MaxChannels)"!][!//
[!//
[!VAR "TotalCanTrcvChannels" = "num:i(0)"!][!//
[!LOOP "CanTrcvChannel/*"!][!//
[!VAR "CanTrcvChUsed" = "./CanTrcvChannelUsed"!][!//
[!IF "$CanTrcvChUsed = 'true'"!][!//
[!VAR "TotalCanTrcvChannels" = "num:i($TotalCanTrcvChannels + num:i(1))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

const Dio_ChannelType CanTrcv6251G_kChannel[[!"num:i($TotalCanTrcvChannels)"!]U][3U] = 
{
[!FOR "Id" ="num:i(0)" TO "num:i($TotalCanTrcvChannels - num:i(1))"!][!//
 {
  CANTRCV_17_6251G_DIO_EN_[!"$Id"!],
  CANTRCV_17_6251G_DIO_NSTB_[!"$Id"!],
  CANTRCV_17_6251G_DIO_NERR_[!"$Id"!]
 }[!//
[!IF "$Id < num:i($TotalCanTrcvChannels - num:i(1))"!],[!ENDIF!]
[!ENDFOR!][!//
};

const Dio_PortLevelType  CanTrcv6251G_KCtrlPin[[!"num:i($TotalCanTrcvChannels)"!]U] =
{
[!FOR "Id" ="num:i(0)" TO "num:i($TotalCanTrcvChannels - num:i(1))"!][!//
CANTRCV_17_6251G_INIT_STATE_CTRLPIN_SETTING_[!"$Id"!][!//
[!IF "$Id < num:i($TotalCanTrcvChannels - num:i(1))"!],[!ENDIF!]
[!ENDFOR!][!//
};

#define CANTRCV_17_6251G_STOP_SEC_CONST_16BIT
#include "MemMap.h"

#define CANTRCV_17_6251G_START_SEC_CONST_32BIT
#include "MemMap.h"

const CanTrcv_TrcvModeType CanTrcv6251G_NetworkMode[[!"num:i($TotalCanTrcvChannels)"!]U] = 
{
[!FOR "Id" ="num:i(0)" TO "num:i($TotalCanTrcvChannels - num:i(1))"!][!//
(CanTrcv_TrcvModeType)CANTRCV_17_6251G_INIT_STATE_[!"$Id"!][!//
[!IF "$Id < num:i($TotalCanTrcvChannels - num:i(1))"!],[!ENDIF!]
[!ENDFOR!][!//
};

#define CANTRCV_17_6251G_STOP_SEC_CONST_32BIT
#include "MemMap.h"

#define CANTRCV_17_6251G_START_SEC_CONST_8BIT
#include "MemMap.h"


[!IF "CanTrcvGeneral/CanTrcvWakeUpSupport != 'CANTRCV_WAKEUP_NOT_SUPPORTED'"!][!//
[!VAR "l" = "0"!][!//
const uint8 CanTrcv_kWakeupFlag[[!"num:i($TotalCanTrcvChannels)"!]U] = 
{
[!FOR "Id" ="num:i(0)" TO "num:i($TotalCanTrcvChannels - num:i(1))"!][!//
(uint8)CANTRCV_17_6251G_WAKEUP_BY_BUS_USED_[!"$Id"!][!//
[!IF "$Id < num:i($TotalCanTrcvChannels - num:i(1))"!],[!ENDIF!]
[!ENDFOR!][!//
};
[!ENDIF!][!//

[!IF "CanTrcvGeneral/CanTrcvWakeUpSupport != 'CANTRCV_WAKEUP_NOT_SUPPORTED'"!][!//
[!VAR "l" = "0"!][!//
const uint8 CanTrcv_kWakeupSourceRef[[!"num:i($TotalCanTrcvChannels)"!]U] = 
{
[!FOR "Id" ="num:i(0)" TO "num:i($TotalCanTrcvChannels - num:i(1))"!][!//
(uint8)CANTRCV_17_6251G_WAKEUP_SOURCE_REF_[!"$Id"!][!//
[!IF "$Id < num:i($TotalCanTrcvChannels - num:i(1))"!],[!ENDIF!]
[!ENDFOR!][!//
};
[!ENDIF!][!//

[!ENDSELECT!][!//
[!//
#define CANTRCV_17_6251G_STOP_SEC_CONST_8BIT
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
[!ENDSELECT!]