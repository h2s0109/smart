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
**   $FILENAME   : Adc_PBCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\dev_tc23x_as4.0.3\16 $                               **
**                                                                            **
**   $DATE       : 2015-07-13 $                                               **
**                                                                            **
**   AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**   VENDOR      : Infineon Technologies                                      **
**                                                                            **
**   DESCRIPTION : Code template for Adc_PBCfg.c file                         **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                                                                            **
**  TRACEABILITY:[cover parentID=SAS_AS_ADC240,DS_AS_ADC090_ADC091,DS_AS_ADC092,
DS_AS_ADC277,DS_AS_ADC451,DS_NAS_ADC_PR699,DS_NAS_ADC_PR700,DS_NAS_ADC_PR701,
DS_NAS_ADC_PR704,DS_NAS_ADC_PR707,DS_NAS_ADC_PR708,DS_NAS_ADC_PR709,
DS_NAS_ADC_PR712,DS_NAS_ADC_PR717,DS_NAS_ADC_PR724,DS_NAS_ADC_PR728,
DS_NAS_ADC_PR446,DS_NAS_ADC_PR78,SAS_NAS_ADC_PR1781,DS_NAS_ADC_PR1782,
SAS_NAS_ADC_PR227,SAS_NAS_ADC_PR914,SAS_NAS_ADC_PR916,SAS_NAS_ADC_PR82,
SAS_NAS_ADC_PR726]                                                            **
**                                                                            **
**  Code template for Adc_PBCfg.c file                                        **
**                                                                            **
**  [/cover]                                                                  **
**                                                                            **
*************************************************************************/!][!//
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
**   $FILENAME   : Adc_PBCfg.c $                                              **
**                                                                            **
**   $CC VERSION : \main\dev_tc23x_as4.0.3\16 $                               **
**                                                                            **
**   DATE, TIME: [!"$date"!], [!"$time"!]                                         **
**                                                                            **
**   GENERATOR : Build [!"$buildnr"!]                                           **
**                                                                            **
**   AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                            **
**   VENDOR    : Infineon Technologies                                        **
**                                                                            **
**   DESCRIPTION  : Adc configuration generated out of ECU configuration      **
**                 file                                                       **
**                                                                            **
**   MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Inclution of module header file */
#include "Adc.h"
/* Import DMA channel information */
#include "Mcal_DmaLib.h"

[!NOCODE!]
[!INCLUDE "Adc.m"!][!//
[!ENDNOCODE!]
/*******************************************************************************
**                      Private Macro definition                              **
*******************************************************************************/

/*******************************************************************************
**                      Configuration Options                                 **
*******************************************************************************/

/*
  Macros for ADC HW unit number definition
*/
#define HWUNIT_ADC0          (0U)
#define HWUNIT_ADC1          (1U)
#define HWUNIT_ADC2          (2U)
#define HWUNIT_ADC3          (3U)
#define HWUNIT_ADC4          (4U)
#define HWUNIT_ADC5          (5U)
#define HWUNIT_ADC6          (6U)
#define HWUNIT_ADC7          (7U)
#define HWUNIT_ADC8          (8U)
#define HWUNIT_ADC9          (9U)
#define HWUNIT_ADC10         (10U)

/*
  Macros for BNDSELX bitfields values definition
  Used for Standard mode limit checking
*/
#define BNDSELU_BNDSELL      (0U)
/*
  Configuration Options: ADC_ARBITRATION_ROUND_LENGTH
  Number of arbitration slots per arbitration round 
  (arbitration round length = tARB).
  00B - An arbitration round contains 4 arbitration slots
  (tARB = 4 / fADCD).
  01B - An arbitration round contains 8 arbitration slots
  (tARB = 8 / fADCD).
  10B - An arbitration round contains 16 arbitration
  slots (tARB = 16 / fADCD).
  11B - An arbitration round contains 20 arbitration
  slots (tARB = 20 / fADCD).
  Defines the number of arbitration slots per arbitration round.
  only 4 slots (i.e. ARBITRATION_SLOTS_4) are required for first 3 request 
  sources (i.e. RS0, RS1, RS2).
*/
#define ADC_ARBITRATION_SLOTS_4       (0U)
#define ADC_ARBITRATION_SLOTS_8       (1U)
#define ADC_ARBITRATION_SLOTS_16      (2U)
#define ADC_ARBITRATION_SLOTS_20      (3U)

/*
  Configuration Options: ADC_REQUEST_SOURCE_PRIO
  Priority of each request source 
  00B - Lowest Priority
  ...
  11B - Highest Priority
*/
#define ADC_REQSRC_PRIORITY_0_LOWEST       (0U)
#define ADC_REQSRC_PRIORITY_1              (1U)
#define ADC_REQSRC_PRIORITY_2              (2U)
#define ADC_REQSRC_PRIORITY_3_HIGHEST      (3U)

/*
  Configuration Options: ADC_HW_TRIG_TYPE
  Type of HW trigger : External request or Timer 
*/
#define ADC_HW_TRIGG_EXT_REQ          (0U)
#define ADC_HW_TRIGG_TIMER            (1U)

/*
  Configuration Options: Reference to MCU/ERU module
  ERU module selection for IOUT signal to form an ADC External request  
*/
#define ADC_HW_ERU0                   (0U)
#define ADC_HW_ERU1                   (1U)
#define ADC_HW_ERU2                   (2U)
#define ADC_HW_ERU3                   (3U)
#define ADC_HW_ERU4                   (4U)
#define ADC_HW_ERU5                   (5U)
#define ADC_HW_ERU6                   (6U)
#define ADC_HW_ERU7                   (7U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU0 Input lines  
*/
#define ERU_INPUT00_PORT15_PIN4       (0U)
#define ERU_INPUT01_CCU60_COUT60      (1U)
#define ERU_INPUT02_PORT10_PIN7       (2U)
#define ERU_INPUT03_MSC0_FCLP         (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU1 Input lines  
*/
#define ERU_INPUT10_PORT14_PIN3       (0U)
#define ERU_INPUT11_CCU61_COUT60      (1U)
#define ERU_INPUT12_PORT10_PIN8       (2U)
#define ERU_INPUT13_STM0_STMIR0       (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU2 Input lines  
*/
#define ERU_INPUT20_PORT10_PIN2       (0U)
#define ERU_INPUT21_PORT02_PIN1       (1U)
#define ERU_INPUT22_PORT00_PIN4       (2U)
#define ERU_INPUT23_ERAY0_MT          (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU3 Input lines  
*/
#define ERU_INPUT30_PORT10_PIN3       (0U)
#define ERU_INPUT31_PORT14_PIN1       (1U)
#define ERU_INPUT32_PORT02_PIN0       (2U)
#define ERU_INPUT33_STM1_STMIR0       (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU4 Input lines  
*/
#define ERU_INPUT40_PORT33_PIN7       (0U)
#define ERU_INPUT41_GTM_TOM0_12       (1U)
#define ERU_INPUT42_GPT120_T3OUT      (2U)
#define ERU_INPUT43_PORT15_PIN5       (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU5 Input lines  
*/
#define ERU_INPUT50_PORT15_PIN8       (0U)
#define ERU_INPUT51_GTM_TOM1_12       (1U)
#define ERU_INPUT52_GPT120_T6OUT      (2U)
#define ERU_INPUT53_STM2_STMIR0       (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU6 Input lines  
*/
#define ERU_INPUT60_PORT20_PIN0       (0U)
#define ERU_INPUT61_ESR0              (1U)
#define ERU_INPUT62_PORT33_PIN11      (2U)
#define ERU_INPUT63_PORT11_PIN10      (3U)

/*
  Configuration Options: Selection of ERU input line
  Selection of Input signal/pin to the selected ERU unit.
  The output of this ERU unit will trigger ADC
  ERU7 Input lines  
*/
#define ERU_INPUT70_PORT20_PIN9       (0U)
#define ERU_INPUT71_ESR1              (1U)
#define ERU_INPUT72_PORT15_PIN1       (2U)
#define ERU_INPUT73_ERAY1_MT          (3U)

/* Trigger selection from ERU IOUT signal */
#define ADC_TRSEL_ERU_IOUT            (7U)


/*
  Configuration Options: ADC_HW_TRIG_PIN
  Type of trigger: External request from ERU
*/
#define ADC0_TRSEL_RS0_RS1_IOUT0         (ADC_TRSEL_ERU_IOUT)
#define ADC1_TRSEL_RS0_RS1_IOUT1         (ADC_TRSEL_ERU_IOUT)
#define ADC2_TRSEL_RS0_RS1_IOUT2         (ADC_TRSEL_ERU_IOUT)
#define ADC3_TRSEL_RS0_RS1_IOUT3         (ADC_TRSEL_ERU_IOUT)
#define ADC4_TRSEL_RS0_RS1_IOUT4         (ADC_TRSEL_ERU_IOUT)
#define ADC5_TRSEL_RS0_RS1_IOUT5         (ADC_TRSEL_ERU_IOUT)
#define ADC6_TRSEL_RS0_RS1_IOUT6         (ADC_TRSEL_ERU_IOUT)
#define ADC7_TRSEL_RS0_RS1_IOUT7         (ADC_TRSEL_ERU_IOUT)
#define ADC8_TRSEL_RS0_RS1_IOUT0         (ADC_TRSEL_ERU_IOUT)
#define ADC9_TRSEL_RS0_RS1_IOUT1         (ADC_TRSEL_ERU_IOUT)
#define ADC10_TRSEL_RS0_RS1_IOUT2        (ADC_TRSEL_ERU_IOUT)
#define ADC0_TRSEL_RS0_RS1_RS3_IOUT0     (ADC_TRSEL_ERU_IOUT)
#define ADC1_TRSEL_RS0_RS1_RS3_IOUT1     (ADC_TRSEL_ERU_IOUT)
#define ADC2_TRSEL_RS0_RS1_RS3_IOUT2     (ADC_TRSEL_ERU_IOUT)
#define ADC3_TRSEL_RS0_RS1_RS3_IOUT3     (ADC_TRSEL_ERU_IOUT)
#define ADCx_TRSEL_RS2_IOUT3             (6U)
#define ADCx_TRSEL_RS2_IOUT4             (7U)
#define ADCx_TRSEL_RS2_IOUT6             (8U)
#define ADCx_TRSEL_RS2_IOUT7             (9U)

/* ERU OGU numbers */
#define ADC_ERU_OGU0                     (0U)
#define ADC_ERU_OGU1                     (1U)
#define ADC_ERU_OGU2                     (2U)
#define ADC_ERU_OGU3                     (3U)
#define ADC_ERU_OGU4                     (4U)
#define ADC_ERU_OGU5                     (5U)
#define ADC_ERU_OGU6                     (6U)
#define ADC_ERU_OGU7                     (7U)

/* Gate selection from GTM TRIG0 */
#define ADC_GTSEL_GTM_TRIG0              (0U)

/* Gate selection from GTM TRIG1 */
#define ADC_GTSEL_GTM_TRIG1              (1U)

/*
  Configuration Options: ADC_HW_GATE_PIN
  Type of trigger: External request/Timer 
*/
#define ADC0_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC0_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC1_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC1_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC2_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC2_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC3_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC3_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC4_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC4_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC5_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC5_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC6_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC6_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC7_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC7_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)

#define ADC8_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC8_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)

#define ADC9_GTSEL_RS0_RS1_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC9_GTSEL_RS0_RS1_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)

#define ADC10_GTSEL_RS0_RS1_TIM_TRIG0    (ADC_GTSEL_GTM_TRIG0)
#define ADC10_GTSEL_RS0_RS1_TIM_TRIG1    (ADC_GTSEL_GTM_TRIG1)

#define ADCx_GTSEL_RS2_TIM_TRIG0         (ADC_GTSEL_GTM_TRIG0)
#define ADCx_GTSEL_RS2_TIM_TRIG1         (ADC_GTSEL_GTM_TRIG1)

#define ADC0_GTSEL_RS0_RS1_RS3_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC0_GTSEL_RS0_RS1_RS3_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC1_GTSEL_RS0_RS1_RS3_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC1_GTSEL_RS0_RS1_RS3_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC2_GTSEL_RS0_RS1_RS3_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC2_GTSEL_RS0_RS1_RS3_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
#define ADC3_GTSEL_RS0_RS1_RS3_TIM_TRIG0     (ADC_GTSEL_GTM_TRIG0)
#define ADC3_GTSEL_RS0_RS1_RS3_TIM_TRIG1     (ADC_GTSEL_GTM_TRIG1)
                                         
/* Gate selection from GTM TRIG1 */
#define ADC_GTSEL_ERU_PDOUT              (12U)
/*
  Configuration Options: ADC_HW_GATE_PIN
  Type of Gate: External request from ERU
*/
#define ADC0_GTSEL_RS0_RS1_PDOUT0        (ADC_GTSEL_ERU_PDOUT)
#define ADC1_GTSEL_RS0_RS1_PDOUT1        (ADC_GTSEL_ERU_PDOUT)
#define ADC2_GTSEL_RS0_RS1_PDOUT2        (ADC_GTSEL_ERU_PDOUT)
#define ADC3_GTSEL_RS0_RS1_PDOUT3        (ADC_GTSEL_ERU_PDOUT)
#define ADC4_GTSEL_RS0_RS1_PDOUT4        (ADC_GTSEL_ERU_PDOUT)
#define ADC5_GTSEL_RS0_RS1_PDOUT5        (ADC_GTSEL_ERU_PDOUT)
#define ADC6_GTSEL_RS0_RS1_PDOUT6        (ADC_GTSEL_ERU_PDOUT)
#define ADC7_GTSEL_RS0_RS1_PDOUT7        (ADC_GTSEL_ERU_PDOUT)
#define ADC8_GTSEL_RS0_RS1_PDOUT0        (ADC_GTSEL_ERU_PDOUT)
#define ADC9_GTSEL_RS0_RS1_PDOUT1        (ADC_GTSEL_ERU_PDOUT)
#define ADC10_GTSEL_RS0_RS1_PDOUT2       (ADC_GTSEL_ERU_PDOUT)
#define ADC0_GTSEL_RS0_RS1_RS3_PDOUT0    (ADC_GTSEL_ERU_PDOUT)
#define ADC1_GTSEL_RS0_RS1_RS3_PDOUT1    (ADC_GTSEL_ERU_PDOUT)
#define ADC2_GTSEL_RS0_RS1_RS3_PDOUT2    (ADC_GTSEL_ERU_PDOUT)
#define ADC3_GTSEL_RS0_RS1_RS3_PDOUT3    (ADC_GTSEL_ERU_PDOUT)

/*
  Configuration Options: ADC_HW_GATE_PIN
  Type of Gate: External request from CCU6
*/
#define ADCx_GTSEL_RS0_RS1_RS2_CCU6061_TRIG0       (0x2U)
#define ADCx_GTSEL_RS0_RS1_RS2_CCU6061_TRIG1       (0x3U)
#define ADCx_GTSEL_RS0_RS1_RS2_CCU6061_TRIG2       (0x4U)
#define ADCx_GTSEL_RS0_RS1_RS2_RS3_CCU6061_TRIG0   (0x2U)
#define ADCx_GTSEL_RS0_RS1_RS2_RS3_CCU6061_TRIG1   (0x3U)
#define ADCx_GTSEL_RS0_RS1_RS2_RS3_CCU6061_TRIG2   (0x4U)

/*
  Configuration Options: ADC_HW_GATE_SIGNAL
  Gating signal High or Low 
*/
#define ADC_GATE_SIGNAL_HIGH             (2U)
#define ADC_GATE_SIGNAL_LOW              (3U)
#define ADC_GATE_SIGNAL_NONE             (1U)

/* Macro to use the Gate pin as Trigger */
#define ADC_USE_GATE_PIN_TO_TRIG         (0xFU)

/* Macro to use the Internal Trigger fo RS3 */
#define ADC_USE_INTERNAL_TRIG_TO_TRIG_RS3          (0xFU)

/*
  Configuration Options: AdcHwExtTrigSelect
*/
#define ADC_GROUP_SR1_TRIG               (12U)

#define ADC0_TRSEL_RS0_RS1_G0_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC1_TRSEL_RS0_RS1_G1_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC2_TRSEL_RS0_RS1_G2_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC3_TRSEL_RS0_RS1_G3_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC4_TRSEL_RS0_RS1_G4_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC5_TRSEL_RS0_RS1_G5_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC6_TRSEL_RS0_RS1_G6_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC7_TRSEL_RS0_RS1_G7_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC8_TRSEL_RS0_RS1_G8_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC9_TRSEL_RS0_RS1_G9_SR1        (ADC_GROUP_SR1_TRIG)
#define ADC10_TRSEL_RS0_RS1_G10_SR1      (ADC_GROUP_SR1_TRIG)
#define ADC0_TRSEL_RS0_RS1_RS3_G0_SR1    (ADC_GROUP_SR1_TRIG)
#define ADC1_TRSEL_RS0_RS1_RS3_G1_SR1    (ADC_GROUP_SR1_TRIG)
#define ADC2_TRSEL_RS0_RS1_RS3_G2_SR1    (ADC_GROUP_SR1_TRIG)
#define ADC3_TRSEL_RS0_RS1_RS3_G3_SR1    (ADC_GROUP_SR1_TRIG)

#define ADCx_TRSEL_RS0_RS1_RS2_CCU60_SR3     (0x0U)
#define ADCx_TRSEL_RS0_RS1_RS2_CCU61_SR3     (0x1U)
#define ADCx_TRSEL_RS0_RS1_RS2_RS3_CCU60_SR3 (0x0U)
#define ADCx_TRSEL_RS0_RS1_RS2_RS3_CCU61_SR3 (0x1U)

#define ADCx_TRSEL_RS0_RS1_RS2_C0_SR1        (13U)
#define ADCx_TRSEL_RS0_RS1_RS2_C1_SR1        (14U)
#define ADCx_TRSEL_RS0_RS1_RS2_RS3_C0_SR1    (13U)
#define ADCx_TRSEL_RS0_RS1_RS2_RS3_C1_SR1    (14U)

/* 
  Configuration Options: Sleep Mode
  values for Adc_ModuleCfgType.SleepMode
*/
/* ADC module responds to the sleep mode request from MCU driver */
#define ADC_SLEEP_MODE_ACCEPT            (0x00000000U)
/* Sleep mode request from MCU driver is rejected, module remains in its current
   state */
#define ADC_SLEEP_MODE_REJECT            (0x00000001U)

/*
  Configuration Options: post calibration control
*/
/* Define to enable post calibration */
#define ADC_POST_CAL_ENABLE              (0U)
/* Define to disable post calibration */
#define ADC_POST_CAL_DISABLE             (1U)

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/* Channel Limit check enabled */
#define ADC_CHANNEL_LIMIT_CHECK          (0x1U)
#endif

#if (ADC_MASTER_SLAVE_SYNC == STD_ON)
/* Master / Slave selection in GxSYNCTR.STSEL bit field */
#define ADC_SLAVE_CI1                    (1U)
#define ADC_SLAVE_CI2                    (2U)
#define ADC_SLAVE_CI3                    (3U)
#define ADC_EVAL_R1                      (0x10U)
#define ADC_EVAL_R2                      (0x20U)
#define ADC_EVAL_R3                      (0x40U)
#endif
#define ADC_STANDALONE                   (0U)

/* Macros for Alternate reference mode */
#define ADC_REF_LOCAL_MODE               (0U)
#define ADC_REF_GLOBAL_MODE              (1U)

#if (ADC_ALTERNATE_REF_MODE == ADC_REF_GLOBAL_MODE)
/*
  Macros for Sample and Hold unit number definition
*/
#define ADC_SAMPLE_HOLD_UNIT0          (0U)
#define ADC_SAMPLE_HOLD_UNIT1          (1U)
#define ADC_SAMPLE_HOLD_UNIT2          (2U)
#define ADC_SAMPLE_HOLD_UNIT3          (3U)
#define ADC_SAMPLE_HOLD_UNIT4          (4U)
#define ADC_SAMPLE_HOLD_UNIT5          (5U)
#define ADC_SAMPLE_HOLD_UNIT6          (6U)
#define ADC_SAMPLE_HOLD_UNIT7          (7U)
#define ADC_SAMPLE_HOLD_UNIT8          (8U)
#define ADC_SAMPLE_HOLD_UNIT9          (9U)
#define ADC_SAMPLE_HOLD_UNIT10         (10U)
#endif /* (ADC_ALTERNATE_REF_MODE == ADC_REF_GLOBAL_MODE) */

/*
  Macros for Operation mode of the converter
*/
#define ADC_NORMAL_MODE                (3U)
#define ADC_FAST_STANDBY_MODE          (2U)
#define ADC_SLOW_STANDBY_MODE          (1U)

/*
  Macros for Calibration order of the converter
*/
#define ADC_CONVERT_THEN_CAL           (0U)
#define ADC_CAL_THEN_CONVERT           (1U)

/*
  Macros for enhanced conversion timing scheme
*/
#define ADC_ACCELERATED_TIMING_ENABLE  (1U)
#define ADC_ACCELERATED_TIMING_DISABLE (0U)

/* Macros to define the Adc Global control parameters */
#if (ADC_MASTER_SLAVE_SYNC == STD_ON)
/* ARBM = 0, if Synchronization of conversion is enabled */
#define ADC_GxARBCFG_ARBM           (0U) 
#else
#define ADC_GxARBCFG_ARBM           (1U) 
#endif /* (ADC_MASTER_SLAVE_SYNC == STD_ON) */

/* All request sources are configured for CANCEL_INJECT_REPEAT mode */
[!IF "ecu:get('Adc.ReqSrcCount') = num:i(4)"!][!//
#define ADC_RS_CANCEL_INJECT_REPEAT ((uint32)(0x00008888U))
[!ELSE!][!//
#define ADC_RS_CANCEL_INJECT_REPEAT ((uint32)(0x00000888U))
[!ENDIF!][!//

/* Macro to enable the detection of input trigger in ERU */
#define ADC_ERU_EIEN_ENABLE         (1U)


#define ADC_POWER_SUPPLY_5V         ((uint32)(0x00000000))
#define ADC_POWER_SUPPLY_3_3V       ((uint32)(0x00004000))

#define ADC_USE_VDDM_PRECH_VAREF_ADJ ((uint32)(0x00000000))
#define ADC_USE_VAREF_CONVERSION     ((uint32)(0x00001000))

#if (ADC_CCU6_SYNCHRONIZATION == STD_ON)
#define ADC_CCU6_MODULE_CCU60        ((uint8)0x0)
#define ADC_CCU6_MODULE_CCU61        ((uint8)0x1)
#endif /* (ADC_CCU6_SYNCHRONIZATION == STD_ON) */
/*******************************************************************************
**                     Utility Macros                                         **
*******************************************************************************/

/*******************************************************************************
** Name             : Adc_lConfigChannel                                      **
**                                                                            **
** Description      : Macro to configure ADC Channel parameters               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lConfigChannel is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lConfigChannel(AdcChannelRefVoltsrcHigh, \
                           AdcInputClassSelection, \
                           AnalogInputChannelNumber \
                          ) \
(                                                \
    ((uint32)((AnalogInputChannelNumber) & ADC_AN_CH_MASK) <<  16U) | \
    ((uint32)(AdcChannelRefVoltsrcHigh) << 11U)  | \
    ((uint32)(AdcInputClassSelection)) \
)

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/*******************************************************************************
** Name             : Adc_lCfgChBoundry                                       **
**                                                                            **
** Description      : Macro to configure ADC Channel parameters               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lCfgChBoundry is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lCfgChBoundry(AdcChannelBound0,AdcChannelBound1)                   \
(                                                                              \
    ((uint32)(AdcChannelBound0)) |                                             \
    ((uint32)(AdcChannelBound1) << (uint32)16)                                 \
)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
/*******************************************************************************
** Name             : Adc_lArbLvlCtrl                                         **
**                                                                            **
** Description      :  Arbitration Level Control Register                     **
**                    Data compution                                          **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lArbLvlCtrl is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lArbLvlCtrl(AdcRS0Prio,AdcRS1Prio,AdcRS2Prio,AdcRS3Prio) \
                                ( (AdcRS0Prio)              |  \
                                 ((uint32)(AdcRS1Prio) << 4U)       |  \
                                 ((uint32)(AdcRS2Prio) << 8U)       |  \
                                 ((uint32)(AdcRS3Prio) << 12U)      |  \
                                 (ADC_RS_CANCEL_INJECT_REPEAT) \
                                )

/*******************************************************************************
** Name             : Adc_lInpClass                                           **
**                                                                            **
** Description      :  ADC Channel resolution and sampling time               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lInpClass is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lInpClass(AdcChSampTime,AdcChRes,AdcEmuxChSampTime) \
                                ( (AdcChSampTime)      | \
                                 ((AdcChRes) << 0x08U) | \
                                 ((AdcEmuxChSampTime) << 0x10U) | \
                                 ((AdcChRes) << 0x18U) \
                                )
/*******************************************************************************
** Name             : Adc_lConfigPrescale                                     **
**                                                                            **
** Description      : Macro to configure ADC clock prescale                   **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lConfigPrescale is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lConfigPrescale(AdcAnClkDiv,AdcDigClkDiv) \
(                                                  \
  ((uint32)(AdcDigClkDiv) << 8U)      | \
  (AdcAnClkDiv)                 \
)
/*******************************************************************************
** Name             : Adc_lConfigArbitration                                  **
**                                                                            **
** Description      : Macro to configure ADC Arbitration                      **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lConfigArbitration is declared as a function
 like macro to avoid function call in configuration data structures*/
#define Adc_lConfigArbitration(AdcArbRndLength)                                \
(                                                                              \
  ((uint32)(ADC_GxARBCFG_ARBM) << 7U) |                                        \
  ((uint32)(AdcArbRndLength)  << 4U)                                           \
)
#if (ADC_USE_EMUX == STD_ON)
/*******************************************************************************
** Name             : Adc_lCfgEmuxSelectGrp                                   **
**                                                                            **
** Description      : Macro to configure ADC Emux Group interface line        **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lCfgEmuxSelectGrp is declared as a function
 like macro to avoid function call in configuration data structures*/
#define Adc_lCfgEmuxSelectGrp(AdcEmuxGrp0,AdcEmuxGrp1) \
(                                                  \
  ((uint32)(AdcEmuxGrp1) << 4U)      | \
  (AdcEmuxGrp0)                 \
)
#endif /* (ADC_USE_EMUX == STD_ON) */

/*******************************************************************************
** Name             : Adc_lConfigHwReqSrc                                     **
**                                                                            **
** Description      : Macro to configure External trigger source for Request  **
**                    line selection and trigger edge selection               **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lConfigHwReqSrc is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lConfigHwReqSrc(GatePin, \
                            TriggType,GateSignal,TriggPin,TriggSignal, \
                            EruUnit, EruInput,EruOutput,EruSelect)\
(                                             \
  ((uint32)(GatePin)) |                       \
  ((uint32)(TriggType) << 4U ) |              \
  ((uint32)(GateSignal) << 5U ) |             \
  ((uint32)(TriggPin) << 8U ) |               \
  ((uint32)(TriggSignal) << 12U ) |           \
  ((uint32)(EruUnit) << 16U ) |               \
  ((uint32)(EruInput) << 20U) |               \
  ((uint32)ADC_ERU_EIEN_ENABLE << 27U) |      \
  ((uint32)(EruOutput) << 28U) |              \
  ((uint32)(EruSelect) << 31U)                \
)

#if (ADC_ERU_GATING == STD_ON)
/*******************************************************************************
** Name             : Adc_lConfigEruGate                                      **
**                                                                            **
** Description      : Macro to configure External Gate source for Request     **
**                    line selection and Gate edge selection                  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lConfigEruGate is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lConfigEruGate(GatePin, GateSignal, EruGateUnit, \
                           EruGateInput,EruGateOutput,EruGateSelect)\
(                                             \
  ((uint32)(GatePin)) |                       \
  ((uint32)(GateSignal) << 5U ) |             \
  ((uint32)(EruGateUnit) << 16U ) |           \
  ((uint32)(EruGateInput) << 20U) |           \
  ((uint32)(EruGateOutput) << 28U) |          \
  ((uint32)(EruGateSelect) << 31U)            \
)
#endif /* (ADC_ERU_GATING == STD_ON) */

#if (ADC_USE_EMUX == STD_ON)
/*******************************************************************************
** Name             : Adc_lGroupEmuxData                                      **
**                                                                            **
** Description      : Macro to configure EMUX scan bit and Emux select value  **
**                                                                            **
*******************************************************************************/
/*IFX_MISRA_RULE_19_07_STATUS=Adc_lGroupEmuxData is declared as a function like 
 macro to avoid function call in configuration data structures*/
#define Adc_lGroupEmuxData(EmuxSelect, EmuxScan, EmuxEnable)   \
             ((uint8)((EmuxSelect) | (EmuxScan) | ((uint32)(EmuxEnable) << 3U)))

#endif /* (ADC_USE_EMUX == STD_ON) */
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Funtion Declarations                           **
*******************************************************************************/
[!SELECT "as:modconf('Adc')[1]"!][!//
[!NOCODE!][!//
[!VAR "ShsAvailable" = "'false'"!][!//
[!IF "node:exists(AdcGeneral/AdcSampleAndHoldUnitAvailable)"!][!//
[!VAR "ShsAvailable" = "AdcGeneral/AdcSampleAndHoldUnitAvailable"!][!//
[!ENDIF!][!//
[!IF "$ShsAvailable = 'true'"!][!//
[!VAR "AltRefMode" = "AdcGeneral/AdcAlternateRefMode"!][!//
[!ELSE!][!//
[!VAR "AltRefMode" = "'ADC_REF_LOCAL_MODE'"!][!//
[!ENDIF!][!//
[!VAR "AdcCcu6Synch" = "'false'"!][!//
[!IF "node:exists(AdcGeneral/AdcCcu6Synchronization)"!][!//
[!VAR "AdcCcu6Synch" = "AdcGeneral/AdcCcu6Synchronization"!][!//
[!ENDIF!][!//
[!VAR "EmuxUse" = "AdcGeneral/AdcUseEmux"!][!//
[!IF "node:exists(AdcGeneral/AdcEnableLimitCheck)"!][!//
[!VAR "EnableLimitCheck" = "AdcGeneral/AdcEnableLimitCheck"!][!//
[!ELSE!][!//
[!VAR "EnableLimitCheck" = "'false'"!][!//
[!ENDIF!][!//
[!IF "node:exists(AdcGeneral/AdcSameChannelQueuing)"!][!//
[!VAR "SameChQue" = "AdcGeneral/AdcSameChannelQueuing"!][!//
[!ELSE!][!//
[!VAR "SameChQue" = "'false'"!][!//
[!ENDIF!][!//
[!VAR "AdcDmaResHandling" = "AdcGeneral/AdcNonAutosarDmaResultHandling"!][!//
[!VAR "AdcResPolling" = "AdcGeneral/AdcNonAutosarResultPolling"!][!//
[!//
[!ASSERT "($AdcDmaResHandling = 'false') or ($AdcResPolling = 'false')"!]
 ERROR: Invalid configuration. Non Autosar Result Polling mode is not supported if DMA result handling is enabled. i.e., AdcNonAutosarDmaResultHandling and AdcNonAutosarResultPolling cannot be set to true together.
[!ENDASSERT!][!//
[!//
[!IF "($AdcDmaResHandling = 'false') and ($AdcResPolling = 'false')"!][!//
[!VAR "AdcPrioImp" = "AdcGeneral/AdcPriorityImplementation"!][!//
[!ELSE!][!//
[!ASSERT "$EnableLimitCheck = 'false'","AdcEnableLimitCheck should be set to false when AdcNonAutosarDmaResultHandling or AdcNonAutosarResultPolling is set to true"!][!//
[!VAR "AdcPrioImp" = "'ADC_PRIORITY_NONE'"!][!//
[!ENDIF!][!//
[!//
[!VAR "AdcReqSrcCount"= "num:i(ecu:get('Adc.ReqSrcCount')) - num:i(1)"!][!//
[!//
[!VAR "AdcHwTrigApi" = "AdcGeneral/AdcHwTriggerApi"!][!//
[!VAR "AdcGrpNotif" = "AdcGeneral/AdcGrpNotifCapability"!][!//
[!VAR "TotalAdcConfig" = "num:i(count(AdcConfigSet/*))"!][!//
[!//PostBuildType not used
[!VAR "PostBuildType" = "'SELECTABLE'"!][!//
[!IF "$TotalAdcConfig = num:i(1)"!][!//
[!SELECT "as:modconf('EcuM')[1]/EcuMConfiguration/*[1]"!][!//
[!VAR "PostBuildType1" = "node:exists(EcuMPostBuildConfigType)"!][!//
[!IF "$PostBuildType1 = 'true'"!][!//
[!VAR "PostBuildType" = "EcuMPostBuildConfigType"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!//To determine if any of the Groups Emux scan is enabled
[!VAR "AdcEmuxScanFlag"= "'false'"!][!//
[!VAR "AdcEmuxScan" = "'false'"!][!//
[!//
[!IF "($EmuxUse = 'true') and ($AdcDmaResHandling = 'false')"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "AdcEmuxScan" = "AdcGroup/*[@index = $GroupId]/AdcEmuxScanEnable"!][!//
[!IF "($AdcEmuxScan = 'true')"!][!//
[!VAR "AdcEmuxScanFlag" = "'true'"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!//
[!//To determine Safety feature enabled or not
[!IF "node:exists(AdcSafety/AdcSafetyEnable)"!][!//
[!VAR "Safety" = "AdcSafety/AdcSafetyEnable"!][!//
[!ELSE!][!//
[!VAR "Safety"= "'false'"!][!//
[!ENDIF!][!//
[!//
[!//To determine Parallel sampling enabled or not
[!IF "node:exists(AdcGeneral/AdcMasterSlaveSync)"!][!//
[!VAR "AdcParallelSampling" = "AdcGeneral/AdcMasterSlaveSync"!][!//
[!ELSE!][!//
[!VAR "AdcParallelSampling"= "'false'"!][!//
[!ENDIF!][!//
[!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configuration set [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "MasterMode" = "'false'"!][!//
[!VAR "SyncGrpAMaster" = "'false'"!][!//
[!VAR "SyncGrpBMaster" = "'false'"!][!//
[!VAR "SyncGrpCMaster" = "'false'"!][!//
[!VAR "SyncGrpASlave" = "'false'"!][!//
[!VAR "SyncGrpBSlave" = "'false'"!][!//
[!VAR "SyncGrpCSlave" = "'false'"!][!//
[!VAR "NoOfSalveInSyncGrpA" = "num:i(0)"!][!//
[!VAR "NoOfSalveInSyncGrpB" = "num:i(0)"!][!//
[!VAR "NoOfSalveInSyncGrpC" = "num:i(0)"!][!//
[!VAR "ShValOfSyncGrpA" = "num:i(0)"!][!//
[!VAR "ShValOfSyncGrpB" = "num:i(0)"!][!//
[!VAR "ShValOfSyncGrpC" = "num:i(0)"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!//
[!VAR "SyncMode" = "./AdcSyncConvMode"!][!//
[!IF "$SyncMode = 'ADC_MASTER'"!][!//
[!VAR "MasterMode" = "'true'"!][!//
[!IF "contains(ecu:get('Adc.SyncGroup_A'), concat('_', $UnitId, '_'))"!][!//
[!ASSERT "$SyncGrpAMaster != 'true'"!]
 ERROR: Invalid configuration. More than one Kernel is configured as Master in Synchronization group A (HWUNIT_0/1/2/3) kernels. Only one Master is possible per synchronization groups.
[!ENDASSERT!][!//
[!VAR "SyncGrpAMaster" = "'true'"!][!//
[!VAR "GrpAMasterKernel" = "num:i($UnitId)"!][!//
[!VAR "GrpA_ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!ELSEIF "contains(ecu:get('Adc.SyncGroup_B'), concat('_', $UnitId, '_'))"!][!//
[!ASSERT "$SyncGrpBMaster != 'true'"!]
 ERROR: Invalid configuration. More than one Kernel is configured as Master in Synchronization group B (HWUNIT_4/5/6/7) kernels. Only one Master is possible per synchronization groups.
[!ENDASSERT!][!//
[!VAR "SyncGrpBMaster" = "'true'"!][!//
[!VAR "GrpBMasterKernel" = "num:i($UnitId) - num:i(4)"!][!//
[!VAR "GrpB_ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!ELSEIF "contains(ecu:get('Adc.SyncGroup_C'), concat('_', $UnitId, '_'))"!][!//
[!ASSERT "$SyncGrpCMaster != 'true'"!]
 ERROR: Invalid configuration. More than one Kernel is configured as Master in Synchronization group C (HWUNIT_8/9/10) kernels. Only one Master is possible per synchronization groups.
[!ENDASSERT!][!//
[!VAR "SyncGrpCMaster" = "'true'"!][!//
[!VAR "GrpCMasterKernel" = "num:i($UnitId) - num:i(8)"!][!//
[!VAR "GrpC_ArbRoundLen" = "./AdcArbitrationRoundLength"!][!//
[!ENDIF!][!//
[!ELSEIF "$SyncMode = 'ADC_SLAVE'"!][!//
[!IF "contains(ecu:get('Adc.SyncGroup_A'), concat('_', $UnitId, '_'))"!][!//
[!VAR "SyncGrpASlave" = "'true'"!][!//
[!VAR "ShValOfSyncGrpA" = "bit:shl(num:i(1),num:i($UnitId))"!][!//
[!VAR "NoOfSalveInSyncGrpA" = "bit:or(num:i($NoOfSalveInSyncGrpA),num:i($ShValOfSyncGrpA))"!][!//
[!ELSEIF "contains(ecu:get('Adc.SyncGroup_B'), concat('_', $UnitId, '_'))"!][!//
[!VAR "SyncGrpBSlave" = "'true'"!][!//
[!VAR "ShValOfSyncGrpB" = "bit:shl(num:i(1),(num:i($UnitId) - num:i(4)))"!][!//
[!VAR "NoOfSalveInSyncGrpB" = "bit:or(num:i($NoOfSalveInSyncGrpB),num:i($ShValOfSyncGrpB))"!][!//
[!ELSEIF "contains(ecu:get('Adc.SyncGroup_C'), concat('_', $UnitId, '_'))"!][!//
[!VAR "SyncGrpCSlave" = "'true'"!][!//
[!VAR "ShValOfSyncGrpC" = "bit:shl(num:i(1),(num:i($UnitId) - num:i(8)))"!][!//
[!VAR "NoOfSalveInSyncGrpC" = "bit:or(num:i($NoOfSalveInSyncGrpC),num:i($ShValOfSyncGrpC))"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!ASSERT "$SyncGrpAMaster != 'true' or $SyncGrpASlave = 'true'"!]
 ERROR: Invalid configuration. Synchronization Master is configured without Synchronization Slave in Synchronization group A (HWUNIT_0/1/2/3) kernels.Configure a Synchronization Master in Synchronization group A (HWUNIT_0/1/2/3) or configure all the kernels in the Synchronization group A (HWUNIT_0/1/2/3) as Standalone in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ASSERT "$SyncGrpAMaster = 'true' or $SyncGrpASlave != 'true'"!]
 ERROR: Invalid configuration. Synchronization Slave is configured without Synchronization Master in Synchronization group A (HWUNIT_0/1/2/3) kernels.Configure a Synchronization Master in Synchronization group A (HWUNIT_0/1/2/3) or configure all the kernels in the Synchronization group A (HWUNIT_0/1/2/3) as Standalone in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ASSERT "$SyncGrpBMaster != 'true' or $SyncGrpBSlave = 'true'"!]
 ERROR: Invalid configuration. Synchronization Master is configured without Synchronization Slave in Synchronization group B (HWUNIT_4/5/6/7) kernels.Configure a Synchronization Master in Synchronization group B (HWUNIT_4/5/6/7) or configure all the kernels in the Synchronization group B (HWUNIT_4/5/6/7) as Standalone in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ASSERT "$SyncGrpBMaster = 'true' or $SyncGrpBSlave != 'true'"!]
 ERROR: Invalid configuration. Synchronization Slave is configured without Synchronization Master in Synchronization group B (HWUNIT_4/5/6/7) kernels.Configure a Synchronization Master in Synchronization group B (HWUNIT_4/5/6/7) or configure all the kernels in the Synchronization group B (HWUNIT_4/5/6/7) as Standalone in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ASSERT "$SyncGrpCMaster != 'true' or $SyncGrpCSlave = 'true'"!]
 ERROR: Invalid configuration. Synchronization Master is configured without Synchronization Slave in Synchronization group C (HWUNIT_8/9/10) kernels.Configure a Synchronization Master in Synchronization group C (HWUNIT_8/9/10) or configure all the kernels in the Synchronization group C (HWUNIT_8/9/10) as Standalone in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ASSERT "$SyncGrpCMaster = 'true' or $SyncGrpCSlave != 'true'"!]
 ERROR: Invalid configuration. Synchronization Slave is configured without Synchronization Master in Synchronization group C (HWUNIT_8/9/10) kernels.Configure a Synchronization Master in Synchronization group C (HWUNIT_8/9/10) or configure all the kernels in the Synchronization group C (HWUNIT_8/9/10) as Standalone in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ASSERT "$MasterMode = 'true'"!]
 ERROR: Invalid configuration. When AdcMasterSlaveSync is set to true, one Kernel should be configured as Master in [!"node:name(.)"!]
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

[!IF "$AdcGrpNotif = 'true'"!][!//
[!//Notification Function Declartion
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!VAR "TotalAdcGroup" = "num:i(count(AdcHwUnit/*[num:i($AdcId)]/AdcGroup/*))"!][!//
[!FOR "AdcGrpId" ="num:i(1)" TO "num:i($TotalAdcGroup)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]/AdcGroup/*[num:i($AdcGrpId)]"!][!//
[!//
[!IF "(num:i(count(./AdcNotification/*)) > num:i(0))"!][!//
[!VAR "Notification" = "./AdcNotification/*[num:i(1)]"!][!//
[!ASSERT "($Notification != 'NULL') and ($Notification != 'NULL_PTR') and ($Notification != '')"!][!//
ERROR: If Notification is not desired, then remove the Notification container. Notification of "NULL" , "NULL_PTR" or empty field is not allowed
[!ENDASSERT!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
/* [!"node:name(.)"!][!//
 Group notification function declartion */
extern void [!"./AdcNotification/*[num:i(1)]"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/
/* Mapping of unspecified size constant */
#define ADC_START_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"

[!IF "($AdcDmaResHandling = 'false') and ($AdcResPolling = 'false')"!][!//
[!IF "AdcGeneral/AdcPriorityImplementation = 'ADC_PRIORITY_HW_SW'"!][!//
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
/*
  Constant for extracting the Groups configured for a particular trigger source
  Used in Scheduler function in Adc.c
*/
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!NOCODE!][!//
[!VAR "GroupRS0Mask" = "num:i(0)"!][!//
[!VAR "GroupRS1Mask" = "num:i(0)"!][!//
[!VAR "GroupRS2Mask" = "num:i(0)"!][!//
[!VAR "GroupRS3Mask" = "num:i(0)"!][!//
[!VAR "index" = "num:i(1)"!][!//
[!ENDNOCODE!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
/* ADC[!"$UnitId"!] configuration */
[!VAR "GrpID" = "num:i(0)"!][!//
static const uint32 Adc_kKernel[!"$UnitId"!]GroupMask[!"string(($CfgCount) -num:i(1))"!][] =
{
[!NOCODE!][!//
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!VAR "ShiftRSMask" = "num:i(0)"!][!//
[!VAR "GroupRSMask" = "num:i(0)"!][!//
[!IF "$ReqSrcId = num:i(0)"!]
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_SW'"!][!//
[!VAR "ShiftRSMask" = "bit:shl(num:i($index),num:i($GrpID))"!][!//
[!VAR "GroupRSMask" = "bit:or(num:i($GroupRSMask),num:i($ShiftRSMask))"!][!//
[!VAR "GrpID" = "$GrpID + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$ReqSrcName = 'REQSRC0_8STG_QUE'"!][!//
[!VAR "GroupRS0Mask" = "num:i($GroupRSMask)"!][!//
[!ELSEIF "$ReqSrcName = 'REQSRC1_NCH_SCAN'"!][!//
[!VAR "GroupRS1Mask" = "num:i($GroupRSMask)"!][!//
[!ELSEIF "$ReqSrcName = 'REQSRC2_BGND_SCAN'"!][!//
[!VAR "GroupRS2Mask" = "num:i($GroupRSMask)"!][!//
[!ELSEIF "$ReqSrcName = 'REQSRC3_8STG_QUE'"!][!//
[!VAR "GroupRS3Mask" = "num:i($GroupRSMask)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
  [!"num:inttohex($GroupRS0Mask)"!]U, /* For Request source 0 */
  [!"num:inttohex($GroupRS1Mask)"!]U, /* For Request source 1 */
  [!"num:inttohex($GroupRS2Mask)"!]U[!IF "$AdcReqSrcCount = num:i(3)"!],[!ENDIF!]  /* For Request source 2 */
[!IF "$AdcReqSrcCount = num:i(3)"!][!//
  [!"num:inttohex($GroupRS3Mask)"!]U  /* For Request source 3 */
[!ENDIF!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
[!ENDIF!][!//
[!ENDIF!][!//

/*
                     Container: AdcGlobalConfiguration
*/
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configuration set [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
static const Adc_GlobalCfgType Adc_kGlobCfg[!"string(($CfgCount) -num:i(1))"!] =
{
  /* ADC088: Module Clock control 
     Divider Factor for Analog Internal Clock (fADCI)
     Divider Factor for Digital Arbiter Clock (fADCD)
  */
[!ASSERT "node:refexists(./AdcSystemClock)"!][!//
 ERROR: Invalid configuration. System Clock reference not provided in [!"node:name(.)"!].
[!ENDASSERT!][!//
[!VAR "AdcSpbClock" = "(node:ref(./AdcSystemClock)/McuClockSPBFrequency)"!][!//
[!VAR "AdcDivaValue" = "./AdcAnalogClockDivider"!][!//
[!IF "$AdcDivaValue = num:i(0)"!][!//
  [!VAR "AdcDivaValue" = "num:i(1)"!][!//
[!ENDIF!][!//
[!VAR "AdcDivaValue" = "($AdcDivaValue + num:i(1)) *  num:i(1000000)"!][!//
[!VAR "AdcfadciClock" = "($AdcSpbClock) div num:i($AdcDivaValue)"!][!//
[!ASSERT "$AdcfadciClock >= (ecu:get('Adc.AnalogClockMinMHz')) and $AdcfadciClock <= (ecu:get('Adc.AnalogClockMaxMHz'))"!][!//
  ERROR: Invalid configuration. Analog clock (fADCI) for [!"node:name(.)"!] is ([!"$AdcfadciClock"!]MHz) out of range.
Modify the AdcAnalogClockDivider or McuClockSPBFrequency, such that Adc analog clock (fADCI) is within 2MHz to 25MHz.
[!ENDASSERT!][!//
  Adc_lConfigPrescale( 
    (Adc_PrescaleType)[!"num:inttohex(./AdcAnalogClockDivider)"!],
    (Adc_PrescaleType)[!"num:inttohex(./AdcDigitalArbiterClockDivider)"!]
    ),
  /*Global Input class configuration */
  {
[!LOOP "AdcGlobInputClass/*"!][!//
    Adc_lInpClass
    ( (uint32)[!"./AdcGlobChSampleTime"!],
      (uint32)ADC_[!"./AdcGlobChResolution"!],
[!IF "node:exists(./AdcGlobEmuxChSampleTime)"!][!//
      (uint32)[!"./AdcGlobEmuxChSampleTime"!]
[!ELSE!][!//
      (uint32)0
[!ENDIF!][!//
    )[!IF "not(node:islast())"!],[!ENDIF!]
[!ENDLOOP!][!//   
  },
  /* Control of post calibration */
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
  (uint32)( 
[!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!//
             ((uint32)ADC_[!"./AdcPostCal"!] << [!"num:i($UnitId + 16)"!]U) [!IF "not(node:islast())"!]|[!ENDIF!]  
[!ENDSELECT!][!//
[!ENDFOR!][!//
           ),
[!//
[!IF "$EmuxUse = 'true'"!][!//    
  Adc_lCfgEmuxSelectGrp( 
    [!"./AdcEmuxSelectGrp0"!],
    [!"./AdcEmuxSelectGrp1"!]
    ),
[!ENDIF!][!//
  ADC_[!"./AdcLowPowerSupplyVoltage"!],
  ADC_[!"./AdcRefPrechargeControl"!],
[!IF "$AdcCcu6Synch = 'true'"!][!//
[!NOCODE!][!//
[!ASSERT "node:refexists(./AdcCcu6ModuleRef)"!][!//
 ERROR: Invalid configuration. Ccu6 Module reference not provided in [!"node:name(.)"!].
[!ENDASSERT!][!//
[!ASSERT "(node:ref(./AdcCcu6ModuleRef)/*/Ccu6ModuleUsage) = 'USED_BY_ADC_DRIVER'"!][!//
 ERROR: Invalid configuration. Referenced Ccu6 Module in [!"node:name(.)"!] is not configured for ADC driver usage.
[!ENDASSERT!][!//
[!VAR "Ccu6Module" = "./AdcCcu6ModuleRef"!][!//
[!VAR "nodepath" = "node:path(node:ref(./AdcCcu6ModuleRef))"!][!//
[!SELECT "node:ref($nodepath)"!][!//
[!VAR "Ccu6T13Clk" = "T13/General/T13ClkSelection"!][!//
[!VAR "Ccu6T13Prescaler" = "T13/General/T13PrescalerEnabled"!][!//
[!ENDSELECT!][!//
[!VAR "Ccu6McuCfgBefore" = "(./AdcCcu6ModuleRef)"!][!//
[!VAR "Ccu6McuCfgAfter" = "(./AdcCcu6ModuleRef)"!][!//
[!VAR "AdcMcuCfgBefore" = "(./AdcSystemClock)"!][!//
[!VAR "AdcMcuCfgAfter" = "(./AdcSystemClock)"!][!//
[!//
[!VAR "Ccu6McuConfig" = "''"!][!//
[!VAR "AdcMcuConfig" = "''"!][!//
[!FOR "CfgSep" ="num:i(1)" TO "num:i(4)"!][!//
[!//
[!VAR "Ccu6McuCfgBefore" = "substring-before($Ccu6McuCfgAfter,'/')"!][!//
[!VAR "Ccu6McuConfig" = "concat($Ccu6McuConfig,$Ccu6McuCfgBefore,'/')"!][!//
[!VAR "Ccu6McuCfgAfter" = "substring-after($Ccu6McuCfgAfter,'/')"!][!//
[!//
[!VAR "AdcMcuCfgBefore" = "substring-before($AdcMcuCfgAfter,'/')"!][!//
[!VAR "AdcMcuConfig" = "concat($AdcMcuConfig,$AdcMcuCfgBefore,'/')"!][!//
[!VAR "AdcMcuCfgAfter" = "substring-after($AdcMcuCfgAfter,'/')"!][!//
[!//
[!ENDFOR!][!//
[!//
[!ASSERT "$Ccu6McuConfig = $AdcMcuConfig"!][!//
 ERROR: Invalid configuration. Same McuModuleConfiguration should be refernced for the parameters AdcCcu6ModuleRef and AdcSystemClock in [!"node:name(.)"!].
[!ENDASSERT!][!//
[!//
[!IF "$Ccu6T13Prescaler = 'false'"!][!//    
[!VAR "T13DivValue" = "num:i(1)"!][!//
[!IF "$Ccu6T13Clk != num:i(0)"!][!//    
[!FOR "Power" ="num:i(1)" TO "num:i($Ccu6T13Clk)"!][!//
[!VAR "T13DivValue" = "($T13DivValue * num:i(2))"!][!//
[!ENDFOR!][!//
[!ENDIF!][!//
[!VAR "T13DivValue" = "($T13DivValue) *  num:i(1000000)"!][!//
[!ELSE!][!//
[!//
[!VAR "PowerFactor" = "($Ccu6T13Clk + num:i(8))"!][!//
[!VAR "T13DivValue" = "num:i(1)"!][!//
[!FOR "Power" ="num:i(1)" TO "num:i($PowerFactor)"!][!//
[!VAR "T13DivValue" = "($T13DivValue * num:i(2))"!][!//
[!ENDFOR!][!//
[!VAR "T13DivValue" = "($T13DivValue * num:i(1000000))"!][!//
[!//	
[!ENDIF!][!//
[!VAR "T13Clock" = "($AdcSpbClock) div $T13DivValue"!][!//
[!VAR "T13ClockRemainder" = "($T13Clock) mod num:i(20)"!][!//
[!//
[!ASSERT "(num:i($T13Clock) >= num:i(20)) and ($T13ClockRemainder = num:i(0))"!][!//
  ERROR: Invalid configuration. CCU6x T13 clock should be multiple of 20MHz to generate 20MHz synchronization signal to all VADCs.
Modify the McuClockSPBFrequency or T13ClkSelection or T13PrescalerEnabled, such that Timer T13 clock of the selected CCU6 module is multiple of 20MHz.
T13 Clock is [!"num:i($T13Clock)"!]MHz as per the current configuration.
[!ENDASSERT!][!//
[!//
[!VAR "T13PeriodValue" = "($T13Clock) div num:i(20)"!][!//
[!VAR "T13PeriodValue" = "($T13PeriodValue) - num:i(1)"!][!//
[!VAR "T13DutyValue" = "$T13PeriodValue"!][!//
[!ENDNOCODE!][!//
[!IF "$Ccu6T13Prescaler = 'false'"!][!//
  (uint32)((uint32)[!"num:i($Ccu6T13Clk)"!] << 8U),
[!ELSE!][!//
  (uint32)(((uint32)1 << 11U) | ((uint32)[!"num:i($Ccu6T13Clk)"!] << 8U)),
[!ENDIF!][!//
[!IF "contains($Ccu6Module,'Ccu60')"!][!//    
  (uint32)0x0,
[!ELSE!][!//
  (uint32)0x8,
[!ENDIF!][!//
  (uint16)[!"num:i($T13PeriodValue)"!],
  (uint16)[!"num:i($T13DutyValue)"!],
[!IF "contains($Ccu6Module,'Ccu60')"!][!//    
  ADC_CCU6_MODULE_CCU60,
[!ELSE!][!//
  ADC_CCU6_MODULE_CCU61,
[!ENDIF!][!//
[!ENDIF!][!//
  ADC_NORMAL_MODE
};
[!ENDSELECT!][!//
[!ENDFOR!][!//

/*
                     Container: AdcHWUnitConfiguration
*/
/* 
Configuration: ADC HW unit configuration structure
*/
[!VAR "ConfiguredDmaCh" = "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configuration set [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!//
[!VAR "EmuxScanFlag"= "'false'"!][!//
[!VAR "EmuxScan" = "'false'"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!FOR "GroupId" ="num:i(0)" TO "num:i($TotalAdcGroups)-1"!][!//
[!VAR "EmuxScan" = "AdcGroup/*[@index = $GroupId]/AdcEmuxScanEnable"!][!//
[!IF "($EmuxScan = 'true')"!][!//
[!VAR "EmuxScanFlag" = "'true'"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
/* ADC [!"$UnitId"!] hardware unit configuration */
static const Adc_HwUnitCfgType Adc_kKernel[!"$UnitId"!]HwCfg[!"string(($CfgCount) -num:i(1))"!] =
{
  /*  
     Arbitration Round Length: 00b - 11b
     ANONC : 11b
     ARBM  : 1b
  */
 [!IF "$AdcParallelSampling = 'true' and ./AdcSyncConvMode = 'ADC_SLAVE'"!][!//
 [!IF "contains(ecu:get('Adc.SyncGroup_A'), concat('_', $UnitId, '_'))"!][!//
 Adc_lConfigArbitration((uint32)ADC_[!"$GrpA_ArbRoundLen"!]),
 [!ELSEIF "contains(ecu:get('Adc.SyncGroup_B'), concat('_', $UnitId, '_'))"!][!//
 Adc_lConfigArbitration((uint32)ADC_[!"$GrpB_ArbRoundLen"!]),
 [!ELSEIF "contains(ecu:get('Adc.SyncGroup_C'), concat('_', $UnitId, '_'))"!][!//
 Adc_lConfigArbitration((uint32)ADC_[!"$GrpC_ArbRoundLen"!]),
 [!ENDIF!][!//
 [!ELSE!][!//
 Adc_lConfigArbitration((uint32)ADC_[!"./AdcArbitrationRoundLength"!]),
 [!ENDIF!][!//
  
  /* Trigger source arbitration level control */
  /* HW trigger sources participate in arbitration only when 
     priority mechanism PRIORITY_HW or PRIORITY_HW_SW considered
     Default value for each trigger source is : REQSRC_PRIORITY_0_LOWEST 
     In No priority, the priority levels of trigger source data shall be set 
     to default value.
  */
 [!IF "$AdcPrioImp = 'ADC_PRIORITY_NONE'"!][!//
 Adc_lArbLvlCtrl(                           
                   ADC_REQSRC_PRIORITY_0_LOWEST,
                   ADC_REQSRC_PRIORITY_0_LOWEST,
                   ADC_REQSRC_PRIORITY_0_LOWEST,
                   ADC_REQSRC_PRIORITY_0_LOWEST
                 ),
 [!ELSE!][!//
 Adc_lArbLvlCtrl(                           
                   ADC_[!"./AdcRequestSource0Prio"!],
                   ADC_[!"./AdcRequestSource1Prio"!],
                   ADC_REQSRC_PRIORITY_0_LOWEST,
                   [!IF "$AdcReqSrcCount = num:i(3) and (num:i($UnitId) = num:i(0) or num:i($UnitId) = num:i(1))"!] [!//
                   ADC_[!"./AdcRequestSource3Prio"!]
                   [!ELSE!][!//
ADC_REQSRC_PRIORITY_0_LOWEST
                   [!ENDIF!][!//
                  ),
 [!ENDIF!][!//

  /*Adc Kernel Input class configuration */
  {
[!LOOP "AdcKernelInputClass/*"!][!//
    Adc_lInpClass
    ( (uint32)[!"./AdcKernelChSampleTime"!],
      (uint32)ADC_[!"./AdcKernelChResolution"!],
[!IF "node:exists(./AdcKernelEmuxChSampleTime)"!][!//
      (uint32)[!"./AdcKernelEmuxChSampleTime"!]
[!ELSE!][!//
      (uint32)0
[!ENDIF!][!//
    )[!IF "not(node:islast())"!],[!ENDIF!]
[!ENDLOOP!][!//    
  },
  
  /* Kernel Mode for Parallel sampling */
[!IF "$AdcParallelSampling = 'true'"!][!//
[!IF "./AdcSyncConvMode != 'ADC_STANDALONE'"!][!//
[!// Kernel is configured as master or Slave
[!IF "contains(ecu:get('Adc.SyncGroup_A'), concat('_', $UnitId, '_'))"!][!//
[!VAR "MasterKernel" = "num:i($GrpAMasterKernel)"!][!//
[!VAR "SlaveId" = "num:i($UnitId)"!][!//
[!VAR "SlaveConfigured" = "num:i($NoOfSalveInSyncGrpA)"!][!//
[!ELSEIF "contains(ecu:get('Adc.SyncGroup_B'), concat('_', $UnitId, '_'))"!][!//
[!VAR "MasterKernel" = "num:i($GrpBMasterKernel)"!][!//
[!VAR "SlaveId" = "num:i($UnitId) - num:i(4)"!][!//
[!VAR "SlaveConfigured" = "num:i($NoOfSalveInSyncGrpB)"!][!//
[!ELSEIF "contains(ecu:get('Adc.SyncGroup_C'), concat('_', $UnitId, '_'))"!][!//
[!VAR "MasterKernel" = "num:i($GrpCMasterKernel)"!][!//
[!VAR "SlaveId" = "num:i($UnitId) - num:i(8)"!][!//
[!VAR "SlaveConfigured" = "num:i($NoOfSalveInSyncGrpC)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "./AdcSyncConvMode = 'ADC_SLAVE'"!][!//
[!IF "$MasterKernel = num:i(0)"!][!//
  ADC_SLAVE_CI1,
[!IF "$SlaveConfigured = num:i(14)"!][!//
  /* ADC1,ADC2 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "($SlaveConfigured = num:i(6)) or (($SlaveConfigured = num:i(10)) and ($SlaveId = num:i(3)))"!][!//
  /* (ADC1 & ADC2) or (ADC1 & ADC3) are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "($SlaveConfigured = num:i(12)) or (($SlaveConfigured = num:i(10)) and ($SlaveId = num:i(1)))"!][!//
  /* (ADC2 & ADC3) or (ADC1 & ADC3) are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "($SlaveConfigured = num:i(2)) or ($SlaveConfigured = num:i(4)) or ($SlaveConfigured = num:i(8))"!][!//
  /* ADC1 or ADC2 or ADC3 is configured as Slave */
  (ADC_EVAL_R1),
[!ENDIF!][!//
[!ELSEIF "$MasterKernel = num:i(1)"!][!//
[!IF "$SlaveId = num:i(0)"!][!//
  ADC_SLAVE_CI1,
[!ELSE!][!//
  ADC_SLAVE_CI2,
[!ENDIF!][!//
[!IF "$SlaveConfigured = num:i(13)"!][!//
  /* ADC0,ADC2 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(5)"!][!//
  /* ADC0 & ADC2 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(9)"!][!//
  /* ADC0 & ADC3 are configured as Slaves */
[!IF "$SlaveId = num:i(0)"!][!//
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "$SlaveId = num:i(3)"!][!//
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ENDIF!][!//
[!ELSEIF "$SlaveConfigured = num:i(12)"!][!//
  /* ADC2 & ADC3 are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(1)"!][!//
  /* ADC0 is configured as Slave */
  (ADC_EVAL_R1),
[!ELSEIF "$SlaveConfigured = num:i(4) or ($SlaveConfigured = num:i(8))"!][!//
  /* ADC2 or ADC3 is configured as Slave */
  (ADC_EVAL_R2),
[!ENDIF!][!//
[!ELSEIF "$MasterKernel = num:i(2)"!][!//
[!IF "$SlaveId = num:i(3)"!][!//
  ADC_SLAVE_CI3,
[!ELSE!][!//
  ADC_SLAVE_CI2,
[!ENDIF!][!//
[!IF "$SlaveConfigured = num:i(11)"!][!//
  /* ADC0,ADC1 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(3)"!][!//
  /* ADC0 & ADC1 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(9)"!][!//
  /* ADC0 & ADC3 are configured as Slaves */
[!IF "$SlaveId = num:i(0)"!][!//
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "$SlaveId = num:i(3)"!][!//
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ENDIF!][!//
[!ELSEIF "$SlaveConfigured = num:i(10)"!][!//
  /* ADC1 & ADC3 are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(1) or ($SlaveConfigured = num:i(2))"!][!//
  /* ADC0 or ADC2 is configured as Slave */
  (ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(8)"!][!//
  /* ADC3 is configured as Slave */
  (ADC_EVAL_R3),
[!ENDIF!][!//
[!ELSEIF "$MasterKernel = num:i(3)"!][!//
  ADC_SLAVE_CI3,
[!IF "$SlaveConfigured = num:i(7)"!][!//
  /* ADC0,ADC1 & ADC2 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "($SlaveConfigured = num:i(3)) or (($SlaveConfigured = num:i(5)) and ($SlaveId = num:i(2)))"!][!//
  /* (ADC0 & ADC1) or (ADC0 & ADC2) are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "($SlaveConfigured = num:i(6)) or (($SlaveConfigured = num:i(5)) and ($SlaveId = num:i(0)))"!][!//
  /* (ADC1 & ADC2) or (ADC0 & ADC2) are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(1) or ($SlaveConfigured = num:i(2)) or ($SlaveConfigured = num:i(4))"!][!//
  /* ADC0 or ADC1 or ADC2 is configured as Slave */
  (ADC_EVAL_R3),
[!ENDIF!][!//
[!ENDIF!][!//
[!ELSEIF "./AdcSyncConvMode = 'ADC_STANDALONE'"!][!//
  ADC_STANDALONE,
  (0x00U), /* Evaluate ready input Rx is 0 for Standalone kernel */ 
[!ELSE!][!//
  [!"./AdcSyncConvMode"!],
[!IF "($SlaveConfigured = num:i(14)) or ($SlaveConfigured = num:i(13)) or ($SlaveConfigured = num:i(11)) or ($SlaveConfigured = num:i(7))"!][!//
  /* ADC1,ADC2 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2|ADC_EVAL_R3),
[!ELSEIF "($SlaveConfigured = num:i(1)) or (($SlaveConfigured = num:i(2)) and ($MasterKernel = num:i(0)))"!][!//
  /* ADC0 or ADC1 is configured as Slave */
  (ADC_EVAL_R1),
[!ELSEIF "(($SlaveConfigured = num:i(4)) and ($MasterKernel = num:i(3))) or ($SlaveConfigured = num:i(8))"!][!//
  /* ADC2 or ADC3 is configured as Slave */
  (ADC_EVAL_R3),
[!ELSEIF "($SlaveConfigured = num:i(4)) or ($SlaveConfigured = num:i(2))"!][!//
  /* ADC2 is configured as Slave */
  (ADC_EVAL_R2),
[!ELSEIF "$MasterKernel = num:i(0)"!][!//
[!IF "$SlaveConfigured = num:i(6)"!][!//
  /* ADC1 & ADC2 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(10)"!][!//
  /* ADC1 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(12)"!][!//
  /* ADC2 & ADC3 are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ENDIF!][!//
[!ELSEIF "$MasterKernel = num:i(1)"!][!//
[!IF "$SlaveConfigured = num:i(5)"!][!//
  /* ADC0 & ADC2 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(9)"!][!//
  /* ADC0 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(12)"!][!//
  /* ADC2 & ADC3 are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ENDIF!][!//
[!ELSEIF "$MasterKernel = num:i(2)"!][!//
[!IF "$SlaveConfigured = num:i(3)"!][!//
  /* ADC0 & ADC1 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(9)"!][!//
  /* ADC0 & ADC3 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(10)"!][!//
  /* ADC1 & ADC3 are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ENDIF!][!//
[!ELSEIF "$MasterKernel = num:i(3)"!][!//
[!IF "$SlaveConfigured = num:i(3)"!][!//
  /* ADC0 & ADC1 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R2),
[!ELSEIF "$SlaveConfigured = num:i(5)"!][!//
  /* ADC0 & ADC2 are configured as Slaves */
  (ADC_EVAL_R1|ADC_EVAL_R3),
[!ELSEIF "$SlaveConfigured = num:i(6)"!][!//
  /* ADC1 & ADC2 are configured as Slaves */
  (ADC_EVAL_R2|ADC_EVAL_R3),
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ELSE!][!//
  ADC_STANDALONE,
  (0x00U), /* Evaluate ready input Rx is 0 for Standalone kernel */ 
[!ENDIF!][!//

[!IF "$AdcDmaResHandling = 'true' or $EmuxScanFlag = 'true'"!][!//
  /* DMA Channel selected for Non AUTOSAR result handling or Emux scan */
[!NOCODE!][!//
[!ASSERT "node:refexists(./AdcDmaChannelRef) = 'true'", "DMA Channel reference not provided"!][!//
[!VAR "DmaChUsed" = "(node:ref(./AdcDmaChannelRef)/ChannelUsed)"!][!//
[!VAR "DmaChNum" = "(node:ref(./AdcDmaChannelRef)/ChannelId)"!][!//
[!IF "$AdcDmaResHandling = 'true'"!]
[!ASSERT "$DmaChUsed = 'USE_FOR_ADC_DRIVER' or $DmaChUsed = 'USE_FOR_DMA_CDD'"!]
 ERROR: Invalid configuration. DmaChannel[!"$DmaChNum"!] is not configured for ADC Driver or DMA Complex Driver.
[!ENDASSERT!][!//
[!ELSE!][!//
[!ASSERT "$DmaChUsed = 'USE_FOR_ADC_DRIVER'"!]
 ERROR: Invalid configuration. DmaChannel[!"$DmaChNum"!] is not configured for ADC Driver.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!VAR "ChkDmaCh" = "bit:and($ConfiguredDmaCh,(bit:shl(1,num:i($DmaChNum))))"!][!//  
[!ASSERT "$ChkDmaCh = num:i(0)"!]
 ERROR: Invalid configuration. DmaChannel[!"$DmaChNum"!] (ChannelId = [!"$DmaChNum"!]) is configured more than once in ADC Driver.
[!ENDASSERT!][!//
[!VAR "ConfiguredDmaCh" = "bit:or($ConfiguredDmaCh,(bit:shl(1,num:i($DmaChNum))))"!][!//  
[!ENDNOCODE!][!//
  (uint8)(DMA_CHANNEL[!"$DmaChNum"!])[!IF "($Safety = 'true')"!],[!ENDIF!]
[!ELSE!][!//
  (uint8)(DMA_CHANNEL_INVALID)[!IF "($Safety = 'true')"!],[!ENDIF!]
[!ENDIF!][!//
[!IF "($Safety = 'true')"!][!//
  /* type of the Adc signal ASIL or QM */
[!IF "(./AdcSafetySignal = 'true')"!][!//
[!IF "$UnitId <= num:i(3)"!][!//
[!IF "(ecu:get('Adc.HwUnitPerCluster') = num:i(1))"!][!//
[!IF "$UnitId = num:i(1)"!][!//
  ADC_ASIL_SIGNAL_1
[!ELSE!][!//
  ADC_ASIL_SIGNAL_0
[!ENDIF!][!//
[!ELSEIF "(ecu:get('Adc.HwUnitPerCluster') = num:i(2))"!][!//
[!IF "$UnitId >= num:i(2)"!][!//
  ADC_ASIL_SIGNAL_1
[!ELSE!][!//
  ADC_ASIL_SIGNAL_0
[!ENDIF!][!//
[!ELSE!][!//
  ADC_ASIL_SIGNAL_0
[!ENDIF!][!//
[!ELSE!][!//
  ADC_ASIL_SIGNAL_1
[!ENDIF!][!//
[!ELSE!][!//
  ADC_QM_SIGNAL
[!ENDIF!][!//
[!ENDIF!][!//

};/* Adc HwCfg */
[!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

/*
                     Container: AdcChannelConfiguration
*/
/* 
Configuration: ADC Channel configuration structure
*/
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configuration set [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!VAR "SyncChPresent" = "'false'"!][!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!VAR "KernelMode" = "./AdcSyncConvMode"!][!//
[!ENDIF!][!//
/* ADC [!"$UnitId"!] Channel configuration */
static const Adc_ChannelCfgType Adc_kKernel[!"$UnitId"!]ChCfg[!"string(($CfgCount)-num:i(1))"!][]=
{[!//
[!VAR "ChannelCount" = "0"!][!//
[!LOOP "node:order(./AdcChannel/*, './AdcChannelId')"!]
[!NOCODE!]
[!VAR "ChannelNumber"= "./AdcAnChannelNum"!]
[!VAR "SymbolicName" = "node:name(.)"!]
[!VAR "InClass" = "num:i(0)"!][!//
[!VAR "ChLimitCheck"= "./AdcChannelLimitCheck"!]
[!IF "$ChLimitCheck  = 'true'"!][!//
[!VAR "ChannelRange"= "./AdcChannelRangeSelect"!]
[!ENDIF!][!//
[!ASSERT "node:refexists(AdcInputClassSelection) = 'true'","AdcInputClassSelection not selected"!][!//
[!VAR "classname" = "node:name(node:ref(AdcInputClassSelection))"!][!//
[!VAR "ParentClassname" = "node:name(node:ref(AdcInputClassSelection)/..)"!][!//
[!//
[!IF "contains($ParentClassname,'Kernel')"!][!//
[!LOOP "../../AdcKernelInputClass/*"!][!//
[!IF "$classname = @name"!][!//
[!VAR "InClass" = "@index"!][!//
[!VAR "ChRes" = "./AdcKernelChResolution"!][!//
[!IF "$EnableLimitCheck = 'true'"!]
[!IF "$ChLimitCheck  = 'true'"!][!//
[!IF "$ChRes = 'CH_RES_10BIT'"!][!//
[!VAR "DataShift" = "num:i(2)"!][!//
[!ELSEIF "$ChRes = 'CH_RES_8BIT'"!][!//
[!VAR "DataShift" = "num:i(4)"!][!//
[!ELSEIF "$ChRes = 'CH_RES_12BIT'"!][!//
[!VAR "DataShift" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//

[!ELSE!][!//

[!LOOP "../../../../AdcGlobInputClass/*"!][!//
[!IF "$classname = @name"!][!//
[!VAR "InClass" = "@index"!][!//
[!VAR "InClass" = "$InClass + num:i(2)"!][!//
[!VAR "ChRes" = "./AdcGlobChResolution"!][!//
[!IF "$EnableLimitCheck = 'true'"!]
[!IF "$ChLimitCheck  = 'true'"!][!//
[!IF "$ChRes = 'CH_RES_10BIT'"!][!//
[!VAR "DataShift" = "num:i(2)"!][!//
[!ELSEIF "$ChRes = 'CH_RES_8BIT'"!][!//
[!VAR "DataShift" = "num:i(4)"!][!//
[!ELSEIF "$ChRes = 'CH_RES_12BIT'"!][!//
[!VAR "DataShift" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!]
 {
  /* [!"$SymbolicName"!]  configuration */
  Adc_lConfigChannel(
                      ADC_[!"AdcChannelRefVoltsrcHigh"!],
                      ([!"num:i($InClass)"!]U),
                      ([!"num:inttohex($ChannelNumber)"!]U)
                    ),
[!IF "($SameChQue = 'true')"!][!//
[!NOCODE!][!//
[!VAR "ChResultAcc" = "'ADC_RES_ACCUMULATION_NONE'"!][!//
[!VAR "AccValue" = "num:i(0)"!][!//
[!LOOP "../../AdcGroup/*[(AdcGroupRequestSource = 'REQSRC0_8STG_QUE') or (AdcGroupRequestSource = 'REQSRC3_8STG_QUE')]"!][!//
[!VAR "TotalAdcGroupDef"= "num:i(count(AdcGroupDefinition/*))"!][!//
[!VAR "FirstOccurance" = "num:i(0)"!][!//
[!FOR "GroupDef" = "num:i(0)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!IF "$GroupDef < num:i($TotalAdcGroupDef)"!][!//
[!VAR "SameChCount" = "num:i(1)"!][!//
[!VAR "AnChannel" = "num:i((node:ref(AdcGroupDefinition/*[@index=$GroupDef]))/AdcAnChannelNum)"!][!//
[!VAR "classname" = "(node:ref(AdcGroupDefinition/*[@index=$GroupDef]))/AdcInputClassSelection"!][!//
[!IF "$AnChannel = $ChannelNumber and $FirstOccurance = num:i(0)"!][!//
[!VAR "FirstOccurance" = "num:i(1)"!][!//
[!FOR "LoopIdx" = "num:i($GroupDef)+num:i(1)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!IF "$AnChannel = num:i((node:ref(AdcGroupDefinition/*[@index=$LoopIdx]))/AdcAnChannelNum)"!][!//
[!VAR "classnamecheck" = "(node:ref(AdcGroupDefinition/*[@index=$LoopIdx]))/AdcInputClassSelection"!][!//
[!ASSERT "$classname = $classnamecheck", "Same analog channel with different Input class cannot be added in same group"!][!//
[!VAR "SameChCount" = "num:i($SameChCount) + num:i(1)"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!IF "$AccValue = num:i(0)"!][!//
[!VAR "AccValue" = "num:i($SameChCount)"!][!//
[!ENDIF!][!//
[!ASSERT "num:i($AccValue) = num:i($SameChCount)"!][!//
Config Error: Analog channel [!"num:i($ChannelNumber)"!] in [!"node:name(.)"!] is queued inconsistently across the Queue RS groups. Analog channel should be queued same number of times across the Groups. 
[!ENDASSERT!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDLOOP!][!//

[!ASSERT "$AccValue <= num:i(4)", "Same analog channel in a group cannot be added more than 4 times"!][!//
[!IF "$AccValue = num:i(1)"!][!//
[!VAR "ChResultAcc" = "'ADC_RES_ACCUMULATION_NONE'"!][!//
[!ELSEIF "$AccValue = num:i(2)"!][!//
[!VAR "ChResultAcc" = "'ADC_RES_ACCUMULATION_TWO'"!][!//
[!ELSEIF "$AccValue = num:i(3)"!][!//
[!VAR "ChResultAcc" = "'ADC_RES_ACCUMULATION_THREE'"!][!//
[!ELSEIF "$AccValue = num:i(4)"!][!//
[!VAR "ChResultAcc" = "'ADC_RES_ACCUMULATION_FOUR'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
  [!"$ChResultAcc"!],
[!ELSE!][!//
  ADC_RES_ACCUMULATION_NONE,
[!ENDIF!][!//
[!IF "AdcChannelLimitCheck  = 'true'"!][!//
  ADC_CHANNEL_LIMIT_CHECK,
  (uint32)[!"AdcChannelRangeSelect"!],
[!IF "($ChannelRange = 'ADC_RANGE_ALWAYS') or ($ChannelRange = 'ADC_RANGE_BETWEEN') or ($ChannelRange = 'ADC_RANGE_NOT_BETWEEN')"!][!//
  Adc_lCfgChBoundry(
                      ((uint32)[!"num:i(AdcChannelHighLimit)"!] << (uint32)[!"num:i($DataShift)"!]),
                      ((uint32)[!"num:i(AdcChannelLowLimit)"!] << (uint32)[!"num:i($DataShift)"!])
                   ),
[!ELSEIF "($ChannelRange = 'ADC_RANGE_OVER_HIGH') or ($ChannelRange = 'ADC_RANGE_NOT_OVER_HIGH')"!][!//
  Adc_lCfgChBoundry(
                      ((uint32)[!"num:i(AdcChannelHighLimit)"!] << (uint32)[!"num:i($DataShift)"!]),
                      ((uint32)0)
                   ),
[!ELSEIF "($ChannelRange = 'ADC_RANGE_UNDER_LOW') or ($ChannelRange = 'ADC_RANGE_NOT_UNDER_LOW')"!][!//
  Adc_lCfgChBoundry(
                      ((uint32)0xFFF),
                      ((uint32)[!"num:i(AdcChannelLowLimit)"!] << (uint32)[!"num:i($DataShift)"!])
                   ),
[!ENDIF!][!//
  BNDSELU_BNDSELL,   /* value of BNDSELX bitfields */
[!ELSE!][!//
  0U,  /* Limit Check not enable for the channel */
  0U,  /* No channel event on Limit Check */
  0U,  /* Boundary values */
  0U,  /* value of BNDSELX bitfields */
[!ENDIF!][!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!IF "$KernelMode = 'ADC_MASTER' and ./AdcSyncChannel = 'true'"!][!//
[!ASSERT "AdcChannelLimitCheck != 'true'", "Limit checking enabled channel can't be used for Synchronized conversion."!][!//
[!VAR "SyncChPresent" = "'true'"!][!//
  ADC_SYNC_CHANNEL
[!ELSE!][!//
  0U   /* Channel not enabled for synchronization */
[!ENDIF!][!//
[!ELSE!][!//
  0U   /* Channel not enabled for synchronization */
[!ENDIF!][!//
 }[!IF "$ChannelCount < (num:i(count(../*))-1)"!],[!ELSE!][!ENDIF!]
[!VAR "ChannelCount" = "$ChannelCount+1"!][!//
[!ENDLOOP!][!//
}; /* Adc_ChCfg[!"string(($CfgCount)-num:i(1))"!] */
[!IF "$AdcParallelSampling = 'true'"!][!//
[!ASSERT "$KernelMode != 'ADC_MASTER' or $SyncChPresent = 'true' "!][!//
Config Error: [!"node:name(.)"!] is configured as ADC_MASTER. But none of the channel is enabled for Synchronized conversion. Atleast one channel should be enabled for synchronized conversion, for the MASTER kernel.
[!ENDASSERT!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

/*
                     Container: AdcGroupConfiguration
*/
/*
Configuration: ADC Group Definitions
Array of channel Id (i.e. Channel Index of channel configuration structure )
ending with Delimiter for each Adc Channel Group.
Maximum number of channels in a group shall be 16.
Channels under the same group can not share the same CHCTR register and hence 
configuration of Channel(x) and Channel(x+n16) under the same group is not
allowed.
*/
[!VAR "SameChAdded" = "num:i(0)"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configset [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!VAR "KernelMode" = "./AdcSyncConvMode"!][!//
[!ENDIF!][!//
/* ADC [!"$UnitId"!] unit configuration */
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!]
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//	
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "num:i($UnitId) = num:i(2) or num:i($UnitId) = num:i(3)"!][!//
[!ASSERT "(./AdcGroupRequestSource != 'REQSRC3_8STG_QUE')"!][!//
   Config Error: Invalid configuration. REQSRC3_8STG_QUE is not available for ADC HW unit 2 and 3 of TC23X ADAS devices.
   Do not configure REQSRC3_8STG_QUE for the parameter AdcGroupRequestSource in [!"node:name(.)"!].
[!ENDASSERT!][!//   	
[!ENDIF!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_SW'"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "CfgIndex" = "num:i($CfgCount)-num:i(1)"!][!//
[!VAR "CfgIndex" = "num:i($CfgIndex)"!][!//
[!ENDNOCODE!][!//
static const Adc_GroupDefType Adc_kCfg[!"$CfgIndex"!]Kernel[!"$UnitId"!][!"$SymbolicName"!][]=
{  
[!VAR "TotalAdcGroupDef"= "num:i(count(AdcGroupDefinition/*))"!][!//
  [!"$TotalAdcGroupDef"!]U,
[!CALL "CG_GroupErrorMacro"!][!//
[!FOR "GroupDef" = "num:i(0)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!ASSERT "node:refexists(AdcGroupDefinition/*[@index=$GroupDef]) = 'true'", "ADC Channel reference not provided"!][!//
[!NOCODE!][!//
[!IF "$EnableLimitCheck = 'true'"!][!//
[!IF "(node:ref(AdcGroupDefinition/*[@index=$GroupDef])/AdcChannelLimitCheck) = 'true'"!][!//
[!ASSERT "$TotalAdcGroupDef <=1", "ADC Channel Limit checking is enabled and the Group has more than one Channel"!][!//
[!ASSERT "./AdcEmuxScanEnable = 'false'", "Emux Scan can not be enabled for the Limit check enabled Adc Channel group"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!IF "(node:ref(AdcGroupDefinition/*[@index=$GroupDef])/AdcSyncChannel) = 'true' and $KernelMode= 'ADC_MASTER'"!][!//
[!ASSERT "./AdcEmuxScanEnable = 'false'"!][!//
  Config Error: Emux Scan group [!"node:name(.)"!] can not have Synchronized conversion (AdcSyncChannel) enabled Adc Channel.
[!ENDASSERT!][!//
[!ASSERT "./AdcStreamingNumSamples = num:i(1)"!][!//
  Config Error: AdcStreamingNumSamples in [!"node:name(.)"!] is not configured as 1. AdcStreamingNumSamples should be 1 for Adc Group which has Synchronized conversion (AdcSyncChannel) enabled Adc Channel.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$GroupDef < num:i($TotalAdcGroupDef)-1"!][!//
[!VAR "SameCh" = "num:i(0)"!][!//
[!VAR "SameChCount" = "num:i(1)"!][!//
[!VAR "DesOrderCheck" = "num:i(0)"!][!//
[!VAR "AnChannel" = "num:i((node:ref(AdcGroupDefinition/*[@index=$GroupDef]))/AdcAnChannelNum)"!][!//
[!FOR "LoopIdx" = "num:i($GroupDef)+num:i(1)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!IF "$AnChannel = num:i((node:ref(AdcGroupDefinition/*[@index=$LoopIdx]))/AdcAnChannelNum)"!][!//
[!IF "$SameChQue = 'true' and (($ReqSrcName = 'REQSRC0_8STG_QUE') or ($ReqSrcName = 'REQSRC3_8STG_QUE'))"!][!//
[!VAR "SameChCount" = "num:i($SameChCount) + num:i(1)"!][!//
[!VAR "SameChAdded" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "SameCh" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "$AdcDmaResHandling = 'true'"!][!//
[!IF "$AnChannel < num:i((node:ref(AdcGroupDefinition/*[@index=$LoopIdx]))/AdcAnChannelNum)"!][!//
[!VAR "DesOrderCheck" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!//
[!IF "$AdcReqSrcCount = num:i(3)"!][!//
[!ASSERT "$SameCh = num:i(0)", "Same analog channel in a group is allowed, only if AdcSameChannelQueuing is set to true and AdcGroupRequestSource is REQSRC0_8STG_QUE or REQSRC3_8STG_QUE."!][!//
[!ELSE!][!//
[!ASSERT "$SameCh = num:i(0)", "Same analog channel in a group is allowed, only if AdcSameChannelQueuing is set to true and AdcGroupRequestSource is REQSRC0_8STG_QUE."!][!//
[!ENDIF!][!//
[!ASSERT "$SameChCount <= num:i(4)", "Same analog channel in a group cannot be added more than 4 times"!][!//
[!IF "$AdcDmaResHandling = 'true'"!][!//
[!ASSERT "$DesOrderCheck = num:i(0)", "Group analog channel are not in descending order"!][!//
[!ENDIF!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!VAR "GroupChannelName" = "node:name(node:ref(AdcGroupDefinition/*[@index=$GroupDef]))"!][!//
[!LOOP "../../AdcChannel/*"!][!//
[!IF "@name = $GroupChannelName"!][!//
[!VAR "GroupChannelIndex" = "AdcChannelId"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
  [!"num:i($GroupChannelIndex)"!]U [!IF "$GroupDef != (($TotalAdcGroupDef)-1)"!],[!ENDIF!]
[!ENDFOR!][!//
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!//
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!]
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW'"!][!//
[!NOCODE!][!//
[!VAR "SymbolicName" = "node:name(.)"!][!//
[!VAR "CfgIndex" = "num:i($CfgCount)-num:i(1)"!][!//
[!VAR "CfgIndex" = "num:i($CfgIndex)"!][!//
[!ENDNOCODE!][!//
static const Adc_GroupDefType Adc_kCfg[!"$CfgIndex"!]Kernel[!"$UnitId"!][!"$SymbolicName"!][]=
{  
[!VAR "TotalAdcGroupDef"= "num:i(count(AdcGroupDefinition/*))"!][!//
  [!"$TotalAdcGroupDef"!]U,
[!CALL "CG_GroupErrorMacro"!][!//
[!FOR "GroupDef" = "num:i(0)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!NOCODE!][!//
[!IF "$EnableLimitCheck = 'true'"!][!//
[!IF "(node:ref(AdcGroupDefinition/*[@index=$GroupDef])/AdcChannelLimitCheck) = 'true'"!][!//
[!ASSERT "$TotalAdcGroupDef <=1", "ADC Channel Limit checking is enabled and the Group has more than one Channel"!][!//
[!ASSERT "./AdcEmuxScanEnable = 'false'", "Emux Scan can not be enabled for the Limit check enabled Adc Channel group"!][!//
[!ASSERT "$ReqSrcName !='REQSRC2_BGND_SCAN'", "Hardware triggered Background Request Source Scan (RS2) Adc Group can not have Limit checking enabled Adc Channel"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ASSERT "./AdcEmuxScanEnable = 'false' or $ReqSrcName !='REQSRC2_BGND_SCAN'", "Hardware triggered Background Request Source Scan (RS2) Adc Group can not be Emux Scan enabled Adc Channel group"!][!//
[!IF "$AdcParallelSampling = 'true'"!][!//
[!IF "(node:ref(AdcGroupDefinition/*[@index=$GroupDef])/AdcSyncChannel) = 'true' and $KernelMode= 'ADC_MASTER'"!][!//
[!ASSERT "./AdcEmuxScanEnable = 'false'"!][!//
  Config Error: Emux Scan group [!"node:name(.)"!] can not have Synchronized conversion (AdcSyncChannel) enabled Adc Channel.
[!ENDASSERT!][!//
[!ASSERT "./AdcStreamingNumSamples = num:i(1)"!][!//
  Config Error: AdcStreamingNumSamples in [!"node:name(.)"!] is not configured as 1. AdcStreamingNumSamples should be 1 for Adc Group which has Synchronized conversion (AdcSyncChannel) enabled Adc Channel.
[!ENDASSERT!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "$GroupDef < num:i($TotalAdcGroupDef)-1"!][!//
[!VAR "SameCh" = "num:i(0)"!][!//
[!VAR "SameChCount" = "num:i(1)"!][!//
[!VAR "DesOrderCheck" = "num:i(0)"!][!//
[!VAR "AnChannel" = "num:i((node:ref(AdcGroupDefinition/*[@index=$GroupDef]))/AdcAnChannelNum)"!][!//
[!FOR "LoopIdx" = "num:i($GroupDef)+num:i(1)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!IF "$AnChannel = num:i((node:ref(AdcGroupDefinition/*[@index=$LoopIdx]))/AdcAnChannelNum)"!][!//
[!IF "$SameChQue = 'true' and (($ReqSrcName = 'REQSRC0_8STG_QUE') or ($ReqSrcName = 'REQSRC3_8STG_QUE'))"!][!//
[!VAR "SameChCount" = "num:i($SameChCount) + num:i(1)"!][!//
[!VAR "SameChAdded" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "SameCh" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!IF "$AdcDmaResHandling = 'true'"!][!//
[!IF "$AnChannel < num:i((node:ref(AdcGroupDefinition/*[@index=$LoopIdx]))/AdcAnChannelNum)"!][!//
[!VAR "DesOrderCheck" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!ENDFOR!][!//
[!IF "$AdcReqSrcCount = num:i(3)"!][!//
[!ASSERT "$SameCh = num:i(0)", "Same analog channel in a group is allowed, only if AdcSameChannelQueuing is set to true and AdcGroupRequestSource is REQSRC0_8STG_QUE or REQSRC3_8STG_QUE."!][!//
[!ELSE!][!//
[!ASSERT "$SameCh = num:i(0)", "Same analog channel in a group is allowed, only if AdcSameChannelQueuing is set to true and AdcGroupRequestSource is REQSRC0_8STG_QUE."!][!//
[!ENDIF!][!//
[!ASSERT "$SameChCount <= num:i(4)", "Same analog channel in a group cannot be added more than 4 times"!][!//
[!IF "$AdcDmaResHandling = 'true'"!][!//
[!ASSERT "$DesOrderCheck = num:i(0)", "Group analog channel are not in descending order"!][!//
[!ENDIF!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ASSERT "node:refexists(AdcGroupDefinition/*[@index=$GroupDef]) = 'true'", "ADC Channel reference not provided"!][!//
[!VAR "GroupChannelName" = "node:name(node:ref(AdcGroupDefinition/*[@index=$GroupDef]))"!][!//
[!LOOP "../../AdcChannel/*"!][!//
[!IF "@name = $GroupChannelName"!][!//
[!VAR "GroupChannelIndex" = "AdcChannelId"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
  [!"num:i($GroupChannelIndex)"!]U [!IF "$GroupDef != (($TotalAdcGroupDef)-1)"!],[!ENDIF!]
[!ENDFOR!][!//
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!//
[!//
[!ENDSELECT!][!//
[!ENDFOR!][!// 
[!ENDSELECT!][!//
[!ENDFOR!][!// 
[!IF "$SameChQue = 'true'"!][!//
[!ASSERT "$SameChAdded != num:i(0)"!][!//
Config Error: None of the Que (REQSRC0_8STG_QUE or REQSRC3_8STG_QUE) channel group has queued the same channel more than once eventhough AdcSameChannelQueuing is set to true.
Add the same channel in a respective Adc channel group or set the parameter AdcSameChannelQueuing to false.
[!ENDASSERT!]
[!ENDIF!][!//

/* 
Configuration: ADC Group configuration structure
 - ADC028 : ADC_GROUP_ID refered by Array Index
            ADC_GROUP_PRIORITY if ADC_PRIORITY_HW_SW considered, 
            ADC_GROUP_REPLACEMENT if ADC_PRIORITY_HW_SW considered
            ADC_GROUP_DEFINITION
            ADC_GROUP_TRIGG_SRC
            ADC_GROUP_CONV_MODE
            ADC_STREAMING_NUM_SAMPLES
            ADC_STREAMING_BUFFER_MODE
            ADC_HW_TRIG_SIGNAL if EXT TR Source selected
            ADC_HW_TRIG_TIMER if TIM TR source selected
*/
/* ADC Groups are arranged in the order of their trigger type ( HW/SW ) and 
   request sources (RS0 .. RS2) starting from SW trigger RS0 to 
   SW trigger RS2 and then HW trigger RS0 to HW trigger RS2.
*/
[!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configset [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!IF "$EmuxUse = 'true'"!][!//    
[!VAR "EmuxSelectGrp0" = "./AdcEmuxSelectGrp0"!][!//
[!VAR "EmuxSelectGrp1" = "./AdcEmuxSelectGrp1"!][!//
[!ENDIF!][!//
[!IF "$AdcHwTrigApi = 'true'"!][!//
[!NOCODE!][!//
[!ASSERT "node:refexists(./AdcSystemClock) = 'true'", "System Clock reference not provided"!][!//
[!VAR "AdcGtmClock" = "(node:ref(./AdcSystemClock)/McuClockGTMFrequency)"!][!//
[!ENDNOCODE!][!//
[!ENDIF!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
[!VAR "TotalAdcGroups"= "num:i(count(AdcGroup/*))"!][!//
[!VAR "GroupCnt" = "num:i(0)"!][!//
/* ADC [!"$UnitId"!] Group configuration */
static const Adc_GroupCfgType Adc_kKernel[!"$UnitId"!]GrpCfg[!"string(($CfgCount)-num:i(1))"!][] =
{
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!][!//
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_SW'"!][!//
[!VAR "GroupCnt" = "num:i($GroupCnt) + num:i(1)"!][!//
  {
[!NOCODE!][!//
[!VAR "SymbolicName" = "node:name(.)"!]
[!VAR "CfgIndex" = "num:i($CfgCount)-num:i(1)"!][!//
[!VAR "CfgIndex" = "num:i($CfgIndex)"!][!//
[!ENDNOCODE!][!//
    /*[!"$SymbolicName"!]*/
[!IF "$AdcGrpNotif = 'true'"!][!//
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* ADC079: ADC081: ADC084: ADC085: ADC104: Notification function pointer */
[!IF "(num:i(count(./AdcNotification/*)) > num:i(0))"!][!//
[!NOCODE!][!//
[!VAR "Notification" = "./AdcNotification/*[num:i(1)]"!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
    [!ASSERT "num:isnumber($Notification)!= 'true'"!]
     ERROR: Under SELECTABLE option AdcNotification should be entered as a function name. Change notification of [!"node:name(.)"!]
    [!ENDASSERT!][!//
    [!VAR "Notification" = "concat('&',$Notification)"!]
[!ELSE!][!//
    [!ASSERT "num:isnumber($Notification) = 'true'"!]
     ERROR: Under LOADABLE option AdcNotification should be entered as a Address. Change notification of [!"node:name(.)"!]
    [!ENDASSERT!][!//
    [!VAR "Notification" = "concat($Notification,'U')"!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
    [!"$Notification"!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
[!ENDIF!][!//

    /* Assignment of channels to a channel group */
    /* First element is the number of configured channels in the group */
    /* From Second element will give the channel ID */
    &Adc_kCfg[!"$CfgIndex"!]Kernel[!"$UnitId"!][!"$SymbolicName"!][0U],

[!IF "$AdcHwTrigApi = 'true'"!][!//
#if (ADC_HW_TRIGGER_API == STD_ON)
    (uint32)0, /* no timer cfg values for SW trigg group*/
    (uint32)0,
    (uint32)0,
    (uint32)0,
[!IF "$AdcReqSrcCount = num:i(3)"!][!//
    (uint32)0,
    (uint32)0,
[!ENDIF!][!//
#endif
[!ENDIF!][!//    
    /* Internal channel mask from group defination - derived from the tool */
[!NOCODE!][!//
[!VAR "TotalAdcGroupDef"= "num:i(count(AdcGroupDefinition/*))"!][!//
[!VAR "GroupMask" = "num:i(0)"!][!//
[!VAR "index" = "num:i(1)"!][!//
[!VAR "ShiftMask" = "num:i(0)"!][!//
[!FOR "GroupDef" = "num:i(0)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!VAR "AnalogInputChannelNumber" = "node:ref(AdcGroupDefinition/*[@index=$GroupDef])/AdcAnChannelNum"!][!//
[!CALL "CG_ConfigChannelNum"!]
[!VAR "ShiftMask" = "bit:shl(num:i($index),num:i($InternalChannelMaskNumber))"!][!//
[!VAR "GroupMask" = "bit:or(num:i($GroupMask),num:i($ShiftMask))"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
    (uint16)[!"num:inttohex($GroupMask)"!],

[!IF "$Safety = 'true'"!][!//
    /* Group Marker value */
    (Adc_ValueGroupType)([!"./AdcGroupBufferMarker"!]U),
[!ENDIF!][!//
    /* Group trigger source : SW / HW */
    [!"AdcGroupTriggSrc"!],

    /* Group HW trigger source : RS0 - RS2 */
    ADC_[!"AdcGroupRequestSource"!],

    /* Group conversion mode */
    [!"AdcGroupConversionMode"!][!//
[!IF "(($AdcDmaResHandling = 'false') and ($AdcResPolling = 'false')) or ($EmuxUse = 'true')"!],[!ENDIF!]

[!IF "($AdcDmaResHandling = 'false') and ($AdcResPolling = 'false')"!][!//
#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Number of ADC values to be acquired in streaming access mode */
    (Adc_StreamNumSampleType)[!"AdcStreamingNumSamples"!],

    /* ADC316: Buffer mode type - Configure streaming buffer as 
       "linear buffer" or "ring buffer" */
    [!"AdcStreamingBufferMode"!][!//
[!IF "$AdcPrioImp = 'ADC_PRIORITY_HW_SW'"!],[!//
[!ELSEIF "$EmuxUse = 'true'"!],[!//
[!ENDIF!]

[!IF "$AdcPrioImp = 'ADC_PRIORITY_HW_SW'"!][!//
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)

[!IF "AdcEmuxScanEnable = 'true'"!][!//
    /* Priority level of the group */
    /* Group EMUX SCAN is enabled and hence its priority is highest */
    /* This Group can't be interrupted by other Groups */
    (Adc_GroupPriorityType)254,
[!ELSE!][!//
[!ASSERT "node:exists(AdcGroupPriority/*[num:i(1)]) = 'true'"!][!//
Config Error: Adc Group Priority (AdcGroupPriority) value is not provided in [!"node:name(.)"!][!//
[!ENDASSERT!][!//
    /* Priority level of the group */
    (Adc_GroupPriorityType)[!"AdcGroupPriority/*[num:i(1)]"!],
[!ENDIF!][!//
    /* Group level Replacement mechanism - 
       Vaild only when Group is interruptable
    */
[!IF "AdcEmuxScanEnable = 'true'"!][!//
    ADC_GROUP_REPL_ABORT_RESTART[!//
[!ELSE!][!//
[!ASSERT "node:exists(AdcGroupReplacement/*[num:i(1)]) = 'true'"!][!//
Config Error: Adc Group Relacement (AdcGroupReplacement) mechanism is not provided in [!"node:name(.)"!][!//
[!ENDASSERT!][!//
    [!"AdcGroupReplacement/*[num:i(1)]"!][!//
[!ENDIF!][!//
[!IF "$EmuxUse = 'true'"!],[!ENDIF!]
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
[!ENDIF!]
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
[!//
[!ENDIF!][!//

[!IF "$EmuxUse = 'true'"!][!//
[!NOCODE!][!//
[!VAR "GrpEmuxSelect" = "num:i(0)"!][!//
[!VAR "EmuxEnable" = "num:i(0)"!][!//
[!IF "$HwUnitName = $EmuxSelectGrp0 or $HwUnitName = $EmuxSelectGrp1"!][!//   
[!VAR "GrpEmuxSelect" = "./AdcChannelEmuxSelect"!][!//
[!VAR "EmuxEnable" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "GrpEmuxSelect" = "num:i(0)"!][!//
[!VAR "EmuxEnable" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#if (ADC_USE_EMUX == STD_ON)
  /* ADC EMUX data */
[!IF "AdcEmuxScanEnable = 'true'"!][!//
    Adc_lGroupEmuxData([!"num:inttohex($GrpEmuxSelect)"!]U,ADC_GROUP_EMUX_SCAN_ENABLE,[!"num:i($EmuxEnable)"!]U)
[!ELSE!][!//
    Adc_lGroupEmuxData([!"num:inttohex($GrpEmuxSelect)"!]U,ADC_GROUP_EMUX_SCAN_DISABLE,[!"num:i($EmuxEnable)"!]U)
[!ENDIF!][!//
#endif /* (ADC_USE_EMUX == STD_ON) */
[!ENDIF!][!//
  }[!IF "num:i($GroupCnt) < num:i($TotalAdcGroups)"!],[!ENDIF!]/*[!"$SymbolicName"!]*/ 
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!//
[!IF "$AdcHwTrigApi = 'true'"!][!//
[!//
[!FOR "ReqSrcId" = "num:i(0)" TO "num:i($AdcReqSrcCount)"!][!//
[!IF "$ReqSrcId = num:i(0)"!][!//
[!VAR "ReqSrcName" = "'REQSRC0_8STG_QUE'"!][!//
[!ELSEIF "$ReqSrcId = num:i(1)"!][!//
[!VAR "ReqSrcName" = "'REQSRC1_NCH_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(2)"!][!//
[!VAR "ReqSrcName" = "'REQSRC2_BGND_SCAN'"!][!//
[!ELSEIF "$ReqSrcId = num:i(3)"!][!//
[!VAR "ReqSrcName" = "'REQSRC3_8STG_QUE'"!][!//
[!ENDIF!][!//
[!LOOP "AdcGroup/*[AdcGroupRequestSource = $ReqSrcName]"!][!//
[!IF "./AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW'"!][!//
[!VAR "GroupCnt" = "num:i($GroupCnt) + num:i(1)"!][!//
  {
[!NOCODE!][!//
[!VAR "SymbolicName" = "node:name(.)"!]
[!VAR "CfgIndex" = "num:i($CfgCount)-num:i(1)"!][!//
[!VAR "CfgIndex" = "num:i($CfgIndex)"!][!//
[!ASSERT "(./AdcGroupConversionMode = 'ADC_CONV_MODE_ONESHOT')"!][!//
Config Error: Group conversion mode should be ADC_CONV_MODE_ONESHOT for Hw triggered group [!"node:name(.)"!]
[!ENDASSERT!]
[!ENDNOCODE!][!//
    /*[!"$SymbolicName"!]*/
[!IF "$AdcGrpNotif = 'true'"!][!//
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /* ADC079: ADC081: ADC084: ADC085: ADC104: Notification function pointer */
[!IF "(num:i(count(./AdcNotification/*)) > num:i(0))"!][!//
[!NOCODE!][!//
[!VAR "Notification" = "./AdcNotification/*[num:i(1)]"!][!//
[!IF "$PostBuildType = 'SELECTABLE'"!][!//
    [!ASSERT "num:isnumber($Notification)!= 'true'"!]
     ERROR: Under SELECTABLE option AdcNotification should be entered as a function name. Change notification of [!"node:name(.)"!]
    [!ENDASSERT!][!//
    [!VAR "Notification" = "concat('&',$Notification)"!]
[!ELSE!][!//
    [!ASSERT "num:isnumber($Notification) = 'true'"!]
     ERROR: Under LOADABLE option AdcNotification should be entered as a Address. Change notification of [!"node:name(.)"!]
    [!ENDASSERT!][!//
    [!VAR "Notification" = "concat($Notification,'U')"!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
    [!"$Notification"!],
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    #endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
[!ENDIF!][!//

    /* Assignment of channels to a channel group */
    /* First element is the number of configured channels in the group */
    /* From Second element will give the channel ID */
    &Adc_kCfg[!"$CfgIndex"!]Kernel[!"$UnitId"!][!"$SymbolicName"!][0U],

[!IF "$AdcHwTrigApi = 'true'"!][!//
[!VAR "AdcUnitName" = "concat('ADC',$UnitId)"!][!//
[!VAR "ShortReqSrcName" = "concat('RS',$ReqSrcId)"!][!//

#if (ADC_HW_TRIGGER_API == STD_ON)
[!IF "./AdcHwTrigType = 'HW_TRIGG_EXT_REQ'"!][!//
[!ASSERT "node:exists(./AdcHwTrigSignal/*[num:i(1)]) = 'true'"!][!//
Config Error: Hw Trigger Signal (AdcHwTrigSignal) not provided in [!"node:name(.)"!] 
[!ENDASSERT!]
[!VAR "ExtTrigSignal" = "./AdcHwExtTrigSelect"!][!//

[!IF "($ExtTrigSignal = 'ADC_USE_INTERNAL_TRIG_TO_TRIG_RS3')"!][!//
[!NOCODE!][!//
[!ASSERT "(./AdcGroupRequestSource = 'REQSRC3_8STG_QUE')"!][!//
Config Error: ADC_USE_INTERNAL_TRIG_TO_TRIG_RS3 cannot be selected as Hw Ext Trig Signal for request source other than REQSRC3_8STG_QUE. Change the AdcHwExtTrigSelect configuration in [!"node:name(.)"!].
[!ENDASSERT!]

[!ENDNOCODE!][!//
    Adc_lConfigHwReqSrc( ADC_USE_INTERNAL_TRIG_TO_TRIG_RS3,
                         ADC_HW_TRIGG_EXT_REQ,
                         ADC_GATE_SIGNAL_NONE,
                         [!"./AdcHwExtTrigSelect"!],
                         [!"./AdcHwTrigSignal/*[num:i(1)]"!],
                         (0U), /* ERU trigger not selected*/
                         (0U),
                         (0U),
                         ADC_TRIG_ERU_NOT_SELECTED
                       ),
    (uint32)0, /* Timer trigger not selected */
    (uint32)0, /* Timer channel not referenced */
    (uint32)0, /*  Eru Gate not configured */
    (uint32)[!"./AdcRS3TriggerSeqCount"!], /* RS3 Trigger Sequence count */
    ADC_[!"./AdcRS3InternalTrigger"!], /* RS3 Internal Trigger */
[!ENDIF!][!//
[!//
[!NOCODE!][!//
[!VAR "EruSelected" = "contains($ExtTrigSignal,'IOUT')"!][!//

[!IF "(./AdcHwGateSignal != 'ADC_GATE_SIGNAL_NONE' or $ExtTrigSignal = 'ADC_USE_GATE_PIN_TO_TRIG')"!][!//
[!VAR "HwGatePin" = "./AdcHwGatePin"!][!//
[!VAR "LogCheck1" = "contains($HwGatePin,$ShortReqSrcName)"!][!//
[!VAR "LogCheck2" = "contains($HwGatePin,$AdcUnitName)"!][!//
[!VAR "LogCheck3" = "contains($HwGatePin,'ADCx')"!][!//
[!ASSERT "($LogCheck1 = 'true') and ($LogCheck2 = 'true' or $LogCheck3 = 'true')"!][!//
Config Error: Hw Gate Pin is not matching with request source / ADC Unit in [!"node:name(.)"!]
[!ENDASSERT!]
[!ENDIF!][!//

[!IF "($ExtTrigSignal != 'ADC_USE_GATE_PIN_TO_TRIG') and ($ExtTrigSignal != 'ADC_USE_INTERNAL_TRIG_TO_TRIG_RS3')"!][!//
[!//
[!VAR "LogCheck1" = "contains($ExtTrigSignal,$ShortReqSrcName)"!][!//
[!VAR "LogCheck2" = "contains($ExtTrigSignal,$AdcUnitName)"!][!//
[!VAR "LogCheck3" = "contains($ExtTrigSignal,'ADCx')"!][!//
[!ASSERT "($LogCheck1 = 'true') and ($LogCheck2 = 'true' or $LogCheck3 = 'true')"!][!//
Config Error: Hw Ext Trig Signal is not matching with request source / ADC Unit in [!"node:name(.)"!] 
[!ENDASSERT!]
[!IF "$EruSelected = 'true'"!][!//
[!//
[!ASSERT "node:refexists(./AdcEruTriggRef) = 'true'", "ERU Trigg reference not provided"!][!//
[!VAR "EruUnit" = "node:name(node:ref(./AdcEruTriggRef))"!][!//
[!VAR "nodepath" = "node:path(node:ref(./AdcEruTriggRef))"!][!//
[!SELECT "node:ref($nodepath)"!]
[!//
[!VAR "EruChUsage" = "./EruChannelUsage"!][!//
[!ASSERT "($EruChUsage = 'USED_BY_ADC_DRIVER')"!][!//
Config Error: Selected Eru unit [!"($EruUnit)"!] is not configured for the use of ADC driver. 
[!ENDASSERT!]
[!VAR "EruInput" = "./EruInputLine"!][!//
[!VAR "EruOutput" = "./EruOutputUnit"!][!//
[!//
[!IF "contains($EruOutput,'UNIT0')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU0'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT1')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU1'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT2')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU2'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT3')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU3'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT4')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU4'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT5')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU5'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT6')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU6'"!][!//
[!ELSEIF "contains($EruOutput,'UNIT7')"!][!//
[!VAR "EruOut" = "'ADC_ERU_OGU7'"!][!//
[!ENDIF!][!//
[!//
[!IF "$LogCheck3 = 'true'"!][!//
[!VAR "OguId" = "substring($ExtTrigSignal,20,1)"!][!//
[!ASSERT "contains($EruOutput,$OguId)"!][!//
Config Error: Selected Eru unit [!"($EruUnit)"!] is not configured for the correct Output gating unit OGU[!"($OguId)"!]. 
[!ENDASSERT!]
[!ELSE!][!//
[!IF "($UnitId = num:i(8))"!][!//
[!ASSERT "contains($EruOutput,'0')"!][!//
Config Error: Selected Eru unit [!"($EruUnit)"!] is not configured for the correct ADC[!"'8'"!] Hw Unit. 
[!ENDASSERT!]
[!ELSEIF "($UnitId = num:i(9))"!][!//
[!ASSERT "contains($EruOutput,'1')"!][!//
Config Error: Selected Eru unit [!"($EruUnit)"!] is not configured for the correct ADC[!"'9'"!] Hw Unit. 
[!ENDASSERT!]
[!ELSEIF "($UnitId = num:i(10))"!][!//
[!ASSERT "contains($EruOutput,'2')"!][!//
Config Error: Selected Eru unit [!"($EruUnit)"!] is not configured for the correct ADC[!"'10'"!] Hw Unit. 
[!ENDASSERT!]
[!ELSE!][!//
[!ASSERT "contains($EruOutput,$UnitId)"!][!//
Config Error: Selected Eru unit [!"($EruUnit)"!] is not configured for the correct ADC[!"($UnitId)"!] Hw Unit. 
[!ENDASSERT!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "($ExtTrigSignal != 'ADC_USE_INTERNAL_TRIG_TO_TRIG_RS3')"!][!//
[!//
    Adc_lConfigHwReqSrc(
                         [!IF "(./AdcHwGateSignal != 'ADC_GATE_SIGNAL_NONE' or $ExtTrigSignal = 'ADC_USE_GATE_PIN_TO_TRIG')"!][!//
[!"./AdcHwGatePin"!],
[!ELSE!][!//
(0U), /* No gate selected */
[!ENDIF!][!//
                         ADC_HW_TRIGG_EXT_REQ,
                         [!IF "($ExtTrigSignal = 'ADC_USE_GATE_PIN_TO_TRIG')"!][!//
ADC_GATE_SIGNAL_NONE,
[!ELSE!][!//
[!"./AdcHwGateSignal"!],
[!ENDIF!][!//
                         [!"./AdcHwExtTrigSelect"!],
                         [!"./AdcHwTrigSignal/*[num:i(1)]"!],
                         [!IF "$EruSelected = 'true'"!][!//
ADC_HW_[!"$EruUnit"!],
                         [!"$EruInput"!],
                         [!"$EruOut"!],
                         ADC_TRIG_ERU_SELECTED
                         [!ELSE!][!//
(0U), /* ERU trigger not selected*/
                         (0U),
                         (0U),
                         ADC_TRIG_ERU_NOT_SELECTED
                         [!ENDIF!][!//
),

    (uint32)0, /* Timer trigger not selected */
    (uint32)0, /* Timer channel not referenced */
[!IF "(./AdcHwGateSignal != 'ADC_GATE_SIGNAL_NONE' or $ExtTrigSignal = 'ADC_USE_GATE_PIN_TO_TRIG')"!][!//
[!NOCODE!][!//
[!//
[!ASSERT "(not(contains(./AdcHwGatePin, 'TIM')) or ($ExtTrigSignal = 'ADC_USE_GATE_PIN_TO_TRIG'))"!][!//
Config Error: Gtm timer cannot be used as Gate pin for trigger type HW_TRIGG_EXT_REQ if AdcHwExtTrigSelect is other than ADC_USE_GATE_PIN_TO_TRIG in [!"node:name(.)"!]
[!ENDASSERT!]
[!IF "(contains(./AdcHwGatePin, 'PDOUT'))"!][!//
[!ASSERT "$ReqSrcName != 'REQSRC2_BGND_SCAN'", "ERU Gating is not applicable for Background Request Source (RS2)"!][!//
[!ASSERT "node:refexists(./AdcEruGateRef) = 'true'", "ERU Gate reference not provided"!][!//
[!VAR "EruGateUnit" = "node:name(node:ref(./AdcEruGateRef))"!][!//
[!IF "$EruSelected = 'true'"!][!//
[!ASSERT "$EruGateUnit != $EruUnit"!][!//
Config Error: [!"$EruUnit"!] is configured as ERU Gating uint and ERU Triggering unit in [!"node:name(.)"!]. ERU Gating uint and ERU Triggering unit should be dfferent.
[!ENDASSERT!]
[!ENDIF!][!//
[!VAR "nodepath" = "node:path(node:ref(./AdcEruGateRef))"!][!//
[!SELECT "node:ref($nodepath)"!]
[!//
[!VAR "EruGateChannelUsage" = "./EruChannelUsage"!][!//
[!ASSERT "($EruGateChannelUsage = 'USED_BY_ADC_DRIVER')"!][!//
Config Error: Selected Eru unit [!"($EruGateUnit)"!] is not configured for the use of ADC driver. 
[!ENDASSERT!]
[!VAR "EruGateInput" = "./EruInputLine"!][!//
[!VAR "EruGateOutput" = "./EruOutputUnit"!][!//
[!//
[!IF "contains($EruGateOutput,'UNIT0')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU0'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT1')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU1'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT2')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU2'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT3')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU3'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT4')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU4'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT5')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU5'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT6')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU6'"!][!//
[!ELSEIF "contains($EruGateOutput,'UNIT7')"!][!//
[!VAR "EruGateOut" = "'ADC_ERU_OGU7'"!][!//
[!ENDIF!][!//
[!//
[!IF "($UnitId = num:i(8))"!][!//
[!ASSERT "contains($EruGateOutput,'0')"!][!//
Config Error: Selected Eru Gate unit [!"($EruGateUnit)"!] is not configured for the correct ADC[!"'8'"!] Hw Unit. 
[!ENDASSERT!]
[!ELSEIF "($UnitId = num:i(9))"!][!//
[!ASSERT "contains($EruGateOutput,'1')"!][!//
Config Error: Selected Eru Gate unit [!"($EruGateUnit)"!] is not configured for the correct ADC[!"'9'"!] Hw Unit. 
[!ENDASSERT!]
[!ELSEIF "($UnitId = num:i(10))"!][!//
[!ASSERT "contains($EruGateOutput,'2')"!][!//
Config Error: Selected Eru Gate unit [!"($EruGateUnit)"!] is not configured for the correct ADC[!"'10'"!] Hw Unit. 
[!ENDASSERT!]
[!ELSE!][!//
[!ASSERT "contains($EruGateOutput,$UnitId)"!][!//
Config Error: Selected Eru Gate unit [!"($EruGateUnit)"!] is not configured for the correct ADC[!"($UnitId)"!] Hw Unit. 
[!ENDASSERT!]
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!IF "(contains(./AdcHwGatePin, 'PDOUT'))"!][!//
[!//
    Adc_lConfigEruGate(
                       [!"./AdcHwGatePin"!],
                       [!IF "($ExtTrigSignal = 'ADC_USE_GATE_PIN_TO_TRIG')"!][!//
ADC_GATE_SIGNAL_NONE,
[!ELSE!][!//
[!"./AdcHwGateSignal"!],
[!ENDIF!][!//
                       ADC_HW_[!"$EruGateUnit"!],
                       [!"$EruGateInput"!],
                       [!"$EruGateOut"!],
                       ADC_GATE_ERU_SELECTED
                      ),
[!ELSE!][!//
    (uint32)0, /* Eru Gate not configured */
[!ENDIF!][!//
[!ELSE!][!//
    (uint32)0, /* Eru Gate not configured */
[!ENDIF!][!//
[!IF "($AdcReqSrcCount = num:i(3))"!][!//
    (uint32)0, /* RS3 Internal triggering not used */
    (uint32)0, /* RS3 Internal triggering not used  */
[!ENDIF!][!//
[!ENDIF!][!//
[!//
[!ELSE!][!//
[!NOCODE!][!//
[!ASSERT "(contains(./AdcHwGatePin, 'TIM'))"!][!//
Config Error: Gate Pin is not matching with Hw trigg type / ADC Unit in [!"node:name(.)"!]
[!ENDASSERT!]
[!ENDNOCODE!][!//
    Adc_lConfigHwReqSrc(
                         [!"./AdcHwGatePin"!],
                         ADC_HW_TRIGG_TIMER,
                         ADC_GATE_SIGNAL_NONE,
                         ADC_USE_GATE_PIN_TO_TRIG,
                         ADC_HW_TRIG_RISING_EDGE,
                         (0U),/* ERU trigger not selected */
                         (0U),
                         (0U),
                         ADC_TRIG_ERU_NOT_SELECTED
                       ),                  
[!NOCODE!][!//

[!VAR "GtmTimerSignal" = "./AdcHwGatePin"!][!//
[!VAR "LogCheck1" = "contains($GtmTimerSignal,$ShortReqSrcName)"!][!//
[!VAR "LogCheck2" = "contains($GtmTimerSignal,$AdcUnitName)"!][!//
[!VAR "LogCheck3" = "contains($GtmTimerSignal,'ADCx')"!][!//
[!ASSERT "($LogCheck1 = 'true') and ($LogCheck2 = 'true' or $LogCheck3 = 'true')"!][!//
Config Error: Gtm Gate Pin is not matching with request source / ADC Unit in [!"node:name(.)"!]
[!ENDASSERT!]
[!ASSERT "node:refexists(./AdcGtmTriggerRef) = 'true'", "Timer reference not provided"!][!//
[!//
[!IF "$ShortReqSrcName = 'RS2'"!][!//
[!IF "$AdcUnitName = 'ADC10'"!][!//
[!VAR "TrigUnit" = "substring($GtmTimerSignal,25,1)"!][!//
[!ELSE!][!//
[!VAR "TrigUnit" = "substring($GtmTimerSignal,24,1)"!][!//
[!ENDIF!][!//
[!ELSE!][!//
[!IF "$AdcUnitName = 'ADC10'"!][!//
[!VAR "TrigUnit" = "substring($GtmTimerSignal,29,1)"!][!//
[!ELSE!][!//
[!IF "($AdcReqSrcCount = num:i(3))"!][!//
[!VAR "TrigUnit" = "substring($GtmTimerSignal,32,1)"!][!//
[!ELSE!][!//
[!VAR "TrigUnit" = "substring($GtmTimerSignal,28,1)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!// fix for UTP AI00186469
[!VAR "nodepath" = "node:path(node:ref(./AdcGtmTriggerRef))"!][!//
[!SELECT "node:ref($nodepath)"!][!//
[!//
[!VAR "McuModuleNum" = "(../../../../../../@index)"!][!//
[!VAR "GtmModuleNum" = "(../../../../@index)"!][!//
[!IF "$TrigUnit = num:i(0)"!][!//
[!VAR "GtmModChannel" = "./GtmTrigger0Select"!][!//
[!ELSE!][!//
[!VAR "GtmModChannel" = "./GtmTrigger1Select"!][!//
[!ENDIF!][!//
[!ASSERT "($GtmModChannel != 'TRIG_0_NONE')"!][!//
Config Error: Gtm Trigger is selected as TRIG_0_NONE in [!"node:name(.)"!]. Select the correct Trigger.
[!ENDASSERT!]
[!//
[!ENDSELECT!][!//

[!// Call GTM macro to convert ms to ticks
[!CALL "CG_GtmGetTicksPerMs","TriggerString" = "$GtmModChannel","McuModuleId" = "$McuModuleNum", "GtmModuleId" = "$GtmModuleNum","MCU_GTMClock" = "$AdcGtmClock", "ClockTicks" = "num:i(0)"!][!//

[!VAR "AtomChannel" = "contains($GtmModChannel,"ATOM")"!]
[!IF "$AtomChannel = "true" "!]
[!//
[!VAR "ModuleIdFind" = "substring($TriggerString,7,1)"!][!//
[!IF "$ModuleIdFind = '_' "!]
[!VAR "GtmModule" = "substring($GtmModChannel,8,5)"!][!//
[!VAR "GtmChannel" = "substring($GtmModChannel,16,2)"!][!//
[!ELSE!]
[!VAR "GtmModule" = "substring($GtmModChannel,9,5)"!][!//
[!VAR "GtmChannel" = "substring($GtmModChannel,17,2)"!][!//
[!ENDIF!]
[!//
[!ELSE!]
[!//
[!VAR "ModuleIdFind" = "substring($TriggerString,7,1)"!][!//
[!IF "$ModuleIdFind = '_' "!]
[!VAR "GtmModule" = "substring($GtmModChannel,8,4)"!][!//
[!VAR "GtmChannel" = "substring($GtmModChannel,15,2)"!][!//
[!ELSE!]
[!VAR "GtmModule" = "substring($GtmModChannel,9,4)"!][!//
[!VAR "GtmChannel" = "substring($GtmModChannel,16,2)"!][!//
[!ENDIF!]
[!//
[!ENDIF!]
[!//
[!ENDNOCODE!][!//
    ([!"num:i($ClockTicks)"!]UL),  /* Configured timer ticks */
    ADC_GTM_[!"$GtmModule"!]_CHANNEL[!"$GtmChannel"!],
    (uint16)0, /* Eru Gate not configured */
[!IF "($AdcReqSrcCount = num:i(3))"!][!//
    (uint32)0, /* RS3 Internal triggering not used */
    (uint32)0, /* RS3 Internal triggering not used  */
[!ENDIF!][!//
[!ENDIF!][!//
#endif
[!ENDIF!][!//    
    /* Internal channel mask from group defination - derived from the tool */
[!NOCODE!][!//
[!VAR "TotalAdcGroupDef"= "num:i(count(AdcGroupDefinition/*))"!][!//
[!VAR "GroupMask" = "num:i(0)"!][!//
[!VAR "index" = "num:i(1)"!][!//
[!VAR "ShiftMask" = "num:i(0)"!][!//
[!FOR "GroupDef" = "num:i(0)" TO "num:i($TotalAdcGroupDef)-1"!][!//
[!VAR "AnalogInputChannelNumber" = "node:ref(AdcGroupDefinition/*[@index=$GroupDef])/AdcAnChannelNum"!][!//
[!CALL "CG_ConfigChannelNum"!]
[!VAR "ShiftMask" = "bit:shl(num:i($index),num:i($InternalChannelMaskNumber))"!][!//
[!VAR "GroupMask" = "bit:or(num:i($GroupMask),num:i($ShiftMask))"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
    (uint16)[!"num:inttohex($GroupMask)"!],

[!IF "$Safety = 'true'"!][!//
    /* Group Marker value */
    (Adc_ValueGroupType)([!"./AdcGroupBufferMarker"!]U),
[!ENDIF!][!//
    /* Group trigger source : SW / HW */
    [!"AdcGroupTriggSrc"!],

    /* Group HW trigger source : RS0 - RS2 */
    ADC_[!"AdcGroupRequestSource"!],

    /* Group conversion mode */
    [!"AdcGroupConversionMode"!][!//
[!IF "(($AdcDmaResHandling = 'false') and ($AdcResPolling = 'false')) or ($EmuxUse = 'true')"!],[!ENDIF!]

[!IF "($AdcDmaResHandling = 'false') and ($AdcResPolling = 'false')"!][!//
#if (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR)
    /* Number of ADC values to be acquired in streaming access mode */
    (Adc_StreamNumSampleType)[!"AdcStreamingNumSamples"!],

    /* ADC316: Buffer mode type - Configure streaming buffer as 
       "linear buffer" or "ring buffer" */

    [!"AdcStreamingBufferMode"!][!//
[!IF "$AdcPrioImp = 'ADC_PRIORITY_HW_SW'"!],[!//
[!ELSEIF "$EmuxUse = 'true'"!],[!//
[!ENDIF!]

[!IF "$AdcPrioImp = 'ADC_PRIORITY_HW_SW'"!][!//
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
    /* Priority level of the group */
    (Adc_GroupPriorityType)0,

    /* Group level Replacement mechanism - 
       Vaild only when Group is interruptable
       HW trigger groups are not interruptable
    */
    ADC_GROUP_REPL_ABORT_RESTART /* Default value */[!//
[!IF "$EmuxUse = 'true'"!],[!ENDIF!]
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
[!ENDIF!][!//
#endif /* (ADC_RESULT_HANDLING_MODE == ADC_AUTOSAR) */
[!//
[!ENDIF!][!//

[!IF "$EmuxUse = 'true'"!][!//
[!NOCODE!][!//
[!VAR "GrpEmuxSelect" = "num:i(0)"!][!//
[!VAR "EmuxEnable" = "num:i(0)"!][!//
[!IF "$HwUnitName = $EmuxSelectGrp0 or $HwUnitName = $EmuxSelectGrp1"!][!//   
[!VAR "GrpEmuxSelect" = "./AdcChannelEmuxSelect"!][!//
[!VAR "EmuxEnable" = "num:i(1)"!][!//
[!ELSE!][!//
[!VAR "GrpEmuxSelect" = "num:i(0)"!][!//
[!VAR "EmuxEnable" = "num:i(0)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
#if (ADC_USE_EMUX == STD_ON)
  /* ADC EMUX data */
[!IF "AdcEmuxScanEnable = 'true'"!][!//
    Adc_lGroupEmuxData([!"num:inttohex($GrpEmuxSelect)"!]U,ADC_GROUP_EMUX_SCAN_ENABLE,[!"num:i($EmuxEnable)"!]U)
[!ELSE!][!//
    Adc_lGroupEmuxData([!"num:inttohex($GrpEmuxSelect)"!]U,ADC_GROUP_EMUX_SCAN_DISABLE,[!"num:i($EmuxEnable)"!]U)
[!ENDIF!][!//
#endif /* (ADC_USE_EMUX == STD_ON) */
[!ENDIF!][!//
  }[!IF "num:i($GroupCnt) < num:i($TotalAdcGroups)"!],[!ENDIF!]/*[!"$SymbolicName"!]*/
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!//
[!ENDIF!][!//
};
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//

/*
                     Container: Adc Kernel Configuration
*/
/*
Configuration : Adc_KernelConfigType
Configuration of ADC: 
Pointer to Adc Hw Unit configuration
Pointer to the array of channel configuration
Pointer to the array of group configuration
Pointer to the array of Group mask in each trigger source
Total number of configured groups
*/
[!VAR "AdcPrioImp" = "AdcGeneral/AdcPriorityImplementation"!][!//
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configset [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!//
[!VAR "HwUnitName" = "./AdcHwUnitId"!][!//
[!VAR "UnitId" = "substring($HwUnitName,11,2)"!][!//
[!VAR "UnitId" = "num:i($UnitId)"!][!//
/* ADC [!"$UnitId"!]  configuration */
static const Adc_KernelConfigType  Adc_kKernel[!"$UnitId"!]Config[!"string(($CfgCount)-num:i(1))"!] =
{
  /* Pointer to Adc Hw Unit configuration */
  &Adc_kKernel[!"$UnitId"!]HwCfg[!"string(($CfgCount)-num:i(1))"!],

  /* Pointer to the array of channel configuration */
  &Adc_kKernel[!"$UnitId"!]ChCfg[!"string(($CfgCount)-num:i(1))"!][0U],

  /* Pointer to the array of group configuration */
  &Adc_kKernel[!"$UnitId"!]GrpCfg[!"string(($CfgCount)-num:i(1))"!][0U],

[!IF "$AdcPrioImp = 'ADC_PRIORITY_HW_SW'"!][!//
#if (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW)
  /* Pointer to the array of Group mask for SW, AS, CHIN trigger sources */
  &Adc_kKernel[!"$UnitId"!]GroupMask[!"string(($CfgCount)-num:i(1))"!][0U],
#endif /* (ADC_PRIORITY_IMPLEMENTATION == ADC_PRIORITY_HW_SW) */
[!ENDIF!][!//

  /* Total number of configured groups */
[!NOCODE!][!//
[!VAR "Count"= "num:i(count(AdcGroup/*))"!][!//
[!ENDNOCODE!][!//
  [!"$Count"!]U
};/* Adcx Configuration */
[!ENDSELECT!] 
[!ENDFOR!][!//
[!ENDSELECT!] 
[!ENDFOR!][!//

/*
                     Container: AdcConfiguration
*/
/*
Configuration : Adc_ConfigType
Configuration of ADC: 
Pointer to Adc Hw Unit configuration
Pointer to the array of channel configuration
Pointer to the array of group configuration
Pointer to the array of Group mask in each trigger source
Total number of configured groups
*/
const Adc_ConfigType  Adc_ConfigRoot[[!"string(num:i($TotalAdcConfig))"!]] =
{
[!FOR "CfgCount" ="num:i(1)" TO "num:i($TotalAdcConfig)"!][!//
/*Configset [!"$CfgCount"!] */
[!SELECT "AdcConfigSet/*[num:i($CfgCount)]"!][!//
  {
[!IF "$Safety = 'true'"!][!//
    /* Configuration Marker value */
    (uint32)(0x007B0000U),
[!ENDIF!][!//
[!NOCODE!][!//
[!// Flags initialised to 0
[!VAR "Adc0Flag" = "num:i(0)"!][!//
[!VAR "Adc1Flag" = "num:i(0)"!][!//
[!VAR "Adc2Flag" = "num:i(0)"!][!//
[!VAR "Adc3Flag" = "num:i(0)"!][!//
[!VAR "Adc4Flag" = "num:i(0)"!][!//
[!VAR "Adc5Flag" = "num:i(0)"!][!//
[!VAR "Adc6Flag" = "num:i(0)"!][!//
[!VAR "Adc7Flag" = "num:i(0)"!][!//
[!VAR "Adc8Flag" = "num:i(0)"!][!//
[!VAR "Adc9Flag" = "num:i(0)"!][!//
[!VAR "Adc10Flag" = "num:i(0)"!][!//
[!VAR "TotalAdcUnit" = "num:i(count(AdcHwUnit/*))"!][!//
[!FOR "AdcId" ="num:i(1)" TO "num:i($TotalAdcUnit)"!][!//
[!SELECT "AdcHwUnit/*[num:i($AdcId)]"!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC0'"!][!//
[!VAR "Adc0Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC1'"!][!//
[!VAR "Adc1Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC2'"!][!//
[!VAR "Adc2Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC3'"!][!//
[!VAR "Adc3Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC4'"!][!//
[!VAR "Adc4Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC5'"!][!//
[!VAR "Adc5Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC6'"!][!//
[!VAR "Adc6Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC7'"!][!//
[!VAR "Adc7Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC8'"!][!//
[!VAR "Adc8Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC9'"!][!//
[!VAR "Adc9Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!IF "./AdcHwUnitId = 'HWUNIT_ADC10'"!][!//
[!VAR "Adc10Flag" = "num:i(1)"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
    {
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC0')"!][!//
      /* Pointer to Adc0 configuration */
[!IF "$Adc0Flag = num:i(1)"!][!//
      &Adc_kKernel0Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC1')"!][!//
,
      /* Pointer to Adc1 configuration */
[!IF "$Adc1Flag = num:i(1)"!][!//
      &Adc_kKernel1Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC2')"!][!//
,
      /* Pointer to Adc2 configuration */
[!IF "$Adc2Flag = num:i(1)"!][!//
      &Adc_kKernel2Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC3')"!][!//
,
      /* Pointer to Adc3 configuration */
[!IF "$Adc3Flag = num:i(1)"!][!//
      &Adc_kKernel3Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!// 
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC4')"!][!//
,
      /* Pointer to Adc4 configuration */
[!IF "$Adc4Flag = num:i(1)"!][!//
      &Adc_kKernel4Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC5')"!][!//
,
      /* Pointer to Adc5 configuration */
[!IF "$Adc5Flag = num:i(1)"!][!//
      &Adc_kKernel5Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC6')"!][!//
,
      /* Pointer to Adc6 configuration */
[!IF "$Adc6Flag = num:i(1)"!][!//
      &Adc_kKernel6Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC7')"!][!//
,
      /* Pointer to Adc7 configuration */
[!IF "$Adc7Flag = num:i(1)"!][!//
      &Adc_kKernel7Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//  
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC8')"!][!//
,
      /* Pointer to Adc8 configuration */
[!IF "$Adc8Flag = num:i(1)"!][!//
      &Adc_kKernel8Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC9')"!][!//
,
      /* Pointer to Adc9 configuration */
[!IF "$Adc9Flag = num:i(1)"!][!//
      &Adc_kKernel9Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "contains(ecu:get('Adc.HwUnitId'), 'HWUNIT_ADC10')"!][!//
,
      /* Pointer to Adc10 configuration */
[!IF "$Adc10Flag = num:i(1)"!][!//
      &Adc_kKernel10Config[!"string(($CfgCount)-num:i(1))"!][!//
[!ELSE!][!//
      NULL_PTR[!//  
[!ENDIF!][!//
[!ENDIF!][!//

    },

    /* Pointer to Adc Global configuration value */
    &Adc_kGlobCfg[!"string(($CfgCount)-num:i(1))"!],
  
    /* Module sleep mode control */
    ADC_[!"AdcSleepMode"!]
  }[!//
[!IF "$CfgCount != $TotalAdcConfig"!],[!ENDIF!][!//
[!ENDSELECT!] 
[!ENDFOR!][!//
};/* AdcConfiguration */
[!//
[!ENDSELECT!]


#define ADC_STOP_SEC_POSTBUILDCFG
/*IFX_MISRA_RULE_19_01_STATUS=File inclusion after pre-processor directives is
 allowed only for MemMap.h*/
#include "MemMap.h"


