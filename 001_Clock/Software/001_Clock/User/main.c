
/*********************************************************************************************
³ÌÐòÃû£º	Ê±ÖÓ³ÌÐò
±àÐ´ÈË£º	emboss2017	
±àÐ´Ê±¼ä£º	2023-11-07
Ó²¼þÖ§³Ö£º	STM32F103C8 Íâ²¿¾§Õñ8MHz RCCº¯ÊýÉèÖÃÖ÷Æµ72MHz¡¡  

ÐÞ¸ÄÈÕÖ¾£º¡¡¡¡
1-	2023-11-12 ÐÞ¸ÄÈÕÆÚÏÔÊ¾·½Ê½
							
ËµÃ÷£º
 # ±¾Ä£°å¼ÓÔØÁËSTM32F103ÄÚ²¿µÄRCCÊ±ÖÓÉèÖÃ£¬²¢¼ÓÈëÁËÀûÓÃµÎ´ð¶¨Ê±Æ÷µÄÑÓÊ±º¯Êý¡£
*********************************************************************************************/

#include "stm32f10x.h" //STM32Í·ÎÄ¼þ
#include "sys.h"
#include "delay.h"
#include "rtc.h"
#include "oled0561.h"
#include "stdio.h"

int main (void){//Ö÷³ÌÐò
	delay_ms(1000); //ÉÏµçÊ±µÈ´ýÆäËûÆ÷¼þ¾ÍÐ÷
	RCC_Configuration(); //ÏµÍ³Ê±ÖÓ³õÊ¼»¯
	RTC_Config(); //ÊµÊ±Ê±ÖÓ³õÊ¼»¯
	
	I2C_Configuration(); //I2C×ÜÏß³õÊ¼»¯
	OLED0561_Init(); //OLED³õÊ¼»¯
	
	while(1){

		if(RTC_Get()==0){ //¶Á³öÊ±¼äÖµ£¬Í¬Ê±ÅÐ¶Ï·µ»ØÖµÊÇ²»ÊÇ0£¬·Ç0Ê±¶ÁÈ¡µÄÖµÊÇ´íÎóµÄ¡
			OLED_DISPLAY_8x16_NUM(2, 3, ryear, 4);//
			OLED_DISPLAY_8x16(2, 7 * 8, '-');//
			OLED_DISPLAY_8x16_NUM(2, 8, rmon, 2);//
			OLED_DISPLAY_8x16(2, 10 * 8, '-');//
			OLED_DISPLAY_8x16_NUM(2, 11, rday, 2);//
			
			OLED_DISPLAY_8x16_NUM(4, 4, rhour, 2);//
			OLED_DISPLAY_8x16(4, 6 * 8, ':');//
			OLED_DISPLAY_8x16_NUM(4, 7, rmin, 2);//
			OLED_DISPLAY_8x16(4, 9 * 8, ':');//
			OLED_DISPLAY_8x16_NUM(4, 10, rsec, 2);//
			
		}else{
			OLED_DISPLAY_CLEAR();//
			OLED_DISPLAY_8x16(2, 7 * 8, '?');//
		}
		
/*

¡¾±äÁ¿¶¨Òå¡¿
u32     a; //¶¨Òå32Î»ÎÞ·ûºÅ±äÁ¿a
u16     a; //¶¨Òå16Î»ÎÞ·ûºÅ±äÁ¿a
u8     a; //¶¨Òå8Î»ÎÞ·ûºÅ±äÁ¿a
vu32     a; //¶¨ÒåÒ×±äµÄ32Î»ÎÞ·ûºÅ±äÁ¿a
vu16     a; //¶¨ÒåÒ×±äµÄ 16Î»ÎÞ·ûºÅ±äÁ¿a
vu8     a; //¶¨ÒåÒ×±äµÄ 8Î»ÎÞ·ûºÅ±äÁ¿a
uc32     a; //¶¨ÒåÖ»¶ÁµÄ32Î»ÎÞ·ûºÅ±äÁ¿a
uc16     a; //¶¨ÒåÖ»¶Á µÄ16Î»ÎÞ·ûºÅ±äÁ¿a
uc8     a; //¶¨ÒåÖ»¶Á µÄ8Î»ÎÞ·ûºÅ±äÁ¿a

#define ONE  1   //ºê¶¨Òå

delay_us(1); //ÑÓÊ±1Î¢Ãë
delay_ms(1); //ÑÓÊ±1ºÁÃë
delay_s(1); //ÑÓÊ±1Ãë

GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED¿ØÖÆ

*/



