#include <MsTimer2.h>     //定时器库的头文件
 
 int tick = 0; //计数值
int state=0;  //中断服务程序
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
  Serial.begin(9600); //初始化串口
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
  
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时 
  attachInterrupt(digitalPinToInterrupt(2),myfunc, CHANGE);

}
 
void loop()
{
  

}


