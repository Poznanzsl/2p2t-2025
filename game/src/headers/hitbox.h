#pragma once
#include "entity.h"
<<<<<<< HEAD
#include "map.h"

class HitboxHandler {
public:



};

class Hitbox {
public:
=======

class Hitbox {
>>>>>>> 7b9a3e92803b07d3c3cc00cf430acbd2586ec513
	int x, y, height, width;

	std::pair<int,int> topRight, topLeft, bottomLeft, bottomRight;
	Hitbox(int x, int y, int width, int height) : x(x),y(y),width(width),height(height) {
		topRight.first = x; topRight.second = y;
		topLeft.first = x + width; topLeft.second = y;
		bottomLeft.first = x; bottomLeft.second = y + height;
		bottomRight.first = x + width; bottomRight.second = y;
	}

<<<<<<< HEAD
	void updateHitbox(Entity* entity, std::vector<std::vector<Fields>>* map);

private:
	bool checkForCollision(std::vector<std::vector<Fields>>* map);
	void snapToModel(Entity* entity);
=======
	bool checkForCollision();
>>>>>>> 7b9a3e92803b07d3c3cc00cf430acbd2586ec513
};
