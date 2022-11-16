/**
 * @file Port_Types.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __PORT_TYPES_H__
#define __PORT_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_WRITE_LOCK_KEY                         (0x4C4F434BUL)
#define PORT_WRITE_UNLOCK_KEY                       (0x00UL)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    PORT_PIN_PA0 =  0, PORT_PIN_PA1, PORT_PIN_PA2, PORT_PIN_PA3, PORT_PIN_PB4, PORT_PIN_PA5, PORT_PIN_PA6, PORT_PIN_PA7,
    PORT_PIN_PB0,      PORT_PIN_PB1, PORT_PIN_PB2, PORT_PIN_PB3, PORT_PIN_PB4, PORT_PIN_PB5, PORT_PIN_PB6, PORT_PIN_PB7,
    PORT_PIN_PC0,      PORT_PIN_PC1, PORT_PIN_PC2, PORT_PIN_PC3, PORT_PIN_PC4, PORT_PIN_PC5, PORT_PIN_PC6, PORT_PIN_PC7, 
    PORT_PIN_PD0,      PORT_PIN_PD1, PORT_PIN_PD2, PORT_PIN_PD3, PORT_PIN_PD4, PORT_PIN_PD5, PORT_PIN_PD6, PORT_PIN_PD7,
    PORT_PIN_PE0,      PORT_PIN_PE1, PORT_PIN_PE2, PORT_PIN_PE3, PORT_PIN_PE4, PORT_PIN_PE5,
    PORT_PIN_PF0 = 40, PORT_PIN_PF1, PORT_PIN_PF2, PORT_PIN_PF3, PORT_PIN_PF4
}Port_PinType;

typedef enum
{
    PORT_PIN_DIR_INPUT = 0,
    PORT_PIN_DIR_OUTPUT
}Port_PinDirectionType;

typedef enum
{
    PORT_PIN_MODE_DIO = 0,
    PORT_PIN_MODE_EXT,
    PORT_PIN_MODE_ANALOG,
    PORT_PIN_MODE_AF
}Port_PinMainModeType;

typedef uint8_t Port_PinAfModeType;

typedef struct
{
    Port_PinMainModeType PortMode;
    Port_PinAfModeType Port_AF_Option;
}Port_PinModeType;


typedef enum
{
    PORT_PIN_INTERNAL_PULL_UP_RES = 0,
    PORT_PIN_INTERNAL_PULL_DOWN_RES,
    PORT_PIN_INTERNAL_OPEN_DRAIN
}Port_PinInternalAttachType;

typedef enum
{
    Port_Pin_LEVEL_LOW = 0,
    Port_Pin_LEVEL_HIGH
}Porn_PinLevelValueType;

typedef enum
{
    PORT_PIN_OUT_CURRENT_2_mA = 0,
    PORT_PIN_OUT_CURRENT_4_mA,
    PORT_PIN_OUT_CURRENT_8_mA

}Port_PinOutputCurrentType;

typedef enum
{
    PORT_WRITE_ACCESS_ENABLE = 0,
    PORT_WRITE_ACCESS_LOCKED
}Port_WriteAccessStatus;

typedef struct
{
    Port_PinType               PinType          ;
    Port_PinDirectionType      PinDir           ;
    Port_PinModeType           PinMode          ;
    Port_PinInternalAttachType PinInternalAttach;
    Port_PinOutputCurrentType  PinOutputCurrent ;
    Porn_PinLevelValueType     PinLevelValue    ;
}Port_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* __PORT_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
