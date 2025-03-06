#ifndef IOHWAB_STEERINGSENSOR_H
#define IOHWAB_STEERINGSENSOR_H

#include "Std_Types.h"
#include <math.h>


/* Maximum steering angle in degrees */
#define MAX_STEERING_ANGLE 180U


Std_ReturnType IoHwAb_SteeringSensor_Init(void);
Std_ReturnType IoHwAb_SteeringSensor_Read();

#endif /* IOHWAB_STEERINGSENSOR_H */
