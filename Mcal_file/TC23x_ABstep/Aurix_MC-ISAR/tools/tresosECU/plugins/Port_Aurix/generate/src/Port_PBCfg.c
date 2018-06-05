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
**  $FILENAME   : Port_PBCfg.c $                                             **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x\7 $                                        **
**                                                                            **
**  $DATE       : 2016-08-03 $                                               **
**                                                                            **
**  AUTHOR      : DL-AUTOSAR-Engineering                                      **
**                                                                            **
**  VENDOR      : Infineon Technologies                                       **
**                                                                            **
**  DESCRIPTION  : Code template for Port_PBCfg.c file                        **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_Port_Driver,Release 4.0.3 ,3.2.1           **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=SAS_AS_PORT079,SAS_AS_PORT079_1,
    DS_NAS_PORT_PR700,DS_NAS_PORT_PR701,DS_NAS_PORT_PR704,SAS_AS_PORT079_2,
    DS_NAS_PORT_PR707,DS_NAS_PORT_PR708,DS_NAS_PORT_PR709,SAS_AS_PORT079_3,
    DS_NAS_PORT_PR712,DS_NAS_PORT_PR713,DS_NAS_PORT_PR714,
    DS_NAS_PORT_PR716,DS_NAS_PORT_PR717,DS_NAS_PORT_PR719,DS_NAS_PORT_PR720,
    DS_NAS_PORT_PR723,DS_NAS_PORT_PR724,SAS_AS4XX_PORT_PR680,
    DS_NAS_PORT_PR728,DS_NAS_PORT_PR741,] [/cover] */!][!//
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
**  FILENAME  : Port_PBCfg.c                                                  **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x\7 $                                        **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Port configuration generated from ECU 
                   configuration file ( Port.bmd)                             **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

[!//
[!NOCODE!]
[!INCLUDE "Port.m"!][!//
[!ENDNOCODE!] 
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclusion of Port Header file */
#include "Port.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
** Name             : Portx_lPdrConfig                                        **
**                                                                            **
** Description      : Macro to configure Portx Pdr register parameters        **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplification  of 
        configuration generation and increase the readability of config file*/
/* Macro definition for PORT pad drive control register Pn_PDR0 */
#define  Portx_lPdrConfig1(Pd0,Pd1,Pd2,Pd3,Pd4,Pd5,Pd6,Pd7)                    \
         ( ((uint32)(Pd7) << (uint32)28) | ((uint32)(Pd6) << (uint32)24) |     \
           ((uint32)(Pd5) << (uint32)20) | ((uint32)(Pd4) << (uint32)16) |     \
           ((uint32)(Pd3) << (uint32)12)|  ((uint32)(Pd2) << (uint32)8)  |     \
           ((uint32)(Pd1) << (uint32)4) | (uint32)(Pd0)                        \
         )
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplification  of 
        configuration generation and increase the readability of config file*/
/* Macro definition for PORT pad drive control register Pn_PDR1 */
#define  Portx_lPdrConfig2(Pd8,Pd9,Pd10,Pd11,Pd12,Pd13,Pd14,Pd15)              \
         ( ((uint32)(Pd15) << (uint32)28) | ((uint32)(Pd14) << (uint32)24) |   \
           ((uint32)(Pd13) << (uint32)20) | ((uint32)(Pd12) << (uint32)16) |   \
           ((uint32)(Pd11) << (uint32)12)|  ((uint32)(Pd10) << (uint32)8)  |   \
           ((uint32)(Pd9) << (uint32)4) | (uint32)(Pd8)                        \
         )                  
 /*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplification  of 
        configuration generation and increase the readability of config file*/        
/* Macro definition for PORT Pad Disable Control Register */
#define Port_lDiscSet(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)   \
  ((uint16)(                                                                    \
            (uint32)(b0) | ((uint32)(b1) << (uint32)1) |                       \
            ((uint32)(b2) << (uint32)2) | ((uint32)(b3) << (uint32)3) |        \
            ((uint32)(b4) << (uint32)4) | ((uint32)(b5) << (uint32)5) |        \
            ((uint32)(b6) << (uint32)6) | ((uint32)(b7) << (uint32)7) |        \
            ((uint32)(b8) << (uint32)8) | ((uint32)(b9) << (uint32)9) |        \
            ((uint32)(b10) << (uint32)10) | ((uint32)(b11) << (uint32)11) |    \
            ((uint32)(b12) << (uint32)12) | ((uint32)(b13)<< (uint32)13) |     \
            ((uint32)(b14) << (uint32)14) | ((uint32)(b15) << (uint32)15)      \
           ))

/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used for simplification  of 
        configuration generation and increase the readability of config file*/
/* Macro definition for PORT PCSR register */
#define Port_lPcsr(b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15)      \
  ((uint32)(                                                                    \
            ((uint32)(b0)) | ((uint32)(b1) << (uint32)1) |                     \
            ((uint32)(b2) << (uint32)2) | ((uint32)(b3) << (uint32)3) |        \
            ((uint32)(b4) << (uint32)4) | ((uint32)(b5) << (uint32)5) |        \
            ((uint32)(b6) << (uint32)6) | ((uint32)(b7) << (uint32)7) |        \
            ((uint32)(b8) << (uint32)8) | ((uint32)(b9) << (uint32)9) |        \
            ((uint32)(b10) << (uint32)10) | ((uint32)(b11) << (uint32)11) |    \
            ((uint32)(b12) << (uint32)12) | ((uint32)(b13) << (uint32)13) |    \
            ((uint32)(b14) << (uint32)14) | ((uint32)(b15) << (uint32)15)      \
           ))

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't 
   be avoided as it is required for mapping global variables, constants 
   and code
*/ 
/*lint -esym( 960, 87 ) Note 960: Violates MISRA Required Rule 87, 
                       only preprocessor statements and comments before 
                       '#include MemMap.h'
*/
/*lint -e537 Warning 537: Repeated include file MemMap.h */


#define PORT_START_SEC_POSTBUILDCFG
#include "MemMap.h"

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/
/*
                     Container : PortPinConfiguration
*/

/* 
Configuration Options: Physical pin level
-LOW  (Low Volatage Level)
-HIGH (High Voltage Level) 
*/
#define  PORT_PIN_LOW                       (0x00U)
#define  PORT_PIN_HIGH                      (0x01U)

/* Macros to define pin Default Input Output control value */
#define  PORT_PIN_DEFAULT                   (0x10U)

/* 
Configuration Options: Pin input characteristics 
-NO PULL
-PULL DOWN
-PULL UP
*/
#define  PORT_PIN_IN_NO_PULL                (0x00U)
#define  PORT_PIN_IN_PULL_DOWN              (0x08U)
#define  PORT_PIN_IN_PULL_UP                (0x10U)

/* 
Configuration Options: Pin output characteristics 
-PUSHPULL
-OPENDRAIN
*/
#define  PORT_PIN_OUT_PUSHPULL              (0x00U)
#define  PORT_PIN_OUT_OPENDRAIN             (0x40U)

/*
Configuration Options: Pin Pad Level  
*/
#define  PORT_PDR_CMOS_AUTOMOTIVE_LEVEL     (0x0U)

/*
Configuration Options: Pin driver strength
*/
#define  PORT_CMOS_SPEED_GRADE1             (0x0U)
#define  PORT_CMOS_SPEED_GRADE2             (0x1U)
#define  PORT_CMOS_SPEED_GRADE3             (0x2U)
#define  PORT_CMOS_SPEED_GRADE4             (0x3U)

/* Pin driver strength value for the non available pins*/
#define  PORT_PIN_PAD_LEVEL_DEFAULT         (0x0U)

/* Configuration Options: Pin drive strength, for class Adc type pad    */
#define  PORT_PDR_ADC                       (0x1U)

/*
  Some of the Pins doesn't have driver strength, To access the same
  pin this null value macro is introduced.
*/
#define  PORT_PDR_ZERO                      (0x0U)

/* For the Px_DISC register value set */
#define  PORT_PIN_ANALOG_INPUT_ENABLE       (0x1U)
#define  PORT_PIN_ANALOG_INPUT_DISABLE      (0x0U)

/* For PCSR register */
#define PORT_PCSR_DEFAULT                   (0x0U)
#define PORT_PCSR_ENABLE                    (0x1U)
#define PORT_PCSR_DISABLE                   (0x0U)

/******************************************************************************/
[!SELECT "as:modconf('Port')[1]"!][!//. 
[!VAR "PortPinDirectionChangeControl" = "PortGeneral/PortSetPinDirectionApi"!][!//
[!VAR "PortPinModeChangeControl" = "PortGeneral/PortSetPinModeApi"!][!//
[!VAR "ConfigCount" = "num:i(count(PortConfigSet/*))"!][!//
[!//
[!/* Determine only one PortConfigSet is configured
                                        when PortPBFixedAddress = true.*/!][!//
[!IF "PortGeneral/PortPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($ConfigCount != 1)"!][!//
Config Error: when PortGeneral/PortPBFixedAddress is set as true, [!//
Only one PortConfigSet configuration is allowed. [!//
But PortConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!//
[!// Determine if the configuration done for the port module is valid
[!CALL "CG_ConfigurationCheck"!][!//
[!//
[!FOR "CfgPosition" ="num:i(1)" TO "num:i($ConfigCount)"!][!//
[!//
[!VAR "IndexNum" = "num:i(0)"!][!//
static const Port_n_ConfigType Port_kConfiguration[!"num:i(string($CfgPosition)- num:i(1))"!][] = 
{
[!FOR "PortNumber" = "num:i(0)" TO "num:i(ecu:get('Port.MaxAvailablePort'))"!][!//
[!//
[!IF "contains(ecu:get('Port.PortsAvailable'), concat('_', $PortNumber, '_'))"!][!//
/*                              Port[!"$PortNumber"!]                       */
  {
    {
      /* Port pins direction, characteristics and mode configuration */
      {
[!CALL "CG_GetPortPinDirectionAndModeAttributes","port" = "$PortNumber","Index" = "$IndexNum","Instance" = "num:i(string($CfgPosition))"!][!//
      }
    },
    {
      /* Port pins initial level configuration */
      {
[!CALL "CG_GetPortPinLevelAttributes","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
      }
    },      
    /* Port pins drive strength1 configuration */
    Portx_lPdrConfig1(
[!CALL "CG_GetPortPinDriverStrength1","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
                     ),
    /* Port pins drive strength2 configuration */
    Portx_lPdrConfig2(
[!CALL "CG_GetPortPinDriverStrength2","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
                     )[!IF "$PortPinModeChangeControl = 'true' or $PortPinDirectionChangeControl = 'true'"!],[!ENDIF!]
[!IF "$PortPinModeChangeControl = 'true'"!][!//
    {/* Port pin run time mode changeable or not configuration */
      {
[!CALL "CG_GetPortPinModeChangeable","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
      }
    }[!IF "$PortPinDirectionChangeControl = 'true'"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "$PortPinDirectionChangeControl = 'true'"!][!//
    {/* Port pin run time direction changeable or not configuration */
      {
[!CALL "CG_GetPortPinDirectionChangeable","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
      }
    },
    {
      /* Port pins direction, characteristics and mode configuration if 
         direction is changeable */   
      {
[!CALL "CG_GetPortPinDirectionChangeableAttributes","port" = "$PortNumber","Index" = "$IndexNum", "Instance" = "num:i(string($CfgPosition))"!][!//
      }
    } 
[!ENDIF!][!//
   }[!IF "not(contains(ecu:get('Port.AvailableLastAnalogPort'), concat('_', $PortNumber, '_')))"!],[!ENDIF!]
[!VAR "IndexNum" = "num:i($IndexNum) + num:i(1)"!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
};

static const uint16 Port_DiscSet[!"num:i(string($CfgPosition)- num:i(1))"!][] = 
{     
[!FOR "PortNumber" = "num:i(0)" TO "num:i(ecu:get('Port.MaxAvailablePort'))"!][!//
[!//
[!IF "contains(ecu:get('Port.AvailableAnalogDigitalPorts'), concat('_', $PortNumber, '_'))"!][!//
/*                              Port[!"$PortNumber"!]                       */
   Port_lDiscSet(
[!CALL "CG_GetPortPinAnalogInputSelection","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!][!//
                )[!IF "not(contains(ecu:get('Port.AvailableLastAnalogPort'), concat('_', $PortNumber, '_')))"!],[!ENDIF!]
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
};
[!//

/* PCSR configuration */
static const Port_n_PCSRConfigType Port_kPCSRConfig[!"num:i(string($CfgPosition)- num:i(1))"!][] = 
{
[!CALL "CG_GetPCSRPads", "Instance" = "num:i(string($CfgPosition))"!][!//
};

[!VAR "PortDevErrorDetect" = "PortGeneral/PortDevErrorDetect"!][!//
[!VAR "nodeval" = "PortSafety/PortSafetyEnable"!][!//
[!//
[!IF "$PortPinModeChangeControl = 'true'"!][!//
[!IF "$nodeval = 'true' or $PortDevErrorDetect = 'true'"!][!//

/*
   Array contains information on the modes supported by each port pin
*/
static const Port_n_ModeType Port_kPinSupportedModes[!"num:i(string($CfgPosition)- num:i(1))"!][] = 
{
[!FOR "PortNumber" = "num:i(0)" TO "num:i(ecu:get('Port.MaxAvailablePort'))"!][!//
[!//
[!IF "contains(ecu:get('Port.PortsAvailable'), concat('_', $PortNumber, '_'))"!][!//
/*     Port[!"$PortNumber"!]      */
  {
    {     
[!CALL "CG_GetPortPinMode","port" = "$PortNumber", "Instance" = "num:i(string($CfgPosition))"!]
    }
  }[!IF "not(contains(ecu:get('Port.AvailableLastAnalogPort'), concat('_', $PortNumber, '_')))"!],[!ENDIF!]
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
};
[!ENDIF!][!// $PortPinModeChangeControl = 'true'
[!ENDIF!][!// $PortSafetyEnable = 'true' && $PortDevErrorDetect = 'true'
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!VAR "nodeval" = "PortSafety/PortSafetyEnable"!][!//

const Port_ConfigType Port_ConfigRoot[[!"num:i($ConfigCount)"!]] =
{
[!FOR "CfgPosition" ="num:i(1)" TO "num:i($ConfigCount)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Port')[1]/PortConfigSet/*[num:i($CfgPosition)]"!][!//
[!//  
  {
    [!IF "$nodeval = 'true'"!][!//
    [!NOCODE!][!//
    [!VAR "PortMarker" = "num:i(0)"!][!//
    [!VAR "ModuleId" = "num:i(124)"!][!//
    [!VAR "PortMarker" = "num:inttohex(bit:or($PortMarker,bit:shl($ModuleId,16)))"!][!//
    [!ENDNOCODE!][!//   
    /* Safety Marker */    
    [!"$PortMarker"!]U,
    [!ENDIF!][!//
    /* Port Configuration set [!"num:i($CfgPosition - num:i(1))"!] */
    &Port_kConfiguration[!"string(($CfgPosition)- num:i(1))"!][0],
    /* Port 40-th and 41-th Disc configuration set [!"num:i($CfgPosition - num:i(1))"!] */
    &Port_DiscSet[!"string(($CfgPosition)- num:i(1))"!][0],
[!IF "$PortPinModeChangeControl = 'true'"!][!//
[!IF "$nodeval = 'true' or $PortDevErrorDetect = 'true'"!][!//
    &Port_kPinSupportedModes[!"string(($CfgPosition)- num:i(1))"!][0],[!//
[!ENDIF!][!// $PortPinModeChangeControl = 'true' && $PortDevErrorDetect = 'true'
[!ENDIF!]
    /* PCSR Configuration */
    &Port_kPCSRConfig[!"string(($CfgPosition)- num:i(1))"!][0]
  }[!//
[!ENDSELECT!][!//
[!IF "$CfgPosition!= $ConfigCount"!],[!ENDIF!][!//
[!ENDFOR!]
};

#define PORT_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is 
 allowed only for MemMap.h*/
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
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


