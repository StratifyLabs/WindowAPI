
#include "window/Event.hpp"

using namespace window;



Event Event::poll(){
  Event result;
  const auto poll_result = SDL_PollEvent(result.native_value());
  result.m_is_valid = (poll_result == 1);
  return result;
}