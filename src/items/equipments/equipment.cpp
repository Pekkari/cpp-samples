#include "items/equipments/equipment.hpp"

Armor::Armor(std::string& name, sf::Vector2<float> position) :
    Equipment(name, position) {
    armor_strength_ = ARMOR_START_VALUE;

    //Load sprite
    //sprite_ = ...;
}

sf::Sprite Armor::getSprite() const {
    return sprite_;
}
