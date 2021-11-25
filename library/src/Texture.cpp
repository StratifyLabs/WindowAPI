//
// Created by Tyler Gilbert on 11/24/21.
//
#include <window/Texture.hpp>

window::Texture::Texture(
  Renderer &renderer,
  PixelFormat pixel_format,
  window::Texture::Access access,
  const Size &size) {

  auto * result = SDL_CreateTexture(renderer.native_value(), u32(pixel_format), int(access), size.width(), size.height());
  if( result == nullptr ){
    API_RETURN_ASSIGN_ERROR(SDL_GetError(), EINVAL);
  }

  printf("texture native:%p\n", result);
  set_native_value(result);

}
window::Texture::~Texture() {
  if( native_value() ){
    SDL_DestroyTexture(native_value());
  }
}
