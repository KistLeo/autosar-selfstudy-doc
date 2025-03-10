#include "Can.h"

//siimulation data
static uint8_t simulatedCanTxData[8] = {120, 45, 0, 0, 0, 0, 0, 0}; 

void Can_Init(const Can_ConfigType* Config)
{
    Can_ConfigType CanConfig = *Config; 
    printf("CAN Driver initialized.\n");
}

/* Giả lập hàm nhận dữ liệu từ CAN bus (polling mode) */
Std_ReturnType Can_ReceiveData(Can_HwHandleType hwHandle, Can_PduType* pdu)
{
    /* Giả lập dữ liệu từ CANTx */
    pdu->swPduHandle = 1;           // Handle giả lập
    pdu->length = 2;                // Độ dài dữ liệu (2 byte: 120, 45)
    pdu->id = 0x123;                // CAN ID giả lập (Standard ID)
    pdu->sdu = simulatedCanTxData;  // Pointer tới dữ liệu giả lập
    
    return E_OK; 
}

/* Hàm Can_MainFunction_Read để polling dữ liệu */
void Can_MainFunction_Read(void)
{
    Can_PduType rxPdu;
    Can_HwType mailbox = {0x123, 0, 0}; 
    
    if (Can_ReceiveData(0, &rxPdu) == E_OK) {
        CanIf_RxIndication(&mailbox, &rxPdu); // Gọi callback lên CanIf
    }
}