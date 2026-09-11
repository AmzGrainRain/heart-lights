#include "REG52.H"
#include "./protocol/UART.h"

#include "util.h"
#include "led_style.h"

sbit MODE_SW = P3 ^ 2;

volatile unsigned char MODE  = 0;
volatile bit mode_sw_pending = 0;

void (*MODE_LIST[6])() = {
    mode_light_colorful,
    mode_light,
    mode_flicker,
    mode_flowing_water,
    mode_line_scan,
    mode_alternating_flicker};

void init_interrupt(void)
{
    MODE_SW = 1;
    IT0     = 1;
    IE0     = 0;
    EX0     = 1;
    EA      = 1;
}

void mode_sw(void) interrupt 0
{
    EX0             = 0;
    mode_sw_pending = 1;
}

int main(void)
{
    led_off();
    UART_init();
    init_interrupt();

    while (1) {
        if (!mode_sw_pending) {
            MODE_LIST[MODE]();
            continue;
        }

        delay10ms();

        if (MODE_SW == 0) {
            ++MODE;
            if (MODE >= 6) MODE = 0;

            while (MODE_SW == 0);
            delay10ms();
        }

        mode_sw_pending = 0;
        IE0             = 0;
        EX0             = 1;
    }
}
