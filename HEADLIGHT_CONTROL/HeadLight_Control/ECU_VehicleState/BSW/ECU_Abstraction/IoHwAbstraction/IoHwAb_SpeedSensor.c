#include "IoHwAb_SpeedSensor.h"
#include "stdio.h"
#include "Adc.h"

Std_ReturnType IoHwAb_SpeedSensor_Init()
{
    ADC_Init();
    return E_OK;
}

Std_ReturnType IoHwAb_SpeedSensor_Read(SpeedSensor_DataType *SensorData)
{
    if (SensorData == NULL) {
        return E_NOT_OK;
    }

    Adc_ValueGroupType adcValue = 0;
    
    if (Adc_ReadGroup(SPEED_SENSOR_GROUP, &adcValue) != E_OK) {
        return E_NOT_OK;
    }

    /* Convert ADC value to km/h */
    SensorData->speed = ((float)adcValue / 1023.0f) * MAX_SPEED_KMH;

    return E_OK;
}
