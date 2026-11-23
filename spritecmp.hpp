#pragma once
#include "ecm.hpp"
#include <SFML/Graphics.hpp>

class SpriteComponent : public Component {
public:
	SpriteComponent() = delete;
	explicit SpriteComponent(Entity* p);
	void update(const float& dt) override;
	void render() override;
	sf::Sprite& get_sprite() const;
	void set_texture(std::shared_ptr<sf::Texture> texture);
protected:
	std::shared_ptr<sf::Sprite> _sprite;
	std::shared_ptr<sf::Texture> _texture;
};