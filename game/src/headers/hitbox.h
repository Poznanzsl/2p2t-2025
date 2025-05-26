#pragma once
#include "entity.h"

class Hitbox {
	int x, y, height, width;

	std::pair<int,int> topRight, topLeft, bottomLeft, bottomRight;
	Hitbox(int x, int y, int width, int height) : x(x),y(y),width(width),height(height) {
		topRight.first = x; topRight.second = y;
		topLeft.first = x + width; topLeft.second = y;
		bottomLeft.first = x; bottomLeft.second = y + height;
		bottomRight.first = x + width; bottomRight.second = y;
	}

	bool checkForCollision();
};
