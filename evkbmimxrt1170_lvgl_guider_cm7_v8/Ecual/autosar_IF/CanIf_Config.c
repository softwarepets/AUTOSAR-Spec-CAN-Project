/*
 * CanIf_Config.c
 *
 *  Created on: Jun 2, 2025
 *      Author: nithi
 */


#include "CanIF.h"

// Example callback implementation
void App_CanRxCallback(PduIdType id, const uint8_t* data, uint8_t len)
{
    // Application-level handling of received CAN data
}

// Rx PDU configuration
static const CanIf_RxPduConfigType rxPdus[] = {
    {
        .rxPduId = 0,
        .hrh = 1,
        .canId = 0x123,
        .RxIndication = App_CanRxCallback
    }
};

// Tx PDU configuration
static const CanIf_TxPduConfigType txPdus[] = {
    {
        .txPduId = 0,
        .hth = 0,
        .canId = 0x321
    }
};

// Global configuration instance (defined here only)
const CanIf_ConfigType canIfConfig = {
    .txPdus = txPdus,
    .numTxPdus = sizeof(txPdus) / sizeof(txPdus[0]),
    .rxPdus = rxPdus,
    .numRxPdus = sizeof(rxPdus) / sizeof(rxPdus[0])
};


