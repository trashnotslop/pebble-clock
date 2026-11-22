#ifndef DIGIT_H
#define DIGIT_H

#include <pebble.h>

typedef enum
{
    UNSET,
    HOURS_1,
    HOURS_2,
    MINUTES_1,
    MINUTES_2,
    SECONDS_1,
    SECONDS_2
} ClockDigit;

struct DigitLayer
{
    ClockDigit digit;
    Window *window;
    BitmapLayer *layer;
};

typedef struct DigitLayer DigitLayer;

DigitLayer *digit_layer_create(Window *window, ClockDigit digit);
void digit_layer_destroy(DigitLayer *layer);
Layer *digit_layer_get_layer(DigitLayer *layer);
void digit_layer_update(DigitLayer *layer, struct tm *tick_time, TimeUnits changed);

#endif