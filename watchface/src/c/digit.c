#include "digit.h"

static GBitmap *s_bitmap;

DigitLayer *digit_layer_create(Window *window, ClockDigit digit)
{
    DigitLayer* digit_layer = malloc(sizeof(DigitLayer));
    digit_layer->digit = digit;
    digit_layer->window = window;
    digit_layer->layer = bitmap_layer_create(layer_get_frame(window_get_root_layer(window)));
    return digit_layer;
}

void digit_layer_destroy(DigitLayer* layer)
{
    layer_destroy(layer->layer);
    free(layer);
}

void digit_layer_set_text_color(DigitLayer *layer, GColor8 color)
{
    layer->fg = color;
}

void digit_layer_set_background_color(DigitLayer *layer, GColor8 color)
{
    layer->bg = color;
}

Layer *digit_layer_get_layer(DigitLayer *layer)
{
    return layer->layer;
}

void digit_layer_update(DigitLayer *layer, struct tm *tick_time, TimeUnits changed)
{
    s_bitmap = gbitmap_create_with_resource(RESOURCE_ID_DIGIT_0);
    bitmap_layer_set_compositing_mode(layer->layer, GCompOpSet);
    bitmap_layer_set_bitmap(layer->layer, s_bitmap);

    switch (layer->digit) {
        case UNSET:
        break;
        case HOURS_1:
        break;
        case HOURS_2:
        break;
        case MINUTES_1:
        break;
        case MINUTES_2:
        break;
        case SECONDS_1:
        break;
        case SECONDS_2:
        break;
    }
}
