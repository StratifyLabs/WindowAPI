//
// Created by Tyler Gilbert on 11/24/21.
//

#ifndef WINDOWAPI_WINDOW_WINDOW_HPP
#define WINDOWAPI_WINDOW_WINDOW_HPP

#include <api/api.hpp>

#include "Types.hpp"

namespace window {

class WindowDeleter {
  friend class Window;
  static void deleter(SDL_Window *value) {
    if (value) {
      SDL_DestroyWindow(value);
    }
  }
};

class Window
  : public NativePointer<SDL_Window, decltype(&WindowDeleter::deleter)> {
public:
  using Flags = WindowFlags;

  class DisplayMode {
  public:
    DisplayMode() = default;

    API_ACCESS_MEMBER_FUNDAMENTAL_WITH_ALIAS(
      DisplayMode,
      int,
      native_value,
      width,
      w)
    API_ACCESS_MEMBER_FUNDAMENTAL_WITH_ALIAS(
      DisplayMode,
      int,
      native_value,
      height,
      h)

    API_ACCESS_MEMBER_FUNDAMENTAL(DisplayMode, int, native_value, refresh_rate)

    API_ACCESS_MEMBER_FUNDAMENTAL(DisplayMode, u32, native_value, format)

  private:
    SDL_DisplayMode m_native_value{};
  };

  Window(
    const char *title,
    const Point &location,
    const Size &size,
    Flags flags);

  u32 get_id() const { return SDL_GetWindowID(mutable_native_value()); }

  Size get_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowSize(mutable_native_value(), &w, &h);
    return Size(w, h);
  }

  Size get_minimum_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowMinimumSize(mutable_native_value(), &w, &h);
    return Size(w, h);
  }

  Size get_maximum_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowMaximumSize(mutable_native_value(), &w, &h);
    return Size(w, h);
  }

  Point get_position() const {
    int x = 0;
    int y = 0;
    SDL_GetWindowPosition(mutable_native_value(), &x, &y);
    return Point(x, y);
  }

  PixelFormat get_pixel_format() const {
    return PixelFormat(SDL_GetWindowPixelFormat(mutable_native_value()));
  }

  Window &set_position(const Point &point) {
    SDL_SetWindowPosition(native_value(), point.x(), point.y());
    return *this;
  }

  Window &set_size(const Size &size) {
    SDL_SetWindowSize(native_value(), size.width(), size.height());
    return *this;
  }

  Flags get_flags() {
    API_ASSERT(native_value() != nullptr);
    return Flags(SDL_GetWindowFlags(native_value()));
  }

  Window &set_always_on_top(bool value = true) {
    SDL_SetWindowAlwaysOnTop(native_value(), SDL_bool(value));
    return *this;
  }

  Window &set_bordered(bool value = true) {
    SDL_SetWindowBordered(native_value(), SDL_bool(value));
    return *this;
  }

  Window &set_fullscreen(bool value = true) {
    SDL_SetWindowFullscreen(native_value(), SDL_bool(value));
    return *this;
  }

  Window &set_resizeable(bool value = true) {
    SDL_SetWindowResizable(native_value(), SDL_bool(value));
    return *this;
  }

  Window &set_minimum_size(const Size &size) {
    SDL_SetWindowMinimumSize(native_value(), size.width(), size.height());
    return *this;
  }

  Window &set_maximum_size(const Size &size) {
    SDL_SetWindowMaximumSize(native_value(), size.width(), size.height());
    return *this;
  }

  static void enable_drop_file();
  static void disable_drop_file();
  static void show_cursor(bool value = true);

  static constexpr auto opacity_transparent = 0.0f;
  static constexpr auto opacity_opaque = 1.0f;

  Window &set_opacity(float opacity) {
    SDL_SetWindowOpacity(native_value(), opacity);
    return *this;
  }

private:
  friend class Renderer;
};

API_OR_NAMED_FLAGS_OPERATOR(Window, Flags)

} // namespace window

#endif // WINDOWAPI_WINDOW_WINDOW_HPP
