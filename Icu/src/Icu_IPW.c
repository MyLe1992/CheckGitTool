/**
*     @file            Icu_IPW.c
*     @implements      Icu_IPW_unit
*     @version 1.1.0
* 
*     @brief   AUTOSAR Icu - ICU Driver LLD source file.
*     @details ICU driver source file, containing the LLD variables and functions that are used by
*              the ICU driver.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_IPW_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*          before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
*          is as  per Autosar  requirement MEMMAP003.
* 
* @section Icu_IPW_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* 
* @section Icu_IPW_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

#include "Icu_Cfg.h"

#include "Icu_IPW.h"


/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define ICU_IPW_VENDOR_ID_C                     43
/*
* @violates @ref Icu_IPW_c_REF_3 Identifier clash.
*/ 
#define ICU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/*
* @violates @ref Icu_IPW_c_REF_3 Identifier clash.
*/ 
#define ICU_IPW_AR_RELEASE_MINOR_VERSION_C      0
/*
* @violates @ref Icu_IPW_c_REF_3 Identifier clash.
*/ 
#define ICU_IPW_AR_RELEASE_REVISION_VERSION_C   3
#define ICU_IPW_SW_MAJOR_VERSION_C              1
#define ICU_IPW_SW_MINOR_VERSION_C              1
#define ICU_IPW_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_IPW.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and Icu_Cfg header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
#error "Icu_IPW.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_IPW.c are different"
    #endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_Cfg.h and Icu_IPW.c are different"
#endif

/* Check if source file and Icu_IPW header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
    #error "Icu_IPW.c and Icu_IPW.h have different vendor IDs"
#endif
/* Check if source file and Icu_IPW header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_IPW.c and Icu_IPW.h are different"
#endif
/* Check if source file and Icu_IPW header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_IPW.c and Icu_IPW.h are different"
#endif


/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @violates @ref Icu_IPW_c_REF_1 only preprocessor statements and
*        comments before "#include".
*/
/**
* @violates @ref Icu_IPW_c_REF_2 precautions to prevent the contents
*        of a header file being included twice  
*/
#include "MemMap.h"


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/



 /**
 * @brief      Icu_IPW_InitChannel
 * @details    Initialize a hardware ICU channel
 *
 * @param[in]      hwChannel   - This index relates the Icu Channel number with the respective
 *                               global variable, depending on the measurement mode
 *                               Each kind of measurement mode has an array(s) in the ICU driver,
 *                               this index points to the corresponding variable within the ICU
 *                               channel
 * @param[in]      ParamValue  - contains the parameters to initialize the hardware channel
 * @param[in]      ChannelMode - The measurement mode of the channel
 *
 * @return void
 *
 * @pre        Icu_DeInit must be called before.
 *
 */
FUNC (void, ICU_CODE) Icu_IPW_InitChannel(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                          VAR(Icu_ParamType, AUTOMATIC) ParamValue,
                                          VAR(Icu_MeasurementModeType, AUTOMATIC) ChannelMode,
                                          VAR(Icu_ParamType, AUTOMATIC) Icu_FilterParamRe,
                                          VAR(Icu_ParamType, AUTOMATIC) Icu_FilterParamFe
                                         )

{
    /* GTM_TIM Channel Configuration */
    if (hwChannel < ICU_MAX_GTM_CHANNELS )
    {
        Icu_Gtm_InitChannel(ParamValue, Icu_FilterParamRe, Icu_FilterParamFe,\
                                                (Icu_Gtm_ChannelMeasurementModeType)ChannelMode,\
                                                ICU_GTM_CHANNEL(hwChannel));
    }
     /* External Interrupt Channel Configuration */
    else
    {
        Icu_SIUL2_InitChannel(ParamValue, ICU_IRQ_CHANNEL(hwChannel));
    }

}

/**
* @brief      Icu_IPW_InitGlobalConfiguration
* @details    Initializes module specific register of the ICU driver
*
* @param[in]  Icu_IPW_GlobalConfiguration   - This is a variable where the hardware specific
*                                             configuration values are stored. 
* @param[in]  bGlobalInit  - information if the function is called from Icu_Init or Icu_DeInit
*
* @return void
*
* @pre        Icu_DeInit or Icu_Init must be called before.
*
*/
FUNC(void, ICU_CODE) Icu_IPW_InitGlobalConfiguration(\
                     P2CONST(Icu_IPW_GlobalConfigurationType, AUTOMATIC, ICU_APPL_DATA)\
                     Icu_IPW_GlobalConfiguration, VAR(boolean, AUTOMATIC) bGlobalInit)
{
     VAR(uint32, AUTOMATIC) u32GlobalConfig;
     
     u32GlobalConfig = ((uint32)(* Icu_IPW_GlobalConfiguration));
     
     if (bGlobalInit == (boolean)TRUE)
     {
        Icu_SIUL2_GlobalConfigurationSetUp((uint8)((u32GlobalConfig & \
                ICU_SIUL2_INT_FILTER_COUNTER_PARAM_MASK) >> ICU_SIUL2_INT_FILTER_COUNTER_PARAM_SHIFT));
     }
     else
     {
        Icu_SIUL2_GlobalConfigurationSetUp(0U);
     }
} 

 #if (ICU_DE_INIT_API == STD_ON)
/**
* @brief              Icu_IPW_DeInit
* @details            De-initialize ICU hardware channel
* 
* @param[in]          hwChannel - This index relates the Icu Channel number
* 
* @return void
*
* @pre                Icu_Init must be called before.
*
*/
FUNC (void, ICU_CODE) Icu_IPW_DeInitChannel(VAR(Icu_ChannelType, AUTOMATIC) hwChannel)
{

    /* GTM Channel Configuration */
    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        Icu_Gtm_DeInitChannel(ICU_GTM_CHANNEL(hwChannel));
    }
    /* External Interrupt Channel Configuration */
    else
    {
        Icu_SIUL2_DeInitChannel((Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
}
#endif /* ICU_DE_INIT_API == STD_ON */

#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief      Icu_IPW_SetSleepMode
* @details    Set sleep mode
* 
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
* @param[in]      active     - ICU channel is active during SLEEP mode (wakeup was enabled)
* 
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_IPW_SetSleepMode(VAR(Icu_ChannelType, AUTOMATIC) hwChannel)
{

    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        Icu_Gtm_SetSleepMode(ICU_GTM_CHANNEL(hwChannel));
    }
    else
    {
        Icu_SIUL2_SetSleepMode((Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }

}


/**
* @brief      Icu_IPW_SetNormalMode
* @details    Set normal mode
* 
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
* 
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_IPW_SetNormalMode(VAR(Icu_ChannelType, AUTOMATIC) hwChannel)
{

    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        Icu_Gtm_SetNormalMode(ICU_GTM_CHANNEL(hwChannel));
    }
    else
    {
        Icu_SIUL2_SetNormalMode((Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
}
#endif  /* ICU_SET_MODE_API */



/**
* @brief      Icu_IPW_SetActivationCondition
* @details
* 
* @param[in]      hwChannel     - The index of ICU channel for current configuration structure
* @param[in]      Activation    - the type of activation for the ICU channel.
* @param[in]      Mode            - the measurement mode of the channel
* 
* @return void
* 
*/
FUNC (void, ICU_CODE) Icu_IPW_SetActivationCondition(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                                     VAR(Icu_ActivationType, AUTOMATIC) Activation,
                                                     VAR(Icu_MeasurementModeType, AUTOMATIC) Mode
                                                    )
{
    /* GTM Channel Configuration */
     if (hwChannel < ICU_MAX_GTM_CHANNELS)
     {
         Icu_Gtm_SetActivationCondition(ICU_GTM_CHANNEL(hwChannel),
                                          (Icu_ActivationType)Activation);
     }
    /* External Interrupt Channel Configuration */
    else
    {
        Icu_SIUL2_SetActivationCondition((Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel), 
                                                           (Icu_Siul2_ActivationType)Activation);
    }

}

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu_IPW_GetInputState
* @details    Service that returns the state of the ICU driver
* 
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
* 
* @return Icu_InputStateType
* @retval   ICU_ACTIVE          An active edge has been detected
* @retval   ICU_IDLE            No active edge has been detected since the cast call to
*                               Icu_IPW_InitChannel or Icu_IPW_GetInputState
* 
*/
FUNC (Icu_InputStateType, ICU_CODE) Icu_IPW_GetInputState(VAR(Icu_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(Icu_InputStateType, AUTOMATIC) tempReturn = ICU_IDLE;
    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        if (Icu_Gtm_GetInputState(ICU_GTM_CHANNEL(hwChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    else
    {
        if (Icu_SIUL2_GetInputState(
                (Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    return (tempReturn);
}
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief          Icu_IPW_EnableEdgeDetection
* @details        Retrieve the number of edges
* 
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
* @return         void
*
*/
FUNC (void, ICU_CODE) Icu_IPW_EnableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) hwChannel)
{

    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        Icu_Gtm_EnableEdgeDetection(ICU_GTM_CHANNEL(hwChannel));
    }
    else
    {
        Icu_SIUL2_EnableEdgeDetection((Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel));
    }
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief      Icu_IPW_DisableEdgeDetection
* @details    Retrieve the number of edges
* 
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
*
* @return         void
*
*/
FUNC (void, ICU_CODE) Icu_IPW_DisableEdgeDetection(VAR(Icu_ChannelType, AUTOMATIC) hwChannel)
{
    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        Icu_Gtm_DisableEdgeDetection(ICU_GTM_CHANNEL(hwChannel));
    }
    else
    {
        Icu_SIUL2_DisableEdgeDetection((Icu_Siul2_ChannelType)ICU_IRQ_CHANNEL(hwChannel)) ;
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_IPW_StartSignalMeasurement
* @details    Starts the signal measurement service
* 
* @param[in]      hwChannel     - The index of ICU channel for current configuration structure
* @param[in]      startEdge     - activation edge of the signal measurement
* @param[in]      measProperty  - the property that will be measured on the channel
* 
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_IPW_StartSignalMeasurement(\
                                    CONST(Icu_ChannelType, AUTOMATIC) hwChannel,
                                    VAR(Icu_ActivationType, AUTOMATIC) startEdge,
                                    VAR(Icu_SignalMeasurementPropertyType, AUTOMATIC)measProperty,
                                    VAR(boolean, AUTOMATIC)bDmaSupport)
{
    Icu_ActivationType activation = ICU_RISING_EDGE;
    (void)bDmaSupport;
    /* Set Default Start Edge, Set channel mode signal can be start measured either by falling edge or
    rising edge */
    if (startEdge == ICU_RISING_EDGE)
    {
        activation = ICU_RISING_EDGE;
    }
    else
    {
        activation = ICU_FALLING_EDGE;
    }
    Icu_Gtm_StartSignalMeasurement(ICU_GTM_CHANNEL(hwChannel),
                              (Icu_Gtm_ActivationType)activation,
                              (Icu_Gtm_SignalMeasurementPropertyType)measProperty);
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */


#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      This function changes the channel prescaler.
* @details    This function sets all channels prescalers based on the input mode.
*
* @param[in]  hwChannel     - The index of ICU channel for current configuration structure
* @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
*
* @return void
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_IPW_SelectPrescaler(VAR(Icu_ChannelType, AUTOMATIC) hwChannel,
                                              VAR(Icu_ParamType, AUTOMATIC) ParamValue,
                                              VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler
                                             )
{
    if (hwChannel < ICU_MAX_GTM_CHANNELS)
    {
        if (ICU_NORMAL_CLOCK_MODE == Prescaler)
        {
            Icu_Gtm_SetPrescaler(hwChannel, \
               (uint32)((ParamValue & ICU_GTM_TIM_CLK_SEL_MASK_U32 ) >> \
               ICU_GTM_TIM_CLK_SEL_SHIFT));
        }
        else
        {
            Icu_Gtm_SetPrescaler(hwChannel, \
                 (uint32)((ParamValue & ICU_GTM_TIM_CLK_SEL_ALT_MASK_U32) >> \
                 ICU_GTM_TIM_CLK_SEL_ALT_SHIFT));
        }
    }
}

/*================================================================================================*/
/**
* @brief      This function changes the global prescaler.
* @details    This function sets the module prescalers based on the input mode.
*
* @param[in]  Icu_IPW_GlobalConfiguration    - The index of ICU channel for current configuration structure
* @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
*
* @return void
*/
/*================================================================================================*/

FUNC (void, ICU_CODE) Icu_IPW_SelectGlobalPrescaler(P2CONST(Icu_IPW_GlobalConfigurationType, \
                                         AUTOMATIC, ICU_APPL_DATA) Icu_IPW_GlobalConfiguration, \
                                         VAR(Icu_SelectPrescalerType, AUTOMATIC) Prescaler)
{
    VAR(uint32, AUTOMATIC) u32GlobalConfig; 
    
    u32GlobalConfig = ((uint32)(* Icu_IPW_GlobalConfiguration));

    if (ICU_NORMAL_CLOCK_MODE == Prescaler)
    {
        Icu_SIUL2_SelectGlobalPrescaler((u32GlobalConfig & ICU_SIUL2_INT_FILTER_CLOCK_PRESCALER_GC_MASK) >> \
                                        ICU_SIUL2_INT_FILTER_CLOCK_PRESCALER_GC_SHIFT);
    }
    else
    {
        Icu_SIUL2_SelectGlobalPrescaler((u32GlobalConfig & ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_MASK) >> \
                                        ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_SHIFT);
    }
}

#endif /* ICU_DUAL_CLOCK_MODE_API == STD_ON */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_IPW_c_REF_1 only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_IPW_c_REF_2 precautions to prevent the contents
*        of a header file being included twice  
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

