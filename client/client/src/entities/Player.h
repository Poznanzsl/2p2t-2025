#pragma once

#include "Entity.h"
#include "Bullet.h"

#include <SFML/Graphics.hpp>
#include <optional>

class Player : public Entity {
public:
    Player(float x = 0, float y = 0);

    void Update(float dt, const sf::RenderWindow& window);
    void Render(sf::RenderWindow& window) override;

    void HandleInput(const sf::RenderWindow& window);

    std::optional<std::unique_ptr<Entity>> TryShoot(const sf::RenderWindow& window);
    void SwingSword(const sf::Vector2f& target);

private:
    sf::RectangleShape m_Shape;
    sf::RectangleShape m_SwordHitbox;
    std::vector<Bullet> m_Bullets;

    bool m_IsSwinging;
    float m_SwordCooldown;
    float m_GunCooldown;

    void UpdateSword(float dt);
};
