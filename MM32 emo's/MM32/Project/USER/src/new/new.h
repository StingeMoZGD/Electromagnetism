#ifndef _NEW_H_
#define _NEW_H_

#include "headfile.h"

#define CircleJudge  d>3230
#define CurveJudge  ((1800<d&&d<2130)&&(((a>1000&&g<1000&&a<1500&&g>500)&&(c>1420&&e<900&&c<1700&&e>500)&&(b>100&&f<100&&b<400))||((g>1000&&a<1000&&g<1500&&a>500)&&(e>1420&&c<900&&e<1700&&c>500)&&(f>100&&b<100&&f<400))))
#define ThreeforksJudge  d<1800&&a>270&&g>270&&c>220&&e>220&&b>30&&f>30&&b<500&&f<500&&c<1000&&e<1000&&a<1050&&g<1050

extern int CircleFlag;
extern int CurveFlag;
extern int ThreeforksFlag;
extern int StraightLineFlag;

void discriminate_init();

#endif
