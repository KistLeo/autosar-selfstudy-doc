#include "ECU_VehicleState/RTE/Rte_VehicleStateSensor.h"
#include "Std_Types.h"

typedef struct {
    float speed;         
    float steeringAngle; 
} VehicleStateData;

static VehicleStateData vehicleState;  
