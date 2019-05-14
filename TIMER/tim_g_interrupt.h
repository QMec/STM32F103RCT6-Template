#ifndef  	 	__TIM_G_INTERRUPT_H
#define  	 	__TIM_G_INTERRUPT_H

#include 	 	"stm32f10x.h"
#include 	 	"led.h"
#include  		"delay.h"

//通过宏定义选择通用定时器
#define 		TIM_GENERAL_2
//#define 		TIM_GENERAL_3
//#define		TIM_GENERAL_4
//#define		TIM_GENERAL_5

#ifdef     		TIM_GENERAL_2
#define			TIM_GENERAL					TIM2
#define			RCC_APB1Periph_TIM_GENERAL	RCC_APB1Periph_TIM2
#define			TIM_GENERAL_IRQn				TIM2_IRQn
#define			TIM_GENERAL_IRQHandler       TIM2_IRQHandler

#elif			TIM_GENERAL_3
#define			TIM_GENERAL					TIM3
#define			RCC_APB1Periph_TIM_GENERAL	RCC_APB1Periph_TIM3
#define			TIM_GENERAL_IRQn				TIM3_IRQn
#define			TIM_GENERAL_IRQHandler       TIM3_IRQHandler

#elif			TIM_GENERAL_4
#define			TIM_GENERAL					TIM4
#define			RCC_APB1Periph_TIM_GENERAL	RCC_APB1Periph_TIM4
#define			TIM_GENERAL_IRQn				TIM4_IRQn
#define			TIMG_ENERAL_IRQHandler       TIM4_IRQHandler

#elif			TIM_GENERAL_5
#define			TIM_GENERAL					TIM5
#define			RCC_APB1Periph_TIM_GENERAL	RCC_APB1Periph_TIM5
#define			TIM_GENERAL_IRQn				TIM5_IRQn
#define			TIM_GENERAL_IRQHandler       TIM5_IRQHandler

#endif


void TIM_GENERAL_Init(uint16_t arr,uint16_t psc);

#endif
