#include "Rte_HeadlightController.h"

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
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Read_RP_HeadlightController_HeadlightState(P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) State)
{
    if (State == NULL_PTR) {
        return E_NOT_OK;
    }

    *State = Rte_HeadlightState;
    return E_OK;
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
/******************************************************************************/ 
/* Name        : RTE_Write_PP_HeadlightActuator_Command                        */
/* Param       : VAR(HeadlightCommand, AUTOMATIC) Command                     */
/*               - Headlight command value to be written to RTE               */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Writes the headlight command to the RTE global variable      */
/*               `Rte_HeadlightCommand`                                       */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Write_PP_HeadlightActuator_Command(VAR(HeadlightState, AUTOMATIC) Command)
{
    Rte_HeadlightCommand = Command;
    IoHwAb_ControlHeadlight();
    return E_OK;
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
/******************************************************************************/ 
/* Name        : RTE_Write_PP_HeadlightActuator_State                         */
/* Param       : VAR(HeadlightState, AUTOMATIC) State                         */
/*               - Headlight state value to be written to RTE                 */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Writes the actual headlight state to the RTE global variable */
/*               `Rte_HeadlightCurrentState`                                  */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Write_PP_HeadlightActuator_State(VAR(HeadlightState, AUTOMATIC) State)
{
    Rte_HeadlightCurrentState = State;
    return E_OK;
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
/******************************************************************************/ 
/* Name        : RTE_Read_RP_HeadlightActuator_Command                        */
/* Param       : P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) Command      */
/*               - Pointer to store the headlight command value               */
/* Return      : Std_ReturnType                                               */
/*               - E_OK if successful, E_NOT_OK if error                      */
/* Contents    : Reads the headlight command from `Rte_HeadlightCommand`      */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) RTE_Read_RP_HeadlightActuator_Command(P2VAR(HeadlightState, AUTOMATIC, RTE_APPL_DATA) Command)
{
    if (Command == NULL_PTR) {
        return E_NOT_OK;
    }

    *Command = Rte_HeadlightCommand;

    return E_OK;
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : RTE_Ev_ControlHeadlight                                      */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Controls the headlight system based on input conditions      */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_ControlHeadlight(void)
{
    ControlHeadlight();
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
/******************************************************************************/ 
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : RTE_Ev_SendHeadlightState                                    */
/* Param       : None                                                         */
/* Return      : None                                                         */
/* Contents    : Sends the computed headlight state to the actuator           */
/* Author      : DinhN                                                         */
/******************************************************************************/ 
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(void, RTE_CODE_EcucPartition_0) RTE_Ev_SendHeadlightState(void)
{
    SendHeadlightState();
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
