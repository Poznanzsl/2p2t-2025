
#include "./headers/entity.h"

void Entity::update() {
	if (abs(veloY) < maxSpeed) {
		veloY = (veloY + 0.1f);
	}		
	if (abs(veloX) > 0) {
		if (veloX > 0) {
			veloX = veloX - 0.1f;
		}
		else{
			veloX = veloX + 0.1f;
		}
	}
	if (pos.y > 500) {
		veloY = 0;
		grounded = true;
	}
	std::cout << veloY;
	pos.y = pos.y + veloY;
	pos.x = pos.x + veloX;
};

void EntityHandler::addToArray(Entity *ent) {
	ent->id = Gid + 1;
	entityArr.push_back(ent);
	std::cout << "pushed Entity into array" << '\n';
	Gid++;
}

void EntityHandler::removeFromArray(int id) {
	for (int i = 0; i < entityArr.size(); i++) {
		if (id == entityArr[i]->id) {
			entityArr[i] = entityArr.back();
			entityArr.pop_back();
			break;
		}
	}
}

void EntityHandler::coutArray() {
	for (int i = 0; i < entityArr.size(); i++) {
		std::cout << entityArr[i]->id << " ";
	}
	std::cout << '\n' << entityArr.size();
}

void EntityHandler::updateAll() {
	for (int i = 0; i < entityArr.size(); i++) {
		entityArr[i]->update();
	}
}