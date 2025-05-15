#pragma once
#include "renderer.h"
#include "player.h"


class InputHandler {
public:		
	Player *player;

	InputHandler(Player* _player) {
		player = _player;
	}

	void inputReciever();
};

