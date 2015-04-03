#include <SFML/Graphics.hpp>
#include "GUI/Menu.h"
#include "GUI/GameView.h"
#include <iostream>


int main()
{
    // TODO: global méretből!
    sf::RenderWindow window(sf::VideoMode(800, 600), "Typing Shooter");
    
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);
    window.setKeyRepeatEnabled(false);
    
    Menu menu(window.getSize().x, window.getSize().y);
    GameView currentGameView = GameView(window.getSize().x, window.getSize().y);
    bool gameRunning = false;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;
                        
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;
                        
                    case sf::Keyboard::Escape:
                        gameRunning = !gameRunning;
                        break;
                        
                    case sf::Keyboard::Return:
                        switch (menu.GetPressedItem())
                    {
                        case 0:
                            std::cout << "Play button has been pressed" << std::endl;
                            gameRunning = true;
                            break;
                        case 1:
                            std::cout << "Option button has been pressed" << std::endl;
                            break;
                        case 2:
                            window.close();
                            break;
                    }
                        
                        break;
                }
                    break;
                    
                case sf::Event::TextEntered:{
                    if (event.text.unicode < 128){
                        char c = tolower((char)event.text.unicode);
                        currentGameView.l->shoot(c);
                        std::cout << c;
                    }
                    
                }
                    break;
                    
                case sf::Event::Closed:
                    window.close();
                    
                    break;
                    
            }
        }
        
        window.clear();
        
        if(gameRunning){
            currentGameView.draw(window);
        }else{
            menu.draw(window);
        }
        
        window.display();
    }
    
    return 0;
}