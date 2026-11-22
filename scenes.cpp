#include <iostream>
#include "scenes.hpp"
#include "level_system.hpp"
#include "game_parameters.hpp"


using ls = LevelSystem;
using param = parameters;
using gs = GameSystem;

std::shared_ptr<Scene> Scenes::menu;
std::shared_ptr<Scene> Scenes::level;



void LevelScene::_load_level(const std::string& filepath) {
	ls::load_level(filepath, param::tile_size);
}





void LevelScene::load() {
	_load_level(param::level1);
}