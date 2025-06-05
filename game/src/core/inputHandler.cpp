#include "./headers/inputHandler.h"

void InputHandler::inputReciever() {

    if (IsKeyDown(KEY_W)) {
        std::cout << "W" << '\n';
        player->jump();
    }
    else if (IsKeyDown(KEY_S)) {
        std::cout << "S" << '\n';
    }
    else if (IsKeyDown(KEY_A)) {
        std::cout << "A" << '\n';
        player->move(Direction::LEFT);
    }
    else if (IsKeyDown(KEY_D)) {
        std::cout << "D" << '\n';
        player->move(Direction::RIGHT);
    }
}
