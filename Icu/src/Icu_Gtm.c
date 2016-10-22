/**
*     @file    Icu_Gtm.c
*     @implements    Icu_Gtm_unit
*     @version 1.1.0
*
*     @brief   AUTOSAR Icu - GTM source file support for ICU driver.
*     @details GTM source file, containing the variables and functions that are exported by the
*              GTM driver.
*
*     @addtogroup ICU_MODULE
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
*     ((c) Copyright 2006-2015 Freescale Inc
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Gtm_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar
* requirement MEMMAP003.
*
* @section Icu_Gtm_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_Gtm_c_REF_3
* Violates MISRA 2004 Required Rule 1.4 , Identifier clash.
* This violation is due to large macro name. This is maintained for better readability.
*
* @section Icu_Gtm_c_REF_4
* Violates MISRA 2004 Required Rule 11.1 , Conversions shall not be performed between
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped registers
* or other hardware specific features.
* @section Icu_Gtm_c_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters.
* @section Icu_Gtm_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section Icu_Gtm_c_REF_7
* Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the
* prototype shall be visible at both the function definition and call.
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
#include "Compiler.h"
#include "Std_Types.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "Gtm_Common_Types.h"
#include "SilRegMacros.h"

#include "Icu_Gtm.h"
#include "Reg_eSys_Gtm.h"
#include "Icu_IPW_Types.h"
#include "Icu_IPW_Irq.h"

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
/**
* @{
* @brief   Source file version information
*
*/
#define ICU_GTM_VENDOR_ID_C         43
/** @violates @ref Icu_Gtm_c_REF_3 Identifier clash.*/
/** @violates @ref Icu_Gtm_c_REF_5 Identifiers shall not rely on the significance of
more than 31 characters.*/
#define ICU_GTM_AR_RELEASE_MAJOR_VERSION_C  4
/**
* @violates @ref Icu_Gtm_c_REF_3 Identifier clash.
* @violates @ref Icu_Gtm_c_REF_5 Identifiers shall not rely on the significance of
more than 31 characters.*/
#define ICU_GTM_AR_RELEASE_MINOR_VERSION_C  0
/**
* @violates @ref Icu_Gtm_c_REF_3 Identifier clash.
* @violates @ref Icu_Gtm_c_REF_5 Identifiers shall not rely on the significance of
more than 31 characters.*/
#define ICU_GTM_AR_RELEASE_REVISION_VERSION_C  3
#define ICU_GTM_SW_MAJOR_VERSION_C  1
#define ICU_GTM_SW_MINOR_VERSION_C  1
#define ICU_GTM_SW_PATCH_VERSION_C  0
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/**
* @{
* @brief Version checks
*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
     #error "AutoSar Version Numbers of Icu_Gtm.c and SilRegMacros.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != STD_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != STD_TYPES_AR_RELEASE_MINOR_VERSION))
     #error "AutoSar Version Numbers of Icu_Gtm.c and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != COMPILER_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != COMPILER_AR_RELEASE_MINOR_VERSION))
     #error "AutoSar Version Numbers of Icu_Gtm.c and Compiler.h are different"
    #endif
#endif

#if (ICU_GTM_VENDOR_ID_C != ICU_GTM_VENDOR_ID)
 #error "Icu_Gtm.c and Icu_Gtm.h have different vendor IDs"
#endif

/* Check if source file and Icu_GTM header file are of the same Autosar version */
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != ICU_GTM_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != ICU_GTM_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION_C != ICU_GTM_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Gtm.c and Icu_Gtm.h are different"
#endif

/* Check if source file and Icu_GTM header file are of the same Software version */
#if ((ICU_GTM_SW_MAJOR_VERSION_C != ICU_GTM_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION_C != ICU_GTM_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION_C != ICU_GTM_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Gtm.c and Icu_Gtm.h are different"
#endif


/* Check if Icu_GTM.c and Reg_eSys_Gtm.h file are of the same vendor */
#if (ICU_GTM_VENDOR_ID_C != REG_ESYS_GTM_H_VENDOR_ID)
 #error "Icu_Gtm.c and Reg_eSys_Gtm.h have different vendor IDs"
#endif

/* Check if Icu_GTM.c and Reg_eSys_Gtm.h file are of the same Autosar version */
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_GTM_H_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_GTM_H_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_GTM_H_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Gtm.c and Reg_eSys_Gtm.h are different"
#endif

/* Check if Icu_GTM.c and Reg_eSys_Gtm.h file are of the same Software version */
#if ((ICU_GTM_SW_MAJOR_VERSION_C != REG_ESYS_GTM_H_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION_C != REG_ESYS_GTM_H_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION_C != REG_ESYS_GTM_H_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Gtm.c and Reg_eSys_Gtm.h are different"
#endif


/* Check if Icu_GTM.c and Icu_IPW_Types.h file are of the same vendor */
#if (ICU_GTM_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
 #error "Icu_Gtm.c and Icu_IPW_Types.h have different vendor IDs"
#endif

/* Check if Icu_GTM.c and Icu_IPW_Types.h file are of the same Autosar version */
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Gtm.c and Icu_IPW_Types.h are different"
#endif

/* Check if Icu_GTM.c and Icu_IPW_Types.h file are of the same Software version */
#if ((ICU_GTM_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Gtm.c and Icu_IPW_Types.h are different"
#endif


/* Check if Icu_GTM.c and Icu_IPW_Irq.h file are of the same vendor */
#if (ICU_GTM_VENDOR_ID_C != ICU_IRQ_VENDOR_ID)
 #error "Icu_Gtm.c and Icu_IPW_Irq.h have different vendor IDs"
#endif

/* Check if Icu_GTM.c and Icu_IPW_Irq.h file are of the same Autosar version */
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != ICU_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != ICU_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION_C != ICU_IRQ_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Gtm.c and Icu_IPW_Irq.h are different"
#endif

/* Check if Icu_GTM.c and Icu_IPW_Irq.h file are of the same Software version */
#if ((ICU_GTM_SW_MAJOR_VERSION_C != ICU_IRQ_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION_C != ICU_IRQ_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION_C != ICU_IRQ_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Gtm.c and Icu_IPW_Irq.h are different"
#endif


/* Check if Icu_GTM.c and Gtm_Common_Types.h file are of the same vendor */
#if (ICU_GTM_VENDOR_ID_C != GTM_COMMON_TYPES_VENDOR_ID)
 #error "Icu_GTM.c and Gtm_Common_Types.h have different vendor IDs"
#endif

/* Check if Icu_GTM.c and Gtm_Common_Types.h file are of the same Autosar version */
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != GTM_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != GTM_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION_C != GTM_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_GTM.c and Gtm_Common_Types.h are different"
#endif

/* Check if Icu_GTM.c and Gtm_Common_Types.h file are of the same Software version */
#if ((ICU_GTM_SW_MAJOR_VERSION_C != GTM_COMMON_TYPES_SW_MAJOR_VERSION) || \
     (ICU_GTM_SW_MINOR_VERSION_C != GTM_COMMON_TYPES_SW_MINOR_VERSION) || \
     (ICU_GTM_SW_PATCH_VERSION_C != GTM_COMMON_TYPES_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_GTM.c and Gtm_Common_Types.h are different"
#endif


/* Check if Icu_GTM.c and Icu_Cfg.h file are of the same vendor */
#if (ICU_GTM_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
 #error "Icu_GTM.c and Icu_Cfg.h have different vendor IDs"
#endif

/* Check if Icu_GTM.c and Icu_Cfg.h file are of the same Autosar version */
#if ((ICU_GTM_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_GTM_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_GTM_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
 #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_GTM.c are different"
#endif

/* Check if Icu_GTM.c and Icu_Cfg.h file are of the same Software version */
#if ((ICU_GTM_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_GTM_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_GTM_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
 #error "Software Version Numbers of Icu_GTM.c and Icu_Cfg.h are different"
#endif


/**@}*/
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef uint16 Icu_Gtm_ChConfigType;

/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/
#define ICU_GTM_MEAS_MODE_MASK            ((uint16)(BIT8|BIT7|BIT6|BIT5|BIT4))
#define ICU_GTM_MEAS_MODE_SHIFT           (4U)

#define ICU_GTM_MEAS_PROPERTY_MASK        ((uint16)(BIT3|BIT2|BIT1|BIT0))
#define ICU_GTM_MEAS_PROPERTY_SHIFT       (0U)

#define ICU_GTM_CH_INITIALIZED_MASK       ((uint16)BIT9)

/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/

/** @violates @ref Icu_Gtm_c_REF_5 Identifiers shall not rely on the significance of
more than 31 characters.*/
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Icu_Gtm_c_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref Icu_Gtm_c_REF_2 precautions to prevent the contents...
*/
#include "MemMap.h"
STATIC VAR(Icu_Gtm_ChConfigType, ICU_VAR) Icu_Gtm_aChConfig[ICU_MAX_GTM_CHANNELS];
/** @violates @ref Icu_Gtm_c_REF_5 Identifiers shall not rely on the significance of
more than 31 characters.*/
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED

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
* @violates @ref Icu_Gtm_c_REF_1 only preprocessor statements and comments before "#include".
* @violates @ref Icu_Gtm_c_REF_2 precautions to prevent the contents of a header file
* being included twice.
*/
#include "MemMap.h"

/**
* @brief      Icu_Gtm_SetChConfig
* @details    Set the Icu_Gtm_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE \
    FUNC(void, ICU_CODE) Icu_Gtm_SetChConfig(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(Icu_Gtm_ChConfigType, AUTOMATIC) mask)
{
        Icu_Gtm_aChConfig[hwChannel] |= mask;
}


/**
* @brief      Icu_Gtm_ClearChConfig
* @details    Clear the Icu_Gtm_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      hwChannel  - The index of ICU channel for current configuration structure
* @param[in]      mask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE\
    FUNC(void, ICU_CODE) Icu_Gtm_ClearChConfig(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                                  VAR(Icu_Gtm_ChConfigType, AUTOMATIC) mask)
{
    Icu_Gtm_aChConfig[hwChannel]  &= ((Icu_Gtm_ChConfigType)(~mask));

}


/**
 * @brief      Icu_Gtm_GetChConfig
 * @details    Return the Icu_Gtm_ChConfigType bitfield specified by mask parameter in an atomic way
 *
 * @param[in]      hwChannel  - The index of ICU channel for current configuration structure
 * @param[in]      mask    - bitfield mask
 * @return         Bitfield specified by mask parameter
 */
LOCAL_INLINE\
    FUNC(Icu_Gtm_ChConfigType, ICU_CODE) Icu_Gtm_GetChConfig(
                                                    VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                                    VAR(Icu_Gtm_ChConfigType, AUTOMATIC) mask)
{
    return (Icu_Gtm_aChConfig[hwChannel]  & mask);
}

/*================================================================================================*/
/**
* @brief      Icu_Gtm_GetStatusFlags
* @details    Returns the flags set only for the enabled interrupts
*
* @param[in]   hwChannel - GTM Hardware Channel
*
* @return      Flags set for enabled interrupts
*
*/
/*================================================================================================*/
LOCAL_INLINE \
        FUNC (uint32, ICU_CODE) Icu_Gtm_GetStatusFlags(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    VAR(uint32, AUTOMATIC) u32Flags;

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    {
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        VAR(uint32, AUTOMATIC) u32RegIRQNOTIFY = REG_READ32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex));
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        VAR(uint32, AUTOMATIC) u32RegIRQEN = REG_READ32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex));
        u32Flags = u32RegIRQNOTIFY & u32RegIRQEN;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();

    return u32Flags;
}

/*================================================================================================*/
/**
* @brief      Icu_Gtm_ClearStatusFlags
* @details    Clear the flags set only for selected interrupts that are enabled
*
* @param[in]      hwChannel - GTM Hardware Channel
* @param[in]      u32bitMask   - flags to be cleared
*
* @return void
*
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Gtm_ClearStatusFlags(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                              VAR(uint32, AUTOMATIC) u32BitMask)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
    {
        /*in case of CNTOF the interrupt request will be generated when the CNT reg has reached maximum value*/
        /*so to clear this request the CNT reg is resetted by enabling and disabling the channel */
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        if ((TIM_CTRL_MODE_TIEM_U32 == \
        ((REG_READ32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex)) & TIM_CTRL_MODE_MASK_U32 ) >> TIM_CTRL_MODE_SHIFT)) && \
            (TIM_IRQ_ENABLE_CNTOF_IRQ_EN_MASK_U32 == (u32BitMask & TIM_IRQ_ENABLE_CNTOF_IRQ_EN_MASK_U32)))
        {
            /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
            REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32);
            /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
            REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32);
        }
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_WRITE32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) , u32BitMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16();
}

#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu_Gtm_Timestamp
* @details    This service is  called when an  interrupt is recognized  as a Timestamp Measurement
*             type.
*
* @param[in]      numChl - The index of ICU channel for current configuration structure
*
* @return void
*
*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Gtm_Timestamp(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel, \
                                                        VAR(boolean, AUTOMATIC) overflow)
{

    STATIC VAR(uint32,ICU_VAR) u16BufferPtr[4];
    VAR(uint8, AUTOMATIC) u8capturedWords = 1U;
    VAR(uint8, AUTOMATIC) u8Index = 0U;

    for (u8Index = 0U; u8Index < u8capturedWords; u8Index++)
    {
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        u16BufferPtr[u8Index]= Icu_Gtm_GetGPR0(hwChannel);
    }
    Icu_IPW_Timestamp(GTM_ICU_CHANNEL(hwChannel), u8capturedWords,u16BufferPtr, \
                      overflow);
}
#endif


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_SignalMeasurement
* @details    This service is  called when an  interrupt is recognized  as a Signal  Measurement
*             type. There are two branch depending on  the sub-function selected: Duty Cycle or
*             OTHER. Duty Cycle requires  an extra  variable, because  three values  are required:
*             two flanks for active signal time and another flank for the end of the pulse. For
*             calculating high, low and period is enough with the HW registers.
*
* @param[in]      numChl - The index of ICU channel for current configuration structure
*
* @return void
*
*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Gtm_SignalMeasurement(
                                                            VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,\
                                                            VAR(boolean, AUTOMATIC) overflow)
{
    VAR(Icu_Gtm_SignalMeasurementPropertyType, AUTOMATIC) \
    MeasurementProperty = (Icu_Gtm_SignalMeasurementPropertyType)\
        (Icu_Gtm_GetChConfig(hwChannel,\
                                ICU_GTM_MEAS_PROPERTY_MASK) >> ICU_GTM_MEAS_PROPERTY_SHIFT);
    VAR(uint32,AUTOMATIC) u32ActivePulseWidth;
    VAR(uint32,AUTOMATIC) u32Period;

    if ((GTM_ICU_HIGH_TIME == MeasurementProperty) ||
                (GTM_ICU_LOW_TIME == MeasurementProperty) ||
                (GTM_ICU_ACTIVE_TIME == MeasurementProperty))
    {
        VAR(uint32, AUTOMATIC) u32LocalGPR1 = Icu_Gtm_GetGPR1(hwChannel);
        VAR(uint32, AUTOMATIC) u32LocalGPR0 = Icu_Gtm_GetGPR0(hwChannel);
        VAR(sint32, AUTOMATIC) temp_result = (sint32)u32LocalGPR1 - (sint32)u32LocalGPR0;
        if( temp_result > (sint32)0)
        {
            u32ActivePulseWidth = (Icu_ValueType)temp_result;
        }
        else
        {
            u32ActivePulseWidth = (Icu_ValueType)(u32LocalGPR0 - u32LocalGPR1);
        }
        Icu_IPW_SignalMeasurement(GTM_ICU_CHANNEL(hwChannel), u32ActivePulseWidth, (uint16)0,\
                          overflow);
    }

    else if (GTM_ICU_PERIOD_TIME == MeasurementProperty)
    {
        u32Period = (Icu_ValueType)Icu_Gtm_GetGPR1(hwChannel);
        Icu_IPW_SignalMeasurement(GTM_ICU_CHANNEL(hwChannel), (uint16)0, u32Period, overflow);
    }

    else if (GTM_ICU_DUTY_CYCLE == MeasurementProperty)
    {

        u32ActivePulseWidth = (Icu_ValueType)Icu_Gtm_GetGPR0(hwChannel);
        u32Period = (Icu_ValueType)Icu_Gtm_GetGPR1(hwChannel);
        Icu_IPW_SignalMeasurement(GTM_ICU_CHANNEL(hwChannel),\
                                 u32ActivePulseWidth, u32Period, overflow);
    }
    else
    {
        /* do nothing */
    }

}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief      Icu_Gtm_InitChannel
* @details    GTM function that initialize each GTM channel
*
* @param[in]      u32ParamValue  - contains the parameters to initialize the hardware channel
* @param[in]      channelMode - Chanel mode
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_InitChannel(CONST(uint32, AUTOMATIC) u32ParamValue,
                                          CONST(uint32, AUTOMATIC) u32IcuFilterParamRe,
                                          CONST(uint32, AUTOMATIC) u32IcuFilterParamFe,
                                          CONST(Icu_Gtm_ChannelMeasurementModeType, AUTOMATIC) ChannelMode,
                                          CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    VAR(uint32, AUTOMATIC) u32TimChannelCtrl = 0U;
    VAR(uint32, AUTOMATIC) u32TimChannelFilterRaramRe = 0U;
    VAR(uint32, AUTOMATIC) u32TimChannelFilterParamFe = 0U;

    VAR(Icu_ParamType, AUTOMATIC) TempConfigParam = (Icu_ParamType)0;
    VAR(Icu_Gtm_ChannelModeType, AUTOMATIC) HardwareMode = ICU_GTM_CHANNEL_TPWM_MODE;

    if ((GTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA == ChannelMode) || \
        (GTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA == ChannelMode))
    {
        TempConfigParam = u32ParamValue;
        HardwareMode = ICU_GTM_CHANNEL_TIEM_MODE;
    }
    else if ( (GTM_CHANNEL_MODE_EDGE_COUNTER == ChannelMode) || \
                                                (GTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT == ChannelMode))
    {
        /*Icu_Channel_Property == ICU_MODE_EDGE_COUNTER or Icu_Channel_Property == ICU_MODE_SIGNAL_EDGE_DETECT */
        TempConfigParam = u32ParamValue;
        /*erase the configured parameters*/
        TempConfigParam &= (~( ICU_GTM_TIM_GPR0_SEL_MASK_U32 | ICU_GTM_TIM_GPR1_SEL_MASK_U32));
        /*write default parameters*/
        TempConfigParam |= ((Icu_ParamType)CNTS_SOURCE << ICU_GTM_TIM_GPR0_SEL_SHIFT);
        TempConfigParam |= ((Icu_ParamType)CNT_SOURCE << ICU_GTM_TIM_GPR1_SEL_SHIFT);
        HardwareMode = ICU_GTM_CHANNEL_TIEM_MODE;
    }
    else
    {
        TempConfigParam = u32ParamValue;
        TempConfigParam &= (~(ICU_GTM_TIM_GPR0_SEL_MASK_U32 | ICU_GTM_TIM_GPR1_SEL_MASK_U32));
        TempConfigParam |= ((Icu_ParamType)CNTS_SOURCE << ICU_GTM_TIM_GPR0_SEL_SHIFT);
        TempConfigParam |= ((Icu_ParamType)CNT_SOURCE << ICU_GTM_TIM_GPR1_SEL_SHIFT);
    }

    /*write edge parameter*/
    u32TimChannelCtrl  = (uint32) (((TempConfigParam & ICU_EDGE_PARAM_MASK ) >> ICU_EDGE_PARAM_SHIFT ) << TIM_CTRL_DSL_SHIFT );
    /*write clock source parameter*/
    u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_CLK_SEL_MASK_U32 ) >> ICU_GTM_TIM_CLK_SEL_SHIFT ) << TIM_CTRL_CLK_SEL_SHIFT );
     /*write GPR0 source parameter*/
    u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_GPR0_SEL_MASK_U32 ) >> ICU_GTM_TIM_GPR0_SEL_SHIFT ) << TIM_CTRL_GPR0_SEL_SHIFT );
      /*write GPR1 source parameter*/
    u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_GPR1_SEL_MASK_U32 ) >> ICU_GTM_TIM_GPR1_SEL_SHIFT ) << TIM_CTRL_GPR1_SEL_SHIFT );
    if(u8ModuleIndex == 0u)
    {
         /*write TBU_TS0z parameter*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_TIME_BASE0_BITS_MASK_U32 ) \
                                        >> ICU_GTM_TIM_TIME_BASE0_BITS_SHIFT ) << TIM_CTRL_TBU0_SEL_SHIFT );
    }
    /*if input filter is enabled*/
    if(ICU_GTM_TIM_FILTER_ENABLE_MASK_U32 == (TempConfigParam & ICU_GTM_TIM_FILTER_ENABLE_MASK_U32))
    {
         /*write filter enable bit*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_FILTER_ENABLE_MASK_U32 ) >> \
                                    ICU_GTM_TIM_FILTER_ENABLE_SHIFT ) << TIM_CTRL_FLT_EN_SHIFT );
        /*write filter mode for falling edge*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_FILTER_MODE_FE_MASK_U32 ) >> \
                                    ICU_GTM_TIM_FILTER_MODE_FE_SHIFT ) << TIM_CTRL_FLT_MODE_FE_SHIFT );
        /*write filter counter mode for falling edge*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_FILTER_COUNTER_MODE_FE_MASK_U32 ) >> \
                                    ICU_GTM_TIM_FILTER_COUNTER_MODE_FE_SHIFT ) << TIM_CTRL_FLT_CTR_FE_SHIFT );
        /*write filter mode for rising edge*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_FILTER_MODE_RE_MASK_U32 ) >> \
                                    ICU_GTM_TIM_FILTER_MODE_RE_SHIFT ) << TIM_CTRL_FLT_MODE_RE_SHIFT );
        /*write filter counter mode for rising edge*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_FILTER_COUNTER_MODE_RE_MASK_U32 ) >> \
                                    ICU_GTM_TIM_FILTER_COUNTER_MODE_RE_SHIFT ) << TIM_CTRL_FLT_CTR_RE_SHIFT );
        /*write clock source bits*/
        u32TimChannelCtrl |= (uint32) (((TempConfigParam & ICU_GTM_TIM_FILTER_COUNTER_CLOCK_MASK_U32 ) >> \
                                    ICU_GTM_TIM_FILTER_COUNTER_CLOCK_SHIFT ) << TIM_CTRL_FLT_CNT_FRQ_SHIFT );
        /*write filter parameter for rising edge*/
        u32TimChannelFilterRaramRe = (uint32)(u32IcuFilterParamRe & ICU_GTM_TIM_FILTER_RINSING_EDGE_PARAM_MASK_U32 );
        /*write filter parameter for rising edge*/
        u32TimChannelFilterParamFe = (uint32)(u32IcuFilterParamFe & ICU_GTM_TIM_FILTER_FALLING_EDGE_PARAM_MASK_U32 );
    }
    /*Set the channel mode*/
    u32TimChannelCtrl |= ((uint32)HardwareMode << TIM_CTRL_MODE_SHIFT);
    /*Reset the GTM_TIM channel registers*/
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_RST_ADDR32(u8ModuleIndex) , (uint32)(TIM_RST_CHANNEL_U32 << u8ChannelIndex));

    /*Write channel filter parameters*/
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_FLT_RE_ADDR32(u8ModuleIndex, u8ChannelIndex) , u32TimChannelFilterRaramRe);
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_FLT_FE_ADDR32(u8ModuleIndex, u8ChannelIndex) , u32TimChannelFilterParamFe);

    /*Write channel config*/
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) ,u32TimChannelCtrl);

    Icu_Gtm_SetChConfig(hwChannel, ICU_GTM_CH_INITIALIZED_MASK);
}

/*================================================================================================*/
/**
* @brief      Icu_GTM_DeInit
* @details    GTM IP function that de-initialize an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
* @violates @ref Icu_Gtm_c_REF_6 All declarations and definitions of objects or functions at file
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_DeInitChannel(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    /*Reset the GTM_TIM channel registers*/
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_RST_ADDR32(u8ModuleIndex) , (uint32)(TIM_RST_CHANNEL_U32 << u8ChannelIndex));
    Icu_Gtm_ClearChConfig(hwChannel,
                             (Icu_Gtm_ChConfigType)(ICU_GTM_CH_INITIALIZED_MASK | \
                                                    ICU_GTM_MEAS_MODE_MASK | \
                                                    ICU_GTM_MEAS_PROPERTY_MASK));
}

#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_SetSleepMode
* @details
*
* @param[in]     hwChannel     - GTM encoded hardware channel
* @param[in]     WakeUpEnabled - specifies if channel is wake-up enabled
*
* @return void
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_SetSleepMode(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );
}

/*================================================================================================*/
/**
* @brief      Icu_Gtm_SetNormalMode
* @details
*
* @param[in]     hwChannel          - GTM encoded hardware channel
* @param[in]     NotificationActive - specifies if channel has notification activated
*
* @return void
*
* @violates  Warning Advisory Rule 16.10: If a function returns error information,
* then that error information shall be tested.
* This is not a violation since the function does not return error information.
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_SetNormalMode(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8,  AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8,  AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CH_IRQ_NOTIFY_NEWVAL_MASK_U32);

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/
/**
* @brief      Icu_Gtm_SetActivationCondition
* @details    GTM IP function that sets up the activation condition
*
* @param[in]      hwChannel   - GTM encoded hardware channel
* @param[in]      channelMode - GTM channel mode
* @param[in]      Activation  - edge activation type
*
* @return void
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_SetActivationCondition(
                                              CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                              CONST(Icu_ActivationType, AUTOMATIC) Activation)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);


    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_RMW32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex), (TIM_CTRL_DSL_MASK_U32 | TIM_CTRL_ISL_MASK_U32), \
                                                        ((uint32)Activation  << TIM_CTRL_DSL_SHIFT));

}


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_EnableEdgeDetection
* @details    GTM IP function that starts the edge detection service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_EnableEdgeDetection(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Clear previous flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CH_IRQ_NOTIFY_NEWVAL_MASK_U32);
    /* Enable Interrupt */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32);
    /* Enable Channel */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    /* Set config mode for channel */
    Icu_Gtm_SetChConfig(hwChannel, \
      (Icu_Gtm_ChConfigType)((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT\
                                                         << ICU_GTM_MEAS_MODE_SHIFT));
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_GTM_DisbleEdgeDetection
* @details    GTM IP function that starts the timestamp service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_DisableEdgeDetection(CONST(Icu_Gtm_ChannelType, AUTOMATIC)hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Disable Interrupt */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32);
    /* Disable Channel */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    /* Clear channel config mode*/
    Icu_Gtm_ClearChConfig(hwChannel, \
          (Icu_Gtm_ChConfigType)((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT\
                                                             << ICU_GTM_MEAS_MODE_SHIFT));
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_StartTimestamp
* @details    GTM IP function that stops the edge detection service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_StartTimestamp(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,\
                                                              CONST(boolean, AUTOMATIC) bDmaSupport)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Clear previous flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CH_IRQ_NOTIFY_NEWVAL_MASK_U32);
    /* Enable Interrupt */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32);


    /* Enable Channel */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    /* Check DMA support */
    if ((boolean)FALSE == bDmaSupport)
    {
        Icu_Gtm_SetChConfig(hwChannel,  (Icu_Gtm_ChConfigType)\
                            ((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA
                                                            << ICU_GTM_MEAS_MODE_SHIFT));
    }
}
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_StopTimestamp
* @details    GTM IP function that stop the timestamp service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_StopTimestamp(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Disable Channel - Channel Enable Register (ENBL) */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    /* Disable Interrupt */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32);

    /* Clear mode of channel */
    Icu_Gtm_ClearChConfig(hwChannel, (Icu_Gtm_ChConfigType)\
             (((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA | \
              (Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA) \
                                                  << ICU_GTM_MEAS_MODE_SHIFT));

}
#endif  /* ICU_TIMESTAMP_API */

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
/**
* @brief      Icu_Gtm_GetStartAddress
* @details    Gtm IP function that returns the source address for a Dma transfer
*
* @param[in]      hwChannel   - Gtm encoded hardware channel
*
* @return void
*
* */
FUNC(uint32, ICU_CODE) Icu_Gtm_GetStartAddress(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    return (GTM_TIM_GPR0_ADDR32(u8ModuleIndex, u8ChannelIndex));
}
#endif

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_ResetEdgeCount
* @details    GTM IP function that reset the edge counting for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_ResetEdgeCount(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    VAR(uint32, AUTOMATIC) u32Channel_state = (uint32)0;

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    u32Channel_state = REG_READ32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex));
    u32Channel_state &= TIM_CTRL_EN_MASK_U32 ;

    /* Reset Counter Register (CNT) */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    /* Check status of channel before call Icu_Gtm_ResetEdgeCount*/
    if((uint32)0 == u32Channel_state )
    {
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );
    }
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_EnableEdgeCount
* @details    GTM IP function that starts the edge counting service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_EnableEdgeCount(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Enable GTM_TIM Channel */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        /* Reset CNT Overflow flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32);
        /* Set CNT Overflow Interrupt Enable */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_CNTOF_IRQ_EN_MASK_U32);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    /* Set chConfig for channel */
    Icu_Gtm_SetChConfig(hwChannel,\
                (Icu_Gtm_ChConfigType)((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_EDGE_COUNTER\
                                                                   << ICU_GTM_MEAS_MODE_SHIFT));
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_DisableEdgeCount
* @details    GTM IP function that disable the edge counting service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*
*/
/*================================================================================================*/

FUNC (void, ICU_CODE) Icu_Gtm_DisableEdgeCount(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Disable GTM_TIM Channel */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
     REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );
#if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        /* Reset CNT Overflow flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32);
    /* Reset CNT Overflow Interrupt Enable */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_CNTOF_IRQ_EN_MASK_U32);
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */

    /* Clear config channel config */
    Icu_Gtm_ClearChConfig(hwChannel,
                (Icu_Gtm_ChConfigType)((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_EDGE_COUNTER\
                                                                   << ICU_GTM_MEAS_MODE_SHIFT));
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_GetEdgeNumbers
* @details    GTM IP function that get the edge numbers
*
* @param[in]   hwChannel   - GTM encoded hardware channel
*
* @return      Counted edges number
*
*/
/*================================================================================================*/
FUNC (uint32, ICU_CODE) Icu_Gtm_GetEdgeNumbers(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    VAR(uint32, AUTOMATIC) u32ValGtmTIMCNT;

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    u32ValGtmTIMCNT = (uint32)(TIM_GPR1_GPR1_MASK_U32 & REG_READ32(GTM_TIM_GPR1_ADDR32(u8ModuleIndex, u8ChannelIndex)));

    return u32ValGtmTIMCNT;
}
#endif  /* ICU_EDGE_COUNT_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_StartSignalMeasurement
* @details    GTM IP function that start the signal measurement for an GTM channel
*
* @param[in]     hwChannel  - GTM encoded hardware channel
* @param[in]     Activation - edge activation type
* @param[in]     tempProperty - property of signal measurement
*
* @return void
*
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Gtm_StartSignalMeasurement(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel,
                                                    CONST(Icu_Gtm_ActivationType, AUTOMATIC)Activation,
                                                    CONST(Icu_Gtm_SignalMeasurementPropertyType, AUTOMATIC)MeasProperty)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    VAR(Icu_Gtm_ChannelModeType, AUTOMATIC) ChannelMode;

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    volatile VAR(uint32, AUTOMATIC) u32TimChannelCtrl = REG_READ32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex));

    /* Clear DSL for GTM channel */
    u32TimChannelCtrl &= ~TIM_CTRL_DSL_MASK_U32;

    if( (ICU_HIGH_TIME == MeasProperty ) || (ICU_LOW_TIME == MeasProperty ) || (ICU_ACTIVE_TIME == MeasProperty))
    {
        ChannelMode = ICU_GTM_CHANNEL_TPIM_MODE;
    }
    else
    {
        /*else Icu_Channel_Property == ICU_PERIOD_TIME or Icu_Channel_Property == ICU_DUTY_CYCLE */
        ChannelMode = ICU_GTM_CHANNEL_TPWM_MODE;
    }


    /* Set activation measurement for channel */
    if(GTM_RISING_EDGE == Activation)
    {
        u32TimChannelCtrl |= (((uint32)GTM_RISING_EDGE)  << TIM_CTRL_DSL_SHIFT);
    }
    else if(GTM_FALLING_EDGE == Activation)
    {
        u32TimChannelCtrl |= (((uint32)GTM_FALLING_EDGE) << TIM_CTRL_DSL_SHIFT);
    }
    else
    {
        /* For Misra complicate */
    }


    /* Clear value channel mode*/
    u32TimChannelCtrl &= ~TIM_CTRL_MODE_MASK_U32;
    /* Set mode for hardware channel*/
    u32TimChannelCtrl |= (((uint32)ChannelMode << TIM_CTRL_MODE_SHIFT));
    /* Set mode, DSL for TIM_CTRL channel*/
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) ,u32TimChannelCtrl);

        /* Clear previous flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CH_IRQ_NOTIFY_NEWVAL_MASK_U32);

        /* Enable Interrupt */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_SET32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32);

    #if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        /* Reset CNT Overflow flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32);

        /* Set Timer Overflow Interrupt Enable */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_BIT_SET32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_CNTOF_IRQ_EN_MASK_U32);
    #endif  /* ICU_OVERFLOW_NOTIFICATION_API */

        /* Enable Channel  */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_BIT_SET32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    /* Set channel config for hwChannel*/
    Icu_Gtm_SetChConfig(hwChannel,\
        (Icu_Gtm_ChConfigType)((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_SIGNAL_MEASUREMENT<<\
                                                           ICU_GTM_MEAS_MODE_SHIFT) |\
        (Icu_Gtm_ChConfigType)((Icu_Gtm_ChConfigType)MeasProperty <<\
                                                           ICU_GTM_MEAS_PROPERTY_SHIFT));
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */



#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_GetInputState
* @details    GTM IP function that gets the input state for a channel
*
* @param[in]  hwChannel   - GTM encoded hardware channel
*
* @return     boolean      The active/inactive state:
* @retval     true          channel is active
* @retval     false         channel is idle
*
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_Gtm_GetInputState(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    /* Interrupt not enabled, flag bit was set */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    if (TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32 != \
            (REG_BIT_GET32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex),TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32)))
    {
        VAR(uint32, AUTOMATIC) u32RegTIMIRQNOTIFY;

        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        u32RegTIMIRQNOTIFY = REG_READ32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex));
        /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_WRITE32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CH_IRQ_NOTIFY_NEWVAL_MASK_U32);

        if ((u32RegTIMIRQNOTIFY & TIM_CH_IRQ_NOTIFY_NEWVAL_MASK_U32 ) != (uint32)0x0U)
        {
            bResult = (boolean)TRUE;
        }
    }
    return bResult;
}
#endif  /* ICU_GET_INPUT_STATE_API */


#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_Gtm_StopSignalMeasurement
* @details    GTM function that stops the signal measurement service for an GTM channel
*
* @param[in]      hwChannel   - GTM encoded hardware channel
*
* @return void
*
*/
/*================================================================================================*/

FUNC (void, ICU_CODE) Icu_Gtm_StopSignalMeasurement(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

         /* Disable Channel  */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) , TIM_CTRL_EN_MASK_U32 );

    #if defined(ICU_OVERFLOW_NOTIFICATION_API) && (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        /* Reset CNT Overflow flag */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
        REG_BIT_SET32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32);
        /* Disable Overflow Interrupt Enable */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_CNTOF_IRQ_EN_MASK_U32);
    #endif  /* ICU_OVERFLOW_NOTIFICATION_API */
        /* Disable Interrupt */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_BIT_CLEAR32(GTM_TIM_IRQ_EN_ADDR32(u8ModuleIndex, u8ChannelIndex) ,TIM_IRQ_ENABLE_NEWVAL_IRQ_EN_MASK_U32);

    Icu_Gtm_ClearChConfig(hwChannel,(Icu_Gtm_ChConfigType)\
                ((Icu_Gtm_ChConfigType)GTM_CHANNEL_MODE_SIGNAL_MEASUREMENT << \
                                          ICU_GTM_MEAS_MODE_SHIFT) \
                                          | ICU_GTM_MEAS_PROPERTY_MASK);

}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */
/*================================================================================================*/
/**
* @brief      Icu_Gtm_GetOverflow
* @details    GTM IP function that get the state of the overflow flag
*
* @param[in]   hwChannel   - GTM encoded hardware channel
*
* @return      boolean      the state of the overflow flag
* @retval      true         the overflow flag is set
* @retval      false        the overflow flag is not set
*
* @return void
* @violates @ref Icu_Gtm_c_REF_6 All declarations and definitions of objects or functions at file
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_Gtm_GetOverflow(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) u32RegIRQNOTIFY;

    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    u32RegIRQNOTIFY = REG_READ32(GTM_TIM_IRQ_NOTIFY_ADDR32(u8ModuleIndex, u8ChannelIndex));
    bResult = ((u32RegIRQNOTIFY & TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32) == \
                            TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32) ? (boolean)TRUE : (boolean)FALSE;

    return bResult;
}

/**
* @brief      Icu_Gtm_GetGPR0
* @details    GTM_TIM IP function that gets the information saved in GPR0 register
*
* @param[in]  hwChannel  - GTM_TIM encoded hardware channel
*
* @return     Values of the GPR0 capture register
*
* @violates @ref Icu_Gtm_c_REF_6 All declarations and definitions of objects or functions at file
*/
/*================================================================================================*/
FUNC(uint32, ICU_CODE) Icu_Gtm_GetGPR0(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    VAR(uint32, AUTOMATIC) u32RegValGPG0 = (uint32)(REG_READ32(GTM_TIM_GPR0_ADDR32(u8ModuleIndex, u8ChannelIndex)));
    
#ifdef  ERR_IPV_GTM_0002
    #if (ERR_IPV_GTM_0002  == STD_ON)
    if((BIT24 == (u32RegValGPG0 & BIT24)) && (BIT0 != (u32RegValGPG0 & BIT0)))
    {
        u32RegValGPG0 = u32RegValGPG0 - (uint32)1U;
    }
    #endif
#endif
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    return (uint32)(TIM_GPR0_GPR0_MASK_U32 & u32RegValGPG0);
}

/**
* @brief      Icu_Gtm_GetGPR1
* @details    GTM_TIM IP function that gets the information saved in GPR1 register
*
* @param[in]  hwChannel  - GTM_TIM encoded hardware channel
*
* @return     Values of the GPR1 capture register
* @violates @ref Icu_Gtm_c_REF_6 All declarations and definitions of objects or functions at file
*/
/*================================================================================================*/
FUNC(uint32, ICU_CODE) Icu_Gtm_GetGPR1(VAR(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    VAR(uint32, AUTOMATIC) u32RegValGPG1 = (uint32)(REG_READ32(GTM_TIM_GPR1_ADDR32(u8ModuleIndex, u8ChannelIndex)));

#ifdef  ERR_IPV_GTM_0002
    #if (ERR_IPV_GTM_0002  == STD_ON)
    if((BIT24 == (u32RegValGPG1 & BIT24)) && (BIT0 != (u32RegValGPG1 & BIT0)))
    {
        u32RegValGPG1 = u32RegValGPG1 - (uint32)1U;
    }
    #endif
#endif    
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    return (uint32)(TIM_GPR1_GPR1_MASK_U32 & u32RegValGPG1);
}

/**
* @brief      Icu_Gtm_ProcessInterrupt
* @details    Process the common part for GTM interrupts
*
* @param[in]      hwChannel - GTM hardware channel
*
* @return void
*
* @implements Icu_Gtm_ProcessInterrupt_Activity
* @violates @ref Icu_Gtm_c_REF_6 All declarations and definitions of...
* @violates @ref Icu_Gtm_c_REF_7  Functions shall have prototype declarations
*
* */
FUNC(void, ICU_CODE) Icu_Gtm_ProcessInterrupt(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel){
    VAR(uint32, AUTOMATIC) u32GTM_StatusFlags = (uint32)0x0000U;
    VAR(Icu_Gtm_ChannelMeasurementModeType, AUTOMATIC) measMode;

    VAR(boolean, AUTOMATIC) bOverflow;
    /* Read Channel Status Registers */
    u32GTM_StatusFlags = Icu_Gtm_GetStatusFlags(ICU_GTM_CHANNEL(hwChannel));


    /* Process interrupt for ICU logical channel */
    if (Icu_Gtm_GetChConfig(hwChannel, ICU_GTM_CH_INITIALIZED_MASK) == \
                                          ICU_GTM_CH_INITIALIZED_MASK)
    {
        /* Check GTM flags */
        if ((uint32)0 != u32GTM_StatusFlags)
        {
            bOverflow = ((u32GTM_StatusFlags & TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32) == \
                            TIM_CH_IRQ_NOTIFY_CNTOF_MASK_U32) ? (boolean)TRUE : (boolean)FALSE;
            measMode = (Icu_Gtm_ChannelMeasurementModeType)\
                    (Icu_Gtm_GetChConfig(hwChannel,ICU_GTM_MEAS_MODE_MASK) >> \
                                              ICU_GTM_MEAS_MODE_SHIFT);
            /* Verify configuration of channel and make the right processing */
            switch (measMode)
            {
    #if (ICU_EDGE_DETECT_API == STD_ON)
                case GTM_CHANNEL_MODE_SIGNAL_EDGE_DETECT:
                    Icu_IPW_ReportEvents(ICU_GTM_CHANNEL(hwChannel),bOverflow);
                    break;
    #endif  /* ICU_EDGE_DETECT_API */

    #if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
                case GTM_CHANNEL_MODE_SIGNAL_MEASUREMENT:
                    Icu_Gtm_SignalMeasurement(hwChannel,bOverflow);
                    break;
    #endif  /* ICU_SIGNAL_MEASUREMENT_API */

    #if (ICU_TIMESTAMP_API == STD_ON)
                case GTM_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA:
                    Icu_Gtm_Timestamp(hwChannel,bOverflow);
                    break;
    #if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                case GTM_CHANNEL_MODE_TIMESTAMP_WITH_DMA:
                    Icu_IPW_ReportWakeupAndOverflow(GTM_ICU_CHANNEL(hwChannel), bOverflow);
                    break;
    #endif
    #endif /* ICU_TIMESTAMP_API == STD_ON */
                    default:
    #if (ICU_EDGE_COUNT_API == STD_ON)
                    Icu_IPW_ReportWakeupAndOverflow(ICU_GTM_CHANNEL(hwChannel), bOverflow);
    #endif
                    break;
            }
        }
    }

    /* Clear pending interrupt serviced*/
    Icu_Gtm_ClearStatusFlags(ICU_GTM_CHANNEL(hwChannel), (uint32)0x0000003F);
}

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief      This function returns the actual status of PIN.
* @details     This function returns the actual status of PIN.
*
* @param[in]     hwChannel          Numeric identifier of the GTM channel
*
* @return      Icu_LevelType    the state of the GTM pin
* @retval      true             the pin state is HIGH
* @retval      false            the pin state is LOW
*
* */
FUNC (Icu_LevelType, ICU_CODE) Icu_Gtm_GetInputLevel(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    return (Icu_LevelType)((REG_READ32(GTM_TIM_GPR0_ADDR32(u8ModuleIndex, u8ChannelIndex)) >> TIM_GPR0_ECNT_SHIFT) & BIT0);
}
#endif /* ICU_GET_INPUT_LEVEL_API */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/**
* @brief      The function changes clock source of Gtm Channel.
* @details This function:
*          - Writes a new clock source in the CLK_SEL field in TIM_CTRL register
*
* @param[in]     hwChannel        Gtm hw channel ID
* @param[in]     u32chClkSrcMode     value of clock source
*
*
*/
FUNC(void, ICU_CODE) Icu_Gtm_SetPrescaler(CONST(Icu_Gtm_ChannelType, AUTOMATIC) hwChannel, \
                                             VAR(uint32, AUTOMATIC) u32chClkSrcMode)
{
    CONST(uint8, AUTOMATIC) u8ModuleIndex  = (uint8)GTM_TIM_MODULE_INDEX_U8(hwChannel);
    CONST(uint8, AUTOMATIC) u8ChannelIndex = (uint8)GTM_TIM_CHANNEL_INDEX_U8(hwChannel);

    VAR(uint32, AUTOMATIC) u32TimChannelCtrl = 0U;

    /* Read value of CTRL register */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    u32TimChannelCtrl = REG_READ32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex));

    /* Clear value of clock source select before write a new value */
    u32TimChannelCtrl = u32TimChannelCtrl & (uint32)(~(TIM_CTRL_CLK_SEL_MASK_U32));

    /* Set new value of clock source */
    u32TimChannelCtrl |= (uint32)((uint32)u32chClkSrcMode << TIM_CTRL_CLK_SEL_SHIFT);

    /* Write new value into control register */
    /**@violates @ref Icu_Gtm_c_REF_4 Conversions shall not be performed between a pointer to...*/
    REG_WRITE32(GTM_TIM_CTRL_ADDR32(u8ModuleIndex, u8ChannelIndex) ,u32TimChannelCtrl);

}
#endif  /* ICU_DUAL_CLOCK_MODE_API */


#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_Gtm_c_REF_1  MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*        "#include".
* @violates @ref Icu_Gtm_c_REF_2  MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents of a header file
*        being included twice.
*/
#include "MemMap.h"

#ifdef __cplusplus
}

#endif
/** @} */
