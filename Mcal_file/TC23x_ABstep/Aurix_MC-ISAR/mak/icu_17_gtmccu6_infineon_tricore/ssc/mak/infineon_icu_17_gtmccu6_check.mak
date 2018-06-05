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
#*  FILENAME  : infineon_icu_17_gtmccu6_check.mak                                     **
#*                                                                            **
#*  VERSION   : 0.0.4                                                         **
#*                                                                            **
#*  DATE      : 2013.02.13                                                    **
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
#* RS          Roopa Sirur                                                   **
#* VS          Vinod Shankar                                                 **
#* SS          Srinivas Shenoy                                               **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*  V0.0.4 : 2013.02.13, SS  : Changes for VendorApiInfix.
#*  V0.0.3 : 2011.09.18, VS  : Adapted to Aurix
#*  V0.0.2 : 2007.09.19, RS  : change year to 2007
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/

#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/icu_17_gtmccu6_infineon_tricore/ssc/mak/infineon_icu_17_gtmccu6_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef ICU_DELIVERY_MODE
$(error The Value of ICU_DELIVERY_MODE is not defined in configuration make file) 
endif

ifeq ($(ICU_DELIVERY_MODE),VARIANTPB_SOURCE)
icupath = cfg1
endif
 