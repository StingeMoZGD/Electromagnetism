#include "serial.h"


#define BYTE0(dwTemp)       (*(char *)(&dwTemp))     //ȡ��int�ͱ����ĵ��ֽ�
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))   // ȡ�洢�ڴ˱�����һ�ڴ��ֽڵ����ݣ����ֽ�
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
     BUFF[_cnt++]=0xAA;//֡ͷ
     BUFF[_cnt++]=0xFF;//Ŀ���ַ
     BUFF[_cnt++]=0XF1;//������
     BUFF[_cnt++]=0x04;//���ݳ���
     BUFF[_cnt++]=BYTE0(a);//��������,С��ģʽ����λ��ǰ
     BUFF[_cnt++]=BYTE1(a);//��Ҫ���ֽڽ��в�֣���������ĺ궨�弴�ɡ�
     BUFF[_cnt++]=BYTE0(b);
     BUFF[_cnt++]=BYTE1(b);
     BUFF[_cnt++]=BYTE0(c);
     BUFF[_cnt++]=BYTE1(c);
//     BUFF[_cnt++]=BYTE0(B);
//     BUFF[_cnt++]=BYTE1(B);
//     BUFF[_cnt++]=BYTE0(C);
//     BUFF[_cnt++]=BYTE1(C);

     //SC��AC��У��ֱ�ӳ�������������ļ���
     for(i=0;i<BUFF[3]+4;i++)
     {
         sumcheck+=BUFF[i];
         addcheck+=sumcheck;
     }
     BUFF[_cnt++]=sumcheck;
     BUFF[_cnt++]=addcheck;

      seekfree_wireless_send_buff(&BUFF[0],_cnt);//���������������
 }


