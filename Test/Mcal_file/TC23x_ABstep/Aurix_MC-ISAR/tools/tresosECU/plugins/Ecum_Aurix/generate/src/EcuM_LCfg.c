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
**   $FILENAME   : EcuM_LCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   $DATE       : 2013-06-24 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for EcuM_LCfg.c file                         **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
*************************************************************************/!][!//
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
**   $FILENAME   : EcuM_LCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\6 $                                                  **
**                                                                            **
**   DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                            **
**   GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : EcuM configuration generated from ECU configuration file  **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: NO                                      **
**                                                                            **
*******************************************************************************/
[!NOCODE!]
[!INCLUDE "EcuM.m"!][!//
[!ENDNOCODE!] 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "EcuM.h"
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
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!IF "EcuMPostBuildConfigType = 'LOADABLE'"!][!//
#define ECUM_START_SEC_VAR_32BIT
#include "MemMap.h"
/*
Configuration: EcuM_ConfigAddressPtr 
*/
const struct EcuM_ConfigType_Tag *EcuM_ConfigAddressPtr =  
                                     (struct EcuM_ConfigType_Tag *)[!"EcuMLoadableConfigAddress"!]U;
#define ECUM_STOP_SEC_VAR_32BIT
#include "MemMap.h"
[!ENDIF!][!//
[!ENDSELECT!][!//

#define ECUM_START_SEC_CONST_32BIT
#include "MemMap.h"
/*
Configuration: EcuM_ConfigConsistencyHash 
*/
/* Hash over all pre-compile and link-time parameters. Currently this is not 
  calculated and not used */
const uint32 EcuM_ConfigConsistencyHash = 0xFFFFFFFFU;  

#define ECUM_STOP_SEC_CONST_32BIT
#include "MemMap.h"
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
**                      Global Function Definitions                           **
*******************************************************************************/

