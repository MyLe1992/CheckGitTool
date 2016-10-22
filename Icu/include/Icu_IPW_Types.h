/**
*     @file Icu_IPW_Types.h
*     @version 1.1.0
* 
*     @brief   AUTOSAR Icu - Brief description.
*     @details Detailed description.
*     
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.0 MCAL
*     Platform PA
*     Peripheral GTM
*     Dependencies none
* 
*     Autosar Version 4.0.3
*     Autosar Revision ASR_REL_4_0_REV_0003
*     Autosar ConfVariant
*     SWVersion 1.1.0
*     BuildVersion MPC577XM_MCAL_1_1_0_FBR_ASR_REL_4_0_REV_0003_20150925
* 
*     (c) Copyright 2006-2015 Freescale Inc
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef ICU_IPW_TYPES_H
#define ICU_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_IPW_Types_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* @section Icu_IPW_Types_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to IP functions.
* @section Icu_IPW_Types_h_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
*          character significance and case sensitivity are supported for external identifiers.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Icu_IPW_Types_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "StdRegMacros.h"
#include "Icu_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_TYPES_VENDOR_ID                       43

#define ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        0
#define ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     3
#define ICU_IPW_TYPES_SW_MAJOR_VERSION                1
#define ICU_IPW_TYPES_SW_MINOR_VERSION                1
#define ICU_IPW_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_IPW_Types header and StdRegMacros header file are of the same vendor */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_IPW_Types.c and StdRegMacros.h are different"
    #endif
#endif

/* Check if Icu_IPW_Types header and Icu_Types header file are of the same vendor */
#if (ICU_IPW_TYPES_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu_IPW_Types.h and Icu_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_IPW_Types header file are of the same Autosar version */
#if ((ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_IPW_Types.h and Icu_Types.h are different"
#endif
/* Check if header file and Icu_IPW_Types header file are of the same software version */
#if ((ICU_IPW_TYPES_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_TYPES_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_TYPES_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_IPW_Types.h and Icu_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/* Macros to name the HW channels (GTM_TIM and IRQ's) */
/**
* @{
* @brief      GTM_TIM Channelss
* @details    GTM_TIM Hardware Channels
*/

#define ICU_GTM_TIM_0_CH_0        (0U)
#define ICU_GTM_TIM_0_CH_1        (ICU_GTM_TIM_0_CH_0 +  1U)
#define ICU_GTM_TIM_0_CH_2        (ICU_GTM_TIM_0_CH_0 +  2U)
#define ICU_GTM_TIM_0_CH_3        (ICU_GTM_TIM_0_CH_0 +  3U)
#define ICU_GTM_TIM_0_CH_4        (ICU_GTM_TIM_0_CH_0 +  4U)
#define ICU_GTM_TIM_0_CH_5        (ICU_GTM_TIM_0_CH_0 +  5U)
#define ICU_GTM_TIM_0_CH_6        (ICU_GTM_TIM_0_CH_0 +  6U)
#define ICU_GTM_TIM_0_CH_7        (ICU_GTM_TIM_0_CH_0 +  7U)

#define ICU_GTM_TIM_1_CH_0        (ICU_GTM_TIM_0_CH_7  +  1U)
#define ICU_GTM_TIM_1_CH_1        (ICU_GTM_TIM_0_CH_7  +  2U)
#define ICU_GTM_TIM_1_CH_2        (ICU_GTM_TIM_0_CH_7  +  3U)
#define ICU_GTM_TIM_1_CH_3        (ICU_GTM_TIM_0_CH_7  +  4U)
#define ICU_GTM_TIM_1_CH_4        (ICU_GTM_TIM_0_CH_7  +  5U)
#define ICU_GTM_TIM_1_CH_5        (ICU_GTM_TIM_0_CH_7  +  6U)
#define ICU_GTM_TIM_1_CH_6        (ICU_GTM_TIM_0_CH_7  +  7U)
#define ICU_GTM_TIM_1_CH_7        (ICU_GTM_TIM_0_CH_7  +  8U)

#define ICU_GTM_TIM_2_CH_0        (ICU_GTM_TIM_1_CH_7  +  1U)
#define ICU_GTM_TIM_2_CH_1        (ICU_GTM_TIM_1_CH_7  +  2U)
#define ICU_GTM_TIM_2_CH_2        (ICU_GTM_TIM_1_CH_7  +  3U)
#define ICU_GTM_TIM_2_CH_3        (ICU_GTM_TIM_1_CH_7  +  4U)
#define ICU_GTM_TIM_2_CH_4        (ICU_GTM_TIM_1_CH_7  +  5U)
#define ICU_GTM_TIM_2_CH_5        (ICU_GTM_TIM_1_CH_7  +  6U)
#define ICU_GTM_TIM_2_CH_6        (ICU_GTM_TIM_1_CH_7  +  7U)
#define ICU_GTM_TIM_2_CH_7        (ICU_GTM_TIM_1_CH_7  +  8U)

#define ICU_GTM_TIM_3_CH_0        (ICU_GTM_TIM_2_CH_7  +  1U)
#define ICU_GTM_TIM_3_CH_1        (ICU_GTM_TIM_2_CH_7  +  2U)
#define ICU_GTM_TIM_3_CH_2        (ICU_GTM_TIM_2_CH_7  +  3U)
#define ICU_GTM_TIM_3_CH_3        (ICU_GTM_TIM_2_CH_7  +  4U)
#define ICU_GTM_TIM_3_CH_4        (ICU_GTM_TIM_2_CH_7  +  5U)
#define ICU_GTM_TIM_3_CH_5        (ICU_GTM_TIM_2_CH_7  +  6U)
#define ICU_GTM_TIM_3_CH_6        (ICU_GTM_TIM_2_CH_7  +  7U)
#define ICU_GTM_TIM_3_CH_7        (ICU_GTM_TIM_2_CH_7  +  8U)

#define ICU_GTM_TIM_4_CH_0        (ICU_GTM_TIM_3_CH_7  +  1U)
#define ICU_GTM_TIM_4_CH_1        (ICU_GTM_TIM_3_CH_7  +  2U)
#define ICU_GTM_TIM_4_CH_2        (ICU_GTM_TIM_3_CH_7  +  3U)
#define ICU_GTM_TIM_4_CH_3        (ICU_GTM_TIM_3_CH_7  +  4U)
#define ICU_GTM_TIM_4_CH_4        (ICU_GTM_TIM_3_CH_7  +  5U)
#define ICU_GTM_TIM_4_CH_5        (ICU_GTM_TIM_3_CH_7  +  6U)
#define ICU_GTM_TIM_4_CH_6        (ICU_GTM_TIM_3_CH_7  +  7U)
#define ICU_GTM_TIM_4_CH_7        (ICU_GTM_TIM_3_CH_7  +  8U)

#define ICU_GTM_TIM_5_CH_0        (ICU_GTM_TIM_4_CH_7  +  1U)
#define ICU_GTM_TIM_5_CH_1        (ICU_GTM_TIM_4_CH_7  +  2U)
#define ICU_GTM_TIM_5_CH_2        (ICU_GTM_TIM_4_CH_7  +  3U)
#define ICU_GTM_TIM_5_CH_3        (ICU_GTM_TIM_4_CH_7  +  4U)
#define ICU_GTM_TIM_5_CH_4        (ICU_GTM_TIM_4_CH_7  +  5U)
#define ICU_GTM_TIM_5_CH_5        (ICU_GTM_TIM_4_CH_7  +  6U)
#define ICU_GTM_TIM_5_CH_6        (ICU_GTM_TIM_4_CH_7  +  7U)
#define ICU_GTM_TIM_5_CH_7        (ICU_GTM_TIM_4_CH_7  +  8U)
/**@}*/
/**
* @{
* @brief      External Interrupt Channels
* @details    SIUL2 IRQ Channels
*/
#define ICU_IRQ_CH_0           (ICU_GTM_TIM_5_CH_7 + 1U)
#define ICU_IRQ_CH_1           (ICU_IRQ_CH_0 +  1U)
#define ICU_IRQ_CH_2           (ICU_IRQ_CH_0 +  2U)
#define ICU_IRQ_CH_3           (ICU_IRQ_CH_0 +  3U)
#define ICU_IRQ_CH_4           (ICU_IRQ_CH_0 +  4U)
#define ICU_IRQ_CH_5           (ICU_IRQ_CH_0 +  5U)
#define ICU_IRQ_CH_6           (ICU_IRQ_CH_0 +  6U)
#define ICU_IRQ_CH_7           (ICU_IRQ_CH_0 +  7U)
#define ICU_IRQ_CH_8           (ICU_IRQ_CH_0 +  8U)
#define ICU_IRQ_CH_9           (ICU_IRQ_CH_0 +  9U)
#define ICU_IRQ_CH_10          (ICU_IRQ_CH_0 + 10U)
#define ICU_IRQ_CH_11          (ICU_IRQ_CH_0 + 11U)
#define ICU_IRQ_CH_12          (ICU_IRQ_CH_0 + 12U)
#define ICU_IRQ_CH_13          (ICU_IRQ_CH_0 + 13U)
#define ICU_IRQ_CH_14          (ICU_IRQ_CH_0 + 14U)
#define ICU_IRQ_CH_15          (ICU_IRQ_CH_0 + 15U)

/**@}*/



/*
* Macros regarding the maximum number of HW channels from different IP modules
*/
/**
* @{
* @brief      ICU_MAX_eTIMER_CHANNELS - the maximum number of eTIMER channels
* @details    Represents the maximum number of eTIMER channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_GTM_CHANNELS      (ICU_IRQ_CH_0)
/**@}*/

/**
* @{
* @brief      ICU_MAX_IRQ_CHANNELS - the maximum number of IRQ channels
* @details    Represents the maximum number of IRQ channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_IRQ_CHANNELS        (ICU_IRQ_CH_15 + 1U)
/**@}*/


/**
* @{
* @brief      ICU_MAX_HW_CHANNELS - the highest ICU hardware channel number
* @details    Represents the maximum number of IRQ channels, not necessary all
*             are available for a specific derivative. If some channels are
*             missing for a derivative, the encoding of the channels will be not
*             contiguous.
*/
#define ICU_MAX_HW_CHANNELS         (ICU_MAX_IRQ_CHANNELS)
/**@}*/

/**
* @{
* @brief      ICU_VALID_CHANNEL_INPUT_LEVEL - the maximum number of eTiemr channels
* @details    Represents the maximum number of eTimer channels, To get the status of
*             input pin using an API Icu_GetInputLevel the channel should be an eTimer
*             Channel.
*/

#define ICU_VALID_CHANNEL_INPUT_LEVEL         (ICU_MAX_GTM_CHANNELS)
/**@}*/

/**
* @{
* @brief Macros to translate ICU generic channels to specific hardware channels
*
* @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
*/
#define ICU_GTM_CHANNEL(ch)             (ch)
/**
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define ICU_IRQ_CHANNEL(ch)             ((ch) - ICU_IRQ_CH_0)
/**
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define GTM_ICU_CHANNEL(ch)             ((ch))
/**
 * @violates @ref Icu_IPW_Types_h_REF_2 Function-like macro defined
 * */
#define IRQ_ICU_CHANNEL(ch)             ((ch) + ICU_IRQ_CH_0)
/**@}*/

/**
* @{
* @brief   Macros for handling the actual states of the ICU Channels
* @remarks These bitfields are used to set Icu_aChannelState array
*/

/**
* @{
* @brief Wakeup feature is currently enabled
*/
#define ICU_CHANNEL_STATE_WKUP                  ((Icu_ChannelStateType)BIT0)
#define ICU_CHANNEL_STATE_WKUP_SHIFT            (0U)
#define ICU_CHANNEL_STATE_WKUP_MASK             ((Icu_ChannelStateType)BIT0)
/**@}*/

/**
* @{
* @brief The current channel status - IDLE / ACTIVE
*/
#define ICU_CHANNEL_STATE_IDLE                  ((Icu_ChannelStateType)BIT1)
#define ICU_CHANNEL_STATE_IDLE_SHIFT            (1U)
#define ICU_CHANNEL_STATE_IDLE_MASK             ((Icu_ChannelStateType)BIT1)
/**@}*/

/**
* @{
* @brief Notification is enabled
*/
#define ICU_CHANNEL_STATE_NOTIFICATION          ((Icu_ChannelStateType)BIT2)
#define ICU_CHANNEL_STATE_NOTIF_SHIFT           (2U)
#define ICU_CHANNEL_STATE_NOTIF_MASK            ((Icu_ChannelStateType)BIT2)
/**@}*/

/**
* @{
* @brief The current channel state
*/
#define ICU_CHANNEL_STATE_RUNNING               ((Icu_ChannelStateType)BIT3)
#define ICU_CHANNEL_STATE_RUNNING_SHIFT         (3U)
#define ICU_CHANNEL_STATE_RUNNING_MASK          ((Icu_ChannelStateType)BIT3)
/**@}*/

/**
* @{
* @brief Overflow flag
*/
#define ICU_CHANNEL_STATE_OVERFLOW              ((Icu_ChannelStateType)BIT4)
#define ICU_CHANNEL_STATE_OVERFLOW_SHIFT        (4U)
#define ICU_CHANNEL_STATE_OVERFLOW_MASK         ((Icu_ChannelStateType)BIT4)
/**@}*/

/**
* @{
* @brief Rising edge
*/
#define ICU_CHANNEL_STATE_RISING                ((Icu_ChannelStateType)BIT5)
#define ICU_CHANNEL_STATE_RISING_SHIFT          (5U)
#define ICU_CHANNEL_STATE_RISING_MASK           ((Icu_ChannelStateType)BIT5)
/**@}*/

/**
* @{
* @brief Falling edge
*/
#define ICU_CHANNEL_STATE_FALLING               ((Icu_ChannelStateType)BIT6)
#define ICU_CHANNEL_STATE_FALLING_SHIFT         (6U)
#define ICU_CHANNEL_STATE_FALLING_MASK          ((Icu_ChannelStateType)BIT6)
/**@}*/

/**
* @{
* @brief Both edges
*/
#define ICU_CHANNEL_STATE_BOTH_EDGES            ((Icu_ChannelStateType)(BIT6|BIT5))
#define ICU_CHANNEL_STATE_BOTH_EDGES_SHIFT      (5U)
#define ICU_CHANNEL_STATE_BOTH_EDGES_MASK       ((Icu_ChannelStateType)(BIT6|BIT5))
/**@}*/

/**
* @{
* @brief Wakeup source
*/
#define ICU_CHANNEL_IS_WAKEUP_SOURCE            ((Icu_ChannelStateType)BIT7)
#define ICU_CHANNEL_IS_WAKEUP_SOURCE_SHIFT      (7U)
#define ICU_CHANNEL_IS_WAKEUP_SOURCE_MASK       ((Icu_ChannelStateType)BIT7)
/**@}*/

/**
 * @brief  Definition of bit mask to isolate the wake up capability  bitfield
 */
#define ICU_WAKEUP_MASK         ((uint32)BIT31)
/**
 * @brief  Definition wake up capability bitfield position
 */
#define ICU_WAKEUP_SHIFT        ((uint32)31U)

/**
 * @brief  Definition of bit mask to isolate the configured edge activation type
 */
#define ICU_EDGE_PARAM_MASK     ((uint32)(BIT30|BIT29))
/**
 * @brief  Definition edge activation type bitfield position
 */
#define ICU_EDGE_PARAM_SHIFT    ((uint32)29U)
/**@}*/
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief   ICU Channel state type
*
*/
typedef uint8 Icu_ChannelStateType;

typedef uint8 Icu_IPW_ChannelType;

typedef const uint32 Icu_IPW_GlobalConfigurationType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* ICU_IPW_TYPES_H */
/** @} */

