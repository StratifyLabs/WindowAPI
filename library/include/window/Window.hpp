//
// Created by Tyler Gilbert on 11/24/21.
//

#ifndef WINDOWAPI_WINDOW_WINDOW_HPP
#define WINDOWAPI_WINDOW_WINDOW_HPP

#include <api/api.hpp>

#include "Types.hpp"

namespace window {

class Window : public NativePointer<SDL_Window> {
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
    const Size &size, Flags flags);
  ~Window();

  u32 get_id() const {
    return SDL_GetWindowID(m_native_pointer);
  }

  Size get_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowSize(m_native_pointer, &w, &h);
    return Size(w,h);
  }

  Size get_minimum_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowMinimumSize(m_native_pointer, &w, &h);
    return Size(w,h);
  }

  Size get_maximum_size() const {
    int w = 0;
    int h = 0;
    SDL_GetWindowMaximumSize(m_native_pointer, &w, &h);
    return Size(w,h);
  }

  Point get_position() const {
    int x = 0;
    int y = 0;
    SDL_GetWindowPosition(m_native_pointer, &x, &y);
    return Point(x,y);
  }

  PixelFormat get_pixel_format() const {
    return PixelFormat(SDL_GetWindowPixelFormat(m_native_pointer));
  }



  Window& set_position(const Point & point){
    SDL_SetWindowPosition(native_value(), point.x(), point.y());
    return *this;
  }

  Window& set_size(const Size & size){
    SDL_SetWindowSize(native_value(), size.width(), size.height());
    return *this;
  }

  Flags get_flags() {
    API_ASSERT(native_value() != nullptr);
    return Flags(SDL_GetWindowFlags(native_value()));
  }


  Window& set_always_on_top(bool value = true){
    SDL_SetWindowAlwaysOnTop(native_value(), SDL_bool(value));
    return *this;
  }

  Window& set_bordered(bool value = true){
    SDL_SetWindowBordered(native_value(), SDL_bool(value));
    return *this;
  }

  Window& set_fullscreen(bool value = true){
    SDL_SetWindowFullscreen(native_value(), SDL_bool(value));
    return *this;
  }

  Window& set_resizeable(bool value = true){
    SDL_SetWindowResizable(native_value(), SDL_bool(value));
    return *this;
  }

  Window& set_minimum_size(const Size & size){
    SDL_SetWindowMinimumSize(native_value(), size.width(), size.height());
    return *this;
  }

  Window& set_maximum_size(const Size & size){
    SDL_SetWindowMaximumSize(native_value(), size.width(), size.height());
    return *this;
  }

  static constexpr float opacity_transparent = 0.0f;
  static constexpr float opacity_opaque = 1.0f;

  Window& set_opacity(float opacity){
    SDL_SetWindowOpacity(native_value(), opacity);
    return *this;
  }



private:
  friend class Renderer;
  static bool m_is_initialized;
};

API_OR_NAMED_FLAGS_OPERATOR(Window,Flags)

} // namespace window

#endif // WINDOWAPI_WINDOW_WINDOW_HPP
