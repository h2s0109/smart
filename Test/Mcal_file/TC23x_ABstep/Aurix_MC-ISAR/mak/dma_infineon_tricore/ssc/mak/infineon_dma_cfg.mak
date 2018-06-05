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
#*  FILENAME  : infineon_dma_cfg.mak                                          **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2013.03.11                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines configuration for the DMA module         **
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
#* AC           Apurav Chandel                                               **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2013.03.11, AC  : Initial version.
#*
#******************************************************************************/
 
# Specify the type of delivery for DMA module one of the values specified below 
# DMA_DELIVERY_MODE = [VARIANTPC_SOURCE/VARIANTPB_SOURCE/VARIANTPB_OBJ]  
DMA_DELIVERY_MODE = VARIANTPB_SOURCE
# Specify if demo is required [ ON / OFF ]  
DMA_DEMO = STD_ON
