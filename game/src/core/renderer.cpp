#pragma once
#include "./headers/renderer.h"

void Render::GameDraw(Camera2D* camera, EntityHandler* entityHandler)
{
    BeginDrawing();
    ClearBackground(DARKGRAY);
    BeginMode2D(*camera);

    for (int i = 0; i < entityHandler->entityArr.size(); i++) {
        if (entityHandler->entityArr[i]->type == Type::PLAYER) {
            DrawRectangle(floor(entityHandler->entityArr[i]->pos.x), floor(entityHandler->entityArr[i]->pos.y), 50, 100, WHITE);
        }
    }
    EndDrawing();
}