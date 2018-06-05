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
#*  FILENAME  : infineon_adc_rules.mak                                        ** 
#*                                                                            ** 
#*  VERSION   : 0.0.6                                                         ** 
#*                                                                            ** 
#*  DATE      : 2014.01.22                                                    **  
#*                                                                            ** 
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        ** 
#*                                                                            ** 
#*  VENDOR    : Infineon Technologies                                         ** 
#*                                                                            ** 
#*  DESCRIPTION  : This make file builds the ADC Driver                       ** 
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
#* AD          Abhishek Dwivedi                                              ** 
#* AT          Angeswaran Thangaswamy                                        ** 
#* RS          Roopa Sirur                                                   ** 
#*                                                                           ** 
#*****************************************************************************/ 
#******************************************************************************* 
#*                      Revision Control History                              ** 
#******************************************************************************/ 
#*  V0.0.6 : 2014-01-22, AT  : Added Adc_HwHandle.c and Adc_Calibration.c     
#*                                           for compilation                  
#*  V0.0.5 : 2013.07.31, AT  : Added new files for compilation.
#*  V0.0.4 : 2012.10.25, AD  : Module specific compile variable introduced
#*  V0.0.3 : 2012.09.17, AT  : Updated for WINDRIVER compiler.
#*  V0.0.2 : 2012.08.21, AT  : Updated for GNU compiler.
#*  V0.0.1 : 2007.10.09, RS  : Initial Version.
#*
#******************************************************************************/ 
 
 
 
 
#***************************** REQUIRE ****************************************/ 
include $(SSC_ROOT)/mak/autosar.mak 
include $(SSC_ROOT)/mak/base_make.mak 
include $(COMPILER_MAKE_PATH)/compiler.mak 
include $(SSC_ROOT)/mak/mcu_infineon_tricore/ssc/mak/infineon_gtm_defs.mak
include $(SSC_ROOT)/mak/adc_infineon_tricore/ssc/mak/infineon_adc_defs.mak 
#***************************** SPECIFIC ****************************************/  
headers = $(STANDARD_DEPENDANCY) $(ADC_DEP_HEADERS) 
ADC_INC_PATHS_FILE = adc_include_paths.ifx 
 
 
build_adc_driver : info adcincpaths $(ADC_SSC_OBJECTS) 
$(ADC_BASE_PATH)/ssc/obj/Adc.$(OBJ_FILE_SUFFIX) : $(ADC_BASE_PATH)/ssc/src/Adc.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_ADC)  $(OUTPUT) $(ADC_BASE_PATH)/ssc/obj/Adc.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ADC_BASE_PATH)\ssc\src\Adc.c  $(ERROR_REPORT) 
	@-rm -f $(ADC_BASE_PATH)/ssc/obj/Adc.ers 

$(ADC_BASE_PATH)/ssc/obj/Adc_ConvHandle.$(OBJ_FILE_SUFFIX) : $(ADC_BASE_PATH)/ssc/src/Adc_ConvHandle.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_ADC)  $(OUTPUT) $(ADC_BASE_PATH)/ssc/obj/Adc_ConvHandle.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ADC_BASE_PATH)\ssc\src\Adc_ConvHandle.c  $(ERROR_REPORT) 
	@-rm -f $(ADC_BASE_PATH)/ssc/obj/Adc_ConvHandle.ers 
 
$(ADC_BASE_PATH)/ssc/obj/Adc_HwHandle.$(OBJ_FILE_SUFFIX) : $(ADC_BASE_PATH)/ssc/src/Adc_HwHandle.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_ADC)  $(OUTPUT) $(ADC_BASE_PATH)/ssc/obj/Adc_HwHandle.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ADC_BASE_PATH)\ssc\src\Adc_HwHandle.c  $(ERROR_REPORT) 
	@-rm -f $(ADC_BASE_PATH)/ssc/obj/Adc_HwHandle.ers 
 
$(ADC_BASE_PATH)/ssc/obj/Adc_Ver.$(OBJ_FILE_SUFFIX) : $(ADC_BASE_PATH)/ssc/src/Adc_Ver.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_ADC)  $(OUTPUT) $(ADC_BASE_PATH)/ssc/obj/Adc_Ver.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ADC_BASE_PATH)\ssc\src\Adc_Ver.c  $(ERROR_REPORT) 
	@-rm -f $(ADC_BASE_PATH)/ssc/obj/Adc_Ver.ers 
 
$(ADC_BASE_PATH)/ssc/obj/Adc_Calibration.$(OBJ_FILE_SUFFIX) : $(ADC_BASE_PATH)/ssc/src/Adc_Calibration.c $(headers) $(MCALLIB_BASE_PATH)/ssc/inc/Mcal.h $(OS_FILE_PATH)/Os.h $(DET_FILE_PATH)/Det.h 
	@$(COMPILE_ADC)  $(OUTPUT) $(ADC_BASE_PATH)/ssc/obj/Adc_Calibration.$(OBJ_FILE_SUFFIX) $(STD_OPT_CC) $(FF_READ)$(ADC_INC_PATHS_FILE)  $(OBJ_CREATION)  $(ADC_BASE_PATH)\ssc\src\Adc_Calibration.c  $(ERROR_REPORT) 
	@-rm -f $(ADC_BASE_PATH)/ssc/obj/Adc_Calibration.ers 
 
print: 
	@echo $(ADC_SSC_OBJECTS) 
adcincpaths: 
	@echo $(STANDARD_INCLUDE) > $(ADC_INC_PATHS_FILE)
	@echo $(GTM_INCLUDE_PATH) >> $(ADC_INC_PATHS_FILE)       
	@echo $(ADC_INCLUDE_PATH) >> $(ADC_INC_PATHS_FILE) 
info:  
	@echo -------------Compiling ADC Module--------------- 
