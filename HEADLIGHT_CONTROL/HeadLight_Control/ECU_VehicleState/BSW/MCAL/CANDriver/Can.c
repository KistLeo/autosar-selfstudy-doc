#include "ECU_VehicleState/BSW/MCAL/CANDriver/Can.h"


/* Gửi dữ liệu thực tế trên bus CAN */
FUNC(Std_ReturnType, CANDRV_CODE) Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo) {
    /* Kiểm tra dữ liệu có hợp lệ không */
    if (PduInfo->length > 0) {
        uint8* data_ptr_check = PduInfo ->sdu;
        uint8 data_check = *data_ptr_check;
        Can_TxConfirmation(Hth, E_OK);
        return E_OK;
    } else {
        Can_TxConfirmation(Hth, E_NOT_OK);
        return E_NOT_OK;
    }
}

/* Nhận phản hồi từ phần cứng CAN */
FUNC(void, CANDRV_CODE) Can_TxConfirmation(PduIdType PduId, Std_ReturnType result) {
    CanIf_TxConfirmation(PduId, result);
}