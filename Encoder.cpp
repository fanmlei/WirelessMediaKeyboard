#include "Encoder.h"

int prePinA = 0;
int prePinB = 0;
int prePinC = 1;
int preDire = 0;
int aPin, bPin, cPin;
byte Up, Down, PressUp, PressDown;
byte LongPress, SingleClick, DoubleClick, TripleClick;

Encoder::Encoder(int Pin_a, int Pin_b, int Pin_c)
{
  aPin = Pin_a;
  bPin = Pin_b;
  cPin = Pin_c;
  pinMode(aPin, INPUT_PULLUP);
  pinMode(bPin, INPUT_PULLUP);
  pinMode(cPin, INPUT_PULLUP);
  prePinA = digitalRead(aPin);
  prePinB = digitalRead(bPin);
  prePinC = digitalRead(cPin);
}
void Encoder::setModelKnob(byte Up = 0x00, byte Down = 0x00, byte PressUp = 0x00, byte PressDown = 0x00)
{
  Up = Up;
  Down = Down;
  PressUp = PressUp;
  PressDown = PressDown;
}

void Encoder::setModelKey(byte LongPress = 0x00, byte SingleClick = 0x00, byte DoubleClick = 0x00, byte TripleClick = 0x00)
{
  LongPress = LongPress;
  SingleClick = SingleClick;
  DoubleClick = DoubleClick;
  TripleClick = TripleClick;
}

int Encoder::nextFrame()
{
  int pinA = digitalRead(aPin);
  int pinB = digitalRead(bPin);
  int result = 0;

  if (pinA > prePinA)
  {
    //a up
    if (pinB == 1)
    {
      //b high
      result = -1;
    }
    else
    {
      //b low
      result = 1;
    }
  }
  else if (pinA < prePinA)
  {
    //a down
    if (pinB == 1)
    {
      //b high
      result = 1;
    }
    else
    {
      //b low
      result = -1;
    }
  }
  else if (pinB > prePinB)
  {
    //b up
    if (pinA == 1)
    {
      //a high
      result = 1;
    }
    else
    {
      //a low
      result = -1;
    }
  }
  else if (pinB < prePinB)
  {
    //b down
    if (pinA == 1)
    {
      //a high
      result = -1;
    }
    else
    {
      //a low
      result = 1;
    }
  }
  prePinA = pinA;
  prePinB = pinB;
  return result;
}

int Encoder::begin()
{
  int dire = nextFrame();
  prePinC = digitalRead(cPin);
  if (dire == 1)
  {
    if (preDire != 1)
    {
      preDire = 1;
      return 0;
    }
    else
    {
      if (!prePinC)
      {
        Serial.println("PressUp");
        const byte Forward[] =  {0x08, 0x00, 0xA1, 0x03, 0x00, 0x00, 0x10, 0x00};
        Serial1.write(Forward, 8);
        return 2;
      }
      const byte Volume_Increment[] =  {0x08, 0x00, 0xA1, 0x03, 0x00, 0x04, 0x00, 0x00};
      Serial1.write(Volume_Increment, 8);
      return 1;
    }
  }
  else if (dire == -1)
  {
    if (preDire != -1)
    {
      preDire = -1;
      return 0;
    }
    else
    {
      if (!prePinC)
      {
        Serial.println("PressDown");
        // const byte Rewind[] =  {0x08, 0x00, 0xA1, 0x03, 0x00, 0x00, 0x20, 0x00};
        // Serial1.write(Rewind, 8);
        return 3;
      }
      // const byte Volume_Decrement[] =  {0x08, 0x00, 0xA1, 0x03, 0x00, 0x02, 0x00, 0x00};
      // Serial1.write(Volume_Decrement, 8);
      return -1;
    }
  }
  return 0;
}
