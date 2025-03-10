#include "Com.h"
#include "RTE/Rte_HeadlightController.c"

// Ghi tốc độ lên RTE
void Com_WriteSpeedData(uint16_t speed)
{
    RTE_Write_PP_SpeedSensor_Speed(speed); 
}

void Com_WriteSteeringAngleData(sint16 steeringAngle)
{
    RTE_Write_PP_SteeringSensor_Angle(steeringAngle); 
}