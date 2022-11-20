/**
 * @file OS.c
 * @author Ahmed Taha (ahmed.m.taha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "OS.h"
#include "../Mcal/SysTick/Systick.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static Os_TaskHandlersType Os_TaskHandlers[OS_MAX_NUM_OF_TASTS];
static uint32_t OS_NumOfCurrentTasks = 0;
static volatile uint32_t OS_TicksCount = 0;

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern uint32_t SystemCoreClock;

/**********************************************************************************************************************
 *  LOCAL Functions Declaration
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL Functions Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL Functions Definitions
 *********************************************************************************************************************/
void OS_AddTask(void (*TaskApi)(void *), uint8_t TaskPeriod, uint8_t TaskOffset)
{
    if(Os_TaskHandlers[OS_NumOfCurrentTasks].TaskDespathcher != NULL_PTR)
    {
        Os_TaskHandlers[OS_NumOfCurrentTasks].TaskDespathcher = TaskApi;
        Os_TaskHandlers[OS_NumOfCurrentTasks].Perid = TaskPeriod;
        Os_TaskHandlers[OS_NumOfCurrentTasks].Delay = TaskOffset;
        OS_NumOfCurrentTasks++;
    }
    else {/* Do Nothing For Now */}
}

void OS_Init(void)
{
    uint32_t SysTickPreload = ( SystemCoreClock * OS_SYSTICK_mSec) / 1000;
    SysTick_Setting SysTick_Config;
    SysTick_Config.ClkSrc = SYSTICK_ClkSrc_SYSTEM_CLOCK;
    SysTick_Config.InitStatus = SYSTICK_STOP;
    SysTick_Config.IntStatus = SYSTICK_INTERRUPT_ENABLE;
    SysTick_Config.InitVal = SysTickPreload;

    SysTic_Init(&SysTick_Config);
}


void OS_SchedulerStart(void)
{
    SysTick_EditStatus(SYSTICK_START);
    uint32_t TaskHandlers_Index = 0;
    while(1)
    {
        if(( Os_TaskHandlers[TaskHandlers_Index].Delay >= OS_TicksCount ) && ( Os_TaskHandlers[TaskHandlers_Index].Delay != 0 ))
        {
            Os_TaskHandlers[TaskHandlers_Index++].Delay = 0;
            continue;
        }
        if(OS_TicksCount % Os_TaskHandlers[TaskHandlers_Index].Delay == 0)
        {
            Os_TaskHandlers[TaskHandlers_Index++].TaskDespathcher(NULL_PTR);
        }
    }

}

void SysTick_Handler(void)
{
    OS_TicksCount++;
}

/**********************************************************************************************************************
 *  END OF FILE: Os.c
 *********************************************************************************************************************/
