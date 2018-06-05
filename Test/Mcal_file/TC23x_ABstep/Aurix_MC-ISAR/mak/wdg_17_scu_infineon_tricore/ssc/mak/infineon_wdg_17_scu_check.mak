#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2007)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : infineon_wdg_17_Scu_check.mak                                 **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2007.09.19                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the WDG module and associates with appropriate folder .**
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
#*  V0.0.2 : 2007.09.19, RS  : Change year to 2007
#*  V0.0.1 : 2007.06.19, RS  : Initial Version.
#*
#******************************************************************************/

#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef WDG_DELIVERY_MODE
$(error The Value of WDG_DELIVERY_MODE is not defined in configuration make file) 
endif

ifeq ($(WDG_DELIVERY_MODE),VARIANTPB_SOURCE)
wdgpath = cfg1
endif
 