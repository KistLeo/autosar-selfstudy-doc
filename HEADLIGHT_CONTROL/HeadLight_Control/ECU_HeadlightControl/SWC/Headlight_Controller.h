#ifndef HEADLIGHT_CONTROLLER_H
#define HEADLIGHT_CONTROLLER_H

#include "Rte_HeadlightController.h"
#include "Std_Types.h"

#include "Rte_HeadlightController.h"
#include "Std_Types.h"
#include "stdint.h"
#include <stdlib.h>


typedef struct {
    uint16 Ambient;            
    uint8 speed;            
    uint16 steeringAngle;    
} HeadlightControllerData_App;
static HeadlightControllerData_App headlightState;

void ReadSpeedData(uint8 *speed);
void ReadSteeringAngleData(sint16 *angle);
void ReadAmbientSensor(uint16 *ambient_check);
void ComputeHeadlightLogic();

#endif /* HEADLIGHT_CONTROLLER_H */