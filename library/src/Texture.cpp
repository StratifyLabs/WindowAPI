//
// Created by Tyler Gilbert on 11/24/21.
//
#include <window/Texture.hpp>

window::Texture::Texture(
  Renderer &renderer,
  PixelFormat pixel_format,
  window::Texture::Access access,
  const Size &size)
  : NativePointer(
    SDL_CreateTexture(
      renderer.native_value(),
      u32(pixel_format),
      int(access),
      size.width(),
      size.height()),
    &TextureDeleter::deleter), m_size(size) {}
