project(logic_lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(logic_lib SHARED
	enemy.cpp
	game_logic.cpp
	missile.cpp
	score_loader.cpp
	vocabulary.cpp
)

target_include_directories(logic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

