#include "LCD.h"
extern int LCDcount;
extern double a,b,c,d,e,f,g,x;
extern int coder,circle_count,ready_circle,per_circle,Yucircle,dircircle,StraightLineFlag,ThreeforksFlag,CircleFlag,CurveDir;
extern uint16 motor;

void LCD_TFT_Init(void)
{
	LCDcount++;
	if(LCDcount==1)
	{
		lcd_showint32(1,1,a,10);
		lcd_showint32(1,2,b,10);
		lcd_showint32(1,3,c,10);
		lcd_showint32(1,4,d,10);
		lcd_showint32(1,5,e,10);
		lcd_showint32(1,6,f,10);
		lcd_showint32(1,7,g,10);
	  lcd_showint32(0,0,coder,10);
		lcd_showint32(50,1,circle_count,10);
		lcd_showint32(50,2,ready_circle,10);
		lcd_showint32(50,3,per_circle,10);
		lcd_showint32(50,4,motor,10);
		lcd_showint32(50,5,Yucircle,10);
		lcd_showint32(50,6,dircircle,10);
		lcd_showint32(50,7,pre_motor,10);
		lcd_showint32(100,5,CircleFlag,10);
		lcd_showint32(100,6,ThreeforksFlag,10);
		lcd_showint32(100,7,StraightLineFlag,10);
		lcd_showint32(100,1,x,10);
		lcd_showint32(100,2,y,10);
		lcd_showint32(100,3,z,10);
		lcd_showint32(100,4,CurveDir,10);
		LCDcount=0;
	}
}

