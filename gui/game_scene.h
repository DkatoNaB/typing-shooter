#ifndef GAMESCENE
#define GAMESCENE

#include "scene.h"
#include "enemy_gui.h"
#include <logic/game_logic.h>

//#include <iostream>
#include <vector>

//TODO inclass //// namespaces
/**
@brief An enum to represent the gamestates.
*/
enum GameState
{
		Running,Paused,NewWave,GameOver
};

/**
@brief Game Scene

@authors Benjamin Ferenc Hajas, Daniel Eke
*/
class GameScene : public Scene
{
public:
	/**
	@brief Runs the scene.
	@param window	The window to run the scene in.
	*/
	int run(sf::RenderWindow &window);

	/**
	@brief Creates bodies for the enemies and puts them in a list.
	@param	enemies	A reference to the list to put the enemies in.
	@param l	A reference to the game's logic.
	*/
	void getEnemies(std::vector<EnemyGUI> &enemies, GameLogic &l);
};

#endif
