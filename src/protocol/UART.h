#ifndef _UART_H_
#define _UART_H_

#include "REG52.H"

void UART_init();

void UART_send_char(unsigned char com_data);

void UART_send_string(const char* str);

#endif
