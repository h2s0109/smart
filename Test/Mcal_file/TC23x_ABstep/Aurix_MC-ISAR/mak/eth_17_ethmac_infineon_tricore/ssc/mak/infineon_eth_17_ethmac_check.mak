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
#*  FILENAME  : infineon_eth_17_check.mak                                     **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2011.09.18                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the ICU module and associates with appropriate folder .**
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
#* PB           P.Balakrishnan                                               **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.0 : 2012.03.02, PB  : Initial version.
#*
#******************************************************************************/

#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/eth_17_ethmac_infineon_tricore/ssc/mak/infineon_eth_17_ethmac_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef ETH_DELIVERY_MODE
$(error The Value of ETH_DELIVERY_MODE is not defined in configuration make file) 
endif

ifeq ($(ETH_DELIVERY_MODE),VARIANTPB_SOURCE)
ethpath = cfg1
endif
 