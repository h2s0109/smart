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
#*  FILENAME  : infineon_dma_check.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.1                                                         ** 
#*                                                                            ** 
#*  DATE      : 2013.03.11                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This file checks for correctness of configuration          ** 
#*                            of DMA module                                   ** 
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
#* AC         Apurav Chandel                                                 ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.1 : 2013.03.11, AC  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/dma_infineon_tricore/ssc/mak/infineon_dma_cfg.mak 
#***************************** SPECIFIC ****************************************/  
ifndef DMA_DELIVERY_MODE  
$(error The Value of DMA_DELIVERY_MODE is not defined in configuration make file) 
endif  
ifeq ($(DMA_DELIVERY_MODE),VARIANTPB_SOURCE) 
dmapath = cfg1
endif  
