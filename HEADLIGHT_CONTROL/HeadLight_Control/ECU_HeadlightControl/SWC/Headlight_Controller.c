#include "SWC/Headlight_Controller.h"

void ReadAmbientSensor(uint16 *ambient_check)
{
    Std_ReturnType status;

    
    status = Rte_Read_RP_AmbientSensor_Ambient(&headlightState.Ambient);
	*ambient_check = headlightState.Ambient;
    if (status != E_OK) {
        //printf("Failed to read Speed Sensor\n");
    }

}


void ReadSpeedData(uint8 *speed)
{   
    Std_ReturnType status;
    status = Rte_Read_RP_SpeedSensor_Speed(&headlightState.speed);
    *speed = headlightState.speed;
    if(status != E_OK)
    {
        //DEM
    }
}

void ReadSteeringAngleData(sint16 *angle)
{
    Std_ReturnType status;
    status = Rte_Read_RP_SteeringSensor_Angle(&headlightState.steeringAngle);
    *angle = headlightState.steeringAngle;
    if(status != E_OK)
    {
        //DEM
    }
}

void ComputeHeadlightLogic()
{

    HeadlightState headlightMode = HEADLIGHT_OFF;

   //morning, small speed, straight
    if ((headlightState.Ambient > 600 && headlightState.speed < 10) ||
        (headlightState.Ambient > 600 && -10 <= headlightState.steeringAngle && headlightState.steeringAngle <= 10)) {
        headlightMode = HEADLIGHT_OFF;
    }
    //night, normal speed, straight
    else if (headlightState.Ambient <= 600 && headlightState.speed >= 10 &&
             (-45 <= headlightState.steeringAngle && headlightState.steeringAngle <= 45)) {
        headlightMode = HEADLIGHT_NORMAL;
    }
    //night, high speed, turn
    else if (headlightState.Ambient <= 300 && headlightState.speed >= 80 &&
             (headlightState.steeringAngle <= -45 || headlightState.steeringAngle >= 45)) {
        headlightMode = HEADLIGHT_HIGH_BEAM;
    }

    RTE_Write_PP_HeadlightController_HeadlightState(headlightMode);
}