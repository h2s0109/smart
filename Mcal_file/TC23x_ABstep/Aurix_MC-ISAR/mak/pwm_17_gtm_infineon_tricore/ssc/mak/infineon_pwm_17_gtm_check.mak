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
#*  FILENAME  : infineon_pwm_check.mak                                        **
#*                                                                            **
#*  VERSION   : 0.0.2                                                         **
#*                                                                            **
#*  DATE      : 2011.09.17                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the PWM module and associates with appropriate folder .**
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
#* AT           Angeswaran Thangaswamy                                       **
#* RS           Roopa Sirur                                                  **
#*                                                                           **
#*****************************************************************************/
#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#* V0.0.2 : 2011.09.17, AT  : Changed for the added vendor id in the module name.
#* V0.0.1 : 2007.02.24, RS  : Initial Version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/pwm_17_gtm_infineon_tricore/ssc/mak/infineon_pwm_17_gtm_cfg.mak 

#***************************** SPECIFIC ****************************************/

ifndef PWM_DELIVERY_MODE
$(error The Value of PWM_DELIVERY_MODE is not defined in configuration make file) 
endif

ifeq ($(PWM_DELIVERY_MODE),VARIANTPB_SOURCE)
pwmpath = cfg1
endif
 