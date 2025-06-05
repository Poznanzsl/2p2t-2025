#include "./headers/hitbox.h"

void Hitbox::updateHitbox(Entity* entity, std::vector<std::vector<Fields>>* map) {
	checkForCollision(map);
	snapToModel(entity);
}

bool Hitbox::checkForCollision(std::vector<std::vector<Fields>> *map) {
	if (map[topLeft.first][topLeft.second] == Fields::FLOOR) {

	}
	return false;
}

void Hitbox::snapToModel(Entity* entity) {
	int x = entity->pos.x;
	int y = entity->pos.y;
}