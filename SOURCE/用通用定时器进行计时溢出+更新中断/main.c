#include "led.h"
#include "tim_g_interrupt.h"

int main(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	delay_init();
	LED_Init();
	TIM_GENERAL_Init(4999,7199);
	
	
	while(1)
	{
		LED1 = !LED1;
		delay_ms(1000);
	}
	
}






