#include "digit.h"

static GBitmap *s_bitmap[10];

static GBitmap *prv_get_digit_bitmap(uint8_t digit)
{
    if (s_bitmap[digit] == NULL)
    {
        s_bitmap[digit] = gbitmap_create_with_resource(RESOURCE_ID_DIGIT_0 + digit);
    }
    return s_bitmap[digit];
}

DigitLayer *digit_layer_create(Window *window, ClockDigit digit)
{
    DigitLayer *digit_layer = malloc(sizeof(DigitLayer));
    digit_layer->digit = digit;
    digit_layer->window = window;
    digit_layer->layer = bitmap_layer_create(layer_get_frame(window_get_root_layer(window)));
    bitmap_layer_set_compositing_mode(digit_layer->layer, GCompOpSet);
    return digit_layer;
}

void digit_layer_destroy(DigitLayer *layer)
{
    bitmap_layer_destroy(layer->layer);
    free(layer);
}

Layer *digit_layer_get_layer(DigitLayer *layer)
{
    return bitmap_layer_get_layer(layer->layer);
}

void digit_layer_update(DigitLayer *layer, struct tm *tick_time, TimeUnits changed)
{
    uint8_t digit_num = 0;

    switch (layer->digit)
    {
    case UNSET:
        digit_num = 0;
        break;
    case HOURS_1:
        digit_num = tick_time->tm_hour / 10;
        break;
    case HOURS_2:
        digit_num = tick_time->tm_hour % 10;
        break;
    case MINUTES_1:
        digit_num = tick_time->tm_min / 10;
        break;
    case MINUTES_2:
        digit_num = tick_time->tm_min % 10;
        break;
    case SECONDS_1:
        digit_num = tick_time->tm_sec / 10;
        break;
    case SECONDS_2:
        digit_num = tick_time->tm_sec % 10;
        break;
    }

    bitmap_layer_set_bitmap(layer->layer, prv_get_digit_bitmap(digit_num));
}
