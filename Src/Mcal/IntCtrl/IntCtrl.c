/**
 * @file IntCtrl.c
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
#include "IntCtrl.h"
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
    extern const IntCtrl_IrqConfig_t IrqConfigTable[INTCTRL_NUM_OF_ENABLED_IRQs];
#endif

/**********************************************************************************************************************
 *  LOCAL Functions Declaration
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL Functions Definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL Functions Definitions
 *********************************************************************************************************************/
void IntCtrl_Init(void)
{
    /* Disable the Exception if required, Set the APINT */
    /* EnterPrivilegedMode(); */

    if(INTCTRL_FAULTS_STATUS == DISABLE){
        DisableFaultExceptions();
    }
    if(INTCTRL_INTERRUPTS_STATUS == DISABLE){
        DisableInterrupt();
    }
		
    SCB->AIRCR |= ( APINT_KEY_VAL | ( INTCTRL_INTERRUPT_PRIORITY_LEVEL << 8 ) );

    #if (INTCTRL_NUM_OF_ENABLED_IRQs > 0)
        
        for(uint8_t i = 0; i < INTCTRL_NUM_OF_ENABLED_IRQs ; ++i)
        {
            IntCtrl_InterruptType_t IrqNum = IrqConfigTable[i].IRQx;
            uint8_t GroupPri = IrqConfigTable[i].GroupPriority;
            uint8_t SubGroupPri = IrqConfigTable[i].SubGroupPriority;

            if(IrqNum < 0)
            {
                uint8_t RegNum = (uint8_t)(IrqNum + 12);
                uint8_t RegBitLoc = (uint8_t)(IrqNum + 12);
                WRITE_VAL((SCB->SHP[RegNum]), (GroupPri | SubGroupPri), INTCTRL_PRI_POS);
                SET_BIT((SCB->SHCSR), RegBitLoc);
            }

            else
            {
                uint8_t RegNum = (uint8_t)IrqNum / WORD_BIT_LENTH;
                uint8_t RegBitLoc = (uint8_t)IrqNum % WORD_BIT_LENTH;
                WRITE_VAL((NVIC->PRI[IrqNum]), (GroupPri | SubGroupPri), INTCTRL_PRI_POS);
                SET_BIT(NVIC->EN[RegNum], RegBitLoc);
            }
        }

    #endif
}

/* 
void SVC_Handler(void)
{
    if(INTCTRL_FAULTS_STATUS == DISABLE){
        __ASM volatile ("cpsid f");
    }
    if(INTCTRL_INTERRUPTS_STATUS == DISABLE){
        __ASM volatile ("cpsid i");
    }
    SCB->APINT = 0x05FA | (INTCTRL_INTERRUPT_PRIORITY_LEVEL << 8);
}

 */
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
