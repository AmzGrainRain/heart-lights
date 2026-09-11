#include "led_style.h"

static unsigned char code PIN[22] = {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
static unsigned char code LED[22] = {0xBF, 0x7F, 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFE, 0xFD, 0x5F,
                                     0x6F, 0x77, 0x7B, 0x7D, 0x7E, 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF};

void mode_light_colorful(void)
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
}

void mode_light(void)
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
    delay10ms();
    led_off();
}

void mode_flicker(void)
{
    P0 = 0;
    P1 = 0;
    P2 = 0;
    delay500ms();
    led_off();
    delay500ms();
}

void mode_flowing_water(void)
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
        delay200ms();
    }
}

void mode_line_scan(void)
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

        delay200ms();
        delay200ms();
        led_off();
        ++i;
        --j;
    }

    P1 = 0x57;
    delay200ms();
    P1 = 0x6F;
    delay200ms();
    P1 = 0x7F;
}

void mode_alternating_flicker(void)
{
    P0 = 0xAA;
    P1 = 0x55;
    P2 = 0x56;
    delay500ms();
    delay200ms();
    P0 = 0x55;
    P1 = 0x6A;
    P2 = 0xA9;
    delay500ms();
    delay200ms();
}
