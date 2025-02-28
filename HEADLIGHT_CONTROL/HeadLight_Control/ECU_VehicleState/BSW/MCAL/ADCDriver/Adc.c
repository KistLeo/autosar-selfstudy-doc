#include "Adc.h"


/* Start ADC conversion (simulated) */
void Adc_StartConversion(Adc_GroupType group) {
    if (group == SPEED_SENSOR_GROUP) {
        AdcRegisters[group] = 512;  
    } else if (group == STEERING_SENSOR_GROUP) {
        AdcRegisters[group] = 300;  
    }
}

/* Read the ADC value for a specific group */
Std_ReturnType Adc_ReadGroup(Adc_GroupType group, Adc_ValueGroupType* DataBufferPtr) {
    *DataBufferPtr = AdcRegisters[group];  // Return ADC value
    return E_OK;
}

void ADC_Init() {
    /* Initialize ADC registers */
    for (int i = 0; i < 10; i++) {
        AdcRegisters[i] = 0;
    }
}   