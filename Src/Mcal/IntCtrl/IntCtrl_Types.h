/**
 * @file IntCtrl_Types.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __INTCTRL_TYPES_H__
#define __INTCTRL_TYPES_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define INTCTRL_PRI_OFSSET      (0x05u)
#define APINT_KEY_VAL           (0x05FAu)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    /****************************************  Cortex-M4 Exceptions Numbers ******************************************/
    NMI_IRQn                    = -14,
    MemoryManagment_IRQn        = -12,
    BusFault_IRQn               = -11,
    UsageFault_IRQn             = -10,
    SVCall_IRQn                 = -5,
    DebugMonitor_IRQn           = -4,
    PendSV_IRQn                 = -2,
    SysTick_IQRn                = -1,

    /****************************************  TIVA Exceptions Numbers ******************************************/
    GPIOA_IQRn                  = 0,
    GPIOB_IQRn                  = 1,
    GPIOC_IQRn                  = 2,
    GPIOD_IQRn                  = 3,
    GPIOE_IQRn                  = 4,
    UART0_IRQn                  = 5,
    UART1_IRQn                  = 6,
    SSI0_IRQn                   = 7,
    I2C0_IRQn                   = 8,
    PWM0_Fault_IRQn             = 9,
    PWM0_Generator0_IRQn        = 10,
    PWM0_Generator1_IRQn        = 11,
    PWM0_Generator2_IRQn        = 12,
    QEI0_IRQn                   = 13,
    ADC0_Sequence0_IRQn         = 14,
    ADC0_Sequence1_IRQn         = 15,
    ADC0_Sequence2_IRQn         = 16,
    ADC0_Sequence3_IRQn         = 17,
    WDT0_WDT1_IRQn              = 18,
    TIM0A_16_32_Bits_IRQn       = 19,
    TIM0B_16_32_Bits_IRQn       = 20,
    TIM1A_16_32_Bits_IRQn       = 21,
    TIM1B_16_32_Bits_IRQn       = 22,
    TIM2A_16_32_Bits_IRQn       = 23,
    TIM2B_16_32_Bits_IRQn       = 24,
    CMB0_IRQn                   = 25,
    CMB1_IRQn                   = 26,
    SysControl_IRQn             = 28,

}IntCtrl_InterruptType_t;

typedef enum
{
    INTCTRL_IRQ_DISABLE = 0,
    INTCTRL_IRQ_EABLE,
}IntCtrl_IrqStatus_t;

typedef struct
{
    IntCtrl_InterruptType_t IRQx;
    uint8_t GroupPriority;
    uint8_t SubGroupPriority;
    IntCtrl_IrqStatus_t IrqStatus;
}IntCtrl_IrqConfig_t;

typedef enum
{
    INTCTRL_INTERRUPT_PRIORITY_LEVEL_G_FULL_S_NONE = 0,
    INTCTRL_INTERRUPT_PRIORITY_LEVEL_G_4_S_2 = 5,
    INTCTRL_INTERRUPT_PRIORITY_LEVEL_G_2_S_4 = 6,
    INTCTRL_INTERRUPT_PRIORITY_LEVEL_G_NONE_S_FULL = 7,
}IntCtrl_InterruptPriorityLevel_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


 
#endif  /* __INTCTRL_TYPES_H__ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/