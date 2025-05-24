#pragma once

#include <SFML/Graphics.hpp>

class GameState {
public:
    virtual void Init() = 0;
    virtual void HandleEvents(sf::RenderWindow& window) = 0;
    virtual void Update(float dt, sf::RenderWindow& window) = 0;
    virtual void Render(sf::RenderWindow& window) = 0;
    virtual void Exit() = 0;

    virtual ~GameState() = default;
};