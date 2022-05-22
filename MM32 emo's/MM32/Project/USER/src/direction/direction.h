#ifndef DIRECTION_H
#define DIRECTION_H
#include "headfile.h"


#define LossFlag a<480&&b<480&&c<480&&d<480&&e<480&&f<480&&g<480

extern int ready_circle;
extern int circle_count;
extern int per_circle;
extern int out_circle;
extern int Yucircle;
extern int dircircle;
extern int ready_dircircle;
extern int threeforks;
extern int threeforks_count;
extern double OUTPUT;
extern double a,b,c,d,e,f,g,x,y,z;
extern uint16 duty;
extern int pre_motor;
extern int CurveDir;

void ADC_init(void);

void direction_init(void);

void LossLine_init(void);









#endif
