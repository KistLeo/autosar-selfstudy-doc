#include "ECU_VehicleState/BSW/Services/Os.h"
#include "ECU_VehicleState/RTE/Rte_VehicleStateSensor.h"  

DeclareTask(AppTask_SensorProcessing);


TASK(AppTask_SensorProcessing) {
    EventMaskType events;
    
    while (1) {
        WaitEvent(Ev_SensorUpdate | Ev_SensorDataSent);
        GetEvent(AppTask_SensorProcessing, &events);
        ClearEvent(events);

        
        if (events & Ev_SensorUpdate) {
            Rte_Ev_ReadSpeedAndSteering();  
            
            SetEvent(AppTask_SensorProcessing, Ev_SensorDataSent);
        }

        if (events & Ev_SensorDataSent) {
            Rte_Ev_SendSensorData();  
        }
    }
}
