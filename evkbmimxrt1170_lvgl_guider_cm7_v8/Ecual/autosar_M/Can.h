/*
 * can.h
 *
 *  Created on: May 16, 2025
 *      Author: nithi
 */

#ifndef AUTOSAR_M_CAN_H_
#define AUTOSAR_M_CAN_H_

#include <stdint.h>
#include "../Comm/hal_flexcan.h"
typedef uint8_t Std_ReturnType;
typedef uint8_t Can_HwHandleType;
typedef uint32_t Can_IdType;


#define E_OK         ((Std_ReturnType)0)
#define E_NOT_OK     ((Std_ReturnType)1)
#define CAN_BUSY       ((Std_ReturnType)2)

// CAN PDU (Protocol Data Unit) to be transmitted, 	Tx frame format for Can_Write()
typedef struct {
    uint32_t id;   // CAN Identifier (11-bit or 29-bit)
    uint8_t length;       // Number of data bytes (0–8 or 0–64 for CAN FD)
    const uint8_t *sdu;// Pointer to data buffer
    uint8_t swPduHandle;    // Software PDU handle for tracking (e.g., for confirmation)
} Can_PduType;

// Controller-specific configuration
typedef struct {
    uint8_t controllerId;       // Logical Controller ID (0, 1, etc.)
    uint32_t bitrate;        // Nominal bitrate (e.g., 500000 for 500 kbps)
} Can_ControllerConfigType;

//	Passed to Can_Init() for multi-controller support
typedef struct {
    const Can_ControllerConfigType *controller;
    HAL_FLEXCAN_t dev;
} Can_ConfigType;

//Used in Rx indication (CanIf_RxIndication())
typedef struct {
    uint8_t controllerId;       // Controller ID (e.g., 0, 1)
    Can_HwHandleType hwHandle;  // Hardware object handle (MB index)
    uint32_t CanId;             // CAN ID of the received message
} Can_HwType;

void Can_Init(const Can_ConfigType *Config);
void Can_DeInit(void);
Std_ReturnType Can_Write(Can_HwHandleType Hth, const Can_PduType *PduInfo);
void Can_MainFunction_Read(void);


#endif /* AUTOSAR_M_CAN_H_ */
