#include "Enemy.h"


Enemy::Enemy(std::string text,Position &position,Position &playerPosition,int movementSpeed)
{
	dead = false;
	this->text = text;
	this->position = position;
	this->movementSpeed = movementSpeed;
	this->playerPosition = playerPosition;
	setDifficulty();
}

Enemy::Enemy(const Enemy &enemy)
{
	text = enemy.text;
	position = enemy.position;
	movementSpeed = enemy.movementSpeed;
	playerPosition = enemy.playerPosition;
	difficulty = enemy.difficulty;
}

void Enemy::update(float deltaTime)
{
	double length = position.distance(playerPosition);
	double newPositionX = (playerPosition.getX()- position.getX()) / length * deltaTime * movementSpeed;
	double newPositionY = (playerPosition.getY() - position.getY()) / length * deltaTime * movementSpeed;
	position.set(position.getX() + newPositionX, position.getY() + newPositionY);

}

void Enemy::setDifficulty()
{
	int l = text.length();
	if (l <= 5) difficulty = 1;
	else if (l <= 7) difficulty = 2;
	else if (l <= 10) difficulty = 3;
}