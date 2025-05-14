#include "menu.h"
#include "raylib.h"

int main() {
    ShowMenu();

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetris - Gra");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Tetris startuje tutaj...", 250, 300, 20, DARKGREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}