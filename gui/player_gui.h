//
//	PlayerGUI.h
//	TypingShooter
//
//	Created by Eke Dániel on 2015. 04. 02..
//	Copyright (c) 2015. elte. All rights reserved.
//

#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class PlayerGUI
{
public:
	PlayerGUI();
	~PlayerGUI();
	void draw(sf::RenderWindow &window);
	sf::Sprite body;
private:
	sf::Texture texture;
};
