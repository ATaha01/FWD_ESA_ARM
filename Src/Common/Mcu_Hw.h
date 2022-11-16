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

#include "Std_Types.h"

#define CORE_M4                                     (TRUE )
#define CORE_M3                                     (FALSE)

/**********************************************************************************************************************
 * Core Registers Abstraction
 *      1- Core Registers.
 *      2- NVIC
 *      3- SCB
 *      4- SysTick
 * 
 *********************************************************************************************************************/

/**
  @brief  Nested Vector Interrupt Controller (NVIC).
 */

typedef struct
{
    volatile uint32_t EN[8u];
    uint32_t RESERVED0[24u];
    volatile uint32_t DIS[8u];
    uint32_t RESERVED1[24u];
    volatile uint32_t PEND[8u];
    uint32_t RESERVED2[24u];
    volatile uint32_t UNPEND[8u];
    uint32_t RESERVED3[24u];
    volatile const uint32_t ACTIVE[8u];
    uint32_t RESERVED4[56u];
    volatile uint8_t PRI[240u];
    uint32_t RESERVED5[644u];
    volatile uint32_t SWTRIG;

}NVIC_Type;

/**
 * @brief   System Control Block (SCB).
 */

typedef struct
{
    volatile const uint32_t CPUID;                  
    volatile       uint32_t ICSR;                   
    volatile       uint32_t VTOR;                   
    volatile       uint32_t AIRCR;                  
    volatile       uint32_t SCR;                    
    volatile       uint32_t CCR;                    
    volatile       uint8_t  SHP[12U];               
    volatile       uint32_t SHCSR;                  
    volatile       uint32_t CFSR;                   
    volatile       uint32_t HFSR;                   
    volatile       uint32_t DFSR;                   
    volatile       uint32_t MMFAR;                  
    volatile       uint32_t BFAR;                   
    volatile       uint32_t AFSR;                   
    volatile       uint32_t PFR[2U];                
    volatile       uint32_t DFR;                    
    volatile       uint32_t ADR;                    
    volatile       uint32_t MMFR[4U];               
    volatile       uint32_t ISAR[5U];               
                   uint32_t RESERVED0[5U];
    volatile       uint32_t CPACR;                  
} SCB_Type;
    
#define APINT_KEY_VAL           (0x05FAu)

/**
 * @brief System Tick Timer (SysTick)
 */

typedef struct
{
  volatile       uint32_t CTRL;                   
  volatile       uint32_t LOAD;                   
  volatile       uint32_t VAL;                    
  volatile const uint32_t CALIB;                  
} SysTick_Type;



/* ================================================================================ */
/* ================                     SYSCTL                     ================ */
/* ================================================================================ */


/**
  * @brief Register map for SYSCTL peripheral (SYSCTL)
  */

typedef struct {                                        /*!< SYSCTL Structure                                                      */
  volatile uint32_t  DID0;                              /*!< Device Identification 0                                               */
  volatile uint32_t  DID1;                              /*!< Device Identification 1                                               */
  volatile uint32_t  DC0;                               /*!< Device Capabilities 0                                                 */
  volatile const  uint32_t  RESERVED;
  volatile uint32_t  DC1;                               /*!< Device Capabilities 1                                                 */
  volatile uint32_t  DC2;                               /*!< Device Capabilities 2                                                 */
  volatile uint32_t  DC3;                               /*!< Device Capabilities 3                                                 */
  volatile uint32_t  DC4;                               /*!< Device Capabilities 4                                                 */
  volatile uint32_t  DC5;                               /*!< Device Capabilities 5                                                 */
  volatile uint32_t  DC6;                               /*!< Device Capabilities 6                                                 */
  volatile uint32_t  DC7;                               /*!< Device Capabilities 7                                                 */
  volatile uint32_t  DC8;                               /*!< Device Capabilities 8                                                 */
  volatile uint32_t  PBORCTL;                           /*!< Brown-Out Reset Control                                               */
  volatile const  uint32_t  RESERVED1[3];
  volatile uint32_t  SRCR0;                             /*!< Software Reset Control 0                                              */
  volatile uint32_t  SRCR1;                             /*!< Software Reset Control 1                                              */
  volatile uint32_t  SRCR2;                             /*!< Software Reset Control 2                                              */
  volatile const  uint32_t  RESERVED2;
  volatile uint32_t  RIS;                               /*!< Raw Interrupt Status                                                  */
  volatile uint32_t  IMC;                               /*!< Interrupt Mask Control                                                */
  volatile uint32_t  MISC;                              /*!< Masked Interrupt Status and Clear                                     */
  volatile uint32_t  RESC;                              /*!< Reset Cause                                                           */
  volatile uint32_t  RCC;                               /*!< Run-Mode Clock Configuration                                          */
  volatile const  uint32_t  RESERVED3[2];
  volatile uint32_t  GPIOHBCTL;                         /*!< GPIO High-Performance Bus Control                                     */
  volatile uint32_t  RCC2;                              /*!< Run-Mode Clock Configuration 2                                        */
  volatile const  uint32_t  RESERVED4[2];
  volatile uint32_t  MOSCCTL;                           /*!< Main Oscillator Control                                               */
  volatile const  uint32_t  RESERVED5[32];
  volatile uint32_t  RCGC0;                             /*!< Run Mode Clock Gating Control Register 0                              */
  volatile uint32_t  RCGC1;                             /*!< Run Mode Clock Gating Control Register 1                              */
  volatile uint32_t  RCGC2;                             /*!< Run Mode Clock Gating Control Register 2                              */
  volatile const  uint32_t  RESERVED6;
  volatile uint32_t  SCGC0;                             /*!< Sleep Mode Clock Gating Control Register 0                            */
  volatile uint32_t  SCGC1;                             /*!< Sleep Mode Clock Gating Control Register 1                            */
  volatile uint32_t  SCGC2;                             /*!< Sleep Mode Clock Gating Control Register 2                            */
  volatile const  uint32_t  RESERVED7;
  volatile uint32_t  DCGC0;                             /*!< Deep Sleep Mode Clock Gating Control Register 0                       */
  volatile uint32_t  DCGC1;                             /*!< Deep-Sleep Mode Clock Gating Control Register 1                       */
  volatile uint32_t  DCGC2;                             /*!< Deep Sleep Mode Clock Gating Control Register 2                       */
  volatile const  uint32_t  RESERVED8[6];
  volatile uint32_t  DSLPCLKCFG;                        /*!< Deep Sleep Clock Configuration                                        */
  volatile const  uint32_t  RESERVED9;
  volatile uint32_t  SYSPROP;                           /*!< System Properties                                                     */
  volatile uint32_t  PIOSCCAL;                          /*!< Precision Internal Oscillator Calibration                             */
  volatile uint32_t  PIOSCSTAT;                         /*!< Precision Internal Oscillator Statistics                              */
  volatile const  uint32_t  RESERVED10[2];
  volatile uint32_t  PLLFREQ0;                          /*!< PLL Frequency 0                                                       */
  volatile uint32_t  PLLFREQ1;                          /*!< PLL Frequency 1                                                       */
  volatile uint32_t  PLLSTAT;                           /*!< PLL Status                                                            */
  volatile const  uint32_t  RESERVED11[7];
  volatile uint32_t  SLPPWRCFG;                         /*!< Sleep Power Configuration                                             */
  volatile uint32_t  DSLPPWRCFG;                        /*!< Deep-Sleep Power Configuration                                        */
  volatile uint32_t  DC9;                               /*!< Device Capabilities 9                                                 */
  volatile const  uint32_t  RESERVED12[3];
  volatile uint32_t  NVMSTAT;                           /*!< Non-volatile Memory Information                                       */
  volatile const  uint32_t  RESERVED13[4];
  volatile uint32_t  LDOSPCTL;                          /*!< LDO Sleep Power Control                                               */
  volatile const  uint32_t  RESERVED14;
  volatile uint32_t  LDODPCTL;                          /*!< LDO Deep-Sleep Power Control                                          */
  volatile const  uint32_t  RESERVED15[80];
  volatile uint32_t  PPWD;                              /*!< Watchdog Timer Peripheral Present                                     */
  volatile uint32_t  PPTIMER;                           /*!< 16/32-Bit General-Purpose Timer Peripheral Present                    */
  volatile uint32_t  PPGPIO;                            /*!< General-Purpose Input/Output Peripheral Present                       */
  volatile uint32_t  PPDMA;                             /*!< Micro Direct Memory Access Peripheral Present                         */
  volatile const  uint32_t  RESERVED16;
  volatile uint32_t  PPHIB;                             /*!< Hibernation Peripheral Present                                        */
  volatile uint32_t  PPUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Present        */
  volatile uint32_t  PPSSI;                             /*!< Synchronous Serial Interface Peripheral Present                       */
  volatile uint32_t  PPI2C;                             /*!< Inter-Integrated Circuit Peripheral Present                           */
  volatile const  uint32_t  RESERVED17;
  volatile uint32_t  PPUSB;                             /*!< Universal Serial Bus Peripheral Present                               */
  volatile const  uint32_t  RESERVED18[2];
  volatile uint32_t  PPCAN;                             /*!< Controller Area Network Peripheral Present                            */
  volatile uint32_t  PPADC;                             /*!< Analog-to-Digital Converter Peripheral Present                        */
  volatile uint32_t  PPACMP;                            /*!< Analog Comparator Peripheral Present                                  */
  volatile uint32_t  PPPWM;                             /*!< Pulse Width Modulator Peripheral Present                              */
  volatile uint32_t  PPQEI;                             /*!< Quadrature Encoder Interface Peripheral Present                       */
  volatile const  uint32_t  RESERVED19[4];
  volatile uint32_t  PPEEPROM;                          /*!< EEPROM Peripheral Present                                             */
  volatile uint32_t  PPWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Present               */
  volatile const  uint32_t  RESERVED20[104];
  volatile uint32_t  SRWD;                              /*!< Watchdog Timer Software Reset                                         */
  volatile uint32_t  SRTIMER;                           /*!< 16/32-Bit General-Purpose Timer Software Reset                        */
  volatile uint32_t  SRGPIO;                            /*!< General-Purpose Input/Output Software Reset                           */
  volatile uint32_t  SRDMA;                             /*!< Micro Direct Memory Access Software Reset                             */
  volatile const  uint32_t  RESERVED21;
  volatile uint32_t  SRHIB;                             /*!< Hibernation Software Reset                                            */
  volatile uint32_t  SRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Software Reset            */
  volatile uint32_t  SRSSI;                             /*!< Synchronous Serial Interface Software Reset                           */
  volatile uint32_t  SRI2C;                             /*!< Inter-Integrated Circuit Software Reset                               */
  volatile const  uint32_t  RESERVED22;
  volatile uint32_t  SRUSB;                             /*!< Universal Serial Bus Software Reset                                   */
  volatile const  uint32_t  RESERVED23[2];
  volatile uint32_t  SRCAN;                             /*!< Controller Area Network Software Reset                                */
  volatile uint32_t  SRADC;                             /*!< Analog-to-Digital Converter Software Reset                            */
  volatile uint32_t  SRACMP;                            /*!< Analog Comparator Software Reset                                      */
  volatile uint32_t  SRPWM;                             /*!< Pulse Width Modulator Software Reset                                  */
  volatile uint32_t  SRQEI;                             /*!< Quadrature Encoder Interface Software Reset                           */
  volatile const  uint32_t  RESERVED24[4];
  volatile uint32_t  SREEPROM;                          /*!< EEPROM Software Reset                                                 */
  volatile uint32_t  SRWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Software Reset                   */
  volatile const  uint32_t  RESERVED25[40];
  volatile uint32_t  RCGCWD;                            /*!< Watchdog Timer Run Mode Clock Gating Control                          */
  volatile uint32_t  RCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control         */
  volatile uint32_t  RCGCGPIO;                          /*!< General-Purpose Input/Output Run Mode Clock Gating Control            */
  volatile uint32_t  RCGCDMA;                           /*!< Micro Direct Memory Access Run Mode Clock Gating Control              */
  volatile const  uint32_t  RESERVED26;
  volatile uint32_t  RCGCHIB;                           /*!< Hibernation Run Mode Clock Gating Control                             */
  volatile uint32_t  RCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
                                                         Control                                                               */
  volatile uint32_t  RCGCSSI;                           /*!< Synchronous Serial Interface Run Mode Clock Gating Control            */
  volatile uint32_t  RCGCI2C;                           /*!< Inter-Integrated Circuit Run Mode Clock Gating Control                */
  volatile const  uint32_t  RESERVED27;
  volatile uint32_t  RCGCUSB;                           /*!< Universal Serial Bus Run Mode Clock Gating Control                    */
  volatile const  uint32_t  RESERVED28[2];
  volatile uint32_t  RCGCCAN;                           /*!< Controller Area Network Run Mode Clock Gating Control                 */
  volatile uint32_t  RCGCADC;                           /*!< Analog-to-Digital Converter Run Mode Clock Gating Control             */
  volatile uint32_t  RCGCACMP;                          /*!< Analog Comparator Run Mode Clock Gating Control                       */
  volatile uint32_t  RCGCPWM;                           /*!< Pulse Width Modulator Run Mode Clock Gating Control                   */
  volatile uint32_t  RCGCQEI;                           /*!< Quadrature Encoder Interface Run Mode Clock Gating Control            */
  volatile const  uint32_t  RESERVED29[4];
  volatile uint32_t  RCGCEEPROM;                        /*!< EEPROM Run Mode Clock Gating Control                                  */
  volatile uint32_t  RCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control    */
  volatile const  uint32_t  RESERVED30[40];
  volatile uint32_t  SCGCWD;                            /*!< Watchdog Timer Sleep Mode Clock Gating Control                        */
  volatile uint32_t  SCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control       */
  volatile uint32_t  SCGCGPIO;                          /*!< General-Purpose Input/Output Sleep Mode Clock Gating Control          */
  volatile uint32_t  SCGCDMA;                           /*!< Micro Direct Memory Access Sleep Mode Clock Gating Control            */
  volatile const  uint32_t  RESERVED31;
  volatile uint32_t  SCGCHIB;                           /*!< Hibernation Sleep Mode Clock Gating Control                           */
  volatile uint32_t  SCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
                                                         Gating Control                                                        */
  volatile uint32_t  SCGCSSI;                           /*!< Synchronous Serial Interface Sleep Mode Clock Gating Control          */
  volatile uint32_t  SCGCI2C;                           /*!< Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
  volatile const  uint32_t  RESERVED32;
  volatile uint32_t  SCGCUSB;                           /*!< Universal Serial Bus Sleep Mode Clock Gating Control                  */
  volatile const  uint32_t  RESERVED33[2];
  volatile uint32_t  SCGCCAN;                           /*!< Controller Area Network Sleep Mode Clock Gating Control               */
  volatile uint32_t  SCGCADC;                           /*!< Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
  volatile uint32_t  SCGCACMP;                          /*!< Analog Comparator Sleep Mode Clock Gating Control                     */
  volatile uint32_t  SCGCPWM;                           /*!< Pulse Width Modulator Sleep Mode Clock Gating Control                 */
  volatile uint32_t  SCGCQEI;                           /*!< Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
  volatile const  uint32_t  RESERVED34[4];
  volatile uint32_t  SCGCEEPROM;                        /*!< EEPROM Sleep Mode Clock Gating Control                                */
  volatile uint32_t  SCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating
                                                             Control                                                               */
  volatile const  uint32_t  RESERVED35[40];
  volatile uint32_t  DCGCWD;                            /*!< Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
  volatile uint32_t  DCGCTIMER;                         /*!< 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                             Control                                                               */
  volatile uint32_t  DCGCGPIO;                          /*!< General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
  volatile uint32_t  DCGCDMA;                           /*!< Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
  volatile const  uint32_t  RESERVED36;
  volatile uint32_t  DCGCHIB;                           /*!< Hibernation Deep-Sleep Mode Clock Gating Control                      */
  volatile uint32_t  DCGCUART;                          /*!< Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
                                                             Clock Gating Control                                                  */
  volatile uint32_t  DCGCSSI;                           /*!< Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
  volatile uint32_t  DCGCI2C;                           /*!< Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
  volatile const  uint32_t  RESERVED37;
  volatile uint32_t  DCGCUSB;                           /*!< Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
  volatile const  uint32_t  RESERVED38[2];
  volatile uint32_t  DCGCCAN;                           /*!< Controller Area Network Deep-Sleep Mode Clock Gating Control          */
  volatile uint32_t  DCGCADC;                           /*!< Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
  volatile uint32_t  DCGCACMP;                          /*!< Analog Comparator Deep-Sleep Mode Clock Gating Control                */
  volatile uint32_t  DCGCPWM;                           /*!< Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
  volatile uint32_t  DCGCQEI;                           /*!< Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
  volatile const  uint32_t  RESERVED39[4];
  volatile uint32_t  DCGCEEPROM;                        /*!< EEPROM Deep-Sleep Mode Clock Gating Control                           */
  volatile uint32_t  DCGCWTIMER;                        /*!< 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                             Control                                                               */
  volatile const  uint32_t  RESERVED40[104];
  volatile uint32_t  PRWD;                              /*!< Watchdog Timer Peripheral Ready                                       */
  volatile uint32_t  PRTIMER;                           /*!< 16/32-Bit General-Purpose Timer Peripheral Ready                      */
  volatile uint32_t  PRGPIO;                            /*!< General-Purpose Input/Output Peripheral Ready                         */
  volatile uint32_t  PRDMA;                             /*!< Micro Direct Memory Access Peripheral Ready                           */
  volatile const  uint32_t  RESERVED41;
  volatile uint32_t  PRHIB;                             /*!< Hibernation Peripheral Ready                                          */
  volatile uint32_t  PRUART;                            /*!< Universal Asynchronous Receiver/Transmitter Peripheral Ready          */
  volatile uint32_t  PRSSI;                             /*!< Synchronous Serial Interface Peripheral Ready                         */
  volatile uint32_t  PRI2C;                             /*!< Inter-Integrated Circuit Peripheral Ready                             */
  volatile const  uint32_t  RESERVED42;
  volatile uint32_t  PRUSB;                             /*!< Universal Serial Bus Peripheral Ready                                 */
  volatile const  uint32_t  RESERVED43[2];
  volatile uint32_t  PRCAN;                             /*!< Controller Area Network Peripheral Ready                              */
  volatile uint32_t  PRADC;                             /*!< Analog-to-Digital Converter Peripheral Ready                          */
  volatile uint32_t  PRACMP;                            /*!< Analog Comparator Peripheral Ready                                    */
  volatile uint32_t  PRPWM;                             /*!< Pulse Width Modulator Peripheral Ready                                */
  volatile uint32_t  PRQEI;                             /*!< Quadrature Encoder Interface Peripheral Ready                         */
  volatile const  uint32_t  RESERVED44[4];
  volatile uint32_t  PREEPROM;                          /*!< EEPROM Peripheral Ready                                               */
  volatile uint32_t  PRWTIMER;                          /*!< 32/64-Bit Wide General-Purpose Timer Peripheral Ready                 */
} SYSCTL_Type;


/* ================================================================================ */
/* ================                     GPIOx                      ================ */
/* ================================================================================ */

typedef struct
{
    volatile uint32_t DATA_MASK[256];
    volatile uint32_t DATA;
    volatile uint32_t DIR;
    volatile uint32_t IS;
    volatile uint32_t  IBE;                               
    volatile uint32_t  IEV;                               
    volatile uint32_t  IM;                                
    volatile uint32_t  RIS;                               
    volatile uint32_t  MIS;                               
    volatile uint32_t  ICR;                               
    volatile uint32_t  AFSEL;                             
    volatile const uint32_t  RESERVED1[55];
    volatile uint32_t  DR2R;                              
    volatile uint32_t  DR4R;                              
    volatile uint32_t  DR8R;                              
    volatile uint32_t  ODR;                               
    volatile uint32_t  PUR;                               
    volatile uint32_t  PDR;                               
    volatile uint32_t  SLR;                               
    volatile uint32_t  DEN;                               
    volatile uint32_t  LOCK;                              
    volatile uint32_t  CR;                                
    volatile uint32_t  AMSEL;                             
    volatile uint32_t  PCTL;                              
    volatile uint32_t  ADCCTL;                            
    volatile uint32_t  DMACTL;                            
}GPIOx_Type;


/**********************************************************************************************************************
 * Base Addresses Definition
 *********************************************************************************************************************/
#define CORE_CM4_PERIPHERNAL_BASE_ADDRESS                       (uint32_t)(0xE000E000)
#define TM4C123G_PERIPHERNAL_BASE_ADDRESS                       (uint32_t)(0x40000000)

#define SYSTIMER_BASE_ADDR                                      (uint32_t)(CORE_CM4_PERIPHERNAL_BASE_ADDRESS + 0x0010UL)
#define NVIC_BASE_ADDR                                          (uint32_t)(CORE_CM4_PERIPHERNAL_BASE_ADDRESS + 0x0100UL)
#define SCB_BASE_ADDR                                           (uint32_t)(CORE_CM4_PERIPHERNAL_BASE_ADDRESS + 0x0D00UL)
#define SYSCTL_BASE_ADDR                                        (uint32_t)(0x400FE000UL                                )

#define GPIOA_APB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x4000  )
#define GPIOA_AHB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x58000 )

#define GPIOB_APB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x5000  )
#define GPIOB_AHB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x59000 )

#define GPIOC_APB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x6000  )
#define GPIOC_AHB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x5A000 )

#define GPIOD_APB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x7000  )
#define GPIOD_AHB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x5B000 )

#define GPIOE_APB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x24000 )
#define GPIOE_AHB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x5C000 )

#define GPIOF_APB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x25000 )
#define GPIOF_AHB_BASE_ADDR                                     (uint32_t)(TM4C123G_PERIPHERNAL_BASE_ADDRESS + 0x5D000 )


#define SysTick                                                 ( (SysTick_Type  *) SYSTIMER_BASE_ADDR )
#define NVIC                                                    ( (NVIC_Type     *) NVIC_BASE_ADDR     )
#define SCB                                                     ( (SCB_Type      *) SCB_BASE_ADDR      )
#define SYSCTL                                                  ( (SYSCTL_Type   *) SYSCTL_BASE_ADDR   )

#define GET_GPIO(PIN_TYPE)                                      ( ( GPIOx_Type   *) ( GPIOA_APB_BASE_ADDR +  ( ( PIN_TYPE ) *  0x1000) + 0x4000 + ( ( PIN_TYPE > 3 )? ( 0x1C000 ):( 0x00 ) ) ) )
#define GPIOA                                                   ( ( GPIOx_Type   *) GPIOA_APB_BASE_ADDR)
#define GPIOB                                                   ( ( GPIOx_Type   *) GPIOB_APB_BASE_ADDR)
#define GPIOC                                                   ( ( GPIOx_Type   *) GPIOC_APB_BASE_ADDR)
#define GPIOD                                                   ( ( GPIOx_Type   *) GPIOD_APB_BASE_ADDR)
#define GPIOE                                                   ( ( GPIOx_Type   *) GPIOE_APB_BASE_ADDR)
#define GPIOF                                                   ( ( GPIOx_Type   *) GPIOF_APB_BASE_ADDR)

#define GPIOA_AHB                                               ( ( GPIOx_Type   *) GPIOA_AHB_BASE_ADDR)
#define GPIOB_AHB                                               ( ( GPIOx_Type   *) GPIOB_AHB_BASE_ADDR)
#define GPIOC_AHB                                               ( ( GPIOx_Type   *) GPIOC_AHB_BASE_ADDR)
#define GPIOD_AHB                                               ( ( GPIOx_Type   *) GPIOD_AHB_BASE_ADDR)
#define GPIOE_AHB                                               ( ( GPIOx_Type   *) GPIOE_AHB_BASE_ADDR)
#define GPIOF_AHB                                               ( ( GPIOx_Type   *) GPIOF_AHB_BASE_ADDR)

/*******************************************************************************
 *                Core Peripheral Special APIs
 ******************************************************************************/

#define EnterPrivilegedMode()               __ASM("SVC #0")
#define DisableFaultExceptions()            __ASM("cpsid f")
#define DisableInterrupt()                  __ASM("cpsid i")


#endif  /* __MCU_HW_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
 