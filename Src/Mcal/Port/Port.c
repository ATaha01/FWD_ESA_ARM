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
#include "Port.h"
#include "../../Config/Port/Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define PORT_ENABLE_CLK(PIN_TYPE)                           ( SET_BIT( ( SYSCTL->RCGCGPIO ), ( ( PIN_TYPE )) ) )


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
void Port_Init(const Port_ConfigType* ConfigPtr)
{
    for(uint8_t i = 0; i < TOTAL_NUM_OF_USED_PINS; ++i)
    {
        uint8_t PortNum           = ConfigPtr[i].PinType / 8;
        uint8_t PinNum            = ConfigPtr[i].PinType % 8;
        uint8_t pinDir            = ConfigPtr[i].PinDir;
        Port_PinModeType pinMode  = ConfigPtr[i].PinMode;
        uint8_t OutputCurrentVal  = ConfigPtr[i].PinOutputCurrent;
        uint8_t PinPad            = ConfigPtr[i].PinInternalAttach;
        uint8_t PinInitValue      = ConfigPtr[i].PinLevelValue;
        /* Enable The GPIO CLOCK */
        PORT_ENABLE_CLK(PortNum);

        /* Get The Required GPIO Address */
        GPIOx_Type* GPIO = GET_GPIO(PortNum);

        /* Set The GPIO Pin Direction */
        WRITE_BIT( ( GPIO->DIR ),  PinNum, pinDir );
        
        /* Set The GPIO Pin Mode */

        /* UNLOCK THE Write Access to Commit Register */
        if( (uint32_t)PORT_WRITE_ACCESS_LOCKED == GPIO->LOCK )
        {
            GPIO->LOCK = PORT_WRITE_UNLOCK_KEY;
        }else{ /* Do Nothing */ }

        /* Enable ?Write Access to the SELECT Register */
        if( DISABLE == READ_BIT( ( GPIO->CR ), PinNum) )
        {
            SET_BIT( ( GPIO->CR ), PinNum);
        }else{ /* Do Nothing */ }

        switch(pinMode.PortMode)
        {
            case PORT_PIN_MODE_DIO:
            {
                CLR_BIT( ( GPIO->AFSEL ), PinNum );
                SET_BIT( ( GPIO->DEN ), PinNum );
            }break;
            
            case PORT_PIN_MODE_EXT:
            {

            }break;
            
            case PORT_PIN_MODE_ANALOG:
            {

            }break;
            
            case PORT_PIN_MODE_AF:
            {

            }break;
            
            default: 
                break;
        }/* Switch */;


        /* Set The OUT Current Value */
        if(PORT_PIN_DIR_OUTPUT == pinDir)
        {
            switch(OutputCurrentVal)
            {
                case PORT_PIN_OUT_CURRENT_2_mA:
                {
                    SET_BIT( ( GPIO->DR2R ), PinNum );
                }break;

                case PORT_PIN_OUT_CURRENT_4_mA:
                {
                    SET_BIT( ( GPIO->DR4R ), PinNum );
                }break;
                
                case PORT_PIN_OUT_CURRENT_8_mA:
                {
                    SET_BIT( ( GPIO->DR8R ), PinNum );
                    SET_BIT( ( GPIO->SLR ), PinNum );
                }break;

                default: 
                    break;
            }/* Switch */;

            /* Set Initial Value */
            WRITE_BIT( ( GPIO->DATA ), PinNum,  PinInitValue);
        }
        else if (PORT_PIN_DIR_INPUT == pinDir)
        {
            switch(PinPad)
            {
                case PORT_PIN_INTERNAL_PULL_UP_RES:
                {
                    SET_BIT( ( GPIO->PUR ), PinNum );
                }break;

                case PORT_PIN_INTERNAL_PULL_DOWN_RES:
                {
                    SET_BIT( ( GPIO->PDR ), PinNum );
                }break;

                case PORT_PIN_INTERNAL_OPEN_DRAIN:
                {
                    SET_BIT( ( GPIO->ODR ), PinNum );
                }break;

                default:
                    break;
            }
        }

        /* LOCK & Disable Write Access */
        GPIO->LOCK = PORT_WRITE_LOCK_KEY;
        CLR_BIT( ( GPIO->CR ), PinNum);

    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
