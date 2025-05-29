#include "Arduino.h"

// ST_CP вход 74HC595
int latchPin = 4;
// SH_CP вход 74HC595
int clockPin = 3;
// DS вход 74HC595
int dataPin = 2;

int speed_pin = A6;
int pause_pin = 5;
int reverse_pin = 6;

int speed = 0;
int pause = 0;
int reversed = 0;

int pause_pressed = 0;
int pause_btn_status = 0;

int reverse_pressed = 0;
int reverse_btn_status = 0;

int num = 0;
unsigned long update_time = 0;

void setup()
{
  pinMode(pause_pin, INPUT);
  pinMode(reverse_pin, INPUT);
  pinMode(speed_pin, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
  pause_btn_status = digitalRead(pause_pin);
  reverse_btn_status = digitalRead(reverse_pin);
  speed = map(analogRead(speed_pin), 0, 1023, 100, 500);

  if (pause_btn_status == 1)
  {
    if (pause_pressed == 0)
    {
      pause_pressed = 1;
      if (pause == 1)
      {
        pause = 0;
      }
      else
      {
        pause = 1;
      }
    }
  }
  else
  {
    pause_pressed = 0;
  }

  if (reverse_btn_status == 1)
  {
    if (reverse_pressed == 0)
    {
      reverse_pressed = 1;
      if (reversed == 1)
      {
        reversed = 0;
      }
      else
      {
        reversed = 1;
      }
    }
  }
  else
  {
    reverse_pressed = 0;
  }

  if (!pause)
  {
    if (millis() - update_time >= speed)
    {
      update_time = millis();

      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, num);
      Serial.println(speed);
      digitalWrite(latchPin, HIGH);
      if (!reversed)
      {
        num++;
      }
      else
      {
        num--;
      }
    }
  }
}
