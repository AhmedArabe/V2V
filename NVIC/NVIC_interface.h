/********************************************************/
/********   Author  : Ahmed Arabe      ******************/
/********   SWC     : NVIC             ******************/
/********   Date    : 10/10/2023       ******************/
/********   Version : 1.00             ******************/
/********************************************************/

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

#define NVIC_16_GROUPS   0b011  // 3
#define NVIC_8_GROUPS    0b100  // 4
                                // 5   6  7


#define  NVIC_SYSTICK       -5
#define  NVIC_PEND_SV       -6

#define  NVIC_SV_CALL       -4

#define NVIC_USAGE_FAULT    -1
#define NVIC_BUS_FAULT      -2
#define NVIC_MEMORY_MANAGE  -3

#define	NVIC_WWDG            0
#define	NVIC_PVD             1
#define NVIC_EXTI16          1
#define	NVIC_TAMP_STAMP      2
#define NVIC_EXTI21          2
#define NVIC_EXTI22          3
#define	NVIC_RTC_WKUP        3

#define	NVIC_FLASH           4
#define	NVIC_RCC             5
#define	NVIC_EXTI0           6
#define	NVIC_EXTI1           7
#define	NVIC_EXTI2           8
#define	NVIC_EXTI3           9
#define	NVIC_EXTI4           10
////////////////////////////////////////////////////////////////////////
void MNVIC_vEnableInteruptPeripheral(u8 A_u8IntId);

void MNVIC_vDisableInteruptPeripheral(u8 A_u8IntId);

/*Test SW int*/
void MNVIC_vSetPending(u8 A_u8IntId);

void MNVIC_vClearPending(u8 A_u8IntId);

//to check

u8 MNVIC_u8GetActive(u8 A_u8IntId);


void MNVIC_vSetPriorityCfg(u8 A_u8Group);

void MNVIC_vSetPriority(s8 A_s8IntId , u8 A_u8GroupPriority,u8 A_u8SubPriority);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
