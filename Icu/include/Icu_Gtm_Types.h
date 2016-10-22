/**
*   @file    Icu_Gtm_Types.h
*   @version 1.1.0
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : GTM
*   Dependencies         : none
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.1.0
*   Build Version        : MPC577XM_MCAL_1_1_0_FBR_ASR_REL_4_0_REV_0003_20150925
*
*   (c) Copyright 2006-2015 Freescale Inc
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_GTM_TYPES_H
#define ICU_GTM_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Gtm_Types_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_GTM_TYPES_VENDOR_ID                         43
#define ICU_GTM_TYPES_MODULE_ID                         122
#define ICU_GTM_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define ICU_GTM_TYPES_AR_RELEASE_MINOR_VERSION          0
#define ICU_GTM_TYPES_AR_RELEASE_REVISION_VERSION       3
#define ICU_GTM_TYPES_SW_MAJOR_VERSION                  1
#define ICU_GTM_TYPES_SW_MINOR_VERSION                  1
#define ICU_GTM_TYPES_SW_PATCH_VERSION                  0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @{
* @brief Specific GTM_TIM Channel parameters
* @remarks defines for bitfields used in Icu_ParamValue member for ICU GTM_TIM Channels
*/
#define CMU_CLK0 ((uint32)0x00)
#define CMU_CLK1 ((uint32)0x01)
#define CMU_CLK2 ((uint32)0x02)
#define CMU_CLK3 ((uint32)0x03)
#define CMU_CLK4 ((uint32)0x04)
#define CMU_CLK5 ((uint32)0x05)
#define CMU_CLK6 ((uint32)0x06)
#define CMU_CLK7 ((uint32)0x07)

#define TBU_TS0     ((uint32)0x00)
#define TBU_TS1     ((uint32)0x01)
#define TBU_TS2     ((uint32)0x02)
#define CNT_SOURCE  ((uint32)0x03)
#define CNTS_SOURCE ((uint32)0x03)

#define TBU_TS0_23_0 ((uint32)0x00)
#define TBU_TS0_26_3 ((uint32)0x01)

#define FLT_CMU_CLK0 ((uint32)0x00)
#define FLT_CMU_CLK1 ((uint32)0x01)
#define FLT_CMU_CLK6 ((uint32)0x02)
#define FLT_CMU_CLK7 ((uint32)0x03)

#define IMMEDIATE_EDGE_PROPAGATION ((uint32)0x00)
#define INDIVIDUAL_DEGLITCH        ((uint32)0x01)

#define UP_DOWN_COUNTER   ((uint32)0x00)
#define HOLD_COUNTER      ((uint32)0x01)

#define  ICU_GTM_TIM_CLK_SEL_ALT_MASK_U32                           ((uint32)(BIT12|BIT11|BIT10))
#define  ICU_GTM_TIM_CLK_SEL_ALT_SHIFT                              ((uint32)10)
#define  ICU_GTM_TIM_CLK_SEL_MASK_U32                               ((uint32)(BIT27|BIT26|BIT25))
#define  ICU_GTM_TIM_CLK_SEL_SHIFT                                  ((uint32)25)
#define  ICU_GTM_TIM_GPR1_SEL_MASK_U32                              ((uint32)(BIT24 | BIT23))
#define  ICU_GTM_TIM_GPR1_SEL_SHIFT                                 ((uint32)23)
#define  ICU_GTM_TIM_GPR0_SEL_MASK_U32                              ((uint32)(BIT22 | BIT21))
#define  ICU_GTM_TIM_GPR0_SEL_SHIFT                                 ((uint32)21)

#define  ICU_GTM_TIM_TIME_BASE0_BITS_MASK_U32                       ((uint32)BIT20)
#define  ICU_GTM_TIM_TIME_BASE0_BITS_SHIFT                          ((uint32)20)
#define  ICU_GTM_TIM_FILTER_MODE_FE_MASK_U32                        ((uint32)BIT19)
#define  ICU_GTM_TIM_FILTER_MODE_FE_SHIFT                           ((uint32)19)
#define  ICU_GTM_TIM_FILTER_COUNTER_MODE_FE_MASK_U32                ((uint32)BIT18)
#define  ICU_GTM_TIM_FILTER_COUNTER_MODE_FE_SHIFT                   ((uint32)18)
#define  ICU_GTM_TIM_FILTER_MODE_RE_MASK_U32                        ((uint32)BIT17)
#define  ICU_GTM_TIM_FILTER_MODE_RE_SHIFT                           ((uint32)17)
#define  ICU_GTM_TIM_FILTER_COUNTER_MODE_RE_MASK_U32                ((uint32)BIT16)
#define  ICU_GTM_TIM_FILTER_COUNTER_MODE_RE_SHIFT                   ((uint32)16)
#define  ICU_GTM_TIM_FILTER_COUNTER_CLOCK_MASK_U32                  ((uint32)(BIT15 | BIT14))
#define  ICU_GTM_TIM_FILTER_COUNTER_CLOCK_SHIFT                     ((uint32)14)
#define  ICU_GTM_TIM_FILTER_ENABLE_MASK_U32                         ((uint32)(BIT13))
#define  ICU_GTM_TIM_FILTER_ENABLE_SHIFT                            ((uint32)13)
#define  ICU_GTM_TIM_FILTER_RINSING_EDGE_PARAM_MASK_U32             ((uint32)(BIT23|BIT22|BIT21|BIT20|BIT19|BIT18|BIT17|BIT16|BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))
#define  ICU_GTM_TIM_FILTER_RINSING_EDGE_PARAM_SHIFT                ((uint32)0)
#define  ICU_GTM_TIM_FILTER_FALLING_EDGE_PARAM_MASK_U32             ((uint32)(BIT23|BIT22|BIT21|BIT20|BIT19|BIT18|BIT17|BIT16|BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))
#define  ICU_GTM_TIM_FILTER_FALLING_EDGE_PARAM_SHIFT                ((uint32)0)


/**
 * @brief          This gives the numeric ID (hardware channel number) of an ICU channel
 * */
typedef uint8                           Icu_Gtm_ChannelType;
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_Gtm_Types_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "MemMap.h"

/* Check if header file and MemMap.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((ICU_GTM_TYPES_AR_RELEASE_MAJOR_VERSION != MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_GTM_TYPES_AR_RELEASE_MINOR_VERSION != MEMMAP_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Gtm_Types.h and MemMap.h are different"
#endif
#endif


#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_Gtm_Types_h_1 precautions to prevent the contents of a header file being
*           included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
#endif
