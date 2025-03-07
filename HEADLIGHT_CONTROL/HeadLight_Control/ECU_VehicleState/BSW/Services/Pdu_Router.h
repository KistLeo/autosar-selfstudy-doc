#ifndef PDU_ROUTER_H
#define PDU_ROUTER_H


#include "Std_Types.h"
#include "Compiler_Cfg.h"

typedef struct {
    uint8* SduDataPtr;
    uint8 SduLength;
} PduInfoType;


FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType PduId, const PduInfoType* PduInfo);
FUNC(void, PDUR_CODE) PduR_TxConfirmation(PduIdType PduId, Std_ReturnType result);

#endif /* PDU_ROUTER_H */