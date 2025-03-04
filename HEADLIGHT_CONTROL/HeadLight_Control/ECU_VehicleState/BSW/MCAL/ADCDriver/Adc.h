#ifndef ADC_H
#define ADC_H

#include "Std_Types.h"  // Include standard types
#include <stdint.h>

typedef unsigned int Adc_GroupType;
typedef unsigned int Adc_ValueGroupType;

/* ADC Group types */
typedef enum {
    SPEED_SENSOR_GROUP = 0,
    STEERING_SENSOR_GROUP = 1
} Adc_GroupType;

/* Simulate ADC Registers */
extern uint16_t AdcRegisters[10];

void ADC_Init();
void Adc_StartConversion(Adc_GroupType group);
Std_ReturnType Adc_ReadGroup(Adc_GroupType group, Adc_ValueGroupType* DataBufferPtr);

#endif /* ADC_H */
