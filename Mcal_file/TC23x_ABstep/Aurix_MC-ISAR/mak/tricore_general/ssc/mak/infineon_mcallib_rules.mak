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
#*  FILENAME  : infineon_mcallib_rules.mak                                    **
#*                                                                            **
#*  VERSION   : 0.1.0                                                         **
#*                                                                            **
#*  DATE      : 2013.07.17                                                    **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This make file is used to build the MCAL driver            **
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
#* SK           Sai Kiran                                                    **
#* AT           Angeswaran Thangaswamy                                       **
#* RS           Roopa Sirur                                                  **
#* BM           Basheer Mohaideen                                            **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#*
#*  V0.1.0: 2013.07.17, AT  : Wdtcon.c compilation removed
#*  V0.0.9: 2013.06.20, AT  : GPT,GTM and WDG are included only if module 
#*                            delivery is STD_ON
#*  V0.0.8: 2013.02.27, SK  : Mcal Library Split
#*  V0.0.7: 2013.02.26, AT  : DIO, GPT and WDG included for MultiCore Demo
#*  V0.0.6: 2012.11.15, AT  : ADC and SPI defs mak files included
#*  V0.0.5: 2012.09.17, AT  : Updated for WINDRIVER compiler
#*  V0.0.4: 2012.08.22, AT  : Updated for GNU compiler
#*  V0.0.3: 2008.02.07, BM  : Added Mcal_Lib object suffix is added
#*  V0.0.2: 2007.09.23, RS  : Change year to 2007, ECUM include path added
#*  V0.0.1: 2007.02.23, RS  : Initial version.
#*
#******************************************************************************/

#***************************** REQUIRE ****************************************/

include $(SSC_ROOT)/mak/autosar.mak
include $(SSC_ROOT)/mak/base_make.mak
include $(SSC_ROOT)/mak/general/compiler/compiler.mak
include $(SSC_ROOT)/mak/tricore_general/ssc/mak/infineon_mcallib_defs.mak
include $(SSC_ROOT)/mak/ecum_infineon_tricore/ssc/mak/infineon_ecum_defs.mak
include $(SSC_ROOT)/mak/irq_infineon_tricore/ssc/mak/infineon_irq_defs.mak
include $(SSC_ROOT)/mak/integration_general/mak/infineon_integration_safetlib_defs.mak
ifeq ($(GPT_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/gpt_infineon_tricore/ssc/mak/infineon_gpt_defs.mak
endif
ifeq ($(GTM_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
endif
include $(SSC_ROOT)/mak/dio_infineon_tricore/ssc/mak/infineon_dio_defs.mak
ifeq ($(WDG_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/wdg_17_scu_infineon_tricore/ssc/mak/infineon_wdg_17_scu_defs.mak
endif
#***************************** SPECIFIC ****************************************/
MCAL_INC_PATHS_FILE = mcal_include_paths.ifx
MCAL_INCLUDE_MODS = 
ifeq ($(SPI_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/spi_infineon_tricore/ssc/mak/infineon_spi_defs.mak
MCAL_INCLUDE_MODS += $(SPI_DEP_HEADERS)
endif
ifeq ($(ADC_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak
MCAL_INCLUDE_MODS += $(ADC_DEP_HEADERS)
endif
ifeq ($(LIN_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/lin_17_AscLin_infineon_tricore/ssc/mak/infineon_lin_17_AscLin_defs.mak
MCAL_INCLUDE_MODS += $(LIN_DEP_HEADERS)
endif
ifeq ($(UART_DELIVERY),STD_ON)
include $(SSC_ROOT)/mak/uart_infineon_tricore/ssc/mak/infineon_uart_defs.mak
MCAL_INCLUDE_MODS += $(UART_DEP_HEADERS)
endif

build_mcallib_driver : info mcalincpath $(MCALLIB_OBJECTS)
	
$(MCALLIB_BASE_PATH)/ssc/obj/Mcal.$(OBJ_FILE_SUFFIX) : $(MCALLIB_BASE_PATH)/ssc/src/Mcal.c $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(ECUM_BASE_PATH)/ssc/inc/EcuM.h $(ECUM_BASE_PATH)/cfg1/inc/EcuM_Cfg.h $(MCAL_INCLUDE_MODS)
	@"$(COMPILER)" $(ERROR_REPORT)  $(OUTPUT) $@ $(STD_OPT_CC) $(SAFETLIB_INTEGRATION) $(FF_READ)$(MCAL_INC_PATHS_FILE) $(OBJ_CREATION)  $< 
	
$(MCALLIB_BASE_PATH)/ssc/obj/Mcal_TcLib.$(OBJ_FILE_SUFFIX) : $(MCALLIB_BASE_PATH)/ssc/src/Mcal_TcLib.c $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(ECUM_BASE_PATH)/ssc/inc/EcuM.h $(ECUM_BASE_PATH)/cfg1/inc/EcuM_Cfg.h
	@$(COMPILE_MCALLIB) $(ERROR_REPORT)  $(OUTPUT) $@ $(STD_OPT_CC) $(FF_READ)$(MCAL_INC_PATHS_FILE) $(OBJ_CREATION)  $<  

$(MCALLIB_BASE_PATH)/ssc/obj/Mcal_WdgLib.$(OBJ_FILE_SUFFIX) : $(MCALLIB_BASE_PATH)/ssc/src/Mcal_WdgLib.c $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(ECUM_BASE_PATH)/ssc/inc/EcuM.h $(ECUM_BASE_PATH)/cfg1/inc/EcuM_Cfg.h
	@$(COMPILE_MCALLIB) $(ERROR_REPORT)  $(OUTPUT) $@ $(STD_OPT_CC) $(FF_READ)$(MCAL_INC_PATHS_FILE) $(OBJ_CREATION)  $<  

$(MCALLIB_BASE_PATH)/ssc/obj/Mcal_DmaLib.$(OBJ_FILE_SUFFIX) : $(MCALLIB_BASE_PATH)/ssc/src/Mcal_DmaLib.c $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(ECUM_BASE_PATH)/ssc/inc/EcuM.h $(ECUM_BASE_PATH)/cfg1/inc/EcuM_Cfg.h
	@$(COMPILE_MCALLIB) $(ERROR_REPORT)  $(OUTPUT) $@ $(STD_OPT_CC) $(FF_READ)$(MCAL_INC_PATHS_FILE) $(OBJ_CREATION)  $<  

	
	@-rm -f $*.ers
 
.PHONY: wipe
wipe:
	@-rm -f *.err       
	@-rm -f *.src

mcalincpath:
	@echo $(STANDARD_INCLUDE) > $(MCAL_INC_PATHS_FILE)
	@echo $(ECUM_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
	@echo $(IRQ_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)

ifeq ($(SPI_DELIVERY),STD_ON)
	@-echo $(SPI_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif

ifeq ($(ADC_DELIVERY),STD_ON)
	@-echo $(ADC_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif

ifeq ($(LIN_DELIVERY),STD_ON)
	@-echo $(LIN_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif
ifeq ($(UART_DELIVERY),STD_ON)
	@-echo $(UART_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif
ifeq ($(GPT_DELIVERY),STD_ON)
	@-echo $(GPT_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
	@-echo $(GTM_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
	@-echo $(GPT_DEMO_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif
ifeq ($(DIO_DELIVERY),STD_ON)
	@-echo $(DIO_DEMO_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif
ifeq ($(WDG_DELIVERY),STD_ON)
	@-echo $(WDG_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
	@-echo $(WDG_DEMO_INCLUDE_PATH) >> $(MCAL_INC_PATHS_FILE)
endif

info: 
	@echo -------------Compiling MCAL Library ---------------
	

           
