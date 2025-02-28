#ifndef IOHWAB_STEERINGSENSOR_H
#define IOHWAB_STEERINGSENSOR_H

#include "Std_Types.h"

/* Maximum steering angle in degrees */
#define MAX_STEERING_ANGLE 45.0f  

typedef struct {
    float angle; // Steering angle in degrees
} SteeringSensor_DataType;

Std_ReturnType IoHwAb_SteeringSensor_Init(void);
Std_ReturnType IoHwAb_SteeringSensor_Read(SteeringSensor_DataType *SensorData);

#endif /* IOHWAB_STEERINGSENSOR_H */
