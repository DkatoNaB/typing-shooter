add_library(gui SHARED
	enemy_gui.cpp
	game_over_scene.cpp
	game_scene.cpp
	main_menu.cpp
	missile_gui.cpp
	pause_scene.cpp
	scene.cpp
	score_scene.cpp
)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(gui
	sfml-graphics
	sfml-audio
)
