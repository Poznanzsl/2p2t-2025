#pragma once

#include "GameState.h"
#include "entities/Player.h"

#include <algorithm> 

class GameplayState : public GameState {
public:
    void Init() override;
    void HandleEvents(sf::RenderWindow& window) override;
    void Update(float dt, sf::RenderWindow& window) override;
    void Render(sf::RenderWindow& window) override;
    void Exit() override;

private:
    std::vector<std::unique_ptr<Entity>> m_Entities;
};