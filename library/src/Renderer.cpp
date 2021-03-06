#include "window/Renderer.hpp"
#include "window/Texture.hpp"

using namespace window;

Renderer::Renderer(Window &window, int index, Renderer::Flags flags)
  : NativePointer(
    SDL_CreateRenderer(window.native_value(), index, u32(flags)),
    &RendererDeleter::deleter) {}

Renderer &Renderer::set_target(Texture &texture) {
  SDL_SetRenderTarget(native_value(), texture.native_value());
  return *this;
}

Renderer &Renderer::clear_target() {
  SDL_SetRenderTarget(native_value(), nullptr);
  return *this;
}

Renderer &Renderer::copy(Texture &texture) {
  SDL_RenderCopy(native_value(), texture.native_value(), nullptr, nullptr);
  return *this;
}

Renderer &Renderer::copy(Texture &texture, const Renderer::Copy &options) {
  SDL_RenderCopy(
    native_value(),
    texture.native_value(),
    options.source().native_value(),
    options.destination().native_value());
  return *this;
}
