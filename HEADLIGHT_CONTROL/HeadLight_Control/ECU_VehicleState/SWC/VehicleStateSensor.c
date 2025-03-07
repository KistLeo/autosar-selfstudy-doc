#include "VehicleStateSensor.h"

void ReadSpeedAndSteering(int *speed_check, sint16 *angle_check)
{
    Std_ReturnType status;

    
    status = Rte_Read_RP_SpeedSensor_Speed(&vehicleState.speed);
		*speed_check = vehicleState.speed;
    if (status != E_OK) {
        //printf("Failed to read Speed Sensor\n");
    }

    status = Rte_Read_RP_SteeringSensor_Angle(&vehicleState.steeringAngle);
		*angle_check = vehicleState.steeringAngle;
    if (status != E_OK) {
        //printf("Failed to read Steering Sensor\n");
    }
}
FUNC(void, RTE_CODE) SendSensorData(void)
{
    Std_ReturnType status;
    uint8 frameData[3];

    /* Chuyển đổi dữ liệu */
    uint8 speedInt = (uint8)(vehicleState.speed);  /* 8-bit Speed */
    uint16 steeringInt = (uint16)(vehicleState.steeringAngle * 10); /* 16-bit Steering Angle (0.1 độ đơn vị) */

    /* Đóng gói dữ liệu vào frame */
    frameData[0] = speedInt;                 /* Speed */
    frameData[1] = (uint8)(steeringInt >> 8); /* High byte của góc lái */
    frameData[2] = (uint8)(steeringInt & 0xFF); /* Low byte của góc lái */

    /* Send Speed Data */
    status = Rte_Write_PP_VehicleStateFrame(frameData);
    if (status != E_OK) {
        printf("Failed to send Vehicle State Frame\n");
    }
}