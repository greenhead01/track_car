#include "Tcrt.h"
#include "sys.h"

void Tcrt_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);	
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11 | GPIO_Pin_12; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB.1;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; 
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
  GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.5;
}

