cmake_minimum_required(VERSION 3.10)
project(typing-shooter)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(sources
	game.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(logic)
#add_subdirectory(gui)
#target_sources(typing-shooter PUBLIC game.cpp) 
#add_dependencies(typing-shooter logic)
#target_link_libraries(typing-shooter logic)
add_executable(typing-shooter game.cpp)
