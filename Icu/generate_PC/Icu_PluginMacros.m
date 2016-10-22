[!NOCODE!][!//
/**
  @file    Icu_PluginMacros.m
  @version 1.1.0

  @brief   AUTOSAR Icu - plugin check.
  @details Version checks.
  
  Project AUTOSAR 4.0 MCAL
  Patform PA
  Peripheral GTM
  Dependencies none
  
  ARVersion 4.0.3
  ARRevision ASR_REL_4_0_REV_0003
  ARConfVariant
  SWVersion 1.1.0
  BuildVersion MPC577XM_MCAL_1_1_0_FBR_ASR_REL_4_0_REV_0003_20150925

  (c) Copyright 2006-2015 Freescale Semiconductor Inc. & STMicroelectronics
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/
[!// MACRO for creating the mapping between hardware channels and logical channels
[!MACRO "ICU_VARIABLES"!]
[!NOCODE!]
[!VAR "NoOfIcuChannels"   = "num:i(64)"!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for creating the mapping between hardware channels and logical channels
[!MACRO "ICU_GENERATE_HW_MAPPING","VARIANT", "MISRA_REF"!]
[!VAR "MacChannelStartIndexNameList"="'GTM_TIM_0,GTM_TIM_1,GTM_TIM_2,GTM_TIM_3,GTM_TIM_4,GTM_TIM_5,IRQ_'"!]
[!VAR "MacChannelStartIndexList"="'000,008,016,024,032,040,048,064'"!]
[!VAR "MacLengthElemIndexNameList"="num:i(string-length('GTM_TIM_0,'))"!]
[!VAR "MacLengthElemIndexList"="num:i(string-length('296,'))"!]
[!LOOP "IcuConfigSet/*"!]
    [!VAR "MacCrtHwModule"="0"!]
/*
 * @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
CONST(Icu_ChannelType,ICU_CONST) Icu_InitHWMap_[!"$VARIANT"!][!"@index"!][ICU_MAX_HW_CHANNELS] =
{[!CR!][!/*
    */!][!FOR "Idx" = "0" TO "$NoOfIcuChannels - 1"!][!/*
        */!][!VAR "Found" = "'false'"!][!/*
        */!][!LOOP "./IcuChannel/*"!][!/*
            */!][!VAR "MacFirstIndex"="text:indexOf(text:toupper($MacChannelStartIndexNameList),text:toupper(substring-before(IcuHwChannel,'_CH')))div $MacLengthElemIndexNameList * $MacLengthElemIndexList+1"!][!/*
            */!][!VAR "MacCh" = "substring-after(IcuHwChannel,'CH_')+num:i(substring($MacChannelStartIndexList,$MacFirstIndex,($MacLengthElemIndexList)-1))"!][!/*
            */!][!IF "num:i($MacCh)=$Idx"!][!/*
                */!][!WS "8"!][!"node:name(.)"!][!/*
                */!][!VAR "Found" = "'true'"!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
        */!][!IF "$Found='false'"!][!/*
            */!][!WS "8"!]NoIcuChannel[!/*
        */!][!ENDIF!][!/*
        */!][!IF "$Idx < $NoOfIcuChannels - 1"!],[!ELSE!] [!ENDIF!][!/*
        */!][!VAR "MacNextIndex"="(substring(text:toupper($MacChannelStartIndexList),($MacCrtHwModule + 1)*$MacLengthElemIndexList + 1,$MacLengthElemIndexList -1))"!][!/*
        */!][!VAR "MacCrtIndex"="(substring(text:toupper($MacChannelStartIndexList),($MacCrtHwModule)*$MacLengthElemIndexList + 1,$MacLengthElemIndexList - 1))"!][!/*
        */!]/* maps to [!"substring(text:toupper($MacChannelStartIndexNameList),$MacCrtHwModule*$MacLengthElemIndexNameList +1 ,$MacLengthElemIndexNameList - 1)"!]_CH_[!"num:i($Idx - $MacCrtIndex)"!]*/[!CR!][!/*
        */!][!IF "$Idx + 1= num:i($MacNextIndex) "!][!VAR "MacCrtHwModule"="$MacCrtHwModule+1"!][!ENDIF!][!/*
    */!][!ENDFOR!][!/*
    */!]};
[!ENDLOOP!]
[!ENDMACRO!]

[!// MACRO for generating the notification function prototype
[!MACRO "ICU_GENERATE_NOTIFICATION_FUNCTIONS_PROTOTYPE"!]
[!NOCODE!]
    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "Found" = "'false'"!]
    [!LOOP "IcuConfigSet/*"!]
        [!LOOP "./IcuChannel/*"!]
            [!VAR "a" = "IcuMeasurementMode"!]
            [!IF "(contains($a,'ICU_MODE_TIMESTAMP') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL_PTR') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL'))"!]
                [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
                [!VAR "MacInnerLoopCounter" = "0"!]
                [!VAR "MacMatchCounter" = "0"!]
                [!VAR "MacNotification" = "IcuTimestampMeasurement/IcuTimestampNotification"!]
                [!LOOP "../../../*/IcuChannel/*"!] [!//All notifications from all configurations
                    [!VAR "a" = "IcuMeasurementMode"!]
                    [!IF "(contains($a,'ICU_MODE_TIMESTAMP') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL_PTR')and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL'))"!]
                        [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                        [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                            [!IF "($MacNotification = IcuTimestampMeasurement/IcuTimestampNotification)"!]
                                [!VAR "MacMatchCounter" = "$MacMatchCounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$MacMatchCounter = 1"!]
                    [!IF "$Found = 'false'"!]
                        [!VAR "Found" = "'true'"!]
                        [!CODE!]
/**
 *   @brief External Notifications for Timestamp
 */[!/*
                       */!][!CR!][!ENDCODE!]
                    [!ENDIF!]
                    [!CODE!]
extern FUNC (void, ICU_CODE) [!"IcuTimestampMeasurement/IcuTimestampNotification"!](void);[!CR!]
                    [!ENDCODE!][!//
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]

    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "Found" = "'false'"!]
    [!LOOP "IcuConfigSet/*"!]
        [!LOOP "./IcuChannel/*"!]
            [!VAR "a" = "IcuMeasurementMode"!]
            [!IF "(contains($a,'ICU_MODE_SIGNAL_EDGE_DETECT') and (IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR'))"!]
                [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
                [!VAR "MacInnerLoopCounter" = "0"!]
                [!VAR "MacMatchCounter" = "0"!]
                [!VAR "MacNotification" = "IcuSignalEdgeDetection/IcuSignalNotification"!]
                [!LOOP "../../../*/IcuChannel/*"!] [!//All notifications from all configurations
                    [!VAR "a" = "IcuMeasurementMode"!]
                    [!IF "(contains($a,'ICU_MODE_SIGNAL_EDGE_DETECT') and (IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR'))"!]
                        [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                        [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                            [!IF "($MacNotification = IcuSignalEdgeDetection/IcuSignalNotification)"!]
                                [!VAR "MacMatchCounter" = "$MacMatchCounter + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDLOOP!]
                [!IF "$MacMatchCounter = 1"!]
                    [!IF "$Found = 'false'"!]
                        [!VAR "Found" = "'true'"!]
                        [!CODE!][!//
[!CR!]/**
 *   @brief External Notifications for Edge Detection
 */[!/*
                        */!][!CR!][!ENDCODE!]
                    [!ENDIF!]
                    [!CODE!]
extern FUNC (void, ICU_CODE) [!"IcuSignalEdgeDetection/IcuSignalNotification"!](void);[!CR!]
                    [!ENDCODE!][!//
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]

    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "Found" = "'false'"!]
    [!LOOP "IcuConfigSet/*"!]
        [!LOOP "./IcuChannel/*"!]
            [!IF "node:exists(IcuOverflowNotification)"!]
                [!IF "(IcuOverflowNotification != 'NULL_PTR') and (IcuOverflowNotification != 'NULL')"!]
                    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
                    [!VAR "MacInnerLoopCounter" = "0"!]
                    [!VAR "MacMatchCounter" = "0"!]
                    [!VAR "MacNotification" = "IcuOverflowNotification"!]
                    [!LOOP "../../../*/IcuChannel/*"!] [!//All notifications from all configurations
                        [!IF "node:exists(IcuOverflowNotification)"!]
                                [!IF "(IcuOverflowNotification != 'NULL_PTR')and (IcuOverflowNotification != 'NULL')"!]
                                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                                        [!IF "($MacNotification = IcuOverflowNotification)"!]
                                           [!VAR "MacMatchCounter" = "$MacMatchCounter + 1"!]
                                        [!ENDIF!]
                                    [!ENDIF!]
                                [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                    [!IF "$MacMatchCounter = 1"!]
                        [!IF "$Found = 'false'"!]
                            [!VAR "Found" = "'true'"!]
                            [!CODE!]
/**
 *   @brief  Overflow notification handlers
 */[!/*
                            */!][!CR!][!ENDCODE!]
                        [!ENDIF!]
                        [!CODE!]
extern FUNC (void, ICU_CODE) [!"IcuOverflowNotification"!](void);[!CR!]
                        [!ENDCODE!][!//
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!]


[!// MACRO for creating the configuration pointer(s)
[!MACRO "ICU_GENERATE_DMA_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
[!/**/!][!LOOP "IcuConfigSet/*"!][!/*
        */!][!VAR "needComma"="'false'"!][!/*
        */!][!VAR "noOfDmaReqConfigured"="0"!][!/*
      */!]/*[!CR!][!/*
      */!] * @brief    [!"$VARIANT"!] DMA Configuration Configuration [!CR!][!/*
      */!] * @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static[!CR!][!/*
      */!] */[!CR!][!/*
      */!]CONST(Icu_DmaConfigType, ICU_CONST) Icu_DmaConfig_[!"$VARIANT"!][!"@index"!]=[!CR!]{[!CR!][!/*
        */!][!WS "8"!](uint8)[!"num:i($noOfDmaReqConfigured)"!],[!CR!][!/*
        */!][!WS "8"!][!IF "$noOfDmaReqConfigured != 0 "!][!/*
            */!]&DmaReqConfig_[!"$VARIANT"!][!"@index"!][!/*
        */!][!ELSE!][!/*
            */!]NULL_PTR[!/*
        */!][!ENDIF!][!/*
        */!][!CR!]};[!CR!][!/*
    */!][!ENDLOOP!]
#endif /* #if (ICU_TIMESTAMP_USES_DMA == STD_ON) */
[!ENDMACRO!]

[!// MACRO for creating the configuration pointer(s)
[!MACRO "ICU_GENERATE_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]
[!LOOP "IcuConfigSet/*"!][!//
[!VAR "MacCount" = "count(IcuChannel/*)"!][!//
[!VAR "Idx" = "1"!][!//
[!VAR "MacLoopVar"="0"!][!//
/*
 *  @brief    [!"$VARIANT"!] Default Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
CONST(Icu_ChannelConfigType, ICU_CONST) Icu_InitChannel_[!"$VARIANT"!][!"@index"!][[!"num:i(count(IcuChannel/*))"!]]=
{
[!FOR "x" = "0" TO "num:i(count(IcuChannel/*))"!][!/*
  */!][!LOOP "IcuChannel/*"!][!/*
    */!][!VAR "Loop"="num:i($MacLoopVar)"!][!/*
    */!][!IF "IcuChannelId = $Loop"!][!/*
    */!][!WS "8"!]/* [!"node:name(.)"!] - [!"IcuHwChannel"!] */
    { [!CR!][!/*
        */!][!WS "8"!]([!IF "IcuWakeupCapability"!]((Icu_ParamType)ICU_WAKEUP_CAPABLE << ICU_WAKEUP_SHIFT) | \[!CR!][!WS "12"!][!ENDIF!][!/*
        
        */!](Icu_ParamType)((Icu_ParamType)[!"IcuDefaultStartEdge"!] << ICU_EDGE_PARAM_SHIFT)[!/*

        */!][!IF "contains(IcuHwChannel,'IRQ_')"!][!/*
            */!][!IF "Icu_EXT_ISR_IFERDigitalFilter='true'"!][!/*
                */!]|  \[!CR!][!WS "8"!]ICU_SIUL2_INT_FILTER_ENABLE_PARAM_MASK [!/*
                */!]|  \[!CR!][!WS "8"!](Icu_ParamType)((Icu_ParamType)[!"Icu_EXT_ISR_IFMCDigitalFilter"!]U << ICU_SIUL2_INT_FILTER_COUNTER_PARAM_SHIFT)[!/*
            */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*

        */!][!IF "contains(IcuHwChannel,'GTM_TIM_')"!][!/*
            */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_SignalMeasuringUnitClock"!] << ICU_GTM_TIM_CLK_SEL_SHIFT)[!/*
            */!][!IF "../../../../IcuNonAUTOSAR/IcuEnableDualClockMode"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_SignalMeasuringUnitClock_Alternative"!] << ICU_GTM_TIM_CLK_SEL_ALT_SHIFT)[!/*
            */!][!ENDIF!][!/*
            */!][!IF "Icu_TIM_ChannelFilter"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)ICU_GTM_TIM_FILTER_ENABLE_MASK_U32[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TimeBase)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TimeBase"!] << ICU_GTM_TIM_GPR0_SEL_SHIFT)[!/*
            */!][!ELSE!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TimeBaseCh0Bits)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TimeBaseCh0Bits"!] << ICU_GTM_TIM_TIME_BASE0_BITS_SHIFT)[!/*
            */!][!ELSE!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterModeFallingEdge)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterModeFallingEdge"!] << ICU_GTM_TIM_FILTER_MODE_FE_SHIFT)[!/*
            */!][!ELSE!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterCounterModeFallingEdge)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterCounterModeFallingEdge"!] << ICU_GTM_TIM_FILTER_COUNTER_MODE_FE_SHIFT)[!/*
            */!][!ELSE!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterModeRisingEdge)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterModeRisingEdge"!] << ICU_GTM_TIM_FILTER_MODE_RE_SHIFT)[!/*
            */!][!ELSE!][!/*    
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterCounterModeRisingEdge)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterCounterModeRisingEdge"!] << ICU_GTM_TIM_FILTER_COUNTER_MODE_RE_SHIFT )[!/*
            */!][!ELSE!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
            */!][!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterCounterClock)"!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterCounterClock"!] << ICU_GTM_TIM_FILTER_COUNTER_CLOCK_SHIFT)[!/*
            */!][!ELSE!][!/*
                */!]|  \[!CR!][!WS "12"!](Icu_ParamType)0U[!/*
            */!][!ENDIF!][!/*
        */!][!ENDIF!]),[!/*
        */!][!CR!][!WS "12"!]([!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterParameterRisingEdge)"!][!/*
            */!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterParameterRisingEdge"!] & ICU_GTM_TIM_FILTER_RINSING_EDGE_PARAM_MASK_U32)[!/*
        */!][!ELSE!][!/*
            */!](Icu_ParamType)0U[!/*
        */!][!ENDIF!]),[!/*
        */!][!CR!][!WS "12"!]([!IF "node:exists(Icu_TIM_FilterParameters/IcuFilterParameterFallingEdge)"!][!/*
            */!](Icu_ParamType)((Icu_ParamType)[!"Icu_TIM_FilterParameters/IcuFilterParameterFallingEdge"!]  & ICU_GTM_TIM_FILTER_FALLING_EDGE_PARAM_MASK_U32)[!/*
        */!][!ELSE!][!/*
            */!](Icu_ParamType)0U[!/*
        */!][!ENDIF!]),
            (Icu_MeasurementModeType)[!"IcuMeasurementMode"!],
            (Icu_MeasurementSubModeType)[!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'"!]0U[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!"IcuTimestampMeasurement/IcuTimestampMeasurementProperty"!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!"IcuSignalMeasurement/IcuSignalMeasurementProperty"!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'"!][!"IcuDefaultStartEdge"!][!ENDIF!],[!CR!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!WS "12"!]NULL_PTR[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'"!][!WS "12"!]NULL_PTR[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
                */!][!IF "IcuTimestampMeasurement/IcuTimestampNotification!='NULL_PTR'"!][!/*
                    */!][!WS "12"!]&[!"IcuTimestampMeasurement/IcuTimestampNotification"!][!/*
                */!][!ELSE!][!/*
                    */!][!WS "12"!]NULL_PTR[!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'"!][!/*
                */!][!IF "IcuSignalEdgeDetection/IcuSignalNotification!='NULL_PTR'"!][!/*
                    */!][!WS "12"!]&[!"IcuSignalEdgeDetection/IcuSignalNotification"!][!/*
                */!][!ELSE!][!/*
                    */!][!WS "12"!]NULL_PTR[!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!],
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
[!/*     */!](Mcl_ChannelType)[!IF "IcuMeasurementMode = 'ICU_MODE_TIMESTAMP'and IcuDMAChannelEnable = 'true'"!][!/*
                */!][!WS "12"!][!"node:value(node:ref(IcuDMAChannelRef)/MclDMAChannelId)"!],[!/* MCL DMA logical Channel
                */!][!IF "node:exists(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif)"!] [!/* Validation for Notification function
                    */!][!IF "(node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) = 'NULL_PTR') or (node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) = 'NULL')"!][!/*
                        */!][!ERROR!] Notification need to be configured for DMA Channels that are linked to Icu Channels. The name of the notification shall be <IcuChannelName>_MclDmaTransferCompletionNotif e.g [!"node:name(.)"!]_MclDmaTransferCompletionNotif[!ENDERROR!][!/*
                */!][!ELSEIF "node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) != concat(node:name(.),'_MclDmaTransferCompletionNotif')"!][!/*
                        */!][!ERROR!] Notification name must be [!"node:name(.)"!]_MclDmaTransferCompletionNotif[!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSE!][!/*
                    */!][!ERROR!] Notification need to be configured for DMA Channels that are linked to Icu Channels [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
                */!][!IF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource0)"!][!/* Validation for DMA source
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource0),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource1)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource1),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource2)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource2),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource3)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource3),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource4)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource4),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource5)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource5),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource6)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource6),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*    
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource7)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource7),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*    
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource8)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource8),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*     
                */!][!ELSEIF "node:exists(node:ref(IcuDMAChannelRef)/DmaSource9)"!][!/*
                    */!][!IF "substring-before(substring-after(node:value(node:ref(IcuDMAChannelRef)/DmaSource9),'GTM_TIM'),'_')!=substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!][!/*
                        */!][!ERROR!] Dma Source shall be GTM_TIM[!"substring-before(substring-after(node:value(IcuHwChannel),'GTM_TIM_'),'_')"!]_CH<number> [!ENDERROR!][!/*
                    */!][!ENDIF!][!/*       
                */!][!ELSE!][!/*
                    */!][!ERROR!] Dma Source need to be configured - For [!"node:ref(IcuDMAChannelRef)"!] set DMA Channel Enable[!ENDERROR!][!/*
                */!][!ENDIF!][!/*
            */!][!ELSE!][!WS "12"!]NoMclDmaChannel,[!/*
        */!][!ENDIF!]
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
[!/*   */!][!IF "node:exists(IcuOverflowNotification)"!][!/*
            */!][!WS "12"!][!IF "IcuOverflowNotification!= 'NULL_PTR'"!]&[!ENDIF!][!"IcuOverflowNotification"!][!/*
        */!][!ELSE!][!/*
            */!][!WS "12"!]NULL_PTR[!/*
        */!][!ENDIF!],
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)[!CR!][!/*
    */!][!WS "8"!](Icu_WakeupValueType)[!/*
    */!][!IF "IcuWakeupCapability"!][!/*
        */!]EcuMConf_EcuMWakeupSource_[!"as:ref(IcuWakeup/IcuChannelWakeupInfo)/@name"!][!/*
    */!][!ELSE!][!/*
        */!]0U[!/*
    */!][!ENDIF!]
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */           
        }[!IF "$Idx!=$MacCount"!],[!CR!][!ENDIF!][!/*
        */!][!VAR "Idx" = "$Idx + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
*/!][!VAR "MacLoopVar"="$MacLoopVar + 1"!][!/*
*/!][!ENDFOR!][!CR!]
 };

[!ENDLOOP!]
[!ENDMACRO!]

[!// MACRO for creating the pointer that contains the configured hardware channels
[!MACRO "ICU_GENERATE_CHANNEL_ID","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]
/**
 *   @brief Configured Hardware channels
 *   @{
 *
 */
[!LOOP "IcuConfigSet/*"!][!//
[!VAR "MacLoopVar1"="0"!][!//
[!VAR "MacNoOfChannels" = "num:i(./IcuMaxChannel - 1)"!][!//
/*
 *  @violates @ref [!"$MISRA_REF"!] external ... could be made static
 */
 CONST(Icu_ChannelType,ICU_VAR) Icu_ChannelId_[!"$VARIANT"!][!"@index"!][[!"num:i(IcuMaxChannel)"!]]= {[!CR!][!/*
    */!][!FOR "x" = "0" TO "num:i(count(IcuChannel/*))"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
                */!][!VAR "Loop"="num:i($MacLoopVar1)"!][!/*
                */!][!IF "IcuChannelId = $Loop"!][!/*
                    */!][!WS "4"!]ICU_[!"IcuHwChannel"!][!/*
                    */!][!IF " $x< $MacNoOfChannels"!],[!CR!][!ENDIF!][!/*
                */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!VAR "MacLoopVar1"="$MacLoopVar1 + 1"!][!/*
    */!][!ENDFOR!]
};
[!ENDLOOP!] 
/**@}*/
[!ENDMACRO!]

[!// MACRO for creating the pointer that contains the global configuration
[!MACRO "ICU_GENERATE_GLOBAL_CONFIG","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]
/**
 *   @brief Configured clobal configuration
 *   @{
 *
 */
[!LOOP "IcuConfigSet/*"!][!//

/*
 *  @violates @ref [!"$MISRA_REF"!] external ... could be made static
 */
CONST(Icu_IPW_GlobalConfigurationType,ICU_CONST) Icu_GlobalConfiguration_[!"$VARIANT"!][!"@index"!]=
{
[!VAR "MacSiul2ChannelsExists"="0"!][!/*
    */!][!LOOP "IcuChannel/*"!][!/*
    */!][!IF "contains(IcuHwChannel,'IRQ_')"!][!/*
        */!][!VAR "MacSiul2ChannelsExists"="1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDLOOP!]
[!IF "$MacSiul2ChannelsExists != 0 "!] 
    [!IF "node:exists(IcuEXT_ISR_InterruptFilterClockPrescaler)"!]
        [!IF "node:exists(IcuEXT_ISR_AlternateInterruptFilterClockPrescaler)"!](uint32)(((uint32)[!"node:value(IcuEXT_ISR_AlternateInterruptFilterClockPrescaler)"!]U << ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_SHIFT) |
            [!"node:value(IcuEXT_ISR_InterruptFilterClockPrescaler)"!]U)
        [!ELSE!][!"node:value(IcuEXT_ISR_InterruptFilterClockPrescaler)"!]U
        [!ENDIF!]
    [!ELSE!]0U
    [!ENDIF!]
[!ELSE!]0U
[!ENDIF!]
};
[!ENDLOOP!] 
/**@}*/
[!ENDMACRO!]


[!ENDNOCODE!]