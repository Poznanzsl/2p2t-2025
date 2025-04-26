#include "Game.h"

void Game::Run(){
	Init();

	// Game loop
	while (m_Running) {
		HandleEvents();
		Update();
		Render();
	}

	Shutdown();
}

void Game::Init(){
	// Should find ip with open server on local network, rn using localhost for testing
	if (m_NetworkClient.Connect("127.0.0.1", 12345)) {
		const char* msg = "Test text from client";
		m_NetworkClient.SendData(msg, strlen(msg) + 1);
	}
	m_CurrentState = GameState::MainMenu;
	m_Running = true;
}

void Game::Shutdown(){
}

void Game::HandleEvents(){
}

void Game::Update(){
	m_NetworkClient.ReceiveData();
}

void Game::Render(){
}
