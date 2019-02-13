#ifndef GAME_OVER_SCENE
#define GAME_OVER_SCENE

#include "scene.h"

/**
@brief Game Over Scene

@authors Daniel Eke, Benjamin Ferenc Hajas
*/
class GameOverScene : public Scene
{
public:
	/**
	@brief Score of the player.
	*/
	int score = 0;
private:
	/**
	@brief Runs the scene.
	@param window	The window to run the scene in.
	*/
	int run(sf::RenderWindow &window);
};
#endif
