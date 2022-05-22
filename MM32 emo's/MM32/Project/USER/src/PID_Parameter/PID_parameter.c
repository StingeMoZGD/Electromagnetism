#include "PID_parameter.h"

void direction_PID_init(void)
{
	/*if(d<2230&&(c>1420||e>1420))
	{
		pre_motor=-250;
		pid_param_t direction_pid = PID_CREATE(0.98, 0, 0, 1, 15, 5, 15); //PID
		OUTPUT=pid_solve(&direction_pid,a-g+b-f)/(a+g+b+f);
		//OUTPUT=-1;
	}
	else
	{
		pid_param_t direction_pid = PID_CREATE(1.08, 0, 0, 1, 15, 5, 15); //PID
	  OUTPUT=pid_solve(&direction_pid,a-g)/(a+g);
	}*/
	pid_param_t direction_pid = PID_CREATE(1, 0, 0, 1, 15, 5, 15); //PID
	OUTPUT=pid_solve(&direction_pid,((a-g)/(a+g+d)));
	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	
	duty=4130-OUTPUT*770;
	LossLine_init();
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}

void Curve_PID_init()
{
	pid_param_t direction_pid = PID_CREATE(1, 0, 0, 1, 15, 5, 15); //PID
	OUTPUT=pid_solve(&direction_pid,((a-g)/(a+g)+(b-f)/5150));
	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	
	duty=4130-OUTPUT*770;

	LossLine_init();
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}

void CircleRun_PID_init(void)
{
	pid_param_t circle_pid = PID_CREATE(0.96, 0, 0, 1, 15, 5, 15); //PID
	OUTPUT=pid_solve(&circle_pid,((a-g)/(a+g)));
	
	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	
	duty=4130-OUTPUT*770;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}


/*void Yucircle_PID_init(void)
{
	pid_param_t Yucircle_pid = PID_CREATE(0.35, 0, 0.1, 1, 15, 5, 15); //PID
	duty=4130+pid_solve(&Yucircle_pid,a-g)/(a+g)*770;

	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}
void Yu1circle_PID_init(void)
{
	pid_param_t Yucircle_pid = PID_CREATE(0.7, 0, 0.2, 1, 15, 5, 15); //PID
	duty=4130+pid_solve(&Yucircle_pid,a-1000-g)/(d)*770;

	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}

void Yu2circle_PID_init(void)
{
	pid_param_t Yucircle_pid = PID_CREATE(0.7, 0, 0.2, 1, 15, 5, 15); //PID
	duty=4130+pid_solve(&Yucircle_pid,a-g+1000)/(d)*770;

	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}*/

void circle_PID_init(void)
{
	pid_param_t circle_pid = PID_CREATE(1.93, 0, 1.2, 1, 15, 5, 15); //PID
	OUTPUT=pid_solve(&circle_pid,c-e)/(0.48*d);
	
	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	
	duty=4130-OUTPUT*770;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}


void Out1circle_PID_init(void)
{
	pid_param_t Outcircle_pid = PID_CREATE(1.43, 0, 0.4, 1, 15, 5, 15); //PID
	
	OUTPUT=pid_solve(&Outcircle_pid,a-g)/(a+g);
	if(OUTPUT>=1)
		OUTPUT=1;
	else if(OUTPUT<=-1)
		OUTPUT=-1;
	else
		OUTPUT=OUTPUT;
	duty=4130-OUTPUT*770;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}

void Out2circle_PID_init(void)
{
	pid_param_t Outcircle_pid = PID_CREATE(0.29, 0, 0.35, 1, 15, 5, 15); //PID
	duty=4130-pid_solve(&Outcircle_pid,a-g)/(a+g+d)*770;
	pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
}


