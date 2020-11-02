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
//	char b[]={"0x31,0x32,0x33,0x34 0x35 0x00 0x36,0x37,哈"};
//	char c[]={"0x31,0x32,0x33,0x34 0x35 \0 0x36,0x37"};
//	char d[]={'1','2','3','4','5','6','7'};
	u8 zero[]= {0x30,0x0d,0x0a};
	u8 one[] = {0x31,0x0d,0x0a};
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	KEY_Init();          //初始化与按键连接的硬件接口
	 
 	while(1)
	{
//		for(t=0;t<3;t++)
//		{
//		
//			USART_SendData(USART1, e[t]);//向串口1发送数据
//			while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
//		}
	
//		if(USART_RX_BUF[0] == '2')
//			printf("hhhhh");

//		delay_ms(300); 
//		LED0 =! LED0;//闪烁LED,提示系统正在运行.
//		
//		if(USART_RX_STA&0x8000)
//		{					   
//			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
//			printf("\r\n您发送的消息为:\r\n\r\n");
//			for(t=0;t<len;t++)
//			{
//				USART_SendData(USART1, USART_RX_BUF[t]);//向串口1发送数据
//				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
//			}
//			if(USART_RX_BUF[0] == '2')
//				printf("hhhhh");//插入换行
//			printf("\r\n\r\n");//插入换行
//			USART_RX_STA=0;
//		}else
//		{
//			times++;
//			if(times%5000==0)
//			{
//				printf("\r\n精英STM32开发板 串口实验\r\n");
//				printf("正点原子@ALIENTEK\r\n\r\n");
//			}
//			if(times%200==0)printf("%c\n",a);  
//			if(times%30==0)LED0=!LED0;//闪烁LED,提示系统正在运行.
//			delay_ms(10);   
//		}

		key=KEY_Scan(0);	//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				
				case KEY1_PRES:	//控制LED1翻转	 
					for(t=0;t<3;t++)
					{
						USART_SendData(USART1, zero[t]);//向串口1发送数据
						while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
					}
					break;
					
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
					for(t=0;t<3;t++)
					{
						USART_SendData(USART1, one[t]);//向串口1发送数据
						while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
					}
					break;
			}
		}else delay_ms(10); 
	}	 
 }

