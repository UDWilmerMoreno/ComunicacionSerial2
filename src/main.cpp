#include <Arduino.h>
#define M1Adelante 45
#define M1Atras 47
#define M2Adelante 49
#define M2Atras 51
#define PWM1 10
#define PWM2 9
int velocidad = 400;

void setup()
{
  Serial1.begin(115200);
  pinMode(M1Adelante, OUTPUT);
  pinMode(M1Atras, OUTPUT);
  pinMode(M2Adelante, OUTPUT);
  pinMode(M2Atras, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  digitalWrite(M1Adelante, LOW);
  digitalWrite(M1Atras, LOW);
  digitalWrite(M2Adelante, LOW);
  digitalWrite(M2Atras, LOW);
  while (!Serial1)
  {
  }
}

void loop()
{

  analogWrite(PWM1, velocidad);
  analogWrite(PWM2, velocidad);
  if (Serial1.available() > 0)
  {
    char dato = Serial1.read();
    if (dato == 'w')
    {
      digitalWrite(M1Adelante, 1);
      digitalWrite(M1Atras, 0);
      digitalWrite(M2Adelante, 1);
      digitalWrite(M2Atras, 0);
    }

    else if (dato == 's')
    {
      digitalWrite(M1Adelante, 0);
      digitalWrite(M1Atras, 1);
      digitalWrite(M2Adelante, 0);
      digitalWrite(M2Atras, 1);
    }

    else if (dato == 'd')
    {
      digitalWrite(M1Adelante, 1);
      digitalWrite(M1Atras, 0);
      digitalWrite(M2Adelante, 0);
      digitalWrite(M2Atras, 1);
    }

    else if (dato == 'a')
    {
      digitalWrite(M1Adelante, LOW);
      digitalWrite(M1Atras, HIGH);
      digitalWrite(M2Adelante, HIGH);
      digitalWrite(M2Atras, LOW);
    }

    else if (dato == 'q')
    {
      digitalWrite(M1Adelante, LOW);
      digitalWrite(M1Atras, LOW);
      digitalWrite(M2Adelante, LOW);
      digitalWrite(M2Atras, LOW);
    }
  }
}