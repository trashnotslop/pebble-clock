#include <pebble.h>

static Window *s_window;
static TextLayer *s_text_layer;
static int digit = 0;
static char s_buffer[8] = "??????";
GColor bg_color = GColorBlack;
GColor fg_color = GColorWhite;

static void update_label(void);

static void prv_window_load(Window *window)
{
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  window_set_background_color(window, bg_color);

  s_text_layer = text_layer_create(GRect(0, 72, bounds.size.w, 100));
  text_layer_set_text_color(s_text_layer, fg_color);
  text_layer_set_background_color(s_text_layer, bg_color);
  text_layer_set_text_alignment(s_text_layer, GTextAlignmentCenter);
  text_layer_set_font(s_text_layer, fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_CHONKY_80)));
  layer_add_child(window_layer, text_layer_get_layer(s_text_layer));
  update_label();
}

static void prv_window_unload(Window *window)
{
  text_layer_destroy(s_text_layer);
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
  
  update_label();
  window_set_background_color(s_window, bg_color);
  text_layer_set_text_color(s_text_layer, fg_color);
  text_layer_set_background_color(s_text_layer, bg_color);
}

static void update_label(void) {
  static char s_label[3];
  strncpy(s_label, s_buffer + digit, 1);
  text_layer_set_text(s_text_layer, s_label);
}

static void tick_handler(struct tm *tick_time, TimeUnits changed)
{
  strftime(s_buffer, sizeof(s_buffer), "%H%M%S", tick_time);
  update_label();
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

static void prv_init(void)
{
  app_message_register_inbox_received(prv_inbox_received_handler);
  app_message_open(128, 128);

  s_window = window_create();
  window_set_window_handlers(s_window, (WindowHandlers){
                                           .load = prv_window_load,
                                           .unload = prv_window_unload,
                                       });
  const bool animated = true;
  window_stack_push(s_window, animated);
}

static void prv_deinit(void)
{
  window_destroy(s_window);
}

int main(void)
{
  prv_init();
  prv_setup_tick_timer();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", s_window);

  app_event_loop();
  prv_deinit();
}
