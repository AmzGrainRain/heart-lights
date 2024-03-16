#ifndef _PROTOCOL_IIC_H_
#define _PROTOCOL_IIC_H_

// struct IIC_Controller {
//   void (*delay)();
//   void (*start)();
//   void (*stop)();
//   unsigned char (*read)();
//   void (*write)(unsigned char bit_data);
//   bit (*read_ack)();
//   void (*write_ack)(bit ack);
// };
// #define T_IIC_Controller struct IIC_Controller

#define WRITE_MODE 0x90
#define READ_MODE  0x91

void IIC_Controller_Delay();

void IIC_Controller_Start();

void IIC_Controller_Stop();

unsigned char IIC_Controller_Read();

void IIC_Controller_Write(unsigned char bit_data);

// Returns 0 that has already received the reply
bit IIC_Controller_Read_ACK();

void IIC_Controller_Write_ACK(bit ack);

void IIC_Controller_Start(unsigned char bit_data);

// T_IIC_Controller* Create_IIC_Controller();

#endif
