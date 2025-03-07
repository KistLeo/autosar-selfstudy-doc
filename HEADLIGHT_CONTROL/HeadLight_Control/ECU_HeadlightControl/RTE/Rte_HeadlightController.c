#include "Rte_HeadlightController.h"
#include "ECU_HeadlightControl/SWC/Headlight_Controller.c"

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
#include "RTE_MemMap.h"

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
#include "RTE_MemMap.h"

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
