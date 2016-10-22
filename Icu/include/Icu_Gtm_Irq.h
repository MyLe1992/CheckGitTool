/**
*    @file    Icu_Gtm_Irq.h
*    @version 1.1.0
* 
*    @brief   AUTOSAR Icu - GTM header file support for ICU driver.
*    @details GTM header file, containing the variables and functions that are exported by the IP driver.
*   
*    @addtogroup ICU_MODULE
*    @{
*/
/*==================================================================================================
*    Project               : AUTOSAR 4.0 MCAL
*    Platform              : PA
*    Peripheral            : GTM
*    Dependencies          : none
* 
*    Autosar Version       : 4.0.3
*    Autosar Revision      : ASR_REL_4_0_REV_0003
*    Autosar Conf.Variant  : 
*    SWVersion             : 1.1.0
*    BuildVersion          : MPC577XM_MCAL_1_1_0_FBR_ASR_REL_4_0_REV_0003_20150925
* 
*    (c) Copyright 2006-2015 Freescale Semiconductor Inc. & STMicroelectronics
*    All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_GTM_IRQ_H
#define ICU_GTM_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section ICU_GTM_IRQ_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the 
* significance of  more than 31 characters.
* 
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Gtm_Types.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define ICU_GTM_IRQ_VENDOR_ID                       43
#define ICU_GTM_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define ICU_GTM_IRQ_AR_RELEASE_MINOR_VERSION        0
#define ICU_GTM_IRQ_AR_RELEASE_REVISION_VERSION     3
#define ICU_GTM_IRQ_SW_MAJOR_VERSION                1
#define ICU_GTM_IRQ_SW_MINOR_VERSION                1
#define ICU_GTM_IRQ_SW_PATCH_VERSION                0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_Gtm_Irq.h file and  Icu_Gtm_Types header file are of the same vendor */
#if (ICU_GTM_IRQ_VENDOR_ID != ICU_GTM_TYPES_VENDOR_ID)
    #error "Icu_Gtm_Irq.h and Icu_Gtm_Types.h have different vendor IDs"
#endif

#if ((ICU_GTM_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_GTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_IRQ_AR_RELEASE_MINOR_VERSION != ICU_GTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_IRQ_AR_RELEASE_REVISION_VERSION != ICU_GTM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Gtm_Irq.h and Icu_Gtm_Types.h are different"
#endif

/*Check if Icu_Gtm_Irq.h file and Icu_Gtm_Types header file are of the same Software version*/
#if ((ICU_GTM_IRQ_SW_MAJOR_VERSION != ICU_GTM_TYPES_SW_MAJOR_VERSION) || \
     (ICU_GTM_IRQ_SW_MINOR_VERSION != ICU_GTM_TYPES_SW_MINOR_VERSION) || \
     (ICU_GTM_IRQ_SW_PATCH_VERSION != ICU_GTM_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Gtm_Irq.h and Icu_Gtm_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref ICU_GTM_IRQ_H_REF_1 precautions to prevent the
*       contents of a header file being included twice  */
#include "MemMap.h"


FUNC(void, ICU_CODE) Icu_Gtm_ProcessInterrupt(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);

#define ICU_STOP_SEC_CODE
/*
* @violates @ref ICU_GTM_IRQ_H_REF_1 precautions to prevent the
*       contents of a header file being included twice
*/
#include "MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* ICU_GTM_IRQ_H */

/** @} */
