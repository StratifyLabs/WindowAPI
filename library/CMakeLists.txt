cmsdk2_check_version(
  NAME API
  VERSION ${API_VERSION}
  MINIMUM_VERSION 1.6.4)

api2_add_library(
  NAME WindowAPI
  DEPENDENCIES ThreadAPI FsAPI ChronoAPI VarAPI)
ExternalProject_Get_Property(sdl INSTALL_DIR)
set(SDL_CMAKE_TARGETS ${INSTALL_DIR}/lib/cmake/SDL2/SDL2staticTargets.cmake)
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
  set(TARGET WindowAPI_${CONFIG}_${CMSDK_ARCH})
  #add_dependencies(${TARGET} sdl)
  if(EXISTS ${SDL_TARGETS})
    message(STATUS "WindowAPI: Using locally built SDL libraries")
    target_link_libraries(${TARGET}
      PUBLIC
      SDL2::SDL2-static)
  else()
    target_include_directories(${TARGET}
      PUBLIC
      $<BUILD_INTERFACE:${CMSDK_LOCAL_PATH}/include/SDL2>
      $<INSTALL_INTERFACE:include/SDL2>)
    target_link_libraries(${TARGET}
      PUBLIC
      ${CMSDK_LOCAL_PATH}/lib/libSDL2.a
      dl)
  endif()
endfunction()
add_sdl_libraries(release ${SDL_CMAKE_TARGETS})
add_sdl_libraries(debug ${SDL_CMAKE_TARGETS})



