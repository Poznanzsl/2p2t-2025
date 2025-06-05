#pragma once
#include "./headers/renderer.h"
#include "./headers/map.h"
#include "./headers/constants.h"
#include <iostream>

void Render::GameDraw(Camera2D* camera, EntityHandler* entityHandler)
{
    BeginDrawing();
    ClearBackground(DARKGRAY);
    BeginMode2D(*camera);
    Scale = static_cast<float>(GetRenderHeight()) / static_cast<float>(InitialHeight);

    DrawRectangle(InitialWidth * Scale, 0, InitialWidth * Scale, InitialHeight * Scale, BLACK);
    std::cout << '\n' << Scale << " Scale" << '\n';


    for (int i = 0; i < entityHandler->entityArr.size(); i++) {
        if (entityHandler->entityArr[i]->type == Type::PLAYER) {
            DrawRectangle(floor(entityHandler->entityArr[i]->pos.x * Scale), floor(entityHandler->entityArr[i]->pos.y * Scale), 50 * Scale, 100 * Scale, WHITE);
        }
    }
    EndDrawing();
}