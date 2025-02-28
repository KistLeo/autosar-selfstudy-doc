/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_VehicleStateSensor.h                                     */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : DinhN                                                         */
/* Note        :                                                              */
/******************************************************************************/
#ifndef RTE_VEHICLESTATESENSOR_H
#define RTE_VEHICLESTATESENSOR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "ECU_VehicleState/BSW/ECU_Abstraction/IoHwAbstraction/IoHwAb_SpeedSensor.h"
#include "IoHwAb_SteeringAngleSensor.h"
#include "Common/Std_Types.h"
#include "Common/Compiler.h"
#include "Common/Compiler_Cfg.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
// void Rte_Ev_ReadSpeedAndSteering();  
// void Rte_Ev_SendSensorData();  

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Ev_ReadSpeedAndSteering(void);
#define Rte_Ev_ReadSpeedAndSteering Rte_Ev_ReadSpeedAndSteering

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Ev_SendSensorData(void);
#define Rte_Ev_SendSensorData Rte_Ev_SendSensorData

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SpeedSensor_Speed( P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Speed );
#define Rte_Read_RP_SpeedSensor_Speed Rte_Read_RP_SpeedSensor_Speed

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SteeringSensor_Angle( P2VAR(float, AUTOMATIC, RTE_APPL_DATA) Angle );
#define Rte_Read_RP_SteeringSensor_Angle Rte_Read_RP_SteeringSensor_Angle



#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_VEHICLESTATESENSOR_H */
