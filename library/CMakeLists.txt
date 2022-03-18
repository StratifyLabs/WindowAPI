
set(LIBRARIES ThreadAPI FsAPI ChronoAPI VarAPI)

api_add_api_library(WindowAPI "${LIBRARIES}")

ExternalProject_Get_Property(sdl INSTALL_DIR)

set(SDL_CMAKE_TARGETS ${INSTALL_DIR}/lib/cmake/SDL2/SDL2Targets.cmake)
if(EXISTS ${SDL_CMAKE_TARGETS})
  include(${SDL_CMAKE_TARGETS})
else()
  # On windows the cmake files get installed in this cmake folder
  set(SDL_CMAKE_TARGETS ${INSTALL_DIR}/cmake/SDL2Targets.cmake)
  if(EXISTS ${SDL_CMAKE_TARGETS})
    include(${SDL_CMAKE_TARGETS})
  endif()
endif()

function(add_sdl_libraries CONFIG SDL_TARGETS)
  set(TARGET WindowAPI_${CONFIG}_link)
  #add_dependencies(${TARGET} sdl)

  if(EXISTS ${SDL_TARGETS})
    message(STATUS "Using locally built SDL libraries")
    target_link_libraries(${TARGET}
      PUBLIC
      SDL2::SDL2-static
      )
  endif()

  # This is needed to build on RPI
  target_include_directories(${TARGET}
    PUBLIC
    /opt/vc/include
    )

  target_link_directories(${TARGET}
    PUBLIC
    /opt/vc/lib
    )

endfunction()

add_sdl_libraries(release ${SDL_CMAKE_TARGETS})
add_sdl_libraries(debug ${SDL_CMAKE_TARGETS})



