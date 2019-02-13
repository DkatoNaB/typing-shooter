#include "missile_gui.h"

MissileGUI::MissileGUI(Missile &missile)
{
	this->missile = &missile;
	//body.setFillColor(sf::Color::Red);
	body.setSize(sf::Vector2f(10, 10));
	body.setOrigin(5, 5);
	body.setPosition(sf::Vector2f(missile.getPosition().getX(), missile.getPosition().getY()));
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Resources/Sprites/missile.png");
	body.setTexture(texture);

}

void MissileGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
//void MissileGUI::draw(sf::RenderWindow& window)
{
	target.draw(body, states);
//	body.setPosition(missle->getPosition().getX(), missle->getPosition().getY());
//	window.draw(body);
}

void MissileGUI::setPosition(sf::Vector2f position)
{
	body.setPosition(position);
}
