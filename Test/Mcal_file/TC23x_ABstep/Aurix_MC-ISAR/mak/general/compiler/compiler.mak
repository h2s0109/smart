#*******************************************************************************
#                                                                             **
#* Copyright (C) Infineon Technologies (2014)                                 **
#*                                                                            **
#* All rights reserved.                                                       **
#*                                                                            **
#* This document contains proprietary information belonging to Infineon       **
#* Technologies. Passing on and copying of this document, and communication   **
#* of its contents is not permitted without prior written authorization.      **
#*                                                                            **
#*******************************************************************************
#*                                                                            **
#*  FILENAME  : compiler.mak                                                  **
#*                                                                            **
#*  VERSION   : 1.0.0                                                         **
#*                                                                            **
#*  DATE      : 2015.03.30                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines variables used during compilation        **
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
#* SK          Sai Kiran B                                                   **
#* VS          Vinod Shankar                                                 **
#* YG          Yogesh Gondalia                                               **
#* HM          Hamzath Mohammed                                              **
#* PG          Prakash Gudnavar                                              **
#* VM          Venkatesh Maddera                                             **
#* AD          Abhishek Dwivedi                                              **
#* AK          Ashish Kumar                                                  **
#* BT          Tejaswini Basavarajaiah                                       **
#* MK          Mundhra Karan                                                 **
#* RK          Rutuja Kawathekar                                             **
#* AJ          Abdul Jaffar                                                  **
#* JN          Jayaprakash Narayana                                          **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#* V1.0.0:  2015.03.30, AT  : Updated for TC27xDB step support
#* V0.3.1:  2015.01.13, AT  : Updated Tasking and GNU compiler options for UTPs
#*                            AI00253254, AI00254354, AI00254543, AI00254544
#* V0.3.0:  2014.09.15, AT  : Updated the TC22x compiler and Linker options
#* V0.2.12: 2013.02.21, AK  : Updated the TC23x compiler and Linker options
#* V0.2.11: 2013.10.10, JN  : Support for I2C module
#* V0.2.10: 2013.09.24, AJ  : Support for DSADC module
#* V0.2.9:  2013.09.24, RK  : Support for SMU module
#* V0.2.8:  2013.09.17, AT  : Updated theTasking compiler option O2RO for UTP AI00229535
#* V0.2.7:  2013.07.17, AT  : Updated the Gnu compiler options - c90
#* V0.2.6:  2013.06.18, AT  : Updated the TC26x and TC29x compiler and Linker options
#* V0.2.5:  2013.06.13, AT  : Updated the TC26x and TC29x SFR path
#* V0.2.4:  2013.04.04, BT  : minor compiler error corrected
#* V0.2.3:  2013.04.04, MK  : Updated DIAB compiler options for memeory section
#*                              split
#* V0.2.2:  2013.03.14, AT  : Hex file generated for loadable configuration
#*                            build
#* V0.2.1:  2013.03.08, AT  : Tasking compiler option changed to --iso=90 for
#*                            UTP: AI00157752
#* V0.2.0:  2013.02.28, SK  : Updated the Sfr path to B-Step
#* V0.1.7:  2013.02.26, AT  : Updated the compiler options for MultiCore
#* V0.1.6:  2013.01.07, MK  : Removed Compiler option for removing unused functions
#* V0.1.5:  2012.11.19, AT  : Updated the compiler options for GNU
#* V0.1.4:  2012.11.08, BT  : Added support for IOM
#* V0.1.3:  2012.10.31, AK  : Support for SENT module
#* V0.1.2:  2012.10.25, AD  : Module specific compile variable
#* V0.1.1:  2012.09.17, AT  : Updated for WINDRIVER compiler
#* V0.1.0:  2012.08.22, AT  : Updated for GNU compiler
#* V0.0.13: 2012.04.04, SK  : Adapted to Tasking 4.0r1 compiler & removed unsupported controllers
#* V0.0.12: 2012.03.16, VS  : Adapted to UTP AI00064361
#* V0.0.11: 2011.03.11, YG  : Modified For AURIX controllers - Removed AudoS/M/F
#* V0.0.10: 2010.07.29, VM  : AI00056132: The optimization issue for FLS is handled
#*                            at function level, the tradeoff value changed to 4.
#* V0.0.9:  2010.07.29, VM  : The instruction FCALL was generated for Thebe with tradeoff=4
#*                            (to optimise for size due to which FCALL was generated
#*                            in sequential code) so tradeoff=1.
#*  V0.0.8: 2010.06.30, VM  : Adapt to Thebe
#*  V0.0.7: 2009.06.02, HM  : Adapt to Audo S
#*  V0.0.6: 2009.05.18, HM  : Removed HEX option for tc1767 compilation

# V0.0.5: 2008.01.23, Prakash   :
#         - Changed location of MON.sym generation to coverage report directory
#
# V0.0.4: 2008.01.07, Prakash   :
#         - Added variables for code coverage tool usage
#
# V0.0.3: 2007.12.05, Prakash   :
#         - Changed forward slashes in compiler path to backward slashes
#            to make it usable with ctc++ tool.
#
#*  V0.0.2: 2007.09.19, HM  : Added the linker option for the loadable &
#*                              Selectable concept
#*  V0.0.1: 2007.02.23, RS  : Initial version for header file
#*
#******************************************************************************/

# Base path of the project directory that we are building i.e. DemoApp or Test Application
ifeq ($(DELIVERY_WITH_TEST),0)
PROJDIR = $(SSC_ROOT)/$(MODULE)
else
ifeq ($(DELIVERY_WITH_TEST),1)
PROJDIR = $(TEST_ROOT)\$(MODULE)
endif
endif

ifeq ($(PERL_AVAILABLE),YES)
CALLFUNCTION = -DCALL_BY_FUNCTION_AVAILABLE
else
CALLFUNCTION =
endif

# Variables for the path of different folders in the project i.e. DemoApp or Test Application
# TODO:
# Change to backslashes to forward slashes once the CTC++ issue is resolved
ifeq ($(COMPILER_CHOICE),TASKING)
OUTDIR  = $(PROJDIR)\obj
endif
ifeq ($(COMPILER_CHOICE),GNU)
OUTDIR  = $(PROJDIR)/obj
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
OUTDIR  = $(PROJDIR)/obj
endif
PROJINC = $(PROJDIR)\inc
PROJSRC = $(PROJDIR)\src

# Variables containig the reference compiler installation folder
PRODDIR = $(COMPILER_PATH)
PROTECTED = p/tc1766

# Variable for GNU Make executable
GNUMAKE = $(GNU_MAKE_PATH)/gnumake.exe

# Variable for Compiler executable
# TODO:
# Following if else block should be restored to
# COMPILER = $(COMPILER_PATH)\bin\cctc.exe
# once the code coverage tool takes space in the path
ifeq ($(CODE_COVERAGE),0)
ifeq ($(COMPILER_CHOICE),TASKING)
COMPILER = $(COMPILER_PATH)\bin\cctc.exe
endif
ifeq ($(COMPILER_CHOICE),GNU)
COMPILER = $(COMPILER_PATH)\bin\tricore-gcc.exe
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
COMPILER = $(COMPILER_PATH)\WIN32\bin\dcc.exe
endif
else
ifeq ($(CODE_COVERAGE),1)
COMPILER = cctc
endif
endif

ifeq ($(COMPILER_CHOICE),TASKING)
LINKER = $(COMPILER_PATH)\bin\ltc.exe
endif
ifeq ($(COMPILER_CHOICE),GNU)
LINKER = $(COMPILER_PATH)\bin\tricore-gcc.exe
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
LINKER = $(COMPILER_PATH)\WIN32\bin\dld.exe
endif

# Variables for code coverage tool command and its options
CODE_COV_CMD = $(CODE_COV_PATH)\ctc.exe
CODE_COV_OPT_GENERAL = -i fd -v -k
CODE_COV_OPT_INI = -c $(TEST_ROOT)\ctc\ctc.ini;$(TEST_ROOT)\ctc\ctc_Aurix_tasking.ini;$(PROJDIR)\bin\ctc_$(MODULE).ini
CODE_COV_OPT_LIB1 = -C LIBRARY=$(TEST_ROOT)\ctc\binaries\targdata.o
CODE_COV_OPT_LIB2 = -C LIBRARY+$(TEST_ROOT)\ctc\binaries\targsend.o
CODE_COV_OPT_LIB3 = -C LIBRARY+$(TEST_ROOT)\ctc\binaries\targcust.o
CODE_COV_OPT_SYM = -n $(TEST_ROOT)\..\..\..\04_Test\07_CodeCoverage\$(MODULE_REPORT_DIR)\MON.sym

ifeq ($(CODE_COVERAGE),0)
COMPILE_WITH_CODECOV = "$(COMPILER)"
LINK_WITH_CODECOV = "$(COMPILER)"
COMPILE_WITH_CODECOV_GLOB =
else
ifeq ($(CODE_COVERAGE),1)
COMPILE_WITH_CODECOV_GLOB = "$(CODE_COV_CMD)" $(CODE_COV_OPT_GENERAL) $(CODE_COV_OPT_INI)
COMPILE_WITH_CODECOV = "$(CODE_COV_CMD)" $(CODE_COV_OPT_GENERAL) $(CODE_COV_OPT_INI) $(CODE_COV_OPT_SYM) "$(COMPILER)"
LINK_WITH_CODECOV = "$(CODE_COV_CMD)" $(CODE_COV_OPT_INI) $(CODE_COV_OPT_LIB1) $(CODE_COV_OPT_LIB2) $(CODE_COV_OPT_LIB3) "$(COMPILER)"
endif
endif

#Following are compiler options used in Tasking

# The suffix of the object file is o
OBJ_FILE_SUFFIX = o


# To create an object file Tasking expects -t -c
ifeq ($(COMPILER_CHOICE),TASKING)
OBJ_CREATION = -t -c
endif
ifeq ($(COMPILER_CHOICE),GNU)
OBJ_CREATION = -c
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
OBJ_CREATION = -c
endif

# the following option forces compiler to report the errors in a text file
ifeq ($(COMPILER_CHOICE),TASKING)
ERROR_REPORT = --error-file
endif
ifeq ($(COMPILER_CHOICE),GNU)
ERROR_REPORT =
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
#ECHO TRACE_COMPILE_ERR > $(SSC_ELK_ROOT)/dcc.err

ERROR_REPORT_LINK=-@E
ERROR_REPORT=-@E+$(SSC_ELK_ROOT)/dcc.err
endif

# The following option tells the compiler to place the output in required place
OUTPUT = -o

# The following option tells the compiler to search the headers in respective paths
CC_INC = -I

# The following option tells the compiler to take the file has input to compiler
ifeq ($(COMPILER_CHOICE),TASKING)
FF_READ = -f
endif
ifeq ($(COMPILER_CHOICE),GNU)
FF_READ = @
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
FF_READ=-@
TARGET=-tTC16PMG:simple
endif

# The following Tasking options to compile with ISO C90 or ISO C99 option
ifeq ($(COMPILER_CHOICE),TASKING)
ifeq ($(C_STANDARD),C90)
ISO_OPTION = --iso=90
endif
ifeq ($(C_STANDARD),C99)
ISO_OPTION = --iso=99
endif
endif

# The following GNU options to compile with ISO C90 or ISO C99 option
ifeq ($(COMPILER_CHOICE),GNU)
ifeq ($(C_STANDARD),C90)
ISO_OPTION = -std=iso9899:1990
endif
ifeq ($(C_STANDARD),C99)
ISO_OPTION = -std=iso9899:1999
endif
endif

# The following WINDRIVER options to compile with ISO C90 or ISO C99 option
ifeq ($(COMPILER_CHOICE),WINDRIVER)
ISO_OPTION = -Xdialect-c89
endif

# The following GNU options to define Triboard number
ifeq ($(COMPILER_CHOICE),GNU)
ifeq ($(CONTROLLER),TC29x)
TRIBOARD_DEFINE = -DTRIBOARD_TC29XX
endif
ifeq ($(CONTROLLER),TC27x)
TRIBOARD_DEFINE = -DTRIBOARD_TC27XX
endif
ifeq ($(CONTROLLER),TC26x)
TRIBOARD_DEFINE = -DTRIBOARD_TC26XX
endif
ifeq ($(CONTROLLER),TC23x)
TRIBOARD_DEFINE = -DTRIBOARD_TC23XX
endif
ifeq ($(CONTROLLER),TC22x)
TRIBOARD_DEFINE = -DTRIBOARD_TC22XX
endif
ifeq ($(CONTROLLER),TC21x)
TRIBOARD_DEFINE = -DTRIBOARD_TC21XX
endif
endif


# The following option is generally used in all compilations

ifeq ($(COMPILER_CHOICE),TASKING)
ifeq ($(COMPILER_TASKING_VER),V4)
STD_OPT_CC  = $(STANDARD_INCLUDE) --core=tc1.6.x -t -Wa-gAHLs --emit-locals=-equ,-symbols -Wa-Ogs -Wa--error-limit=42 $(ISO_OPTION) --eabi-compliant --integer-enumeration --language=-comments,-gcc,+volatile,-strings --switch=auto --align=0 --default-near-size=0 --default-a0-size=0 --default-a1-size=0 -O2ROPYG --tradeoff=4 -g --source -D_TASKING_C_TRICORE_=1 $(CALLFUNCTION) -I"$(PRODDIR)/include"
endif
ifeq ($(COMPILER_TASKING_VER),V5)
STD_OPT_CC  = $(STANDARD_INCLUDE) --core=tc1.6.x -t -Wa-gAHLs --emit-locals=-equ,-symbols -Wa-Ogs -Wa--error-limit=42 $(ISO_OPTION) --eabi-compliant --integer-enumeration --language=-comments,-gcc,+volatile,-strings --switch=auto --align=0 --default-near-size=0 --default-a0-size=0 --default-a1-size=0 -O2ROPFG --tradeoff=4 -g --source -D_TASKING_C_TRICORE_=1 $(CALLFUNCTION) -I"$(PRODDIR)/include"
endif
endif
ifeq ($(COMPILER_CHOICE),GNU)
STD_OPT_CC  = $(STANDARD_INCLUDE) -save-temps=obj $(ISO_OPTION) -ansi -fno-asm -ffreestanding -Wundef -Wp,$(ISO_OPTION) -fno-short-enums -fpeel-loops -falign-functions=4 -frecord-gcc-switches -fsection-anchors -funsigned-bitfields -ffunction-sections -fno-ivopts -fno-peephole2 -nostartfiles -O3 -g3 -W -Wall -Wuninitialized $(TRIBOARD_DEFINE) -mtc161 -D_GNU_C_TRICORE_=1 $(CALLFUNCTION) -I "$(PRODDIR)/tricore/include/machine"
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
STD_OPT_CC  = $(TARGET) $(STANDARD_INCLUDE) $(ISO_OPTION) -Xno-common -Xalign-functions=4 -Xfp-fast -Xsection-split=1 -Xkeep-assembly-file=2 -g3 -ew4084 -ei4177,4550,4549,4068,5388 -XO -D_DIABDATA_C_TRICORE_=1 $(CALLFUNCTION) -I"$(PRODDIR)\include\diab" -I"$(PRODDIR)\libraries\src\common\embsys"
endif

#The ELF Directory where ELF will be created based on the project i.e. DemoApp or Test Application
ifeq ($(DELIVERY_WITH_TEST),0)
ELFDIR = $(SSC_ROOT)/$(MODULE)/out
endif
ifeq ($(DELIVERY_WITH_TEST),1)
ELFDIR = $(TEST_ROOT)/$(MODULE)/out
endif

# Compiler Specific Public definitions ends

# standard include variable for include path required for the compilation for general files ( Ex: Std_Types.h,Compiler.h)
# Include directory for DET, DEM and OS removed from STANDARD INCLUDE as all file are pointing to same path
# and integration general files ( DET, DEM, OS files)
STANDARD_INCLUDE  = -I "$(STDINC)/inc" -I "$(STDINC)/tricore/inc"
ifeq ($(CONTROLLER),TC26x)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC26x"
endif
ifeq ($(CONTROLLER),TC27x)
ifeq ($(DEVICE_STEP),TC27xBC)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC27xB"
endif
ifeq ($(DEVICE_STEP),TC27xCA)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC27xC"
endif
ifeq ($(DEVICE_STEP),TC27xDB)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC27xD"
endif
ifeq ($(DEVICE_STEP),TC27xDC)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC27xD"
endif
endif
ifeq ($(CONTROLLER),TC29x)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC29x"
endif
ifeq ($(CONTROLLER),TC23x)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC23x"
endif
ifeq ($(CONTROLLER),TC22x)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC22x"
endif
ifeq ($(CONTROLLER),TC21x)
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc/TC21x"
endif
STANDARD_INCLUDE += -I "$(STDINC)/tricore/inc"
STANDARD_INCLUDE += -I "$(STDINC)/tricore/compiler" -I "$(SSC_ROOT)/tricore_general/ssc/inc"
STANDARD_INCLUDE += -I "$(STDTEST_BASE_PATH)/inc"
STANDARD_INCLUDE += -I "$(SSC_ROOT)/DemoApp/tricore/compiler"
STANDARD_INCLUDE += -I "$(SSC_ROOT)/DemoApp/inc"
ifeq ($(COMPILER_CHOICE),GNU)
STANDARD_INCLUDE += -I "$(PRODDIR)/tricore/libos.src"
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
STANDARD_INCLUDE += -I "$(PRODDIR)\include\diab"
endif

# standard dependency variable for general files ( Ex: Std_Types.h,Compiler.h)
STANDARD_DEPENDANCY  = $(STDINC)/inc/Std_Types.h
ifeq ($(COMPILER_CHOICE),GNU)
STANDARD_DEPENDANCY += $(PRODDIR)/tricore/include/machine/intrinsics.h
endif
STANDARD_DEPENDANCY += $(STDINC)/tricore/inc/Platform_Types.h
STANDARD_DEPENDANCY += $(STDINC)/tricore/compiler/Compiler.h $(STDINC)/tricore/compiler/Compiler_Cfg.h
STANDARD_DEPENDANCY += $(SSC_ROOT)/DemoApp/tricore/compiler/MemMap.h

# The Linker option to definf the used CPU
ifeq ($(COMPILER_CHOICE),TASKING)

CPU_USED = userdef16x
OPT_CPU_CORE = -Cmpe:vtc
ifeq ($(CONTROLLER),TC29x)
CPU_USED = tc29x
endif
ifeq ($(CONTROLLER),TC27x)
CPU_USED = tc27x
endif
ifeq ($(CONTROLLER),TC26x)
CPU_USED = tc26x
endif
ifeq ($(CONTROLLER),TC23x)
CPU_USED = userdef16x_tc0
OPT_CPU_CORE = -Cmpe:tc0
endif
ifeq ($(CONTROLLER),TC22x)
CPU_USED = userdef16x_tc0
OPT_CPU_CORE = -Cmpe:tc0
endif
ifeq ($(CONTROLLER),TC21x)
CPU_USED = userdef16x_tc0
OPT_CPU_CORE = -Cmpe:tc0
endif


LTC_OPTIMIZATION = -Otxycl
ifeq ($(LTC_OPTM_ENABLED),NO)
LTC_OPTIMIZATION = -OTXYCL
endif

endif

# This is the Linker option
ifeq ($(COMPILER_CHOICE),TASKING)
OPT_LKLC = -o "$(ELFDIR)/$(PROJNAME).elf" -o "$(ELFDIR)/$(PROJNAME).hex":IHEX --hex-format=s -t -d_mcal_pjt.lsl -D__CPU__=$(CPU_USED) $(OPT_CPU_CORE) $(LTC_OPTIMIZATION) --error-limit=42 -M -mcrfiklsmnoduq -L"$(PRODDIR)/lib/tc16x"  -lc -lfp -lrt
OPT_LKLC_TEMP = -o "$(ELFDIR)/$(PROJNAME)_tmp.elf" -t -d_mcal_pjt.lsl -D__CPU__=$(CPU_USED) $(OPT_CPU_CORE) --error-limit=42 -M -mcrfiklsmnoduq -L"$(PRODDIR)/lib/tc16x"  -lc -lfp -lrt
OPT_LKLC_LOAD = -o "$(ELFDIR)/$(PROJCFGNAME).elf" -o "$(ELFDIR)/$(PROJCFGNAME).hex":IHEX --hex-format=s -t -d_mcal_cfg.lsl -D__CPU__=$(CPU_USED) $(OPT_CPU_CORE) --error-limit=42 -M -mcrfiklsmnoduq -L"$(PRODDIR)/lib/tc16x"  -lc -lfp -lrt
endif
ifeq ($(COMPILER_CHOICE),GNU)
OPT_LKLC = -o "$(ELFDIR)/$(PROJNAME).elf" -T"$(BATCH_PATH)\_mcal_pjt.ld" -Wl,-Map="$(ELFDIR)/$(PROJNAME).map" -nostartfiles -Wl,--allow-multiple-definition -Wl,--cref -Wl,--oformat=elf32-tricore -Wl,--mcpu=tc161 -Wl,--mem-holes -Wl,--extmap="a" -L"$(PRODDIR)/tricore/include"
OPT_LKLC_TEMP = -o "$(ELFDIR)/$(PROJNAME)_tmp.elf" -T"$(BATCH_PATH)\_mcal_pjt.ld" -Wl,-Map="$(ELFDIR)/$(PROJNAME).map" -nostartfiles -Wl,--cref -Wl,--mcpu=tc161 -Wl,--mem-holes -Wl,--extmap="a" -L"$(PRODDIR)/tricore/include"
OPT_LKLC_LOAD = -o "$(ELFDIR)/$(PROJCFGNAME).elf" -T"$(BATCH_PATH)\_mcal_cfg.ld" -Wl,-Map="$(ELFDIR)/$(PROJCFGNAME).map" -nostartfiles -Wl,--cref -Wl,--mcpu=tc161 -Wl,--mem-holes -Wl,--extmap="a" -L"$(PRODDIR)/tricore/include"
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
OPT_LKLC = -o "$(ELFDIR)/$(PROJNAME).elf" -m6 "$(BATCH_PATH)\_mcal_pjt.dld" -@O="$(ELFDIR)/$(PROJNAME).map" -lc
OPT_LKLC_TEMP = -o "$(ELFDIR)/$(PROJNAME)_tmp.elf" -m6 "$(BATCH_PATH)\_mcal_pjt.dld" -@O="$(ELFDIR)/$(PROJNAME).map" -lc
OPT_LKLC_LOAD = -o "$(ELFDIR)/$(PROJCFGNAME).elf" -m6 "$(BATCH_PATH)\_mcal_cfg.dld" -@O="$(ELFDIR)/$(PROJCFGNAME).map" -lc
endif


ifeq ($(COMPILER_CHOICE),TASKING)
HEX_GENERATE_COMMAND = NO
HEX_GENERATE_COMMAND_CFG = NO
endif
ifeq ($(COMPILER_CHOICE),GNU)
HEX_GENERATE_COMMAND = $(COMPILER_PATH)\bin\tricore-objcopy.exe -O ihex "$(ELFDIR)/$(PROJNAME).elf" "$(ELFDIR)/$(PROJNAME).hex"
HEX_GENERATE_COMMAND_CFG = $(COMPILER_PATH)\bin\tricore-objcopy.exe -O ihex "$(ELFDIR)/$(PROJCFGNAME).elf" "$(ELFDIR)/$(PROJCFGNAME).hex"
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
HEX_GENERATE_COMMAND = $(COMPILER_PATH)\WIN32\bin\ddump.exe -R "$(ELFDIR)/$(PROJNAME).elf" -X -o "$(ELFDIR)/$(PROJNAME).hex"
HEX_GENERATE_COMMAND_CFG = $(COMPILER_PATH)\WIN32\bin\ddump.exe -R "$(ELFDIR)/$(PROJCFGNAME).elf" -X -o "$(ELFDIR)/$(PROJCFGNAME).hex"
endif


#**************************MODULE SPECIFIC COMPILE VARIABLE**********************/
COMPILE_ADC = "$(COMPILER)"
COMPILE_BFX = "$(COMPILER)"
COMPILE_CAN = "$(COMPILER)"
COMPILE_CANTRCV_17_6250GV33 = "$(COMPILER)"
COMPILE_CANTRCV_17_6251G = "$(COMPILER)"
COMPILE_CRC = "$(COMPILER)"
COMPILE_DIO = "$(COMPILER)"
COMPILE_ETH = "$(COMPILER)"
COMPILE_FEE = "$(COMPILER)"
COMPILE_FLS = "$(COMPILER)"
COMPILE_FLSLOADER = "$(COMPILER)"
COMPILE_FR = "$(COMPILER)"
COMPILE_GPT = "$(COMPILER)"
COMPILE_GTM = "$(COMPILER)"
COMPILE_ICU = "$(COMPILER)"
COMPILE_LIN = "$(COMPILER)"
COMPILE_MCALLIB = "$(COMPILER)"
COMPILE_MCU = "$(COMPILER)"
COMPILE_MSC = "$(COMPILER)"
COMPILE_PORT = "$(COMPILER)"
COMPILE_PWM = "$(COMPILER)"
COMPILE_SPI = "$(COMPILER)"
COMPILE_UART = "$(COMPILER)"
COMPILE_WDG = "$(COMPILER)"
COMPILE_SENT = "$(COMPILER)"
COMPILE_IOM = "$(COMPILER)"
COMPILE_STM = "$(COMPILER)"
COMPILE_DMA = "$(COMPILER)"
COMPILE_STDLIN = "$(COMPILER)"
COMPILE_SMU = "$(COMPILER)"
COMPILE_DSADC = "$(COMPILER)"
COMPILE_I2C = "$(COMPILER)"
