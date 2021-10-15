#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32BT");//设置蓝牙名称
  SerialBT.setPin("asdfghjkl");//z设置蓝牙密码
  Serial.printf("BT initial ok and ready to pair. \r\n");
}

void loop() {
/*   if(SerialBT.connected()){
    Serial.printf("Connected!\r\n");
  }
  else{
    Serial.printf("Disconnect!\r\n");
  } */
  if(SerialBT.available()){
    Serial.write(SerialBT.read());
  }
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  delay(100);
}