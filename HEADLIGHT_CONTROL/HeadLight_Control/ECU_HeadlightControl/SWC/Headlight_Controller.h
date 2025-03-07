#include "Rte_HeadlightController.h"
#include "Std_Types.h"
#include "stdint.h"
#include <stdlib.h>
typedef struct {
    uint16 Ambient;         
} VehicleStateData;
static VehicleStateData vehicleState;  