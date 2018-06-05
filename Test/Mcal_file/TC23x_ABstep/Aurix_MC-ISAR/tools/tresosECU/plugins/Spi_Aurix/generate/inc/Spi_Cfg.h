[!/****************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2015)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Spi_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\85 $                                                 **
**                                                                           **
**  $DATE       : 2016-05-13 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : Code template for Spi_Cfg.h file                          **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
*************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID= DS_AS_SPI199_Conf, DS_AS_SPI198_Conf,
DS_AS_SPI197_Conf, DS_NAS_SPI_PR700, DS_NAS_SPI_PR701, DS_NAS_SPI_PR704,
DS_NAS_SPI_PR707, DS_NAS_SPI_PR712, DS_NAS_SPI_PR713,
DS_NAS_SPI_PR714, DS_NAS_SPI_PR716, DS_NAS_SPI_PR717, DS_NAS_SPI_PR723,
DS_NAS_SPI_PR724, DS_NAS_SPI_PR728,
DS_NAS_HE2_SPI_PR2966_1,DS_NAS_EP_SPI_PR2966_1,
DS_NAS_SPI_PR708, SAS_NAS_SPI_PR127, DS_NAS_SPI_PR69_PR469,
DS_AS4XX_SPI_PR2849, DS_AS403_SPI191,SAS_AS4XX_SPI_PR678,
SAS_NAS_SPI_PR914,SAS_NAS_SPI_PR915,
SAS_MCAL_SPI_9853, SAS_NAS_HE2_SPI_PR2954, SAS_NAS_EP_SPI_PR2954,
DS_NAS_HE2_SPI_PR3024_1, DS_NAS_EP_SPI_PR3024_1,DS_NAS_EP_SPI_PR3054_1,
DS_NAS_HE2_SPI_PR3054_1,DS_NAS_EP_SPI_PR3054_2,
DS_NAS_HE2_SPI_PR3054_2,,DS_NAS_EP_SPI_PR3054_3,DS_NAS_HE2_SPI_PR3054_3,
DS_NAS_EP_SPI_PR3054_4,DS_NAS_HE2_SPI_PR3054_4]
[/cover]                                                                */!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2015)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Spi_Cfg.h                                                     **
**                                                                            **
**  $CC VERSION : \main\85 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : SPI configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/
#ifndef SPI_CFG_H
#define SPI_CFG_H
/*Section to Generate Autosar Specific Version Information*/
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//
[!VAR "NewString" = "text:replaceAll($moduleReleaseVer,"\.",'')"!]

[!IF "$MajorVersion = num:i(4)"!][!//
#define SPI_AR_RELEASE_MAJOR_VERSION  ([!"$MajorVersion"!]U)
#define SPI_AR_RELEASE_MINOR_VERSION  ([!"$MinorVersion"!]U)
#define SPI_AR_RELEASE_REVISION_VERSION  ([!"$RevisionVersion"!]U)
[!ENDIF!][!//

/*Section to Generate Vendor Specific Version Information*/
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//
/* Vendor specific implementation version information */
#define SPI_SW_MAJOR_VERSION   ([!"$SwMajorVersion"!]U)
#define SPI_SW_MINOR_VERSION   ([!"$SwMinorVersion"!]U)
#define SPI_SW_PATCH_VERSION   ([!"$SwRevisionVersion"!]U)
[!/* Find the Autosar version number */!][!//
[!IF "$NewString = num:i(402)"!][!//
[!VAR "AS_Version" = "num:i(402)"!][!//
[!ELSEIF "$NewString = num:i(321)"!][!//
[!VAR "AS_Version" = "num:i(321)"!][!//
[!ELSE!][!//
[!VAR "AS_Version" = "num:i(0)"!][!//
[!ENDIF!][!//
[!//
[!//
[!IF "$MajorVersion = num:i(4)"!][!//
[!VAR "SpiDriverName" = "'SpiDriver'"!][!//
[!VAR "SpiSequenceName" = "'SpiSequence'"!][!//
[!VAR "SpiChannelName" = "'SpiChannel'"!][!//
[!VAR "SpiJobName" = "'SpiJob'"!][!//
[!VAR "SpiDevName" = "'SpiExternalDevice'"!][!//
[!VAR "SpiJobAssignmentName" = "'SpiJobAssignment'"!][!//
[!VAR "SpiDeviceAssignmentName" = "'SpiDeviceAssignment'"!][!//
[!ENDIF!][!//
[!NOCODE!]
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "TotalConfig" = "num:i(count(node:ref($SpiDriverName)/*))"!][!//
[!VAR "SafetyEnable" = "'false'"!][!//
[!IF "SpiSafety/SpiSafetyEnable = 'true'"!][!//
[!VAR "SafetyEnable" = "'true'"!][!//
[!ENDIF!][!//
[!VAR "Spi_BaudrateAtRuntime" = "SpiGeneral/SpiBaudrateConfigAtRuntime"!]
[!ENDSELECT!][!//

[!/*
MACRO: CG_ConfigSwitch
Macro to generate configuration switch Values STD_ON/STD_OFF based on configuration
true/false
*/!]
[!MACRO "CG_ConfigSwitch", "node" = ""!][!//
[!//
[!IF "$node = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!]
[!ENDMACRO!]

[!/*
MACRO: Get_MrisSelection
Macro to generate MRIS selection based on MISO port pin
*/!]
[!MACRO "Get_MrisSelection", "hwmodule" = ""!][!//
[!IF "num:i($hwmodule) = num:i(0)"!][!//
[!VAR "PortMiso" = "SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwPinConfiguration/SpiHWPinMISO"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(1)"!][!//
[!VAR "PortMiso" = "SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwPinConfiguration/SpiHWPinMISO"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(2)"!][!//
[!VAR "PortMiso" = "SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwPinConfiguration/SpiHWPinMISO"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(3)"!][!//
[!VAR "PortMiso" = "SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwPinConfiguration/SpiHWPinMISO"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(4)"!][!//
[!VAR "PortMiso" = "SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwPinConfiguration/SpiHWPinMISO"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(5)"!][!//
[!VAR "PortMiso" = "SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwPinConfiguration/SpiHWPinMISO"!][!//
[!ENDIF!][!//
[!IF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'A_') = 'true'"!][!//
(0U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'B_') = 'true'"!][!//
(1U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'C_') = 'true'"!][!//
(2U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'CN_') = 'true'"!][!//
(2U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'CP_') = 'true'"!][!//
(2U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'D_') = 'true'"!][!//
(3U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'DN_') = 'true'"!][!//
(3U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'DP_') = 'true'"!][!//
(3U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'E_') = 'true'"!][!//
(4U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'F_') = 'true'"!][!//
(5U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'FN_') = 'true'"!][!//
(5U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'FP_') = 'true'"!][!//
(5U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'G_') = 'true'"!][!//
(6U)[!//
[!ELSEIF "contains($PortMiso,'MRST') = 'true' and contains($PortMiso,'H_') = 'true'"!][!//
(7U)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!/*
MACRO: Get_SrisSelection
Macro to generate SRIS selection based on MOSI port pin
*/!]
[!MACRO "Get_SrisSelection", "hwmodule" = ""!][!//
[!IF "num:i($hwmodule) = num:i(0)"!][!//
[!VAR "PortMosi" = "SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwPinConfiguration/SPISlaveHwPinMOSI"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(1)"!][!//
[!VAR "PortMosi" = "SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwPinConfiguration/SPISlaveHwPinMOSI"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(2)"!][!//
[!VAR "PortMosi" = "SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwPinConfiguration/SPISlaveHwPinMOSI"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(3)"!][!//
[!VAR "PortMosi" = "SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwPinConfiguration/SPISlaveHwPinMOSI"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(4)"!][!//
[!VAR "PortMosi" = "SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwPinConfiguration/SPISlaveHwPinMOSI"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(5)"!][!//
[!VAR "PortMosi" = "SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwPinConfiguration/SPISlaveHwPinMOSI"!][!//
[!ENDIF!][!//
[!IF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'A_') = 'true'"!][!//
(0U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'B_') = 'true'"!][!//
(1U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'C_') = 'true'"!][!//
(2U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'D_') = 'true'"!][!//
(3U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'E_') = 'true'"!][!//
(4U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'F_') = 'true'"!][!//
(5U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'G_') = 'true'"!][!//
(6U)[!//
[!ELSEIF "contains($PortMosi,'MTSR') = 'true' and contains($PortMosi,'H_') = 'true'"!][!//
(7U)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!/*
MACRO: Get_ScisSelection
Macro to generate SCIS selection based on SCLK port pin
*/!]
[!MACRO "Get_ScisSelection", "hwmodule" = ""!][!//
[!IF "num:i($hwmodule) = num:i(0)"!][!//
[!VAR "PortSclk" = "SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwPinConfiguration/SPISlaveHwPinSCLK"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(1)"!][!//
[!VAR "PortSclk" = "SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwPinConfiguration/SPISlaveHwPinSCLK"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(2)"!][!//
[!VAR "PortSclk" = "SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwPinConfiguration/SPISlaveHwPinSCLK"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(3)"!][!//
[!VAR "PortSclk" = "SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwPinConfiguration/SPISlaveHwPinSCLK"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(4)"!][!//
[!VAR "PortSclk" = "SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwPinConfiguration/SPISlaveHwPinSCLK"!][!//
[!ELSEIF "num:i($hwmodule) = num:i(5)"!][!//
[!VAR "PortSclk" = "SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwPinConfiguration/SPISlaveHwPinSCLK"!][!//
[!ENDIF!][!//
[!IF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'A_') = 'true'"!][!//
(0U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'B_') = 'true'"!][!//
(1U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'C_') = 'true'"!][!//
(2U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'D_') = 'true'"!][!//
(3U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'E_') = 'true'"!][!//
(4U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'F_') = 'true'"!][!//
(5U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'G_') = 'true'"!][!//
(6U)[!//
[!ELSEIF "contains($PortSclk,'SCLK') = 'true' and contains($PortSclk,'H_') = 'true'"!][!//
(7U)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!/* MACRO: Get_ECON_Index
Macro to resolve Index of ECON register based on selected slave channel.
*/!]
[!MACRO "Get_ECON_Index", "SlaveChannel" = "", "EconBitIndex" = ""!][!//
[!IF "$SlaveChannel = 'Channel0'"!][!//
[!VAR "EconBitIndex"= "num:i(1)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel1'"!][!//
[!VAR "EconBitIndex"= "num:i(2)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel2'"!][!//
[!VAR "EconBitIndex"= "num:i(3)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel3'"!][!//
[!VAR "EconBitIndex"= "num:i(4)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel4'"!][!//
[!VAR "EconBitIndex"= "num:i(5)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel5'"!][!//
[!VAR "EconBitIndex"= "num:i(6)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel6'"!][!//
[!VAR "EconBitIndex"= "num:i(7)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel7'"!][!//
[!VAR "EconBitIndex"= "num:i(8)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel8'"!][!//
[!VAR "EconBitIndex"= "num:i(1)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel9'"!][!//
[!VAR "EconBitIndex"= "num:i(2)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel10'"!][!//
[!VAR "EconBitIndex"= "num:i(3)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel11'"!][!//
[!VAR "EconBitIndex"= "num:i(4)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel12'"!][!//
[!VAR "EconBitIndex"= "num:i(5)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel13'"!][!//
[!VAR "EconBitIndex"= "num:i(6)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel14'"!][!//
[!VAR "EconBitIndex"= "num:i(7)"!][!//
[!ELSEIF "$SlaveChannel = 'Channel15'"!][!//
[!VAR "EconBitIndex"= "num:i(8)"!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!// Get No of Sequences Configured
[!VAR "SyncJobPresent" = "'FALSE'"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "MaxTotalSequences" = "num:i(0)"!]
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!VAR "TotalSequences" = "num:i(count(node:ref($SpiSequenceName)/*))"!]
[!"$TotalSequences"!][!//
[!IF "$TotalSequences > $MaxTotalSequences"!]
[!VAR "MaxTotalSequences" = "$TotalSequences"!]
[!ENDIF!][!//

[!IF "../../SpiGeneral/SpiLevelDelivered = 2"!][!//
[!IF "num:i(count(node:ref($SpiJobName)/*[SpiHwUnitSynchronous='Synchronous']) )>0"!][!//
[!IF "$SyncJobPresent = 'FALSE'"!][!//
[!VAR "SyncJobPresent" = "'TRUE'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!/* [!IF $SpiLevel = 2 */!][!//

[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!// Check whether all sequence notification configured or not
[!// Get No of Sequences Configured
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SeqNotifRequired" = "'STD_OFF'"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SpiSeqEndNotify" = "./SpiSeqEndNotification"!][!//
[!IF "contains($SpiSeqEndNotify,'NULL_PTR') = 'true' or string-length($SpiSeqEndNotify) = 0"!][!//
[!ELSE!][!//
[!VAR "SeqNotifRequired" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!// Check whether all sequence notification configured or not
[!// Get No of Sequences Configured
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "JobNotifRequired" = "'STD_OFF'"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!VAR "SpiJobEndNotify" = "./SpiJobEndNotification"!][!//
[!IF "contains($SpiJobEndNotify,'NULL_PTR') = 'true' or string-length($SpiJobEndNotify) = 0"!][!//
[!ELSE!][!//
[!VAR "JobNotifRequired" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!// Get No of IB Channels Configured
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "MaxTotalIBChannels" = "num:i(0)"!]
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!VAR "TotalIBChannels" = "num:i(count(node:ref($SpiChannelName)/*[SpiChannelType='IB']))"!]
[!IF "$TotalIBChannels > $MaxTotalIBChannels"!]
[!VAR "MaxTotalIBChannels" = "$TotalIBChannels"!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!// Get No of EB Channels Configured
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "MaxTotalEBChannels" = "num:i(0)"!]
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!VAR "TotalEBChannels" = "num:i(count(node:ref($SpiChannelName)/*[SpiChannelType='EB']))"!]
[!IF "$TotalEBChannels > $MaxTotalEBChannels"!]
[!VAR "MaxTotalEBChannels" = "$TotalEBChannels"!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!// Get the Maximum IB Buffer Size Configured
[!VAR "MaxIBBufferSize" = "num:i(0)"!][!//
[!IF "SpiGeneral/SpiChannelBuffersAllowed = 0 or SpiGeneral/SpiChannelBuffersAllowed = 2"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "IBBuffer16BitChannel" = "num:i(1)"!][!//
[!VAR "IBBufferMod" = "num:i(2)"!][!//
[!VAR "IBBufferMod32" = "num:i(4)"!][!//
[!VAR "IBBufferModReminder" = "num:i(0)"!][!//
[!VAR "IBBufferOddSize32" = "num:i(0)"!][!//
[!VAR "IBBufferOddSize16" = "num:i(0)"!][!//
[!VAR "IBBufferOddSize8" = "num:i(0)"!][!//
[!VAR "IBBufferSize32" = "num:i(0)"!][!//
[!VAR "IBBufferSize16" = "num:i(0)"!][!//
[!VAR "IBBufferSize8" = "num:i(0)"!][!//
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!VAR "IBBufferSize" = "num:i(0)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!//this loop is to know that 16/32 bit data are configured
[!LOOP "node:ref($SpiChannelName)/*"!][!//
[!IF "num:i(./SpiDataWidth) > num:i(16)"!][!//
[!VAR "IBBufferOddSize32" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "num:i(./SpiDataWidth) > num:i(8)"!][!//
[!VAR "IBBufferOddSize16" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "node:ref($SpiChannelName)/*"!][!//
[!IF "./SpiChannelType = 'IB'"!][!//
[!IF "num:i(./SpiDataWidth) > num:i(16)"!][!//
[!VAR "IBBufferSize32" = "num:i(4) * ./SpiIbNBuffers"!][!//
[!ENDIF!][!//
[!IF "num:i(./SpiDataWidth) > num:i(8) and num:i(./SpiDataWidth) <= num:i(16)"!][!//
[!VAR "IBBufferSize16" = "num:i(2) * ./SpiIbNBuffers"!][!//
[!ENDIF!][!//
[!IF "num:i(./SpiDataWidth) < num:i(9)"!][!//
[!VAR "IBBufferSize8" = "./SpiIbNBuffers"!][!//
[!VAR "IBBufferModReminder" = "$IBBufferSize8 mod $IBBufferMod"!][!//
[!IF "$IBBufferModReminder = num:i(1)"!][!//
[!VAR "IBBufferOddSize8" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$IBBufferOddSize8 = num:i(1) and $IBBufferOddSize16 = num:i(1)"!][!//
[!ERROR!]
Config Error: The configuration restricts the mixed 8/16-bit data for IB channels in a way that only 8-bit channels with an even number of configured bytes are allowed,
              odd number of buffers in [!"node:name(.)"!]
[!ENDERROR!]
[!ENDIF!][!//

[!VAR "IBBufferSize" = "$IBBufferSize + $IBBufferSize16 + $IBBufferSize8 + $IBBufferSize32"!][!//
[!VAR "IBBufferSize32" = "num:i(0)"!][!//
[!VAR "IBBufferSize16" = "num:i(0)"!][!//
[!VAR "IBBufferSize8" = "num:i(0)"!][!//
[!VAR "IBBufferOddSize8" = "num:i(0)"!][!//
[!IF "$IBBufferSize > $MaxIBBufferSize "!][!//
[!VAR "MaxIBBufferSize" = "$IBBufferSize"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!// to check correct channel type configured for SpiChannelBuffersAllowed
[!IF "SpiGeneral/SpiChannelBuffersAllowed = 0 "!][!//
[!//[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'EB']"!][!//
[!ERROR!]
Config Error: SpiChannelBuffersAllowed is configured 0 only IB channels should be configured, but EB Channel configured in: [!"node:name(.)"!]
[!ENDERROR!]
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//

[!IF "SpiGeneral/SpiChannelBuffersAllowed = 1 "!][!//
[!//[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!ERROR!]
Config Error: SpiChannelBuffersAllowed is configured 1 only EB channels should be configured, but IB Channel configured in: [!"node:name(.)"!]
[!ENDERROR!]
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//

[!// Get No of Channels Configured
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "MaxTotalChannels" = "num:i(0)"!]
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!VAR "TotalChannels" = "num:i(count(node:ref($SpiChannelName)/*))"!]
[!IF "$TotalChannels > $MaxTotalChannels"!]
[!VAR "MaxTotalChannels" = "$TotalChannels"!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!// Get No of Jobs Configured
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "MaxTotalJobs" = "num:i(0)"!]
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!VAR "TotalJobs" = "num:i(count(node:ref($SpiJobName)/*))"!]
[!IF "$TotalJobs > $MaxTotalJobs"!]
[!VAR "MaxTotalJobs" = "$TotalJobs"!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!VAR "SpiWriteChannelLock" = "num:i(0)"!]
[!VAR "SpiWriteChannelLock" = "(($MaxTotalIBChannels - num:i(1)) div num:i(8)) + num:i(1)"!][!//
[!ENDNOCODE!][!//

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
  [!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiDriverName" = "'SpiDriver'"!][!//
[!VAR "TotalConfig" = "num:i(count(node:ref($SpiDriverName)/*))"!][!//
/* Configuration: Total number of Config Root */
#define SPI_CONFIG_COUNT  ([!"num:i($TotalConfig)"!]U)

/*
         Container : SpiGeneralConfiguration
*/

/*
Configuration: SPI_DEV_ERROR_DETECT
- if STD_ON, DET is Enabled
- if STD_OFF,DET is Disabled
SPI005: The detection of all development errors is configurable (On / Off)
at precompile time. The switch SPI_DEV_ERROR_DETECT (see chapter 10) shall
activate or deactivate the detection of all development errors.

SPI029:If the switch SPI_DEV_ERROR_DETECT is enabled API parameter checking
is also enabled.
*/
#define SPI_DEV_ERROR_DETECT  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiDevErrorDetect"!]

/*
Configuration: SPI_VERSION_INFO_API
- if STD_ON, Function Spi_GetVersionInfo is available
- if STD_OFF,Function Spi_GetVersionInfo is not available
*/
#define SPI_VERSION_INFO_API  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiVersionInfoApi"!]

/*
Configuration: SPI_LEVEL_DELIVERED
Configure the Spi Handler/driver level of scalablity
0:The LEVEL 0 Simple Synchronous SPI Handler/Driver functionalities are
  selected.
1:The LEVEL 1 Basic Asynchronous SPI Handler/Driver functionalities are
  selected.
2:The LEVEL 2 Enhanced SPI Handler/Driver functionalities are selected.
SPI109: The SPI Handler/Driver level of scalable functionality shall be always
statically configurable, that means configured at pre-compile time, to allow the
best source code optimisation.
SPI110: In order to select the SPI Handler/Driver level of scalable
functionality, the SPI_LEVEL_DELIVERED parameter shall be configured with
one of the 3 authorized values according to the described levels: 0, 1 or 2.
*/
#define SPI_LEVEL_DELIVERED  ([!//
[!"num:i(node:value(SpiGeneral/SpiLevelDelivered))"!]U)

[!IF "SpiGeneral/SpiLevelDelivered = 2"!][!//
/*
SPI LEVEL 2 supports both Synchronous and Asynchronou transmision.
"SPI_LEVEL2_ASYNC_ONLY" macro is applicable for only LEVEL 2,
 where in only Asynchronous jobs are defined.
*/
[!IF "$SyncJobPresent = 'FALSE'"!][!//
#define SPI_LEVEL2_ASYNC_ONLY  (STD_ON)
[!ELSE!][!//
#define SPI_LEVEL2_ASYNC_ONLY  (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_LEVEL2_ASYNC_ONLY  (STD_OFF)
[!ENDIF!][!// LEVEL 2

/*
Configuration: SPI_CHANNEL_BUFFERS_ALLOWED
Configure the Spi Handler/driver buffer usage
0:The Usage 0, only Internal Buffers are selected in Handler/Driver.
1:The Usage 1, only External Buffers are selected in Handler/Driver.
2:The Usage 2, both Internal and External Buffers are selected in
Handler/Driver.
SPI111: In order to select which Channel Buffers the SPI Handler/Driver manages,
the SPI_CHANNEL_BUFFERS_ALLOWED parameter shall be configured with one of
the 3 authorized values according to the described usage: 0, 1 or 2.
SPI115,SPI117.
*/
#define SPI_CHANNEL_BUFFERS_ALLOWED  ([!//
[!"num:i(node:value(SpiGeneral/SpiChannelBuffersAllowed))"!]U)

/*
Configuration: SPI_INTERRUPTABLE_SEQUENCE_ALLOWED
- if STD_ON, configuration of interruptible sequences is allowed
- if STD_OFF,configuration of interruptible sequences is not allowed
SPI121, SPI122
*/
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
#define SPI_INTERRUPTABLE_SEQUENCE_ALLOWED  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiInterruptibleSeqAllowed"!]
[!ELSE!][!//
#define SPI_INTERRUPTABLE_SEQUENCE_ALLOWED  (STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_HW_STATUS_API
- if STD_ON, Function Spi_GetHWUnitStatus is available
- if STD_OFF,Function Spi_GetHWUnitStatus is not available
*/
#define SPI_HW_STATUS_API  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiHwStatusApi"!]

/*
Configuration: SPI_HW_STATUS_API
- if STD_ON, Function Spi_Cancel is available
- if STD_OFF,Function Spi_Cancel is not available
*/
#define SPI_CANCEL_API  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiCancelApi"!]

/*
Configuration: SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT
- if STD_ON, concurrent Spi_SyncTransmit() calls for different se-quences on
    different buses allowed
- if STD_OFF, concurrent Spi_SyncTransmit() calls for different se-quences on
   different buses Not allowed
*/
[!IF "node:exists(SpiGeneral/SpiSupportConcurrentSyncTransmit)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 0 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!ASSERT "SpiGeneral/SpiSupportConcurrentSyncTransmit = 'true'"!][!//
Config Error: SpiSupportConcurrentSyncTransmit should be True if SPI Safety feature is enabled.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiSupportConcurrentSyncTransmit"!]
[!ELSE!][!//
#define SPI_SUPPORT_CONCURRENT_SYNC_TRANSMIT  (STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_MAX_JOB_TRIG_Q_LENGTH
Configure the total SPI Job Queue length.
*/
#define SPI_MAX_JOB_TRIG_Q_LENGTH  ([!//
[!"num:i(node:value(SpiGeneral/SpiMaxJobTriggerQueueLength))"!]U)

/*
Configuration: SPI_PB_FIXEDADDR
- if STD_ON, Fixed Address feature is Enabled
- if STD_OFF,Fixed Address feature is Disabled
*/
[!IF "node:exists(./SpiGeneral/SpiPBFixedAddress)"!][!//
#define SPI_PB_FIXEDADDR  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiPBFixedAddress"!]
[!ENDIF!][!//

[!IF "(SpiGeneral/SpiRunningInUser0Mode = 'true')"!][!//
[!VAR "UserModeInitApi" = "SpiGeneral/SpiUserModeInitApiEnable"!][!//
[!VAR "UserModeDeInitApi" = "SpiGeneral/SpiUserModeDeInitApiEnable"!][!//
[!VAR "UserModeRuntimeApi" = "SpiGeneral/SpiUserModeRuntimeApiEnable"!][!//
[!ASSERT "($UserModeInitApi = 'true') or ($UserModeDeInitApi = 'true') or ($UserModeRuntimeApi = 'true')"!][!//
ERROR: SpiRunningInUser0Mode is set 'true' then atleast any one of the below should be set true.
SpiUserModeRuntimeApiEnable, SpiUserModeInitApiEnable or SpiUserModeDeInitApiEnable.
[!ENDASSERT!][!// 
[!ENDIF!][!//

/*
Configuration: Spi_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "SpiGeneral/SpiRunningInUser0Mode = 'true'"!][!//
#define SPI_RUNNING_IN_USER_0_MODE_ENABLE (STD_ON)
[!ELSE!][!//
#define SPI_RUNNING_IN_USER_0_MODE_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "SpiGeneral/SpiUserModeInitApiEnable = 'true'"!][!//
#define SPI_USER_MODE_INIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  SPI_USER_MODE_INIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: SPI_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected mode in DeInit API 
- if STD_OFF, Disable Protected mode in DeInit API
*/
[!IF "SpiGeneral/SpiUserModeDeInitApiEnable = 'true'"!][!//
#define SPI_USER_MODE_DEINIT_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  SPI_USER_MODE_DEINIT_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*Configuration: SPI_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected mode in APIs other than Init/Deinit APIs
- if STD_OFF, Disable Protected mode in APIs other than Init/Deinit APIs
*/
[!IF "SpiGeneral/SpiUserModeRuntimeApiEnable = 'true'"!][!//
#define SPI_USER_MODE_RUNTIME_API_ENABLE (STD_ON)
[!ELSE!][!//
#define  SPI_USER_MODE_RUNTIME_API_ENABLE (STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_SYNCTRANSMIT_TIMEOUT_COUNTER
 Timeout loop counter while waiting for data transmission/reception
 of 1 data element
*/
#define SPI_SYNCTRANSMIT_TIMEOUT_COUNTER  ([!//
[!"num:i(node:value(SpiGeneral/SpiSyncTransmitTimeoutDuration))"!]U)

[!ENDSELECT!][!//

/*
                 Container : SpiDriverConfiguration
*/

/*
Configuration : SPI_MAXIMUM_SEQUENCE
It is the maximum among the total number of sequences configured in each
Spi configuration.
For example if there are two post build configurations with 2 and 3 sequences
repectively, SPI_MAXIMUM_SEQUENCE must be configured as 3.
*/
#define SPI_MAXIMUM_SEQUENCE ([!"num:i($MaxTotalSequences)"!]U)

/*
Configuration : SPI_MAXIMUM_IB_BUFFER_SIZE(Vendor Specific)
It is the maximum among the total number of IB buffer size configured in each
Spi configuration.
For example if there are two post build configurations, one having 3 IB channels
with total buffer size 30 and another having 2 IB channels with total buffer
size 40, SPI_MAXIMUM_IB_BUFFER_SIZE must be configured as 40.
The IB Buffer is realized by software implementation.
This parameter provides the buffer size to be used based on the number of
IB Channels configured and their buffer size.
*/
[!VAR "IBBufferSizealigned" = "num:i($MaxIBBufferSize) mod num:i(4)"!][!//
[!VAR "MaxIBBufferSize" = "num:i($MaxIBBufferSize) + num:i(4) - num:i($IBBufferSizealigned)"!][!//

#define SPI_MAXIMUM_IB_BUFFER_SIZE  ([!"num:i($MaxIBBufferSize)"!]U)[!//

/*
Configuration : SPI_MAXIMUM_EB_CHANNELS(Vendor Specific)
It is the maximum among the total number of EB channels configured in each
Spi configuration.
For example if there are two post build configurations, one having 5 EB channels
and another having 2 EB channels, SPI_MAXIMUM_EB_CHANNELS must be
configured as 5.
*/
[!IF "SpiGeneral/SpiChannelBuffersAllowed = 2 "!][!//
[!ASSERT "$MaxTotalEBChannels > 0 "!][!//
Config Error: SpiChannelBuffersAllowed is configured 2, but EB channels are not configured.
[!ENDASSERT!][!//
[!ENDIF!][!//
#define SPI_MAXIMUM_EB_CHANNELS  ([!"num:i($MaxTotalEBChannels)"!]U)

/*
Configuration: SPI_MAXIMUM_IB_CHANNELS(Vendor Specific)
It is the maximum among the total number of IB channels configured in each
Spi configuration.
For example if there are two post build configurations, one having 3 IB channels
and another having 6 IB channels, SPI_MAXIMUM_IB_CHANNELS must be
configured as 6.
*/
[!IF "SpiGeneral/SpiChannelBuffersAllowed = 2 "!][!//
[!ASSERT "$MaxTotalIBChannels > 0 "!][!//
Config Error: SpiChannelBuffersAllowed is configured 2, but IB channels are not configured.
[!ENDASSERT!][!//
[!ENDIF!][!//
#define SPI_MAXIMUM_IB_CHANNELS  ([!"num:i($MaxTotalIBChannels)"!]U)

/*
Configuration: SPI_MAXIMUM_CHANNEL
It is the maximum among the total number of channels configured in each
Spi configuration.
*/
#define SPI_MAXIMUM_CHANNEL  ([!"num:i($MaxTotalChannels)"!]U)

/*
Configuration: SPI_MAXIMUM_JOB
It is the maximum among the total number of Jobs configured in each
Spi configuration.
*/
#define SPI_MAXIMUM_JOB  ([!"num:i($MaxTotalJobs)"!]U)

/*
Configuration: SPI_WRITELOCK_INDEX
This is the array index valve to define the total number of IB channels
configured to be used in Spi_WriteIB API to lock the channels using
variable Spi_ChannelWriteLock
*/
#define SPI_WRITELOCK_INDEX ([!"num:i($SpiWriteChannelLock)"!]U)

/*
Configuration: SPI_SAFETY_ENABLE
This determines if the safety features of SPI is enabled or not.
*/
#define SPI_SAFETY_ENABLE [!//
[!CALL "CG_ConfigSwitch","node" = "SpiSafety/SpiSafetyEnable"!][!//

/*
Configuration: SPI_SLAVE_ENABLE
This determines if the Slave has been configured or not
*/
#define SPI_SLAVE_ENABLE [!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef = 'SPI_SLAVE_UNUSED'"!][!//
(STD_OFF)
[!ELSE!][!//
(STD_ON)
[!ENDIF!][!//SpiGeneral/SpiSlaveSelectRef
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//$SafetyEnable = 'true'

[!IF "$SafetyEnable = 'true'"!][!//
/*
Configuration: SPI_INITCHECK_API
This determines if the Spi_InitCheck API is enabled or not
*/
#define SPI_INITCHECK_API [!//
[!CALL "CG_ConfigSwitch","node" = "SpiSafety/SpiInitCheckApi"!][!//

[!IF "SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"!][!//
/*
Configuration: SPI_SLAVE_FLIP_TRANSFERSTART
This is to determine if the data receieved by Slave should be flipped
with respect to master data transmission i.e. MSB->LSB or vice versa.
*/
#define SPI_SLAVE_FLIP_TRANSFERSTART [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiSlaveFlipTransferStart"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/*
                    Container : SpiChannelConfiguration
*/
/*
Configuration: SPI_CHANNEL_NAME
SPI Driver Channel Symbolic Names. For Each Channel a unique Id is created.
The Symbolic Name is Equivalent to the Channel Container Name
*/
[!/*
The Symbolic names are arranged as :
IB channels first followed by EB Channels.
*/!]
[!/* This loop is to generate multiple instances of Spi configuration */!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!//
[!VAR "j"="0"!][!//
[!IF "SpiGeneral/SpiChannelBuffersAllowed = 2 or SpiGeneral/SpiChannelBuffersAllowed = 0"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!IF "num:i(SpiDataWidth) > num:i(16)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!//
[!VAR "SkipChName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipChName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipChName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_[!"$SymbolicName"!] ((Spi_ChannelType)[!"(num:i($j))"!]U)
[!ENDIF!][!//
[!//
[!VAR "j"="$j + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!IF "num:i(SpiDataWidth) > num:i(8) and num:i(SpiDataWidth) <= num:i(16)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!//
[!VAR "SkipChName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipChName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipChName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_[!"$SymbolicName"!] ((Spi_ChannelType)[!"(num:i($j))"!]U)
[!ENDIF!][!//
[!VAR "j"="$j + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!IF "num:i(SpiDataWidth) <= num:i(8)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!//
[!VAR "SkipChName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipChName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipChName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_[!"$SymbolicName"!] ((Spi_ChannelType)[!"(num:i($j))"!]U)
[!ENDIF!][!//
[!VAR "j"="$j + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!IF "SpiGeneral/SpiChannelBuffersAllowed = 2 or SpiGeneral/SpiChannelBuffersAllowed = 1"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'EB']"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!//
[!VAR "SkipChName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'EB']"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipChName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipChName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiChannel_[!"$SymbolicName"!] ((Spi_ChannelType)[!"(num:i($j))"!]U)
[!ENDIF!][!//
[!VAR "j"="$j + 1"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

/*
Configuration Options:
Selection of Channel Buffer Type
*/
/* EB Buffer Channel Type */
#define SPI_EB_BUFFER   (0U)

/* IB Buffer Channel Type */
#define SPI_IB_BUFFER   (1U)

/*
Configuration Options:
SPI Data Order Options
*/
/* Least Significant Bit is transferred first */
#define SPI_DATA_LSB_FIRST   (0U)

/* Most Significant Bit is transferred first */
#define SPI_DATA_MSB_FIRST   (1U)

/*
Macro: CHANNEL_LINK_DELIMITER
Identifier for Channel Link End Delimiter.
This parameter is used internally in the driver code to determine end
of Channel Link.
*/
#define SPI_CHANNEL_LINK_DELIMITER ((Spi_ChannelType)0xFFU)

/*
                   Container : SpiJobConfiguration
*/

/*
Configuration: Job Name
SPI Driver Job Symbolic Names. For Each Job a unique Id is created.
The Symbolic Name is Equivalent to the Job Container Name.
This name is referenced to build the Job Link within a sequence.
*/
[!/* This loop is to generate multiple instances of Spi configuration */!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!VAR "Id"="0"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipJobName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipJobName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipJobName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiJob_[!"$SymbolicName"!] ((Spi_JobType)[!"(num:i($Id))"!]U)
[!ENDIF!][!//
[!//
[!VAR "Id"="$Id+1"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
/*
Configuration Options:
SPI Shift Clock Idle Levels
*/
/* Idle Level : Low Voltage Level */
#define SPI_CLK_IDLE_LOW       (0U)
/* Idle Level : High Voltage Level */
#define SPI_CLK_IDLE_HIGH      (1U)

/*
Configuration Options:
SPI Data Shift Edge Options
*/
#define SPI_DATA_SHIFT_LEAD    ((uint8)1U)
#define SPI_DATA_SHIFT_TRAIL   ((uint8)0U)

/*
Configuration Options:
SPI CS Polarity Levels (The Active Level)
*/
/* Polarity : Low Voltage Level */
#define SPI_CS_POLARITY_LOW    (0U)
/* Polarity : High Voltage Level */
#define SPI_CS_POLARITY_HIGH   (1U)

/*
Configuration Options:
SPI CS Pins
*/
/* The  CS Pins are configured in the Module Port */
/* The following define is used if no Pins are referenced */
#define SPI_CS_NONE ((uint16)0xFFFFU)

#define SPI_CS_HW   ((uint16)0xEFFFU)


/*
Macro:JOB_LINK_DELIMITER
Job Link End Delimiter.
This parameter is used internally in the driver code to determine end
of Job Link.
*/
#define SPI_JOB_LINK_DELIMITER ((Spi_JobType)0xFFFFU)

/*
Macro:SPI_SHARED_JOBS_DELIMITER
Sequences sharing jobs end Delimiter.
This parameter is used internally in the driver code to determine end
of sequences sharing the Job Link.
*/
#define SPI_SHARED_JOBS_DELIMITER ((uint8)0xFFU)


/*
            Container : SpiSequenceConfiguration
*/

/*
Configuration Options:
SPI Sequence Interruptible Options
*/
#define SPI_SEQ_INT_FALSE     ((uint8)0U)
#define SPI_SEQ_INT_TRUE      ((uint8)1U)

/*
Configuration: SPI_SEQUENCE_NAME
SPI Driver Sequence Symbolic Names. For Each Sequence a unique Id is created.
The Symbolic Name is Equivalent to the Sequence Container Name*/
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!VAR "Id"="0"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!IF "$SpiLevel = 0 or $SpiLevel = 1"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipSeqName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipSeqName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_[!"$SymbolicName"!] ((Spi_SequenceType)[!"(num:i($Id))"!]U)
[!ENDIF!][!//
[!VAR "Id"="$Id+1"!][!//
[!ENDLOOP!][!//
[!ELSE!][!/* Spi Level 2 */!]
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous != 'Asynchronous'"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipSeqName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipSeqName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_[!"$SymbolicName"!] ((Spi_SequenceType)[!"(num:i($Id))"!]U)
[!ENDIF!][!//
[!VAR "Id"="$Id+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous = 'Asynchronous'"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($ModuleId - 1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SymbolicName) = 'true'"!][!//
[!VAR "SkipSeqName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipSeqName = 'false'"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SpiConf_SpiSequence_[!"$SymbolicName"!] ((Spi_SequenceType)[!"(num:i($Id))"!]U)
[!ENDIF!][!//
[!VAR "Id"="$Id+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!/* Spi Level */!]
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

/*
              Container : SpiHardwareConfiguration
*/

/*
Configuration Options:
Spi HW Units supported. This parameter is used internally
by the other configurations. The user should not alter this.
*/
#define SPI_0 ((uint8)0U)
#define SPI_1 ((uint8)1U)
#define SPI_2 ((uint8)2U)
#define SPI_3 ((uint8)3U)
#define SPI_4 ((uint8)4U)
#define SPI_5 ((uint8)5U)

#define SPI_QSPI_CHANNEL0 ((uint8)0U)
#define SPI_QSPI_CHANNEL1 ((uint8)1U)
#define SPI_QSPI_CHANNEL2 ((uint8)2U)
#define SPI_QSPI_CHANNEL3 ((uint8)3U)
#define SPI_QSPI_CHANNEL4 ((uint8)4U)
#define SPI_QSPI_CHANNEL5 ((uint8)5U)
#define SPI_QSPI_CHANNEL6 ((uint8)6U)
#define SPI_QSPI_CHANNEL7 ((uint8)7U)
#define SPI_QSPI_CHANNEL8 ((uint8)8U)
#define SPI_QSPI_CHANNEL9 ((uint8)9U)
#define SPI_QSPI_CHANNEL10 ((uint8)10U)
#define SPI_QSPI_CHANNEL11 ((uint8)11U)
#define SPI_QSPI_CHANNEL12 ((uint8)12U)
#define SPI_QSPI_CHANNEL13 ((uint8)13U)
#define SPI_QSPI_CHANNEL14 ((uint8)14U)
#define SPI_QSPI_CHANNEL15 ((uint8)15U)

/*
Configuration Options:
configuration options to check whether HW modules QSPIx are configured
*/
#define SPI_0_NOT_CONFIGURED   (255U)
#define SPI_1_NOT_CONFIGURED   (255U)
#define SPI_2_NOT_CONFIGURED   (255U)
#define SPI_3_NOT_CONFIGURED   (255U)
#define SPI_4_NOT_CONFIGURED   (255U)
#define SPI_5_NOT_CONFIGURED   (255U)
/*
Configuration Options:
QSPI Module Sleep Settings
*/
/* SPI Module is enabled.Module Does not enter Sleep Mode upon Sleep Request.*/
#define SPI_CLK_SLEEP_DISABLE   (0x00000008U)

/* SPI Module is Enabled.Module Enters Sleep Mode upon Sleep Request.*/
#define SPI_CLK_SLEEP_ENABLE    (0x00000000U)

/*
Master receive pin input selection
MRSTxA : 0
MRSTxB : 1
*/
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi0)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'QSPI0'"!][!//
#define SPI_QSPI0_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_QSPI0_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi1)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'QSPI1'"!][!//
#define SPI_QSPI1_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_QSPI1_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi2)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'QSPI2'"!][!//
#define SPI_QSPI2_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(2)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_QSPI2_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(2)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi3)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'QSPI3'"!][!//
#define SPI_QSPI3_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(3)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_QSPI3_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(3)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'QSPI4'"!][!//
#define SPI_QSPI4_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(4)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_QSPI4_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(4)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi5)"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'QSPI5'"!][!//
#define SPI_QSPI5_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(5)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_QSPI5_MRIS_SEL [!//
[!CALL "Get_MrisSelection","hwmodule" = "num:i(5)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//

/*
Configuration: SPI_QSPI0_USED
- if STD_ON, QSPI0 is used
- if STD_OFF,QSPI0 is not used
*/
[!VAR "QSPI0Used" = "'false'"!][!//
[!VAR "QSPI1Used" = "'false'"!][!//
[!VAR "QSPI2Used" = "'false'"!][!//
[!VAR "QSPI3Used" = "'false'"!][!//
[!VAR "QSPI4Used" = "'false'"!][!//
[!VAR "QSPI5Used" = "'false'"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!FOR "Index2" = "num:i(0)" TO "num:i(count(node:ref($SpiJobName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiJobName)/*[@index =$Index2]"!][!//
[!ASSERT "(node:refexists(node:ref($SpiDeviceAssignmentName)) = 'true')"!][!//
Config Error: Device assignment reference not provided for [!"node:name(.)"!][!//
[!ENDASSERT!][!//
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI0'"!][!//
[!VAR "QSPI0Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI1'"!][!//
[!VAR "QSPI1Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI2'"!][!//
[!VAR "QSPI2Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI3'"!][!//
[!VAR "QSPI3Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI4'"!][!//
[!VAR "QSPI4Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI5'"!][!//
[!VAR "QSPI5Used" = "'true'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef = 'QSPI0'"!][!//
[!VAR "QSPI0Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef = 'QSPI1'"!][!//
[!VAR "QSPI1Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef = 'QSPI2'"!][!//
[!VAR "QSPI2Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef = 'QSPI3'"!][!//
[!VAR "QSPI3Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef = 'QSPI4'"!][!//
[!VAR "QSPI4Used" = "'true'"!][!//
[!ENDIF!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef = 'QSPI5'"!][!//
[!VAR "QSPI5Used" = "'true'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "SpiTotalMasterUsedModules" = "num:i(0)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i(0)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i(0)"!][!//
[!VAR "SpiNumQmAsyncMasters" = "num:i(0)"!][!//
[!VAR "SpiUsedModule0" = "num:i(0)"!][!//
[!VAR "SpiUsedModule1" = "num:i(0)"!][!//
[!VAR "SpiUsedModule2" = "num:i(0)"!][!//
[!VAR "SpiUsedModule3" = "num:i(0)"!][!//
[!VAR "SpiUsedModule4" = "num:i(0)"!][!//
[!VAR "SpiUsedModule5" = "num:i(0)"!][!//
[!//
#define SPI_QSPI0_USED  [!//
[!IF "$QSPI0Used = 'true'"!][!//
(STD_ON)
[!VAR "SpiUsedModule0" = "num:i(1)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules + 1)"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:or($SpiTotalMasterUsedModules,(bit:shl($SpiUsedModule0,0)))"!][!//
/* Index For QSPI0 Module */
#define SPI_QSPI0_INDEX (0U)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_QSPI1_USED
- if STD_ON, QSPI1 is used
- if STD_OFF,QSPI1 is not used
*/
#define SPI_QSPI1_USED [!//
[!IF "$QSPI1Used = 'true'"!][!//
(STD_ON)
[!VAR "SpiUsedModule1" = "num:i(1)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules + 1)"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:or($SpiTotalMasterUsedModules,(bit:shl($SpiUsedModule1,1)))"!][!//
/* Index For QSPI1 Module */
#define SPI_QSPI1_INDEX (1U)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_QSPI2_USED
- if STD_ON, QSPI2 is used
- if STD_OFF,QSPI2 is not used
*/
#define SPI_QSPI2_USED [!//
[!IF "$QSPI2Used = 'true'"!][!//
(STD_ON)
[!VAR "SpiUsedModule2" = "num:i(1)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules + 1)"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:or($SpiTotalMasterUsedModules,(bit:shl($SpiUsedModule2,2)))"!][!//
/* Index For QSPI2 Module */
#define SPI_QSPI2_INDEX (2U)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_QSPI3_USED
- if STD_ON, QSPI3 is used
- if STD_OFF,QSPI3 is not used
*/
#define SPI_QSPI3_USED [!//
[!IF "$QSPI3Used = 'true'"!][!//
(STD_ON)
[!VAR "SpiUsedModule3" = "num:i(1)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules + 1)"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:or($SpiTotalMasterUsedModules,(bit:shl($SpiUsedModule3,3)))"!][!//
/* Index For QSPI3 Module */
#define SPI_QSPI3_INDEX (3U)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_QSPI4_USED
- if STD_ON, QSPI4 is used
- if STD_OFF,QSPI4 is not used
*/
#define SPI_QSPI4_USED [!//
[!IF "$QSPI4Used = 'true'"!][!//
(STD_ON)
[!VAR "SpiUsedModule4" = "num:i(1)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules + 1)"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:or($SpiTotalMasterUsedModules,(bit:shl($SpiUsedModule4,4)))"!][!//
/* Index For QSPI4 Module */
#define SPI_QSPI4_INDEX (4U)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//

/*
Configuration: SPI_QSPI5_USED
- if STD_ON, QSPI5 is used
- if STD_OFF,QSPI5 is not used
*/
#define SPI_QSPI5_USED [!//
[!IF "$QSPI5Used = 'true'"!][!//
(STD_ON)
[!VAR "SpiUsedModule5" = "num:i(1)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules + 1)"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:or($SpiTotalMasterUsedModules,(bit:shl($SpiUsedModule5,5)))"!][!//
/* Index For QSPI5 Module */
#define SPI_QSPI5_INDEX (5U)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//
[!//
[!//
[!IF "$Spi_BaudrateAtRuntime = 'false'"!][!//
[!//
[!NOCODE!][!//
[!// Check the External Device Configurations
  [!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
    [!FOR "IndexEcon" = "num:i(0)" TO "num:i(7)"!][!//
      [!VAR "Spi_QSPI0_ECON" = "num:i(0)"!][!//
      [!VAR "Spi_QSPI1_ECON" = "num:i(0)"!][!//
      [!VAR "Spi_QSPI2_ECON" = "num:i(0)"!][!//
      [!VAR "Spi_QSPI3_ECON" = "num:i(0)"!][!//
      [!VAR "Spi_QSPI4_ECON" = "num:i(0)"!][!//
      [!VAR "Spi_QSPI5_ECON" = "num:i(0)"!][!//
      [!VAR "TempVar" = "num:i(0)"!][!//
      [!VAR "EconBitIndex0" = "num:i(0)"!][!//
      [!VAR "EconBitIndex1" = "num:i(0)"!][!//
      [!VAR "EconBitIndex2" = "num:i(0)"!][!//
      [!VAR "EconBitIndex3" = "num:i(0)"!][!//
      [!VAR "EconBitIndex4" = "num:i(0)"!][!//
      [!VAR "EconBitIndex5" = "num:i(0)"!][!//
    [!ENDFOR!][!//
    [!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
      [!FOR "Index1" = "num:i(0)" TO "num:i(count(node:ref($SpiDevName)/*)) - num:i(1)"!][!//

        [!IF "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwModule = 'QSPI0'"!][!//
          [!VAR "SlaveSelectCh" = "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!][!//
          [!CALL "Get_ECON_Index","SlaveChannel" = "$SlaveSelectCh", "EconBitIndex" = "$TempVar"!][!//
          [!VAR "EconBitIndex0" = "$EconBitIndex"!][!//
          [!IF "bit:getbit($Spi_QSPI0_ECON,num:i($EconBitIndex0)) = 0"!][!//
            [!VAR "Spi_QSPI0_ECON" = "bit:bitset($Spi_QSPI0_ECON,num:i($EconBitIndex0))"!][!//
          [!ELSE!][!//
            [!ERROR!] Contradiction in configuration of QSPI0: [!"node:name(node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel)"!] = [!"node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!].
1) Same Channel of QSPIx cannot be selected more than Once.
2) When Ch(x) is selected Ch(x+8) shall not be selected; and Vice Versa.
            [!ENDERROR!]
          [!ENDIF!][!//
        [!ENDIF!][!//

        [!IF "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwModule = 'QSPI1'"!][!//
          [!VAR "SlaveSelectCh" = "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!][!//
          [!CALL "Get_ECON_Index","SlaveChannel" = "$SlaveSelectCh", "EconBitIndex" = "$TempVar"!][!//
          [!VAR "EconBitIndex1" = "$EconBitIndex"!][!//
          [!IF "bit:getbit($Spi_QSPI1_ECON,num:i($EconBitIndex1)) = 0"!][!//
            [!VAR "Spi_QSPI1_ECON" = "bit:bitset($Spi_QSPI1_ECON,num:i($EconBitIndex1))"!][!//
          [!ELSE!][!//
            [!ERROR!] Contradiction in configuration of QSPI1: [!"node:name(node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel)"!] = [!"node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!].
1) Same Channel of QSPIx cannot be selected more than Once.
2) When Ch(x) is selected Ch(x+8) shall not be selected; and Vice Versa.
            [!ENDERROR!]
          [!ENDIF!][!//
        [!ENDIF!][!//

        [!IF "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwModule = 'QSPI2'"!][!//
          [!VAR "SlaveSelectCh" = "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!][!//
          [!CALL "Get_ECON_Index","SlaveChannel" = "$SlaveSelectCh", "EconBitIndex" = "$TempVar"!][!//
          [!VAR "EconBitIndex2" = "$EconBitIndex"!][!//
          [!IF "bit:getbit($Spi_QSPI2_ECON,num:i($EconBitIndex2)) = 0"!][!//
            [!VAR "Spi_QSPI2_ECON" = "bit:bitset($Spi_QSPI2_ECON,num:i($EconBitIndex2))"!][!//
          [!ELSE!][!//
            [!ERROR!] Contradiction in configuration of QSPI2: [!"node:name(node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel)"!] = [!"node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!].
1) Same Channel of QSPIx cannot be selected more than Once.
2) When Ch(x) is selected Ch(x+8) shall not be selected; and Vice Versa.
            [!ENDERROR!]
          [!ENDIF!][!//
        [!ENDIF!][!//

        [!IF "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwModule = 'QSPI3'"!][!//
          [!VAR "SlaveSelectCh" = "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!][!//
          [!CALL "Get_ECON_Index","SlaveChannel" = "$SlaveSelectCh", "EconBitIndex" = "$TempVar"!][!//
          [!VAR "EconBitIndex3" = "$EconBitIndex"!][!//
          [!IF "bit:getbit($Spi_QSPI3_ECON,num:i($EconBitIndex3)) = 0"!][!//
            [!VAR "Spi_QSPI3_ECON" = "bit:bitset($Spi_QSPI3_ECON,num:i($EconBitIndex3))"!][!//
          [!ELSE!][!//
            [!ERROR!] Contradiction in configuration of QSPI3: [!"node:name(node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel)"!] = [!"node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!].
1) Same Channel of QSPIx cannot be selected more than Once.
2) When Ch(x) is selected Ch(x+8) shall not be selected; and Vice Versa.
            [!ENDERROR!]
          [!ENDIF!][!//
        [!ENDIF!][!//

        [!IF "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwModule = 'QSPI4'"!][!//
          [!VAR "SlaveSelectCh" = "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!][!//
          [!CALL "Get_ECON_Index","SlaveChannel" = "$SlaveSelectCh", "EconBitIndex" = "$TempVar"!][!//
          [!VAR "EconBitIndex4" = "$EconBitIndex"!][!//
          [!IF "bit:getbit($Spi_QSPI4_ECON,num:i($EconBitIndex4)) = 0"!][!//
            [!VAR "Spi_QSPI4_ECON" = "bit:bitset($Spi_QSPI4_ECON,num:i($EconBitIndex4))"!][!//
          [!ELSE!][!//
            [!ERROR!] Contradiction in configuration of QSPI4: [!"node:name(node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel)"!] = [!"node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!].
1) Same Channel of QSPIx cannot be selected more than Once.
2) When Ch(x) is selected Ch(x+8) shall not be selected; and Vice Versa.
            [!ENDERROR!]
          [!ENDIF!][!//
        [!ENDIF!][!//

        [!IF "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwModule = 'QSPI5'"!][!//
          [!VAR "SlaveSelectCh" = "node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!][!//
          [!CALL "Get_ECON_Index","SlaveChannel" = "$SlaveSelectCh", "EconBitIndex" = "$TempVar"!][!//
          [!VAR "EconBitIndex5" = "$EconBitIndex"!][!//
          [!IF "bit:getbit($Spi_QSPI5_ECON,num:i($EconBitIndex5)) = 0"!][!//
            [!VAR "Spi_QSPI5_ECON" = "bit:bitset($Spi_QSPI5_ECON,num:i($EconBitIndex5))"!][!//
          [!ELSE!][!//
            [!ERROR!] Contradiction in configuration of QSPI5: [!"node:name(node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel)"!] = [!"node:ref($SpiDevName)/*[@index =$Index1]/SpiHwUnit/SpiAssignedHwChannel"!].
1) Same Channel of QSPIx cannot be selected more than Once.
2) When Ch(x) is selected Ch(x+8) shall not be selected; and Vice Versa.
            [!ENDERROR!]
          [!ENDIF!][!//
        [!ENDIF!][!//
      [!ENDFOR!][!//  end of "node:ref(SpiExternalDevice)
    [!ENDSELECT!][!//  end of "node:ref($SpiDriverName)/*[@index = $Index]
  [!ENDFOR!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!//
[!ENDIF!][!//
[!NOCODE!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!VAR "SpiSafetyMasterQSPI" = "node:value(./SpiGeneral/SpiSafetyMasterRef)"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules - 1)"!][!//
[!VAR "MaxTotalAsilSequences" = "num:i(0)"!]
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!VAR "SpiMasterMatch" = "num:i(0)"!][!//
[!VAR "SpiSlaveMatch" = "num:i(0)"!][!//
[!FOR "Index2" = "num:i(0)" TO "num:i(count(node:ref($SpiDevName)/*)) - num:i(1)"!][!//Verify if Safety Master QSPI is configured
[!SELECT "node:ref($SpiDevName)/*[@index =$Index2]"!][!//
[!IF "node:value(../../../../SpiGeneral/SpiSafetyMasterRef) = node:value(SpiHwUnit/SpiAssignedHwModule)"!][!//
[!VAR "SpiMasterMatch" = "num:i(1)"!][!//Safety Master QSPI configured in this config set;break
[!BREAK!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//End of for to Check for safety master QSPI configured in this config set
[!FOR "Index2" = "num:i(0)" TO "num:i(count(node:ref($SpiDevName)/*)) - num:i(1)"!][!//Verify if Safety Slave QSPI is configured
[!SELECT "node:ref($SpiDevName)/*[@index =$Index2]"!][!//
[!IF "node:value(../../../../SpiGeneral/SpiSlaveSelectRef) = node:value(SpiHwUnit/SpiAssignedHwModule)"!][!//
[!VAR "SpiSlaveMatch" = "num:i(1)"!][!//Safety Slave QSPI configured in this config set;break
[!BREAK!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//End of for to Check for slave QSPI configured in this config set
[!ASSERT "$SpiMasterMatch = num:i(1)"!][!//
Config Error: Safety Master [!"node:value(../../SpiGeneral/SpiSafetyMasterRef)"!] not configured in configuration set SpiDriver/[!"node:name(.)"!][!//
[!ENDASSERT!][!//
[!ASSERT "$SpiSlaveMatch = num:i(0)"!][!//
Config Error: Safety Slave [!"node:value(../../SpiGeneral/SpiSlaveSelectRef)"!] should not be configured in configuration set SpiDriver/[!"node:name(.)"!]. The same settings as Safety Master [!"node:value(../../SpiGeneral/SpiSafetyMasterRef)"!] will be used for the slave.[!//
[!ENDASSERT!][!//
[!VAR "SpiSequenceAsilCount" = "num:i(0)"!][!//
[!FOR "Index2" = "num:i(0)" TO "num:i(count(node:ref($SpiSequenceName)/*)) - num:i(1)"!][!//Verify in a sequence either all jobs linked to safety master QSPI or all jobs linked to non-safety master
[!SELECT "node:ref($SpiSequenceName)/*[@index =$Index2]"!][!//
[!VAR "SafetySequence" = "'false'"!][!//
[!VAR "Index3" = "num:i(0)"!][!//
[!IF "node:refexists(./SpiJobAssignment/*[@index=$Index3])"!][!//
[!VAR "SpiHwUnitNode" = "node:ref(node:ref(./SpiJobAssignment/*[@index=$Index3])/SpiDeviceAssignment)/SpiHwUnit/SpiAssignedHwModule"!][!//
[!IF "$SpiHwUnitNode = $SpiSafetyMasterQSPI"!][!//
[!VAR "SafetySequence" = "'true'"!][!//
[!VAR "SpiSequenceAsilCount" = "$SpiSequenceAsilCount + num:i(1)"!][!//Increment Safety sequence count
[!ENDIF!][!//
[!ENDIF!][!//
[!FOR "Index3" = "num:i(1)" TO "num:i(count(./SpiJobAssignment/*)) - num:i(1)"!][!//Loop thru all jobs in this sequence
[!VAR "SpiHwUnitNode" = "node:ref(node:ref(./SpiJobAssignment/*[@index=$Index3])/SpiDeviceAssignment)/SpiHwUnit/SpiAssignedHwModule"!][!//
[!IF "$SafetySequence = 'true'"!][!//Verify if all jobs are linked to safety master QSPI only
[!ASSERT "$SpiSafetyMasterQSPI = $SpiHwUnitNode"!][!//
Config Error: The first job in this sequence uses Safety master QSPI; hence all other jobs in this Sequence [!"node:name(.)"!] should use Safety master QSPI only [!//
[!ENDASSERT!][!//
[!ELSE!][!//Else Verify if all jobs are not linked to safety master QSPI only
[!"$SpiHwUnitNode"!][!//
[!ASSERT "$SpiSafetyMasterQSPI != $SpiHwUnitNode"!][!//
Config Error: The first job in this sequence uses non-Safety master QSPI; hence all other jobs in this Sequence [!"node:name(.)"!] should use non-Safety master QSPI only [!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDFOR!][!//End of For loop for all the jobs in SpiJob/*
[!ENDSELECT!][!//End of Select for the SpiSequence/*
[!ENDFOR!][!//End of For loop for all the sequences in SpiSequence/*
[!ENDSELECT!][!//End of Select for the SpiDriver/* Config set
[!IF "$SpiSequenceAsilCount > $MaxTotalAsilSequences"!]
[!VAR "MaxTotalAsilSequences" = "$SpiSequenceAsilCount"!]
[!ENDIF!][!//
[!ENDFOR!][!//End of For loop for all the config sets in SpiDriver/*

[!VAR "SpiSafeMasterModule" = "num:i(substring(./SpiGeneral/SpiSafetyMasterRef,5,1))"!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"!][!//
[!VAR "SpiSlaveQSPINum" = "num:i(substring(./SpiGeneral/SpiSlaveSelectRef,5,1))"!][!//
[!VAR "SpiTotalMasterUsedModules" = "bit:bitclear($SpiTotalMasterUsedModules,$SpiSlaveQSPINum)"!][!//
[!VAR "SpiSlaveUsedModule" = "concat('SPI_QSPI', $SpiSlaveQSPINum, '_INDEX')"!][!//
[!VAR "SpiTotalMasterModules" = "num:i($SpiTotalMasterModules - 1)"!][!//
[!ENDIF!][!//
[!VAR "SpiSequenceAsilIndex" = "num:i(0)"!]
[!VAR "SpiSequenceAsilIndex" = "(($MaxTotalAsilSequences - num:i(1)) div num:i(16)) + num:i(1)"!][!//
[!VAR "MaxTotalSequences" = "$MaxTotalSequences - $MaxTotalAsilSequences"!]
[!VAR "MaxTotalAsilJobs" = "num:i(0)"!]
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId - 1)]"!][!//
[!VAR "SpiJobAsilCount" = "num:i(0)"!]
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!IF "node:refexists(node:ref($SpiDeviceAssignmentName))"!][!//
[!VAR "SpiHwUnitNode" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule"!][!//
[!IF "$SpiSafetyMasterQSPI = $SpiHwUnitNode"!][!//
[!VAR "SpiJobAsilCount" = "$SpiJobAsilCount + num:i(1)"!][!//Increment Safety job count
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//End of Select for the SpiDriver/* Config set
[!IF "$SpiJobAsilCount > $MaxTotalAsilJobs"!]
[!VAR "MaxTotalAsilJobs" = "$SpiJobAsilCount"!]
[!ENDIF!][!//
[!ENDFOR!][!//End of For loop for all the config sets in SpiDriver/*
[!VAR "SpiJobAsilIndex" = "num:i(0)"!]
[!VAR "SpiJobAsilIndex" = "(($MaxTotalAsilJobs - num:i(1)) div num:i(16)) + num:i(1)"!][!//
[!VAR "MaxTotalJobs" = "$MaxTotalJobs - $MaxTotalAsilJobs"!]
[!ENDIF!][!//If Safety enabled = true
[!VAR "SpiSequenceQmIndex" = "num:i(0)"!]
[!VAR "SpiSequenceQmIndex" = "(($MaxTotalSequences - num:i(1)) div num:i(16)) + num:i(1)"!][!//
[!VAR "SpiJobQmIndex" = "num:i(0)"!]
[!VAR "SpiJobQmIndex" = "(($MaxTotalJobs - num:i(1)) div num:i(16)) + num:i(1)"!][!//
[!ENDNOCODE!][!//
/* SPI Master Used Modules */
#define SPI_MASTER_MODULES_USED      ([!"num:inttohex($SpiTotalMasterUsedModules, 4)"!]U)
[!IF "$SafetyEnable = 'true'"!][!//
/* SPI Safety Master Used Module*/
#define SPI_ASIL_MASTER_MODULE_USED  ([!"num:inttohex(bit:shl(1,$SpiSafeMasterModule), 4)"!]U)
[!IF "./SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"!][!//
/* SPI Safety Slave QSPI Index */
#define SPI_SLAVE_MODULE_INDEX       ([!"$SpiSlaveUsedModule"!])
/* SPI Safety Slave Receive Input Selection */
#define SPI_SLAVE_SRIS_SEL           [!//
[!CALL "Get_SrisSelection","hwmodule" = "num:i($SpiSlaveQSPINum)"!]
/* SPI Safety Slave SCLK Selection */
#define SPI_SLAVE_SCIS_SEL           [!//
[!CALL "Get_ScisSelection","hwmodule" = "num:i($SpiSlaveQSPINum)"!][!//
/* SPI Number of Safety Slave
     configured */
#define SPI_NUM_ASIL_SLAVE_MODULES   (1U)
[!ENDIF!][!//

/*
Configuration: SPI_SEQUENCE_ASIL_ARRAY_INDEX
This is the array index valve to define the total number of safety sequences
configured to be used in Spi_SeqStatus, SpiSeqCancel variables.
*/
#define SPI_SEQUENCE_ASIL_ARRAY_INDEX ([!"num:i($SpiSequenceAsilIndex)"!]U)

/*
Configuration: SPI_JOB_ASIL_ARRAY_INDEX
This is the array index valve to define the total number of safety jobs
configured to be used in Spi_JobResult variables.
*/
#define SPI_JOB_ASIL_ARRAY_INDEX ([!"num:i($SpiJobAsilIndex)"!]U)

/* SPI Number of Safety masters configured */
#define SPI_NUM_ASIL_MASTER_MODULES  (1U)
[!ENDIF!][!//$SafetyEnable = 'true'

/*
Configuration: SPI_SEQUENCE_QM_ARRAY_INDEX
This is the array index valve to define the total number of non-safety
sequences configured to be used in Spi_SeqStatus, SpiSeqCancel variables.
*/
#define SPI_SEQUENCE_QM_ARRAY_INDEX ([!"num:i($SpiSequenceQmIndex)"!]U)

/*
Configuration: SPI_JOB_QM_ARRAY_INDEX
This is the array index valve to define the total number of non-safety jobs
configured to be used in Spi_JobResult variables.
*/
#define SPI_JOB_QM_ARRAY_INDEX ([!"num:i($SpiJobQmIndex)"!]U)

[!IF "SpiGeneral/SpiLevelDelivered = 1"!][!//
/*
Configuration: Aync Mode for Level 1
By default the Mode is Interrupt mechanism. However the Mode can be switched
to Polling Manually by setting this configuration to SPI_POLLING_MODE.
In this case the interrupts QSPI0_ESRC, DMA_SRC00 are not required
*/
#define SPI_ASYNC_MODE_LEVEL1 (SPI_ASYNC_MODE_INTERRUPT)
[!ELSE!][!//
#define SPI_ASYNC_MODE_LEVEL1 (SPI_ASYNC_MODE_POLLING)
[!ENDIF!][!//

[!IF "SpiGeneral/SpiChannelBuffersAllowed = 2 or SpiGeneral/SpiChannelBuffersAllowed = 1"!][!//
/* Switch to Enable Check of DMA ADDRESS Alignment in case of EB Buffers */
#define SPI_DMA_ADDR_SIZE_ALIGN_CHECK  [!//
[!IF "SpiGeneral/SpiLevelDelivered = 1"!][!//
(STD_ON)
[!ELSE!][!//
(STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_DMA_ADDR_SIZE_ALIGN_CHECK   (STD_OFF)
[!ENDIF!][!//

/* Switch to globally enable / disable Seq end notification */
#define SPI_SEQ_END_NOTIF_REQ   ([!"$SeqNotifRequired"!])
/* Switch to globally enable / disable Job end notification */
#define SPI_JOB_END_NOTIF_REQ   ([!"$JobNotifRequired"!])

/*
 Number of HW SPI Modules:
*/
/*SPI108: The LEVEL 2 SPI Handler/Driver is specified for microcontrollers
that have to provide, at least, two SPI busses using separated hardware units.
Otherwise,using this level of functionality makes no sense.*/
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi5)"!][!//
#define SPI_MAX_HW_UNIT   (6U)
[!ELSEIF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//
#define SPI_MAX_HW_UNIT   (5U)
[!ELSEIF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi3)"!][!//
#define SPI_MAX_HW_UNIT   (4U)
[!ELSEIF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi2)"!][!//
#define SPI_MAX_HW_UNIT   (3U)
[!ELSEIF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi1)"!][!//
#define SPI_MAX_HW_UNIT   (2U)
[!ELSEIF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi0)"!][!//
#define SPI_MAX_HW_UNIT   (1U)
[!ENDIF!][!//

#define SPI_DMA_ADDRESS_ACCESS   (STD_ON)

#define SYNC_BUS (0U)
#define ASYNC_BUS (1U)
[!//
[!NOCODE!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "SpiSafety/SpiSafetyEnable = 'true'"!][!//
[!IF "SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"!][!//
  [!IF "node:refexists(node:value(concat('SpiHwConfiguration/SpiHwConfiguration','Qspi',substring-after(SpiGeneral/SpiSlaveSelectRef,'QSPI'),'/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef'))) != 'true'"!][!//
    [!ERROR!]
      Config Error:  DMA Rx channel not defined for Slave [!"SpiGeneral/SpiSlaveSelectRef"!], Spi/SpiHwConfiguration/SpiHwConfigurationQspi[!"substring-after(SpiGeneral/SpiSlaveSelectRef,'QSPI')"!]/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef
    [!ENDERROR!]
  [!ENDIF!]
[!ENDIF!][!//IF "SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"
[!ENDIF!][!//IF "$SafetyEnable = 'true'"!
[!ENDSELECT!]
[!ENDNOCODE!][!//
[!//
[!IF "SpiGeneral/SpiLevelDelivered != 0"!][!//
[!NOCODE!]
[!VAR "QSPI0HWType" = "'BUS_UNDEF'"!][!//
[!VAR "QSPI1HWType" = "'BUS_UNDEF'"!][!//
[!VAR "QSPI2HWType" = "'BUS_UNDEF'"!][!//
[!VAR "QSPI3HWType" = "'BUS_UNDEF'"!][!//
[!VAR "QSPI4HWType" = "'BUS_UNDEF'"!][!//
[!VAR "QSPI5HWType" = "'BUS_UNDEF'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!ASSERT "(node:refexists(node:ref($SpiDeviceAssignmentName)) = 'true')"!][!//
Config Error: Device assignment reference not provided for [!"node:name(.)"!]
[!ENDASSERT!]
[!IF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI0'"!][!//
   [!IF "./../../../../SpiGeneral/SpiLevelDelivered = 2"!][!//
     [!IF "./SpiHwUnitSynchronous='Synchronous'"!][!//
       [!IF "$QSPI0HWType!='ASYNC_BUS'"!][!//
         [!VAR "QSPI0HWType" = "'SYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI0
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ELSE!][!//
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI0, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI0, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "$QSPI0HWType!='SYNC_BUS'"!][!//
         [!VAR "QSPI0HWType" = "'ASYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI0
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ELSE!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI0, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI0, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
   [!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!ELSEIF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI1'"!][!//
   [!IF "./../../../../SpiGeneral/SpiLevelDelivered = 2"!][!//
     [!IF "SpiHwUnitSynchronous='Synchronous'"!][!//
       [!IF "$QSPI1HWType!='ASYNC_BUS'"!][!//
         [!VAR "QSPI1HWType" = "'SYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI1
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ELSE!][!//
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI1, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI1, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "$QSPI1HWType!='SYNC_BUS'"!][!//
         [!VAR "QSPI1HWType" = "'ASYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI1
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ELSE!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI1, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI1, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
   [!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!ELSEIF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI2'"!][!//
   [!IF "./../../../../SpiGeneral/SpiLevelDelivered = 2"!][!//
     [!IF "./SpiHwUnitSynchronous='Synchronous'"!][!//
       [!IF "$QSPI2HWType!='ASYNC_BUS'"!][!//
         [!VAR "QSPI2HWType" = "'SYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI2
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ELSE!][!//
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI2, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI2, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "$QSPI2HWType!='SYNC_BUS'"!][!//
         [!VAR "QSPI2HWType" = "'ASYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI2
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ELSE!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI2, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI2, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
   [!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!ELSEIF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI3'"!][!//
   [!IF "./../../../../SpiGeneral/SpiLevelDelivered = 2"!][!//
     [!IF "./SpiHwUnitSynchronous='Synchronous'"!][!//
       [!IF "$QSPI3HWType!='ASYNC_BUS'"!][!//
         [!VAR "QSPI3HWType" = "'SYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI3
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ELSE!][!//
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI3, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI3, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "$QSPI3HWType!='SYNC_BUS'"!][!//
         [!VAR "QSPI3HWType" = "'ASYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI3
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ELSE!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI3, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI3, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
   [!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!ELSEIF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI4'"!][!//
   [!IF "./../../../../SpiGeneral/SpiLevelDelivered = 2"!][!//
     [!IF "./SpiHwUnitSynchronous='Synchronous'"!][!//
       [!IF "$QSPI4HWType!='ASYNC_BUS'"!][!//
         [!VAR "QSPI4HWType" = "'SYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI4
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ELSE!][!//
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI4, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI4, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "$QSPI4HWType!='SYNC_BUS'"!][!//
         [!VAR "QSPI4HWType" = "'ASYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI4
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ELSE!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI4, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI4, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
   [!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!ELSEIF "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule = 'QSPI5'"!][!//
   [!IF "./../../../../SpiGeneral/SpiLevelDelivered = 2"!][!//
     [!IF "./SpiHwUnitSynchronous='Synchronous'"!][!//
       [!IF "$QSPI5HWType!='ASYNC_BUS'"!][!//
         [!VAR "QSPI5HWType" = "'SYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI5
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ELSE!][!//
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI5, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI5, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "$QSPI5HWType!='SYNC_BUS'"!][!//
         [!VAR "QSPI5HWType" = "'ASYNC_BUS'"!][!//
       [!ELSE!][!//
         [!ERROR!]
           Config Error:  SpiHwUnitSynchronous is defined both as Synchronous and Asynchronous BUS for QSPI5
         [!ENDERROR!]
       [!ENDIF!][!//
     [!ENDIF!][!//
   [!ELSE!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Tx channel not defined for QSPI5, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef"
         [!ENDERROR!]
       [!ENDIF!]
       [!IF "node:refexists(./../../../../SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef) != 'true'"!][!//
         [!ERROR!]
           Config Error:  DMA Rx channel not defined for QSPI5, "Spi/SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef"
         [!ENDERROR!]
       [!ENDIF!]
   [!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!ENDIF!]
[!ENDLOOP!]
[!ENDSELECT!]
[!ENDFOR!]
[!ENDSELECT!]
[!//
[!ENDNOCODE!]
[!ENDIF!][!//SpiGeneral/SpiLevelDelivered = 2
[!//
[!IF "SpiGeneral/SpiLevelDelivered = 1"!][!//
[!VAR "QSPI0HWType" = "'ASYNC_BUS'"!][!//
[!VAR "QSPI1HWType" = "'ASYNC_BUS'"!][!//
[!VAR "QSPI2HWType" = "'ASYNC_BUS'"!][!//
[!VAR "QSPI3HWType" = "'ASYNC_BUS'"!][!//
[!VAR "QSPI4HWType" = "'ASYNC_BUS'"!][!//
[!VAR "QSPI5HWType" = "'ASYNC_BUS'"!][!//
[!ENDIF!][!//
[!//
[!IF "SpiGeneral/SpiLevelDelivered = 0"!][!//
[!VAR "QSPI0HWType" = "'SYNC_BUS'"!][!//
[!VAR "QSPI1HWType" = "'SYNC_BUS'"!][!//
[!VAR "QSPI2HWType" = "'SYNC_BUS'"!][!//
[!VAR "QSPI3HWType" = "'SYNC_BUS'"!][!//
[!VAR "QSPI4HWType" = "'SYNC_BUS'"!][!//
[!VAR "QSPI5HWType" = "'SYNC_BUS'"!][!//
[!ENDIF!][!//
[!//
/* QSPI HW Type */
[!IF "$QSPI0Used = 'true'"!][!//
#define SPI_QSPI0_HWTYPE  ([!"$QSPI0HWType"!])
[!ENDIF!][!//
[!IF "$QSPI1Used = 'true'"!][!//
#define SPI_QSPI1_HWTYPE  ([!"$QSPI1HWType"!])
[!ENDIF!][!//
[!IF "$QSPI2Used = 'true'"!][!//
#define SPI_QSPI2_HWTYPE  ([!"$QSPI2HWType"!])
[!ENDIF!][!//
[!IF "$QSPI3Used = 'true'"!][!//
#define SPI_QSPI3_HWTYPE  ([!"$QSPI3HWType"!])
[!ENDIF!][!//
[!IF "$QSPI4Used = 'true'"!][!//
#define SPI_QSPI4_HWTYPE  ([!"$QSPI4HWType"!])
[!ENDIF!][!//
[!IF "$QSPI5Used = 'true'"!][!//
#define SPI_QSPI5_HWTYPE  ([!"$QSPI5HWType"!])
[!ENDIF!][!//
[!//
[!//
[!VAR "SpiAsyncBusModule0" = "num:i(0)"!][!//
[!VAR "SpiAsyncBusModule1" = "num:i(0)"!][!//
[!VAR "SpiAsyncBusModule2" = "num:i(0)"!][!//
[!VAR "SpiAsyncBusModule3" = "num:i(0)"!][!//
[!VAR "SpiAsyncBusModule4" = "num:i(0)"!][!//
[!VAR "SpiAsyncBusModule5" = "num:i(0)"!][!//
[!IF "$QSPI0HWType ='ASYNC_BUS'"!][!//
[!VAR "SpiAsyncBusModule0" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$QSPI1HWType ='ASYNC_BUS'"!][!//
[!VAR "SpiAsyncBusModule1" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$QSPI2HWType ='ASYNC_BUS'"!][!//
[!VAR "SpiAsyncBusModule2" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$QSPI3HWType ='ASYNC_BUS'"!][!//
[!VAR "SpiAsyncBusModule3" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$QSPI4HWType ='ASYNC_BUS'"!][!//
[!VAR "SpiAsyncBusModule4" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "$QSPI5HWType ='ASYNC_BUS'"!][!//
[!VAR "SpiAsyncBusModule5" = "num:i(1)"!][!//
[!ENDIF!][!//

[!NOCODE!][!//
[!VAR "SpiTotalAsyncModules" = "bit:and($SpiTotalMasterUsedModules,(bit:shl($SpiAsyncBusModule0,0)))"!][!//
[!VAR "SpiTotalAsyncModules" = "bit:or($SpiTotalAsyncModules,bit:and($SpiTotalMasterUsedModules,(bit:shl($SpiAsyncBusModule1,1))))"!][!//
[!VAR "SpiTotalAsyncModules" = "bit:or($SpiTotalAsyncModules,bit:and($SpiTotalMasterUsedModules,(bit:shl($SpiAsyncBusModule2,2))))"!][!//
[!VAR "SpiTotalAsyncModules" = "bit:or($SpiTotalAsyncModules,bit:and($SpiTotalMasterUsedModules,(bit:shl($SpiAsyncBusModule3,3))))"!][!//
[!VAR "SpiTotalAsyncModules" = "bit:or($SpiTotalAsyncModules,bit:and($SpiTotalMasterUsedModules,(bit:shl($SpiAsyncBusModule4,4))))"!][!//
[!VAR "SpiTotalAsyncModules" = "bit:or($SpiTotalAsyncModules,bit:and($SpiTotalMasterUsedModules,(bit:shl($SpiAsyncBusModule5,5))))"!][!//
[!ENDNOCODE!][!//

/* SPI ASYNC Modules */
#define SPI_ASYNC_MODULES   ([!"num:inttohex($SpiTotalAsyncModules, 4)"!]U)

[!IF "$SafetyEnable = 'true'"!][!//
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i($SpiSafeMasterModule))= num:i(1)"!][!//
#define SPI_ASIL_MASTER_ASYNC_USED (STD_ON)
[!ELSE!][!//
#define SPI_ASIL_MASTER_ASYNC_USED (STD_OFF)
[!ENDIF!][!//
[!ELSE!][!//
#define SPI_ASIL_MASTER_ASYNC_USED (STD_OFF)
[!ENDIF!][!//

/* Time-out counter for infinite loops */
#define SPI_LOOPCNTR_MAX (0xFFFFFFFEU)

/* Debug switch */
#define IFX_SPI_DEBUG_TX  (STD_OFF)

#define IFX_SPI_DEBUG_ERR (STD_OFF)

#define IFX_SPI_DEBUG_RST (STD_OFF)

#define IFX_SPI_DEBUG_CLC (STD_OFF)

[!NOCODE!][!//
[!// count the configured and used Async Modules
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i(0)) = num:i(1)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters + 1)"!][!//
[!ENDIF!][!//
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i(1)) = num:i(1)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters + 1)"!][!//
[!ENDIF!][!//
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i(2)) = num:i(1)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters + 1)"!][!//
[!ENDIF!][!//
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i(3)) = num:i(1)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters + 1)"!][!//
[!ENDIF!][!//
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i(4)) = num:i(1)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters + 1)"!][!//
[!ENDIF!][!//
[!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i(5)) = num:i(1)"!][!//
[!VAR "SpiTotalNumOfAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters + 1)"!][!//
[!ENDIF!][!//

[!// Substract of the ASIL master if configured as Async
[!IF "$SafetyEnable = 'true'"!][!//
  [!IF "bit:getbit(num:i($SpiTotalAsyncModules),num:i($SpiSafeMasterModule))= num:i(1)"!][!//
    [!VAR "SpiNumQmAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters) - 1"!][!//
  [!ELSE!][!//
    [!VAR "SpiNumQmAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters)"!][!//
  [!ENDIF!][!//
[!ELSE!][!//
  [!VAR "SpiNumQmAsyncMasters" = "num:i($SpiTotalNumOfAsyncMasters)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/* SPI Number of QM Async masters configured */
#define SPI_NUM_QM_ASYNC_MASTERS    ([!"num:i($SpiNumQmAsyncMasters)"!]U)

/* Module Debug Support */
#define SPI_DEBUG_SUPPORT  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiDebugSupport"!][!//

/* SpiAsyncParallelTransmit Support */
#define SPI_ASYNC_PARALLEL_TRANSMIT  [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiAsyncParallelTransmit"!][!//

/* SpiBaudrateConfigAtRuntime Support */
#define SPI_BAUDRATE_AT_RUNTIME      [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiBaudrateConfigAtRuntime"!][!//

/* SpiResetSfrAtInit Support */
#define SPI_RESET_SFR_INIT           [!//
[!CALL "CG_ConfigSwitch","node" = "SpiGeneral/SpiResetSfrAtInit"!][!//

/* Timeout count for kernel reset */
/* Kernel reset @160MHz CPU0, takes at most 59 cycles
   hence, one instance of loop takes 59 cycles(with succesful reset).
   loop counter 0x100 is sufficient for reset to happen at max clock of 300 */
#define SPI_KERNEL_RESET_WAIT_COUNT  (0x00000100U)

[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
/*
  Transmit and Receive Dma Channel IRQ Priorities.
*/
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI0_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI0_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI1_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI1_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI2_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI2_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI3_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI3_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI4_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI4_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI5_DMA_TX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI5_DMA_RX_OR_ERR_PRIO (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_PRIO)
[!ENDIF!][!//
/*
  Transmit and Receive Dma Channel IRQ CAT.
*/
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI0_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi0/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI0_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI1_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi1/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI1_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI2_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi2/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI2_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI3_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi3/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI3_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI4_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi4/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI4_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!ENDIF!][!//
[!IF "node:refexists(SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef) = 'true'"!][!//
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef)/ChannelId)"!][!//
#define IRQ_QSPI5_DMA_TX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!VAR "DmaChNum" = "(node:ref(SpiHwConfiguration/SpiHwConfigurationQspi5/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef)/ChannelId)"!][!//
#define IRQ_QSPI5_DMA_RX_OR_ERR_CAT (IRQ_DMA_CHANNEL[!"$DmaChNum"!]_SR_CAT)
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!IF "$MajorVersion = num:i(4)"!][!//
/* Dem reporting  macros */
#define DEM_REPORT_DISABLED (0U)
#define DEM_REPORT_ENABLED (1U)

[!VAR "DemReportStatus" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($SpiDriverName)/*))- 1)"!][!//
[!IF "(node:exists(node:ref($SpiDriverName)/*[@index = $ModuleIndex]/SpiDemEventParameterRefs/*[1]))"!][!//
[!IF "(node:refexists(node:ref($SpiDriverName)/*[@index = $ModuleIndex]/SpiDemEventParameterRefs/*[1]/SPI_E_DMA_TRANSFER/*[1]) = 'true') and (node:value(node:ref($SpiDriverName)/*[@index = $ModuleIndex]/SpiDemEventParameterRefs/*[1]/SPI_E_DMA_TRANSFER/*[1]) != ' ' )"!][!//
#define SPI_DMA_ERROR_DEM_REPORT    (ENABLE_DEM_REPORT)
[!SELECT "node:ref($SpiDriverName)/*[@index = $ModuleId - 1]"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SPI_E_DMA_TRANSFER  ((Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./SpiDemEventParameterRefs/*[1]/SPI_E_DMA_TRANSFER/*[1])))"!])
[!ENDSELECT!][!//
[!VAR "DemReportStatus" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$DemReportStatus = num:i(0)"!][!//
#define SPI_DMA_ERROR_DEM_REPORT    (DISABLE_DEM_REPORT)
[!ENDIF!][!//

[!VAR "DemReportStatus" = "num:i(0)"!][!//
[!FOR "ModuleIndex" = "0" TO "(num:i(count(node:ref($SpiDriverName)/*))- 1)"!][!//
[!IF "(node:exists(node:ref($SpiDriverName)/*[@index = $ModuleIndex]/SpiDemEventParameterRefs/*[1]))"!][!//
[!IF "(node:refexists(node:ref($SpiDriverName)/*[@index = $ModuleIndex]/SpiDemEventParameterRefs/*[1]/SPI_E_HARDWARE_ERROR/*[1]) = 'true') and (node:value(node:ref($SpiDriverName)/*[@index = $ModuleIndex]/SpiDemEventParameterRefs/*[1]/SPI_E_HARDWARE_ERROR/*[1]) != ' ' )"!][!//
#define SPI_HW_ERROR_DEM_REPORT    (ENABLE_DEM_REPORT)
[!SELECT "node:ref($SpiDriverName)/*[@index = $ModuleId - 1]"!][!//
/* The generated macro may exceeds 31 characters to follow Autosar naming
   conventions*/
#define SPI_E_HARDWARE_ERROR  ((Dem_EventIdType)DemConf_DemEventParameter_[!"node:name(node:ref(node:value(./SpiDemEventParameterRefs/*[1]/SPI_E_HARDWARE_ERROR/*[1])))"!])
[!ENDSELECT!][!//
[!VAR "DemReportStatus" = "num:i(1)"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$DemReportStatus = num:i(0)"!][!//
#define SPI_HW_ERROR_DEM_REPORT    (DISABLE_DEM_REPORT)
[!ENDIF!][!//
[!ENDIF!][!//

/*
Function Like Macro:Spi_DataConfig
Data Width, Data Order
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_DataConfig(DataWidth,Heading) ((uint16)(((DataWidth) - (1U))\
                                                |(((uint32)(Heading)) << (8U))))

/*
Function Like Macro:Spi_ShiftClkConfig
Configuration of Shift Clock according to Register setting:
Clock Polarity and Clock Phase/Data Shift Edge
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_ShiftClkConfig(ClkPolarity,DataShiftEdge) ((uint8)\
((uint8) ( ((uint8)(ClkPolarity)) << (1U)) | ((uint8)(DataShiftEdge)) ))

/*
Function Like Macro: Spi_BaudRateParams
Spi baud rate parameters GLOBALCON.TQ, ECON.Q, A, B, C
bit 0-7: TQ
bit 8-13 : Q
bit 16-17 : A
bit 18-19 : B
bit 20-21 : C
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_BaudRateParams(TQ, Q, A, B, C) ((uint32)((((uint32)(TQ)) )|  \
                        (((uint32)(Q)) << ( 8U))| (((uint32)(A)) << (16U))| \
                        (((uint32)(B)) << (18U))| (((uint32)(C)) << (20U))))

[!IF "$Spi_BaudrateAtRuntime = 'false'"!][!//
/*
Function Like Macro: Spi_BaudRateECON
EcoN register config values
Q [5:0]
A [7:6]
B [9:8]
C [11:10]
CPH 12
CPOL 13
PAREN 14
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_BaudRateECON(Q, A, B, C, CPH, CPOL, PAREN) ((uint32)((((uint32)(Q)) )|  \
                        (((uint32)(A)) << (6U))| (((uint32)(B)) << (8U))| \
                        (((uint32)(C)) << (10U))| (((uint32)(CPH)) << (12U)) | \
                        (((uint32)(CPOL)) << (13U))| (((uint32)(PAREN)) << (14U))))
[!ENDIF!][!//

/*
Function Like Macro: Spi_CsGpioPortPin
Bit 0 - 3 : Pin no
Bit 4 - 9 : Port no
*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_CsGpioPortPin(Port,Pin)                                       \
        ((uint16)((uint16)(((uint16)(Port)) << (4U)) | (((uint16)(Pin)))))

/*
Function Like Macro: Spi_DelayParams
Spi delay parameters according to register setting (BACON)
   bit 0 : Reserved
   bit 1-3: IPRE
   bit 4-6: IDLE
   bit 7-9: LPRE
   bit 10-12: LEAD
   bit 13-15: TPRE
   bit 16-18: TRAIL
   bit 19-31: Reserved

*/
/*IFX_MISRA_RULE_19_07_STATUS=Function like macros used in generated cfg files
                                            in order to minimise the runtime */
#define Spi_DelayParams(IPRE,IDLE,LPRE,LEAD,TPRE,TRAIL) \
((uint32)(\
(((uint32)(IPRE) & (0x7U)) << ( 1U)) | (((uint32)(IDLE)  & (0x7U)) << ( 4U))| \
(((uint32)(LPRE) & (0x7U)) << ( 7U)) | (((uint32)(LEAD)  & (0x7U)) << (10U))| \
(((uint32)(TPRE) & (0x7U)) << (13U)) | (((uint32)(TRAIL) & (0x7U)) << (16U))  \
))

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
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif  /* SPI_CFG_H */
[!ENDSELECT!]
