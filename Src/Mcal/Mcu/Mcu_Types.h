/**
 * @file Mcu_Types.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief Mcu System Control Data Types
 * @version 0.1
 * @date 2022-11-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MCU_TYPES_H__
#define __MCU_TYPES_H__

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
    MCU_RAW_RESRT_TYPE_EXTERNAL  = 0,
    MCU_RAW_RESRT_TYPE_POWER_ON     ,
    MCU_RAW_RESRT_TYPE_BROWN_OUT    ,
    MCU_RAW_RESRT_TYPE_WDT0         ,
    MCU_RAW_RESRT_TYPE_SW           ,
    MCU_RAW_RESRT_TYPE_WDT1         ,
    MCU_RAW_RESRT_TYPE_MOSC_FAIL    ,
    MCU_RAW_RESET_TYPES_TOTAL_NUM
}Mcu_RawResetType;

typedef enum
{
    MCU_PLL_STATUS_NOT_POWERED_OR_NOT_LOCKED = 0,
    MCU_PLL_STATUS_POWERED_AND_LOCKED
}Mcu_PllStatusType;

typedef enum
{
    MCU_PLL_CONFIG_OUT_200MHz = 0,
    MCU_PLL_CONFIG_OUT_400MHz
}Mcu_PllConfig;

typedef enum
{
    MOSC = 0,
    PIOSC,
    PIOSC_DIV_BY_4,
    LFIOSC,
    _32p768kHz_EXT_OSC = 7
}Mcu_ClkOscillatorSrc;

typedef enum
{
    _4_MHz_OSC = 6,
    _4p096_MHz_OSC,
    _4p9152_MHz_OSC,
    _5_MHz_OSC,
    _5p12_MHz_OSC,
    _6_MHz_OSC,
    _6p144_MHz_OSC,
    _7p3728_MHz_OSC,
    _8_MHz_OSC,
    _8p192_MHz_OSC,
    _10_MHz_OSC,
    _12_MHz_OSC,
    _12p288_MHz_OSC,
    _13p56_MHz_OSC,
    _14p31878_MHz_OSC,
    _16_MHz_OSC,
    _16p384_MHz_OSC,
    _18_MHz_OSC,
    _20_MHz_OSC,
    _24_MHz_OSC,
    _25_MHz_OSC

}Mcu_ClkXtalValue;

typedef enum
{
    SYSCTL_SYSDIV_1 = 0,
    SYSCTL_SYSDIV_2,
    SYSCTL_SYSDIV_3,
    SYSCTL_SYSDIV_4,
    SYSCTL_SYSDIV_5,
    SYSCTL_SYSDIV_6,
    SYSCTL_SYSDIV_7,
    SYSCTL_SYSDIV_8,
    SYSCTL_SYSDIV_9,
    SYSCTL_SYSDIV_10,
    SYSCTL_SYSDIV_11,
    SYSCTL_SYSDIV_12,
    SYSCTL_SYSDIV_13,
    SYSCTL_SYSDIV_14,
    SYSCTL_SYSDIV_15,
    SYSCTL_SYSDIV_16,
    SYSCTL_SYSDIV_GT_16

}Mcu_SysCtlSysDiv;

typedef struct
{
    Mcu_ClkOscillatorSrc SysClkSrc;
    Mcu_ClkXtalValue     XtalVal;
    Mcu_SysCtlSysDiv     SysDivVal;
}Mcu_ClockType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* __MCU_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Types.h
 *********************************************************************************************************************/
