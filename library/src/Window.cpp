
#include <SDL.h>

#include <var/StackString.hpp>

#include "window/Window.hpp"

using namespace window;
using namespace var;

namespace {
bool is_sdl_initialized = false;
}

Window::Window(
  const char *title,
  const Point &location,
  const Size &size,
  const Flags flags)
  : NativePointer(nullptr, &WindowDeleter::deleter) {
  if (!is_sdl_initialized) {
    const auto result = SDL_Init(SDL_INIT_VIDEO);
    if( result < 0 ){
      API_RETURN_ASSIGN_ERROR(StringView("SDL Error ") | SDL_GetError(), EIO);
    }
  }

  auto *result = SDL_CreateWindow(
    title,
    location.x(),
    location.y(),
    size.width(),
    size.height(),
    u32(flags));

  if (result == nullptr) {
    API_RETURN_ASSIGN_ERROR(SDL_GetError(), EINVAL);
  }

  set_native_value(result);
}

void Window::enable_drop_file() {
  SDL_EventState(SDL_DROPBEGIN, SDL_ENABLE);
  SDL_EventState(SDL_DROPCOMPLETE, SDL_ENABLE);
  SDL_EventState(SDL_DROPFILE, SDL_ENABLE);
  SDL_EventState(SDL_DROPTEXT, SDL_ENABLE);
}

void Window::disable_drop_file() {
  SDL_EventState(SDL_DROPBEGIN, SDL_DISABLE);
  SDL_EventState(SDL_DROPCOMPLETE, SDL_DISABLE);
  SDL_EventState(SDL_DROPFILE, SDL_DISABLE);
  SDL_EventState(SDL_DROPTEXT, SDL_DISABLE);
}

void Window::show_cursor(bool value) {
  SDL_ShowCursor(value ? SDL_ENABLE : SDL_DISABLE);
}
