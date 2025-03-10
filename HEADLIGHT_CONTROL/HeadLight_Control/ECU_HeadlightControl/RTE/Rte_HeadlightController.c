#include "Rte_HeadlightController.h"
#include "../SWC/Headlight_Controller.h"

/* AUTOSAR Version Check : Com */
#if ( ( COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION )\
|| ( COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION ) )
#error "AUTOSAR Release Version error between Com and RTE." 
#endif


/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : RTE_Ev_ReadAmbientSensor                                     */
/* Param       : uint16 *ambient_check                                        */
/*               - Pointer to store the ambient light value                   */
/* Return      : None                                                          */
/* Contents    : Reads ambient light data from the sensor layer               */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadAmbientSensor(uint16 *ambient_check)
{
    ReadAmbientSensor(ambient_check);
}

#define RTE_STOP_SEC_CODE_EcucPartition_0



/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_PP_AmbientSensor_Ambient                           */
/* Param       : P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient             */
/*               - Pointer to store the ambient light value                   */
/* Return      : Std_ReturnType                                                */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Writes ambient light value to the global DataSensor struct   */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_AmbientSensor_Ambient(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient)
{
    if (Ambient != NULL_PTR) {
        Rte_Ambient = *Ambient; 
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0


/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_RP_AmbientSensor_Ambient                            */
/* Param       : P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient              */
/*               - Pointer to store the ambient light value                   */
/* Return      : Std_ReturnType                                                */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads ambient light from the ambient sensor and stores it    */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_AmbientSensor_Ambient(P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Ambient)
{
    /* Validate the input pointer */
    if (Ambient == NULL_PTR) {
        return E_NOT_OK;  
    }

    Std_ReturnType status;

    /* Read the Ambient Sensor */
    status = IoHwAb_AmbientSensor_Read();
    
    if (status == E_OK) {
        *Ambient = Rte_Ambient; 
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0


/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : RTE_Ev_ReadSpeedData                                         */
/* Param       : uint8_t *speed_check                                         */
/*               - Pointer to store the speed data                            */
/* Return      : None                                                          */
/* Contents    : Reads speed data from the speed sensor layer                 */
/* Author      :  DinhN                                                       */
/******************************************************************************/ 
FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadSpeedData(uint8_t *speed_check)
{
    ReadSpeedData(speed_check);
}

/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_RP_SpeedSensor_Speed                                */
/* Param       : P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) Speed                */
/*               - Pointer to store the speed value                           */
/* Return      : Std_ReturnType                                                */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads speed data from the Speed Sensor and stores it in `Speed`*/
/* Author      : DinhN                                                        */
/******************************************************************************/ 
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SpeedSensor_Speed(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) Speed)
{
    //Call down layer to read speed data here and then update to Rte_Speed
    PduInfoType pduInfo;
    Std_ReturnType status;

    if (Speed == NULL_PTR) {
        return E_NOT_OK;
    }

    /* Gọi xuống Can Interface để đọc dữ liệu từ buffer */
    status = CanIf_ReadRxPduData(CAN_MSG_ID_SPEED, &pduInfo);
    if (Speed != NULL_PTR) {
        *Speed = Rte_Speed;  
        return E_OK;         // Trả về thành công
    }

    return E_NOT_OK;  // Trả về lỗi nếu con trỏ `Speed` là NULL
}
/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_PP_SpeedSensor_Speed                               */
/* Param       : VAR(uint8, AUTOMATIC) Speed                                  */
/*               - Speed value to be written to the RTE                       */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Writes the speed data to the RTE global variable `Rte_Speed` */
/*               so that it can be accessed by other software components      */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_SpeedSensor_Speed(VAR(uint8, AUTOMATIC) Speed)
{
    Rte_Speed = Speed; 
    return E_OK;
}


/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : RTE_Ev_ReadSteeringAngleData                                 */
/* Param       : sint16 *angle_check                                          */
/*               - Pointer to store the steering angle data                   */
/* Return      : None                                                          */
/* Contents    : Reads steering angle data from the steering sensor layer     */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ReadSteeringAngleData(sint16 *angle_check)
{
    ReadSteeringAngleData(angle_check);
}
/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_RP_SteeringAngleSensor_Angle                        */
/* Param       : P2VAR(sint16, AUTOMATIC, RTE_APPL_DATA) Angle                */
/*               - Pointer to store the steering angle value                  */
/* Return      : Std_ReturnType                                                */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads steering angle data from the Sensor and stores it      */
/*               in `Angle`                                                   */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_SteeringAngleSensor_Angle(P2VAR(sint16, AUTOMATIC, RTE_APPL_DATA) Angle)
{
    PduInfoType pduInfo;
    Std_ReturnType status;

    if (Angle == NULL_PTR) {
        return E_NOT_OK;
    }

    /* Gọi Can Interface để đọc dữ liệu từ buffer */
    status = CanIf_ReadRxPduData(CAN_MSG_ID_STEERING_ANGLE, &pduInfo);

    if (status == E_OK) {
        *Angle = Rte_SteeringAngle;  
        return E_OK;  // Trả về thành công
    }

    return E_NOT_OK;  // Trả về lỗi nếu không đọc được dữ liệu
}
/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_PP_SteeringAngleSensor_Angle                       */
/* Param       : VAR(sint16, AUTOMATIC) Angle                                 */
/*               - Steering angle value to be written to the RTE              */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Writes the steering angle data to the RTE global variable    */
/*               `Rte_SteeringAngle` so that it can be accessed by other SWCs */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_PP_SteeringAngleSensor_Angle(VAR(sint16, AUTOMATIC) Angle)
{
    Rte_SteeringAngle = Angle; 
    return E_OK;
}


/******************************************************************************/ 
/* Name        : RTE_Read_RP_HeadlightController_HeadlightState               */
/* Param       : P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) State        */
/*               - Pointer to store the headlight state value                 */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads the headlight state from `Rte_HeadlightState` and      */
/*               stores it in `State`.                                        */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Read_RP_HeadlightController_HeadlightState(P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) State)
{
    if (State == NULL_PTR) {
        return E_NOT_OK;
    }

    *State = Rte_HeadlightState;
    return E_OK;
}

/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : RTE_Write_PP_HeadlightController_HeadlightState               */
/* Param       : VAR(HeadlightState, AUTOMATIC) State                         */
/*               - Headlight state value to be written to the RTE             */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Writes the headlight state data to the RTE global variable   */
/*               `Rte_HeadlightState` so that it can be accessed by other SWCs*/
/* Author      : DinhN                                                         */
/******************************************************************************/ 
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Write_PP_HeadlightController_HeadlightState(VAR(HeadlightState, AUTOMATIC) State)
{
    Rte_HeadlightState = State;  
    return E_OK;
}

