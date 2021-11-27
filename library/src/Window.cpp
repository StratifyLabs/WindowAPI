
#include <SDL.h>

#include "window/Window.hpp"


using namespace window;

bool Window::m_is_initialized = false;

Window::Window(const char * title, const Point & location, const Size & size, const Flags flags){
  if( m_is_initialized == false ){
    SDL_Init(SDL_INIT_VIDEO);
  }

  auto * result = SDL_CreateWindow(title, location.x(), location.y(), size.width(), size.height(), u32(flags));

  if( result == nullptr ){
    API_RETURN_ASSIGN_ERROR(SDL_GetError(), EINVAL);
  }

  printf("window native:%p\n", result);
  set_native_value(result);
}

Window::~Window(){
  if( native_value() ){
    SDL_DestroyWindow(native_value());
  }
}