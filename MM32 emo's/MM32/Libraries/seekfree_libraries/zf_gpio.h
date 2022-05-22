/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2019,��ɿƼ�
* All rights reserved.
* ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897
*
* �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
* ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
*
* @file				gpio
* @company			�ɶ���ɿƼ����޹�˾
* @author			��ɿƼ�(QQ3184284598)
* @version			�鿴doc��version�ļ� �汾˵��
* @Software			IAR 8.3 or MDK 5.28
* @Target core		MM32SPIN2XPs
* @Taobao			https://seekfree.taobao.com/
* @date				2020-11-23
********************************************************************************************************************/

#ifndef _zf_gpio_h
#define _zf_gpio_h

#include "common.h"
#include "hal_gpio.h"

typedef enum																					// ö�ٶ˿ڷ���
{
	GPI_AIN = 0x00,																				// ����ܽ�ģ������
	GPI_FL = 0x04,																				// ����ܽŸ�������
	GPI_PD = 0x08,																				// ����ܽ���������
	GPI_PU = 0x08,																				// ����ܽ���������
	GPO_PP = 0x03,																				// ����ܽ��������
	GPO_OD = 0x07,																				// ����ܽſ�©���
	GPO_AFPP = 0x0B,																			// ����ܽŸ����������
	GPO_AFOD = 0x0F,																			// ����ܽŸ��ÿ�©���
}GPIOMODE_enum;

typedef enum																					// ö�ٶ˿ڵ�ƽ
{
	GPIO_AF0 = 0x00,																			// ���Ÿ��ù���ѡ�� 0
	GPIO_AF1 = 0x01,																			// ���Ÿ��ù���ѡ�� 1
	GPIO_AF2 = 0x02,																			// ���Ÿ��ù���ѡ�� 2
	GPIO_AF3 = 0x03,																			// ���Ÿ��ù���ѡ�� 3
	GPIO_AF4 = 0x04,																			// ���Ÿ��ù���ѡ�� 4
	GPIO_AF5 = 0x05,																			// ���Ÿ��ù���ѡ�� 5
	GPIO_AF6 = 0x06,																			// ���Ÿ��ù���ѡ�� 6
	GPIO_AF7 = 0x07,																			// ���Ÿ��ù���ѡ�� 7
}GPIOAF_enum;

typedef enum																					// ö�ٶ˿ڵ�ƽ
{
	GPIO_LOW = 0,																				// ����ܽ����뷽��
	GPIO_HIGH = 1,																				// ����ܽ��������
}GPIOLEVEL_enum;

#define GPIO_PIN_RESET(x)	gpio_group[(x>>4)]->BRR  |= ((uint16_t)0x0001 << (x & 0x0F))		//GPIO��λ
#define GPIO_PIN_SET(x)		gpio_group[(x>>4)]->BSRR  |= ((uint16_t)0x0001 << (x & 0x0F))		//GPIO��λ

extern GPIO_TypeDef *gpio_group[4];

void		gpio_init		(PIN_enum pin, GPIOMODE_enum mode, GPIOLEVEL_enum dat);
void		afio_init		(PIN_enum pin, GPIOMODE_enum mode, GPIOAF_enum af);
void		gpio_set		(PIN_enum pin, uint8 dat);
uint8		gpio_get		(PIN_enum pin);
void		gpio_dir		(PIN_enum pin, GPIOMODE_enum dir);

#endif
