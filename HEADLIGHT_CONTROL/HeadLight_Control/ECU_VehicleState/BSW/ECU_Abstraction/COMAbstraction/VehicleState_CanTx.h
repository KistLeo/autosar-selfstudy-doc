/* CanIf.h */

#ifndef VEHICLESTATE_CANIF_H
#define VEHICLESTATE_CANIF_H


#include "ECU_VehicleState/BSW/MCAL/CANDriver/Can.h"
#include "ECU_VehicleState/BSW/Services/Pdu_Router.h"



typedef struct {
    PduIdType swPduHandle;  // Handle của PDU
    uint8 length;           // Độ dài dữ liệu
    Can_IdType id;          // ID của CAN
    uint8* sdu;             // Con trỏ đến dữ liệu
} Can_PduType;

FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(PduIdType TxPduId, const PduInfoType* PduInfo);
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType PduId, Std_ReturnType result);

#endif /* VEHICLESTATE_CANIF_H */