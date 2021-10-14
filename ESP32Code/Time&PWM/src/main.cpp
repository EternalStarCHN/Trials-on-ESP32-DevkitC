#include <Arduino.h>

hw_timer_t *timer = NULL;
int count = 0;

void IRAM_ATTR TimerEvent(){
  Serial.printf("%d\r\n",(count>4)?count=1:++count);
}

void setup() {
  //串口波特率初始化
  Serial.begin(115200);
  //定时器初始化
  timer = timerBegin(0,80,true);
  timerAttachInterrupt(timer,&TimerEvent,true);
  timerAlarmWrite(timer,2000000,true);
  timerAlarmEnable(timer);
  //ledc输出PWM初始化
  ledcSetup(2,1000,10);
  ledcAttachPin(23,2);
}

void loop() {
  //配置ledc输出PWM的占空比
  ledcWrite(2,count*200);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}