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
#*  FILENAME  : infineon_icu_17_gtmccu6_cfg.mak                               **
#*                                                                            **
#*  VERSION   : 0.1.1                                                         **
#*                                                                            **
#*  DATE      : 2011.03.18                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines configuration for the ICU module         **
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
#* PR           Pawan Reddy                                                  **
#* SS           Srinivas Shenoy                                              **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.1 : 2013.02.13, SS  : Changes for VendorApiInfix.
#*  V0.1.0 : 2011.03.22, PR  : Initial version.
#*
#******************************************************************************/

#****************************** Specific **************************************/

# Specify the type of delivery for ICU module one of the values specified below
# ICU_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]

ICU_DELIVERY_MODE = VARIANTPB_SOURCE

# Specify if demo is required [ STD_ON / STD_OFF ]
ICU_DEMO = STD_ON
 
