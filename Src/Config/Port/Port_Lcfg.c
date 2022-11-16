/**
 * @file Port_Lcfg.c
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
#include "../../Common/Std_Types.h"
#include "../../Mcal/Port/Port_Types.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#if (TOTAL_NUM_OF_USED_PINS > 0)
    
    const Port_ConfigType Port_Config[TOTAL_NUM_OF_USED_PINS] = 
    {
        {PORT_PIN_PA0, PORT_PIN_DIR_OUTPUT, {PORT_PIN_MODE_DIO, 0}, 0, PORT_PIN_OUT_CURRENT_4_mA, Port_Pin_LEVEL_LOW},
        {PORT_PIN_PA0, PORT_PIN_DIR_INPUT, {PORT_PIN_MODE_DIO, 0}, PORT_PIN_INTERNAL_PULL_UP_RES, 0, 0}
    };

#endif

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/