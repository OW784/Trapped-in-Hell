#include "weaponcmp.hpp"
#include "renderer.hpp"
#include "game_parameters.hpp"
#include <SFML/Window.hpp>

WeaponComponent::WeaponComponent(Entity* p)
    : Component(p), _weapon_sprite(std::make_shared<sf::Sprite>())
{
}

void WeaponComponent::render() { Renderer::queue(_weapon_sprite.get()); }

void WeaponComponent::update(const float& dt) {
    _weapon_sprite->setPosition(_parent->get_position() + _offset);

    auto& window = Renderer::get_window();
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    // Find where the mouse is pointing in the game world
    sf::Vector2f mouseWorld = window.mapPixelToCoords(mousePos);


    //calculates the angle from the weapon towards the mouse in radians
    float angle = std::atan2(
        mouseWorld.y - _weapon_sprite->getPosition().y,
        mouseWorld.x - _weapon_sprite->getPosition().x
    );
    //converts radians to degrees
    _weapon_sprite->setRotation(angle / M_PI * 180.f);

}

void WeaponComponent::set_texture(std::shared_ptr<sf::Texture> texture)
{
    _texture = texture;
    _weapon_sprite->setTexture(*_texture);
}

sf::Sprite& WeaponComponent::get_sprite() const{
    return *_weapon_sprite;
}

void WeaponComponent::set_offset(const sf::Vector2f& offset) {
    _offset = offset;
}