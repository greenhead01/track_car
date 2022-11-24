#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "stm32f10x.h"
#include "pwm.h"
#include "dir.h"

int main(void)
 {	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
	delay_init();	    	 //延时函数初始化	  
	usart_init(9600);	 //串口初始化为9600
	AIN_Init();
	TIM2_PWM_Init(199,7199);
	TIM_SetCompare2(TIM2,100);
	TIM_SetCompare4(TIM2,100);
		while(1)
	 {
			roll1();
			delay_ms(1000);
			roll0();
	 }
  
		
} 

