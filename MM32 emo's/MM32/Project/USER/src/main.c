/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,��ɿƼ�
* All rights reserved.
* ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
*
* �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
* ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
*
* @file				main
* @company			�ɶ���ɿƼ����޹�˾
* @author			��ɿƼ�(QQ3184284598)
* @version			�鿴doc��version�ļ� �汾˵��
* @Software			IAR 8.3 or MDK 5.24
* @Target core		MM32SPIN2XPs
* @Taobao			https://seekfree.taobao.com/
* @date				2020-11-23
********************************************************************************************************************/

#include "headfile.h"
// *************************** explain group ***************************
// ����˵��
// 
// ������Ҫ׼����ɿƼ�MM32SPIIN27PS���İ�һ��
// 
// ����������Ҫ׼����ɿƼ�CMSIS-DAP��Jlink����������һ��
// 
// �������Ǹ��չ��� ������ͬѧ����ֲʹ��
// 
// ���µĹ��̻��߹����ƶ���λ�����ִ�����²���
// ��һ�� �ر��������д򿪵��ļ�
// �ڶ��� project  clean  �ȴ��·�����������
// 
// *************************** explain group ***************************

// **************************** define group ****************************
#define L7 ADC1_CH03_A03
#define L6 ADC1_CH00_A00
#define L5 ADC1_CH02_A02
#define L4 ADC1_CH05_A05
#define L3 ADC1_CH07_A07
#define L2 ADC1_CH11_B10
#define L1 ADC1_CH06_A06
// **************************** define group ****************************
double a,b,c,d,e,f,g;
int LCDcount=0;
int coder;   //������
uint16 duty,motor;
int ready_circle=0;       
int circle_count=0;
int per_circle=0;
int out_circle=0;
int Yucircle=0;
int dircircle=0;
int ready_dircircle=0;
int threeforks=0;
int threeforks_count=0;
int pre_motor=0;
double OUTPUT=0;
int CircleFlag=0;    //Ԫ�ر�־λ
int CurveFlag=0;
int ThreeforksFlag=0;
int StraightLineFlag=1;
double x=0;     //������
double y=0;
double z=0;
int CurveDir=0;  //�������
int16 datas[16];  //���ߴ���
// **************************** value group ****************************
void All_Config(void)
{
	tim_encoder_init(TIM_1, TIM_1_ENC1_A08, TIM_1_ENC2_A01);                                     //��������ʼ��
	
  pwm_init(TIM_2, TIM_2_CH1_A11, 15000, 0);										// ???TIM2 ??10KHz ?????? 0/PWM_DUTY_MAX*100%
  pwm_init(TIM_2, TIM_2_CH2_A12, 15000, 0);	                  //                   
	
	pwm_init(TIM_3, TIM_3_CH2_C07, 50, 0);                      //�����ʼ��
		
  lcd_init();                                                 //LCD��ʼ��
	lcd_clear(WHITE);                                           
  adc_init(ADC_1,L1,ADC_12BIT);                               //adc��ʼ��
	adc_init(ADC_1,L2,ADC_12BIT);
	adc_init(ADC_1,L3,ADC_12BIT);
	adc_init(ADC_1,L4,ADC_12BIT);
	adc_init(ADC_1,L5,ADC_12BIT);
	adc_init(ADC_1,L6,ADC_12BIT);
	adc_init(ADC_1,L7,ADC_12BIT);
	
	
	
	
	seekfree_wireless_init();
	uart_init(1,115200,UART1_TX_A10,UART1_RX_A09);
	
	
	
	
	systick_delay_ms(500);                                     //����
	
	
	duty=4130;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);              //�������
	
  systick_delay_ms(500);                                    //����
  
	tim_interrupt_init (TIM_14, 300, 2);                      //�жϿ�ʼ
	
	tim_interrupt_init (TIM_16, 50, 1);
	
  tim_interrupt_init (TIM_17, 200, 0);
      	//���

}
 

 
// **************************** code group ****************************
int main(void)
{
	
	All_Config();      //��ʼ������
	pre_motor=-320;
	//motor=4000;
	//pwm_duty_updata(TIM_2, TIM_2_CH1_A11, motor);
	//pwm_duty_updata(TIM_2, TIM_2_CH2_A12, 0);
			uint16 error=((a-g)/(a+g+d)*100);
	while(1)
	{
	  //ADC_init();
		
		//motor_Init();
		//direction_PID_init();
		
		//threeforks_init();
		
		sent_date(duty,motor,error);
		LCD_TFT_Init();
	}
	
	

		
   

	
	
	
	  
}



// **************************** code group ****************************