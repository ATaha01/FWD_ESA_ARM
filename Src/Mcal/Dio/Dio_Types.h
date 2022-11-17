/**
 * @file Dio_Types.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __DIO_TYPES_H__
#define __DIO_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    DIO_CHANNEL_PA0 =  0, DIO_CHANNEL_PA1, DIO_CHANNEL_PA2, DIO_CHANNEL_PA3, DIO_CHANNEL_PA4, DIO_CHANNEL_PA5, DIO_CHANNEL_PA6, DIO_CHANNEL_PA7,
    DIO_CHANNEL_PB0,      DIO_CHANNEL_PB1, DIO_CHANNEL_PB2, DIO_CHANNEL_PB3, DIO_CHANNEL_PB4, DIO_CHANNEL_PB5, DIO_CHANNEL_PB6, DIO_CHANNEL_PB7,
    DIO_CHANNEL_PC0,      DIO_CHANNEL_PC1, DIO_CHANNEL_PC2, DIO_CHANNEL_PC3, DIO_CHANNEL_PC4, DIO_CHANNEL_PC5, DIO_CHANNEL_PC6, DIO_CHANNEL_PC7, 
    DIO_CHANNEL_PD0,      DIO_CHANNEL_PD1, DIO_CHANNEL_PD2, DIO_CHANNEL_PD3, DIO_CHANNEL_PD4, DIO_CHANNEL_PD5, DIO_CHANNEL_PD6, DIO_CHANNEL_PD7,
    DIO_CHANNEL_PE0,      DIO_CHANNEL_PE1, DIO_CHANNEL_PE2, DIO_CHANNEL_PE3, DIO_CHANNEL_PE4, DIO_CHANNEL_PE5,
    DIO_CHANNEL_PF0 = 40, DIO_CHANNEL_PF1, DIO_CHANNEL_PF2, DIO_CHANNEL_PF3, DIO_CHANNEL_PF4

}Dio_ChannelType;

typedef enum
{
    DIO_PORT_A = 0,
    DIO_PORT_B,
    DIO_PORT_C,
    DIO_PORT_D,
    DIO_PORT_E,
    DIO_PORT_F
}Dio_PortType;

typedef enum
{
    DIO_LEVEL_LOW = 0,
    DIO_LEVEL_HIGH
}Dio_LevelType;

typedef uint8_t Dio_PortLevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/



#endif /* __DIO_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/
