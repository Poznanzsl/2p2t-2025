#pragma once
#include <vector>
#include <iostream>

static int Gid = 0;

class Position {
public:
	float x = 0.0f;
	float y = 0.0f;

	Position(float x_, float y_) : x(x_), y(y_){}
};

enum class Type {
	TYPENULL = 0,
	PLAYER = 1,
};

class Entity {
public:
	Position pos;
	int health;
	Type type;
	int id = (Gid + 1);;
	float veloX = 0;
	float veloY = 0;
	int maxSpeed = 10;

	Entity(Position pos, int health, Type type) : pos(pos), health(health), type(type) {
		Gid++;
	}

	void update();

protected:
	bool grounded = false;
};

class EntityHandler {
public:
	std::vector<Entity*> entityArr;

	void addToArray(Entity *ent);
	void removeFromArray(int id);
	void coutArray();
	void updateAll();
};