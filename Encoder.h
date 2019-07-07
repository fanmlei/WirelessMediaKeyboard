/*
  Created by fanmlei, 7 July 2019.
  使用EC11编码器：
  共计八种操作类型：1 正转， 2 反转，3 按压正转， 4 按压反转 5 长按， 6 单击，7 双击， 8 三击
  引脚: 
      aPin  A
      bPin  B
      cPin  E
*/
#ifndef Encoder_H
#define Encoder_H

#include <Arduino.h>

class Encoder
{
private:
  int prePinA;
  int prePinB;
  int preDire;
  int aPin, bPin, cPin;
  byte Up, Down, PressUp, PressDown;
  byte LongPress, SingleClick, DoubleClick, TripleClick;
  int nextFrame();

public:
  Encoder(int aPin, int bPin, int cPin);
  int begin();
  void setModelKnob(byte Up = 0x00, byte Down = 0x00, byte PressUp = 0x00, byte PressDown = 0x00);
  void setModelKey(byte LongPress = 0x00, byte SingleClick = 0x00, byte DoubleClick = 0x00, byte TripleClick = 0x00);
};

#endif
