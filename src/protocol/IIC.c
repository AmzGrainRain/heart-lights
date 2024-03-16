#include <INTRINS.H>
#include <STDLIB.H>

#include "REG52.H"
#include "UART.h"
#include "IIC.h"

sbit SCL = P0 ^ 1;
sbit SDA = P0 ^ 0;

void IIC_Controller_Delay()
{
  unsigned char data i;

  _nop_();
  i = 11;
  while (--i);
}

void IIC_Controller_Start()
{
  SCL = 0;
  SDA = 1;
  IIC_Controller_Delay();
  SCL = 1;
  IIC_Controller_Delay();
  SDA = 0;
  IIC_Controller_Delay();
}

void IIC_Controller_Stop()
{
  SCL = 0;
  SDA = 0;
  IIC_Controller_Delay();
  SCL = 1;
  IIC_Controller_Delay();
  SDA = 1;
  IIC_Controller_Delay();
}

// Reading 8-bit data from the PCF8591 chip
unsigned char IIC_Controller_Read()
{
  unsigned char i = 0x80, bit_data = 0;
  for (; i != 0; i >>= 1) {
    SCL = 0;
    // release SDA
    SDA = 1;
    IIC_Controller_Delay();
    SCL = 1;
    IIC_Controller_Delay();
    if (SDA) bit_data |= i;
    IIC_Controller_Delay();
  }

  return bit_data;
}

// Writing 8-bit data to the PCF8591 chip
void IIC_Controller_Write(unsigned char bit_data)
{
  unsigned char i = 0x80;
  for (; i != 0; i >>= 1) {
    SCL = 0;
    IIC_Controller_Delay();
    SDA = (bit_data & i) == i ? 1 : 0;
    IIC_Controller_Delay();
    SCL = 1;
    IIC_Controller_Delay();
  }
}

// Returns 0 that has already received the reply
bit IIC_Controller_Read_ACK()
{
  bit ack = 0;
  SCL     = 0;
  SDA     = 1;
  IIC_Controller_Delay();
  SCL = 1;
  IIC_Controller_Delay();
  ack = SDA;

  return ack;
}

// A reply will be sent when the parameter is 0
void IIC_Controller_Write_ACK(bit ack)
{
  SCL = 0;
  SDA = ack;
  IIC_Controller_Delay();
  SCL = 1;
  IIC_Controller_Delay();
}

void IIC_Controller_Start_And_Write(unsigned char bit_data)
{
  IIC_Controller_Start();
  IIC_Controller_Write(bit_data);
}

// T_IIC_Controller *Create_IIC_Controller()
// {
//   T_IIC_Controller *iic = malloc(sizeof(T_IIC_Controller));
//   iic->delay            = IIC_Controller_Delay;
//   iic->start            = IIC_Controller_Start;
//   iic->stop             = IIC_Controller_Stop;
//   iic->read             = IIC_Controller_Read;
//   iic->write            = IIC_Controller_Write;
//   iic->read_ack         = IIC_Controller_Read_ACK;
//   iic->write_ack        = IIC_Controller_Write_ACK;

//   return iic;
// }
