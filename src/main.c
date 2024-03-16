#include "REG52.H"
#include "./protocol/UART.h"

#include "util.h"
#include "led_style.h"

sbit MODE_SW           = P3 ^ 2;
int MODE               = 0;
void (*MODE_LIST[6])() = {
    mode_light_colorful,
    mode_light,
    mode_flicker,
    mode_flowing_water,
    mode_line_scan,
    mode_alternating_flicker
};

void init_interrupt()
{
    IT0 = 1; // ����Ϊ�½��ش���
    EX0 = 1;
    EA  = 1;
    UART_send_string("Init interrupt done.\n");
}

void mode_sw() interrupt 0
{
    IE0 = 0; // ����ⲿ�ж�0��־λ
    delay10ms();
    if (MODE_SW == 1) MODE = MODE == 5 ? 0 : MODE + 1;
    UART_send_string("\n\nswitch mode\n\n");
}

int main()
{
    led_off();
    UART_init();
    init_interrupt();
    while (1) MODE_LIST[MODE]();
}
