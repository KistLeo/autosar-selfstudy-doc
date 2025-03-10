#include "BSW/ECU_Abstraction/COMAbstraction/VehicleState_CanRx.h"
#include <stddef.h>
#include "BSW/Services/Pdu_Router.h"

/* Biến toàn cục */
static const CanIf_ConfigType* CanIfConfig = NULL;
static boolean CanIfInitialized = FALSE;

/* Khởi tạo CanIf */
void CanIf_Init(const CanIf_ConfigType* Config)
{
    CanIfConfig = Config;
    CanIfInitialized = TRUE;
}

/* Callback xử lý dữ liệu nhận được từ Can Driver */
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr)
{
    uint8_t i;

    /* Kiểm tra khởi tạo */
    if (!CanIfInitialized) {
        //DCM: Diagnostic Communication Manager
        return;
    }

    /* Kiểm tra tham số */
    if (Mailbox == NULL || PduInfoPtr == NULL) {
        ////DEM: Diagnostic Communication Manager Det_ReportError(CANIF_MODULE_ID, 0, CANIF_SID_RX_INDICATION, CANIF_E_PARAM_POINTER);
        return;
    }
    if (Mailbox->Hoh >= 255) { // Giả định giới hạn Hoh
        // DEM: Det_ReportError(CANIF_MODULE_ID, 0, CANIF_SID_RX_INDICATION, CANIF_E_PARAM_HOH);
        return;
    }
    if ((Mailbox->CanId & CAN_ID_STANDARD_MASK) == 0) { // Giả định kiểm tra CAN ID
        //DEM Det_ReportError(CANIF_MODULE_ID, 0, CANIF_SID_RX_INDICATION, CANIF_E_PARAM_CANID);
        return;
    }
    if (PduInfoPtr->SduLength > 8) { // Kiểm tra độ dài dữ liệu
        //DEM Det_ReportError(CANIF_MODULE_ID, 0, CANIF_SID_RX_INDICATION, CANIF_E_INVALID_DATA_LENGTH);
        return;
    }

    /* Duyệt qua các Rx PDU để tìm cấu hình phù hợp */
    for (i = 0; i < CanIfConfig->RxPduCount; i++) {
        if (CanIfConfig->RxPduConfig[i].CanId == Mailbox->CanId &&
            CanIfConfig->RxPduConfig[i].Hoh == Mailbox->Hoh) {
            /* Lưu dữ liệu vào buffer nếu ReadData được bật */
            if (CanIfConfig->RxPduConfig[i].ReadDataEnabled) {
                if (PduInfoPtr->SduLength <= CanIfConfig->RxPduConfig[i].BufferSize) {
                    for (uint8_t j = 0; j < PduInfoPtr->SduLength; j++) {
                        CanIfConfig->RxPduConfig[i].Buffer[j] = PduInfoPtr->SduDataPtr[j];
                    }
                }
            }
            break;
        }
    }
}

/* Đọc dữ liệu L-SDU từ buffer */
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxPduId, PduInfoType* PduInfoPtr)
{
    if (!CanIfInitialized) {
        //DEM Det_ReportError(CANIF_MODULE_ID, 0, CANIF_SID_READ_RX_PDU_DATA, CANIF_E_UNINIT);
        return E_NOT_OK;
    }
    if (CanIfRxPduId >= CanIfConfig->RxPduCount) {
        return E_NOT_OK;
    }
    if (PduInfoPtr == NULL) {
        //DEM Det_ReportError(CANIF_MODULE_ID, 0, CANIF_SID_READ_RX_PDU_DATA, CANIF_E_PARAM_POINTER);
        return E_NOT_OK;
    }

    const CanIf_RxPduConfigType* rxPdu = &CanIfConfig->RxPduConfig[CanIfRxPduId];
    if (!rxPdu->ReadDataEnabled) {
        return E_NOT_OK; // Không hỗ trợ đọc dữ liệu
    }

    PduInfoPtr->SduDataPtr = rxPdu->Buffer;
    PduInfoPtr->SduLength = 2; 
    PduR_RxIndication(CanIfRxPduId, PduInfoPtr);

    return E_OK;
}