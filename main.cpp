#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_parameters.hpp"
#include "scenes.hpp"
#include "physics.hpp"

using param = parameters;

int main() {
	Scenes::level = std::make_shared<LevelScene>();
	Scenes::level->load();
	GameSystem::set_active_scene(Scenes::menu);
	GameSystem::start(param::game_width, param::game_height, "Trapped in Hell", Physics::time_step, true);
}

