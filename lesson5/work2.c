#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define S1 8
#define S2 9
#define S3 10
#define S4 11

#define LT 6
#define BT 7
int in,in1,in2,in3,in4;
void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,LOW);
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  digitalWrite(S4,LOW);
}

void loop()
{
  if(Serial.available()>0)
  {
    digitalWrite(S1,LOW);
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    digitalWrite(S4,LOW);
    in1=Serial.read();
    in1=in1-'0';
    delay(10);
    in2=Serial.read();
    in2=in2-'0';
    delay(10);
    in3=Serial.read();
    in3=in3-'0';
    delay(10);
    in4=Serial.read();
    in4=in4-'0';
    delay(10);
    digitalWrite(IN1,in1&0x1);
    digitalWrite(IN2,in1>>1&0x1);
    digitalWrite(IN3,in1>>2&0x1);
    digitalWrite(IN4,in1>>3&0x1);
    digitalWrite(S1,HIGH);
    digitalWrite(IN1,in2&0x1);
    digitalWrite(IN2,in2>>1&0x1);
    digitalWrite(IN3,in2>>2&0x1);
    digitalWrite(IN4,in2>>3&0x1);
    digitalWrite(S2,HIGH);
    digitalWrite(IN1,in3&0x1);
    digitalWrite(IN2,in3>>1&0x1);
    digitalWrite(IN3,in3>>2&0x1);
    digitalWrite(IN4,in3>>3&0x1);
    digitalWrite(S3,HIGH);
    digitalWrite(IN1,in4&0x1);
    digitalWrite(IN2,in4>>1&0x1);
    digitalWrite(IN3,in4>>2&0x1);
    digitalWrite(IN4,in4>>3&0x1);
    digitalWrite(S4,HIGH);
    delay(10);
  }  
}