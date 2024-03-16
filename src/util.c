#include "util.h"

void delay10ms()
{
    unsigned char data n = 18, m = 235;
    do {
        while (--m) {};
    } while (--n);
}

void delay100ms()
{
    unsigned char data n = 180, m = 73;
    do {
        while (--m) {};
    } while (--n);
}

void delay1000ms()
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void led_off()
{
    P0 = 0xFF;
    P1 = 0x7F;
    P2 = 0xFF;
}

void call_led(unsigned char pin, unsigned char led)
{
    switch (pin) {
        case 0:
            P0 = led;
            break;
        case 1:
            P1 = led;
            break;
        case 2:
            P2 = led;
    }
}
