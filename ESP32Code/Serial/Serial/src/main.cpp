#include <Arduino.h>
void setup()
{ // put your setup code here, to run once:

  //初始化串口
  
  Serial.begin(115200);
  
}

void loop()
{ // put your main code here, to run repeatedly:
  
  Serial.printf("heap:%d\r\n", heap_caps_get_free_size(MALLOC_CAP_DEFAULT));
  delay(1000);
  
}