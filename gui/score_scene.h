#ifndef SCORE_SCENE
#define SCORE_SCENE

#include "scene.h"
#include <SFML/Graphics.hpp>

/**
@brief Highscore scene
@author Daniel Eke
*/

class ScoreScene : public Scene
{
	/**
		@brief Runs the scene.
		@param window	The window to run the scene in.
	*/
public:
	int run(sf::RenderWindow &window);
};

#endif
