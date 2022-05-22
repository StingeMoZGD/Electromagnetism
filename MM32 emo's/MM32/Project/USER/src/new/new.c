#include "headfile.h"
#include "new.h"



void discriminate_init()
{
	if(CircleFlag==1)
		pre_motor=-250;
	else if(ThreeforksFlag==1)
		pre_motor=-250;
	else if(CurveFlag==1)
		pre_motor =-250;
	else
	{
		beep_off_init();
		pre_motor=-320;
		if(CircleJudge)
	  {
		  CircleFlag=1;
		  ThreeforksFlag=0;
		  StraightLineFlag=0;
			CurveFlag=0;
	  }
	  //else if(CurveJudge)
		//CurveFlag=1;
	  else if(ThreeforksJudge)
	  {
		  CircleFlag=0;
		  ThreeforksFlag=1;
		  StraightLineFlag=0;
			CurveFlag=0;
	  }
		else if(CurveJudge)
		{
			CircleFlag=0;
		  ThreeforksFlag=0;
		  StraightLineFlag=0;
			CurveFlag=1;
		}
	  else
	  {
		  CircleFlag=0;
		  ThreeforksFlag=0;
		  StraightLineFlag=1;
			CurveFlag=0;
	  }
	}
		
}	






