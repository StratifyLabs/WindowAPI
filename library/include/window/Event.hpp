//
// Created by Tyler Gilbert on 11/24/21.
//

#ifndef WINDOWAPI_WINDOW_EVENT_HPP
#define WINDOWAPI_WINDOW_EVENT_HPP

#include "Types.hpp"

namespace window {

enum class EventState { pressed = SDL_PRESSED, released = SDL_RELEASED };

template <typename TypeName>
class EventObject : public NativeConstPointer<TypeName> {
public:
  using Type = EventType;
  using State = EventState;

  Type type() const { return Type(this->native_value()->type); }
  u32 timestamp() const { return this->native_value()->timestamp; }
  u32 window_id() const { return this->native_value()->windowID; }

protected:
  EventObject(const TypeName *value) : NativeConstPointer<TypeName>(value) {}
};

class MouseMotionEvent : public EventObject<SDL_MouseMotionEvent> {
public:
  bool is_valid() const { return type() == Type::mouse_motion; }
  u32 which() const { return native_value()->which; }
  Point point() const { return Point(native_value()->x, native_value()->y); }
  Point relative_point() const {
    return Point(native_value()->xrel, native_value()->yrel);
  }

private:
  friend class Event;
  MouseMotionEvent(const SDL_MouseMotionEvent *event) : EventObject(event) {}
};

class MouseWheelEvent : public EventObject<SDL_MouseWheelEvent> {
public:
  enum class Direction {
    normal = SDL_MOUSEWHEEL_NORMAL,
    flipped = SDL_MOUSEWHEEL_FLIPPED
  };

  bool is_valid() const { return type() == Type::mouse_wheel; }
  Direction direction() const { return Direction(native_value()->direction); }
  Point point() const { return Point(native_value()->x, native_value()->y); }

private:
  friend class Event;
  MouseWheelEvent(const SDL_MouseWheelEvent *event) : EventObject(event) {}
};

class MouseButtonEvent : public EventObject<SDL_MouseButtonEvent> {
public:
  bool is_valid() const {
    return type() == Type::mouse_button_up || type() == Type::mouse_button_down;
  }

  State state() const { return State(native_value()->state); }

  u8 clicks() const { return native_value()->clicks; }

  Point point() const { return Point(native_value()->x, native_value()->y); }

private:
  friend class Event;
  MouseButtonEvent(const SDL_MouseButtonEvent *event) : EventObject(event) {}
};

class KeyboardEvent : public EventObject<SDL_KeyboardEvent> {
public:
  bool is_valid() const {
    return type() == Type::key_down || type() == Type::key_up;
  }

  State state() const { return State(native_value()->state); }
  bool is_repeat() const { return native_value()->repeat != 0; }
  ScanCode scan_code() const {
    return ScanCode(native_value()->keysym.scancode);
  }

  KeyModifier modifiers() const {
    return KeyModifier(native_value()->keysym.mod);
  }

  bool is_control() const { return modifiers() & KeyModifier::control; }

  bool is_shift() const { return modifiers() & KeyModifier::shift; }

  bool is_meta() const { return modifiers() & KeyModifier::meta; }

  bool is_alt() const { return modifiers() & KeyModifier::alt; }

  u32 key_code() const { return u32(native_value()->keysym.sym); }

private:
  friend class Event;
  KeyboardEvent(const SDL_KeyboardEvent *event) : EventObject(event) {}
};

class DropEvent : public EventObject<SDL_DropEvent> {
public:
  ~DropEvent() {
    if( is_valid() && native_value() && (type() == Type::drop_file) && native_value()->file ){
      SDL_free(native_value()->file);
    }
  }

  static bool is_valid(Type type){
    if( type == Type::drop_begin ){ return true; }
    if( type == Type::drop_complete ){ return true; }
    if( type == Type::drop_file ){ return true; }
    if( type == Type::drop_text ){ return true; }
    return false;
  }

  bool is_valid() const {
    return is_valid(type());
  }

  const char *path() const { return native_value()->file; }

private:
  friend class Event;
  DropEvent(const SDL_DropEvent *event) : EventObject(event) {}


};

class WindowEvent : public EventObject<SDL_WindowEvent> {
public:
  bool is_valid() const { return type() == Type::window; }

  enum class WindowType {
    none = SDL_WINDOWEVENT_NONE,
    shown = SDL_WINDOWEVENT_SHOWN,
    hidden = SDL_WINDOWEVENT_HIDDEN,
    exposed = SDL_WINDOWEVENT_EXPOSED,
    moved = SDL_WINDOWEVENT_MOVED,
    resized = SDL_WINDOWEVENT_RESIZED,
    size_changed = SDL_WINDOWEVENT_SIZE_CHANGED,
    minimized = SDL_WINDOWEVENT_MINIMIZED,
    maximized = SDL_WINDOWEVENT_MAXIMIZED,
    restored = SDL_WINDOWEVENT_RESTORED,
    enter = SDL_WINDOWEVENT_ENTER,
    leave = SDL_WINDOWEVENT_LEAVE,
    focus_gained = SDL_WINDOWEVENT_FOCUS_GAINED,
    focus_lost = SDL_WINDOWEVENT_FOCUS_LOST,
    close = SDL_WINDOWEVENT_CLOSE,
    take_focus = SDL_WINDOWEVENT_TAKE_FOCUS,
    hit_test = SDL_WINDOWEVENT_HIT_TEST
  };

  WindowType window_type() const { return WindowType(native_value()->event); }

  s32 data1() const { return native_value()->data1; }

  s32 data2() const { return native_value()->data2; }

  Point data_point() const { return Point(data1(), data2()); }

  Size data_size() const { return Size(data1(), data2()); }

private:
  friend class Event;
  WindowEvent(const SDL_WindowEvent *event) : EventObject(event) {}
};

class Event : public NativeValue<SDL_Event> {
public:
  using Type = EventType;
  using State = EventState;

  Type type() const { return Type(native_value()->type); }

  static Event poll();

  bool is_valid() const { return m_is_valid; }

  KeyboardEvent get_keyboard() const {
    auto result = KeyboardEvent(&native_value()->key);
    API_ASSERT(result.is_valid());
    return result;
  }

  MouseButtonEvent get_mouse_button() const {
    auto result = MouseButtonEvent(&native_value()->button);
    API_ASSERT(result.is_valid());
    return result;
  }

  MouseWheelEvent get_mouse_wheel() const {
    auto result = MouseWheelEvent(&native_value()->wheel);
    API_ASSERT(result.is_valid());
    return result;
  }

  MouseMotionEvent get_mouse_motion() const {
    auto result = MouseMotionEvent(&native_value()->motion);
    API_ASSERT(result.is_valid());
    return result;
  }

  WindowEvent get_window() const {
    auto result = WindowEvent(&native_value()->window);
    API_ASSERT(result.is_valid());
    return result;
  }

  DropEvent get_drop() const {
    auto result = DropEvent(&native_value()->drop);
    API_ASSERT(result.is_valid());
    return result;
  }

private:
  bool m_is_valid = false;
};

} // namespace window

#endif // WINDOWAPI_WINDOW_EVENT_HPP
