#include "menu.h"
#include "raylib.h"
#include "settings.h"
using namespace GameConfig;


int main() {
    ShowMenu();

    // Debugowanie - wypisanie ustawieñ
    TraceLog(LOG_INFO, TextFormat("Trudnosc: %d", static_cast<int>(settings.difficulty)));
    TraceLog(LOG_INFO, settings.soundEnabled ? "Dzwiek wlaczony" : "Dzwiek wylaczony");

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
