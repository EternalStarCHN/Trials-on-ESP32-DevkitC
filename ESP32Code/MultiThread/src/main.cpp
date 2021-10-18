#include <Arduino.h>

#define Use_MultiCore 1 
void xTask0(void *xTask){
  while(1){
    Serial.println("task0");
    delay(1000);
  }
}

void xTask1(void *xTask){
  while(1){
    Serial.println("task1");
    delay(2000);
  }
}

void setup() {
  Serial.begin(115200);
#if !Use_MultiCore
  xTaskCreate(
    xTask0,   //任务函数
    "xTask0", //具有任务名称的字符串
    4096,     //堆栈大小（字节）
    NULL,     //作为任务输入传递的参数
    2,        //优先级（数值越大优先级越高，loop的优先级为1）
    NULL);    //任务句柄
  xTaskCreate(
    xTask1,
    "xTask1",
    4096,
    NULL,
    0,
    NULL);
#else
  xTaskCreatePinnedToCore(
    xTask0,   //任务函数
    "xtask0", //具有任务名称的字符串
    4096,     //堆栈大小（字节）
    NULL,     //作为任务输入传递的参数
    1,        //优先级（数值越大优先级越高）
    NULL,    //任务句柄
    0);      //核选择，PRO_CPU 为 0, APP_CPU 为 1,或者 tskNO_AFFINITY 允许任务在两者上运行（PRO_CPU的优先级高于APP_CPU）
  xTaskCreatePinnedToCore(
    xTask1,
    "xTask1",
    4096,
    NULL,
    2,
    NULL,
    1);
#endif
}

//优先级1
void loop() {
  Serial.println("test");
  delay(2000);
}