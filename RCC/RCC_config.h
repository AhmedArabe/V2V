/********************************************************/
/********   Author  : Ahmed Arabe      ******************/
/********   SWC     : RCC              ******************/
/********   Date    : 10/10/2023       ******************/
/********   Version : 1.00             ******************/
/********************************************************/

#ifndef MCAL_RCC_CFG_H_
#define MCAL_RCC_CFG_H_

#include "RCC_pivate.h"

/*options of system clock:
 * 1- HSI
 * 2- HSE
 * 3- PLL
 *  */
#define SYSTEM_CLOCK  HSI

//HSE options
#if SYSTEM_CLOCK == HSE
/*              HSE bypassing options
 * 1- HSE_NOT_BYPASSED
 * 2- HSE_BYPASSED*/
#define HSE_BYPASSING    HSE_NOT_BYPASSED
#endif



//PLL options:
/* P values : 2,4,,6,8
 * N range : 192 -> 432
 * M range : 2 -> 63*/
#if SYSTEM_CLOCK == PLL
#define PLLP          2
#define PLLN          192
#define PLLM          2
#define HSI_PLL_INPUT 0
#define HSE_PLL_INPUT 1
//PLL input options : 1- HSI_PLL_INPUT , 2- HSE_PLL_INPUT
#define PLL_SOURCE    HSI_PLL_INPUT
#endif

/*              AHB PRESCALER OPTIONS :
 *  AHB_FCPU
 *  AHB_FCPU_2
 *  AHB_FCPU_4
 *  AHB_FCPU_8
 *  AHB_FCPU_16
 *  AHB_FCPU_64
 *  AHB_FCPU_128
 *  AHB_FCPU_256
 *  AHB_FCPU_512
 *
 * */
#define AHB_PRESCALER     AHB_FCPU_2

/*             APB2 PRESCALER OPTIONS:
 * 1- APB2_AHB_1    2- APB2_AHB_2    3- APB2_AHB_4
 * 4- APB2_AHB_8    5- APB2-AHB_16*/
#define APB2_PRESCALER    APB2_AHB_1

#endif /* MCAL_RCC_CFG_H_ */
