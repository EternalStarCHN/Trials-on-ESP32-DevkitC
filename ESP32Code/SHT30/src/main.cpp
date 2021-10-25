#include <WEMOS_SHT3X.h>
// #define _SSDAMODE 1
#define _PDAMODE 1
SHT3X sht30(0x44);

void setup() {

  Serial.begin(115200);

}

void loop() {
#ifdef _SSDAMODE
  if(sht30.get_SSDAmode()==0){
    Serial.println("---------------MODE:SSDA---------------");
    Serial.print("Temperature in Celsius : ");
    Serial.println(sht30.cTemp);
    Serial.print("Temperature in Fahrenheit : ");
    Serial.println(sht30.fTemp);
    Serial.print("Relative Humidity : ");
    Serial.println(sht30.humidity);
    Serial.println("---------------------------------------");
  }
  else
  {
    Serial.println("Error!");
  }
  delay(1000);
#endif
#ifdef _PDAMODE
  if(sht30.get_PDAmode()==0){
    Serial.println("----------------MODE:PDA---------------");
    Serial.print("Temperature in Celsius : ");
    Serial.println(sht30.cTemp);
    Serial.print("Temperature in Fahrenheit : ");
    Serial.println(sht30.fTemp);
    Serial.print("Relative Humidity : ");
    Serial.println(sht30.humidity);
    Serial.println();
    Serial.println("---------------------------------------");
  }
  else
  {
    Serial.println("Error!");
  }
  delay(2000);
#endif
}
