#include "tim_g_interrupt.h"

/**
  * @brief  ����ͨ�ö�ʱ�����м򵥵ļ�ʱ��� �����ж� 
  *         
  *         
  * @note   TIMGeneral TIM2,3,4,5
  * @param  arr��װ��ֵ,pscԤ��Ƶϵ��
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
	TIM_TimeBaseInitStruct.TIM_ClockDivision= 0;  //���벶�� ��Ϊ����Ч�Լ�飬��������һ����Чֵ��
	//TIM_TimeBaseInitStruct.TIM_RepetitionCounter=   //�߼���ʱ��ʹ��
	TIM_TimeBaseInit(TIM_GENERAL,&TIM_TimeBaseInitStruct);  //����ARR, PSC�Ĵ���
	
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




