
/*********************************************************************************************
程序名:	  时钟程序
编写人:	  emboss2017
编写时间:	2023-11-07
硬件支持:	STM32F103C8 外部晶振8MHz RCC函数设置主频72MHz   

修改日志:  
1- 
							
说明:
 # 加载了STM32F103内部的RCC时钟设置,加入了利用滴答定时器的延时函数。
*********************************************************************************************/

#include "stm32f10x.h" //STM32头文件
#include "sys.h"
#include "delay.h"
#include "rtc.h"
#include "oled0561.h"
#include "stdio.h"

int main (void){//主程序
	delay_ms(1000); //上电时等待其他器件就绪
	RCC_Configuration(); //系统时钟初始化
	RTC_Config(); //实时时钟初始化
	
	I2C_Configuration(); //I2C总线初始化
	OLED0561_Init(); //OLED初始化
	
	while(1){

		if(RTC_Get()==0){ //读出时间值，同时判断返回值是不是0，非0时读取的值是错误的�
			OLED_DISPLAY_8x16(2,4*8,ryear/10+0x30);//显示年
			OLED_DISPLAY_8x16(2,5*8,ryear%10+0x30);//显示年
			OLED_DISPLAY_8x16(2,6*8,'-');//

			OLED_DISPLAY_8x16(2,7*8,rmon/10+0x30);//显示月
			OLED_DISPLAY_8x16(2,8*8,rmon%10+0x30);//显示月
			OLED_DISPLAY_8x16(2,9*8,'-');//

			OLED_DISPLAY_8x16(2,10*8,rday/10+0x30);//显示日
			OLED_DISPLAY_8x16(2,11*8,rday%10+0x30);//显示日
			
			OLED_DISPLAY_8x16(4,4*8,rhour/10+0x30);//显示时
			OLED_DISPLAY_8x16(4,5*8,rhour%10+0x30);//显示时
			OLED_DISPLAY_8x16(4,6*8,':');//

			OLED_DISPLAY_8x16(4,7*8,rmin/10+0x30);//显示分
			OLED_DISPLAY_8x16(4,8*8,rmin%10+0x30);//显示分
			OLED_DISPLAY_8x16(4,9*8,':');//

			OLED_DISPLAY_8x16(4,10*8,rsec/10+0x30);//显示秒
			OLED_DISPLAY_8x16(4,11*8,rsec%10+0x30);//显示秒

		}
	}
}

/*********************************************************************************************
 * emboss2017
 * https://github.com/emboss2017/
*********************************************************************************************/
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

GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED控制

*/



