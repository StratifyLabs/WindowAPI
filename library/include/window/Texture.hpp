

#ifndef WINDOWAPI_WINDOW_TEXTURE_HPP
#define WINDOWAPI_WINDOW_TEXTURE_HPP

#include <SDL_render.h>

#include <api/api.hpp>

#include "Renderer.hpp"

namespace window {

class TextureDeleter {
  friend class Texture;
  static void deleter(SDL_Texture *texture) {
    if (texture) {
      SDL_DestroyTexture(texture);
    }
  }
};

class Texture
  : public NativePointer<SDL_Texture, decltype(&TextureDeleter::deleter)> {
public:
  enum class Access {
    static_ = SDL_TEXTUREACCESS_STATIC,
    streaming = SDL_TEXTUREACCESS_STREAMING,
    target = SDL_TEXTUREACCESS_TARGET
  };

  Texture(
    Renderer &renderer,
    PixelFormat pixel_format,
    Access access,
    const Size &size);

  Texture &update(const Rectangle &rectangle, const void *pixels, int pitch) {
    SDL_UpdateTexture(native_value(), rectangle.native_value(), pixels, pitch);
    return *this;
  }

  Texture &update(const void *pixels, int pitch) {
    SDL_UpdateTexture(native_value(), nullptr, pixels, pitch);
    return *this;
  }

  Texture &set_blend_mode(BlendMode value) {
    SDL_SetTextureBlendMode(native_value(), SDL_BlendMode(value));
    return *this;
  }

  BlendMode get_blend_mode() {
    SDL_BlendMode result;
    SDL_GetTextureBlendMode(native_value(), &result);
    return BlendMode(result);
  }

  const Size &size() const { return m_size; }

private:
  friend class Renderer;
  Size m_size{};
};

} // namespace window

#endif // WINDOWAPI_WINDOW_TEXTURE_HPP
