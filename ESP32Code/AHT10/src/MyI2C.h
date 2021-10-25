#ifndef __MYI2C_H
#define __MYI2C_H
#include <Arduino.h>

void MyI2c_Create(uint8_t SDA_Pin,uint8_t SCL_Pin);
void MYI2C_Starts(void);
void MYI2C_Stop(void);
uint8_t MYI2C_WaitACK(void);
void MYI2C_ACK(void);
void MYI2C_NACK();
void MYI2C_Send_Byte(uint8_t dat);
uint8_t MYI2C_Read_Byte(uint8_t ack);

#endif