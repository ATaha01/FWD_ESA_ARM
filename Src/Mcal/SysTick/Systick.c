/**
 * @file Systick.c
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysTick.h"
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
void SysTic_Init(SysTick_Setting * SysTicCongig)
{
    if(SysTicCongig == NULL_PTR)
        return;

    SysTick->LOAD = SysTicCongig->InitVal;

    if(SYSTICK_ClkSrc_PIOSC_SYSTEM_CLOCK == SysTicCongig->ClkSrc)
        SET_BIT((SysTick->CTRL), 2);
    else
        CLR_BIT((SysTick->CTRL), 2);

    if(SYSTICK_INTERRUPT_ENABLE == SysTicCongig->ClkSrc)
        SET_BIT((SysTick->CTRL), 1);
    else
        CLR_BIT((SysTick->CTRL), 1);

    if(SYSTICK_START == SysTicCongig->InitStatus)
        SET_BIT((SysTick->CTRL), 0);
    else
        CLR_BIT((SysTick->CTRL), 0);
}


void SysTick_UpdateLoadValue(uint32_t SysTick_LoadValue)
{
    SysTick->LOAD = SysTick_LoadValue;
}

void SysTick_EditStatus(SysTick_Status Status)
{
    if(SYSTICK_START == Status)
        SET_BIT((SysTick->CTRL), 0);
    else
        CLR_BIT((SysTick->CTRL), 0);
}


/**********************************************************************************************************************
 *  END OF FILE: SysTick.c
 *********************************************************************************************************************/
