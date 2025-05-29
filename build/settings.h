// settings.h
#ifndef SETTINGS_H
#define SETTINGS_H

#include "raylib.h"

namespace GameConfig {

    enum class Difficulty {
        EASY,
        MEDIUM,
        HARD
    };

    struct Settings {
        Difficulty difficulty = Difficulty::MEDIUM;
        bool soundEnabled = true;
    };

    extern Settings settings;

    void ShowSettingsMenu();

}

#endif
