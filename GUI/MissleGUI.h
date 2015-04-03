//
//  MissleGUI.h
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 04. 03..
//  Copyright (c) 2015. elte. All rights reserved.
//

#pragma once
#include "SFML/Graphics.hpp"
#include "Position.h"
#include "Missle.h"
#include <iostream>

class Missle;
class MissleGUI
{
public:
    MissleGUI(Missle &missle);
    ~MissleGUI();
    sf::Sprite body;
    void draw(sf::RenderWindow &window);
private:
    Missle *missle;
};