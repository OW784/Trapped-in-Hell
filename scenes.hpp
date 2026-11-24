#pragma once
#include "game_system.hpp"

class MenuScene : public Scene {
public:
	MenuScene() = default;
	void update(const float& dt) override;
	void render() override;
	void load() override;
	void unload() override;

private:

};

class LevelScene : public Scene {
public:
	LevelScene() = default;
	void update(const float& dt) override;
	void render() override;
	void load() override;
	void unload() override;
private:
	void _load_level(const std::string& filepath);
	std::shared_ptr<Entity> _player;
	sf::Texture _backgroundTexture;
	sf::Sprite _backgroundSprite;
};

struct Scenes {
	static std::shared_ptr<Scene> menu;
	static std::shared_ptr<Scene> level;
};