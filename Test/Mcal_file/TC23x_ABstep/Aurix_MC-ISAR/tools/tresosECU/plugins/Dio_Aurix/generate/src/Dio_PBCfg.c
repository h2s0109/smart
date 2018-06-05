[!/*****************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Dio_PBCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\29 $                                                 **
**                                                                            **
**   $DATE       : 2014-11-05 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Dio configuration generated out of ECU configuration file  **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
**                                                                            **
**   Traceabilty : [cover parentID=SAS_AS_DIO026_2_DIO017,DS_NAS_DIO_PR723,
                  DS_NAS_DIO_PR700,DS_NAS_DIO_PR701,SAS_NAS_DIO_PR82,
                  DS_NAS_DIO_PR708,DS_NAS_DIO_PR712,DS_NAS_DIO_PR724,
                  DS_NAS_DIO_PR707,DS_NAS_DIO_PR704,DS_NAS_DIO_PR709,
                  DS_NAS_DIO_PR717,DS_NAS_DIO_PR728,SAS_AS4XX_DIO_PR680,
                  SAS_NAS_DIO_PR914,SAS_NAS_DIO_PR915,SAS_NAS_DIO_PR916,
                  DS_AS4XX_HE2_DIO_PR2934]                                    **
**                                                                            **
** [/cover]                                                                   **
/************************************************************************/!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2014)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Dio_PBCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\29 $                                                 **
**                                                                            **
**   DATE, TIME  : [!"$date"!], [!"$time"!]                                       **
**                                                                            **
**   GENERATOR   : Build [!"$buildnr"!]                                         **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : DIO configuration generated out of ECU configuration       **
**                  file                                                      **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

[!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Dio')"!][!//
[!//
[!/* Include Code Generator Macros */!][!//
[!NOCODE!][!//
[!INCLUDE "..\Dio.m"!][!//
[!//
[!VAR "ConfigCount" = "num:i(count(DioConfig/*))"!][!//
[!/* Determine only one DioConfig is configured 
      when DioPBFixedAddress = true.*/!]
[!IF "DioGeneral/DioPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($ConfigCount != 1)"!][!//
Config Error: when DioGeneral/DioPBFixedAddress is set as true, [!//
Only one DioConfig configuration is allowed. [!//
But DioConfig has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//

[!//
[!ENDNOCODE!][!//

/*******************************************************************************
**                             Includes                                       **
*******************************************************************************/

/* Include Port Module File */
#include "Dio.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/*
  Information on MISRA-2004 violations:
  - MISRA Rule 19.1: Only preprocessor statements and comments before 
    '#include'Inclusion of the file MemMap.h is done for memory mapping of 
    the code and data. This is violation of MISRA Rule 19.1, but cannot 
    be avoided.
*/

/* Memory mapping of the DIO configuration */
#define DIO_START_SEC_POSTBUILDCFG
#include "MemMap.h"

[!/* Generated Const port variables */!][!//
[!CALL "CG_Generate_Const_PortValues"!][!//
[!//
[!/* Generated Const Chnl variables */!][!//
[!CALL "CG_Generate_Const_ChnlValues"!][!//
[!//
[!/* Generated Const ChnlGrp variables */!][!//
[!CALL "CG_Generate_Const_ChnlGrp2Values"!][!//
[!//
[!FOR "CfgPosition" ="num:i(1)" TO "num:i(($ConfigCount))"!][!//
[!//
[!IF "$ConfigCount = num:i(1)"!][!//
/*
      Configuration of DIO Channel groups 
      DioConfig [!"num:i(string($CfgPosition))"!]
*/
[!CALL "CG_GetDioChannelGroupDefinition", "Instance" = "num:i(string($CfgPosition))"!][!//
[!ELSE!][!//
[!CALL "CG_GetDioChannelGroupVerify", "Instance" = "num:i(string($CfgPosition))"!][!//
[!ENDIF!][!//

static const Dio_PortChannelIdType Dio_kPortChannelConfig_[!"num:i(string($CfgPosition)- num:i(1))"!][] =
{
[!CALL "CG_check_duplicate_DioPortId", "Instance" = "num:i(string($CfgPosition))"!][!//
[!FOR "PortNumber" = "num:i(0)" TO "ecu:get('Dio.MaxAvailablePort')"!][!//
[!//
[!IF "contains(ecu:get('Dio.AvailablePorts'), concat('_', $PortNumber, '_'))"!][!//
  { /* Port[!"$PortNumber"!] */
[!CALL "CG_check_duplicate_DioPortChannelId", "PortNum" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
[!CALL "CG_GetDioConfiguredChannelInfo", "PortNum" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
  }[!IF "$PortNumber != ecu:get('Dio.MaxAvailablePort')"!],[!ENDIF!]
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
};
[!ENDFOR!]

const Dio_ConfigType Dio_ConfigRoot[[!"num:i($ConfigCount)"!]] =
{
[!FOR "CfgPosition" ="num:i(1)" TO "num:i($ConfigCount)"!][!//
[!CALL "CG_GVerify_Unique_Channel_Name", "Instance" = "num:i(string($CfgPosition))"!][!//
[!CALL "CG_GVerify_Unique_Channel_Grp_Name", "Instance" = "num:i(string($CfgPosition))"!][!//
[!CALL "CG_GetNumOfDioChannelGroupsConfigured", "Instance" = "num:i(string($CfgPosition))", "Print" = "num:i(0)"!][!//
  {
[!IF "DioSafety/DioSafetyEnable = 'true'"!][!//
    /* Marker check value */
    (uint32)(((uint32)DIO_MODULE_ID<<DIO_MODULEID_SHIFT_VAL) | (DIO_INSTANCE_ID)),
[!ENDIF!][!//

    /* Dio Port and Channelconfiguration set [!"num:i($CfgPosition - num:i(1))"!] */
    &Dio_kPortChannelConfig_[!"string(($CfgPosition)- num:i(1))"!][0],
[!IF "$ConfigCount = num:i(1)"!][!//
    /* Dio Channelgroup configuration set [!"num:i($CfgPosition - num:i(1))"!] */
[!IF "$NumOfGroups != num:i(0)"!][!//
    &Dio_kChannelGroupConfig_[!"string(($CfgPosition)- num:i(1))"!][0],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    /* Configured number of Dio Channelgroups for configuration set [!"num:i($CfgPosition - num:i(1))"!] */
    DIO_CHANNELGROUPCOUNT_[!"string(($CfgPosition)- num:i(1))"!],
[!ELSE!]
[!CALL "CG_GetUserDefinedSymbolicNames2", "Instance" = "num:i($CfgPosition)"!][!//
    /*  ChnlGrp ID Map */
[!CALL "CG_ChnlGrpIdMap", "Instance" = "num:i(string($CfgPosition))", "CFGCount" = "num:i($ConfigCount)"!][!//

    /* Chnl ID Map*/
[!CALL "CG_ChnlIdMap", "Instance" = "num:i(string($CfgPosition))", "CFGCount" = "num:i($ConfigCount)"!][!//

    /* Port ID Map */
[!CALL "CG_PortIdMap", "Instance" = "num:i(string($CfgPosition))", "CFGCount" = "num:i($ConfigCount)"!][!//
[!ENDIF!][!//
  }[!//
[!IF "$CfgPosition!= $ConfigCount"!],[!ENDIF!]
[!ENDFOR!][!//
};

#define DIO_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives
  is allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
[!ENDSELECT!][!//
