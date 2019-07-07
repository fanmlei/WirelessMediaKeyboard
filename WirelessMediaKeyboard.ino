#include "Encoder.h"
#include "Button.h"

#define Encoder_A 3
#define Encoder_B 8
#define Encoder_M 9
#define Button_A 2
#define Button_B 4
#define Button_C 5
#define Buzzer 6

const byte MUTE[] =              {0x08, 0x00, 0xA1, 0x03, 0x00, 0x01, 0x00, 0x00};
const byte Volume_Decrement[] =  {0x08, 0x00, 0xA1, 0x03, 0x00, 0x02, 0x00, 0x00};
const byte Volume_Increment[] =  {0x08, 0x00, 0xA1, 0x03, 0x00, 0x04, 0x00, 0x00};
const byte PLAY_PAUSE[] =        {0x08, 0x00, 0xA1, 0x03, 0x00, 0x08, 0x00, 0x00};
const byte STOP[] =              {0x08, 0x00, 0xA1, 0x03, 0x00, 0x10, 0x00, 0x00};
const byte PREVIOUS[] =          {0x08, 0x00, 0xA1, 0x03, 0x00, 0x20, 0x00, 0x00};
const byte NEXT[] =              {0x08, 0x00, 0xA1, 0x03, 0x00, 0x40, 0x00, 0x00};

Encoder Encode(Encoder_A, Encoder_B, Encoder_M);
// Encoder Encode(3, 8, 9);
Button A_Button(2);
// Button B_Button;
// Button C_Button;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  int re = Encode.begin();
  // Serial.println(re);
  // int re = Encode.refresh();
  
  // if(re == 1){
  //   //#编码器正转#
  //   Serial1.write(Volume_Increment, 8);
  // }
  // else if(re == -1){
  //   //#编码器反转#
  //   Serial1.write(Volume_Decrement, 8);
  // }
  // A_Button.refresh();
}
