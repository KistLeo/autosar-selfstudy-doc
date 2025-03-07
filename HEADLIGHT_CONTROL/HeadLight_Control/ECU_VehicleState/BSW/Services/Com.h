#ifndef COM_H
#define COM_H

#include "Pdu_Router.h"
#include "Std_Types.h"
#include "Compiler.h"

#define PDU_ID_VEHICLE_STATE_FRAME  0x200  
#define VEHICLE_STATE_FRAME_LENGTH 8

FUNC(Std_ReturnType, COM_CODE) Com_SendSignal(PduIdType PduId, const PduInfoType* PduInfo);
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType PduId, Std_ReturnType result);

#endif /* COM_H */