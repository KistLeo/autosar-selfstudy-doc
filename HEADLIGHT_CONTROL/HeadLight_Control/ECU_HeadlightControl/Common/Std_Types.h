/**
 *
 * \brief Electric Memory Seat
 * \author GroupDinhN
 *
 */

 #ifndef STD_TYPES_H
 #define STD_TYPES_H
 
 /* Platform Types */
 typedef signed char         sint8;
 typedef unsigned char       uint8;
 typedef signed short        sint16;
 typedef unsigned short      uint16;
 typedef signed long         sint32;
 typedef unsigned long       uint32;
 typedef float               float32;
 typedef double              float64;
 typedef unsigned char       boolean;
 
 /* AUTOSAR Types */
 typedef uint8 Std_ReturnType;
 typedef uint8 Can_HwHandleType;
 typedef uint32 Can_IdType;

/* Định nghĩa PDU ID Type */
typedef uint16 PduIdType;

/* [SWS_Can_00416] Can_IdType: Represents the Identifier of an L-PDU */
#define CAN_ID_STANDARD_MASK    (0x000007FFU) 
#define CAN_ID_EXTENDED_MASK    (0x1FFFFFFFU) // 29-bit Extended ID


/* [SWS_Can_00415] Can_PduType: Structure for CAN L-SDU */
typedef struct {
    PduIdType swPduHandle;      // PDU handle
    uint8_t length;             // Length of SDU data
    Can_IdType id;              // CAN ID
    uint8_t* sdu;               // Pointer to SDU data
} Can_PduType;

/* [SWS_CAN_00496] Can_HwType: Structure for hardware object and CAN ID */
typedef struct {
    Can_IdType CanId;           // Standard/Extended CAN ID
    Can_HwHandleType Hoh;       // Hardware Object Handle
    uint8_t ControllerId;       // CAN Controller ID
} Can_HwType;

/* [SWS_Can_00413] Can_ConfigType: Overall initialization data for CAN driver */
typedef struct {
    uint8_t ControllerCount;    // Số lượng controller
    const Can_HwType* HwConfig; // Pointer tới cấu hình hardware objects
} Can_ConfigType;
 
typedef enum {
    HEADLIGHT_OFF,
    HEADLIGHT_NORMAL,
    HEADLIGHT_HIGH_BEAM
} HeadlightState;


 /* AUTOSAR Defines */
 #define TRUE      			1U
 #define FALSE     			0U
 #define E_NOT_OK    		1U
 #define E_OK      			0U
 #define STD_HIGH    		1U
 #define STD_LOW     		0U
 #define E_OK			    0U
 #define E_NOK		    	1U
 
 #endif /* STD_TYPE_H */