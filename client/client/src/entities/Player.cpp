#include "Player.h"
#include <cmath>

Player::Player(float x, float y)
    : Entity(x, y), m_IsSwinging(false), m_SwordCooldown(0), m_GunCooldown(0) {
    m_Shape.setSize({ 50, 100 });
    m_Shape.setFillColor(sf::Color::Blue);
    m_Shape.setPosition(m_Position);

    m_SwordHitbox.setSize({ 60, 20 });
    m_SwordHitbox.setFillColor(sf::Color::Yellow);
}

void Player::HandleInput(const sf::RenderWindow& window) {
    m_Velocity.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        m_Velocity.x = -200;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        m_Velocity.x = 200;

    sf::Vector2f worldMousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && m_SwordCooldown <= 0)
        SwingSword(worldMousePos);
}

void Player::Update(float dt, const sf::RenderWindow& window) {
    m_Position += m_Velocity * dt;
    m_Shape.setPosition(m_Position);

    UpdateSword(dt);

    if (m_SwordCooldown > 0) m_SwordCooldown -= dt;
    if (m_GunCooldown > 0) m_GunCooldown -= dt;
}

void Player::Render(sf::RenderWindow& window) {
    window.draw(m_Shape);
    if (m_IsSwinging) window.draw(m_SwordHitbox);
}

std::optional<std::unique_ptr<Entity>> Player::TryShoot(const sf::RenderWindow& window) {
    if (m_GunCooldown <= 0.f && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        m_GunCooldown = 0.5f;

        sf::Vector2f dir = mousePos - m_Position;
        float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
        if (len != 0) dir /= len;

        return std::optional<std::unique_ptr<Bullet>>(std::make_unique<Bullet>(m_Position, dir));
    }
    return std::nullopt;
}

void Player::SwingSword(const sf::Vector2f& target) {
    sf::Vector2f dir = target - m_Position;
    float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    if (len != 0)
        dir /= len;

    m_IsSwinging = true;
    m_SwordCooldown = 1.0f;

    m_SwordHitbox.setRotation(sf::degrees(std::atan2(dir.y, dir.x)) * 180 / 3.14159f);
    m_SwordHitbox.setPosition(m_Position + dir * 60.0f);
}


void Player::UpdateSword(float dt) {
    if (m_IsSwinging) {
        static float swingDuration = 0.2f;
        swingDuration -= dt;
        if (swingDuration <= 0) {
            m_IsSwinging = false;
            swingDuration = 0.2f;
        }
    }
}
