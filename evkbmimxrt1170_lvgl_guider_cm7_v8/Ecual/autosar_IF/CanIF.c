/*
 * canIF.c
 *
 *  Created on: May 21, 2025
 *      Author: nithi
 */

#include "CanIF.h"
#include <stddef.h>
#include <string.h>

static const CanIf_ConfigType* g_canIfConfig = NULL;

void CanIf_Init(const CanIf_ConfigType* Config)
{
    g_canIfConfig = Config;
}

Std_ReturnType CanIf_Transmit(PduIdType TxPduId, const PduInfoType* PduInfoPtr)
{
    if (!g_canIfConfig || !PduInfoPtr || !PduInfoPtr->SduDataPtr) {
        return E_NOT_OK;
    }

    for (uint8_t i = 0; i < g_canIfConfig->numTxPdus; i++) {
        const CanIf_TxPduConfigType* txCfg = &g_canIfConfig->txPdus[i];
        if (txCfg->txPduId == TxPduId) {
            Can_PduType pdu;
            pdu.id = txCfg->canId;
            pdu.length = PduInfoPtr->SduLength;
            pdu.sdu = PduInfoPtr->SduDataPtr;
            pdu.swPduHandle = TxPduId;
            return Can_Write(txCfg->hth, &pdu);
        }
    }

    return E_OK;
}

void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr)
{
    if (!g_canIfConfig || !Mailbox || !PduInfoPtr || !PduInfoPtr->SduDataPtr) {
        return;
    }

    for (uint8_t i = 0; i < g_canIfConfig->numRxPdus; i++) {
        const CanIf_RxPduConfigType* rxCfg = &g_canIfConfig->rxPdus[i];

        if (rxCfg->hrh == Mailbox->hwHandle && rxCfg->canId == Mailbox->CanId) {
            if (rxCfg->RxIndication) {
                rxCfg->RxIndication(rxCfg->rxPduId,
                                    PduInfoPtr->SduDataPtr,
                                    PduInfoPtr->SduLength);
            }
            return;
        }
    }
}


void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    if (!CanTxPduId){
    ;
    }
}



