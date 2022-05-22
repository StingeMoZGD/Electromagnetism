#include "motor.h"
#include "headfile.h"
#include "PID.h"

extern uint16 motor;
extern int coder;
extern double a,b,c,d,e,f,g;

extern int pre_motor;
int last_motor=0;

void encode_Init(void)
{
	coder=tim_encoder_get_count(TIM_1);
}



void motor_Init(void)
{
	
	
	//if(a<120&&b<120&&c<120&&d<120&&e<120&&f<120&&g<120)
		//pre_motor=0;
	//else
		//pre_motor=pre_motor;
	
	
	pid_param_t motor_pid = PID_CREATE(15, 6, 0, 1, 15, 15, 15);
	motor=last_motor+increment_pid_solve(&motor_pid, coder-pre_motor);
	if(motor>=9000)
		motor=9000;
	else
		motor=motor;
	last_motor=motor;
	
	pwm_duty_updata(TIM_2, TIM_2_CH1_A11, motor);							// ?? 1 ??
  pwm_duty_updata(TIM_2, TIM_2_CH2_A12, 0);
	
}
