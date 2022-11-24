#include "dir.h"
#include "stm32f10x.h"

extern u16 PWMA;
extern u16 PWMB;
extern u16 D;
void AIN_Init(){
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}
void BIN_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void turnleft()	//缓慢左转
{
		AIN1=0;
		AIN2=0;
		BIN1=1;
		BIN2=0;
		PWMA=199;
		PWMB=170;
}

void turnleft2()	//大角度左转
{
	AIN1=0;
	AIN2=1;
	BIN1=1;
	BIN2=0;
	PWMA=175;
	PWMB=175;
}

void turnright()	//缓慢右转
{
		AIN1=1;
		AIN2=0;
		BIN1=0;
		BIN2=0;
		PWMA=170;
		PWMB=199;
}

void turnright2()		//大角度右转
{
	AIN1=1;
	AIN2=0;
	BIN1=0;
	BIN2=1;
	PWMA=175;
	PWMB=175;
}

void stop()
{
	AIN1=0;
	AIN2=0;
	BIN1=0;
	BIN2=0;
	PWMA=199;
	PWMB=199;
}

void straight()
{
	AIN1=1;
	AIN2=0;
	BIN1=1;
	BIN2=0;
	PWMA=170;
	PWMB=170;
}