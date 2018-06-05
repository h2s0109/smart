#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2009)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_flsloader_check.mak                                  **
#*                                                                            **
#*  VERSION   : 1.0.0                                                         **
#*                                                                            **
#*  DATE      : 2009.03.02                                                   **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the flsloader module and associates with appropriate folder .**
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
#* BM           Basheer Mohaideen                                            **
#*                                                                           **
#*****************************************************************************/
#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V1.0.0 : 2009.03.02, BM  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/flsloader_infineon_tricore/ssc/mak/infineon_flsloader_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef FLSLOADER_DELIVERY_MODE
$(error The Value of FLSLOADER_DELIVERY_MODE is not defined in configuration make file) 
endif
 
ifeq ($(FLSLOADER_DELIVERY_MODE),VARIANTPC_SOURCE)
flsloaderpath = cfg1
else
$(error The Value of FLSLOADER_DELIVERY_MODE is not VARIANTPC_SOURCE) 
endif
 