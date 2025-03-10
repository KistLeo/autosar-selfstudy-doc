#ifndef PDU_ROUTER_H
#define PDU_ROUTER_H

#include "Std_Types.h"
#include <stdint.h>

#define CAN_MSG_ID_SPEED           0x101  
#define CAN_MSG_ID_STEERING_ANGLE  0x102  

void PduR_RxIndication(PduIdType pduId, const PduInfoType* PduInfoPtr);

#endif /* PDU_ROUTER_H */