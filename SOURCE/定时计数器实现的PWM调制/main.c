#include "led.h"
#include "tim_pwm.h"

int main(void)
{

	u16 pwmvalue = 0;
	u8	flag = 1;
	
	delay_init();
	
	TIM_PWM_Init(899,0);
	
	while(1)
	{
		delay_ms(10);
		
		if(flag) pwmvalue++;
		else 	 pwmvalue--;	
		
		if(pwmvalue>300) flag=0;
		if(pwmvalue==0) flag=1;
		
		TIM_SetCompare1(TIM1,pwmvalue);
	}
}
