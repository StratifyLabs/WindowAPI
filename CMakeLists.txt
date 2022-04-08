cmake_minimum_required(VERSION 3.12)

project(WindowAPI CXX)
include(CTest)

include(ExternalProject)

if(SOS_IS_LINUX)
  ExternalProject_Add(sdl
    PREFIX ${SOS_SDK_PATH}
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.0.20
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/SDL/configure --enable-video-kmsdrm --prefix=${SOS_SDK_PATH}
    BUILD_COMMAND make -j4
    INSTALL_COMMAND make install
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL
    )
else()
  ExternalProject_Add(sdl
    PREFIX ${SOS_SDK_PATH}
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-2.0.20
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
    CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=${SOS_SDK_PATH}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL
    )
endif()

add_subdirectory(library library)

option(WINDOW_API_IS_TEST "Enable test builds for WindowAPI" OFF)
if(WINDOW_API_IS_TEST)
  add_subdirectory(tests tests)
endif()

