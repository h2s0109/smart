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
#*  VERSION   : 0.1.2                                                         **
#*                                                                            **
#*  DATE      : 2013.03.15                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build Demo Application           **
#*                                                                            **
#*                                                                            **
#*  MAY BE CHANGED BY USER [yes/no]: no                                       **
#*                                                                            **
#******************************************************************************/

#******************************************************************************
#*                      Author(s) Identity                                   **
#******************************************************************************
#*                                                                           **
#* Initials     Name                                                         **
#* --------------------------------------------------------------------------**
#* AT          Angeswaran Thangaswamy                                        **
#* VS          Vinod Shankar                                                 **
#* HM          Hamzath                                                       **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.2: 2013.03.14, AT  : Hex file generated for loadable configuration
#*                            build
#*  V0.1.1: 2012.09.17, AT  : Adapted to WINDRIVER compiler
#*  V0.1.0: 2012.08.21, AT  : Adapted to GNU compiler
#*  V0.0.9: 2012.03.16, VS  : Adapted to UTP AI00064361
#*  V0.0.8: 2011.03.10, YG  : Adapted to Aurix
#*  V0.0.6: 2009.06.02, HM  : Adapted to AudoS
#*  V0.0.5: 2007.10.09, HM  : Made clean simpler
#*  V0.0.4: 2007.06.19, RS  : Added FEE, FLS
#*  V0.0.3: 2007.04.28, JV  : Changed INT to IRQ
#*  V0.0.2: 2007.02.23, RS  : Initial version.
#*  V0.0.1: 2007.02.23, RS  : Initial version.
#*
#******************************************************************************/

include $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_defs.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_safetlib_defs.mak

PB_TARGETS = 
LINK_ALL_FILES = 

ifeq ($(APP_CONFIG),POSTBUILD_SELECTABLE)
PB_TARGETS = postbuild_files
PB_TARGETS += postbuild_ecum
LINK_ALL_FILES = link_all_files
OBJECTS_LINK_ONLY += $(PBCFG_OBJECTS_LINK_ONLY)
endif

# compiling mcallib,gpt, are optional, more important thing is to include the object files.
ifeq ($(PERL_AVAILABLE),YES)
all : check  generate_dwarf1 mcallib ssc_files demo_files precompile_files $(PB_TARGETS) stdtest irq ecum $(LINK_ALL_FILES) link_step generate_dwarf2 link_step2 link_step3
else
all : check mcallib ssc_files demo_files precompile_files $(PB_TARGETS) stdtest irq ecum $(LINK_ALL_FILES) link_step3
endif
check:
	@-IF EXIST "$(COMPILER)" (echo ---------------------------- Aurix_MC-ISAR --------------------------) ELSE echo Complier Directory Doesn't exists

mcallib : 
	@-echo $(MCALLIB_OBJECTS) > $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/tricore_general/ssc/mak/infineon_mcallib_rules.mak

ssc_files:
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_driver_rules.mak

demo_files:
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_demo_rules.mak

precompile_files:
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_precompile_rules.mak
   
postbuild_files:
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_postbuild_rules.mak

postbuild_ecum:
	@-echo $(ECUM_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/ecum_infineon_tricore/cfg1/mak/infineon_ecum_rules.mak

stdtest:
	@-echo $(STDTEST_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_general_rules.mak
	
irq:
	@-echo $(IRQ_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/irq_infineon_tricore/ssc/mak/infineon_irq_rules.mak
	
ecum:
	@-echo $(ECUM_OBJECTS) >> $(LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_rules.mak

link_all_files:
	@-copy  $(LINK_INP_FILE)+$(PBCFG_LINK_INP_FILE)
   	
link_step : $(ELFDIR)/$(PROJNAME)_tmp.elf

$(ELFDIR)/$(PROJNAME)_tmp.elf : $(OBJECTS_LINK_ONLY) $(APPLN_OBJECTS)
ifeq ($(COMPILER_CHOICE),TASKING)
	@"$(LINKER)"  -f $(LINK_INP_FILE) $(OPT_LKLC_TEMP)  $(ERROR_REPORT)
endif
ifeq ($(COMPILER_CHOICE),GNU)
	@"$(LINKER)"  $(FF_READ)$(LINK_INP_FILE) $(OPT_LKLC_TEMP)  $(ERROR_REPORT)
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
	@"$(LINKER)"  $(TARGET) $(FF_READ)$(LINK_INP_FILE) $(OPT_LKLC_TEMP)  $(ERROR_REPORT_LINK)=$(SSC_ELK_ROOT)/dld.elk $(OUTPUT) $@
endif

generate_dwarf2 :
	@"$(PERL_PATH)/readelf.exe" -wi "$(ELFDIR)/$(PROJNAME)_tmp.elf" > "dwarf_info.txt"
	@$(PERL) "$(PERL_SCRIPT_PATH)/get_functions_dwarf.pl"  "..\src\DemoApp_FctCall.ct" "dwarf_info.txt" 0 >> call_any_fn.txt
	@-rm -f dwarf_info.txt

generate_dwarf1 :
	@$(PERL) "$(PERL_SCRIPT_PATH)/get_functions_dwarf.pl"  "..\src\DemoApp_FctCall.ct" "dwarf_info.txt" 1
	

link_step2 :
	@set DEMO_FCTLIST_GEN=1& $(GNUMAKE) -f $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_demo_rules.mak

link_step3 : $(ELFDIR)/$(PROJNAME).elf

$(ELFDIR)/$(PROJNAME).elf : $(OBJECTS_LINK_ONLY) $(APPLN_OBJECTS)
ifeq ($(COMPILER_CHOICE),TASKING)
	@"$(LINKER)"  -f $(LINK_INP_FILE) $(SAFETLIB_OBJECTS_LINK_ONLY) $(OPT_LKLC)  $(ERROR_REPORT)
endif
ifeq ($(COMPILER_CHOICE),GNU)
	@"$(LINKER)"  $(FF_READ)$(LINK_INP_FILE) $(SAFETLIB_OBJECTS_LINK_ONLY) $(OPT_LKLC)  $(ERROR_REPORT)
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
	@"$(LINKER)"  $(TARGET) $(FF_READ)$(LINK_INP_FILE) $(SAFETLIB_OBJECTS_LINK_ONLY) $(OPT_LKLC)  $(ERROR_REPORT_LINK)=$(SSC_ELK_ROOT)/dld.elk $(OUTPUT) $@
endif
	@-rm -f $(DEMOAPP_INC_PATHS_FILE)
	@-rm -f $(ELFDIR)/$(PROJNAME)_tmp.*

ifneq ($(HEX_GENERATE_COMMAND),NO)	
	@$(HEX_GENERATE_COMMAND)
endif
		
# CLEAN_ALL_OBJECTS has all the objects that can be generated through this make ,
# If you need a rebuild all - clean can be called here.
.PHONY: clean

clean : 
	@-rm -f $(STDTEST_CLEAN_OBJECTS)
	@-rm -f $(APPLN_OBJECTS)
	@-rm -f $(MCALLIB_CLEAN_OBJECTS)
	@-rm -f $(CLEAN_DRIVER_OBJECTS)
	@-rm -f $(CLEAN_DEMO_OBJECTS)
	@-rm -f $(IRQ_CLEAN_OBJECTS)
	@-rm -f $(CLEAN_LT_CFG_OBJECTS)
	
# wipe is a simple utility that will clear the source and error files.
.PHONY: wipe
wipe:
	@-rm -f *.src
	@-rm -f *.err

info:
	@-echo ---------Building DemoApp-----------------


#**************************************************************************************************************************
# Only for configuration data
#**************************************************************************************************************************
loadable_cfg_data: check_load info_load pb_files pb_ecum link_pb
check_load:
	@-IF EXIST "$(COMPILER)" (echo ---------------------------- Aurix_MC-ISAR--------------------------) ELSE echo Complier Directory Doesn't exists

pb_files:
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/demoapp/ssc/mak/infineon_demoapp_postbuild_rules.mak	

pb_ecum:
	@-echo $(ECUM_PB_CFG_OBJECTS) >> $(PBCFG_LINK_INP_FILE)
	@$(GNUMAKE) -f $(SSC_ROOT)/mak/ecum_infineon_tricore/cfg1/mak/infineon_ecum_rules.mak
link_pb : $(ELFDIR)/$(PROJCFGNAME).elf

$(ELFDIR)/$(PROJCFGNAME).elf : $(PBCFG_OBJECTS_LINK_ONLY) 
ifeq ($(COMPILER_CHOICE),TASKING)
	@"$(LINKER)"  -f $(PBCFG_LINK_INP_FILE) $(OPT_LKLC_LOAD)  $(ERROR_REPORT)
endif
ifeq ($(COMPILER_CHOICE),GNU)
	@"$(LINKER)"  $(FF_READ)$(PBCFG_LINK_INP_FILE) $(OPT_LKLC_LOAD)  $(ERROR_REPORT)
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
	@"$(LINKER)"  $(TARGET) $(FF_READ)$(PBCFG_LINK_INP_FILE) $(OPT_LKLC_LOAD)  $(ERROR_REPORT_LINK)=$(SSC_ELK_ROOT)/dld.elk $(OUTPUT) $@
endif

ifneq ($(HEX_GENERATE_COMMAND_CFG),NO)	
	@$(HEX_GENERATE_COMMAND_CFG)
endif
		
info_load:
	@-echo Building configuration data only

clean_loadable_cfg_data:
	@-rm -f $(PBCFG_OBJECTS_LINK_ONLY)
