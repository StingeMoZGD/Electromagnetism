#include "threeforks.h"

void threeforks_init()
{
	if(threeforks_count==0)
	{
		if(d<1800&&a>270&&g>270&&c>220&&e>220&&b>30&&f>30&&b<500&&f<500&&c<1000&&e<1000&&a<1050&&g<1050)
	  {
		  threeforks=1;
			beep_on_init();
	  }
	  else
	  {
		  threeforks=threeforks;
	  }
	  if(threeforks==1)
	  {
		  if(b<47&&f<47)
		  {
				threeforks_count=1;
				beep_off_init();
			  direction_PID_init();
				//pre_motor=-227;
		  }
		  else
			{
				duty=4130-770;
				pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
			}
	  }
	}
	else
	{
		threeforks=0;
		threeforks_count=0;
		ThreeforksFlag=0;
		direction_PID_init();
	}
}


/*

#define threeforkjudge d<2000&&a>780&&g>780&&c>750&&e>750&&b<100&&f<100

void threeforks_init(void)
{
	if(threeforks_count==0)
	{
		if(threeforkjudge)
	  {
		  threeforks=1;
			beep_on_init();
	  }
	  else
	  {
		  threeforks=threeforks;
	  }
	  if(threeforks==1)
	  {
		  if(d<450)
		  {
				threeforks_count=1;
				beep_off_init();
			  direction_PID_init();
		  }
		  else
			{
				duty=4130-500;
				pwm_duty_updata(TIM_3, TIM_3_CH2_C07, duty);
			}
	  }
	}
	else
	{
		threeforks=0;
		threeforks_count=0;
		direction_PID_init();
	}
}


*/




