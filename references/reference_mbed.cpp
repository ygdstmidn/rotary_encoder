/**
 * このライブラリのもとになった，ロータリーエンコーダを動かすためのプログラムです．
 * このプログラムはreference_arduino.cppから作られています．
*/

#if(0)

#include "mbed.h"
#include <stdio.h>//snprintf使う
#include <math.h>//πはmbedにはない

const int encode_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
int encode_count=0;

UnbufferedSerial pc(USBTX,USBRX,9600);

DigitalIn read_encode_pinA (PA_0);
DigitalIn read_encode_pinB (PA_1);

DigitalIn read_encode_sw (PA_4);

InterruptIn wa_encode_pinA(PA_0);//割り込み
InterruptIn wa_encode_pinB(PA_1);

void encode(){
  static int last_state1 = 0;
  int sig1_A = read_encode_pinA;
  int sig1_B = read_encode_pinB;
  int8_t state1 = sig1_A | (sig1_B << 1);
  int8_t sum1 = state1 | last_state1<<2;
  if (last_state1 != state1) {
    encode_count+=encode_table[sum1];
    last_state1=state1;
  }
}

const int encode_PR=4*100;
const int encode_gear=15;//エンコード側の歯数
const int gear=40;//ピニオンの歯数
const int gear_dia=40;//ピッチ円直径 mm
double encode_angle;
float hight_calculation(float count){//単位mm
  encode_angle = float(count)*360.0/encode_PR;
  float gear_angle=encode_angle*encode_gear/gear;
  float hight=gear_dia*M_PI*gear_angle/360;
  return hight;
}

void serialprint(float data)
{
  char sendd[17];
  for (int i = 0; i < 17; i++)
  {
    sendd[i]=0;
  }
  char *pointa=sendd;
  int data10=(int)(data*100);
  snprintf(pointa,17,"%d.%02d\n",data10/100,(1-2*(0>data10))*(data10-(data10/100)*100));
  pc.write(pointa,16);
}

void setup(){
  read_encode_sw.mode(PullUp);

  wa_encode_pinA.rise(&encode);//割り込み
  wa_encode_pinA.fall(&encode);
  wa_encode_pinA.mode(PullUp);

  wa_encode_pinB.rise(&encode);
  wa_encode_pinB.fall(&encode);
  wa_encode_pinB.mode(PullUp);
}

void loop(){
  if(read_encode_sw==0)encode_count=0;
  float hight=hight_calculation(encode_count);
  serialprint(hight);
}

int main()
{
  setup();
  while(1)
  {
    loop();
  }
}

#endif