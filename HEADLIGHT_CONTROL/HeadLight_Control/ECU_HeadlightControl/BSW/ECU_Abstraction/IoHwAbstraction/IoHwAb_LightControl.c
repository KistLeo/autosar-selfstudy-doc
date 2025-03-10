#include "IoHwAb_LightControl.h"


void IoHwAb_ControlHeadlight()
{
    HeadlightState command;

    // Đọc lệnh điều khiển đèn từ RTE
    if (RTE_Read_RP_HeadlightActuator_Command(&command) == E_OK)
    {
        switch (command)
        {
            case HEADLIGHT_OFF:
                Dio_WriteChannel(DIO_CHANNEL_HEADLIGHT_NORMAL, STD_LOW);
                Dio_WriteChannel(DIO_CHANNEL_HEADLIGHT_HIGH_BEAM, STD_LOW);
                break;
            case HEADLIGHT_NORMAL:
                Dio_WriteChannel(DIO_CHANNEL_HEADLIGHT_NORMAL, STD_HIGH);
                Dio_WriteChannel(DIO_CHANNEL_HEADLIGHT_HIGH_BEAM, STD_LOW);
                break;
            case HEADLIGHT_HIGH_BEAM:
                Dio_WriteChannel(DIO_CHANNEL_HEADLIGHT_NORMAL, STD_LOW);
                Dio_WriteChannel(DIO_CHANNEL_HEADLIGHT_HIGH_BEAM, STD_HIGH);
                break;
        }
    }
}