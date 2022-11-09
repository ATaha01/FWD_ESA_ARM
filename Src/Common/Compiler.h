/**
 * @file Compiler.h
 * @author Ahmed Taha (ahmed.m.taha01@gmail.com)
 * @brief Contains Compiler Dependent MACRO Definition 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __COMPILER_H__
#define __COMPILER_H__

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*  NULL_PTR is a Void Pointer to Zero*/
#define NULL_PTR                ((void *)0)

#ifndef __WEAK
    #define __WEAK              __attribute__((weak))
#endif

#ifndef __FORCEINLINE
    #define __FORCEINLINE       __attribute__((always_inline))
#endif

#ifndef __INLINE
    #define _INLINE             inline
#endif

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

 
#endif  /* __COMPILER_H__ */

/**********************************************************************************************************************
 *  END OF FILE: Compiler.h
 *********************************************************************************************************************/