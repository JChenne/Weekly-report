#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
 
 int main(void)
 {		
 	vu8 key=0;	
 	u16 t;  
//	u8 a[]= {'5',0x33,0x34,0x35,0x00,0x36,0x37}; 	 //ascii
//	int aa[]={'123',0x38373635,0x0000};
//	char b[]={"0x31,0x32,0x33,0x34 0x35 0x00 0x36,0x37,��"};
//	char c[]={"0x31,0x32,0x33,0x34 0x35 \0 0x36,0x37"};
//	char d[]={'1','2','3','4','5','6','7'};
	u8 zero[]= {0x30,0x0d,0x0a};
	u8 one[] = {0x31,0x0d,0x0a};
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	LED_Init();			     //LED�˿ڳ�ʼ��
	KEY_Init();          //��ʼ���밴�����ӵ�Ӳ���ӿ�
	 
 	while(1)
	{
//		for(t=0;t<3;t++)
//		{
//		
//			USART_SendData(USART1, e[t]);//�򴮿�1��������
//			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
//		}
	
//		if(USART_RX_BUF[0] == '2')
//			printf("hhhhh");

//		delay_ms(300); 
//		LED0 =! LED0;//��˸LED,��ʾϵͳ��������.
//		
//		if(USART_RX_STA&0x8000)
//		{					   
//			len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
//			printf("\r\n�����͵���ϢΪ:\r\n\r\n");
//			for(t=0;t<len;t++)
//			{
//				USART_SendData(USART1, USART_RX_BUF[t]);//�򴮿�1��������
//				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
//			}
//			if(USART_RX_BUF[0] == '2')
//				printf("hhhhh");//���뻻��
//			printf("\r\n\r\n");//���뻻��
//			USART_RX_STA=0;
//		}else
//		{
//			times++;
//			if(times%5000==0)
//			{
//				printf("\r\n��ӢSTM32������ ����ʵ��\r\n");
//				printf("����ԭ��@ALIENTEK\r\n\r\n");
//			}
//			if(times%200==0)printf("%c\n",a);  
//			if(times%30==0)LED0=!LED0;//��˸LED,��ʾϵͳ��������.
//			delay_ms(10);   
//		}

		key=KEY_Scan(0);	//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				
				case KEY1_PRES:	//����LED1��ת	 
					for(t=0;t<3;t++)
					{
						USART_SendData(USART1, zero[t]);//�򴮿�1��������
						while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
					}
					break;
					
				case KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
					for(t=0;t<3;t++)
					{
						USART_SendData(USART1, one[t]);//�򴮿�1��������
						while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//�ȴ����ͽ���
					}
					break;
			}
		}else delay_ms(10); 
	}	 
 }

