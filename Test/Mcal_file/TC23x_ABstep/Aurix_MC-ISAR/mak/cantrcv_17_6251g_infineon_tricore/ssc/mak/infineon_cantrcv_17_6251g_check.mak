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
#*  FILENAME  : infineon_cantrcv_17_6251g_check.mak                           ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2012.12.28                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file checks for correctness of configuration   ** 
#*                            of CANTRCV_17_6251G module                      ** 
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
#* SK           SaiKiran B                                                   ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2012.12.28, SK  : Initial Version.
#*
#******************************************************************************/ 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/ssc/mak/infineon_cantrcv_17_6251g_cfg.mak 
#***************************** SPECIFIC ****************************************/  
ifndef CANTRCV_17_6251G_DELIVERY_MODE  
$(error The Value of CANTRCV_17_6251G_DELIVERY_MODE is not defined in configuration make file) 
endif  
ifeq ($(CANTRCV_17_6251G_DELIVERY_MODE),VARIANTPC_SOURCE) 
cantrcv_17_6251gpath = cfg1
endif  
