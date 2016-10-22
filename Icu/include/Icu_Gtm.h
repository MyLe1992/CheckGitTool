/**
*    @file    Icu_Gtm.h
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

#ifndef ICU_GTM_H
#define ICU_GTM_H

/**
*    @file         Icu_GTM.h
*/

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section ICU_GTM_H_REF_1
* Violates MISRA 2004 Required Rule  19.15 ,Precautions shall be taken in order to prevent the 
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the 
* significance of  more than 31 characters.
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Gtm_Types.h"
#include "Icu_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Icu_GTM.h
* @brief          Source file version information
*/
#define ICU_GTM_VENDOR_ID                       43
#define ICU_GTM_AR_RELEASE_MAJOR_VERSION        4
#define ICU_GTM_AR_RELEASE_MINOR_VERSION        0
#define ICU_GTM_AR_RELEASE_REVISION_VERSION     3
#define ICU_GTM_SW_MAJOR_VERSION                1
#define ICU_GTM_SW_MINOR_VERSION                1
#define ICU_GTM_SW_PATCH_VERSION                0
/**@}*/
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if Icu_Gtm.h file and  Icu_Gtm_Types header file are of the same vendor */
#if (ICU_GTM_VENDOR_ID != ICU_GTM_TYPES_VENDOR_ID)
    #error "Icu_Gtm.h and Icu_Gtm_Types.h have different vendor IDs"
#endif

/*Check if Icu_Gtm.h file and Icu_Gtm_Types header file are of the same Software version*/
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION != ICU_GTM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION != ICU_GTM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION != ICU_GTM_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Gtm.h and Icu_Gtm_Types.h are different"
#endif

/*Check if Icu_Gtm.h file and Icu_Gtm_Types header file are of the same Software version*/
#if ((ICU_GTM_SW_MAJOR_VERSION != ICU_GTM_TYPES_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION != ICU_GTM_TYPES_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION != ICU_GTM_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Gtm.h and Icu_Gtm_Types.h are different"
#endif


/* Check if Icu_Gtm.h file and  Icu_Types header file are of the same vendor */
#if (ICU_GTM_VENDOR_ID != ICU_TYPES_VENDOR_ID)
    #error "Icu_Gtm.h and Icu_Types.h have different vendor IDs"
#endif

/*Check if Icu_Gtm.h file and Icu_Types header file are of the same Software version*/
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Gtm.h and Icu_Types.h are different"
#endif

/*Check if Icu_Gtm.h file and Icu_Types header file are of the same Software version*/
#if ((ICU_GTM_SW_MAJOR_VERSION != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION != ICU_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Gtm.h and Icu_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Number of channels on GTM module
*/
#define GTM_TIM_N_CHANNELS       (7U)


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Icu_Gtm_ChannelModeType
* @details          Type that indicates the channel mode type(capture mode, edge counter).
*/
typedef enum
{
    ICU_GTM_CHANNEL_TPWM_MODE = 0U,
    ICU_GTM_CHANNEL_TPIM_MODE = 1U,      /**< @brief GTM_CHANNEL_TPWM_MODE */
    ICU_GTM_CHANNEL_TIEM_MODE = 2U,      /**< @brief GTM_CHANNEL_TIEM_MODE */ 
    ICU_GTM_CHANNEL_TIPM_MODE = 3U,      /**< @brief GTM_CHANNEL_TIPM_MODE */
    ICU_GTM_CHANNEL_TBCM_MODE = 4U      /**< @brief GTM_CHANNEL_TBCM_MODE */
} Icu_Gtm_ChannelModeType;


/**
* @brief            GTM_MesurementModeType
* @details          Type that indicates the channel mode type(capture mode, edge counter).
*
* */
typedef enum
{
    GTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT    = 0x01U, /*< @brief Mode for detecting edges. */
    GTM_CHANNEL_MODE_SIGNAL_MEASUREMENT    = 0x02U, /*< @brief Mode for measuring different times
                                                    *  between various configurable edges. */
    GTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA = 0x04U, /*< @brief Mode for capturing timer values
                                                    *  on configurable edges. */
    GTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA    = 0x10U, /*< @brief Mode for capturing timer values
                                                     *  on configurable edges. */
    GTM_CHANNEL_MODE_EDGE_COUNTER          = 0x08U /*< @brief Mode for counting edges on
                                                       *  configurable edges. */
} Icu_Gtm_ChannelMeasurementModeType;

/**
 * @brief Definition of the measurement property type.
 * */
typedef enum
{
    GTM_ICU_LOW_TIME     = 0x01U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Low Time. */
    GTM_ICU_HIGH_TIME    = 0x02U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal High Time. */
    GTM_ICU_ACTIVE_TIME  = 0x03U,    /*< @brief The channel is configured for reading the
                                         *          elapsed signal active Time. */
    GTM_ICU_PERIOD_TIME  = 0x04U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Period Time. */
    GTM_ICU_DUTY_CYCLE   = 0x08U     /*< @brief The channel is configured to read values which
                                         *          are needed for calculating the duty cycle
                                         *          (coherent Active and Period Time). */
} Icu_Gtm_SignalMeasurementPropertyType;

/**
* @brief         Icu_Gtm_ActivationType
* @details       Type that indicates the channel activation type
*                 (Rising, Falling, Both Edges or Opposite Edges).
*
*/
typedef enum
{
    /**< @brief An appropriate action shall be executed when a falling edge occurs on the 
        ICU input signal. */
    GTM_FALLING_EDGE = 0x0U,  
    /**< @brief An appropriate action shall be executed when a rising edge occurs on the 
        ICU input signal.*/
    GTM_RISING_EDGE  = 0x1U, 
    /**< @brief An appropriate action shall be executed when either a rising or falling edge occur
        on the ICU input signal.*/
    GTM_BOTH_EDGES   = 0x2U
} Icu_Gtm_ActivationType;
/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/** @violates @ref ICU_GTM_H_REF_1 precautions to prevent the contents */
#include "MemMap.h"

FUNC (void, ICU_CODE) Icu_Gtm_InitChannel(CONST(uint32, AUTOMATIC) u32ParamValue,
                                          CONST(uint32, AUTOMATIC) u32IcuFilterParamRe,
                                          CONST(uint32, AUTOMATIC) u32IcuFilterParamFe,
                                          CONST(Icu_Gtm_ChannelMeasurementModeType, AUTOMATIC) ChannelMode,
                                          CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
FUNC (void, ICU_CODE) Icu_Gtm_DeInitChannel(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);

#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Gtm_SetSleepMode(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);


FUNC (void, ICU_CODE) Icu_Gtm_SetNormalMode(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SET_MODE_API */


FUNC (void, ICU_CODE) Icu_Gtm_SetActivationCondition(
                                              CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                              CONST(Icu_ActivationType, AUTOMATIC) Activation);


#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Gtm_EnableEdgeDetection(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);


FUNC (void, ICU_CODE) Icu_Gtm_DisableEdgeDetection(CONST(Icu_Gtm_ChannelType, AUTOMATIC)
                                                                                   hwChannel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_TIMESTAMP_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Gtm_StartTimestamp(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,\
                                                        CONST(boolean, AUTOMATIC) bDmaSupport);


FUNC (void, ICU_CODE) Icu_Gtm_StopTimestamp(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
FUNC(uint32, ICU_CODE) Icu_Gtm_GetStartAddress(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Gtm_ResetEdgeCount(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);


FUNC (void, ICU_CODE) Icu_Gtm_EnableEdgeCount(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);


FUNC (void, ICU_CODE) Icu_Gtm_DisableEdgeCount(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);


FUNC (uint32, ICU_CODE) Icu_Gtm_GetEdgeNumbers(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_EDGE_COUNT_API */

FUNC (boolean, ICU_CODE) Icu_Gtm_GetOverflow(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);

FUNC (uint32, ICU_CODE) Icu_Gtm_GetGPR0(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);

FUNC (uint32, ICU_CODE) Icu_Gtm_GetGPR1(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Gtm_StartSignalMeasurement(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                              CONST(Icu_Gtm_ActivationType, AUTOMATIC)Activation,
                              CONST(Icu_Gtm_SignalMeasurementPropertyType, AUTOMATIC)MeasProperty);


FUNC (void, ICU_CODE) Icu_Gtm_StopSignalMeasurement(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (boolean, ICU_CODE) Icu_Gtm_GetInputState(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
FUNC (Icu_LevelType, ICU_CODE) Icu_Gtm_GetInputLevel(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel);
#endif /* ICU_GET_INPUT_LEVEL_API */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Gtm_SetPrescaler(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel, \
                                             VAR(uint32, AUTOMATIC) u32chClkSrcMode);
                                          
#endif  /* ICU_DUAL_CLOCK_MODE_API */

#define ICU_STOP_SEC_CODE
/** @violates @ref ICU_GTM_H_REF_1 precautions to prevent the contents */
#include "MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_GTM_H */

/** @} */
