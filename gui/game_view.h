//
//	GameView.h
//	TypingShooter
//
//	Created by Daniel Eke on 2015. 03. 16..
//	Copyright (c) 2015. elte. All rights reserved.
//

#pragma once
#include <logic/game_logic.h>
#include "player_gui.h"
#include "enemy_gui.h"
#include "missile_gui.h"

#include <SFML/Graphics.hpp>
#include <iostream>

class GameView
{
public:
	GameView(float width, float height);
	~GameView();

	Position p = Position(800,600);
	GameLogic *l;// = GameLogic(p);

	void getEnemies(std::vector<EnemyGUI> &enemies, GameLogic &l);
	void draw(sf::RenderWindow &window);
	// private maybe?
	sf::Texture backgroundTexture;
private:
	float backgroundOffset = 0;
	sf::Sprite background;
	std::vector<EnemyGUI> enemies;
	PlayerGUI player;
	sf::Clock deltaClock;
};
