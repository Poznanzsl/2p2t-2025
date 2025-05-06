#pragma once

#include <SFML/Graphics.hpp>

#include "network/NetworkClient.h"
#include <memory>

enum class GameState {
	MainMenu,
	Lobby,
	Playing,
	GameOver,
	Exiting,
};

class Game {
public:
	void Run();
private:
	void Init();
	void Shutdown();
	void HandleEvents();
	void Update();
	void Render();
private:
	NetworkClient m_NetworkClient;
	std::optional<uint32_t> m_Room;

	std::unique_ptr<sf::RenderWindow> m_Window;
	std::unique_ptr<sf::Texture> m_Texture;
	std::unique_ptr<sf::Sprite> m_Sprite;

	GameState m_CurrentState;
	bool m_Running;
};