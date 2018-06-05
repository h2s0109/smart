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
#*  FILENAME  : infineon_crc_check.mak 			                              **
#*                                                                            **
#*  VERSION   : 0.0.1                                                         **
#*                                                                            **
#*  DATE      : 2011.09.28                                                    **
#*                                                                            **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file checks for correctness of configuration          **
#*                 for the CRC module and associates with appropriate folder. **
#*                 						                                      **
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
#* KP           Kaushal Purohit                                              **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.1: 2011.09.28, KP  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/crc_infineon_tricore/ssc/mak/infineon_crc_cfg.mak 


#***************************** SPECIFIC ****************************************/

ifndef CRC_DELIVERY_MODE
$(error The Value of CRC_DELIVERY_MODE is not defined in configuration make file) 
endif

crcpath = cfg1
 