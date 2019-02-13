include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../logic)
add_library(gui SHARED
	enemy_gui.cpp
	game_over_scene.cpp
	game_scene.cpp
	game_view.cpp
	main_menu.cpp
	menu.cpp
	missile_gui.cpp
	pause_scene.cpp
	player_gui.cpp
	scene.cpp
	score_scene.cpp
	)
