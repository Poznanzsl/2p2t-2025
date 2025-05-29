// settings.cpp
#include "settings.h"
#include "ui_utils.h"

namespace GameConfig {

    Settings settings;

    void ShowSettingsMenu() {
        const int screenWidth = 600;
        const int screenHeight = 900;

        InitWindow(screenWidth, screenHeight, "Tetris - Ustawienia");

        Rectangle easyBtn = { 150, 200, 300, 60 };
        Rectangle mediumBtn = { 150, 280, 300, 60 };
        Rectangle hardBtn = { 150, 360, 300, 60 };
        Rectangle soundToggleBtn = { 150, 460, 300, 60 };
        Rectangle backBtn = { 150, 600, 300, 60 };

        while (!WindowShouldClose()) {
            Vector2 mousePos = GetMousePosition();

            BeginDrawing();
            ClearBackground(DARKGRAY);

            DrawText("Ustawienia", 160, 100, 50, RAYWHITE);

            DrawCenteredTextInButton("Latwy", easyBtn, 30, settings.difficulty == Difficulty::EASY ? GREEN : WHITE);
            DrawCenteredTextInButton("Sredni", mediumBtn, 30, settings.difficulty == Difficulty::MEDIUM ? GREEN : WHITE);
            DrawCenteredTextInButton("Trudny", hardBtn, 30, settings.difficulty == Difficulty::HARD ? GREEN : WHITE);

            DrawCenteredTextInButton(settings.soundEnabled ? "Dzwiek: Wlaczony" : "Dzwiek: Wylaczony", soundToggleBtn, 30, WHITE);
            DrawCenteredTextInButton("Powrot", backBtn, 30, WHITE);

            EndDrawing();

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (CheckCollisionPointRec(mousePos, easyBtn)) settings.difficulty = Difficulty::EASY;
                if (CheckCollisionPointRec(mousePos, mediumBtn)) settings.difficulty = Difficulty::MEDIUM;
                if (CheckCollisionPointRec(mousePos, hardBtn)) settings.difficulty = Difficulty::HARD;
                if (CheckCollisionPointRec(mousePos, soundToggleBtn)) settings.soundEnabled = !settings.soundEnabled;
                if (CheckCollisionPointRec(mousePos, backBtn)) break;
            }
        }

        CloseWindow();
    }

}
