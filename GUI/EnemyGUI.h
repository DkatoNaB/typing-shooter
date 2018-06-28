#ifndef ENEMYGUI_H
#define ENEMYGUI_H

#include <SFML/Graphics.hpp>
#include "../Logic/Enemy.h"

/**
@brief Body of an enemy
@author Benjamin Ferenc Hajas
*/
class EnemyGUI : public sf::Drawable
{
public:
	/**
	@brief Creates a body for an enemy.
	@param enemy	A reference to an enemy in logic.
	*/
	EnemyGUI(Enemy &enemy);
	/**
	@brief Draws the enemy.
	*/
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	/**
	@brief Changes the position of the enemy.
	@param position	The new position.
	*/
	void setPosition(sf::Vector2f position);
	/**
	@brief Sets the enemy as a target.
	*/
	void setAsTarget();
	/**
	@brief Updates the text of the enemy.
	*/
	void updateText();
protected:
<<<<<<< HEAD
	sf::Sprite body;
=======
	/**
	@brief The body of the enemy.
	*/
	sf::RectangleShape body;
	/**
	@brief Text of the enemy.
	*/
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
	sf::Text* text;
	/**
	@brief The enemy's representation in logic.
	*/
	Enemy* enemy;
    float rotateSpeed;
};

#endif //ENEMYGUI_H