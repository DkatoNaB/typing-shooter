//
//  Menu.cpp
//  TypingShooter
//
//  Created by Daniel Eke on 2015. 03. 16..
//  Copyright (c) 2015. elte. All rights reserved.
//

#include "Menu.h"


Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }
    
    sf::FloatRect textRect;
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    textRect = menu[0].getLocalBounds();
    menu[0].setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Options");
    textRect = menu[1].getLocalBounds();
    menu[1].setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    
    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    textRect = menu[2].getLocalBounds();
    menu[2].setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    
    selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}