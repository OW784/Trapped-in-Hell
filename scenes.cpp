#include <iostream>
#include "scenes.hpp"
#include "level_system.hpp"
#include "game_parameters.hpp"
#include "renderer.hpp"
#include "spritecmp.hpp"
#include "weaponcmp.hpp"
#include "physicscmp.hpp"

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
	std::shared_ptr<PlayerPhysicsComponent> cmp =
		_player->add_component<PlayerPhysicsComponent>(
			sf::Vector2f(param::player_size[0], param::player_size[1]));

	cmp->create_capsule_shape(
		sf::Vector2f(param::player_size[0], param::player_size[1]),
		param::player_weight,
		param::player_friction,
		param::player_restitution);

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

	auto gun_sprite = _player->add_component<WeaponComponent>();
	auto gun_texture = std::make_shared<sf::Texture>();

	if (!gun_texture->loadFromFile("assets/sprite_sheets/gun/gun.png")) {
		throw std::runtime_error("Failed to load gun texture");
	}
	gun_texture->setSmooth(false);
	gun_sprite->set_texture(gun_texture);
	gun_sprite->get_sprite().setScale(2.f, 2.f);
	gun_sprite->get_sprite().setOrigin(8.f, 9.f);
	gun_sprite->get_sprite().setTextureRect(
		sf::IntRect(0, 0, 16, 24)
	);
	gun_sprite->set_offset(sf::Vector2f(0.f, -30.f));
	std::vector<std::vector<sf::Vector2i>> wall_groups = ls::get_groups(ls::WALL);

	for (const std::vector<sf::Vector2i>& walls : wall_groups) {
		_walls.push_back(make_entity());
		_walls.back()->add_component<PlatformComponent>(walls);
	}
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

