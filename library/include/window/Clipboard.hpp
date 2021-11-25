

#ifndef WINDOWAPI_WINDOW_CLIPBOARD_HPP
#define WINDOWAPI_WINDOW_CLIPBOARD_HPP

#include <SDL_render.h>

#include <api/api.hpp>

#include "Window.hpp"

namespace window {

class Clipboard : public api::ExecutionContext {
public:
  Clipboard() : m_text(SDL_GetClipboardText()){}

  ~Clipboard(){
    if( m_text ){
      SDL_free(m_text);
    }
  }

  static bool has_text(){
    return SDL_HasClipboardText();
  }

  static void set_text(const char * text){
    SDL_SetClipboardText(text);
  }

  const char * get_text() const {
    return m_text;
  }

private:
  char * m_text = nullptr;
};


}


#endif // WINDOWAPI_WINDOW_CLIPBOARD_HPP
