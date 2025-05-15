#include <SFML/Graphics.hpp>
#include "square.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    square rect(100, 100);
    sf::RectangleShape shape(sf::Vector2(rect.getHeight(), rect.getWidth()));
    shape.setFillColor(sf::Color(100, 100, 100));

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}