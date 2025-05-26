#include "./headers/player.h"
#include <iostream>

void Player::move(Direction direction) {
	switch (direction) {
	case Direction::LEFT:
		if (abs(veloX) < maxSpeed) veloX--;
		break;
	case Direction::RIGHT:
		if (abs(veloX) < maxSpeed) veloX++;
		break;
	}
}

void Player::jump() {
	if (grounded) {
		pos.y--;
		veloY = -8.0f;
		grounded = false;
		std::cout << "jumping";
	}
}