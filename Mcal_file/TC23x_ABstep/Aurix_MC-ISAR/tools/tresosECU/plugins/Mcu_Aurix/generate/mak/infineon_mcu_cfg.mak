#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2013)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_mcu_cfg.mak                                          **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2013.07.04                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines type of delivery for the MCU module      **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* Ak           Ashish Kumar                                                 **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2013.07.03, AK  : Initial version.
#*
#******************************************************************************/


#****************************** Specific **************************************/

# Specify the type of delivery for MCU module one of the values specified below
# MCU_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]

MCU_DELIVERY_MODE = VARIANTPB_SOURCE
 
# Specify if demo is required [ ON / OFF ]
MCU_DEMO = STD_ON

[!NOCODE!][!//
[!VAR "CrcHardwareModeUsed" = "'OFF'"!][!//
[!SELECT "as:modconf('Crc')[1]"!][!//
[!IF "CrcGeneral/Crc8Mode/__1 = 'CRC_8_HARDWARE'"!][!//
[!VAR "CrcHardwareModeUsed" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "CrcGeneral/Crc16Mode/__1 = 'CRC_16_HARDWARE'"!][!//
[!VAR "CrcHardwareModeUsed" = "'ON'"!][!//
[!ENDIF!][!//
[!IF "CrcGeneral/Crc32Mode/__1 = 'CRC_32_HARDWARE' or CrcGeneral/Crc32Mode/__1 = 'CRC_32_INSTRUCTION'"!][!//
[!VAR "CrcHardwareModeUsed" = "'ON'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "DmaHardwareUsed" = "'OFF'"!][!//
[!VAR "ModulePath" = "'McuModuleConfiguration'"!][!//
[!VAR "TotalMcuModuleConfig" = "num:i(count(node:ref($ModulePath)/*))"!][!//
[!FOR "ModuleIndex" = "0" TO " ($TotalMcuModuleConfig - 1)"!][!//
[!VAR "Count" = "num:i(count(node:ref($ModulePath)/*[@index= $ModuleIndex]/DmaConfiguration/*))"!]
[!IF "$Count = num:i(1)"!][!//
[!VAR "DmaHardwareUsed" = "'ON'"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDSELECT!]
[!ENDNOCODE!]
MCU_CRC_USED = [!"$CrcHardwareModeUsed"!]

MCU_DMA_USED = [!"$DmaHardwareUsed"!]