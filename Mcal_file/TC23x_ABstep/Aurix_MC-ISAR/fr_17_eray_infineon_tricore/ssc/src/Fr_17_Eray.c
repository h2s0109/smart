/*******************************************************************************
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
**  $FILENAME   : Fr_17_Eray.c $                                             **
**                                                                            **
**  $CC VERSION : \main\117 $                                                **
**                                                                            **
**  $DATE       : 2016-07-15 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                - FR115: FlexRay driver API implementation                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/

/** Traceability : [cover parentID=DS_AS40X_FR451_FR452,DS_AS40X_FR030,
    DS_AS40X_FR625_FR626,DS_AS_FR099,DS_AS40X_FR646_FR648,
    DS_AS_FR098,DS_NAS_FR_PR919,DS_NAS_FR_PR912_1,DS_NAS_FR_PR912_2,
    DS_NAS_FR_FR_PR734,DS_NAS_FR_PR624_PR759_PR760_PR761,,DS_NAS_FR_PR228,
    SAS_NAS_ALL_PR749,SAS_NAS_ALL_PR102,SAS_NAS_ALL_PR470,
    SAS_NAS_ALL_PR128,SAS_NAS_ALL_PR70,SAS_NAS_ALL_PR1652,
    SAS_NAS_ALL_PR630_PR631,DS_NAS_FR_PR1650_PR1654,
    DS_NAS_FR_PR131,DS_NAS_FR_PR115,
    SAS_AS_FR063_FR071_FR074_FR076_FR101_FR102_FR110_FR111_FR112_FR115_FR117_FR118_FR463_FR464_FR499_FR500_FR657,
    DS_AS_FR073,DS_AS403_FR453 ]
    [/cover]                                                                 **/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* FR Driver header file structure. */

/* FR module interface file */
#include "Fr_17_Eray.h"

/* Register definition file for Aurix target */
#include "IfxEray_reg.h"
#include "IfxSrc_reg.h"


/*
  FR111: The Fr module source code file(s) shall include SchM_17_McalCfg.h if
  data consistency mechanisms of the BSW scheduler are required.
*/
#include "SchM_17_McalCfg.h"
#include SCHM_FR_17_ERAY_HEADER

/*******************************************************************************
** TRACEABILITY: [cover parentID=DS_NAS_FR_PR730]                             **
**                                                                            **
**               Imported Compiler Switch Check - Version check               **
**                                                                            **
**               [/cover]                                                     **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*
  FR031: The Fr module shall perform a consistency check between code files and
  header files based on pre-process-checking the version numbers of related
  code files and header files.
*/
#ifndef FR_17_ERAY_AR_RELEASE_MAJOR_VERSION
  #error "FR_17_ERAY_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef FR_17_ERAY_AR_RELEASE_MINOR_VERSION
  #error "FR_17_ERAY_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#ifndef FR_17_ERAY_SW_MAJOR_VERSION
  #error "FR_17_ERAY_SW_MAJOR_VERSION is not defined. "
#endif

#ifndef FR_17_ERAY_SW_MINOR_VERSION
  #error "FR_17_ERAY_SW_MINOR_VERSION is not defined. "
#endif

#ifndef FR_17_ERAY_SW_PATCH_VERSION
  #error "FR_17_ERAY_SW_PATCH_VERSION is not defined. "
#endif

#if ( FR_17_ERAY_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "FR_17_ERAY_AR_MAJOR_VERSION does not match. "
#endif

#if ( FR_17_ERAY_AR_RELEASE_MINOR_VERSION != 0U )
  #error "FR_17_ERAY_AR_MINOR_VERSION does not match. "
#endif

#if ( FR_17_ERAY_SW_MAJOR_VERSION != 2U )
  #error "FR_17_ERAY_SW_MAJOR_VERSION does not match. "
#endif

#if ( FR_17_ERAY_SW_MINOR_VERSION != 3U )
  #error "FR_17_ERAY_SW_MINOR_VERSION does not match. "
#endif


/*
  VERSION CHECK FOR DET MODULE INCLUSION
*/
#if ( FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)

#ifndef DET_AR_RELEASE_MAJOR_VERSION
  #error "DET_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DET_AR_RELEASE_MINOR_VERSION
  #error "DET_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if (IFX_DET_VERSION_CHECK == STD_ON)
#if ( DET_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DET_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DET_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DET_AR_RELEASE_MINOR_VERSION does not match. "
#endif

#endif /* #if (IFX_DET_VERSION_CHECK == STD_ON) */
#endif
/* End Of FR_17_ERAY_DEV_ERROR_DETECT */

#ifndef DEM_AR_RELEASE_MAJOR_VERSION
  #error "DEM_AR_RELEASE_MAJOR_VERSION is not defined. "
#endif

#ifndef DEM_AR_RELEASE_MINOR_VERSION
  #error "DEM_AR_RELEASE_MINOR_VERSION is not defined. "
#endif

#if (IFX_DEM_VERSION_CHECK == STD_ON)
#if ( DEM_AR_RELEASE_MAJOR_VERSION != 4U )
  #error "DEM_AR_RELEASE_MAJOR_VERSION does not match. "
#endif
#if ( DEM_AR_RELEASE_MINOR_VERSION != 0U )
  #error "DEM_AR_RELEASE_MINOR_VERSION does not match. "
#endif
#endif /* #if (IFX_DEM_VERSION_CHECK == STD_ON)  */

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* FlexRay Communication Host Interface commands */
#define FR_17_ERAY_CHI_CMD_NOT_ACCEPTED          (0x0U)
#define FR_17_ERAY_CHI_CMD_CONFIG                (0x1U)
#define FR_17_ERAY_CHI_CMD_READY                 (0x2U)
#define FR_17_ERAY_CHI_CMD_WAKEUP                (0x3U)
#define FR_17_ERAY_CHI_CMD_RUN                   (0x4U)
#define FR_17_ERAY_CHI_CMD_ALL_SLOTS             (0x5U)
#define FR_17_ERAY_CHI_CMD_HALT                  (0x6U)
#define FR_17_ERAY_CHI_CMD_FREEZE                (0x7U)
#define FR_17_ERAY_CHI_CMD_SEND_MTS              (0x8U)
#define FR_17_ERAY_CHI_CMD_ALLOW_COLDSTART       (0x9U)
#define FR_17_ERAY_CHI_CMD_CLEAR_RAMS            (0xCU)

/*----------------------------------------------------------------------------*/
            /*  Protocol Operation Control Status  */
/* Actual state of operation of the CC Protocol Operation Control */
#define FR_17_ERAY_POCS_DEFAULT_CONFIG  ((uint8)0x00)
#define FR_17_ERAY_POCS_READY           ((uint8)0x01)
#define FR_17_ERAY_POCS_NORMAL_ACTIVE   ((uint8)0x02)
#define FR_17_ERAY_POCS_NORMAL_PASSIVE  ((uint8)0x03)
#define FR_17_ERAY_POCS_HALT            ((uint8)0x04)
#define FR_17_ERAY_POCS_MONITOR_MODE    ((uint8)0x05)
#define FR_17_ERAY_POCS_CONFIG          ((uint8)0x0F)
/* Indicates the actual state of operation of the POC in the wakeup path */
#define FR_17_ERAY_POCS_WAKEUP_STANDBY  ((uint8)0x10)
#define FR_17_ERAY_POCS_WAKEUP_LISTEN   ((uint8)0x11)
#define FR_17_ERAY_POCS_WAKEUP_SEND     ((uint8)0x12)
#define FR_17_ERAY_POCS_WAKEUP_DETECT   ((uint8)0x13)
/* Actual state of operation of the POC in the startup path */
#define FR_17_ERAY_POCS_STARTUP_PREPARE                   ((uint8)0x20)
#define FR_17_ERAY_POCS_COLDSTART_LISTEN                  ((uint8)0x21)
#define FR_17_ERAY_POCS_COLDSTART_COLLISION_RESOLUTION    ((uint8)0x22)
#define FR_17_ERAY_POCS_COLDSTART_CONSISTENCY_CHECK       ((uint8)0x23)
#define FR_17_ERAY_POCS_COLDSTART_GAP                     ((uint8)0x24)
#define FR_17_ERAY_POCS_COLDSTART_JOIN                    ((uint8)0x25)
#define FR_17_ERAY_POCS_INTEGRATION_COLDSTART_CHECK       ((uint8)0x26)
#define FR_17_ERAY_POCS_INTEGRATION_LISTEN                ((uint8)0x27)
#define FR_17_ERAY_POCS_INTEGRATION_CONSISTENCY_CHECK     ((uint8)0x28)
#define FR_17_ERAY_POCS_INITIALIZE_SCHEDULE               ((uint8)0x29)
#define FR_17_ERAY_POCS_ABORT_STARTUP                     ((uint8)0x2A)
#define FR_17_ERAY_POCS_STARTUP_SUCCESS                   ((uint8)0x2B)

/*----------------------------------------------------------------------------*/
/* Magic numbers used for code coverage */
#ifdef IFX_ERAY_DEBUG
#define FR_17_ERAY_DEBUG_NUM_1                     (uint32)(0x01U)
#define FR_17_ERAY_DEBUG_NUM_2                     (uint32)(0x02U)
#define FR_17_ERAY_DEBUG_NUM_3                     (uint32)(0x03U)
#define FR_17_ERAY_DEBUG_NUM_4                     (uint32)(0x04U)
#define FR_17_ERAY_DEBUG_NUM_5                     (uint32)(0x05U)
#define FR_17_ERAY_DEBUG_NUM_6                     (uint32)(0x06U)
#define FR_17_ERAY_DEBUG_NUM_7                     (uint32)(0x07U)
#define FR_17_ERAY_DEBUG_NUM_8                     (uint32)(0x08U)
#define FR_17_ERAY_DEBUG_NUM_9                     (uint32)(0x09U)
#define FR_17_ERAY_DEBUG_NUM_10                    (uint32)(0x0AU)
#define FR_17_ERAY_DEBUG_NUM_11                    (uint32)(0x0BU)
#define FR_17_ERAY_DEBUG_NUM_12                    (uint32)(0x0CU)
#define FR_17_ERAY_DEBUG_NUM_13                    (uint32)(0x0DU)
#define FR_17_ERAY_DEBUG_NUM_14                    (uint32)(0x0EU)
#define FR_17_ERAY_DEBUG_NUM_15                    (uint32)(0x0FU)
#define FR_17_ERAY_DEBUG_NUM_16                    (uint32)(0x10U)
#define FR_17_ERAY_DEBUG_NUM_17                    (uint32)(0x11U)
#define FR_17_ERAY_DEBUG_NUM_18                    (uint32)(0x12U)
#define FR_17_ERAY_DEBUG_NUM_19                    (uint32)(0x13U)
#define FR_17_ERAY_DEBUG_GETPOCS                   ((uint32)0xFFFFFFFFU)
#endif
/*----------------------------------------------------------------------------*/
/* Magic numbers used for bit shift */
#define FR_17_ERAY_SHIFT_BIT_1                     ((uint32)0x01U)
#define FR_17_ERAY_SHIFT_BIT_2                     ((uint32)0x02U)
#define FR_17_ERAY_SHIFT_BIT_3                     ((uint32)0x03U)
#define FR_17_ERAY_SHIFT_BIT_4                     ((uint32)0x04U)
#define FR_17_ERAY_SHIFT_BIT_5                     ((uint32)0x05U)
#define FR_17_ERAY_SHIFT_BIT_6                     ((uint32)0x06U)
#define FR_17_ERAY_SHIFT_BIT_7                     ((uint32)0x07U)
#define FR_17_ERAY_SHIFT_BIT_8                     ((uint32)0x08U)
#define FR_17_ERAY_SHIFT_BIT_9                     ((uint32)0x09U)
#define FR_17_ERAY_SHIFT_BIT_10                    ((uint32)0x0AU)
#define FR_17_ERAY_SHIFT_BIT_11                    ((uint32)0x0BU)
#define FR_17_ERAY_SHIFT_BIT_12                    ((uint32)0x0CU)
#define FR_17_ERAY_SHIFT_BIT_13                    ((uint32)0x0DU)
#define FR_17_ERAY_SHIFT_BIT_14                    ((uint32)0x0EU)
#define FR_17_ERAY_SHIFT_BIT_15                    ((uint32)0x0FU)
#define FR_17_ERAY_SHIFT_BIT_16                    ((uint32)0x10U)
#define FR_17_ERAY_SHIFT_BIT_21                    ((uint32)0x15U)
#define FR_17_ERAY_SHIFT_BIT_24                    ((uint32)0x18U)
/*----------------------------------------------------------------------------*/


/* Maximum  LSDU Length */
#define FR_17_ERAY_MAX_LSDU_LENGTH  (64U)

/* Message buffer configuration values */
#define FR_17_ERAY_NO_DYNAMIC_MSG_BUFFERS     (0x80U)

/* Buffer reconfiguration related macros */
#define FR_17_ERAY_BUFFER_RECONFIG_LOCKED     (2U)
#define FR_17_ERAY_BUFFER_RECONFIG_ALLOWED    (0U)

/* Write values used in unlock sequence */
#define FR_17_ERAY_UNLOCK_SEQ1                (0xCEU)
#define FR_17_ERAY_UNLOCK_SEQ2                (0x31U)

/* Interrupt lines */
#define FR_17_ERAY_ILE_ENABLE_BOTH_LINES      (3U)
#define FR_17_ERAY_SILS_TIMER_LINES           (0x200U)

/* Mask for valid bits */
#define FR_17_ERAY_WRHS1_MASK                 (0x3F7F07FFU)
#define FR_17_ERAY_WRHS2_MASK                 (0x007F07FFU)
#define FR_17_ERAY_WRHS3_MASK                 (0x000007FFU)
#define FR_17_ERAY_FRF_MASK                   (0x01FF1FFFU)
#define FR_17_ERAY_SUCC1_MASK                 (0x0FFFFB8FU)
#define FR_17_ERAY_SUCC2_MASK                 (0x0F1FFFFFU)
#define FR_17_ERAY_SUCC3_MASK                 (0x000000FFU)
#define FR_17_ERAY_NEMC_MASK                  (0x0000000FU)
#define FR_17_ERAY_PRTC1_MASK                 (0xFDFFF7FFU)
#define FR_17_ERAY_PRTC2_MASK                 (0x3FFF3F3FU)
#define FR_17_ERAY_MHDC_MASK                  (0x1FFF007FU)
#define FR_17_ERAY_GTUC01_MASK                (0x000FFFFFU)
#define FR_17_ERAY_GTUC02_MASK                (0x000F3FFFU)
#define FR_17_ERAY_GTUC03_MASK                (0x7F7FFFFFU)
#define FR_17_ERAY_GTUC04_MASK                (0x3FFF3FFFU)
#define FR_17_ERAY_GTUC05_MASK                (0xFF1FFFFFU)
#define FR_17_ERAY_GTUC06_MASK                (0x07FF07FFU)
#define FR_17_ERAY_GTUC07_MASK                (0x03FF03FFU)
#define FR_17_ERAY_GTUC08_MASK                (0x1FFF003FU)
#define FR_17_ERAY_GTUC09_MASK                (0x00031F3FU)
#define FR_17_ERAY_GTUC10_MASK                (0x07FF3FFFU)
#define FR_17_ERAY_CLC_MASK                   (0x0000070BU)
#define FR_17_ERAY_IBCM_MASK                  (0x00070007U)
#define FR_17_ERAY_ACS_MASK                   (0x00001F1FU)

/* Mask for valid POCS bits in CCSV */
#define FR_17_ERAY_POCS_MASK                  (0x0000003FU)

/*
  Transfer only header section to MessageRAM
    ERAY_IBCM.B.LHSH  = 1 ;  (Bit 0)
    ERAY_IBCM.B.LDSH  = 0 ;  (Bit 1)
    ERAY_IBCM.B.STXRH = 0 ;  (Bit 2)

*/
#define FR_17_ERAY_TRANSFER_HEADER            (1U)

/*
  Transfer only data section to MessageRAM and set message buffer for tx
    ERAY_IBCM.B.LHSH  = 0 ;  (Bit 0)
    ERAY_IBCM.B.LDSH  = 1 ;  (Bit 1)
    ERAY_IBCM.B.STXRH = 1 ;  (Bit 2)
*/
#define FR_17_ERAY_TRANSFER_DATA              (6U)

/* Write Data Section nn */
/*#define FR_17_ERAY_WRITE_DATA_SECTION_START   (&ERAY_WRDS01)*/

/* Read Data Section nn */
/*#define FR_17_ERAY_READ_DATA_SECTION_START   (&ERAY_RDDS01)*/

#define FR_17_ERAY_TXRQ                       (&ERAY0_TXRQ1)
#define FR_17_ERAY_NDAT                       (&ERAY0_NDAT1)

#define FR_17_ERAY_LPDU_IDX_UNUSED (0xFFU)

/* Bit position of RMC bit field */
#define FR_17_ERAY_CLC_RMC_BIT_POS (8U)

/* Number of bytes per 16-bit word */
#define FR_17_ERAY_BYTES_PER_HALFWORD   (2U)

/* Number of bytes per 32-bit word */
#define FR_17_ERAY_BYTES_PER_WORD   (4U)

/* Index of last FlexRay communication cycle*/
#define FR_17_ERAY_MAX_CYCLE_INDEX  (63U)

/*
  K divider values for ERAY PLL
  Note:
  Only fOSC = 16Mhz, 20MHz and 24MHz are supported
             N
    fPLL = ----- * fOSC
            P*K
    P = 1 (always)

    fPLL = 40MHz step:
            ((29 + 1)/ (11+1)) * 16 = (30/3 * 4) = 40
            ((23 + 1)/ (11+1)) * 20 = (2 * 20)   = 40
            ((19 + 1)/ (11+1)) * 24 = (20 * 2)   = 40

    fPLL = 80MHz step:
            ((29 + 1)/ (5+1)) * 16  = (5  * 16) = 80
            ((23 + 1)/ (5+1)) * 20  = (4  * 20) = 80
            ((19 + 1)/ (5+1)) * 24  = (20 * 4 ) = 80
*/
#define FR_17_ERAY_PLLERAY_KDIV_40MHZ (11U)
#define FR_17_ERAY_PLLERAY_KDIV_80MHZ (5U)

/* Note: FR_17_ERAY_PLL_NDIV => Pre-compile config parameter */
#define FR_17_ERAY_PLLERAYCON0_NDIV_SET     ((uint32)FR_17_ERAY_PLL_NDIV << 9U)


#if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON)
/* Initialization vector of header */
#define FR_17_ERAY_HEADER_VECTOR_INITVAL      (0x1AU)
/* Flexray header CRC polynomial */
#define FR_17_ERAY_HEADER_CRC_POLYNOMINAL     (0x385U)
/* Number of bits for Header CRC Calculation */
#define FR_17_ERAY_NUM_BITS_FOR_HEADERCRC     (0x14U)
/* Slot ID bit position */
#define FR_17_ERAY_HEADER_FID_BITPOS          (0x07U)
/* Macro for MSB Mask */
#define FR_17_ERAY_MASK_MSB                   (0x80000000U)
/* Macro for 12U  */
#define FR_17_ERAY_NUM_12                     (0x0CU)
/* Macro for 21U  */
#define FR_17_ERAY_NUM_21                     (0x15U)
/* PLC Bit position  in WRHS2  */
#define FR_17_ERAY_BIT_POS_PLC                (0x10U)
#endif /* #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON) */

/* Timer related macros */
#define FR_17_ERAY_TIMER_CYCLECODE_SHIFT          (8U)
#define FR_17_ERAY_TIMER_MACROTICK_SHIFT          (16U)
#define FR_17_ERAY_TIMER_CYCLECODE_ONCE_IN_64     (0x40U)
#define FR_17_ERAY_TIMER_MODE_MASK                (2U)

#define FR_17_ERAY_SIR_TI0_MASK               ((uint32)1 << 8U)
#define FR_17_ERAY_SIR_TI1_MASK               ((uint32)1 << 9U)

#define FR_17_ERAY_SIER_TI0E_MASK             ((uint32)1 << 8U)
#define FR_17_ERAY_SIER_TI1E_MASK             ((uint32)1 << 9U)

#define FR_17_ERAY_SIES_TI0E_MASK             ((uint32)1 << 8U)
#define FR_17_ERAY_SIES_TI1E_MASK             ((uint32)1 << 9U)

/* Number of Startum Frames */
#define FR_17_ERAY_STARTUP_FRAMES           ((uint8)2U)

/* Channel Status related Macros*/
/* Channel A related macros */
#define FR_17_ERAY_A_STATUS_MASK            ((uint32)0x001FU)
#define FR_17_ERAY_A_SWNIT_VMTS_MASK        ((uint32)0x0040U)
#define FR_17_ERAY_A_SWNIT_STATUS_MASK      ((uint32)0x0003U)
#define FR_17_ERAY_A_NIT_STATUS_MASK        ((uint32)0x0300U)

/* Channel B related macros */
#define FR_17_ERAY_B_STATUS_MASK            ((uint32)0x1F00U)
#define FR_17_ERAY_B_SWNIT_VMTS_MASK        ((uint32)0x0080U)
#define FR_17_ERAY_B_SWNIT_STATUS_MASK      ((uint32)0x0018U)
#define FR_17_ERAY_B_NIT_STATUS_MASK        ((uint32)0x0C00U)

#define FR_17_ERAY_A_SWNIT_VMTS_SHIFT       ((uint32)6U)
#define FR_17_ERAY_A_NIT_STATUS_SHIFT       ((uint32)8U)

#define FR_17_ERAY_B_ACS_SHIFT              ((uint32)8U)
#define FR_17_ERAY_B_SWNIT_VMTS_SHIFT       ((uint32)7U)
#define FR_17_ERAY_B_SWNIT_STATUS_SHIFT     ((uint32)3U)
#define FR_17_ERAY_B_NIT_STATUS_SHIFT       ((uint32)10U)

#define FR_17_ERAY_SWNIT_VMTS_SHIFT         ((uint32)8U)
#define FR_17_ERAY_SWNIT_STATUS_SHIFT       ((uint32)9U)
#define FR_17_ERAY_NIT_STATUS_SHIFT         ((uint32)12U)

#define FR_17_ERAY_ACS_CHANNELA_MASK         (0x17U)
#define FR_17_ERAY_ACS_CHANNELA_VALID_BIT    (0x01U)

#define FR_17_ERAY_ACS_CHANNELB_MASK         (0x1700U)
#define FR_17_ERAY_ACS_CHANNELB_VALID_BIT    (0x0100U)

/* Cycle Repetition Macros: 1, 2, 4, 8, 16, 32, 64*/
#define FR_17_ERAY_CYCLE_REPETION_1         ((uint32)1U)
#define FR_17_ERAY_CYCLE_REPETION_2         ((uint32)2U)
#define FR_17_ERAY_CYCLE_REPETION_4         ((uint32)4U)
#define FR_17_ERAY_CYCLE_REPETION_8         ((uint32)8U)
#define FR_17_ERAY_CYCLE_REPETION_16        ((uint32)16U)
#define FR_17_ERAY_CYCLE_REPETION_32        ((uint32)32U)
#define FR_17_ERAY_CYCLE_REPETION_64        ((uint32)64U)

/*Max Valid configuration parameter Index*/
#define FR_17_ERAY_CONFIG_PARAM_IDX_MAX     ((uint32)63U)

/*Max Valid Header CRC in Fr_ReconfigLpdu API*/
#define FR_17_ERAY_HEADER_CRC_MAX           ((uint32)2047U)

/*Macro to define if register values is same as configuration */
#define   FR_17_ERAY_TEST_PASS                ((uint32)1U)
#define   FR_17_ERAY_TEST_FAIL                ((uint32)0U)

/* Message buffer configuration values */
#define FR_17_ERAY_NO_FIFO_MSG_BUFFERS        ((uint32)0x80U)

/*Symbolic FIFO Mesg Buffer ID to differentiate from other message Buff Ids*/
#define FR_17_ERAY_FIFO_MESG_BUF_ID           ((uint8)0xFFU)

/*Macro to reset Aggregated Channel status*/
#define FR_17_ERAY_ACS_RESET                  ((uint32)0x00001F1FU)

/*Macro to reset wakeup received indication status information */
#define FR_17_ERAY_SIR_RESET                  ((uint32)0x01010000U)

/* Limit Macro for Fr_ListSize in Fr_17_Eray_GetSyncFrameList */
#define FR_17_ERAY_MAX_LIST_SIZE              ((uint8)15U)

#define FR_17_ERAY_CUST1_MASK                 ((uint32)0xFC00U)

/* Shift Playload length Received by 1 to divide by 2*/
#define FR_17_ERAY_PLR_SHIFT                  ((uint32)1U)

/* MACRO for Hardware timeout */
#define FR_17_ERAY_MAX_TIMEOUT                ((uint32)0xFFFFFFFFU)

/* Macro to Mask Message Buffer ID */
#define FR_17_ERAY_MSG_BUFF_ID_MASK           ((uint32)0x1FU)

/*Macro for shift count of 5 */
#define FR_17_ERAY_MSG_BUFF_ID_SHIFT          ((uint8)5U)

/*Macro to use for Divide by 4 */
#define FR_17_ERAY_DIV_BY_4                   ((uint8)4U)

/*Mask Frame ID Macro to store in FIFO Rejection Filter Mask */
#define FR_17_ERAY_FRFM_MFID                   ((uint16)0U)

/* Number of samples per microtick,For ERay Spec 2.1 only N4SAMPLES is valid*/
#define N4SAMPLES                            (2U)

#if (FR_RESET_SFR_AT_INIT == STD_ON)
#define FR_KERNEL_RESET_TIMEOUT              ((uint32)0x35U)
#endif

/* Bit field positions of ERAY Service Request Control Register */
#define ERAY_SRC_CLRR                    (0x02000000U)
#define ERAY_SRC_MASK_NOCLEAR              (0x00000000U)

/* Exclusive area macros */
#define FR_17_ERAY_EA_CONTROLLERINIT        ((uint8)1)
#define FR_17_ERAY_EA_SETWAKEUPCHANNEL      ((uint8)2)

#define FR_17_ERAY_MOD_4                     (3U)
#define FR_17_ERAY_CLEAR_REG_FLAGS           ((uint32)0xFFFFFFFFU)
#define FR_17_ERAY_CLEAR_FLAGS               ((uint32)0x7F7F7FFFU)

#define ERAY_CONTROLLER_NOT_CONFIGURED       ((uint8)0xFFU)
#define DEC_ZERO                             ((uint8)0U)
#define DEC_ONE                              ((uint8)1U)

#define FR_INIT_API_ACCESS                   ((uint8)70U)
#define FR_RUNTIME_API_ACCESS                ((uint8)71U)

#define FR_NUM_FOUR                          4U
#define FR_NUM_EIGHT                         8U

/* Mask for valid bits */
#define FR_NVM_PIN_SHIFT_MASK             (0x000000FFU)

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define FR_NVM_BIT_SHIFT_COUNT(Pin)       (FR_NUM_EIGHT * \
                                              ((Pin) % (FR_NUM_FOUR)))

/*IFX_MISRA_RULE_19_07_STATUS=To support user modification of OS protected
  calls definition, it is declared as a function like macro*/
#define FR_PIN_NVM_SETMASK(Pin)           ((uint32)FR_NVM_PIN_SHIFT_MASK << \
                                               FR_NVM_BIT_SHIFT_COUNT(Pin))

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/* Memory Map of the FR Code */
#define FR_17_ERAY_START_SEC_CODE
#include "MemMap.h"

#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)

/*Function to check for invalid Timer id for ablsoule r relative timer */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidTimerIdx(
                        uint8 TimerIdx,uint8 ServiceId);
/*Function to check for the pointer is invalid */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidPointer(
                      const void * Ptr,uint8 ServiceId);
/*Function to check for invalid control index */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidCtrlIdx(uint8 CtrlIdx,
                                                              uint8 ServiceId);

/* Used by all APIs */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckNoInit
                                           (uint8 Fr_CtrlIdx,uint8 ServiceId);

/* FR_17_ERAY_E_INV_POCSTATE */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidPOCState(
            uint8 Fr_CtrlIdx,uint8 ExpectedState,uint8 ServiceId);

/* FR_17_ERAY_E_INV_LPDU_IDX: TransmitTxLPdu, ReceiveRxLPdu, CheckTxLPduStatus*/
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidLPduIdx
                                              (uint8 Fr_CtrlIdx,uint16 LPduIdx,
                                                              uint8 ServiceId);
IFX_LOCAL_INLINE  Std_ReturnType Fr_17_Eray_lReceiveDetCheck(
                                  uint8 Fr_CtrlIdx,
                                  uint16 Fr_LPduIdx,
                                  const uint8* Fr_LSduPtr,
                                  const Fr_RxLPduStatusType* Fr_LPduStatusPtr,
                                  const uint8* Fr_LSduLengthPtr
                                );

IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_lTransmitDetCheck(
          uint8 Fr_CtrlIdx,uint16 Fr_LPduIdx,const uint8* Fr_LSduPtr);

#endif /*#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */


#if(FR_17_ERAY_RX_STRINGENT_CHECK == STD_ON)

IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_RxStringentCheck(
                      uint8 Fr_CtrlIdx,uint8 ChannelIdx);
#endif

IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_SlotStatusErrorCheck
                                            (uint8 Fr_CtrlIdx,uint8 ChannelIdx);

IFX_LOCAL_INLINE uint32 Fr_17_Eray_lIsCCInSync(uint8 Fr_CtrlIdx);

/* Function to change POC state any state except READY */
static uint32 Fr_17_Eray_lChangePOCState(uint8 Fr_CtrlIdx,
                                uint8 ChiCmdId,uint8 ApiAccessId);

/* Function to wait for ERAY POC state change */
static uint32 Fr_17_Eray_lWaitTillPOCStateChange(
                      uint8 Fr_CtrlIdx,uint8 PocState,uint8 ApiAccessId);

/* Function to change POC state to READY */
static void Fr_17_Eray_lChangePOCStateToReady(
                  uint8 Fr_CtrlIdx,uint8 ExclusiveArea,uint8 ApiAccessId);

/* Transfer input buffer contents to message RAM buffer */
static uint32 Fr_17_Eray_lInputBufBsyHost(uint8 Fr_CtrlIdx,
                                                         uint8 ApiAccessId);

#if (FR_RESET_SFR_AT_INIT == STD_ON)
IFX_LOCAL_INLINE void Fr_17_Eray_lResetSFR(uint8 CtrlIdx);
#endif

#if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON)
/* Function to re calculate header CRC */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lHeaderCRC
(
  uint32 FrameId,
  uint8 PayloadLength
);
#endif  /* #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON) */

#if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
/*Function for Receive FIFO*/
IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_lReceiveRxFifo(uint8 Fr_CtrlIdx,
        uint8* Fr_LSduPtr,
              Fr_RxLPduStatusType* Fr_LPduStatusPtr, uint8* Fr_LSduLengthPtr );
#endif

/* Memory Map of the FR Code */
#define FR_17_ERAY_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
#define FR_17_ERAY_START_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
/* Fixed address feature enabled: Use constant config pointer */
static const Fr_17_Eray_ConfigType* const Fr_17_Eray_kConfigPtr =
                                                &Fr_17_Eray_ConfigRoot[0];
#endif

/* ERAY base address Kernel wise */
#if (FR_NUM_CONTROLLERS_IN_DEVICE == 1u)
static Ifx_ERAY* const ERAY[] = { &MODULE_ERAY0 };
/*IFX_MISRA_RULE_08_07_STATUS=SRC_FRTINT0 is accessed in
multiple functions*/
static volatile Ifx_SRC_SRCR* const SRC_FRTINT0[] = { &SRC_ERAYTINT0 };

#endif

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 2u)
static Ifx_ERAY* const ERAY[] = { &MODULE_ERAY0,&MODULE_ERAY1  };
static volatile Ifx_SRC_SRCR* const SRC_FRTINT0[] =
                                        { &SRC_ERAY0TINT0 , &SRC_ERAY1TINT0 };
#endif


#define FR_17_ERAY_STOP_SEC_CONST_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

#define FR_17_ERAY_START_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#if (FR_17_ERAY_PB_FIXEDADDR == STD_OFF)
/* To store the driver configuration pointer */
static const Fr_17_Eray_ConfigType* Fr_17_Eray_kConfigPtr;
#endif

/* Used for code coverage */
#ifdef IFX_ERAY_DEBUG
extern volatile uint32 TestFr_DebugMask;
extern volatile uint32 TestFr_DebugMaskIbsyh;
extern volatile uint32 TestFr_DebugMaskHostBusy;
extern volatile uint32 TestFr_DebugMaskReady;
extern volatile uint32 TestFr_DebugMaskChangeState;
extern volatile uint32 TestFr_DebugMaskWaitState;
extern volatile uint32 TestFr_DebugMaskNotReady;
extern volatile uint32 TestFr_DebugMaskRxfifo;
extern volatile uint32 TestFr_DebugMaskCCInit;
extern volatile uint32 TestFr_DebugMaskStringent;
extern volatile uint32 TestFr_DebugMaskSlotErr;
extern volatile uint32 TestFr_DebugMaskGetPocs;
extern volatile uint32 TestFr_DebugMaskPbsy;
extern volatile uint32 TestFr_DebugMaskDiss;
extern volatile uint32 TestFr_DebugMaskKRSTSTAT;
extern volatile uint8 TestFr_DebugMaskLogIdx;
#endif /* End of (IFX_ERAY_DEBUG) */

#define FR_17_ERAY_STOP_SEC_VAR_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

#define FR_17_ERAY_START_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* Message buffer index to LPDU index mapping */

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 2u)

#if (FR_17_ERAY_CONTROLLER0_CONFIGURED == STD_ON)
static uint8 Fr_17_Eray_MsgBuff2LPduIdx_0[FR_17_ERAY_MSG_BUFF_COUNT_MAX_0];
#endif

#if (FR_17_ERAY_CONTROLLER1_CONFIGURED == STD_ON)
static uint8 Fr_17_Eray_MsgBuff2LPduIdx_1[FR_17_ERAY_MSG_BUFF_COUNT_MAX_1];
#endif

#endif

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 1u)
#if (FR_17_ERAY_CONTROLLER0_CONFIGURED == STD_ON)
static uint8 Fr_17_Eray_MsgBuff2LPduIdx_0[FR_17_ERAY_MSG_BUFF_COUNT_MAX_0];
#endif
#endif


/*
  Number of message buffers required to be used
  Calculated by Fr_17_Eray_Init and used by Fr_17_Eray_ControllerInit
*/
static uint8 MsgBuffCount[FR_NUM_CONTROLLERS_IN_DEVICE];

#if (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
/*
  Fixed address feature enabled: Can not use Fr_17_Eray_kConfigPtr for DET
  check of driver initialization status because the config pointer is non-null
  always. Hence use a flag.
  Assumption: The flag is not initialized to 1 by start up code.
*/
/*IFX_MISRA_RULE_08_07_STATUS=Fr_17_Eray_DriverInitDone is accessed in
multiple functions*/
static uint8 Fr_17_Eray_DriverInitDone;
#endif

#define FR_17_ERAY_STOP_SEC_VAR_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"


#define FR_17_ERAY_START_SEC_VAR_INIT_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* Message buffer index to LPDU index mapping */

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 2u)
/*IFX_MISRA_RULE_08_07_STATUS=MsgBuffCountMax is not defined at the block scope
to have a generic code across devices*/
static uint8 MsgBuffCountMax[FR_NUM_CONTROLLERS_IN_DEVICE] =
  {FR_17_ERAY_MSG_BUFF_COUNT_MAX_0, FR_17_ERAY_MSG_BUFF_COUNT_MAX_1};
#endif

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 1u)
/*IFX_MISRA_RULE_08_07_STATUS=MsgBuffCountMax is not defined at the block scope
to have a generic code across devices*/
static uint8 MsgBuffCountMax[FR_NUM_CONTROLLERS_IN_DEVICE] =
  {FR_17_ERAY_MSG_BUFF_COUNT_MAX_0};
#endif

#define FR_17_ERAY_STOP_SEC_VAR_INIT_8BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"


#define FR_17_ERAY_START_SEC_VAR_INIT_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/* Message buffer index to LPDU index mapping */

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 2u)
static uint8 *MsgBuff2LPduIdxPtr[FR_NUM_CONTROLLERS_IN_DEVICE] =
{
 #if (FR_17_ERAY_CONTROLLER0_CONFIGURED == STD_ON)
 Fr_17_Eray_MsgBuff2LPduIdx_0,
 #else
 NULL_PTR,
 #endif
 #if (FR_17_ERAY_CONTROLLER1_CONFIGURED == STD_ON)
 Fr_17_Eray_MsgBuff2LPduIdx_1
 #else
 NULL_PTR
 #endif
};
#endif

#if (FR_NUM_CONTROLLERS_IN_DEVICE == 1u)
static uint8 *MsgBuff2LPduIdxPtr[FR_NUM_CONTROLLERS_IN_DEVICE] =
{
 #if (FR_17_ERAY_CONTROLLER0_CONFIGURED == STD_ON)
 Fr_17_Eray_MsgBuff2LPduIdx_0,
 #else
 NULL_PTR,
 #endif
};
#endif

#define FR_17_ERAY_STOP_SEC_VAR_INIT_32BIT
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Memory Map of the FR Code */
#define FR_17_ERAY_START_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR032_FR097,DS_AS_FR078_FR135_FR391]
** Traceability : [cover parentID=DS_AS_FR137,DS_NAS_HE2_FR_PR3018,
**                 DS_NAS_EP_FR_PR3018]                                       **
** Syntax : void Fr_17_Eray_Init( const Fr_17_Eray_ConfigType *Fr_ConfigPtr)  **
**                                                                            **
** [/cover]                                                                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID:  0x1c                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): Fr_ConfigPtr - Address to an Fr dependant configuration   **
**                                  structure that contains all information   **
**                                  for operating the Fr subsequently.        **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description : Initalizes the FR                                            **
**                                                                            **
*******************************************************************************/
void Fr_17_Eray_Init(const Fr_17_Eray_ConfigType* Fr_ConfigPtr)
{
 uint32 TmpMsgBuffCount ;
 uint32 MsgBuffIdx ;
 uint32 LPduIdx ;
 uint32 TimeOutCount;
 volatile uint32 ReadBack;
 uint8 ModuleClockDivider ;
 uint8 CtrlIdx;
 uint8 LogIdx;
 volatile uint8 CRamChk;
 volatile uint8 PbsyChk;
 volatile uint8 DissChk;
 uint8 LoopBreak;

#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
 uint32 DevError ;

 /* FR_17_ERAY_E_INV_POINTER */
 DevError = Fr_17_Eray_lDetCheckInvalidPointer(
  Fr_ConfigPtr, FR_17_ERAY_SID_INIT) ;

 /* Return if a development error occured */
 if (DevError == FR_17_ERAY_E_DET_NO_ERR)
 {
#endif
  LoopBreak = DEC_ZERO;

#if (FR_17_ERAY_PB_FIXEDADDR == STD_OFF)
  /*FR137: Store the configuration data address in a global variable to enable
  subsequent API calls to access the configuration data. */
  Fr_17_Eray_kConfigPtr = Fr_ConfigPtr ;
#else
  UNUSED_PARAMETER(Fr_ConfigPtr)
#endif

   for (CtrlIdx = DEC_ZERO; ((CtrlIdx < FR_NUM_CONTROLLERS_IN_DEVICE)&&
    (LoopBreak == DEC_ZERO)); CtrlIdx++)
   {
#ifdef IFX_ERAY_DEBUG
    LogIdx = TestFr_DebugMaskLogIdx;
#else
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
    PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[CtrlIdx];
#endif
#if (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
    /* Set flag to indicate driver is not initialized */
    Fr_17_Eray_DriverInitDone = DEC_ZERO ;
#endif
    if ((uint8)ERAY_CONTROLLER_NOT_CONFIGURED !=  LogIdx)
    {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
     PBConfigStructure and is within allowed range.*/
     ModuleClockDivider = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrClockDivider;

     /* Clear the ENDINIT bit in the WDT_CON0 register in order to disable the
     write-protection for registers protected via the EndInit feature */
     FR_SFR_INIT_RESETENDINIT();

     FR_SFR_INIT_WRITE32((ERAY[CtrlIdx]->CLC.U),\
      (unsigned_int)(((uint32)ModuleClockDivider << FR_17_ERAY_CLC_RMC_BIT_POS)\
                                                       & FR_17_ERAY_CLC_MASK));

     ReadBack = FR_SFR_INIT_READ32(ERAY[CtrlIdx]->CLC.U);

     /* Set the ENDINIT bit in the WDT_CON0 register again
     to enable the write-protection and to prevent a time-out */
     FR_SFR_INIT_SETENDINIT();

#ifdef IFX_ERAY_DEBUG
     DissChk = (uint8)(FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->CLC.U) & \
                           FR_CLC_DISS_SETMASK) |(uint8)(TestFr_DebugMaskDiss);
#else
     DissChk = (uint8)(FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->CLC.U) & \
                                                          FR_CLC_DISS_SETMASK);
#endif
     if (DEC_ZERO != DissChk )
     {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId
       != DEM_REPORT_DISABLED)
      {
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range.*/
       Dem_ReportErrorStatus( \
        Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId,
        DEM_EVENT_STATUS_FAILED);
      }
      LoopBreak = DEC_ONE;
     }
     else
     {

#if (FR_RESET_SFR_AT_INIT == STD_ON)
      /* Reset the Kernel registers to default value */
      Fr_17_Eray_lResetSFR(CtrlIdx);
#endif

      /* wait till the SUCC1.PBSY bit is cleared  */
      TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION;
      do
      {
       TimeOutCount-- ;
#ifdef IFX_ERAY_DEBUG
       PbsyChk =
            ((uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->SUCC1.U) & \
                         FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7) | \
                     (uint8)(TestFr_DebugMaskPbsy >> FR_17_ERAY_DEBUG_NUM_7));
#else
       PbsyChk =
         (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->SUCC1.U) & \
                            FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7);
#endif
      }while ((PbsyChk == 1U) && (TimeOutCount > 0U)) ;

      if (TimeOutCount == 0U)
      {
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
       PBConfigStructure and is within allowed range.*/
       if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId
        != DEM_REPORT_DISABLED)
       {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        Dem_ReportErrorStatus( \
         Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId,
         DEM_EVENT_STATUS_FAILED);
       }
       LoopBreak = DEC_ONE;

      }
      else
      {
       /* CLEAR_RAMS */
       FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[CtrlIdx]->SUCC1.U), \
                       FR_SUCC1_CMD_CLEARMASK, FR_17_ERAY_CHI_CMD_CLEAR_RAMS)

       /* wait till execution of the CHI command CLEAR_RAMS is complete */
       TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION;

       do
       {
        TimeOutCount-- ;
#ifdef IFX_ERAY_DEBUG
        CRamChk = (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->MHDS.U) \
                        & FR_MHDS_CRAM_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7) | \
                          (uint8)(TestFr_DebugMask >> FR_17_ERAY_DEBUG_NUM_7);
#else
        CRamChk = (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->MHDS.U)\
                            & FR_MHDS_CRAM_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7);
#endif
       } while ((CRamChk==1U) && (TimeOutCount > 0U)) ;
       if (TimeOutCount == 0U)
       {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
         DEM_REPORT_DISABLED)
        {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         Dem_ReportErrorStatus( \
          Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId,
          DEM_EVENT_STATUS_FAILED);
        }
        LoopBreak = DEC_ONE;
       }
       else
       {
        /* ------------------------------------------------------------------ */
        /* Construct global array Fr_17_Eray_MsgBuff2LPduIdx[ ] */

        /* Initialize array Fr_17_Eray_MsgBuff2LPduIdx[ ] with unused LPDU index
        values */
        for(MsgBuffIdx = 0U;MsgBuffIdx < MsgBuffCountMax[CtrlIdx];MsgBuffIdx++)
        {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         MsgBuff2LPduIdxPtr[CtrlIdx][MsgBuffIdx] = FR_17_ERAY_LPDU_IDX_UNUSED ;
        }

        TmpMsgBuffCount = 0U ;

        /* Construct array Fr_17_Eray_MsgBuff2LPduIdx[ ] */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        for (LPduIdx = 0U; LPduIdx <
         Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduCount; LPduIdx++)
        {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[LPduIdx]
         != FR_17_ERAY_LPDU_IDX_UNUSED)
         {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
          if (MsgBuff2LPduIdxPtr[CtrlIdx][Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].
           LPduIdx2MsgBuffIdxPtr[LPduIdx]] == FR_17_ERAY_LPDU_IDX_UNUSED)
          {
           /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
           PBConfigStructure and is within allowed range.*/
           /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
           PBConfigStructure and is within allowed range.*/
           /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
           PBConfigStructure and is within allowed range.*/
           MsgBuff2LPduIdxPtr[CtrlIdx][Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].\
            LPduIdx2MsgBuffIdxPtr[LPduIdx]] = (uint8)LPduIdx;
           TmpMsgBuffCount++ ;
          }
         }
        }

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        if(TmpMsgBuffCount < Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduCount)
        {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         for (LPduIdx = 0U; LPduIdx <
          Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduCount; LPduIdx++)
         {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
          if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].
           LPduIdx2MsgBuffIdxPtr[LPduIdx] == FR_17_ERAY_LPDU_IDX_UNUSED)
          {
           /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
           PBConfigStructure and is within allowed range.*/
           MsgBuff2LPduIdxPtr[CtrlIdx][TmpMsgBuffCount] = (uint8)LPduIdx ;
           TmpMsgBuffCount++ ;
          }
         }
        }
        /* Write to global variable */
        MsgBuffCount[CtrlIdx] = (uint8) TmpMsgBuffCount ;

        /* ------------------------------------------------------------------ */
#if (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
        /* Set flag to indicate driver is initialized */
        Fr_17_Eray_DriverInitDone = DEC_ONE ;
#endif
       }
      }
     }
     UNUSED_PARAMETER(ReadBack)
    }
   }
#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
 }
#endif

}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS40X_FR017,
DS_AS40X_FR147_FR478_1_FR498_FR512_FR515,
DS_AS_FR097_FR103_FR127_FR143_FR144_FR148,
DS_AS_FR149_FR150_FR151_FR152_FR153_FR390_FR438_FR494_FR598_FR647]
** ** [/cover]                                                                **
** Syntax : Std_ReturnType Fr_17_Eray_ControllerInit (uint8 Fr_CtrlIdx)       **
**                                                                            **
** Service ID:  0x00                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in):                                                           **
**       Fr_CtrlIdx         - Index of FlexRay CC within the context of       **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Initializes a FlexRay CC.                                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_ControllerInit(uint8 Fr_CtrlIdx)
{
  uint32 MsgBuffIdx ;
  uint32 ErrorCount ;
  uint8 LpduId;
  volatile uint8 i;
  uint32 CtrlTest;
  Std_ReturnType RetValue ;
  uint8 LastConfiguredBuffer;
  const Fr_17_Eray_LPduConfigType *LPduCfgPtr ;
  const Fr_17_Eray_CCConfigType *CCConfigPtr;
  uint8 GoToReady;
  uint8 LogIdx;

  #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
  uint8 FifoFFB;
  #endif

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError;
  #endif

  ErrorCount = 0U ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  RetValue = E_OK;
  /*  FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                   (Fr_CtrlIdx,FR_17_ERAY_SID_CONTROLLERINIT) ;

  if(DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*  FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(
                                   Fr_CtrlIdx, FR_17_ERAY_SID_CONTROLLERINIT);
  }

  if(DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }
  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Clear all the FLags */
    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->EIR.U), \
                                                FR_17_ERAY_CLEAR_REG_EIR_FLAGS);
    /* Clear Error Int. */
    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIR.U), \
                                                FR_17_ERAY_CLEAR_REG_SIR_FLAGS);
    /* Clear Status Int.*/
    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->EIER.U), \
                                               FR_17_ERAY_CLEAR_REG_EIER_FLAGS);
    /* Disable all Error Int.  */
    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIER.U), \
                                               FR_17_ERAY_CLEAR_REG_SIER_FLAGS);
    /* Disable all Status Int. */
    /* Switch CC into 'POC:config' (from any other POCState). */
    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->MHDS.U), \
                                                        FR_17_ERAY_CLEAR_FLAGS);
    /* Disable message handler Status.*/

    /* Switch CC into 'POC:config' (from any other POCState). */
    if ((FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U) & \
                               FR_CCSV_POCS_SETMASK) != FR_17_ERAY_POCS_CONFIG)
    {
      /* Any state to HALT state */
      ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                              FR_17_ERAY_CHI_CMD_FREEZE,FR_INIT_API_ACCESS);

      ErrorCount += Fr_17_Eray_lWaitTillPOCStateChange(Fr_CtrlIdx,
                                   FR_17_ERAY_POCS_HALT,FR_INIT_API_ACCESS);

      /* Halt to default config */
      ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                              FR_17_ERAY_CHI_CMD_CONFIG,FR_INIT_API_ACCESS);

      ErrorCount += Fr_17_Eray_lWaitTillPOCStateChange(Fr_CtrlIdx,
                         FR_17_ERAY_POCS_DEFAULT_CONFIG,FR_INIT_API_ACCESS);

      /* default config to config */
      ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                              FR_17_ERAY_CHI_CMD_CONFIG,FR_INIT_API_ACCESS);

      ErrorCount += Fr_17_Eray_lWaitTillPOCStateChange(Fr_CtrlIdx,
                                 FR_17_ERAY_POCS_CONFIG,FR_INIT_API_ACCESS);

      if (ErrorCount != 0U)
      {
      /* Command not accepted or POC state change did not happen --> Time out-->
          Production error */
        RetValue = E_NOT_OK;
      }
      else
      {
        RetValue = E_OK;
      }

    }
    else
    {
      RetValue = E_OK;
    }
  }
/*------------------------  MRC Register configuration  ----------------------*/

  if(RetValue == E_OK)
  {
    /*
      Enable both interrupt lines.
      Line 0 is used for absolute timer interrupts
    */

    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->ILE.U), \
                                            FR_17_ERAY_ILE_ENABLE_BOTH_LINES);

    FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SILS.U), \
                                                  FR_17_ERAY_SILS_TIMER_LINES);

    /*
      First Dynamic Buffer configuration.
      Its value is hard coded to 0, meaning no group of Message Buffers
      exclusively for the static segment configured.

      Its configuration doesn't have significance w.r.t AUTOSAR requirements.
      FDB is used to disable transmission of message Buffers for static
      segment with numbers >= FDB when MRC.SEC = 1 or 3.
      AUTOSAR requirements do not require MRC.SEC to be 1 or 3.
    */
    FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->MRC.U), \
                                                     FR_MRC_FDB_CLEARMASK, 0U)

    /*  Last Configured Buffer
      01H..7FH: Number of Message Buffers is LCB + 1
      80H..FFH: No Message Buffer configured
     */
    LastConfiguredBuffer = MsgBuffCount[Fr_CtrlIdx] - 1U;
    FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->MRC.U), \
                FR_MRC_LCB_CLEARMASK, ((uint32)LastConfiguredBuffer \
                                                 << FR_17_ERAY_SHIFT_BIT_16))
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /*
      Check if Fifo is configured
    */
  #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
  {

      /*  First Buffer of FIFO
      00H..7EH: Message Buffers from FFB to LCB assigned to the FIFO
      7FH: All Message Buffers assigned to the FIFO
     */
      /*(Total number of message buffers - FrFifoDepth)*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FifoFFB = MsgBuffCount[Fr_CtrlIdx] -
             Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].RxFifoConfigPtr->FrFifoDepth;
      /*(Total number of message buffers - FrFifoDepth)*/
      FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->MRC.U), \
            FR_MRC_FFB_CLEARMASK, ((uint32)FifoFFB << FR_17_ERAY_SHIFT_BIT_8))

      /* Configure Fifo Rejection Filter Register based on configuration */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->FRF.U),(unsigned_int)\
       (Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].RxFifoConfigPtr->FrFifoFrfCfg)\
                                                      & FR_17_ERAY_FRF_MASK);

      /* Configure FRFM.MFID */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->FRFM.U), \
         FR_FRFM_MFID_CLEARMASK, ((uint32)Fr_17_Eray_kConfigPtr->CfgPtr \
              [LogIdx].RxFifoConfigPtr->FrFifoFrfm << FR_17_ERAY_SHIFT_BIT_2))

      /* Configure the Critical level */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->FCL.U), \
            FR_FCL_CL_CLEARMASK, \
            Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].RxFifoConfigPtr->FrFifoDepth)

  }
  #else
   {
    /*
      First Buffer of FIFO
      FIFO is not supported by the driver. No message buffers assigned to
      the FIFO, if FFB >= 128
    */
      FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->MRC.U), \
          FR_MRC_FFB_CLEARMASK,(uint32)(FR_17_ERAY_NO_FIFO_MSG_BUFFERS \
                                                  << FR_17_ERAY_SHIFT_BIT_8))
    }
  #endif
        /*#if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)*/

    /* Secure Buffers configuration */
    #if (FR_17_ERAY_RECONFIG_BUFFER == STD_ON)
    FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->MRC.U), \
       FR_MRC_SEC_CLEARMASK, ((uint32)FR_17_ERAY_BUFFER_RECONFIG_ALLOWED \
                                                   << FR_17_ERAY_SHIFT_BIT_24))
    #else
    FR_SFR_INIT_USER_MODE_MODIFY32(ERAY[Fr_CtrlIdx]->MRC.U), \
             FR_MRC_SEC_CLEARMASK, (FR_17_ERAY_BUFFER_RECONFIG_LOCKED \
                                                   << FR_17_ERAY_SHIFT_BIT_24))
    #endif

    /*
    Note:
      MRC.SPLM = 0 (Reset value; It is left untouched).
      Only Message Buffer 0 locked against reconfiguration.
      As per AUTOSAR, atmost one slot id is used for SYNC frame transmission
      (Multiplicity of PKeySlotId is 0..1)

      This bit is only evaluated if the node is configured as sync node
      (SUCC1.TXSY = 1) or for single slot mode operation
      (SUCC1.TSM = 1).

      Hence,
      - the msg buf 0 CAN be shared among LPDUs if PKeySlotUsedForSync = false
      - the msg buf 0 CANNOT be shared among LPDUs if PKeySlotUsedForSync = true

    */

    /* -----------------------------------------------------------------------*/
    /*                    Configure message buffers                           */

    for(MsgBuffIdx = 0U; MsgBuffIdx < MsgBuffCount[Fr_CtrlIdx] ; MsgBuffIdx++)
    {
      /*  Check if input buffer is busy with another transfer
          a. Wait until it becomes free or a time out happens
          b. If time out happens, report to DEM     */
      ErrorCount += Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,FR_INIT_API_ACCESS);

      if (ErrorCount != 0U)
      {
      /* Command not accepted or POC state change did not happen --> Time out-->
         Production error */
        RetValue = E_NOT_OK;
        break;
      }
      else
      {
        RetValue = E_OK;
      }


      /* Write header section values into input buffer */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS2.U), \
      (unsigned_int)(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)\
      [MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx]].WRHS2.U\
      & FR_17_ERAY_WRHS2_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS1.U), \
      (unsigned_int)(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)\
                      [MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx]].WRHS1.U\
                                                      & FR_17_ERAY_WRHS1_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS3.U),(unsigned_int)\
        Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].DataPointerOffsetPtr[MsgBuffIdx]\
                                                      & FR_17_ERAY_WRHS3_MASK);

      /* Select header section for writing into message buffer */
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U), \
                         (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

      /* Start the buffer transfer */
      FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                   FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

      /*  Check if input buffer is busy with another transfer
          a. Wait until it becomes free or a time out happens
          b. If time out happens, report to DEM     */
      ErrorCount += Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,FR_INIT_API_ACCESS);


    }

  /*----- Disable all LPdus which are dynamically reconfigurable ---------*/

    if(RetValue == E_OK)
    {
      /* Store the LPDU configuration */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr ;

      /* Check if Lpdu is dynamically reconfigurable */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      for (LpduId=0U; LpduId <
                     Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduCount; LpduId++)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        if (LPduCfgPtr[LpduId].LpduReconfigurable == FR_LPDU_RECONFIGURABLE)
        {
          /* Figure out the message buffer corresponding to LPduIdx */
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
          MsgBuffIdx =
          Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[LpduId];

          /* Set Channel Filter Control A and Channel Filter Control B bits to
        zero,to stop transmission and receive buffer will ignore frames */
          FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->WRHS1.U), \
                                                   FR_WRHS1_CHA_CLEARMASK, 0U)
          FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->WRHS1.U), \
                                                   FR_WRHS1_CHB_CLEARMASK, 0U)

          /* Select header section for writing into message buffer */
          FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U),
                          (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

          /* Start the buffer transfer */
          FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                  FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

         /*  Check if input buffer is busy with another transfer
             a. Wait until it becomes free or a time out happens
             b. If time out happens, report to DEM     */
         ErrorCount += Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                         FR_INIT_API_ACCESS);
         }
       }
    /*----------------- Communication controller Configuration ---------------*/

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SUCC1.U),\
          (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->SUCC1.U\
                                        & FR_17_ERAY_SUCC1_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SUCC2.U),\
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->SUCC2.U\
                                              & FR_17_ERAY_SUCC2_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SUCC3.U),\
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->SUCC3.U\
                                              & FR_17_ERAY_SUCC3_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->NEMC.U), \
          (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->NEMC.U\
                                                & FR_17_ERAY_NEMC_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->PRTC1.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->PRTC1.U\
                                             & FR_17_ERAY_PRTC1_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->PRTC2.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->PRTC2.U\
                                              & FR_17_ERAY_PRTC2_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->MHDC.U), \
          (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->MHDC.U\
                                             & FR_17_ERAY_MHDC_MASK);

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC01.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC01.U\
                                            & FR_17_ERAY_GTUC01_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC02.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC02.U\
                                                     & FR_17_ERAY_GTUC02_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC03.U), \
        (unsigned_int) Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC03.U\
                                       & FR_17_ERAY_GTUC03_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC04.U), \
        (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC04.U\
                                             & FR_17_ERAY_GTUC04_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC05.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC05.U\
                                              & FR_17_ERAY_GTUC05_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC06.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC06.U\
                                             & FR_17_ERAY_GTUC06_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC07.U), \
        (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC07.U \
                                            & FR_17_ERAY_GTUC07_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC08.U), \
        (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC08.U\
                                           & FR_17_ERAY_GTUC08_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC09.U), \
        (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC09.U \
                                             & FR_17_ERAY_GTUC09_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC10.U), \
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC10.U\
                                                     & FR_17_ERAY_GTUC10_MASK);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->GTUC11.U), \
                 Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->GTUC11.U);
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      FR_SFR_INIT_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->CUST1.U), \
                Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->CUST1.U);


    /*---------------------- CC Test ----------------------------*/

      /* The CC test to check if node and cluster FlexRay parameters
         were written properly into the FlexRay CC */

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        CCConfigPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr;

        #if(FR_17_ERAY_CTRL_TEST_COUNT != 0U)
          /* Initialize the variable */
          CtrlTest = FR_17_ERAY_TEST_PASS;
          for (i=0U; i < FR_17_ERAY_CTRL_TEST_COUNT ; i++)
          {
            #ifdef IFX_ERAY_DEBUG
            if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_1)
                  CtrlTest =0U;
            else
                  CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->SUCC1.U);
            #else
            CtrlTest =FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->SUCC1.U);
            #endif
            if (CtrlTest == CCConfigPtr->SUCC1.U)
            {
              #ifdef IFX_ERAY_DEBUG
              if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_2)
                  CtrlTest =0U;
              else
                  CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->SUCC2.U);
              #else
              CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->SUCC2.U);
              #endif
              if (CtrlTest == CCConfigPtr->SUCC2.U)
              {
                #ifdef IFX_ERAY_DEBUG
                if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_3)
                  CtrlTest =0U;
                else
                  CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->SUCC3.U);
                #else
                CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->SUCC3.U);
                #endif
                if (CtrlTest == CCConfigPtr->SUCC3.U)
                {
                  #ifdef IFX_ERAY_DEBUG
                  if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_4)
                    CtrlTest =0U;
                  else
                    CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                     (ERAY[Fr_CtrlIdx]->NEMC.U);
                  #else
                  CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                     (ERAY[Fr_CtrlIdx]->NEMC.U);
                  #endif
                  if (CtrlTest == CCConfigPtr->NEMC.U)
                  {
                    #ifdef IFX_ERAY_DEBUG
                    if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_5)
                      CtrlTest =0U;
                    else
                      CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->PRTC1.U);
                    #else
                    CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->PRTC1.U);
                    #endif
                    if (CtrlTest == CCConfigPtr->PRTC1.U)
                    {
                      #ifdef IFX_ERAY_DEBUG
                      if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_6)
                        CtrlTest =0U;
                      else
                        CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->PRTC2.U);
                      #else
                      CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->PRTC2.U);
                      #endif
                      if (CtrlTest == CCConfigPtr->PRTC2.U)
                      {
                        #ifdef IFX_ERAY_DEBUG
                        if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_7)
                          CtrlTest =0U;
                        else
                          CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->MHDC.U);
                        #else
                        CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                     (ERAY[Fr_CtrlIdx]->MHDC.U);
                        #endif
                        if (CtrlTest == CCConfigPtr->MHDC.U)
                        {
                          #ifdef IFX_ERAY_DEBUG
                          if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_8)
                            CtrlTest =0U;
                          else
                            CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC01.U);
                          #else
                          CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC01.U);
                          #endif
                          if (CtrlTest == CCConfigPtr->GTUC01.U)
                          {
                           #ifdef IFX_ERAY_DEBUG
                           if (TestFr_DebugMaskCCInit == FR_17_ERAY_DEBUG_NUM_9)
                              CtrlTest =0U;
                            else
                              CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC02.U);
                            #else
                            CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC02.U);
                            #endif
                            if (CtrlTest == CCConfigPtr->GTUC02.U)
                            {
                              #ifdef IFX_ERAY_DEBUG
                              if (TestFr_DebugMaskCCInit ==
                                        FR_17_ERAY_DEBUG_NUM_10)
                                CtrlTest =0U;
                              else
                                CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC03.U);
                              #else
                              CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC03.U);
                              #endif
                              if (CtrlTest == CCConfigPtr->GTUC03.U)
                              {
                                #ifdef IFX_ERAY_DEBUG
                                if (TestFr_DebugMaskCCInit
                                    == FR_17_ERAY_DEBUG_NUM_11)
                                  CtrlTest =0U;
                                else
                                  CtrlTest =FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC04.U);
                                #else
                                CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC04.U);
                                #endif
                                if (CtrlTest == CCConfigPtr->GTUC04.U)
                                {
                                  #ifdef IFX_ERAY_DEBUG
                                  if (TestFr_DebugMaskCCInit ==
                                            FR_17_ERAY_DEBUG_NUM_12)
                                    CtrlTest =0U;
                                  else
                                    CtrlTest =FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC05.U);
                                  #else
                                  CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC05.U);
                                  #endif
                                  if (CtrlTest == CCConfigPtr->GTUC05.U)
                                  {
                                    #ifdef IFX_ERAY_DEBUG
                                    if (TestFr_DebugMaskCCInit ==
                                                    FR_17_ERAY_DEBUG_NUM_13)
                                      CtrlTest =0U;
                                    else
                                      CtrlTest =FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC06.U);
                                    #else
                                    CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC06.U);
                                    #endif
                                    if (CtrlTest == CCConfigPtr->GTUC06.U)
                                    {
                                      #ifdef IFX_ERAY_DEBUG
                                      if (TestFr_DebugMaskCCInit ==
                                        FR_17_ERAY_DEBUG_NUM_14)
                                        CtrlTest =0U;
                                      else
                                        CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC07.U);
                                      #else
                                      CtrlTest = FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC07.U);
                                      #endif
                                      if (CtrlTest == CCConfigPtr->GTUC07.U)
                                      {
                                        #ifdef IFX_ERAY_DEBUG
                                        if (TestFr_DebugMaskCCInit ==
                                          FR_17_ERAY_DEBUG_NUM_15)
                                          CtrlTest =0U;
                                        else
                                          CtrlTest =
                                              FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC08.U);
                                        #else
                                        CtrlTest =
                                            FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC08.U);
                                        #endif
                                        if (CtrlTest == CCConfigPtr->GTUC08.U)
                                        {
                                          #ifdef IFX_ERAY_DEBUG
                                          if (TestFr_DebugMaskCCInit ==
                                            FR_17_ERAY_DEBUG_NUM_16)
                                            CtrlTest =0U;
                                          else
                                            CtrlTest =
                                              FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC09.U);
                                          #else
                                          CtrlTest =
                                              FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC09.U);
                                          #endif
                                          if (CtrlTest == CCConfigPtr->GTUC09.U)
                                          {
                                            #ifdef IFX_ERAY_DEBUG
                                            if (TestFr_DebugMaskCCInit ==
                                              FR_17_ERAY_DEBUG_NUM_17)
                                              CtrlTest =0U;
                                            else
                                              CtrlTest =
                                                FR_SFR_INIT_USER_MODE_READ32\
                                                  (ERAY[Fr_CtrlIdx]->GTUC10.U);
                                            #else
                                            CtrlTest =
                                              FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC10.U);
                                            #endif
                                            if(CtrlTest ==CCConfigPtr->GTUC10.U)
                                            {
                                              #ifdef IFX_ERAY_DEBUG
                                              if (TestFr_DebugMaskCCInit ==
                                                FR_17_ERAY_DEBUG_NUM_18)
                                                CtrlTest =1U;
                                              else
                                                CtrlTest =
                                                FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC11.U);
                                              #else
                                              CtrlTest =
                                              FR_SFR_INIT_USER_MODE_READ32\
                                                   (ERAY[Fr_CtrlIdx]->GTUC11.U);
                                              #endif
                                              if (CtrlTest ==
                                                   CCConfigPtr->GTUC11.U)
                                              {
                                             #ifdef IFX_ERAY_DEBUG
                                             if (TestFr_DebugMaskCCInit ==
                                              FR_17_ERAY_DEBUG_NUM_19)
                                               CtrlTest =0U;
                                             else
                                               CtrlTest =
                                                (FR_SFR_INIT_USER_MODE_READ32\
                                                (ERAY[Fr_CtrlIdx]->CUST1.U) & \
                                                       FR_17_ERAY_CUST1_MASK);
                                             #else
                                             CtrlTest =
                                                 (FR_SFR_INIT_USER_MODE_READ32\
                                                 (ERAY[Fr_CtrlIdx]->CUST1.U) & \
                                                      FR_17_ERAY_CUST1_MASK);
                                                #endif
                                              }
                                            if(CtrlTest == CCConfigPtr->CUST1.U)
                                            {
                                              CtrlTest = FR_17_ERAY_TEST_PASS;
                                            }
                                           }

                                          }

                                        }

                                      }

                                    }

                                  }

                                }

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

              }

            }

            /* Check If the CC test is passed within FrCtrlTestCount */
            if (CtrlTest == FR_17_ERAY_TEST_PASS)
            {
              break;
            }
          }

          if (CtrlTest == FR_17_ERAY_TEST_PASS)
          {
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
            if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemCtrlTestResultId !=
                                                         DEM_REPORT_DISABLED)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
              Dem_ReportErrorStatus( \
                   Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemCtrlTestResultId,
                                    DEM_EVENT_STATUS_PASSED);
            }
          }
          else
          {
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
            if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemCtrlTestResultId !=
                                                          DEM_REPORT_DISABLED)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
              Dem_ReportErrorStatus( \
                  Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemCtrlTestResultId,
                                    DEM_EVENT_STATUS_FAILED);
            }
            RetValue = E_NOT_OK;
          }
        #endif

    /*------------------------------------------------------------------------*/

      if(RetValue == E_OK)
      {

        /*
          Switch the CC to POC:Ready state.
        */
        Fr_17_Eray_lChangePOCStateToReady(Fr_CtrlIdx,
                            FR_17_ERAY_EA_CONTROLLERINIT,FR_INIT_API_ACCESS);
        #ifdef IFX_ERAY_DEBUG
        GoToReady = (FR_17_ERAY_POCS_READY|((uint8)(TestFr_DebugMaskNotReady>> \
                                                     FR_17_ERAY_SHIFT_BIT_1)));
        #else
        GoToReady = FR_17_ERAY_POCS_READY;
        #endif
        ErrorCount += Fr_17_Eray_lWaitTillPOCStateChange(Fr_CtrlIdx,GoToReady,
                                                          FR_INIT_API_ACCESS);

        if (ErrorCount != 0U)
        {
          /* Command not accepted or POC state change did not happen->Time out->
              Production error */
          RetValue = E_NOT_OK ;
        }
      }
    }
  }
  return RetValue ;
}
/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR010_FR125_FR173_FR174_FR175_FR177_FR438_FR490_FR494,
DS_AS40X_FR477_FR478_2]
** Syntax : Std_ReturnType Fr_17_Eray_StartCommunication(uint8 Fr_CtrlIdx)    **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x03                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non re-entrant for the same device                            **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Starts communication.                                        **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_StartCommunication( uint8 Fr_CtrlIdx )
{
  uint32 ErrorCount ;
  Std_ReturnType RetValue;


  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;

  RetValue = E_OK;

  /*  FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                        FR_17_ERAY_SID_STARTCOMMUNICATION) ;

  if(DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                            FR_17_ERAY_SID_STARTCOMMUNICATION);
  }
  /* Driver is not initialized, avoid register access */
  if(DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*  FR_17_ERAY_E_INV_POCSTATE */
    DevError = Fr_17_Eray_lDetCheckInvalidPOCState(Fr_CtrlIdx,
                      FR_17_ERAY_POCS_READY, FR_17_ERAY_SID_STARTCOMMUNICATION);
  }



  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = 0U ;

    /*
      Invoke the CC CHI command RUN, which initiates the startup procedure
      within the FlexRay CC.
    */
    ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,FR_17_ERAY_CHI_CMD_RUN,
                                                       FR_RUNTIME_API_ACCESS);

    if (ErrorCount == 0U)
    {
      RetValue = E_OK ;
    }
    else
    {
      /* Command not accepted --> Time out --> Production error */
      RetValue = E_NOT_OK;
    }
  }
  return RetValue;
}

/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR114_FR178_FR179_FR494_FR180_FR182_FR495]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_AllowColdstart(uint8 Fr_CtrlIdx)        **
**                                                                            **
** [/cover]

** Service ID:  0x23                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Invokes the CC CHI command 'ALLOW_COLDSTART'.                **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_AllowColdstart( uint8 Fr_CtrlIdx )
{
  uint32 ErrorCount ;
  Std_ReturnType RetValue ;


  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  uint32 TmpReg32 ;

  RetValue = E_OK ;

  /*  FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                   (Fr_CtrlIdx,FR_17_ERAY_SID_ALLOWCOLDSTART) ;

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*  FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                FR_17_ERAY_SID_ALLOWCOLDSTART);
  }
  /* Driver is not initialized, avoid register access */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    TmpReg32 =
         (uint32)(FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U) & \
                                                         FR_CCSV_POCS_SETMASK) ;
    /*  FR_17_ERAY_E_INV_POCSTATE */
    if (( TmpReg32 == FR_17_ERAY_POCS_DEFAULT_CONFIG) ||
           (TmpReg32 == FR_17_ERAY_POCS_CONFIG) ||
           (TmpReg32 == FR_17_ERAY_POCS_HALT)
       )
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                      FR_17_ERAY_SID_ALLOWCOLDSTART, FR_17_ERAY_E_INV_POCSTATE);
      DevError = FR_17_ERAY_E_INV_POCSTATE;
    }
  }



  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                    FR_17_ERAY_CHI_CMD_ALLOW_COLDSTART,FR_RUNTIME_API_ACCESS);

    if (ErrorCount != 0U)
    {
      /* Command not accepted --> Time out --> Production error */
      RetValue = E_NOT_OK ;
    }
    else
    {
      RetValue = E_OK;
    }
  }

  return RetValue;
}

/*******************************************************************************
[cover parentID=DS_AS40X_FR070_FR494_FR495_FR516_FR518_FR521_FR522_FR523]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_AllSlots(uint8 Fr_CtrlIdx)              **
**                                                                            **
** [/cover]
** [/cover]
**
** Service ID:  0x24                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Invokes the CC CHI command 'ALL_SLOTS'.                      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_AllSlots( uint8 Fr_CtrlIdx )
{
  Std_ReturnType RetValue;
  uint32 ErrorCount ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;

  RetValue = E_OK;

  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_ALLSLOTS);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                               FR_17_ERAY_SID_ALLSLOTS);
  }
  /* Driver is not initialized, avoid register access */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*
      FR_17_ERAY_E_INV_POCSTATE if controller is not synchronised to global time
    */
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 0U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                FR_17_ERAY_SID_ALLSLOTS, FR_17_ERAY_E_INV_POCSTATE);
      DevError = FR_17_ERAY_E_INV_POCSTATE;
    }
  }



  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = 0U;

    /* Issue CC CHI command "ALL_SLOTS" */
    ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                        FR_17_ERAY_CHI_CMD_ALL_SLOTS,FR_RUNTIME_API_ACCESS);

    if (ErrorCount == 0U)
    {
      RetValue = E_OK ;
    }
    else
    {
      /* Command not accepted --> Time out --> Production error */
      RetValue = E_NOT_OK;
    }
  }

  return RetValue;
}

/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR014_FR183_FR184_FR185_FR187_FR438_FR494,
                DS_AS40X_FR478_3]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_HaltCommunication(uint8 Fr_CtrlIdx)     **
**                                                                            **
** [/cover]
** [/cover]

** Service ID:  0x04                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Invokes the CC CHI command 'HALT'                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_HaltCommunication( uint8 Fr_CtrlIdx )
{
  uint32 ErrorCount;
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;

  RetValue = E_OK;
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                 (Fr_CtrlIdx,FR_17_ERAY_SID_HALTCOMMUNICATION);

    if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                             FR_17_ERAY_SID_HALTCOMMUNICATION);
  }
  /* Driver is not initialized, avoid register access */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*
      FR_17_ERAY_E_INV_POCSTATE if controller is not synchronised to
      global time
    */
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 0U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                FR_17_ERAY_SID_HALTCOMMUNICATION, FR_17_ERAY_E_INV_POCSTATE);
      DevError = FR_17_ERAY_E_INV_POCSTATE;
    }
  }



  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = 0U;

    /* Issue CC CHI command "HALT" */
    ErrorCount += Fr_17_Eray_lChangePOCState\
                    (Fr_CtrlIdx,FR_17_ERAY_CHI_CMD_HALT,FR_RUNTIME_API_ACCESS);

    if (ErrorCount == 0U)
    {
      RetValue = E_OK ;
    }
    else
    {
      /* Command not accepted --> Time out --> Production error */
      RetValue = E_NOT_OK;
    }
  }
  return RetValue;
}

/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR011_FR188_FR189_FR191_FR438_FR494,DS_AS40X_FR478_4]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_AbortCommunication(uint8 Fr_CtrlIdx)    **
**                                                                            **
** [/cover]

** Service ID:  0x05                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Invokes the CC CHI command 'FREEZE'                          **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_AbortCommunication( uint8 Fr_CtrlIdx )
{
  uint32 ErrorCount ;
  Std_ReturnType RetValue ;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                          FR_17_ERAY_SID_ABORTCOMMUNICATION);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {

    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                           FR_17_ERAY_SID_ABORTCOMMUNICATION);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = 0U ;

    /* Issue CC CHI command "FREEZE" */
    ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                             FR_17_ERAY_CHI_CMD_FREEZE, FR_RUNTIME_API_ACCESS);

    if (ErrorCount == 0U)
    {
      ErrorCount += Fr_17_Eray_lWaitTillPOCStateChange(Fr_CtrlIdx,
                                  FR_17_ERAY_POCS_HALT,FR_RUNTIME_API_ACCESS);
    }

    if (ErrorCount != 0U)
    {
      /* Command not accepted or POC state change did not happen --> Time out ->
          Production error */
      RetValue = E_NOT_OK ;
    }
  }

  return RetValue;
}

/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR007_FR192_FR196_FR193_FR194_FR359_FR438_FR494_FR495,
DS_AS40X_FR478_5,DS_AS_FR009]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_SendWUP(uint8 Fr_CtrlIdx)               **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x06                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Invokes the CC CHI command 'WAKEUP'                   **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_SendWUP( uint8 Fr_CtrlIdx )
{
  Std_ReturnType RetValue ;
  uint32 ErrorCount ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;

  RetValue = E_OK;
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_SENDWUP) ;

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                      FR_17_ERAY_SID_SENDWUP);
  }
  /* Driver is not initialized, avoid register access */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POCSTATE */
    DevError = Fr_17_Eray_lDetCheckInvalidPOCState(Fr_CtrlIdx,
                  FR_17_ERAY_POCS_READY,FR_17_ERAY_SID_SENDWUP);
  }



  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = 0U;

    /* Issue CC CHI command "WAKEUP" */
    ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                             FR_17_ERAY_CHI_CMD_WAKEUP,FR_RUNTIME_API_ACCESS);

    if (ErrorCount == 0U)
    {
      RetValue = E_OK ;
    }
    else
    {
      /* Command not accepted --> Time out --> Production error */
      RetValue = E_NOT_OK;
    }
  }
  return RetValue;
}

/*******************************************************************************
[cover parentID=DS_AS_FR091_FR197_FR198_FR198_FR199_FR200_FR202_FR491_FR495,
DS_AS_FR344_FR468,DS_AS40X_FR514]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_SetWakeupChannel(                       **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    Fr_ChannelType Fr_ChnlIdx               **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x07                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_ChnlIdx - Index of FlexRay channel within the context  **
**                                of the FlexRay CC Fr_CtrlIdx. Valid values  **
**                                are FR_CHANNEL_A and FR_CHANNEL_B.          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Sets a wakeup channel.                                **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_SetWakeupChannel(
                                           uint8 Fr_CtrlIdx,
                                           Fr_ChannelType Fr_ChnlIdx
                                           )
{
  uint32 ErrorCount ;
  Std_ReturnType RetValue ;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                  (Fr_CtrlIdx,FR_17_ERAY_SID_SETWAKEUPCHANNEL);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                            FR_17_ERAY_SID_SETWAKEUPCHANNEL);
  }
  /* Driver is not initialized, avoid register access */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POCSTATE */
    DevError = Fr_17_Eray_lDetCheckInvalidPOCState(Fr_CtrlIdx,
        FR_17_ERAY_POCS_READY,FR_17_ERAY_SID_SETWAKEUPCHANNEL);
  }



  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CHNL_IDX */
    if ((Fr_ChnlIdx != FR_CHANNEL_A) && (Fr_ChnlIdx != FR_CHANNEL_B))
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                   FR_17_ERAY_SID_SETWAKEUPCHANNEL, FR_17_ERAY_E_INV_CHNL_IDX);
      DevError = FR_17_ERAY_E_INV_CHNL_IDX;
    }
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    ErrorCount = 0U ;

    /* Change the CC's POCState to POC:config by invoking the CHI command
    'CONFIG'. */
    ErrorCount += Fr_17_Eray_lChangePOCState(Fr_CtrlIdx,
                            FR_17_ERAY_CHI_CMD_CONFIG,FR_RUNTIME_API_ACCESS);

    if (ErrorCount == 0U)
    {
      /* Configure the wakeup channel according to parameter Fr_ChnlIdx. */
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->SUCC1.U), \
       FR_SUCC1_WUCS_CLEARMASK, ((uint32)Fr_ChnlIdx << FR_17_ERAY_SHIFT_BIT_21))

      /* Change the CC's POCState to POC:ready again by invoking the CHI command
        "CONFIG_COMPLETE" */
      Fr_17_Eray_lChangePOCStateToReady(Fr_CtrlIdx,
                        FR_17_ERAY_EA_SETWAKEUPCHANNEL,FR_RUNTIME_API_ACCESS);
    }
    else
    {
      /* POC state change did not happen --> Time out --> Production error */
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR012_FR213_FR214_FR215_FR217_FR488,
DS_AS40X_FR506_FR507_FR508_FR509_FR510_FR505]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetPOCStatus(                           **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    Fr_POCStatusType* Fr_POCStatusPtr       **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x0a                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out): Fr_POCStatusPtr - Address the output value is stored to. **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the POC status.                                         **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetPOCStatus(
                                       uint8 Fr_CtrlIdx,
                                       Fr_POCStatusType* Fr_POCStatusPtr
                                      )
{
  Ifx_ERAY_CCSV RegCCSV ;
  Std_ReturnType RetValue;
  volatile uint8 pocstate;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif


  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_GETPOCSTATUS);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                FR_17_ERAY_SID_GETPOCSTATUS);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer((void *)Fr_POCStatusPtr,
                                                FR_17_ERAY_SID_GETPOCSTATUS);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    RegCCSV.U = FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U);

    Fr_POCStatusPtr->ColdstartNoise = (boolean) RegCCSV.B.CSNI ;
    Fr_POCStatusPtr->CHIHaltRequest = (boolean) RegCCSV.B.HRQ ;
    Fr_POCStatusPtr->Freeze = (boolean) RegCCSV.B.FSI ;
    Fr_POCStatusPtr->SlotMode = ((Fr_SlotModeType)RegCCSV.B.SLM ==
                                  FR_SLOTMODE_KEYSLOT)?FR_SLOTMODE_KEYSLOT:
                                  ((Fr_SlotModeType)(RegCCSV.B.SLM - 1U)) ;
    Fr_POCStatusPtr->WakeupStatus = (Fr_WakeupStatusType) RegCCSV.B.WSV ;
    Fr_POCStatusPtr->ErrorMode = (Fr_ErrorModeType) \
              ((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCEV.U) & \
                             FR_CCEV_ERRM_SETMASK) >> FR_17_ERAY_SHIFT_BIT_6);


    #ifdef IFX_ERAY_DEBUG
      if(TestFr_DebugMaskGetPocs == FR_17_ERAY_DEBUG_GETPOCS)
        pocstate = RegCCSV.B.POCS;
      else
        pocstate = (uint8)TestFr_DebugMaskGetPocs;
    #else
      pocstate = RegCCSV.B.POCS;
    #endif
    switch (pocstate)
    {
      case FR_17_ERAY_POCS_STARTUP_PREPARE :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP ;
        break;

      case FR_17_ERAY_POCS_COLDSTART_LISTEN :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_LISTEN;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_COLDSTART_COLLISION_RESOLUTION :
        Fr_POCStatusPtr->StartupState =
                                     FR_STARTUP_COLDSTART_COLLISION_RESOLUTION;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_COLDSTART_CONSISTENCY_CHECK :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_CONSISTENCY_CHECK;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_COLDSTART_GAP :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_GAP;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_COLDSTART_JOIN :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_COLDSTART_JOIN;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_INTEGRATION_COLDSTART_CHECK :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_INTEGRATION_COLDSTART_CHECK;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_INTEGRATION_LISTEN :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_INTEGRATION_LISTEN;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_INTEGRATION_CONSISTENCY_CHECK :
        Fr_POCStatusPtr->StartupState =
                                      FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_INITIALIZE_SCHEDULE :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_INITIALIZE_SCHEDULE;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_ABORT_STARTUP :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_STARTUP_SUCCESS :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
        Fr_POCStatusPtr->State = FR_POCSTATE_STARTUP;
        break ;

      case FR_17_ERAY_POCS_DEFAULT_CONFIG :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_DEFAULT_CONFIG;
        break ;

      case FR_17_ERAY_POCS_CONFIG :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
        Fr_POCStatusPtr->State = FR_POCSTATE_CONFIG;
        break ;

      case FR_17_ERAY_POCS_NORMAL_PASSIVE :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_NORMAL_PASSIVE;
        break ;

      case FR_17_ERAY_POCS_NORMAL_ACTIVE :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_NORMAL_ACTIVE ;
        break ;

      case FR_17_ERAY_POCS_READY :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_READY ;
        break ;

      case FR_17_ERAY_POCS_HALT :
      case FR_17_ERAY_POCS_MONITOR_MODE :
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_HALT;
        break ;

      case FR_17_ERAY_POCS_WAKEUP_STANDBY:
      case FR_17_ERAY_POCS_WAKEUP_LISTEN:
      case FR_17_ERAY_POCS_WAKEUP_SEND:
      case FR_17_ERAY_POCS_WAKEUP_DETECT:
          Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
          Fr_POCStatusPtr->State = FR_POCSTATE_WAKEUP;
          break;

      default:
        Fr_POCStatusPtr->StartupState = FR_STARTUP_UNDEFINED ;
        Fr_POCStatusPtr->State = FR_POCSTATE_HALT;
        break ;
    }
  }
  return RetValue;
}

/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR005_1,DS_AS_FR221,
DS_AS_FR092_FR217_FR218_FR219_FR220_FR222_FR224_FR225_FR226,
DS_AS_FR440_FR496_FR497]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_TransmitTxLPdu(                         **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    const uint8* Fr_LSduPtr,                **
**                                    uint8 Fr_LSduLength                     **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x0b                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                  Fr_LSduPtr - This reference points to a buffer where the  **
**                                  assembled LSdu to be transmitted within   **
**                                  this LPdu is stored at.                   **
**                  Fr_LSduLength - Determines the length of the data (in     **
**                                  Bytes) to be transmitted.                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Transmits data on the FlexRay network                        **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_TransmitTxLPdu(
                                           uint8 Fr_CtrlIdx,
                                           uint16 Fr_LPduIdx,
                                           const uint8* Fr_LSduPtr,
                                           uint8 Fr_LSduLength
                                         )
{
  Std_ReturnType RetValue ;
  volatile uint8 obsys;
  uint32 ByteIndex ;
  uint32 MsgBuffIdx ;
  uint32 TimeOutCount;
  uint32 TempLsduPtr[FR_17_ERAY_MAX_LSDU_LENGTH];
  #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON)
  uint32 ConfiguredSlotId;
  uint32 HeaderCRC;
  uint32 HeaderPlc;
  uint8 LSduLengthIn16BitWords;
  #endif
  uint16  AllowDynamicLSduLengthFlag;
  uint8 RegIndex;
  uint8 RegCount;
  uint8  PlcBytes ;
  uint8 LogIdx;
  volatile uint8 IbsyhZero;
  const Fr_17_Eray_LPduConfigType *LPduCfgPtr ;
  uint32 ErrCount;
  ErrCount = 0U;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  RetValue = Fr_17_Eray_lTransmitDetCheck(Fr_CtrlIdx,Fr_LPduIdx,Fr_LSduPtr);

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    RetValue = E_OK;
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr ;
      /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx =
       Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx];

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    PlcBytes =
    (uint8)(LPduCfgPtr[Fr_LPduIdx].WRHS2.B.PayloadLengthConfigured *
                                              FR_17_ERAY_BYTES_PER_HALFWORD );

    /* Payload Length Configured in bytes */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(LPduCfgPtr[Fr_LPduIdx].LpduReconfigurable == FR_LPDU_RECONFIGURABLE)
    {
      /*Read Header only */
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCM.U), \
                                                  FR_OBCM_RHSS_CLEARMASK, 1U)

      /* Request transfer of Message Buffer MsgBuffIdx to OBF Shadow buffer */
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
                                   FR_OBCR_OBRS_CLEARMASK,(uint32)MsgBuffIdx)
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
                 FR_OBCR_REQ_CLEARMASK, ((uint32)1 << FR_17_ERAY_SHIFT_BIT_9))

      /* Wait until transfer is complete */
      TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION ;

      do
      {
        TimeOutCount-- ;
        #ifdef IFX_ERAY_DEBUG
        obsys =
        (uint8)(((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->OBCR.U) & \
                         FR_OBCR_OBSYS_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15) | \
                       ((uint8)(TestFr_DebugMask >> FR_17_ERAY_DEBUG_NUM_15)));
        #else
        obsys =
        (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->OBCR.U) & \
                           FR_OBCR_OBSYS_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15);
        #endif
      }
      while ((obsys == 1U) && (TimeOutCount > 0U));

      /* Report time out error to DEM */
      if (TimeOutCount == 0U)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
          DEM_REPORT_DISABLED)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
          Dem_ReportErrorStatus( \
          Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId,
                                DEM_EVENT_STATUS_FAILED);
        }
        RetValue = E_NOT_OK ;
        PlcBytes = 0U;
      }
      else
      {
        /* Swap the host and shadow buffer */
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
                 FR_OBCR_VIEW_CLEARMASK,((uint32)1 << FR_17_ERAY_SHIFT_BIT_8))

        PlcBytes =
        (uint8)
        ((uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->RDHS2.U) & \
                          FR_RDHS2_PLC_SETMASK) >> FR_17_ERAY_SHIFT_BIT_16) * \
                                               FR_17_ERAY_BYTES_PER_HALFWORD);
        RetValue = E_OK;
      }
    }

    #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
    /* FR_17_ERAY_E_INV_LENGTH */
    if ((RetValue == E_OK) && (Fr_LSduLength > PlcBytes ))
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                      FR_17_ERAY_SID_TRANSMITTXLPDU, FR_17_ERAY_E_INV_LENGTH);
      RetValue = E_NOT_OK ;
    }
    if(RetValue == E_OK)
    #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
    {
      /* DynamicLength Reduction Configuration  */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      AllowDynamicLSduLengthFlag =
             (uint16)(LPduCfgPtr[Fr_LPduIdx].WRHS2.B.AllowDynamicLSduLength );

        /* Does current message buffer configuration correspond to LPduIdx? */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      if (MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] == Fr_LPduIdx)
      {

        /* Is host side input buffer free? */
        #ifdef IFX_ERAY_DEBUG
        IbsyhZero =
        (uint8)(((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) & \
                        FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15) | \
               ((uint8)(TestFr_DebugMaskHostBusy >> FR_17_ERAY_SHIFT_BIT_15)));
        #else
        IbsyhZero =
           (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) \
                         & FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15);
        #endif
        if (IbsyhZero == 0U)
        {
          /* If input buffer is free */
          #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON)
          /* Get the SlotId of the LPdu */
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
          ConfiguredSlotId = (uint32)(LPduCfgPtr[Fr_LPduIdx].WRHS1.B.SlotId );
          /*Get LSduLength in 2 byte words,add 1 for length
          (for rounding)not multiple of 2 */
          LSduLengthIn16BitWords = (uint8)((Fr_LSduLength + 1U) >> \
                                                     FR_17_ERAY_SHIFT_BIT_1);

          if ( AllowDynamicLSduLengthFlag == 1U)
          {
            /* Check if configured payloadLength is same as LSduLength */
            /*  Re-Calculate header CRC for new LSduLength  */
            HeaderCRC =
                Fr_17_Eray_lHeaderCRC
                    (ConfiguredSlotId,LSduLengthIn16BitWords);
            /* Write header section values into input buffer */
            HeaderPlc = ((uint32)LSduLengthIn16BitWords
                                                 << FR_17_ERAY_BIT_POS_PLC);
            FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS2.U),\
                  (unsigned_int)(HeaderPlc|HeaderCRC) & FR_17_ERAY_WRHS2_MASK);
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
              PBConfigStructure and is within allowed range.*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
              PBConfigStructure and is within allowed range.*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
              PBConfigStructure and is within allowed range.*/
            FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS1.U), \
         (unsigned_int)(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)[ \
                         MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx]].WRHS1.U \
                                                     & FR_17_ERAY_WRHS1_MASK);
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
            /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
            FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS3.U), \
                     (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx]. \
                    DataPointerOffsetPtr[MsgBuffIdx] & FR_17_ERAY_WRHS3_MASK);

            /* Select header section for writing into message buffer */
            FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U), \
                          (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

            /* Start the buffer transfer */
            FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U),\
                                   FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

            /*  Check if input buffer is busy with another transfer
                a. Wait until it becomes free or a time out happens
                b. If time out happens, report to DEM     */
            ErrCount += Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                        FR_RUNTIME_API_ACCESS);

            if(ErrCount != 0U)
            {
              RetValue = E_NOT_OK ;
            }
            else
            {
              RetValue = E_OK ;
            }
          }

          if(RetValue == E_OK)
          {
          #endif /* #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON) */
            /* Set input buffer for data copy. Set input buffer for transmit */
            FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U), \
                           (FR_17_ERAY_TRANSFER_DATA & FR_17_ERAY_IBCM_MASK));


          /* if LSduLength is less than configured length and
             if Dynamic LSdu length is not allowed write fill pattern */
          /* Copy the data to WRDSn registers for length of LSduLength. */
          /* Do 32-bit word transfer */
          if ((Fr_LSduLength < PlcBytes) && (AllowDynamicLSduLengthFlag != 1U))
          {
            for (ByteIndex = 0U; ByteIndex < FR_17_ERAY_MAX_LSDU_LENGTH;
                  ByteIndex++)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
              *(TempLsduPtr + ByteIndex)  = 0U;
            }
            for ( ByteIndex = 0U ; ByteIndex < Fr_LSduLength ; ByteIndex++ )
             {
               /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
               /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
               *((uint8 *)(void*)TempLsduPtr + ByteIndex) =
                                                   *(Fr_LSduPtr + ByteIndex);
             }

            RegCount = (PlcBytes / FR_17_ERAY_DIV_BY_4);
            if ((PlcBytes & FR_17_ERAY_MOD_4) != 0U)
            {
                RegCount = RegCount + 1U;
            }

            for (RegIndex = 0U; RegIndex < RegCount; RegIndex++)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
              FR_SFR_RUNTIME_USER_MODE_WRITE32\
               ((*((uint32 *)(void*)&ERAY[Fr_CtrlIdx]->WRDS_1S[0] + \
                    RegIndex)), (*((uint32 *)(void*)TempLsduPtr + RegIndex)));
            }
          }
          else
          /* Copy the data to WRDSn registers for length of LSduLength. */
          /* Do 32-bit word transfer */
          {
            for (ByteIndex = 0U; ByteIndex < FR_17_ERAY_MAX_LSDU_LENGTH;
                   ByteIndex++)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
              *(TempLsduPtr + ByteIndex)  = 0U;
            }
            for ( ByteIndex = 0U ; ByteIndex < Fr_LSduLength ; ByteIndex++ )
             {
                   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
                   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
                   *((uint8 *)(void*)TempLsduPtr + ByteIndex) =
                                                  *(Fr_LSduPtr + ByteIndex);
             }

            RegCount = (Fr_LSduLength / FR_17_ERAY_DIV_BY_4);
            if ((Fr_LSduLength & FR_17_ERAY_MOD_4) != 0U)
            {
                RegCount = RegCount + 1U;
            }

            for (RegIndex = 0U; RegIndex < RegCount; RegIndex++)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
                PBConfigStructure and is within allowed range.*/
              FR_SFR_RUNTIME_USER_MODE_WRITE32\
              ((*((uint32 *)(void*)&ERAY[Fr_CtrlIdx]->WRDS_1S[0] + \
              RegIndex)), (*((uint32 *)(void*)TempLsduPtr + RegIndex)));
            }
          }

          /* Set the input buffer to transfer the data section to message
            buffer */
          FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                    FR_IBCR_IBRH_CLEARMASK,(uint8)MsgBuffIdx)

          /*  Check if input buffer is busy with another transfer
           a. Wait until it becomes free or a time out happens
           b. If time out happens, report to DEM     */
          ErrCount += Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                      FR_RUNTIME_API_ACCESS);

          if(ErrCount == 0U)
          {
            RetValue = E_OK ;
          }

       #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON)
          }
       #endif

        }
        else
        {
          /* Host side input buffer is NOT free */
          RetValue = E_NOT_OK ;
        }
      }
      else
      {
        /* Current message buffer configuration does not correspond to
           LPduIdx */
        RetValue = E_NOT_OK ;
      }
    }
  }
  return RetValue  ;

}

/*******************************************************************************
[cover parentID=DS_AS40X_FR610_FR611_FR612_FR614_FR615_FR616,DS_AS_FR005_2]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_CancelTxLPdu(                           **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                   )                                        **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x2d                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Cancels the already pending transmission of a LPdu
                contained in a controllers physical transmit resource
                (e.g. message buffer).                                        **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_CancelTxLPdu(uint8 Fr_CtrlIdx,
                            uint16 Fr_LPduIdx)
{
  uint32 NdatRegId ;
  uint32 NdatRegMsgBuffIdPos ;
  uint32 MsgBuffIdx ;
  Std_ReturnType RetValue ;
  uint32 ErrCount;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif
  uint8 LogIdx;
  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)

  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_CANCELTXLPDU);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                            FR_17_ERAY_SID_CANCELTXLPDU);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                          FR_17_ERAY_SID_CANCELTXLPDU);
  }

  /*
    Invalid LPduIdx, avoid array out of bound access for
     Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr[LPduIdx]
  */


  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /*FR_17_ERAY_E_INV_LPDU_IDX if its a receive message buffer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (Fr_17_Eray_kConfigPtr->
      CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].WRHS1.B.Cfg == 0U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                  FR_17_ERAY_SID_CANCELTXLPDU, FR_17_ERAY_E_INV_LPDU_IDX);
      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }

 if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /*FR_17_ERAY_E_INV_LPDU_IDX if its a sync node and cancelling msg buffer0*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if((Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx]
              == 0U) &&
       (Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->
       SUCC1.B.pKeySlotUsedForSync == 1U))
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                  FR_17_ERAY_SID_CANCELTXLPDU, FR_17_ERAY_E_INV_LPDU_IDX);
      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx = Fr_17_Eray_kConfigPtr->
    CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx];

    /* Does current message buffer configuration correspond to LPduIdx? */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] == Fr_LPduIdx)
    {
      /* Figure out the TXRQ register corresponding to MsgBuffIdx */
      NdatRegId = MsgBuffIdx >> FR_17_ERAY_MSG_BUFF_ID_SHIFT ;

      /* Figure out the bit, corresponding to MsgBuffIdx, in TXRQ register */
      /* Note: ANDing with 0x1F ==> MOD operation */
      NdatRegMsgBuffIdPos = MsgBuffIdx & FR_17_ERAY_MSG_BUFF_ID_MASK ;

      /* Check if transmission is pending */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      if ((FR_SFR_RUNTIME_USER_MODE_READ32\
                     ((&ERAY[Fr_CtrlIdx]->TXRQ1)[NdatRegId].U) &
                                      ((uint32)1 << NdatRegMsgBuffIdPos))!= 0U)
      {
        /* Updated header so that pending bit clears and TX does not happen */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS1.U),
         (unsigned_int) ((Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)
                          [Fr_LPduIdx].WRHS1.U) & FR_17_ERAY_WRHS1_MASK);

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS2.U),
         (unsigned_int)(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)[
                                  Fr_LPduIdx].WRHS2.U & FR_17_ERAY_WRHS2_MASK);

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS3.U),\
                    (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].\
                    DataPointerOffsetPtr[MsgBuffIdx] & FR_17_ERAY_WRHS3_MASK);

        /* Select header section for writing into message buffer */
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U), \
                         (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

        /* Start the buffer transfer */
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                    FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

        /*  Check if input buffer is busy with another transfer
           a. Wait until it becomes free or a time out happens
           b. If time out happens, report to DEM     */
        ErrCount = Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                      FR_RUNTIME_API_ACCESS);

        if(ErrCount == 0U)
        {
          RetValue = E_OK ;
        }
      }
      else
      {
        /* No transmission is pending, No such cancelation took place.
        return E_NOT_OK */
        RetValue = E_NOT_OK ;
      }
    }
    else
    {
      /* Current message buffer configuration does not correspond to
         LPduIdx */
      RetValue = E_NOT_OK ;
    }
  }

  return RetValue ;

}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR593_FR594_FR595_FR596_FR597,
DS_AS_FR093_FR226_FR233_FR234_FR236_FR237_FR239_FR441,DS_AS_FR005_3,
DS_AS40X_FR512,DS_AS_FR227,DS_AS_FR229_FR230_FR231,
DS_AS_FR593_FR594_FR595_FR596_FR597,
DS_AS40X_FR452_FR600_FR603_FR604_FR605_FR606_FR627_FR628_FR629_FR630_FR645]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_ReceiveRxLPdu(                          **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    uint8* Fr_LSduPtr,                      **
**                                    Fr_RxLPduStatusType* Fr_LPduStatusPtr,  **
**                                    uint8* Fr_LSduLengthPtr                 **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
** [/cover]
** [/cover]
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x0c                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_LSduPtr - This reference points to a buffer where the  **
**                                  LSdu to be received shall be stored       **
**                  Fr_LPduStatusPtr - This reference points to the memory    **
**                                      location where the status of the LPdu **
**                                      shall be stored                       **
**                  Fr_LSduLengthPtr - This reference points to the memory    **
**                           location where the length of the LSdu (in bytes) **
**                           shall be stored. This length represents the      **
**                           number of bytes copied to LSduPtr.               **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Receives data from the FlexRay network.                      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_ReceiveRxLPdu(
                                          uint8 Fr_CtrlIdx,
                                          uint16 Fr_LPduIdx,
                                          uint8* Fr_LSduPtr,
                                          Fr_RxLPduStatusType* Fr_LPduStatusPtr,
                                          uint8* Fr_LSduLengthPtr
                                        )
{
  uint32 TimeOutCount ;
  uint32 ByteIndex ;
  uint32 NdatRegId ;
  uint32 NdatRegMsgBuffIdPos ;
  uint32 MsgBuffIdx ;
  uint32 TempLsduPtr[FR_17_ERAY_MAX_LSDU_LENGTH];
  Std_ReturnType RetValue ;
  uint8 PayloadLenReceived;
  uint8 PayloadLenConfigured;
  uint8 ChannelIdx;
  uint8 RegCount;
  uint8 RegIndex;
  volatile uint8 obsys;
  #if(FR_17_ERAY_RX_STRINGENT_CHECK == STD_OFF)
   uint8 ValidFrameA;
   uint8 ValidFrameB;
  #endif
  uint8 LogIdx;

  for (RegIndex = 0U; RegIndex < FR_17_ERAY_MAX_LSDU_LENGTH; RegIndex++)
  {
    TempLsduPtr[RegIndex] = 0U;
  }
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  RetValue = Fr_17_Eray_lReceiveDetCheck(Fr_CtrlIdx,Fr_LPduIdx,Fr_LSduPtr,
                                          Fr_LPduStatusPtr,Fr_LSduLengthPtr);
  if(RetValue == E_OK)
  #else
  RetValue = E_OK;
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx = Fr_17_Eray_kConfigPtr->
    CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx];

  #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if ( (Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].RxFifoConfigPtr != NULL_PTR) &&
         (MsgBuffIdx == FR_17_ERAY_FIFO_MESG_BUF_ID))
    {
      /* MsgBuffIdx is stored as 0xFF for FIFO */
      /*If it is not a FIFO,then continue with normal Receive,else go to receive
        Fifo*/
        RetValue = Fr_17_Eray_lReceiveRxFifo(Fr_CtrlIdx,Fr_LSduPtr,
                        Fr_LPduStatusPtr,Fr_LSduLengthPtr);
    }/*if ( Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].RxFifoConfigPtr != NULL_PTR)*/
    else
  #endif
    {
      /* Does current message buffer configuration correspond to LPduIdx? */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      if (MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] == Fr_LPduIdx)
      {
        /* Initialize output parameters */
        *Fr_LSduLengthPtr = 0U ;
        *Fr_LPduStatusPtr = FR_NOT_RECEIVED ;

        /* Figure out the NDAT register corresponding to MsgBuffIdx */
        NdatRegId = MsgBuffIdx >> FR_17_ERAY_MSG_BUFF_ID_SHIFT ;

        /* Figure out the bit, corresponding to MsgBuffIdx, in NDAT register */
        /* Note: ANDing with 0x1F ==> MOD operation */
        NdatRegMsgBuffIdPos = MsgBuffIdx & FR_17_ERAY_MSG_BUFF_ID_MASK ;

        /* Check if new data is received */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        if ((FR_SFR_RUNTIME_USER_MODE_READ32\
             ((&ERAY[Fr_CtrlIdx]->NDAT1)[NdatRegId].U) & \
                                      ((uint32)1 << NdatRegMsgBuffIdPos))!= 0U)
        {
          /* Subtract 1 to correct the channel as per Fr_ChannelType enum */
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
          ChannelIdx = (uint8)
             ((uint8)(Fr_17_Eray_kConfigPtr->
                 CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].WRHS1.B.Channel) -
                                                          (uint8)0x1);

          #if(FR_17_ERAY_RX_STRINGENT_CHECK == STD_ON)
          RetValue = Fr_17_Eray_RxStringentCheck(Fr_CtrlIdx,ChannelIdx);
          #else
          /*Check if the SlotStatus does not show a valid frame (vSS!ValidFrame)
             and return E_NOT_OK*/

          #ifdef IFX_ERAY_DEBUG
            ValidFrameA =
            (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->ACS.U) \
               & FR_ACS_VFRA_SETMASK) & (uint8)(TestFr_DebugMaskStringent));
            ValidFrameB =
            (uint8)(((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->ACS.U) \
              & FR_ACS_VFRB_SETMASK) >> FR_17_ERAY_SHIFT_BIT_8) & \
               (uint8)(TestFr_DebugMaskStringent >> FR_17_ERAY_SHIFT_BIT_8));
          #else
            ValidFrameA = (uint8)(FR_SFR_RUNTIME_USER_MODE_READ32\
                               (ERAY[Fr_CtrlIdx]->ACS.U) & FR_ACS_VFRA_SETMASK);
            ValidFrameB = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                         (ERAY[Fr_CtrlIdx]->ACS.U) & FR_ACS_VFRB_SETMASK) \
                                                   >> FR_17_ERAY_SHIFT_BIT_8);
          #endif
          if(((ChannelIdx == (uint8)FR_CHANNEL_A) && (ValidFrameA == 0U)) ||
             ((ChannelIdx == (uint8)FR_CHANNEL_B) && (ValidFrameB == 0U)) )
          {
            RetValue = E_NOT_OK ;
          }
          #endif
               /*#if(FR_17_ERAY_RX_STRINGENT_CHECK == STD_ON)*/
          if(RetValue == E_OK)
          {


            /*
              Write Output Buffer Command Mask for both header and data section
              transfer
            */
            FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCM.U), \
                                                   FR_OBCM_RHSS_CLEARMASK, 1U)
            FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCM.U), \
                FR_OBCM_RDSS_CLEARMASK, ((uint32)1 << FR_17_ERAY_SHIFT_BIT_1))

            /*Request transfer of Message Buffer MsgBuffIdx to OBF Shadow
             buffer*/
            FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
                              FR_OBCR_OBRS_CLEARMASK, (uint32)MsgBuffIdx)
            FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
                                                   FR_OBCR_REQ_CLEARMASK, \
                                      ((uint32)1 << FR_17_ERAY_SHIFT_BIT_9))

            /* Wait until transfer is complete */
            TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION ;

            do
            {
              TimeOutCount-- ;
              #ifdef IFX_ERAY_DEBUG
              obsys = (uint8)(((FR_SFR_RUNTIME_USER_MODE_READ32 \
                      (ERAY[Fr_CtrlIdx]->OBCR.U) & FR_OBCR_OBSYS_SETMASK) \
                                              >> FR_17_ERAY_SHIFT_BIT_15) \
                   | (uint8)(TestFr_DebugMask >> FR_17_ERAY_DEBUG_NUM_15));
              #else
              obsys = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                          (ERAY[Fr_CtrlIdx]->OBCR.U) & FR_OBCR_OBSYS_SETMASK) \
                                                 >> FR_17_ERAY_SHIFT_BIT_15);
              #endif
            }
            while ((obsys == 1U) && (TimeOutCount > 0U));

            /* Report time out error to DEM */
            if (TimeOutCount == 0U)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
              if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
                DEM_REPORT_DISABLED)
              {
                /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
                Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                                   CfgPtr[LogIdx].FrDemTimeoutId,
                                      DEM_EVENT_STATUS_FAILED);
              }
              RetValue = E_NOT_OK ;
            }
            else
            {
              /* Swap the host and shadow buffer */
              FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
                 FR_OBCR_VIEW_CLEARMASK, ((uint32)1 << FR_17_ERAY_SHIFT_BIT_8))

              /*--------------------------------------------------------------*/
              /* Read message buffer status, header and data sections as below*/

              /* Received length in bytes = Min(PLR, PLC) [FR239] * 2 */
              PayloadLenReceived = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                     (ERAY[Fr_CtrlIdx]->RDHS2.U) & FR_RDHS2_PLR_SETMASK) \
                                                  >> FR_17_ERAY_SHIFT_BIT_24);

              /*Dynamic Slot*/
              PayloadLenConfigured = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                     (ERAY[Fr_CtrlIdx]->RDHS2.U) & FR_RDHS2_PLC_SETMASK) \
                                                  >> FR_17_ERAY_SHIFT_BIT_16);

              #if(FR_17_ERAY_RX_STRINGENT_LENGTH_CHECK == STD_ON)

               /* Check if received payload length match
               with configured payload length */
              if(PayloadLenReceived != PayloadLenConfigured)
              {
                /* received payload length does not match
                the configured payload length */
                RetValue = E_NOT_OK ;
              }

              if(RetValue == E_OK)
              #endif
              {
                *Fr_LPduStatusPtr = FR_RECEIVED ;

                if (PayloadLenReceived > PayloadLenConfigured)
                {
                  *Fr_LSduLengthPtr =
                  (uint8)(PayloadLenConfigured * FR_17_ERAY_BYTES_PER_HALFWORD);
                }
                else
                {
                  *Fr_LSduLengthPtr =
                  (uint8)(PayloadLenReceived * FR_17_ERAY_BYTES_PER_HALFWORD);
                }


            /* Copy data from RDDSn registers to application buffer pointed
                by LSduPtr */

             /* Do 32-bit word transfer, as much as possible */

            RegCount = ((*Fr_LSduLengthPtr)  / FR_17_ERAY_DIV_BY_4);
            if (((*Fr_LSduLengthPtr) & FR_17_ERAY_MOD_4) != 0U)
            {
                RegCount = RegCount + 1U;
            }

            for (RegIndex = 0U; RegIndex < RegCount; RegIndex++)
            {
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
              /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
              *((uint32 *)(void *)TempLsduPtr + RegIndex) =
             FR_SFR_RUNTIME_USER_MODE_READ32\
               (*((uint32 *)(void *)&ERAY[Fr_CtrlIdx]->RDDS_1S[0] + RegIndex));
            }

            for ( ByteIndex = 0U ; ByteIndex < (*Fr_LSduLengthPtr) ;ByteIndex++)
            {
               /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
               /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
               *(Fr_LSduPtr + ByteIndex) =
                              *((uint8*)(void*)TempLsduPtr + ByteIndex);
            }

                /* If syntax error is observed, report to DEM */
                /*single slot status error DEM */

                RetValue = Fr_17_Eray_SlotStatusErrorCheck(Fr_CtrlIdx,
                                          ChannelIdx);
                /*------------------------------------------------------------*/
              }
            }
          }
        }
      }
      else
      {
        /* Current message buffer configuration does not correspond to
         LPduIdx */
        RetValue = E_NOT_OK ;
      }
    }
  }
  return RetValue ;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR094_FR240_FR241_FR242_FR244_FR343,
DS_AS40X_FR511]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_CheckTxLPduStatus(                      **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    Fr_TxLPduStatusType* Fr_TxLPduStatusPtr **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x0d                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_TxLPduStatusPtr - This reference is used to store the  **
**                                        transmit status of the LSdu         **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Checks the transmit status of the LSdu.                      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_CheckTxLPduStatus(
                                     uint8 Fr_CtrlIdx,
                                     uint16 Fr_LPduIdx,
                                     Fr_TxLPduStatusType* Fr_TxLPduStatusPtr
                                     )
{
  uint32 NdatRegId ;
  uint32 NdatRegMsgBuffIdPos ;
  uint32 MsgBuffIdx ;
  Std_ReturnType RetValue ;
  uint8 ChannelIdx;
  uint8 LogIdx;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)

  RetValue = E_OK ;
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                 (Fr_CtrlIdx,FR_17_ERAY_SID_CHECKTXLPDUSTATUS);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                            FR_17_ERAY_SID_CHECKTXLPDUSTATUS);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                            FR_17_ERAY_SID_CHECKTXLPDUSTATUS);
  }

  /*
    Invalid LPduIdx, avoid array out of bound access for
     Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx]
  */


  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* FR_17_ERAY_E_INV_LPDU_IDX if its a receive message buffer */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (Fr_17_Eray_kConfigPtr->
       CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].WRHS1.B.Cfg == 0U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                  FR_17_ERAY_SID_CHECKTXLPDUSTATUS, FR_17_ERAY_E_INV_LPDU_IDX);
      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
                 (void *)Fr_TxLPduStatusPtr, FR_17_ERAY_SID_CHECKTXLPDUSTATUS);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    *Fr_TxLPduStatusPtr = FR_NOT_TRANSMITTED ;
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx = Fr_17_Eray_kConfigPtr->
                        CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx];

    /* Does current message buffer configuration correspond to LPduIdx? */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] == Fr_LPduIdx)
    {
      /* Figure out the TXRQ register corresponding to MsgBuffIdx */
      NdatRegId = MsgBuffIdx >> FR_17_ERAY_MSG_BUFF_ID_SHIFT ;

      /* Figure out the bit, corresponding to MsgBuffIdx, in TXRQ register */
      /* Note: ANDing with 0x1F ==> MOD operation */
      NdatRegMsgBuffIdPos = MsgBuffIdx & FR_17_ERAY_MSG_BUFF_ID_MASK ;

      /* Check if transmission has completed. */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      if ((FR_SFR_RUNTIME_USER_MODE_READ32\
              ((&ERAY[Fr_CtrlIdx]->TXRQ1)[NdatRegId].U) &
                                     ((uint32)1 << NdatRegMsgBuffIdPos)) == 0U)
      {
        *Fr_TxLPduStatusPtr = FR_TRANSMITTED ;
      }
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      ChannelIdx =(uint8)
      ((uint8)(Fr_17_Eray_kConfigPtr->
                CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].WRHS1.B.Channel)
                                                        - (uint8)0x1);

      RetValue = Fr_17_Eray_SlotStatusErrorCheck(Fr_CtrlIdx,ChannelIdx);
    }
    else
    {
      /* Current message buffer configuration does not correspond to
         LPduIdx */
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue ;
}

#if(FR_17_ERAY_RECONFIG_BUFFER == STD_ON)
/******************************************************************************
*Traceability : [cover parentID=DS_AS_FR070_FR107_FR245_FR246_FR247_FR249_FR250]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_PrepareLPdu(                            **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x1f                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Prepares a LPdu.                                             **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_PrepareLPdu(uint8 Fr_CtrlIdx,uint16 Fr_LPduIdx )
{
  uint32 MsgBuffIdx ;
  Std_ReturnType RetValue;
  volatile uint8 IbsyhZero;
  const Fr_17_Eray_LPduConfigType *LPduCfgPtr ;
  uint32 ErrCount;
 uint8 LogIdx;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif


  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_PREPARELPDU);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                 FR_17_ERAY_SID_PREPARELPDU);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX: LPduIdx >= LPDU count  */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                                  FR_17_ERAY_SID_PREPARELPDU);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx = Fr_17_Eray_kConfigPtr->
                    CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx];

    /* Store the LPDU configuration */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr;

    /* Is the message buffer MsgBuffIdx already configured for LPduIdx? */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if ((MsgBuffIdx != FR_17_ERAY_LPDU_IDX_UNUSED) &&
        ((MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] != Fr_LPduIdx)||
        (LPduCfgPtr[Fr_LPduIdx].LpduReconfigurable == FR_LPDU_RECONFIGURABLE)))
    {

      /* Reconfigure MsgBuffIdx for Fr_LPduIdx */

      /* Is host side input buffer free? */
      #ifdef IFX_ERAY_DEBUG
      IbsyhZero = (uint8)(((FR_SFR_RUNTIME_USER_MODE_READ32 \
                      (ERAY[Fr_CtrlIdx]->IBCR.U) & FR_IBCR_IBSYH_SETMASK) \
            >> FR_17_ERAY_SHIFT_BIT_15) |(uint8)(TestFr_DebugMaskHostBusy \
                                              >> FR_17_ERAY_SHIFT_BIT_15));
      #else
      IbsyhZero = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32 \
                     (ERAY[Fr_CtrlIdx]->IBCR.U) & FR_IBCR_IBSYH_SETMASK) \
                                              >> FR_17_ERAY_SHIFT_BIT_15);
      #endif
      if (IbsyhZero == 0U)
      {
        /* Write into header section values into input buffer */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS1.U),
        (unsigned_int)((Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)
                             [Fr_LPduIdx].WRHS1.U & FR_17_ERAY_WRHS1_MASK));

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS2.U),
          (unsigned_int)((Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr)
                               [Fr_LPduIdx].WRHS2.U & FR_17_ERAY_WRHS2_MASK));

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS3.U),
                      (unsigned_int)((Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx]
         .DataPointerOffsetPtr[MsgBuffIdx]) & (uint32)FR_17_ERAY_WRHS3_MASK));

        /* Select header section for writing into message buffer */
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U),\
                    (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

        /* Start the buffer transfer */
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                   FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

        /*  Check if input buffer is busy with another transfer
           a. Wait until it becomes free or a time out happens
           b. If time out happens, report to DEM     */
        ErrCount = Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                      FR_RUNTIME_API_ACCESS);

        if(ErrCount == 0U)
        {
          RetValue = E_OK ;
        }

        /* Update the message buffer to LPDU mapping */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] = (uint8)Fr_LPduIdx;
      }
      else
      {
        /* Host side input buffer is NOT free */
        RetValue = E_NOT_OK ;
      }
    }
    else
    {
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue ;
}
#endif /* (FR_17_ERAY_RECONFIG_BUFFER == STD_ON) */

#if (FR_17_ERAY_RECONFIG_BUFFER == STD_ON)
/*******************************************************************************
** Traceability :
[cover parentID=DS_AS40X_FR492_FR524_FR525_FR526_FR527_FR528_FR530_FR531_FR532]
[cover parentID=DS_AS40X_FR533_FR534_FR535_FR536_FR537_FR538_FR634_FR633]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_ReconfigLPdu(                           **
**                                           uint8 Fr_CtrlIdx,                **
**                                           uint16 Fr_LPduIdx,               **
**                                           uint16 Fr_FrameId,               **
**                                           Fr_ChannelType Fr_ChnlIdx,       **
**                                           uint8 Fr_CycleRepetition,        **
**                                           uint8 Fr_CycleOffset,            **
**                                           uint8 Fr_PayloadLength,          **
**                                           uint16 Fr_HeaderCRC              **
**                                           )                                **
**                                                                            **
** [/cover]
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x25                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                    Fr_FrameId -  FlexRay Frame ID the FrIf_LPdu shall be   **
**                               configured to.                               **
**                    Fr_ChnlIdx -  FlexRay Channel the FrIf_LPdu shall be    **
**                                configured to.                              **
**                    Fr_CycleRepetition -Cycle Repetition part of the cycle  **
**                          filter mechanism FrIf_LPdu shall be configured to **
**                    Fr_CycleOffset - Cycle Offset part of the cycle filter  **
**                                mechanism FrIf_LPdu shall be configured to. **
**                    Fr_PayloadLength  - Payloadlength in units of bytes the **
**                                FrIf_LPduIdx shall be configured to.        **
**                     Fr_HeaderCRC - Header CRC the FrIf_LPdu shall be       **
**                                configured to.                              **
**                                                                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Reconfigures a given LPdu according to the parameters
         (FrameId, Channel, CycleRepetition, CycleOffset, PayloadLength,
         HeaderCRC) at runtime.                                               **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_ReconfigLPdu(
    uint8 Fr_CtrlIdx,
    uint16 Fr_LPduIdx,
    uint16 Fr_FrameId,
    Fr_ChannelType Fr_ChnlIdx,
    uint8 Fr_CycleRepetition,
    uint8 Fr_CycleOffset,
    uint8 Fr_PayloadLength,
    uint16 Fr_HeaderCRC
)
{
  uint32 ErrorCount;
  uint32 MsgBuffIdx ;
  Std_ReturnType RetValue ;
  const Fr_17_Eray_LPduConfigType *LPduCfgPtr ;
  Fr_17_Eray_RegWrhs1Type Wrhs1;
  Fr_17_Eray_RegWrhs2Type Wrhs2;
  uint8 CycleCode;
  uint8 LogIdx;
  volatile uint8 IbsyhZero;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  uint8  PlcBytes ;
  Fr_ChannelType ChannelIdx;
  #endif

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  RetValue = E_OK;
  #endif

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_RECONFIGLPDU);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                 FR_17_ERAY_SID_RECONFIGLPDU);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX: LPduIdx >= LPDU count  */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                                  FR_17_ERAY_SID_RECONFIGLPDU);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr ;
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (LPduCfgPtr[Fr_LPduIdx].LpduReconfigurable != FR_LPDU_RECONFIGURABLE)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                   FR_17_ERAY_SID_RECONFIGLPDU, FR_17_ERAY_E_INV_LPDU_IDX);

      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* FR_17_ERAY_E_INV_CHNL_IDX */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->SUCC1.B.pChannels ==
                                                                        0x1U)
    {
      ChannelIdx = FR_CHANNEL_A;
    }
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    else if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr->SUCC1.B.pChannels
                                                                     == 0x2U)
    {
      ChannelIdx = FR_CHANNEL_B;
    }
    else
    {
      ChannelIdx = FR_CHANNEL_AB;
    }

    if(((ChannelIdx != FR_CHANNEL_AB) && (Fr_ChnlIdx != ChannelIdx ))||
      ((ChannelIdx == FR_CHANNEL_AB) && (Fr_ChnlIdx > ChannelIdx )))
    {
        Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                     FR_17_ERAY_SID_RECONFIGLPDU, FR_17_ERAY_E_INV_CHNL_IDX);
        DevError = FR_17_ERAY_E_INV_CHNL_IDX;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* Valid values for Fr_CycleRepetition: 1, 2, 4, 8, 16, 32, 64 */
    /* FR_17_ERAY_E_INV_CYCLE */
    if ((Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_1) &&
      (Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_2) &&
      (Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_4) &&
      (Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_8) &&
      (Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_16) &&
      (Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_32) &&
      (Fr_CycleRepetition != FR_17_ERAY_CYCLE_REPETION_64))
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                     FR_17_ERAY_SID_RECONFIGLPDU, FR_17_ERAY_E_INV_CYCLE);
      DevError = FR_17_ERAY_E_INV_CYCLE;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* Valid values for Fr_BaseCycle : 0 to (Fr_CycleRepetition - 1) */
    /* FR_17_ERAY_E_INV_CYCLE */
    if (Fr_CycleOffset >= Fr_CycleRepetition )
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                     FR_17_ERAY_SID_RECONFIGLPDU, FR_17_ERAY_E_INV_CYCLE);
      DevError = FR_17_ERAY_E_INV_CYCLE;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* FR_17_ERAY_E_INV_LENGTH */
    /* Valid values for Fr_PayloadLength */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr ;
    /* Payload Length Configured in bytes */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    PlcBytes =
    (uint8)(LPduCfgPtr[Fr_LPduIdx].WRHS2.B.PayloadLengthConfigured *
                                                FR_17_ERAY_BYTES_PER_HALFWORD);

    /* FR_17_ERAY_E_INV_LENGTH */
    if (Fr_PayloadLength > PlcBytes)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                      FR_17_ERAY_SID_RECONFIGLPDU, FR_17_ERAY_E_INV_LENGTH);
      DevError = FR_17_ERAY_E_INV_LENGTH;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* Valid values for Fr_HeaderCRC : 0 to 2047 */
    /* FR_17_ERAY_E_INV_HEADERCRC */
    if (Fr_HeaderCRC > FR_17_ERAY_HEADER_CRC_MAX)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                     FR_17_ERAY_SID_RECONFIGLPDU, FR_17_ERAY_E_INV_HEADERCRC);
      DevError = FR_17_ERAY_E_INV_HEADERCRC;
    }
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
#endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
     /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx = Fr_17_Eray_kConfigPtr->
                           CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx] ;

    /* Is the message buffer MsgBuffIdx already configured for LPduIdx? */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr ;

    /* Check if Lpdu is dynamically reconfigurable */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (LPduCfgPtr[Fr_LPduIdx].LpduReconfigurable == FR_LPDU_RECONFIGURABLE)
    {
      /* Is host side input buffer free? */
      #ifdef IFX_ERAY_DEBUG
      IbsyhZero = (uint8)(((FR_SFR_RUNTIME_USER_MODE_READ32 \
                  (ERAY[Fr_CtrlIdx]->IBCR.U) & FR_IBCR_IBSYH_SETMASK) \
         >> FR_17_ERAY_SHIFT_BIT_15)|(uint8)(TestFr_DebugMaskHostBusy \
                                           >> FR_17_ERAY_SHIFT_BIT_15));
      #else
      IbsyhZero=
        (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) & \
                          FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15);
      #endif
      if (IbsyhZero == 0U)
      {
        /*Write from config for values that are not available for
        reconfiguring*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        Wrhs1.U = LPduCfgPtr[Fr_LPduIdx].WRHS1.U;
        /* Write into header section values into input buffer */
        Wrhs1.B.SlotId = Fr_FrameId ;
        /* CycleCode = CycleRepetition | BaseCycle */
        CycleCode = (Fr_CycleRepetition + Fr_CycleOffset);
        Wrhs1.B.CycleCode = CycleCode;
        /*Configure Channel Index, add 0x1 to make the value as per WRHS1 bits*/
        Wrhs1.B.Channel = (uint8)(Fr_ChnlIdx + (Fr_ChannelType)0x1);

        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS1.U),
                               (unsigned_int)(Wrhs1.U & FR_17_ERAY_WRHS1_MASK));

        /* If payload length is odd, Fr_PayloadLength must be rounded to next
           higher even number */
        if ((Fr_PayloadLength & 0x01U)== 1U)
        {
          Fr_PayloadLength = (Fr_PayloadLength + 1U) ;
        }

        /* Configure payload length in terms of 2 byte word */
        Wrhs2.B.PayloadLengthConfigured = (Fr_PayloadLength >> 1U);

        /*Configure Header CRC*/
        Wrhs2.B.HeaderCRC = Fr_HeaderCRC;

        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS2.U),
                              (unsigned_int)(Wrhs2.U & FR_17_ERAY_WRHS2_MASK));

        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->WRHS3.U),\
         (unsigned_int)Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].\
                   DataPointerOffsetPtr[MsgBuffIdx] & FR_17_ERAY_WRHS3_MASK);

        /* Select header section for writing into message buffer */
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U), \
                        (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

        /* Start the buffer transfer */
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                   FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

        /*  Check if input buffer is busy with another transfer
           a. Wait until it becomes free or a time out happens
           b. If time out happens, report to DEM     */
        ErrorCount = Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                      FR_RUNTIME_API_ACCESS);

        if (ErrorCount != 0U)
        {
          /* Command not accepted or POC state change did not happen -->
          Time out--> Production error */
          RetValue = E_NOT_OK;
        }
        else
        {
          RetValue = E_OK;
        }

        /* Update the message buffer to LPDU mapping */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] = (uint8)Fr_LPduIdx ;
      }
      else
      {
        /* Host side input buffer is NOT free */
        RetValue = E_NOT_OK ;
      }
    }
    else
    {
      /* LPDU is not reconfigurable */
      RetValue = E_NOT_OK ;

    }
  }
  return RetValue ;

}
#endif /* (FR_17_ERAY_RECONFIG_BUFFER == STD_ON) */

#if (FR_17_ERAY_RECONFIG_BUFFER == STD_ON)
/*******************************************************************************
[cover parentID=DS_AS40X_FR539_FR540_FR541_FR542_FR544_FR545_FR546]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_DisableLPdu(                            **
**                                           uint8 Fr_CtrlIdx,                **
**                                           uint16 Fr_LPduIdx,               **
**                                           )                                **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x26                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Disables the hardware resource of a LPdu for
                 transmission/reception.                                      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_DisableLPdu(uint8 Fr_CtrlIdx,uint16 Fr_LPduIdx)
{
  uint32 MsgBuffIdx ;
  const Fr_17_Eray_LPduConfigType *LPduCfgPtr ;
  Std_ReturnType RetValue;
  uint32 ErrCount;
  uint8 LogIdx;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_DISABLELPDU);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                   FR_17_ERAY_SID_DISABLELPDU);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX: LPduIdx >= LPDU count  */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                                  FR_17_ERAY_SID_DISABLELPDU);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (Fr_17_Eray_kConfigPtr->
      CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].LpduReconfigurable !=
                                                        FR_LPDU_RECONFIGURABLE)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                   FR_17_ERAY_SID_DISABLELPDU, FR_17_ERAY_E_INV_LPDU_IDX);

      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* Figure out the message buffer corresponding to LPduIdx */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    MsgBuffIdx = Fr_17_Eray_kConfigPtr->
                           CfgPtr[LogIdx].LPduIdx2MsgBuffIdxPtr[Fr_LPduIdx] ;

    /* Check if Lpdu is dynamically reconfigurable */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LPduCfgPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr ;

    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (LPduCfgPtr[Fr_LPduIdx].LpduReconfigurable == FR_LPDU_RECONFIGURABLE)
    {
      /* Set Channel Filter Control A and Channel Filter Control B bits to
      zero,to stop transmission and receive buffer will ignore frames.*/
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->WRHS1.U), \
                                                   FR_WRHS1_CHA_CLEARMASK, 0U)
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->WRHS1.U), \
                                                   FR_WRHS1_CHB_CLEARMASK, 0U)


     /* Select header section for writing into message buffer */
        FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->IBCM.U), \
                         (FR_17_ERAY_TRANSFER_HEADER & FR_17_ERAY_IBCM_MASK));

     /* Start the buffer transfer */
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->IBCR.U), \
                                   FR_IBCR_IBRH_CLEARMASK, (uint8)MsgBuffIdx)

        /*  Check if input buffer is busy with another transfer
           a. Wait until it becomes free or a time out happens
           b. If time out happens, report to DEM     */
        ErrCount = Fr_17_Eray_lInputBufBsyHost(Fr_CtrlIdx,
                                                      FR_RUNTIME_API_ACCESS);

        if(ErrCount == 0U)
        {
          RetValue = E_OK ;
        }


     /* Update the message buffer to LPDU mapping */
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        MsgBuff2LPduIdxPtr[Fr_CtrlIdx][MsgBuffIdx] = (uint8)Fr_LPduIdx ;
    }
    else
    {
      RetValue = E_NOT_OK;
    }
  }
  return RetValue ;
}
#endif /* (FR_17_ERAY_RECONFIG_BUFFER == STD_ON) */

/*******************************************************************************
[cover parentID=DS_AS_FR042_FR044_FR251_FR252_FR253_FR254_FR256_FR257]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetGlobalTime(                          **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8* Fr_CyclePtr,                     **
**                                    uint16* Fr_MacroTickPtr                 **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x10                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_CyclePtr - Address where the current FlexRay           **
**                                communication cycle value shall be stored.  **
**                                                                            **
**                  Fr_MacroTickPtr - Address where the current macrotick     **
**                                    value shall be stored.                  **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the current global FlexRay time.                        **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetGlobalTime(
                                         uint8 Fr_CtrlIdx,
                                         uint8* Fr_CyclePtr,
                                         uint16* Fr_MacroTickPtr
                                       )
{
  Std_ReturnType RetValue ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError =
        Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_GETGLOBALTIME) ;

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                FR_17_ERAY_SID_GETGLOBALTIME);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(Fr_CyclePtr,
                                                FR_17_ERAY_SID_GETGLOBALTIME);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(Fr_MacroTickPtr,
                                                FR_17_ERAY_SID_GETGLOBALTIME);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue ==E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 1U)
    {
      *Fr_MacroTickPtr = (uint16)(FR_SFR_RUNTIME_USER_MODE_READ32\
                          (ERAY[Fr_CtrlIdx]->MTCCV.U) & FR_MTCCV_MTV_SETMASK) ;
      *Fr_CyclePtr = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                      (ERAY[Fr_CtrlIdx]->MTCCV.U) & FR_MTCCV_CCV_SETMASK) \
                                               >> FR_17_ERAY_SHIFT_BIT_16);
    }
    else
    {
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue ;
}

#if (FR_17_ERAY_NMVECTOR_ENABLE == STD_ON) /* FR266 */
/*******************************************************************************
[cover parentID=DS_AS_FR113_FR258_FR259_FR260_FR262_FR263_FR264]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetNmVector(                            **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8* Fr_NmVectorPtr                   **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x22                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_NmVectorPtr - Address where the NmVector of the last   **
**                                communication cycle shall be stored.        **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the network management vector of the last               **
**                 communication cycle.                                       **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetNmVector(
                                       uint8 Fr_CtrlIdx,
                                       uint8* Fr_NmVectorPtr
                                     )
{
  uint8 ByteIndex ;
  uint32 * NmvRegAddr ;
  uint8 LogIdx;
  Std_ReturnType RetValue ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,FR_17_ERAY_SID_GETNMVECTOR);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                  FR_17_ERAY_SID_GETNMVECTOR);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(Fr_NmVectorPtr,
                                                  FR_17_ERAY_SID_GETNMVECTOR);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 1U)
    {
      NmvRegAddr =  (uint32 *)(void *)&ERAY[Fr_CtrlIdx]->NMV_1S[0];
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
        PBConfigStructure and is within allowed range.*/
      LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
      /* Fill in the NM vector values into output parameter */
      /* Note: NEMC.NML = gNetworkManagementVectorLength */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      for (ByteIndex = 0U; ByteIndex < Fr_17_Eray_kConfigPtr->
                            CfgPtr[LogIdx].CCCfgPtr->NEMC.U; ByteIndex++)
      {
        *Fr_NmVectorPtr = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(*NmvRegAddr)\
                                       & FR_PIN_NVM_SETMASK(ByteIndex)) \
                                     >> FR_NVM_BIT_SHIFT_COUNT(ByteIndex));
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
          PBConfigStructure and is within allowed range.*/
        Fr_NmVectorPtr++ ;

        if(((ByteIndex % FR_NUM_FOUR) == 0U) && (ByteIndex != 0U))
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
            PBConfigStructure and is within allowed range.*/
          NmvRegAddr++;

        }
      }
    }
    else
    {
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue ;
}
#endif /* (FR_17_ERAY_NMVECTOR_ENABLE == STD_ON) */

/*******************************************************************************
[cover parentID=DS_AS40X_FR547_FR549_FR550_FR551_FR553_FR554_FR555]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetNumOfStartupFrames(                  **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8* Fr_NumOfStartupFramesPtr         **
**                                    )                                       **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x27                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**
**          Fr_NumOfStartupFramesPtr - Address where the number of startup    **
**          frames seen within the last even/odd cycle pair shall be stored.  **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the current number of startup frames seen on the        **
**               cluster.                                                     **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetNumOfStartupFrames(
    uint8 Fr_CtrlIdx,
    uint8* Fr_NumOfStartupFramesPtr
)
{
  Std_ReturnType RetValue ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETNUMOFSTARTUPFRAMES);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETNUMOFSTARTUPFRAMES);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_NumOfStartupFramesPtr,FR_17_ERAY_SID_GETNUMOFSTARTUPFRAMES);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 1U)
    {
      *Fr_NumOfStartupFramesPtr = FR_17_ERAY_STARTUP_FRAMES ;

    }
    else
    {
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue ;
}

/*******************************************************************************
[cover parentID=DS_AS_FR556_FR558_FR559_FR561_FR562_FR563_FR607]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetChannelStatus                        **
                        (                                                     **
**                         uint8 Fr_CtrlIdx,                                  **
**                         uint16* Fr_ChannelAStatusPtr,                      **
**                         uint16* Fr_ChannelBStatusPtr                       **
**                      )                                                     **
**                                                                            **
** [/cover]
** [/cover]
**
** Service  ID:  0x28                                                         **
**                                                                            **
** Sync/Asyn c:  Synchronous                                                  **
**                                                                            **
** Reentrancy :  non reentrant for the same device                            **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**          Fr_ChannelAStatusPtr - Address where the bitcoded channel A status
            information shall be stored.
            Fr_ChannelBStatusPtr - Address where the bitcoded channel B status
            information shall be stored.                                      **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the channel status information.                         **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetChannelStatus(
    uint8 Fr_CtrlIdx,
    uint16* Fr_ChannelAStatusPtr,
    uint16* Fr_ChannelBStatusPtr
)
{
  Std_ReturnType RetValue ;
  uint32 AggrChaAStatusA;
  uint32 SymbWindValidMTSA ;
  uint32  SymbWindErrStatusA ;
  uint32  NITStatusDataA ;
  uint32 AggrChaAStatusB;
  uint32 SymbWindValidMTSB ;
  uint32  SymbWindErrStatusB ;
  uint32  NITStatusDataB ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETCHANNELSTATUS);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETCHANNELSTATUS);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ChannelAStatusPtr,FR_17_ERAY_SID_GETCHANNELSTATUS);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ChannelBStatusPtr,FR_17_ERAY_SID_GETCHANNELSTATUS);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 1U)
    {
      /*Channel A aggregated channel status */
      AggrChaAStatusA = FR_SFR_RUNTIME_USER_MODE_READ32\
                          (ERAY[Fr_CtrlIdx]->ACS.U) & FR_17_ERAY_A_STATUS_MASK;
      /* Channel A symbol window MTS status data */
      SymbWindValidMTSA = ((FR_SFR_RUNTIME_USER_MODE_READ32\
              (ERAY[Fr_CtrlIdx]->SWNIT.U) & FR_17_ERAY_A_SWNIT_VMTS_MASK) >> \
                                                FR_17_ERAY_A_SWNIT_VMTS_SHIFT);
      /* Channel A symbol window status data */
      SymbWindErrStatusA = (FR_SFR_RUNTIME_USER_MODE_READ32\
                 (ERAY[Fr_CtrlIdx]->SWNIT.U) & FR_17_ERAY_A_SWNIT_STATUS_MASK);
      /* Channel A NIT status data */
      NITStatusDataA = ((FR_SFR_RUNTIME_USER_MODE_READ32\
              (ERAY[Fr_CtrlIdx]->SWNIT.U) & FR_17_ERAY_A_NIT_STATUS_MASK)>>\
                                               FR_17_ERAY_A_NIT_STATUS_SHIFT);

      /* write channel status data to output parameter Fr_ChannelAStatusPtr */
      *Fr_ChannelAStatusPtr = (uint16)((AggrChaAStatusA)|
      (SymbWindValidMTSA << FR_17_ERAY_SWNIT_VMTS_SHIFT)|
      (SymbWindErrStatusA << FR_17_ERAY_SWNIT_STATUS_SHIFT)|
      (NITStatusDataA << FR_17_ERAY_NIT_STATUS_SHIFT));

      /*Channel B aggregated channel status */
      AggrChaAStatusB = ((FR_SFR_RUNTIME_USER_MODE_READ32\
                   (ERAY[Fr_CtrlIdx]->ACS.U) & FR_17_ERAY_B_STATUS_MASK) >> \
                                                        FR_17_ERAY_B_ACS_SHIFT);
      /* Channel A symbol window MTS status data */
      SymbWindValidMTSB = ((FR_SFR_RUNTIME_USER_MODE_READ32\
          (ERAY[Fr_CtrlIdx]->SWNIT.U) & FR_17_ERAY_B_SWNIT_VMTS_MASK) >>\
                                                 FR_17_ERAY_B_SWNIT_VMTS_SHIFT);
      /* Channel A symbol window status data */
      SymbWindErrStatusB = ((FR_SFR_RUNTIME_USER_MODE_READ32\
            (ERAY[Fr_CtrlIdx]->SWNIT.U) &  FR_17_ERAY_B_SWNIT_STATUS_MASK) >>\
                                               FR_17_ERAY_B_SWNIT_STATUS_SHIFT);
      /* Channel A NIT status data */
      NITStatusDataB = ((FR_SFR_RUNTIME_USER_MODE_READ32\
               (ERAY[Fr_CtrlIdx]->SWNIT.U) & FR_17_ERAY_B_NIT_STATUS_MASK) >>\
                                                 FR_17_ERAY_B_NIT_STATUS_SHIFT);

      /* write channel status data to output parameter Fr_ChannelAStatusPtr */
      *Fr_ChannelBStatusPtr = (uint16)((AggrChaAStatusB)|
      ( SymbWindValidMTSB << FR_17_ERAY_SWNIT_VMTS_SHIFT)|
      ((SymbWindErrStatusB) << FR_17_ERAY_SWNIT_STATUS_SHIFT)|
      ((NITStatusDataB) << FR_17_ERAY_NIT_STATUS_SHIFT));

      /* Reset the aggregated channel status info within the FlexRay controlle*/
      /* A flag is cleared by writing a 1 to the corresponding bit position.*/
      FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->ACS.U), \
                              (FR_17_ERAY_ACS_RESET & FR_17_ERAY_ACS_MASK));

    }
    else
    {
      RetValue = E_NOT_OK ;
    }
  }
  return RetValue ;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR564_FR566_FR569_FR570_FR571_FR572]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetClockCorrection
                          (
                           uint8 Fr_CtrlIdx,
                           sint16* Fr_RateCorrectionPtr,
                           sint32* Fr_OffsetCorrectionPtr
                          )
**
**                                                                            **
** [/cover]
**                                                                            **
** Service  ID:  0x29                                                         **
**                                                                            **
**  Sync/Asyn c:  Synchronous                                                 **
**                                                                            **
**  Reentrancy :  non reentrant for the same device                           **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out):                                                          **
**          Fr_RateCorrectionPtr - Address where the current rate correction  **
**               value shall be stored.                                       **
**            Fr_ChannelBStatusPtr - Address where the current offset         **
**                             correction                                     **
**               value shall be stored.                                       **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :Gets the current clock correction values.                     **
**                                                                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetClockCorrection(
    uint8 Fr_CtrlIdx,
    sint16* Fr_RateCorrectionPtr,
    sint32* Fr_OffsetCorrectionPtr
)
{
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETCLOCKCORRECTION);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETCLOCKCORRECTION);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_RateCorrectionPtr,FR_17_ERAY_SID_GETCLOCKCORRECTION);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_OffsetCorrectionPtr,FR_17_ERAY_SID_GETCLOCKCORRECTION);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }
  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Write Rate and offset Correction value to the output pointers */
    * Fr_RateCorrectionPtr = (sint16) FR_SFR_RUNTIME_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->RCV.U) ;
    * Fr_OffsetCorrectionPtr =(sint32) FR_SFR_RUNTIME_USER_MODE_READ32\
                                                    (ERAY[Fr_CtrlIdx]->OCV.U) ;
  }

  return RetValue ;
}

/*******************************************************************************
[cover parentID=
DS_AS40X_FR573_FR575_FR576_FR577_FR578_FR581_FR582_FR583_FR584_FR585_FR586]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetSyncFrameList
        (
             uint8 Fr_CtrlIdx,
             uint8 Fr_ListSize,
             uint16* Fr_ChannelAEvenListPtr,
             uint16* Fr_ChannelBEvenListPtr,
             uint16* Fr_ChannelAOddListPtr,
             uint16* Fr_ChannelBOddListPtr
        )
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service  ID:  0x2a                                                         **
**                                                                            **
** Sync/Asyn c:  Synchronous                                                  **
**                                                                            **
** Reentrancy :  non reentrant for the same device                            **
**                                                                            **
** Parameters (in): Fr_CtrlIdx -  Index of FlexRay CC within the context of the
                    FlexRay Driver.
                    Fr_ListSize - Size of the arrays passed via parameters:
                    Fr_ChannelAEvenListPtr
                    Fr_ChannelBEvenListPtr
                    Fr_ChannelAOddListPtr
                    Fr_ChannelBOddListPtr.
                  The service must ensure to not write more entries into
                  those arrays than granted by this parameter.

**                                                                            **
** Parameters (out):                                                          **
**  Fr_ChannelAEvenListPtr - Address the list of syncframes on channel
        A within the even communication cycle is written to. The exact number
        of elements written to the list is limited by parameter Fr_ListSize.
        Unused list elements are filled with the value '0' to indicate that
        no more syncframe has been seen.
    Fr_ChannelBEvenListPtr - Address the list of syncframes on channel B
        within the even communication cycle is written to. The exact number
        of elements written to the list is limited by parameter Fr_ListSize.
        Unused list elements are filled with the value '0' to indicate that
        no more syncframe has been seen.
    Fr_ChannelAOddListPtr - Address the list of syncframes on channel A
      within the odd communication cycle is written to. The exact number of
      elements written to the list is limited by parameter Fr_ListSize.
      Unused list elements are filled with the value '0' to indicate that
      no more syncframe has been seen.
    Fr_ChannelBOddListPtr - Address the list of syncframes on channel B
      within the odd communication cycle is written to. The exact number
      of elements written to the list is limited by parameter Fr_ListSize.
      Unused list elements are filled with the value '0' to indicate that
      no more syncframe has been seen.

** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :Gets a list of syncframes received or transmitted on
       channel A and channel B via the even and odd communication cycle       **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetSyncFrameList(
    uint8 Fr_CtrlIdx,
    uint8 Fr_ListSize,
    uint16* Fr_ChannelAEvenListPtr,
    uint16* Fr_ChannelBEvenListPtr,
    uint16* Fr_ChannelAOddListPtr,
    uint16* Fr_ChannelBOddListPtr
)
{
  Std_ReturnType RetValue;
  uint8 i ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETSYNCFRAMELIST);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETSYNCFRAMELIST);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    if (Fr_ListSize > FR_17_ERAY_MAX_LIST_SIZE)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
       FR_17_ERAY_SID_GETSYNCFRAMELIST,FR_17_ERAY_E_INV_LIST_SIZE);
      DevError = FR_17_ERAY_SID_GETSYNCFRAMELIST;
    }
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {

    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ChannelAEvenListPtr,FR_17_ERAY_SID_GETSYNCFRAMELIST);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ChannelBEvenListPtr,FR_17_ERAY_SID_GETSYNCFRAMELIST);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ChannelAOddListPtr,FR_17_ERAY_SID_GETSYNCFRAMELIST);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ChannelBOddListPtr,FR_17_ERAY_SID_GETSYNCFRAMELIST);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Initialise all 4 array values to 0 */
    for(i=0U; i< Fr_ListSize; i++)
    {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     Fr_ChannelAEvenListPtr[i] = 0U;
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     Fr_ChannelBEvenListPtr[i] = 0U;
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     Fr_ChannelAOddListPtr[i] = 0U;
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     Fr_ChannelBOddListPtr[i] = 0U;
    }

    /*  Frame Ids of the SYNC frames received in even Comm Cycle */
    for(i=0U; i< Fr_ListSize; i++)
    {
       /* If Even Sync ID received on Cha A */
       if (((FR_SFR_RUNTIME_USER_MODE_READ32\
                            (ERAY[Fr_CtrlIdx]->ESID_1S[i].U) & \
                      FR_ESID_RXEA_SETMASK) >> FR_17_ERAY_SHIFT_BIT_14) ==1U)
       {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
         Fr_ChannelAEvenListPtr[i] =
              (uint16)(FR_SFR_RUNTIME_USER_MODE_READ32\
                       (ERAY[Fr_CtrlIdx]->ESID_1S[i].U) & FR_ESID_EID_SETMASK);
       }

       /* Even Sync ID received on Cha B */
       if (((FR_SFR_RUNTIME_USER_MODE_READ32\
                            (ERAY[Fr_CtrlIdx]->ESID_1S[i].U) & \
                      FR_ESID_RXEB_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15) ==1U)
       {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
         Fr_ChannelBEvenListPtr[i] =
              (uint16)(FR_SFR_RUNTIME_USER_MODE_READ32\
                       (ERAY[Fr_CtrlIdx]->ESID_1S[i].U) & FR_ESID_EID_SETMASK);
       }
    }

    /*  Frame ids of the SYNC frames received in Odd comm. cycle */
    for(i=0U; i< Fr_ListSize; i++)
    {
       if (((FR_SFR_RUNTIME_USER_MODE_READ32\
            (ERAY[Fr_CtrlIdx]->OSID_1S[i].U) & FR_OSID_RXOA_SETMASK) \
                                           >> FR_17_ERAY_SHIFT_BIT_14) == 1U)
       /* Odd Sync ID received on ChaA */
       {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         Fr_ChannelAOddListPtr[i] = (uint16) (FR_SFR_RUNTIME_USER_MODE_READ32\
                       (ERAY[Fr_CtrlIdx]->OSID_1S[i].U) & FR_OSID_OID_SETMASK);
       }

       if (((FR_SFR_RUNTIME_USER_MODE_READ32\
            (ERAY[Fr_CtrlIdx]->OSID_1S[i].U) & FR_OSID_RXOB_SETMASK) \
                                   >> FR_17_ERAY_SHIFT_BIT_15) == 1U)
       /* Odd Sync ID received on Cha B*/
       {
         /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
         PBConfigStructure and is within allowed range.*/
         Fr_ChannelBOddListPtr[i] = (uint16)(FR_SFR_RUNTIME_USER_MODE_READ32\
                       (ERAY[Fr_CtrlIdx]->OSID_1S[i].U) & FR_OSID_OID_SETMASK);
       }
    }
  }
  return RetValue ;
}

/*******************************************************************************
[cover parentID=DS_AS40X_FR587_FR588_FR590_FR591_FR592]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetWakeupRxStatus
(
    uint8 Fr_CtrlIdx,
    uint8* Fr_WakeupRxStatusPtr
)

**                                                                            **
** [/cover]
**                                                                            **
** Service  ID:  0x2b                                                         **
**                                                                            **
** Sync/Asyn c:  Synchronous                                                  **
**                                                                            **
** Reentrancy :  non reentrant for the same device                            **
**                                                                            **
** Parameters (in): Fr_CtrlIdx -  Index of FlexRay CC within the context of the
                    FlexRay Driver.
**                                                                            **
** Parameters (out):                                                          **
**  Fr_WakeupRxStatusPtr - Address where bitcoded wakeup reception status
      shall be stored.
    Bit 0: Wakeup received on channel A indicator
    Bit 1: Wakeup received on channel B indicator
    Bit 2-7: Unused

** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Gets the wakeup received information from the FlexRay
                 controller.                                                  **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetWakeupRxStatus(
    uint8 Fr_CtrlIdx,
    uint8* Fr_WakeupRxStatusPtr
)
{
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETWAKEUPRXSTATUS);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_GETWAKEUPRXSTATUS);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_WakeupRxStatusPtr,FR_17_ERAY_SID_GETWAKEUPRXSTATUS);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */

  {
    /* Write the Wakeup pattern received on channel A and B to output
     parameter*/
    *Fr_WakeupRxStatusPtr = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                       (ERAY[Fr_CtrlIdx]->SIR.U) & FR_SIR_WUPA_SETMASK) \
                                              >> FR_17_ERAY_SHIFT_BIT_16);
    *Fr_WakeupRxStatusPtr |= (uint8)((uint32)((FR_SFR_RUNTIME_USER_MODE_READ32\
                            (ERAY[Fr_CtrlIdx]->SIR.U) & FR_SIR_WUPB_SETMASK) \
                      >> FR_17_ERAY_SHIFT_BIT_24) << FR_17_ERAY_SHIFT_BIT_1);

    /* Reset the wakeup received indication status information within
       the FlexRay controller */
    /* A flag is cleared by writing a 1 to the corresponding bit position.
      Writing a 0 has no effect on the flag*/
     FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIR.U), \
                                                         FR_17_ERAY_SIR_RESET);
  }
  return RetValue ;

}

/*******************************************************************************
[cover parentID=
DS_AS_FR033_FR106_FR267_FR268_FR269_FR270_FR271_FR273_FR345_FR436_FR473_FR489]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_SetAbsoluteTimer(                       **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx,                   **
**                                    uint8 Fr_Cycle,                         **
**                                    uint16 Fr_Offset                        **
**                         )                                                  **
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x11                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                  Fr_Cycle - Absolute cycle the timer shall elapse in.      **
**                  Fr_Offset - Offset within cycle Cycle in units of         **
**                              macrotick the timer shall elapse at.          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Sets the absolute FlexRay timer.                            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_SetAbsoluteTimer(
                                             uint8 Fr_CtrlIdx,
                                             uint8 Fr_AbsTimerIdx,
                                             uint8 Fr_Cycle,
                                             uint16 Fr_Offset
                                           )
{
  Std_ReturnType RetValue ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #else
  UNUSED_PARAMETER(Fr_AbsTimerIdx)
  #endif

  RetValue = E_OK ;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                 (Fr_CtrlIdx,FR_17_ERAY_SID_SETABSOLUTETIMER);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                             FR_17_ERAY_SID_SETABSOLUTETIMER);
  }
  /* Driver is not initialized, avoid register access */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*
      FR_17_ERAY_E_INV_POCSTATE if controller is not synchronised to
      global time
    */
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 0U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                  FR_17_ERAY_SID_SETABSOLUTETIMER, FR_17_ERAY_E_INV_POCSTATE);
      DevError = FR_17_ERAY_E_INV_POCSTATE;
    }
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_OFFSET */
    /* Note: Valid Offset is 0 .. (gMacroPerCycle - 1) */
    /* DevError is re-used to read the GTUC02 register to avoid the static
       analysis issue */
    DevError = FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->GTUC02.U);
    DevError = DevError & FR_GTUC02_MPC_SETMASK;

    if (Fr_Offset >= (uint16)DevError)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                 FR_17_ERAY_SID_SETABSOLUTETIMER, FR_17_ERAY_E_INV_OFFSET);
      DevError = FR_17_ERAY_E_INV_OFFSET;
    }
    else
    {
      DevError = FR_17_ERAY_E_DET_NO_ERR;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_TIMER_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidTimerIdx(Fr_AbsTimerIdx,
                                             FR_17_ERAY_SID_SETABSOLUTETIMER);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CYCLE */
    if (Fr_Cycle > (uint8)FR_17_ERAY_MAX_CYCLE_INDEX )
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                    FR_17_ERAY_SID_SETABSOLUTETIMER, FR_17_ERAY_E_INV_CYCLE);
      DevError = FR_17_ERAY_E_INV_CYCLE;
    }
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    if (Fr_17_Eray_lIsCCInSync(Fr_CtrlIdx) == 1U)
    {
      /* Halt the timer */
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->T0C.U),\
                                                   FR_T0C_T0RC_CLEARMASK, 0U)

      /* Set cycle value to elapse at cycle count Cycle, once every 64 cycles*/
      /* Set macrotick offset and Timer mode (Continuous) */
      FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->T0C.U),
      (unsigned_int)(((FR_17_ERAY_TIMER_CYCLECODE_ONCE_IN_64 | (uint32)Fr_Cycle)
                                         << FR_17_ERAY_TIMER_CYCLECODE_SHIFT) |
                      ((uint32)Fr_Offset << FR_17_ERAY_TIMER_MACROTICK_SHIFT) |
                                                  FR_17_ERAY_TIMER_MODE_MASK));

      /* Start the timer */
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->T0C.U),\
                                                   FR_T0C_T0RC_CLEARMASK, 1U)
    }
    else
    {
      RetValue = E_NOT_OK ;
    }
  }

  return RetValue ;
}

/*******************************************************************************
[cover parentID=DS_AS_FR070_FR095_FR283_FR284_FR285_FR287]**
** Syntax : Std_ReturnType Fr_17_Eray_CancelAbsoluteTimer(                    **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x13                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Stops an absolute timer.                                    **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_CancelAbsoluteTimer(
                                               uint8 Fr_CtrlIdx,
                                               uint8 Fr_AbsTimerIdx
                                             )
{
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #else
  UNUSED_PARAMETER(Fr_AbsTimerIdx)
  #endif


  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                         FR_17_ERAY_SID_CANCELABSOLUTETIMER);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                         FR_17_ERAY_SID_CANCELABSOLUTETIMER);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_TIMER_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidTimerIdx(Fr_AbsTimerIdx,
                                         FR_17_ERAY_SID_CANCELABSOLUTETIMER);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }
  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* TODO: Why is this required? Without this CLRR doesn't clear SRR */
    /* Disable Timer Service Request 0 */
    FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIER.U), \
                                                   FR_17_ERAY_SIER_TI0E_MASK) ;

    /* Halt the timer */
    FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->T0C.U),\
                                                   FR_T0C_T0RC_CLEARMASK, 0U)
  }
  return RetValue ;
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR034_FR294_FR295_FR296_FR298]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_EnableAbsoluteTimerIRQ(                 **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x15                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Enables the interrupt line of an absolute timer.            **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_EnableAbsoluteTimerIRQ(
                                                   uint8 Fr_CtrlIdx,
                                                   uint8 Fr_AbsTimerIdx
                                                 )
{
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #else
  UNUSED_PARAMETER(Fr_AbsTimerIdx)
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                       FR_17_ERAY_SID_ENABLEABSOLUTETIMERIRQ);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                       FR_17_ERAY_SID_ENABLEABSOLUTETIMERIRQ);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_TIMER_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidTimerIdx(Fr_AbsTimerIdx,
                                       FR_17_ERAY_SID_ENABLEABSOLUTETIMERIRQ);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Clear any pending Timer Service Request 0 flag */
    FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIR.U), \
                                                     FR_17_ERAY_SIR_TI0_MASK) ;

    /* Enable Timer Service Request 0 */
    FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIES.U), \
                                                   FR_17_ERAY_SIES_TI0E_MASK) ;
  }
  return RetValue ;
}

/*******************************************************************************
[cover parentID=DS_AS_FR036_FR305_FR306_FR307_FR309]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_AckAbsoluteTimerIRQ(                    **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x17                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Resets the interrupt condition of an absolute timer.        **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_AckAbsoluteTimerIRQ(
                                               uint8 Fr_CtrlIdx,
                                               uint8 Fr_AbsTimerIdx
                                             )
{
  Std_ReturnType RetValue;
  volatile uint32 *RegAddress;
  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #else
  UNUSED_PARAMETER(Fr_AbsTimerIdx)
  #endif
  UNUSED_PARAMETER(Fr_CtrlIdx)
  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                        FR_17_ERAY_SID_ACKABSOLUTETIMERIRQ);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                        FR_17_ERAY_SID_ACKABSOLUTETIMERIRQ);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_TIMER_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidTimerIdx(Fr_AbsTimerIdx,
                                        FR_17_ERAY_SID_ACKABSOLUTETIMERIRQ);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
     /* Clear Timer Service Request 0 flag */
     RegAddress =(volatile uint32 *)(volatile void *)SRC_FRTINT0[Fr_CtrlIdx];
    /* Clear Timer Service Request 0 flag */
     FR_SFR_RUNTIME_MODIFY32((*RegAddress), \
                        FR_SRC_FRTINT0_CLRR_CLEARMASK, ERAY_SRC_MASK_NOCLEAR)
  }
  return RetValue ;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR035_FR316_FR317_FR318_FR320]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_DisableAbsoluteTimerIRQ(                **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx                    **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x19                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Disables the interrupt line of an absolute timer.           **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_DisableAbsoluteTimerIRQ(
                                                   uint8 Fr_CtrlIdx,
                                                   uint8 Fr_AbsTimerIdx
                                                 )
{
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #else
  UNUSED_PARAMETER(Fr_AbsTimerIdx)
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                     FR_17_ERAY_SID_DISABLEABSOLUTETIMERIRQ);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                     FR_17_ERAY_SID_DISABLEABSOLUTETIMERIRQ);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_TIMER_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidTimerIdx(Fr_AbsTimerIdx,
                                     FR_17_ERAY_SID_DISABLEABSOLUTETIMERIRQ);
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Disable Timer Service Request 0 */
    FR_SFR_RUNTIME_USER_MODE_WRITE32((ERAY[Fr_CtrlIdx]->SIER.U), \
                                                   FR_17_ERAY_SIER_TI0E_MASK) ;
  }
  return RetValue ;
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FR108_FR327_FR328_FR329_FR330_FR332]
** Traceability : [cover parentID=DS_AS_FR025_1]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_GetAbsoluteTimerIRQStatus(              **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint8 Fr_AbsTimerIdx,                   **
**                                    boolean* Fr_IRQStatusPtr                **
**                         )                                                  **
**                                                                            **
** [/cover]
**                                                                            **
** Service ID:  0x20                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_AbsTimerIdx - Index of absolute timer within the       **
**                                    context of the FlexRay CC.              **
**                                                                            **
** Parameters (out): Fr_IRQStatusPtr                                          **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :  Gets IRQ status of an absolute timer.                       **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_GetAbsoluteTimerIRQStatus(
                                                     uint8 Fr_CtrlIdx,
                                                     uint8 Fr_AbsTimerIdx,
                                                     boolean* Fr_IRQStatusPtr
                                                   )
{
  uint32 SiesReg;
  Std_ReturnType RetValue;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;
  #else
  UNUSED_PARAMETER(Fr_AbsTimerIdx)
  #endif

  RetValue = E_OK;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                   FR_17_ERAY_SID_GETABSOLUTETIMERIRQSTATUS);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                   FR_17_ERAY_SID_GETABSOLUTETIMERIRQSTATUS);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_TIMER_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidTimerIdx(Fr_AbsTimerIdx,
                                   FR_17_ERAY_SID_GETABSOLUTETIMERIRQSTATUS);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(Fr_IRQStatusPtr,
                                   FR_17_ERAY_SID_GETABSOLUTETIMERIRQSTATUS) ;
  }
  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

 if(RetValue == E_OK)
 #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /* for Misra Rule 12.4, side effects on
      right hand of logical operator: '&&' */
    SiesReg = FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->SIES.U);
    /* Write status into output parameter */
    if ( (((FR_SFR_RUNTIME_USER_MODE_READ32(SRC_FRTINT0[Fr_CtrlIdx]->U) & \
            FR_SRC_ERAYTINT0_SRR_SETMASK) >> FR_17_ERAY_SHIFT_BIT_24) != 0U) &&
                                ((SiesReg & FR_17_ERAY_SIES_TI0E_MASK) !=0U))
    {
      *Fr_IRQStatusPtr = (boolean)TRUE;
    }
    else
    {
      *Fr_IRQStatusPtr = (boolean)FALSE;
    }
  }
  return RetValue ;
}

/*******************************************************************************
** Traceability :
[cover parentID=DS_AS_FR651_FR653_FR654_FR655_FR656_FR658_FR659_FR660_FR661,
DS_AS_FR662,DS_AS_FR663,DS_AS_FR664,DS_AS_FR665,DS_AS_FR666,DS_AS402_FR660]
**                                                                            **
** Syntax : Std_ReturnType Fr_17_Eray_ReadCCConfig
            (
              uint8 Fr_CtrlIdx,
              uint8 Fr_ConfigParamIdx,
              uint32* Fr_ConfigParamValuePtr
            )
**                                                                            **
** [/cover]
** [/cover]
**                                                                            **
** Service ID:  0x2e                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_ConfigParamIdx - Index that identifies the
                               configuration parameter to read.               **
**                                                                            **
** Parameters (out): Fr_ConfigParamValuePtr - Address the output value is
                     stored to.                                               **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description :Reads a FlexRay protocol configuration parameter for a
        particular FlexRay controller out of the module's configuration.      **
**                                                                            **
*******************************************************************************/
Std_ReturnType Fr_17_Eray_ReadCCConfig(
                                        uint8 Fr_CtrlIdx,
                                        uint8 Fr_ConfigParamIdx,
                                        uint32* Fr_ConfigParamValuePtr
                                      )
{
  Std_ReturnType RetValue ;
  const Fr_17_Eray_CCConfigType *CCConfigPtr;
  const Fr_17_ReadCCParametersType *CCConfigParmPtr;
  uint8 LogIdx;

  #if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
  uint32 DevError ;

  RetValue = E_OK;

  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_READCCCONFIG);

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                      FR_17_ERAY_SID_READCCCONFIG);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_HEADERCRC (0 - 63)*/
    if (Fr_ConfigParamIdx > FR_17_ERAY_CONFIG_PARAM_IDX_MAX )
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                     FR_17_ERAY_SID_READCCCONFIG, FR_17_ERAY_E_INV_CONFIG_IDX);
      DevError = FR_17_ERAY_E_INV_CONFIG_IDX;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
       (void *)Fr_ConfigParamValuePtr,FR_17_ERAY_SID_READCCCONFIG);
  }

  /* Return if a development error occured */
  if (DevError != FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_NOT_OK;
  }

  if(RetValue == E_OK)
  #endif /* (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* Assign configured value in Flexray CC to output parameter */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    CCConfigPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].CCCfgPtr;
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    CCConfigParmPtr = Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].ConfigParamPtr;

    switch (Fr_ConfigParamIdx)
    {
      case FR_CIDX_GDCYCLE :
        *Fr_ConfigParamValuePtr = CCConfigParmPtr->FrIfGdCycle;
        RetValue = E_OK;
        break;

      case FR_CIDX_PMICROPERCYCLE :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC01.B.UT;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PDLISTENTIMEOUT :
        *Fr_ConfigParamValuePtr = CCConfigPtr->SUCC2.B.pdListenTimeout;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GMACROPERCYCLE :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC02.B.gMacroPerCycle;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDMACROTICK :
        *Fr_ConfigParamValuePtr = (uint32)CCConfigParmPtr->FrIfGdMacrotick;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GNUMBEROFMINISLOTS :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC08.B.gNumberOfMinislots;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GNUMBEROFSTATICSLOTS :
        *Fr_ConfigParamValuePtr =
                         CCConfigPtr->GTUC07.B.gNumberOfStaticSlots;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDNIT :
        *Fr_ConfigParamValuePtr = (uint32)CCConfigParmPtr->FrIfGdNit;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDSTATICSLOT :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC07.B.gdStaticSlot;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDWAKEUPRXWINDOW :
        *Fr_ConfigParamValuePtr =
                  CCConfigPtr->PRTC1.B.gdWakeupSymbolRxWindow;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PKEYSLOTID :
        *Fr_ConfigParamValuePtr = (uint32)CCConfigParmPtr->FrPKeySlotId ;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PLATESTTX  :
        *Fr_ConfigParamValuePtr = CCConfigPtr->MHDC.B.pLatestTx;
        RetValue = E_OK;
        break ;

      case FR_CIDX_POFFSETCORRECTIONOUT :
        *Fr_ConfigParamValuePtr =
          CCConfigPtr->GTUC10.B.pOffsetCorrectionOut;
        RetValue = E_OK;
        break ;

      case FR_CIDX_POFFSETCORRECTIONSTART :
        *Fr_ConfigParamValuePtr =
          ((uint32)(CCConfigPtr->GTUC04.B.gOffsetCorrectionStartMinusOne)+1U);
        RetValue = E_OK;
        break ;

      case FR_CIDX_PRATECORRECTIONOUT :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC10.B.pRateCorrectionOut;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PSECONDKEYSLOTID :
      /* For FlexRay Protocol 2.1 Rev A compliance hardware this should be 0 */
        *Fr_ConfigParamValuePtr = 0U;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PDACCEPTEDSTARTUPRANGE :
        *Fr_ConfigParamValuePtr =
            CCConfigPtr->GTUC06.B.pdAcceptedStartupRange;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GCOLDSTARTATTEMPTS :
        *Fr_ConfigParamValuePtr = CCConfigPtr->SUCC1.B.gColdStartAttempts;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GCYCLECOUNTMAX:
        *Fr_ConfigParamValuePtr = (uint32)CCConfigParmPtr->FrIfGCycleCountMax ;
        RetValue = E_OK;
        break;

      case FR_CIDX_GLISTENNOISE:
        *Fr_ConfigParamValuePtr =
          ((uint32)(CCConfigPtr->SUCC2.B.gListenNoiseMinusOne)+1U);
        RetValue = E_OK;
        break;

      case FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL:
        *Fr_ConfigParamValuePtr =
               CCConfigPtr->SUCC3.B.gMaxWithoutClockCorrectionFatal;
        RetValue = E_OK;
        break;

      case FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE:
          *Fr_ConfigParamValuePtr =
             CCConfigPtr->SUCC3.B.gMaxWithoutClockCorrectionPassive;
          RetValue = E_OK;
          break;

      case FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH :
        *Fr_ConfigParamValuePtr =
                 CCConfigPtr->NEMC.B.gNetworkManagementVectorLength;
        RetValue = E_OK;
        break;

      case FR_CIDX_GPAYLOADLENGTHSTATIC :
        *Fr_ConfigParamValuePtr = CCConfigPtr->MHDC.B.gPayloadLengthStatic;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GSYNCFRAMEIDCOUNTMAX :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC02.B.gSyncNodeMax;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDACTIONPOINTOFFSET :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC09.B.gdActionPointOffset;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDBIT :
        *Fr_ConfigParamValuePtr = CCConfigParmPtr->FrIfGdBit ;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDCASRXLOWMAX :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC1.B.gdCASRxLowMax;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDDYNAMICSLOTIDLEPHASE :
        *Fr_ConfigParamValuePtr =
                   CCConfigPtr->GTUC09.B.gdDynamicSlotIdlePhase;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDMINISLOTACTIONPOINTOFFSET :
        *Fr_ConfigParamValuePtr =
                     CCConfigPtr->GTUC09.B.gdMinislotActionPointOffset;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDMINISLOT :
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC08.B.gdMinislot;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDSAMPLECLOCKPERIOD :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC1.B.Brp;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDSYMBOLWINDOW :
        *Fr_ConfigParamValuePtr = (uint32)CCConfigParmPtr->FrIfGdSymbolWindow;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET  :
        *Fr_ConfigParamValuePtr =
                               CCConfigPtr->GTUC09.B.gdActionPointOffset;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDTSSTRANSMITTER :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC1.B.gdTSSTransmitter;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDWAKEUPRXIDLE :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC2.B.gdWakeupSymbolRxIdle;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDWAKEUPRXLOW :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC2.B.gdWakeupSymbolRxLow;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDWAKEUPTXACTIVE :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC2.B.gdWakeupTxActive;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDWAKEUPTXIDLE :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC2.B.gdWakeupSymbolTxIdle;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PALLOWPASSIVETOACTIVE :
        *Fr_ConfigParamValuePtr = CCConfigPtr->SUCC1.B.pAllowPassiveToActive;
        RetValue = E_OK;
        break;

      case FR_CIDX_PCHANNELS :
        *Fr_ConfigParamValuePtr =
                   ((uint32)CCConfigPtr->SUCC1.B.pChannels - 1U);
        RetValue = E_OK;
        break ;

      case FR_CIDX_PCLUSTERDRIFTDAMPING:
        *Fr_ConfigParamValuePtr =
                             CCConfigPtr->GTUC05.B.pClusterDriftDamping;
        RetValue = E_OK;
        break;

      case FR_CIDX_PDECODINGCORRECTION:
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC05.B.pDecodingCorrection;
        RetValue = E_OK;
        break;

      case FR_CIDX_PDELAYCOMPENSATIONA:
        *Fr_ConfigParamValuePtr = CCConfigPtr->GTUC05.B.pDelayCompensationA;
        RetValue = E_OK;
        break;

      case FR_CIDX_PDELAYCOMPENSATIONB:
          *Fr_ConfigParamValuePtr =
                          CCConfigPtr->GTUC05.B.pDelayCompensationB;
          RetValue = E_OK;
          break;

      case FR_CIDX_PMACROINITIALOFFSETA :
        *Fr_ConfigParamValuePtr =
                             CCConfigPtr->GTUC03.B.pMacroInitialOffsetA;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PMACROINITIALOFFSETB :
        *Fr_ConfigParamValuePtr =
                           CCConfigPtr->GTUC03.B.pMacroInitialOffsetB;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PMICROINITIALOFFSETA :
        *Fr_ConfigParamValuePtr =
                        CCConfigPtr->GTUC03.B.pMicroInitialOffsetA;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PMICROINITIALOFFSETB :
        *Fr_ConfigParamValuePtr =
                        CCConfigPtr->GTUC03.B.pMicroInitialOffsetB;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PPAYLOADLENGTHDYNMAX :
        *Fr_ConfigParamValuePtr =
                         (uint32)CCConfigParmPtr->FrPPayloadLengthDynMax;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PSAMPLESPERMICROTICK :
      /* For FlexRay Protocol 2.1 Rev A compliance hardware
         this should be 2 (N4SAMPLES) */
        *Fr_ConfigParamValuePtr = N4SAMPLES;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PWAKEUPCHANNEL :
        *Fr_ConfigParamValuePtr = (uint32)CCConfigPtr->SUCC1.B.pWakeupChannel;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PWAKEUPPATTERN :
        *Fr_ConfigParamValuePtr = CCConfigPtr->PRTC1.B.pWakeupPattern;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PDMICROTICK :
        *Fr_ConfigParamValuePtr = CCConfigParmPtr->FrPdMicrotick;
        RetValue = E_OK;
        break ;

      case FR_CIDX_GDIGNOREAFTERTX :
        *Fr_ConfigParamValuePtr = 0U;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PALLOWHALTDUETOCLOCK  :
        *Fr_ConfigParamValuePtr =
                       CCConfigPtr->SUCC1.B.pAllowHaltDueToClock;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PEXTERNALSYNC :
        /* For FlexRay Protocol 2.1 Rev A compliance hardware this
           should be 0 */
        *Fr_ConfigParamValuePtr = 0U;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PFALLBACKINTERNAL :
        /* For FlexRay Protocol 2.1 Rev A compliance hardware this
           should be 0 */
        *Fr_ConfigParamValuePtr = 0U;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PKEYSLOTONLYENABLED :
        *Fr_ConfigParamValuePtr =
                  CCConfigPtr->SUCC1.B.pSingleSlotEnabled;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PKEYSLOTUSEDFORSTARTUP :
        *Fr_ConfigParamValuePtr =
                   CCConfigPtr->SUCC1.B.pKeySlotUsedForStartup;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PKEYSLOTUSEDFORSYNC :
        *Fr_ConfigParamValuePtr =
               CCConfigPtr->SUCC1.B.pKeySlotUsedForSync;
        RetValue = E_OK;
        break ;

      case FR_CIDX_PNMVECTOREARLYUPDATE :
        /* For FlexRay Protocol 2.1 Rev A compliance hardware this should be 0*/
        *Fr_ConfigParamValuePtr = 0U;
        RetValue = E_OK;
        break;

      case FR_CIDX_PTWOKEYSLOTMODE :
        /* For FlexRay Protocol 2.1 Rev A compliance hardware this should be 0*/
        *Fr_ConfigParamValuePtr = 0U;
        RetValue = E_OK;
        break ;

      default:
        RetValue = E_NOT_OK;
        break ;
    }
  }
  return RetValue;
}

/*******************************************************************************
**                      Local Function Definitions                            **
*******************************************************************************/
/*******************************************************************************
** Syntax : uint32 Fr_17_Eray_lChangePOCState(uint8 Fr_CtrlIdx,uint8 ChiCmdId,**
**                                            uint8 ApiAccessId)              **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): uint8 Fr_CtrlIdx, uint8 ChiCmdId, uint8 ApiAccessId       **
**                                                                            **
** Parameters (out):  uint32    ErrCount                                      **
**                                                                            **
** Return value:  zero     : Function call finished successfully.             **
**                non-zero : Function call aborted due to error (time out)    **
**                                                                            **
** Description : Function to change ERAY POC state                            **
**                                                                            **
*******************************************************************************/
static uint32 Fr_17_Eray_lChangePOCState(uint8 Fr_CtrlIdx,
                                          uint8 ChiCmdId,uint8 ApiAccessId)
{
  uint32 TimeOutCount ;
  uint32 ErrCount ;
  volatile uint8 PbsyChk;
  volatile uint8 ChiCmdChk;
  uint8 LogIdx;
  ErrCount = 0U;

  /* wait till the SUCC1.PBSY bit is cleared  */
  TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION;
  do
  {
    TimeOutCount-- ;
    if(ApiAccessId == FR_INIT_API_ACCESS)
    {
      #ifdef IFX_ERAY_DEBUG
      PbsyChk = (uint8)((FR_SFR_INIT_USER_MODE_READ32( \
                                              ERAY[Fr_CtrlIdx]->SUCC1.U)\
                         & FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7) \
                    | (uint8)(TestFr_DebugMaskPbsy >> FR_17_ERAY_DEBUG_NUM_7);
      #else
      PbsyChk = (uint8)((FR_SFR_INIT_USER_MODE_READ32( \
                                              ERAY[Fr_CtrlIdx]->SUCC1.U)\
                          & FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7);
      #endif
    }
    else
    {
      #ifdef IFX_ERAY_DEBUG
      PbsyChk = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32( \
                                              ERAY[Fr_CtrlIdx]->SUCC1.U)\
                       & FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7) \
                     | (uint8)(TestFr_DebugMaskPbsy >> FR_17_ERAY_DEBUG_NUM_7);
      #else
      PbsyChk = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32( \
                                              ERAY[Fr_CtrlIdx]->SUCC1.U)\
                            & FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7);
      #endif
    }
  }while ((PbsyChk==1U) && (TimeOutCount > 0U)) ;

 /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
 LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
  /* Report time out error to DEM */
  if (TimeOutCount == 0U)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
      DEM_REPORT_DISABLED)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                              CfgPtr[LogIdx].FrDemTimeoutId,
                            DEM_EVENT_STATUS_FAILED);
    }
    ErrCount++ ;
  }
  else
  {
    if(ApiAccessId == FR_INIT_API_ACCESS)
    {
      FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->SUCC1.U),\
                                              FR_SUCC1_CMD_CLEARMASK, ChiCmdId)

      #ifdef IFX_ERAY_DEBUG
      ChiCmdChk = (uint8)((FR_SFR_INIT_USER_MODE_READ32 \
                 (ERAY[Fr_CtrlIdx]->SUCC1.U) & FR_SUCC1_CMD_SETMASK) \
                                     & ((uint8)(TestFr_DebugMaskChangeState)));
      #else
      ChiCmdChk =
           (uint8)(FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->SUCC1.U) & \
                                                        FR_SUCC1_CMD_SETMASK);
      #endif
    }
    else
    {
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->SUCC1.U),\
                                              FR_SUCC1_CMD_CLEARMASK, ChiCmdId)

      #ifdef IFX_ERAY_DEBUG
      ChiCmdChk = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32 \
                 (ERAY[Fr_CtrlIdx]->SUCC1.U) & FR_SUCC1_CMD_SETMASK) \
                                     & ((uint8)(TestFr_DebugMaskChangeState)));
      #else
      ChiCmdChk = (uint8)(FR_SFR_RUNTIME_USER_MODE_READ32( \
                           ERAY[Fr_CtrlIdx]->SUCC1.U) & FR_SUCC1_CMD_SETMASK);
      #endif
    }

    if (ChiCmdChk == FR_17_ERAY_CHI_CMD_NOT_ACCEPTED)
    {
      ErrCount++ ;
    }
  }

  return ErrCount ;
}

/*******************************************************************************
** Syntax : static uint32 Fr_17_Eray_lWaitTillPOCStateChange(uint8 Fr_CtrlIdx,**
**                                  uint8 PocState,uint8 ApiAccessId)         **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): uint8 Fr_CtrlIdx, uint8 PocState, uint8 ApiAccessId       **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  zero     : Function call finished successfully.             **
**                non-zero : Function call aborted due to error (time out)    **
**                                                                            **
** Description : Function to wait for ERAY POC state change                   **
**                                                                            **
*******************************************************************************/
static uint32 Fr_17_Eray_lWaitTillPOCStateChange(
                        uint8 Fr_CtrlIdx,uint8 PocState,uint8 ApiAccessId)
{
  uint32 TimeOutCount ;
  uint32 ErrorCount ;
  uint8 LogIdx;
  volatile uint8 Pocs;
  ErrorCount = 0U ;
  TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION ;

  do
  {
    TimeOutCount-- ;
    if(ApiAccessId == FR_INIT_API_ACCESS)
    {
      #ifdef IFX_ERAY_DEBUG
      Pocs = (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U) & \
                        FR_CCSV_POCS_SETMASK)|(uint8)TestFr_DebugMaskWaitState);
      #else
      Pocs = (uint8)(FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U) & \
                                                         FR_CCSV_POCS_SETMASK);
      #endif
    }
    else
    {
      #ifdef IFX_ERAY_DEBUG
      Pocs = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U)\
                    & FR_CCSV_POCS_SETMASK)|(uint8)TestFr_DebugMaskWaitState);
      #else
      Pocs = (uint8)(FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U)\
                                               & FR_CCSV_POCS_SETMASK);
      #endif
    }
  }  while ((Pocs != PocState) && (TimeOutCount > 0U)) ;

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];

  if (TimeOutCount == 0U)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
      DEM_REPORT_DISABLED)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                                CfgPtr[LogIdx].FrDemTimeoutId,
                            DEM_EVENT_STATUS_FAILED);
    }
    ErrorCount++ ;
  }

  return ErrorCount ;
}

/*******************************************************************************
** Syntax : static void Fr_17_Eray_lChangePOCStateToReady(uint8 Fr_CtrlIdx,   **
**                                   uint8 ExclusiveArea, uint8 ApiAccessId)  **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): uint8 Fr_CtrlIdx, uint8 ExclusiveArea,uint8 ApiAccessId   **
**                                                                            **
** Parameters (out):  none                                                    **
**                                                                            **
** Return value:  none                                                        **
**                                                                            **
** Description :                                                              **
**   Switch the CC to POC:Ready state.                                        **
**   Hardware requires uninterrupted execution of lock sequence, hence the    **
**   need to disable all interrupts.                                          **
**                                                                            **
*******************************************************************************/
static void Fr_17_Eray_lChangePOCStateToReady(
                    uint8 Fr_CtrlIdx, uint8 ExclusiveArea,uint8 ApiAccessId)
{
  uint32 TimeOutCount;
  volatile uint8 PbsyChk;
  volatile uint8 TrigAPI;
  uint8 LogIdx;
  TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION;
  TrigAPI = ExclusiveArea;

  /* Enter Critical Section */
  if(TrigAPI == FR_17_ERAY_EA_CONTROLLERINIT)
  {
    SchM_Enter_Fr_17_Eray_ControllerInit();
  }
  else
  {
    SchM_Enter_Fr_17_Eray_SetWakeupChannel();
  }

  if(ApiAccessId == FR_INIT_API_ACCESS)
  {
    /* Lock sequence start */
    FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->LCK.U), \
                                  FR_LCK_CLK_CLEARMASK, FR_17_ERAY_UNLOCK_SEQ1)
    FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->LCK.U), \
                                  FR_LCK_CLK_CLEARMASK, FR_17_ERAY_UNLOCK_SEQ2)
  }
  else
  {
    /* Lock sequence start */
    FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->LCK.U), \
                                  FR_LCK_CLK_CLEARMASK, FR_17_ERAY_UNLOCK_SEQ1)
    FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->LCK.U), \
                                  FR_LCK_CLK_CLEARMASK, FR_17_ERAY_UNLOCK_SEQ2)
  }

  /* wait till the SUCC1.PBSY bit is cleared  */
  do
  {
    TimeOutCount-- ;
    if(ApiAccessId == FR_INIT_API_ACCESS)
    {
      #ifdef IFX_ERAY_DEBUG
      PbsyChk =
        (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->SUCC1.U) & \
                            FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7) \
                    | (uint8)(TestFr_DebugMaskReady >> FR_17_ERAY_SHIFT_BIT_7);
      #else
      PbsyChk =
        (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->SUCC1.U) & \
                            FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7);
      #endif
    }
    else
    {
      #ifdef IFX_ERAY_DEBUG
      PbsyChk =
        (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->SUCC1.U) & \
                            FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7) \
                    | (uint8)(TestFr_DebugMaskReady >> FR_17_ERAY_SHIFT_BIT_7);
      #else
      PbsyChk =
        (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->SUCC1.U) & \
                            FR_SUCC1_PBSY_SETMASK) >> FR_17_ERAY_SHIFT_BIT_7);
      #endif
    }
  }while ((PbsyChk==1U) && (TimeOutCount > 0U)) ;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
  /* Report time out error to DEM */
  if (TimeOutCount == 0U)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
      DEM_REPORT_DISABLED)
    {
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                            CfgPtr[LogIdx].FrDemTimeoutId,
                            DEM_EVENT_STATUS_FAILED);
    }
  }

  if(ApiAccessId == FR_INIT_API_ACCESS)
  {
    /* Switch CC into 'POC:ready'*/
    FR_SFR_INIT_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->SUCC1.U), \
                              FR_SUCC1_CMD_CLEARMASK, FR_17_ERAY_CHI_CMD_READY)
  }
  else
  {
    /* Switch CC into 'POC:ready'*/
    FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->SUCC1.U), \
                              FR_SUCC1_CMD_CLEARMASK, FR_17_ERAY_CHI_CMD_READY)
  }
  /* Lock sequence end */

  /* Exit Critical Section */
  if(TrigAPI == FR_17_ERAY_EA_CONTROLLERINIT)
  {
    SchM_Exit_Fr_17_Eray_ControllerInit();
  }
  else
  {
    SchM_Exit_Fr_17_Eray_SetWakeupChannel();
  }

  return ;
}

#if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON)
/*******************************************************************************
** Syntax : uint32 Fr_17_Eray_lHeaderCRC(uint32 FrameId,                      **
**                                       uint8 PayloadLength                  **
**                                     )                                      **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): FrameId -  Dynamic Frame ID                               **
**             PayloadLength - Payload length                                 **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:  HeaderCRC                                                   **
**                                                                            **
** Description :                                                              **
**   Used to Re Calulate Header CRC for Dynamic frames                        **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lHeaderCRC(
  uint32 FrameId,
  uint8 PayloadLength
)
{
  uint32 vCrcReg;
  uint32 vCrcPoly;
  uint32 vNextBitCrcReg;
  uint32 vCrcNext;
  uint32 length;
  uint32 Header;
  uint32 vNextBitHeader ;

  Header = (FrameId << FR_17_ERAY_HEADER_FID_BITPOS) | PayloadLength ;
  /* Initial value for Header CRC - 0x1A */
  vCrcReg = FR_17_ERAY_HEADER_VECTOR_INITVAL ;
  /* Flexray header CRC polynomial - 0x385U */
  vCrcPoly = FR_17_ERAY_HEADER_CRC_POLYNOMINAL ;
  /* Number of bits for Header CRC Calculation  - 0x14 */
  length = FR_17_ERAY_NUM_BITS_FOR_HEADERCRC ;

  Header = Header << FR_17_ERAY_NUM_12 ;
  vCrcReg = vCrcReg << FR_17_ERAY_NUM_21 ;
  vCrcPoly = vCrcPoly << FR_17_ERAY_NUM_21 ;

  while(length)
  {
    vNextBitHeader = Header & FR_17_ERAY_MASK_MSB ;
    vNextBitCrcReg = vCrcReg & FR_17_ERAY_MASK_MSB ;
    vCrcNext = vNextBitHeader ^ vNextBitCrcReg ;

    Header = Header << 1U ;
    vCrcReg = vCrcReg << 1U ;

    if(vCrcNext)
    {
      vCrcReg = vCrcReg ^ vCrcPoly ;
    }

    length-- ;
  }

  vCrcReg = vCrcReg >> FR_17_ERAY_NUM_21 ;

  return (vCrcReg) ;
}
#endif /* #if (FR_17_ERAY_MSG_ALLOW_DYNAMICLSDULENGTH == STD_ON) */

#if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON)

/*******************************************************************************
** Syntax : Std_ReturnType Fr_17_Eray_lReceiveRxFifo(                         **
**                                    uint8 Fr_CtrlIdx,uint8* Fr_LSduPtr,     **
**                                   Fr_RxLPduStatusType* Fr_LPduStatusPtr,   **
**                                   uint8* Fr_LSduLengthPtr                  **
**                                   )                                        **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in):                                                           **
**                  Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                  Fr_LSduPtr - This reference points to a buffer where the  **
**                                  LSdu to be received shall be stored       **
**                  Fr_LPduStatusPtr - This reference points to the memory    **
**                                      location where the status of the LPdu **
**                                      shall be stored                       **
**                  Fr_LSduLengthPtr - This reference points to the memory    **
**                           location where the length of the LSdu (in bytes) **
**                           shall be stored. This length represents the      **
**                           number of bytes copied to LSduPtr.               **
**                                                                            **
** Parameters (out): Std_ReturnType                                           **
**                                                                            **
** Description :                                                              **
**   Function for Receieve Fifo                                               **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_lReceiveRxFifo(
                                         uint8 Fr_CtrlIdx,uint8* Fr_LSduPtr,
                                         Fr_RxLPduStatusType* Fr_LPduStatusPtr,
                                         uint8* Fr_LSduLengthPtr
                                         )
{
  uint32 TimeOutCount ;
  uint32 ByteIndex ;
  uint32 TempLsduPtr[FR_17_ERAY_MAX_LSDU_LENGTH];
  uint8 PayloadLenReceived;
  uint8 PayloadLenConfigured;
  Std_ReturnType RetVal;
  uint8 RegCount;
  uint8 RegIndex;
  volatile uint8 Obsys;
  uint8 LogIdx;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
  RetVal = E_OK;

  for (RegIndex = 0U; RegIndex < FR_17_ERAY_MAX_LSDU_LENGTH; RegIndex++)
  {
    TempLsduPtr[RegIndex] = 0U;
  }

  /* Check if FIFO is not empty */
  if ((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->FSR.U) & \
                                                  FR_FSR_RFNE_SETMASK) == 1U)
  {
    /*Receive FIFO is not empty, hence Read the New data*/
    /* Check if there is a overrun error */
    if(((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->FSR.U) & \
                       FR_FSR_RFO_SETMASK) >> FR_17_ERAY_SHIFT_BIT_2) == 1U)
    {
      /* There is a FIFO overrun error.*/
      *Fr_LPduStatusPtr = FR_RECEIVED;
      RetVal = E_NOT_OK;
    }
    else
    {

      /*
        Write Output Buffer Command Mask for both header and data section
        transfer
      */
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCM.U), \
                                                  FR_OBCM_RHSS_CLEARMASK, 1U)
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCM.U), \
               FR_OBCM_RDSS_CLEARMASK, ((uint32)1 << FR_17_ERAY_SHIFT_BIT_1))

      /* Write Output Buffer Command register with the first message buffer ID
      of FIFO to request transfer of FIFO message buffer to OBF Shadow buffer*/
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
        FR_OBCR_OBRS_CLEARMASK, (((uint32)FR_SFR_RUNTIME_USER_MODE_READ32\
                       (ERAY[Fr_CtrlIdx]->MRC.U) & FR_MRC_FFB_SETMASK) \
                                                >> FR_17_ERAY_SHIFT_BIT_8))
      FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
               FR_OBCR_REQ_CLEARMASK, ((uint32)1 << FR_17_ERAY_SHIFT_BIT_9))

      /* Wait until transfer is complete */
      TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION ;

      do
      {
        TimeOutCount-- ;
        #ifdef IFX_ERAY_DEBUG
        Obsys = (uint8)\
               (((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->OBCR.U) &\
                        FR_OBCR_OBSYS_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15 ) \
                 | (uint8)(TestFr_DebugMaskRxfifo >> FR_17_ERAY_SHIFT_BIT_15));
        #else
        Obsys = (uint8)\
        ((uint32)(FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->OBCR.U) &\
                           FR_OBCR_OBSYS_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15);
        #endif
      }
      while ((Obsys == 1U) && (TimeOutCount > 0U));

      /* Report time out error to DEM */
      if (TimeOutCount == 0U)
      {
        /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
        if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
          DEM_REPORT_DISABLED)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
          Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                               CfgPtr[LogIdx].FrDemTimeoutId,
                                DEM_EVENT_STATUS_FAILED);
        }
        RetVal = E_NOT_OK ;
      }
      else
      {

        /* Swap the host and shadow buffer */
        FR_SFR_RUNTIME_USER_MODE_MODIFY32((ERAY[Fr_CtrlIdx]->OBCR.U), \
           FR_OBCR_REQ_VIEW_CLEARMASK, ((uint32)1 << FR_17_ERAY_SHIFT_BIT_8))

        /*---------------------------------------------------------------*/
        /* Read message buffer status, header and data sections as below */

        /* Received length in bytes = Min(PLR, PLC) [FR239] * 2 */
        PayloadLenReceived = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                (ERAY[Fr_CtrlIdx]->RDHS2.U) & FR_RDHS2_PLR_SETMASK) \
                                                >> FR_17_ERAY_SHIFT_BIT_24);
        PayloadLenConfigured = (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32\
                    (ERAY[Fr_CtrlIdx]->RDHS2.U) & FR_RDHS2_PLC_SETMASK) \
                                                >> FR_17_ERAY_SHIFT_BIT_16);

        /* Check if Receive FIFO Fill Level has reached FIFO Critical Level
         (which is configured as depth) */
        if (((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->FSR.U) & \
                       FR_FSR_RFFL_SETMASK) >> FR_17_ERAY_SHIFT_BIT_8) != 0U)
        {
          /* FIFO has not reached critical level, more data is available in
             FIFO to be read */
          *Fr_LPduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE ;
        }
        else
        {
          /* FIFO has reached critical level, No data is available in
             FIFO to be read */
          *Fr_LPduStatusPtr = FR_RECEIVED ;
        }

        *Fr_LSduLengthPtr = (uint8)
                         (((PayloadLenReceived > PayloadLenConfigured) ?
                         PayloadLenConfigured : PayloadLenReceived) *
                         FR_17_ERAY_BYTES_PER_HALFWORD);


        /* Message Buffer of FIFO addressed by the GET Index Register (GIDX) is
           transferred to the Output Buffer*/
        /* Copy FIFO data from RDDSn registers to application buffer pointed
            by Fr_LSduPtr */
        /* Do 32-bit word transfer */
        /* Copy data from RDDSn registers to application buffer pointed by
          LSduPtr */

        RegCount = ((*Fr_LSduLengthPtr) / FR_17_ERAY_DIV_BY_4);
        if (((*Fr_LSduLengthPtr) & FR_17_ERAY_MOD_4) != 0U)
        {
            RegCount = RegCount + 1U;
        }

        for (RegIndex = 0U; RegIndex < RegCount; RegIndex++)
        {
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
          /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
          *((uint32 *)(void *)TempLsduPtr + RegIndex) =
          FR_SFR_RUNTIME_USER_MODE_READ32\
               (*((uint32 *)(void *)&ERAY[Fr_CtrlIdx]->RDDS_1S[0] + RegIndex));
        }

        for ( ByteIndex = 0U ; ByteIndex < (*Fr_LSduLengthPtr) ; ByteIndex++ )
        {
           /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
           /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
           *(Fr_LSduPtr + ByteIndex) =
                                *((uint8 *)(void*)TempLsduPtr + ByteIndex);
        }
      }
    }
  }
  else
  {
    /* Receive FIFO is empty, New data is not received by FIFO */
    *Fr_LPduStatusPtr = FR_NOT_RECEIVED;
    *Fr_LSduLengthPtr = 0U;
  }
  return RetVal;
}
#endif
    /* #if (FR_17_ERAY_FIFO_CONFIGURED == STD_ON) */

/*----------------------------------------------------------------------------*/
#if(FR_17_ERAY_RX_STRINGENT_CHECK == STD_ON)
/* Stringent check for Receive */
IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_RxStringentCheck(
                      uint8 Fr_CtrlIdx,uint8 ChannelIdx)
{
  uint32 ErayAcsChA;
  uint32 ErayAcsChB;
  Std_ReturnType RetValue ;

  RetValue = E_OK ;
/* Check if the SlotStatus does not show a valid frame (vSS!ValidFrame)
  and a single SlotStatus error bit set (vSS!SyntaxError,vSS!ContentError,
  vSS!Bviolation) and return E_NOT_OK */

  #ifdef IFX_ERAY_DEBUG
  ErayAcsChA = (uint32)
            ((FR_SFR_RUNTIME_USER_MODE_READ32\
            (ERAY[Fr_CtrlIdx]->ACS.U) | (TestFr_DebugMaskStringent >> \
               FR_17_ERAY_DEBUG_NUM_16)) & FR_17_ERAY_ACS_CHANNELA_MASK);
  ErayAcsChB = (uint32)
            ((FR_SFR_RUNTIME_USER_MODE_READ32\
            (ERAY[Fr_CtrlIdx]->ACS.U) | (TestFr_DebugMaskStringent >> \
               FR_17_ERAY_DEBUG_NUM_16)) & FR_17_ERAY_ACS_CHANNELB_MASK);
  #else
  ErayAcsChA = (uint32)(FR_SFR_RUNTIME_USER_MODE_READ32\
                     (ERAY[Fr_CtrlIdx]->ACS.U) & FR_17_ERAY_ACS_CHANNELA_MASK);
  ErayAcsChB = (uint32)(FR_SFR_RUNTIME_USER_MODE_READ32\
                     (ERAY[Fr_CtrlIdx]->ACS.U) & FR_17_ERAY_ACS_CHANNELB_MASK);
  #endif
  /* As VFRA is 0 if a valid frame is not recieved, toggle this bit to
     check for error */
  ErayAcsChA ^= FR_17_ERAY_ACS_CHANNELA_VALID_BIT;

  /* As VFRB is 0 if a valid frame is not recieved, toggle this bit to
     check for error */
  ErayAcsChB ^= FR_17_ERAY_ACS_CHANNELB_VALID_BIT;

  if((ChannelIdx == (uint8)FR_CHANNEL_A) && (ErayAcsChA != 0U))
  {
    RetValue = E_NOT_OK ;
  }
  else if((ChannelIdx == (uint8)FR_CHANNEL_B) && (ErayAcsChB != 0U))
  {
    RetValue = E_NOT_OK ;
  }
  else if((ErayAcsChA != 0U) && (ErayAcsChB != 0U))
  {
    RetValue = E_NOT_OK ;
  }
  else
  {
    /* for misra warning */
  }

  return RetValue;
}
#endif
/*----------------------------------------------------------------------------*/


/* Slot status error check for Receive */
IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_SlotStatusErrorCheck(
                      uint8 Fr_CtrlIdx,uint8 ChannelIdx)
{
  Std_ReturnType RetValue ;
  uint32 ErayAcsChA;
  uint32 ErayAcsChB;
  uint8 LogIdx;
  RetValue = E_OK ;

  #ifdef IFX_ERAY_DEBUG
  ErayAcsChA = (uint32)((FR_SFR_RUNTIME_USER_MODE_READ32\
               (ERAY[Fr_CtrlIdx]->ACS.U) | (TestFr_DebugMaskSlotErr >>\
                 FR_17_ERAY_DEBUG_NUM_16)) & FR_17_ERAY_ACS_CHANNELA_MASK);
  ErayAcsChB = (uint32)((FR_SFR_RUNTIME_USER_MODE_READ32\
                (ERAY[Fr_CtrlIdx]->ACS.U) | (TestFr_DebugMaskSlotErr >>\
                 FR_17_ERAY_DEBUG_NUM_16)) & FR_17_ERAY_ACS_CHANNELB_MASK);
  #else
  ErayAcsChA = (uint32)(FR_SFR_RUNTIME_USER_MODE_READ32\
                   (ERAY[Fr_CtrlIdx]->ACS.U) & FR_17_ERAY_ACS_CHANNELA_MASK);
  ErayAcsChB = (uint32)(FR_SFR_RUNTIME_USER_MODE_READ32\
                   (ERAY[Fr_CtrlIdx]->ACS.U) & FR_17_ERAY_ACS_CHANNELB_MASK);
  #endif
  /* Clear VFRA bit as this is slotstatus check only */
  ErayAcsChA &= ~FR_17_ERAY_ACS_CHANNELA_VALID_BIT;

  /* Clear VFRA bit as this is slotstatus check only */
  ErayAcsChB &= ~FR_17_ERAY_ACS_CHANNELB_VALID_BIT;

  if((ChannelIdx == (uint8)FR_CHANNEL_A) && (ErayAcsChA != 0U))
  {
    RetValue = E_NOT_OK ;
  }
  else if((ChannelIdx == (uint8)FR_CHANNEL_B) && (ErayAcsChB != 0U))
  {
    RetValue = E_NOT_OK ;
  }
  else if((ErayAcsChA != 0U) && (ErayAcsChB != 0U))
  {
    RetValue = E_NOT_OK ;
  }
  else
  {
    /* for misra warning */
  }
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
  /* If single slot status error bit (vSS!SyntaxError, vSS!ContentError,
  vSS!Bviolation) is set, Raise DEM -> DEM_EVENT_STATUS_FAILED */
  if(RetValue == E_NOT_OK)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemFTSlotStatusErrId !=
                                                       DEM_REPORT_DISABLED)
    {

      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                                CfgPtr[LogIdx].FrDemFTSlotStatusErrId,
                            DEM_EVENT_STATUS_FAILED);
    }
  }
  else
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if(Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemFTSlotStatusErrId !=
                                                      DEM_REPORT_DISABLED)
    {

     /* If single slot status error bit (vSS!SyntaxError, vSS!ContentError,
      vSS!Bviolation) is not set, Raise DEM -> DEM_EVENT_STATUS_PASSED */
      /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
      Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                                       CfgPtr[LogIdx].FrDemFTSlotStatusErrId,
                            DEM_EVENT_STATUS_PASSED);
    }
  }
  return RetValue;
}

/*----------------------------------------------------------------------------*/

/* Function to check if comm controller is synchronised to global time */
/* condition (!vPOC!Freeze) is not checked as CC can never be in (!vPOC!Freeze)
 when the POC state is NORMAL_ACTIVE or NORMAL_PASSIVE */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lIsCCInSync(uint8 Fr_CtrlIdx)
{
  uint32 RetVal;
  uint32 ErayCcsv;

  ErayCcsv = (uint32)(FR_SFR_RUNTIME_USER_MODE_READ32\
                           (ERAY[Fr_CtrlIdx]->CCSV.U) & FR_17_ERAY_POCS_MASK);
  if ((ErayCcsv == FR_17_ERAY_POCS_NORMAL_ACTIVE) ||
                               (ErayCcsv == FR_17_ERAY_POCS_NORMAL_PASSIVE))
  {
    RetVal = 1U;
  }
  else
  {
    RetVal = 0U;
  }
  return RetVal;

}

/*******************************************************************************
** Syntax : static uint32 Fr_17_Eray_lInputBufBsyHost(uint8 Fr_CtrlIdx,       **
**                                                     uint8 ApiAccessId)     **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): uint8 Fr_CtrlIdx, uint8 ApiAccessId                       **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value:  HeaderCRC                                                   **
**                                                                            **
** Description :                                                              **
**   Transfer input buffer contents to message RAM buffer                     **
**                                                                            **
*******************************************************************************/
static uint32 Fr_17_Eray_lInputBufBsyHost(uint8 Fr_CtrlIdx,
                                                    uint8 ApiAccessId)
{
   uint32 ErrorCount;
   uint32 TimeOutCount ;
   volatile uint8 IbsyhChk;
   uint8 LogIdx;

   ErrorCount = 0U ;
   /* Wait till Header is moved to message buffer and input buffer is free */
   TimeOutCount = FR_17_ERAY_TIMEOUT_DURATION ;

  do
  {
    TimeOutCount-- ;

    if(ApiAccessId == FR_INIT_API_ACCESS)
    {
      #ifdef IFX_ERAY_DEBUG
      IbsyhChk =
        (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) & \
             FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15) | \
                    (uint8)(TestFr_DebugMaskIbsyh >> FR_17_ERAY_SHIFT_BIT_15);
      #else
      IbsyhChk =
         (uint8)((FR_SFR_INIT_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) & \
                          FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15);
      #endif
    }
    else
    {
      #ifdef IFX_ERAY_DEBUG
      IbsyhChk =
        (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) & \
             FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15) | \
                    (uint8)(TestFr_DebugMaskIbsyh >> FR_17_ERAY_SHIFT_BIT_15);
      #else
      IbsyhChk =
         (uint8)((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->IBCR.U) & \
                          FR_IBCR_IBSYH_SETMASK) >> FR_17_ERAY_SHIFT_BIT_15);
      #endif
    }
  }while ((IbsyhChk == 1U) && (TimeOutCount > 0U)) ;

   /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
   LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
   /*  Raise DEM if Input buffer is not FREE within timeout period */
   if (TimeOutCount == 0U)
   {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     if (Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].FrDemTimeoutId !=
                                                          DEM_REPORT_DISABLED)
     {
       /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
       Dem_ReportErrorStatus(Fr_17_Eray_kConfigPtr->
                                             CfgPtr[LogIdx].FrDemTimeoutId,
                             DEM_EVENT_STATUS_FAILED);
     }
     ErrorCount ++;
   }
   return ErrorCount;
}

/*----------------------------------------------------------------------------*/
/*******************  Inline functions for DET checks ************************/

#if (FR_17_ERAY_DEV_ERROR_DETECT == STD_ON)
/* DET check for FR_17_ERAY_E_INV_TIMER_IDX */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidTimerIdx(
                                                            uint8 TimerIdx,
                                                            uint8 ServiceId
                                                          )
{
  uint32 DevError;

  DevError = FR_17_ERAY_E_DET_NO_ERR;
  /* Only timer (absolute or relative) exists */
  if (TimerIdx != 0U)
  {
    Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID, ServiceId,
                                                  FR_17_ERAY_E_INV_TIMER_IDX);
    DevError = FR_17_ERAY_E_INV_TIMER_IDX ;
  }

  return DevError;
}

/*----------------------------------------------------------------------------*/

/* DET check for FR_17_ERAY_E_INV_POINTER */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidPointer(
                              const void * Ptr,
                                                          uint8 ServiceId)
{
  uint32 DevError;
  #if (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
  volatile uint8 SID;
  SID = ServiceId;
  #endif
  DevError = FR_17_ERAY_E_DET_NO_ERR;

  #if (FR_17_ERAY_PB_FIXEDADDR == STD_OFF)
  if (Ptr == NULL_PTR)
  #elif (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
  if (((SID == FR_17_ERAY_SID_INIT) &&
       (Ptr != &Fr_17_Eray_ConfigRoot[0U])) ||
       (Ptr == NULL_PTR) )
  #endif
  {
    Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID, ServiceId,
                                                  FR_17_ERAY_E_INV_POINTER);
    DevError = FR_17_ERAY_E_INV_POINTER;
  }
  return DevError;
}

/*----------------------------------------------------------------------------*/

/* DET check for FR_17_ERAY_E_INV_CTRL_IDX */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidCtrlIdx(
                                                          uint8 CtrlIdx,
                                                          uint8 ServiceId
                                                        )
{
  uint32 DevError;

  DevError = FR_17_ERAY_E_DET_NO_ERR;

  /* Only communication controller exists */
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  if ((CtrlIdx >= FR_NUM_CONTROLLERS_IN_DEVICE)||
      (ERAY_CONTROLLER_NOT_CONFIGURED ==
                 Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[CtrlIdx]))
  {
    Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID, ServiceId,
                                                    FR_17_ERAY_E_INV_CTRL_IDX);
    DevError = FR_17_ERAY_E_INV_CTRL_IDX;
  }
  return DevError ;
}
/*----------------------------------------------------------------------------*/

/* Can be used by all APIs */
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckNoInit( uint8 Fr_CtrlIdx,
                                                         uint8 ServiceId)
{
  uint32 DevError;
  DevError = FR_17_ERAY_E_DET_NO_ERR;
  UNUSED_PARAMETER(Fr_CtrlIdx)
  /* Fr_17_Eray_Init API was NOT called */
  #if (FR_17_ERAY_PB_FIXEDADDR == STD_OFF)
  if (Fr_17_Eray_kConfigPtr == NULL_PTR)

  #elif (FR_17_ERAY_PB_FIXEDADDR == STD_ON)
  if (Fr_17_Eray_DriverInitDone != 1U)
  #endif
  {
    Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID, ServiceId,
                                                 FR_17_ERAY_E_NOT_INITIALIZED);
    DevError = FR_17_ERAY_E_NOT_INITIALIZED;
  }
  return DevError ;
}

/*----------------------------------------------------------------------------*/

/*
  FR_17_ERAY_E_INV_POCSTATE: Used only by APIs that check against one expected
  state. It can't be used to check for multiple states for example : to check
  if CC is synchronised to FlexRay global time because it involves checking
  if CC is in either NORMAL PASSIVE or ACTIVE state.
*/
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidPOCState(
                                                            uint8 Fr_CtrlIdx,
                                                            uint8 ExpectedState,
                                                            uint8 ServiceId
                                                          )
{
  uint32 DevError;

  DevError = FR_17_ERAY_E_DET_NO_ERR;

  /* Fr_17_Eray_Init API was called */
  if ((FR_SFR_RUNTIME_USER_MODE_READ32(ERAY[Fr_CtrlIdx]->CCSV.U) & \
                                        FR_CCSV_POCS_SETMASK) != ExpectedState)
  {
    Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID, ServiceId,
                                                  FR_17_ERAY_E_INV_POCSTATE);
    DevError = FR_17_ERAY_E_INV_POCSTATE;
  }
  return DevError ;
}

/*----------------------------------------------------------------------------*/

/* FR_17_ERAY_E_INV_LPDU_IDX: TransmitTxLPdu, ReceiveRxLPdu, CheckTxLPduStatus*/
IFX_LOCAL_INLINE uint32 Fr_17_Eray_lDetCheckInvalidLPduIdx(
                                                         uint8 Fr_CtrlIdx,
                                                           uint16 LPduIdx,
                                                           uint8 ServiceId
                                                         )
{
  uint32 DevError;
  uint8 LogIdx;

  DevError = FR_17_ERAY_E_DET_NO_ERR;
  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];

  /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
  if (LPduIdx >= Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduCount)
  {
    Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID, ServiceId,
                                                    FR_17_ERAY_E_INV_LPDU_IDX);
    DevError = FR_17_ERAY_E_INV_LPDU_IDX;
  }
  return DevError ;
}

/*******************************************************************************
**                                                                            **
** Syntax : IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_lTransmitDetCheck(     **
**                                    uint8 Fr_CtrlIdx,                       **
**                                    uint16 Fr_LPduIdx,                      **
**                                    const uint8* Fr_LSduPtr,                **
**                         )                                                  **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                            **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant                                                 **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of    **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a    **
**                                  FlexRay frame.                            **
**                  Fr_LSduPtr - This reference points to a buffer where the  **
**                                  assembled LSdu to be transmitted within   **
**                                  this LPdu is stored at.                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Checks for Transmit API DET                                  **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE Std_ReturnType Fr_17_Eray_lTransmitDetCheck(
            uint8 Fr_CtrlIdx,
                     uint16 Fr_LPduIdx,
                     const uint8* Fr_LSduPtr)
{
  uint32 DevError ;
  Std_ReturnType RetVal ;
  uint8 LogIdx;


  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                   (Fr_CtrlIdx,FR_17_ERAY_SID_TRANSMITTXLPDU) ;

  /* Driver not initialized(Fr_17_Eray_kConfigPtr->
                                  CfgPtr[LogIdx] not initialized), avoid trap*/
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                FR_17_ERAY_SID_TRANSMITTXLPDU);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX: Fr_LPduIdx >= LPDU count  */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                               FR_17_ERAY_SID_TRANSMITTXLPDU);
  }



  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
     /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
     LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* FR_17_ERAY_E_INV_LPDU_IDX if its a receive LPDU */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (Fr_17_Eray_kConfigPtr->
                    CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].WRHS1.B.Cfg == 0U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                      FR_17_ERAY_SID_TRANSMITTXLPDU, FR_17_ERAY_E_INV_LPDU_IDX);
      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(Fr_LSduPtr,
                                               FR_17_ERAY_SID_TRANSMITTXLPDU);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    RetVal = E_OK;
  }
  else
  {
    RetVal = E_NOT_OK;
  }
  return RetVal;
}

/*******************************************************************************
** Syntax :IFX_LOCAL_INLINE  Std_ReturnType Fr_17_Eray_lReceiveDetCheck(      **
**                                 uint8 Fr_CtrlIdx,                       **
**                                 uint16 Fr_LPduIdx,                      **
**                                 const uint8* Fr_LSduPtr,                   **
**                                 const Fr_RxLPduStatusType* Fr_LPduStatusPtr,*
**                                 const uint8* Fr_LSduLengthPtr              **
**                         )                                                  **
**                                                                            **
**                                                                            **
** Service ID:  NA                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  non reentrant for the same device                             **
**                                                                            **
** Parameters (in): Fr_CtrlIdx - Index of FlexRay CC within the context of   **
**                                the FlexRay Driver.                         **
**                                                                            **
**                  Fr_LPduIdx - This index is used to uniquely identify a   **
**                                  FlexRay frame.                            **
**                                                                            **
** Parameters (out):                                                          **
**                  Fr_LSduPtr - This reference points to a buffer where the  **
**                                  LSdu to be received shall be stored       **
**                  Fr_LPduStatusPtr - This reference points to the memory    **
**                                      location where the status of the LPdu **
**                                      shall be stored                       **
**                  Fr_LSduLengthPtr - This reference points to the memory    **
**                           location where the length of the LSdu (in bytes) **
**                           shall be stored. This length represents the      **
**                           number of bytes copied to LSduPtr.            **
**                                                                            **
** Return value:  E_OK: API call finished successfully.                       **
**                E_NOT_OK: API call aborted due to errors.                   **
**                                                                            **
** Description : Checks for Receive DET                                       **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE  Std_ReturnType Fr_17_Eray_lReceiveDetCheck(
                                    uint8 Fr_CtrlIdx,
                                    uint16 Fr_LPduIdx,
                                    const uint8* Fr_LSduPtr,
                                    const Fr_RxLPduStatusType* Fr_LPduStatusPtr,
                                    const uint8* Fr_LSduLengthPtr
                                        )
{
  uint32 DevError ;
  Std_ReturnType RetValue;
  uint8 LogIdx;


  /* FR_17_ERAY_E_NOT_INITIALIZED */
  DevError = Fr_17_Eray_lDetCheckNoInit
                                   (Fr_CtrlIdx,FR_17_ERAY_SID_RECEIVERXLPDU) ;

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_CTRL_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidCtrlIdx(Fr_CtrlIdx,
                                                FR_17_ERAY_SID_RECEIVERXLPDU);
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_LPDU_IDX */
    DevError = Fr_17_Eray_lDetCheckInvalidLPduIdx(Fr_CtrlIdx,Fr_LPduIdx,
                                                FR_17_ERAY_SID_RECEIVERXLPDU);
  }

  /*
    Invalid LPduIdx, avoid array out of bound access for
     Fr_17_Eray_kConfigPtr->CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx]
  */


  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    LogIdx = Fr_17_Eray_kConfigPtr->Phy2LogIdxPtr[Fr_CtrlIdx];
    /* FR_17_ERAY_E_INV_LPDU_IDX if its a transmit LPDU */
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    /*IFX_MISRA_RULE_17_04_STATUS=Pointer arithmetic used due to
      PBConfigStructure and is within allowed range.*/
    if (Fr_17_Eray_kConfigPtr->
                   CfgPtr[LogIdx].LPduConfigPtr[Fr_LPduIdx].WRHS1.B.Cfg == 1U)
    {
      Det_ReportError(FR_17_ERAY_MODULE_ID, FR_17_ERAY_INSTANCE_ID,
                      FR_17_ERAY_SID_RECEIVERXLPDU, FR_17_ERAY_E_INV_LPDU_IDX);
      DevError = FR_17_ERAY_E_INV_LPDU_IDX;
    }
  }
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(Fr_LSduPtr,
                                               FR_17_ERAY_SID_RECEIVERXLPDU);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
                  (const void *)Fr_LPduStatusPtr, FR_17_ERAY_SID_RECEIVERXLPDU);
  }

  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    /* FR_17_ERAY_E_INV_POINTER */
    DevError = Fr_17_Eray_lDetCheckInvalidPointer(
                  (const void *)Fr_LSduLengthPtr, FR_17_ERAY_SID_RECEIVERXLPDU);
  }

  /* Return if a development error occured */
  if (DevError == FR_17_ERAY_E_DET_NO_ERR)
  {
    RetValue = E_OK;
  }
  else
  {
    RetValue = E_NOT_OK;
  }

  return RetValue;
}

#endif
/* FR_17_ERAY_DEV_ERROR_DETECT == STD_ON) */

#if (FR_RESET_SFR_AT_INIT == STD_ON)

/*******************************************************************************
** Syntax           : IFX_LOCAL_INLINE void Fr_17_Eray_lResetSFR(             **
**                                                       uint8 CtrlIdx)       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non-Reentrant                                           **
**                                                                            **
** Parameters (in)  : CtrlIdx - Index of FlexRay CC within the context of     **
**                                the FlexRay Driver.                         **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : None                                                    **
**                                                                            **
** Description      : Initializes the Kernel registers to default value       **
**                                                                            **
*******************************************************************************/
IFX_LOCAL_INLINE void Fr_17_Eray_lResetSFR(uint8 CtrlIdx)
{
  volatile uint32 ReadBack; /* Readback of KRST register */
  uint32 TimeOutVal; /* Time out value for Kernel Reset to happen */
  uint32 KerRstStat; /* Kernel Reset Status */
  ReadBack = DEC_ZERO;

    /* Disable write-protection of registers with EndInit protection */
    FR_SFR_INIT_RESETENDINIT();

    /* Request a Kernel Reset */
    FR_SFR_INIT_MODIFY32((ERAY[CtrlIdx]->KRST0.U), \
                                              FR_KRST0_RST_CLEARMASK, DEC_ONE)

    /* Read back to ensure the KRST0 register modifications */
    ReadBack = FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->KRST0.U);

    /* Request a Kernel Reset */
    FR_SFR_INIT_WRITE32((ERAY[CtrlIdx]->KRST1.U), \
                                              DEC_ONE & FR_KRST1_RST_SETMASK);

    /* Read back to ensure the KRST1 register modifications */
    ReadBack = FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->KRST1.U);

    /* Enable write-protection of registers with EndInit protection */
    FR_SFR_INIT_SETENDINIT();

    /* Time out value for Kernel Reset is loaded */
    TimeOutVal = FR_KERNEL_RESET_TIMEOUT;
    do
    {
      TimeOutVal--;
#ifdef IFX_ERAY_DEBUG
      KerRstStat = TestFr_DebugMaskKRSTSTAT;
#else
      KerRstStat = (uint32)((FR_SFR_INIT_USER_MODE_READ32\
                   (ERAY[CtrlIdx]->KRST0.U) & FR_KRST0_RSTSTAT_SETMASK) \
                                                >> FR_17_ERAY_SHIFT_BIT_1);
#endif
    }
    while ((KerRstStat == DEC_ZERO) && (TimeOutVal > DEC_ZERO));

    /* Disable write-protection of registers with EndInit protection */
    FR_SFR_INIT_RESETENDINIT();
    /* Clear the Kernel Reset Status */
    FR_SFR_INIT_WRITE32((ERAY[CtrlIdx]->KRSTCLR.U), \
                                          DEC_ONE & FR_KRSTCLR_CLR_SETMASK);
    /* Read back to ensure the KRSCLR register modifications */
    ReadBack = FR_SFR_INIT_USER_MODE_READ32(ERAY[CtrlIdx]->KRSTCLR.U);

    /* Enable write-protection of registers with EndInit protection */
    FR_SFR_INIT_SETENDINIT();


  UNUSED_PARAMETER(ReadBack)
}
#endif


/*----------------------------------------------------------------------------*/

/* Memory Map of the FR Code */
#define FR_17_ERAY_STOP_SEC_CODE
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directive is
 allowed only for MemMap.h*/
#include "MemMap.h"
/*******************************************************************************
**                               End of File                                  **
*******************************************************************************/
