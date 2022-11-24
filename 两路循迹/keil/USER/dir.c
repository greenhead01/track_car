#include "dir.h"
#include "stm32f10x.h"

void AIN_Init(){
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
void roll1(){
	AIN1 = 1;
	AIN2 = 0;
}
void roll0(){
	AIN1 = 0;
	AIN2 = 1;
}