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
#*  FILENAME  : infineon_fls_17_pmu_check.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.3                                                         **
#*                                                                            **
#*  DATE      : 2013.02.19                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the FLS module and associates with appropriate folder .**
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
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.3 : 2013.02.19, Vani  : Updated with vendor ApiInfix change
#*  V0.0.2 : 2007.06.19, RS  : Year change to 2007
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/



#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/fls_17_pmu_infineon_tricore/ssc/mak/infineon_fls_17_pmu_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef FLS_DELIVERY_MODE
$(error The Value of FLS_DELIVERY_MODE is not defined in configuration make file) 
endif

ifeq ($(FLS_DELIVERY_MODE),VARIANTPB_SOURCE)
flspath = cfg1
else
$(error The Value of FLS_DELIVERY_MODE is none of the VARIANTPC_SOURCE/VARIANTPB_SOURCE) 
endif
 