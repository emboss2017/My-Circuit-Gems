
/*********************************************************************************************
��������	ʱ�ӳ���
��д�ˣ�	emboss2017	
��дʱ�䣺	2023-11-07
Ӳ��֧�֣�	STM32F103C8 �ⲿ����8MHz RCC����������Ƶ72MHz��  

�޸���־������
1-	2023-11-12 �޸�������ʾ��ʽ
							
˵����
 # ��ģ�������STM32F103�ڲ���RCCʱ�����ã������������õδ�ʱ������ʱ������
*********************************************************************************************/

#include "stm32f10x.h" //STM32ͷ�ļ�
#include "sys.h"
#include "delay.h"
#include "rtc.h"
#include "oled0561.h"
#include "stdio.h"

int main (void){//������
	delay_ms(1000); //�ϵ�ʱ�ȴ�������������
	RCC_Configuration(); //ϵͳʱ�ӳ�ʼ��
	RTC_Config(); //ʵʱʱ�ӳ�ʼ��
	
	I2C_Configuration(); //I2C���߳�ʼ��
	OLED0561_Init(); //OLED��ʼ��
	
	while(1){

		if(RTC_Get()==0){ //����ʱ��ֵ��ͬʱ�жϷ���ֵ�ǲ���0����0ʱ��ȡ��ֵ�Ǵ���ġ
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

���������塿
u32     a; //����32λ�޷��ű���a
u16     a; //����16λ�޷��ű���a
u8     a; //����8λ�޷��ű���a
vu32     a; //�����ױ��32λ�޷��ű���a
vu16     a; //�����ױ�� 16λ�޷��ű���a
vu8     a; //�����ױ�� 8λ�޷��ű���a
uc32     a; //����ֻ����32λ�޷��ű���a
uc16     a; //����ֻ�� ��16λ�޷��ű���a
uc8     a; //����ֻ�� ��8λ�޷��ű���a

#define ONE  1   //�궨��

delay_us(1); //��ʱ1΢��
delay_ms(1); //��ʱ1����
delay_s(1); //��ʱ1��

GPIO_WriteBit(LEDPORT,LED1,(BitAction)(1)); //LED����

*/



