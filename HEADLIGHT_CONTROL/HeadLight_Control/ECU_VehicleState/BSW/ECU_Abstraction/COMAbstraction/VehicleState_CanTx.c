#include "ECU_VehicleState/BSW/ECU_Abstraction/COMAbstraction/VehicleState_CanTx.h"

FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit(PduIdType TxPduId, const PduInfoType* PduInfo) {
    Can_HwHandleType Hth = TxPduId;  // Map TxPduId → HTH
    Can_IdType CanId = TxPduId;   // Map TxPduId → CAN ID

    /* Tạo struct Can_PduType từ PduInfoType */
    Can_PduType CanPdu;
    CanPdu.swPduHandle = TxPduId;
    CanPdu.length = PduInfo->SduLength;
    CanPdu.id = CanId;
    CanPdu.sdu = PduInfo->SduDataPtr;

    /* Gọi Can_Write() từ Can Driver */
    return Can_Write(Hth, &CanPdu);
}
/* Nhận phản hồi từ CAN Driver và gửi về PDU Router */
FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType PduId, Std_ReturnType result) {
    PduR_TxConfirmation(PduId, result);
}