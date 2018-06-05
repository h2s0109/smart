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
#*  FILENAME  : infineon_fls_17_pmu_cfg.mak                                   **
#*                                                                            **
#*  VERSION   : 0.1.2                                                         **
#*                                                                            **
#*  DATE      : 2013.02.19                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines configuration for the FLS module         **
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
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.2 : 2013.02.19, Vani : Vendor ID Infix change - Fls_17 to Fls_17_Pmu
#*  V0.1.1 : 2011.09.19, Ravi : Vendor ID change - Fls to Fls_17
#*  V0.1.0 : 2011.03.22, PR  : Initial version.
#*
#******************************************************************************/

#****************************** Specific **************************************/

# Specify the type of delivery for FLS module one of the values specified below
# FLS_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]

FLS_DELIVERY_MODE = VARIANTPB_SOURCE
 
# Specify if demo is required [ ON / OFF ]
FLS_DEMO = STD_ON
