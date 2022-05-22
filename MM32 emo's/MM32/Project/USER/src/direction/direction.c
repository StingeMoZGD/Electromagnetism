#include "direction.h"
#include "headfile.h"
#include "PID.h"

#define L7 ADC1_CH03_A03
#define L6 ADC1_CH00_A00
#define L5 ADC1_CH02_A02
#define L4 ADC1_CH05_A05
#define L3 ADC1_CH07_A07
#define L2 ADC1_CH11_B10
#define L1 ADC1_CH06_A06

int i=0;

void ADC_init(void)
{
	
	a=adc_mean_filter (ADC_1, L1, 3);
	b=adc_mean_filter (ADC_1, L2, 3);
	c=adc_mean_filter (ADC_1, L3, 3);
	d=adc_mean_filter (ADC_1, L4, 3);
	e=adc_mean_filter (ADC_1, L5, 3);
	f=adc_mean_filter (ADC_1, L6, 3);
	g=adc_mean_filter (ADC_1, L7, 3);
	//ÂË²¨
	
	
}

void direction_init()      //ÔªËØ
{
	if(CircleFlag==1)
		circle_init();
	else if(ThreeforksFlag==1)
		threeforks_init();
	else if(CurveFlag==1)
		Curve_init();
	else
		direction_PID_init();
		
}

void LossLine_init()    //¶ªÏß
{
	if(LossFlag)
	{
		if(a>g)
		{
			duty=4130-670;
		}
		else
		{
			duty=4130+670;
		}
	}
}
	


