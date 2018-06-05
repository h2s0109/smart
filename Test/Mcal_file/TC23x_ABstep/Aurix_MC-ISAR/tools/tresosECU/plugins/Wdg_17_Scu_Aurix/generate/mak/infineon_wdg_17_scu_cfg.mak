#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2011)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_wdg_17_scu_cfg.mak                                   **
#*                                                                            **
#*  VERSION   : NA                                                            **
#*                                                                            **
#*  DATE      : 2011.03.18                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines configuration for the WDG module         **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      **
#*                                                                            **
#******************************************************************************/


#****************************** Specific **************************************/

# Specify the type of delivery for WDG module one of the values specified below
#WDG_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]

WDG_DELIVERY_MODE = VARIANTPB_SOURCE

# Specify if demo is required [ ON / OFF ]
WDG_DEMO = STD_ON

[!SELECT "as:modconf('Wdg')[1]"!][!//
[!VAR "Wdg_MaxTimers" = "ecu:get('Wdg.MaxTimers')"!]

[!NOCODE!][!//

[!VAR "WDGSAFECOUNT" = "num:i(0)"!][!//

[!IF "WdgSafety/Wdg0SafetyEnable = 'true'"!] [!//
[!VAR "WDGSAFECOUNT" = "($WDGSAFECOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//

[!IF "WdgSafety/Wdg1SafetyEnable = 'true'"!] [!//
[!VAR "WDGSAFECOUNT" = " ($WDGSAFECOUNT) + num:i(1)"!] [!//
[!ENDIF!] [!//

[!IF "$Wdg_MaxTimers > num:i(2)"!][!//
[!IF "WdgSafety/Wdg2SafetyEnable = 'true'"!] [!//
[!VAR "WDGSAFECOUNT" = " ($WDGSAFECOUNT) + num:i(1)"!] [!//
[!ENDIF!][!//
[!ENDIF!][!//

[!IF "$WDGSAFECOUNT  = num:i(0)"!][!//
[!VAR "WdgSafetyUsed" = "'STD_OFF'"!][!//
[!ELSE!][!//
[!VAR "WdgSafetyUsed" = "'STD_ON'"!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//

WDG_SAFETY_USED = [!"$WdgSafetyUsed"!]

[!ENDSELECT!][!//


 
