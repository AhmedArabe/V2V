/********************************************************/
/********   Author  : Ahmed Arabe      ******************/
/********   SWC     : SYSTICK          ******************/
/********   Date    : 10/10/2023       ******************/
/********   Version : 1.00             ******************/
/********************************************************/


#ifndef MCAL_SYSTICK_SYSTICK_CFG_H_
#define MCAL_SYSTICK_SYSTICK_CFG_H_


/*systick clock sources options :
 *
 * 1- STK_AHB
 * 2- STK_AHB_8
 *
 */
#define STK_CLK_SOURCE   STK_AHB_8

/*systick options for interrupt enable options :
 *
 * 1- STK_INT_EN
 * 2- STK_INT_DIS
 *
 *
 */
#define STK_INT_OPTION   STK_INT_EN


#endif /* MCAL_SYSTICK_SYSTICK_CFG_H_ */
