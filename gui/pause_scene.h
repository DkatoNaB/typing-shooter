#ifndef PAUSE_SCENE
#define PAUSE_SCENE

#include "scene.h"
#include <logic/position.h>
#include <vector>
#include <iostream>

/**
@brief Pause Scene
@author Daniel Eke
*/
class PauseScene : public Scene
{	/**
	@brief Runs the scene.
	@param window	The window to run the scene in.
	*/
	int run(sf::RenderWindow &window);
};

#endif
