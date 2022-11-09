/**
 * @file Mcu_Hw.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief Cortex-Mx Specific Registers Definitions
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __MCU_HW_H__
#define __MCU_HW_H__


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEX_M3            (FALSE)
#define CORTEX_M4            (TRUE)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#if ((CORTEX_M3 == TRUE) && (CORTEX_M4 == FALSE))
    #error CORTEX-M3 Not Implemented Yet
#elif ((CORTEX_M3 == FALSE) && (CORTEX_M4 == TRUE))
    
    /*************************************************************************************************************
     * SysTic
     *************************************************************************************************************/
    typedef struct
    {
        volatile uint32_t STCTRL;
        volatile uint32_t STRELOAD;
        volatile uint32_t STCURRENT;
    }SysTick_Type;

    /*************************************************************************************************************
     * NVIC
     *************************************************************************************************************/
    typedef struct
    {
        volatile uint32_t EN[5];
        uint32_t RESERVED0[28];
        volatile uint32_t DIS[5];
        uint32_t RESERVED1[28];
        volatile uint32_t PEND[5];
        uint32_t RESERVED2[28];
        volatile uint32_t UNPEND[5];
        uint32_t RESERVED3[28];
        volatile const uint32_t ACTIVE[5];
        uint32_t RESERVED4[60];
        volatile uint32_t PRI[136];
        uint32_t RESERVED5[670];
        volatile uint32_t SWTRIG;

    }NVIC_Type;
    
    /*************************************************************************************************************
     * SCB
     *************************************************************************************************************/
    typedef struct 
    {
        volatile const uint32_t CPUID;
        volatile uint32_t INTCTRL;
        volatile uint32_t VTABLE;
        volatile uint32_t APINT;
        volatile uint32_t SYSCTRL;
        volatile uint32_t CFGCTRL;
        volatile uint32_t SYSPRI[3];
        volatile uint32_t SYSHNDCTRL;
        volatile uint32_t FAULTSTAT;
        volatile uint32_t HFAULTSTAT;
        uint32_t RESERVED;
        volatile uint32_t MMADDR;
        volatile uint32_t FAULTADDR;
    }SCB_Type;
    


#else
    #error Select a Valid Cortex-M Option
#endif


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#if ((CORTEX_M3 == TRUE) && (CORTEX_M4 == FALSE))
    #error CORTEX-M3 Not Implemented Yet
#elif ((CORTEX_M3 == FALSE) && (CORTEX_M4 == TRUE))

    #define CM4_COR_PERIPHERNAL_BASE_ADDRESS                (uint32_t)(0xE000E000)

    #define SYSTIMER_BASE_ADDR                              (uint32_t)(CM4_COR_PERIPHERNAL_BASE_ADDRESS + 0x0010UL)
    #define NVIC_BASE_ADDR                                  (uint32_t)(CM4_COR_PERIPHERNAL_BASE_ADDRESS + 0x0100UL)
    #define SCB_BASE_ADDR                                   (uint32_t)(CM4_COR_PERIPHERNAL_BASE_ADDRESS + 0x0D00UL)

    #define SysTick                                         ( (SysTick_Type  *) SYSTIMER_BASE_ADDR )
    #define NVIC                                            ( (NVIC_Type     *) NVIC_BASE_ADDR     )
    #define SCB                                             ( (SCB_Type      *) SCB_BASE_ADDR      )


#else
    #error Select a Valid Cortex-M Option
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define EnterPrivilegedMode()               __ASM("SVC #0")
#define DisableFaultExceptions()            __ASM("cpsid f")
#define DisableInterrupt()                  __ASM("cpsid i")

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* __MCU_HW_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/