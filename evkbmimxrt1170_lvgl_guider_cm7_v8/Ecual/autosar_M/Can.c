/*
 * can.c
 *
 *  Created on: May 16, 2025
 *      Author: nithi
 */

#include "Can.h"

#include <assert.h>
#include <string.h>

static HAL_FLEXCAN_t g_halCan;
static const Can_ConfigType *g_canConfig = NULL;

void Can_Init(const Can_ConfigType *Config){

	assert(Config != NULL);
	g_canConfig = Config;

		status_t status = HAL_FLEXCAN_Init(&Config->dev);

		if (status != kStatus_Success) {
			return;
		}
}


void Can_DeInit(void){

	if (g_canConfig == NULL){
		return;
	}
		HAL_FLEXCAN_Deinit(&g_canConfig->dev);
	g_canConfig = NULL;
}

Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo)
{
    if (g_canConfig == NULL || PduInfo == NULL || PduInfo->sdu == NULL || PduInfo->length > 8) {
        return E_NOT_OK;
    }

    HAL_FLEXCAN_t *dev = &g_canConfig->dev;

    flexcan_frame_t frame;
    memset(&frame, 0, sizeof(frame));

    frame.id = FLEXCAN_ID_STD(PduInfo->id);  // Assuming standard ID
    frame.format = kFLEXCAN_FrameFormatStandard;
    frame.type = kFLEXCAN_FrameTypeData;
    frame.length = PduInfo->length;

    memcpy(&frame.dataByte0, PduInfo->sdu, PduInfo->length);

    status_t status = HAL_FLEXCAN_Transmit(dev, &frame, 0);
    if (status == kStatus_Success) {
        return E_OK;
    } else if (status == kStatus_FLEXCAN_TxBusy) {
        return CAN_BUSY;
    } else {
        return E_NOT_OK;
    }
}

void Can_MainFunction_Read(void)
{
    if (g_canConfig == NULL) {
        return;
    }

    HAL_FLEXCAN_t *dev = &g_canConfig->dev;
    flexcan_frame_t rxFrame;
    flexcan_handle_t flexcanHandle;

    status_t status = HAL_FLEXCAN_Receive(&dev);
//    if (status == kStatus_Success)
//    {
//        static uint8_t rxData[8];
//        memcpy(rxData, &rxFrame.dataByte0, rxFrame.length);
//
//        Can_PduType pdu;
//        pdu.id = rxFrame.id >> CAN_ID_STD_SHIFT;
//        pdu.length = rxFrame.length;
//        pdu.sdu = rxData;
//        pdu.swPduHandle = 0;
//
//        Can_HwType mailbox;
//        mailbox.controllerId = 0;
//        mailbox.hwHandle = 0;
//        mailbox.CanId = pdu.id;
//
//        CanIf_RxIndication(&mailbox, pdu.id, pdu.length, pdu.sdu);
//    }
}
