#include <pebble.h>
#include "digit.h"

static Window *s_window;

static DigitLayer *s_digit_layer;
static ClockDigit digit = UNSET;
static GColor8 bg_color;
static GColor8 fg_color;

static void prv_window_load(Window *window)
{
  Layer *window_layer = window_get_root_layer(window);

  s_digit_layer = digit_layer_create(window, digit);
  digit_layer_set_text_color(s_digit_layer, fg_color);
  digit_layer_set_background_color(s_digit_layer, bg_color);
  layer_add_child(window_layer, digit_layer_get_layer(s_digit_layer));
}

static void prv_window_unload(Window *window)
{
  digit_layer_destroy(s_digit_layer);
}

static void prv_inbox_received_handler(DictionaryIterator *iter, void *context)
{
  // Read color preferences
  Tuple *bg_color_t = dict_find(iter, MESSAGE_KEY_BackgroundColor);
  if (bg_color_t)
  {
    bg_color = GColorFromHEX(bg_color_t->value->int32);
  }

  Tuple *fg_color_t = dict_find(iter, MESSAGE_KEY_ForegroundColor);
  if (fg_color_t)
  {
    fg_color = GColorFromHEX(fg_color_t->value->int32);
  }

  // Read digit preferences
  Tuple *digit_t = dict_find(iter, MESSAGE_KEY_Digit);
  if (digit_t)
  {
    digit = atoi(digit_t->value->cstring);
  }

  window_set_background_color(s_window, bg_color);
  digit_layer_set_text_color(s_digit_layer, fg_color);
  digit_layer_set_background_color(s_digit_layer, bg_color);
}

static void tick_handler(struct tm *tick_time, TimeUnits changed)
{
  digit_layer_update(s_digit_layer, tick_time, changed);
}

static void prv_setup_tick_timer(void)
{
  TimeUnits tu = SECOND_UNIT;
  if (digit < 2)
  {
    tu = HOUR_UNIT;
  }
  else if (digit < 4)
  {
    tu = MINUTE_UNIT;
  }

  tick_timer_service_subscribe(tu, tick_handler);
}

static WindowHandlers handlers = (WindowHandlers){
    .load = prv_window_load,
    .unload = prv_window_unload,
};

static void prv_init(void)
{
  app_message_register_inbox_received(prv_inbox_received_handler);
  app_message_open(128, 128);

  s_window = window_create();
  window_set_window_handlers(s_window, handlers);
  window_stack_push(s_window, false);
}

static void prv_deinit(void)
{
  window_destroy(s_window);
}

int main(void)
{
  prv_init();
  prv_setup_tick_timer();
  app_event_loop();
  prv_deinit();
}
