#include "VehicleStateSensor.h"

void ReadSpeedAndSteering(int *speed_check, sint16 *angle_check)
{
    Std_ReturnType status;

    
    status = Rte_Read_RP_SpeedSensor_Speed(&vehicleState.speed);
		*speed_check = vehicleState.speed;
    if (status != E_OK) {
        //printf("Failed to read Speed Sensor\n");
    }

    status = Rte_Read_RP_SteeringSensor_Angle(&vehicleState.steeringAngle);
		*angle_check = vehicleState.steeringAngle;
    if (status != E_OK) {
        //printf("Failed to read Steering Sensor\n");
    }
}
void SendSensorData(){}