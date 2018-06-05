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
**  FILENAME  : ModuleDelivery.bat                                            **
**                                                                            **
**  VERSION   : 1.1.0                                                         **
**                                                                            **
**  DATE      : 2014-09-15                                                    **
**                                                                            **
**  BSW MODULE DECRIPTION : NA                                                **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for ModuleDelivery.bat file                  **
**                                                                            **
**  SPECIFICATION(S) :  NA                                                    **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: No                                       **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.1.0: 2014-09-15,   : Updated for TC22x
 * V1.0.10:2013-10-10,   : Updated for I2C
 * V1.0.9: 2013-09-25,   : Updated for SMU
 * V1.0.8: 2013-06-14,   : Updated for DSADC
 * V1.0.7: 2013-06-14,   : Updated for TC26x
 * V1.0.6: 2013-04-13,   : Updated for Hssl
 * V1.0.5: 2013-01-02,   : Support for CanTrcv
 * V1.0.4: 2012-10-30,   : Support for STM
 * V1.0.3: 2012-10-19,   : Support for SENT
 * V1.0.2: 2012-09-10,   : Support for CCU. AI00066335
 * V1.0.1: 2012-06-18,   : Fix for AI00071821
 * V0.0.1: 2011.03.09,   : Initial version.
*/
*************************************************************************/!][!//
@ECHO OFF
REM ****************************************************************************
REM *                                                                         **
REM * Copyright (C) Infineon Technologies (2013)                              **
REM *                                                                         **
REM * All rights reserved.                                                    **
REM *                                                                         **
REM * This document contains proprietary information belonging to Infineon    **
REM * Technologies. Passing on and copying of this document, and communication**
REM * of its contents is not permitted without prior written authorization.   **
REM *                                                                         **
REM ****************************************************************************
REM *                                                                         **
REM *  FILENAME  : ModuleDelivery.bat                                         **
REM *                                                                         **
REM *  VERSION   : 1.1.0                                                      **
REM *                                                                         **
REM *  DATE,TIME : [!"$date"!], [!"$time"!]                                       **
REM *                                                                         **
REM *  AUTHOR    : DL-AUTOSAR-Engineering                                     **
REM *                                                                         **
REM *  VENDOR    : Infineon Technologies                                      **
REM *                                                                         **
REM *  DESCRIPTION  : This file creates the Demo Modules that are delivered.  **
REM *                                                                         **
REM *  MAY BE CHANGED BY USER [yes/no]: YES                                   **
REM *                                                                         **
REM ***************************************************************************/
[!NOCODE!]
[!VAR "MajorVersion" = "text:split($moduleReleaseVer, '.')[position()-1 = 0]"!][!//

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

[!VAR "CanTrcv6250GV33ModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('CanTrcv_17_6250GV33')[1]"!][!//
[!VAR "CanTrcv6250GV33ModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!VAR "CanTrcv6251GModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('CanTrcv_17_6251G')[1]"!][!//
[!VAR "CanTrcv6251GModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//

[!IF "$MajorVersion = num:i(4)"!][!//
[!VAR "DemModuleUsed" = "'STD_OFF'"!][!//
[!SELECT "as:modconf('Dem')[1]"!][!//
[!VAR "DemModuleUsed" = "'STD_ON'"!][!//
[!ENDSELECT!][!//
[!ELSE!]
[!VAR "DemModuleUsed" = "'STD_ON'"!][!//
[!ENDIF!]

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
SET MCU_DELIVERY=[!"$McuModuleUsed"!]
SET PORT_DELIVERY=[!"$PortModuleUsed"!]
SET DIO_DELIVERY=[!"$DioModuleUsed"!]
SET GPT_DELIVERY=[!"$GptModuleUsed"!]
SET SPI_DELIVERY=[!"$SpiModuleUsed"!]
SET SPI_SLAVE_DELIVERY=[!"$SpiSlaveModuleUsed"!]
SET PWM_DELIVERY=[!"$PwmModuleUsed"!]
SET ADC_DELIVERY=[!"$AdcModuleUsed"!]
SET MLI_DELIVERY=[!"$MliModuleUsed"!]
SET FADC_DELIVERY=[!"$FadcModuleUsed"!]
SET DMA_DELIVERY=[!"$DmaModuleUsed"!]
SET FEE_DELIVERY=[!"$FeeModuleUsed"!]
SET FLS_DELIVERY=[!"$FlsModuleUsed"!]
SET FLSLOADER_DELIVERY=[!"$FlsLoaderModuleUsed"!]
SET HSSL_DELIVERY=[!"$HsslModuleUsed"!]
SET GTM_DELIVERY=[!"$GtmModuleUsed"!]
SET WDG_DELIVERY=[!"$WdgModuleUsed"!]
SET ICU_DELIVERY=[!"$IcuModuleUsed"!]
SET ERU_DELIVERY=[!"$EruModuleUsed"!]
SET CCU_DELIVERY=[!"$CcuModuleUsed"!]
SET CAN_DELIVERY=[!"$CanModuleUsed"!]
SET MSC_DELIVERY=[!"$MscModuleUsed"!]
SET MCHK_DELIVERY=[!"$MchkModuleUsed"!]
SET SCI_DELIVERY=[!"$SciModuleUsed"!]
SET FR_DELIVERY=[!"$FrModuleUsed"!]
SET LIN_DELIVERY=[!"$LinModuleUsed"!]
SET UART_DELIVERY=[!"$UartModuleUsed"!]
SET ETH_DELIVERY=[!"$EthModuleUsed"!]
SET CRC_DELIVERY=[!"$CrcModuleUsed"!]
SET SENT_DELIVERY=[!"$SentModuleUsed"!]
SET IOM_DELIVERY=[!"$IomModuleUsed"!]
SET DEM_DELIVERY=[!"$DemModuleUsed"!]
SET RAMTST_DELIVERY=[!"$RamTstModuleUsed"!]
SET CANTRCV_6250GV33_DELIVERY=[!"$CanTrcv6250GV33ModuleUsed"!]
SET CANTRCV_6251G_DELIVERY=[!"$CanTrcv6251GModuleUsed"!]
SET STM_DELIVERY=STD_OFF
SET STDLIN_DELIVERY=[!"$StdLinModuleUsed"!]
SET DSADC_DELIVERY=[!"$DsadcModuleUsed"!]
SET SMU_DELIVERY=[!"$SmuModuleUsed"!]
IF "%SAFETLIB_USED%" == "STD_ON" SET SMU_DELIVERY=STD_OFF
SET I2C_DELIVERY=[!"$I2cModuleUsed"!]
SET OS_DELIVERY=STD_OFF

:nextpart
[!IF "$derivate = 'TC27Dx'"!]
SET CONTROLLER=TC27Dx
[!ELSEIF "$derivate = 'TC275'"!]
SET CONTROLLER=TC27x
[!ELSEIF "$derivate = 'TC277'"!]
SET CONTROLLER=TC27x
[!ELSEIF "$derivate = 'TC264'"!]
SET CONTROLLER=TC26x
[!ELSEIF "$derivate = 'TC265'"!]
SET CONTROLLER=TC26x
[!ELSEIF "$derivate = 'TC267'"!]
SET CONTROLLER=TC26x
[!ELSEIF "$derivate = 'TC298'"!]
SET CONTROLLER=TC29x
[!ELSEIF "$derivate = 'TC297'"!]
SET CONTROLLER=TC29x
[!ELSEIF "$derivate = 'TC299'"!]
SET CONTROLLER=TC29x
[!ELSEIF "$derivate = 'TC233'"!]
SET CONTROLLER=TC23x
[!ELSEIF "$derivate = 'TC234'"!]
SET CONTROLLER=TC23x
[!ELSEIF "$derivate = 'TC237'"!]
SET CONTROLLER=TC23x
[!ELSEIF "$derivate = 'TC222'"!]
SET CONTROLLER=TC22x
[!ELSEIF "$derivate = 'TC223'"!]
SET CONTROLLER=TC22x
[!ELSEIF "$derivate = 'TC224'"!]
SET CONTROLLER=TC22x
[!ELSEIF "$derivate = 'TC212'"!]
SET CONTROLLER=TC21x
[!ELSEIF "$derivate = 'TC213'"!]
SET CONTROLLER=TC21x
[!ELSEIF "$derivate = 'TC214'"!]
SET CONTROLLER=TC21x
[!ENDIF!]
REM STD_OFF for Variant LT. STD_ON for Variant PB
[!IF "$MajorVersion = num:i(4)"!][!//
SET DIO_TYPE=STD_ON
[!ELSE!][!//
SET DIO_TYPE=STD_OFF
[!ENDIF!][!//

[!IF "$MajorVersion = num:i(4)"!][!//
SET MCAL_AUTOSAR_VERSION=AS40X
[!ELSE!][!//
SET MCAL_AUTOSAR_VERSION=AS32X
[!ENDIF!][!//

