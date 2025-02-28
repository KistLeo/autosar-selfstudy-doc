#ifndef OS_EVENT_H
#define OS_EVENT_H

#include <stdint.h>  

/* Define EventMaskType if not already defined */
typedef uint32_t EventMaskType;  

/* Define event bitmasks */
#define Ev_SensorUpdate    ((EventMaskType)0x01)  // Bit 0
#define Ev_SensorDataSent  ((EventMaskType)0x02)  // Bit 1


#endif /* OS_EVENT_H */
