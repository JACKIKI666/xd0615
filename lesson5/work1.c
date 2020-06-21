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
  pinMode(IN1, OUTPUT);//杈撳叆1
  pinMode(IN2, OUTPUT);//杈撳叆2
  pinMode(IN3, OUTPUT);//杈撳叆3
  pinMode(IN4, OUTPUT);//杈撳叆4
  pinMode(S1, OUTPUT);//鐗囬€?
  pinMode(S2, OUTPUT);//鐗囬€?
  pinMode(S3, OUTPUT);//鐗囬€?
  pinMode(S4, OUTPUT);//鐗囬€?
  
  pinMode(LT,OUTPUT);//娴嬭瘯
  pinMode(BT,OUTPUT);//娑堥殣
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,LOW);
}

void loop()
{
  if(Serial.available()>0)
  {
    inall=Serial.read();
    digitalWrite(S4,LOW);
    digitalWrite(IN1,inall&0x1);
    digitalWrite(IN2,inall>>1&0x1);
    digitalWrite(IN3,inall>>2&0x1);
    digitalWrite(IN4,inall>>3&0x1);
    digitalWrite(S4,HIGH);
      delay(1000); 
   }
}