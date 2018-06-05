#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2010)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_fr_17_eray_check.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2010.02.15                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                            of FR module                                    **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: yes                                      **
#*                                                                            **
#******************************************************************************/
#*******************************************************************************
#*                      Author(s) Identity                                    **
#*******************************************************************************
#*                                                                            **
#* Initials     Name                                                          **
#* ---------------------------------------------------------------------------**
#* Prakash      Prakash Gudnavar                                              **
#*                                                                            **
#******************************************************************************/
#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  v0.0.2: 2010-02-15, PrakashG : AI00053231: File/Folder name change 
#*                                    Fr to Fr_17_Eray, fr to fr_17_eray

#*  V0.0.1 : 2009.01.16, Prakash  : Initial Version.
#*
#******************************************************************************/
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/fr_17_eray_infineon_tricore/ssc/mak/infineon_fr_17_eray_cfg.mak 
#***************************** SPECIFIC ****************************************/  
ifndef FR_DELIVERY_MODE  
$(error The Value of FR_DELIVERY_MODE is not defined in configuration make file) 
endif  
ifeq ($(FR_DELIVERY_MODE),VARIANTPB_SOURCE) 
frpath = cfg1
endif  
