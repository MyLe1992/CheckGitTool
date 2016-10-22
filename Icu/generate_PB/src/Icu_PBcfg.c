[!CODE!][!//
[!AUTOSPACING!]
/**
 *   @file         Icu_PBCfg.c
 *   @implements Icu_PBCfg.c_Artifact
 *   @version 1.1.0
 *
 *   @brief   AUTOSAR Icu - contains the data exported by the Icu module
 *   @details Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup ICU_MODULE
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
 =================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
 *@page misra_violations MISRA-C:2004 violations
 *
 *@section Icu_PBCfg_c_1
 *          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
 *          before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
 *          is as  per Autosar  requirement MEMMAP003.
 *
 *@section Icu_PBCfg_c_2
 *          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
 *          the contents of a header file being included twice
 *          This is not a violation since all header files are protected against multiple inclusions
 *
 * @section Icu_PBCfg_c_3
 *          Violates MISRA 2004 Required Rule 8.10, external ... could be made static
 *          The respective code could not be made static because of layers architecture design of
 *          the driver.
 *
 * @section Icu_PBCfg_c_4
 *          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
 *          character significance and case sensitivity are supported for external identifiers.
 *          This is not a violation since all the compilers used interpret the identifiers correctly
 *
 * @section [global]
 *          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
 *          on the significance of more than 31 characters. The used compilers use more than 31 chars 
 *          for identifiers.
 */
 /*==================================================================================================
 *                                         INCLUDE FILES
 * 1) system and project includes
 * 2) needed interfaces from external units
 * 3) internal and external interfaces from this unit
 *================================================================================================*/
#include "Icu.h"
#include "Icu_IPW.h"

#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
#include "CDD_Mcl.h"
#endif

#ifndef ICU_PRECOMPILE_SUPPORT
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/

#define ICU_VENDOR_ID_PBCFG_C                   43

#define ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C    4
#define ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C    0
/*
 * @violates @ref Icu_PBCfg_c_4 Identifier clash
 */
#define ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C       3

#define ICU_SW_MAJOR_VERSION_PBCFG_C            1
#define ICU_SW_MINOR_VERSION_PBCFG_C            1
#define ICU_SW_PATCH_VERSION_PBCFG_C            0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/

/* Check Icu_PBCfg.c against Icu.h file versions */
#if (ICU_VENDOR_ID_PBCFG_C != ICU_VENDOR_ID)
    #error "Icu_PBCfg.c and Icu.h have different vendor IDs"
#endif

#if ((ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
    (ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C != ICU_AR_RELEASE_MINOR_VERSION) || \
    (ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_PBCfg.c and Icu.h are different"
#endif

#if ((ICU_SW_MAJOR_VERSION_PBCFG_C != ICU_SW_MAJOR_VERSION) || \
    (ICU_SW_MINOR_VERSION_PBCFG_C != ICU_SW_MINOR_VERSION) || \
    (ICU_SW_PATCH_VERSION_PBCFG_C != ICU_SW_PATCH_VERSION))
     #error "Software Version Numbers of Icu_PBCfg.c  and Icu.h are different"
#endif


/* Check Icu_PBCfg.c against Icu_IPW.h file versions */
#if (ICU_VENDOR_ID_PBCFG_C != ICU_IPW_VENDOR_ID)
    #error "Icu_PBCfg.c and Icu_IPW.hhave different vendor IDs"
#endif

#if ((ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
    (ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
    (ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_PBCfg.c and Icu_IPW.h are different"
#endif

#if ((ICU_SW_MAJOR_VERSION_PBCFG_C != ICU_IPW_SW_MAJOR_VERSION) || \
    (ICU_SW_MINOR_VERSION_PBCFG_C != ICU_IPW_SW_MINOR_VERSION) || \
    (ICU_SW_PATCH_VERSION_PBCFG_C != ICU_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_PBCfg.c  and Icu_IPW.h are different"
#endif

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))

/* Check Icu_PBCfg.c against CDD_Mcl.h file versions */
#if (ICU_VENDOR_ID_PBCFG_C != MCL_VENDOR_ID)
    #error "Icu_PBCfg.c and CDD_Mcl.h have different vendor IDs"
#endif

#if ((ICU_AR_RELEASE_MAJOR_VERSION_PBCFG_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
    (ICU_AR_RELEASE_MINOR_VERSION_PBCFG_C != MCL_AR_RELEASE_MINOR_VERSION) || \
    (ICU_AR_RELEASE_REVISION_VERSION_PBCFG_C != MCL_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_PBCfg.c and CDD_Mcl.h are different"
#endif

#if ((ICU_SW_MAJOR_VERSION_PBCFG_C != MCL_SW_MAJOR_VERSION) || \
    (ICU_SW_MINOR_VERSION_PBCFG_C != MCL_SW_MINOR_VERSION) || \
    (ICU_SW_PATCH_VERSION_PBCFG_C != MCL_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_PBCfg.c and CDD_Mcl.h are different"
#endif
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/


/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/


/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/


/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/


/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
[!INCLUDE "Icu_PluginMacros.m"!][!//
[!CALL "ICU_VARIABLES"!]

#define ICU_START_SEC_CODE
/*
 * @violates @ref Icu_PBCfg_c_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 *           and comments before "#include"
 * @violates @ref Icu_PBCfg_c_2 precautions to prevent the contents of a header file being included
 *           twice
 */
#include "MemMap.h"

[!CALL "ICU_GENERATE_NOTIFICATION_FUNCTIONS_PROTOTYPE"!]

#define ICU_STOP_SEC_CODE
/*
 * @violates @ref Icu_PBCfg_c_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 *           and comments before "#include"
 * @violates @ref Icu_PBCfg_c_2 precautions to prevent the contents of a header file being included
 *           twice
 */
#include "MemMap.h"

 #define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
/*
 * @violates @ref Icu_PBCfg_c_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 *           and comments before "#include"
 * @violates @ref Icu_PBCfg_c_2 precautions to prevent the contents of a header file being included
 *           twice
 */
#include "MemMap.h"

[!CALL "ICU_GENERATE_DMA_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]

[!CALL "ICU_GENERATE_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]

[!CALL "ICU_GENERATE_CHANNEL_ID","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]

[!CALL "ICU_GENERATE_GLOBAL_CONFIG","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]

/*
 *   @brief This index relates the Hardware channels with the respective ICU channel.
 *   When an normal interrupt is asserted this index is used to locate the corresponding ICU channel
 *
 *  @violates @ref Icu_PBCfg_c_3 external ... could be made static
 */
[!CALL "ICU_GENERATE_HW_MAPPING","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]

[!LOOP "IcuConfigSet/*"!][!//
/*
 *   @brief Pre-Compile Default Configuration
 *   @violates @ref Icu_PBCfg_c_3 external ... could be made static
 */
CONST(Icu_ConfigType, ICU_CONST) [!"@name"!] =
{
    (Icu_ChannelType)[!"num:i(IcuMaxChannel)"!], /* The number of channels configured*/
    (const void *)&Icu_GlobalConfiguration_PB[!"@index"!],
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
    &Icu_DmaConfig_PB[!"@index"!],
#endif
    &Icu_InitChannel_PB[!"@index"!],
    &Icu_ChannelId_PB[!"@index"!],
    &Icu_InitHWMap_PB[!"@index"!]
};
[!ENDLOOP!]
#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/*
 * @violates @ref Icu_PBCfg_c_1 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
 *           and comments before "#include"
 * @violates @ref Icu_PBCfg_c_2 precautions to prevent the contents of a header file being included
 *           twice
 */
#include "MemMap.h"
/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/


/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/


/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/


#endif  /* ifndef ICU_PRECOMPILE_SUPPORT */

#ifdef __cplusplus
}
#endif

/** @} */
[!ENDCODE!]
