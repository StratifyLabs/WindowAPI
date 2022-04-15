

#ifndef WINDOWAPI_WINDOW_RENDERER_HPP
#define WINDOWAPI_WINDOW_RENDERER_HPP

#include <SDL_render.h>

#include <api/api.hpp>

#include "Window.hpp"

namespace window {

class Texture;

class RendererDeleter {
  friend class Renderer;
  static void deleter(SDL_Renderer *value) {
    if (value) {
      SDL_DestroyRenderer(value);
    }
  }
};

class Renderer
  : public NativePointer<SDL_Renderer, decltype(&RendererDeleter::deleter)> {
public:
  enum class Flags {
    software = SDL_RENDERER_SOFTWARE,
    accelerated = SDL_RENDERER_ACCELERATED,
    prevent_vsync = SDL_RENDERER_PRESENTVSYNC,
    target_texture = SDL_RENDERER_TARGETTEXTURE
  };

  static constexpr int default_index = -1;

  Renderer(Window &window, int index, Flags flags);

  Renderer &set_target(Texture &texture);
  Renderer &clear_target();
  Renderer &clear() {
    SDL_RenderClear(native_value());
    return *this;
  }

  Renderer &set_draw_color(const RgbaColor &color) {
    SDL_SetRenderDrawColor(
      native_value(),
      color.red(),
      color.green(),
      color.blue(),
      color.alpha());
    return *this;
  }

  Renderer &draw_rectangle(const Rectangle &rectangle) {
    SDL_RenderDrawRect(native_value(), rectangle.native_value());
    return *this;
  }

  Renderer &set_clip_rectangle(const Rectangle &rectangle) {
    SDL_RenderSetClipRect(native_value(), rectangle.native_value());
    return *this;
  }

  Renderer &clear_clip_rectangle() {
    SDL_RenderSetClipRect(native_value(), nullptr);
    return *this;
  }

  Renderer &copy(Texture &texture);

  class Copy {
    API_AC(Copy, Rectangle, source);
    API_AC(Copy, Rectangle, destination);
  };

  Renderer &copy(Texture &texture, const Copy &options);

  Renderer &present() {
    SDL_RenderPresent(native_value());
    return *this;
  }

private:
  friend class Texture;
};

} // namespace window

#endif // WINDOWAPI_WINDOW_RENDERER_HPP
