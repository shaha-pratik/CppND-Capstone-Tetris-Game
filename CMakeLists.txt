cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall -lncurses")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Tetris)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(TetrisGame src/main.cpp src/piece.cpp src/renderer.cpp src/board.cpp src/game.cpp src/controller.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(TetrisGame ${SDL2_LIBRARIES})

add_subdirectory(thirdparty/googletest)
add_executable(test test/test.cpp src/piece.cpp)

target_link_libraries(test gtest_main )