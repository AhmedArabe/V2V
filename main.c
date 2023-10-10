#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"
#include "HAL/IR/IR_interface.h"
#include "MCAL/SYSTICK/Systick_interface.h"
#include "MCAL/TIMER/Timer_init.h"

extern  volatile u8 Data ;
// TIMER 2 --> CH1 --> PA5
// TIMER 3 --> CH1 --> PA6
// TIMER 4 --> CH1 --> PB6
// TIMER 5 --> CH2 --> PA1


void IR_APP(void);
void main(void)
{

	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1 , RCC_GPIO_A);
	MRCC_vEnableClock(RCC_APB2 , RCC_SYSCFG);


	MSTK_vInit();
	MGPIO_Config_t x = { .Port_ID =GPIO_Port_A , .Pin_ID =GPIO_Pin0 , .mode = Digital_input , .output_speed = Low ,.input_pull_type = No_resistor };
	MGPIO_Config_t M1_P1 = { .Port_ID =GPIO_Port_A , .Pin_ID =GPIO_Pin1 , .mode = Digital_output , .output_speed = Low , .input_pull_type = Push_pull };
	MGPIO_Config_t M1_P2 = { .Port_ID =GPIO_Port_A , .Pin_ID =GPIO_Pin2 , .mode = Digital_output , .output_speed = Low , .input_pull_type = Push_pull };



	MGPIO_vInit(&x); MGPIO_vInit(&M1_P1); MGPIO_vInit(&M1_P2);


	MEXTI_vSetCallBack(EXTI_LINE0,Read_time);
	MEXTI_vEnableLine(EXTI_LINE0,EXTI_FAILING);
	MNVIC_vEnableInteruptPeripheral(6);

	MTimer_voidInit(TIM2_TYPE);
	MTimer_voidInit(TIM3_TYPE);
	MTimer_voidInit(TIM4_TYPE);
	MTimer_voidInit(TIM5_TYPE);
	Read_data(IR_APP);



	while(1) ;
}

void IR_APP(void)
{
	if(Data == NUM_2 ) // forward speed low
	{

		//		MGPIO_vSetPin(GPIO_Port_A , GPIO_Pin1 , Low);
		MTimer_voidPWM(TIM2_TYPE , TIM_CHANNEL_1 ,0);
		MTimer_voidPWM(TIM3_TYPE , TIM_CHANNEL_1 ,10);

		MTimer_voidPWM(TIM4_TYPE , TIM_CHANNEL_1 ,0);
		MTimer_voidPWM(TIM5_TYPE , TIM_CHANNEL_2 ,10);

	}
	else if(Data == NUM_3) // forward speed high
	{
		//		MGPIO_vSetPin(GPIO_Port_A , GPIO_Pin1 , Low);
		MTimer_voidPWM(TIM2_TYPE , TIM_CHANNEL_1 ,0);
		MTimer_voidPWM(TIM3_TYPE , TIM_CHANNEL_1 ,200);

		MTimer_voidPWM(TIM4_TYPE , TIM_CHANNEL_1 ,0);
		MTimer_voidPWM(TIM5_TYPE , TIM_CHANNEL_2 ,10);

	}
	else if(Data == NUM_4) // backword low speed
	{
		MTimer_voidPWM(TIM2_TYPE , TIM_CHANNEL_1 ,10);
		MTimer_voidPWM(TIM3_TYPE , TIM_CHANNEL_1 ,0);

		MTimer_voidPWM(TIM4_TYPE , TIM_CHANNEL_1 ,10);
		MTimer_voidPWM(TIM5_TYPE , TIM_CHANNEL_2 ,0);

	}
	else if(Data == NUM_5)// backword high high
	{
		MTimer_voidPWM(TIM2_TYPE , TIM_CHANNEL_1 ,100);
		MTimer_voidPWM(TIM3_TYPE , TIM_CHANNEL_1 ,0);

		MTimer_voidPWM(TIM4_TYPE , TIM_CHANNEL_1 ,100);
		MTimer_voidPWM(TIM5_TYPE , TIM_CHANNEL_2 ,0);

	}

}




