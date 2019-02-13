cmake_minimum_required(VERSION 3.10)
project(typing-shooter)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(logic)
add_subdirectory(gui)
add_executable(typing-shooter game.cpp)

target_link_libraries(typing-shooter logic_lib)
target_link_libraries(typing-shooter gui)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(typing-shooter
	sfml-graphics
	sfml-audio
)
