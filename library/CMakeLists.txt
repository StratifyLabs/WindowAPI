
set(LIBRARIES ThreadAPI FsAPI ChronoAPI VarAPI)

api_add_api_library(WindowAPI "${LIBRARIES}")


ExternalProject_Get_Property(sdl INSTALL_DIR)
include(${INSTALL_DIR}/lib/cmake/SDL2/SDL2Targets.cmake)

function(add_sdl_libraries CONFIG)
  set(TARGET WindowAPI_${CONFIG}_link)
  add_dependencies(${TARGET} sdl)

  target_link_libraries(${TARGET}
    PUBLIC
    SDL2::SDL2-static
    )


endfunction()

add_sdl_libraries(release)
add_sdl_libraries(debug)



