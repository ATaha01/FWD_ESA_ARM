/**
 * @file IntCtrl_Lcfg.c
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"
#include "../../Mcal/IntCtrl/IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#if (INTCTRL_NUM_OF_ENABLED_IRQs > 0)
    
    const IntCtrl_IrqConfig_t IrqConfigTable[INTCTRL_NUM_OF_ENABLED_IRQs] = 
    {
        {SysTick_IQRn, 1, 1},
        {GPIOA_IQRn, 1, 1}
    };

#endif

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
