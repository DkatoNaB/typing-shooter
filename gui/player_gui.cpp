//
//  PlayerGUI.cpp
//  TypingShooter
//
//  Created by Eke Dániel on 2015. 04. 02..
//  Copyright (c) 2015. elte. All rights reserved.
//

#include "PlayerGUI.h"

sf::Texture texture;

PlayerGUI::PlayerGUI()
{
    texture.loadFromFile("player.png");
    body.setTexture(texture);
    body.setOrigin(sf::Vector2f(texture.getSize().x/2, texture.getSize().y/2));
}

PlayerGUI::~PlayerGUI()
{
    
}

void PlayerGUI::draw(sf::RenderWindow &window)
{
    window.draw(body);
}