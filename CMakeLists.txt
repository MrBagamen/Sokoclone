cmake_minimum_required(VERSION 2.8)

project(Sokoclone)

include_directories(include)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions("-std=c++11 -pedantic -Wall -Wextra")
endif ()

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})

add_executable(Sokoclone
include/map.hpp
include/player.hpp
include/wall.hpp
include/entity.hpp
src/main.cpp
src/map.cpp
src/player.cpp
src/wall.cpp
src/entity.cpp
)

target_link_libraries(Sokoclone ${SFML_LIBRARIES} ${OPENGL_LIBRARY})
