#include "Dio.h"

/* Biến toàn cục giả lập thanh ghi GPIO */
uint8 P2OUT = 0x00;  /* Thanh ghi mô phỏng xuất tín hiệu */
uint8 P2IN = 0x00;   /* Thanh ghi mô phỏng nhập tín hiệu */

/* Function API to Read a Channel */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    switch (ChannelId)
    {
        case DIO_CHANNEL_HEADLIGHT_NORMAL:
            return (P2IN & GPIO_HEADLIGHT_NORMAL) ? STD_HIGH : STD_LOW;

        case DIO_CHANNEL_HEADLIGHT_HIGH_BEAM:
            return (P2IN & GPIO_HEADLIGHT_HIGH_BEAM) ? STD_HIGH : STD_LOW;

        default:
            return STD_LOW;  /* Trả về mặc định nếu kênh không hợp lệ */
    }
}

/* Function to write to a channel */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    switch (ChannelId)
    {
        case DIO_CHANNEL_HEADLIGHT_NORMAL:
            if (Level == STD_LOW)
                P2OUT &= ~GPIO_HEADLIGHT_NORMAL;  /* Xóa bit */
            else
                P2OUT |= GPIO_HEADLIGHT_NORMAL;   /* Đặt bit */
            break;

        case DIO_CHANNEL_HEADLIGHT_HIGH_BEAM:
            if (Level == STD_LOW)
                P2OUT &= ~GPIO_HEADLIGHT_HIGH_BEAM;  /* Xóa bit */
            else
                P2OUT |= GPIO_HEADLIGHT_HIGH_BEAM;   /* Đặt bit */
            break;

        default:
            /* Xử lý trường hợp không hợp lệ */
            break;
    }
}
