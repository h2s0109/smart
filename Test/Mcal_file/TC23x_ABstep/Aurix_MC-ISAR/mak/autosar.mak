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
#*  FILENAME  : autosar.mak                                                   **
#*                                                                            **
#*  VERSION   : 1.0.0                                                         **
#*                                                                            **
#*  DATE      : 2016.06.28                                                    **
#*                                                                            **
#*  AUTHOR    : DL-AUTOSAR-Engineering                                        **
#*                                                                            **
#*  VENDOR    : Infineon Technologies                                         **
#*                                                                            **
#*  DESCRIPTION  : This file defines global variables                         ** 
#*                 used accross the modules                                   **
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
#* AT           Angeswaran Thangaswamy                                       **
#* RS           Roopa Sirur                                                  **
#* Prakash      Prakash Gudnavar                                             **
#*                                                                           **
#*****************************************************************************/


#*******************************************************************************
#*                      Revision Control History                              **
#******************************************************************************/
#* 
#* V1.0.0: 2016.06.28, AT  : Windriver compiler 5.9.4.8 path updated
#* V0.0.6: 2013.07.17, AT  : gnu compiler 4.6.3.0 path updated
#* V0.0.5: 2013.03.04, AT  : reverted back to tasking 4.1r1 path
#* V0.0.4: 2013.02.26, AT  : updated tasking 4.1r2 path
#* V0.0.3: 2012.08.21, AT  : updated for Hitech compiler
#* V0.0.2: 2008.01.07, Prakash : 
#*            - Added variables for code coverage tool usage
#*            
#* V0.0.1: 2007.02.23, RS  : Initial version.
#*
#******************************************************************************/


# Compiler installation directory path should be set by the user here.
ifeq ($(COMPILER_CHOICE),TASKING)
ifeq ($(COMPILER_TASKING_VER),V4)
COMPILER_PATH = c:\Program Files\TASKING\TriCore v4.2r2\ctc
endif
ifeq ($(COMPILER_TASKING_VER),V5)
COMPILER_PATH = c:\Program Files\TASKING\TriCore v5.0r2\ctc
endif
endif
ifeq ($(COMPILER_CHOICE),GNU)
COMPILER_PATH = C:\HIGHTEC\toolchains\tricore\v4.6.3.0
endif
ifeq ($(COMPILER_CHOICE),WINDRIVER)
COMPILER_PATH = C:\WindRiver\diab\5.9.4.8
endif
CODE_COV_PATH = c:\Program Files\Testwell\CTC

# shortcut variable for refering the different files present inside the general folder (Std_Types.h, Complier.h etc) 
STDINC  = $(SSC_ROOT)/general
