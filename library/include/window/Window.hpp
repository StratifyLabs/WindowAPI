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


  Window& set_size(const Size & size){
    SDL_SetWindowSize(native_value(), size.width(), size.height());
    return *this;
  }

  Flags get_flags() {
    API_ASSERT(native_value() != nullptr);
    return Flags(SDL_GetWindowFlags(native_value()));
  }




  Window &set_minimum_width(u16 value);
  Window &set_minimum_height(u16 value);

  Window &set_width(u16 value);
  Window &set_height(u16 value);



private:
  friend class Renderer;
  static bool m_is_initialized;
};

API_OR_NAMED_FLAGS_OPERATOR(Window,Flags)

} // namespace window

#endif // WINDOWAPI_WINDOW_WINDOW_HPP
