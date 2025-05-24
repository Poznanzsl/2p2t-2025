#pragma once

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(const sf::Vector2f& position, const sf::Vector2f& direction);

    void Update(float dt, const sf::RenderWindow& window) override;
    void Render(sf::RenderWindow& window) override;
    bool IsOffscreen(const sf::Vector2u& screenSize) const;

private:
    sf::CircleShape m_Shape;
    sf::Vector2f m_Direction;
    float m_Speed = 500.f;
};