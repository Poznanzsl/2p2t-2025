#include "menu.h"
#include "raylib.h"
#include "settings.h"
#include "game.h"
using namespace GameConfig;


int main() {
    ShowMenu();

    // Debugowanie - wypisanie ustawieñ
    TraceLog(LOG_INFO, TextFormat("Trudnosc: %d", static_cast<int>(settings.difficulty)));
    TraceLog(LOG_INFO, settings.soundEnabled ? "Dzwiek wlaczony" : "Dzwiek wylaczony");

    const int screenWidth = 500;
    const int screenHeight = 620;
    
    InitWindow(screenWidth, screenHeight, "Tetris - Gra");

    Game game = Game();

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        game.Run();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
