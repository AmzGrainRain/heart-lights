#include "led_style.h"

void mode_light_colorful()
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
}

void mode_light()
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
    delay100ms();
    led_off();
}

void mode_flicker()
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
    delay100ms();
    led_off();
    delay100ms();
}

void mode_flowing_water()
{
    unsigned char i;
    for (i = 0; i < 22; ++i) {
        led_off();
        switch (PIN[i]) {
            case 0:
                P0 = LED[i];
                break;
            case 1:
                P1 = LED[i];
                break;
            case 2:
                P2 = LED[i];
        }
        delay100ms();
    }
}

void mode_line_scan()
{
    unsigned char i = 2, j = 20;

    P0 = 0xBF;
    delay100ms();
    P0 = 0x5F;
    delay100ms();
    P0 = 0xFF;

    while (i < 10 || j > 12) {
        if (PIN[i] == PIN[j]) call_led(PIN[i], !(!LED[i] | !LED[j]));
        else {
            call_led(PIN[i], LED[i]);
            call_led(PIN[j], LED[j]);
        }

        delay100ms();
        led_off();
        ++i;
        --j;
    }

    P1 = 0x57;
    delay100ms();
    P1 = 0x6F;
    delay100ms();
    P1 = 0x7F;
}

void mode_alternating_flicker()
{
    P0 = 0xAA;
    P1 = 0x55;
    P2 = 0x56;
    delay100ms();
    P0 = 0x55;
    P1 = 0x6A;
    P2 = 0xA9;
    delay100ms();
}
