#include "curve.h"




void Curve_init()
{
	beep_on_init();
	Curve_PID_init();
	x=((a-g)/(a+g)+(b-f)/3000)*1000;
	z=x-y;
	y=x;
	if(CurveDir==0)
	{
		if(x<=-380||x>=380)
		{
		  CurveDir=1;
		}
		else
		{
			CurveDir=CurveDir;
		}
	}
	if(CurveDir==1)
	{
		if(x>=-380&&x<=380)
		{
			CurveFlag=0;
			StraightLineFlag=1;
			CurveDir=0;
			x=0;
		}
	}
  
}


