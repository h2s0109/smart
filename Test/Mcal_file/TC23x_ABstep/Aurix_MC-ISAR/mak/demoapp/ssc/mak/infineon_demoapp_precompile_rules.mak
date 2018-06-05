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
#*  FILENAME  : DemoApp.mak                                                   **
#*                                                                            **
#*  VERSION   : 0.0.7                                                         **
#*                                                                            **
#*  DATE      : 2013.07.26                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build precompile configuration files  **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* SK           Sai Kiran B                                                  **
#* PM           Puneetha Mukherjee                                           **
#* HM           Hamzath Mohammed                                             **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.0.7: 2013.07.26, SK  : added stdlin CD module
#*  V0.0.6: 2012.12.28, SK  : updated cantrcv for aurix
#*  V0.0.5: 2010.11.06, PM  : added Hssl
#*  V0.0.4: 2009.10.20, HM  : add RamTst
#*  V0.0.3: 2009.04.02, HM  : add CanTrcv 6250GV33
#*  V0.0.2: 2009.03.24, HM  : add CanTrcv 6251G
#*  V0.0.1: 2007.09.19, HM  : Initial version.
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_defs.mak

all : check info $(PRECOMPILE_TARGETS)
check:
	@-IF EXIST "$(COMPILER)" (echo ---------------------------- Aurix_MC-ISAR--------------------------) ELSE echo Complier Directory Doesn't exists

flsloader_cfg:
	
fee_cfg:
	@-echo $(FEE_CFG_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/fee_infineon_tricore/$(feepath)/mak/infineon_fee_rules.mak
bfx_cfg:
	echo A1234
	$(GNUMAKE) -f $(SSC_ROOT)/mak/bfx_infineon_tricore/$(bfxpath)/mak/infineon_bfx_rules.mak	
crc_cfg:
	echo Abhi
	$(GNUMAKE) -f $(SSC_ROOT)/mak/crc_infineon_tricore/$(crcpath)/mak/infineon_crc_rules.mak
	
sci_lcfg:
	@-echo $(SCI_LT_CFG_OBJECTS) >> $(LINK_INP_FILE)
cantrcv_17_6251G_cfg:
	@-echo $(CANTRCV_17_6251G_PC_CFG_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6251g_infineon_tricore/$(cantrcv_17_6251gpath)/mak/infineon_cantrcv_17_6251g_rules.mak
cantrcv_17_6250GV33_cfg:
	@-echo $(CANTRCV_17_6250GV33_PC_CFG_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/cantrcv_17_6250gv33_infineon_tricore/$(cantrcv_17_6250gv33path)/mak/infineon_cantrcv_17_6250gv33_rules.mak
stdlin_cfg:
	@-echo $(STDLIN_CFG_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/stdlin_infineon_tricore/$(stdlinpath)/mak/infineon_stdlin_rules.mak
dio_lcfg:
	@-echo $(DIO_LT_CFG_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/dio_infineon_tricore/$(diopath)/mak/infineon_dio_rules.mak

hssl_cfg:
	@-echo $(HSSL_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/hssl_infineon_tricore/$(hsslpath)/mak/infineon_hssl_rules.mak
	
info: 
	@echo -------------Compiling link time configuration files ---------------
