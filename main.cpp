#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_parameters.hpp"
#include "scenes.hpp"
#include "physics.hpp"

using param = parameters;

int main() {
    Physics::initialise();

    Scenes::level = std::make_shared<LevelScene>();
    Scenes::level->load();

    GameSystem::set_active_scene(Scenes::level);

    GameSystem::start(param::game_width, param::game_height,
        "Trapped in Hell", Physics::time_step, true);

    Physics::shutdown();
    return 0;
}