--------------------------------------------------------------------------------
                            FlexTrain 
--------------------------------------------------------------------------------

This is a tool to generate LPDU index to message buffer index mapping. 

The tool generates the mapping information to share message buffers by multiple 
LPDUs, based on LPDU usage configuration information given as input. The input 
is given inside of C comment in Fr_PBCfg.c file. The output is appended in 
Fr_PBCfg.c. Note that the input info is generated based on configuration of 
FrIfFrameTriggering, FrIfLPdu and FrIfJObList in FrIf.

An example input is given below:

/*
@@@@@@START_OF_FLEX-TRAIN_DUMP@@@@@@
NUMBER_OF_PB_CFG 1
MSG_RAM_SIZE_TOTAL 8192
MSG_BUFFER_COUNT_MAX 128

PB_CFG_START
FLEX_TRAIN_RUN_REQUIRED NO 120
KEY_SLOT_LPDU,1,0,4
DYNAMIC_LPDU,2,4,4,5,4
10110,2,1,4,1,4
15115,1,2,4
20120,2,3,4,3,4
PB_CFG_END

@@@@@@END_OF_FLEX-TRAIN_DUMP@@@@@@
*/

The output generated for above input is:

/************************** <FlexTrain-Output-Begin> **************************/

/* LPduIdx to Message buffer mapping for PB config 0 */

#define START_SEC_POSTBUILDCFG
#include "MemMap.h"

const uint8 Fr_LPduIdx2MsgBuff_0[6] = {0, 1, 2, 1, 3, 4};

const uint16 Fr_DataPointerOffset_0[7] = {20, 21, 22, 23, 24, 25, 26};

#define STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

/*************************** <FlexTrain-Output-End> ***************************/


Usage:
-------
Run the following command in DOS prompt. 
FlexTrain <ConfigFile>

Example: FlexTrain c:\MC-ISAR_AudoF\fr_infineon_tricore\cfg1\src\Fr_PBCfg.c

Things to note:
----------------
1. Fr_PBCfg.c should not be a read-only file.

2. If FlexTrain is run with Fr_PBCfg.c that is already processed by FlexTrain,
    the tool does nothing. If your intention to run the tool again is to 
    generate the mapping info for modified input data, then update the input 
    and remove the section marked by <FlexTrain-Output-Begin> and 
    <FlexTrain-Output-End>, and then re-run the tool.

3. The tool is required to be used only if message buffer re-configuration 
    (i.e. when pre-compile parameter FR_RECONFIG_BUFFER is ON).
    
4. Even if FR_RECONFIG_BUFFER is ON, the mapping between LPDUs and message 
    buffers may not be needed becasue there enough number of message buffers 
    to cater to all LPDUs. In this case, the tool does nothing.
    
5. The tool generates mapping information if:
      - there are not enough message buffers (maximum 128) for use by LPDUs 
      - ERAY MessageRAM is not sufficient due to large LSDU lengths 
          (e.g. 50 LPDUs each with LSDU length 254)  

6. The tool returns 0 when run is successful and non-zero value in case of 
    errors. This sets environment variable ERRORLEVEL in DOS. This info can be 
    used in batch file.
          
Limitations:
------------
1. It does not support multiple post-build configurations
2. It supports only sharing of one message buffer by a maximum of 4 LPDUs.
