#include <Arduino.h>

void setup() {
  ledcSetup(0,108000,9);//108Khz(分辨率需小于10位，否则输出频率无法高于78KHz)
  ledcAttachPin(23,0);
}

void loop() {
  ledcWrite(0,256);
}