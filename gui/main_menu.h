#ifndef MAIN_MENU
#define MAIN_MENU

#include "scene.h"

/**
@brief Main Menu
@author Daniel Eke
*/

class MainMenu : public Scene
{	/**
	@brief Runs the scene.
	@param window	The window to run the scene in.
	*/
public:
	int run(sf::RenderWindow &window) override;
};

#endif
