/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,��ɿƼ�
* All rights reserved.
* ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
*
* �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
* ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
*
* @file				tim
* @company			�ɶ���ɿƼ����޹�˾
* @author			��ɿƼ�(QQ3184284598)
* @version			�鿴doc��version�ļ� �汾˵��
* @Software			IAR 8.3 or MDK 5.24
* @Target core		MM32SPIN2XPs
* @Taobao			https://seekfree.taobao.com/
* @date				2020-11-23
********************************************************************************************************************/

#include "zf_tim.h"
#include "zf_gpio.h"

TIM_TypeDef *tim_index[7] = {TIM1, TIM8, TIM2, TIM3, TIM14, TIM16, TIM17};

//-------------------------------------------------------------------------------------------------------------------
// @brief		encoder ���ų�ʼ�� �ڲ�����
// @param		pin				ѡ�� capture ����
// @return		void			NULL
// Sample usage:				tim_capture_pin_init(pin);
//-------------------------------------------------------------------------------------------------------------------
static void tim_encoder_pin_init (TIM_ENC_PIN_enum pin)
{
	afio_init((PIN_enum)(pin &0xff), GPI_FL, (GPIOAF_enum)((pin &0xf00)>>8));					// ��ȡ��ӦIO���� AF���ܱ���
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		encoder ��ʼ��
// @param		tim				ѡ�� encoder ʹ�õ� TIM
// @param		PULSEA_pin		ѡ�� encoder ����
// @param		PULSEB_pin		ѡ�� encoder ����
// @return		void
// Sample usage:				tim_encoder_init(TIM_1, PULSEA_pin, TIM_ENC_PIN_enum);
//-------------------------------------------------------------------------------------------------------------------
void tim_encoder_init (TIM_enum tim, TIM_ENC_PIN_enum PULSEA_pin, TIM_ENC_PIN_enum PULSEB_pin)
{
	if((tim&0x0f) > 0x03) return;																// ������ʱ����֧�ֱ�����ģʽ
	tim_encoder_pin_init(PULSEA_pin);
	tim_encoder_pin_init(PULSEB_pin);
	if(tim & 0xf000)
		RCC->APB2ENR |= ((uint32_t)0x00000001 << ((tim&0x0ff0) >> 4));							// ʹ��ʱ��
	else
		RCC->APB1ENR |= ((uint32_t)0x00000001 << ((tim&0x0ff0) >> 4));							// ʹ��ʱ��

	tim_index[(tim&0x0f)]->ARR = TIM_ENCODER_COUNTER_BASE;										// װ���Զ���װ��ֵ
	tim_index[(tim&0x0f)]->PSC = 0;																// װ��Ԥ��Ƶ

	tim_index[(tim&0x0f)]->CCMR1 |= TIM_CCMR1_CC1S_DIRECTTI;									// ���벶�� IC1 ӳ�䵽 TI1
	tim_index[(tim&0x0f)]->CCMR1 |= TIM_CCMR1_CC2S_DIRECTTI;									// ���벶�� IC2 ӳ�䵽 TI2
	tim_index[(tim&0x0f)]->CCER |= TIM_CCER_CC1EN | TIM_CCER_CC2EN;								// ʹ��ͨ�� 1

	tim_index[(tim&0x0f)]->SMCR |= TIM_SMCR_SMS_ENCODER3;										// ��ģʽ ������ģʽ 3 ѡ��

	tim_index[(tim&0x0f)]->CR1 |= TIM_CR1_UDIS;													// ��ֹUEV�¼��Ĳ���
	tim_index[(tim&0x0f)]->CR1 |= TIM_CR1_CEN;													// ʹ�ܶ�ʱ��
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		encoder ��λ������
// @param		tim				ѡ�� encoder ʹ�õ� TIM
// Sample usage:				tim_encoder_rst(tim);
//-------------------------------------------------------------------------------------------------------------------
void tim_encoder_rst (TIM_enum tim)
{
	tim_index[(tim&0x0f)]->EGR |= 0x01;															// ��������ʱ����װ�ؼ�����
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		��ȡ encoder ������ ����λ
// @param		tim				ѡ�� encoder ʹ�õ� TIM
// Sample usage:				temp = tim_encoder_rst(tim);
//-------------------------------------------------------------------------------------------------------------------
int16 tim_encoder_get_count (TIM_enum tim)
{
	int16 temp = tim_index[(tim&0x0f)]->CNT;
	tim_index[(tim&0x0f)]->EGR |= 0x01;															// ��������ʱ����װ�ؼ�����
	return temp;
}




