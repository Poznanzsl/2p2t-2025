#pragma once

#include "network/NetworkClient.h"

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

	GameState m_CurrentState;
	bool m_Running;
};