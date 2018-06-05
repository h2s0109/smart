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
**  $FILENAME   : Dma_Cfg.h $                                                **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  $DATE       : 2016-03-22 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                Code template for Dma_Cfg.h file                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/!][!//
[!//
/******************************************************************************
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
**  FILENAME  : Dma_Cfg.h                                                    **
**                                                                           **
**  $CC VERSION : \main\17 $                                                 **
**                                                                           **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                     **
**                                                                           **
**  GENERATOR : Build [!"$buildnr"!]                                         **
**                                                                           **
**  AUTHOR    : DL-AUTOSAR-Engineering                                       **
**                                                                           **
**  VENDOR    : Infineon Technologies                                        **
**                                                                           **
**  DESCRIPTION  : DMA configuration generated out of ECU configuration      **
**                 file (Dma.bmd/.xdm)                                       **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
**                                                                           **
    TRACEBILITY :[cover parentID = DS_NAS_DMA_PR446,
    SAS_NAS_DMA_PR914,SAS_NAS_DMA_PR915,SAS_NAS_DMA_PR916,SAS_NAS_DMA_PR60,
    SAS_NAS_DMA_PR64,SAS_NAS_DMA_PR82,DS_NAS_HE2_DMA_PR3054_1,
    DS_NAS_EP_DMA_PR3054_1,DS_NAS_HE2_DMA_PR3054_2,DS_NAS_EP_DMA_PR3054_2,
    DS_NAS_HE2_DMA_PR3054_3,DS_NAS_EP_DMA_PR3054_3,DS_NAS_HE2_DMA_PR3054_4
    DS_NAS_EP_DMA_PR3054_4][/cover]                                          **
**                                                                           **
******************************************************************************/

#ifndef DMA_CFG_H 
#define DMA_CFG_H 

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Dma')[1]"!][!//
[!//
[!VAR "SwMajorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 0]"!][!//
[!VAR "SwMinorVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 1]"!][!//
[!VAR "SwRevisionVersion" = "text:split($moduleSoftwareVer, '.')[position()-1 = 2]"!][!//

#define DMA_MODULE_INSTANCE             ((uint8)[!"DmaGeneralConfiguration/DmaIndex"!]U)

/*SW Version Information*/
#define DMA_SW_MAJOR_VERSION            ([!"$SwMajorVersion"!]U)
#define DMA_SW_MINOR_VERSION            ([!"$SwMinorVersion"!]U)
#define DMA_SW_PATCH_VERSION            ([!"$SwRevisionVersion"!]U)

/*Number of DMA channels present in the controller*/
#define DMA_NUM_OF_CHANNELS             ([!"ecu:get('Dma.NoOfChannels')"!]U)

/* Total Number of DMA Config Sets */
#define DMA_CONFIG_COUNT               ([!"num:i(count(DmaConfigSet/*))"!]U)

/* Derived Configuration for DmaDevErrorDetect */
#define DMA_DEV_ERROR_DETECT            ([!//
[!IF "DmaGeneralConfiguration/DmaDevErrorDetect = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/*
Configuration: Dma_RUNNING_IN_USER_0_MODE_ENABLE 
- if STD_ON, enable User0 mode 
- if STD_OFF, enable User1 mode 
*/
[!IF "node:exists(./DmaGeneralConfiguration/DmaRunningInUser0Mode)"!][!//
  [!IF "DmaGeneralConfiguration/DmaRunningInUser0Mode = 'true'"!][!//
  [!ASSERT "not((./DmaGeneralConfiguration/DmaUserModeInitApiEnable != 'true') and (./DmaGeneralConfiguration/DmaUserModeDeInitApiEnable != 'true') and (./DmaGeneralConfiguration/DmaUserModeRuntimeApiEnable != 'true'))"!][!//
Config Error: when DmaGeneralConfiguration/DmaRunningInUser0Mode is set as true, [!//
Then atleast any one of the switches: DmaUserModeInitApiEnable or [!//
DmaUserModeDeInitApiEnable or DmaUserModeRuntimeApiEnable should be selected.[!//
But in configuration none are selected.[!//
  [!ENDASSERT!][!//
#define DMA_RUNNING_IN_USER_0_MODE_ENABLE    (STD_ON)
  [!ELSE!][!//
#define DMA_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define DMA_RUNNING_IN_USER_0_MODE_ENABLE    (STD_OFF)
[!ENDIF!][!//

/*
Configuration: Dma_USER_MODE_INIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in Init API 
- if STD_OFF, Enable Supervisor mode in Init API  
*/
[!IF "node:exists(./DmaGeneralConfiguration/DmaUserModeInitApiEnable)"!][!//
  [!IF "DmaGeneralConfiguration/DmaUserModeInitApiEnable = 'true'"!][!// 
#define DMA_USER_MODE_INIT_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define DMA_USER_MODE_INIT_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define DMA_USER_MODE_INIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//
/*
Configuration: Dma_USER_MODE_DEINIT_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in DeInit API 
- if STD_OFF, Enable Supervisor mode in DeInit API 
*/
[!IF "node:exists(./DmaGeneralConfiguration/DmaUserModeDeInitApiEnable)"!][!//
  [!IF "DmaGeneralConfiguration/DmaUserModeDeInitApiEnable = 'true'"!][!// 
#define DMA_USER_MODE_DEINIT_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define DMA_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define DMA_USER_MODE_DEINIT_API_ENABLE    (STD_OFF)
[!ENDIF!][!//
/*
Configuration: Dma_MODE_RUNTIME_API_ENABLE
- if STD_ON, Enable Protected Mode(user mode) in APIs other than Init/Deinit APIs
- if STD_OFF, Enable Supervisor mode in APIs other than Init/Deinit APIs
*/
[!IF "node:exists(./DmaGeneralConfiguration/DmaUserModeRuntimeApiEnable)"!][!//
  [!IF "DmaGeneralConfiguration/DmaUserModeRuntimeApiEnable = 'true'"!][!//    
#define DMA_USER_MODE_RUNTIME_API_ENABLE    (STD_ON)
  [!ELSE!][!//
#define DMA_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
  [!ENDIF!][!//
[!ELSE!][!//
#define DMA_USER_MODE_RUNTIME_API_ENABLE    (STD_OFF)
[!ENDIF!][!//
/* Derived Configuration for DmaVersionInfoApi */
#define DMA_VERSION_INFO_API            ([!//
[!IF "DmaGeneralConfiguration/DmaVersionInfoApi = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for DmaDoubleBufferEnable */
#define DMA_DOUBLE_BUFFER_ENABLE      ([!//
[!IF "DmaGeneralConfiguration/DmaDoubleBufferEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for DmaDeInitApi */
#define DMA_DEINIT_API                  ([!//
[!IF "DmaGeneralConfiguration/DmaDeInitApi  = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration for DmaLinkedListEnable*/
#define DMA_LINKED_LIST_ENABLE          ([!//
[!IF "DmaGeneralConfiguration/DmaLinkedListEnable = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration DmaDebugSupport*/
#define DMA_DEBUG_SUPPORT               ([!//
[!IF "DmaGeneralConfiguration/DmaDebugSupport = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)

/* Derived Configuration DmaResetSfrAtInit */
#define DMA_RESET_SFR_INIT              ([!//
[!IF "DmaGeneralConfiguration/DmaResetSfrAtInit = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


[!NOCODE!][!//
[!//
[!VAR "TotalDmaConfig" = "num:i(count(DmaConfigSet/*))"!][!//
[!/* Determine only one DmaConfigSet is configured 
                                        when DmaPBFixedAddress = true.*/!]
[!IF "DmaGeneralConfiguration/DmaPBFixedAddress = 'true'"!][!//
[!//
  [!ASSERT "not($TotalDmaConfig != 1)"!][!//
Config Error: when DmaGeneralConfiguration/DmaPBFixedAddress is set as true, [!//
Only one DmaConfigSet configuration is allowed. [!//
But DmaConfigSet has more than one configuration.[!//
  [!ENDASSERT!][!//
[!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

/* Derived Configuration DmaPBFixedAddress*/
#define DMA_PB_FIXEDADDR                ([!//
[!IF "DmaGeneralConfiguration/DmaPBFixedAddress = 'true'"!][!//
STD_ON[!//
[!ELSE!][!//
STD_OFF[!//
[!ENDIF!][!//
)


[!ENDSELECT!][!//

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
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/

#endif  /*End of DMA_CFG_H */


