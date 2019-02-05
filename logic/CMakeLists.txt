include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(logic SHARED
	enemy.cpp
	enemy.h
	game_logic.cpp
	game_logic.h
	missile.cpp
	missile.h
	position.h
	score_loader.cpp
	score_loader.h
	vocabulary.cpp
	vocabulary.h
)
