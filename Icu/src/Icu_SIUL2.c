/**
*     @file            Icu_SIUL2.c
*     @implements    Icu_SIUL2_unit
*     @version 1.1.0
* 
*     @brief   AUTOSAR Icu - SIUL source file support for ICU driver.
*     @details SIUL source file, containing the variables and functions that are exported by the SIUL driver.
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
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_SIUL2_c_REF_1
*         Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
*         '#include'
*         This is an Autosar requirement about the memory management (Autosar requirement MEMMAP003)
* 
* @section Icu_SIUL2_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15,Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* 
* 
* @section Icu_SIUL2_c_REF_3
*         Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*         that 31 character significance and case sensitivity are supported for external identifiers
*         The defines are validated.
* 
* @section Icu_SIUL2_c_REF_4
*         Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*         pointer to a function and a type other than an integral type. This violation is due to the
*         pointer arithmetic used to write/ read the data to/from the registers
*
* @section Icu_SIUL2_c_REF_5
*         Violates MISRA 2004 Required Rule 8.10, external ... could be made static
*         The respective code could not be made static because of layers architecture design of the driver.
*
* @section [global]
*         Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall 
*         not rely on the significance of more than 31 characters.
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
#include "Mcal.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Icu_Reg_eSys_SIUL2.h"
#include "Icu_SIUL2.h"

#include "Icu_IPW_Types.h"


/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define ICU_SIUL2_VENDOR_ID_C                    43
/** @violates @ref Icu_SIUL2_c_REF_3 MISRA 2004 Rule 1.4, Identifier clash */
#define ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref Icu_SIUL2_c_REF_3 MISRA 2004 Rule 1.4, Identifier clash */
#define ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C     0
/** @violates @ref Icu_SIUL2_c_REF_3 MISRA 2004 Rule 1.4, Identifier clash */
#define ICU_SIUL2_AR_RELEASE_REVISION_VERSION_C  3
#define ICU_SIUL2_SW_MAJOR_VERSION_C             1
#define ICU_SIUL2_SW_MINOR_VERSION_C             1
#define ICU_SIUL2_SW_PATCH_VERSION_C             0


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Siul2.c and Mcal.h are different"
    #endif
#endif


#if (ICU_SIUL2_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Siul2.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_SIUL2_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Siul2.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_SIUL2_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_SIUL2_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_SIUL2_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_Siul2.c are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Siul2.c and SilRegMacros.h are different"
    #endif
#endif



/* Check if source file and Icu_Reg_eSys_SIUL2.h file are of the same vendor */
#if (ICU_SIUL2_VENDOR_ID_C != ICU_REGESYS_SIUL2_VENDOR_ID)
#error "Icu_SIUL2.c and Icu_Reg_eSys_SIUL2.h have different vendor IDs"
#endif
#if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != ICU_REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C != ICU_REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL2_AR_RELEASE_REVISION_VERSION_C != ICU_REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_SIUL2.c and Icu_Reg_eSys_SIUL2.h are different"
#endif
/* Check if source file and Icu_Reg_eSys_SIUL2.h header file are of the same Software version */
#if ((ICU_SIUL2_SW_MAJOR_VERSION_C != ICU_REGESYS_SIUL2_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_SW_MINOR_VERSION_C != ICU_REGESYS_SIUL2_SW_MINOR_VERSION) || \
     (ICU_SIUL2_SW_PATCH_VERSION_C != ICU_REGESYS_SIUL2_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_SIUL2.c and Icu_Reg_eSys_SIUL2.h are different"
#endif


/* Check if source file and Icu_SIUL2.h file are of the same vendor */
#if (ICU_SIUL2_VENDOR_ID_C != ICU_SIUL2_VENDOR_ID)
#error "Icu_SIUL2.c and Icu_SIUL2.h have different vendor IDs"
#endif
    #if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != ICU_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C != ICU_SIUL2_AR_RELEASE_MINOR_VERSION) || \
         (ICU_SIUL2_AR_RELEASE_REVISION_VERSION_C != ICU_SIUL2_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_SIUL2.c and Icu_SIUL2.h are different"
    #endif
/* Check if source file and Icu_SIUL2.h header file are of the same Software version */

#if ((ICU_SIUL2_SW_MAJOR_VERSION_C != ICU_SIUL2_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_SW_MINOR_VERSION_C != ICU_SIUL2_SW_MINOR_VERSION) || \
     (ICU_SIUL2_SW_PATCH_VERSION_C != ICU_SIUL2_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_SIUL2.c and Icu_SIUL2.h are different"
#endif



#if (ICU_SIUL2_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_SIUL2.c and Icu_IPW_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_IPW_Types header file are of the same Autosar version */
#if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL2_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL2_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_SIUL2.c and Icu_IPW_Types.h are different"
#endif
/* Check if source file and Icu_IPW_Types header file are of the same Software version */
#if ((ICU_SIUL2_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_SIUL2_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_SIUL2.c and Icu_IPW_Types.h are different"
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
#define ICU_START_SEC_VAR_INIT_32
/**
* @violates @ref Icu_SIUL2_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*           contents of a header file being included twice
*/
#include "MemMap.h"

STATIC VAR(uint32, ICU_VAR) Icu_Siul2_u32ChInit = (uint32)0;

#define ICU_STOP_SEC_VAR_INIT_32
/**
* @violates @ref Icu_SIUL2_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_SIUL2_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "MemMap.h"

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
* @violates @ref Icu_SIUL2_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*               comments before "#include"
* @violates @ref Icu_SIUL2_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*               contents of a header file being included twice
*/
#include "MemMap.h"

#if ((ICU_SET_MODE_API == STD_ON) ||(ICU_EDGE_DETECT_API == STD_ON))
/*================================================================================================*/
/**
* @brief      Icu driver function that enables the interrupt of SIUL channel
* @details    This function enables SIUL Channel Interrupt
* 
* @param[in]  u32ChannelMask - Channel's Bit Mask
* 
* @return void
* 
* */
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_SIUL2_EnableInterrupt(VAR(uint32, AUTOMATIC) u32ChannelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13();
    {
        /* Clear pending flag */
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
        * to pointer.*/
        REG_WRITE32(SIUL2_DISR0_ADDR32, u32ChannelMask);

        /* Enable interrupt */
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_BIT_SET32(SIUL2_DIRER0_LOCKABLE_ADDR32, u32ChannelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13();
}
#endif
/*================================================================================================*/
/**
* @brief      Icu driver function that disables the interrupt of SIUL channel
* @details    This function disables SIUL Channel Interrupt
* 
* @param[in]  u32ChannelMask - Channel's Bit Mask
* 
* @return void
* 
* */
/*================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_SIUL2_DisableInterrupt(VAR(uint32, AUTOMATIC) u32ChannelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14();
    {
        /* Clear pending flag */
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_WRITE32(SIUL2_DISR0_ADDR32, u32ChannelMask);

        /* Disable interrupt */
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_BIT_CLEAR32(SIUL2_DIRER0_LOCKABLE_ADDR32, u32ChannelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14();
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if ((defined ICU_IRQ_CH_0_ISR_USED)  || (defined ICU_IRQ_CH_1_ISR_USED) \
    || (defined ICU_IRQ_CH_2_ISR_USED) || (defined ICU_IRQ_CH_3_ISR_USED) \
    || (defined ICU_IRQ_CH_4_ISR_USED) || (defined ICU_IRQ_CH_5_ISR_USED) \
    || (defined ICU_IRQ_CH_6_ISR_USED) || (defined ICU_IRQ_CH_7_ISR_USED) \
    || (defined ICU_IRQ_CH_8_ISR_USED) || (defined ICU_IRQ_CH_9_ISR_USED) \
    || (defined ICU_IRQ_CH_10_ISR_USED) || (defined ICU_IRQ_CH_11_ISR_USED) \
    || (defined ICU_IRQ_CH_12_ISR_USED) || (defined ICU_IRQ_CH_13_ISR_USED) \
    || (defined ICU_IRQ_CH_14_ISR_USED) || (defined ICU_IRQ_CH_15_ISR_USED) \
    || (defined ICU_IRQ_CH_16_ISR_USED) || (defined ICU_IRQ_CH_17_ISR_USED) \
    || (defined ICU_IRQ_CH_18_ISR_USED) || (defined ICU_IRQ_CH_19_ISR_USED) \
    || (defined ICU_IRQ_CH_20_ISR_USED) || (defined ICU_IRQ_CH_21_ISR_USED) \
    || (defined ICU_IRQ_CH_22_ISR_USED) || (defined ICU_IRQ_CH_23_ISR_USED) \
    || (defined ICU_IRQ_CH_24_ISR_USED) || (defined ICU_IRQ_CH_25_ISR_USED) \
    || (defined ICU_IRQ_CH_26_ISR_USED) || (defined ICU_IRQ_CH_27_ISR_USED) \
    || (defined ICU_IRQ_CH_28_ISR_USED) || (defined ICU_IRQ_CH_29_ISR_USED) \
    || (defined ICU_IRQ_CH_30_ISR_USED) || (defined ICU_IRQ_CH_31_ISR_USED) \
    || (defined ICU_IRQ_SINGLE_INTERRUPT))

/**
* @brief      Icu_Siul2_GetChInit
* @details    Returns if the current channel was initialized or not
*
* @param[in]      Channel  - The index of ICU channel for current configuration structure
*
* @return         Channel state initialization
* @retval         TRUE  channel was initialized
* @retval         FALSE channel was not initialized
* @violates @ref Icu_SIUL2_c_REF_5 external ... could be made static
*/
FUNC(boolean, ICU_CODE) Icu_Siul2_GetChInit(CONST(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    return ((Icu_Siul2_u32ChInit  & (BIT0 << hwChannel)) == (BIT0 << hwChannel)) ? \
                                           (boolean)TRUE : (boolean)FALSE;
}
#endif
/**
* @brief      Driver function that initializes SIUL hardware channel.
* @details    This function:
*              - Disables interrupt.
*              - Sets Interrupt filter enable register
*              - Sets Interrupt Filter Clock Prescaler Register
*              - Sets Activation Condition
* 
* @param[in]  ParamValue IRQ Param value
* @param[in]  hwChannel IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_InitChannel(CONST(Icu_Siul2_ParamType, AUTOMATIC) ParamValue,
                                            CONST(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel
                                           )
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    /* Disable IRQ Interrupt */
    Icu_SIUL2_DisableInterrupt(u32ChannelMask);

    /* Set Interrupt Filter Enable Register */
    if (SIUL2_INT_FILTER_ENABLE == ((ParamValue & ICU_SIUL2_INT_FILTER_ENABLE_PARAM_MASK) >> \
                                    ICU_SIUL2_INT_FILTER_ENABLE_PARAM_SHIFT
                                   )
       )
    {
        /* Set Interrupt Filter Clock Prescaler Register */
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_WRITE32(SIUL2_IFMCR_LOCKABLE_ADDR32((uint32)((uint32)hwChannel << (uint32)2U)),\
                    (ParamValue & ICU_SIUL2_INT_FILTER_COUNTER_PARAM_MASK) >> \
                    ICU_SIUL2_INT_FILTER_COUNTER_PARAM_SHIFT \
                   );

        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_BIT_SET32(SIUL2_IFER0_LOCKABLE_ADDR32, u32ChannelMask);
    }
    else
    {
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_BIT_CLEAR32(SIUL2_IFER0_LOCKABLE_ADDR32, u32ChannelMask);
    }


    /* Set Activation Condition */
    Icu_SIUL2_SetActivationCondition
            (hwChannel, (Icu_Siul2_ActivationType)
                ((ParamValue & ICU_EDGE_PARAM_MASK) >> ICU_EDGE_PARAM_SHIFT)
            );

    Icu_Siul2_u32ChInit |= (uint32) (BIT0 << hwChannel);
}

/**
* @brief      Driver function that initializes global configuration for SIUL2 IP.
* @details    This function:
*              - Sets Interrupt Filter Clock Prescaler Register
*
* @param[in]  ParamValue IRQ Param value
* @param[in]  hwChannel IRQ HW Channel
*
* @return void
*
* */
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_SIUL2_GlobalConfigurationSetUp(CONST(uint8, AUTOMATIC) prescaler)
{
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    REG_WRITE32(SIUL2_IFCPR_LOCKABLE_ADDR32, prescaler);
}
#if (ICU_DE_INIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that de-initializes SIUL hardware channel.
* @details    This function:
*              - Disables interrupt.
*              - Clears edge event enable registers
*              - Clears Interrupt Filter Enable Register
*              - Clears Interrupt Filter Clock Prescaler Register
* 
* @param[in]  hwChannel   - IRQ HW Channel
* 
* @return void
* 
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_DeInitChannel(VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    /* Disable IRQ Interrupt */
    Icu_SIUL2_DisableInterrupt(u32ChannelMask);

    /* Clear edge event enable registers */
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    REG_BIT_CLEAR32(SIUL2_IREER0_LOCKABLE_ADDR32, u32ChannelMask);
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    REG_BIT_CLEAR32(SIUL2_IFEER0_LOCKABLE_ADDR32, u32ChannelMask);

    /* Clear Interrupt Filter Enable Register */
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    REG_BIT_CLEAR32(SIUL2_IFER0_LOCKABLE_ADDR32, u32ChannelMask);

    /* Clear Interrupt Filter Clock Prescaler Register */
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    REG_WRITE32(SIUL2_IFMCR_LOCKABLE_ADDR32((uint32)((uint32)hwChannel << 2U)), 0x00U);
    Icu_Siul2_u32ChInit &= (uint32)(~(BIT0 << hwChannel));
}
#endif


#if (ICU_SET_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Driver function that sets SIUL hardware channel into SLEEP mode.
* @details    This function enables the interrupt if wakeup is enabled for corresponding SIUL channel
* 
* @param[in]  hwChannel       - IRQ HW Channel
* @param[in]  WakeUpEnabled   - channel wakeup feature is enabled
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_SetSleepMode(VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    /* Disable IRQ Interrupt */
    Icu_SIUL2_DisableInterrupt(u32ChannelMask);
}

/*================================================================================================*/
/**
* @brief      Driver function that sets SIUL hardware channel into NORMAL mode.
* @details    This function enables the interrupt if Notification is enabled for corresponding
*             SIUL channel
* 
* @param[in]  hwChannel           - IRQ HW Channel
* @param[in]  NotificationActive  - channel notification is activated
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_SetNormalMode(VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    /* Enable IRQ Interrupt */
    Icu_SIUL2_EnableInterrupt(u32ChannelMask);
}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/
/**
* @brief      Driver function that sets activation condition of SIUL channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding SIUL channels.
* 
* @param[in]  hwChannel -  Hardware channel
* @param[in]  Activation - Activation condition
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_SetActivationCondition
                                               (VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel,
                                                VAR(Icu_Siul2_ActivationType, AUTOMATIC) Activation
                                               )
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    switch (Activation)
    {
        case SIUL2_RISING_EDGE:
        {
            /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned
             * long to pointer.*/
            REG_BIT_SET32(SIUL2_IREER0_LOCKABLE_ADDR32, u32ChannelMask);
            /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned
             * long to pointer.*/
            REG_BIT_CLEAR32(SIUL2_IFEER0_LOCKABLE_ADDR32, u32ChannelMask);
        }
        break;

        case SIUL2_FALLING_EDGE:
        {
            /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned
             * long to pointer.*/
            REG_BIT_CLEAR32(SIUL2_IREER0_LOCKABLE_ADDR32, u32ChannelMask);
            /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned
             * long to pointer.*/
            REG_BIT_SET32(SIUL2_IFEER0_LOCKABLE_ADDR32, u32ChannelMask);
        }
        break;

        default:
        {
            /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned
             * long to pointer.*/
            REG_BIT_SET32(SIUL2_IREER0_LOCKABLE_ADDR32, u32ChannelMask);
            /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned
             * long to pointer.*/
            REG_BIT_SET32(SIUL2_IFEER0_LOCKABLE_ADDR32, u32ChannelMask);
        }
        break;
    }
}



#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_SIUL2_EnableEdgeDetection
* @details    This function enables the interrupt corresponding to the SIUL channel.
* 
* @param[in]  hwChannel - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_EnableEdgeDetection(VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    /* Enable IRQ Interrupt */
    Icu_SIUL2_EnableInterrupt(u32ChannelMask);
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_SIUL2_DisableEdgeDetection
* @details    This function disables the interrupt corresponding to the SIUL channel.
* 
* @param[in]  hwChannel - IRQ HW Channel
* 
* @return void
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_DisableEdgeDetection(VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    CONST(uint32, AUTOMATIC) u32ChannelMask = SIUL2_CHANNEL_MASK_U32((uint32)hwChannel);

    /* Disable IRQ Interrupt */
    Icu_SIUL2_DisableInterrupt(u32ChannelMask);
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_INPUT_STATE_API == STD_ON)

FUNC (boolean, ICU_CODE) Icu_SIUL2_GetInputState(VAR(Icu_Siul2_ChannelType, AUTOMATIC) hwChannel)
{
    VAR(uint32, AUTOMATIC) u32RegSiul2DISR;
    VAR(boolean,AUTOMATIC) bStatus = (boolean)FALSE;
    CONST(uint32, AUTOMATIC) u32ChannelMask = (uint32)(BIT0 << hwChannel);
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    CONST(uint32, AUTOMATIC) u32RegSiul2DIRER = \
                            REG_BIT_GET32(SIUL2_DIRER0_LOCKABLE_ADDR32, u32ChannelMask);

    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    u32RegSiul2DISR = REG_BIT_GET32(SIUL2_DISR0_ADDR32, u32ChannelMask);

    /* Interrupt condition activated (ISR), interrupt not enabled (IRER) */
    if ((0x0U !=  u32RegSiul2DISR) && (0x0U == u32RegSiul2DIRER))
    {
        /* Clear IRQ Flag */
        /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
         * to pointer.*/
        REG_WRITE32(SIUL2_DISR0_ADDR32, u32ChannelMask);

        bStatus = (boolean)TRUE;
    }

    return bStatus;
}
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)

/*================================================================================================*/
/**
* @brief      Icu driver function sets the global prescaler of a siul2 module
* @details    This function:
*             - Sets IFCPR register with a prescaler value
* 
* @param[in]  Prescaler - Global prescaler for the siul2 module
* 
* */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_SIUL2_SelectGlobalPrescaler(CONST(Icu_Siul2_ParamType, AUTOMATIC) Prescaler)
{
    /* Set Interrupt Filter Clock Prescaler Register */
    /* @violates @ref Icu_SIUL2_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long
     * to pointer.*/
    REG_WRITE32(SIUL2_IFCPR_LOCKABLE_ADDR32, Prescaler);
}
#endif /*ICU_DUAL_CLOCK_MODE_API*/

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_SIUL2_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
*                comments before "#include"
* @violates @ref Icu_SIUL2_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*                contents of a header file being included twice
*/
#include "MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

