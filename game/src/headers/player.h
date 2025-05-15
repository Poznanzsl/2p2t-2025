#pragma once
#include "entity.h"

enum class Direction {
	TOP = 0,
	LEFT = 1,
	BOTTOM = 2,
	RIGHT = 3
};

class Player : public Entity {
public:

	Player(Position pos, int health, Type type) : Entity(pos, health, type) {

		
	}

	void jump();
	void move(Direction direction);

};
