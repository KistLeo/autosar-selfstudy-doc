#ifndef VEHICLESTATE_CANRX_H
#define VEHICLESTATE_CANRX_H


#include "Std_Types.h"
#include "stdint.h"

/* Service IDs */
#define CANIF_SID_RX_INDICATION     0x14
#define CANIF_SID_READ_RX_PDU_DATA  0x1A

/* Error codes */
#define CANIF_E_PARAM_HOH           0x10
#define CANIF_E_PARAM_CANID         0x11
#define CANIF_E_PARAM_POINTER       0x12
#define CANIF_E_INVALID_DATA_LENGTH 0x13
#define CANIF_E_UNINIT              0x14

/* Giả định PduInfoType từ AUTOSAR */
typedef struct {
    uint8_t* SduDataPtr;    // Pointer tới dữ liệu L-SDU
    uint8_t SduLength;      // Độ dài dữ liệu
} PduInfoType;

/* Cấu hình cho mỗi Rx PDU */
typedef struct {
    Can_IdType CanId;           // CAN ID của Rx PDU
    Can_HwHandleType Hoh;       // Hardware Object Handle
    boolean ReadDataEnabled;    // CanIfRxPduReadData
    uint8_t* Buffer;            // Buffer lưu L-SDU
    uint8_t BufferSize;         // Kích thước buffer
} CanIf_RxPduConfigType;

/* Cấu hình tổng thể cho CanIf */
typedef struct {
    uint8_t RxPduCount;
    const CanIf_RxPduConfigType* RxPduConfig;
} CanIf_ConfigType;

/* API của CanIf */
void CanIf_Init(const CanIf_ConfigType* Config);
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr);
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxPduId, PduInfoType* PduInfoPtr);


#endif /* VEHICLESTATE_CANRX_H */