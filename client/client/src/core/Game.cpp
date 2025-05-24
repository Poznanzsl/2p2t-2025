#include "Game.h"

Game::Game()
	:m_Window(sf::RenderWindow(sf::VideoMode({ 1200, 800 }), "test")){}

void Game::Run(){
	Init();

	// Game loop
	while (m_Running) {
		float dt = m_Clock.restart().asSeconds();
		HandleEvents();
		Update(dt);
		Render();
	}
}

void Game::Init(){
	if (m_NetworkClient.Connect("34.118.65.8", 12345)) {
		m_Room = m_NetworkClient.CreateRoom();
		if (!m_Room.has_value()) {
			std::cerr << "Couldnt create room" << std::endl;
		}
		else {
			std::cout << "Room created with code: " << m_Room.value() << std::endl;
		}	
	}
	
	ChangeGameState(GameStateEnum::Playing);
	m_Running = true;
}

void Game::ChangeGameState(GameStateEnum state) {
	if (m_CurrentStateEnum == state) return;

	if (m_CurrentState) {
		m_CurrentState->Exit(); 
	}

	switch (state) {
	case GameStateEnum::Playing:
		m_CurrentState = std::make_unique<GameplayState>();
		break;
	}
	//etc

	m_CurrentState->Init(); 
	m_CurrentStateEnum = state;
}

void Game::HandleEvents(){
	while (const std::optional<sf::Event> e = m_Window.pollEvent()) {
		if (e->is<sf::Event::Closed>()) {
			m_Window.close();
			m_Running = false;
		}
	}
	m_CurrentState->HandleEvents(m_Window);
}

void Game::Update(float dt){
	m_NetworkClient.ReceiveData();
	m_CurrentState->Update(dt, m_Window);
}

void Game::Render(){
	m_CurrentState->Render(m_Window);
}
