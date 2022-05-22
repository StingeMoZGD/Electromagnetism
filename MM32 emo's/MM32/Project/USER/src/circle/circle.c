#include "circle.h"

void circle_init()
{
	if(circle_count==0)
	{
		if(d>3230)
		{
			if(ready_dircircle==0)
			{
				//pre_motor=-270;
				if(a-g>0)
				{
					dircircle=1;    //左
					ready_dircircle=1;
				}
				else if(a-g<0)
				{
					dircircle=2;    //右
					ready_dircircle=1;
				}
				else
				{
					dircircle=dircircle;
					
				}
			}
			else
				ready_circle=1;
		}
		else
			ready_circle=ready_circle;
		if(ready_circle==1)    
		{
			if(dircircle==1)         //左
			{
				if((c-e>=0)&&d>2100)
				{
					circle_PID_init();
					per_circle=1;
					//i=1;
					beep_on_init();
				}
				else if(c-e<0&&d>2100)
				{
					direction_PID_init();
				}
				else
				{
					Curve_PID_init();
					circle_count=1;
					beep_off_init();
					//pre_motor=-280;
				}
			}
			else if(dircircle==2)         //右
			{
				if((c-e<=0)&&d>2100)
				{
					circle_PID_init();
					per_circle=1;
					beep_on_init();
					//i=1;
				}
				else if(c-e>0&&d>2100)
				{
					direction_PID_init();
				}
				else
				{
					Curve_PID_init();
					circle_count=1;
					beep_off_init();
					//pre_motor=-255;
				}
			}
			else
				direction_PID_init();		
	  }
		else
			direction_PID_init();
	}
	else
	{
		if(d>2350)       //出环检测
		{
			out_circle=1;
		}
		else
		{
			out_circle=out_circle;
		}
		if(out_circle !=0)
		{
			if(d<=2140&&b<=180&&f<=180)
			{
				if(per_circle==1)
				{
						/*if(i==1)
							pre_motor=-250;
						else
							pre_motor=-220;*/
						circle_count=0;
						ready_circle=0;
					  per_circle=0;
						out_circle=0;
						Yucircle=0;
						dircircle=0;
						ready_dircircle=0;
						CircleFlag=0;
					  StraightLineFlag=1;
						//i=0;
				} 
					/*else if(d>1740&&d<2700)
					{
						circle_count=1;
					  Out2circle_PID_init();
					}*/
				else      
				{
						circle_count=1;
					  Curve_PID_init();
				}
			}
			else      //出环
			{
					circle_count=1;
					CircleRun_PID_init();
			}
		}
		else                 //环岛转弯
			CircleRun_PID_init();
	}
}

