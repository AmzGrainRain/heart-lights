#ifndef __LED_STYLE_H__
#define __LED_STYLE_H__

#include "REG52.H"
#include "util.h"

static unsigned char PIN[22] = {0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
static unsigned char LED[22] = {0xBF, 0x7F, 0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFE, 0xFD, 0x5F, 0x6F, 0x77, 0x7B, 0x7D, 0x7E, 0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF};

void mode_light_colorful();

void mode_light();

void mode_flicker();

void mode_flowing_water();

void mode_line_scan();

void mode_alternating_flicker();

#endif
