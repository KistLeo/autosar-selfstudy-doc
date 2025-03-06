#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include "Std_Types.h"
#include <math.h>


/* Maximum Speed in km/h based on ADC full scale */
#define MAX_SPEED_KMH 250U


Std_ReturnType IoHwAb_SpeedSensor_Init();
Std_ReturnType IoHwAb_SpeedSensor_Read();

#endif /* IOHWAB_SPEEDSENSOR_H */
