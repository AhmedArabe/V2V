
/********************************************************/
/********   Author  : Ahmed Arabe      ******************/
/********   SWC     : EXTI             ******************/
/********   Date    : 10/10/2023       ******************/
/********   Version : 1.00             ******************/
/********************************************************/

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS   0x40013C00

typedef  struct
{
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER ;
	volatile u32 PR ;
}EXTI_MemMap_t;

#define EXTI     ((volatile EXTI_MemMap_t*)(EXTI_BASE_ADDRESS))

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
