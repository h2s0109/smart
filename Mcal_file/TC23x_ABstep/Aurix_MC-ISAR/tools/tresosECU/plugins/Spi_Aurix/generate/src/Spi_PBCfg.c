[!/*****************************************************************************
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
**  $FILENAME   : Spi_PBCfg.c $                                              **
**                                                                            **
**  $CC VERSION : \main\88 $                                                 **
**                                                                            **
**  $DATE       : 2015-11-19 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for Spi_PBCfg.c file                         **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
/************************************************************************/!][!//
[!/*  TRACEABILITY : [cover parentID=SAS_AS_SPI123, DS_AS_SPI130_SPI131,
DS_NAS_SPI_PR700, DS_NAS_SPI_PR701, DS_NAS_SPI_PR704, DS_NAS_SPI_PR707,
DS_NAS_SPI_PR707, DS_NAS_SPI_PR712, DS_NAS_SPI_PR713, DS_NAS_SPI_PR714,
DS_NAS_SPI_PR716, DS_NAS_SPI_PR717, DS_NAS_SPI_PR723, DS_NAS_SPI_PR724,
DS_NAS_SPI_PR728, DS_NAS_SPI_PR708,
DS_NAS_SPI_PR78,  DS_NAS_SPI_PR446, SAS_MCAL_SPI_9840,
SAS_NAS_SPI_PR916,SAS_NAS_SPI_PR82,
SAS_AS4XX_SPI_PR680,
SAS_NAS_HE2_SPI_PR2956, SAS_NAS_EP_SPI_PR2956
                                                         ] [/cover]     */!][!//
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
**  FILENAME  : Spi_PBCfg.c                                                   **
**                                                                            **
**  $CC VERSION : \main\88 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                         **
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
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//
[!VAR "MinorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 1]"!][!//
[!VAR "RevisionVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 2]"!][!//

[!NOCODE!]
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "$MajorVersion = num:i(4)"!][!//
[!VAR "SpiDriverName" = "'SpiDriver'"!][!//
[!VAR "SpiSequenceName" = "'SpiSequence'"!][!//
[!VAR "Spi4StepSequence" = "'../../../../SpiSequence'"!][!//
[!VAR "Spi2StepSequence" = "'../../SpiSequence'"!][!//
[!VAR "SpiChannelName" = "'SpiChannel'"!][!//
[!VAR "SpiJobName" = "'SpiJob'"!][!//
[!VAR "Spi3StepChannel" ="'../../SpiJob'"!][!//
[!VAR "LowName" = "'LOW'"!][!//
[!VAR "LeadingName" = "'LEADING'"!][!//
[!VAR "SpiJobAssignmentName" = "'SpiJobAssignment'"!][!//
[!VAR "SpiDeviceAssignmentName" = "'SpiDeviceAssignment'"!][!//
[!ENDIF!][!//
[!//
[!VAR "TotalConfig" = "num:i(count(node:ref($SpiDriverName)/*))"!][!//
[!VAR "SafetyEnable" = "'false'"!][!//
[!IF "SpiSafety/SpiSafetyEnable = 'true'"!][!//
[!VAR "SafetyEnable" = "'true'"!][!//
[!ENDIF!][!//
[!VAR "Spi_BaudrateAtRuntime" = "SpiGeneral/SpiBaudrateConfigAtRuntime"!]
[!ENDSELECT!]
[!//

[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiAsyncPllelTransmit" = "./SpiGeneral/SpiAsyncParallelTransmit"!][!//
[!ENDSELECT!][!//
[!IF "$SpiAsyncPllelTransmit = 'true'"!][!//
[!VAR "FirstJobQspiNode" = "'NODE_UNDEF'"!][!//
[!VAR "NonFirstJobQspiNode" = "'NODE_UNDEF'"!][!//
[!ENDIF!][!//
[!/*
MACRO: CG_BaudrateDelayParams
Macro to get the Baudrate and delay parameters
*/!]
[!MACRO "CG_BaudrateDelayParams", "autocalcbaud_on" = "", "autocalcdelay_on" = "", "QSPIModuleClock2" = ""!][!//
[!NOCODE!][!//
[!//
[!IF "$autocalcbaud_on = 'true'"!][!//
[!// Calculate TQ, Q,A,B,C params based on baudrate.
    [!VAR "Loopbreak" = "'false'"!][!//
    [!VAR "ModuleClkinHz" = "$QSPIModuleClock2"!][!//
    [!FOR "QSPI_TQ" ="num:i(1)" TO "num:i(256)"!][!//
    [!FOR "QSPI_Q" ="num:i(1)" TO "num:i(64)"!][!//
    [!FOR "QSPI_A" ="num:i(1)" TO "num:i(4)"!][!//
    [!FOR "QSPI_B" ="num:i(0)" TO "num:i(3)"!][!//
    [!FOR "QSPI_C" ="num:i(0)" TO "num:i(3)"!][!//
    [!VAR "prereq1" = "$QSPI_Q * ($QSPI_A + $QSPI_B + $QSPI_C)"!][!//
    [!IF "$prereq1 >=  num:i(4)"!]
    [!VAR "calc_baudrate" = "($ModuleClkinHz) div ($QSPI_TQ) div ($prereq1)"!][!//
      [!IF "$QSPI_Baudrate =  $calc_baudrate"!]
      [!VAR "Loopbreak" = "'true'"!][!//
      [!VAR "QSPI_Q" = "num:i($QSPI_Q) - 1"!][!//
      [!VAR "QSPI_TQ" = "num:i($QSPI_TQ) - 1"!][!//
      [!VAR "QSPI_A" = "num:i($QSPI_A) - 1"!][!//
      [!BREAK!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'true'"!]
    [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'true'"!]
    [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'true'"!]
    [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'true'"!]
    [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'false'"!]
      [!ERROR!]
       No config suitable to generate baud [!"$QSPI_Baudrate"!] bps with QSPI clock [!"num:i($ModuleClkinHz)"!] Hz. Please configure the TQ, Q, A,B,C parameters instead of using SpiAutoCalcBaudAndDelayParams = ON
      [!ENDERROR!]
    [!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "$autocalcdelay_on = 'true'"!][!//
[!// Calculate IPRE, IDLE params based on SpiIdleTime. This is used for IDLEA, IDLEB
    [!VAR "Loopbreak" = "'false'"!][!//
    [!VAR "QSPI_IPRE" = "num:i(1)"!][!//
    [!FOR "Count" ="num:i(0)" TO "num:i(7)"!][!//
    [!FOR "QSPI_IDLE" ="num:i(1)" TO "num:i(8)"!][!//
    [!VAR "calc_val" = "(num:i($QSPI_IPRE) * num:i($QSPI_IDLE) div  num:i($QSPIModuleClock2))"!][!//
    [!IF "$calc_val = $QSPI_IdleTime"!][!//
      [!VAR "QSPI_IPRE" = "num:i($Count)"!][!//
      [!VAR "QSPI_IDLE" = "num:i($QSPI_IDLE) - 1"!][!//
      [!VAR "Loopbreak" = "'true'"!][!//
      [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
      [!IF "$Loopbreak = 'true'"!]
      [!BREAK!][!//
      [!ELSE!][!//
      [!VAR "QSPI_IPRE" = "$QSPI_IPRE * 4"!][!//
      [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'false'"!]
      [!ERROR!]
       No config suitable for SpiIdleTime ([!"$QSPI_IdleTime"!] sec) generation with QSPI clock [!"num:i($QSPIModuleClock2)"!] Hz. Please configure the SpiQSpiParamIPre, SpiQSpiParamIPre parameters instead of using SpiAutoCalcBaudAndDelayParams = ON
      [!ENDERROR!]
    [!ENDIF!][!//

[!// Calculate LPRE, LEAD params based on TimeClk2Cs.
    [!VAR "Loopbreak" = "'false'"!][!//
    [!VAR "QSPI_LPRE" = "num:i(1)"!][!//
    [!FOR "Count" ="num:i(0)" TO "num:i(7)"!][!//
    [!FOR "QSPI_LEAD" ="num:i(1)" TO "num:i(8)"!][!//
    [!VAR "calc_val" = "($QSPI_LPRE * $QSPI_LEAD) div num:i($QSPIModuleClock2)"!][!//
    [!IF "$calc_val = $QSPI_TimeClk2Cs"!][!//
      [!VAR "QSPI_LPRE" = "num:i($Count)"!][!//
      [!VAR "QSPI_LEAD" = "num:i($QSPI_LEAD) - 1"!][!//
      [!VAR "Loopbreak" = "'true'"!][!//
      [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
      [!IF "$Loopbreak = 'true'"!]
      [!BREAK!][!//
      [!ELSE!][!//
      [!VAR "QSPI_LPRE" = "$QSPI_LPRE * 4"!][!//
      [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'false'"!]
      [!ERROR!]
       No config suitable for TimeClk2Cs [!"$QSPI_TimeClk2Cs"!]generation . Please configure the SpiQSpiParamLPre, SpiQSpiParamLead parameters instead of using SpiAutoCalcBaudAndDelayParams = ON
      [!ENDERROR!]
    [!ENDIF!][!//

[!// Calculate TPRE, TRAIL params based on SpiTrailingTime.
    [!VAR "Loopbreak" = "'false'"!][!//
    [!VAR "QSPI_TPRE" = "num:i(1)"!][!//
    [!FOR "Count" ="num:i(0)" TO "num:i(7)"!][!//
    [!FOR "QSPI_TRAIL" ="num:i(1)" TO "num:i(8)"!][!//
    [!VAR "calc_val" = "($QSPI_TPRE * $QSPI_TRAIL ) div  num:i($QSPIModuleClock2)"!][!//
    [!IF "$calc_val = $QSPI_TrailTime"!][!//
      [!VAR "QSPI_TPRE" = "num:i($Count)"!][!//
      [!VAR "QSPI_TRAIL" = "num:i($QSPI_TRAIL) - 1"!][!//
      [!VAR "Loopbreak" = "'true'"!][!//
      [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'true'"!]
      [!BREAK!][!//
      [!ELSE!][!//
      [!VAR "QSPI_TPRE" = "$QSPI_TPRE * 4"!][!//
    [!ENDIF!][!//
    [!ENDFOR!][!//
    [!IF "$Loopbreak = 'false'"!]
      [!ERROR!]
       No config suitable for Trail timing/s ([!"$QSPI_TrailTime"!] sec) generation with QSPI clock [!"num:i($QSPIModuleClock2)"!] Hz. Please configure the SpiQSpiParamTPre, SpiQSpiParamTrail parameters instead of using SpiAutoCalcBaudAndDelayParams = ON
      [!ENDERROR!]
    [!ENDIF!][!//

[!ELSE!][!// AutoCalc STD_OFF
[!//  [!VAR "QSPI_Baudrate" = "(num:i($QSPI_TQ+1) * num:i($QSPI_Q+1) * ($QSPI_A + 1 + $QSPI_B + $QSPI_C)) div ($QSPIModuleClock2)"!][!//
[!//  [!VAR "QSPI_TimeClk2Cs" = "0"!][!//
[!ENDIF!][!// AutoCalc
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*
MACRO: Compare_DmaChannels.
Compares the dma channel/s in MCU (allocated for Spi) and Spi configuration.
Raises an assert if they don't match
SpiDmaRef: Reference to 'Spi/SpiHwConfiguration/SpiHwConfigurationQspix'
*/!]
[!MACRO "Compare_DmaChannels", "SpiDmaRef" = "", "McuDmaRef2" = ""!][!//
[!/*
Compares the dma channel/s in MCU (allocated for Spi) and Spi configuration.
Raises an assert if they don't match
McuDmaRef2: reference to Mcu/McuModuleConfiguration/DmaConfiguration
SpiDmaRef: Reference to Spi/SpiHwConfiguration/SpiHwConfigurationQspix
 */!]
[!SELECT "as:modconf('Spi')[1]"!][!//
[!NOCODE!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!VAR "DmaNode" = "concat($SpiDmaRef,'/SpiHwDmaConfiguration')"!][!//
[!IF "node:exists(($DmaNode))"!][!//
[!VAR "DmaNode" = "concat($SpiDmaRef,'/SpiHwDmaConfiguration/SpiHwDmaChannelTransmissionRef')"!][!//
[!VAR "DmaRxNode" = "concat($SpiDmaRef,'/SpiHwDmaConfiguration/SpiHwDmaChannelReceptionRef')"!][!//
[!IF "node:refexists(node:ref($DmaNode)) = 'true'"!][!//
[!VAR "DmaChNum" = "node:ref(node:ref($DmaNode))/ChannelId"!][!//
[!VAR "SpiDmaChTX" = "concat('DMA_CHANNEL', $DmaChNum)"!][!//
[!ELSE!][!//
[!VAR "SpiDmaChTX" = "'DMA_CHANNEL_INVALID'"!][!//
[!ENDIF!][!//

[!IF "node:refexists(node:ref($DmaRxNode)) = 'true'"!][!//
[!VAR "DmaChNum" = "node:ref(node:ref($DmaRxNode))/ChannelId"!][!//
[!VAR "SpiDmaChRX" = "concat('DMA_CHANNEL', $DmaChNum)"!][!//
[!ELSE!][!//
[!VAR "SpiDmaChRX" = "'DMA_CHANNEL_INVALID'"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "SpiDmaChTX" = "'DMA_CHANNEL_INVALID'"!][!//
[!VAR "SpiDmaChRX" = "'DMA_CHANNEL_INVALID'"!][!//
[!ENDIF!][!//
[!//[!VAR "McuDmaRef2" = "node:path(node:ref(SpiHwConfiguration/SystemClock)/../../../DmaConfiguration)"!][!//
[!IF "$SpiDmaChTX != 'DMA_CHANNEL_INVALID' and $SpiDmaChRX != 'DMA_CHANNEL_INVALID'"!][!/* usecase: if QSPIx is unused, the coresponding dma channel/s neednot be allocated/configured*/!][!//
[!VAR "DmaChUsed" = "node:ref(node:ref($DmaNode))/ChannelId"!][!//
[!IF "node:ref($McuDmaRef2)/*[1]/DmaChannel/*[ChannelId=$DmaChUsed]/ChannelUsed != 'USE_FOR_SPI_DRIVER'"!][!//
[!ERROR!]
Configure the [!"$SpiDmaChTX"!] for SPI in Mcu Configuration [!//
 [!ENDERROR!][!//
[!ENDIF!]
[!VAR "DmaChUsed" = "node:ref(node:ref($DmaRxNode))/ChannelId"!][!//
[!IF "node:ref($McuDmaRef2)/*[1]/DmaChannel/*[ChannelId=$DmaChUsed]/ChannelUsed != 'USE_FOR_SPI_DRIVER'"!][!//
[!ERROR!]
Configure the [!"$SpiDmaChRX"!] for SPI in Mcu Configuration [!//
 [!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!/* DMA_NOT_USED */!][!//
[!ENDNOCODE!][!//
[!ENDSELECT!][!//
[!ENDMACRO!][!//

[!/* This loop is to generate multiple instances of Spi configuration */!][!//
[!FOR "ModuleId" ="num:i(0)" TO "num:i($TotalConfig) - 1"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!//

[!// Check if device assignment reference is present.
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = $ModuleId]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!ASSERT "(node:refexists(node:ref($SpiDeviceAssignmentName)) = 'true')"!][!//
Config Error: Device assignment reference not provided for [!"node:name(.)"!]
[!ENDASSERT!]
[!ENDLOOP!][!//
[!ASSERT "node:refexists(./SpiSystemClock) = 'true'", "System Clock reference not provided"!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//

[!SELECT "node:ref($SpiDriverName)/*[@index = $ModuleId]"!][!//
[!ENDSELECT!][!//

[!ENDSELECT!][!// MODULE-CONFIGURATION
[!ENDFOR!][!//

[!// Calculation of System Clock frequency
[!//[!VAR "QSPIModuleClock" = "num:i(node:ref(SpiHwConfiguration/SystemClock)/McuClockBAUD2Frequency)"!][!//

[!/*
MACRO: CG_GetSequenceSharingJobs.
Get for each sequence, the other sequences that shares a job with the
current sequence.
seqid: The name of the sequence.
*/!]

[!MACRO "CG_GetSequenceSharingJobs", "SeqName" = ""!][!//
[!/*
when the macro is called SpiDriverConfiguration/*[@index =$Index]/SpiSequenceConfiguration/*
get the job */!]
[!NOCODE!][!//
[!LOOP "node:ref($SpiJobAssignmentName)/*"!][!//
    [!VAR "JobName" ="node:name(node:ref(.))"!][!//
  [!LOOP "node:ref($Spi4StepSequence)/*"!][!//
    [!VAR "RefSeqName" = "node:name(.)"!][!//
        [!IF "$RefSeqName != $SeqName"!][!//
            [!LOOP "node:ref($SpiJobAssignmentName)/*"!][!//
            [!VAR "RefJobName" = "node:name(node:ref(.))"!][!//
                [!IF "$JobName = $RefJobName"!][!//
                [!VAR "IsSeqShared" = "'1'"!][!//
                [!BREAK!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//
        [!ENDIF!][!//
    [!IF "$IsSeqShared = '1'"!][!//
    [!BREAK!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*
MACRO: CG_SetSequenceSharing.
Set for each sequence, the other sequences that shares a job with the
current sequence.
seqid: The name of the sequence.
*/!]
[!MACRO "CG_SetSequenceSharing", "SeqName" = ""!][!//
[!/*
when the macro is called SpiDriverConfiguration/*[@index =$Index]/SpiSequenceConfiguration/*
get the job */!]
[!NOCODE!][!//
[!LOOP "node:ref($SpiJobAssignmentName)/*"!][!//
[!VAR "JobSeqShared" = "'0'"!][!//
[!VAR "JobName" ="node:name(node:ref(.))"!][!//
[!LOOP "node:ref($Spi4StepSequence)/*"!][!//
[!VAR "RefSeqName" = "node:name(.)"!][!//
[!IF "$RefSeqName != $SeqName"!][!//
[!LOOP "node:ref($SpiJobAssignmentName)/*"!][!//
[!VAR "RefJobName" = "node:name(node:ref(.))"!][!//
[!IF "$JobName = $RefJobName"!][!//
[!VAR "JobSeqShared" = "'1'"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$JobSeqShared = '1'"!][!//
[!VAR "Cntr" = "@index"!][!//
[!IF "$Cntr < 32"!][!//
[!VAR "SEQSHARE_0" = "bit:bitset($SEQSHARE_0,num:i($Cntr))"!][!//
[!ELSEIF "$Cntr < 64"!][!//
[!VAR "SEQSHARE_1" = "bit:bitset($SEQSHARE_1,num:i($Cntr) - 32)"!][!//
[!ELSEIF "$Cntr < 96"!][!//
[!VAR "SEQSHARE_2" = "bit:bitset($SEQSHARE_2,num:i($Cntr) - 64)"!][!//
[!ELSEIF "$Cntr < 128"!][!//
[!VAR "SEQSHARE_3" = "bit:bitset($SEQSHARE_3,num:i($Cntr) - 96)"!][!//
[!ELSEIF "$Cntr < 160"!][!//
[!VAR "SEQSHARE_4" = "bit:bitset($SEQSHARE_4,num:i($Cntr) - 128)"!][!//
[!ELSEIF "$Cntr < 192"!][!//
[!VAR "SEQSHARE_5" = "bit:bitset($SEQSHARE_5,num:i($Cntr) - 160)"!][!//
[!ELSEIF "$Cntr < 224"!][!//
[!VAR "SEQSHARE_6" = "bit:bitset($SEQSHARE_6,num:i($Cntr) - 192)"!][!//
[!ELSEIF "$Cntr < 256"!][!//
[!VAR "SEQSHARE_7" = "bit:bitset($SEQSHARE_7,num:i($Cntr) - 224)"!][!//
[!ENDIF!][!//

[!VAR "JobSeqShared" = "'0'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!/*
MACRO: CG_SetHwForSeq.
*/!]
[!MACRO "CG_SetHwForSeq"!][!//
[!/*
when the macro is called SpiDriverConfiguration/*[@index =$Index]/SpiSequenceConfiguration/*
 */!]
[!NOCODE!][!//
[!VAR "SeqHwUnits" = "num:i(0)"!][!//
[!LOOP "node:ref($SpiJobAssignmentName)/*"!][!//
[!IF "$MajorVersion = num:i(4)"!][!//
[!VAR "hw_channel" = "number(substring-after(node:ref(node:ref(.)/SpiDeviceAssignment)/SpiHwUnit/SpiAssignedHwModule , 'QSPI'))"!][!//
[!ENDIF!][!//
[!VAR "SeqHwUnits" = "bit:bitset($SeqHwUnits, $hw_channel)"!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//

[!ENDNOCODE!]

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Include SPI Module File */
/* [cover parentID=DS_NAS_SPI_PR699,DS_NAS_SPI_PR709] */

#include "Spi.h"
/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
[!IF "$SafetyEnable = 'true'"!][!//
/*
Configuration: SPI_SAFETY_MARKER
This verifies the authenticity of the Spi_ConfigRoot pointer.
*/
#define SPI_SAFETY_MARKER  (((uint32)SPI_MODULE_ID << 16U) | \
                             (uint32)SPI_INSTANCE_ID)
[!ENDIF!][!//
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
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
/* MISRA RULE 87 VIOLATION: Inclusion of MemMap.h in between the code can't
   be avoided as it is required for mapping global variables, constants
   and code
*/
/* Violates MISRA Required Rule 16.9,
            function identifier used without '&' or parenthisized parameter list
           when using function pointer in configurations
*/

/*
                     Container: SpiChannelConfiguration
*/
#define SPI_START_SEC_POSTBUILDCFG
/*
 * To be used for global or static constants (unspecified size)
*/
#include "MemMap.h"
[!//
[!/* This loop is to generate multiple instances of Spi configuration */!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 1 or SpiGeneral/SpiLevelDelivered = 2"!][!//
[!VAR "SpiIntSeqAllowed" = "./SpiGeneral/SpiInterruptibleSeqAllowed"!][!//
[!ELSE!][!//
[!VAR "SpiIntSeqAllowed" ="'false'"!][!//
[!ENDIF!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
/*
Configuration : Channel Configuration Constant Structure.
The IB Channels are configured first followed by EB.
*/
static const Spi_ChannelConfigType Spi_kChannelConfig[!"string(($Index))"!][] =
{
[!VAR "SpiIbPerChannel" = "'0'"!][!//
[!VAR "SpiEbPerChannel" = "'0'"!][!//
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!//
[!IF "./SpiGeneral/SpiChannelBuffersAllowed = 2 or ./SpiGeneral/SpiChannelBuffersAllowed = 0"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!IF "num:i(SpiDataWidth) > num:i(16)"!][!//
/* IB Channel: [!"node:name(.)"!] Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)[!"num:inttohex(./SpiDefaultData, 8)"!]U,
    /* Data Configuration */
    Spi_DataConfig([!"num:i(./SpiDataWidth)"!]U, /* Data Width */
                   SPI_DATA_[!"./SpiTransferStart"!]_FIRST), /* Transfer Start */
    [!IF "num:i(./SpiDataWidth) > num:i(16)"!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(65535)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 65535 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(num:i(./SpiIbNBuffers) * num:i(4))"!]U,
    [!ELSEIF "num:i(./SpiDataWidth) > num:i(8)"!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(32767)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 32767 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(num:i(./SpiIbNBuffers) * num:i(2))"!]U,
    [!ELSE!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(16383)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 16383 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(./SpiIbNBuffers)"!]U,
    [!ENDIF!][!//
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_[!"./SpiChannelType"!]_BUFFER,
    [!IF "$SafetyEnable = 'true'"!][!//
    /* Safety Buffer Marker */
    [!"./SpiSafetyBufferMarker"!]U,
    [!ENDIF!][!//
  },
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!IF "num:i(SpiDataWidth) > num:i(8) and num:i(SpiDataWidth) <= num:i(16)"!][!//
/* IB Channel: [!"node:name(.)"!] Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)[!"num:inttohex(./SpiDefaultData, 8)"!]U,
    /* Data Configuration */
    Spi_DataConfig([!"num:i(./SpiDataWidth)"!]U, /* Data Width */
                   SPI_DATA_[!"./SpiTransferStart"!]_FIRST), /* Transfer Start */
    [!IF "num:i(./SpiDataWidth) > num:i(16)"!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(65535)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 65535 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(num:i(./SpiIbNBuffers) * num:i(4))"!]U,
    [!ELSEIF "num:i(./SpiDataWidth) > num:i(8)"!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(32767)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 32767 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(num:i(./SpiIbNBuffers) * num:i(2))"!]U,
    [!ELSE!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(16383)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 16383 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(./SpiIbNBuffers)"!]U,
    [!ENDIF!][!//
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_[!"./SpiChannelType"!]_BUFFER,
    [!IF "$SafetyEnable = 'true'"!][!//
    /* Safety Buffer Marker */
    [!"./SpiSafetyBufferMarker"!]U,
    [!ENDIF!][!//
  },
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'IB']"!][!//
[!IF "num:i(SpiDataWidth) <= num:i(8)"!][!//
/* IB Channel: [!"node:name(.)"!] Configuration */
  {
    /*IB Channels : Number of IB Buffers*/
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)[!"num:inttohex(./SpiDefaultData, 8)"!]U,
    /* Data Configuration */
    Spi_DataConfig([!"num:i(./SpiDataWidth)"!]U, /* Data Width */
                   SPI_DATA_[!"./SpiTransferStart"!]_FIRST), /* Transfer Start */
    [!IF "num:i(./SpiDataWidth) > num:i(16)"!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(65535)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 65535 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(num:i(./SpiIbNBuffers) * num:i(4))"!]U,
    [!ELSEIF "num:i(./SpiDataWidth) > num:i(8)"!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(32767)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 32767 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(num:i(./SpiIbNBuffers) * num:i(2))"!]U,
    [!ELSE!][!//
     [!IF "$SpiLevel = 1"!][!//
      [!VAR "SpiIbPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!IF "$SpiIbPerChannel > num:i(16383)"!][!//
      [!ERROR!]
      Config Error: maximum allowed 16383 in IB Channel: [!"node:name(.)"!] Configuration
      [!ENDERROR!]
      [!ENDIF!][!//
     [!ENDIF!][!//
    (Spi_NumberOfDataType)[!"num:i(./SpiIbNBuffers)"!]U,
    [!ENDIF!][!//
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_[!"./SpiChannelType"!]_BUFFER,
    [!IF "$SafetyEnable = 'true'"!][!//
    /* Safety Buffer Marker */
    [!"./SpiSafetyBufferMarker"!]U,
    [!ENDIF!][!//
  },
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//

[!ENDSELECT!][!//
[!ENDIF!][!//
[!//
[!IF "./SpiGeneral/SpiChannelBuffersAllowed = 2 or ./SpiGeneral/SpiChannelBuffersAllowed = 1"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!LOOP "node:ref($SpiChannelName)/*[SpiChannelType = 'EB']"!][!//
/* EB Channel: [!"node:name(.)"!] Configuration */
  {
    /* Default Data, SPI_DEFAULT_DATA */
    (uint32)[!"num:inttohex(./SpiDefaultData, 8)"!]U,
    /* Data Configuration */
    Spi_DataConfig([!"num:i(./SpiDataWidth)"!]U, /* Data Width */
                   SPI_DATA_[!"./SpiTransferStart"!]_FIRST), /* Transfer Start */
    [!IF "num:i(./SpiDataWidth) > num:i(16)"!][!//
    [!IF "$SpiLevel = 1"!][!//
    [!VAR "SpiEbPerChannel" = "num:i(./SpiEbMaxLength)"!][!//
    [!IF "$SpiEbPerChannel > num:i(65535)"!][!//
    [!ERROR!]
    Config Error: maximum allowed 65535 in EB Channel: [!"node:name(.)"!] Configuration
    [!ENDERROR!]
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!ELSEIF "num:i(./SpiDataWidth) > num:i(8)"!][!//
    [!IF "$SpiLevel = 1"!][!//
    [!VAR "SpiEbPerChannel" = "num:i(./SpiEbMaxLength)"!][!//
    [!IF "$SpiEbPerChannel > num:i(32767)"!][!//
    [!ERROR!]
    Config Error: maximum allowed 32767 in EB Channel: [!"node:name(.)"!] Configuration
    [!ENDERROR!]
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!ELSE!][!//
    [!IF "$SpiLevel = 1"!][!//
    [!VAR "SpiEbPerChannel" = "num:i(./SpiEbMaxLength)"!][!//
    [!IF "$SpiEbPerChannel > num:i(16383)"!][!//
    [!ERROR!]
    Config Error: maximum allowed 16383 in EB Channel: [!"node:name(.)"!] Configuration
    [!ENDERROR!]
    [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
    /* EB Channels : SPI112: Max EB Buffers  */
    (Spi_NumberOfDataType)[!"num:i(./SpiEbMaxLength)"!]U,
    /* Buffer Type, SPI_CHANNEL_TYPE */
    (uint8)SPI_[!"./SpiChannelType"!]_BUFFER,
    [!IF "$SafetyEnable = 'true'"!][!//
    /* Safety Buffer Marker */
    [!"./SpiSafetyBufferMarker"!]U,
    [!ENDIF!][!//
  },
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
};
[!ENDFOR!][!//
[!ENDSELECT!][!//

/*
                    Container: SpiJobConfiguration
*/
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiJobEndNotify" = "'NULL_PTR'"!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipJobName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
[!IF "node:exists(./SpiJobEndNotification)"!][!//
[!VAR "SpiJobEndNotify" = "./SpiJobEndNotification"!][!//
[!ENDIF!][!//
[!IF "$SpiJobEndNotify = 'NULL_PTR'"!][!//
/* Notification Function of [!"node:name(.)"!] is NULL_PTR */
[!ELSE!][!//
/* Notification Function of [!"node:name(.)"!] */
extern void [!"$SpiJobEndNotify"!](void);[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!NOCODE!]
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 2"!][!//
  [!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
  [!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
    [!LOOP "node:ref($SpiChannelName)/*"!][!//
      [!VAR "SpiChName" = "node:name(.)"!][!//
      [!VAR "DataWidth" = "./SpiDataWidth"!][!//
      [!IF "./SpiChannelType = 'EB'"!][!//
      [!VAR "SpiWordsPerChannel" = "num:i(./SpiEbMaxLength)"!][!//
      [!ELSE!][!//
      [!VAR "SpiWordsPerChannel" = "num:i(./SpiIbNBuffers)"!][!//
      [!ENDIF!][!//
      [!SELECT "node:ref($Spi3StepChannel)"!][!//
      [!LOOP "./*[./SpiHwUnitSynchronous = 'Asynchronous']"!][!// Loop on total number of Async Jobs
      [!IF "$MajorVersion >= num:i(4)"!][!//
        [!FOR "Index1" = "num:i(0)" TO "num:i(count(SpiChannelList/*)) - num:i(1)"!][!//
          [!VAR "ChanSel" = "concat('SpiChannelList/*[',$Index1 + 1,']/SpiChannelAssignment')"!][!//
          [!VAR "RefChannel" ="node:ref($ChanSel)"!][!//
          [!IF "$SpiChName = node:name($RefChannel)"!][!//
            [!IF "num:i($DataWidth) > num:i(16)"!][!//
              [!IF "$SpiWordsPerChannel > num:i(65535)"!][!//
                [!ERROR!]
                Config Error: maximum allowed 65535 in channel [!"$SpiChName"!]
                [!ENDERROR!]
              [!ENDIF!][!//
            [!ELSEIF "num:i($DataWidth) > num:i(8)"!][!//
              [!IF "$SpiWordsPerChannel > num:i(32767)"!][!//
                [!ERROR!]
                Config Error: maximum allowed 32767 in channel [!"$SpiChName"!]
                [!ENDERROR!]
              [!ENDIF!][!//
            [!ELSE!][!//
               [!IF "$SpiWordsPerChannel > num:i(16383)"!][!//
                [!ERROR!]
                Config Error: maximum allowed 16383 in channel [!"$SpiChName"!]
                [!ENDERROR!]
              [!ENDIF!][!//$SpiWordsPerChannel > num:i(16383)
            [!ENDIF!][!// num:i($DataWidth) > num:i(8)
          [!ENDIF!][!// $SpiChName = $RefChannel
        [!ENDFOR!][!//
      [!ENDIF!][!//
      [!ENDLOOP!][!//
    [!ENDSELECT!][!// end of ../../SpiJobConfiguration
    [!ENDLOOP!][!//
  [!ENDSELECT!][!//
  [!ENDFOR!][!//
[!ENDIF!][!// SpiGeneral/SpiLevelDelivered = 2
[!ENDSELECT!][!//
[!ENDNOCODE!]

[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipJobName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
/*
Configuration: Channel Assignment
*/
/*Channel Assignment of Job: [!"node:name(.)"!]*/
static const Spi_ChannelType [!"node:name(.)"!]_ChannelLinkPtr[] =
{
[!IF "$MajorVersion >= num:i(4)"!][!//
[!VAR "TotalChannelCount" = "num:i(0)"!][!//
[!VAR "ChanIdxChksumRef" = "num:i(0)"!][!//
[!VAR "ChanIdxChksum" = "num:i(0)"!][!//
[!FOR "Index2" = "num:i(0)" TO "num:i(count(SpiChannelList/*)) - num:i(1)"!][!//
[!VAR "ChanIdxChksumRef" = "$ChanIdxChksumRef + $Index2"!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(SpiChannelList/*)) - num:i(1)"!][!//
[!VAR "ChanIdx" = "concat('SpiChannelList/*[',$Index1 + 1,']')"!][!//
[!VAR "ChanSel" = "concat('SpiChannelList/*[',$Index1 + 1,']/SpiChannelAssignment')"!][!//
[!VAR "RefChanSel" = "node:ref($ChanSel)"!][!//
[!IF "num:i(node:ref($ChanIdx)/SpiChannelIndex) = num:i($Index2)"!][!//
[!ASSERT "string-length($RefChanSel) != 0"!][!//
Config Error: Channel assignment reference not provided for [!"node:name(.)"!] , index [!"$Index1"!]
[!ENDASSERT!][!//
[!VAR "TotalChannelCount" = "$TotalChannelCount + 1"!][!//
[!VAR "path" ="node:name(node:ref(./SpiChannelList/*[@index = $Index1]/SpiChannelAssignment))"!][!//
[!VAR "ChanIdxChksum" = "$ChanIdxChksum + $Index2"!][!//
  SpiConf_SpiChannel_[!"$path"!],
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ASSERT "num:i($TotalChannelCount) = num:i(count(SpiChannelList/*))"!][!//
Config Error: Parameter SpiChannelIndex for some channels in Job [!"node:name(.)"!] is NOT Configured properly. SpiChannelIndex needs to be unique number.
[!ENDASSERT!][!//
[!ASSERT "num:i($ChanIdxChksum) = num:i($ChanIdxChksumRef)"!][!//
Config Error: Parameter SpiChannelIndex for some channels in Job [!"node:name(.)"!] is NOT Configured properly. SpiChannelIndex needs to be unique number.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!//
  SPI_CHANNEL_LINK_DELIMITER
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//

[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
/*
Configuration: Job Configuration Constant Structure.
*/
static const Spi_JobConfigType Spi_kJobConfig[!"string(($Index))"!][] =
{
[!SELECT "node:ref($SpiDriverName)/*[@index = $Index]"!][!//
[!VAR "QSPIModuleClock" = "num:i(node:ref(./SpiSystemClock)/McuClockBAUD2Frequency)"!][!//

[!LOOP "node:ref($SpiJobName)/*"!][!//
/* Job: [!"node:name(.)"!] Configuration */
  {
[!IF "$SpiLevel = 0"!][!//
[!ASSERT "(node:refexists(node:ref($SpiDeviceAssignmentName)) = 'true')"!][!//
Config Error: Device assignment reference not provided for [!"node:name(.)"!][!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!IF "$SpiLevel = 1 or $SpiLevel = 2"!][!//
[!VAR "SymbolicName" = "./SpiJobEndNotification"!][!//
[!IF "$SymbolicName != 'NULL_PTR'"!][!//
[!IF "$PostBuildType != 'SELECTABLE'"!][!//
[!ASSERT "(num:isnumber($SymbolicName)= 'true')"!][!//
ERROR: Under LOADABLE option SpiJobEnd Notification should be entered as a Address. Change notification of [!"node:name(.)"!][!//
[!ENDASSERT!][!//
[!VAR "SymbolicName" = "concat('(Spi_NotifFunctionPtrType)',$SymbolicName,'U')"!][!//
[!ELSE!][!//
[!ASSERT "(num:isnumber($SymbolicName)!= 'true')"!][!//
ERROR: Under SELECTABLE option SpiJobEnd Notification should be entered as a function name. Change notification of [!"node:name(.)"!][!//
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
   /* Job End Notification: Spi_JobEndNotification, SPI118 */
  [!IF "($SymbolicName != 'NULL_PTR') and  ($PostBuildType = 'SELECTABLE')"!][!//
    &[!"$SymbolicName"!],
  [!ELSE!][!//
    [!"$SymbolicName"!],
  [!ENDIF!][!//
[!ENDIF!][!//
    /* User given name outside the naming convention */
    /* Spi_ChannelLinkPtr */
    [!"node:name(.)"!]_ChannelLinkPtr,
[!//
[!VAR "tmpVar" = "node:path(node:ref(node:ref($SpiDeviceAssignmentName)))"!][!//
[!VAR "autocalcbaud_en" = "node:value(node:ref(concat($tmpVar, '/SpiAutoCalcBaudParams')))"!][!//
[!//
[!VAR "autocalcdelay_en" = "node:value(node:ref(concat($tmpVar, '/SpiAutoCalcDelayParams')))"!][!//
[!//
[!VAR "ParitySupportVal" = "node:value(node:ref(concat($tmpVar, '/SpiParitySupport')))"!][!//
[!//
[!IF "$autocalcdelay_en = 'false'"!][!//
[!VAR "QSPI_LPRE" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamLPre')))"!][!//
[!VAR "QSPI_LEAD" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamLead')))"!][!//
[!VAR "QSPI_TPRE" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamTPre')))"!][!//
[!VAR "QSPI_TRAIL" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamTrail')))"!][!//
[!VAR "QSPI_IPRE" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamIPre')))"!][!//
[!VAR "QSPI_IDLE" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamIdle')))"!][!//
[!VAR "QSPI_TimeClk2Cs" = "num:i(0)"!][!//
[!VAR "QSPI_TrailTime" = "num:i(0)"!][!//
[!VAR "QSPI_IdleTime" = "num:i(0)"!][!//
[!ELSE!][!//
[!VAR "QSPI_TimeClk2Cs" = "node:value(node:ref(concat($tmpVar, '/SpiTimeClk2Cs')))"!][!//
[!VAR "QSPI_TrailTime" = "node:value(node:ref(concat($tmpVar, '/SpiTrailingTime')))"!][!//
[!VAR "QSPI_IdleTime" = "node:value(node:ref(concat($tmpVar, '/SpiIdleTime')))"!][!//
[!VAR "QSPI_LPRE" = "num:i(0)"!][!//
[!VAR "QSPI_LEAD" = "num:i(0)"!][!//
[!VAR "QSPI_TPRE" = "num:i(0)"!][!//
[!VAR "QSPI_TRAIL" = "num:i(0)"!][!//
[!VAR "QSPI_TQ" = "num:i(0)"!][!//
[!VAR "QSPI_Q" = "num:i(0)"!][!//
[!VAR "QSPI_IPRE" = "num:i(0)"!][!//
[!VAR "QSPI_IDLE" = "num:i(0)"!][!//
[!VAR "QSPI_A" = "num:i(0)"!][!//
[!VAR "QSPI_B" = "num:i(0)"!][!//
[!VAR "QSPI_C" = "num:i(0)"!][!//
[!ENDIF!][!//
[!//
[!IF "$autocalcbaud_en = 'false'"!][!//
[!VAR "QSPI_TQ" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamTq')))"!][!//
[!VAR "QSPI_Q" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamQ')))"!][!//
[!VAR "QSPI_A" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamA')))"!][!//
[!VAR "QSPI_B" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamB')))"!][!//
[!VAR "QSPI_C" = "node:value(node:ref(concat($tmpVar, '/SpiQSpiParamC')))"!][!//
[!VAR "QSPI_Baudrate" = "num:i($QSPIModuleClock) div (num:i($QSPI_TQ+1) * num:i($QSPI_Q+1) * ($QSPI_A + 1 + $QSPI_B + $QSPI_C))"!][!//
[!IF "$QSPI_Baudrate > num:i(50 * 1000000)"!][!//
[!ERROR!][!//
Config Error: Spi Baudrate [!"$QSPI_Baudrate"!] should be less than 50Mhz. Configure TQ, Q, A, B, C parameters acordingly.
[!ENDERROR!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!VAR "QSPI_Baudrate" = "node:value(node:ref(concat($tmpVar, '/SpiBaudrate')))"!][!//
[!ENDIF!][!//
[!//
[!CALL "CG_BaudrateDelayParams","autocalcbaud_on" = "$autocalcbaud_en","autocalcdelay_on" = "$autocalcdelay_en","QSPIModuleClock2" = "$QSPIModuleClock"!][!//
    /* Baud Rate ([!"num:i($QSPI_Baudrate)"!] Hz) Hw configuration Parameters */
    Spi_BaudRateParams(/*TQ*/([!"num:inttohex($QSPI_TQ)"!]U), /*Q*/([!"num:inttohex($QSPI_Q)"!]U),
              /*A*/([!"num:inttohex($QSPI_A)"!]U), /*B*/([!"num:inttohex($QSPI_B)"!]U), /*C*/([!"num:inttohex($QSPI_C)"!]U)),

    /* Time Delay Configuration */
      (uint32)Spi_DelayParams(/*IPRE*/[!"num:inttohex($QSPI_IPRE , 2)"!]U,/*IDLE*/ [!"num:inttohex($QSPI_IDLE, 2)"!]U,
        /*LPRE*/[!"num:inttohex($QSPI_LPRE, 2)"!]U, /*LEAD*/[!"num:inttohex($QSPI_LEAD, 2)"!]U,
        /*TPRE*/[!"num:inttohex($QSPI_TPRE, 2)"!]U, /*TRAIL*/[!"num:inttohex($QSPI_TRAIL, 2)"!]U),

[!IF "node:value(node:ref(concat($tmpVar, '/SpiEnableCs'))) = 'true'"!][!//
[!IF "node:value(node:ref(concat($tmpVar, '/SpiCsSelection'))) = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
    SPI_CS_HW, /* Hw CS Pin is Selected */
[!ELSEIF "node:value(node:ref(concat($tmpVar, '/SpiCsSelection'))) = 'CS_VIA_GPIO'"!][!//
[!VAR "PortValue" = "node:value(node:ref(concat($tmpVar, '/SpiCsGpio/SpiCsGpioPortSelection')))"!][!//
[!VAR "PinValue" ="node:value(node:ref(concat($tmpVar, '/SpiCsGpio/SpiCsGpioPinSelection')))"!][!//
    (uint16)Spi_CsGpioPortPin([!"num:i($PortValue)"!]U, [!"num:i($PinValue)"!]U), /* Gpio CS Port/Pin  */
[!ENDIF!][!//
[!ELSE!][!/* SpiEnableCs */!][!//
    SPI_CS_NONE, /* No CS Pin is Selected */
[!ENDIF!][!//

    /*CS Active level Polarity*/
[!IF "node:value(node:ref(concat($tmpVar, '/SpiCsPolarity'))) = $LowName"!][!//
    SPI_CS_POLARITY_LOW,
[!ELSE!][!//
    SPI_CS_POLARITY_HIGH,
[!ENDIF!][!//

 /* Shift Clock Configuration : Clock Idle Polarity: SPI_SHIFT_CLOCK_IDLE_LEVEL,
                                  Clock Phase: SPI_DATA_SHIFT_EDGE */
    Spi_ShiftClkConfig([!//
[!IF "node:value(node:ref(concat($tmpVar, '/SpiShiftClockIdleLevel'))) = $LowName "!][!//
SPI_CLK_IDLE_LOW,
[!ELSE!][!//
SPI_CLK_IDLE_HIGH,
[!ENDIF!][!//
[!IF "node:value(node:ref(concat($tmpVar, '/SpiDataShiftEdge'))) = $LeadingName "!][!//
                      SPI_DATA_SHIFT_LEAD),
[!ELSE!][!//
                      SPI_DATA_SHIFT_TRAIL),
[!ENDIF!][!//
[!NOCODE!][!//
[!VAR "CurJobName" = "node:name(.)"!][!//
[!IF "$SpiIntSeqAllowed = 'true'"!][!//
[!VAR "EscalatePriority" = "'0'"!][!//
[!LOOP "node:ref($Spi2StepSequence)/*"!][!//
[!VAR "SeqInt" ="'false'"!][!//
[!IF "node:exists(SpiInterruptibleSequence)"!][!//
[!VAR "SeqInt" = "./SpiInterruptibleSequence"!][!//
[!ENDIF!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(node:ref($SpiJobAssignmentName)/*)) - num:i(1)"!][!//
    [!VAR "ChanSel" = "concat($SpiJobAssignmentName,'/*[',$Index1 + 1,']')"!][!//
    [!VAR "RefChanSel" = "node:ref($ChanSel)"!][!//
    [!ASSERT "string-length($RefChanSel) != 0"!][!//
    Config Error: Job assignment reference not provided for [!"node:name(.)"!] , index [!"$Index1"!]
    [!ENDASSERT!][!//
    [!VAR "path" ="node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!][!//
    [!IF "$path = $CurJobName"!]
    [!IF "$SeqInt = 'false'"!][!//
    [!VAR "EscalatePriority" = "'1'"!][!//
    [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!][!//
[!ELSE!][!//
[!VAR "EscalatePriority" = "'1'"!][!//
[!ENDIF!][!//
[!IF "SpiGeneral/SpiLevelDelivered = 0"!][!//
[!VAR "EscalatePriority" = "'0'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "$EscalatePriority = '0'"!][!//
   /* Job Priority : SPI_JOB_PRIORITY, SPI002,SPI093 */
    SPI_JOB_PRIORITY_[!"num:i(./SpiJobPriority)"!],
[!ELSE!][!//
   /* Job Priority escalated to Maximum as it is mapped
      to one or more non-interruptible sequence */
    SPI_JOB_PRIORITY_3,
[!ENDIF!][!//

[!VAR "cur_hw" = "node:value(node:ref(concat($tmpVar, '/SpiHwUnit/SpiAssignedHwModule')))"!][!//
[!VAR "cur_ch" = "node:value(node:ref(concat($tmpVar, '/SpiHwUnit/SpiAssignedHwChannel')))"!][!//
    /* Spi HW Unit. bit[7:4]: Channel no, bit[3:0]: hw module no */
      (uint8)((uint8)SPI_QSPI_[!"text:toupper($cur_ch)"!] << 4U) | (SPI_[!"$cur_hw"!]_INDEX),

    /* Channel Based Chip Select */
    [!IF "./SpiChannelBasedCS = 'Disabled'"!][!//
    (uint8)0U,
    [!ELSE!][!//
    (uint8)1U,
    [!ENDIF!][!//

    /* Spi Parity Selection */
    [!IF "$ParitySupportVal = 'Unused'"!][!//
    (uint8)SPI_QSPI_PARITY_UNUSED,
    [!ELSEIF "$ParitySupportVal = 'Even'"!][!//
    (uint8)SPI_QSPI_PARITY_EVEN,
    [!ELSEIF "$ParitySupportVal = 'Odd'"!][!//
    (uint8)SPI_QSPI_PARITY_ODD,
    [!ENDIF!][!//

[!IF "not(node:islast())"!][!//
  },
[!ELSE!][!//
  }
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
};
[!ENDFOR!][!//
[!ENDSELECT!][!//

/*
                     Container: Spi_SequenceConfiguration
*/
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SeqPosition" = "num:i(0)"!][!//
[!VAR "SpiSeqEndNotify" = "'NULL_PTR'"!][!//
[!IF "node:exists(SpiGeneral/SpiSupportConcurrentSyncTransmit)"!][!//
[!VAR "SpiMultiSyncSeqAllowed" = "SpiGeneral/SpiSupportConcurrentSyncTransmit"!][!//
[!ELSE!][!//
[!VAR "SpiMultiSyncSeqAllowed" = "'false'"!][!//
[!ENDIF!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
[!IF "node:exists(./SpiSeqEndNotification)"!][!//
[!VAR "SpiSeqEndNotify" = "./SpiSeqEndNotification"!][!//
[!ENDIF!][!//
[!IF "$SpiSeqEndNotify = 'NULL_PTR'"!][!//
/* Notification Function of Sequence: [!"node:name(.)"!] is NULL_PTR */
[!ELSE!][!//
/* Notification Function of Sequence: [!"node:name(.)"!] */
extern void [!"$SpiSeqEndNotify"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!AUTOSPACING!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!IF "$SpiLevel = num:i(0)"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "JobsinSeq" = "num:i(0)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: [!"node:name(.)"!] */
static const Spi_JobType [!"node:name(.)"!]_JobLinkPtr[] =
{
[!FOR "Index1" = "num:i(0)" TO "num:i(count(node:ref($SpiJobAssignmentName)/*)) - num:i(1)"!][!//
[!VAR "ChanSel" = "concat($SpiJobAssignmentName, '/*[',$Index1 + 1,']')"!][!//
[!VAR "RefChanSel" = "node:ref($ChanSel)"!][!//
  [!ASSERT "string-length($RefChanSel) != 0"!][!//
  Config Error: Job assignment reference not provided for [!"node:name(.)"!] , index [!"$Index1"!]
  [!ENDASSERT!][!//
  [!VAR "path" ="node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!][!//
  SpiConf_SpiJob_[!"$path"!],
[!ENDFOR!][!//
  SPI_JOB_LINK_DELIMITER
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!//
[!IF "$SpiLevel = 1"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "JobsinSeq" = "num:i(0)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: [!"node:name(.)"!] */
static const Spi_JobType [!"node:name(.)"!]_JobLinkPtr[] =
{
[!FOR "prio_current" = "num:i(3)" TO "num:i(0)" STEP "num:i(-1)"!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(node:ref($SpiJobAssignmentName)/*)) - num:i(1)"!][!//
[!VAR "ChanSel" = "concat($SpiJobAssignmentName,'/*[',$Index1 + 1,']')"!][!//
[!VAR "RefChanSel" = "node:ref($ChanSel)"!][!//
  [!ASSERT "string-length($RefChanSel) != 0"!][!//
  Config Error: Job assignment reference not provided for [!"node:name(.)"!] , index [!"$Index1"!]
  [!ENDASSERT!][!//
    [!IF "$SpiAsyncPllelTransmit = 'true'"!][!//
      [!VAR "JobCSTrigTypeRef" = "(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1])/SpiDeviceAssignment)"!][!//
      [!IF "$Index1 = num:i(0)"!][!//
        [!VAR "FirstJobQspiNode" = "(node:ref($JobCSTrigTypeRef))/SpiHwUnit/SpiAssignedHwModule"!][!//
      [!ELSE!][!//
        [!VAR "NonFirstJobQspiNode" = "(node:ref($JobCSTrigTypeRef))/SpiHwUnit/SpiAssignedHwModule"!][!//
        [!IF "$FirstJobQspiNode != $NonFirstJobQspiNode"!][!//
          [!ERROR!]
        Config Error: QSPI node of Job:[!"node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!] is configured as [!"$NonFirstJobQspiNode"!].
Since SpiAsyncParallelTransmit=ON all Jobs must belong to same QSPI module.
          [!ENDERROR!]
        [!ENDIF!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
  [!IF "num:i(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1])/SpiJobPriority) = num:i($prio_current)"!][!//
  [!VAR "path" ="node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!][!//
  SpiConf_SpiJob_[!"$path"!],
  [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
  SPI_JOB_LINK_DELIMITER
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!//
[!IF "$SpiLevel = 2"!]
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous = 'Asynchronous'"!][!//
[!VAR "JobsinSeq" = "num:i(0)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
/*
Configuration: Job Assignment
*/
/* Job Assignment of Sequence: [!"node:name(.)"!] */
static const Spi_JobType [!"node:name(.)"!]_JobLinkPtr[] =
{
[!FOR "prio_current" = "num:i(3)" TO "num:i(0)" STEP "num:i(-1)"!][!//
[!FOR "Index1" = "num:i(0)" TO "num:i(count(node:ref($SpiJobAssignmentName)/*)) - num:i(1)"!][!//
[!VAR "ChanSel" = "concat($SpiJobAssignmentName,'/*[',$Index1 + 1,']')"!][!//
[!VAR "RefChanSel" = "node:ref($ChanSel)"!][!//
  [!ASSERT "string-length($RefChanSel) != 0"!][!//
  Config Error: Job assignment reference not provided for [!"node:name(.)"!] , index [!"$Index1"!]
  [!ENDASSERT!][!//
    [!IF "$SpiAsyncPllelTransmit = 'true'"!][!//
      [!VAR "JobCSTrigTypeRef" = "(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1])/SpiDeviceAssignment)"!][!//
      [!IF "$Index1 = num:i(0)"!][!//
        [!VAR "FirstJobQspiNode" = "(node:ref($JobCSTrigTypeRef))/SpiHwUnit/SpiAssignedHwModule"!][!//
      [!ELSE!][!//
        [!VAR "NonFirstJobQspiNode" = "(node:ref($JobCSTrigTypeRef))/SpiHwUnit/SpiAssignedHwModule"!][!//
        [!IF "$FirstJobQspiNode != $NonFirstJobQspiNode"!][!//
          [!ERROR!]
        Config Error: QSPI node of Job:[!"node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!] is configured as [!"$NonFirstJobQspiNode"!].
Since SpiAsyncParallelTransmit=ON all Jobs must belong to same QSPI module.
          [!ENDERROR!]
        [!ENDIF!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
  [!IF "num:i(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1])/SpiJobPriority) = num:i($prio_current)"!][!//
  [!VAR "path" ="node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!][!//
  SpiConf_SpiJob_[!"$path"!],
  [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
  SPI_JOB_LINK_DELIMITER
};
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous != 'Asynchronous'"!][!//
[!VAR "JobsinSeq" = "num:i(0)"!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
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
/* Job Assignment of Sequence: [!"node:name(.)"!] */
static const Spi_JobType [!"node:name(.)"!]_JobLinkPtr[] =
{
[!FOR "Index1" = "num:i(0)" TO "num:i(count(node:ref($SpiJobAssignmentName)/*)) - num:i(1)"!][!//
[!VAR "ChanSel" = "concat($SpiJobAssignmentName,'/*[',$Index1 + 1,']')"!][!//
[!VAR "RefChanSel" = "node:ref($ChanSel)"!][!//
  [!ASSERT "string-length($RefChanSel) != 0"!][!//
  Config Error: Job assignment reference not provided for [!"node:name(.)"!] , index [!"$Index1"!]
  [!ENDASSERT!][!//
  [!VAR "path" ="node:name(node:ref(node:ref($SpiJobAssignmentName)/*[@index = $Index1]))"!][!//
  SpiConf_SpiJob_[!"$path"!],
[!ENDFOR!][!//
  SPI_JOB_LINK_DELIMITER
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!AUTOSPACING!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!VAR "SpiIntSeq" = "'false'"!][!//
[!IF "node:exists(./SpiGeneral/SpiInterruptibleSeqAllowed)"!][!//
[!VAR "SpiIntSeq" = "./SpiGeneral/SpiInterruptibleSeqAllowed"!][!//
[!ENDIF!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!//
[!IF "$SafetyEnable = 'true'"!][!//
[!VAR "SpiSlaveModule" = "./SpiGeneral/SpiSlaveSelectRef"!][!//
[!ELSE!][!//
[!VAR "SpiSlaveModule" = "'SPI_SLAVE_UNUSED'"!][!//
[!ENDIF!][!//
[!IF "$SpiLevel = 1 or $SpiLevel = 2 or $SpiSlaveModule != 'SPI_SLAVE_UNUSED'"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!VAR "MaxSeq" = "num:i(count(node:ref($SpiSequenceName)/*))"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SequenceName" = "node:name(.)"!][!//
[!VAR "SkipSeqName" = "'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "ModuleId2" ="num:i(1)" TO "num:i($Index)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($ModuleId2 - 1)]"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!VAR "SymbolicName_ref" = "node:name(.)"!][!//
[!IF "contains($SymbolicName_ref , $SequenceName) = 'true'"!][!//
[!VAR "SkipSeqName" = "'true'"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!//
[!IF "$SkipSeqName = 'false'"!][!//
[!VAR "AccessSeq" = "''"!][!//
[!VAR "IsSeqShared" = "'0'"!][!//
[!CALL "CG_GetSequenceSharingJobs", "SeqName" = "$SequenceName"!][!//
[!IF "$IsSeqShared = '1'"!][!//
[!VAR "SEQSHARE_0" = "0"!][!//
[!VAR "SEQSHARE_1" = "0"!][!//
[!VAR "SEQSHARE_2" = "0"!][!//
[!VAR "SEQSHARE_3" = "0"!][!//
[!VAR "SEQSHARE_4" = "0"!][!//
[!VAR "SEQSHARE_5" = "0"!][!//
[!VAR "SEQSHARE_6" = "0"!][!//
[!VAR "SEQSHARE_7" = "0"!][!//
[!CALL "CG_SetSequenceSharing", "SeqName" = "$SequenceName"!][!//
/* Printing of shared sequence */
static const Spi_SequenceType [!"$SequenceName"!]_SharedSeqsPtr[] = {
[!FOR "Cntr" = "0" TO "$MaxSeq"!][!//
[!IF "$Cntr < 32"!][!//
[!IF "bit:getbit($SEQSHARE_0,num:i($Cntr)) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 64"!][!//
[!IF "bit:getbit($SEQSHARE_1,num:i($Cntr) - 32) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 96"!][!//
[!IF "bit:getbit($SEQSHARE_2,num:i($Cntr) - 64) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 128"!][!//
[!IF "bit:getbit($SEQSHARE_3,num:i($Cntr) - 96) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 160"!][!//
[!IF "bit:getbit($SEQSHARE_4,num:i($Cntr) - 128) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 192"!][!//
[!IF "bit:getbit($SEQSHARE_5,num:i($Cntr) - 160) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 224"!][!//
[!IF "bit:getbit($SEQSHARE_6,num:i($Cntr) - 192) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ELSEIF "$Cntr < 256"!][!//
[!IF "bit:getbit($SEQSHARE_7,num:i($Cntr) - 224) = 1"!][!//
  SpiConf_SpiSequence_[!"node:name(../*[@index=$Cntr])"!],
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
  SPI_SHARED_JOBS_DELIMITER
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!AUTOSPACING!][!//
[!NOCODE!][!//
[!/*MIXED Sync and Async Jobs in a seq is not allowed.*/!][!//
[!IF "$SpiLevel = 2"!][!//
[!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!FOR "SeqIndex" = "num:i(0)" TO "num:i(count(node:ref($SpiSequenceName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiSequenceName)/*[@index =$SeqIndex]"!][!//
[!VAR "CurSeqName" ="node:name(.)"!][!//
[!VAR "CurSeqType" = "'UNDEF'"!][!//
[!LOOP "node:ref($SpiJobAssignmentName)/*"!][!//
[!VAR "CurJobName" ="node:name(node:ref(.))"!][!//
[!IF "node:ref(.)/SpiHwUnitSynchronous = 'Asynchronous'"!][!//
[!IF "$CurSeqType != 'SYNC_BUS'"!][!//
[!VAR "CurSeqType" = "'ASYNC_BUS'"!][!//
[!ELSE!][!//
[!ERROR!][!//
Config Error: [!"$CurSeqName"!] Sequence has both Synchronous Bus and Asynchronous Bus Jobs
[!ENDERROR!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "$CurSeqType != 'ASYNC_BUS'"!][!//
[!VAR "CurSeqType" = "'SYNC_BUS'"!][!//
[!ELSE!][!//
[!ERROR!][!//
  Config Error: [!"$CurSeqName"!] Sequence has both Synchronous Bus and Asynchronous Bus Jobs
[!ENDERROR!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!/* END node:ref($SpiJobAssignmentName).*/!][!//
[!ENDLOOP!][!//
[!/* END SELECT "node:ref($SpiSequenceName)/*[@index =$SeqIndex.*/!][!//
[!ENDSELECT!][!//
[!/* END FOR "SeqIndex" = "num:i(0)" TO "num:i(count(node:ref($SpiSequenceName)*/!][!//
[!ENDFOR!][!//
[!/* END node:ref($SpiDriverName*/!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!//
[!ENDNOCODE!][!//
/*
Configuration: Sequence Configuration Constant Structure.
*/
[!AUTOSPACING!][!//
static const Spi_SequenceConfigType Spi_kSequenceConfig[!"string(($Index))"!][] =
{ [!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!IF "$SpiLevel = 0 or $SpiLevel = 1"!][!//
  [!LOOP "node:ref($SpiSequenceName)/*"!][!//
  /* Sequence: [!"node:name(.)"!] Configuration */
  {
  [!IF "$SpiLevel = 1"!][!//
    /* Spi_SeqEndNotification */
  [!VAR "SymbolicName" = "./SpiSeqEndNotification"!][!//
  [!IF "$SymbolicName != 'NULL_PTR'"!][!//
  [!IF "$PostBuildType != 'SELECTABLE'"!][!//
  [!ASSERT "(num:isnumber($SymbolicName)= 'true') or ($SymbolicName = 'NULL_PTR')"!][!//
  ERROR: Under LOADABLE option Spi_SeqEndNotification should be entered as a Address. Change notification of [!"node:name(.)"!][!//
  [!ENDASSERT!][!//
  [!VAR "SymbolicName" = "concat('(Spi_NotifFunctionPtrType)',$SymbolicName,'U')"!][!//
  [!ELSE!][!//
  [!ASSERT "(num:isnumber($SymbolicName)!= 'true') or ($SymbolicName = 'NULL_PTR')"!][!//
  ERROR: Under SELECTABLE option Spi_SeqEndNotification should be entered as a function name. Change notification of [!"node:name(.)"!][!//
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "($SymbolicName != 'NULL_PTR') and  ($PostBuildType = 'SELECTABLE')"!][!//
    &[!"$SymbolicName"!],
  [!ELSE!][!//
    [!"$SymbolicName"!],
  [!ENDIF!][!//
  [!ENDIF!][!//
    /* User given name outside the naming convention */[!//
    /* Spi_JobLinkPtr */
    [!"node:name(.)"!]_JobLinkPtr,
  [!IF "$SpiLevel = 1 or $SpiSlaveModule != 'SPI_SLAVE_UNUSED'"!][!//
    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */[!//
  [!VAR "SequenceName" = "node:name(.)"!][!//
  [!VAR "IsSeqShared" = "'0'"!][!//
  [!CALL "CG_GetSequenceSharingJobs", "SeqName" = "$SequenceName"!][!//
  [!IF "$IsSeqShared = '1'"!][!//
    [!"$SequenceName"!]_SharedSeqsPtr,
  [!ELSE!][!//
    NULL_PTR,
  [!ENDIF!][!//
  [!ENDIF!][!//
     /* This holds the total number of jobs linked to this sequence */
    [!"num:i(count(node:ref($SpiJobAssignmentName)/*))"!]U,
  [!IF "$SpiIntSeq = 'true'"!][!//
  [!IF "./SpiInterruptibleSequence = 'true'"!][!//
    /* Sequence Interruptible or Not (SPI125, SPI126) */
    SPI_SEQ_INT_TRUE [!//
  [!ELSE!][!//
    /* Sequence Interruptible or Not (SPI125, SPI126) */
    SPI_SEQ_INT_FALSE [!//
  [!ENDIF!][!//
  [!IF "$SpiLevel = 0 and $SpiMultiSyncSeqAllowed = 'true'"!][!//
  ,
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "$SpiLevel = 0 and $SpiMultiSyncSeqAllowed = 'true'"!][!//
    /* Holds the Hw modules used by the sequence  */ [!//
  [!CALL "CG_SetHwForSeq"!][!//
    (uint8)[!"$SeqHwUnits"!]U
  [!ENDIF!][!//
  [!IF "not(node:islast())"!][!//
  },
  [!ELSE!][!//
  }
  [!ENDIF!][!//
  [!ENDLOOP!][!//
[!//
[!ELSE!][!/* Level Delivered = 2 */!][!//
[!//
[!/* First List the Sync Sequences.*/!][!//
  [!LOOP "node:ref($SpiSequenceName)/*"!][!//
  [!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous != 'Asynchronous'"!][!//
  /* Sequence: [!"node:name(.)"!] Configuration */
  {
    /* Spi_SeqEndNotification */
  [!VAR "SymbolicName" = "./SpiSeqEndNotification"!][!//
  [!IF "$SymbolicName != 'NULL_PTR'"!][!//
  [!IF "$PostBuildType != 'SELECTABLE'"!][!//
  [!ASSERT "(num:isnumber($SymbolicName)= 'true') or ($SymbolicName = 'NULL_PTR')"!][!//
  ERROR: Under LOADABLE option Spi_SeqEndNotification should be entered as a Address. Change notification of [!"node:name(.)"!][!//
  [!ENDASSERT!][!//
  [!VAR "SymbolicName" = "concat('(Spi_NotifFunctionPtrType)',$SymbolicName,'U')"!][!//
  [!ELSE!][!//
  [!ASSERT "(num:isnumber($SymbolicName)!= 'true') or ($SymbolicName = 'NULL_PTR')"!][!//
  ERROR: Under SELECTABLE option Spi_SeqEndNotification should be entered as a function name. Change notification of [!"node:name(.)"!][!//
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "($SymbolicName != 'NULL_PTR') and  ($PostBuildType = 'SELECTABLE')"!][!//
    &[!"$SymbolicName"!],
  [!ELSE!][!//
    [!"$SymbolicName"!],
  [!ENDIF!][!//

    /* User given name outside the naming convention */[!//
    /* Spi_JobLinkPtr */
    [!"node:name(.)"!]_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */[!//
  [!VAR "SequenceName" = "node:name(.)"!][!//
  [!VAR "IsSeqShared" = "'0'"!][!//
  [!CALL "CG_GetSequenceSharingJobs", "SeqName" = "$SequenceName"!][!//
  [!IF "$IsSeqShared = '1'"!][!//
    [!"$SequenceName"!]_SharedSeqsPtr,
  [!ELSE!][!//
    NULL_PTR,
  [!ENDIF!][!//
    /* This holds the total number of jobs linked to this sequence */
    [!"num:i(count(node:ref($SpiJobAssignmentName)/*))"!]U,
  [!IF "$SpiIntSeq = 'true'"!][!//
  [!IF "./SpiInterruptibleSequence = 'true'"!][!//
    /* Sequence Interruptible or Not (SPI125, SPI126) */
    SPI_SEQ_INT_TRUE, [!//
  [!ELSE!][!//
    /* Sequence Interruptible or Not (SPI125, SPI126) */
    SPI_SEQ_INT_FALSE, [!//
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "$SpiMultiSyncSeqAllowed = 'true'"!][!//
  /* Holds the Hw modules used by the sequence  */[!//
  [!CALL "CG_SetHwForSeq"!][!//
    (uint8)[!"$SeqHwUnits"!]U
  [!ENDIF!][!//
  },
  [!ENDIF!][!//* Sync Job Check */!]
  [!ENDLOOP!][!//
  [!//
  [!/* Async Sequences Listing.*/!]
  [!LOOP "node:ref($SpiSequenceName)/*"!][!//
  [!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous = 'Asynchronous'"!][!//
  /* Sequence: [!"node:name(.)"!] Configuration */
  {
    /* Spi_SeqEndNotification */
  [!VAR "SymbolicName" = "./SpiSeqEndNotification"!][!//
  [!IF "$SymbolicName != 'NULL_PTR'"!][!//
  [!IF "$PostBuildType != 'SELECTABLE'"!][!//
  [!ASSERT "(num:isnumber($SymbolicName)= 'true') or ($SymbolicName = 'NULL_PTR')"!]
  ERROR: Under LOADABLE option Spi_SeqEndNotification should be entered as a Address. Change notification of [!"node:name(.)"!]
  [!ENDASSERT!][!//
  [!VAR "SymbolicName" = "concat('(Spi_NotifFunctionPtrType)',$SymbolicName,'U')"!][!//
  [!ELSE!][!//
  [!ASSERT "(num:isnumber($SymbolicName)!= 'true') or ($SymbolicName = 'NULL_PTR')"!]
  ERROR: Under SELECTABLE option Spi_SeqEndNotification should be entered as a function name. Change notification of [!"node:name(.)"!]
  [!ENDASSERT!][!//
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "($SymbolicName != 'NULL_PTR') and  ($PostBuildType = 'SELECTABLE')"!][!//
    &[!"$SymbolicName"!],
  [!ELSE!][!//
    [!"$SymbolicName"!],
  [!ENDIF!][!//

    /* User given name outside the naming convention */[!//
    /* Spi_JobLinkPtr */
    [!"node:name(.)"!]_JobLinkPtr,

    /* User given name outside the naming convention */
    /* Sequences that share jobs with this sequence */[!//
  [!VAR "SequenceName" = "node:name(.)"!][!//
  [!VAR "IsSeqShared" = "'0'"!][!//
  [!CALL "CG_GetSequenceSharingJobs", "SeqName" = "$SequenceName"!][!//
  [!IF "$IsSeqShared = '1'"!][!//
    [!"$SequenceName"!]_SharedSeqsPtr,
  [!ELSE!][!//
    NULL_PTR,
  [!ENDIF!][!//
     /* This holds the total number of jobs linked to this sequence */
    [!"num:i(count(node:ref($SpiJobAssignmentName)/*))"!]U,
  [!IF "$SpiIntSeq = 'true'"!][!//
  [!IF "./SpiInterruptibleSequence = 'true'"!][!//
    /* Sequence Interruptible or Not (SPI125, SPI126) */
    SPI_SEQ_INT_TRUE, [!//
  [!ELSE!][!//
    /* Sequence Interruptible or Not (SPI125, SPI126) */
    SPI_SEQ_INT_FALSE, [!//
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "$SpiMultiSyncSeqAllowed = 'true'"!][!//
  /* Holds the Hw modules used by the sequence.
    For ASync Sequences in SpiLevelDeliverd 2, it's not applicable  */
  (uint8)0U
  [!ENDIF!][!//
  [!IF "not(node:islast())"!][!//
  },
  [!ELSE!][!//
  }
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!ENDLOOP!][!//
[!//
[!ENDIF!][!/* Level Delivered = 2 */!]
[!ENDSELECT!][!//
};
[!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!AUTOSPACING!][!//

[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiLevel" = "./SpiGeneral/SpiLevelDelivered"!][!//
[!IF "$SafetyEnable = 'true'"!][!//
[!VAR "SpiSlaveModule" = "./SpiGeneral/SpiSlaveSelectRef"!][!//
[!ELSE!][!//
[!VAR "SpiSlaveModule" = "'SPI_SLAVE_UNUSED'"!][!//
[!ENDIF!][!//
[!IF "$SpiLevel = 2 or $SpiLevel = 1 or $SpiSlaveModule != 'SPI_SLAVE_UNUSED'"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
static const Spi_DmaConfigType Spi_kDmaConfig[!"string(($Index))"!][]=
{
 [!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!VAR "McuDmaRef" = "node:path(node:ref(./SpiSystemClock)/../../../DmaConfiguration)"!][!//
[!ENDSELECT!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi0)"!][!//
[!CALL "Compare_DmaChannels", "SpiDmaRef" = "'SpiHwConfiguration/SpiHwConfigurationQspi0'", "McuDmaRef2" = "$McuDmaRef"!][!//
  { /* QSPI0 Module Hw Dma Config */
    [!"$SpiDmaChTX"!],  /* Tx */[!//
    [!"$SpiDmaChRX"!]   /* Rx */[!//
  },
[!ELSEIF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//  
  { /*QSPI0 Module Dummy in TC298*/
    DMA_CHANNEL_INVALID,  /* Tx */    DMA_CHANNEL_INVALID   /* Rx */  },
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi1)"!][!//
[!CALL "Compare_DmaChannels", "SpiDmaRef" = "'SpiHwConfiguration/SpiHwConfigurationQspi1'", "McuDmaRef2" = "$McuDmaRef"!][!//
  { /* QSPI1 Module Hw Dma Config */
    [!"$SpiDmaChTX"!],  /* Tx */[!//
    [!"$SpiDmaChRX"!]   /* Rx */[!//
  },
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi2)"!][!//
[!CALL "Compare_DmaChannels", "SpiDmaRef" = "'SpiHwConfiguration/SpiHwConfigurationQspi2'", "McuDmaRef2" = "$McuDmaRef"!][!//
  { /* QSPI2 Module Hw Dma Config */
    [!"$SpiDmaChTX"!],  /* Tx */[!//
    [!"$SpiDmaChRX"!]   /* Rx */[!//
  },
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi3)"!][!//
[!CALL "Compare_DmaChannels", "SpiDmaRef" = "'SpiHwConfiguration/SpiHwConfigurationQspi3'", "McuDmaRef2" = "$McuDmaRef"!][!//
  { /* QSPI3 Module Hw Dma Config */
    [!"$SpiDmaChTX"!],  /* Tx */[!//
    [!"$SpiDmaChRX"!]   /* Rx */[!//
  },
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//
[!CALL "Compare_DmaChannels", "SpiDmaRef" = "'SpiHwConfiguration/SpiHwConfigurationQspi4'", "McuDmaRef2" = "$McuDmaRef"!][!//
  { /* QSPI4 Module Hw Dma Config */
    [!"$SpiDmaChTX"!],  /* Tx */[!//
    [!"$SpiDmaChRX"!]   /* Rx */[!//
  },
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi5)"!][!//
[!CALL "Compare_DmaChannels", "SpiDmaRef" = "'SpiHwConfiguration/SpiHwConfigurationQspi5'", "McuDmaRef2" = "$McuDmaRef"!][!//
  { /* QSPI5 Module Hw Dma Config */
    [!"$SpiDmaChTX"!],  /* Tx */[!//
    [!"$SpiDmaChRX"!]   /* Rx */[!//
  },
[!ENDIF!][!//
[!//[!ENDSELECT!][!//
};
[!ENDFOR!][!//
[!ENDIF!][!//

[!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
static const Spi_HWModuleConfigType Spi_kModuleConfig[!"string(($Index))"!][]=
{
  [!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
  [!IF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi0)"!][!//
  [!IF "num:i(count(node:ref($SpiJobName)/*[node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule='QSPI0']) )>0"!][!//
  /* QSPI0 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi0/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      SPI_QSPI0_MRIS_SEL,
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
      &Spi_kDmaConfig[!"string(($Index))"!][0U],
[!ELSE!][!//
      NULL_PTR,
[!ENDIF!][!//
  },
  [!ELSEIF "../../SpiGeneral/SpiSlaveSelectRef = 'QSPI0'"!][!//
  /* QSPI0 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi0/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      (uint32)((uint32)((uint32)SPI_SLAVE_SRIS_SEL << 4U) | 
               ((uint32)SPI_SLAVE_SCIS_SEL << 8U)),
      &Spi_kDmaConfig[!"string(($Index))"!][0U],
  },
  [!ELSE!][!//
  /* QSPI0 Module */
  {
    SPI_0_NOT_CONFIGURED,
    SPI_0_NOT_CONFIGURED,
    NULL_PTR,
  },
  [!ENDIF!][!//
  [!ELSEIF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//  
  /*QSPI0 Module Dummy in TC298*/
  {
      SPI_0_NOT_CONFIGURED,
      SPI_0_NOT_CONFIGURED,
      NULL_PTR,
  },
  [!ENDIF!][!//
  [!IF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi1)"!][!//
  [!IF "num:i(count(node:ref($SpiJobName)/*[node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule='QSPI1']) )>0"!][!//
  /* QSPI1 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi1/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      SPI_QSPI1_MRIS_SEL,
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
      &Spi_kDmaConfig[!"string(($Index))"!][1U],
[!ELSE!][!//
      NULL_PTR,
[!ENDIF!][!//
  },
  [!ELSEIF "../../SpiGeneral/SpiSlaveSelectRef = 'QSPI1'"!][!//
  /* QSPI1 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi1/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      (uint32)((uint32)((uint32)SPI_SLAVE_SRIS_SEL << 4U) | 
               ((uint32)SPI_SLAVE_SCIS_SEL << 8U)),
      &Spi_kDmaConfig[!"string(($Index))"!][1U],
  },
  [!ELSE!][!//
  /* QSPI1 Module */
  {
    SPI_1_NOT_CONFIGURED,
    SPI_1_NOT_CONFIGURED,
    NULL_PTR,
  },
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi2)"!][!//
  [!IF "num:i(count(node:ref($SpiJobName)/*[node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule='QSPI2']) )>0"!][!//
  /* QSPI2 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi2/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      SPI_QSPI2_MRIS_SEL,
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
      &Spi_kDmaConfig[!"string(($Index))"!][2U],
[!ELSE!][!//
      NULL_PTR,
[!ENDIF!][!//
  },
  [!ELSEIF "../../SpiGeneral/SpiSlaveSelectRef = 'QSPI2'"!][!//
  /* QSPI2 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi2/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      (uint32)((uint32)((uint32)SPI_SLAVE_SRIS_SEL << 4U) | 
               ((uint32)SPI_SLAVE_SCIS_SEL << 8U)),
      &Spi_kDmaConfig[!"string(($Index))"!][2U],
  },
  [!ELSE!][!//
  /* QSPI2 Module */
  {
    SPI_2_NOT_CONFIGURED,
    SPI_2_NOT_CONFIGURED,
    NULL_PTR,
  },
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi3)"!][!//
  [!IF "num:i(count(node:ref($SpiJobName)/*[node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule='QSPI3']) )>0"!][!//
  /* QSPI3 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi3/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      SPI_QSPI3_MRIS_SEL,
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
      &Spi_kDmaConfig[!"string(($Index))"!][3U],
[!ELSE!][!//
      NULL_PTR,
[!ENDIF!][!//
  },
  [!ELSEIF "../../SpiGeneral/SpiSlaveSelectRef = 'QSPI3'"!][!//
  /* QSPI3 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi3/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      (uint32)((uint32)((uint32)SPI_SLAVE_SRIS_SEL << 4U) | 
               ((uint32)SPI_SLAVE_SCIS_SEL << 8U)),
      &Spi_kDmaConfig[!"string(($Index))"!][3U],
  },
  [!ELSE!][!//
  /* QSPI3 Module */
  {
    SPI_3_NOT_CONFIGURED,
    SPI_3_NOT_CONFIGURED,
    NULL_PTR,
  },
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//
  [!IF "num:i(count(node:ref($SpiJobName)/*[node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule='QSPI4']) )>0"!][!//
  /* QSPI4 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi4/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      SPI_QSPI4_MRIS_SEL,
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
      &Spi_kDmaConfig[!"string(($Index))"!][4U],
[!ELSE!][!//
      NULL_PTR,
[!ENDIF!][!//
  },
  [!ELSEIF "../../SpiGeneral/SpiSlaveSelectRef = 'QSPI4'"!][!//
  /* QSPI4 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi4/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      (uint32)((uint32)((uint32)SPI_SLAVE_SRIS_SEL << 4U) | 
               ((uint32)SPI_SLAVE_SCIS_SEL << 8U)),
      &Spi_kDmaConfig[!"string(($Index))"!][4U],
  },
  [!ELSE!][!//
  /* QSPI4 Module */
  {
    SPI_4_NOT_CONFIGURED,
    SPI_4_NOT_CONFIGURED,
    NULL_PTR,
  },
  [!ENDIF!][!//
  [!ENDIF!][!//
  [!IF "node:exists(../../SpiHwConfiguration/SpiHwConfigurationQspi5)"!][!//
  [!IF "num:i(count(node:ref($SpiJobName)/*[node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule='QSPI5']) )>0"!][!//
  /* QSPI5 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi5/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      SPI_QSPI5_MRIS_SEL,
[!IF "$SpiLevel = 2 or $SpiLevel = 1"!][!//
      &Spi_kDmaConfig[!"string(($Index))"!][5U],
[!ELSE!][!//
      NULL_PTR,
[!ENDIF!][!//
  },
[!ELSEIF "../../SpiGeneral/SpiSlaveSelectRef = 'QSPI5'"!][!//
  /* QSPI5 Module */
  {
      /*Clock Settings:Sleep Control Disabled*/
      [!IF "../../SpiHwConfiguration/SpiHwConfigurationQspi5/SpiClockConfiguration/SpiSleepEnable = 'true'"!][!//
      SPI_CLK_SLEEP_ENABLE,
      [!ELSE!][!//
      SPI_CLK_SLEEP_DISABLE,
      [!ENDIF!][!//
[!//
      (uint32)((uint32)((uint32)SPI_SLAVE_SRIS_SEL << 4U) | 
               ((uint32)SPI_SLAVE_SCIS_SEL << 8U)),
      &Spi_kDmaConfig[!"string(($Index))"!][5U],
  },
  [!ELSE!][!//
  /* QSPI5 Module */
  {
    SPI_5_NOT_CONFIGURED,
    SPI_5_NOT_CONFIGURED,
    NULL_PTR,
  },
  [!ENDIF!][!//
  [!ENDIF!][!//
[!ENDSELECT!][!//
};
[!ENDFOR!][!//
[!IF "$SpiLevel = 2"!][!//
[!//Level 2 related Asserts
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!VAR "AsyncJobPresent" = "'FALSE'"!][!//
[!IF "num:i(count(node:ref($SpiJobName)/*[SpiHwUnitSynchronous='Asynchronous']) )>0"!][!//
[!IF "$AsyncJobPresent = 'FALSE'"!][!//
[!VAR "AsyncJobPresent" = "'TRUE'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ASSERT "$AsyncJobPresent" = "'TRUE'"!][!//
Config Error: Level2 driver configuration is used. But no Jobs are configured on the Async Bus.
[!ENDASSERT!][!//
[!ENDIF!][!/* [!IF $SpiLevel = 2 */!][!//
[!ENDSELECT!][!//

[!IF "$SafetyEnable = 'true'"!][!//
[!VAR "SpiSafetyMasterQSPI" = "node:value(./SpiGeneral/SpiSafetyMasterRef)"!][!//
[!VAR "SpiSafetySlaveQSPI" = "node:value(./SpiGeneral/SpiSlaveSelectRef)"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
static const Spi_MapConfigType Spi_kMapConfig[!"string(($Index))"!][]=
{
  {
[!SELECT "node:ref($SpiDriverName)/*[@index = num:i($Index)]"!][!//
    {
    /* Job Index */
[!VAR "SpiJobAsilIndex" = "num:i(-1)"!]
[!VAR "SpiJobQmIndex" = "num:i(-1)"!]
[!LOOP "node:ref($SpiJobName)/*"!][!//
[!IF "node:refexists(node:ref($SpiDeviceAssignmentName))"!][!//
[!VAR "SpiHwUnitNode" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule"!][!//
[!IF "$SpiSafetyMasterQSPI = $SpiHwUnitNode"!][!//
[!VAR "SpiJobAsilIndex" = "$SpiJobAsilIndex + num:i(1)"!][!//Increment Safety job index
      [!"num:i($SpiJobAsilIndex)"!]U,
[!ELSE!][!//
[!VAR "SpiJobQmIndex" = "$SpiJobQmIndex + num:i(1)"!][!//Increment QM job index
      [!"num:i($SpiJobQmIndex)"!]U,
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
    },
    {
   /* Sequence Index */
[!VAR "SpiSeqAsilIndex" = "num:i(-1)"!]
[!VAR "SpiSeqQmIndex" = "num:i(-1)"!]
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!IF "node:refexists(./SpiJobAssignment/*[@index=0])"!][!//
[!VAR "SpiHwUnitNode" = "node:ref(node:ref(./SpiJobAssignment/*[@index=0])/SpiDeviceAssignment)/SpiHwUnit/SpiAssignedHwModule"!][!//
[!IF "$SpiSafetyMasterQSPI = $SpiHwUnitNode"!][!//
[!VAR "SpiSeqAsilIndex" = "$SpiSeqAsilIndex + num:i(1)"!][!//Increment Safety sequence index
      [!"num:i($SpiSeqAsilIndex)"!]U,
[!ELSE!][!//
[!VAR "SpiSeqQmIndex" = "$SpiSeqQmIndex + num:i(1)"!][!//Increment QM sequence index
      [!"num:i($SpiSeqQmIndex)"!]U,
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
    }
  }
[!ENDSELECT!][!//End of Select for the SpiDriver/* Config set
};
[!ENDFOR!][!//
[!ENDIF!][!//SafetyEnable = true

[!IF "$Spi_BaudrateAtRuntime = 'false'"!][!//
[!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!FOR "Index" = "num:i(0)" TO "num:i(count(node:ref($SpiDriverName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index =$Index]"!][!//
[!VAR "Spi_ECONConfigString" = "''"!][!//
[!VAR "SPI_TMP" = "num:i(0)"!][!//
static const Spi_BaudrateEconType Spi_kBaudrateEcon[!"string(($Index))"!][]=
{
[!FOR "Index2" = "num:i(0)" TO "num:i(count(node:ref($SpiJobName)/*)) - num:i(1)"!][!//
[!SELECT "node:ref($SpiJobName)/*[@index =$Index2]"!][!//
[!VAR "Spi_EconHwUnit" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwModule"!][!//
[!VAR "Spi_EconHwChannel" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiHwUnit/SpiAssignedHwChannel"!][!//
[!IF "not(contains(text:split($Spi_ECONConfigString,','),concat('(',$Spi_EconHwUnit,$Spi_EconHwChannel,')')))"!][!//
[!VAR "autocalcbaud_en" = "''"!][!//
[!VAR "QSPI_Q" = "num:i(0)"!][!//
[!VAR "QSPI_A" = "num:i(0)"!][!//
[!VAR "QSPI_B" = "num:i(0)"!][!//
[!VAR "QSPI_C" = "num:i(0)"!][!//
[!VAR "QSPI_Parity" = "num:i(0)"!][!//
[!VAR "QSPI_ClkPol" = "num:i(0)"!][!//
[!VAR "QSPI_ClkPh" = "num:i(0)"!][!//
[!VAR "QSPIModuleClock" = "num:i(node:ref(./../../SpiSystemClock)/McuClockBAUD2Frequency)"!][!//
[!VAR "QSPI_Parity" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiParitySupport"!][!//
[!VAR "QSPI_ClkPol" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiShiftClockIdleLevel"!][!//
[!VAR "QSPI_ClkPh" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiDataShiftEdge"!][!//
[!VAR "autocalcbaud_en" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiAutoCalcBaudParams"!][!//
[!IF "$autocalcbaud_en = 'false'"!][!//
[!VAR "QSPI_Q" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiQSpiParamQ"!][!//
[!VAR "QSPI_A" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiQSpiParamA"!][!//
[!VAR "QSPI_B" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiQSpiParamB"!][!//
[!VAR "QSPI_C" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiQSpiParamC"!][!//
[!VAR "QSPI_Baudrate" = "num:i($QSPIModuleClock) div (num:i($QSPI_TQ+1) * num:i($QSPI_Q+1) * ($QSPI_A + 1 + $QSPI_B + $QSPI_C))"!][!//
[!ELSE!][!//
[!VAR "QSPI_Baudrate" = "node:ref(node:ref($SpiDeviceAssignmentName))/SpiBaudrate"!][!//
[!ENDIF!][!//
[!CALL "CG_BaudrateDelayParams","autocalcbaud_on" = "$autocalcbaud_en","autocalcdelay_on" = "'false'","QSPIModuleClock2" = "$QSPIModuleClock"!][!//
[!IF "$QSPI_Parity = 'Unused'"!][!//
[!VAR "QSPI_Parity" = "'SPI_QSPI_PARITY_DISABLE'"!][!//
[!ELSE!][!//
[!VAR "QSPI_Parity" = "'SPI_QSPI_PARITY_ENABLE'"!][!//
[!ENDIF!][!//
[!//
[!IF "$QSPI_ClkPol = 'LOW'"!][!//
[!VAR "QSPI_ClkPol" = "'SPI_CLK_IDLE_LOW'"!][!//
[!ELSE!][!//
[!VAR "QSPI_ClkPol" = "'SPI_CLK_IDLE_HIGH'"!][!//
[!ENDIF!][!//
[!IF "$QSPI_ClkPh = 'TRAILING'"!][!//
[!VAR "QSPI_ClkPh" = "'SPI_DATA_SHIFT_TRAIL'"!][!//
[!ELSE!][!//
[!VAR "QSPI_ClkPh" = "'SPI_DATA_SHIFT_LEAD'"!][!//
[!ENDIF!][!//
[!IF "$SPI_TMP = num:i(1)"!][!//
,
[!ENDIF!][!//
[!VAR "SPI_TMP" = "num:i(1)"!][!//
  {
    Spi_BaudRateECON([!"num:inttohex($QSPI_Q)"!]U, [!"num:inttohex($QSPI_A)"!]U, [!"num:inttohex($QSPI_B)"!]U, [!"num:inttohex($QSPI_C)"!]U,
    [!"$QSPI_ClkPh"!],
    [!"$QSPI_ClkPol"!],
    [!"$QSPI_Parity"!]),
    (uint8)((uint8)SPI_QSPI_[!"text:toupper($Spi_EconHwChannel)"!] << 4U) | (SPI_[!"$Spi_EconHwUnit"!]_INDEX)
  }[!//
[!VAR "Spi_ECONConfigString" = "concat($Spi_ECONConfigString,'(',$Spi_EconHwUnit,$Spi_EconHwChannel,')',',')"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

};
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDIF!][!// /* SpiBaudrateAtRuntime = 'false' */

const Spi_ConfigType Spi_ConfigRoot[[!"string(num:i($TotalConfig))"!]U] =
{
[!FOR "ModuleId" ="num:i(1)" TO "num:i($TotalConfig)"!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!//
  {
    [!IF "$SafetyEnable = 'true'"!][!//
    /* Safety Marker */
    (uint32)SPI_SAFETY_MARKER,
    [!ENDIF!][!//
    Spi_kChannelConfig[!"string(($ModuleId)-num:i(1))"!],
    Spi_kJobConfig[!"string(($ModuleId)-num:i(1))"!],
    Spi_kSequenceConfig[!"string(($ModuleId)-num:i(1))"!],
    {
[!IF "ecu:get('Rel.Derivate') = '_TRICORE_TC298'"!][!//
      /*QSPI0 Module Dummy in TC298, to preserve the Indexed access*/
[!ENDIF!][!//
      &Spi_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][0U],
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi1)"!][!//
      &Spi_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][1U],
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi2)"!][!//
      &Spi_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][2U],
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi3)"!][!//
      &Spi_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][3U],
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi4)"!][!//
      &Spi_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][4U],
[!ENDIF!][!//
[!IF "node:exists(SpiHwConfiguration/SpiHwConfigurationQspi5)"!][!//
      &Spi_kModuleConfig[!"string(($ModuleId)-num:i(1))"!][5U],
[!ENDIF!][!//
    },
    [!IF "$SafetyEnable = 'true'"!][!//
    Spi_kMapConfig[!"string(($ModuleId)-num:i(1))"!],
    [!ENDIF!][!//
[!IF "$Spi_BaudrateAtRuntime = 'false'"!][!//
    Spi_kBaudrateEcon[!"string(($ModuleId)-num:i(1))"!],
[!ENDIF!][!//
    (Spi_JobType)(sizeof(Spi_kJobConfig[!"string(($ModuleId)-num:i(1))"!]) / sizeof(Spi_JobConfigType)),
    (Spi_ChannelType)(sizeof(Spi_kChannelConfig[!"string(($ModuleId)-num:i(1))"!]) / \
                      sizeof(Spi_ChannelConfigType)),
    (Spi_SequenceType)(sizeof(Spi_kSequenceConfig[!"string(($ModuleId)-num:i(1))"!]) / \
                                        sizeof(Spi_SequenceConfigType)),
[!IF "$Spi_BaudrateAtRuntime = 'false'"!][!//
    (uint8)(sizeof(Spi_kBaudrateEcon[!"string(($ModuleId)-num:i(1))"!]) / sizeof(Spi_BaudrateEconType)),
[!ENDIF!][!//
    [!IF "$SpiLevel = 2"!][!//
[!NOCODE!][!//
[!SELECT "node:ref($SpiDriverName)/*[@index = ($ModuleId - 1)]"!][!//
[!VAR "SpiNoOfSyncSeqInLvl2" = "num:i(0)"!][!//
[!LOOP "node:ref($SpiSequenceName)/*"!][!//
[!IF "node:ref(node:ref($SpiJobAssignmentName)/*[1])/SpiHwUnitSynchronous != 'Asynchronous'"!][!//
[!VAR "SpiNoOfSyncSeqInLvl2" = "num:i($SpiNoOfSyncSeqInLvl2) + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!][!//
    [!"num:i($SpiNoOfSyncSeqInLvl2)"!]U
    [!ENDIF!][!//
  }[!//
[!IF "$ModuleId != $TotalConfig"!][!//
,
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!]

};


#define SPI_STOP_SEC_POSTBUILDCFG
/* Allows to map variables, constants and code of modules to individual
  memory sections.*/
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
/* General Notes */
/*
SPI095: The code file structure shall not be defined within this specification
completely. At this point it shall be pointed out that the code-file structure
shall include the following file named:
- Spi_Lcfg.c – for link time and for post-build configurable parameters and
- Spi_PBcfg.c – for post build time configurable parameters.
These files shall contain all link time and post-build time configurable
parameters.
This file shall contain all link time and post-build time configurable
parameters.
For the implementation of VariantPC, the implementation stores the
pre compile time parameters that have to be defined as constants in this file.

SPI123: In this configuration, all Sequences declared are considered as Non
Interruptible Sequences. That means, their dedicated parameter
SPI_INTERRUPTIBLE_SEQUENCE (see SPI064 & SPI106) could be omitted or the
FALSE value should be used as default.

*/


