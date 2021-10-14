#include <Arduino.h>

hw_timer_t *timer = NULL;
int count = 1;

void IRAM_ATTR TimerEvent(){
  Serial.printf("%d\r\n",(count>5)?count=1:count++);
}

void setup() {
  Serial.begin(115200);
  timer = timerBegin(0,80,true);
  timerAttachInterrupt(timer,&TimerEvent,true);
  timerAlarmWrite(timer,1000000,true);
  timerAlarmEnable(timer);
}

void loop() {
  // put your main code here, to run repeatedly:
}