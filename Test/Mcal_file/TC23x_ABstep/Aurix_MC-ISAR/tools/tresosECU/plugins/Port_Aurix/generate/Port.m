[!/*
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
**  $FILENAME   : Port.m $                                                   **
**                                                                            **
**  $CC VERSION : \main\dev_tc23x\5 $                                        **
**                                                                            **
**  $DATE       : 2015-02-11 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains code generator macros                   **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_Port_Driver,Release  4.0.3 ,3.2.1          **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
*/!]

[!/*****************************************************************************
MACRO: CG_ConfigSwitch
Macro to generate configuration switch Values ON/OFF based on configuration
true/false
******************************************************************************/!]
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]

[!/*****************************************************************************
  Macro: CG_ConfigurationCheck

  Macro to determine if the configuration for Port module is correct or not.
*****************************************************************************/!]
[!MACRO "CG_ConfigurationCheck"!][!//
[!NOCODE!][!//
[!//
[!/* Determine if there is any Port pin whose direction is changeable,*/!]
[!/* when the general setting doesn't allow for direction changeable pins */!]
[!IF "PortGeneral/PortSetPinDirectionApi = 'true'"!][!//
  [!//
  [!/* ConfigOk = 0 indicates all pins are direction not changeable */!][!//
  [!VAR "ConfigOk" = "num:i(0)"!][!//
  [!VAR "ConfigCount" = "num:i(count(PortConfigSet/*))"!][!//

  [!FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"!][!//
    [!//
    [!/* Scan through the Port Pins other than the read only ports */!][!//
    [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*"!][!//
      [!//
      [!IF "not( contains( ecu:get('Port.AvailableReadOnlyPorts'), concat('_', bit:shr(num:i(bit:and(PortPinId,640)), 4), '_' )) )"!][!//
        [!IF "PortPinDirectionChangeable = 'true'"!][!//
          [!VAR "ConfigOk" = "num:i(1)"!][!/* One of the pins is direction changeable*/!][!//
          [!BREAK!][!//
        [!ENDIF!][!//
      [!ENDIF!][!//
      [!//
    [!ENDLOOP!][!//
    [!//
    [!IF "num:i($ConfigOk) = num:i(1)"!][!//
      [!BREAK!][!//
    [!ENDIF!][!//
    [!//
  [!ENDFOR!][!/*FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"*/!][!//

  [!ASSERT "not(num:i($ConfigOk) = num:i(0))"!][!//
Config Error: PortGeneral/PortSetPinDirectionApi is set as true,[!//
but PortPinDirectionChangeable of none of the I/O port pins of is set to true![!//
  [!ENDASSERT!][!//
  [!//
[!ENDIF!][!/* IF "PortGeneral/PortSetPinDirectionApi = 'true'" */!][!//
[!//
[!/* Determine if there is any Port pin whose mode is changeable,*/!]
[!/* when the general setting doesn't allow for mode changeable pins */!]
[!IF "PortGeneral/PortSetPinModeApi = 'true'"!][!//
  [!//
  [!/* ConfigOk = 0 indicates all pins are mode not changeable */!][!//
  [!VAR "ConfigOk" = "num:i(0)"!][!//
  [!VAR "ConfigCount" = "num:i(count(PortConfigSet/*))"!][!//

  [!FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"!][!//
    [!//
    [!/* Scan through the Port Pins other than the read only ports */!][!//
    [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*"!][!//
      [!//
      [!IF "not( contains( ecu:get('Port.AvailableReadOnlyPorts'), concat('_', bit:shr(num:i(bit:and(PortPinId,640)), 4), '_' )) )"!][!//
        [!IF "PortPinModeChangeable = 'true'"!][!//
          [!VAR "ConfigOk" = "num:i(1)"!][!/* One of the pins is mode changeable*/!][!//
          [!BREAK!][!//
        [!ENDIF!][!//
      [!ENDIF!][!//
      [!//
    [!ENDLOOP!][!//
    [!//
    [!IF "num:i($ConfigOk) = num:i(1)"!][!//
      [!BREAK!][!//
    [!ENDIF!][!//
    [!//
  [!ENDFOR!][!/*FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"*/!][!//

  [!ASSERT "not(num:i($ConfigOk) = num:i(0))"!][!//
Config Error: PortGeneral/PortSetPinModeApi is set as true,[!//
but PortPinModeChangeable of none of the I/O port pins of is set to true![!//
  [!ENDASSERT!][!//
  [!//
[!ENDIF!][!/* IF "PortGeneral/PortSetPinModeApi = 'true'" */!][!//


[/*To check if the Port has Correct Port Number*/]

[!VAR "ConfigCount" = "num:i(count(PortConfigSet/*))"!][!//
[!FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"!][!//

[/*To check if No of PortPins configured are valid*/]

  [!/* Scan through the Port Pins other than the read only ports */!][!//
  [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*"!][!//
    [!IF "num:i(count(../*)) != ecu:get('Port.TotalNumOfPort')"!][!//
      [!ERROR!][!//
   At "PortConfigSet/[!"../../@name"!]/PortContainer/[!"@name"!]",
  Number of Ports configured is not proper, there should be [!"ecu:get('Port.TotalNumOfPort')"!] Ports configured
      [!ENDERROR!][!//
    [!ENDIF!]
    [!IF "not(contains(ecu:get('Port.PortsAvailable'),concat('_',./PortNumber,'_')))"!][!//
      [!ERROR!][!//
   At "PortConfigSet/[!"../../@name"!]/PortContainer/[!"@name"!]",
  Port[!"node:value(./PortNumber)"!] is not available for the MC.
      [!ENDERROR!][!//
    [!ENDIF!]
  [!ENDLOOP!][!//

[/*To check if the Port has Correct PortNumberOfPortPins*/]

  [!/* Scan through the Port Pins other than the read only ports */!][!//
  [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*"!][!//
    [!IF "num:i(count(text:split(ecu:get(concat('Port.Port',./PortNumber,'_AvailablePins')),' '))) != num:i(./PortNumberOfPortPins)"!][!//
      [!ERROR!][!//
   At "PortConfigSet/[!"../../@name"!]/PortContainer/[!"@name"!]",
  Port_[!"./PortNumber"!] should have [!"num:i(count(text:split(ecu:get(concat('Port.Port',./PortNumber,'_AvailablePins')),' ')))"!]pins
      [!ENDERROR!][!//
    [!ENDIF!]
  [!ENDLOOP!][!//

  [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*"!][!//
  [!IF "num:i(count(../*)) != ../../PortNumberOfPortPins"!]
      [!ERROR!][!//
   At "PortConfigSet/[!"../../../../@name"!]/PortContainer/[!"../../@name"!]/PortPin/[!"@name"!]",
The Number of Pins configured for the Port[!"../../PortNumber"!] is not valid. There should be [!"../../PortNumberOfPortPins"!]pins configured
      [!ENDERROR!][!//
  [!ENDIF!]
  [!ENDLOOP!][!//

[!ENDFOR!][!/*FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"*/!][!//

[!/*To check if the PortPinMode is defined more than one for a portpin*/!]

[!VAR "ConfigCount" = "num:i(count(PortConfigSet/*))"!][!//
[!FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"!][!//
  [!/* Scan through the Port Pins other than the read only ports */!][!//
  [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*/PortPinMode/*"!][!//
    [!IF "
     contains(substring-before(concat(text:join(../*, ','), ','), concat(., ',')), concat(., ',')) = 'true'
     or
     contains(substring-after(concat(text:join(../*, ','), ','), concat(., ',')), concat(., ',')) = 'true'
     "!][!//
      [!ERROR!][!//
At "PortConfigSet/[!"../../../../../../@name"!]/PortContainer/[!"../../../../@name"!]/PortPin/[!"../../@name"!]/PortPinMode/",
[!"node:value(.)"!] should be defined only once for [!"../../PortPinSymbolicName"!]
      [!ENDERROR!][!//
    [!ENDIF!]
  [!ENDLOOP!][!//

[!/* To check there should be only one mode available if PORT_PIN_MODE_ALL is selected */!]

[!/* Scan through the Port Pins other than the read only ports */!][!//
  [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*/PortPinMode/*"!][!//
    [!IF "
      (contains(substring-before(concat(text:join(../*, ','), ','), concat(., ',')), 'PORT_PIN_MODE_ALL')
      or
      contains(substring-after(concat(text:join(../*, ','), ','), concat(., ',')), 'PORT_PIN_MODE_ALL'))
      and
      (count(../*) > 1)
      "!][!//
      [!ERROR!][!//
At "PortConfigSet/[!"../../../../../../@name"!]/PortContainer/[!"../../../../@name"!]/PortPin/[!"../../@name"!]/PortPinMode/",
PORT_PIN_MODE_ALL selects all the modes available for [!"../../PortPinSymbolicName"!], no need to add any other modes
      [!ENDERROR!][!//
    [!ENDIF!]
  [!ENDLOOP!][!//

[!/*To Check if the Mode is available for the PortPin*/!]

[!/* Scan through the Port Pins other than the read only ports */!][!//
  [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*/PortPinMode/*"!][!//
    [!IF "
        contains(ecu:get(concat('Port.InitialModes',(../../../../PortNumber),'_',((../../PortPinId) mod 16))),
        concat(substring-after(.,'PORT_PIN_MODE_'),' = RESERVED'))
         "!][!//
      [!ERROR!][!//
At "PortConfigSet/[!"../../../../../../@name"!]/PortContainer/[!"../../../../@name"!]/PortPin/[!"../../@name"!]/PortPinMode/",
[!"node:value(.)"!] is not available for [!"../../PortPinSymbolicName"!]
      [!ENDERROR!][!//
    [!ENDIF!]
  [!ENDLOOP!][!//





[!ENDFOR!][!/*FOR "Instance" ="num:i(1)" TO "num:i($ConfigCount)"*/!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!/* End of macro CG_ConfigurationCheck */!][!//

[!/*****************************************************************************
  MACRO: CG_GetPortPinSymbolicName
  Sets the symbolic name of each Port Pin.

  Input Prameters:
  port     : The Port Id
*****************************************************************************/!]
[!MACRO "CG_GetPortPinSymbolicName", "port" = "", "Instance" = ""!][!//
[!VAR "pinstart" = "num:i(0)"!][!//
[!VAR "pinend" = "num:i(15)"!][!//
[!//
[!/* Code for AS4.0 */!][!//
[!VAR "DirectionChangesAllowed" = "PortGeneral/PortSetPinDirectionApi"!][!//
[!VAR "ModeChangesAllowed" = "PortGeneral/PortSetPinModeApi"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($pinstart)"!][!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//

/* Symbolic Name: Port[!"num:i($port)"!] Pin[!"num:i($PortPinNo)"!] */
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!VAR "SymbolicName" = "PortPinSymbolicName"!][!//
[!VAR "SymbolicName" = "normalize-space($SymbolicName)"!][!//
/* To prevent double declaration */
#ifndef  [!"$SymbolicName"!]
#define [!"$SymbolicName"!]                          ((Port_PinType)([!"num:inttohex($PinId, 3)"!]))
#endif
[!//
[!NOCODE!][!//
[!ASSERT "not(PortPinDirection = 'PORT_PIN_IN' and PortPinInitialMode != 'PORT_PIN_MODE_GPIO')"!]
Config Error: [!"$SymbolicName"!] is configured as Input Direction Pin, [!//
but the configuration: PortPinInitialMode is not set as PORT_PIN_MODE_GPIO!
[!ENDASSERT!][!//
[!IF "PortPinDirectionChangeable = 'true' and not( contains( ecu:get('Port.AvailableReadOnlyPorts'), concat('_', bit:shr(num:i(bit:and(PortPinId,640)), 4), '_' )) )"!][!//
[!ASSERT "not($DirectionChangesAllowed = 'false')"!][!//
Config Error: [!"$SymbolicName"!] of PortConfigSet_[!"num:i(string($Instance)- num:i(1))"!] is configured as Direction Changeable Pin, [!//
but the configuration: PortSetPinDirectionApi is set as false![!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!IF "PortPinModeChangeable = 'true' and not( contains( ecu:get('Port.AvailableReadOnlyPorts'), concat('_', bit:shr(num:i(bit:and(PortPinId,640)), 4), '_' )) )"!][!//
[!ASSERT "not($ModeChangesAllowed = 'false')"!][!//
Config Error: [!"$SymbolicName"!] of PortConfigSet_[!"num:i(string($Instance)- num:i(1))"!] is configured as Mode Changeable Pin, [!//
but the configuration: PortSetPinModeApi is set as false![!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!VAR "PinId" = "num:i($PinId) + num:i(1)"!][!//
[!ENDFOR!][!//
[!//
[!ENDMACRO!]!//

[!/******************************************************************************
MACRO: CG_GetPortPinDirectionAndModeAttributes
Gets the Port Pin attributes : Direction, Characteristic and pin mode.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinDirectionAndModeAttributes", "port"="", "Index"="", "Instance" = ""!][!//
[!//
[!NOCODE!]
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!//
[!ASSERT "not(num:i($port) = num:i(20) and num:i($PortPinNo) = num:i(2) and PortPinDirection = 'PORT_PIN_OUT')"!][!//
Config Error: [!"@name"!](P20.2) is configured as PORT_PIN_OUT, [!//
But [!"@name"!](P20.2) has to be configured as PORT_PIN_IN(GPI) only.[!//
[!ENDASSERT!][!//
[!IF "PortPinModeChangeable = 'true'"!][!//
[!IF "(../../PortNumber != num:i(40)) and (../../PortNumber != num:i(41)) "!][!//
[!VAR "PinInitialMode" = "PortPinInitialMode"!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!LOOP "./PortPinMode/*"!][!//
  [!IF "text:contains('PORT_PIN_MODE_ALL',.)"!][!//
    [!VAR "ErrorFlag" = "num:i(0)"!][!//
    [!BREAK!][!//
  [!ELSEIF "text:contains($PinInitialMode,.)"!][!//
    [!VAR "ErrorFlag" = "num:i(0)"!][!//
    [!BREAK!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i($ErrorFlag) = num:i(1)"!][!//
  [!ERROR!][!//
At "PortConfigSet/[!"../../../../@name"!]/PortContainer/[!"../../@name"!]/PortPin/[!"@name"!]/PortPinMode]",
The mode [!"./PortPinInitialMode"!] is not available in the PortPinMode list for [!"./PortPinSymbolicName"!]
  [!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!//
[!CODE!][!//
         ((uint8)[!"PortPinDirection"!] | [!//
[!ENDCODE!][!//
[!IF "PortPinDirection = 'PORT_PIN_IN'"!][!//
[!CODE!][!//
[!"PortPinInputCharacteristic"!] | [!//
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
[!"PortPinOutputCharacteristic"!] | [!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!CODE!][!//
[!"PortPinInitialMode"!])[!//
[!ENDCODE!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
[!CODE!][!//
         (PORT_PIN_DEFAULT)[!//
[!ENDCODE!][!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
[!CODE!][!//
,/*Pin [!"num:i($PortPinNo)"!]*/
[!ENDCODE!][!//
[!ELSE!][!//
[!CODE!][!//
 /*Pin [!"num:i($PortPinNo)"!]*/ [!//
[!ENDCODE!][!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//
[!/******************************************************************************
MACRO: CG_GetPortPinLevelAttributes
Gets the Port Pin attributes : Direction, Characteristic and pin mode.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinLevelAttributes", "port"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!IF "PortPinLevelValue = 'PORT_PIN_LEVEL_LOW'"!][!//
         PORT_PIN_LOW[!//
[!ELSE!][!//
         PORT_PIN_HIGH[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
         0U[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
,/* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ELSE!][!//
 /* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//
[!/******************************************************************************
MACRO: CG_GetPortPinModeChangeable
Gets the Port Pin attributes : Direction, Characteristic and pin mode.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinModeChangeable", "port"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!IF "PortPinModeChangeable = 'true'"!][!//
         PORT_PIN_MODE_CHANGEABLE[!//
[!ELSE!][!//
         PORT_PIN_MODE_NOT_CHANGEABLE[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
         PORT_PIN_MODE_NOT_CHANGEABLE[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
,/* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ELSE!][!//
 /* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//
[!/******************************************************************************
MACRO: CG_GetPortPinDirectionChangeable
Gets the Port Pin attributes : Direction, Characteristic and pin mode.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinDirectionChangeable", "port"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!IF "PortPinDirectionChangeable = 'true'"!][!//
         PORT_PIN_DIR_CHANGEABLE[!//
[!ELSE!][!//
         PORT_PIN_DIR_NOT_CHANGEABLE[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
         PORT_PIN_DIR_NOT_CHANGEABLE[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
,/* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ELSE!][!//
 /* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!/******************************************************************************
MACRO: CG_GetPortPinDirectionChangeableAttributes
Gets the Port Pin attributes : Direction, Characteristic and pin mode.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinDirectionChangeableAttributes", "port"="", "Index"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!//
[!NOCODE!][!//
[!IF "PortPinDirectionChangeable = 'true'"!][!//
[!VAR "ErrorFlag" = "num:i(1)"!][!//
[!LOOP "./PortPinMode/*"!][!//
  [!IF "text:contains(.,'PORT_PIN_MODE_ALL')"!][!//
    [!VAR "ErrorFlag" = "num:i(0)"!][!//
    [!BREAK!][!//
  [!ELSEIF "text:contains(.,'PORT_PIN_MODE_GPIO')"!]
    [!VAR "ErrorFlag" = "num:i(0)"!][!//
    [!BREAK!][!//
  [!ENDIF!][!//
[!ENDLOOP!][!//
  [!IF "num:i($ErrorFlag) = num:i(1)"!][!//
    [!ERROR!][!//
At "PortConfigSet/[!"../../../../@name"!]/PortContainer/[!"../../@name"!]/PortPin/[!"@name"!]/PortPinMode]",
For [!"./PortPinSymbolicName"!] "PortPindirectionChangeable" is true and "PortPinMode" list does not have GPIO as a supported Mode
    [!ENDERROR!][!//
  [!ENDIF!][!//
[!ENDIF!][!//[!//
[!ENDNOCODE!][!//
[!IF "PortPinDirectionChangeable = 'false'"!][!//
[!IF "PortPinDirection = 'PORT_PIN_IN'"!][!//
         ((uint8)PORT_PIN_IN | [!//
[!"PortPinInputCharacteristic"!] | [!//
[!ELSE!][!//
         ((uint8)PORT_PIN_OUT | [!//
[!"PortPinOutputCharacteristic"!] | [!//
[!ENDIF!][!//
[!"PortPinInitialMode"!])[!//
[!ELSE!][!//
[!IF "PortPinDirection = 'PORT_PIN_IN'"!][!//
         ((uint8)PORT_PIN_OUT | [!//
[!"PortPinOutputCharacteristic"!] | [!//
[!ELSE!][!//
         ((uint8)PORT_PIN_IN | [!//
[!"PortPinInputCharacteristic"!] | [!//
[!ENDIF!][!//
PORT_PIN_MODE_GPIO)[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
         (PORT_PIN_DEFAULT)[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
,/*Pin [!"num:i($PortPinNo)"!]*/ [!//
[!ELSE!][!//
 /*Pin [!"num:i($PortPinNo)"!]*/ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//
[!/******************************************************************************
MACRO: CG_GetPortPinDriverStrength1
Gets the Port Pin attributes : Level and Strength.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinDriverStrength1", "port"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "7"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!VAR "PadStrength" = "PortPinDriverStrength"!][!//
[!VAR "PadLevel" = "PortPinPadLevel"!][!//
         ([!"$PadLevel"!] | [!"$PadStrength"!])[!//
[!ENDSELECT!][!//
[!ELSE!][!//
         (PORT_PIN_PAD_LEVEL_DEFAULT)[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(7)"!][!//
,/* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ELSE!][!//
 /* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//
[!/******************************************************************************
MACRO: CG_GetPortPinDriverStrength2
Gets the Port Pin attributes : Port pin Level and strength.
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinDriverStrength2", "port"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "8" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!VAR "PadStrength" = "PortPinDriverStrength"!][!//
[!VAR "PadLevel" = "PortPinPadLevel"!][!//
         ([!"$PadLevel"!] | [!"$PadStrength"!])[!//
[!ENDSELECT!][!//
[!ELSE!][!//
         (PORT_PIN_PAD_LEVEL_DEFAULT)[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
,/* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ELSE!][!//
 /* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//


[!/******************************************************************************
MACRO: CG_GetPortPinAnalogInputSelection
Gets the Port Pin attributes : Analog input Enabled or not
Input Prameters:
port: The Port Id
pinstart: The Starting Pin id of the Port
pinend: The ending Pin id of the Port
******************************************************************************/!]
[!MACRO "CG_GetPortPinAnalogInputSelection", "port"="", "Instance" = ""!][!//
[!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
[!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
[!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//
[!IF "node:exists(PortConfigSet/*[',$Instance,']/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
[!/*
  Select the container for the calculated PinId to extract the configuration
*/!][!//
[!SELECT "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]"!][!//
[!IF "PortPinAnalogInput  = 'ENABLE'"!][!//
                 PORT_PIN_ANALOG_INPUT_ENABLE[!//
[!ELSE!][!//
                 PORT_PIN_ANALOG_INPUT_DISABLE[!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ELSE!][!//
                 PORT_PIN_ANALOG_INPUT_DISABLE[!//
[!ENDIF!][!//
[!IF "num:i($PortPinNo) != num:i(15)"!][!//
,/* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ELSE!][!//
 /* Pin [!"num:i($PortPinNo)"!] */ [!//
[!ENDIF!]
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetAvailablePorts00to31

  Macro to generate definition to indicate the ports that are available in the
  microcontroller

  Notes:
  The macro checks for the string Port_AvailablePorts for the ports that are
  available and the corresponding bits within the printed definition are set
  for all existing ports

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetAvailablePorts00to31"!][!//
[!NOCODE!][!//

  [!VAR "AvailablePorts" = "num:i(0)"!][!//

  [!FOR "PortNumber" = "0" TO "31"!]
    [!IF "(contains( ecu:get('Port.PortsAvailable'), concat('_', $PortNumber , '_' )))"!][!//
      [!VAR "AvailablePorts" = "bit:bitset($AvailablePorts, $PortNumber)"!][!//
    [!ENDIF!]
  [!ENDFOR!]

[!ENDNOCODE!][!//
[!//
#define PORTS_AVAILABLE_00_31       ([!"num:inttohex($AvailablePorts, 8)"!]U)
[!//
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: CG_GetAvailablePorts32to63

  Macro to generate definition to indicate the ports that are available in the
  microcontroller

  Notes:
  The macro checks for the string Port_AvailablePorts for the ports that are
  available and the corresponding bits within the printed definition are set
  for all existing ports

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetAvailablePorts32to63"!][!//
[!NOCODE!][!//

  [!VAR "AvailablePorts" = "num:i(0)"!][!//

  [!FOR "PortNumber" = "32" TO "63"!]
    [!IF "(contains( ecu:get('Port.PortsAvailable'), concat('_', $PortNumber , '_' )))"!][!//
      [!VAR "AvailablePorts" = "bit:bitset($AvailablePorts, ($PortNumber - 32))"!][!//
    [!ENDIF!]
  [!ENDFOR!]

[!ENDNOCODE!][!//
[!//
#define PORTS_AVAILABLE_32_63       ([!"num:inttohex($AvailablePorts, 8)"!]U)
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

  [!FOR "PortNumber" = "0" TO "31"!]
    [!IF "(contains( ecu:get('Port.AvailableReadOnlyPorts'), concat('_', $PortNumber , '_' )))"!][!//
      [!VAR "ReadOnlyPorts" = "bit:bitset($ReadOnlyPorts, $PortNumber)"!][!//
    [!ENDIF!]
  [!ENDFOR!]

[!ENDNOCODE!][!//
#define PORTS_READONLY_00_31        ([!"num:inttohex($ReadOnlyPorts, 8)"!]U)
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetReadOnlyPorts32to63

  Macro to generate definition to indicate the read only ports of the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetReadOnlyPorts32to63"!][!//
[!NOCODE!][!//

  [!VAR "ReadOnlyPorts" = "num:i(0)"!][!//

  [!FOR "PortNumber" = "32" TO "63"!]
    [!IF "(contains( ecu:get('Port.AvailableReadOnlyPorts'), concat('_', $PortNumber , '_' )))"!][!//
      [!VAR "ReadOnlyPorts" = "bit:bitset($ReadOnlyPorts, ($PortNumber - 32))"!][!//
    [!ENDIF!]
  [!ENDFOR!]

[!ENDNOCODE!][!//
#define PORTS_READONLY_32_63        ([!"num:inttohex($ReadOnlyPorts, 8)"!]U)
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetAvailablePortPins

  Macro to generate definition to indicate the port pins that are available
  in the microcontroller

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetAvailablePortPins"!][!//
[!FOR "PortNumber" = "0" TO "num:i(ecu:get('Port.MaxAvailablePort'))"!][!//
[!VAR "Port_Temp" = "num:i(0)"!][!//
[!IF "contains( ecu:get('Port.PortsAvailable'), concat('_', $PortNumber , '_' ))"!][!//
[!FOR "PinNumber" = "0" TO "15"!][!//
[!IF "(contains( ecu:get(concat('Port.Port',$PortNumber,'_AvailablePins')), concat('_', $PinNumber , '_' )))"!][!//
[!VAR "Port_Temp" = "bit:bitset(num:i($Port_Temp), $PinNumber)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
#define PORT_AVAILABLE_PINS_PORT[!"$PortNumber"!]  ([!"num:inttohex($Port_Temp, 4)"!]U)
[!ENDFOR!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: CG_GetMaxPortNum
  Macro to generate definition to indicate the port pins that are available
  in the microcontroller
  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetMaxPortNum"!][!//
#define PORT_MAX_NUMBER             ([!"num:i(ecu:get('Port.MaxAvailablePort'))"!]U)
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: CG_GetMaxAvailablePortPinId
  Macro to generate the value for Maximum available port on the uC
  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetMaxAvailablePortPinId"!][!//
[!//
#define PORT_MAX_PIN_ID             ([!"num:inttohex(bit:or(bit:shl(num:i(ecu:get('Port.MaxAvailablePort')),num:i(4)),num:i(15)))"!]U)
[!//
[!ENDMACRO!][!//
[!/*****************************************************************************
  Macro: CG_GetNumOfPorts
  Macro to generate the value for Maximum available port on the uC
  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetNumOfPorts"!][!//
[!//
#define PORT_MAX_NUM                ([!"ecu:get('Port.TotalNumOfPort')"!]U)
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
MACRO: CG_GetPortPinMode
Sets the array for the modes supported by the port pin
Input Prameters:
port: The Port Id
*****************************************************************************/!]
[!MACRO "CG_GetPortPinMode", "port" = "", "Instance" = ""!][!//
[!NOCODE!][!//
[!FOR "PortPinNo" = "0" TO "15"!][!//
  [!VAR "PinId" = "num:i($port) * num:i(16)"!][!//
  [!VAR "PinId" = "num:i($PinId) + num:i($PortPinNo)"!][!//

    [!IF "node:exists(PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)])"!][!//
                [!VAR "PortPinHwSupportModes" = "num:i(0)"!][!//

                [!LOOP "PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:i($PinId)]/PortPinMode/*"!][!//

                  [!IF ". = 'PORT_PIN_MODE_GPIO'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(1))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT1'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(2))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT2'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(4))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT3'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(8))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT4'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(16))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT5'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(32))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT6'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(64))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALT7'"!][!//
                    [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,num:i(128))"!][!//
                  [!ELSEIF ". = 'PORT_PIN_MODE_ALL'"!][!//
                    [!VAR "CurPortPinHwSupportModes"= "num:i(1)"!][!//
                    [!VAR "PortPinHwSupportModes"= "$CurPortPinHwSupportModes"!][!//
                      [!FOR "PortPinModeIndex" = "1" TO "7"!][!//
                      [!VAR "CurPortPinHwSupportModes"= "bit:shl($CurPortPinHwSupportModes,num:i(1))"!][!//
                        [!IF "
                          not(contains(ecu:get(concat('Port.InitialModes',(../../../../PortNumber),'_',((../../PortPinId) mod 16))),
                            concat('ALT',$PortPinModeIndex,' = RESERVED'))
                             )
                        "!][!//
                        [!VAR "PortPinHwSupportModes"= "bit:or($PortPinHwSupportModes,$CurPortPinHwSupportModes)"!][!//
                        [!ENDIF!]
                      [!ENDFOR!]
                  [!ENDIF!]
                [!ENDLOOP!][!//
[!CODE!][!//
      (uint8)([!"num:inttohex($PortPinHwSupportModes, 2)"!]U)[!//
[!ENDCODE!][!//
                [!IF "num:i($PortPinNo) != num:i(15)"!][!//
[!CODE!][!//
,/*Pin[!"num:i($PortPinNo)"!]*/
[!ENDCODE!][!//
                [!ELSE!][!//
[!CODE!][!//
 /*Pin[!"num:i($PortPinNo)"!]*/[!//
[!ENDCODE!][!//
                [!ENDIF!][!//
    [!ELSE!][!//
[!CODE!][!//
      (uint8)(0x00U)[!//
[!ENDCODE!][!//
        [!IF "num:i($PortPinNo) != num:i(15)"!][!//
[!CODE!][!//
,/*Pin[!"num:i($PortPinNo)"!]*/
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
 /*Pin[!"num:i($PortPinNo)"!]*/[!//
[!ENDCODE!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetPCSRPads
  Macro to generate Port_PCSRConfigType for all the Ports
  Input Parameters: Configset instance.
  None
*****************************************************************************/!]
[!MACRO "CG_GetPCSRPads", "Instance" = ""!][!//
[!NOCODE!][!//
[!VAR "counter" = "num:i(num:add(count(text:split(ecu:get('Port.AvailablePCSREth'),' ')),count(text:split(ecu:get('Port.AvailablePCSRVADC'),' '))))"!]
[!SELECT "as:modconf('Port')[1]"!][!//
  [!LOOP "node:order(PortConfigSet/*[num:i($Instance)]/PortContainer/*,'node:value(./PortNumber)')"!][!//
    [!IF "contains(ecu:get('Port.AvailablePCSREth'),concat('_',./PortNumber,'_')) or
          contains(ecu:get('Port.AvailablePCSRVADC'),concat('_',./PortNumber,'_'))"!]
      [!VAR "counter" = "num:i(num:sub($counter,1))"!]
[!CODE!][!//

               /*           Port[!"./PortNumber"!]            */
   Port_lPcsr(
[!ENDCODE!][!//
      [!FOR "PortPinNo" = "0" TO "15"!][!//
          [!IF "text:contains(text:split(ecu:get(concat('Port.Port',./PortNumber,'_AvailablePinPCSR')),' '),$PortPinNo)"!]
            [!VAR "PortHolder" = "num:i(./PortNumber)"!]
            [!SELECT "as:modconf('Port')[1]/PortConfigSet/*[num:i($Instance)]/PortContainer/*/PortPin/*[PortPinId = num:add(num:mul($PortHolder,16),$PortPinNo)]"!][!//
              [!IF "./PortPinControllerSelect = 'DISABLE'"!]
                [!IF "$PortPinNo = num:i(15)"!]
[!CODE!][!//
               PORT_PCSR_DISABLE   /*Pin[!"$PortPinNo"!]*/
[!ENDCODE!][!//
                [!ELSE!]
[!CODE!][!//
               PORT_PCSR_DISABLE,  /*Pin[!"$PortPinNo"!]*/
[!ENDCODE!][!//
                [!ENDIF!]
              [!ELSE!]
                [!IF "$PortPinNo = num:i(15)"!]
[!CODE!][!//
               PORT_PCSR_ENABLE    /*Pin[!"$PortPinNo"!]*/
[!ENDCODE!][!//
                [!ELSE!]
[!CODE!][!//
               PORT_PCSR_ENABLE,   /*Pin[!"$PortPinNo"!]*/
[!ENDCODE!][!//
                [!ENDIF!]
              [!ENDIF!]
            [!ENDSELECT!]
          [!ELSE!]
            [!IF "$PortPinNo = num:i(15)"!]
[!CODE!][!//
               PORT_PCSR_DEFAULT   /*Pin[!"$PortPinNo"!]*/
[!ENDCODE!][!//
            [!ELSE!]
[!CODE!][!//
               PORT_PCSR_DEFAULT,  /*Pin[!"$PortPinNo"!]*/
[!ENDCODE!][!//
            [!ENDIF!]
          [!ENDIF!]
      [!ENDFOR!]
          [!IF "$counter = num:i(0)"!]
[!CODE!][!//
              )
[!ENDCODE!][!//
          [!ELSE!]
[!CODE!][!//
              ),
[!ENDCODE!][!//
          [!ENDIF!]
    [!ENDIF!]
 [!ENDLOOP!]
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!//
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetPCSRPorts00to31

  Macro to generate definition to indicate the read only ports of the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetPCSRPorts00to31"!][!//
[!NOCODE!][!//

  [!VAR "PCSROnlyPorts" = "num:i(0)"!][!//

  [!FOR "PortNumber" = "0" TO "31"!]
    [!IF "(contains( ecu:get('Port.AvailablePCSREth'), concat('_', $PortNumber , '_' )))
           or
          (contains( ecu:get('Port.AvailablePCSRVADC'), concat('_', $PortNumber , '_' )))"!][!//
      [!VAR "PCSROnlyPorts" = "bit:bitset($PCSROnlyPorts, $PortNumber)"!][!//
    [!ENDIF!]
  [!ENDFOR!]

[!ENDNOCODE!][!//
#define PORTS_PCSR_00_31        ([!"num:inttohex($PCSROnlyPorts, 8)"!]U)
[!ENDMACRO!][!//

[!/*****************************************************************************
  Macro: CG_GetPCSRPorts32to63

  Macro to generate definition to indicate the read only ports of the uC

  Input Parameters:
  None
*****************************************************************************/!]
[!MACRO "CG_GetPCSRPorts32to63"!][!//
[!NOCODE!][!//

  [!VAR "PCSROnlyPorts" = "num:i(0)"!][!//

  [!FOR "PortNumber" = "32" TO "63"!]
    [!IF "(contains( ecu:get('Port.AvailablePCSREth'), concat('_', $PortNumber , '_' )))
           or
          (contains( ecu:get('Port.AvailablePCSRVADC'), concat('_', $PortNumber , '_' )))"!][!//
      [!VAR "PCSROnlyPorts" = "bit:bitset($PCSROnlyPorts, ($PortNumber - 32))"!][!//
    [!ENDIF!]
  [!ENDFOR!]

[!ENDNOCODE!][!//
#define PORTS_PCSR_32_63        ([!"num:inttohex($PCSROnlyPorts, 8)"!]U)
[!ENDMACRO!][!//

[!/*****************************************************************************/!]
