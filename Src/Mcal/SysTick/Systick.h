/**
 * @file Systick.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Systick_Types.h"
#include "../../Config/SysTic/SysTick_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SysTic_Init(SysTick_Setting * SysTicCongig);
void SysTick_UpdateLoadValue(uint32_t SysTick_LoadValue);
void SysTick_EditStatus(SysTick_Status Status);

#endif /* __SYSTICK_H__ */

/**********************************************************************************************************************
 *  END OF FILE: SysTic.h
 *********************************************************************************************************************/
