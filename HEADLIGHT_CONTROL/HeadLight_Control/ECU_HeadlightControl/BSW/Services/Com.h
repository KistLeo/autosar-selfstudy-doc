#ifndef COM_H
#define COM_H

#include "Std_Types.h"
#include <stdint.h>
#include "RTE/Rte_HeadlightController.h"

/* Khai báo các hàm ghi dữ liệu lên RTE */
void Com_WriteSpeedData(uint16_t speed);
void Com_WriteSteeringAngleData(sint16 steeringAngle);


#endif /* COM_H */