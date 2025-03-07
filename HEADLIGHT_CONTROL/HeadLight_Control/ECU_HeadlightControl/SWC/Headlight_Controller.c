#include "ECU_HeadlightControl/SWC/Headlight_Controller.h"

void ReadAmbientSensor(uint16 *ambient_check)
{
    Std_ReturnType status;

    
    status = Rte_Read_RP_AmbientSensor_Ambient(&vehicleState.Ambient);
	*ambient_check = vehicleState.Ambient;
    if (status != E_OK) {
        //printf("Failed to read Speed Sensor\n");
    }

}