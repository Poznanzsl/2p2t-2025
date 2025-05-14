#include "ui_utils.h"

void DrawCenteredTextInButton(const char* text, Rectangle rect, int fontSize, Color color) {
    int textWidth = MeasureText(text, fontSize);
    int textX = rect.x + (rect.width - textWidth) / 2;
    int textY = rect.y + (rect.height - fontSize) / 2;
    DrawText(text, textX, textY, fontSize, color);
}
