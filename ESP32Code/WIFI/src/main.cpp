#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "../lib/ArduinoJson/ArduinoJson.h"//使用ArduinoJson库

void WiFi_Connect(){
  WiFi.begin("EternalStarHonorV20","asdfghjkl");
  while(WiFi.status() != WL_CONNECTED){
    delay(200);
    Serial.printf(".");
  }
}

void setup() {
  Serial.begin(115200);
  Serial.printf("connecting.. ");
  WiFi_Connect();
  Serial.println("WiFi connected");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());
}

//获取哔哩哔哩粉丝数
void getBiliBiliFollower(){
  String UID = "336687895";
  String Url = "http://api.bilibili.com/x/relation/stat?vmid=" + UID;
  DynamicJsonDocument doc(1024);
  HTTPClient http;
  http.begin(Url);
  int httpCode = http.GET();
  if(httpCode>0){
    Serial.printf("\r\nhttp get code:%d \r\n",httpCode);
    if(httpCode = HTTP_CODE_OK){
      String resBuff = http.getString();
      Serial.println(resBuff);
      deserializeJson(doc,resBuff);
      long follower = doc["data"]["follower"];
      Serial.printf("Follower:%d\r\n",follower); 
    }
    else{
      Serial.printf("http get error:%s",http.errorToString(httpCode).c_str());
    }
    http.end();
  }
}

//使用和风天气API获取城市实时天气
void getweather(){
  String CID = "CN101210101";//城市ID
  String Key = "c0e520ca3cb24d068107f120a534fc87";//和风天气key
  String Url1 = "https://free-api.heweather.net/s6/weather/now?location=" + CID + "&key=" + Key;
  DynamicJsonDocument doc1(1024);
  HTTPClient http1;
  http1.begin(Url1);
  int httpCode = http1.GET();
  if(httpCode>0){
    //Serial.printf("\r\nhttp get code:%d \r\n",httpCode);
    if(httpCode = HTTP_CODE_OK){
      String resBuff1 = http1.getString();
      Serial.println(resBuff1 + "\r\n");
      deserializeJson(doc1,resBuff1);
      const char*cid = doc1["HeWeather6"][0]["basic"]["cid"];
      const char*location = doc1["HeWeather6"][0]["basic"]["location"];
      const char*parent_city = doc1["HeWeather6"][0]["basic"]["parent_city"];
      const char*admin_area = doc1["HeWeather6"][0]["basic"]["admin_area"];
      const char*cnty = doc1["HeWeather6"][0]["basic"]["cnty"];
      const char*lat = doc1["HeWeather6"][0]["basic"]["lat"];
      const char*lon = doc1["HeWeather6"][0]["basic"]["lon"];
      const char*tz = doc1["HeWeather6"][0]["basic"]["tz"];

      const char*loc = doc1["HeWeather6"][0]["update"]["loc"];
      const char*utc = doc1["HeWeather6"][0]["update"]["utc"];

      const char*status = doc1["HeWeather6"][0]["status"];

      const char*cloud = doc1["HeWeather6"][0]["now"]["cloud"];
      const char*cond_code = doc1["HeWeather6"][0]["now"]["cond_code"];
      const char*cond_txt = doc1["HeWeather6"][0]["now"]["cond_txt"];
      const char*fl = doc1["HeWeather6"][0]["now"]["fl"];
      const char*hum = doc1["HeWeather6"][0]["now"]["hum"];
      const char*pcpn = doc1["HeWeather6"][0]["now"]["pcpn"];
      const char*pres = doc1["HeWeather6"][0]["now"]["pres"];
      const char*tmp = doc1["HeWeather6"][0]["now"]["tmp"];
      const char*vis = doc1["HeWeather6"][0]["now"]["vis"];
      const char*wind_deg = doc1["HeWeather6"][0]["now"]["wind_deg"];
      const char*wind_dir = doc1["HeWeather6"][0]["now"]["wind_dir"];
      const char*wind_sc = doc1["HeWeather6"][0]["now"]["wind_sc"];
      const char*wind_spd = doc1["HeWeather6"][0]["now"]["wind_spd"];
      
      //参数对应描述参考：https://blog.csdn.net/qq_41405257/article/details/80056873
      Serial.printf("城市ID:%s\r\n 位置:%s\r\n 上级城市:%s\r\n 行政区域:%s\r\n 国家:%s\r\n 经度:%s\r\n 纬度:%s\r\n 时区:%s\r\n ",cid,location,parent_city,admin_area,cnty,lat,lon,tz);
      Serial.printf("本地更新时间:%s\r\n UTC更新时间:%s\r\n ",loc,utc);
      Serial.printf("状态:%s\r\n ",status);
      Serial.printf("云量:%s\r\n 实际天气状况代码:%s\r\n 实际天气状况名称:%s\r\n 体感温度:%s\r\n 湿度:%s\r\n 降水量:%s\r\n 大气压强:%s\r\n 温度:%s\r\n 能见度(km):%s\r\n 风向360°角度:%s\r\n 风向:%s\r\n 风力:%s\r\n 风速:%s\r\n ",
      cloud,cond_code,cond_txt,fl,hum,pcpn,pres,tmp,vis,wind_deg,wind_dir,wind_sc,wind_spd); 
    }
    http1.end();
  }
  delay(10000);//十秒获取一次
}

void loop() {
  //WiFi断线重连
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("WiFi connection lost");
    Serial.printf("connecting.. ");
    WiFi_Connect();
    Serial.println("WiFi connected");
    Serial.println("IP address:");
    Serial.println(WiFi.localIP());
  }
  getBiliBiliFollower();
  getweather();
}