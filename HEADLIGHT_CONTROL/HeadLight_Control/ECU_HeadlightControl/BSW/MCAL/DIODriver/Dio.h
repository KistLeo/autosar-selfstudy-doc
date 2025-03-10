#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"

/* Định nghĩa kiểu dữ liệu */
typedef uint8 Dio_LevelType;    /* Kiểu dữ liệu lưu mức tín hiệu (LOW/HIGH) */
typedef uint8 Dio_ChannelType;  /* Kiểu dữ liệu lưu ID của kênh */

/* Định nghĩa mức tín hiệu */
#define STD_LOW     (0x00U)  /* Tín hiệu mức thấp */
#define STD_HIGH    (0x01U)  /* Tín hiệu mức cao */

/* Định nghĩa các kênh DIO */
#define DIO_CHANNEL_HEADLIGHT_NORMAL    (10U)  /* Kênh điều khiển đèn bình thường */
#define DIO_CHANNEL_HEADLIGHT_HIGH_BEAM (11U)  /* Kênh điều khiển đèn pha */


extern uint8 P2OUT;  /* Thanh ghi mô phỏng xuất tín hiệu */
extern uint8 P2IN;   /* Thanh ghi mô phỏng nhập tín hiệu */

#define GPIO_HEADLIGHT_NORMAL    (1U << 0)  /* Bit 0: Đèn bình thường */
#define GPIO_HEADLIGHT_HIGH_BEAM (1U << 1)  /* Bit 1: Đèn pha */

/* API MCAL DIO */
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

#endif /* DIO_H */
