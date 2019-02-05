cmake_minimum_required(VERSION 3.10)
project(typing-shooter)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(sources
	game.cpp)

add_subdirectory(logic)
add_subdirectory(gui)

add_executable(${project_name} ${sources})
