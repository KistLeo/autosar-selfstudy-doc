#ifndef CAN_H
#define CAN_H

#include "Std_Types.h"
#include "Compiler_Cfg.h"
#include "Compiler.h"
#include "VehicleState_CanTx.h"
//#include "ECU_VehicleState/BSW/Services/Pdu_Router.h"

FUNC(Std_ReturnType, CANDRV_CODE) Can_Write(Can_HwHandleType Hth, const Can_PduType* PduInfo);
FUNC(void, CANDRV_CODE) Can_TxConfirmation(PduIdType PduId, Std_ReturnType result);

#endif /* CAN_H */