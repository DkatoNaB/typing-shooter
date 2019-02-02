//
//  GameView.h
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 03. 16..
//  Copyright (c) 2015. elte. All rights reserved.
//

#pragma once
#include "SFML/Graphics.hpp"
#include "GameLogic.h"
#include "PlayerGUI.h"
#include "EnemyGUI.h"
#include "MissleGUI.h"
#include <iostream>

class GameView
{
public:
    GameView(float width, float height);
    ~GameView();

    Position p = Position(800,600);
	GameLogic *l;// = GameLogic(p);

    void draw(sf::RenderWindow &window);
private:
    float
    backgroundOffset = 0;
    sf::Sprite background;
    std::vector<EnemyGUI> enemies;
    PlayerGUI player;
    sf::Clock deltaClock;
};