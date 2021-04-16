#include <Arduino.h>
int flag = 0;
void bumper_ISR();
void bumper_reset_ISR();
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),bumper_ISR,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),bumper_reset_ISR,CHANGE);
}

void loop() {
    Serial.println(flag);
}

void bumper_ISR(){
  flag = 1;
}

void bumper_reset_ISR(){
  flag = 0;
}