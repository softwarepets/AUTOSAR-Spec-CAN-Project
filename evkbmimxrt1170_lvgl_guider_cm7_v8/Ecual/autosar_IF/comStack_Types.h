/*
 * comStack_Types.h
 *
 *  Created on: Jun 2, 2025
 *      Author: nithi
 */

#ifndef AUTOSAR_IF_COMSTACK_TYPES_H_
#define AUTOSAR_IF_COMSTACK_TYPES_H_

#include "std_types.h"

typedef uint8_t PduIdType;

typedef struct {
    uint8_t* SduDataPtr;
    uint8_t  SduLength;
} PduInfoType;



#endif /* AUTOSAR_IF_COMSTACK_TYPES_H_ */
