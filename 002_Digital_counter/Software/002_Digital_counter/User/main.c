
/*********************************************************************************************
程序名：	电子计数器
编写人：	emboss2017
编写时间：	2024-03-15
硬件支持：	STM32F103C8   外部晶振8MHz RCC函数设置主频72MHz　  

修改日志：　　
1-	

说明：
 # 本模板加载了STM32F103内部的RCC时钟设置，并加入了利用滴答定时器的延时函数。

*********************************************************************************************/

#include "stm32f10x.h" //STM32头文件
#include "sys.h"
#include "delay.h"
#include "led.h"

#include "key.h" 

#include "oled0561.h"

int main (void){//主程序
	u8 a; //定义变量
	//初始化程序
	RCC_Configuration(); //时钟设置
	LED_Init();//LED初始化
	KEY_Init();//按键初始化
	
	I2C_Configuration();//I2C初始化
	OLED0561_Init(); //OLED初始化
	OLED_DISPLAY_LIT(100);//亮度设置
	
	a=0;
	
	//主循环
	while(1){

		//有锁存
    OLED_DISPLAY_8x16_BUFFER(2,"  Counter:"); //显示字符串
		OLED_DISPLAY_8x16(2,11*8,a%10+0x30);//
		
		if(!GPIO_ReadInputDataBit(KEYPORT,KEY1)){ //读按键接口的电平
			delay_ms(20); //延时去抖动
			if(!GPIO_ReadInputDataBit(KEYPORT,KEY1)){ //读按键接口的电平
				while(!GPIO_ReadInputDataBit(KEYPORT,KEY1)); //等待按键松开 
				a++;
			}
		}
		
		if(!GPIO_ReadInputDataBit(KEYPORT,KEY2)){ //读按键接口的电平
			delay_ms(20); //延时去抖动
			if(!GPIO_ReadInputDataBit(KEYPORT,KEY2)){ //读按键接口的电平
				while(!GPIO_ReadInputDataBit(KEYPORT,KEY2)); //等待按键松开 
				a=0;
			}
		}

	}
}

/*

【变量定义】
u32     a; //定义32位无符号变量a
u16     a; //定义16位无符号变量a
u8     a; //定义8位无符号变量a
vu32     a; //定义易变的32位无符号变量a
vu16     a; //定义易变的 16位无符号变量a
vu8     a; //定义易变的 8位无符号变量a
uc32     a; //定义只读的32位无符号变量a
uc16     a; //定义只读 的16位无符号变量a
uc8     a; //定义只读 的8位无符号变量a

#define ONE  1   //宏定义

delay_us(1); //延时1微秒
delay_ms(1); //延时1毫秒
delay_s(1); //延时1秒

*/



