#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "Tcrt.h"
#include "time3.h"
#include "pwm.h"
#include "dir.h"

u8 resl1='0';
u8 resr1='0';
u8 resl2='0';
u8 resr2='0';
u16 PWMA=0;
u16 PWMB=0;
u16 D=0;
int flag = -1;
 int main(void)
 {	
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
	 delay_init();	    //��ʱ������ʼ��	 
	 Tcrt_Init();
	 uart_init(9600);
	 TIM2_PWM_Init(199,7199);	//�������50Hz
	 TIM3_Init(99,71999);	//��ʱ������������Ϊ100ms����200ms���IOһ��
	 while(1){
		if(flag == -1){
			printf("%d   %d	  %d 	 %d\r\n",resl1,resl2,resr2,resr1);
			
			TIM_SetCompare4(TIM2,PWMA);		//����
			TIM_SetCompare2(TIM2,PWMB);		//����
			//delay_ms(500);
			if(resl1==0&&resl2==0&&resr2==0&&resr1==0){
					switch(D){
						case 0:
							straight();		break;
						case 1:
							turnleft2();	break;
						case 2:
							turnright2();		break;
						default:
							stop();			break;
					}
			}
			if(resl1==0&&resl2==1&&resr2==0&&resr1==0){		//����
					turnleft();
					D=0;
			}
			if(resl1==1&&resl2==1&&resr2==0&&resr1==0){		//����
					turnleft2();
					D=1;
			}
			if(resl1==1&&resl2==0&&resr2==0&&resr1==0){		//����
					turnleft2();
					D=1;
			}
			if(resl1==0&&resl2==0&&resr2==1&&resr1==0){		//����
					turnright();
					D=0;
			}
			if(resl1==0&&resl2==0&&resr2==0&&resr1==1){		//����
					turnright2();
					D=2;
			}
			if(resl1==0&&resl2==0&&resr2==1&&resr1==1){		//����
					turnright2();
					D=2;
			}
			if(resl1==1&&resl2==1&&resr2==1&&resr1==1){		//ͣ��
					stop();
					D=3;
			}
	 }		
  }
 }


 