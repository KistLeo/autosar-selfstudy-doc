#ifndef IOHWAB_AMBIENTSENSOR_H
#define IOHWAB_AMBIENTSENSOR_H


#include "Std_Types.h"
#include <math.h>
#include "RTE/Rte_HeadlightController.h"


/* Maximum Speed in km/h based on ADC full scale */
#define MAX_AMBIENT 1000U


Std_ReturnType IoHwAb_AmbientSensor_Init();
Std_ReturnType IoHwAb_AmbientSensor_Read();

#endif /* IOHWAB_AMBIENTSENSOR_H */
