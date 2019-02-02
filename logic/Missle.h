//
//  Missle.h
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 04. 03..
//  Copyright (c) 2015. elte. All rights reserved.
//

#pragma once
#include "Position.h"
#include "MissleGUI.h"
#include "Enemy.h"

class MissleGUI;
class Missle
{
public:
    Missle(Position position, Enemy* target, char c);
    ~Missle();
    
    MissleGUI* gui;
    Enemy* target;
    char c;
    
    Position getPosition(){ return position; };
    bool updateWithHitTest(float deltaTime);
private:
    Position position;
};