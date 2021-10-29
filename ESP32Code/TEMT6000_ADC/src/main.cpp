#include <Arduino.h>
#define ADC_Pin 39
void setup() {
  Serial.begin(115200);
  adcAttachPin(ADC_Pin);
  analogReadResolution(16);//设置分辨率
};

void loop() {
  double adc_value = 0;
  adc_value = analogRead(ADC_Pin);
  Serial.printf("Volt = %lf\r\n",adc_value/65535*3.3);
  delay(1000);
  // put your main code here, to run repeatedly:
}