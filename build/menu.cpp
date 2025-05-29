#include "raylib.h"
#include "menu.h"
#include "ui_utils.h"
#include <math.h> // dla sin()
#include "settings.h"
using namespace GameConfig;

void ShowMenu() {
    const int screenWidth = 600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Tetris - Menu");

    float btnWidth = 320;
    float btnHeight = 90;

    // Nowe rozmieszczenie: wyżej
    float btnSpacing = 70;
    float firstBtnY = 350;

    Rectangle startBtn = {
        (screenWidth - btnWidth) / 2,
        firstBtnY,
        btnWidth,
        btnHeight
    };

    Rectangle settingsBtn = {
        (screenWidth - btnWidth) / 2,
        firstBtnY + btnHeight + btnSpacing,
        btnWidth,
        btnHeight
    };

    int menuOption = 0;

    // Kolory
    Color titleColor = { 255, 0, 255, 255 };
    Color btnColor = { 0, 255, 200, 255 };
    Color btnHoverColor = { 0, 200, 180, 255 };
    Color textColor = BLACK;

    float time = 0.0f;

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        time += GetFrameTime();

        BeginDrawing();

        // Animowane tło: lekko pulsujące odcienie
        float wave = sinf(time * 1.5f); // teraz wave ∈ [-1, 1]

        // Skaluje do 0–1 → potem do 0–40
        float intensity = (wave + 1.0f) / 2.0f * 40.0f;

        Color bgColor;
        bgColor.r = 10 + (int)intensity;     // 10–50
        bgColor.g = 10;
        bgColor.b = 30 + (int)intensity;     // 30–70
        bgColor.a = 255;

        ClearBackground(bgColor);

        // Tytuł
        const char* title = "TETRIS";
        int titleFontSize = 100;
        int titleTextWidth = MeasureText(title, titleFontSize);
        int textX = (screenWidth - titleTextWidth) / 2;
        DrawText(title, textX, 120, titleFontSize, titleColor);

        // Przycisk: START
        bool hoverStart = CheckCollisionPointRec(mousePos, startBtn);
        DrawRectangleRounded(startBtn, 0.4f, 10, hoverStart ? btnHoverColor : btnColor);
        DrawCenteredTextInButton("START", startBtn, 40, textColor);

        // Przycisk: USTAWIENIA
        bool hoverSettings = CheckCollisionPointRec(mousePos, settingsBtn);
        DrawRectangleRounded(settingsBtn, 0.4f, 10, hoverSettings ? btnHoverColor : btnColor);
        DrawCenteredTextInButton("USTAWIENIA", settingsBtn, 40, textColor);

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (hoverStart) {
                menuOption = 1;
                break;
            }
            else if (hoverSettings) {
                menuOption = 2;
                break;
            }
        }
    }

    CloseWindow();

    if (menuOption == 1) {
        TraceLog(LOG_INFO, "Start gry!");
    }
    else if (menuOption == 2) {
        TraceLog(LOG_INFO, "Ustawienia!");
        ShowSettingsMenu();
        ShowMenu(); // po powrocie z ustawień, znów pokaż menu
    }
}
