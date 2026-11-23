#include "game_parameters.hpp"
#include "spritecmp.hpp"
#include "renderer.hpp"

void SpriteComponent::render() { Renderer::queue(_sprite.get()); }

sf::Sprite& SpriteComponent::get_sprite() const { return *_sprite; }

void SpriteComponent::set_texture(std::shared_ptr<sf::Texture> texture)
{
	_texture = texture;
	_sprite->setTexture(*_texture);
}

SpriteComponent::SpriteComponent(Entity* p)
	: Component(p), _sprite(std::make_shared<sf::Sprite>()) {
}

void SpriteComponent::update(const float& dt) {
	_sprite->setPosition(_parent->get_position());
	_sprite->setRotation((_parent->get_rotation()) / M_PI * 180.f);
}
