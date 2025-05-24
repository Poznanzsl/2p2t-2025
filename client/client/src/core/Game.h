#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "network/NetworkClient.h"

#include "gameStates/GameState.h"
#include "gameStates/GameplayState.h"
#include "gameStates/MainMenuState.h"

enum class GameStateEnum {
	MainMenu,
	Lobby,
	Playing,
	GameOver,
	Exiting,
};

class Game {
public:
	Game();
	void Run();
private:
	void Init();
	void ChangeGameState(GameStateEnum state);
	void HandleEvents();
	void Update(float dt);
	void Render();
private:
	NetworkClient m_NetworkClient;
	std::optional<uint32_t> m_Room;

	sf::RenderWindow m_Window;
	sf::Clock m_Clock;

	std::unique_ptr<GameState> m_CurrentState;
	GameStateEnum m_CurrentStateEnum;
	bool m_Running;
};