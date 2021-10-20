#include <Arduino.h>
#include "WiFi.h"
#include "NTPClient.h"
 
const char *ssid     = "EternalStarHonorV20";
const char *password = "asdfghjkl";
const char *NTPaddress = "ntp1.aliyun.com"; //各个NTP服务器地址https://blog.csdn.net/weixin_42588262/article/details/82501488
WiFiUDP ntpUDP; // 创建一个WIFI UDP连接
 
NTPClient timeClient(ntpUDP, NTPaddress, 60*60*8, 30*60*1000);
 
void setup(){
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  Serial.println();
  timeClient.begin();
}
 
void loop() {
  timeClient.update();
 
  Serial.println(timeClient.getFormattedTime());
 
  delay(1000);
}