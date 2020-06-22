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
int inall,in[100],i,j;
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
    for(i=0;i<30;i++)
      {
        in[i]=Serial.read();
        delay(10);
        in[i]=in[i]-'0';       
      }
    for(j=0;in[j+3]>=0&&in[j+3]<=9;j++)
    {
    
    digitalWrite(S1,LOW);
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    digitalWrite(S4,LOW);
    digitalWrite(IN1,in[j]&0x1);
    digitalWrite(IN2,in[j]>>1&0x1);
    digitalWrite(IN3,in[j]>>2&0x1);
    digitalWrite(IN4,in[j]>>3&0x1); 
    digitalWrite(S1,HIGH);
    digitalWrite(IN1,in[j+1]&0x1);
    digitalWrite(IN2,in[j+1]>>1&0x1);
    digitalWrite(IN3,in[j+1]>>2&0x1);
    digitalWrite(IN4,in[j+1]>>3&0x1);
    digitalWrite(S2,HIGH);
    digitalWrite(IN1,in[j+2]&0x1);
    digitalWrite(IN2,in[j+2]>>1&0x1);
    digitalWrite(IN3,in[j+2]>>2&0x1);
    digitalWrite(IN4,in[j+2]>>3&0x1);
    digitalWrite(S3,HIGH);
    digitalWrite(IN1,in[j+3]&0x1);
    digitalWrite(IN2,in[j+3]>>1&0x1);
    digitalWrite(IN3,in[j+3]>>2&0x1);
    digitalWrite(IN4,in[j+3]>>3&0x1);
    digitalWrite(S4,HIGH);
    delay(1000);
    } 
   }
}