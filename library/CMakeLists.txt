
set(LIBRARIES ThreadAPI FsAPI ChronoAPI VarAPI lvgl)

api_add_api_library(WindowAPI "${LIBRARIES}")

function(add_sdl_libraries CONFIG)

  ExternalProject_Get_Property(sdl INSTALL_DIR)
  message(STATUS "SDL Install directory is ${INSTALL_DIR}")

  set(TARGET WindowAPI_${CONFIG}_link)
  add_dependencies(${TARGET} sdl)

  target_link_libraries(${TARGET}
    PUBLIC
    ${INSTALL_DIR}/lib/libSDL2.a
    )

  target_include_directories(${TARGET}
    PUBLIC
    $<BUILD_INTERFACE:${INSTALL_DIR}/include/SDL2>
    )

  target_compile_definitions(${TARGET}
    PUBLIC
    SDL_IS_AVAILABLE=1
    )

endfunction()

add_sdl_libraries(release)
add_sdl_libraries(debug)



