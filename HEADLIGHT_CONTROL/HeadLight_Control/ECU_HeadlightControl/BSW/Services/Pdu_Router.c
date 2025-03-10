#include "BSW/Services/Pdu_Router.h"
#include "Com.h"
#include "BSW/ECU_Abstraction/COMAbstraction/VehicleState_CanRx.h"
#include "stddef.h"

/* Hàm xử lý dữ liệu từ CAN Interface */
void PduR_RxIndication(PduIdType pduId, const PduInfoType* PduInfoPtr)
{
    if (PduInfoPtr == NULL || PduInfoPtr->SduDataPtr == NULL) {
        return; 
    }

    /* Gửi dữ liệu lên COM Service */
    switch (pduId)
    {
        case CAN_MSG_ID_SPEED:
            Com_WriteSpeedData(PduInfoPtr->SduDataPtr[0]);  // Ghi tốc độ vào COM
            break;
        case CAN_MSG_ID_STEERING_ANGLE:
            Com_WriteSteeringAngleData(PduInfoPtr->SduDataPtr[1]);  // Ghi góc lái vào COM
            break;
        default:
            // Xử lý trường hợp CAN ID không hợp lệ
            break;
    }
}
