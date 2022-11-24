#include "stm32f10x.h"
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
//在库函数中， PWM 通道设置是通过函数 TIM_OC1Init()~TIM_OC4Init()来设置的，
//不同的通道的设置函数不一样，这里我们使用的是通道 1，所以使用的函数是 TIM_OC1Init()。
//先初始化，随后‘’再‘’修改占空比

void TIM2_PWM_Init(u16 arr,u16 psc)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//TIM2通道2
	
	
	TIM_TimeBaseStructure.TIM_Period = arr; 
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
		
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);  
  TIM_CtrlPWMOutputs(TIM2,ENABLE);
	
 
  NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&NVIC_InitStructure);

	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //CH2预装载使能	 
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);  //CH4预装载使能	 
	TIM_ARRPreloadConfig(TIM2, ENABLE); //使能TIMx在ARR上的预装载寄存器
	TIM_Cmd(TIM2, ENABLE); 
	//使能更新中断
	TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_CC1,ENABLE);
 
} 









