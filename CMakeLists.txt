cmake_minimum_required(VERSION 3.12)
cmsdk2_minimum_required(2.1.2)
project(WindowAPI
  LANGUAGES CXX
  VERSION 1.0.1)
include(CTest)
include(ExternalProject)
set(SDL_GIT_TAG release-2.24.1)
if(CMSDK_IS_LINUX)
  ExternalProject_Add(sdl
    PREFIX ${CMSDK_LOCAL_PATH}
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG ${SDL_GIT_TAG}
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/SDL/configure --enable-video-kmsdrm --prefix=${CMSDK_LOCAL_PATH} --disable-shared
    BUILD_COMMAND make -j4
    INSTALL_COMMAND make install
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL)
else()
  ExternalProject_Add(sdl
    PREFIX ${CMSDK_LOCAL_PATH}
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG ${SDL_GIT_TAG}
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=${CMSDK_LOCAL_PATH}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL)
endif()
add_subdirectory(library library)
option(WINDOW_API_IS_TEST "Enable test builds for WindowAPI" OFF)
if(WINDOW_API_IS_TEST)
  add_subdirectory(tests tests)
endif()

