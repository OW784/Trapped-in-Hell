#pragma once
#include "game_system.hpp"

class MenuScene : public scene {
public:
	MenuScene() = default;
	void update(const float& dt) override;
	void render() override;
	void load() override;
	void unload() override;

private:

};

class LevelScene : public scene {
public:
	LevelScene() = default;
	void update(const float& dt) override;
	void render() override;
	void load() override;
	void unload() override;
private:

};

struct Scenes {
	static std::shared_ptr<Scene> menu;
	static std::shared_ptr<Scene> level;
};