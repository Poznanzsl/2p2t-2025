#include "Bullet.h"

Bullet::Bullet(const sf::Vector2f& position, const sf::Vector2f& direction)
    : Entity(position.x, position.y), m_Direction(direction) {
    m_Shape.setRadius(5.f);
    m_Shape.setFillColor(sf::Color::Yellow);
    m_Shape.setOrigin({ 5.0f, 5.0f });
    m_Shape.setPosition(m_Position);
}

void Bullet::Update(float dt, const sf::RenderWindow& window) {
    m_Position += m_Direction * m_Speed * dt;
    m_Shape.setPosition(m_Position);
}

void Bullet::Render(sf::RenderWindow& window) {
    window.draw(m_Shape);
}

bool Bullet::IsOffscreen(const sf::Vector2u& screenSize) const {
    return m_Position.x < 0 || m_Position.y < 0 ||
        m_Position.x > screenSize.x || m_Position.y > screenSize.y;
}