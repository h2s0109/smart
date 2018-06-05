[!/*****************************************************************************
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
**   $FILENAME   : DemoApp_Cfg.h $                                            **
**                                                                            **
**   $CC VERSION : \main\27 $                                                 **
**                                                                            **
**   $DATE       : 2014-03-13 $                                               **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for DemoApp_Cfg.h file                       **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*************************************************************************/!][!//
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
**   $FILENAME   : DemoApp_Cfg.h $                                            **
**                                                                            **
**   $CC VERSION : \main\27 $                                                 **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : DemoApp configuration generated out of ECU configuration   **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : NA                                                     **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: Yes                                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#ifndef  DEMOAPP_CFG_H
#define  DEMOAPP_CFG_H

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/************************* Demo Application Configuration *********************/

#define PRE_COMPILE_DELIVERY           (1U)
#define POST_BUILD_DELIVERY            (2U)
#define LINK_TIME_DELIVERY             (3U) 
/*NOTE: At a time only one type of delivery for a particular module is possible 
and not both the deliveries*/ 
/************************** Basic Driver Modules ******************************/

#define MCU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define PORT_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define DIO_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define GPT_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define SPI_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define PWM_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define ADC_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define MLI_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define FADC_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define DMA_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define FEE_DELIVERY_TYPE              (PRE_COMPILE_DELIVERY)
#define FLS_DELIVERY_TYPE              (PRE_COMPILE_DELIVERY)
#define FLSLOADER_DELIVERY_TYPE        (PRE_COMPILE_DELIVERY)
#define HSSL_DELIVERY_TYPE             (PRE_COMPILE_DELIVERY)
#define STDLIN_DELIVERY_TYPE           (PRE_COMPILE_DELIVERY)
#define CRC_DELIVERY_TYPE         	   (PRE_COMPILE_DELIVERY)
#define GTM_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define WDG_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define ICU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define ERU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define CAN_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define MSC_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define MCHK_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define SCI_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define FR_DELIVERY_TYPE               (POST_BUILD_DELIVERY)
#define LIN_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define UART_DELIVERY_TYPE             (POST_BUILD_DELIVERY)
#define ETH_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define CCU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define SENT_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define IOM_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define CANTRCV_6251G_DELIVERY_TYPE    (PRE_COMPILE_DELIVERY)
#define CANTRCV_6250GV33_DELIVERY_TYPE (PRE_COMPILE_DELIVERY)
#define SMU_DELIVERY_TYPE              (POST_BUILD_DELIVERY)
#define I2C_DELIVERY_TYPE              (POST_BUILD_DELIVERY)

[!NOCODE!]
[!VAR "McuModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "McuModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "PortModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Port')[1]"!][!//
[!VAR "PortModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "DioModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Dio')[1]"!][!//
[!VAR "DioModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "GptModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Gpt')[1]"!][!//
[!VAR "GptModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "SpiModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!VAR "SpiModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "PwmModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Pwm')[1]"!][!//
[!VAR "PwmModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "AdcModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Adc')[1]"!][!//
[!VAR "AdcModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "MliModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Mli')[1]"!][!//
[!VAR "MliModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "FadcModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Fadc')[1]"!][!//
[!VAR "FadcModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "DmaModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Dma')[1]"!][!//
[!VAR "DmaModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "FeeModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Fee')[1]"!][!//
[!VAR "FeeModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "FlsModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Fls')[1]"!][!//
[!VAR "FlsModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "FlsLoaderModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('FlsLoader')[1]"!][!//
[!VAR "FlsLoaderModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "HsslModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Hssl')[1]"!][!//
[!VAR "HsslModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "GtmModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "TotalMcuModuleConfig" = "num:i(count(McuModuleConfiguration/*))"!][!//
[!FOR "ModuleIndex" = "0" TO " ($TotalMcuModuleConfig - 1)"!][!//
[!VAR "McuGtmUsed" = "num:i(count(McuModuleConfiguration/*[@index= $ModuleIndex]/GtmConfiguration/*))"!][!//
[!ENDFOR!][!//
[!IF "$McuGtmUsed >= num:i(1)"!][!//
[!VAR "GtmModuleUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//


[!VAR "SpiSlaveModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Spi')[1]"!][!//
[!IF "SpiSafety/SpiSafetyEnable = 'true'"!][!//
[!IF "./SpiGeneral/SpiSlaveSelectRef != 'SPI_SLAVE_UNUSED'"!][!//
[!VAR "SpiSlaveModuleUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//


[!VAR "WdgModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Wdg')[1]"!][!//
[!VAR "WdgModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "IcuModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Icu')[1]"!][!//
[!VAR "IcuModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "EruModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "TotalMcuModuleConfig" = "num:i(count(McuModuleConfiguration/*))"!][!//
[!FOR "ModuleIndex" = "0" TO " ($TotalMcuModuleConfig - 1)"!][!//
[!VAR "McuEruUsed" = "num:i(count(McuModuleConfiguration/*[@index= $ModuleIndex]/EruConfiguration/*))"!][!//
[!ENDFOR!][!//
[!IF "$McuEruUsed >= num:i(1)"!][!//
[!VAR "EruModuleUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//

[!VAR "CcuModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Mcu')[1]"!][!//
[!VAR "TotalMcuModuleConfig" = "num:i(count(McuModuleConfiguration/*))"!][!//
[!FOR "ModuleIndex" = "0" TO " ($TotalMcuModuleConfig - 1)"!][!//
[!VAR "McuCcuUsed" = "num:i(count(McuModuleConfiguration/*[@index= $ModuleIndex]/CcuConfiguration/*))"!][!//
[!ENDFOR!][!//
[!IF "$McuCcuUsed >= num:i(1)"!][!//
[!VAR "CcuModuleUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//
[!ENDSELECT!][!//


[!VAR "CanModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Can')[1]"!][!//
[!VAR "CanModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "MscModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Msc')[1]"!][!//
[!VAR "MscModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "MchkModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Mchk')[1]"!][!//
[!VAR "MchkModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "SciModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Sci')[1]"!][!//
[!VAR "SciModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "FrModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Fr')[1]"!][!//
[!VAR "FrModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "LinModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Lin')[1]"!][!//
[!VAR "LinModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "UartModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Uart')[1]"!][!//
[!VAR "UartModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//
[!VAR "EthModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Eth')[1]"!][!//
[!VAR "EthModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "CrcModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Crc')[1]"!][!//
[!VAR "CrcModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "RamTstModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('RamTst')[1]"!][!//
[!VAR "RamTstModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "SentModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Sent')[1]"!][!//
[!VAR "SentModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "IomModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Iom')[1]"!][!//
[!VAR "IomModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "CanTrcv6251GModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('CanTrcv_17_6251G')[1]"!][!//
[!VAR "CanTrcv6251GModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "CanTrcv6250GV33ModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('CanTrcv_17_6250GV33')[1]"!][!//
[!VAR "CanTrcv6250GV33ModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "StdLinModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('StdLin')[1]"!][!//
[!VAR "StdLinModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "DsadcModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Dsadc')[1]"!][!//
[!VAR "DsadcModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "SmuModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Smu')[1]"!][!//
[!VAR "SmuModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "I2cModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('I2c')[1]"!][!//
[!VAR "I2cModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//


[!ENDNOCODE!]

#define MCU_DELIVERY                   ([!"$McuModuleUsed"!])
#define PORT_DELIVERY                  ([!"$PortModuleUsed"!])
#define DIO_DELIVERY                   ([!"$DioModuleUsed"!])
#define GTM_DELIVERY                   ([!"$GtmModuleUsed"!])
#define GPT_DELIVERY                   ([!"$GptModuleUsed"!])
#define SPI_DELIVERY                   ([!"$SpiModuleUsed"!])
#define SPI_SLAVE_DELIVERY             ([!"$SpiSlaveModuleUsed"!])
#define PWM_DELIVERY                   ([!"$PwmModuleUsed"!])
#define ADC_DELIVERY                   ([!"$AdcModuleUsed"!])
#define MLI_DELIVERY                   ([!"$MliModuleUsed"!])
#define FADC_DELIVERY                  ([!"$FadcModuleUsed"!])
#define DMA_DELIVERY                   ([!"$DmaModuleUsed"!])
/* Note that the FLS Delivery must be ON if FEE is ON */
#define FEE_DELIVERY                   ([!"$FeeModuleUsed"!])
#define FLS_DELIVERY                   ([!"$FlsModuleUsed"!])
#define FLSLOADER_DELIVERY             ([!"$FlsLoaderModuleUsed"!])
#define HSSL_DELIVERY                  ([!"$HsslModuleUsed"!])
#define WDG_DELIVERY                   ([!"$WdgModuleUsed"!])
#define ICU_DELIVERY                   ([!"$IcuModuleUsed"!])
#define ERU_DELIVERY                   ([!"$EruModuleUsed"!])
#define CAN_DELIVERY                   ([!"$CanModuleUsed"!])
#define MSC_DELIVERY                   ([!"$MscModuleUsed"!])
#define MCHK_DELIVERY                  ([!"$MchkModuleUsed"!])
#define SCI_DELIVERY                   ([!"$SciModuleUsed"!])
#define FR_DELIVERY                    ([!"$FrModuleUsed"!])
#define ETH_DELIVERY                   ([!"$EthModuleUsed"!])
#define CRC_DELIVERY                   ([!"$CrcModuleUsed"!])
#define LIN_DELIVERY                   ([!"$LinModuleUsed"!])
#define UART_DELIVERY                  ([!"$UartModuleUsed"!])
#define RAMTST_DELIVERY                ([!"$RamTstModuleUsed"!])
#define CCU_DELIVERY                   ([!"$CcuModuleUsed"!])
#define SENT_DELIVERY                  ([!"$SentModuleUsed"!])
#define IOM_DELIVERY                   ([!"$IomModuleUsed"!])
#define STM_DELIVERY                   (STD_OFF)
#define CANTRCV_6251G_DELIVERY         ([!"$CanTrcv6251GModuleUsed"!])
#define CANTRCV_6250GV33_DELIVERY      ([!"$CanTrcv6250GV33ModuleUsed"!])
#define STDLIN_DELIVERY                ([!"$StdLinModuleUsed"!])
#define DSADC_DELIVERY                   ([!"$DsadcModuleUsed"!])
#define SMU_DELIVERY                   ([!"$SmuModuleUsed"!])
#define I2C_DELIVERY                   ([!"$I2cModuleUsed"!])
#define OS_DELIVERY                   (STD_OFF)

#endif /* DEMOAPP_CFG_H */
