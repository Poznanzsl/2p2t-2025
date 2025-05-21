#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "GameEngine.hpp"
#include <iostream>

Grid gameGrid(20, 20, 30.f, 30.f, -5.f);
Graphics gameGraphics(700.f, 700.f);

int main()
{
    sf::RenderWindow window(sf::VideoMode(gameGraphics.getScreenHeight(), gameGraphics.getScreenWidth()), "SFML works!");

    //define a shape (EXAMPLE)
    sf::RectangleShape gridBG;                                          // Create a shape object 
    gridBG = gameGraphics.newRect(602, 602, sf::Color(64, 67, 78));     // Initialize shape with size and color
    gridBG.setPosition(gameGraphics.setToCenterScreenRect(gridBG));     // Position the shape at the coordinates specified
    gridBG.setOutlineThickness(50.f);                                   // Create an outline for the shape
    gridBG.setOutlineColor(sf::Color(139, 137, 130));                   // Change the outline color
    
    sf::Font scpFont;
    scpFont = gameGraphics.newFont("SCP-black.ttf");
    sf::Text gameName;
    gameName = gameGraphics.newText(scpFont ,"MineSweeper",sf::Color::Black, 50);
    gameName.setPosition(sf::Vector2f(0.5f * gameGraphics.getScreenWidth(), 25.f));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
        {
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(gridBG);
        gameGrid.Draw(window);
        window.draw(gameName);
         window.display();
    }

    return 0;
}