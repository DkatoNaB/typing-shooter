//
//  GameView.cpp
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 03. 16..
//  Copyright (c) 2015. elte. All rights reserved.
//

#include "GameView.h"

sf::Texture backgroundTexture;

void getEnemies(std::vector<EnemyGUI> &enemies, GameLogic &l);
GameView::GameView(float width, float height)
{
    p = Position(width, height);
    l = new GameLogic(p);
    l->newGame();
    getEnemies(enemies, *l);
    
    player = PlayerGUI();    
    player.body.setPosition(sf::Vector2f(l->getPlayerPosition().getX(), l->getPlayerPosition().getY()));
    
    backgroundTexture.loadFromFile("stars.png");
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0,0,width,height));  
}


GameView::~GameView()
{
    
}

void GameView::draw(sf::RenderWindow &window)
{
    // TODO: ez kellhet ha engedjük az átméretezést, de inkább ne
    //background.setTextureRect(sf::IntRect(0,0,window.getSize().x,window.getSize().y));
    window.draw(background);
    if (l->isWaveOver()){ l->nextWave(); getEnemies(enemies, *l); }

    for (int i = 0; i < enemies.size(); i++)
    {
        if (!l->getEnemies()[i].isDead()){
            enemies[i].setPosition(sf::Vector2f(l->getEnemies()[i].getPosition().getX(), l->getEnemies()[i].getPosition().getY()));
            window.draw(enemies[i]);
        }
    }

    for (int i = 0; i < l->getMissles().size(); i++)
    {
        Missle missle = l->getMissles()[i];
        if(missle.gui == 0){
           MissleGUI missleGUI = MissleGUI(missle);
            missle.gui = &missleGUI;
        }
        missle.gui->draw(window);
    }
    player.draw(window);
    float deltaTime = deltaClock.getElapsedTime().asSeconds();
    l->update(deltaTime);
    backgroundOffset = fmod((backgroundOffset - deltaTime * 100),backgroundTexture.getSize().y);
    background.setTextureRect(sf::IntRect(0,backgroundOffset,800,600));
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