/*
  Pitch follower

  Plays a pitch that changes based on a changing
  analog input

  circuit:
  * 8-ohm speaker on digital pin 9
  * photoresistor on analog 0 to 5V
  * 4.7K resistor on analog 0 to ground

  created 21 Jan 2010
  modified 31 May 2012  by Tom Igoe, with
  suggestion from Michael Flynn

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone2
*/

int sensorReading = 0;//定义为整型，初始化变量为0

void setup()
{
  pinMode(A0, INPUT);//把A0引脚设置为输入
  Serial.begin(9600);//初始化串口
  pinMode(9, OUTPUT);//把9引脚设置为输出
}

void loop()
{
  // read the sensor
  sensorReading = analogRead(A0);
  //通过analogRead指令A0口可以读取此时的电压值，在Arduino内置的模拟数字转换功能作用下，该输入电压将被映射到数值0-1023之间
  // print the sensor reading so you know its range
  Serial.println(sensorReading);
  //在串口监视器中打印每刻的电压
  // map the sensor reading to a range for the
  // speaker
  tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
  //tone指令可使压电蜂鸣器播放声音用法是tone（引脚，频率，持续时间），9代表在第9引脚，map是将数字从一个范围映射到一个新的范围，由于输入的A0口的电压被映射到0到1023，整个中间函数为了将输入的A0电压转化为可被人听到的声音频率，1000表示持续1000ms
  delay(10); // Delay a little bit to improve simulation performance
  //暂停10ms
}