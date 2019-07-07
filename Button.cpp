#include "Button.h"

int pin, ret = 0;

Button::Button(int pin, byte Long = 0x00, byte Single = 0x00, byte Double = 0x00, byte Triple = 0x00)
{
    Long = Long;
    pin = pin;
    Single = Single;
    Double = Double;
    Triple = Triple;
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
}

void Button::refresh()
{
    if(digitalRead(pin)){
    int i = 0;
    //按下循环
    while(digitalRead(pin)){
      delay(10);
      i++;
      //按下超时（上一首）
      if(i>50){
        //#按钮长按保持#
        Serial.println(Long);
        i = 0;
        while(digitalRead(pin)){
          if(i>1){
            //#按钮长按保持循环#
            Serial.println(Long);
          }
          delay(500);
          i++;
        }
        return;
      }
    }
    i = 0;
    //释放循环
    while(!digitalRead(pin)){
      delay(10);
      i++;
      //释放超时（暂停/播放）
      if(i>50){
        //#按钮短按#
        Serial.println(Single);
        return;
      }
    }

    i = 0;
    //按下循环2
    while(digitalRead(pin)){
      delay(10);
      i++;
      //按下超时（下一首）
      if(i>50){
        //#按钮双击保持#
        Serial.println(Double);
        i = 0;
        while(digitalRead(pin)){
          if(i>1){
            //#按钮双击保持循环#
           Serial.println(Double);
          }
          delay(500);
          i++;
        }
        return;
      }
    }

    i = 0;
    //释放循环2
    while(!digitalRead(pin)){
      delay(10);
      i++;
      //释放超时（下一首）
      if(i>50){
        //#按钮双击#
        Serial.println(Double);
        return;
      }
    }

    //按下循环3
    while(digitalRead(pin)){
      delay(10);
      i++;
      //按下超时（喜欢）
      if(i>50){
        //#按钮三击保持#
        Serial.println(Triple);
        while(!digitalRead(pin)){
          //#按钮三击保持循环#
          delay(500);
        }
        return;
      }
    }
    //#按钮三击#
    Serial.println(Triple);
    return;

  }
}
