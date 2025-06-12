/*
 * hal_flexcan.h
 *
 *  Created on: May 14, 2025
 *      Author: nithi
 */

#ifndef COMM_HAL_FLEXCAN_H_
#define COMM_HAL_FLEXCAN_H_

#include "../../Mcal/fsl_flexcan.h"  // NXP MCAL driver

typedef struct {
    CAN_Type *instance;
    flexcan_handle_t handle;
    flexcan_config_t config;
    uint32_t sourceClockHz;
    flexcan_mb_transfer_t transfer;
    flexcan_frame_t frame;
} HAL_FLEXCAN_t;

/* ............Initialization and shutdown */
status_t HAL_FLEXCAN_GetDefaultConfig(HAL_FLEXCAN_t *dev);
status_t HAL_FLEXCAN_TransferCreateHandle(HAL_FLEXCAN_t *dev);
status_t HAL_FLEXCAN_Init(HAL_FLEXCAN_t *dev);
void HAL_FLEXCAN_Deinit(HAL_FLEXCAN_t *dev);
void HAL_FLEXCAN_Reset(HAL_FLEXCAN_t *dev);

/* ...............Bitrate configuration */
status_t HAL_FLEXCAN_SetBitrate(HAL_FLEXCAN_t *dev, uint32_t bitrate);
status_t HAL_FLEXCAN_SetFDBitrate(HAL_FLEXCAN_t *dev, uint32_t bitrateNominal, uint32_t bitrateData);

/* ............Message buffer handling */
status_t HAL_FLEXCAN_Transmit(HAL_FLEXCAN_t *dev, flexcan_frame_t *frame, uint8_t mbIdx);
status_t HAL_FLEXCAN_Receive(HAL_FLEXCAN_t *dev);




#endif /* COMM_HAL_FLEXCAN_H_ */
