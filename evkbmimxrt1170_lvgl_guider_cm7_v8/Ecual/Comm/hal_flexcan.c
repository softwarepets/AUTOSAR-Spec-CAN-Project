/*
 * hal_flexcan.c
 *
 *  Created on: May 14, 2025
 *      Author: nithi
 */


#include "hal_flexcan.h"
uint32_t RXIdentifier;


status_t HAL_FLEXCAN_GetDefaultConfig(HAL_FLEXCAN_t *dev)
{
    assert(dev != NULL);

    FLEXCAN_GetDefaultConfig(&dev->config);
    dev->config.bitRate = 500000U;

    return kStatus_Success;
}

status_t HAL_FLEXCAN_TransferCreateHandle(HAL_FLEXCAN_t *dev)
{
    assert(dev != NULL);

    FLEXCAN_TransferCreateHandle(dev->instance, &dev->handle, NULL, NULL);  // No callback yet

    return kStatus_Success;
}

status_t HAL_FLEXCAN_Init(HAL_FLEXCAN_t *dev)
{
    assert(dev != NULL);
    dev->instance = CAN1;
    dev->sourceClockHz  = ((CLOCK_GetRootClockFreq(kCLOCK_Root_Can3) / 100000U) * 100000U);

   // FLEXCAN_GetDefaultConfig(&dev->config);
    dev->config.clkSrc = kFLEXCAN_ClkSrc0;
    dev->config.bitRate = 1000000U;
    dev->config.bitRateFD = 2000000U;
    dev->config.maxMbNum = 16;
    dev->config.enableLoopBack = false;
    dev->config.enableTimerSync = true;
    dev->config.enableSelfWakeup = false;
    dev->config.wakeupSrc = kFLEXCAN_WakeupSrcUnfiltered;
    dev->config.enableIndividMask = false;
    dev->config.disableSelfReception = false;
    dev->config.enableListenOnlyMode = false;
    dev->config.enableSupervisorMode = true;
    dev->config.enableDoze = false;
    dev->config.enableMemoryErrorControl = true;
    dev->config.enableNonCorrectableErrorEnterFreeze = true;
    dev->config.timingConfig.phaseSeg1 = 1;
    dev->config.timingConfig.phaseSeg2   = 1;
	dev->config.timingConfig.propSeg     = 4;
	dev->config.timingConfig.rJumpwidth  = 1;
	dev->config.timingConfig.fphaseSeg1  = 1;
	dev->config.timingConfig.fphaseSeg2  = 1;
	dev->config.timingConfig.fpropSeg    = 0;
	dev->config.timingConfig.frJumpwidth = 1;


    FLEXCAN_Init(dev->instance, &dev->config, dev->sourceClockHz);
    uint32_t maxMb = (dev->instance->MCR & CAN_MCR_MAXMB_MASK);
    printf("MAXMB set to: %lu\n", maxMb);  // or use your debugger to inspect

    return kStatus_Success;
}

void HAL_FLEXCAN_Deinit(HAL_FLEXCAN_t *dev)
{
    assert(dev != NULL);
    FLEXCAN_Deinit(dev->instance);
}

status_t HAL_FLEXCAN_SetBitrate(HAL_FLEXCAN_t *dev, uint32_t bitrate)
{
    assert(dev != NULL);
    return FLEXCAN_SetBitRate(dev->instance, dev->sourceClockHz, bitrate);
}

status_t HAL_FLEXCAN_SetFDBitrate(HAL_FLEXCAN_t *dev, uint32_t bitrateNominal, uint32_t bitrateData)
{
#if defined(FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE) && FSL_FEATURE_FLEXCAN_HAS_FLEXIBLE_DATA_RATE
    assert(dev != NULL);
    return FLEXCAN_SetFDBitRate(dev->instance, dev->sourceClockHz, bitrateNominal, bitrateData);
#else
    return kStatus_Fail;
#endif
}

status_t HAL_FLEXCAN_Transmit(HAL_FLEXCAN_t *dev, flexcan_frame_t *frame, uint8_t mbIdx)
{
    assert(dev != NULL && frame != NULL);
    return FLEXCAN_TransferSendBlocking(dev->instance, mbIdx, frame);
}

status_t HAL_FLEXCAN_Receive(HAL_FLEXCAN_t *dev)
{
    assert(dev != NULL);
    assert(dev->transfer.frame != NULL);
    dev->instance = CAN1;
    dev->sourceClockHz  = ((CLOCK_GetRootClockFreq(kCLOCK_Root_Can3) / 100000U) * 100000U);

    //FLEXCAN_TransferCreateHandle(dev->instance, &dev->handle, flexcan_callback, NULL);
    dev->config.maxMbNum = 16;
    dev->transfer.mbIdx = 9;
    dev->frame.id = FLEXCAN_ID_STD(RXIdentifier);
    dev->frame.format = (uint8_t)kFLEXCAN_FrameFormatStandard;
    dev->frame.type = (uint8_t)kFLEXCAN_FrameTypeData;
    dev->frame.length = (uint8_t)8;
    dev->transfer.frame = &dev->frame;
    return FLEXCAN_TransferReceiveNonBlocking(dev->instance, &dev->handle, &dev->transfer);
}


void HAL_FLEXCAN_Reset(HAL_FLEXCAN_t *dev)
{
	assert(dev != NULL);
	FLEXCAN_Reset(dev->instance);
}
