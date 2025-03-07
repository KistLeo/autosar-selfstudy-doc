#include "ECU_VehicleState/BSW/Services/Com.h"
#include "Compiler_Cfg.h"
#include "Com.h"

/* Gửi dữ liệu từ COM đến PDU Router */
FUNC(Std_ReturnType, COM_CODE) Com_SendSignal(PduIdType PduId, const PduInfoType* PduInfo) {
    return PduR_ComTransmit(PduId, PduInfo);
}

/* Nhận xác nhận từ PDU Router */
FUNC(void, COM_CODE) Com_TxConfirmation(PduIdType PduId, Std_ReturnType result) {
    if (result == E_OK) {
        /* Dữ liệu được gửi thành công */
    } else {
        /* Xử lý lỗi truyền */
    }
}