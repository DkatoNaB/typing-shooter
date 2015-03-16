//
//  GameView.cpp
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 03. 16..
//  Copyright (c) 2015. elte. All rights reserved.
//

#include "GameView.h"


void getEnemies(std::vector<EnemyGUI> &enemies, GameLogic &l);
GameView::GameView(float width, float height)
{
	p = Position(width, height);
	l = new GameLogic(p);
    l->newGame();
    getEnemies(enemies, *l);
    player.setSize(sf::Vector2f(10, 10));
    player.setPosition(sf::Vector2f(l->getPlayerPosition().getX(), l->getPlayerPosition().getY()));
    player.setOrigin(sf::Vector2f(5, 5));
    player.setFillColor(sf::Color::Green);
}


GameView::~GameView()
{
    
}

void GameView::draw(sf::RenderWindow &window)
{
    if (l->isWaveOver()){ l->nextWave(); getEnemies(enemies, *l); }
    
    for (int i = 0; i < enemies.size(); i++)
    {
        if (!l->getEnemies()[i].isDead()){
            enemies[i].setPosition(sf::Vector2f(l->getEnemies()[i].getPosition().getX(), l->getEnemies()[i].getPosition().getY()));
            window.draw(enemies[i]);
        }
    }
    window.draw(player);
    l->update(deltaClock.getElapsedTime().asSeconds());
    deltaClock.restart();
}



void getEnemies(std::vector<EnemyGUI> &enemies, GameLogic &l)
{
    enemies.clear();
    for (int i = 0; i < l.getEnemyCount(); i++)
    {
        EnemyGUI e(l.getEnemies()[i]);
        enemies.push_back(e);
    }
}