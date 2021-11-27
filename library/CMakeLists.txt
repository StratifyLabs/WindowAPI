
set(LIBRARIES ThreadAPI FsAPI ChronoAPI VarAPI)

api_add_api_library(WindowAPI "${LIBRARIES}")

ExternalProject_Get_Property(sdl INSTALL_DIR)

set(SDL_CMAKE_TARGETS ${INSTALL_DIR}/lib/cmake/SDL2/SDL2Targets.cmake)
if(EXISTS ${SDL_CMAKE_TARGETS})
  include(${INSTALL_DIR}/lib/cmake/SDL2/SDL2Targets.cmake)
endif()

function(add_sdl_libraries CONFIG SDL_TARGETS)
  set(TARGET WindowAPI_${CONFIG}_link)
  add_dependencies(${TARGET} sdl)

  if(EXISTS ${SDL_TARGETS})
    target_link_libraries(${TARGET}
      PUBLIC
      SDL2::SDL2-static
      )
  endif()

endfunction()

add_sdl_libraries(release ${SDL_CMAKE_TARGETS})
add_sdl_libraries(debug ${SDL_CMAKE_TARGETS})



