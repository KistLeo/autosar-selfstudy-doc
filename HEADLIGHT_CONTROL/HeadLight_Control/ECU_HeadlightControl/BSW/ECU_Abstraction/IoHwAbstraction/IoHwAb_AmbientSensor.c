#include "BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_AmbientSensor.h"
#include "stdio.h"
#include "BSW/MCAL/ADCDriver/Adc.h"
#include <stdlib.h>  
#include <stdint.h>

Std_ReturnType IoHwAb_AmbientSensor_Init()
{
    ADC_Init();
    return E_OK;
}


Std_ReturnType IoHwAb_AmbientSensor_Read()
{
    uint16 Ambient = 0;

    Adc_ValueGroupType adcValue = 0;

    Adc_StartConversion(AMBIENT_SENSOR_GROUP);
    if (Adc_ReadGroup(AMBIENT_SENSOR_GROUP, &adcValue) != E_OK) {
        return E_NOT_OK;
    }

    /* Convert ADC value to km/h */
    //Speed = (adcValue / 1023) * MAX_SPEED_KMH;
		Ambient = rand() % (MAX_AMBIENT + 1);
     /* Write the speed value to RTE */
    Std_ReturnType status = Rte_Write_PP_AmbientSensor_Ambient(&Ambient);
    if (status != E_OK) {
        return E_NOT_OK;
    }
    return E_OK;
}