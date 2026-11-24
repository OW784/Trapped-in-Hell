#pragma once
#include "ecm.hpp"
#include <SFML/Graphics.hpp>

class WeaponComponent : public Component {
public:
	explicit WeaponComponent(Entity* p);
	sf::Sprite& get_sprite() const;
	void update(const float& dt) override;
	void render() override;
	void set_texture(std::shared_ptr<sf::Texture> texture);
	void set_offset(const sf::Vector2f& offset);
private:
	std::shared_ptr<sf::Texture> _texture;
	std::shared_ptr<sf::Sprite> _weapon_sprite;
	sf::Vector2f _offset;
};