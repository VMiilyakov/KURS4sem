
#include "Arduino.h"
int C_pin = 8;
int D_pin = 7;
int E_pin = 6;
int F_pin = 5;
int G_pin = 4;
int A_pin = 3;
int B_pin = 2;

int inc_oct_pin = A5;
int dec_oct_pin = A4;

int C_pin_status = 0;
int D_pin_status = 0;
int E_pin_status = 0;
int F_pin_status = 0;
int G_pin_status = 0;
int A_pin_status = 0;
int B_pin_status = 0;

int inc_oct_pin_status = 0;
int dec_oct_pin_status = 0;

int C_pin_pressed = 0;
int D_pin_pressed = 0;
int E_pin_pressed = 0;
int F_pin_pressed = 0;
int G_pin_pressed = 0;
int A_pin_pressed = 0;
int B_pin_pressed = 0;

int inc_oct_pin_pressed = 0;
int dec_oct_pin_pressed = 0;

int octave = 4;

void setup()
{

    Serial.begin(9600);
    pinMode(C_pin, INPUT);
    pinMode(D_pin, INPUT);
    pinMode(E_pin, INPUT);
    pinMode(F_pin, INPUT);
    pinMode(G_pin, INPUT);
    pinMode(A_pin, INPUT);
    pinMode(B_pin, INPUT);

    pinMode(inc_oct_pin, INPUT);
    pinMode(dec_oct_pin, INPUT);
}
void loop()
{
    C_pin_status = digitalRead(C_pin);
    D_pin_status = digitalRead(D_pin);
    E_pin_status = digitalRead(E_pin);
    F_pin_status = digitalRead(F_pin);
    G_pin_status = digitalRead(G_pin);
    A_pin_status = digitalRead(A_pin);
    B_pin_status = digitalRead(B_pin);

    inc_oct_pin_status = digitalRead(inc_oct_pin);
    dec_oct_pin_status = digitalRead(dec_oct_pin);

    if (inc_oct_pin_status == 1)
    {
        if (inc_oct_pin_pressed == 0)
        {
            inc_oct_pin_pressed = 1;
            if(octave < 7)
                octave++;
        }
    }
    else
    {
        inc_oct_pin_pressed = 0;
    }

    if (dec_oct_pin_status == 1)
    {
        if (dec_oct_pin_pressed == 0)
        {
            dec_oct_pin_pressed = 1;
            if(octave > 1)
            octave--;
        }
    }
    else
    {
        dec_oct_pin_pressed = 0;
    }


// C
    if (C_pin_status == 1)
    {
        if (C_pin_pressed == 0)
        {
            C_pin_pressed = 1;
                Serial.write(144);
                Serial.write(24+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (C_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(24+12*octave);
            Serial.write(100);
        }
        C_pin_pressed = 0;
    }
// D
    if (D_pin_status == 1)
    {
        if (D_pin_pressed == 0)
        {
            D_pin_pressed = 1;
                Serial.write(144);
                Serial.write(26+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (D_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(26+12*octave);
            Serial.write(100);
        }
        D_pin_pressed = 0;
    }
// E
    if (E_pin_status == 1)
    {
        if (E_pin_pressed == 0)
        {
            E_pin_pressed = 1;
                Serial.write(144);
                Serial.write(28+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (E_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(28+12*octave);
            Serial.write(100);
        }
        E_pin_pressed = 0;
    }
// F
    if (F_pin_status == 1)
    {
        if (F_pin_pressed == 0)
        {
            F_pin_pressed = 1;
                Serial.write(144);
                Serial.write(29+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (F_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(29+12*octave);
            Serial.write(100);
        }
        F_pin_pressed = 0;
    }
// G
    if (G_pin_status == 1)
    {
        if (G_pin_pressed == 0)
        {
            G_pin_pressed = 1;
                Serial.write(144);
                Serial.write(31+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (G_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(31+12*octave);
            Serial.write(100);
        }
        G_pin_pressed = 0;
    }
// A
    if (A_pin_status == 1)
    {
        if (A_pin_pressed == 0)
        {
            A_pin_pressed = 1;
                Serial.write(144);
                Serial.write(33+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (A_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(33+12*octave);
            Serial.write(100);
        }
        A_pin_pressed = 0;
    }
// B
    if (B_pin_status == 1)
    {
        if (B_pin_pressed == 0)
        {
            B_pin_pressed = 1;
                Serial.write(144);
                Serial.write(35+12*octave);
                Serial.write(100);
        }
    }
    else
    {
        if (B_pin_pressed == 1)
        {
            Serial.write(128);
            Serial.write(35+12*octave);
            Serial.write(100);
        }
        B_pin_pressed = 0;
    }

}
