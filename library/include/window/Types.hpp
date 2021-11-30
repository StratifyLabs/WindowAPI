

#ifndef WINDOWAPI_WINDOW_TYPES_HPP
#define WINDOWAPI_WINDOW_TYPES_HPP

#include <api/api.hpp>

#include <SDL.h>

namespace window {

enum class WindowFlags {
  null = 0,
  fullscreen = SDL_WINDOW_FULLSCREEN,
  opengl = SDL_WINDOW_OPENGL,
  shown = SDL_WINDOW_SHOWN,
  hidden = SDL_WINDOW_HIDDEN,
  borderless = SDL_WINDOW_BORDERLESS,
  resizeable = SDL_WINDOW_RESIZABLE,
  minimized = SDL_WINDOW_MINIMIZED,
  maximized = SDL_WINDOW_MAXIMIZED,
  mouse_grabbed = SDL_WINDOW_MOUSE_GRABBED,
  input_focus = SDL_WINDOW_INPUT_FOCUS,
  mouse_focus = SDL_WINDOW_MOUSE_FOCUS,
  fullscreen_desktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
  foreign = SDL_WINDOW_FOREIGN,
  highdpi = SDL_WINDOW_ALLOW_HIGHDPI,
  mouse_capture = SDL_WINDOW_MOUSE_CAPTURE,
  always_on_top = SDL_WINDOW_ALWAYS_ON_TOP,
  skip_taskbar = SDL_WINDOW_SKIP_TASKBAR,
  utility = SDL_WINDOW_UTILITY,
  tooltip = SDL_WINDOW_TOOLTIP,
  popup_menu = SDL_WINDOW_POPUP_MENU,
  keyboard_grabbed = SDL_WINDOW_KEYBOARD_GRABBED,
  vulkan = SDL_WINDOW_VULKAN,
  metal = SDL_WINDOW_METAL
};

enum class PixelFormat {
  unknown = SDL_PIXELFORMAT_UNKNOWN,
  index1lsb = SDL_PIXELFORMAT_INDEX1LSB,
  index1msb = SDL_PIXELFORMAT_INDEX1MSB,
  index4lsb = SDL_PIXELFORMAT_INDEX4LSB,
  index4msb = SDL_PIXELFORMAT_INDEX4MSB,
  index8 = SDL_PIXELFORMAT_INDEX8,
  rgb332 = SDL_PIXELFORMAT_RGB332,
  rgb444 = SDL_PIXELFORMAT_RGB444,
  rgb555 = SDL_PIXELFORMAT_RGB555,
  bgr555 = SDL_PIXELFORMAT_BGR555,
  argb4444 = SDL_PIXELFORMAT_ARGB4444,
  rgba4444 = SDL_PIXELFORMAT_RGBA4444,
  abgr4444 = SDL_PIXELFORMAT_ABGR4444,
  bgra4444 = SDL_PIXELFORMAT_BGRA4444,
  argb1555 = SDL_PIXELFORMAT_ARGB1555,
  rgba5551 = SDL_PIXELFORMAT_RGBA5551,
  abgr1555 = SDL_PIXELFORMAT_ABGR1555,
  bgra5551 = SDL_PIXELFORMAT_BGRA5551,
  rgb565 = SDL_PIXELFORMAT_RGB565,
  bgr565 = SDL_PIXELFORMAT_BGR565,
  rgb24 = SDL_PIXELFORMAT_RGB24,
  bgr24 = SDL_PIXELFORMAT_BGR24,
  rgb888 = SDL_PIXELFORMAT_RGB888,
  rgbx8888 = SDL_PIXELFORMAT_RGBX8888,
  bgr888 = SDL_PIXELFORMAT_BGR888,
  bgrx8888 = SDL_PIXELFORMAT_BGRX8888,
  argb8888 = SDL_PIXELFORMAT_ARGB8888,
  rgba8888 = SDL_PIXELFORMAT_RGBA8888,
  abgr8888 = SDL_PIXELFORMAT_ABGR8888,
  bgra8888 = SDL_PIXELFORMAT_BGRA8888,
  argb2101010 = SDL_PIXELFORMAT_ARGB2101010
};

enum class BlendMode {
  none = SDL_BLENDMODE_NONE,
  blend = SDL_BLENDMODE_BLEND,
  add = SDL_BLENDMODE_ADD,
  modulate = SDL_BLENDMODE_MOD
};

class Point {
public:
  Point() = default;
  Point(int x, int y) : m_x(x), m_y(y) {}
  static constexpr int undefined_value = SDL_WINDOWPOS_UNDEFINED;

private:
  API_AF(Point, int, x, undefined_value);
  API_AF(Point, int, y, undefined_value);
};

class Size {
public:
  Size() = default;
  Size(int width, int height) : m_width(width), m_height(height) {}

  Size get_double() const { return Size(width() * 2, height() * 2); }

  Size get_half() const { return Size(width() / 2, height() / 2); }

private:
  API_AF(Size, int, width, 0);
  API_AF(Size, int, height, 0);
};

class RgbaColor {
private:
  API_AF(RgbaColor, u8, red, 0);
  API_AF(RgbaColor, u8, green, 0);
  API_AF(RgbaColor, u8, blue, 0);
  API_AF(RgbaColor, u8, alpha, 0);
};

enum class EventType {
  null = SDL_FIRSTEVENT,
  quit = SDL_QUIT,
  app_terminating = SDL_APP_TERMINATING,
  app_low_memory = SDL_APP_LOWMEMORY,
  app_will_enter_background = SDL_APP_WILLENTERBACKGROUND,
  app_did_enter_background = SDL_APP_DIDENTERBACKGROUND,
  app_will_enter_foreground = SDL_APP_WILLENTERFOREGROUND,
  app_did_enter_foreground = SDL_APP_DIDENTERFOREGROUND,
  locale_changed = SDL_LOCALECHANGED,
  display = SDL_DISPLAYEVENT,
  window = SDL_WINDOWEVENT,
  system_wm = SDL_SYSWMEVENT,
  key_down = SDL_KEYDOWN,
  key_up = SDL_KEYUP,
  text_editing = SDL_TEXTEDITING,
  text_input = SDL_TEXTINPUT,
  key_map_changed = SDL_KEYMAPCHANGED,
  mouse_motion = SDL_MOUSEMOTION,
  mouse_button_down = SDL_MOUSEBUTTONDOWN,
  mouse_button_up = SDL_MOUSEBUTTONUP,
  mouse_wheel = SDL_MOUSEWHEEL,
  joy_axis_motion = SDL_JOYAXISMOTION,
  joy_ball_motion = SDL_JOYBALLMOTION,
  joy_hat_motion = SDL_JOYHATMOTION,
  joy_button_motion = SDL_JOYBUTTONDOWN,
  joy_button_up = SDL_JOYBUTTONUP,
  joy_device_added = SDL_JOYDEVICEADDED,
  joy_device_removed = SDL_JOYDEVICEREMOVED,
  controller_axis_motion = SDL_CONTROLLERAXISMOTION,
  controller_button_down = SDL_CONTROLLERBUTTONDOWN,
  controller_button_up = SDL_CONTROLLERBUTTONUP,
  controller_device_added = SDL_CONTROLLERDEVICEADDED,
  controller_device_removed = SDL_CONTROLLERDEVICEREMOVED,
  controller_device_mapped = SDL_CONTROLLERDEVICEREMAPPED,
  controller_touchpad_down = SDL_CONTROLLERTOUCHPADDOWN,
  controller_touchpad_motion = SDL_CONTROLLERTOUCHPADMOTION,
  controller_touchpad_up = SDL_CONTROLLERTOUCHPADUP,
  controller_sensor_update = SDL_CONTROLLERSENSORUPDATE,
  finger_down = SDL_FINGERDOWN,
  finger_up = SDL_FINGERUP,
  finger_motion = SDL_FINGERMOTION,
  dollar_gesture = SDL_DOLLARGESTURE,
  dollar_record = SDL_DOLLARRECORD,
  multi_gesture = SDL_MULTIGESTURE,
  clipboard_update = SDL_CLIPBOARDUPDATE,
  drop_file = SDL_DROPFILE,
  drop_text = SDL_DROPTEXT,
  drop_begin = SDL_DROPBEGIN,
  drop_complete = SDL_DROPCOMPLETE,
  audio_device_added = SDL_AUDIODEVICEADDED,
  audio_device_removed = SDL_AUDIODEVICEREMOVED,
  sensor_update = SDL_SENSORUPDATE,
  render_targets_reset = SDL_RENDER_TARGETS_RESET,
  render_device_reset = SDL_RENDER_DEVICE_RESET,
  // poll_sentinel = SDL_POLLSENTINEL,
  user = SDL_USEREVENT,
  last = SDL_LASTEVENT
};

#if defined __macosx
#define KEY_MODIFIER_LEFT_META KMOD_LCTRL
#define KEY_MODIFIER_RIGHT_META KMOD_RCTRL
#define KEY_MODIFIER_META KMOD_CTRL
#define KEY_MODIFIER_LEFT_CONTROL KMOD_LGUI
#define KEY_MODIFIER_RIGHT_CONTROL KMOD_RGUI
#define KEY_MODIFIER_CONTROL KMOD_GUI
#else
#define KEY_MODIFIER_LEFT_META KMOD_LGUI
#define KEY_MODIFIER_RIGHT_META KMOD_RGUI
#define KEY_MODIFIER_META KMOD_GUI
#define KEY_MODIFIER_LEFT_CONTROL KMOD_LCTRL
#define KEY_MODIFIER_RIGHT_CONTROL KMOD_RCTRL
#define KEY_MODIFIER_CONTROL KMOD_CTRL
#endif

enum class KeyModifier {
  none = KMOD_NONE,
  left_shift = KMOD_LSHIFT,
  right_shift = KMOD_RSHIFT,
  left_control = KEY_MODIFIER_LEFT_CONTROL,
  right_control = KEY_MODIFIER_RIGHT_CONTROL,
  left_alt = KMOD_LALT,
  right_alt = KMOD_RALT,
  left_meta = KEY_MODIFIER_LEFT_META,
  right_meta = KEY_MODIFIER_RIGHT_META,
  number_lock = KMOD_NUM,
  caps_lock = KMOD_CAPS,
  mode = KMOD_MODE,
  control = KEY_MODIFIER_CONTROL,
  shift = KMOD_SHIFT,
  alt = KMOD_ALT,
  meta = KEY_MODIFIER_META,
};

enum class ScanCode {
  unknown = SDL_SCANCODE_UNKNOWN,
  a = SDL_SCANCODE_A,
  b = SDL_SCANCODE_B,
  c = SDL_SCANCODE_C,
  d = SDL_SCANCODE_D,
  e = SDL_SCANCODE_E,
  f = SDL_SCANCODE_F,
  g = SDL_SCANCODE_G,
  h = SDL_SCANCODE_H,
  i = SDL_SCANCODE_I,
  j = SDL_SCANCODE_J,
  k = SDL_SCANCODE_K,
  l = SDL_SCANCODE_L,
  m = SDL_SCANCODE_M,
  n = SDL_SCANCODE_N,
  o = SDL_SCANCODE_O,
  p = SDL_SCANCODE_P,
  q = SDL_SCANCODE_Q,
  r = SDL_SCANCODE_R,
  s = SDL_SCANCODE_S,
  t = SDL_SCANCODE_T,
  u = SDL_SCANCODE_U,
  v = SDL_SCANCODE_V,
  w = SDL_SCANCODE_W,
  x = SDL_SCANCODE_X,
  y = SDL_SCANCODE_Y,
  z = SDL_SCANCODE_Z,
  x1 = SDL_SCANCODE_1,
  x2 = SDL_SCANCODE_2,
  x3 = SDL_SCANCODE_3,
  x4 = SDL_SCANCODE_4,
  x5 = SDL_SCANCODE_5,
  x6 = SDL_SCANCODE_6,
  x7 = SDL_SCANCODE_7,
  x8 = SDL_SCANCODE_8,
  x9 = SDL_SCANCODE_9,
  x0 = SDL_SCANCODE_0,
  return_ = SDL_SCANCODE_RETURN,
  escape = SDL_SCANCODE_ESCAPE,
  backspace = SDL_SCANCODE_BACKSPACE,
  tab = SDL_SCANCODE_TAB,
  space = SDL_SCANCODE_SPACE,
  minus = SDL_SCANCODE_MINUS,
  equals = SDL_SCANCODE_EQUALS,
  left_bracket = SDL_SCANCODE_LEFTBRACKET,
  right_bracket = SDL_SCANCODE_RIGHTBRACKET,
  backslash = SDL_SCANCODE_BACKSLASH,
  non_us_hash = SDL_SCANCODE_NONUSHASH,
  semicolon = SDL_SCANCODE_SEMICOLON,
  apostrophe = SDL_SCANCODE_APOSTROPHE,
  grave = SDL_SCANCODE_GRAVE,
  comma = SDL_SCANCODE_COMMA,
  period = SDL_SCANCODE_PERIOD,
  slash = SDL_SCANCODE_SLASH,
  caps_lock = SDL_SCANCODE_CAPSLOCK,
  f1 = SDL_SCANCODE_F1,
  f2 = SDL_SCANCODE_F2,
  f3 = SDL_SCANCODE_F3,
  f4 = SDL_SCANCODE_F4,
  f5 = SDL_SCANCODE_F5,
  f6 = SDL_SCANCODE_F6,
  f7 = SDL_SCANCODE_F7,
  f8 = SDL_SCANCODE_F8,
  f9 = SDL_SCANCODE_F9,
  f10 = SDL_SCANCODE_F10,
  f11 = SDL_SCANCODE_F11,
  f12 = SDL_SCANCODE_F12,
  print_screen = SDL_SCANCODE_PRINTSCREEN,
  scroll_lock = SDL_SCANCODE_SCROLLLOCK,
  pause = SDL_SCANCODE_PAUSE,
  insert = SDL_SCANCODE_INSERT,
  home = SDL_SCANCODE_HOME,
  page_up = SDL_SCANCODE_PAGEUP,
  delete_ = SDL_SCANCODE_DELETE,
  end = SDL_SCANCODE_END,
  page_down = SDL_SCANCODE_PAGEDOWN,
  right = SDL_SCANCODE_RIGHT,
  left = SDL_SCANCODE_LEFT,
  down = SDL_SCANCODE_DOWN,
  up = SDL_SCANCODE_UP,
  number_lock_clear = SDL_SCANCODE_NUMLOCKCLEAR,
  keypad_divide = SDL_SCANCODE_KP_DIVIDE,
  keypad_multiply = SDL_SCANCODE_KP_MULTIPLY,
  keypad_minus = SDL_SCANCODE_KP_MINUS,
  keypad_plus = SDL_SCANCODE_KP_PLUS,
  keypad_enter = SDL_SCANCODE_KP_ENTER,
  keypad_1 = SDL_SCANCODE_KP_1,
  keypad_2 = SDL_SCANCODE_KP_2,
  keypad_3 = SDL_SCANCODE_KP_3,
  keypad_4 = SDL_SCANCODE_KP_4,
  keypad_5 = SDL_SCANCODE_KP_5,
  keypad_6 = SDL_SCANCODE_KP_6,
  keypad_7 = SDL_SCANCODE_KP_7,
  keypad_8 = SDL_SCANCODE_KP_8,
  keypad_9 = SDL_SCANCODE_KP_9,
  keypad_0 = SDL_SCANCODE_KP_0,
  keypad_period = SDL_SCANCODE_KP_PERIOD,
  non_us_backslash = SDL_SCANCODE_NONUSBACKSLASH,
  application = SDL_SCANCODE_APPLICATION,
  power = SDL_SCANCODE_POWER,
  keypad_equals = SDL_SCANCODE_KP_EQUALS,
  f13 = SDL_SCANCODE_F13,
  f14 = SDL_SCANCODE_F14,
  f15 = SDL_SCANCODE_F15,
  f16 = SDL_SCANCODE_F16,
  f17 = SDL_SCANCODE_F17,
  f18 = SDL_SCANCODE_F18,
  f19 = SDL_SCANCODE_F19,
  f20 = SDL_SCANCODE_F20,
  f21 = SDL_SCANCODE_F21,
  f22 = SDL_SCANCODE_F22,
  f23 = SDL_SCANCODE_F23,
  f24 = SDL_SCANCODE_F24,
  execute = SDL_SCANCODE_EXECUTE,
  help = SDL_SCANCODE_HELP,
  menu = SDL_SCANCODE_MENU,
  select = SDL_SCANCODE_SELECT,
  stop = SDL_SCANCODE_STOP,
  again = SDL_SCANCODE_AGAIN,
  undo = SDL_SCANCODE_UNDO,
  cut = SDL_SCANCODE_CUT,
  copy = SDL_SCANCODE_COPY,
  paste = SDL_SCANCODE_PASTE,
  find = SDL_SCANCODE_FIND,
  mute = SDL_SCANCODE_MUTE,
  volume_up = SDL_SCANCODE_VOLUMEUP,
  volume_down = SDL_SCANCODE_VOLUMEDOWN,
  /* not sure whether there's a reason to enable these */
  /*  value =   value =  SDL_SCANCODE_LOCKINGCAPSLOCK ,  value = */
  /*  value =   value =  SDL_SCANCODE_LOCKINGNUMLOCK , */
  /*  value =   value =  SDL_SCANCODE_LOCKINGSCROLLLOCK , */
  keypad_comma = SDL_SCANCODE_KP_COMMA,
  keypad_equals_as_400 = SDL_SCANCODE_KP_EQUALSAS400,
  international1 = SDL_SCANCODE_INTERNATIONAL1,
  international2 = SDL_SCANCODE_INTERNATIONAL2,
  international3 = SDL_SCANCODE_INTERNATIONAL3,
  international4 = SDL_SCANCODE_INTERNATIONAL4,
  international5 = SDL_SCANCODE_INTERNATIONAL5,
  international6 = SDL_SCANCODE_INTERNATIONAL6,
  international7 = SDL_SCANCODE_INTERNATIONAL7,
  international8 = SDL_SCANCODE_INTERNATIONAL8,
  international9 = SDL_SCANCODE_INTERNATIONAL9,
  language1 = SDL_SCANCODE_LANG1,
  language2 = SDL_SCANCODE_LANG2,
  language3 = SDL_SCANCODE_LANG3,
  language4 = SDL_SCANCODE_LANG4,
  language5 = SDL_SCANCODE_LANG5,
  language6 = SDL_SCANCODE_LANG6,
  language7 = SDL_SCANCODE_LANG7,
  language8 = SDL_SCANCODE_LANG8,
  language9 = SDL_SCANCODE_LANG9,
  alt_erase = SDL_SCANCODE_ALTERASE,
  system_request = SDL_SCANCODE_SYSREQ,
  cancel = SDL_SCANCODE_CANCEL,
  clear = SDL_SCANCODE_CLEAR,
  prior = SDL_SCANCODE_PRIOR,
  return2 = SDL_SCANCODE_RETURN2,
  separator = SDL_SCANCODE_SEPARATOR,
  out = SDL_SCANCODE_OUT,
  oper = SDL_SCANCODE_OPER,
  clear_again = SDL_SCANCODE_CLEARAGAIN,
  cr_sel = SDL_SCANCODE_CRSEL,
  ex_sel = SDL_SCANCODE_EXSEL,
  keypad_00 = SDL_SCANCODE_KP_00,
  keypad_000 = SDL_SCANCODE_KP_000,
  thousands_separator = SDL_SCANCODE_THOUSANDSSEPARATOR,
  decimal_separator = SDL_SCANCODE_DECIMALSEPARATOR,
  currency_unit = SDL_SCANCODE_CURRENCYUNIT,
  currency_subunit = SDL_SCANCODE_CURRENCYSUBUNIT,
  left_parenthesis = SDL_SCANCODE_KP_LEFTPAREN,
  right_parenthesis = SDL_SCANCODE_KP_RIGHTPAREN,
  left_brace = SDL_SCANCODE_KP_LEFTBRACE,
  right_brace = SDL_SCANCODE_KP_RIGHTBRACE,
  keypad_tab = SDL_SCANCODE_KP_TAB,
  keypad_backspace = SDL_SCANCODE_KP_BACKSPACE,
  keypad_a = SDL_SCANCODE_KP_A,
  keypad_b = SDL_SCANCODE_KP_B,
  keypad_c = SDL_SCANCODE_KP_C,
  keypad_d = SDL_SCANCODE_KP_D,
  keypad_e = SDL_SCANCODE_KP_E,
  keypad_f = SDL_SCANCODE_KP_F,
  keypad_xor = SDL_SCANCODE_KP_XOR,
  keypad_power = SDL_SCANCODE_KP_POWER,
  keypad_percent = SDL_SCANCODE_KP_PERCENT,
  keypad_less = SDL_SCANCODE_KP_LESS,
  keypad_greater = SDL_SCANCODE_KP_GREATER,
  keypad_ampersand = SDL_SCANCODE_KP_AMPERSAND,
  keypad_double_ampersand = SDL_SCANCODE_KP_DBLAMPERSAND,
  keypad_vertical_bar = SDL_SCANCODE_KP_VERTICALBAR,
  keypad_double_vertical_bar = SDL_SCANCODE_KP_DBLVERTICALBAR,
  keypad_colon = SDL_SCANCODE_KP_COLON,
  keypad_hash = SDL_SCANCODE_KP_HASH,
  keypad_space = SDL_SCANCODE_KP_SPACE,
  keypad_at = SDL_SCANCODE_KP_AT,
  keypad_exclamation = SDL_SCANCODE_KP_EXCLAM,
  keypad_memory_store = SDL_SCANCODE_KP_MEMSTORE,
  keypad_memory_recall = SDL_SCANCODE_KP_MEMRECALL,
  keypad_memory_clear = SDL_SCANCODE_KP_MEMCLEAR,
  keypad_memory_add = SDL_SCANCODE_KP_MEMADD,
  keypad_memory_subtract = SDL_SCANCODE_KP_MEMSUBTRACT,
  keypad_memory_mutiply = SDL_SCANCODE_KP_MEMMULTIPLY,
  keypad_memory_divide = SDL_SCANCODE_KP_MEMDIVIDE,
  keypad_plus_minus = SDL_SCANCODE_KP_PLUSMINUS,
  keypad_clear = SDL_SCANCODE_KP_CLEAR,
  keypad_clear_entry = SDL_SCANCODE_KP_CLEARENTRY,
  keypad_binary = SDL_SCANCODE_KP_BINARY,
  keypad_octal = SDL_SCANCODE_KP_OCTAL,
  keypad_decimal = SDL_SCANCODE_KP_DECIMAL,
  keypad_hexadecimal = SDL_SCANCODE_KP_HEXADECIMAL,
  left_control = SDL_SCANCODE_LCTRL,
  left_shift = SDL_SCANCODE_LSHIFT,
  left_alt = SDL_SCANCODE_LALT,
  left_meta = SDL_SCANCODE_LGUI,
  right_control = SDL_SCANCODE_RCTRL,
  right_shift = SDL_SCANCODE_RSHIFT,
  right_alt = SDL_SCANCODE_RALT,
  right_meta = SDL_SCANCODE_RGUI,
  mode = SDL_SCANCODE_MODE,
  audio_next = SDL_SCANCODE_AUDIONEXT,
  audio_previous = SDL_SCANCODE_AUDIOPREV,
  audio_stop = SDL_SCANCODE_AUDIOSTOP,
  audio_play = SDL_SCANCODE_AUDIOPLAY,
  audio_mute = SDL_SCANCODE_AUDIOMUTE,
  media_select = SDL_SCANCODE_MEDIASELECT,
  www = SDL_SCANCODE_WWW,
  mail = SDL_SCANCODE_MAIL,
  calculator = SDL_SCANCODE_CALCULATOR,
  computer = SDL_SCANCODE_COMPUTER,
  ac_search = SDL_SCANCODE_AC_SEARCH,
  ac_home = SDL_SCANCODE_AC_HOME,
  ac_back = SDL_SCANCODE_AC_BACK,
  ac_forward = SDL_SCANCODE_AC_FORWARD,
  ac_stop = SDL_SCANCODE_AC_STOP,
  ac_refresh = SDL_SCANCODE_AC_REFRESH,
  ac_bookmarks = SDL_SCANCODE_AC_BOOKMARKS,
  brightness_down = SDL_SCANCODE_BRIGHTNESSDOWN,
  brightness_up = SDL_SCANCODE_BRIGHTNESSUP,
  display_switch = SDL_SCANCODE_DISPLAYSWITCH,
  kb_dillum_toggle = SDL_SCANCODE_KBDILLUMTOGGLE,
  kb_dillum_down = SDL_SCANCODE_KBDILLUMDOWN,
  kb_dillum_up = SDL_SCANCODE_KBDILLUMUP,
  eject = SDL_SCANCODE_EJECT,
  sleep = SDL_SCANCODE_SLEEP,
  app1 = SDL_SCANCODE_APP1,
  app2 = SDL_SCANCODE_APP2,
  audio_rewind = SDL_SCANCODE_AUDIOREWIND,
  audio_fash_forward = SDL_SCANCODE_AUDIOFASTFORWARD,
  scancodes = SDL_NUM_SCANCODES
};

API_OR_ENUM_CLASS(KeyModifier)

template <typename NativeType>
class NativeValue : public api::ExecutionContext {
public:
  NativeValue() = default;
  NativeValue(const NativeType &value) : m_native_value{value} {}

  NativeType *native_value() { return &m_native_value; }

  const NativeType *native_value() const { return &m_native_value; }

protected:
  NativeType m_native_value{};
};

template <typename NativeType>
class NativePointer : public api::ExecutionContext {
public:

  NativeType *native_value() { return m_native_pointer; }

  const NativeType *native_value() const { return m_native_pointer; }

protected:
  void set_native_value(NativeType *value) { m_native_pointer = value; }
  void swap(NativePointer & a){
    std::swap(m_native_pointer, a.m_native_pointer);
  }
  NativeType *m_native_pointer = nullptr;
};

template <typename NativeType>
class NativeConstPointer : public api::ExecutionContext {
public:
  const NativeType *native_value() const { return m_native_pointer; }

protected:
  NativeConstPointer(const NativeType *value) : m_native_pointer(value) {}
  void set_native_value(const NativeType *value) { m_native_pointer = value; }

  const NativeType *m_native_pointer = nullptr;
};

class Rectangle : public NativeValue<SDL_Rect> {
public:
  Rectangle() = default;
  Rectangle(const Point &point, const Size &size)
    : NativeValue({point.x(), point.y(), size.width(), size.height()}) {}
  int x() const { return native_value()->x; }
  int y() const { return native_value()->y; }
  int width() const { return native_value()->w; }
  int height() const { return native_value()->h; }
};

} // namespace window

#endif // WINDOWAPI_WINDOW_TYPES_HPP
