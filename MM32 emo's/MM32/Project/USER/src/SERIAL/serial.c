#include "serial.h"


#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //取出int型变量的低字节
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))   // 取存储在此变量下一内存字节的内容，高字节
#define BYTE2(dwTemp)       (*((char *)(&dwTemp) + 2))
#define BYTE3(dwTemp)       (*((char *)(&dwTemp) + 3))
 uint8  sumcheck = 0 ;
 uint8  addcheck = 0 ;

 uint8 BUFF[30];

void sent_date(uint16 a,uint16 b,uint16 c)
 {
     int i;
     uint8 sumcheck = 0;
     uint8 addcheck = 0;
     uint8 _cnt=0;
     BUFF[_cnt++]=0xAA;//帧头
     BUFF[_cnt++]=0xFF;//目标地址
     BUFF[_cnt++]=0XF1;//功能码
     BUFF[_cnt++]=0x04;//数据长度
     BUFF[_cnt++]=BYTE0(a);//数据内容,小段模式，低位在前
     BUFF[_cnt++]=BYTE1(a);//需要将字节进行拆分，调用上面的宏定义即可。
     BUFF[_cnt++]=BYTE0(b);
     BUFF[_cnt++]=BYTE1(b);
     BUFF[_cnt++]=BYTE0(c);
     BUFF[_cnt++]=BYTE1(c);
//     BUFF[_cnt++]=BYTE0(B);
//     BUFF[_cnt++]=BYTE1(B);
//     BUFF[_cnt++]=BYTE0(C);
//     BUFF[_cnt++]=BYTE1(C);

     //SC和AC的校验直接抄最上面上面简介的即可
     for(i=0;i<BUFF[3]+4;i++)
     {
         sumcheck+=BUFF[i];
         addcheck+=sumcheck;
     }
     BUFF[_cnt++]=sumcheck;
     BUFF[_cnt++]=addcheck;

      seekfree_wireless_send_buff(&BUFF[0],_cnt);//串口逐个发送数据
 }


