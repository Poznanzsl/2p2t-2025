#pragma once
#include <vector>

#include <iostream>
#include "raylib.h"
#include "raymath.h"

enum class Fields {
	EMPTY = 0,
	FLOOR = 1,
	WALL = 2
};

class Map {
public:

	std::vector<std::vector<Fields>> fieldMap;

	Map() {

	}

	std::vector<std::vector<Fields>> mapToVector(std::string path);
	void showMap(std::vector<std::vector<Fields>> &fieldMap);
};