#include "tim_g_interrupt.h"

/**
  * @brief  利用通用定时器进行简单的计时溢出 更新中断 
  *         
  *         
  * @note   TIMGeneral TIM2,3,4,5
  * @param  arr重装载值,psc预分频系数
  * @retval None
  */
  
void TIM_GENERAL_Init(uint16_t arr,uint16_t psc)
{
	TIM_TimeBaseInitTypeDef	 	TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef		 	NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM_GENERAL,ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_CounterMode= TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period= arr;
	TIM_TimeBaseInitStruct.TIM_Prescaler= psc;
	TIM_TimeBaseInitStruct.TIM_ClockDivision= 0;  //输入捕获 因为有有效性检查，所以输入一个有效值；
	//TIM_TimeBaseInitStruct.TIM_RepetitionCounter=   //高级定时器使用
	TIM_TimeBaseInit(TIM_GENERAL,&TIM_TimeBaseInitStruct);  //配置ARR, PSC寄存器
	
	TIM_ITConfig(TIM_GENERAL,TIM_IT_Update,ENABLE);
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM_GENERAL_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM_GENERAL,ENABLE);
}

void TIM_GENERAL_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM_GENERAL,TIM_IT_Update) != RESET)     //TIM_FLAG_Update
	{
		LED0 = !LED0;
		TIM_ClearITPendingBit(TIM_GENERAL,TIM_IT_Update);
	}
}




