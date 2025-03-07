#include "Pdu_Router.h"
#include "Com.h"
#include "ECU_VehicleState/RTE/RTE_MemMap.h"          /* Đảm bảo bộ nhớ được ánh xạ đúng */

/* Chuyển tiếp dữ liệu từ COM xuống CanIf */
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType PduId, const PduInfoType* PduInfo) {
    return CanIf_Transmit(PduId, PduInfo);
}

/* Nhận phản hồi từ CanIf và gửi về COM */
FUNC(void, PDUR_CODE) PduR_TxConfirmation(PduIdType PduId, Std_ReturnType result) {
    Com_TxConfirmation(PduId, result);
}