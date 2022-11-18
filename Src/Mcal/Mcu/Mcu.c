/**
 * @file Mcu.c
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define ASSERT_CLK_SRC(CLK_SRC)                    (((CLK_SRC) == MOSC)                ||\
                                                    ((CLK_SRC) == PIOSC)               ||\
                                                    ((CLK_SRC) == PIOSC_DIV_BY_4)      ||\
                                                    ((CLK_SRC) == LFIOSC)              ||\
                                                    ((CLK_SRC) == _32p768kHz_EXT_OSC))


#define ASSERT_XTAL_VAL(XTALL)                      (((XTALL) == _4_MHz_OSC)            ||\
                                                    ((XTALL) == _4p096_MHz_OSC)        ||\
                                                    ((XTALL) == _4p9152_MHz_OSC)       ||\
                                                    ((XTALL) == _5_MHz_OSC)            ||\
                                                    ((XTALL) == _5p12_MHz_OSC)         ||\
                                                    ((XTALL) == _6_MHz_OSC)            ||\
                                                    ((XTALL) == _6p144_MHz_OSC)        ||\
                                                    ((XTALL) == _7p3728_MHz_OSC)       ||\
                                                    ((XTALL) == _8_MHz_OSC)            ||\
                                                    ((XTALL) == _8p192_MHz_OSC)        ||\
                                                    ((XTALL) == _10_MHz_OSC)           ||\
                                                    ((XTALL) == _12_MHz_OSC)           ||\
                                                    ((XTALL) == _12p288_MHz_OSC)       ||\
                                                    ((XTALL) == _13p56_MHz_OSC)        ||\
                                                    ((XTALL) == _14p31878_MHz_OSC)     ||\
                                                    ((XTALL) == _16_MHz_OSC)           ||\
                                                    ((XTALL) == _16p384_MHz_OSC)       ||\
                                                    ((XTALL) == _18_MHz_OSC)           ||\
                                                    ((XTALL) == _20_MHz_OSC)           ||\
                                                    ((XTALL) == _24_MHz_OSC)           ||\
                                                    ((XTALL) == _25_MHz_OSC))
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static uint32_t Mcu_SystemClock = 0UL;

/**********************************************************************************************************************
 *  LOCAL Functions Declaration
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL Functions Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL Functions Definitions
 *********************************************************************************************************************/
void Mcu_Init(void)
{
    Mcu_ClockType ClkSetting = {MCU_OSCILLATOR_SRC, MCU_CLK_MOSC_XTAL_VALUE, MCU_USE_SYSDIV};
    Mcu_InitClock(&ClkSetting);
}

Mcu_RawResetType Mcu_GetResetRawValue(void)
{
    uint32_t ResetCause = 0;
    ResetCause = SYSCTL->RESC;
    return (Mcu_RawResetType)ResetCause;
}

#if (MCU_SW_RESET == ENABLE)
    void Mcu_PerformReset(void)
    {
        SCB->AIRCR |= ( APINT_KEY_VAL | ( 0x01 << AIRCR_SYSRESREQ_POS ) );
    }
#endif /* (MCU_SW_RESET == ENABLE) */

Mcu_PllStatusType Mcu_GetPllStatus(void)
{
    Mcu_PllStatusType PllStatus = 0;
    PllStatus = (Mcu_PllStatusType)(SYSCTL->PLLSTAT & 0x01UL);
    return PllStatus;
}


Std_ReturnType Mcu_InitClock(Mcu_ClockType * ClockSetting)
{
    if(!ASSERT_CLK_SRC(ClockSetting->SysClkSrc))
    {
        return E_NOT_OK;
    }
    else { /* Do Nothing */ }

    if( MOSC == ClockSetting->SysClkSrc)
    {
        SET_BIT((SYSCTL->RCC), 0); // Enable MOSC
        if(!ASSERT_XTAL_VAL(ClockSetting->XtalVal))
        {
            return E_NOT_OK;
        }
        else
        {
            WRITE_VAL((SYSCTL->RCC), 6, (ClockSetting->XtalVal)); //Set Xtal Value
        }
    }
    else if( _32p768kHz_EXT_OSC == ClockSetting->SysClkSrc)
    {
        SET_BIT((SYSCTL->RCC), 0); // Enable MOSC
        if(!ASSERT_XTAL_VAL(ClockSetting->XtalVal))
        {
            return E_NOT_OK;
        }
        else
        {
            WRITE_VAL((SYSCTL->RCC), 6, (ClockSetting->XtalVal)); //Set Xtal Value
        }
        SET_BIT((SYSCTL->RCC2), 31); //Use Rcc2
    }
    else { /* Do Nothing */ }

    WRITE_VAL((SYSCTL->RCC), 4, (ClockSetting->SysClkSrc)); // Select Src
    WRITE_VAL((SYSCTL->RCC2), 4, (ClockSetting->SysClkSrc)); // Select Src

    if (MCU_USE_SYSDIV == ENABLE)
    {
        SET_BIT((SYSCTL->RCC), 22); //UseSysDiv
        if(ClockSetting->SysDivVal < SYSCTL_SYSDIV_GT_16)
        {
            WRITE_VAL((SYSCTL->RCC), 23, (ClockSetting->SysDivVal ));
            WRITE_VAL((SYSCTL->RCC2), 23, (ClockSetting->SysDivVal ));
        }
        else
        {
            WRITE_VAL((SYSCTL->RCC2), 22, (((ClockSetting->SysDivVal) << 1) | MCU_PLL_SYSDIV2_LSB) );
            SET_BIT((SYSCTL->RCC2), 31); //Use Rcc2
        }
    }
    else
    {
        CLR_BIT((SYSCTL->RCC), 22); //Clear useSysDiv
    }

    if(MCU_PLL_OUT_CONFIGURATION == MCU_PLL_CONFIG_OUT_400MHz)
    {
        SET_BIT((SYSCTL->RCC2), 30); //Set DIV400
        SET_BIT((SYSCTL->RCC2), 31); //Use Rcc2
    }
    else { /* Do Nothing */ }

    /* Enable the Pll First to ensure a stable clock */
    if(MCU_PLL_BYBASS == ENABLE)
    {
        SET_BIT((SYSCTL->RCC), 13); // PLL On
        SET_BIT((SYSCTL->RCC2), 13); // PLL On
        while( ( MCU_PLL_STATUS_NOT_POWERED_OR_NOT_LOCKED == READ_BIT( ( SYSCTL->PLLSTAT ), 0 ) ) /* && (Timeout mechanism) */ );
        CLR_BIT((SYSCTL->RCC), 11); // SET Bybass
        CLR_BIT((SYSCTL->RCC2), 11); // SET Bybass
    }
    else
    {
        SET_BIT((SYSCTL->RCC), 11); // SET Bybass
        SET_BIT((SYSCTL->RCC2), 11); // SET Bybass
    }
    return E_OK;
}




/**********************************************************************************************************************
 *  END OF FILE: Mcu.c
 *********************************************************************************************************************/
