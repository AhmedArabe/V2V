/********************************************************/
/********   Author  : Ahmed Arabe      ******************/
/********   SWC     : IR               ******************/
/********   Date    : 10/10/2023       ******************/
/********   Version : 1.00             ******************/
/********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/EXTI/EXTI_interface.h"
#include "../../MCAL/NVIC/NVIC_interface.h"
#include "../../MCAL/SYSTICK/Systick_interface.h"
#include "IR_interface.h"


/*******************************************************/
volatile u32 Data_Frame_Time[34]={0};
volatile u8 Data = 0;
volatile u8 flag = 1;
volatile u8 counter = 0;
/*******************************************************/
void Read_data(void (*PTF)(void))
{
	counter=0;
	flag=1;
	//	Data=0;
	for(u8 i=0;i<8;i++)
	{
		if(Data_Frame_Time[i+17] >=1000 && Data_Frame_Time[17+i]<=1500)
		{
			CLR_BIT(Data,i);
		}
		else if(Data_Frame_Time[i+17] >=2100 && Data_Frame_Time[17+i]<=2500)
		{
			SET_BIT(Data,i);
		}
	}

	PTF();
	for(u8 i=0;i<34;i++)
	{
		Data_Frame_Time[i] = 0;
	}

	flag = 1;

}
/*******************************************************/
extern void Read_time()
{

	if(flag==1)
	{
		MSTK_vSetIntervalSingle(1000,Read_data);
		flag=0;
	}
	else
	{

		Data_Frame_Time[counter] =  MSTK_u32GetElapsedTime();
		MSTK_vSetIntervalSingle(1000,Read_data);

		counter++;
		if(counter==34)
		{
			counter=33;
		}
	}
}


