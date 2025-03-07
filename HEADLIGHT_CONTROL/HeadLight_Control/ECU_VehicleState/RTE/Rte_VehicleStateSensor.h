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
#include "IoHwAb_SpeedSensor.h"
#include "IoHwAb_SteeringAngleSensor.h"
#include "Std_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "RTE_MemMap.h"
#include "ECU_VehicleState/BSW/Services/Com.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
// void Rte_Ev_ReadSpeedAndSteering();  
// void Rte_Ev_SendSensorData();  

typedef struct {
    sint16 angle;
    uint16 speed;
} DataSensor;
static DataSensor dataSensor;

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Ev_ReadSpeedAndSteering(int *speed_check, sint16 *angle_check);
#define Rte_Ev_ReadSpeedAndSteering Rte_Ev_ReadSpeedAndSteering

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Ev_SendSensorData(void);
#define Rte_Ev_SendSensorData Rte_Ev_SendSensorData

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SpeedSensor_Speed( P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Speed );
#define Rte_Read_RP_SpeedSensor_Speed Rte_Read_RP_SpeedSensor_Speed

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SteeringSensor_Angle( P2VAR(sint16, AUTOMATIC, RTE_APPL_DATA) Angle );
#define Rte_Read_RP_SteeringSensor_Angle Rte_Read_RP_SteeringSensor_Angle

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_SpeedSensor_Speed(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Speed);
#define Rte_Write_PP_SpeedSensor_Speed Rte_Write_PP_SpeedSensor_Speed

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_SteeringSensor_Angle(P2VAR(sint16, AUTOMATIC, RTE_APPL_DATA) Angle);
#define Rte_Write_PP_SteeringSensor_Angle Rte_Write_PP_SteeringSensor_Angle

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PP_VehicleStateFrame( P2CONST(uint8, AUTOMATIC, RTE_APPL_DATA) FrameData);
#define Rte_Write_PP_VehicleStateFrame Rte_Write_PP_VehicleStateFrame


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_VEHICLESTATESENSOR_H */
