#ifndef Button_H
#define Button_H

#include "arduino.h"

class Button
{
private:
    int pin;
    byte Long, Single, Double, Triple;

public:
    Button(int pin, byte Long = 0x00, byte Single = 0x00, byte Double = 0x00, byte Triple = 0x00);
    void begin();
    void refresh();
    // void longPress();  //长按
    // void singleClick();  //单击
    // void doubleClick();  //双击
    // void tripleClick();  //三击
};

#endif
