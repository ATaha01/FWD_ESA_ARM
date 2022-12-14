/**
 * @file OS_Types.h
 * @author Ahmed Taha (ahmed.m.taha@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __OS_TYPES_H__
#define __OS_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Common/Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
    void (*TaskDespathcher)(void *);
    uint8_t Perid;
    uint8_t Delay;
}Os_TaskHandlersType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* __OS_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: OS_Types.h
 *********************************************************************************************************************/
