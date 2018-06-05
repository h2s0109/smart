[!/*****************************************************************************
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
**   $FILENAME   : Smu_Cfg.h $                                                **
**                                                                            **
**   $CC VERSION : \main\10 $                                                 **
**                                                                            **
**   $DATE       : 2014-04-21 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : SafeTlib                                                      **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  TRACEABILITY: [cover parentID=]                                           **
**                                                                            **
**  DESCRIPTION  : Code template for Smu_Cfg.h file                           **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/!][!//

[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  :  Smu_Cfg.h                                                   **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd /xdm                                      **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / HighTec /WindRiver                                  **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SMU configuration header file                             **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SMU_CFG_H
#define SMU_CFG_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Smu.h"
[!NOCODE!]
[!INCLUDE "Smu.m"!][!//
[!ENDNOCODE!]
/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!SELECT "as:modconf('Smu')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(SmuConfigSet/*))"!][!//
[!FOR "SmuId" ="num:i(1)" TO "(num:i($TotalConfig))"!][!//
[!SELECT "SmuConfigSet/*[num:i($SmuId)]"!][!//
#define [!"node:name(.)"!]         ((uint8)[!"@index"!])
[!ENDSELECT!][!//
[!ENDFOR!][!//

/* Timeout value for function blocking spinlock */ 
#define SMU_SPINLOCK_TIMEOUT    ((uint32)([!"num:i(SmuSpinlockTimeout/SpinlockTimeout)"!]U))

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
[!ENDSELECT!][!//
#endif  /* SMU_CFG_H */
[!AUTOSPACING!]
