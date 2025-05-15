
#include "raylib.h"
#include "raymath.h"

#include "game.h"   // an external header in this project
#include "lib.h"	// an external header in the static lib project

#include "headers/entity.h"
#include "headers/player.h"
#include "headers/renderer.h"
#include "headers/inputHandler.h"

void GameInit()
{
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(InitialWidth, InitialHeight, "Example");
    SetTargetFPS(144);

}

void GameCleanup()
{
    CloseWindow();
}

void gameLoop(Render* render, EntityHandler* entityHandler, InputHandler* inputHandler, Camera2D *camera) {
    while (!WindowShouldClose()) {
        inputHandler->inputReciever();
        entityHandler->updateAll();
        render->GameDraw(camera, entityHandler);
    }
}

int main()
{
    GameInit();
    EntityHandler entityHandler;
    Player player(Position(1, 1), 100, Type::PLAYER);
    InputHandler inputHandler(&player);

    Camera2D cam = { 0 };
    cam.target = { 0.0f, 0.0f };
    cam.zoom = 1.0f;

    Render render;

    entityHandler.addToArray(&player);
    gameLoop(&render, &entityHandler, &inputHandler, &cam);
    
    GameCleanup();

    return 0;
}