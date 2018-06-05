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
#*  FILENAME  : infineon_can_17_mcanp_rules.mak                               **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2013.02.25                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines configuration for the CAN module         **
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
#* SGN          Gururaj Nath S                                               ** 
#*                                                                           ** 
#*                                                                           ** 
#*****************************************************************************/ 
#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*
#*  V0.0.2 : 2013.02.25, SGN : Updated for AI00133871
#*  V0.0.1 : 2012.05.10, SGN : Initial version, baselined from Audo
#******************************************************************************/
 
# Specify the type of delivery for CAN module one of the values specified below 
# CAN_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]  
CAN_DELIVERY_MODE = VARIANTPB_SOURCE
# Specify if demo is required [ STD_ON / STD_OFF ]
CAN_DEMO = STD_ON
