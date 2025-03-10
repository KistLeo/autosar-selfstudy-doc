#include "Headlight_Actuator.h"

void ControlHeadlight()
{
    HeadlightState currentState;

    if (RTE_Read_RP_HeadlightController_HeadlightState(&currentState) == E_OK)
    {
        HeadlightState command = HEADLIGHT_OFF;

        switch (currentState)
        {
            case HEADLIGHT_OFF:
                command = HEADLIGHT_OFF;
                RTE_Write_PP_HeadlightActuator_Command(command);
                RTE_Write_PP_HeadlightActuator_State(currentState);
                break;
            case HEADLIGHT_NORMAL:
                command = HEADLIGHT_NORMAL;
                RTE_Write_PP_HeadlightActuator_Command(command);
                RTE_Write_PP_HeadlightActuator_State(currentState);
                break;
            case HEADLIGHT_HIGH_BEAM:
                command = HEADLIGHT_HIGH_BEAM;
                RTE_Write_PP_HeadlightActuator_Command(command);
                RTE_Write_PP_HeadlightActuator_State(currentState);
                break;
        }
        
    }
}
