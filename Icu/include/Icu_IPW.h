/**
*     @file ICU_IPW.h
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

#ifndef ICU_IPW_H
#define ICU_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_IPW_h_REF_1
*         Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*         Middle layer between AUTOSAR and hardware needs a way to map HLD
*         functions to IP functions.
*
* @section Icu_IPW_h_REF_2
*         Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*         the contents of a header file being included twice
*         This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_IPW_h_REF_3
*           Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced
*           initialiser, a constant, a parenthesised expression, a type qualifier, a storage class
*           specifier, or a do-while-zero construct.
*           This is used to route calls from AUTOSAR to hardware layer
* @section [global]
*         Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*         on the significance of more than 31 characters. The used compilers use more than 31 chars
*         for identifiers.
*
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/

#include "Icu_IPW_Types.h"
#include "Icu_Gtm.h"
#include "Icu_SIUL2.h"


/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_IPW_VENDOR_ID                       43

#define ICU_IPW_AR_RELEASE_MAJOR_VERSION        4
#define ICU_IPW_AR_RELEASE_MINOR_VERSION        0
#define ICU_IPW_AR_RELEASE_REVISION_VERSION     3
#define ICU_IPW_SW_MAJOR_VERSION                1
#define ICU_IPW_SW_MINOR_VERSION                1
#define ICU_IPW_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_IPW header and Icu_IPW_Types header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_IPW.h and Icu_IPW_Types.h have different vendor IDs"
#endif
    /* Check if header file and Icu_IPW_Types header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_IPW.h and Icu_IPW_Types.h are different"
#endif
/* Check if header file andIcu_IPW_Types header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION != ICU_IPW_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_IPW.h and Icu_IPW_Types.h are different"
#endif


/* Check if Icu_IPW header and Icu_eTimer header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_GTM_VENDOR_ID)
    #error "Icu_IPW.h and Icu_GTM.h have different vendor IDs"
#endif
    /* Check if header file and Icu_eTimer header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION != ICU_GTM_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION != ICU_GTM_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION != ICU_GTM_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_IPW.h and Icu_GTM.h are different"
#endif
/* Check if header file and Icu_GTM header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION != ICU_GTM_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION != ICU_GTM_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION != ICU_GTM_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_IPW.h and Icu_GTM.h are different"
#endif


/* Check if Icu_IPW header and Icu_Siul2 header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID != ICU_SIUL2_VENDOR_ID)
    #error "Icu_IPW.h and Icu_Siul2.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Siul2 header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION != ICU_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION != ICU_SIUL2_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION != ICU_SIUL2_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_IPW.h and Icu_Siul2.h are different"
#endif
/* Check if header file andIcu_Siul2 header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION != ICU_SIUL2_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION != ICU_SIUL2_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION != ICU_SIUL2_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_IPW.h and Icu_Siul2.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*@brief default value for the global configuration*/
#define ICU_GC_DEFAULT_VALUE (ICU_SIUL2_IFCPR_DEFAULT_VALUE)


#if (ICU_TIMESTAMP_API == STD_ON)
 /**
 * @brief Mapping macro between start timestamp GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
 #define Icu_IPW_StartTimestamp(hwChannel, dmaSupport) \
    do \
    { \
        Icu_Gtm_StartTimestamp(ICU_GTM_CHANNEL((hwChannel)), (dmaSupport));\
    } while(0)

 /**
 * @brief Mapping macro between stop timestamp GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
 #define Icu_IPW_StopTimestamp(hwChannel) \
    do \
    { \
        Icu_Gtm_StopTimestamp(ICU_GTM_CHANNEL((hwChannel)));\
    } while(0)

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/*
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define Icu_IPW_InitDmaConfiguration(u8NoDmaChConfigured, DmaReqConfig) \
     do \
     { \
     } while(0)
#endif
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/*
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
#define Icu_IPW_DeInitDmaConfiguration(u8NoDmaChConfigured, DmaReqConfig) \
    do \
    { \
    } while(0)
#endif
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/*
* @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* @violates @ref Icu_IPW_h_REF_3  MISRA 2004 Advisory Rule 19.4, C macros shall only expand to a
*                                 braced initializer, a constant, a parenthesized expression
*/
#define Icu_IPW_GetStartAddress(hwChannel) \
    Icu_Gtm_GetStartAddress(ICU_GTM_CHANNEL((hwChannel)))
#endif
#endif  /* ICU_TIMESTAMP_API == STD_ON */

#if (ICU_EDGE_COUNT_API == STD_ON)
 /**
 * @brief Mapping macro between reset edge count GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
 #define Icu_IPW_ResetEdgeCount(hwChannel)  \
    do \
    { \
        Icu_Gtm_ResetEdgeCount(ICU_GTM_CHANNEL((hwChannel)));\
    } while(0)
 /**
 * @brief Mapping macro between enable edge count GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
 #define Icu_IPW_EnableEdgeCount(hwChannel) \
    do \
    { \
        Icu_Gtm_EnableEdgeCount(ICU_GTM_CHANNEL((hwChannel)));\
    } while(0)
 /**
 * @brief Mapping macro between disable edge count GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 */
 #define Icu_IPW_DisableEdgeCount(hwChannel)  \
    do \
    { \
        Icu_Gtm_DisableEdgeCount(ICU_GTM_CHANNEL((hwChannel)));\
    } while(0)
 /**
 * @brief Mapping macro between get edge numbers GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 * @violates @ref Icu_IPW_h_REF_3  MISRA 2004 Advisory Rule 19.4, C macros shall only expand to a
 *                                 braced initializer, a constant, a parenthesized expression
 *
 */
 #define Icu_IPW_GetEdgeNumbers(hwChannel) \
        (Icu_EdgeNumberType)Icu_Gtm_GetEdgeNumbers(ICU_GTM_CHANNEL((hwChannel)))
#endif  /* ICU_EDGE_COUNT_API == STD_ON */


#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || \
                                           (ICU_TIMESTAMP_API == STD_ON)))
/**@violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined  */
 #define Icu_IPW_GetCaptureRegisterValue(hwChannel) \
        ((Icu_ValueType)Icu_Gtm_GetGPR0(hwChannel))
#endif

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON) )
 /**
 * @brief Mapping macro between get overflow GTM functionality and high level function
 *
 * @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
 * @violates @ref Icu_IPW_h_REF_3  MISRA 2004 Advisory Rule 19.4, C macros shall only expand to a
 *                                 braced initializer, a constant, a parenthesized expression
 *
 */
 #define Icu_IPW_Get_Overflow(hwChannel) \
     Icu_Gtm_GetOverflow(ICU_GTM_CHANNEL((hwChannel)))

#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief Mapping macro between stop signal GTM measurement functionality and high level function
*
* @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define Icu_IPW_StopSignalMeasurement(hwChannel) \
    do \
    { \
        Icu_Gtm_StopSignalMeasurement(ICU_GTM_CHANNEL(hwChannel));\
    } while(0)
#endif  /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */


#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief Mapping macro between GTM get input level functionality and high level function
*
* @violates @ref Icu_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* @violates @ref Icu_IPW_h_REF_3  MISRA 2004 Advisory Rule 19.4, C macros shall only expand to a
*                                 braced initializer, a constant, a parenthesized expression
*
*/
#define Icu_IPW_GetInputLevel(hwChannel) \
        Icu_Gtm_GetInputLevel(ICU_GTM_CHANNEL((hwChannel)))
#endif   /* ICU_GET_INPUT_LEVEL_API == STD_ON */

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
* @violates @ref Icu_IPW_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"

FUNC (void, ICU_CODE) Icu_IPW_InitChannel(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                          VAR(Icu_ParamType, AUTOMATIC) ParamValue,
                                          VAR(Icu_MeasurementModeType, AUTOMATIC) ChannelMode,
                                          VAR(Icu_ParamType, AUTOMATIC) Icu_FilterParamRe,
                                          VAR(Icu_ParamType, AUTOMATIC) Icu_FilterParamFe
                                         );

FUNC(void, ICU_CODE) Icu_IPW_InitGlobalConfiguration(\
                     P2CONST(Icu_IPW_GlobalConfigurationType, AUTOMATIC, ICU_APPL_DATA)Icu_IPW_GlobalConfiguration,
                     VAR(boolean, AUTOMATIC) bGlobalInit);

#if (ICU_DE_INIT_API == STD_ON)
 FUNC (void, ICU_CODE) Icu_IPW_DeInitChannel(VAR(Icu_ChannelType, AUTOMATIC) hwChannel);
#endif

#if (ICU_SET_MODE_API == STD_ON)
 FUNC (void, ICU_CODE) Icu_IPW_SetSleepMode(VAR(Icu_ChannelType, AUTOMATIC) hwChannel);
 FUNC (void, ICU_CODE) Icu_IPW_SetNormalMode(VAR(Icu_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SET_MODE_API == STD_ON */


FUNC (void, ICU_CODE) Icu_IPW_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(Icu_ActivationType, AUTOMATIC) Activation,
                                                     VAR(Icu_MeasurementModeType, AUTOMATIC) Mode
                                                     );

#if (ICU_GET_INPUT_STATE_API == STD_ON)
 FUNC(Icu_InputStateType, ICU_CODE)Icu_IPW_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API == STD_ON */



#if (ICU_EDGE_DETECT_API == STD_ON)
 FUNC (void, ICU_CODE) Icu_IPW_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) hwChannel);
 FUNC (void, ICU_CODE) Icu_IPW_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_EDGE_DETECT_API */



#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_IPW_StartSignalMeasurement( CONST(Icu_ChannelType, AUTOMATIC) hwChannel,\
                                                    VAR(Icu_ActivationType, AUTOMATIC) startEdge,\
                                                    VAR(Icu_SignalMeasurementPropertyType, AUTOMATIC) measProperty,
                                                    VAR(boolean, AUTOMATIC)bDmaSupport
                                                    );
#endif  /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */


#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)

FUNC (void, ICU_CODE) Icu_IPW_SelectPrescaler(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                              VAR(Icu_ParamType, AUTOMATIC) ParamValue,
                                              VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler
                                              );

FUNC (void, ICU_CODE) Icu_IPW_SelectGlobalPrescaler(P2CONST(Icu_IPW_GlobalConfigurationType, \
                                            AUTOMATIC, ICU_APPL_DATA) Icu_IPW_GlobalConfiguration, \
                                            VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler);

#endif /* ICU_DUAL_CLOCK_MODE_API == STD_ON */


FUNC (void, ICU_CODE) Icu_IPW_ProcessCommonInterrupt(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(uint32, AUTOMATIC) flags
                                                    );

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_IPW_h_REF_2 Precautions shall be taken in order to prevent the contents of a
* header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_IPW_H */
/** @} */

