#include <iostream>
#include "scenes.hpp"
#include "level_system.hpp"
#include "game_parameters.hpp"
#include "renderer.hpp"


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

void LevelScene::update(const float& dt) {
	Scene::update(dt);
}

void LevelScene::render() {
	ls::render(Renderer::get_window());
	Scene::render();
}

void LevelScene::unload() {
	Scene::unload();
}