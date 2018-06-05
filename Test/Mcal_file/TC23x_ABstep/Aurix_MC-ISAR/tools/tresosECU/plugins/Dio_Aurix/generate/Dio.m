[!/*
*******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Dio.m $                                                    **
**                                                                           **
**  $CC VERSION : \main\22 $                                                 **
**                                                                           **
**  $DATE       : 2014-11-05 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                the macros needed for Configuration Template files         **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************
*/!]


[!/*****************************************************************************
  Macro: CG_ConfigSwitch

  Macro to generate configuration switch Values STD_ON/STD_OFF based on
  configuration true/false

  Input Parameters:
  - nodeval: true/false
*****************************************************************************/!]
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]


[!/*****************************************************************************
  Macro: CG_GetDioChannelSymbolicNames

  Macro to print the symbolic names of each of the Dio channels

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioChannelSymbolicNames", "PortNum" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($PortNum) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!//
[!IF "contains(ecu:get(concat('Dio.DioChannels_Port',$PortNum)),concat('_',$PortPinNo,'_'))"!][!//
#define DIO_CHANNEL_[!"num:i($PortNum)"!]_[!"num:i($PortPinNo)"!]                    ((Dio_ChannelType)[!"num:inttohex($PinId, 3)"!])
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!ENDMACRO!]
[!/*****************************************************************************
  Macro: CG_GetDioPortSymbolicNames

  Macro to print the symbolic names of each of the Dio Ports

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioPortSymbolicNames"!][!//
[!//
[!FOR "PortNumber" = "0" TO "ecu:get('Dio.MaxAvailablePort')"!][!//
[!IF "contains(ecu:get('Dio.AvailablePorts'),concat('_',$PortNumber,'_'))"!][!//
#define DIO_PORT_[!"$PortNumber"!]                          ((Dio_PortType)[!"$PortNumber"!])
[!ENDIF!][!//
[!ENDFOR!][!//
[!//
[!ENDMACRO!]

[!/*****************************************************************************
  Macro: CG_GetDioEsrChannelsSymbolicNames

  Macro to print the symbolic names of each of the Dio Esrchannels

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioEsrChannelsSymbolicNames"!][!//
[!//
[!IF "var:defined('Esr0_Exists')"!][!//
#define DIO_ESRCHANNEL_0                    ((Dio_ChannelType)0x0100)
[!ENDIF!][!//
[!IF "var:defined('Esr1_Exists')"!][!//
#define DIO_ESRCHANNEL_1                    ((Dio_ChannelType)0x0101)
[!ENDIF!][!//
[!IF "var:defined('Esr2_Exists')"!][!//
#define DIO_ESRCHANNEL_2                    ((Dio_ChannelType)0x0102)
[!ENDIF!][!//
[!//
[!ENDMACRO!]
[!/*****************************************************************************
  Macro: CG_GetDioConfiguredChannelInfo

  Macro to identify and print the configured Dio Port/Channel

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioConfiguredChannelInfo", "PortNum" = "", "Instance" = ""!][!//
[!//
[!VAR "PortConfigured" = "num:i(0)"!][!//
[!/* Loop for all DioPort containers to generate configured Port,
     Channels under this port  */!][!//
[!IF "node:exists(DioConfig/*[num:i($Instance)]/DioPort/*[DioPortId = num:i($PortNum)])"!][!//
[!SELECT "DioConfig/*[num:i($Instance)]/DioPort/*[DioPortId = num:i($PortNum)]"!][!//
     DIO_PORT_CONFIGURED,
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!IF "node:exists(DioChannel/*[DioChannelId = num:i($PortPinNo)])"!][!//
[!VAR "PortConfigured" = "bit:or($PortConfigured,(bit:shl(1,num:i($PortPinNo))))"!][!//
[!ELSE!][!//
[!VAR "PortConfigured" = "bit:or($PortConfigured,(bit:shl(0,num:i($PortPinNo))))"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
     ([!"num:inttohex($PortConfigured, 4)"!]U)
[!ENDSELECT!][!//
[!ELSE!][!//
     DIO_PORT_NOT_CONFIGURED,
     (0x0000U)
[!ENDIF!][!//
[!//
[!ENDMACRO!]
[!/*****************************************************************************
  Macro: CG_GetUserDefinedSymbolicNames

  Macro to print the user defined symbolic names of each Dio Port/Channel/Group

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetUserDefinedSymbolicNames", "Instance" = ""!][!//
[!//
[!/* Variable used as index to refer to the channel groups */!][!//
[!VAR "j" = "num:i(0)"!][!//
[!//
[!/* Loop for all DioPort containers to generate symbolic names for the Port,
     Channels under this port & Channel groups under this port */!][!//
[!LOOP "DioConfig/*[num:i($Instance)]/DioPort/*"!][!//
[!//
[!/* Check if the Port Id. is valid. */!][!//
[!CALL "CG_CheckPortIdValidity", "PortId" = "num:i(./DioPortId)"!][!//
[!//
[!VAR "PortId" = "num:i(./DioPortId)"!][!//
[!VAR "PortName" = "concat('DIO_PORT_', num:i(./DioPortId))"!][!//
[!VAR "ChannelPrefix" = "concat('DIO_CHANNEL_', num:i(./DioPortId))"!][!//
[!VAR "ChannelGroupPrefix" = "'Dio_kChannelGroupConfig'"!][!//
[!VAR "PortSymbolicName" = "node:name(.)"!][!//
[!VAR "PortSymbolicName" = "concat("DioConf_DioPort_",$PortSymbolicName)"!]

/*
  DIO PORT : ([!"$PortSymbolicName"!])
*/
[!VAR "PortSymbolicName" = "normalize-space($PortSymbolicName)"!][!//
[!IF "num:i(string-length($PortSymbolicName)) != 0"!][!//
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef [!"$PortSymbolicName"!]
#define [!"$PortSymbolicName"!] ([!"$PortName"!])
#endif
[!ELSE!][!//
/* The Port does not have a User defined symbolic name. Use directly the
   internal Symbolic Name ([!"$PortName"!]) */
[!ENDIF!][!//
[!//
[!/* Generate Symbolic names for Dio channels under this port */!][!//
[!LOOP "./DioChannel/*"!][!//
[!//
[!/* Check for validity of the configured channel id*/!][!//
[!CALL "CG_CheckChannelIdValidity", "PortId" = "num:i($PortId)", "ChannelId" = "num:i(./DioChannelId)"!][!//
[!//
[!VAR "ChannelName" = "concat($ChannelPrefix,'_', num:i(./DioChannelId))"!][!//
[!VAR "ChannelSymbolicName" = "node:name(.)"!][!//
[!VAR "ChannelSymbolicName" = "normalize-space($ChannelSymbolicName)"!][!//
[!VAR "ChannelSymbolicName" = "concat("DioConf_DioChannel_",$ChannelSymbolicName)"!]

/* DIO Channel : ([!"$ChannelSymbolicName"!]) */
[!IF "num:i(string-length($ChannelSymbolicName)) != 0"!][!//
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef [!"$ChannelSymbolicName"!]
#define [!"$ChannelSymbolicName"!] ([!"$ChannelName"!])
#endif
[!ELSE!][!//
/* The Dio Channel does not have a User defined symbolic name. Use directly the
   internal Symbolic Name ([!"$ChannelName"!]) */
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!/* Generate Symbolic names for Dio channel groups under this port */!][!//
[!LOOP "./DioChannelGroup/*"!][!//
[!//
[!/* Check for validity of Mask */!][!//
[!CALL "CG_CheckChannelGroupMaskValidity", "GroupName" = "DioChannelGroupIdentification", "PortId" = "../../DioPortId", "MaskValue" = "num:i(DioPortMask)"!][!//
[!//

[!VAR "ChannelGroupSymbolicName" = "DioChannelGroupIdentification"!][!//
[!VAR "ChannelGroupSymbolicName" = "normalize-space($ChannelGroupSymbolicName)"!][!//
[!VAR "ChannelGroupSymbolicName" = "concat("DioConf_DioChannelGroup_",$ChannelGroupSymbolicName)"!]

/*DIO Channel Group : [!"$ChannelGroupSymbolicName"!]*/
[!IF "num:i(string-length($ChannelGroupSymbolicName)) != num:i(0)"!][!//
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/* To prevent double declaration */
#ifndef [!"$ChannelGroupSymbolicName"!]
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
#define [!"$ChannelGroupSymbolicName"!] (&Dio_ConfigRoot[[!"string(($Instance)-num:i(1))"!]].Dio_ChannelGroupConfigPtr[[!"num:i($j)"!]])
[!ELSE!][!//
#define [!"$ChannelGroupSymbolicName"!] (&(Dio_kConfigPtr->Dio_ChannelGroupConfigPtr[[!"num:i($j)"!]]))
[!ENDIF!][!//
#endif
[!ELSE!][!//
/* The Dio Port Pin Group does not have a User defined symbolic name.*/
[!ENDIF!][!//
[!VAR "j" = "$j + 1"!][!//
[!ENDLOOP!][!/* LOOP "./DioChannelGroup/*" */!][!//
[!//
[!ENDLOOP!][!/*LOOP "DioPort/*"*/!][!//

[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: GetNumOfDioChannelGroupsConfigured

  Macro to get the number of channel groups configured
  Port.

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetNumOfDioChannelGroupsConfigured", "Instance" = "", "Print" = ""!][!//
[!//
[!/* If there are DIO channel groups configured */!][!//
[!VAR "NumOfGroups" = "num:i(count(DioConfig/*[num:i($Instance)]/DioPort/*/DioChannelGroup/*))"!][!//
[!IF "num:i($Print) = num:i(1)"!][!//
#define DIO_CHANNELGROUPCOUNT_[!"string(($Instance)-num:i(1))"!]   ([!"$NumOfGroups"!]U)
[!ENDIF!][!//
[!//
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: GetDioChannelGroupDefinition

  Macro to set the definition of the channel group under each
  Port.

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioChannelGroupDefinition", "Instance" = ""!][!//
[!//
[!/* If there are DIO channel groups configured */!][!//
[!IF "num:i(count(DioConfig/*[num:i($Instance)]/DioPort/*/DioChannelGroup/*)) > 0"!][!//
[!VAR "PortChannelGroupStructName" = "'Dio_kChannelGroupConfig'"!][!//
static const Dio_ChannelGroupType [!"$PortChannelGroupStructName"!]_[!"string(($Instance)-num:i(1))"!][DIO_CHANNELGROUPCOUNT_[!"string(($Instance)-num:i(1))"!]]=
{[!//
[!/* Variables used in this configuration structure */!][!//
[!VAR "LastPortFlag" = "0"!][!//
[!VAR "PortName" = "0"!][!//
[!VAR "PortId" = "0"!][!//
[!VAR "PortOffset" = "0"!][!//
[!VAR "BitPosition" = "0"!][!//
[!VAR "counter" = "0"!][!//
[!//
[!/* Loop for all DioPort containers */!][!//
[!LOOP "DioConfig/*[num:i($Instance)]/DioPort/*"!][!//
[!IF "node:islast()"!][!//
[!VAR "LastPortFlag" = "1"!][!//
[!ENDIF!][!//
[!VAR "PortName" = "node:name(.)"!][!//
[!VAR "PortId" = "num:i(./DioPortId)"!][!//
[!LOOP "./DioChannelGroup/*"!][!//
[!/* To skip the first comma in the generated file */!][!//
[!IF "$counter = num:i(1)"!][!//
,[!//
[!ENDIF!]
[!VAR "counter" = "1"!][!//
[!NOCODE!][!//
	[!/* Calculate the offset depending on the value of the DioPortMask */!][!//
	[!VAR "PortOffset" = "num:i(0)"!][!//
  [!FOR "BitPosition" = "num:i(0)" TO "num:i(15)"!]
    [!IF "bit:getbit( num:i(DioPortMask), num:i($BitPosition) ) = 'true'"!]
      [!VAR "PortOffset" = "num:i($BitPosition)"!][!//
      [!BREAK!]
    [!ENDIF!]
  [!ENDFOR!]

  [!VAR "MaskValuecorrect" = "num:i(0)"!][!//
  [!VAR "MaskValuewrong" = "num:i(0)"!][!//
  [!VAR "Mask" = "DioPortMask"!][!//
  [!VAR "Mask" = "num:i(bit:shr($Mask,$PortOffset))"!][!//
  [!FOR "Index" = "num:i(0)" TO "num:i(15 - $PortOffset)"!][!//
  [!VAR "MaskValuecorrect" = "num:i(bit:and(num:i(1),num:i($Mask)))"!][!//
  [!IF "$MaskValuecorrect = num:i(1)"!][!//
  [!IF "$MaskValuewrong = num:i(1)"!][!//
  [!ERROR!][!//
   Config Error: Set the mask value which have only adjoining one's in the Group [!"DioChannelGroupIdentification"!]
  [!ENDERROR!][!//
  [!ENDIF!][!//
  [!ELSE!][!//
  [!VAR "MaskValuewrong" = "num:i(1)"!][!//
  [!ENDIF!][!//
  [!VAR "Mask" = "num:i(bit:shr($Mask,1))"!][!//
  [!ENDFOR!][!//

[!ENDNOCODE!][!//
  {
    /* [!"$PortName"!], [!"DioChannelGroupIdentification"!] */
    (Dio_PortLevelType)[!"num:inttohex(num:i(DioPortMask))"!], /* Mask    */
    (uint8)[!"num:i($PortOffset)"!], 	            /* Offset  */
    (Dio_PortType)[!"num:i($PortId)"!]	        /* Port Id */
  }[!//
[!ENDLOOP!][!/*LOOP "./DioChannelGroup/*"*/!][!//
[!ENDLOOP!][!/*LOOP "DioPort/*"*/!][!//

};
[!//
[!/* If there are no DIO channel groups configured */!][!//
[!ELSE!][!//
/* No Groups are configured */
[!ENDIF!][!//
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: GetDioChannelGroupCount

  Macro to count the number of channel group configured

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioChannelGroupCount"!][!//
[!NOCODE!][!//
[!IF "num:i(count(DioConfig/*/DioPort/*/DioChannelGroup/*)) > 0"!][!//
[!CODE!][!//
/* Macro to define the No of channel groups configured */
#define DIO_CHANNELGROUPCOUNT               ([!"num:i(count(DioConfig/*/DioPort/*/DioChannelGroup/*))"!]U)
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: CG_CheckPortIdValidity

  Macro to check the validity of the channel id. for the specified port

  Input Parameters:
  - PortCtrName:
  - PortId:
*****************************************************************************/!]
[!MACRO "CG_CheckPortIdValidity", "PortId" = ""!][!//
[!NOCODE!][!//
[!//
[!IF "(not(ecu:has(concat('Dio.DioChannels_Port',$PortId))))"!][!//
[!ERROR!][!//
Config Error: The PortId [!"$PortId"!] is invalid. The available Ports are [!"ecu:get('Dio.AvailablePorts')"!].[!//
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!ENDMACRO!]

[!/*****************************************************************************
  Macro: CG_CheckChannelIdValidity

  Macro to check the validity of the channel id. for the specified port

  Input Parameters:
  - PortId:
  - ChannelId:
*****************************************************************************/!]
[!MACRO "CG_CheckChannelIdValidity", "PortId" = "", "ChannelId" = ""!][!//
[!NOCODE!][!//
[!//
[!IF "(ecu:has(concat('Dio.DioChannels_Port',$PortId)))"!][!//
[!IF "(not(contains(ecu:get(concat('Dio.DioChannels_Port',$PortId)),concat('_',$ChannelId,'_'))))"!][!//
[!ERROR!][!//
Config Error: The ChannelID [!"$ChannelId"!] is invalid. The available PortPins for PORT[!"$PortId"!] are [!"ecu:get(concat('Dio.DioChannels_Port',$PortId))"!].[!//
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!ENDMACRO!]

[!/*****************************************************************************
  Macro: CG_CheckChannelGroupIdValidity

  Macro to check the validity of the channel group Id

  Input Parameters:
  - GroupCtrName:
*****************************************************************************/!]
[!MACRO "CG_CheckChannelGroupIdValidity", "GroupCtrName" = ""!][!//
[!NOCODE!][!//
  [!ASSERT "not( num:i(string-length(DioChannelGroupIdentification)) = num:i(0) )"!][!//
Config Error: The parameter DioChannelGroupIdentification for the ChannelGroup [!//
with container name [!"$GroupCtrName"!] is not configured[!//
  [!ENDASSERT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!/*****************************************************************************
  Macro: CG_CheckChannelGroupMaskValidity

  Macro to check the validity of the mask value of the channel group

  Input Parameters:
  - GroupName:
  - PortId:
  - MaskValue:
*****************************************************************************/!]
[!MACRO "CG_CheckChannelGroupMaskValidity", "GroupName" = "", "PortId" = "", "MaskValue" = ""!][!//
[!NOCODE!][!//

[!/* Check if MaskValue is 0 */!][!//
[!ASSERT "not( num:i($MaskValue) = num:i(0) )"!][!//
Config Error: The ChannelGroup [!"$GroupName"!] is configured with no channels [!//
because the parameter DioPortMask is configured 0. Configure a valid mask value[!//
[!ENDASSERT!][!//

[!/* Check for the validity of the mask value for the channel group */!][!//
[!VAR "InvalidMaskValue" = "'False'"!][!//

[!IF "boolean( bit:and( ($MaskValue) , (bit:not(num:hextoint(ecu:get(concat('Dio.DioPortMask_Port',$PortId)))))))"!][!//
  [!VAR "InvalidMaskValue" = "'True'"!][!//
[!ENDIF!]

[!/* Generate error message */!][!//
[!ASSERT "not( $InvalidMaskValue = 'True' )"!][!//
Config Error: The ChannelGroup [!"$GroupName"!] is configured with a mask value [!//
that specifies more no. of port pins in the group than available on that port. [!//
Configure a valid mask value[!//
[!ENDASSERT!][!//

[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_VerifyDioConfig

  Macro to verify the validity of the Dio configuration

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_VerifyDioConfig"!][!//
[!NOCODE!][!//

  [!//
  [!/* Loop for all DioPort containers to verify the configuration for the Port,
       Channels under this port & Channel groups under this port */!][!//
  [!LOOP "DioPort/*"!][!//
    [!//
    [!VAR "PortId" = "num:i(./DioPortId)"!][!//
    [!VAR "PortName" = "concat('DIO_PORT_', num:i(./DioPortId))"!][!//
    [!VAR "ChannelPrefix" = "concat('DIO_CHANNEL_', num:i(./DioPortId))"!][!//
    [!VAR "ChannelGroupPrefix" = "'Dio_ChannelGroupConfig'"!][!//
    [!VAR "PortSymbolicName" = "node:name(.)"!][!//
    [!//
    [!/* Check if the Port Id. is valid. */!][!//
    [!CALL "CG_CheckPortIdValidity", "PortId" = "$PortId"!][!//
    [!//
    [!ASSERT "not($PortSymbolicName = $PortName)"!][!//
Config Error: The User Defined Symbolic Name is same as Internal Symbolic Name [!//
for [!"$PortName"!]. Define another unique name![!//
    [!ENDASSERT!][!//
    [!//

    [!//
    [!/* Loop for all channels under this port */!][!//
    [!LOOP "./DioChannel/*"!][!//
      [!//
      [!VAR "ChannelName" = "concat($ChannelPrefix,'_', num:i(./DioChannelId))"!][!//
      [!VAR "ChannelSymbolicName" = "node:name(.)"!][!//
      [!//
      [!/* Check for validity of the configured channel id*/!][!//
      [!CALL "CG_CheckChannelIdValidity", "PortId" = "num:i($PortId)", "ChannelId" = "num:i(./DioChannelId)"!][!//
      [!//
      [!ASSERT "not($ChannelSymbolicName = $ChannelName)"!]
The User Defined Symbolic Name is same as Internal Symbolic Name for [!//
[!"$ChannelName"!]. Define another unique name![!//
      [!ENDASSERT!][!//
      [!//
    [!ENDLOOP!][!/*LOOP "./DioChannel/*"*/!][!//
    [!//

    [!//
    [!/* Loop for all the Dio channel groups under this port */!][!//
    [!LOOP "./DioChannelGroup/*"!][!//
      [!//
      [!/* Check for validity of the DioChannelGroupIdentification */!][!//
      [!CALL "CG_CheckChannelGroupIdValidity", "GroupCtrName" = "node:name(.)"!][!//
      [!//
      [!/* Check for validity of Mask */!][!//
      [!CALL "CG_CheckChannelGroupMaskValidity", "GroupName" = "DioChannelGroupIdentification", "PortId" = "../../DioPortId", "MaskValue" = "num:i(DioPortMask)"!][!//
      [!//
    [!ENDLOOP!][!/* LOOP "./DioChannelGroup/*" */!][!//
    [!//

  [!//
  [!ENDLOOP!][!/*LOOP "DioPort/*"*/!][!//
  [!//

[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!/*****************************************************************************
  Macro: CG_GetMaskForPortPins

  Macro to generate the values to mask the undefined port pins

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetMaskForPortPins"!][!//
[!//
/* Values to mask the undefined port pins within a port */
[!FOR "PortNumber" = "0" TO "41"!][!//
[!VAR "MaskPort_Temp" = "num:inttohex(0,4)"!][!//
[!IF "contains(ecu:get('Dio.AvailablePorts'),concat('_',$PortNumber,'_'))"!][!//
[!VAR "MaskPort_Temp" = "num:inttohex(num:hextoint(ecu:get(concat('Dio.DioPortMask_Port',$PortNumber))),4)"!][!//
[!ENDIF!][!//
#define DIO_MASK_UNDEF_PINS_PORT[!"$PortNumber"!]             ([!"$MaskPort_Temp"!]U)
[!ENDFOR!][!//
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetPortMSPin

  Macro to generate the most significant pin for each port

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetPortMSPin"!][!//
[!FOR "PortNumber" = "0" TO "41"!][!//
[!VAR "MsPort_Temp" = "num:i(0)"!][!//
[!IF "contains(ecu:get('Dio.AvailablePorts'),concat('_',$PortNumber,'_'))"!][!//
[!VAR "MsPort_Temp" = "num:i(ecu:get(concat('Dio.Port',$PortNumber,'_MSPin')))"!][!//
[!ENDIF!][!//
#define DIO_PORT_[!"$PortNumber"!]_MSPIN                     ([!"$MsPort_Temp"!]U)
[!ENDFOR!][!//
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetReadOnlyPorts00to31

  Macro to generate definition to indicate the read only ports of the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetReadOnlyPorts00to31"!][!//
[!NOCODE!][!//

[!VAR "ReadOnlyPorts" = "num:i(0)"!][!//

[!FOR "PortNumber" = "0" TO "31"!][!//
[!IF "contains(ecu:get('Dio.AvailableReadOnlyPorts'),concat('_',$PortNumber,'_'))"!][!//
  [!VAR "ReadOnlyPorts" = "bit:bitset($ReadOnlyPorts, $PortNumber)"!][!//
[!ENDIF!]
[!ENDFOR!]

[!ENDNOCODE!][!//
[!//
#define DIO_PORTS_READONLY_00_31             ([!"num:inttohex($ReadOnlyPorts, 8)"!]U)
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetMaxAvailablePort

  Macro to generate the value for Maximum available port on the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetMaxAvailablePort"!][!//
[!//
#define MAX_AVAILABLE_PORTS                  ([!"num:i(ecu:get('Dio.MaxAvailablePort'))"!]U)
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetReadOnlyPorts32to40

  Macro to generate definition to indicate the read only ports of the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetReadOnlyPorts32to40"!][!//
[!NOCODE!][!//

[!VAR "ReadOnlyPorts" = "num:i(0)"!][!//

[!FOR "PortNumber" = "32" TO "ecu:get('Dio.MaxAvailablePort')"!][!//
[!IF "contains(ecu:get('Dio.AvailableReadOnlyPorts'),concat('_',$PortNumber,'_'))"!][!//
  [!VAR "ReadOnlyPorts" = "bit:bitset($ReadOnlyPorts, (num:i($PortNumber)-num:i(32)))"!][!//
[!ENDIF!]
[!ENDFOR!]

[!ENDNOCODE!][!//
[!//
#define DIO_PORTS_READONLY_32_40             ([!"num:inttohex($ReadOnlyPorts, 8)"!]U)
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetPortsAvailable00to31

  Macro to generate definition to indicate the ports available on the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetPortsAvailable00to31"!][!//
[!NOCODE!][!//

[!VAR "AvailablePorts" = "num:i(0)"!][!//

[!FOR "PortNumber" = "0" TO "31"!][!//
[!IF "contains(ecu:get('Dio.AvailablePorts'),concat('_',$PortNumber,'_'))"!][!//
  [!VAR "AvailablePorts" = "bit:bitset($AvailablePorts, $PortNumber)"!][!//
[!ENDIF!]
[!ENDFOR!]

[!ENDNOCODE!][!//
[!//
#define DIO_PORTS_AVAILABLE_00_31           ([!"num:inttohex($AvailablePorts, 8)"!]U)
[!//
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: CG_GetPortsAvailable32to40

  Macro to generate definition to indicate the ports available on the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetPortsAvailable32to40"!][!//
[!NOCODE!][!//

[!VAR "AvailablePorts" = "num:i(0)"!][!//

[!FOR "PortNumber" = "32" TO "ecu:get('Dio.MaxAvailablePort')"!][!//
[!IF "contains(ecu:get('Dio.AvailablePorts'),concat('_',$PortNumber,'_'))"!][!//
  [!VAR "AvailablePorts" = "bit:bitset($AvailablePorts, (num:i($PortNumber)-num:i(32)))"!][!//
[!ENDIF!]
[!ENDFOR!]

[!ENDNOCODE!][!//
[!//
#define DIO_PORTS_AVAILABLE_32_40           ([!"num:inttohex($AvailablePorts, 8)"!]U)
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetEsrPinsAvailable

  Macro to generate definition to indicate the EsrPins available on the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetEsrPinsAvailable"!][!//
[!NOCODE!][!//

[!VAR "AvailableEsrPins" = "num:i(0)"!][!//

[!IF "var:defined('Esr0_Exists')"!][!//
  [!VAR "AvailableEsrPins" = "bit:bitset($AvailableEsrPins, 0)"!][!//
[!ENDIF!]
[!IF "var:defined('Esr1_Exists')"!][!//
  [!VAR "AvailableEsrPins" = "bit:bitset($AvailableEsrPins, 1)"!][!//
[!ENDIF!]
[!IF "var:defined('Esr2_Exists')"!][!//
  [!VAR "AvailableEsrPins" = "bit:bitset($AvailableEsrPins, 2)"!][!//
[!ENDIF!]


[!ENDNOCODE!][!//
[!//
#define DIO_ESRPINS_AVAILABLE               ([!"num:inttohex($AvailableEsrPins, 2)"!]U)
[!//
[!ENDMACRO!][!//



[!/*****************************************************************************
  Macro: CG_check_duplicate_DioPortId

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_check_duplicate_DioPortId", "Instance" = ""!][!//
[!//
[!FOR "index" = "num:i(0)" TO "ecu:get('Dio.MaxAvailablePort')"!][!//
[!VAR "COUNT" = "num:i(0)"!][!//
[!LOOP "as:modconf('Dio')[1]/DioConfig/*[num:i($Instance)]/DioPort/*"!][!//
[!IF "./DioPortId = num:i($index)"!][!//
[!VAR "COUNT" = "$COUNT + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$COUNT > num:i(1)"!][!//
[!ERROR!][!//
[!VAR "ID" = "$Instance - 1"!][!//
  DioPortId = [!"$index"!], is repeated [!"num:i($COUNT)"!] times in Dio/DioConfig[[!"num:i($ID)"!]]/DioPort/DioPortId
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//


[!/*****************************************************************************
  Macro: CG_check_duplicate_DioPortChannelId

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_check_duplicate_DioPortChannelId", "PortNum" = "", "Instance" = ""!][!//
[!//
[!FOR "Index" = "num:i(0)" TO "ecu:get('Dio.DioPortMax')"!][!//
[!FOR "index" = "num:i(0)" TO "num:i(16)"!][!//
[!VAR "COUNT" = "num:i(0)"!][!//
[!LOOP "as:modconf('Dio')[1]/DioConfig/*[num:i($Instance)]/DioPort/*[num:i($Index)]/DioChannel/*"!][!//
[!IF "./DioChannelId = num:i($index)"!][!//
[!VAR "COUNT" = "$COUNT + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$COUNT > num:i(1)"!][!//
[!ERROR!][!//
[!VAR "ID" = "$Instance - 1"!][!//
[!VAR "Index" = "$Index - 1"!][!//
  DioChannelId = [!"$index"!], is repeated [!"num:i($COUNT)"!] times in Dio/DioConfig[[!"num:i($ID)"!]]/DioPort[[!"num:i($Index)"!]]/DioChannel
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//


[!/*****************************************************************************
  Macro: CG_Generate_Const_PortValues

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_Generate_Const_PortValues"!][!//
[!//
[!NOCODE!][!//
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(./DioConfig/*))"!]
[!VAR "Superstring" = "''"!]
[!"$Superstring"!]
[!LOOP "as:modconf('Dio')[1]/DioConfig/*"!]
[!LOOP "./DioPort/*"!]
[!VAR "CurIdx" = "../../@index"!]
[!VAR "CurName" = "node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(0)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($CurIdx)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!LOOP "./DioPort/*"!]
[!IF "$CurName = node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(1)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!IF "$UniqueFlag = num:i(0)"!][!//
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($ConfigCount)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!VAR "Flag" = "num:i(0)"!]
[!LOOP "./DioPort/*"!]
[!IF "$CurName = node:name(.)"!]
[!VAR "Flag" = "num:i(1)"!]
[!VAR "temp" = "num:inttohex(./DioPortId,2)"!]
[!VAR "temp" = "substring-after(string($temp),'x')"!]
[!VAR "Superstring" = "concat(string($Superstring),string($temp))"!] [!"./DioPortId"!],
[!ENDIF!]
[!ENDLOOP!]
[!IF "$Flag = num:i(0)"!][!//
[!VAR "Superstring" = "concat(string($Superstring),'FF')"!] 0xFFU,
[!ENDIF!]
[!ENDSELECT!]
[!ENDFOR!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_PortIdMap

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_PortIdMap", "Instance" = "", "CFGCount" = ""!][!//
[!//
[!NOCODE!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "SymbolCount" = "num:i(num:div(string-length($Superstring),num:mul(num:i(2),num:i(num:i(count(./DioConfig/*))))))"!]
[!IF "$SymbolCount = num:i(0)"!]
[!CODE!][!//
    /* No DioPorts Configured */
[!ENDCODE!][!//
[!ELSE!]
[!CODE!][!//
    {
[!ENDCODE!][!//
[!VAR "strpos" = "num:i(1) + (($Instance - num:i(1))*num:i(2))"!]
[!FOR "CfgPosition2" ="num:i(1)" TO "num:i($SymbolCount)"!][!//
[!CODE!][!//
      0x[!"substring( $Superstring, $strpos, num:i(2))"!]U[!//
[!ENDCODE!][!//
[!VAR "strpos" = "num:i($strpos) + num:i($CFGCount)"!][!//
[!VAR "strpos" = "num:i($strpos) + num:i($CFGCount)"!][!//
[!CODE!][!//
[!IF "$CfgPosition2 = num:i($SymbolCount)"!]
[!ELSE!],
[!ENDIF!][!//
[!ENDCODE!][!//
[!ENDFOR!][!//
[!CODE!][!//
    }
[!ENDCODE!][!//
[!ENDIF!]
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_PortIdMapSymbolicName

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_PortIdMapSymbolicName"!][!//
[!//
[!NOCODE!][!//
[!VAR "chnlidx" = "num:i(0)"!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(./DioConfig/*))"!]
[!VAR "Superstring" = "''"!]
[!LOOP "as:modconf('Dio')[1]/DioConfig/*"!]
[!LOOP "./DioPort/*"!]
[!VAR "CurIdx" = "../../@index"!]
[!VAR "CurName" = "node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(0)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($CurIdx)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!LOOP "./DioPort/*"!]
[!IF "$CurName = node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(1)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!IF "$UniqueFlag = num:i(0)"!][!//
[!CODE!][!//
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
#ifndef DioConf_DioPort_[!"$CurName"!]
#define DioConf_DioPort_[!"$CurName"!] (Dio_kConfigPtr->Dio_PortIdMap[[!"num:i($chnlidx)"!]])
#endif

[!ENDCODE!]
[!VAR "chnlidx" = "(num:i($chnlidx) + num:i(1))"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//


[!/*****************************************************************************
  Macro: CG_Generate_Const_ChnlValues

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_Generate_Const_ChnlValues"!][!//
[!//
[!NOCODE!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(./DioConfig/*))"!]
[!VAR "Superstringchnl" = "''"!]
[!LOOP "as:modconf('Dio')[1]/DioConfig/*"!]
[!LOOP "./DioPort/*/DioChannel/*"!]
[!VAR "CurIdx" = "./../../../../@index"!]
[!VAR "CurName" = "node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(0)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($CurIdx)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!LOOP "./DioPort/*/DioChannel/*"!]
[!IF "$CurName = node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(1)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!IF "$UniqueFlag = num:i(0)"!][!//
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($ConfigCount)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!VAR "Flag" = "num:i(0)"!]
[!LOOP "./DioPort/*/DioChannel/*"!]
[!IF "$CurName = node:name(.)"!]
[!VAR "Flag" = "num:i(1)"!]
[!VAR "temp" = "num:i(./../../DioPortId) * num:i(16)"!][!//
[!VAR "temp" = "num:i($temp) + num:i(./DioChannelId)"!][!//
[!VAR "temp" = "num:inttohex($temp,4)"!]
[!VAR "temp" = "substring-after(string($temp),'x')"!]
[!VAR "Superstringchnl" = "concat(string($Superstringchnl),string($temp))"!]
[!ENDIF!]
[!ENDLOOP!]
[!IF "$Flag = num:i(0)"!][!//
[!VAR "Superstringchnl" = "concat(string($Superstringchnl),'FFFF')"!]
[!ENDIF!]
[!ENDSELECT!]
[!ENDFOR!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_ChnlIdMap

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_ChnlIdMap", "Instance" = "", "CFGCount" = ""!][!//
[!//
[!NOCODE!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "SymbolCount" = "num:i(num:div(string-length($Superstringchnl),num:mul(num:i(4),num:i(num:i(count(./DioConfig/*))))))"!]
[!IF "$SymbolCount = num:i(0)"!]
[!CODE!][!//
    /* No DioChannel Configured */
[!ENDCODE!][!//
[!ELSE!]
[!CODE!][!//
    {
[!ENDCODE!][!//
[!VAR "strpos" = "num:i(1) + (($Instance - num:i(1))*num:i(4))"!]
[!FOR "CfgPosition2" ="num:i(1)" TO "num:i($SymbolCount)"!][!//
[!CODE!][!//
      0x[!"substring( $Superstringchnl, $strpos, num:i(4))"!]U[!//
[!ENDCODE!][!//
[!VAR "strpos" = "num:i($strpos) + num:i($CFGCount)"!][!//
[!VAR "strpos" = "num:i($strpos) + num:i($CFGCount)"!][!//
[!VAR "strpos" = "num:i($strpos) + num:i($CFGCount)"!][!//
[!VAR "strpos" = "num:i($strpos) + num:i($CFGCount)"!][!//
[!CODE!][!//
[!IF "$CfgPosition2 = num:i($SymbolCount)"!]
[!ELSE!],
[!ENDIF!][!//
[!ENDCODE!][!//
[!ENDFOR!][!//
[!CODE!][!//
    },
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_ChnlIdMapSymbolicName

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_ChnlIdMapSymbolicName"!][!//
[!//
[!NOCODE!][!//
[!VAR "chnlidx" = "num:i(0)"!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(./DioConfig/*))"!]
[!VAR "Superstringchnl" = "''"!]
[!LOOP "as:modconf('Dio')[1]/DioConfig/*"!]
[!LOOP "./DioPort/*/DioChannel/*"!]
[!VAR "CurIdx" = "./../../../../@index"!]
[!VAR "CurName" = "node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(0)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($CurIdx)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!LOOP "./DioPort/*/DioChannel/*"!]
[!IF "$CurName = node:name(.)"!]
[!VAR "UniqueFlag" = "num:i(1)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!IF "$UniqueFlag = num:i(0)"!][!//
[!CODE!][!//
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
#ifndef DioConf_DioChannel_[!"$CurName"!]
#define DioConf_DioChannel_[!"$CurName"!] (Dio_kConfigPtr->Dio_PortPinIdMap[[!"num:i($chnlidx)"!]])
#endif

[!ENDCODE!]
[!VAR "chnlidx" = "(num:i($chnlidx) + num:i(1))"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_Generate_Const_ChnlGrp1Values

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_Generate_Const_ChnlGrp1Values"!][!//
[!//
[!NOCODE!]
[!VAR "ChGrpIdx" = "num:i(0)"!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(./DioConfig/*))"!]
[!VAR "Superstringchnlgrp" = "''"!]
[!LOOP "as:modconf('Dio')[1]/DioConfig/*"!]
[!LOOP "./DioPort/*/DioChannelGroup/*"!]
[!VAR "CurIdx" = "./../../../../@index"!]
[!VAR "CurName" = "node:value(./DioChannelGroupIdentification)"!]
[!VAR "UniqueFlag" = "num:i(0)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($CurIdx)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!LOOP "./DioPort/*/DioChannelGroup/*"!]
[!IF "$CurName = node:value(./DioChannelGroupIdentification)"!]
[!VAR "UniqueFlag" = "num:i(1)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!IF "$UniqueFlag = num:i(0)"!][!//
[!CODE!][!//
/*IFX_MISRA_RULE_05_01_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
/*IFX_MISRA_RULE_01_04_STATUS = The generated macro may exceed
  31 characters to follow Autosar naming conventions*/
#define [!"concat("DioConf_DioChannelGroup_",$CurName)"!]    (&(Dio_kConfigPtr->Dio_ChGrpIdMap[[!"num:i($ChGrpIdx)"!]]))

[!ENDCODE!][!//
[!VAR "ChGrpIdx" = "num:i(1) + num:i($ChGrpIdx)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($ConfigCount)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!VAR "Flag" = "num:i(0)"!]
[!LOOP "./DioPort/*/DioChannelGroup/*"!]
[!IF "$CurName = node:value(./DioChannelGroupIdentification)"!]
[!VAR "Flag" = "num:i(1)"!]
[!VAR "temp" = "node:value(./DioChannelGroupIdentification)"!]
[!/* Calculate the offset depending on the value of the DioPortMask */!][!//
[!VAR "PortOffset" = "num:i(0)"!][!//
  [!FOR "BitPosition" = "num:i(0)" TO "num:i(15)"!]
    [!IF "bit:getbit( num:i(./DioPortMask), num:i($BitPosition) ) = 'true'"!]
      [!VAR "PortOffset" = "num:i($BitPosition)"!][!//
      [!BREAK!]
    [!ENDIF!]
  [!ENDFOR!]
  [!VAR "MaskValuecorrect" = "num:i(0)"!][!//
  [!VAR "MaskValuewrong" = "num:i(0)"!][!//
  [!VAR "Mask" = "DioPortMask"!][!//
  [!VAR "Mask" = "num:i(bit:shr($Mask,$PortOffset))"!][!//
  [!FOR "Index" = "num:i(0)" TO "num:i(15 - $PortOffset)"!][!//
  [!VAR "MaskValuecorrect" = "num:i(bit:and(num:i(1),num:i($Mask)))"!][!//
  [!IF "$MaskValuecorrect = num:i(1)"!][!//
  [!IF "$MaskValuewrong = num:i(1)"!][!//
  [!ERROR!][!//
   Config Error: Set the mask value which have only adjoining one's in the Group [!"DioChannelGroupIdentification"!]
  [!ENDERROR!][!//
  [!ENDIF!][!//
  [!ELSE!][!//
  [!VAR "MaskValuewrong" = "num:i(1)"!][!//
  [!ENDIF!][!//
  [!VAR "Mask" = "num:i(bit:shr($Mask,1))"!][!//
  [!ENDFOR!][!//
[!VAR "Superstringchnlgrp" = "concat(string($Superstringchnlgrp),'{(Dio_PortLevelType)',num:inttohex(num:i(./DioPortMask)),'(uint8)',num:i($PortOffset),'(Dio_PortType)',num:i(../../DioPortId),'}',':')"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$Flag = num:i(0)"!][!//
[!VAR "Superstringchnlgrp" = "concat(string($Superstringchnlgrp),'{65535U, 255U, 255U}',':')"!]
[!ENDIF!]
[!ENDSELECT!]
[!ENDFOR!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_ChnlGrpIdMap

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_ChnlGrpIdMap", "Instance" = "", "CFGCount" = ""!][!//
[!//
[!NOCODE!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "SymbolCount" = "num:i(num:div(num:i(count(text:split($Superstringchnlgrp,':'))),num:i(count(./DioConfig/*))))"!]
[!IF "$SymbolCount = num:i(0)"!]
[!CODE!][!//
    /* No DioChannelGroup Configured */
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
    {
[!ENDCODE!][!//
[!VAR "strpos" = "num:i($Instance)"!]
[!FOR "CfgPosition2" ="num:i(1)" TO "num:i($SymbolCount)"!][!//
[!CODE!][!//
     {
      [!"text:split(text:split($Superstringchnlgrp,':')[num:i($strpos)],'~')[2]"!]
      [!"text:split(text:split($Superstringchnlgrp,':')[num:i($strpos)],'~')[3]"!]
      [!"text:split(text:split($Superstringchnlgrp,':')[num:i($strpos)],'~')[4]"!]
     }[!//
[!ENDCODE!][!//
[!VAR "strpos" = "num:i($strpos) + num:i((count(./DioConfig/*)))"!]
[!CODE!][!//
[!IF "$CfgPosition2 = num:i($SymbolCount)"!]
[!ELSE!],
[!ENDIF!][!//
[!ENDCODE!][!//
[!ENDFOR!][!//
[!CODE!][!//
    },
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_Generate_Const_ChnlGrp2Values

  Macro to check containers with duplicate id

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_Generate_Const_ChnlGrp2Values"!][!//
[!//
[!NOCODE!]
[!VAR "ChGrpIdx" = "num:i(0)"!]
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "ConfigCount" = "num:i(count(./DioConfig/*))"!]
[!VAR "Superstringchnlgrp" = "''"!]
[!LOOP "as:modconf('Dio')[1]/DioConfig/*"!]
[!LOOP "./DioPort/*/DioChannelGroup/*"!]
[!VAR "CurIdx" = "./../../../../@index"!]
[!VAR "CurName" = "node:value(./DioChannelGroupIdentification)"!]
[!VAR "UniqueFlag" = "num:i(0)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($CurIdx)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!LOOP "./DioPort/*/DioChannelGroup/*"!]
[!IF "$CurName = node:value(./DioChannelGroupIdentification)"!]
[!VAR "UniqueFlag" = "num:i(1)"!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!IF "$UniqueFlag = num:i(0)"!][!//
[!VAR "ChGrpIdx" = "num:i(1) + num:i($ChGrpIdx)"!]
[!FOR "newCurIdx" = "num:i(1)" TO "num:i($ConfigCount)"!][!//
[!SELECT "as:modconf('Dio')[1]/DioConfig/*[num:i($newCurIdx)]"!]
[!VAR "Flag" = "num:i(0)"!]
[!LOOP "./DioPort/*/DioChannelGroup/*"!]
[!IF "$CurName = node:value(./DioChannelGroupIdentification)"!]
[!VAR "Flag" = "num:i(1)"!]
[!VAR "temp" = "node:value(./DioChannelGroupIdentification)"!]
[!VAR "PortOffset" = "num:i(0)"!][!//
[!FOR "BitPosition" = "num:i(0)" TO "num:i(15)"!]
[!IF "bit:getbit( num:i(./DioPortMask), num:i($BitPosition) ) = 'true'"!]
[!VAR "PortOffset" = "num:i($BitPosition)"!][!//
[!BREAK!]
[!ENDIF!]
[!ENDFOR!]
[!VAR "Superstringchnlgrp" = "concat(string($Superstringchnlgrp),'{~(Dio_PortLevelType)',num:inttohex(num:i(./DioPortMask)),'U /* Mask */,~','(uint8)',num:i($PortOffset),'U /* Offset */,~','(Dio_PortType)',num:i(../../DioPortId),'U /* PortID */','  /* ',node:value(./DioChannelGroupIdentification),' */ ','~}',':')"!]
[!ENDIF!]
[!ENDLOOP!]
[!IF "$Flag = num:i(0)"!][!//
[!VAR "Superstringchnlgrp" = "concat(string($Superstringchnlgrp),'{~65535U,~255U,~255U /* NULL */ ~}',':')"!]
[!ENDIF!]
[!ENDSELECT!]
[!ENDFOR!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GVerify_Unique_Channel_Name

  Macro to check containers with duplicate Channel name

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_GVerify_Unique_Channel_Name", "Instance" = ""!][!//
[!//
[!NOCODE!][!//
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "Dio_chnl_list" = "''"!]
[!LOOP "./DioConfig/*[num:i($Instance)]/DioPort/*/DioChannel/*"!]
[!"node:name(.)"!]
[!IF "contains(text:split($Dio_chnl_list,','),concat('(',node:name(.),')')) = 'true'"!]
[!ERROR!][!//
In a Config Set, Symbolic Name of a channel shall not be assigned to more than one PortPin.
The Channel name '[!"node:name(.)"!]' is used for channels more than once.
Location: Dio/DioConfig/[!"node:name(./../../../..)"!]/DioPort/[!"node:name(./../..)"!]/DioChannel/[!"node:name(.)"!]
[!ENDERROR!][!//
[!ENDIF!]
[!VAR "Dio_chnl_list" = "concat($Dio_chnl_list,',','(',node:name(.),')')"!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GVerify_Unique_Channel_Grp_Name

  Macro to check containers with duplicate Channel name

  Input Parameters:
  none
*****************************************************************************/!]
[!MACRO "CG_GVerify_Unique_Channel_Grp_Name", "Instance" = ""!][!//
[!//
[!NOCODE!][!//
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "Dio_chnl_grp_list" = "''"!]
[!LOOP "./DioConfig/*[num:i($Instance)]/DioPort/*/DioChannelGroup/*"!]
[!IF "contains(text:split($Dio_chnl_grp_list,','),concat('(',node:value(./DioChannelGroupIdentification),')')) = 'true'"!]
[!ERROR!][!//
In a Config Set, Symbolic Name of a Channel Group shall not be assigned to more than one PortPin.
The Channel Group name "[!"./DioChannelGroupIdentification"!]" is used for channels more than once.
Location: Dio/DioConfig/[!"node:name(./../../../..)"!]/DioPort/[!"node:name(./../..)"!]/DioChannel/[!"node:name(.)"!]
[!ENDERROR!][!//
[!ENDIF!]
[!VAR "Dio_chnl_grp_list" = "concat($Dio_chnl_grp_list,',','(',node:value(./DioChannelGroupIdentification),')')"!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetDioChannelGroupVerify

  Macro to set the definition of the channel group under each
  Port.

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetDioChannelGroupVerify", "Instance" = ""!][!//
[!//
[!NOCODE!][!//
[!/* If there are DIO channel groups configured */!][!//
[!IF "num:i(count(DioConfig/*[num:i($Instance)]/DioPort/*/DioChannelGroup/*)) > 0"!][!//
[!/* Variables used in this configuration structure */!][!//
[!VAR "PortName" = "0"!][!//
[!VAR "PortId" = "0"!][!//
[!VAR "PortOffset" = "0"!][!//
[!VAR "BitPosition" = "0"!][!//
[!VAR "counter" = "0"!][!//
[!/* Loop for all DioPort containers */!][!//
[!LOOP "DioConfig/*[num:i($Instance)]/DioPort/*"!][!//
[!VAR "PortName" = "node:name(.)"!][!//
[!VAR "PortId" = "num:i(./DioPortId)"!][!//
[!LOOP "./DioChannelGroup/*"!][!//
[!/* Calculate the offset depending on the value of the DioPortMask */!][!//
[!VAR "PortOffset" = "num:i(0)"!][!//
  [!FOR "BitPosition" = "num:i(0)" TO "num:i(15)"!]
    [!IF "bit:getbit( num:i(DioPortMask), num:i($BitPosition) ) = 'true'"!]
      [!VAR "PortOffset" = "num:i($BitPosition)"!][!//
      [!BREAK!]
    [!ENDIF!]
  [!ENDFOR!]
  [!VAR "MaskValuecorrect" = "num:i(0)"!][!//
  [!VAR "MaskValuewrong" = "num:i(0)"!][!//
  [!VAR "Mask" = "DioPortMask"!][!//
  [!VAR "Mask" = "num:i(bit:shr($Mask,$PortOffset))"!][!//
  [!FOR "Index" = "num:i(0)" TO "num:i(15 - $PortOffset)"!][!//
  [!VAR "MaskValuecorrect" = "num:i(bit:and(num:i(1),num:i($Mask)))"!][!//
  [!IF "$MaskValuecorrect = num:i(1)"!][!//
  [!IF "$MaskValuewrong = num:i(1)"!][!//
  [!ERROR!][!//
   Config Error: Set the mask value which have only adjoining one's in the Group [!"DioChannelGroupIdentification"!]
  [!ENDERROR!][!//
  [!ENDIF!][!//
  [!ELSE!][!//
  [!VAR "MaskValuewrong" = "num:i(1)"!][!//
  [!ENDIF!][!//
  [!VAR "Mask" = "num:i(bit:shr($Mask,1))"!][!//
  [!ENDFOR!][!//
[!ENDLOOP!][!/*LOOP "./DioChannelGroup/*"*/!][!//
[!ENDLOOP!][!/*LOOP "DioPort/*"*/!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetUserDefinedSymbolicNames2

  Macro to validate the DioPort, DioChannel and DioChannelGroup.

  Input Parameters: Instance
*****************************************************************************/!]
[!MACRO "CG_GetUserDefinedSymbolicNames2", "Instance" = ""!][!//
[!NOCODE!][!//
[!/* Loop for all DioPort containers to generate symbolic names for the Port,
     Channels under this port & Channel groups under this port */!][!//
[!LOOP "DioConfig/*[num:i($Instance)]/DioPort/*"!][!//
[!//
[!/* Check if the Port Id. is valid. */!][!//
[!CALL "CG_CheckPortIdValidity", "PortId" = "num:i(./DioPortId)"!][!//
[!//
[!/* Generate Symbolic names for Dio channels under this port */!][!//
[!LOOP "./DioChannel/*"!][!//
[!//
[!/* Check for validity of the configured channel id*/!][!//
[!CALL "CG_CheckChannelIdValidity", "PortId" = "num:i(../../DioPortId)", "ChannelId" = "num:i(./DioChannelId)"!][!//
[!//
[!ENDLOOP!][!//
[!//
[!/* Generate Symbolic names for Dio channel groups under this port */!][!//
[!LOOP "./DioChannelGroup/*"!][!//
[!//
[!/* Check for validity of Mask */!][!//
[!CALL "CG_CheckChannelGroupMaskValidity", "GroupName" = "DioChannelGroupIdentification", "PortId" = "../../DioPortId", "MaskValue" = "num:i(DioPortMask)"!][!//
[!//
[!//
[!ENDLOOP!][!/*LOOP "DioChannelGroup/*"*/!][!//
[!ENDLOOP!][!/*LOOP "DioPort/*"*/!][!//
[!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

