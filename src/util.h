#ifndef __UTIL_H__
#define __UTIL_H__

#include "REG52.H"
#include "INTRINS.H"

void delay10ms();
void delay100ms();
void delay1000ms();

void led_off();

void call_led(unsigned char pin, unsigned char led);

#endif
