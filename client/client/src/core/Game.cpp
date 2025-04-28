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
		m_Room = m_NetworkClient.CreateRoom();
		if (!m_Room.has_value()) {
			std::cerr << "Couldnt create room" << std::endl;
		}
		else {
			std::cout << "Room created with code: " << m_Room.value() << std::endl;
		}
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
