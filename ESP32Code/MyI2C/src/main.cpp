#include <Arduino.h>
#include <Wire.h>

#define MYI2C_SCL 23
#define MYI2C_SDA 22

#define _address 0x44
TwoWire Wire_SHT3X = TwoWire(0);
unsigned int data[6];

struct Sensor_data{
  double Temp_C;
  double Temp_F;
  double Humi;
}SHT3X;

byte SHT3X_GetData(){
  Wire_SHT3X.beginTransmission(_address);
	// Send measurement command
	Wire_SHT3X.write(0x2C);
	Wire_SHT3X.write(0x06);
	// Stop I2C transmission

	if (Wire_SHT3X.endTransmission()!=0) {
    Serial.println("1");
    return 1;
  }
	  

	delay(500);

	// Request 6 bytes of data
	Wire_SHT3X.requestFrom(_address, 6);

	// Read 6 bytes of data
	// cTemp msb, cTemp lsb, cTemp crc, humidity msb, humidity lsb, humidity crc
	for (int i=0;i<6;i++) {
		data[i]=Wire_SHT3X.read();
	};
	delay(50);
	
	if (Wire_SHT3X.available()!=0) {
    Serial.println("2");
    return 2; 
  }
		

	// Convert the data
	SHT3X.Temp_C = ((((data[0] * 256.0) + data[1]) * 175) / 65535.0) - 45;
	SHT3X.Temp_F = (SHT3X.Temp_C * 1.8) + 32;
	SHT3X.Humi = ((((data[3] * 256.0) + data[4]) * 100) / 65535.0);

	return 0;
}

void setup() {
  Serial.begin(115200);
  Wire_SHT3X.begin(MYI2C_SDA,MYI2C_SCL);
}

void loop() {
  if(SHT3X_GetData()==0){
    Serial.printf("Temp= %lf °C , %lf °F\r\n",SHT3X.Temp_C,SHT3X.Temp_F);
    Serial.printf("Humi = %lf \r\n",SHT3X.Humi);
    delay(1000);
  }
  // put your main code here, to run repeatedly:
}