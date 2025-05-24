#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity(float x = 0, float y = 0)
        : m_Position(x, y), m_Velocity(0.f, 0.f) {
    }

    virtual void Update(float dt, const sf::RenderWindow& window) = 0;
    virtual void Render(sf::RenderWindow& window) = 0;

    virtual ~Entity() = default;

protected:
    sf::Vector2f m_Position;
    sf::Vector2f m_Velocity;
};