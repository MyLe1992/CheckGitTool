/**
*     @file    Icu_SIUL2_Types.h
*     @version 1.1.0
* 
*     @brief   AUTOSAR Icu - SIUL low level driver exported structures.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
* 
*     *     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================    
*     Project             : AUTOSAR 4.0 MCAL
*     Platform            : PA
*     Peripheral          : GTM
*     Dependencies        : none
* 
*     Autosar Version     : 4.0.3
*     Autosar Revision    : ASR_REL_4_0_REV_0003
*     Autosar ConfVariant : 
*     SWVersion           : 1.1.0
*     BuildVersion        : MPC577XM_MCAL_1_1_0_FBR_ASR_REL_4_0_REV_0003_20150925
* 
*     (c) Copyright 2006-2015 Freescale Inc
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_SIUL2_TYPES
#define ICU_SIUL2_TYPES

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_SIUL2_Types_h_1
*        Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*        that 31 character significance and case sensitivity are supported for external identifiers.
*        The defines are validated.
*
* @section [global]
*        Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*        on the significance of more than 31 characters. The used compilers use more than 31 chars
*        for identifiers.
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_SIUL2_TYPES_VENDOR_ID                   43
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION    4
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION    0
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION 3
#define ICU_SIUL2_TYPES_SW_MAJOR_VERSION            1
#define ICU_SIUL2_TYPES_SW_MINOR_VERSION            1
#define ICU_SIUL2_TYPES_SW_PATCH_VERSION            0
/**@}*/


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief SIUL External Interrupt Channels defines
*/
#define SIUL2_IRQ_0    ((uint8) 0U)
#define SIUL2_IRQ_1    ((uint8) 1U)
#define SIUL2_IRQ_2    ((uint8) 2U)
#define SIUL2_IRQ_3    ((uint8) 3U)
#define SIUL2_IRQ_4    ((uint8) 4U)
#define SIUL2_IRQ_5    ((uint8) 5U)
#define SIUL2_IRQ_6    ((uint8) 6U)
#define SIUL2_IRQ_7    ((uint8) 7U)
#define SIUL2_IRQ_8    ((uint8) 8U)
#define SIUL2_IRQ_9    ((uint8) 9U)
#define SIUL2_IRQ_10   ((uint8)10U)
#define SIUL2_IRQ_11   ((uint8)11U)
#define SIUL2_IRQ_12   ((uint8)12U)
#define SIUL2_IRQ_13   ((uint8)13U)
#define SIUL2_IRQ_14   ((uint8)14U)
#define SIUL2_IRQ_15   ((uint8)15U)
#define SIUL2_IRQ_16   ((uint8)16U)
#define SIUL2_IRQ_17   ((uint8)17U)
#define SIUL2_IRQ_18   ((uint8)18U)
#define SIUL2_IRQ_19   ((uint8)19U)
#define SIUL2_IRQ_20   ((uint8)20U)
#define SIUL2_IRQ_21   ((uint8)21U)
#define SIUL2_IRQ_22   ((uint8)22U)
#define SIUL2_IRQ_23   ((uint8)23U)
#define SIUL2_IRQ_24   ((uint8)24U)
#define SIUL2_IRQ_25   ((uint8)25U)
#define SIUL2_IRQ_26   ((uint8)26U)
#define SIUL2_IRQ_27   ((uint8)27U)
#define SIUL2_IRQ_28   ((uint8)28U)
#define SIUL2_IRQ_29   ((uint8)29U)
#define SIUL2_IRQ_30   ((uint8)30U)
#define SIUL2_IRQ_31   ((uint8)31U)

/**@}*/

/**
* @{
* @brief Filter for enabling the SIUL2 interrupt
*/
#define SIUL2_INT_FILTER_ENABLE  (0x1U)
/**@}*/


/**
* @{
* @brief SIUL2 Channel Parameters
* @remarks Interrupt Filter Enable Register (IFER)
*          These macros are used in ICU plug-in
*
*/
#define ICU_SIUL2_INT_FILTER_ENABLE_PARAM_MASK       ((uint32)BIT4)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_FILTER_ENABLE_PARAM_SHIFT      ((uint32)4U)
/**@}*/

/**
* @{
* @brief SIUL2 Channel Parameters
* @remarks Interrupt Filter Maximum Counter Registers (IFMC0-FMC23)
*          These macros are used in ICU plug-in
*/
#define ICU_SIUL2_INT_FILTER_COUNTER_PARAM_MASK      (BIT3|BIT2|BIT1|BIT0)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_FILTER_COUNTER_PARAM_SHIFT     ((uint32)0U)
/**@}*/

/**
* @{
* @brief SIUL2 Global Configuration Parameter
* @remarks Interrupt Filter Clock Prescaler Register(SIUL2_IFCPR)
*/
#define ICU_SIUL2_INT_FILTER_CLOCK_PRESCALER_GC_MASK      (BIT3|BIT2|BIT1|BIT0)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_FILTER_CLOCK_PRESCALER_GC_SHIFT     ((uint32)0U)

/**
* @{
* @brief SIUL2 Global Configuration Parameter
* @remarks Interrupt Filter Clock Prescaler in Alternate Mode(SIUL2_IFCPR)
*/
#define ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_MASK      (BIT7|BIT6|BIT5|BIT4)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_SHIFT     ((uint32)4U)

/**@}*/
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8  Icu_Siul2_ChannelType;
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* ICU_SIUL2_TYPES */
/** @} */

