#include <MsTimer2.h>     //��ʱ�����ͷ�ļ�
 
 int tick = 0; //����ֵ
int state=0;  //�жϷ������
void onTimer()
{
  
  digitalWrite(9,LOW);
  digitalWrite(3,tick&0x1);
  digitalWrite(4,tick>>1&0x1);
  digitalWrite(5,tick>>2&0x1);
  digitalWrite(6,tick>>3&0x1);
  tick++;
  if(tick==10)
    tick=0;

  Serial.print("timer ");
  Serial.println(tick);
  
}
void myfunc()
{
  tick=0;
}
 
void setup()
{
  Serial.begin(9600); //��ʼ������
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  
  MsTimer2::set(1000, onTimer); //�����жϣ�ÿ1000ms����һ���жϷ������ onTimer()
  MsTimer2::start(); //��ʼ��ʱ 
  attachInterrupt(digitalPinToInterrupt(2),myfunc, CHANGE);

}
 
void loop()
{
  

}


