[!/*
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2012)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**   $FILENAME   : Smu.m $                                                    **
**                                                                            **
**   $CC VERSION : \main\5 $                                                  **
**                                                                            **
**   $DATE       : 2014-03-17 $                                               **
**                                                                            **
**  BSW MODULE DECRIPTION : Smu.bmd/xdm                                       **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Configuration Generator Macros                             **
**                                                                            **
**  SPECIFICATION(S) :                                                        **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** BK           Basavaraj Kotayya                                                  **
** CS           Chaitra Shanthpur                                              **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V0.0.1:  2012-11-17, BK,CS :Initial Version of Aurix SMU
*/
*/!]
/******************************************************************************/
[!/* *** multiple inclusion protection*** */!][!//
[!IF "not(var:defined('Smu_M'))"!][!//
[!VAR "Smu_M"="'true'"!][!//


/*******************************************************************************
** Name             : CG_FSP_Value                                           **
**                                                                            **
** Description      : Macro to retrieve the value in OutMac_FSP variable     **
**                    based on the MacInputVal value                          **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_FSP_Value", "MacInputVal" = ""!][!//
[!//
[!IF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_2'"!][!//
[!VAR "OutMac_FSP" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_4'"!][!//
[!VAR "OutMac_FSP" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_8'"!][!//
[!VAR "OutMac_FSP" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_16'"!][!//
[!VAR "OutMac_FSP" = "num:i(3)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_32'"!][!//
[!VAR "OutMac_FSP" = "num:i(4)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_64'"!][!//
[!VAR "OutMac_FSP" = "num:i(5)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_128'"!][!//
[!VAR "OutMac_FSP" = "num:i(6)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_256'"!][!//
[!VAR "OutMac_FSP" = "num:i(7)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_512'"!][!//
[!VAR "OutMac_FSP" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_1024'"!][!//
[!VAR "OutMac_FSP" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_2048'"!][!//
[!VAR "OutMac_FSP" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_REF_CLK_FRQ_DIV_4096'"!][!//
[!VAR "OutMac_FSP" = "num:i(3)"!]
[!ELSEIF "$MacInputVal = 'SMU_FSP_BISTABLE_PROTOCOL'"!][!//
[!VAR "OutMac_FSP" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_FSP_TIME_SWITCHING_PROTOCOL'"!][!//
[!VAR "OutMac_FSP" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_FSP_PES_DISABLE'"!][!//
[!VAR "OutMac_FSP" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_FSP_PES_ENABLE'"!][!//
[!VAR "OutMac_FSP" = "num:i(1)"!]
[!ELSE!][!//
[!ERROR"Config Error: Wrong SMU_FSP."!]
[!ENDIF!]
[!ENDMACRO!]

/*******************************************************************************
** Name             : CG_AG_Value                                           **
**                                                                            **
** Description      : Macro to retrieve the value in OutMac_AG variable     **
**                    based on the MacInputVal value                          **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_AGC_Value", "MacInputVal" = ""!][!//
[!//
[!IF "$MacInputVal = 'SMU_SELECT_INT_NONE'"!][!//
[!VAR "OutMac_AGC" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT0'"!][!//
[!VAR "OutMac_AGC" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT1'"!][!//
[!VAR "OutMac_AGC" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT2'"!][!//
[!VAR "OutMac_AGC" = "num:i(4)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT0_INT1'"!][!//
[!VAR "OutMac_AGC" = "num:i(3)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT0_INT2'"!][!//
[!VAR "OutMac_AGC" = "num:i(5)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT1_INT2'"!][!//
[!VAR "OutMac_AGC" = "num:i(6)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_INT0_INT1_INT2'"!][!//
[!VAR "OutMac_AGC" = "num:i(7)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_NONE'"!][!//
[!VAR "OutMac_AGC" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU0'"!][!//
[!VAR "OutMac_AGC" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU1'"!][!//
[!VAR "OutMac_AGC" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU2'"!][!//
[!VAR "OutMac_AGC" = "num:i(4)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU0_CPU1'"!][!//
[!VAR "OutMac_AGC" = "num:i(3)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU0_CPU2'"!][!//
[!VAR "OutMac_AGC" = "num:i(5)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU1_CPU2'"!][!//
[!VAR "OutMac_AGC" = "num:i(6)"!]
[!ELSEIF "$MacInputVal = 'SMU_SELECT_IDLE_CPU0_CPU1_CPU2'"!][!//
[!VAR "OutMac_AGC" = "num:i(7)"!]
[!ELSEIF "$MacInputVal = 'true'"!][!//
[!VAR "OutMac_AGC" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'false'"!][!//
[!VAR "OutMac_AGC" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_EFRST_DISABLE'"!][!//
[!VAR "OutMac_AGC" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_EFRST_ENABLE'"!][!//
[!VAR "OutMac_AGC" = "num:i(1)"!]
[!ELSE!][!//
[!ERROR"Config Error: Wrong SMU_AGC Select."!]
[!ENDIF!]
[!ENDMACRO!]


/*******************************************************************************
** Name             : CG_AlmCfg_Value                                           **
**                                                                            **
** Description      : Macro to retrieve the value in OutMac_AlmCfg variable     **
**                    based on the MacInputVal value                          **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_AlmCfg_Value", "MacInputVal" = ""!][!//
[!//
[!IF "$MacInputVal = 'SMU_NA_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_IGCS0_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_IGCS1_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(3)"!]
[!ELSEIF "$MacInputVal = 'SMU_IGCS2_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(4)"!]
[!ELSEIF "$MacInputVal = 'SMU_NMI_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(5)"!]
[!ELSEIF "$MacInputVal = 'SMU_RESET_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(6)"!]
[!ELSEIF "$MacInputVal = 'SMU_IDLE_INT_ACTION'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(7)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_FSP_DISABLED'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_FSP_ENABLED'"!][!//
[!VAR "OutMac_AlmCfg" = "num:i(1)"!]
[!ELSE!][!//
[!ERROR"Config Error: Wrong SMU_AlmCfg Select."!]
[!ENDIF!]
[!ENDMACRO!]


/*******************************************************************************
** Name             : CG_RTACfg_Value                                           **
**                                                                            **
** Description      : Macro to retrieve the value in OutMac_RTACCfg variable     **
**                    based on the MacInputVal value                          **
**                                                                            **
*******************************************************************************/
[!MACRO "CG_RTACfg_Value", "MacInputVal" = ""!][!//
[!//
[!IF "$MacInputVal = 'SMU_ALARM_GROUP0'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(0)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_GROUP1'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(1)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_GROUP2'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(2)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_GROUP3'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(3)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_GROUP4'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(4)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_GROUP5'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(5)"!]
[!ELSEIF "$MacInputVal = 'SMU_ALARM_GROUP6'"!][!//
[!VAR "OutMac_RTACCfg" = "num:i(6)"!]
[!ELSE!][!//
[!ERROR"Config Error: Wrong SMU_RTACCfg Select."!]
[!ENDIF!]
[!ENDMACRO!]



[!ENDIF!][!// IF "not(var:defined('Smu_M'))
