#include <Arduino.h>
void TouchEvent(){
  digitalWrite(2,HIGH);
  Serial.printf("Touch!\r\n");
  delay(100);
}

void setup() {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  touchAttachInterrupt(T0,TouchEvent,30);
}

void loop() {
  Serial.printf("touch:%d\r\n",touchRead(T0));
  digitalWrite(2,LOW);
  delay(100);
}