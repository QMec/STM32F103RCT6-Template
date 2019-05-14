#include "tim_pwm.h"

void TIM_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef 			GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef 			TIM_OCInitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;   //复用推挽输出
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;  
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_Period=arr;
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	//TIM_TimeBaseInitStruct.TIM_RepetitionCounter=
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStruct);
	
	TIM_OCInitStruct.TIM_OCMode=TIM_OCMode_PWM1;
	//TIM_OCInitStruct.TIM_OCIdleState=
	//TIM_OCInitStruct.TIM_OCNIdleState=
	//TIM_OCInitStruct.TIM_OCNPolarity=
	TIM_OCInitStruct.TIM_OCPolarity=TIM_OCPolarity_Low;
	//TIM_OCInitStruct.TIM_OutputNState=
	TIM_OCInitStruct.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStruct.TIM_Pulse=0;
	TIM_OC1Init(TIM1,&TIM_OCInitStruct);
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);  //MOE位,主输出使能
	
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);  //预装载使能
	
	TIM_ARRPreloadConfig(TIM1,ENABLE);
	
	TIM_Cmd(TIM1,ENABLE);
}





