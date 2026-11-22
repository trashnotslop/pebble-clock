#ifndef DIGIT_H
#define DIGIT_H

#include <pebble.h>

typedef enum  {
    UNSET,
    HOURS_1,
    HOURS_2,
    MINUTES_1,
    MINUTES_2,
    SECONDS_1,
    SECONDS_2
} ClockDigit;

struct DigitLayer {
    ClockDigit digit;
    Window* window;
    Layer* layer;
    GColor8 bg;
    GColor8 fg;
};

typedef struct DigitLayer DigitLayer;

DigitLayer* digit_layer_create(Window* window, ClockDigit digit);
void digit_layer_destroy(DigitLayer* layer);
void digit_layer_set_text_color(DigitLayer* layer, GColor8 color);
void digit_layer_set_background_color(DigitLayer* layer, GColor8 color);
Layer* digit_layer_get_layer(DigitLayer* layer);
void digit_layer_update(DigitLayer* layer, struct tm *tick_time, TimeUnits changed);

#endif