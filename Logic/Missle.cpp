//
//  Missle.cpp
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 04. 03..
//  Copyright (c) 2015. elte. All rights reserved.
//

#include "Missle.h"

int movementSpeed = 500;
Missle::Missle(Position position, Enemy* target, char c)
{
    this->position = position;
    this->target = target;
    this->c = c;
    this->gui = 0;
}

Missle::~Missle()
{
    
}

bool Missle::updateWithHitTest(float deltaTime)
{
    float length = position.distance(target->getPosition());
    float newPositionX = (target->getPosition().getX()- position.getX()) / length * deltaTime * movementSpeed;
    float newPositionY = (target->getPosition().getY() - position.getY()) / length * deltaTime * movementSpeed;
    position.set(position.getX() + newPositionX, position.getY() + newPositionY);
    if(length < 5){
        return true;
    }else{
        return false;
    }
}
