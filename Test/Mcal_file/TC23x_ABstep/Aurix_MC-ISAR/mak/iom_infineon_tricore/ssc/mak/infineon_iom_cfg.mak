#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2012)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  FILENAME  : infineon_iom_cfg.mak                                          ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.10.19                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file defines type of delivery for the IOM module      ** 
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
#* HM          hamzath                                                       ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.10.19, HM  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
# Specify the type of delivery for IOM module one of the values specified below 
# IOM_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]  
IOM_DELIVERY_MODE = VARIANTPB_SOURCE
# Specify if demo is required [ ON / OFF ]  
IOM_DEMO = STD_ON
