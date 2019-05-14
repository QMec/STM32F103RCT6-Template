#ifndef  	__LED_H
#define	 	__LED_H

#include  "stm32f10x.h"
#include  "sys.h"
#include "delay.h"

#define   LED0       													PAout(8)
#define   LED1       													PDout(2)

#define		LED0_GPIO_PORT											GPIOA
#define		LED0_GPIO_CLK												RCC_APB2Periph_GPIOA
#define 	LED0_GPIO_PIN												GPIO_Pin_8


#define 	LED1_GPIO_PORT											GPIOD
#define   LED1_GPIO_CLK												RCC_APB2Periph_GPIOD
#define   LED1_GPIO_PIN												GPIO_Pin_2

void LED_Init(void);
void Main_Led(void);

#endif

