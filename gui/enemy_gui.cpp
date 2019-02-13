#include "enemy_gui.h"

EnemyGUI::EnemyGUI(Enemy &enemy)
{
	this->enemy = &enemy;
	//body.setFillColor(sf::Color::Red);
	body.setSize(sf::Vector2f(14, 14));
	body.setOrigin(7, 7);
	body.setPosition(sf::Vector2f(enemy.getPosition().getX(), enemy.getPosition().getY()));
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Resources/Sprites/enemy.png");
	body.setTexture(texture);
	
	sf::Font* f = new sf::Font();
	f->loadFromFile("Resources/Fonts/Ubuntu-Regular.ttf");
	text = new sf::Text(enemy.getText(),*f);
	text->setColor(sf::Color::White);
	text->setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x, body.getPosition().y));
	text->setCharacterSize(15);
	text->setStyle(sf::Text::Style::Bold);

    rotateSpeed = (std::rand() % 50) + 30;
}

void EnemyGUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(body,states);
	target.draw(*text,states);
}

void EnemyGUI::setPosition(sf::Vector2f position)
{
	body.setPosition(position);
	text->setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x + 1, body.getPosition().y - body.getSize().y/2- text->getLocalBounds().top));
    body.setRotation(body.getRotation()+rotateSpeed*0.1);
}

void EnemyGUI::setAsTarget()
{
	text->setColor(sf::Color::Red);
}

void EnemyGUI::updateText()
{
	text->setString(enemy->getText());
}
