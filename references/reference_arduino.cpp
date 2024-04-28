/**
 * このライブラリのもとになった，ロータリーエンコーダを動かすためのプログラムです．
 * このプログラムはくまさんからもらいました．
 * ネットに転がっていたのを拾ってきたと言ってました．
 * 著作権とかは知らないです．
*/

#if(0)

#include <Arduino.h>

const int encode_pinA=5;
const int encode_pinB=6;
const int encode_sw=7;
const int encode_table[] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
int encode_count;

void encode(){
  static int last_state1 = 0;
  int sig1_A = digitalRead(encode_pinA);
  int sig1_B = digitalRead(encode_pinB);
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
  float hight=gear_dia*PI*gear_angle/360;
  return hight;
}

void setup(){
  Serial.begin(9600);
  
  pinMode(encode_pinA,INPUT_PULLUP);
  pinMode(encode_pinB,INPUT_PULLUP);

  pinMode(encode_sw,INPUT_PULLUP);

  attachInterrupt(5, encode, CHANGE);
  attachInterrupt(6, encode, CHANGE);
}

void loop(){
  if(digitalRead(encode_sw)==LOW)encode_count=0;
  float hight=hight_calculation(encode_count);
  Serial.println(hight);

}

#endif