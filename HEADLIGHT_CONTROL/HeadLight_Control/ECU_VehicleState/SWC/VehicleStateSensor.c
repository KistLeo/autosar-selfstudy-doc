#include "VehicleStateSensor.h"

void ReadSpeedAndSteering(void)
{
    Std_ReturnType status;

    
    status = Rte_Read_RP_SpeedSensor_Speed(&vehicleState.speed);
    if (status != E_OK) {
        printf("Failed to read Speed Sensor\n");
    }

    status = Rte_Read_RP_SteeringSensor_Angle(&vehicleState.steeringAngle);
    if (status != E_OK) {
        printf("Failed to read Steering Sensor\n");
    }
}
