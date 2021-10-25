#include "MyI2C.h"
uint8_t MYI2C_SDA, MYI2C_SCL;
void MyI2c_Create(uint8_t SDA_Pin,uint8_t SCL_Pin){
    MYI2C_SDA = SDA_Pin;
    MYI2C_SCL = SCL_Pin;
}

void MYI2C_Starts(void){
    pinMode( MYI2C_SCL , OUTPUT );
    digitalWrite( MYI2C_SCL , HIGH );
    digitalWrite( MYI2C_SDA , HIGH );
    delayMicroseconds(5);
    // digitalWrite( MYI2C_SCL , HIGH);
    digitalWrite( MYI2C_SDA , LOW );
    delayMicroseconds(5);
    digitalWrite( MYI2C_SCL , LOW );
}

void MYI2C_Stop(void){
    pinMode( MYI2C_SDA , OUTPUT );
    pinMode( MYI2C_SCL , OUTPUT );
    digitalWrite( MYI2C_SCL , LOW );
    digitalWrite( MYI2C_SDA , LOW );
    delayMicroseconds(5);
    digitalWrite( MYI2C_SCL , HIGH );
    digitalWrite( MYI2C_SDA , HIGH );
    delayMicroseconds(5);
}

uint8_t MYI2C_WaitACK(void){
    uint8_t ucTimeCnt = 0;
    pinMode( MYI2C_SDA , OUTPUT );
    pinMode( MYI2C_SCL , OUTPUT );
    digitalWrite( MYI2C_SDA , HIGH );
    delayMicroseconds(5);
    digitalWrite( MYI2C_SCL , HIGH );
    delayMicroseconds(5);
    // pinMode( MYI2C_SDA , INPUT );
    while(digitalRead( MYI2C_SDA )){
        ucTimeCnt ++;
        if( ucTimeCnt > 250 ){
            MYI2C_Stop();
            return 1;
        }
    }
    digitalWrite( MYI2C_SCL , LOW );
    return 0;
}

void MYI2C_ACK(void){
    pinMode( MYI2C_SDA , OUTPUT );
    pinMode( MYI2C_SCL , OUTPUT );
    digitalWrite( MYI2C_SCL , LOW );
    digitalWrite( MYI2C_SDA , LOW );
    delayMicroseconds(2);
    digitalWrite( MYI2C_SCL , HIGH );
    delayMicroseconds(5);
    digitalWrite( MYI2C_SCL , LOW );
}

void MYI2C_NACK(){
    pinMode( MYI2C_SDA , OUTPUT );
    pinMode( MYI2C_SCL , OUTPUT );
    digitalWrite( MYI2C_SCL , LOW );
    digitalWrite( MYI2C_SDA , HIGH );
    delayMicroseconds(2);
    digitalWrite( MYI2C_SCL , HIGH );
    delayMicroseconds(5);
    digitalWrite( MYI2C_SCL , LOW );
}

void MYI2C_Send_Byte(uint8_t dat){
    pinMode( MYI2C_SDA , OUTPUT );
    pinMode( MYI2C_SCL , OUTPUT );
    digitalWrite( MYI2C_SCL , LOW );
    for( uint8_t t = 0 ; t < 8 ; t++ ){
        digitalWrite( MYI2C_SDA , ( dat & 0x80 ) >> 7 );
        dat = dat << 1;
        digitalWrite( MYI2C_SCL , HIGH );
        delayMicroseconds(2);
        digitalWrite( MYI2C_SCL , LOW );
        delayMicroseconds(2);
    }
}

uint8_t MYI2C_Read_Byte(uint8_t ack){
    uint8_t value;
    value = 0;
    pinMode( MYI2C_SCL , OUTPUT );
    for( uint8_t i = 0 ; i < 8 ; i++ ){
        value <<= 1;
        digitalWrite( MYI2C_SCL , HIGH );
        delayMicroseconds(2);
        if( digitalRead( MYI2C_SDA ) ){
            value++;
        }
        digitalWrite( MYI2C_SCL , LOW );
        delayMicroseconds(2);
    }
    if(ack == 0){
        MYI2C_NACK();
    }
    else{
        MYI2C_ACK();
    }
    return value;
}