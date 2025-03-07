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
#include "IoHwAb_AmbientSensor.h"
#include "Std_Types.h"
#include "Compiler.h"
#include "Compiler_Cfg.h"
#include "RTE_MemMap.h"
#include "ECU_HeadlightControl/SWC/Headlight_Controller.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
// void Rte_Ev_ReadSpeedAndSteering();  
// void Rte_Ev_SendSensorData();  

uint16 Rte_Ambient = 0;

extern FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadAmbientSensor(uint16 *ambient_check);
#define RTE_Ev_ReadAmbientSensor RTE_Ev_ReadAmbientSensor

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_AmbientSensor_Ambient(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient);
#define Rte_Write_PP_AmbientSensor_Ambient Rte_Write_PP_AmbientSensor_Ambient

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_AmbientSensor_Ambient(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient);
#define Rte_Read_RP_AmbientSensor_Ambient Rte_Read_RP_AmbientSensor_Ambient





#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_VEHICLESTATESENSOR_H */
