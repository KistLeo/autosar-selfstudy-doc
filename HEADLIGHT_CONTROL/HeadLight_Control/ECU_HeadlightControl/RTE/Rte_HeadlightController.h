/******************************************************************************/
/* Copyright   :                                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_VehicleStateSensor.h                                     */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : DinhN                                                         */
/* Note        :                                                              */
/******************************************************************************/
#ifndef RTE_HEADLIGHTCONTROLLER_H
#define RTE_HEADLIGHTCONTROLLER_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "BSW/ECU_Abstraction/COMAbstraction/VehicleState_CanRx.h"
#include "Std_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "RTE/Rte_MemMap.h"
#include "../SWC/Headlight_Controller.h"
#include "../BSW/Services/Pdu_Router.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
// void Rte_Ev_ReadSpeedAndSteering();  
// void Rte_Ev_SendSensorData();  

uint8 Rte_Speed=0;
uint16_t Rte_SteeringAngle=0;
uint16_t Rte_CameraData =0;
uint16 Rte_Ambient = 0;

extern HeadlightState Rte_HeadlightState;
extern HeadlightState Rte_HeadlightCommand;
extern HeadlightState Rte_HeadlightCurrentState;

//RTE service for reading the ambient sensor
extern FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadAmbientSensor(uint16 *ambient_check);
#define RTE_Ev_ReadAmbientSensor RTE_Ev_ReadAmbientSensor

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_AmbientSensor_Ambient(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient);
#define Rte_Write_PP_AmbientSensor_Ambient Rte_Write_PP_AmbientSensor_Ambient

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_AmbientSensor_Ambient(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient);
#define Rte_Read_RP_AmbientSensor_Ambient Rte_Read_RP_AmbientSensor_Ambient

//RTE service for speed sensor
extern FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadSpeedData(uint8_t *speed_check);
#define RTE_Ev_ReadSpeedData RTE_Ev_ReadSpeedData

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SpeedSensor_Speed( P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Speed );
#define Rte_Read_RP_SpeedSensor_Speed Rte_Read_RP_SpeedSensor_Speed

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_SpeedSensor_Speed(VAR(uint8, AUTOMATIC) Speed);
#define Rte_Write_PP_SpeedSensor_Speed Rte_Write_PP_SpeedSensor_Speed

//RTE service for steering sensor
extern FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadSteeringAngleData(sint16 *angle_check);
#define RTE_Ev_ReadSteeringAngleData RTE_Ev_ReadSteeringAngleData

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SteeringSensor_Angle( P2VAR(sint16, AUTOMATIC, RTE_APPL_DATA) Angle );
#define Rte_Read_RP_SteeringSensor_Angle Rte_Read_RP_SteeringSensor_Angle

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_SteeringSensor_Angle(VAR(sint16, AUTOMATIC) Angle);
#define Rte_Write_PP_SteeringSensor_Angle Rte_Write_PP_SteeringSensor_Angle


//service for computing headlight logic
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Write_PP_HeadlightController_HeadlightState(VAR(HeadlightState, AUTOMATIC) State);
#define RTE_Write_PP_HeadlightController_HeadlightState RTE_Write_PP_HeadlightController_HeadlightState //compute -> write state

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Read_RP_HeadlightController_HeadlightState(P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) State);
#define RTE_Read_RP_HeadlightController_HeadlightState RTE_Read_RP_HeadlightController_HeadlightState //actuator -> read state


extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Write_PP_HeadlightActuator_Command(VAR(HeadlightState, AUTOMATIC) Command);
#define RTE_Write_PP_HeadlightActuator_Command RTE_Write_PP_HeadlightActuator_Command //write comand to rte

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Write_PP_HeadlightActuator_State(VAR(HeadlightState, AUTOMATIC) State);
#define RTE_Write_PP_HeadlightActuator_State RTE_Write_PP_HeadlightActuator_State  //send back the state 

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Read_RP_HeadlightActuator_Command(P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) Command);
#define RTE_Read_RP_HeadlightActuator_Command RTE_Read_RP_HeadlightActuator_Command //read command from rte

extern FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ControlHeadlight ();
#define RTE_Ev_ControlHeadlight RTE_Ev_ControlHeadlight
  


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_VEHICLESTATESENSOR_H */
