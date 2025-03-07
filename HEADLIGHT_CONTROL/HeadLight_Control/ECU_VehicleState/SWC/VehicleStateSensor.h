#include "Rte_VehicleStateSensor.h"
#include "Std_Types.h"
#include "stdint.h"
#include <stdlib.h>
typedef struct {
    uint16 speed;         
    sint16 steeringAngle; 
} VehicleStateData;
static VehicleStateData vehicleState;  
extern FUNC(void, RTE_CODE) SendSensorData(void);