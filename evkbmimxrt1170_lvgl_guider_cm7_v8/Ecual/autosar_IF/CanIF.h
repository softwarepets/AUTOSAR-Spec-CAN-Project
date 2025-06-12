/*
 * canIF.h
 *
 *  Created on: May 21, 2025
 *      Author: nithi
 */

#ifndef AUTOSAR_IF_CANIF_H_
#define AUTOSAR_IF_CANIF_H_

#include "std_types.h"
#include "comStack_Types.h"
#include "../autosar_M/Can.h"

typedef void (*CanIf_RxIndicationCallback)(PduIdType id, const uint8_t *data, uint8_t len);

typedef struct {
    PduIdType txPduId;
    Can_HwHandleType hth;
    Can_IdType canId;
} CanIf_TxPduConfigType;

typedef struct {
    PduIdType rxPduId;
    Can_HwHandleType hrh;
    Can_IdType canId;
    CanIf_RxIndicationCallback RxIndication;
} CanIf_RxPduConfigType;

typedef struct {
    const CanIf_TxPduConfigType* txPdus;
    uint8_t numTxPdus;
    const CanIf_RxPduConfigType* rxPdus;
    uint8_t numRxPdus;
} CanIf_ConfigType;


void CanIf_Init(const CanIf_ConfigType* Config);
Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr);
void CanIf_RxIndication(const Can_HwType* Mailbox,  const PduInfoType* PduInfoPtr);
void CanIf_TxConfirmation(PduIdType CanTxPduId); // optional
//void App_CanRxCallback(PduIdType id, const uint8_t* data, uint8_t len);
extern const CanIf_ConfigType canIfConfig;


#endif /* AUTOSAR_IF_CANIF_H_ */
