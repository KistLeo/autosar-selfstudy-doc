#ifndef CAN_H
#define CAN_H

#include <stdint.h>
#include "Common/Std_Types.h"
#include "BSW/ECU_Abstraction/COMAbstraction/VehicleState_CanRx.h"


/* Service IDs */
#define CAN_SID_INIT            0x00
#define CAN_SID_MAIN_READ       0x08

/* API của CAN Driver */
void Can_Init(const Can_ConfigType* Config);
void Can_MainFunction_Read(void);

#endif /* CAN_H */