cmake_minimum_required(VERSION 3.10)
project(typing-shooter)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(logic)
add_subdirectory(gui)
add_executable(typing-shooter game.cpp)

target_link_libraries(typing-shooter logic)
target_link_libraries(typing-shooter gui)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(typing-shooter
	sfml-graphics
	sfml-audio
)

add_custom_command(TARGET typing-shooter POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/resources
	$<TARGET_FILE_DIR:typing-shooter>/resources
)
