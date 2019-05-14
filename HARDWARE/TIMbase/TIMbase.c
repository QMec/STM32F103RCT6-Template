#include "TIMbase.h"
#include "led.h"
#include "delay.h"




void BASIC_TIM_Config(void)
{

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
		//开启定时器
	BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK,ENABLE);
	
	
	TIM_TimeBaseInitStruct.TIM_Period= 1000;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;
	TIM_TimeBaseInitStruct.TIM_Prescaler= 71;
	TIM_TimeBaseInit(BASIC_TIM,&TIM_TimeBaseInitStruct);
	
	//清除计数器中断标志
	TIM_ClearFlag(BASIC_TIM,TIM_FLAG_Update);
	
	//开启定时器中断
	TIM_ITConfig(BASIC_TIM,BASIC_TIM_IRQ,ENABLE);
	
	//使能计数器
	TIM_Cmd(BASIC_TIM,ENABLE);
	

}

void BASIC_TIM_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct; 
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStruct.NVIC_IRQChannel= BASIC_TIM_IRQ;
	NVIC_InitStruct.NVIC_IRQChannelCmd= ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority= 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority= 2;
	NVIC_Init(&NVIC_InitStruct);
}




