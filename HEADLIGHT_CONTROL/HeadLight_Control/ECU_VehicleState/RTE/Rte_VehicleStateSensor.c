#include "ECU_VehicleState/RTE/Rte_VehicleStateSensor.h"


/* AUTOSAR Version Check : Com */
#if ( ( COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION )\
|| ( COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION ) )
#error "AUTOSAR Release Version error between Com and RTE." 
#endif


// void Rte_Ev_ReadSpeedAndSteering(){
//     ReadSpeedAndSteering(); 
// }
// void Rte_Ev_SendSensorData(){
//     SendSensorData(); 
// }

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Ev_ReadSpeedAndSteering                                 */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Reads speed and steering data from the sensor layer         */
/* Author      : DinhN                                                         */
/******************************************************************************/
FUNC(void, RTE_CODE_EcucPartition_0) Rte_Ev_ReadSpeedAndSteering(void)
{
    ReadSpeedAndSteering();
}

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Ev_SendSensorData                                       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Sends sensor data to the appropriate system component        */
/* Author      : DinhN                                                         */
/******************************************************************************/
FUNC(void, RTE_CODE_EcucPartition_0) Rte_Ev_SendSensorData(void)
{
    SendSensorData();
}

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SpeedSensor_Read( P2VAR(SpeedSensor_DataType, AUTOMATIC, RTE_APPL_DATA) sensorData );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_RP_SpeedSensor_Speed                               */
/* Param       : P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Speed                 */
/*               - Pointer to store the speed value                           */
/* Return      : Std_ReturnType                                                */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads speed from the speed sensor and stores it in `Speed`   */
/* Author      : DinhN                                                         */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "ECU_VehicleState/RTE/RTE_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SpeedSensor_Speed(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Speed)
{
    SpeedSensor_DataType sensorData;
    Std_ReturnType status;

    /* Read speed sensor data from the IoHwAbstraction Layer */
    status = IoHwAb_SpeedSensor_Read(&sensorData);

    if (status == E_OK) {
        *Speed = sensorData.speed;  
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}
#define RTE_STOP_SEC_CODE_EcucPartition_0


extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SteeringSensor_Read( P2VAR(SteeringSensor_DataType, AUTOMATIC, RTE_APPL_DATA) sensorData );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_RP_SteeringSensor_Angle                            */
/* Param       : P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Angle                 */
/*               - Pointer to store the steering angle value                  */
/* Return      : Std_ReturnType                                                */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads steering angle from the sensor and stores it in `Angle`*/
/* Author      : DinhN                                                         */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "ECU_VehicleState/RTE/RTE_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SteeringSensor_Angle(P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Angle)
{
    SteeringSensor_DataType sensorData;
    Std_ReturnType status;

    /* Read steering sensor data from the IoHwAbstraction Layer */
    status = IoHwAb_SteeringSensor_Read(&sensorData);

    if (status == E_OK) {
        *Angle = sensorData.angle;  
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}
#define RTE_STOP_SEC_CODE_EcucPartition_0












// /******************************************************************************/
// /* ModuleID    :                                                              */
// /* ServiceID   :                                                              */
// /* Name        : Rte_Read_RP_SteeringSensor_Angle                            */
// /* Param       : P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Angle                 */
// /*               - Pointer to store the steering angle value                  */
// /* Return      : Std_ReturnType                                                */
// /*               - E_OK if successful, E_NOT_OK if error                      */
// /* Contents    : Reads steering angle from the sensor and stores it in `Angle`*/
// /* Author      : DinhN                                                         */
// /******************************************************************************/
// Std_ReturnType Rte_Read_RP_SteeringSensor_Angle(float* Angle)
// {
//     SteeringSensor_DataType sensorData;
//     Std_ReturnType status;

//     /* Read steering sensor data from the IoHwAbstraction Layer */
//     status = IoHwAb_SteeringSensor_Read(&sensorData);

//     if (status == E_OK) {
//         *Angle = sensorData.angle;  
//         return E_OK;
//     } else {
//         return E_NOT_OK;
//     }
// }