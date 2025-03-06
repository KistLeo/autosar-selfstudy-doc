#include "IoHwAb_SteeringAngleSensor.h"
#include <stdio.h>
#include "Adc.h"
#include <stdlib.h>  
#include <stdint.h>  
#include "Rte_VehicleStateSensor.h"

Std_ReturnType IoHwAb_SteeringSensor_Init(void)
{
    ADC_Init();
    return E_OK;
}

//Std_ReturnType IoHwAb_SteeringSensor_Read(SteeringSensor_DataType *SensorData)
//{
//    if (SensorData == NULL) {
//        return E_NOT_OK;
//    }

//    Adc_ValueGroupType adcValue = 0;
//    
//    if (Adc_ReadGroup(STEERING_SENSOR_GROUP, &adcValue) != E_OK) {
//        return E_NOT_OK;
//    }

//    /* Convert ADC value to degrees */
//    SensorData->angle = (adcValue / 1023U) * MAX_STEERING_ANGLE;

//    return E_OK;
//}
Std_ReturnType IoHwAb_SteeringSensor_Read()
{
    sint16 angle = 0;

    Adc_ValueGroupType adcValue = 0;
    
    if (Adc_ReadGroup(STEERING_SENSOR_GROUP, &adcValue) != E_OK) {
        return E_NOT_OK;
    }

    /* Convert ADC value to degrees */
    //angle = (adcValue / 1023) * MAX_STEERING_ANGLE;
		
		angle = (rand() % (2 * MAX_STEERING_ANGLE + 1)) - MAX_STEERING_ANGLE;
    Std_ReturnType status = Rte_Write_PP_SteeringSensor_Angle(&angle);
    if (status != E_OK) {
        return E_NOT_OK;
    }
    return E_OK;
}