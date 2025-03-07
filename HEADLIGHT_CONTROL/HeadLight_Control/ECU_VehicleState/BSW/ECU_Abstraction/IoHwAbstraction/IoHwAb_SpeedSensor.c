#include "IoHwAb_SpeedSensor.h"
#include "stdio.h"
#include "Adc.h"
#include <stdlib.h>  
#include <stdint.h>
#include "Rte_VehicleStateSensor.h"

Std_ReturnType IoHwAb_SpeedSensor_Init()
{
    ADC_Init();
    return E_OK;
}


Std_ReturnType IoHwAb_SpeedSensor_Read()
{
    uint16 Speed = 0;

    Adc_ValueGroupType adcValue = 0;

    Adc_StartConversion(SPEED_SENSOR_GROUP);
    if (Adc_ReadGroup(SPEED_SENSOR_GROUP, &adcValue) != E_OK) {
        return E_NOT_OK;
    }

    /* Convert ADC value to km/h */
    //Speed = (adcValue / 1023) * MAX_SPEED_KMH;
		Speed = rand() % (MAX_SPEED_KMH + 1);
     /* Write the speed value to RTE */
    Std_ReturnType status = Rte_Write_PP_SpeedSensor_Speed(&Speed);
    if (status != E_OK) {
        return E_NOT_OK;
    }

    return E_OK;

}