#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include "Std_Types.h"

/* Maximum Speed in km/h based on ADC full scale */
#define MAX_SPEED_KMH 250.0f  

typedef struct {
    float speed;
} SpeedSensor_DataType;

Std_ReturnType IoHwAb_SpeedSensor_Init();
Std_ReturnType IoHwAb_SpeedSensor_Read(SpeedSensor_DataType *SensorData);

#endif /* IOHWAB_SPEEDSENSOR_H */
