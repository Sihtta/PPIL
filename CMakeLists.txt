cmake_minimum_required(VERSION 3.20)
project(projet_synthese LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(projet_synthese
    app/main.cpp
    ${SOURCES}
)

target_include_directories(projet_synthese PRIVATE include)

if (WIN32)
  target_compile_options(projet_synthese PRIVATE
    "SHELL:-include winsock2.h"
    "SHELL:-include ws2tcpip.h"
  )
  target_link_libraries(projet_synthese PRIVATE ws2_32)
endif()

add_subdirectory(tests)