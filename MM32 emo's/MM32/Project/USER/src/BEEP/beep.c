#include "beep.h"
#include "headfile.h"


void beep_on_init(void)
{
	gpio_init(A15,GPO_PP,1);
}


void beep_off_init(void)
{
	gpio_init(A15,GPO_PP,0);
}


/*
#define Beep_Pin A15

void beep_on_init(void)
{
	gpio_init(Beep_Pin,GPO_PP,1);
}
void beep_off_init(void)
{
	gpio_init(Beep_Pin,GPO_PP,0);
}
*/