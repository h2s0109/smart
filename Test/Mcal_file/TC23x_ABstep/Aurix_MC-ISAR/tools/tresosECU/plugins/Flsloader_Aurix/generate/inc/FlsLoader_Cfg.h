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
**  $FILENAME   : FlsLoader_Cfg.h $                                          **
**                                                                           **
**  $CC VERSION : \main\47 $                                                 **
**                                                                           **
**  $DATE       : 2016-08-03 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for FlsLoader_Cfg.h file                     **
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
**  FILENAME  : FlsLoader_Cfg.h                                               **
**                                                                            **
**  $CC VERSION : \main\47 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                      **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION : This file contains                                          **
**                Code template for FlsLoader_Cfg.h file                      **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
TRACEABILITY : [cover parentID=SAS_NAS_FLSLOADER_PR914,SAS_NAS_FLSLOADER_PR915,
               SAS_AS4XX_FLSLOADER_PR678,SAS_NAS_FLSLOADER_PR916] [/cover]
*******************************************************************************/
#ifndef FLSLOADER_CFG_H
#define FLSLOADER_CFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Offset of PFlashX  */
#define FLSLOADER_PF_S0   (0x000000U)
#define FLSLOADER_PF_S1   (0x004000U)
#define FLSLOADER_PF_S2   (0x008000U)
#define FLSLOADER_PF_S3   (0x00C000U)
#define FLSLOADER_PF_S4   (0x010000U)
#define FLSLOADER_PF_S5   (0x014000U)
#define FLSLOADER_PF_S6   (0x018000U)
#define FLSLOADER_PF_S7   (0x01C000U)
#define FLSLOADER_PF_S8   (0x020000U)
#define FLSLOADER_PF_S9   (0x028000U)
#define FLSLOADER_PF_S10  (0x030000U)
#define FLSLOADER_PF_S11  (0x038000U)
#define FLSLOADER_PF_S12  (0x040000U)
#define FLSLOADER_PF_S13  (0x048000U)
#define FLSLOADER_PF_S14  (0x050000U)
#define FLSLOADER_PF_S15  (0x058000U)
#define FLSLOADER_PF_S16  (0x060000U)
#define FLSLOADER_PF_S17  (0x070000U)
#define FLSLOADER_PF_S18  (0x080000U)
#define FLSLOADER_PF_S19  (0x090000U)
#define FLSLOADER_PF_S20  (0x0A0000U)
#define FLSLOADER_PF_S21  (0x0C0000U)
#define FLSLOADER_PF_S22  (0x0E0000U)
#define FLSLOADER_PF_S23  (0x100000U)
#define FLSLOADER_PF_S24  (0x140000U)
#define FLSLOADER_PF_S25  (0x180000U)
#define FLSLOADER_PF_S26  (0x1C0000U)

/* Higher 5 nibbles of Data Flash */
#define FLSLOADER_DF_S0   (0xAF000)
#define FLSLOADER_DF_S1   (0xAF010)
#define FLSLOADER_DF_S2   (0xAF020)
#define FLSLOADER_DF_S3   (0xAF030)
#define FLSLOADER_DF_S4   (0xAF040)
#define FLSLOADER_DF_S5   (0xAF050)
#define FLSLOADER_TC26X   (1U)
#define FLSLOADER_TC27X   (2U)
#define FLSLOADER_TC29X   (3U)
#define FLSLOADER_TC23X   (4U)
#define FLSLOADER_TC22X   (5U)
#define FLSLOADER_TC21X   (6U)

#define NO_PROTECTION     (0U)
#define READ_PROTECTION   (1U)
#define WRITE_PROTECTION  (2U)
#define WOP_PROTECTION    (3U)
#define OTP_PROTECTION    (4U)

[!NOCODE!][!//
[!/*
MACRO: CG_ConfigSwitch
Macro to generate configuration switch Values ON/OFF based on configuration
true/false
*/!]
[!MACRO "CG_ConfigSwitch", "nodeval" = ""!][!//
[!IF "$nodeval = 'true'"!][!//
(STD_ON)[!//
[!ELSE!][!//
(STD_OFF)[!//
[!ENDIF!][!//
[!ENDMACRO!][!//
[!//
[!ENDNOCODE!][!//
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('FlsLoader')[1]"!][!//

[!IF "ecu:get('FlsLoader.DfSectors') = num:i(16)"!][!//
#define FLSLOADER_DERIVATIVE             (FLSLOADER_TC23X)
[!IF "ecu:get('FlsLoader.Pf0Sectors') = num:i(27)"!][!//
#define FLSLOADER_PROCON_CHECK          ((uint32)(0x7FFFFFFU))
[!ELSEIF "ecu:get('FlsLoader.Pf0Sectors') = num:i(25)"!][!//
#define FLSLOADER_PROCON_CHECK          ((uint32)(0x1FFFFFFU))
[!ELSEIF "ecu:get('FlsLoader.Pf0Sectors') = num:i(23)"!][!//
#define FLSLOADER_PROCON_CHECK          ((uint32)(0x007FFFFF))
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.DfSectors') = num:i(12) or ecu:get('FlsLoader.DfSectors') = num:i(9)"!][!//
[!IF "ecu:get('FlsLoader.Pf1Sectors')>num:i(0)"!][!//
#define FLSLOADER_DERIVATIVE             (FLSLOADER_TC26X)
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.DfSectors') = num:i(8) or ecu:get('FlsLoader.DfSectors') = num:i(6)"!][!//
[!IF "ecu:get('FlsLoader.Pf0Sectors') = num:i(18)"!][!//
#define FLSLOADER_DERIVATIVE               (FLSLOADER_TC21X)
#define FLSLOADER_PROCON_CHECK         ((uint32)0x0003FFFF)
[!ENDIF!][!//
[!ENDIF!][!//


[!IF "ecu:get('FlsLoader.DfSectors') = num:i(12) or ecu:get('FlsLoader.DfSectors') = num:i(8)"!][!//
[!IF "ecu:get('FlsLoader.Pf0Sectors') = num:i(23)"!][!//
[!IF "ecu:get('FlsLoader.Pf1Sectors')=num:i(0)"!][!//
#define FLSLOADER_PROCON_CHECK         ((uint32)0x007FFFFF)
#define FLSLOADER_DERIVATIVE              (FLSLOADER_TC22X)
[!ENDIF!][!//
[!ELSEIF "ecu:get('FlsLoader.Pf0Sectors') = num:i(21)"!][!//
[!IF "ecu:get('FlsLoader.Pf1Sectors')=num:i(0)"!][!//
#define FLSLOADER_DERIVATIVE              (FLSLOADER_TC22X)
#define FLSLOADER_PROCON_CHECK         ((uint32)0x001FFFFF)
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//


[!IF "ecu:get('FlsLoader.DfSectors') = num:i(48) or ecu:get('FlsLoader.DfSectors') = num:i(18)"!][!//
#define FLSLOADER_DERIVATIVE             (FLSLOADER_TC27X)
[!ELSEIF "ecu:get('FlsLoader.DfSectors') = num:i(96) or ecu:get('FlsLoader.DfSectors') = num:i(24)"!][!//
#define FLSLOADER_DERIVATIVE             (FLSLOADER_TC29X)
[!ENDIF!][!//


/* FLASH LOADER module instance ID */
#define FLSLOADER_INSTANCE_ID            ((uint8)1U)

/* Software version numbers of the module.*/
[!//
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwPatchVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//

/* Vendor specific implementation version information */
#define FLSLOADER_SW_MAJOR_VERSION       ([!"$SwMajorVersion"!]U)
#define FLSLOADER_SW_MINOR_VERSION       ([!"$SwMinorVersion"!]U)
#define FLSLOADER_SW_PATCH_VERSION       ([!"$SwPatchVersion"!]U)


 
#define FLSLOADER_PFLASH0_START_ADDRESS  ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf0StartAddress'))"!]U))
[!IF "ecu:get('FlsLoader.Pf1Sectors') > num:i(0)"!][!//

#define FLSLOADER_PFLASH1_START_ADDRESS  ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf1StartAddress'))"!]U))
[!ENDIF!][!//
[!IF "ecu:get('FlsLoader.Pf2Sectors') > num:i(0)"!][!//

#define FLSLOADER_PFLASH2_START_ADDRESS  ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf2StartAddress'))"!]U))
[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.Pf3Sectors') > num:i(0)"!][!//
#define FLSLOADER_PFLASH3_START_ADDRESS  ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf3StartAddress'))"!]U))
[!ENDIF!][!//
 

#define FLSLOADER_DFLASH0_START_ADDRESS  ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Df0StartAddress'))"!]U))

#define FLSLOADER_DFLASH0_END            ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Df0EndAddress'))"!]U))
#define FLSLOADER_DFLASH_BANK_SIZE       ([!"num:inttohex(ecu:get('FlsLoader.DfBankSize'))"!]U)

#define FLSLOADER_PFLASH0_END            ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf0EndAddress'))"!]U))
#define FLSLOADER_PFLASH0_SIZE           ([!"num:inttohex(ecu:get('FlsLoader.Pf0Size'))"!]U)

[!IF "ecu:get('FlsLoader.Pf1Sectors') > num:i(0)"!][!//
#define FLSLOADER_PFLASH1_END            ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf1EndAddress'))"!]U))
#define FLSLOADER_PFLASH1_SIZE           ([!"num:inttohex(ecu:get('FlsLoader.PF1Size'))"!]U)
[!ENDIF!][!//

[!IF "(ecu:get('FlsLoader.Pf2Sectors') > num:i(0))"!][!//
#define FLSLOADER_PFLASH2_END            ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf2EndAddress'))"!]U))
#define FLSLOADER_PFLASH2_SIZE           ([!"num:inttohex(ecu:get('FlsLoader.Pf2Size'))"!]U)
[!ENDIF!][!//

[!IF "(ecu:get('FlsLoader.Pf3Sectors') > num:i(0))"!][!//
#define FLSLOADER_PFLASH3_END            ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.Pf3EndAddress'))"!]U))
#define FLSLOADER_PFLASH3_SIZE           ([!"num:inttohex(ecu:get('FlsLoader.PF3Size'))"!]U)
[!ENDIF!][!//

/* UCB PFLASH address */
#define FLSLOADER_UCB_PFLASH             ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.UcbPf'))"!]U))
/* UCB DFLASH address */
#define FLSLOADER_UCB_DFLASH             ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.UcbDf'))"!]U))
/* UCB DFLASH address */
#define FLSLOADER_UCB_OTP                ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.UcbOtp'))"!]U))

/* UCB Start address */
#define FLSLOADER_UCB_START_ADDRESS      ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.UcbStartAddress'))"!]U))

/* UCB End address */
#define FLSLOADER_UCB_END_ADDRESS        ((FlsLoader_AddressType)([!"num:inttohex(ecu:get('FlsLoader.UcbEndAddress'))"!]U))


#define FLSLOADER_NUM_OF_PF0_SECTORS     ([!"(ecu:get('FlsLoader.Pf0Sectors'))"!]U)
[!IF "(ecu:get('FlsLoader.Pf1Sectors') > num:i(0))"!][!//
#define FLSLOADER_NUM_OF_PF1_SECTORS     ([!"(ecu:get('FlsLoader.Pf1Sectors'))"!]U)
[!ENDIF!][!//
[!IF "(ecu:get('FlsLoader.Pf2Sectors') > num:i(0))"!][!//
#define FLSLOADER_NUM_OF_PF2_SECTORS     ([!"(ecu:get('FlsLoader.Pf2Sectors'))"!]U)
[!ENDIF!][!//
[!IF "(ecu:get('FlsLoader.Pf3Sectors') > num:i(0))"!][!//
#define FLSLOADER_NUM_OF_PF3_SECTORS     ([!"(ecu:get('FlsLoader.Pf3Sectors'))"!]U)
[!ENDIF!][!//

#define FLSLOADER_NUM_OF_DF_SECTORS      ([!"(ecu:get('FlsLoader.DfSectors'))"!]U) 

[!IF "(ecu:get('FlsLoader.Pf3Sectors') > num:i(0))"!][!//
#define FLSLOADER_PF_BANKS                (4U)
[!ELSEIF "ecu:get('FlsLoader.Pf2Sectors') > num:i(0)"!][!//
#define FLSLOADER_PF_BANKS                (3U)
[!ELSEIF "ecu:get('FlsLoader.Pf1Sectors') > num:i(0)"!][!//
#define FLSLOADER_PF_BANKS                (2U)
[!ELSE!][!//
#define FLSLOADER_PF_BANKS                (1U)
[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.Pf3Sectors') > num:i(0)"!][!//
#define FLSLOADER_FLASH_BUSY_MASK       (0x0000007AU)
[!ELSEIF "ecu:get('FlsLoader.Pf2Sectors') > num:i(0)"!][!//
#define FLSLOADER_FLASH_BUSY_MASK       (0x0000003AU)
[!ELSEIF "ecu:get('FlsLoader.Pf1Sectors') > num:i(0)"!][!//
#define FLSLOADER_FLASH_BUSY_MASK       (0x0000001AU)
[!ELSE!][!//
#define FLSLOADER_FLASH_BUSY_MASK       (0x0000000AU)
[!ENDIF!][!//

/*
Configuration: FLSLOADER_DEV_ERROR_DETECT
Preprocessor switch to enable/disable the development error detection and
reporting.
-If ON, Enable development error detecion
-If OFF,Disable development error detecion
*/
#define FLSLOADER_DEV_ERROR_DETECT       [!CALL "CG_ConfigSwitch","nodeval" = "FlsLoaderDriverConfiguration/FlsLoaderDevErrorDetect"!][!//

/*
Configuration: FLSLOADER_ENABLE_LOCKCHECK
Preprocessor switch to enable/disable the Lockcheck
The erase and write API's has Lock Check functionality, substantially
this is a big section, user could remove the same, if locking is not
used.
-If ON, Enable the FlsLoader Lockcheck in Write / Erase API's
-If OFF,Disable the FlsLoader Lockcheck in Write / Erase API's
*/
#define FLSLOADER_ENABLE_LOCKCHECK       [!CALL "CG_ConfigSwitch", "nodeval" = "FlsLoaderDriverConfiguration/FlsLoaderEnableLockCheck"!][!//

/*
Configuration: FLSLOADER_DEINIT_API
Preprocessor switch to enable/disable the deinitilize FlsLoader API
-If ON, Enable FlsLoader Deinitilization API
-If OFF,Disable FlsLoader Deinitilization API
*/
#define FLSLOADER_DEINIT_API             [!CALL "CG_ConfigSwitch", "nodeval" = "FlsLoaderOptionalApi/FlsLoaderDeInitApi"!]

/*
Configuration: FLSLOADER_LOCK_UNLOCK_API
Preprocessor switch to enable/disable the Lock/UnLock API
-If ON, Enable the FlsLoader Lock/UnLock API
-If OFF,Disable FlsLoader Lock/UnLock API
*/
#define FLSLOADER_LOCK_UNLOCK_API        [!CALL "CG_ConfigSwitch", "nodeval" = "FlsLoaderOptionalApi/FlsLoaderLockUnlockApi"!][!//

/*
Configuration: FLSLOADER_VERSION_INFO_API
Preprocessor switch to enable/disable the versioninfo API
-If ON, Include the FlsLoader GetVersionInfo API
-If OFF,Disable FlsLoader GetVersionInfo API
*/
#define FLSLOADER_VERSION_INFO_API       [!CALL "CG_ConfigSwitch", "nodeval" = "FlsLoaderOptionalApi/FlsLoaderVersionInfoApi"!]

/* Configuration: FlsLoader PFlash0 Protection configuration */
#define FLSLOADER_PF0_PROT         ([!"FlsLoaderPFlash0ProtConfig/FlsLoaderPF0WriteProt"!])

[!IF "ecu:get('FlsLoader.Pf1Sectors') > num:i(0)"!][!//
/* Configuration: FlsLoader PFlash1 Protection configuration */
#define FLSLOADER_PF1_PROT        ([!"FlsLoaderPFlash1ProtConfig/FlsLoaderPF1WriteProt"!])
[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.Pf2Sectors') > num:i(0)"!][!//
/* Configuration: FlsLoader PFlash0 Protection configuration */
#define FLSLOADER_PF2_PROT         ([!"FlsLoaderPFlash2ProtConfig/FlsLoaderPF2WriteProt"!])
[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.Pf3Sectors') > num:i(0)"!][!//
/* Configuration: FlsLoader PFlash1 Protection configuration */
#define FLSLOADER_PF3_PROT        ([!"FlsLoaderPFlash3ProtConfig/FlsLoaderPF3WriteProt"!])
[!ENDIF!][!//

/*
Configuration: FlsLoader DFLASH0 Read/Write Protection configuration */
#define FLSLOADER_DF0_PROT        ([!"FlsLoaderDFlashProtConfig/FlsLoaderDF0Prot"!])


#if ((FLSLOADER_PF0_PROT == READ_PROTECTION )|| \
  (FLSLOADER_PF0_PROT == WRITE_PROTECTION)|| \
  (FLSLOADER_PF0_PROT == OTP_PROTECTION )|| \
  (FLSLOADER_PF0_PROT == WOP_PROTECTION)\
[!IF "(ecu:get('FlsLoader.Pf1Sectors') > num:i(0))"!][!//
||(FLSLOADER_PF1_PROT == READ_PROTECTION )||\
  (FLSLOADER_PF1_PROT == WRITE_PROTECTION)\
||(FLSLOADER_PF1_PROT == OTP_PROTECTION )|| \
  (FLSLOADER_PF1_PROT == WOP_PROTECTION)\
[!ENDIF!][!//
[!IF "(ecu:get('FlsLoader.Pf2Sectors') > num:i(0))"!][!//
||(FLSLOADER_PF2_PROT == READ_PROTECTION )|| \
  (FLSLOADER_PF2_PROT == WRITE_PROTECTION)\
||(FLSLOADER_PF2_PROT == OTP_PROTECTION )|| \
  (FLSLOADER_PF2_PROT == WOP_PROTECTION)\
[!ENDIF!][!//
[!IF "(ecu:get('FlsLoader.Pf3Sectors') > num:i(0))"!][!//
||(FLSLOADER_PF3_PROT == READ_PROTECTION )|| \
  (FLSLOADER_PF3_PROT == WRITE_PROTECTION)\
||(FLSLOADER_PF3_PROT == OTP_PROTECTION )|| \
  (FLSLOADER_PF3_PROT == WOP_PROTECTION)\
[!ENDIF!][!//
)
/* PFLASH0 UCB 4 double word password*/
#define FLSLOADER_PF0_PW00   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW0_0),8)"!]U)
#define FLSLOADER_PF0_PW01   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW0_1),8)"!]U)
#define FLSLOADER_PF0_PW10   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW1_0),8)"!]U)
#define FLSLOADER_PF0_PW11   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW1_1),8)"!]U)
#define FLSLOADER_PF0_PW20   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW2_0),8)"!]U)
#define FLSLOADER_PF0_PW21   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW2_1),8)"!]U)
#define FLSLOADER_PF0_PW30   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW3_0),8)"!]U)
#define FLSLOADER_PF0_PW31   ((uint32)[!"num:inttohex(num:i(FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW3_1),8)"!]U)

[!NOCODE!][!//
[!VAR "PW00" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW0_0"!][!//
[!VAR "PW01" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW0_1"!][!//
[!VAR "PW10" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW1_0"!][!//
[!VAR "PW11" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW1_1"!][!//
[!VAR "PW20" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW2_0"!][!//
[!VAR "PW21" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW2_1"!][!//
[!VAR "PW30" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW3_0"!][!//
[!VAR "PW31" = "FlsLoaderPFlash0ProtConfig/FlsLoaderPFUcbPW3_1"!][!//
[!ENDNOCODE!][!//


/* Passwords in the form of Bytes used in array to fill in UCB_PFLASH  */
#define FLSLOADER_P0_PW00_B0 ((uint8)[!"num:inttohex(bit:and($PW00,255),2)"!]U)
#define FLSLOADER_P0_PW00_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW00,8),255),2)"!]U)
#define FLSLOADER_P0_PW00_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW00,16),255),2)"!]U)
#define FLSLOADER_P0_PW00_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW00,24),255),2)"!]U)

#define FLSLOADER_P0_PW01_B0 ((uint8)[!"num:inttohex(bit:and($PW01,255),2)"!]U)
#define FLSLOADER_P0_PW01_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW01,8),255),2)"!]U)
#define FLSLOADER_P0_PW01_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW01,16),255),2)"!]U)
#define FLSLOADER_P0_PW01_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW01,24),255),2)"!]U)

#define FLSLOADER_P0_PW10_B0 ((uint8)[!"num:inttohex(bit:and($PW10,255),2)"!]U)
#define FLSLOADER_P0_PW10_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW10,8),255),2)"!]U)
#define FLSLOADER_P0_PW10_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW10,16),255),2)"!]U)
#define FLSLOADER_P0_PW10_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW10,24),255),2)"!]U)

#define FLSLOADER_P0_PW11_B0 ((uint8)[!"num:inttohex(bit:and($PW11,255),2)"!]U)
#define FLSLOADER_P0_PW11_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW11,8),255),2)"!]U)
#define FLSLOADER_P0_PW11_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW11,16),255),2)"!]U)
#define FLSLOADER_P0_PW11_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW11,24),255),2)"!]U)

#define FLSLOADER_P0_PW20_B0 ((uint8)[!"num:inttohex(bit:and($PW20,255),2)"!]U)
#define FLSLOADER_P0_PW20_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW20,8),255),2)"!]U)
#define FLSLOADER_P0_PW20_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW20,16),255),2)"!]U)
#define FLSLOADER_P0_PW20_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW20,24),255),2)"!]U)

#define FLSLOADER_P0_PW21_B0 ((uint8)[!"num:inttohex(bit:and($PW21,255),2)"!]U)
#define FLSLOADER_P0_PW21_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW21,8),255),2)"!]U)
#define FLSLOADER_P0_PW21_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW21,16),255),2)"!]U)
#define FLSLOADER_P0_PW21_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW21,24),255),2)"!]U)

#define FLSLOADER_P0_PW30_B0 ((uint8)[!"num:inttohex(bit:and($PW30,255),2)"!]U)
#define FLSLOADER_P0_PW30_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW30,8),255),2)"!]U)
#define FLSLOADER_P0_PW30_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW30,16),255),2)"!]U)
#define FLSLOADER_P0_PW30_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW30,24),255),2)"!]U)

#define FLSLOADER_P0_PW31_B0 ((uint8)[!"num:inttohex(bit:and($PW31,255),2)"!]U)
#define FLSLOADER_P0_PW31_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW31,8),255),2)"!]U)
#define FLSLOADER_P0_PW31_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW31,16),255),2)"!]U)
#define FLSLOADER_P0_PW31_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($PW31,24),255),2)"!]U)

/* PFLASH0 Read/write protection for Sector x*/
[!VAR "Proconp0" = "num:i(0)"!][!//
[!VAR "ProconOtp0" = "num:i(0)"!][!//
[!VAR "ProconWop0" = "num:i(0)"!][!//


[!IF "(FlsLoaderPFlash0ProtConfig/FlsLoaderPF0WriteProt = 'WRITE_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash0ProtConfig/FlsLoaderPF0Sector'"!][!//

[!FOR "i" = "0" TO "ecu:get('FlsLoader.Pf0Sectors') - num:i(1)"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WRITE_PROTECTION'"!][!//
[!VAR "Proconp0" = "bit:bitset($Proconp0, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash0ProtConfig/FlsLoaderPF0WriteProt = 'OTP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash0ProtConfig/FlsLoaderPF0Sector'"!][!//

[!FOR "i" = "0" TO "ecu:get('FlsLoader.Pf0Sectors') - num:i(1)"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'OTP_PROTECTION'"!][!//
[!VAR "ProconOtp0" = "bit:bitset($ProconOtp0, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash0ProtConfig/FlsLoaderPF0WriteProt = 'WOP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash0ProtConfig/FlsLoaderPF0Sector'"!][!//

[!FOR "i" = "0" TO "ecu:get('FlsLoader.Pf0Sectors') - num:i(1)"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WOP_PROTECTION'"!][!//
[!VAR "ProconWop0" = "bit:bitset($ProconWop0, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//


[!/* Byte0 = ProconP0 & 0xFFU*/
/*Byte1 = ((ProconP0 >> 8U) & 0xFFU)*/
/*Byte2 = ((ProconP0 >> 16U)& 0xFFU)*/
/*Byte3 = ((ProconP0 >> 24U)& 0xFFU)*/!][!//
#define FLSLOADER_PROCONP0_BYTE0 ((uint8)[!"(bit:and($Proconp0,255))"!])
#define FLSLOADER_PROCONP0_BYTE1 ((uint8)[!"(bit:and(bit:shr($Proconp0,8),255))"!])
#define FLSLOADER_PROCONP0_BYTE2 ((uint8)[!"(bit:and(bit:shr($Proconp0,16),255))"!])
#define FLSLOADER_PROCONP0_BYTE3 ((uint8)[!"(bit:and(bit:shr($Proconp0,24),255))"!])

#define FLSLOADER_PROCONOTP0_BYTE0 ((uint8)[!"(bit:and($ProconOtp0,255))"!])
#define FLSLOADER_PROCONOTP0_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconOtp0,8),255))"!])
#define FLSLOADER_PROCONOTP0_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconOtp0,16),255))"!])
#define FLSLOADER_PROCONOTP0_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconOtp0,24),255))"!])

#define FLSLOADER_PROCONWOP0_BYTE0 ((uint8)[!"(bit:and($ProconWop0,255))"!])
#define FLSLOADER_PROCONWOP0_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconWop0,8),255))"!])
#define FLSLOADER_PROCONWOP0_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconWop0,16),255))"!])
#define FLSLOADER_PROCONWOP0_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconWop0,24),255))"!])

[!IF "ecu:get('FlsLoader.Pf1Sectors') > num:i(0)"!][!//
/* PFLASH1 Read/write protection*/
[!VAR "Proconp1" = "num:i(0)"!][!//
[!VAR "ProconOtp1" = "num:i(0)"!][!//
[!VAR "ProconWop1" = "num:i(0)"!][!//

[!IF "(FlsLoaderPFlash1ProtConfig/FlsLoaderPF1WriteProt = 'WRITE_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash1ProtConfig/FlsLoaderPF1Sector'"!][!//

[!FOR "i" = "0" TO "ecu:get('FlsLoader.Pf1Sectors') - num:i(1)"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WRITE_PROTECTION'"!][!//
[!VAR "Proconp1" = "bit:bitset($Proconp1, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash1ProtConfig/FlsLoaderPF1WriteProt = 'OTP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash1ProtConfig/FlsLoaderPF1Sector'"!][!//

[!FOR "i" = "0" TO "ecu:get('FlsLoader.Pf1Sectors') - num:i(1)"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'OTP_PROTECTION'"!][!//
[!VAR "ProconOtp1" = "bit:bitset($ProconOtp1, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash1ProtConfig/FlsLoaderPF1WriteProt = 'WOP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash1ProtConfig/FlsLoaderPF1Sector'"!][!//

[!FOR "i" = "0" TO "ecu:get('FlsLoader.Pf1Sectors') - num:i(1)"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WOP_PROTECTION'"!][!//
[!VAR "ProconWop1" = "bit:bitset($ProconWop1, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!/*Byte0 = ProconP1 & 0xFFU*/
/*Byte1 = ((ProconP1 >> 8) & 0xFF)*/
/*Byte2 = ((ProconP1 >> 16)& 0xFF)*/
/*Byte3 = ((ProconP1 >> 24)& 0xFF)*/!][!//
#define FLSLOADER_PROCONP1_BYTE0 ((uint8)[!"(bit:and($Proconp1,255))"!])
#define FLSLOADER_PROCONP1_BYTE1 ((uint8)[!"(bit:and(bit:shr($Proconp1,8),255))"!])
#define FLSLOADER_PROCONP1_BYTE2 ((uint8)[!"(bit:and(bit:shr($Proconp1,16),255))"!])
#define FLSLOADER_PROCONP1_BYTE3 ((uint8)[!"(bit:and(bit:shr($Proconp1,24),255))"!])

#define FLSLOADER_PROCONOTP1_BYTE0 ((uint8)[!"(bit:and($ProconOtp1,255))"!])
#define FLSLOADER_PROCONOTP1_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconOtp1,8),255))"!])
#define FLSLOADER_PROCONOTP1_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconOtp1,16),255))"!])
#define FLSLOADER_PROCONOTP1_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconOtp1,24),255))"!])

#define FLSLOADER_PROCONWOP1_BYTE0 ((uint8)[!"(bit:and($ProconWop1,255))"!])
#define FLSLOADER_PROCONWOP1_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconWop1,8),255))"!])
#define FLSLOADER_PROCONWOP1_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconWop1,16),255))"!])
#define FLSLOADER_PROCONWOP1_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconWop1,24),255))"!])

[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.Pf2Sectors') > num:i(0)"!][!//

/* PFLASH2 Read/write protection*/
[!VAR "Proconp2" = "num:i(0)"!][!//
[!VAR "ProconOtp2" = "num:i(0)"!][!//
[!VAR "ProconWop2" = "num:i(0)"!][!//

[!IF "(FlsLoaderPFlash2ProtConfig/FlsLoaderPF2WriteProt = 'WRITE_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash2ProtConfig/FlsLoaderPF2Sector'"!][!//
[!FOR "i" = "0" TO "26"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WRITE_PROTECTION'"!][!//
[!VAR "Proconp2" = "bit:bitset($Proconp2, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash2ProtConfig/FlsLoaderPF2WriteProt = 'OTP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash2ProtConfig/FlsLoaderPF2Sector'"!][!//
[!FOR "i" = "0" TO "26"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'OTP_PROTECTION'"!][!//
[!VAR "ProconOtp2" = "bit:bitset($ProconOtp2, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash2ProtConfig/FlsLoaderPF2WriteProt = 'WOP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash2ProtConfig/FlsLoaderPF2Sector'"!][!//
[!FOR "i" = "0" TO "26"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WOP_PROTECTION'"!][!//
[!VAR "ProconWop2" = "bit:bitset($ProconWop2, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!/*Byte0 = ProconP2 & 0xFFU*/
/*Byte1 = ((ProconP2 >> 8) & 0xFF)*/
/*Byte2 = ((ProconP2 >> 16)& 0xFF)*/
/*Byte3 = ((ProconP2 >> 24)& 0xFF)*/!][!//
#define FLSLOADER_PROCONP2_BYTE0 ((uint8)[!"(bit:and($Proconp2,255))"!])
#define FLSLOADER_PROCONP2_BYTE1 ((uint8)[!"(bit:and(bit:shr($Proconp2,8),255))"!])
#define FLSLOADER_PROCONP2_BYTE2 ((uint8)[!"(bit:and(bit:shr($Proconp2,16),255))"!])
#define FLSLOADER_PROCONP2_BYTE3 ((uint8)[!"(bit:and(bit:shr($Proconp2,24),255))"!])

#define FLSLOADER_PROCONOTP2_BYTE0 ((uint8)[!"(bit:and($ProconOtp2,255))"!])
#define FLSLOADER_PROCONOTP2_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconOtp2,8),255))"!]) 
#define FLSLOADER_PROCONOTP2_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconOtp2,16),255))"!])
#define FLSLOADER_PROCONOTP2_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconOtp2,24),255))"!])

#define FLSLOADER_PROCONWOP2_BYTE0 ((uint8)[!"(bit:and($ProconWop2,255))"!])
#define FLSLOADER_PROCONWOP2_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconWop2,8),255))"!])
#define FLSLOADER_PROCONWOP2_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconWop2,16),255))"!])
#define FLSLOADER_PROCONWOP2_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconWop2,24),255))"!])


[!ENDIF!][!//

[!IF "ecu:get('FlsLoader.Pf3Sectors') > num:i(0)"!][!//


/* PFLASH3 Read/write protection*/
[!VAR "Proconp3" = "num:i(0)"!][!//
[!VAR "ProconOtp3" = "num:i(0)"!][!//
[!VAR "ProconWop3" = "num:i(0)"!][!//

[!IF "(FlsLoaderPFlash3ProtConfig/FlsLoaderPF3WriteProt = 'WRITE_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash3ProtConfig/FlsLoaderPF3Sector'"!][!//
[!FOR "i" = "0" TO "26"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WRITE_PROTECTION'"!][!//
[!VAR "Proconp3" = "bit:bitset($Proconp3, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash3ProtConfig/FlsLoaderPF3WriteProt = 'OTP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash3ProtConfig/FlsLoaderPF3Sector'"!][!//
[!FOR "i" = "0" TO "26"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'OTP_PROTECTION'"!][!//
[!VAR "ProconOtp3" = "bit:bitset($ProconOtp3, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//

[!ELSEIF "(FlsLoaderPFlash3ProtConfig/FlsLoaderPF3WriteProt = 'WOP_PROTECTION')"!][!//
[!VAR "SectorPath1" ="'FlsLoaderPFlash3ProtConfig/FlsLoaderPF3Sector'"!][!//
[!FOR "i" = "0" TO "26"!][!//
[!VAR "SectorPath" = "concat($SectorPath1,$i)"!][!//
[!IF "node:value($SectorPath) = 'WOP_PROTECTION'"!][!//
[!VAR "ProconWop3" = "bit:bitset($ProconWop3, $i)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!/*Byte0 = ProconP3 & 0xFFU*/
/*Byte1 = ((ProconP3 >> 8) & 0xFF)*/
/*Byte2 = ((ProconP3 >> 16)& 0xFF)*/
/*Byte3 = ((ProconP3 >> 24)& 0xFF)*/!][!//
#define FLSLOADER_PROCONP3_BYTE0 ((uint8)[!"(bit:and($Proconp3,255))"!]) 
#define FLSLOADER_PROCONP3_BYTE1 ((uint8)[!"(bit:and(bit:shr($Proconp3,8),255))"!])  
#define FLSLOADER_PROCONP3_BYTE2 ((uint8)[!"(bit:and(bit:shr($Proconp3,16),255))"!])
#define FLSLOADER_PROCONP3_BYTE3 ((uint8)[!"(bit:and(bit:shr($Proconp3,24),255))"!])

#define FLSLOADER_PROCONOTP3_BYTE0 ((uint8)[!"(bit:and($ProconOtp3,255))"!])
#define FLSLOADER_PROCONOTP3_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconOtp3,8),255))"!])  
#define FLSLOADER_PROCONOTP3_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconOtp3,16),255))"!]) 
#define FLSLOADER_PROCONOTP3_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconOtp3,24),255))"!]) 

#define FLSLOADER_PROCONWOP3_BYTE0 ((uint8)[!"(bit:and($ProconWop3,255))"!]) 
#define FLSLOADER_PROCONWOP3_BYTE1 ((uint8)[!"(bit:and(bit:shr($ProconWop3,8),255))"!])   
#define FLSLOADER_PROCONWOP3_BYTE2 ((uint8)[!"(bit:and(bit:shr($ProconWop3,16),255))"!]) 
#define FLSLOADER_PROCONWOP3_BYTE3 ((uint8)[!"(bit:and(bit:shr($ProconWop3,24),255))"!]) 

[!ENDIF!][!//

#endif

#if (FLSLOADER_DF0_PROT == READ_PROTECTION)

#define FLSLOADER_PROCOND_BYTE0 ((uint8)(0x01U))
#define FLSLOADER_PROCOND_BYTE1 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE2 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE3 ((uint8)(0x80U))

#elif (FLSLOADER_DF0_PROT == WRITE_PROTECTION)
#define FLSLOADER_PROCOND_BYTE0 ((uint8)(0x01U))
#define FLSLOADER_PROCOND_BYTE1 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE2 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE3 ((uint8)(0U))

#else
#define FLSLOADER_PROCOND_BYTE0 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE1 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE2 ((uint8)(0U))
#define FLSLOADER_PROCOND_BYTE3 ((uint8)(0U))
#endif

[!IF "FlsLoaderDFlashProtConfig/FlsLoaderDFWriteProt != 'NO_PROTECTION'"!][!//
#if (FLSLOADER_DF0_PROT != NO_PROTECTION)
/* DFLASH UCB 4 double word password*/
#define FLSLOADER_DF0_PW00    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW0_0),8)"!]U)
#define FLSLOADER_DF0_PW01    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW0_1),8)"!]U)
#define FLSLOADER_DF0_PW10    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW1_0),8)"!]U)
#define FLSLOADER_DF0_PW11    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW1_1),8)"!]U)
#define FLSLOADER_DF0_PW20    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW2_0),8)"!]U)
#define FLSLOADER_DF0_PW21    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW2_1),8)"!]U)
#define FLSLOADER_DF0_PW30    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW3_0),8)"!]U)
#define FLSLOADER_DF0_PW31    ((uint32)[!"num:inttohex(num:i(FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW3_1),8)"!]U)

[!NOCODE!][!//
[!VAR "DF0_PW00" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW0_0"!][!//
[!VAR "DF0_PW01" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW0_1"!][!//
[!VAR "DF0_PW10" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW1_0"!][!//
[!VAR "DF0_PW11" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW1_1"!][!//
[!VAR "DF0_PW20" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW2_0"!][!//
[!VAR "DF0_PW21" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW2_1"!][!//
[!VAR "DF0_PW30" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW3_0"!][!//
[!VAR "DF0_PW31" = "FlsLoaderDFlashProtConfig/FlsLoaderDFUcbPW3_1"!][!//
[!ENDNOCODE!][!//

/* Passwords in the form of Bytes used in array to fill in UCB_PFLASH  */
#define FLSLOADER_DF0_PW00_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW00,255),2)"!]U)
#define FLSLOADER_DF0_PW00_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW00,8),255),2)"!]U)
#define FLSLOADER_DF0_PW00_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW00,16),255),2)"!]U)
#define FLSLOADER_DF0_PW00_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW00,24),255),2)"!]U)

#define FLSLOADER_DF0_PW01_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW01,255),2)"!]U)
#define FLSLOADER_DF0_PW01_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW01,8),255),2)"!]U)
#define FLSLOADER_DF0_PW01_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW01,16),255),2)"!]U)
#define FLSLOADER_DF0_PW01_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW01,24),255),2)"!]U)

#define FLSLOADER_DF0_PW10_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW10,255),2)"!]U)
#define FLSLOADER_DF0_PW10_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW10,8),255),2)"!]U)
#define FLSLOADER_DF0_PW10_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW10,16),255),2)"!]U)
#define FLSLOADER_DF0_PW10_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW10,24),255),2)"!]U)

#define FLSLOADER_DF0_PW11_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW11,255),2)"!]U)
#define FLSLOADER_DF0_PW11_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW11,8),255),2)"!]U)
#define FLSLOADER_DF0_PW11_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW11,16),255),2)"!]U)
#define FLSLOADER_DF0_PW11_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW11,24),255),2)"!]U)

#define FLSLOADER_DF0_PW20_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW20,255),2)"!]U)
#define FLSLOADER_DF0_PW20_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW20,8),255),2)"!]U)
#define FLSLOADER_DF0_PW20_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW20,16),255),2)"!]U)
#define FLSLOADER_DF0_PW20_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW20,24),255),2)"!]U)

#define FLSLOADER_DF0_PW21_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW21,255),2)"!]U)
#define FLSLOADER_DF0_PW21_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW21,8),255),2)"!]U)
#define FLSLOADER_DF0_PW21_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW21,16),255),2)"!]U)
#define FLSLOADER_DF0_PW21_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW21,24),255),2)"!]U)

#define FLSLOADER_DF0_PW30_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW30,255),2)"!]U)
#define FLSLOADER_DF0_PW30_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW30,8),255),2)"!]U)
#define FLSLOADER_DF0_PW30_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW30,16),255),2)"!]U)
#define FLSLOADER_DF0_PW30_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW30,24),255),2)"!]U)

#define FLSLOADER_DF0_PW31_B0 ((uint8)[!"num:inttohex(bit:and($DF0_PW31,255),2)"!]U)
#define FLSLOADER_DF0_PW31_B1 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW31,8),255),2)"!]U)
#define FLSLOADER_DF0_PW31_B2 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW31,16),255),2)"!]U)
#define FLSLOADER_DF0_PW31_B3 ((uint8)[!"num:inttohex(bit:and(bit:shr($DF0_PW31,24),255),2)"!]U)

#else

/* Passords in the form of Bytes used in array to fill in UCB_PFLASH  */
#define FLSLOADER_DF0_PW00_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW00_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW00_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW00_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW01_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW01_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW01_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW01_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW10_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW10_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW10_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW10_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW11_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW11_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW11_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW11_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW20_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW20_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW20_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW20_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW21_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW21_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW21_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW21_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW30_B0 ((uint8)(0U))
#define FLSLOADER_DF0_PW30_B1 ((uint8)(0U))
#define FLSLOADER_DF0_PW30_B2 ((uint8)(0U))
#define FLSLOADER_DF0_PW30_B3 ((uint8)(0U))

#define FLSLOADER_DF0_PW31_B0 ((uint8)(0U)
#define FLSLOADER_DF0_PW31_B1 ((uint8)(0U)
#define FLSLOADER_DF0_PW31_B2 ((uint8)(0U)
#define FLSLOADER_DF0_PW31_B3 ((uint8)(0U)
#endif

[!ENDIF!][!//

[!ENDSELECT!][!//

#endif /*FLSLOADER_CFG_H*/
