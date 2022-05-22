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

#include "zf_gpio.h"

GPIO_TypeDef *gpio_group[4] = {GPIOA, GPIOB, GPIOC, GPIOD};

//-------------------------------------------------------------------------------------------------------------------
// @brief		GPIO��ʼ��
// @param		pin			ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @param		mode		���ŵ�ģʽ
// @param		dat			���ų�ʼ��ʱ���õĵ�ƽ״̬�����ʱ��Ч 0���͵�ƽ 1���ߵ�ƽ
// @return		void
// Sample usage:			gpio_init(D5, GPO, 1);//D5��ʼ��ΪGPIO���ܡ����ģʽ������ߵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_init(PIN_enum pin, GPIOMODE_enum mode, GPIOLEVEL_enum dat)
{
	uint8 io_group = ((pin&0xf0)>>4);															// ��ȡIO����
	uint8 io_pin = (pin&0x0f);																	// ��ȡIO�����±�

	RCC->AHBENR |= RCC_AHBENR_GPIOA << io_group;												// ʹ�� GPIOx ʱ��

	if(io_pin < 0x08)																			// ��8λ����
	{
		gpio_group[io_group]->CRL &= ~(0x0000000f << (io_pin*4));								// �������
		gpio_group[io_group]->CRL |= ((uint32)mode << (io_pin*4));								// д������
	}
	else																						// ��8λ����
	{
		gpio_group[io_group]->CRH &= ~(0x0000000f << ((io_pin-8)*4));							// �������
		gpio_group[io_group]->CRH |= ((uint32)mode << ((io_pin-8)*4));							// д������
	}

	if(dat)
		GPIO_PIN_SET(pin);																		// ��ʼ����ƽ���ø�
	else
		GPIO_PIN_RESET(pin);																	// ��ʼ����ƽ���õ�
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		GPIO��ʼ��
// @param		pin			ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @param		mode				���ŵ�ģʽ
// @param		dat			���ų�ʼ��ʱ���õĵ�ƽ״̬�����ʱ��Ч 0���͵�ƽ 1���ߵ�ƽ
// @return		void
// Sample usage:			gpio_init(D5, GPO, 1);//D5��ʼ��ΪGPIO���ܡ����ģʽ������ߵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
void afio_init(PIN_enum pin, GPIOMODE_enum mode, GPIOAF_enum af)
{
	uint8 io_group = ((pin&0xf0)>>4);															// ��ȡIO����
	uint8 io_pin = (pin&0x0f);																	// ��ȡIO�����±�

	RCC->AHBENR |= RCC_AHBENR_GPIOA << io_group;												// ʹ�� GPIOx ʱ��

	if(io_pin < 0x08)																			// ��8λ����
	{
		gpio_group[io_group]->CRL &= ~(0x0000000f << (io_pin*4));								// �������
		gpio_group[io_group]->CRL |= ((uint32)mode << (io_pin*4));								// д������
		gpio_group[io_group]->AFRL &= ~(0x0000000f << (io_pin*4));								// ��ո���
		gpio_group[io_group]->AFRL |= ((uint32)af << (io_pin*4));								// д�븴��
	}
	else																						// ��8λ����
	{
		gpio_group[io_group]->CRH &= ~(0x0000000f << ((io_pin-8)*4));							// �������
		gpio_group[io_group]->CRH |= ((uint32)mode << ((io_pin-8)*4));							// д������
		gpio_group[io_group]->AFRH &= ~(0x0000000f << ((io_pin-8)*4));							// ��ո���
		gpio_group[io_group]->AFRH |= ((uint32)af << ((io_pin-8)*4));							// д�븴��
	}
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		GPIO�������
// @param		pin			ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @param		dat			0���͵�ƽ 1���ߵ�ƽ
// @return		void
// Sample usage:			gpio_set(D5,1);//D5 ����ߵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_set(PIN_enum pin, uint8 dat)
{
	if(dat)
		gpio_group[(pin&0xf0)>>4]->BSRR |= (((uint16_t)0x0001) << (pin&0x0f));					// ����ߵ�ƽ
	else
		gpio_group[(pin&0xf0)>>4]->BRR |= (((uint16_t)0x0001) << (pin&0x0f));					// ����͵�ƽ
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		GPIO�������
// @param		pin			ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @return		uint8		0���͵�ƽ 1���ߵ�ƽ
// Sample usage:			uint8 status = gpio_get(D5);//��ȡD5���ŵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
uint8 gpio_get(PIN_enum pin)
{
	if(gpio_group[(pin&0xf0)>>4]->IDR & (((uint16_t)0x0001) << (pin&0x0f)))						// ��ȡ����ֵ
		return 1;
	return 0;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief		GPIO��������
// @param		pin			ѡ������� (��ѡ��Χ�� common.h ��PIN_enumö��ֵȷ��)
// @param		dir			���ŵķ���   �����GPO   ���룺GPI
// @return		void
// Sample usage:			gpio_dir(D5,GPO);//����D5Ϊ���ģʽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_dir(PIN_enum pin, GPIOMODE_enum dir)
{
	uint8 io_group = ((pin&0xf0)>>4);															// ��ȡIO����
	uint8 io_pin = (pin&0x0f);																	// ��ȡIO�����±�
	if(io_pin < 0x08)																			// ��8λ����
	{
		gpio_group[io_group]->CRL &= ~(0x0000000f << (io_pin*4));								// �������
		gpio_group[io_group]->CRL |= ((uint32)dir << (io_pin*4));								// д������
	}
	else																						// ��8λ����
	{
		gpio_group[io_group]->CRH &= ~(0x0000000f << ((io_pin-8)*4));							// �������
		gpio_group[io_group]->CRH |= ((uint32)dir << ((io_pin-8)*4));							// д������
	}
}
