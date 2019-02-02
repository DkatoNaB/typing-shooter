//
//  MissleGUI.cpp
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 04. 03..
//  Copyright (c) 2015. elte. All rights reserved.
//

#include "MissleGUI.h"

sf::Texture missleTexture;

MissleGUI::MissleGUI(Missle &missle)
{
    this->missle = &missle;
    missleTexture.loadFromFile("missle.png");
    body.setTexture(missleTexture);
    body.setOrigin(sf::Vector2f(missleTexture.getSize().x/2, missleTexture.getSize().y/2));
}

MissleGUI::~MissleGUI()
{
    
}

void MissleGUI::draw(sf::RenderWindow &window)
{
    body.setPosition(missle->getPosition().getX(), missle->getPosition().getY());
    window.draw(body);
}