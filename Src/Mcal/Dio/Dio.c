/**
 * @file Dio.c
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @file Port.c
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL Functions Declaration
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL Functions Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL Functions Definitions
 *********************************************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint8_t PortNum           = ChannelId / 8;
    uint8_t PinNum            = ChannelId % 8;
    uint8_t DataMaskRegInx    = ( !PinNum ) ? ( 0 ) : ( 0x01U << ( PinNum - 1 ) );

    /* Get The Required GPIO Address */
    GPIOx_Type* GPIO = GET_GPIO(PortNum);

    uint32_t Level = GPIO->DATA_MASK[DataMaskRegInx];
    
    if(Level == DIO_LEVEL_LOW)
    {
        return DIO_LEVEL_LOW;
    }
    else
    {
        return DIO_LEVEL_HIGH;
    }

    return DIO_LEVEL_LOW;

}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint8_t PortNum           = ChannelId / 8;
    uint8_t PinNum            = ChannelId % 8;
    uint8_t DataMaskRegInx    = ( !PinNum ) ? ( 0 ) : ( 0x01U << ( PinNum - 1 ) );

    /* Get The Required GPIO Address */
    GPIOx_Type* GPIO = GET_GPIO(PortNum);

    GPIO->DATA_MASK[DataMaskRegInx] = ( Level == DIO_LEVEL_LOW ) ? ( 0x00UL ) : ( 0xFFFFFFFF );

}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    uint32_t PortLevel = 0;
    switch(PortId)
    {
        case DIO_PORT_A:
        {
            PortLevel = GPIOA->DATA;
        }break;

        case DIO_PORT_B:
        {
            PortLevel = GPIOB->DATA;
        }break;
        
        case DIO_PORT_C:
        {
            PortLevel = GPIOC->DATA;
        }break;
        
        case DIO_PORT_D:
        {
            PortLevel = GPIOD->DATA;
        }break;
        
        case DIO_PORT_E:
        {
            PortLevel = GPIOE->DATA;
        }break;
        
        case DIO_PORT_F:
        {
            PortLevel = GPIOF->DATA;
        }break;
        
        default:
            break;
    }

    return (Dio_PortLevelType)PortLevel;
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch(PortId)
    {
        case DIO_PORT_A:
        {
            GPIOA->DATA = Level;
        }break;

        case DIO_PORT_B:
        {
            GPIOB->DATA = Level;
        }break;
        
        case DIO_PORT_C:
        {
            GPIOC->DATA = Level;
        }break;
        
        case DIO_PORT_D:
        {
            GPIOD->DATA = Level;
        }break;
        
        case DIO_PORT_E:
        {
            GPIOE->DATA = Level;
        }break;
        
        case DIO_PORT_F:
        {
            GPIOF->DATA = Level;
        }break;
        
        default:
            break;
    }
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint8_t PortNum           = ChannelId / 8;
    uint8_t PinNum            = ChannelId % 8;
    uint8_t DataMaskRegInx    = ( !PinNum ) ? ( 0 ) : ( 0x01U << ( PinNum - 1 ) );

    /* Get The Required GPIO Address */
    GPIOx_Type* GPIO = GET_GPIO(PortNum);

    uint32_t Level = GPIO->DATA_MASK[DataMaskRegInx];

    if(Level == DIO_LEVEL_LOW)
    {
        GPIO->DATA_MASK[DataMaskRegInx] = 0xFFFFFFFFUL;
    }
    else
    {
        GPIO->DATA_MASK[DataMaskRegInx] = 0x00UL;
    }
}


/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
