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
#*  FILENAME  : infineon_gtm_check.mak                                       **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2011.03.18                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the GTM module and associates with appropriate folder.**
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
#* VS           Vinod Shankar                                                **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1 : 2011.03.18, VS  : Initial version.
#*
#******************************************************************************/
#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef GTM_DELIVERY_MODE
$(error The Value of GTM_DELIVERY_MODE is not defined in configuration make file) 
endif

ifeq ($(GTM_DELIVERY_MODE),VARIANTPB_SOURCE)
gtmpath = cfg1
endif
 