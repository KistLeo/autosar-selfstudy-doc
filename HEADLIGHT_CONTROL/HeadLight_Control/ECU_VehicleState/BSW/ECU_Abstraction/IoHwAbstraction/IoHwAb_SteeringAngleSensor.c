#include "IoHwAb_SteeringAngleSensor.h"
#include <stdio.h>
#include "Adc.h"

Std_ReturnType IoHwAb_SteeringSensor_Init(void)
{
    ADC_Init();
    return E_OK;
}

Std_ReturnType IoHwAb_SteeringSensor_Read(SteeringSensor_DataType *SensorData)
{
    if (SensorData == NULL) {
        return E_NOT_OK;
    }

    Adc_ValueGroupType adcValue = 0;
    
    if (Adc_ReadGroup(STEERING_SENSOR_GROUP, &adcValue) != E_OK) {
        return E_NOT_OK;
    }

    /* Convert ADC value to degrees */
    SensorData->angle = ((float)adcValue / 1023.0f) * MAX_STEERING_ANGLE;

    return E_OK;
}
