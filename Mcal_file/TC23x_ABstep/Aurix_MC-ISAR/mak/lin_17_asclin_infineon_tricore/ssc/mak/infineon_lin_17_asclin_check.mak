#******************************************************************************* 
#                                                                             ** 
#* Copyright (C) Infineon Technologies (2008)                                 **
#*                                                                            ** 
#* All rights reserved.                                                       ** 
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       ** 
#* Technologies. Passing on and copying of this document, and communication   ** 
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            ** 
#******************************************************************************* 
#*                                                                            ** 
#*  FILENAME  : infineon_can_check.mak                                          ** 
#*                                                                            ** 
#*  VERSION   : 0.0.2                                                         ** 
#*                                                                            ** 
#*  DATE      : 2013.02.21                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file builds the LIN Driver                       **
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
#*  KP     Kaushal Purohit                                                   **
#* CKP     Chaithanya Kumar Pokala                                           **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.2: 2013.02.21,  KP  : VendorApiInfix changes added
#*  V0.0.1: 2009.01.30, CKP  : Initial version.
#*
#******************************************************************************/
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_cfg.mak 
#***************************** SPECIFIC ****************************************/  
ifndef LIN_DELIVERY_MODE  
$(error The Value of LIN_DELIVERY_MODE is not defined in configuration make file) 
endif  
ifeq ($(LIN_DELIVERY_MODE),VARIANTPB_SOURCE) 
linpath = cfg1
endif  
