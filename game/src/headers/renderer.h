#pragma once

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "entity.h"

class Render {
public:

	Render() {}

	void GameDraw(Camera2D* camera, EntityHandler* entityHandler);

};