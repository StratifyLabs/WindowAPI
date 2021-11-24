
#include "SDL.h"

#include "window/Window.hpp"


using namespace window;

bool Window::is_initialized = false;

Window::Window(){
  if( is_initialized == false ){
    SDL_Init(SDL_INIT_VIDEO);
    //SDL_SetEventFilter(quit_filter, NULL);


  }
}