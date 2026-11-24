#include <iostream>
#include "scenes.hpp"
#include "level_system.hpp"
#include "game_parameters.hpp"
#include "renderer.hpp"
#include "spritecmp.hpp"


using ls = LevelSystem;
using param = parameters;
using gs = GameSystem;

std::shared_ptr<Scene> Scenes::menu;
std::shared_ptr<Scene> Scenes::level;



void LevelScene::_load_level(const std::string& filepath) {
	ls::load_level(filepath, param::tile_size);


	_player = make_entity();
	sf::Vector2f spawn = ls::get_start_position();

	spawn.x += param::tile_size / 2.f;
	spawn.y += param::tile_size;

	_player->set_position(spawn);

	auto sprite = _player->add_component<SpriteComponent>();
	auto texture = std::make_shared<sf::Texture>();

	if (!texture->loadFromFile("assets/sprite_sheets/player/walk.png")) {
		throw std::runtime_error("Failed to load player texture");
	}
	texture->setSmooth(false);
	sprite->set_texture(texture);
	sprite->get_sprite().setScale(2.f, 2.f);
	sprite->get_sprite().setOrigin(8.f, 24.f);
	sprite->get_sprite().setTextureRect(
		sf::IntRect(0, 0, 16, 24)
	);
}


void LevelScene::load() {
	_backgroundTexture.loadFromFile("assets/backgrounds/hell.png");
	_backgroundTexture.setSmooth(false);

	_backgroundSprite.setTexture(_backgroundTexture);
	_backgroundSprite.setScale(4.f, 4.f);
	_load_level(param::level1);
}

void LevelScene::update(const float& dt) {
	Scene::update(dt);
}

void LevelScene::render() {
	Renderer::get_window().draw(_backgroundSprite);

	ls::render(Renderer::get_window());
	Scene::render();
}

void LevelScene::unload() {
	Scene::unload();
}