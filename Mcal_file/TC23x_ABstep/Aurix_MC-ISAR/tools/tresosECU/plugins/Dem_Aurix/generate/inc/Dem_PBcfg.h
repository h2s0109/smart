[!/*****************************************************************************
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
**  FILENAME  : Dem_PBcfg.h                                                   **
**                                                                            **
**  VERSION   : 1.0.1                                                         **
**                                                                            **
**  DATE      : 2012.06.18                                                    **
**                                                                            **
**  BSW MODULE DECRIPTION : Dem.xdm                                           **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Code template for Dem_PBcfg.h file                         **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_DiagnosticEventManager, Release-4.0, 4.1.0 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
********************************************************************************
** VS: Vinod Shankar  							                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
* V1.0.1: 2012.06.18, VS :Fix for AI00071821
* V1.0.0: 2011.07.09, VS :Initial Version

 ************************************************************************/!][!//
[!//
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2011)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Dem_PBcfg.h                                                   **
**                                                                            **
**  VERSION   : 1.0.1                                                         **
**                                                                            **
**  DATE, TIME: [!"$date"!], [!"$time"!]                                          **
**                                                                            **
**  GENERATOR : Build [!"$buildnr"!]                                            **
**                                                                            **
**  BSW MODULE DESCRIPTION : Dem.xdm                                          **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking                                                       **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : DEM configuration generated out of ECU configuration       **
**                 file                                                       **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_DiagnosticEventManager, Release-4.0, 4.1.0 **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/

#ifndef DEM_PBCFG_H
#define DEM_PBCFG_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

[!/* Select MODULE-CONFIGURATION as context-node */!][!//
[!SELECT "as:modconf('Dem')[1]"!][!//
[!//
[!VAR "DemSelect" = "'DemConfigSet'"!][!//
[!IF "node:exists(node:ref($DemSelect)/*[1]/DemEventParameter/*[1])"!][!//
[!SELECT "node:ref($DemSelect)/*[1]"!][!//
/* Assignment of Event Id values for the Symbols */
[!VAR "EventIdCount" = "num:i(1)"!][!//
[!LOOP "(./DemEventParameter/*)"!][!//
#define DemConf_DemEventParameter_[!"node:name(.)"!]  (Dem_EventIdType)([!"num:i($EventIdCount)"!]U) /* Event Id for [!"node:name(.)"!] */
[!VAR "EventIdCount" = "num:i($EventIdCount + 1)"!][!//
[!ENDLOOP!][!//
[!ENDSELECT!][!//[!SELECT "DemConfigSet"!]
[!ENDIF!][!//
[!ENDSELECT!][!//[!SELECT "as:modconf('Dem')[1]"!]
#endif /* end of DEM_PBCFG_H */

