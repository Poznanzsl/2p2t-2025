#include "GameplayState.h" 

#include <iostream>

void GameplayState::Init() {
    auto player = std::make_unique<Player>(400.0f, 300.0f);

    m_Entities.clear();
    m_Entities.push_back(std::move(player));
}

void GameplayState::HandleEvents(sf::RenderWindow& window) {
    if (!m_Entities.empty()) {
        if (auto* player = dynamic_cast<Player*>(m_Entities[0].get())) {
            player->HandleInput(window);
        }
    }
}

void GameplayState::Update(float dt, sf::RenderWindow& window) {
    for (auto& entity : m_Entities) {
        entity->Update(dt, window);
    }

    if (!m_Entities.empty()) {
        if (auto* player = dynamic_cast<Player*>(m_Entities[0].get())) {
            auto newBullet = player->TryShoot(window);
            if (newBullet.has_value()) {
                m_Entities.push_back(std::move(newBullet.value()));
            }
        }
    }

    m_Entities.erase(
        std::remove_if(m_Entities.begin(), m_Entities.end(),
            [&](const std::unique_ptr<Entity>& e) {
                if (auto* bullet = dynamic_cast<Bullet*>(e.get())) {
                    return bullet->IsOffscreen(window.getSize());
                }
                return false;
            }),
        m_Entities.end()
    );
}

void GameplayState::Render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    for (auto& entity : m_Entities) {
        entity->Render(window);
    }
    
    window.display();
}

void GameplayState::Exit() {
    m_Entities.clear();
}
